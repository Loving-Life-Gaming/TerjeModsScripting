#!/usr/bin/env python3
"""Pack the LLGMedicine addon folder into an unbinarised DayZ PBO.

    python3 LLGMedicine/Tools/pack_pbo.py

Writes build/@LLGMedicine/addons/LLGMedicine.pbo next to the repository root.

config.cpp is binarised to config.bin on the way in (see rap.py). That is
not cosmetic: this engine treats a class re-opened from a RAW config.cpp as a
replacement for the earlier definition, so a two-line descriptionShort
override strips the item of its model or its ancestry. A binarised config
merges, which is how TerjeMedicine's own overrides of vanilla items work.
config.cpp stays the source you edit; only config.bin ships.

Nothing here signs the PBO; that needs a .biprivatekey and DSSignFile.
"""

import hashlib
import os
import struct
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import rap

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SOURCE = os.path.join(REPO, "LLGMedicine")
PREFIX = "LLGMedicine"
OUTPUT = os.path.join(REPO, "build", "@" + PREFIX, "addons", PREFIX + ".pbo")

# Everything under LLGMedicine/ ships except the source-only extras.
EXCLUDE_DIRS = {"Tools"}
EXCLUDE_FILES = {"README.md"}

VERSION_MIME = 0x56657273  # 'Vers'


def collect(root):
    """Return [(pbo_path, absolute_path)], config.cpp first, then sorted."""
    found = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = sorted(d for d in dirnames if d not in EXCLUDE_DIRS)
        for name in sorted(filenames):
            if name in EXCLUDE_FILES:
                continue
            absolute = os.path.join(dirpath, name)
            relative = os.path.relpath(absolute, root).replace(os.sep, "\\")
            found.append((relative, absolute))
    found.sort(key=lambda entry: (entry[0].lower() != "config.cpp", entry[0].lower()))
    return found


def cstring(text):
    return text.encode("utf-8") + b"\x00"


def entry(name, data_size, timestamp):
    # mime=0 (uncompressed), original size 0, reserved 0, timestamp, data size.
    return cstring(name) + struct.pack("<5I", 0, 0, 0, timestamp, data_size)


def pack(source, prefix, output):
    files = collect(source)
    if not files:
        sys.exit("no files found under " + source)

    timestamp = int(time.time())
    blobs = []
    names = []
    for (name, absolute) in files:
        data = open(absolute, "rb").read()
        if name.lower() == "config.cpp":
            data = rap.write(rap.parse_cpp(data.decode("utf-8")))
            name = "config.bin"
        names.append(name)
        blobs.append(data)
    files = [(n, a) for n, (_, a) in zip(names, files)]

    header = cstring("") + struct.pack("<5I", VERSION_MIME, 0, 0, 0, 0)
    header += cstring("product") + cstring("dayz ugc")
    header += cstring("prefix") + cstring(prefix)
    header += cstring("")

    for (name, _), blob in zip(files, blobs):
        header += entry(name, len(blob), timestamp)
    header += entry("", 0, 0)

    body = header + b"".join(blobs)
    digest = hashlib.sha1(body).digest()

    os.makedirs(os.path.dirname(output), exist_ok=True)
    with open(output, "wb") as handle:
        handle.write(body + b"\x00" + digest)

    for (name, _), blob in zip(files, blobs):
        print("  %-46s %8d bytes" % (name, len(blob)))
    print("\nwrote %s (%d bytes, %d files)" % (output, os.path.getsize(output), len(files)))
    return output


if __name__ == "__main__":
    # A config syntax error only shows up as a popup on game start, so refuse
    # to pack one. check_config.py explains what it found.
    import check_config
    problems = check_config.check(os.path.join(SOURCE, "config.cpp"))
    if problems:
        for number, message in problems:
            print("config.cpp:%d: %s" % (number, message))
        sys.exit("\nconfig.cpp has %d problem(s); not packing" % len(problems))

    pack(SOURCE, PREFIX, OUTPUT)
