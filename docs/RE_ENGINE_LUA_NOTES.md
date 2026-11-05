# RE Engine Lua 侧底层约定

从 Lua 里操作 RE Engine 运行时绕不开的一批硬事实：托管对象布局、矩阵约定、枚举取值、版本分水岭、
跨游戏命名差异。这些是引擎侧行为，和具体某个 mod 无关。

标注习惯：

- **实测**：在真实运行的 RE4（`sdk.get_tdb_version()` = 71）上用 Lua RPC 跑出来的结果，复现代码见第 8 节。
- **实践值**：没有当场验证，来自实际 mod 的用法与踩坑，换了引擎版本优先怀疑这类。
- `path:line`：能直接在本仓库里核对的实现，指向 `shared/sdk/` 或 `src/mods/bindings/`。

## 1. 托管对象的原生布局

`shared/sdk/ReClass_Internal_RE4.hpp:164`

```
REManagedObject   0x0008   uint32 referenceCount        size 0x10
REComponent       0x0010   REGameObject* ownerGameObject
                  0x0018   REComponent* childComponent
                  0x0020   REComponent* prevComponent
                  0x0028   REComponent* nextComponent   size 0x30
```

- **`+0x10` 就是 ownerGameObject**（实测）：`obj:read_qword(0x10)` 和
  `obj:call("get_GameObject"):get_address()` 在 `via.Transform` 和 `via.render.Mesh` 上都精确相等。
  先读字段、再 `sdk.is_managed_object(addr)` 验一遍，比直接调 `get_GameObject()` 稳。
- **`+0x8` 是引用计数**（实测）：活着的组件上读到 3、5、6 这类小整数；`obj:release()` 之后从 3 变成 2。
  注意别拿 Lua 的 `add_ref()` 做加计数实验——它有自己的记账表（`src/mods/bindings/Sdk.cpp:48`），
  连调三次计数不动。
- **判活**：`obj:read_qword(0x8) <= 0` 意味着这个对象只剩 REFramework 的引用撑着、游戏本体已经放手。
  这个阈值语义是**实践值**，实测只确认了字段含义。
- **`get_GameObject()` 是 internal exception 的常见来源**（实践值，无法在不动游戏状态的前提下复现）：
  值得无条件 pcall。
- **区分值类型和托管对象用 `sdk.is_managed_object()`**（实测）：值类型返回 false。
  网上流传的 `tostring(obj):find("::ValueType")` 在 tdb 71 上**抓不到任何东西**——托管对象打印成
  `sol.RETransform*: 0x...`，`via.vec3` / `via.mat4` 这类打印成 `sol.glm::vec<3,float,0>: 0x...`，
  两者都没有 `::ValueType` 字样。glm 值类型上也没有 `get_type_definition` / `read_qword`。

```lua
local function safe_gameobject(comp)
  if not comp or not sdk.is_managed_object(comp:read_qword(0x10)) then return nil end
  local ok, go = pcall(comp.call, comp, "get_GameObject()")
  return ok and go or nil
end
```

## 2. 变换矩阵

RE 的 `via.mat4` 是 4 行、每行 16 字节，**平移放在第 3 行**（实测）：

```lua
local pos   = mat4[3]:to_vec3()   -- 平移，与 transform:get_Position() 完全相等
local rot   = mat4:to_quat()      -- 旋转
local scale = Vector3f.new(magnitude(mat4[0]), magnitude(mat4[1]), magnitude(mat4[2]))
```

- 行偏移 0 / 16 / 32 / 48；`m[0]`..`m[3]` 都是 `glm::vec<4,float,0>`，`m[4]` 是 `nil`。
- **`#m` 会直接报错**（`attempt to get length of a sol.glm::mat<4,4,float,0> value`），别指望拿行数。
- **`get_Position()` 返回世界坐标**（实测）：它等于 `get_WorldMatrix()[3]` 的 xyz，而
  `get_LocalPosition()` 才是相对父级的局部值。想要“这个物体在世界里在哪”用前者就够。
- 反向写矩阵时同样 `new_mat[3] = translation:to_vec4()`。
- **存在 4x3 矩阵**：写回时得跳过第 4 行。（**实践值**，没在实测里遇到）
- 动 `via.Transform` 不要直接怼矩阵，走 `set_Position` / `set_Rotation` / `set_Scale`。（**实践值**）

## 3. 枚举成员连数值一起读

`via.ModuleEntry` 那类枚举，成员名和数值都可以运行期读出。枚举成员是**静态字段**：

```lua
local td = sdk.find_type_definition("via.ModuleEntry")
for _, f in ipairs(td:get_fields()) do
  if f:is_static() then
    local v = f:get_data(nil)
    if type(v) == "userdata" and type(v.call) == "function" then
      v = select(2, pcall(v.call, v, "ToString()"))
    end
    print(f:get_name(), v)
  end
end
```

实测（RE4）：`via.ModuleEntry` 共 **435** 个字段，其中 **434** 个是静态的——`is_static()` 过滤是必须的，
否则会混进实例字段。成员值 `get_data(nil)` 直接给 `number`（`Initialize = 0`、`InitializeLog = 1`、
`InitializeUbitus = 2`），所以 `ToString()` 那段分支在本 build 上用不到；留着是为了兼容返回 userdata 的类型。

REFramework 内部走同一条路——被注释掉的 `get_object_field<uint16_t>`
（`shared/sdk/Application.cpp:239`），字段绑定见 `src/mods/bindings/Sdk.cpp:1826`。

## 4. `via.Application` 入口表为什么 Lua 枚举不了

`shared/sdk/Application.hpp:13` 的 `Function`：`+0x0 entry`、`+0x8 func`、`+0x18 description`、
`+0x20 priority`（就是 `via.ModuleEntry` 的值）、`+0x22 type`，步长 `0xD0`。

表基址**没有固定偏移**：REFramework 自己得先扫特征码，MHRise 有个专用分支
（`89 81 ? ? ? ? 48 8B ? 48 81 C1 ? ? ? ?`），主分支是
`44 8B ? ? ? 00 00 4C 8D ? ? ? ? 00 41`；都失败再把 `+0x100` 到 `+0x1000` 按 8 字节暴力试
（`shared/sdk/Application.cpp:26-130`）。

实测（RE4）：`sdk.get_native_singleton("via.Application")` 能拿到非空指针，但
`via.Application` 的 TDB 里**没有** `get_function`，也没有 `get_ModuleEntry`——它只有一堆
`get_FrameCount` / `get_MaxFps` 之类的普通方法。想枚举入口只有两条路：读启动日志里的
`Hooked <name>` 行，或者硬编码名字表。

## 5. 版本与跨游戏差异

### TDB 版本分水岭

| 变化 | 判据 |
| --- | --- |
| natives 路径 `x64/` → `stm/` | `sdk.get_tdb_version() <= 67` 用旧值 |
| SCN 里 `via.Folder` 路径字段偏移 `0x68` → `0x38` | 同上 |
| RE2 / RE3 / RE7 进入 RT 版 | `>= 69` |

第二条的用法是 `read_unicode_string(obj:get_address() + offs)`。以上均为**实践值**，本机只能确认
RE4 的 `tdb_version` 是 71（即落在 RT 一侧）；`x64/` → `stm/` 的路径变化没在运行期验证过。

容易混的一点：另有一批 `version >= 35/44/46/48/52/53` 的判断，那是 **RSZ 文件头自己的 version**，
和 TDB 版本无关。（**实践值**）

### 命名空间

`sdk.game_namespace(name)` 只是给名字加**固定**前缀（`shared/sdk/RETypes.cpp:16`，本 build 加的是
`chainsaw.`），它并不做每游戏映射。所以它给出的名字**不一定存在**：

- 实测 RE4：`game_namespace("MathEx")` = `chainsaw.MathEx`，而 `sdk.find_type_definition("chainsaw.MathEx")`
  是 nil，真正存在的是 **`via.MathEx`**。RE2 那是 `app.MathEx`。
- 实测 RE4：`game_namespace("PlayerManager")` = `chainsaw.PlayerManager`，这个**确实存在**；
  `snow.player.PlayerManager`、`app.PlayerManager` 在 RE4 上都不存在。

结论：拿不准就逐前缀试 `find_type_definition`，别信 `game_namespace` 的返回值。

### 其它命名与取值差异

- **PlayerManager 要三级回退**：`game_namespace("PlayerManager")` → `snow.player.PlayerManager` →
  `chainsaw.CharacterManager`。（**实践值**，实测只确认了 RE4 命中第一级）
- **髋骨命名**：RE2/RE3 `COG`，RE7/RE8/DMC5/RE4 `Hip`，MHRise `Cog`，SF6 `C_Hip`。（**实践值**；
  想用 `via.render.Mesh:getJointNameList()` 验证，但实测该方法在 tdb 71 上返回 nil，故未验证）
- **生成 GameObject 得先找一个可写 folder**，各游戏不同：RE4 `Test`、RE2 `GUI_Rogue`、
  RE3 `RopewayGrandSceneDevelop`、SF6 `EmulatorContent`、DMC5 `Develop`、MHRise `Item_b_000`、
  RE8 `Debug`。实测 RE4 的 `Test` folder 存在（`scene:call("findFolder", "Test")` 非空），其余
  候选在本场景里都是 nil；“可写”没测，因为要真建对象。
- **材质参数类型码**：`1 = MaterialFloat`、`4 = MaterialFloat4`，决定该调
  `getMaterialFloat` / `getMaterialFloat4`；`0 = MaterialBool` 是实践值，实测扫了 200 个 mesh 的
  7115 个变量只出现 1 和 4，没见过 0。**调错 getter 不会报错**，只是静默返回 `0.0` / `false`——
  这就是必须自己查 `getMaterialVariableType` 的原因。
- **物理有两套 API**：`via.physics.System`（老）和 `via.dynamics.System`（新），实测两者在 RE4 上
  类型和 native singleton 都存在；RE2/RE3 偏刚体那套。（**实践值**）

## 6. 运行期造原生组件

`createComponent(sdk.typeof("via.xxx"))` + `.ctor()`。**collider 三件套必须自己 `add_ref()`**，
否则会被托管 GC 收走；`createComponent` 造出来的组件本身由 GameObject 持有，不需要额外 add_ref。

```lua
local colliders = go:call("createComponent", sdk.typeof("via.physics.Colliders"))
colliders:call(".ctor")
colliders:add_ref()

local userdata = sdk.create_instance("via.physics.UserData")
userdata:call(".ctor")
userdata:add_ref()

local new_collider = sdk.create_instance("via.physics.Collider")
new_collider:call(".ctor")
new_collider:add_ref()
new_collider:call("set_UserData", userdata)

colliders:call("setCollidersCount", 1)
colliders:call("setColliders", 0, new_collider)
```

刚体那侧：

```lua
local rb = go:call("createComponent", sdk.typeof("via.dynamics.RigidBodySet"))
rb:write_dword(0x48, 1)                 -- 置位写法，语义未考证
rb:call("setStatesCount", 1)
rb:call("set_StateName", "DynamicStates")
rb:call("setStateHash", 3416527488)
```

实测只确认了 `via.physics.Colliders` / `via.physics.Collider` / `via.physics.UserData` /
`via.dynamics.RigidBodySet` 四个类型都存在；**整段序列没有执行**，因为要真改场景。
而且这套序列**实测在别的场景里会触发游戏内部异常**，实践中通常被整段注释掉——只能当调用顺序参考，
不能当可用配方。（**实践值**）

## 7. 二进制 RSZ 的缺口

REFramework 本身不带 `.pfb` / `.scn` / `.user` 的反序列化器。Lua 侧读写这些文件要靠外部
[RE_RSZ](https://github.com/alphazolam/RE_RSZ) 项目的 `rsz_parser`，加每游戏一份
`reframework/data/rsz/rsz<game>.json`；文件缺失时只能自己去那个仓库下。（实测本机
`reframework/data/rsz/` 目录根本不存在，正好是这个状态）

和本仓库 `reversing/rsz/` 是互补关系：那边是 Python 侧用 Unicorn 模拟反序列化链、dump 出原生类型
布局 json；这边是 Lua 侧消费那份 json 去改文件。

## 8. 自己复核这些结论

**实测**那几条随时能原样重跑。在游戏运行状态下（`POST http://127.0.0.1:13377/rpc`，
协议见 [LUA_RPC.md](LUA_RPC.md)）：

```lua
local smt = sdk.find_type_definition("via.SceneManager")
local scene = sdk.call_native_func(sdk.get_native_singleton("via.SceneManager"), smt, "get_CurrentScene")
local tr = scene:call("findComponents", sdk.typeof("via.Transform"))[0]   -- [0] 起始，不是 1

print(sdk.get_tdb_version())              -- 第 5 节的判据，RE4 是 71
print(sdk.game_namespace("MathEx"))       -- 只是加前缀，不代表类型存在
print(sdk.find_type_definition("via.MathEx") ~= nil)
print(sdk.is_managed_object(tr))          -- 托管对象 true；via.vec3 之类给 false
print(tr:read_qword(0x8))                 -- 引用计数
print(tr:read_qword(0x10) == tr:call("get_GameObject"):get_address())   -- 布局 1 里那条
local m = tr:call("get_WorldMatrix")
print(m[3].x, m[3].y, m[3].z)             -- 与 get_Position() 相等
```

第 3 节那段静态字段循环本身就是枚举探测器，换个类型名即可。

两个 API 习惯，踩过才知道：`scene:findComponents()` 返回的是 `SystemArray`，**按 0 起始下标索引**
（`arr[0]`），和 Lua 绑定里其它 1 起始的容器不一样；`scene:get_Children()` 拿到的是
`via.Scene.<get_Children>d__1` 这种迭代器类，既没有 `get_Length` 也没有 `get_elements`，
遍历不了，要用 `findComponents` / `findFolder` 这类接口。