# Lua RPC — 在运行中的游戏里执行 Lua

REFramework 内置了一个只监听本机回环地址的 HTTP 端点。`POST /rpc` 会在游戏进程内、由拥有 Lua 状态的帧线程执行一段 Lua 代码，并把返回值、`print` 输出和错误信息以 JSON 返回。

这篇文章是给你（AI / 脚本作者）看的操作手册：怎么调、能返回什么、哪里会失败。

## 前提

- 游戏正在运行，且 `dinput8.dll`（本仓库构建产物）已被加载。
- `LuaRpcEnabled` 默认就是 `true`，端口默认 `13377`。可以在游戏内 REFramework 菜单 → `ScriptRunner` → `Lua RPC` 里改端口或关闭。
- 服务启动成功时日志里会有一行 `[ScriptRpc] Listening on http://127.0.0.1:13377/rpc`。

## 端点与协议

```
POST http://127.0.0.1:13377/rpc
Content-Type: application/json

{"code": "...", "mode": "chunk", "timeout_ms": 5000}
```

| 字段 | 类型 | 默认 | 含义 |
| --- | --- | --- | --- |
| `code` | string | 必填 | 要执行的 Lua 代码 |
| `mode` | `"chunk"` \| `"expr"` | `"chunk"` | `expr` 会自动在前面拼 `return `，适合写一行表达式 |
| `timeout_ms` | number | `5000` | 等待游戏帧线程执行的最长时间，范围 100–30000 |

成功响应：

```json
{"ok": true, "returns": [42], "print": "...", "elapsed_ms": 1}
```

失败响应：

```json
{"ok": false, "error": "rpc:1: attempt to index a nil value (global 'x')", "elapsed_ms": 0}
```

`returns` 是 Lua 多返回值的数组；`print` 只在有输出时出现。

## 推荐调用方式（Python）

`urllib` 没有额外依赖，也不会撞上 Windows shell 的引号转义坑。

```python
import json, urllib.request, urllib.error

def lua(code, mode="chunk", timeout_ms=5000, port=13377):
    body = json.dumps({"code": code, "mode": mode, "timeout_ms": timeout_ms}).encode("utf-8")
    req = urllib.request.Request(
        f"http://127.0.0.1:{port}/rpc",
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout_ms / 1000 + 5) as resp:
            return json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:          # 400 / 404 / 405 / 429 / 503 / 504
        return json.loads(e.read().decode("utf-8"))
```

用法：

```python
print(lua("sdk.get_tdb_version()", mode="expr"))     # 一行表达式
print(lua("return 1 + 2"))                           # 显式 return 的 chunk
print(lua('print("hi", 1, true)'))                   # 捕获 print 输出
```

想直接把整段脚本丢进去时，用 `mode="chunk"` 并在末尾写 `return`。

## 备用调用方式（curl，Git Bash）

注意 Git Bash 会把单引号里的内容原样传给 `curl`，内层 Lua 字符串要用 `\"` 或换行。

```bash
curl -s -X POST http://127.0.0.1:13377/rpc \
  -H 'Content-Type: application/json' \
  -d '{"code":"return sdk.get_tdb_version()"}'
```

Windows 上更稳的做法是把 JSON 写进文件再 `curl --data-binary @req.json`。

## 返回值怎么变成 JSON

- 全部由正整数 1..n 连续构成的表 → JSON 数组。
- 其它表 → JSON 对象（键会转成字符串）。
- `nil` → `null`，布尔 → `true/false`，整数 → 整数，浮点 → 浮点（`nan`/`inf` 变成字符串）。
- 函数 → `"<function>"`，协程 → `"<thread>"`。
- userdata / lightuserdata → `"<类型名: 0x地址>"`，例如 `"<via.SceneManager: 0x000001F4A2C3D4E0>"`。序列化不会调用 `__tostring`，所以这**不是**对象的可读内容，只用来确认拿到的是谁。
- 序列化限制：嵌套深度 6 层、每张表最多 200 个条目、整次响应最多 4000 个节点；超出的部分会变成 `"<truncated>"` 或 `"<table: max depth>"`。想看完整内容请自己 `select` 字段。

## 常用片段

**查类型是否存在、列出方法名**

```lua
local t = sdk.find_type_definition("via.SceneManager")
if not t then return "type not found" end
local names = {}
for _, m in ipairs(t:get_methods()) do names[#names + 1] = m:get_name() end
return names
```

**列出字段名**

```lua
local t = sdk.find_type_definition("app.SomeType")
local out = {}
for _, f in ipairs(t:get_fields()) do out[#out + 1] = f:get_name() end
return out
```

**拿托管单例并确认身份**

```lua
local s = sdk.get_managed_singleton("app.SomeManager")
return s and s:get_type_definition():get_full_name() or "nil"
```

**读 / 写字段**

```lua
local s = sdk.get_managed_singleton("app.SomeManager")
return s:get_field("SomeField")
```

写字段用 `set_field`（值类型和引用类型规则不同，先读一次确认类型）。

**调用方法**

托管对象上有 `:call("方法名", 参数...)`，最省事：

```lua
local mgr = sdk.get_managed_singleton("app.SomeManager")
return mgr:call("get_Size")
```

要按类型 + 名字调用（常见于原生单例），用 `sdk.call_native_func(对象, 类型, "方法名", 参数...)`；需要线程上下文的原生方法把 `sdk.get_thread_context()` 作为第一个参数传进去：

```lua
local t = sdk.find_type_definition("via.SceneManager")
local mgr = sdk.get_native_singleton("via.SceneManager")
return tostring(sdk.call_native_func(mgr, t, "get_CurrentScene", sdk.get_thread_context()))
```

**装一个 hook 观察参数**

```lua
local t = sdk.find_type_definition("app.SomeType")
local m = t:get_method("someMethod")
sdk.hook(m, function(args)
    -- args[1] = thread context, args[2] = this (静态方法是第一个参数), args[3..] = 实际参数
    local self = sdk.to_managed_object(args[2])
    print("called, this =", sdk.to_ptr(args[2]))
end, function(retval)
    return retval
end)
```

hook 会在下一次安装周期生效；之后每次调用都会走到你的回调，输出会进入日志。回调里**不要**长时间阻塞。

**持续采样再取回**

RPC 是「请求一次、游戏执行一次」的模型。想连续观察，就在一次调用里注册 `re.on_frame` 自己攒数据，再用另一次调用把攒到的内容取走。`fs.write` 是整文件覆盖写，路径相对于 REFramework 的数据目录。

```lua
-- 第一次：注册回调，攒最近 200 条样本
trace = {}
re.on_frame(function()
    local s = sdk.get_managed_singleton("app.SomeManager")
    trace[#trace + 1] = tostring(s and s:get_field("SomeField"))
    if #trace > 200 then table.remove(trace, 1) end
end)
return "registered"

-- 第二次：取回（没有样本时返回空数组）
return trace or {}
```

## 超时、预算与状态

- 代码在游戏帧线程上执行，**每次调用至少要等到下一帧**。重活会掉帧，别在 RPC 里跑长循环。
- 死循环防护：每次请求有 2000 万条指令的预算，超出后报 `instruction budget exceeded (possible infinite loop)`，并带 `"budget_exceeded": true`。
- 超时（504）通常意味着：游戏暂停 / 正在加载 / 帧线程卡在一个更长的调用里。等几百毫秒重试。
- 游戏还在加载、Lua 状态没建好时，返回 `{"ok": false, "error": "lua state is not ready yet (the game is still loading)"}`，重试即可。

## 错误码

| HTTP | 含义 |
| --- | --- |
| 200 | 执行完毕，看 `ok` |
| 400 | JSON 解析失败 / 缺 `code` |
| 404 | 路径不是 `/rpc` |
| 405 | 不是 POST |
| 429 | 队列已满（同时挂起超过 64 个请求） |
| 503 | 服务已停止 |
| 504 | 帧线程没在 `timeout_ms` 内执行完 |

## 限制与注意事项

- 只绑定 `127.0.0.1`，局域网连不上。
- **没有任何鉴权**：本机任意进程都能在你的游戏里执行 Lua，等价于本机任意代码执行。只在你信任的机器上开。
- 执行的是和你手写 mod 脚本同一个 Lua 状态，副作用（改字段、装 hook、写文件）都是真的。
- 一次只处理一个请求，其余排队；别用并发去压它。
- 返回值走 JSON，所以在 Lua 里已经能算完的东西不要返回整个对象图——既慢又会被截断。
