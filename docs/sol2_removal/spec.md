# Spec: 从手写 Lua 绑定中移除 sol2

## 1. 目标

把 sol2 从 REFramework 的 Lua 绑定中彻底移除（头文件依赖、链接体积、运行期编组），
同时让 `tools/lua_conformance` 探针对比结果保持不变——只允许已记录的 3 条故意差异：

1. `mat4 index write out of range`：`nil` vs `ERR: matrix index out of range`
2. `ValueType construct`
3. `ValueType get_type_definition`

基线/手写版验证已完成（`%TEMP%\sol2_new.txt` vs `%TEMP%\hand_new.txt`，`diff.py` 仅上述 3 条）。
分支 `novr_re4_lua_hand_ut`，基线提交 `e74d7fd9`。

## 2. 现状与约束

- `src/mods/bindings/LuaStack.hpp` 已存在（约 1443 行，`lua_stack` 命名空间），是 sol2-free 的
  编组层，已读全文。提供 `check/get/get_pointer/get_ref/put/push_value/push_pointer/
  push_borrowed/construct_value/object/reference/protected_function/protected_function_result/
  variadic_args/stack_proxy/script_default_on_error/value_metatable/pointer_metatable/
  unique_metatable/user_metatable/const_*_metatable/qualified_name/container_qualified_name/
  value_gc/unique_value_gc`。
- `tools/lua_conformance/SOL2_REMOVAL.md` 是逐 token 迁移图（已存在，未提交）。
- 无本地 MSVC：只能推分支走 CI 取 `RE4` artifact 的 `dinput8.dll`（`AGENTS.md` 命令）。
- 四个文件含 `sol::` token：`LuaHand.hpp`(50)、`Sdk.cpp`(428)、`ScriptRunner.cpp`(58)、
  `ScriptRunner.hpp`(42)。`ImGui.cpp`/`Json.cpp`/`FS.cpp` 只调用 `s->lua().lua_state()`，零 token。
- 依赖面：`Mod.hpp:556-557`、`APIProxy.hpp:20-21`、`APIProxy.cpp:246-251`、
  `Graphics.hpp:25`、`Graphics.cpp:319` 使用 `sol::state&` 签名。
- `ScriptRpc.cpp:260` 仅用 `state.lua().lua_state()`。
- `sol::state_view` 站点：Sdk.cpp 54/146/203/289/338/1418/1429/3218/3414；ScriptRunner.cpp 74。
- `_sol_lua_push_*` 全局表由 `Sdk.cpp:3317-3321` 的 `lua.do_string` 初始化，被
  `sol_lua_push` 重载（Sdk.cpp 全局作用域，`ScriptRunner.hpp:98-101` 声明）与
  115× `sol::make_object` 使用。
- 关键语义：`sol::make_object(object*)/stack::push<T*>` 对 `detail::ManagedObjectBased` /
  `detail::CachedUserType` 走 ADL 重载做 add_ref/缓存。新层必须保留该 seam，否则引擎对象
  失去引用计数（崩溃风险）。

## 3. 设计决定（决策完整）

### D1. LuaStack.hpp 新增（保持现有 API 不变）

1. **受管指针推送 seam**
   - `template <typename T> struct pointer_tag {};`
   - `namespace detail { template <typename T, typename = void> struct pointer_push_override
     : std::false_type {}; template <typename T> struct pointer_push_override<T,
     std::void_t<decltype(lua_stack_push(pointer_tag<T>{}, (lua_State*)nullptr, (T*)nullptr))>>
     : std::true_type {}; }`
   - 现有 `push_pointer` 拆成 `push_pointer_plain`（原实现）+ `push_pointer`：
     `if constexpr (detail::pointer_push_override<T>::value) return
     lua_stack_push(pointer_tag<T>{}, L, obj); else return push_pointer_plain(L, obj);`
   - `push_borrowed` 与 Sdk 重载内部一律改调 `push_pointer_plain`（避免递归）。
   - `put<T>` 对指针仍调 `push_pointer`，因此 `make_object`/返回值自动走 seam。
   - 依赖 MSVC 宽松两阶段查找（与 sol2 原机制同形）；Sdk.cpp 的重载必须在实例化点可见。

2. **`table`（registry 引用语义，继承 `reference`）**
   `table(lua_State*, int)`、`table(nil_t)`、`lua_state()`：
   - `T get<T>(const char*)`、`std::optional<T> get_optional<T>(const char*)`
   - `T get<T>(lua_Integer)`、`std::optional<T> get_optional<T>(lua_Integer)`
   - `set(const char*, V&&)`、`set(lua_Integer, V&&)`、`set_nil(key)`
   - `set_cfunction(const char*, lua_CFunction)`
   - `int size()`（`luaL_len`）、`clear()`（标准 `lua_next` + `lua_settable(nil)` 循环）
   - `put(lua_State*, const table&)` 重载（push 引用本身，避免走 `push_value`）

3. **registry / global 帮助函数**
   - `table global_table(lua_State*, const char*)`、`table registry_table(lua_State*, const char*)`
     （不存在则创建并写入）
   - `template <typename T> T registry_get(lua_State*, const char*)`
   - `template <typename V> void registry_set(lua_State*, const char*, V&&)`
   - `template <typename T> std::optional<T> global_table_get_optional(lua_State*, const char*
     table, lua_Integer key)` / `global_table_set(lua_State*, const char*, lua_Integer, V&&)`
     （覆盖 `_sol_lua_push_*` 高频访问，语义等价于 sol2 每次 `sv["t"][k]`）

4. **`state`（替代 `sol::state`，仅满足 ScriptState 所需）**
   - `state()`：`luaL_newstate()`；`~state()`：`lua_close`
   - `lua_State* lua_state() const`
   - `void open_libraries()`：固定为 base/package/string/math/table/bit32/utf8/os/coroutine/
     debug（`luaL_requiref(..., 1)` + `lua_pop`），不含 io（`FS.cpp` 自行打开）
   - `table create_table(int array = 0, int hash = 0)`
   - `void do_string(const char* code)`（`luaL_dostring`，静默失败，与原 `do_string` 返回被忽略一致）
   - `void safe_script_file(const std::string& path)`：`luaL_loadfile` + `lua_pcall`，
     失败时抛出 `lua_stack::error("sol: <status> error: <msg>")`（复用 `status_names` 表）

### D2. 注册期约定变更（必须成对修改）

- registry `"state"`：写入改 `lua_pushlightuserdata(L, this)` + `lua_setfield(REGISTRY)`；
  读取改 `lua_getfield(REGISTRY,"state")` + `lua_touserdata` + `lua_pop`。
  （唯一读写方是本仓库代码；脚本侧 `debug` 库未暴露 registry。）
- `m_lua.registry()["package_path"]` 等 → `lua_stack::registry_get<std::string>` /
  `registry_set`；`registry()["package_searchers"]` → `registry_table`。
- `m_lua["package"]["path"]` → `lua_stack::global_table(L, "package")` + `table::get/set`。
- `m_lua.new_usertype<REFramework>` → `lh::install<REFramework>` + `lh::methods`，各 lambda
  改写成 `ScriptState` 的静态成员函数（内部用 `lua_stack::registry_get<ScriptState>` 取回
  `this`），函数指针交给 `lh::fthunk` / `lh::mthunk`。
- `m_lua.create_table()` / `lua["sdk"]=t` → `state::create_table` / `table::set` /
  `lua_setglobal`。

### D3. 逐文件变换

**LuaHand.hpp（去掉 `#include <sol/sol.hpp>`，改 `#include "LuaStack.hpp"`）**
- `sol::stack::check<T>`→`lua_stack::check<T>`；`get<T>`→`lua_stack::get<T>`；
  `get<T&>`→`lua_stack::get_ref<T>`；`get<T*>`→`lua_stack::get_pointer<T>`；
  `check<T*>`→`lua_stack::check<T*>`。
- `put`：`sol::nil_t`→`lua_stack::nil_t`；`sol::object`→`lua_stack::object`；泛型体改
  `lua_stack::put`。
- `get_object`→`lua_stack::object(L, index)`（保留 none→pushnil）。
- `get_rest`→`lua_stack::variadic_args(L, first)`。
- `slot_count`：`sol::this_state/this_main_state/this_environment` 三个特化删除，新增
  `slot_count<lua_State*>`；`get_arg` 对 `lua_State*` 直接返回 `L`；`get_param` 排除
  `lua_State*`（与 `object`/`variadic_args` 并列）。
- `get_self`→`lua_stack::get_pointer<T>`。
- 元表：`usertype_traits<T>::metatable()`→`lua_stack::value_metatable<T>()`；
  `<T*>`→`pointer_metatable<T>()`；`<const T>`→`const_value_metatable<T>()`；
  `<const T*>`→`const_pointer_metatable<T>()`；`user_metatable()`→`user_metatable<T>()`；
  `<unique_usertype<T>>`→`unique_metatable<T>()`；`qualified_name<U>()`→
  `lua_stack::qualified_name<U>()`（返回 `const std::string&`）。
- `sol::detail::make_destructor<T>()`→`&lua_stack::value_gc<T>`（保持既有唯一元表布局，
  见 D5）；`sol::detail::as_pointer_tag<T>`→`lua_stack::push_pointer_plain<T>`。
- `sol::weak_derive`/`mark_derived`：删除（`check_userdata` 在元表带 `class_check` 时
  总是查询）。
- `push_borrowed`：保留现有 `_sol_lua_push_usertypes` 全局缓存键逻辑，仅 push 改
  `push_pointer_plain`（与基线一致，缓存位置不变）。
- 保留 `lh::new_index_error` 文本：`sol: cannot set (new_index) into this object: no defined
  new_index operation on usertype`。

**Sdk.cpp**
- 机械替换（按此顺序）：`sol::this_state{L}`→`L`；`sol::this_state s`→`lua_State* s`；
  `sol::protected_function_result`→`lua_stack::protected_function_result`；
  `sol::protected_function`→`lua_stack::protected_function`；
  `sol::variadic_args`→`lua_stack::variadic_args`；`sol::object`→`lua_stack::object`；
  `sol::lua_nil`/`sol::nil`→`lua_stack::lua_nil`；`sol::error`→`lua_stack::error`；
  `sol::make_object`→`lua_stack::make_object`；`sol::script_default_on_error`→
  `lua_stack::script_default_on_error`；`sol::function`→`lua_stack::protected_function`。
- `sol::state_view{l}` 状态获取 → `lua_stack::registry_get<ScriptState>(l, "state")`
  （D2 的 lightuserdata 约定）。
- `_sol_lua_push_*` 表 → `lua_stack::global_table_get_optional` / `global_table_set`；
  原 `sv.load("return setmetatable({}, {__mode='v'})")()` → `lua_createtable` + `__mode="v"`。
- `sol::stack::get<sol::object>(l,-backpedal)`→`lua_stack::get<lua_stack::object>(...)`。
- `sol::stack::push<sol::detail::as_pointer_tag<T>>`→`lua_stack::push_pointer_plain<T>`。
- `sol::stack::push(l, sol::nil)`→`lua_stack::put(l, lua_stack::lua_nil)`。
- `sol::lua_table`（`objects/ref_counts/objects_top` 等）→ `lua_stack::table` 的
  `get/ get_optional/ set`（键为 `uintptr_t`/`lua_Integer`/字符串）。
- `sol::types<T*>` 的 `sol_lua_push` 重载 → `lua_stack_push(lua_stack::pointer_tag<T>,
  lua_State*, T*)`（函数名与签名按 D1.1），内部 push 一律 `push_pointer_plain`。
- 注册段：`lua.create_table()`→`lua_stack::state::create_table`；`sdk["f"]=fn`→
  `sdk.set_cfunction("f", lh::fthunk<&fn>)`（无捕获函数）或新增静态函数包装
  （原 lambda 改写为静态自由函数）；`sdk.new_enum`→新增 `lua_stack::set_enum`
  （`table.set_cfunction` 前先 `lua_pushinteger` 为值不可行，故用 `luaL_setfuncs`/逐项
  `table.set(name, int)` 生成常量表）；`lua["sdk"]=sdk`→`lua_setglobal`。
- 新增 `lua_stack_push` 重载保持在全局作用域、且在首次 `lua_stack::put` 实例化之前定义
  （现 `ScriptRunner.hpp` 的声明位置保留为 `lua_stack::pointer_tag` 形式）。

**ScriptRunner.hpp**
- 成员类型：`sol::protected_function`→`lua_stack::protected_function`（18 处）；
  `sol::reference`→`lua_stack::reference`；`sol::nil`→`lua_stack::lua_nil`；
  `sol::protected_function_result`→`lua_stack::protected_function_result`；
  `sol::object`→`lua_stack::object`。
- `sol::state m_lua`→`lua_stack::state m_lua`（`lua()` 返回 `lua_stack::state&`，
  `lua_state()` 调用点不变）。
- `TablePool::acquire(sol::state_view lua)`→`acquire(lua_State* L)`；
  `TableGuard` 持有 `lua_stack::table`，移动构造的 `sol::nil`→`lua_stack::lua_nil`。
- `sol_lua_push` 声明改 `lua_stack::pointer_tag<T>` 形式。

**ScriptRunner.cpp**
- 数学绑定（1-1145 行）：`math_metatable<T>()`→`lua_stack::value_metatable<T>().c_str()`；
  `sol::stack::get<T&>`→`lua_stack::get_ref<T>`；`get<T*>`→`lua_stack::get_pointer<T>`；
  `sol::stack::push(L, value)`→`lua_stack::put`；`&self[index]`→`push_pointer_plain<Vector4f>`；
  `sol::detail::demangle<sol::as_container_t<T>>`→`lua_stack::container_qualified_name<T>()`。
- `get_hook_storage(sol::this_state s)`→`(lua_State* s)`，registry 按 D2；返回值
  `lua_stack::make_object(s, result)`。
- 状态初始化 1146-1330：`registry()["state"]`、`open_libraries`、`create_table`、
  `new_usertype`、package 路径/搜索器按 D2 重写；`safe_script_file` 用
  `lua_stack::state::safe_script_file`。
- hook/回调分发 1330-1720：`sol::script_default_on_error(...)`→`lua_stack::...`；
  `sol::this_state`→`lua_State*`；`sol::object`→`lua_stack::object`。
- 2153/2177：`mod->on_lua_state_*_created(m_main_state->lua())`→传
  `m_main_state->lua().lua_state()`；2195-2201 package path 用 global_table。
- 1335/1562/1574/1616/1688：结果与错误处理改 `lua_stack` 对应物；
  `state->get_table_pool().acquire(state->lua())`→`acquire(state->lua().lua_state())`。

**Mod.hpp / APIProxy / Graphics**
- `virtual void on_lua_state_created(sol::state&)`→`(lua_State*)`；
  destroyed 同理。`Mod.hpp` 需要 `#include <lua.hpp>`（若尚未经 LuaHand 引入）。
- `APIProxy.cpp` 的 `invoke_cbs(..., state.lua_state())` 无需改调用点，只改签名。
- `Graphics::on_lua_state_created(sol::state& lua)`→`(lua_State* L)`，函数体若用
  `lua.create_table()` 等按 D2 重写（仅此一处）。

**CMakeLists.txt / 依赖**
- 移除 sol2 的 include 目录与 `dependencies/sol2`（或至少从 include path 删除），确认
  没有 TU 再 include `<sol/sol.hpp>`。

### D4. 需要逐字节保留的文本（探针比对）

`caught (...) exception`；`sol: cannot set (new_index) into this object: no defined new_index
operation on usertype`；`sol: no matching function call takes this number of arguments and the
specified types`；`sol: cannot call '__pairs/pairs' on type '<container_qualified_name>': it is
not recognized as a container`；`sol: <status> error: <lua message>`；
`unknown C++ exception`；`expected <type>, got <lua type>`。

### D5. 已知保留项（不改变行为）

- `lh::install(owns_gc=true)` 的 `__gc` 仍绑 `value_gc<T>`（当前两版一致；`unique_value_gc`
  留给后续单独修复，避免本迁移引入未验证的行为变化）。
- `lh::push_borrowed` 继续用 `_sol_lua_push_usertypes` 全局弱表，键为 value 元表名
  （与基线一致）。
- 只删 sol2 的使用，不改任何 Lua 可见 API 名称、参数顺序或错误文本。

## 4. 验证步骤（决策完整）

1. `git add` 新增 `LuaStack.hpp`、`SOL2_REMOVAL.md`、本 spec/tasks；提交草稿。
2. 全量改动后：`git push origin novr_re4_lua_hand_ut`。
3. `gh run list -R howareyouo/REFramework --branch novr_re4_lua_hand_ut --limit 3`；
   `gh run watch <run-id> -R howareyouo/REFramework --exit-status`。
4. `gh run download <run-id> -R howareyouo/REFramework -n RE4 -D /tmp`。
5. 安装：`D:\Games\Resident Evil 4\dinput8.dll` 先改名为
   `dinput8.dll_bak_yyyymmddhhmm`，再拷入新 dll（游戏运行中也可改名）。
6. 重启游戏使 dll 生效；等待 Lua RPC 就绪（`python -I docs/lua_rpc/lua.py "return 1"`）。
7. `python -I tools/lua_conformance/run.py --dll <dll> --out <report> --no-launch`
   （现成会话优先；必要时完整模式）。
8. `python -I tools/lua_conformance/diff.py <baseline> <report>`：只允许 3 条已记录差异；
   exit 1 属正常。
9. 启动日志无 sol2 相关错误；`dinput8.dll` 体积相比基线下降（记录前后字节数）。
10. 失败即回到第 2 步按 CI 编译错误修复，重复直至通过。

## 5. 风险与回滚

- 无本地编译器，只能 CI 迭代；每轮以编译错误为准。
- ScriptRunner 的状态初始化是最大改动面，若探针出现批量差异，优先怀疑
  `open_libraries` 顺序、`package.searchers` 拷贝、`safe_script_file` 错误文本。
- `lua_stack_push` ADL 检测依赖 MSVC 宽松查找；若 CI 报未定义/未找到，改为在
  `LuaStack.hpp` 增加显式 trait 特化点并由 Sdk.cpp 特化。
- 回滚：分支保留基线提交 `e74d7fd9`，可 `git revert` 或重置到该提交并重新出包。

## 6. 需要批准

请确认上述设计（尤其 D1.1 的 ADL seam 命名 `lua_stack_push`/`pointer_tag`、D2 的
registry `"state"` 改为 lightuserdata、D5 保留 `value_gc`）后再开始执行。
