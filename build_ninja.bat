@echo off
REM ============================================================
REM  REFramework One-Click Build (Ninja + CMake 3.31 + MSVC)
REM  Output: build\bin\RE4\dinput8.dll
REM  Usage: Double-click build_ninja.bat
REM ============================================================

setlocal EnableDelayedExpansion

set "BUILD_TOOLS=F:\Program Files\BuildTools"
set "CMAKE=%BUILD_TOOLS%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "BUILD_JOBS=8"


echo [1/4] Loading MSVC environment...
call "%BUILD_TOOLS%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo ERROR: Failed to load MSVC environment.
    pause
    exit /b 1
)

REM Detect sccache compile cache
where sccache >nul 2>&1
if %ERRORLEVEL%==0 (
    echo [info] sccache found in PATH, enabling compile cache...
    set "SCCACHE_ARGS=-DCMAKE_C_COMPILER_LAUNCHER=sccache -DCMAKE_CXX_COMPILER_LAUNCHER=sccache"
) else (
    echo [warn] sccache NOT in PATH, building without compile cache.
    set "SCCACHE_ARGS="
)

echo [2/4] CMake configure (3.31.6)...
"%CMAKE%" -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DREF_BUILD_FRAMEWORK=ON -DREF_BUILD_RE4_SDK=ON %SCCACHE_ARGS%
if %ERRORLEVEL% neq 0 (
    echo ERROR: CMake configure failed!
    pause
    exit /b 1
)

echo [3/4] Ninja build RE4 Using %BUILD_JOBS% parallel build jobs....
ninja -C build -j %BUILD_JOBS% RE4
if %ERRORLEVEL% neq 0 (
    echo ERROR: Build failed!
    pause
    exit /b 1
)

echo.
echo ============================================================
echo  BUILD SUCCESS
echo  Output: build\bin\RE4\dinput8.dll
echo ============================================================

REM --- 4. Deploy to game directory ---
echo [4/4] Deploying dinput8.dll...
set "SRC=build\bin\RE4\dinput8.dll"
set "GAME_DIR=D:\Games\Resident Evil 4"
set "DST=%GAME_DIR%\dinput8.dll"

if not exist "%SRC%" (
    echo ERROR: build output not found: %SRC%
    pause
    exit /b 1
)

REM Timestamp suffix for renamed old dll: MMDD_HHMMSS
for /f %%i in ('powershell -NoProfile -Command "Get-Date -Format 'MMdd_HHmmss'"') do set "STAMP=%%i"

REM If an old dll exists, rename it with a timestamp suffix to keep history.
if exist "%DST%" (
    echo [info] Existing dinput8.dll found, renaming to dinput8_!STAMP!.dll...
    move /Y "%DST%" "%GAME_DIR%\dinput8.dll_!STAMP!" >nul
)

copy /Y "%SRC%" "%DST%" >nul
echo Deployed: %DST%
pause
