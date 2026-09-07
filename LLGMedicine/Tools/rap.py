#!/usr/bin/env python3
"""Read and write binarised DayZ/Arma configs (the "\\0raP" format).

    python3 rap.py dump  config.bin            # print the class tree
    python3 rap.py bin   config.cpp config.bin # binarise a (regular) config.cpp
    python3 rap.py check config.bin            # parse, re-write, compare bytes

The parser is deliberately narrow: it handles the subset of config.cpp that
an override mod uses - classes, externs, string/int/float properties and
flat arrays of those. It does not do the C preprocessor, string
concatenation, or nested arrays. It refuses anything it does not understand
rather than guessing.

Why this exists: a raw config.cpp inside a PBO is treated by this engine as a
replacement for any class it re-opens, so a two-line override strips the
item of its model. A config.bin merges. TerjeMedicine ships config.bin;
the working Jeep override ships config.bin; the 1988 override shipped a raw
config.cpp and had to restate every property to survive.
"""

import re
import struct
import sys

# ----------------------------------------------------------------- tree

class Class:
    def __init__(self, name, parent=""):
        self.name = name
        self.parent = parent
        self.entries = []       # (kind, name, payload)

class Extern:
    def __init__(self, name):
        self.name = name

# entry kinds: ("class", Class) ("extern", Extern) ("value", name, value) ("array", name, list)

# --------------------------------------------------------------- reader

def _cstr(b, o):
    e = b.index(b"\x00", o)
    return b[o:e].decode("utf-8", "replace"), e + 1

def _cint(b, o):
    v = shift = 0
    while True:
        c = b[o]; o += 1
        v |= (c & 0x7F) << shift
        if not (c & 0x80):
            return v, o
        shift += 7

def _read_value(b, o, sub):
    if sub in (0, 4):
        return _cstr(b, o)
    if sub == 1:
        return struct.unpack_from("<f", b, o)[0], o + 4
    if sub == 2:
        return struct.unpack_from("<i", b, o)[0], o + 4
    if sub == 3:
        return struct.unpack_from("<q", b, o)[0], o + 8
    raise ValueError("value subtype %d" % sub)

def _read_array(b, o):
    n, o = _cint(b, o)
    out = []
    for _ in range(n):
        t = b[o]; o += 1
        if t == 3:
            v, o = _read_array(b, o)
        else:
            v, o = _read_value(b, o, t)
        out.append(v)
    return out, o

def _read_class(b, o, cls):
    cls.parent, o = _cstr(b, o)
    n, o = _cint(b, o)
    for _ in range(n):
        t = b[o]; o += 1
        if t == 0:
            name, o = _cstr(b, o)
            off = struct.unpack_from("<I", b, o)[0]; o += 4
            child = Class(name)
            _read_class(b, off, child)
            cls.entries.append(("class", child))
        elif t == 1:
            sub = b[o]; o += 1
            name, o = _cstr(b, o)
            v, o = _read_value(b, o, sub)
            cls.entries.append(("value", name, v))
        elif t == 2:
            name, o = _cstr(b, o)
            v, o = _read_array(b, o)
            cls.entries.append(("array", name, v))
        elif t == 3:
            name, o = _cstr(b, o)
            cls.entries.append(("extern", Extern(name)))
        elif t == 4:
            name, o = _cstr(b, o)
            cls.entries.append(("delete", name))
        else:
            raise ValueError("entry type %d at %d" % (t, o - 1))
    return o

def read(data):
    if data[:4] != b"\x00raP":
        raise ValueError("not a raP file")
    zero, eight, enum_off = struct.unpack_from("<III", data, 4)
    root = Class("")
    _read_class(data, 16, root)
    return root

# --------------------------------------------------------------- writer

def _wcstr(s):
    return s.encode("utf-8") + b"\x00"

def _wcint(v):
    out = bytearray()
    while True:
        c = v & 0x7F
        v >>= 7
        if v:
            out.append(c | 0x80)
        else:
            out.append(c)
            return bytes(out)

def _wvalue(v):
    if isinstance(v, bool):
        return b"\x02" + struct.pack("<i", int(v))
    if isinstance(v, int):
        return b"\x02" + struct.pack("<i", v)
    if isinstance(v, float):
        return b"\x01" + struct.pack("<f", v)
    if isinstance(v, str):
        return b"\x00" + _wcstr(v)
    raise TypeError(type(v))

def _warray(items):
    out = bytearray(_wcint(len(items)))
    for v in items:
        if isinstance(v, list):
            out += b"\x03" + _warray(v)
        else:
            out += _wvalue(v)
    return bytes(out)

def _write_class(cls, buf):
    """Append this class body to buf. Children are written after the entry
    list, depth first, with their offsets back-patched - the same layout
    the engine's own binariser produces."""
    buf += _wcstr(cls.parent)
    buf += _wcint(len(cls.entries))
    patches = []
    for e in cls.entries:
        kind = e[0]
        if kind == "class":
            buf += b"\x00" + _wcstr(e[1].name)
            patches.append((len(buf), e[1]))
            buf += b"\x00\x00\x00\x00"
        elif kind == "value":
            payload = _wvalue(e[2])
            buf += b"\x01" + payload[:1] + _wcstr(e[1]) + payload[1:]
        elif kind == "array":
            buf += b"\x02" + _wcstr(e[1]) + _warray(e[2])
        elif kind == "extern":
            buf += b"\x03" + _wcstr(e[1].name)
        elif kind == "delete":
            buf += b"\x04" + _wcstr(e[1])
    # Every body ends with the offset just past its last descendant, i.e.
    # where whatever comes next begins. Reserve it, write the children,
    # then fill it in.
    end_at = len(buf)
    buf += b"\x00\x00\x00\x00"
    for at, child in patches:
        struct.pack_into("<I", buf, at, len(buf))
        _write_class(child, buf)
    struct.pack_into("<I", buf, end_at, len(buf))

def write(root):
    buf = bytearray(b"\x00raP" + struct.pack("<III", 0, 8, 0))
    _write_class(root, buf)
    struct.pack_into("<I", buf, 12, len(buf))   # enum table offset
    buf += struct.pack("<I", 0)                 # zero enums
    return bytes(buf)

# ------------------------------------------------------------ cpp parser

_TOKEN = re.compile(r"""
    (?P<ws>\s+|//[^\n]*|/\*.*?\*/)
  | (?P<str>"(?:[^"\\]|\\.)*")
  | (?P<num>[-+]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][-+]?\d+)?)
  | (?P<id>[A-Za-z_]\w*)
  | (?P<sym>\[\]|[{}:;=,])
""", re.S | re.X)

def _tokens(text):
    pos = 0
    while pos < len(text):
        m = _TOKEN.match(text, pos)
        if not m:
            raise SyntaxError("cannot tokenise at %r" % text[pos:pos + 30])
        pos = m.end()
        if m.lastgroup != "ws":
            yield m.lastgroup, m.group()

def _number(tok):
    if re.fullmatch(r"[-+]?\d+", tok):
        return int(tok)
    return float(tok)

class _Parser:
    def __init__(self, text):
        self.toks = list(_tokens(text))
        self.i = 0

    def peek(self, k=0):
        return self.toks[self.i + k] if self.i + k < len(self.toks) else (None, None)

    def take(self, kind=None, value=None):
        t, v = self.peek()
        if (kind and t != kind) or (value and v != value):
            raise SyntaxError("expected %s %s, got %s %s (token %d)" % (kind, value, t, v, self.i))
        self.i += 1
        return v

    def parse(self):
        root = Class("")
        while self.peek()[0] is not None:
            self.entry(root)
        return root

    def entry(self, cls):
        t, v = self.peek()
        if t == "id" and v == "class":
            self.take()
            name = self.take("id")
            t2, v2 = self.peek()
            if v2 == ";":
                self.take(); cls.entries.append(("extern", Extern(name))); return
            parent = ""
            if v2 == ":":
                self.take(); parent = self.take("id")
            self.take("sym", "{")
            child = Class(name, parent)
            while self.peek()[1] != "}":
                self.entry(child)
            self.take("sym", "}")
            self.take("sym", ";")
            cls.entries.append(("class", child))
            return
        if t == "id":
            name = self.take("id")
            if self.peek()[1] == "[]":
                self.take(); self.take("sym", "=")
                cls.entries.append(("array", name, self.array()))
            else:
                self.take("sym", "=")
                cls.entries.append(("value", name, self.scalar()))
            self.take("sym", ";")
            return
        raise SyntaxError("unexpected %s %r" % (t, v))

    def scalar(self):
        t, v = self.peek()
        if t == "str":
            self.take(); return _unquote(v)
        if t == "num":
            self.take(); return _number(v)
        raise SyntaxError("bad scalar %r" % v)

    def array(self):
        self.take("sym", "{")
        items = []
        while self.peek()[1] != "}":
            if self.peek()[1] == "{":
                items.append(self.array())
            else:
                items.append(self.scalar())
            if self.peek()[1] == ",":
                self.take()
        self.take("sym", "}")
        return items

def _unquote(s):
    return s[1:-1].replace('\\"', '"').replace("\\\\", "\\")

def parse_cpp(text):
    return _Parser(text).parse()

# ------------------------------------------------------------------ dump

def dump(cls, depth=0, out=None):
    out = [] if out is None else out
    pad = "  " * depth
    for e in cls.entries:
        if e[0] == "class":
            head = e[1].name + (": " + e[1].parent if e[1].parent else "")
            out.append(pad + "class " + head)
            dump(e[1], depth + 1, out)
        elif e[0] == "extern":
            out.append(pad + "class " + e[1].name + ";")
        elif e[0] == "value":
            out.append(pad + "%s = %r" % (e[1], e[2]))
        elif e[0] == "array":
            out.append(pad + "%s[] = %r" % (e[1], e[2]))
    return out

# ------------------------------------------------------------------ main

if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else ""
    if cmd == "dump":
        print("\n".join(dump(read(open(sys.argv[2], "rb").read()))))
    elif cmd == "bin":
        text = open(sys.argv[2], encoding="utf-8").read()
        open(sys.argv[3], "wb").write(write(parse_cpp(text)))
        print("wrote", sys.argv[3])
    elif cmd == "check":
        data = open(sys.argv[2], "rb").read()
        again = write(read(data))
        print("round-trip", "IDENTICAL" if again == data else
              "DIFFERS (%d vs %d bytes)" % (len(again), len(data)))
        sys.exit(0 if again == data else 1)
    else:
        print(__doc__)
