"""Turn re_dump.py's JSON into browsable documentation.

    python tools/lua_rpc/re_doc.py re_types.json docs/RE4_API

Writes one Markdown page per namespace plus an index. Generic instantiations
and compiler-generated names are filtered out by default; pass --all to keep
them. Types with no fields and no methods carry no information and are always
dropped.
"""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

# Compiler-generated / generic-instantiation noise.
NOISE = re.compile(r"<|`|\bsz_|\bEmptyArray\b|\bInternal\b")


def is_noise(name: str) -> bool:
    return bool(NOISE.search(name))


def safe(name: str) -> str:
    return re.sub(r"[^A-Za-z0-9_.-]", "_", name) or "unnamed"


def signature(method: dict) -> str:
    params = ", ".join(method["params"])
    return f"{method['ret']} {method['name']}({params})"


def render_type(rec: dict) -> str:
    lines = [f"## `{rec['name']}`", ""]

    fields = rec["fields"]
    if fields:
        lines += ["**Fields**", "", "| name | type | static | offset |", "| --- | --- | --- | --- |"]
        for f in sorted(fields, key=lambda x: (not x["static"], x["offset"], x["name"])):
            lines.append(f"| `{f['name']}` | `{f['type']}` | {'yes' if f['static'] else ''} | {f['offset']} |")
        lines.append("")

    methods = rec["methods"]
    if methods:
        statics = sorted((m for m in methods if m["static"]), key=lambda m: m["name"])
        members = sorted((m for m in methods if not m["static"]), key=lambda m: m["name"])

        if members:
            lines += ["**Methods**", "", "```lua"]
            lines += [f":{signature(m)}" for m in members]
            lines += ["```", ""]

        if statics:
            lines += ["**Static methods**", "", "```lua"]
            lines += [f"sdk.call_native_func(nil, type_def, \"{m['name']}\", ...)  -- {signature(m)}"
                      for m in statics]
            lines += ["```", ""]

    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dump")
    ap.add_argument("outdir")
    ap.add_argument("--all", action="store_true", help="keep generic instantiations")
    args = ap.parse_args()

    data = json.loads(Path(args.dump).read_text(encoding="utf-8"))
    outdir = Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)

    buckets: dict[str, list] = defaultdict(list)
    for name, rec in data.items():
        if not args.all and is_noise(name):
            continue
        if not rec["fields"] and not rec["methods"]:
            continue
        bucket = name.split(".")[0] if "." in name else "(global)"
        buckets[bucket].append(rec)

    index = ["# RE Engine API index", "",
             "Generated from a running game via `tools/lua_rpc/re_dump.py`. "
             "Call a member with `obj:call(\"name\", ...)`; statics go through `sdk.call_native_func`. "
             "Type names are dotted, so search with `rg '^## `chainsaw\\.CharacterManager`' chainsaw.md`.", "",
             "| root namespace | types | file |", "| --- | --- | --- |"]

    for bucket in sorted(buckets):
        recs = sorted(buckets[bucket], key=lambda r: r["name"])
        page = [f"# `{bucket}.*`", "", f"{len(recs)} types.", ""]
        for rec in recs:
            page.append(render_type(rec))

        filename = safe(bucket) + ".md"
        (outdir / filename).write_text("\n".join(page), encoding="utf-8")
        index.append(f"| `{bucket}` | {len(recs)} | [{filename}]({filename}) |")

    (outdir / "README.md").write_text("\n".join(index) + "\n", encoding="utf-8")
    total = sum(len(v) for v in buckets.values())
    print(f"{total} types in {len(buckets)} namespaces -> {outdir}")


if __name__ == "__main__":
    main()
