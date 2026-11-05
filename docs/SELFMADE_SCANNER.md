# 自研扫描器（ScanSelf）可行性评估与迁移计划

本文记录把 kananlib `utility/Scan.hpp` + bddisasm 换成自研解码/走查层的评估结果。
姊妹项目 `re4-mod-manager` 已经完成同类替换（`src/scan.cpp`，DLL 体积 −48%），
本文的经验部分可直接复用那边的方法论。

**结论先行**：技术上可行，解码内核已实现并通过全量差分验证。bddisasm 本体已不再链接
（`shared/utility/bdshim/` 顶替，−~585 KB 静态库，已进 `dinput8.dll`）；
剩下的收益是把 kananlib `Scan.hpp` 也换掉，代价仍是重写约 1500–2500 行承载整个 SDK
定位逻辑的代码，所以按阶段推进。

## 1. 现状盘点

### kananlib 使用面

| 项目 | 数量 |
| --- | --- |
| 引用 `utility/Scan.hpp` 的文件 | 21 |
| `utility::scan(` 系列调用 | 60 |
| 实际用到的 Scan API 函数 | 30 |
| 其余 kananlib 头 | Module 23、String 13、Thread 5、ScopeGuard 4、Address 3、Memory 2、RTTI 1 |

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

### bddisasm 已由 bdshim 顶替

kananlib `Scan.cpp`（3246 行）和 `src/mods/IntegrityCheckBypass.{hpp,cpp}`
（`#include <bdshemu.h>`，用到 `INSTRUX`）都没改一行调用代码，链接到的却是
`shared/utility/bdshim/`（API 兼容 shim）：

- `CMakeLists.txt:157-169` 的 `bddisasm` 目标由 `bdshim.cpp` + `bdshim_text.cpp` +
  `ScanSelf.cpp` 组成，导出 `bddisasm::bddisasm` / `bddisasm::bdshemu` 别名；
  `cmake.toml:197-205` 侧已不再 FetchContent。
- shim 只实现调用点真正读到的字段（`Length`、`Mnemonic`、`Category`、`Instruction`、
  `BranchInfo`、`Operands` 的 REG/MEM/IMM 信息），**枚举数值与 bddisasm 不等价**——
  两边同名常量值不同，放在同一个翻译单元里会串味，`tools/bdshim_diff` 因此强制分 TU。
- 是不是真的等价由 `tools/bdshim_diff` 按**谓词**判定（见 §3）。

`FunctionHook` 走的是 **safetyhook**，`Relocate` 不用反汇编，所以 hook 引擎不受影响，
这是"可以动扫描层"的前提。

### IntegrityCheckBypass 真正需要的指令语义

| 位置 | 需求 | 是否必要 |
| --- | --- | --- |
| `:529-541` `pak_store_flags_hook` | `Operands[0]` 的 REG/MEM 信息 | **死代码**：`s_pak_load_check_insn` 只有声明（`hpp:68`），全项目从未赋值，永远是默认构造的 `INSTRUX{}`，该分支只会打 error 日志 |
| `:805`、`:808-820` | `Mnemonic` 含 "TEST"、`Operands[0]` 是 GPR（取序号）、`Operands[1]` 是立即数 0x8/0x20/0x40 | 需要（`s_sha3_reg_index`） |
| `:687` | `Mnemonic` 前缀 `VMOVUPS` | 需要 |
| `:1191-1192` | `Category == ND_CAT_CALL && Instruction == ND_INS_CALLNI` | 需要（间接 call 判定） |
| `:250`、`:783` | `BranchInfo.IsBranch / IsConditional / IsFar` | 需要，shim 已提供 |
| `:788` | `instrux.Length` | 需要，shim 已提供 |

结论：bddisasm 的**操作数级**需求只剩 `TEST r, imm` 和一处 REG/MEM 判别，
其余是分支/长度/助记符；shim 的 ModRM + imm 解析已覆盖，谓词差分零分歧。

## 2. 体积账（实测）

bddisasm 固定版本 `70db0957` 用 MinGW 编译成单目标文件后的段大小：

| 段 | 字节 | 说明 |
| --- | --- | --- |
| `.rdata` | 588,928 | 指令/操作数表，`NdDecodeEx` 必然全量引用 |
| `.text` | 17,984 | |
| `.data` | 13,728 | |
| 合计 | ~600 KB | 已开 `BDDISASM_NO_FORMAT`，更小 |

这段静态库已不再链接（`CMakeLists.txt:160` 记的也是 ~585 KB），当前 `dinput8.dll`
为 6,948,864 字节。

对比 `re4-mod-manager` 的 −48%：那个 DLL 只有 1.9 MB，几乎全是扫描代码；
REFramework 的大头是 Lua/sol2/imgui/spdlog/OpenXR，扫描层占比本来就小。

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

`tools/bdshim_diff` 是更强的门禁：它不比对「所有字段」（那会产出 3490 万条不可观测的
噪声），而是比对两边调用点实际会问的谓词——分支跟随、`LOCK INC [mem]`、`TEST r, imm`、
`CMP [mem], imm`、`ND_INS_CALLNI`、以及 RIP 相对/分支目标这类派生值。`re4.exe`
（230 MB、27,544,500 次解码）全部 gating 谓词 **0 分歧**，结论 `identical observable
behaviour`。已知噪声只有 `CMPS*`/`SCAS*` 的助记符归类（不 gating：唯一调用点还要
`op0==MEM && op1==IMM` 复合条件），以及 61 处长度分歧 / 92 次拒绝——这两项是
`ScanSelf` 自身的既有缺口，与 shim 无关，落在被拒字节（`D6`=SALC 之类、或内嵌表数据）上；
拒绝只会让走查多花一次单字节重同步，不会静默返回错误地址。

这套工具本身是可复用资产：任何"自研解码器替代商用/第三方解码器"的项目，
都应该先建这个差分门禁，再谈替换。

## 4. 迁移阶段

| 阶段 | 内容 | 状态 |
| --- | --- | --- |
| 1 | 解码内核 `shared/utility/ScanSelf.{hpp,cpp}` + `tools/scan_diff` 差分门禁 | **已完成** |
| 2 | 在其上实现 `utility::` 命名空间的 Scan API 子集（30 个函数，沿用调用点签名） | 未开始 |
| 3a | `IntegrityCheckBypass` 的 `INSTRUX` 换成自研结构（含 TEST 操作数解析） | **已完成**（以 `bdshim` 兼容层落地，调用点零改动） |
| 3b | 21 个文件的 `#include <utility/Scan.hpp>` 改为 `ScanSelf.hpp` | 未开始 |
| 4 | CMakeLists 摘掉 `kananlib` 的 FetchContent 与 `target_link_libraries`（`bddisasm` 的已摘），CI 出包，进游戏看 `reframework_log.txt` | 部分完成：`bddisasm` 已摘，`kananlib` 未摘 |

阶段 2、3b 是主要工作量，也是最容易"看起来能跑但某个 SDK 定位失败"的地方：
kananlib 的 `scan` 有 7 个重载、分块 `memchr` 搜索、模块/范围两种寻址语义，
`find_landmark_sequence` 的走查语义要逐字节对齐。每迁一个 API 都应先在真实 exe 上
验证命中地址与原实现一致，再改调用点。

### 回退

`bddisasm → bdshim` 这一层回退用 `git revert 26889617`，`CMakeLists.txt` 的
FetchContent 段落与 include 行是独立提交，冲突面很小。
尚未开始的 3b 之前没有生产文件被改，`tools/scan_diff/`、`tools/bdshim_diff/`
都是独立工具，删掉不影响构建。

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
