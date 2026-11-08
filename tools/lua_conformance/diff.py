"""Compare two reports written by run.py, key by key.

    python tools/lua_conformance/diff.py baseline.txt candidate.txt

Exit status is 0 when the two agree and 1 when they do not, so this can be the
last command of a script that only proceeds on a match.

Both reports are read as `key = value` lines grouped under `### probe` headers.
Comparing keys rather than raw lines means a line that moved or a probe that
reported in a different order is not a difference; only a changed value is.
"""
import argparse
import sys
from pathlib import Path


def parse(path):
    reports = {}
    probe = None

    for line in Path(path).read_text(encoding="utf-8").split("\n"):
        if line.startswith("### "):
            probe = line[4:].strip()
            reports[probe] = {}
            continue

        if not line or probe is None:
            continue

        key, sep, value = line.partition(" = ")

        if not sep:
            reports[probe].setdefault("@raw", []).append(line)
            continue

        reports[probe][key] = value

    return reports


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    p.add_argument("baseline", help="report to compare against (e.g. sol2)")
    p.add_argument("candidate", help="report being checked (e.g. hand-written)")
    args = p.parse_args()

    baseline = parse(args.baseline)
    candidate = parse(args.candidate)

    differences = 0

    for probe in sorted(set(baseline) | set(candidate)):
        if probe not in baseline:
            print("+ %s: only in %s" % (probe, args.candidate))
            differences += 1
            continue

        if probe not in candidate:
            print("- %s: only in %s" % (probe, args.baseline))
            differences += 1
            continue

        left, right = baseline[probe], candidate[probe]

        for key in sorted(set(left) | set(right)):
            if key not in left:
                print("%s  %s: only in candidate -> %s" % (probe, key, right[key]))
                differences += 1
            elif key not in right:
                print("%s  %s: only in baseline -> %s" % (probe, key, left[key]))
                differences += 1
            elif left[key] != right[key]:
                print("%s  %s:\n    baseline: %s\n    candidate: %s"
                      % (probe, key, left[key], right[key]))
                differences += 1

    if differences == 0:
        print("identical: %d probes, %d keys"
              % (len(candidate), sum(len(v) for v in candidate.values())))
        return 0

    print("\n%d difference(s)" % differences)
    return 1


if __name__ == "__main__":
    sys.exit(main())