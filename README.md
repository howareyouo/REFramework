# REFramework (RE4-only fork) [![Build status](https://github.com/praydog/reframework/actions/workflows/dev-release.yml/badge.svg)](https://github.com/praydog/REFramework-nightly/releases)
A mod framework, scripting platform, and modding tool for Resident Evil 4 Remake. Inspired by and uses code from [Kanan](https://github.com/cursey/kanan-new)

## Installation
The last stable build can be downloaded from the [Releases](https://github.com/praydog/REFramework/releases) page.

For newer builds, check out the [Nightly Developer Builds](https://github.com/praydog/REFramework-nightly/releases)

### Non-VR
* Extract only the `dinput8.dll` from the zip file into your game folder.

### Proton/Linux
Add the launch option `WINEDLLOVERRIDES="dinput8.dll=n,b" %command%` to your game through Steam's properties after extraction.

Example game folder: `D:\Games\Resident Evil 4` (modded), or `G:\SteamLibrary\steamapps\common\RESIDENT EVIL 4` (Steam).

Supports both DirectX 11 and DirectX 12.

## Included Mods
* Lua Scripting API & Plugin System (check out the [Wiki](https://cursey.github.io/reframework-book/))
* Free Camera
* Scene Timescale
* FOV Slider / Custom Global FOV
* Vignette Disabler / Brightness
* Ultrawide/Aspect Ratio fixes
* GUI Hider/Disabler
* Temporal Upscaler

## Included Tools (Developer Mode)
* Game Objects Display
* Object Explorer

## Supported Games
* Resident Evil 4 Remake

## Thanks
[cursey](https://github.com/cursey/) for helping develop the VR component and the scripting system.

[The Hitchhiker](https://github.com/youwereeatenbyalid/) and [alphaZomega](https://github.com/alphazolam) for the great help stress testing, creating scripts for the scripting system, and helpful suggestions.