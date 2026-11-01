# tools/scan_diff

Differential test for `shared/utility/ScanSelf.*`: decodes a whole PE with both
bddisasm and the self-made decoder and compares instruction lengths. This is the
gate any change to the decoder has to pass before it is wired into the build —
`ScanSelf` is not compiled into `dinput8.dll` yet (see
`docs/SELFMADE_SCANNER.md`).

## Build

No MSVC needed. MinGW g++ + curl + unzip:

```bash
./build.sh            # downloads bddisasm at the pinned commit into .deps/
```

## Run

```bash
./.deps/out/pdata.exe "D:/Games/Resident Evil 4/re4.exe"
```

- `pdata.exe` — decodes each `.pdata` function body sequentially and compares
  lengths. This is the number that matters: it covers real code only.
- `main.exe` — decodes `.text` linearly, boundary by boundary. It also reports
  bddisasm failures, so it can tell "the decoder disagrees" apart from "we are
  walking over an RVA table".

Both resync on bddisasm's length, so a single desync does not cascade.

## Expected output (RE4 build 2026-04, 233 MB exe)

```
[pdata] functions=508868 insns=25400722 ours_fail=42 (0.00017%) len_mismatch=33 (0.00013%)
```

Read the mismatches before trusting a green run: every current one is a jump
table that happens to sit inside a `.pdata` range (`CF 20 BC 01`, `D6 01 FC 92`
byte runs), not a decode bug in straight-line code. A mismatch on plausible
instruction boundaries is the signal that the decoder regressed.

`ours_fail` is the dangerous direction: a walk that hits it stops early, which
shows up in game as "the SDK could not find X", not as a crash.
