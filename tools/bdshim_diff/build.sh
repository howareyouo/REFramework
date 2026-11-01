#!/usr/bin/env bash
# Builds the bdshim-vs-bddisasm differential test with MinGW g++.
#
# The real bddisasm headers and the shim headers declare the same identifiers
# with different values, so each lives in its own translation unit and meets
# only through common.h.
#
# Usage: ./build.sh [path-to-bddisasm-source]
set -euo pipefail

PIN=70db095765ab2066dd88dfb7bbcc42259ed167c5   # same commit CMakeLists pins
HERE="$(cd "$(dirname "$0")" && pwd)"
DEPS="$HERE/.deps"
BDD="${1:-$DEPS/bddisasm-$PIN}"
OUT="$DEPS/out"
SHIM="$HERE/../../shared/utility/bdshim"

if [ ! -d "$BDD" ]; then
    mkdir -p "$DEPS"
    echo "fetching bddisasm $PIN..."
    curl -sL -o "$DEPS/bd.zip" "https://codeload.github.com/bitdefender/bddisasm/zip/$PIN"
    unzip -q -o "$DEPS/bd.zip" -d "$DEPS"
fi

mkdir -p "$OUT"
# __forceinline is redefined for GCC in nd_crt.h; emptying it is enough.
# BDDISASM_NO_FORMAT drops NdToText, which the tests never call.
if [ ! -f "$OUT/bddisasm.o" ]; then
    gcc -O1 -D__forceinline= -DNdDecodeEx=bddisasm_NdDecodeEx -DBDDISASM_NO_FORMAT \
        -I "$BDD/inc" -I "$BDD/bddisasm/include" \
        -c "$BDD/bddisasm/bddisasm.c" -o "$OUT/bddisasm.o"
fi

g++ -O2 -std=c++20 -c "$HERE/main.cpp" -o "$OUT/main_main.o"
g++ -O2 -std=c++20 -c "$HERE/ref.cpp" -I "$BDD/inc" -I "$BDD/bddisasm/include" -o "$OUT/main_ref.o"
g++ -O2 -std=c++20 -c "$HERE/shim.cpp" -I "$SHIM" -o "$OUT/main_shim.o"
g++ -O2 -std=c++20 -c "$SHIM/bdshim.cpp" -I "$SHIM" -I "$HERE/../../shared/utility" -o "$OUT/main_bdshim.o"
g++ -O2 -std=c++20 -c "$HERE/../../shared/utility/ScanSelf.cpp" -I "$HERE/../../shared/utility" \
    -o "$OUT/main_scanself.o"

g++ -O2 -std=c++20 \
    "$OUT/main_main.o" "$OUT/main_ref.o" "$OUT/main_shim.o" "$OUT/main_bdshim.o" \
    "$OUT/main_scanself.o" "$OUT/bddisasm.o" \
    -o "$OUT/bdshim_diff.exe"

echo "built $OUT/bdshim_diff.exe"
echo
echo "run: $OUT/bdshim_diff.exe \"D:/Games/Resident Evil 4/re4.exe\""
