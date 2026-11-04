"""Dump every RE Engine type through the Lua RPC endpoint.

`sdk.get_num_types()` + `sdk.get_type(i)` enumerate the type database, so no
name list is needed. Each request asks for one slice of indices, which keeps it
under the instruction budget and the response size cap.

    python tools/lua_rpc/re_dump.py [out.json] [batch_size]
"""
import json
import sys
import urllib.error
import urllib.request

PORT = 13377


def lua(code, timeout_ms=30000):
    body = json.dumps({"code": code, "mode": "chunk", "timeout_ms": timeout_ms}).encode("utf-8")
    req = urllib.request.Request(
        f"http://127.0.0.1:{PORT}/rpc",
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout_ms / 1000 + 5) as resp:
            return json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        return json.loads(e.read().decode("utf-8"))


# Runs inside the game. JSON is assembled by hand because json.dump_string drops
# nothing but is slower; %q escaping keeps names safe.
SLICE = r"""
local first, last = FIRST, LAST
local function s(v)
    if type(v) == "string" then return string.format("%q", v) end
    if type(v) == "number" then return tostring(v) end
    if type(v) == "boolean" then return v and "true" or "false" end
    return "null"
end
local function arr(list)
    local parts = {}
    for i = 1, #list do parts[i] = s(list[i]) end
    return "[" .. table.concat(parts, ",") .. "]"
end

local types = {}
for i = first, last do
    local td = sdk.get_type(i)
    if td then
        local seen_m, methods = {}, {}
        for _, m in ipairs(td:get_methods()) do
            local ps = {}
            for _, p in ipairs(m:get_param_types()) do ps[#ps + 1] = p and p:get_full_name() or "?" end
            local ret = m:get_return_type()
            local key = m:get_name() .. "|" .. table.concat(ps, ",") .. "|" .. tostring(m:is_static())
            if not seen_m[key] then
                seen_m[key] = true
                methods[#methods + 1] = "{\"name\":" .. s(m:get_name())
                    .. ",\"static\":" .. s(m:is_static())
                    .. ",\"ret\":" .. s(ret and ret:get_full_name() or "void")
                    .. ",\"params\":" .. arr(ps) .. "}"
            end
        end

        local seen_f, fields = {}, {}
        for _, f in ipairs(td:get_fields()) do
            local ft = f:get_type()
            local key = f:get_name() .. "|" .. tostring(f:is_static())
            if not seen_f[key] then
                seen_f[key] = true
                fields[#fields + 1] = "{\"name\":" .. s(f:get_name())
                    .. ",\"type\":" .. s(ft and ft:get_full_name() or "?")
                    .. ",\"static\":" .. s(f:is_static())
                    .. ",\"offset\":" .. s(f:get_offset_from_base()) .. "}"
            end
        end

        types[#types + 1] = "{\"name\":" .. s(td:get_full_name())
            .. ",\"methods\":[" .. table.concat(methods, ",") .. "]"
            .. ",\"fields\":[" .. table.concat(fields, ",") .. "]}"
    end
end

return "[" .. table.concat(types, ",") .. "]"
"""


def main():
    out_path = sys.argv[1] if len(sys.argv) > 1 else "re_types.json"
    batch = int(sys.argv[2]) if len(sys.argv) > 2 else 200

    total = lua("return sdk.get_num_types()")
    if not total.get("ok"):
        sys.exit(f"cannot read the type count: {total.get('error')}")

    num_types = int(total["returns"][0])
    print(f"{num_types} types", file=sys.stderr)

    found = {}
    for first in range(0, num_types, batch):
        last = min(first + batch, num_types) - 1
        code = SLICE.replace("FIRST", str(first), 1).replace("LAST", str(last), 1)
        result = lua(code)

        if not result.get("ok"):
            print(f"  [{first}-{last}] {result.get('error')}", file=sys.stderr)
            continue

        for rec in json.loads(result["returns"][0]):
            found[rec["name"]] = rec
        print(f"  {last + 1}/{num_types} -> {len(found)} types", file=sys.stderr)

    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(found, f, indent=1, ensure_ascii=False)

    methods = sum(len(t["methods"]) for t in found.values())
    fields = sum(len(t["fields"]) for t in found.values())
    print(f"wrote {out_path}: {len(found)} types, {methods} methods, {fields} fields", file=sys.stderr)


if __name__ == "__main__":
    main()
