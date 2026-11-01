# 分支策略 (BRANCHES.md)

本 fork 的三条分支共享同一个 root commit(`cfb168d7`),并非互不相干的 orphan 线。
但 `novr` 与 `novr_re4` 从 `4a21e455` 起已各自演进数十个提交,实测 `git merge`
会产生 30 个文件冲突,且两边存在大量"同一改动各写一遍"的平行实现。
因此跨分支同步一律用 `git cherry-pick`,不要整段 merge。
(`main` 例外:它是纯跟踪线,可以直接从上游 merge/fetch。)

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
   (历史上 M1-M11 移植就是这么做的)。跨分支 cherry-pick 冲突多时,
   逐个提交摘,不要整段 merge。
4. **novr 需要同步修复时**(确实要给其他游戏出包了)→ 从 `novr_re4`
   cherry-pick 过去,推 `origin/novr`,再对 `novr` ref 触发一次 CI。
   **同步前先列一遍差集,逐条判断,不要整批摘**:

   ```sh
   git log --oneline novr..novr_re4          # novr_re4 有、novr 没有的提交
   git show --stat <sha>                     # 先看它到底动了什么
   ```

   差集里的提交通常分三类,只有第三类需要摘:
   - **已有等价实现**:novr 早前用别的写法做过了,`git cherry-pick` 会报空补丁
     或引入重复逻辑 → 跳过。
   - **分支定位差异**(RE4 专属裁剪:删 Camera、删 regenny 树、改 CI target 矩阵、
     改写文档等)→ 不能摘,摘了会破坏 novr 的多游戏支持。
   - **真正缺的改动** → 摘过来。

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

## 教训记录:2026-11-01 跨分支同步误摘

给 `novr` 同步 `novr_re4` 的改动时,差集会骗人。

- **无冲突 ≠ 语义适用。** `45298d3b`(re4-only: trim docs and CI)在 `novr` 上
  `git cherry-pick` 零冲突,但它把 CI 的 target 矩阵从 16 个游戏砍成只剩 `[RE4]`。
  摘得进去,功能是坏的。**先 `git show --stat` 看清它动了什么,再决定摘不摘。**
- **平行实现会让 cherry-pick 白干。** 那次 `novr_re4` 领先 25 个提交:10 个 `novr`
  已有等价实现(写法不同)、12 个是 RE4 专属裁剪(不能摘)、只有 1 个真正缺。
  先逐条判类型,再动手。
- **reset 之前先确认已推送的提交。** 用 `git reset --soft` 整理历史时,把已经推上去的
  修复 commit 摘出了分支,导致非快进推送。整理历史前先 `git log origin/<branch>` 对一遍。
- **本地跟踪引用可能陈旧。** 一度以为远端有上千个新提交,实际是 `origin/novr` 的本地引用
  没刷新。用 `git ls-remote origin refs/heads/<branch>` 直接问远端,不要只信 `git log origin/x`。
