# Lua 片段

放到游戏里直接跑的 Lua 代码，配合 [Lua RPC](../LUA_RPC.md) 使用。每个文件都是自包含的：把整段代码作为 `code` 发出去即可，文件末尾没有副作用调用。

## 怎么发

```python
import json, urllib.request

def lua(code, timeout_ms=5000):
    body = json.dumps({"code": code, "mode": "chunk", "timeout_ms": timeout_ms}).encode()
    req = urllib.request.Request("http://127.0.0.1:13377/rpc", data=body,
                                 headers={"Content-Type": "application/json"}, method="POST")
    with urllib.request.urlopen(req, timeout=timeout_ms / 1000 + 5) as resp:
        return json.loads(resp.read().decode())

snip = open("docs/lua_snippets/costume_change.lua", encoding="utf-8").read()
print(lua(snip + "\nreturn set_costume(104)"))
# {"ok": true, "returns": [true, "已请求 Costume_104 (preset 837708748)"]}
```

片段里的函数是**每次调用都重新定义**的——Lua 状态在两次请求之间保留，所以你也可以先发一次片段定义函数，之后只发 `return set_costume(104)`。

## costume_change.lua — Leon 服装切换

Leon（RE4 主角，`chainsaw.PlayerBaseContext`，`KindID = 100000`）的外观。

| 函数 | 返回 |
| --- | --- |
| `set_costume(costume)` | `(ok, 说明)` |
| `get_costume()` | 当前生效的 `CostumeCharacter` 枚举值；不在映射表里时返回 preset ID |
| `list_costumes()` | `{ {costume=, preset=}, ... }`，按枚举值升序 |

`costume` 传 `CostumeCharacter` 的枚举值，例如 `104` = `Costume_04`。可用值见文件里的 `PRESETS` 表。

### 必须两步

```lua
cst:call("requestCostumeChange", go, 100000, preset, nil)  -- 1. 写 CostumeApplyingInfo
cm:call("requestCostumeChange", ctx, preset, nil)          -- 2. 推重建，这步少了模型不变
```

第 1 步的 `cst` 是 `CharacterManager:get_CostumeManager()`，第 2 步的 `cm` 是 `chainsaw.CharacterManager`、`ctx` 是 `PlayerBaseContext`。只做第 1 步时 `CostumeApplyingInfo.PresetID` 会变、请求队列也会被消费掉，但模型纹丝不动。

### 坑

- 第 3 个参数是 **preset ID**，不是 `CostumeCharacter` 枚举值。两者不同，例如 `Costume_04` 是枚举 `104` / preset `837708748`。
- Leon 的 KindID 是 `100000`（`ch0_a0z0`），不是 `ch1_c0z0`。
- `sdk.get_managed_singleton("chainsaw.CostumeManager")` 返回 `nil`，必须从 `CharacterManager:get_CostumeManager()` 拿。
- `sdk.create_delegate` 对泛型委托类型（`System.Action\`1<...>`）拿不到 runtime type，传 `nil` 回调即可，不要试图用委托取结果。
- `CostumeManager:get_PrefabRefUpdated()` 和 `BodyUpdater.SetupedCostumeMotionJackLayer` **不能**当成功判据：换成功时它们也是 `false`。

### 不支持：同步游戏内换装菜单

模型换了以后，打开换装菜单看到的高亮项还是旧的。菜单选中项存在 `GuiCostumeManager.CostumeSettingDict[*]._SelectId`，是另一份数据，`CostumeManager` 不会去更新它。

试过直接写 `_SelectId`、调 `setCurrentSettingID(menuKind, 枚举值)`、传 boxed `UInt32`，结果都不稳定：出现过写成 `0`、`getCurrentSettingID` 变成 `512052608` 这类不一致。`setCurrentSettingID` 有 4 个重载（`CostumeCharacter` / `CostumeAccessory` / `CostumeSwitch` / `UInt32`），传 `UInt32` 会落到 `CostumeSwitch` 上把数据写坏。**建议菜单只在游戏里操作，脚本别碰。**

如果不是写入而是读取，这几个接口是安全的：

```lua
local g = sdk.get_managed_singleton("chainsaw.GuiCostumeManager")
return g:call("getCurrentCostumeID", 100000)          -- 菜单认定的 preset ID
return g:call("getCurrentSettingCostumeID", 0)        -- 菜单高亮的 CostumeCharacter 枚举值
```
