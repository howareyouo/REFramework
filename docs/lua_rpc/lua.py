"""Lua-RPC client: execute Lua in the running game and print the JSON reply.

Protocol, limits and error codes: docs/LUA_RPC.md

    python docs/lua_rpc/lua.py 'sdk.get_tdb_version()' expr
    python docs/lua_rpc/lua.py 'return 1 + 2'
    python docs/lua_rpc/lua.py --file probe.lua
"""
import argparse
import json
import sys
import urllib.error
import urllib.request

# Straight to loopback: an HTTP_PROXY in the environment would otherwise answer
# for a dead endpoint and hand back an HTML error page instead of a refusal.
_opener = urllib.request.build_opener(urllib.request.ProxyHandler({}))


def lua(code, mode="chunk", timeout_ms=5000, port=13377):
    body = json.dumps({"code": code, "mode": mode, "timeout_ms": timeout_ms}).encode("utf-8")
    req = urllib.request.Request(
        f"http://127.0.0.1:{port}/rpc",
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    try:
        with _opener.open(req, timeout=timeout_ms / 1000 + 5) as resp:
            return _reply(resp.read(), f"http {resp.status}")
    except urllib.error.HTTPError as e:  # 400 / 404 / 405 / 429 / 503 / 504
        return _reply(e.read(), f"http {e.code}")
    except urllib.error.URLError as e:
        return {"ok": False, "error": f"no rpc endpoint on 127.0.0.1:{port} ({e.reason})"}


def _reply(raw, what):
    text = raw.decode("utf-8", "replace")
    try:
        return json.loads(text)
    except json.JSONDecodeError:
        return {"ok": False, "error": f"{what} was not JSON: {text.strip()[:300]}"}


def main():
    p = argparse.ArgumentParser(
        description="Execute Lua in the running game through REFramework's /rpc endpoint.")
    p.add_argument("code", nargs="?", help="Lua source; leave empty when using --file")
    p.add_argument("mode", nargs="?", default="chunk", choices=("chunk", "expr"),
                   help="chunk (default) runs the source as a block, expr prepends 'return '")
    p.add_argument("--file", help="read the Lua source from this file")
    p.add_argument("--timeout", type=int, default=5000, metavar="MS",
                   help="how long the frame thread may take to run it (100-30000)")
    p.add_argument("--port", type=int, default=13377)
    args = p.parse_args()

    if args.file:
        with open(args.file, encoding="utf-8") as f:
            code = f.read()
    elif args.code is not None:
        code = args.code
    else:
        p.error("pass the Lua source, or --file <path>")

    reply = lua(code, mode=args.mode, timeout_ms=args.timeout, port=args.port)
    print(json.dumps(reply, indent=1, ensure_ascii=False))
    return 0 if reply.get("ok") else 1


if __name__ == "__main__":
    sys.exit(main())
