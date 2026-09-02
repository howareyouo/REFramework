@echo off
REM ============================================================
REM  REFramework One-Click Build (Ninja + CMake 3.31 + MSVC)
REM  Output: build\bin\RE4\dinput8.dll
REM  Usage: Double-click build_ninja.bat
REM ============================================================

setlocal EnableDelayedExpansion

set "BUILD_JOBS=8"

echo [1/4] Loading MSVC environment...
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
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
"%~dp0.temp\cmake331\cmake-3.31.6-windows-x86_64\bin\cmake.exe" -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DREF_BUILD_FRAMEWORK=ON -DREF_BUILD_RE4_SDK=ON %SCCACHE_ARGS%
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
set "DST=D:\Games\Resident Evil 4\dinput8.dll"
set "BAK=D:\Games\Resident Evil 4\dinput8_bak.dll"
set "GAME_PROC=re4.exe"

if not exist "%SRC%" (
    echo ERROR: build output not found: %SRC%
    pause
    exit /b 1
)

REM If the game is running, dinput8.dll is likely locked — ask before killing.
tasklist /FI "IMAGENAME eq %GAME_PROC%" 2>nul | findstr /I "%GAME_PROC%" >nul
if %ERRORLEVEL%==0 (
    echo [warn] %GAME_PROC% is running — dinput8.dll may be in use.
    set /P "KILL=Close %GAME_PROC% and continue deploy? (Y/N): "
    if /I "!KILL!"=="Y" (
        echo Killing %GAME_PROC%...
        taskkill /F /IM %GAME_PROC% >nul 2>&1
        timeout /T 2 >nul
    ) else (
        echo Deploy skipped by user.
        pause
        exit /b 0
    )
)

if exist "%DST%" (
    echo [info] Existing dinput8.dll found, backing up to dinput8_bak.dll...
    move /Y "%DST%" "%BAK%" >nul
)
copy /Y "%SRC%" "%DST%" >nul
if exist "%DST%" (
    echo Deployed: %DST%
) else (
    echo ERROR: Deploy failed!
    pause
    exit /b 1
)
pause
