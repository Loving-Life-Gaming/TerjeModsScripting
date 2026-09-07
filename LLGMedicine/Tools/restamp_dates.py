#!/usr/bin/env python3
"""Shift every printed expiry date in the label script.

    python3 LLGMedicine/Tools/restamp_dates.py --shift -30     # 1989-1994
    python3 LLGMedicine/Tools/restamp_dates.py --base 2031     # 2031-2036
    python3 LLGMedicine/Tools/restamp_dates.py --show          # list, change nothing

The dates ship in 2026-2031. Move the whole window if your server's in-game
year sits somewhere else. Only the four-digit years inside `EXP`, `BEST BY` and
`STERILE UNTIL` are touched: month, day, lot codes, wording and the spread
between items all survive, so hand edits to label text are safe.
"""

import argparse
import os
import re
import signal
import sys

# Allow `... --show | head` without a BrokenPipeError traceback.
try:
    signal.signal(signal.SIGPIPE, signal.SIG_DFL)
except (AttributeError, ValueError):
    pass

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CONFIG = os.path.join(REPO, "LLGMedicine", "Scripts", "4_World", "LLGMedicineLabels.c")

# LOT 3699P - EXP 2030-04-06  /  - BEST BY 2030-03-23  /  - STERILE UNTIL 2031-03-11
STAMP = re.compile(r"\b(EXP|BEST BY|STERILE UNTIL) (\d{4})-(\d{2}-\d{2})\b")


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    group = parser.add_mutually_exclusive_group()
    group.add_argument("--shift", type=int, metavar="N",
                       help="add N years to every date (negative moves earlier)")
    group.add_argument("--base", type=int, metavar="YYYY",
                       help="move the earliest date to YYYY, keeping the spread")
    parser.add_argument("--show", action="store_true", help="print the dates and exit")
    parser.add_argument("--config", default=CONFIG, help="label script to rewrite")
    args = parser.parse_args()

    text = open(args.config, encoding="utf-8", newline="").read()
    stamps = STAMP.findall(text)
    if not stamps:
        sys.exit("no expiry stamps found in " + args.config)

    years = sorted({int(y) for _, y, _ in stamps})
    if args.show or (args.shift is None and args.base is None):
        print("%d dates across %d-%d" % (len(stamps), years[0], years[-1]))
        for verb, year, rest in sorted(set(stamps), key=lambda s: (s[1], s[2])):
            print("  %-14s %s-%s" % (verb, year, rest))
        return

    shift = args.shift if args.shift is not None else args.base - years[0]
    if shift == 0:
        print("nothing to do")
        return

    def bump(match):
        verb, year, rest = match.groups()
        return "%s %d-%s" % (verb, int(year) + shift, rest)

    updated, count = STAMP.subn(bump, text)
    with open(args.config, "w", encoding="utf-8", newline="") as handle:
        handle.write(updated)

    print("shifted %d dates by %+d years: %d-%d -> %d-%d"
          % (count, shift, years[0], years[-1], years[0] + shift, years[-1] + shift))
    print("re-pack with: python3 LLGMedicine/Tools/pack_pbo.py")


if __name__ == "__main__":
    main()
