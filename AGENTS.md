# AGENTS.md - REFramework Build Guide
[RE Engine Modding Documentation](https://github.com/Havens-Night/REEngine-Modding-Documentation)

## Getting the DLL: use CI

This machine has no MSVC — do not build locally. Push the branch and take `dinput8.dll` from the CI artifact.

```bash
git push origin <branch>
gh run list -R howareyouo/REFramework --branch <branch> --limit 3
gh run watch <run-id> -R howareyouo/REFramework --exit-status
gh run download <run-id> -R howareyouo/REFramework -n RE4 -D /tmp
```

- Always pass `-R`: the local default remote is `upstream`, which has no such run.
- Install: rename the existing `dinput8.dll` to `dinput8.dll_bak_yyyymmddhhmm` (e.g. `dinput8.dll_bak_202611050556`), then copy the new one in. Renaming works while the game is running, so no need to close it. Target: `D:\Games\Resident Evil 4\`.

`build_ninja.bat` is only for machines that do have MSVC; it auto-deploys to the game directory and ends with `pause`. Do not run cmake by hand.
