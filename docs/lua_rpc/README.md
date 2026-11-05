# docs/lua_rpc

Standalone client for the in-game Lua RPC endpoint (`POST
http://127.0.0.1:13377/rpc`): sends a snippet of Lua, prints the JSON reply.
Pure standard-library Python — no install step, any Python 3 works. The
protocol, limits and error codes it speaks are documented in
[`LUA_RPC.md`](../LUA_RPC.md), which this directory accompanies.

## Run

```bash
python docs/lua_rpc/lua.py 'sdk.get_tdb_version()' expr
python docs/lua_rpc/lua.py --file probe.lua   # multi-line scripts are easier as files
```

- Bypasses `HTTP_PROXY` explicitly: a proxy env var would otherwise answer for
  the loopback endpoint with an HTML error page instead of a refusal.
- Exits 1 when the reply's `ok` is false, so it drops straight into pipelines
  and scripts.
- `--file` only reads the file into the request's `code` field; there is no
  upload path on the wire.
