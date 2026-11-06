# Lua RPC — 在运行中的游戏里执行 Lua

REFramework 内置一个 HTTP 端点：`POST /rpc` 在游戏的帧线程上执行一段 Lua, 把返回值、`print` 输出和错误以 JSON 返回. 默认开启, 默认绑 `127.0.0.1:13377`. 游戏内 REFramework 菜单 → `ScriptRunner` 里那个 `Lua RPC` 复选框决定开关.

## 请求与响应

```
POST http://127.0.0.1:13377/rpc
Content-Type: application/json

{"code": "return 1", "mode": "chunk", "timeout_ms": 5000}
```

| 字段 | 默认 | 含义 |
| --- | --- | --- |
| `code` | 必填 | Lua 源码, 直接放进来; 没有“上传文件”这回事 |
| `mode` | `"chunk"` | `"expr"` 会自动在前面补 `return ` |
| `timeout_ms` | `5000` | 等帧线程执行的时限, 100–30000 |

```json
{"ok": true, "returns": [42], "print": "...", "elapsed_ms": 1}
{"ok": false, "error": "rpc:1: attempt to index a nil value", "elapsed_ms": 0}
```

`returns` 是多返回值数组, `print` 只在有输出时出现.

## 怎么调

最省事是本仓库自带的参考客户端 [`lua_rpc/lua.py`](lua_rpc/lua.py)（纯标准库, 协议逻辑与本文一致, 显式绕过 `HTTP_PROXY`, `ok=false` 时退出码 1）：

```bash
python docs/lua_rpc/lua.py 'sdk.get_tdb_version()' expr
python docs/lua_rpc/lua.py --file probe.lua        # 多行脚本写文件更省事
python docs/lua_rpc/lua.py 'return 1' --timeout 15000 --port 13377
```

没有客户端时直接 curl（Git Bash 会原样传单引号, 内层字符串用 `\"`、换行用 `\n`）：

```bash
curl -s --noproxy '*' -H 'Content-Type: application/json' \
  --data-binary '{"code":"return sdk.get_tdb_version()"}' http://127.0.0.1:13377/rpc
```

`--file` 只是客户端把文件读进来塞进 `code`, 两条路径的请求完全一样.

## 关键约定（这几条踩过坑）

- 类型名必须带游戏的命名空间：RE4 是 `chainsaw.`. 拿不准用 `sdk.game_namespace("CharacterManager")`（必须传参）.
- 枚举类型用 `sdk.get_num_types()` + `sdk.get_type(i)`, 越界返回 `nil`. **没有** `sdk.get_types()`.
- 绑定返回的容器是 **1 起始**表（`get_methods` / `get_fields` / `get_param_types`）：用 `ipairs` 或 `1..#t`, `t[0]` 永远是 `nil`. 从 0 开始遍历会“看起来一个都没有”.
- `get_methods()` 会滤掉方法体是 stub 的方法, 计数可能偏少甚至为 0; 单个方法用 `td:get_method("名字")` 取, 不过滤（可能拿到 stub）.
- 实例方法 `obj:call("名字", ...)`; 静态方法 `sdk.call_native_func(nil, type_def, "名字", ...)`.

## 常用片段

```lua
-- 列方法名
local t = sdk.find_type_definition("via.SceneManager")
local out = {}
for _, m in ipairs(t:get_methods()) do out[#out + 1] = m:get_name() end
return out
```

```lua
-- 读字段 / 调方法
local s = sdk.get_managed_singleton("chainsaw.CharacterManager")
return s and s:call("get_PlayerManager") or "nil"
```

```lua
-- 装 hook（args[1]=thread context, args[2]=this, args[3..]=实际参数）
sdk.hook(sdk.find_type_definition("chainsaw.CharacterManager"):get_method("get_PlayerManager"),
  function(args) print("called") end,
  function(ret) return ret end)
```

```lua
-- 连续采样：这一次注册, 下一次请求取回
trace = {}
re.on_frame(function()
  local s = sdk.get_managed_singleton("chainsaw.CharacterManager")
  trace[#trace + 1] = tostring(s and s:get_field("SomeField"))
  if #trace > 200 then table.remove(trace, 1) end
end)
return "registered"
```

回调里不要长时间阻塞; hook 在下一个安装周期生效.

## 离线查表：`docs/RE4_API/`

`docs/RE4_API/` 是用这套 RPC 全量 dump 的类型表（13 页约 15 MB, `chainsaw` 18769 类型）, 不启动游戏也能查成员名和签名：

```bash
rg -A30 '^## `chainsaw\.CharacterManager`$' docs/RE4_API/chainsaw.md   # 方法行写作 `:返回类型 名字(参数)`
```

格式与省略项（backing field、`.ctor`、字段偏移、泛型实例、全部 `T[]`）见 [README](RE4_API/README.md). 文件里**没有 tdb 版本戳**, 打补丁即静默过期; 有游戏在跑时以 RPC 为准.

## 返回值与限制

- 表 → JSON：正整数 `1..n` 连续的表是数组, 其它表是对象; `nil`/布尔/整数/浮点直出, 函数 → `"<function>"`, userdata → `"<类型名: 地址>"`.
- 序列化上限：深度 6 层、每张表 200 项、整次响应 4000 节点. 超过深度的表变成 `"<table: max depth>"`; 单表超过 200 项的部分**静默丢弃**（不报错、不留标记）; 只有 4000 节点预算跑完才出现 `"<truncated>"`. 要看全就自己 `select`.
- 指令预算 2000 万条, 超出报 `instruction budget exceeded (possible infinite loop)` 并带 `"budget_exceeded": true`. 预算只数指令不数时间：`s = s .. "x"` 这类 O(n²) 拼接几十万条指令就能把帧线程占住几秒.
- 每次调用至少等一帧, 重活拆成分帧做. 请求体上限 256 KB.
- 每次只处理一个请求, 其余排队（同时挂起上限 64 个）.
- 错误码：`400` JSON 错 / 缺 `code` / HTTP 层错误（请求行或头解析失败、头部超 16 KB、请求体超 256 KB）, `404` 路径不对, `405` 不是 POST, `429` 队列满, `503` 服务已停, `504` 帧线程没在 `timeout_ms` 内跑完（游戏暂停/加载中/被更长的调用占着; 被超时放弃的请求不会执行, 已开始的会跑完, 等几百毫秒重试）.
- Lua 状态没建好时返回 `lua state is not ready yet (the game is still loading)`, 重试即可.
- **无鉴权**：默认只绑回环（`127.0.0.1`）, 本机任何进程都能在你的游戏里执行 Lua. 把 `Bind IP` 改成 `0.0.0.0` 或本机网卡地址就等于把这能力开放给局域网, 谁能连上谁就能执行. 执行的是和手写 mod 同一个 Lua 状态, 副作用都是真的. 地址填错（不是 IPv4 字面量）会显示 `Last error: invalid bind address ...` 并不监听.

原生偏移、跨游戏类型差异和 TDB 版本分水岭见 [RE_ENGINE_LUA_NOTES.md](RE_ENGINE_LUA_NOTES.md).
