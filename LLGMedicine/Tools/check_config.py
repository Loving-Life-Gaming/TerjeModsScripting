#!/usr/bin/env python3
"""Parse LLGMedicine/config.cpp the way the DayZ config parser does.

    python3 LLGMedicine/Tools/check_config.py

Catches the mistakes that only show up as a popup on game start, with the
file and line number. Run it before packing.

The rules it enforces:

  class Name;              forward declaration - no base class allowed here.
                           `class Name: Parent;` is what produced
                           "';' encountered instead of '{'" on line 70.
  class Name: Parent { }   definition - base class required to be declared
                           earlier in the same enclosing class.
  class Name { }           definition with no base.

It also checks brace balance, that every property line ends in a semicolon,
that no string contains a double quote (config strings cannot escape one), and
that CfgMods does not ask the game to draw a mod picture the PBO never ships.
"""

import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CONFIG = os.path.join(REPO, "LLGMedicine", "config.cpp")

FORWARD_WITH_BASE = re.compile(r"^\s*class\s+(\w+)\s*:\s*(\w+)\s*;")
FORWARD = re.compile(r"^\s*class\s+(\w+)\s*;")
DEFINITION = re.compile(r"^\s*class\s+(\w+)\s*(?::\s*(\w+)\s*)?$")
DEFINITION_INLINE = re.compile(r"^\s*class\s+(\w+)\s*(?::\s*(\w+)\s*)?\{")
PROPERTY = re.compile(r"^\s*[\w\[\]]+\s*=")


def strip_comment(line):
    """Drop a // comment, but not one inside a string (a URL has // in it)."""
    in_string = False
    for i, ch in enumerate(line):
        if ch == '"':
            in_string = not in_string
        elif ch == "/" and not in_string and line[i:i + 2] == "//":
            return line[:i]
    return line


def check(path):
    errors = []
    text = open(path, encoding="utf-8", newline="").read()
    lines = text.replace("\r\n", "\n").split("\n")

    declared = set()
    depth = 0
    for number, raw in enumerate(lines, 1):
        line = strip_comment(raw).rstrip()
        if not line.strip():
            continue

        bad = FORWARD_WITH_BASE.match(line)
        if bad:
            errors.append((number, "forward declaration cannot carry a base class: "
                                   "write `class %s;` not `class %s: %s;`"
                                   % (bad.group(1), bad.group(1), bad.group(2))))
            declared.add(bad.group(1))
            continue

        forward = FORWARD.match(line)
        if forward:
            declared.add(forward.group(1))
            continue

        define = DEFINITION.match(line) or DEFINITION_INLINE.match(line)
        if define:
            name, base = define.group(1), define.group(2)
            if base and base not in declared:
                errors.append((number, "base class `%s` is used before it is declared; "
                                       "add `class %s;` above" % (base, base)))
            declared.add(name)

        # A property may open a multi-line array, in which case the semicolon
        # arrives with the closing brace several lines later.
        stripped = line.rstrip()
        if (PROPERTY.match(line) and not stripped.endswith(";")
                and not stripped.endswith(("=", "{", ","))):
            errors.append((number, "property is missing its trailing semicolon"))

        for value in re.findall(r'=\s*"(.*)"\s*;\s*$', line):
            if '"' in value:
                errors.append((number, "string contains a double quote, which "
                                       "config syntax cannot escape"))

        depth += line.count("{") - line.count("}")
        if depth < 0:
            errors.append((number, "closing brace with no matching open brace"))
            depth = 0

    if depth != 0:
        errors.append((len(lines), "file ends with %d unclosed brace(s)" % depth))

    errors.extend(check_mod_picture(lines))
    return errors


def check_mod_picture(lines):
    """hidePicture=0 tells the game to render a mod icon. If no picture is
    declared there is nothing to render. The DayZ sample mod pairs
    picture="" with hidePicture=1; TerjeMedicine pairs a real .edds with
    hidePicture=0. Either is fine, one without the other is not."""
    picture = None
    hide = None
    line_no = 0
    for number, raw in enumerate(lines, 1):
        line = strip_comment(raw)
        found = re.match(r'\s*picture\s*=\s*"(.*)"\s*;', line)
        if found:
            picture = found.group(1)
        found = re.match(r"\s*hidePicture\s*=\s*(\d+)\s*;", line)
        if found:
            hide, line_no = int(found.group(1)), number
    if hide == 0 and not picture:
        return [(line_no, "hidePicture=0 asks the game to draw a mod icon, but "
                          "no non-empty `picture` is declared; either ship one "
                          "or set picture=\"\" with hidePicture=1")]
    return []


if __name__ == "__main__":
    path = sys.argv[1] if len(sys.argv) > 1 else CONFIG
    found = check(path)
    if not found:
        print("%s: OK" % os.path.relpath(path, REPO))
        sys.exit(0)
    for number, message in found:
        print("%s:%d: %s" % (os.path.relpath(path, REPO), number, message))
    print("\n%d problem(s)" % len(found))
    sys.exit(1)
