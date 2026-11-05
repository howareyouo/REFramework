"""Turn re_dump.py's JSON into a split, self-contained HTML doc set.

    python tools/lua_rpc/re_html.py re_types.json docs/RE4_API_HTML

Writes an `index.html` plus one page per volume. Types are sorted by name and
packed into volumes of roughly --max-mb, so each page embeds only its own slice
and opens straight from disk without a server or the other 40 MB. Volumes follow
the name ordering rather than namespace boundaries; the index lists them in order.
"""
import argparse
import json
import re
from html import escape
from pathlib import Path

# Compiler-generated / generic-instantiation noise, same filter as re_doc.py.
NOISE = re.compile(r"<|`|\bsz_|\bEmptyArray\b|\bInternal\b")

STYLE = """
:root { color-scheme: dark; }
* { box-sizing: border-box; }
body { margin: 0; font: 14px/1.55 ui-monospace, "Cascadia Mono", Consolas, monospace;
       background: #14161a; color: #cfd4dc; }
a { color: #7aa2e3; text-decoration: none; }
header { position: sticky; top: 0; z-index: 2; display: flex; gap: 12px; align-items: center;
         padding: 10px 16px; background: #1b1f26; border-bottom: 1px solid #2b313b; }
h1 { margin: 0; font-size: 15px; font-weight: 600; color: #e6e9ee; white-space: nowrap; }
header .meta { color: #78808d; font-size: 12px; white-space: nowrap; }
input[type=search] { flex: 1; min-width: 140px; padding: 6px 10px; border-radius: 6px;
                     border: 1px solid #333a45; background: #101216; color: inherit; font: inherit; }
input[type=search]:focus { outline: none; border-color: #4c8bf5; }
.hint { color: #78808d; }
main { display: grid; grid-template-columns: 300px 1fr; height: calc(100vh - 53px); }
#list { overflow: auto; border-right: 1px solid #2b313b; }
#list a { display: block; padding: 4px 12px; color: #aab2be;
          white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 13px; }
#list a:hover { background: #1b1f26; color: #e6e9ee; }
#list a.on { background: #22304a; color: #e6e9ee; }
#note { padding: 10px 12px; color: #78808d; }
#view { overflow: auto; padding: 16px 22px; }
#view h2 { margin: 0 0 4px; font-size: 18px; color: #e6e9ee; }
#view h3 { margin: 18px 0 6px; font-size: 13px; text-transform: uppercase;
           letter-spacing: .06em; color: #78808d; }
table { border-collapse: collapse; width: 100%; }
th, td { text-align: left; padding: 3px 10px 3px 0; border-bottom: 1px solid #21252c; vertical-align: top; }
th { color: #78808d; font-weight: 500; }
td.k { color: #8fd18f; white-space: nowrap; }
td.t, .sig .r { color: #9fb6d4; }
.sig .n { color: #8fd18f; }
.static { color: #d4a76a; font-size: 11px; }
mark { background: #3a4a1f; color: #eaf0d0; }
/* index page */
.idx { padding: 16px 22px; }
.idx table { max-width: 780px; }
.idx td.n { text-align: right; color: #78808d; }
"""

# Shared page script. Pages differ only in the embedded payload.
SCRIPT = r"""
const RAW = JSON.parse(document.getElementById("data").textContent);
const TYPES = Object.keys(RAW).sort().map(name => ({ name, ...RAW[name] }));
const listEl = document.getElementById("list"), viewEl = document.getElementById("view");
const qEl = document.getElementById("q");
let shown = TYPES, cursor = 0;

const esc = s => String(s).replace(/[&<>"]/g, c => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;" }[c]));

function highlight(text, terms) {
  let out = esc(text);
  for (const term of terms) {
    const re = new RegExp("(" + term.replace(/[.*+?^${}()|[\]\\]/g, "\\$&") + ")", "gi");
    out = out.replace(re, "<mark>$1</mark>");
  }
  return out;
}

function renderList(terms) {
  const frag = document.createDocumentFragment();
  const limit = Math.min(shown.length, 400);
  for (let i = 0; i < limit; i++) {
    const a = document.createElement("a");
    a.href = "#" + encodeURIComponent(shown[i].name);
    a.innerHTML = highlight(shown[i].name, terms);
    a.dataset.i = i;
    if (shown[i].name === current) a.classList.add("on");
    frag.appendChild(a);
  }
  const note = document.createElement("div");
  note.id = "note";
  note.textContent = shown.length ? `${shown.length} 个匹配，显示前 ${limit} 个` : "没有匹配的类型";
  listEl.replaceChildren(frag, note);
}

function filter() {
  const terms = qEl.value.toLowerCase().split(/\s+/).filter(Boolean);
  shown = terms.length ? TYPES.filter(t => {
    const hay = t.name.toLowerCase();
    return terms.every(term => hay.includes(term));
  }) : TYPES;
  cursor = 0;
  renderList(terms);
}

const sig = m => `<span class="sig"><span class="r">${esc(m.ret)}</span> <span class="n">${esc(m.name)}</span>(${m.params.map(esc).join(", ")})</span>`;

let current = "";

function renderType(t) {
  current = t.name;
  let html = `<h2>${esc(t.name)}</h2><p class="hint">${t.fields.length} fields · ${t.methods.length} methods</p>`;

  if (t.fields.length) {
    html += `<h3>Fields（offset 相对 this）</h3><table><tr><th>name</th><th>type</th><th></th><th>offset</th></tr>`;
    for (const f of t.fields) {
      html += `<tr><td class="k">${esc(f.name)}</td><td class="t">${esc(f.type)}</td>` +
              `<td>${f.static ? '<span class="static">static</span>' : ""}</td><td>${f.offset}</td></tr>`;
    }
    html += `</table>`;
  }

  const inst = t.methods.filter(m => !m.static).sort((a, b) => a.name.localeCompare(b.name));
  const stat = t.methods.filter(m => m.static).sort((a, b) => a.name.localeCompare(b.name));

  if (inst.length) {
    html += `<h3>Methods</h3><table>` + inst.map(m =>
      `<tr><td>${sig(m)}</td><td class="hint">obj:call("${esc(m.name)}", …)</td></tr>`).join("") + `</table>`;
  }
  if (stat.length) {
    html += `<h3>Static methods</h3><table>` + stat.map(m =>
      `<tr><td>${sig(m)}</td><td class="hint">sdk.call_native_func(nil, type_def, "${esc(m.name)}", …)</td></tr>`).join("") + `</table>`;
  }
  if (!t.fields.length && !t.methods.length) html += `<p class="hint">没有字段或方法。</p>`;

  viewEl.innerHTML = html;
  viewEl.scrollTop = 0;
  for (const a of listEl.querySelectorAll("a")) a.classList.toggle("on", a.textContent === t.name);
}

function open(name) {
  const t = TYPES.find(x => x.name === name);
  if (t) renderType(t);
}

qEl.addEventListener("input", filter);
qEl.addEventListener("keydown", e => {
  if (e.key === "ArrowDown" || e.key === "ArrowUp") {
    e.preventDefault();
    const links = listEl.querySelectorAll("a");
    if (!links.length) return;
    cursor = Math.max(0, Math.min(links.length - 1, cursor + (e.key === "ArrowDown" ? 1 : -1)));
    links.forEach((a, i) => a.classList.toggle("on", i === cursor));
    links[cursor].scrollIntoView({ block: "nearest" });
  } else if (e.key === "Enter") {
    const link = listEl.querySelectorAll("a")[cursor];
    if (link) location.hash = link.hash;
  }
});

window.addEventListener("hashchange", () => open(decodeURIComponent(location.hash.slice(1))));
filter();
if (location.hash) open(decodeURIComponent(location.hash.slice(1)));
"""


def page(title: str, payload: dict, extra_head: str = "", body: str = "") -> str:
    blob = json.dumps(payload, separators=(",", ":"), ensure_ascii=False).replace("</", "<\\/")
    return f"""<!DOCTYPE html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{title}</title>
<style>{STYLE}</style>
</head>
<body>
<header>
  <h1>{title}</h1>
  <span class="meta">{extra_head}</span>
  <input type="search" id="q" placeholder="搜索类型名（空格分隔多个关键词）" autofocus>
  <span class="hint">↑↓ 选择 · Enter 打开</span>
</header>
<main>
  <nav id="list"></nav>
  <article id="view"><p class="hint">从左侧选一个类型，或输入关键词搜索。</p></article>
</main>
<script id="data" type="application/json">{blob}</script>
<script>{SCRIPT}</script>
</body>
</html>
"""


def volume_label(names) -> str:
    """Name a volume after the one or two namespaces it spans, e.g. `chainsaw.a~b.*`."""
    prefixes = sorted({"global" if "." not in n else n.rsplit(".", 1)[0] for n in names})
    if len(prefixes) == 1:
        return prefixes[0] + ".*"
    return f"{prefixes[0]} ~ {prefixes[-1]}.*"


def pack(records: dict, max_bytes: int) -> list[tuple[str, dict]]:
    """Fill one volume at a time from the name-sorted records.

    Namespaces are a poor packing unit: a few roots hold megabytes while the long
    tail scatters over thousands of tiny ones, and every page repeats the ~4 KB
    template. Walking the sorted names instead keeps every volume full and the
    total close to the raw data size.
    """
    volumes: list[tuple[str, dict]] = []
    cur: dict = {}
    size = 0
    for name in sorted(records):
        rec = records[name]
        cost = len(json.dumps({name: rec}, separators=(",", ":"), ensure_ascii=False)) + 1
        if cur and size + cost > max_bytes:
            volumes.append((volume_label(cur), cur))
            cur, size = {}, 0
        cur[name] = rec
        size += cost
    if cur:
        volumes.append((volume_label(cur), cur))
    return volumes


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dump")
    ap.add_argument("outdir")
    ap.add_argument("--all", action="store_true", help="keep generic instantiations")
    ap.add_argument("--max-mb", type=float, default=2.0, help="target size of one volume")
    args = ap.parse_args()

    data = json.loads(Path(args.dump).read_text(encoding="utf-8"))
    if not args.all:
        data = {k: v for k, v in data.items() if not NOISE.search(k)}

    volumes = pack(data, int(args.max_mb * 1048576))

    outdir = Path(args.outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    for stale in outdir.glob("*.html"):
        stale.unlink()

    total_methods = total_fields = 0
    index_rows = []

    for i, (label, recs) in enumerate(volumes):
        # Volumes are numbered so they sort in name order and stay unique even
        # when two volumes end up covering the same namespace.
        filename = f"vol{i:02d}_{re.sub(r'[^A-Za-z0-9_.-]', '_', label).strip('_.')}.html"
        methods = sum(len(r["methods"]) for r in recs.values())
        fields = sum(len(r["fields"]) for r in recs.values())
        total_methods += methods
        total_fields += fields

        payload = {n: {"methods": r["methods"], "fields": r["fields"]} for n, r in recs.items()}
        (outdir / filename).write_text(
            page(label, payload, f"{len(recs)} types · {methods} methods · {fields} fields"),
            encoding="utf-8",
        )
        index_rows.append(f"<tr><td><a href='{filename}'>{escape(label)}</a></td>"
                          f"<td class='n'>{len(recs)}</td></tr>")

    (outdir / "index.html").write_text(f"""<!DOCTYPE html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>RE Engine API</title>
<style>{STYLE}</style>
</head>
<body>
<header><h1>RE Engine API</h1>
<span class="meta">{len(data)} types · {total_methods} methods · {total_fields} fields · {len(volumes)} volumes</span></header>
<div class="idx">
<p class="hint">从运行中的游戏经 Lua RPC 导出（<code>tools/lua_rpc/re_dump.py</code> + <code>re_html.py</code>）。
类型按名字排序后装箱成卷，每卷只内嵌自己的数据，搜索在当前卷内进行。</p>
<table><tr><th>volume</th><th>types</th></tr>{''.join(index_rows)}</table>
</div>
</body>
</html>
""", encoding="utf-8")

    biggest = max((len(p.read_bytes()) for p in outdir.glob("*.html") if p.name != "index.html"), default=0)
    print(f"{len(data)} types in {len(volumes)} volumes -> {outdir} (largest {biggest / 1048576:.1f} MB)")


if __name__ == "__main__":
    main()
