# AGENTS.md - REFramework Build Guide

## 🔨 Building This Project

- **Build command:** Run the one-click build script `@build_ninja.bat` from the project root (`G:/REFramework`).
  - From Git Bash: `G:/REFramework/build_ninja.bat` (or `cmd //c "build_ninja.bat"` if needed).
  - The script loads MSVC env, configures CMake (Ninja + Release) and builds the `RE4` target.
  - **Output:** `build\bin\RE4\dinput8.dll`
- **Do NOT** configure/compile manually — always prefer `build_ninja.bat` unless the user explicitly asks otherwise.
- Requires: `F:\Program Files\BuildTools` (MSVC + CMake 3.31.6) and `ninja` in PATH.

## ⚡ Compile Cache (sccache) — always use it

- `build_ninja.bat` already enables sccache via `-DCMAKE_C_COMPILER_LAUNCHER=sccache -DCMAKE_CXX_COMPILER_LAUNCHER=sccache`.
- **Any task that compiles code must go through sccache**, including ad-hoc single-file / syntax-check compilations. Prefix the compiler with `sccache` (binary: `F:\Program Files\BuildTools\sccache\sccache.exe`):
  - Git Bash: `export PATH="/f/Program Files/BuildTools/sccache:$PATH"`, then `sccache cl.exe ...`
  - cmd: `set "PATH=F:\Program Files\BuildTools\sccache;%PATH%"`, then `sccache cl.exe ...`
- **Do NOT set `SCCACHE_DIR`.** The cache directory belongs to the background sccache server, which is shared by every project on this machine; it uses its default (`%APPDATA%\Mozilla\sccache`). A server that is already running silently ignores a `SCCACHE_DIR` set by a later client.
- Verify cache effectiveness with `sccache --show-stats` (compile requests / cache hits / cache misses).