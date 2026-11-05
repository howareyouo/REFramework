# Lua RPC — 在运行中的游戏里执行 Lua

REFramework 内置一个只监听 `127.0.0.1` 的 HTTP 端点：`POST /rpc` 在游戏的帧线程上执行一段 Lua，把返回值、`print` 输出和错误以 JSON 返回。默认开启，端口 `13377`，可在游戏内 REFramework 菜单 → `ScriptRunner` → `Lua RPC` 里改或关掉。启动日志里没有服务提示行，想确认在跑就直接探一发。

## 请求与响应

```
POST http://127.0.0.1:13377/rpc
Content-Type: application/json

{"code": "return 1", "mode": "chunk", "timeout_ms": 5000}
```

| 字段 | 默认 | 含义 |
| --- | --- | --- |
| `code` | 必填 | Lua 源码，直接放进来；没有“上传文件”这回事 |
| `mode` | `"chunk"` | `"expr"` 会自动在前面补 `return ` |
| `timeout_ms` | `5000` | 等帧线程执行的时限，100–30000 |

```json
{"ok": true, "returns": [42], "print": "...", "elapsed_ms": 1}
{"ok": false, "error": "rpc:1: attempt to index a nil value", "elapsed_ms": 0}
```

`returns` 是多返回值数组，`print` 只在有输出时出现。

## 怎么调

最省事是现成客户端：`G:/re4-mod-manager/tools/lua_rpc/lua.py`（协议逻辑与本文一致，显式绕过 `HTTP_PROXY`，`ok=false` 时退出码 1）：

```bash
RPC=/g/re4-mod-manager/tools/lua_rpc/lua.py   # 客户端不在本仓库，按你的实际路径改
python "$RPC" 'sdk.get_tdb_version()' expr
python "$RPC" --file probe.lua        # 多行脚本写文件更省事
python "$RPC" 'return 1' --timeout 15000 --port 13377
```

没有客户端时直接 curl（Git Bash 会原样传单引号，内层字符串用 `\"`、换行用 `\n`）：

```bash
curl -s --noproxy '*' -H 'Content-Type: application/json' \
  --data-binary '{"code":"return sdk.get_tdb_version()"}' http://127.0.0.1:13377/rpc
```

`--file` 只是客户端把文件读进来塞进 `code`，两条路径的请求完全一样。

## 关键约定（这几条踩过坑）

- 类型名必须带游戏的命名空间：RE4 是 `chainsaw.`。拿不准用 `sdk.game_namespace("CharacterManager")`（必须传参）。
- 枚举类型用 `sdk.get_num_types()` + `sdk.get_type(i)`，越界返回 `nil`。**没有** `sdk.get_types()`。
- 绑定返回的容器是 **1 起始**表（`get_methods` / `get_fields` / `get_param_types`）：用 `ipairs` 或 `1..#t`，`t[0]` 永远是 `nil`。从 0 开始遍历会“看起来一个都没有”。
- `get_methods()` 会滤掉方法体是 stub 的方法，计数可能偏少甚至为 0；单个方法用 `td:get_method("名字")` 取，不过滤（可能拿到 stub）。
- 实例方法 `obj:call("名字", ...)`；静态方法 `sdk.call_native_func(nil, type_def, "名字", ...)`。

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
-- 装 hook（args[1]=thread context，args[2]=this，args[3..]=实际参数）
sdk.hook(sdk.find_type_definition("chainsaw.CharacterManager"):get_method("get_PlayerManager"),
  function(args) print("called") end,
  function(ret) return ret end)
```

```lua
-- 连续采样：这一次注册，下一次请求取回
trace = {}
re.on_frame(function()
  local s = sdk.get_managed_singleton("chainsaw.CharacterManager")
  trace[#trace + 1] = tostring(s and s:get_field("SomeField"))
  if #trace > 200 then table.remove(trace, 1) end
end)
return "registered"
```

回调里不要长时间阻塞；hook 在下一个安装周期生效。

## 返回值与限制

- 表 → JSON：正整数 `1..n` 连续的表是数组，其它表是对象；`nil`/布尔/整数/浮点直出，函数 → `"<function>"`，userdata → `"<类型名: 地址>"`。
- 序列化上限：深度 6 层、每张表 200 项、整次响应 4000 节点，超出变 `"<truncated>"`。要看全就自己 `select`。
- 指令预算 2000 万条，超出报 `instruction budget exceeded (possible infinite loop)` 并带 `"budget_exceeded": true`。预算只数指令不数时间：`s = s .. "x"` 这类 O(n²) 拼接几十万条指令就能把帧线程占住几秒。
- 每次调用至少等一帧，重活拆成分帧做。请求体上限 256 KB。
- 每次只处理一个请求，其余排队（同时挂起上限 64 个）。
- 错误码：`400` JSON 错 / 缺 `code`，`404` 路径不对，`405` 不是 POST，`429` 队列满，`503` 服务已停，`504` 帧线程没在 `timeout_ms` 内跑完（游戏暂停/加载中/被更长的调用占着；被超时放弃的请求不会执行，已开始的会跑完，等几百毫秒重试）。
- Lua 状态没建好时返回 `lua state is not ready yet`，重试即可。
- 只绑回环，**无鉴权**：本机任何进程都能在你的游戏里执行 Lua。执行的是和手写 mod 同一个 Lua 状态，副作用都是真的。

`docs/RE4_API/` 是类型表的静态快照，怎么查见它自己的 [README](RE4_API/README.md)。
