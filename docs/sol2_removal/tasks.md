# Tasks: 移除 sol2（按依赖顺序）

状态图例：`pending` / `in_progress` / `done`

## T1 — LuaStack.hpp 扩展（基础）

- [x] T1.1 增加 `<array>`/`<optional>` 等缺失 include（如缺）
- [x] T1.2 `pointer_tag<T>` + `detail::pointer_push_override` 检测
- [x] T1.3 `push_pointer` 拆分为 `push_pointer_plain` + 带 seam 的 `push_pointer`；
      `push_borrowed` 改调 plain
- [x] T1.4 `table` 类：ctor、`get<T>`/`get_optional<T>`（字符串与整数键）、`set`、
      `set_nil`、`set_cfunction`、`size`、`clear`、`put(table)`
- [x] T1.5 `global_table`/`registry_table`/`registry_get`/`registry_set`/
      `global_table_get_optional`/`global_table_set`
- [x] T1.6 `state` 类：ctor/dtor/`lua_state`/`open_libraries`/`create_table`/
      `do_string`/`safe_script_file`
- [x] T1.7 `reference` 增加 `operator=(nil_t)`（供 `m_current_hook_storage = lua_nil`）

验证：仅头文件语法自查 + grep 不再引入 sol2。产出随 T2-T4 一起过 CI。

## T2 — LuaHand.hpp 去 sol2

- [x] T2.1 include 换成 `LuaStack.hpp`
- [x] T2.2 `is/get/get_checked/get_ref/get_arg_ref/get_self/get_object/get_rest` 迁到 `lua_stack`
- [x] T2.3 `slot_count`：删除 `this_state/this_main_state/this_environment`，新增 `lua_State*`
- [x] T2.4 元表/名字/析构器/`as_pointer_tag`/`weak_derive` 替换
- [x] T2.5 `put` 重载与 `push_borrowed`（缓存键保持 `_sol_lua_push_usertypes`）

## T3 — Sdk.cpp 去 sol2

- [x] T3.1 机械替换 token 集（`this_state/object/protected_function/variadic_args/
      make_object/nil/lua_nil/error/script_default_on_error/function/protected_function_result`）
- [x] T3.2 `sol::state_view` 9 处 → `registry_get<ScriptState>`（lightuserdata 约定）
- [x] T3.3 `sol::lua_table`/`_sol_lua_push_*` → `lua_stack::table` 与 global/registry 帮助
- [x] T3.4 `sol_lua_push` 重载改 `lua_stack_push(lua_stack::pointer_tag<T>, ...)`；
      内部改 `push_pointer_plain`
- [x] T3.5 `open_sdk` 注册段：`create_table`/`set_cfunction`/`fthunk`/枚举/`lua_setglobal`

## T4 — ScriptRunner.hpp/.cpp

- [x] T4.1 hpp：成员类型替换（protected_function/reference/object/result）、`m_lua` 改
      `lua_stack::state`、`TablePool::acquire(lua_State*)`、`sol_lua_push` 声明改 tag
- [x] T4.2 cpp math 绑定（1-1145 行）替换
- [x] T4.3 cpp `get_hook_storage` + 状态初始化（1146-1330）重写
- [x] T4.4 cpp hook/回调分发（1330-1720）替换
- [x] T4.5 cpp 2153/2177 传 `lua_State*`；2195-2201 package path

## T5 — Mod/APIProxy/Graphics

- [x] T5.1 `Mod.hpp:556-557` 签名改 `lua_State*`（补 include）
- [x] T5.2 `APIProxy.hpp:20-21` / `APIProxy.cpp:246-251` 签名与调用
- [x] T5.3 `Graphics.hpp:25` / `Graphics.cpp:319` 签名与函数体
- [x] T5.4 grep 全仓确认 `sol::` 仅剩注释/无

## T6 — 构建与依赖

- [x] T6.1 `CMakeLists.txt` 移除 sol2 include/link
- [x] T6.2 grep 确认无 `<sol/sol.hpp>`
- [x] T6.3 提交（可拆：基础/绑定/状态/清理）

## T7 — CI 构建

- [x] T7.1 `git push origin novr_re4_lua_hand_ut`
- [x] T7.2 `gh run list -R howareyouo/REFramework --branch novr_re4_lua_hand_ut --limit 3`
- [x] T7.3 `gh run watch <run-id> -R howareyouo/REFramework --exit-status`
- [x] T7.4 `gh run download <run-id> -R howareyouo/REFramework -n RE4 -D /tmp`
- [x] T7.5 编译失败 → 修复 → 重复 T7.1-T7.4

## T8 — 游戏内一致性验证

- [x] T8.1 备份并在 `D:\Games\Resident Evil 4\` 安装新 `dinput8.dll`
- [x] T8.2 重启游戏；等 RPC 就绪（`python -I docs/lua_rpc/lua.py "return 1"`）
- [x] T8.3 `python -I tools/lua_conformance/run.py --dll <dll> --out <report> --no-launch`
- [x] T8.4 `diff.py <baseline> <report>`：仅 3 条已记录差异
- [x] T8.5 记录 `dinput8.dll` 体积变化

## T9 — 清理

- [x] T9.1 若验证通过，删除 `dependencies/sol2`（仅在 CMake 已不引用后）
- [ ] T9.2 更新 `SOL2_REMOVAL.md` 标记完成（可选，仅在用户要求时）

## 验收标准

- CI 产出 RE4 `dinput8.dll`，游戏可启动、Lua RPC 可用。
- `diff.py` 输出恰好 3 条已记录差异（exit 1 正常）。
- 全仓 `grep -r "sol::" src/` 为空（注释除外）。
- dll 体积低于改动前。
