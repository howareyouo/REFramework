# AGENTS.md - REFramework Build Guide

## 🔨 Building This Project

- **Build command:** Run the one-click build script `@build_ninja.bat` from the project root (`G:/REFramework`).
  - From Git Bash: `G:/REFramework/build_ninja.bat` (or `cmd //c "build_ninja.bat"` if needed).
  - The script loads MSVC env, configures CMake (Ninja + Release) and builds the `RE4` target.
  - **Output:** `build\bin\RE4\dinput8.dll`
- **Do NOT** configure/compile manually — always prefer `build_ninja.bat` unless the user explicitly asks otherwise.
- Requires: `F:\Program Files\BuildTools` (MSVC + CMake 3.31.6) and `ninja` in PATH.