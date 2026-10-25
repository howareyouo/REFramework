# 分支策略 (BRANCHES.md)

本 fork 的三条分支**互不共享提交历史**(orphan 线),不能用 git merge 互相合并,
跨分支同步一律用 `git cherry-pick`。

## 分支一览

| 分支 | 定位 | CI 目标 | 开发策略 |
|------|------|---------|----------|
| `novr_re4` | **日常开发主线**,RE4 专用(-16 万行非 RE4 代码) | `[RE4]` | 所有新功能、修复都在这里做 |
| `novr` | 其他 RE Engine 游戏的冻结备份(通用版,去 VR) | RE2/RE3/RE4/RE7/RE8/RE9/DMC5/MHRISE/SF6/DD2/MHWILDS/PRAGMATA/MHSTORIES3 等 | 平时不动;需要给其他游戏出包时才 cherry-pick 关键修复 |
| `main` | 上游(praydog/REFramework)跟踪线,唯一保留完整上游历史 | — | 只用来查/摘上游提交,不在上面开发 |

## 日常工作流

1. **新功能 / 修复** → 在 `novr_re4` 上提交,推送到 `origin/novr_re4`。
2. **触发 CI 构建**:Actions → Dev Release 是 `workflow_dispatch`,按分支 ref 手动触发:

   ```sh
   gh workflow run dev-release.yml -R howareyouo/REFramework --ref novr_re4
   gh run download <run-id> -R howareyouo/REFramework -n RE4
   ```

   artifact 内的 `dinput8.dll` 解压后覆盖到游戏目录
   (`D:\Games\Resident Evil 4\dinput8.dll`,构建提交号可用
   `strings dinput8.dll | grep -E '^[0-9a-f]{40}$'` 核对)。
   本地构建用 `build_ninja.bat`(输出 `build\bin\RE4\dinput8.dll`)。
3. **上游有想要的改动** → 在 `main` 上找到对应提交,cherry-pick 到 `novr_re4`
   (历史上 M1-M11 移植就是这么做的)。跨 orphan 线 cherry-pick 冲突多时,
   逐个提交摘,不要整段 merge。
4. **novr 需要同步修复时**(确实要给其他游戏出包了)→ 从 `novr_re4`
   cherry-pick 过去,推 `origin/novr`,再对 `novr` ref 触发一次 CI。

## 教训记录:2026-10-26 is_readable 事件

同一份 "design patterns phases 1-8" 重构曾在三条线上**独立应用**了三次:

- `main`:`05cdf7b6`(取反写对了)
- `novr`:`9cf1f3f7` → 漏取反,修复 `e48bfc20`
- `novr_re4`:`8a07db5e` → 漏取反,修复 `708a9295`

`shared/sdk/Application.cpp` 里 `IsBadReadPtr`(true=不可读)被替换成
`utility::is_readable`(true=可读)时,部分线没有翻转条件,导致 RE4 上
`Application::get_functions()` 永远失败 → Hooks mod 初始化中止 → 框架
`m_initialized` 永远为 false → **UI 不渲染、菜单键无响应**。

规则:

- 任何"多分支同名改动"一律 cherry-pick,不要手工重做第二遍。
- 引入语义相反的替代函数(`IsBadReadPtr` → `is_readable` 这类)时,
  替换处必须逐个核对布尔极性。
- 改完跑一次真实游戏日志(`reframework_log.txt`)再部署。
