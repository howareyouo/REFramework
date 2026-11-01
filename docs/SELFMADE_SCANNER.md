# 自研扫描器（ScanSelf）可行性评估与迁移计划

本文记录把 kananlib `utility/Scan.hpp` + bddisasm 换成自研解码/走查层的评估结果。
姊妹项目 `re4-mod-manager` 已经完成同类替换（`src/scan.cpp`，DLL 体积 −48%），
本文的经验部分可直接复用那边的方法论。

**结论先行**：技术上可行，解码内核已实现并通过全量差分验证；但收益只有约 5.6%
（约 600 KB / 10.67 MB），而代价是重写约 1500–2500 行承载整个 SDK 定位逻辑的代码。
因此按阶段推进，不一次性替换。

## 1. 现状盘点

### kananlib 使用面

| 项目 | 数量 |
| --- | --- |
| 引用 `utility/Scan.hpp` 的文件 | 20 |
| `utility::scan(` 系列调用 | 60 |
| 实际用到的 Scan API 函数 | ~35 |
| 其余 kananlib 头（Module/String/Thread/ScopeGuard/Address/RTTI/Memory） | 各 1–13 处，量小 |

用到的 API 分三类：

- **纯字节/字符串搜索**：`scan`、`scan_reverse`、`scan_data`、`scan_ptr`、`scan_string(s)`、
  `scan_displacement_reference(s)`、`scan_relative_reference_strict`、`scan_opcode`、
  `scan_disasm` —— 不涉及指令语义，只是模块内搜索 + RIP 位移换算。
- **走查/CFG**：`exhaustive_decode`、`linear_decode`、`collect_basic_blocks`、
  `collect_linear_blocks`、`determine_function_bounds`、`find_landmark_sequence`、
  `get_disassembly_behind` —— 只需要**指令长度 + 分支类别 + 分支目标**。
- **函数定位**：`find_function_start(_unwind/_with_call)`、`find_function_from_string_ref`、
  `find_virtual_function_start`、`resolve_instruction`、`resolve_displacement` ——
  `.pdata` 查表 + 走查，同样只需要长度/分支信息。

### bddisasm 的直接使用者只有两个

1. kananlib 的 `Scan.cpp`（3246 行）。
2. `src/mods/IntegrityCheckBypass.{hpp,cpp}` —— `#include <bddisasm.h>`，用到 `INSTRUX`。

`FunctionHook` 走的是 **safetyhook**，`Relocate` 不用反汇编，所以 hook 引擎不受影响，
这是"可以动扫描层"的前提。

### IntegrityCheckBypass 真正需要的指令语义

| 位置 | 需求 | 是否必要 |
| --- | --- | --- |
| `:529-541` `pak_store_flags_hook` | `Operands[0]` 的 REG/MEM 信息 | **死代码**：`s_pak_load_check_insn` 只有声明（`hpp:69`），全项目从未赋值，永远是默认构造的 `INSTRUX{}`，该分支只会打 error 日志 |
| `:808-820` | `Mnemonic` 含 "TEST"、`Operands[0]` 是 GPR（取序号）、`Operands[1]` 是立即数 0x8/0x20/0x40 | 需要（`s_sha3_reg_index`） |
| `:1164-1165` | `Category == ND_CAT_CALL && Instruction == ND_INS_CALLNI` | 需要（间接 call 判定） |
| `:250-253`、`:783` | `BranchInfo.IsBranch / IsConditional / IsFar` | 需要，但解码器已有 |
| `:818` | `instrux.Length` | 需要，已有 |

结论：bddisasm 的**操作数级**需求只剩 `TEST r, imm` 一处，其余是分支/长度/助记符。
自研解码器补一个很小的操作数解析（ModRM + imm）即可覆盖。

## 2. 体积账（实测）

bddisasm 固定版本 `70db0957` 用 MinGW 编译成单目标文件后的段大小：

| 段 | 字节 | 说明 |
| --- | --- | --- |
| `.rdata` | 588,928 | 指令/操作数表，`NdDecodeEx` 必然全量引用 |
| `.text` | 17,984 | |
| `.data` | 13,728 | |
| 合计 | ~600 KB | 已开 `BDDISASM_NO_FORMAT`，更小 |

当前 `dinput8.dll` = 10,668,544 字节。所以全砍掉 bddisasm 约 **−5.6%**，
加上 kananlib `Scan.o` 也就 **−6~7%**。对比 `re4-mod-manager` 的 −48%：
那个 DLL 只有 1.9 MB，几乎全是扫描代码；REFramework 的 10.67 MB 里主要是
Lua/sol2/imgui/spdlog/OpenXR 等，扫描层占比很小。

**这就是不建议一次性替换的核心原因**——收益与风险不成比例。

## 3. 正确性验证：差分测试

`tools/scan_diff` 用 bddisasm 作为参考实现，对 `re4.exe` 整个代码段逐条比对指令长度。

```
[pdata] functions=508868 insns=25400722 ours_fail=42 (0.00017%) len_mismatch=33 (0.00013%)
```

- 2540 万条指令（只统计 `.pdata` 覆盖的函数体，排除数据段），长度分歧 **33 处**。
- 逐条检查：全部落在函数体内嵌的跳转表（`CF 20 BC 01`、`D6 01 FC 92` 这类 RVA 序列），
  真实直线代码零分歧。
- `ours_fail=42` 是危险方向（走查会提前中断），同样全部是数据字节。

这套工具本身是可复用资产：任何"自研解码器替代商用/第三方解码器"的项目，
都应该先建这个差分门禁，再谈替换。

## 4. 迁移阶段

| 阶段 | 内容 | 状态 |
| --- | --- | --- |
| 1 | 解码内核 `shared/utility/ScanSelf.{hpp,cpp}` + `tools/scan_diff` 差分门禁 | **已完成**（未接入编译，源码按显式清单收集，不影响现有构建） |
| 2 | 在其上实现 `utility::` 命名空间的 Scan API 子集（~35 个函数，沿用调用点签名） | 未开始 |
| 3 | 20 个文件的 `#include <utility/Scan.hpp>` 改为 `ScanSelf.hpp`；`IntegrityCheckBypass` 的 `INSTRUX` 字段换成自研结构（含 TEST 操作数解析） | 未开始 |
| 4 | CMakeLists 摘掉 `bddisasm` / `kananlib` 的 FetchContent 与 `target_link_libraries`，CI 出包，进游戏看 `reframework_log.txt` | 未开始 |

阶段 2 是主要工作量，也是最容易"看起来能跑但某个 SDK 定位失败"的地方：
kananlib 的 `scan` 有 7 个重载、分块 `memchr` 搜索、模块/范围两种寻址语义，
`find_landmark_sequence` 的走查语义要逐字节对齐。每迁一个 API 都应先用
`tools/scan_diff` 或离线探针在真实 exe 上验证命中地址与原实现一致，再改调用点。

### 回退

阶段 3 之前的改动都是新增文件，回退只需删掉 `shared/utility/ScanSelf.*` 与
`tools/scan_diff/`。阶段 3、4 之后回退用 `git revert`，因为 `CMakeLists.txt`
的 FetchContent 段落与 include 行都是独立提交。

## 5. 风险清单

- **静默失败**：定位不到函数不会崩，只会让某个功能不工作（例如 Hooks mod 初始化中止
  → `m_initialized` 永远 false → UI 不渲染）。这是最难查的一类回归，见
  `BRANCHES.md` 里 2026-10-26 的 `is_readable` 事件。
- **走查语义差异**：kananlib 的 `BREAK` 只结束当前分支，`linear_decode` 是全局中止，
  两者不同；自研走查器的 `Break` 是全局语义。移植时必须逐个对齐。
- **间接 jmp/call thunk**：`exhaustive_decode` 会跟随 `FF 25` / `FF 15` 解引用后的目标，
  RE Engine 大量函数以 thunk 开头，漏掉这层会让大量定位失败。
- **本机无 MSVC**：只能用 CI（`gh workflow run dev-release.yml --ref novr_re4`）验证编译，
  实机验证靠用户进游戏读日志。
