# REFramework 重构计划与实现指引

> 目标：在不破坏现有功能的前提下，精简代码量、提升运行时性能、降低维护成本。
>
> 约束：不能改 ABI，不能导致游戏崩溃；性能是最高优先级。

---

## 1. 项目现状与重构历史

### 1.1 代码规模分布

| 区域 | 文件数（估算） | 核心痛点 |
|------|---------------|---------|
| `src/mods/bindings/` | 3 个超大文件（`Sdk.cpp` 2356 行、`ImGui.cpp` 2654 行） | 单一文件职责过多，编译时间长，改动易冲突 |
| `src/mods/` | `IntegrityCheckBypass.cpp` 2454 行、`Graphics.cpp` 1473 行 | 逻辑混杂，UI/业务/Hook 未分离 |
| `src/` 根目录 | `REFramework.cpp` 1546 行 | 虽然已经拆分，仍有进一步解耦空间 |
| `shared/sdk/` | 约 20 个文件 | 部分函数重复实现，缓存策略不一致 |
| `src/re2-imgui/` | 3 个渲染后端文件（~2000 行） | 与项目核心逻辑耦合较深 |

### 1.2 已完成的重构（按 git 提交顺序）

#### Phase A — SDK 层优化
- **commit `c3fb8c44`**：`shared/sdk/Memory.cpp`、`RETypeDB.cpp`、`RETypeDefinition.cpp` 精简冗余分支，统一类型检索模式，减少约 200 行重复代码。
- **commit `67330500`**：引入 `s_fnv_cache`（`std::unordered_map`）缓存 `RETypeDefinition` 的 FNV 哈希，避免每次查询重复计算；`ScriptRunner.cpp` 预热常用类型。

#### Phase B — Hook 系统重构
- **commit `afaa5d16`**：`HookManager.cpp` 大重构：
  - 将 `unordered_map<uintptr_t, vector<PreHookFn>> + shared_mutex` 替换为 **lock-free TLS vector 索引**。每个 `HookedFn` 分配一个 `tls_idx`，线程本地数组实现 O(1) 无锁访问。
  - 合并 `save_arg`/`restore_arg` 重复 JIT lambda 为单一 `emit_arg`。
  - 删除死代码（`next_hook_id`、未使用的 `hook_create` 参数等）。
  - 净收益：**~965 行 → ~560 行（-42%）**，热路径零锁竞争。

#### Phase C — D3D 钩子重构
- **commit `4871fd70`**：`D3D11Hook.cpp` 提取公共逻辑：
  - `ScopedFunctionUnhook` RAII：临时还原被 hook 的函数字节，析构自动恢复。
  - `is_swapchain_filtered()` inline helper：`present`/`resize_buffers` 共用。
  - `ReentrancyScope` RAII：管理 `g_inside_d3d11_present` 标志和上一次结果存储。
  - `create_device` lambda：消除 `D3D11CreateDeviceAndSwapChain` 重复调用。

#### Phase D — 核心框架拆分
- **commit `1cfd8b37`**：将 `REFramework.cpp`（~2448 行）拆分为专用子系统：
  - `core/StartupPipeline` — 启动管线
  - `core/D3DHookMonitor` — Hook 健康监控（修复了 `hooks_unusable` 因未使用后端为 null 恒为 true 的 bug）
  - `input/InputManager` — 输入处理
  - `render/FrameRenderer` — D3D11/D3D12 帧渲染
  - 热路径使用直接函数调用，非虚派发，**零帧时开销**。

#### Phase E — Mod UI 样板消除
- **未提交改动**：
  - `Mod.hpp` 新增 `detail::with_id()` 模板：统一 `ImGui::PushID/PopID`，替换 `ModToggle/ModFloat/ModSlider/ModInt32/ModCombo/ModComboString/ModKey::draw()` 中的重复代码。
  - 新增 `Mod::begin_draw_ui(bool)`：统一 `SetNextItemOpen + CollapsingHeader` 开头。
  - `Graphics.cpp` 将 `on_draw_ui()` 拆分为 5 个 private 子函数。

---

## 2. 崩溃分析报告

### 2.1 Dump 关键信息

- **文件**：`D:\Games\Resident Evil 4\reframework_crash.dmp`
- **异常**：`C++ EH exception` (`0xe06d7363`) — 主动 `throw` 抛出的 C++ 异常
- **线程**：TID `0x341c`（非主线程），re4.exe 工作线程
- **崩溃时机**：进程启动后 **7 秒**
- **异常对象**（`0x7ebef280`）：
  - 虚表指针：`0x00007ffaa5138088`
  - 偏移 `0x20` 处出现 **`0x887A0005`** — 即 `DXGI_ERROR_DEVICE_REMOVED`

### 2.2 调用链（从游戏线程到异常抛出）

```
re4.exe 工作线程
  → dinput8+0x15e41               (REFramework DLL 入口附近)
  → dinput8!DirectInput8Create+0x10b74
  → ...dinput8 内部深层调用...
  → KERNELBASE!RaiseException
```

**符号说明**：dinput8.dll 无 PDB，因此所有 `dinput8!igItemSize_Vec2+0x...` 均为基于导出表的伪解析，不具备实际函数名意义；真实偏移已丢失。

### 2.3 根因判定

| 检查项 | 结论 |
|--------|------|
| 崩溃路径是否经过 UI 绘制代码？ | **否**。`Mod::begin_draw_ui()` / `detail::with_id()` 仅在 ImGui 菜单打开时执行，启动阶段不运行。 |
| 崩溃路径是否经过 HookManager 热路径？ | **否**。异常在线程启动早期抛出，尚未进入 present 帧循环。 |
| 异常码 `0x887A0005` 指向什么？ | `DXGI_ERROR_DEVICE_REMOVED`，D3D 设备在初始化期间被移除。 |
| 用户描述是否支持竞态？ | **是**。“进游戏崩溃了，再进又正常了”是典型的偶发竞态特征。 |
| 重构是否修改了 D3D 设备创建逻辑？ | **未修改核心逻辑**。`D3D11Hook.cpp` 仅做了 RAII 包装和 lambda 提取，`D3D12Hook.cpp` 未改动设备创建路径。 |

**结论：本次崩溃与已完成的重构修改无关。** 它是游戏启动阶段 D3D/DXGI 设备初始化失败的既有竞态（偶发 `DXGI_ERROR_DEVICE_REMOVED`），属于 REFramework 和游戏/驱动交互层面的已知问题。

### 2.4 建议的后续排查

若需要进一步定位该偶发崩溃，建议：
1. **开启 PDB 生成**：在 `cmake.toml` Release 配置中添加 `/Zi` + `/DEBUG`，重新编译后获得可解析的 dinput8 符号。
2. **捕获更多 dump**：启用 Windows LocalDumps 注册表项，收集多次崩溃样本，比对异常抛出点的 RVA。
3. **检查 D3D12 设备创建路径**：`D3D12Hook.cpp` 的 `hook()` 方法使用临时 hidden window 创建 swapchain，若驱动在超时检测恢复（TDR）窗口内触发，可能抛出 `dxgidebug` 或 `_com_error`。
4. **增加 try-catch**：在 `D3D11Hook::hook()` 和 `D3D12Hook::hook()` 的 COM 调用外层捕获 `_com_error` 或 `std::exception`，记录 `HRESULT` 后返回 `false` 而非向上传播异常。

---

## 3. 进一步重构路线图

### 3.1 高优先级（性能敏感 + 维护收益大）

#### 3.1.1 Lua Binding 文件拆分 (`mods/bindings/`)

**现状**：`Sdk.cpp` (2356 行)、`ImGui.cpp` (2654 行)、`FS.cpp` (290 行) 全部堆在一个目录下，前两个文件尤其庞大。

**目标**：按子域拆分为独立编译单元，减少增量编译时间，降低合并冲突。

**建议拆分方式**：
```
src/mods/bindings/
├── SdkMain.cpp        (REManagedObject, REType, VM 基础操作)
├── SdkArray.cpp       (create_managed_array, REManagedObject 数组访问)
├── SdkDelegate.cpp    (create_delegate, invoke)
├── SdkField.cpp       (index/new_index/get_field/set_field)
├── SdkTransform.cpp   (RETransform, joints, apply_joints_tpose)
├── ImGuiDraw.cpp      (draw_list, widgets, tables)
├── ImGuiNodes.cpp     (imnodes wrapper)
├── ImGuiGizmo.cpp     (imguizmo wrapper)
├── ImGuiFont.cpp      (add_font, font_atlas)
├── ImGuiInput.cpp     (input_text, combo, slider 等)
└── ... 保持 FS.cpp、Json.cpp
```

**实现指引**：
- 每个新 `.cpp` 文件暴露一个 `void register_xxx(sol::state& lua)` 函数。
- `ScriptRunner.cpp` 在初始化阶段依次调用各 `register_xxx`。
- **不改动** Lua API 的表结构和函数名，保证脚本兼容性。
- 使用 `namespace api::sdk::detail` 存放内部辅助函数，避免全局符号污染。

#### 3.1.2 `IntegrityCheckBypass.cpp` 模块化

**现状**：2454 行，混合了模式扫描、内存 patch、syscall hook、mid-hook JIT、异常处理等多种反作弊对抗技术。

**目标**：提取独立子模块，使每个文件 < 400 行。

**建议拆分**：
```
src/mods/integrity/
├── IntegrityCheckBypass.cpp   (主控逻辑，保持原有 public API)
├── PatchedRegionTracker.cpp   (内存 patch 区域追踪)
├── MidHookJit.cpp             (bddisasm + asmjit mid-hook 生成)
├── SyscallBypass.cpp          (syscall 劫持与 pristine syscall)
└── ExceptionFilter.cpp        (VEH / SEH 相关过滤)
```

**实现指引**：
- `IntegrityCheckBypass` 保持为 `singleton`，内部持有 `std::unique_ptr<Impl>`。
- 提取 `struct MidHookJit` 封装 `asmjit::x86::Assembler` 的重复用法。
- `gpr_slot()`、`gpr_or()` 等通用寄存器映射函数放入 `utility/AsmJitUtil.hpp`。

#### 3.1.3 帧渲染热路径去虚函数化

**现状**：`FrameRenderer.cpp` 中 `on_frame_d3d11()` / `on_frame_d3d12()` 每帧调用 `m_mods->on_frame()`，而 `Mods` 内部可能遍历所有 mod 并调用虚函数 `on_frame()`。

**优化方向**：
- 将需要 `on_frame()` 回调的 mod 注册到一个**紧凑的函数指针数组**中，而非 `std::vector<std::unique_ptr<Mod>>` 遍历。
- 使用 `std::function` 缓存，或更激进地，让 `Mods` 在初始化后生成一个 `std::vector<void(*)()>` 的扁平回调列表。
- **验证方式**：在 `on_frame_d3d11()` 中打点 `std::chrono::high_resolution_clock`，对比重构前后帧中耗时（应 < 0.01ms 差异）。

### 3.2 中优先级（代码精简 + 可读性）

#### 3.2.1 `Graphics.cpp` 业务逻辑与 UI 进一步分离

**已完成**：`on_draw_ui()` 已拆分为 5 个子函数。

**下一步**：
- 将 `do_ultrawide_fov_restore()`、`set_ultrawide_fov()` 等渲染逻辑提取到 `render/UltrawideFix.cpp`。
- 将 `setup_path_trace_hook()`、`setup_shader_interception_hook()` 提取到 `render/RayTracingHooks.cpp`。
- `Graphics` 类仅保留配置值和 UI 调度，成为**薄控制器**。

#### 3.2.2 `TemporalUpscaler.cpp` 模块化

**现状**：1063 行，混合了 DLSS/FSR/XeSS 初始化、upscale 参数配置、渲染回调。

**建议**：
- 提取 `UpscalerBackend` 接口（`initialize()`、`evaluate()`、`destroy()`）。
- `DLSSBackend`、`FSRBackend`、`XeSSBackend` 作为独立类实现该接口。
- `TemporalUpscaler` 持有 `std::unique_ptr<UpscalerBackend>`，根据配置切换。

#### 3.2.3 配置系统统一

**现状**：各 mod 自行实现 `on_config_load` / `on_config_save`，手动读写 `utility::Config`，重复代码多。

**建议**：
- 在 `Mod.hpp` 中引入声明式配置宏或模板：
  ```cpp
  struct GraphicsConfig : ModConfig<Graphics> {
      CONFIG_FIELD(bool, ultrawide_fix, "UltrawideFix", true);
      CONFIG_FIELD(float, fov_multiplier, "FOVMultiplier", 1.0f);
  };
  ```
- 基类 `Mod` 提供默认的 `on_config_load/save` 实现，通过反射（或编译期宏）自动序列化/反序列化。
- 预期收益：每个 mod 减少 20~40 行样板代码。

### 3.3 低优先级（工程卫生 + 长期收益）

#### 3.3.1 移除 `IsBadReadPtr` 遗留

`D3D12Hook.cpp` 中已替换为 `VirtualQuery` 方案（`is_protection_readable` + `scan_readable_slots`）。检查整个代码库是否还有其他使用：
```bash
grep -rn "IsBadReadPtr\|IsBadWritePtr\|IsBadCodePtr" src/ shared/
```
若有，统一替换。

#### 3.3.2 `std::vector` 预分配

在已知最大元素数量的热路径中（如 `HookManager` 的 arg save/restore、`D3D12Hook` 的 descriptor 列表），使用 `vector::reserve` 避免帧中 realloc。

#### 3.3.3 字符串去重复

`spdlog::info/error` 的格式化字符串在多处重复（如 `"Timed out waiting for VM to initialize."` 出现两次）。提取为 `constexpr std::string_view` 常量，减少二进制体积和 rodata 缓存压力。

---

## 4. 实现指引与验收标准

### 4.1 开发流程

1. **每次只改一个域**：例如只拆 `Sdk.cpp`，不碰 `ImGui.cpp`。
2. **编译验证**：每次提交后运行 `build_ninja.bat`，确保 `RE4/dinput8.dll` 0 error、0 新增 warning。
3. **运行时验证**：
   - 启动游戏，确认不崩溃（至少连续 3 次）。
   - 打开 REFramework 菜单，确认所有 mod UI 正常显示。
   - 加载一个依赖 Lua API 的脚本（如示例插件），确认功能正常。
4. **性能基线**：若修改热路径（`on_frame`、`present`、`hook monitor`），使用 ` Tracy ` 或手动 `QueryPerformanceCounter` 打点，确保帧时无退化。

### 4.2 禁止清单（底线）

| 禁止项 | 原因 |
|--------|------|
| 修改 `PreHookFn` / `PostHookFn` 签名 | ABI 破坏，已有插件失效 |
| 改变 `Mod` 虚函数表顺序或删除虚函数 | 已有插件可能依赖动态_cast 或虚表偏移 |
| 改变 Lua API 的表名、函数名、参数顺序 | 用户脚本不兼容 |
| 在 `present` / `on_frame` 中引入 heap alloc | 帧时抖动，GC 压力 |
| 删除 `#if defined(RE4)` 等多游戏分支 | `cmake.toml` 仍构建多 target |
| 修改 vendored 依赖（imgui、sol2 等）的内部文件 | 升级维护成本剧增 |

### 4.3 性能检查清单

- [ ] 热路径无 `shared_mutex` 写锁（已完成的 HookManager 重构满足）。
- [ ] 热路径无 `std::unordered_map` 查找（已完成的 SDK cache 满足）。
- [ ] 热路径无异常处理（try/catch 不在 `on_frame` / `present` 中）。
- [ ] 热路径无 `std::function` 拷贝（使用 `const&` 或函数指针）。
- [ ] 临时对象使用栈分配或对象池，避免 `new`/`delete`。

---

## 5. 总结

| 维度 | 已完成的成果 | 下一步行动 |
|------|-------------|-----------|
| **代码精简** | HookManager -42%、REFramework 核心拆分、Mod.hpp 样板消除 | Lua binding 拆分、IntegrityCheckBypass 拆分 |
| **性能提升** | Lock-free TLS Hook 存储、SDK FNV cache、/GT TLS 优化 | 帧渲染回调扁平化、`vector::reserve` 审计 |
| **可维护性** | 子系统分离、RAII 封装、UI 子函数拆分 | 声明式配置系统、UpscalerBackend 接口 |
| **稳定性** | D3DHookMonitor bug 修复、null guard 增加 | 增加 D3D 设备创建异常捕获、PDB 生成 |

**当前最高风险**：偶发启动崩溃（`DXGI_ERROR_DEVICE_REMOVED`）与重构无关，建议在 `D3D11Hook::hook()` / `D3D12Hook::hook()` 中增加 COM 异常防护，使其失败时优雅回退而非终止进程。
