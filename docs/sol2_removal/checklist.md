# Checklist: 移除 sol2

- [x] `src/` 下不再 include `<sol/sol.hpp>`，`grep -rn "sol::" src/` 只剩注释
- [x] `CMakeLists.txt` 不再声明或链接 sol2 目标
- [x] `dependencies/sol2` 已从工作区与索引中删除
- [x] CI 产出 RE4 artifact，`dinput8.dll` 可被游戏加载（REFramework 日志显示 startup complete）
- [x] Lua RPC 可用：`python -I docs/lua_rpc/lua.py "return 1"` 返回 `ok: true`
- [x] `tools/lua_conformance/run.py` 九个探针全部跑完（269 行报告）
- [x] `diff.py sol2 基线 新报告` 只剩 3 条已记录差异：
      `mat4 index write out of range`、`ValueType construct`、`ValueType get_type_definition`
- [x] `dinput8.dll` 体积低于改动前（4,040,192 → 3,615,744 字节）
