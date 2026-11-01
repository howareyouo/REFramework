#!/usr/bin/env bash
# Builds the bddisasm-vs-ScanSelf differential tests with MinGW g++.
# Usage: ./build.sh [path-to-bddisasm-source]
set -euo pipefail

PIN=70db095765ab2066dd88dfb7bbcc42259ed167c5   # same commit CMakeLists pins
HERE="$(cd "$(dirname "$0")" && pwd)"
DEPS="$HERE/.deps"
BDD="${1:-$DEPS/bddisasm-$PIN}"
OUT="$DEPS/out"

if [ ! -d "$BDD" ]; then
    mkdir -p "$DEPS"
    echo "fetching bddisasm $PIN..."
    curl -sL -o "$DEPS/bd.zip" "https://codeload.github.com/bitdefender/bddisasm/zip/$PIN"
    unzip -q -o "$DEPS/bd.zip" -d "$DEPS"
fi

mkdir -p "$OUT"
# __forceinline is redefined for GCC in nd_crt.h; emptying it is enough.
# BDDISASM_NO_FORMAT drops NdToText, which the tests never call.
gcc -O1 -D__forceinline= -DBDDISASM_NO_FORMAT -I "$BDD/inc" -I "$BDD/bddisasm/include" \
    -c "$BDD/bddisasm/bddisasm.c" -o "$OUT/bddisasm.o"

for t in main pdata; do
    g++ -O2 -std=c++20 \
        -I "$HERE/../../shared/utility" \
        -I "$BDD/inc" -I "$BDD/bddisasm/include" \
        "$HERE/$t.cpp" "$HERE/../../shared/utility/ScanSelf.cpp" "$OUT/bddisasm.o" \
        -o "$OUT/$t.exe"
    echo "built $OUT/$t.exe"
done

echo
echo "run: \$OUT/pdata.exe \"D:/Games/Resident Evil 4/re4.exe\""
