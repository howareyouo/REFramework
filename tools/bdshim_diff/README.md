# bdshim differential test

Compares the real [bddisasm](https://github.com/bitdefender/bddisasm) decoder against
`shared/utility/bdshim/`, the API-compatible shim that lets kananlib and the rest of
REFramework keep their `NdDecodeEx` call sites without linking bddisasm.

The shim exists to delete ~585 KB of static library from `dinput8.dll`. The only thing
that makes that trade safe is evidence that no call site can tell the two decoders
apart, which is what this tool measures.

## Why not compare fields

bddisasm and `ScanSelf` describe an instruction with hundreds of fields, most of which
nobody reads. A field-by-field diff over a 230 MB image produced 34.9 million
disagreements that were entirely unobservable — different names for the same thing,
fields no call site touches, padding bits.

So the comparison is done on **predicates**: the exact boolean questions the REFramework
and kananlib call sites ask of a decoded instruction. If a predicate agrees on every
instruction the image contains, no call site can behave differently. Predicate
disagreements gate the verdict; the two decoder-level counters do not (see
"Known noise").

## Predicates and the call sites they come from

| Predicate | Call site |
| --- | --- |
| `follow_branch` (`IsRipRelative && !IsIndirect`) | `kananlib/include/utility/Scan.hpp:234`, `:208` |
| `jmp_in_place` (`JMPE..JMPNR` window) | `kananlib/include/utility/Scan.hpp:250` |
| `mnemonic == CALL` | `shared/sdk/REContext.cpp:334` |
| `mnemonic starts_with CALL` | `src/mods/Graphics.cpp:1035` |
| `mnemonic starts_with RET` | `shared/sdk/Renderer.cpp:102` |
| `mnemonic starts_with INT3` | `shared/sdk/Renderer.cpp:102` |
| `mnemonic starts_with VMOVUPS` | `src/mods/IntegrityCheckBypass.cpp:687` |
| `mnemonic contains TEST` | `src/mods/IntegrityCheckBypass.cpp:805` |
| `mnemonic starts_with CMP` | `src/mods/Graphics.cpp:1039` |
| `mnemonic == LEA` | `shared/sdk/REContext.cpp:338`, `shared/sdk/RETypeDB.cpp:525` |
| `Category == CALL && Instruction == CALLNI` | `kananlib/src/Scan.cpp:1338` |
| `HasLock && INC && op0 == MEM` | `shared/sdk/ResourceManager.cpp:271` |
| `CMP && op0 == MEM && op1 == IMM && hasBase && dispSize != 4 && imm == 6` | `src/mods/Graphics.cpp:1039-1058` (composite: prefix test ANDed with the operand test) |
| `TEST && op0 == REG/GPR && op1 == IMM in {8, 20h, 40h}` | `src/mods/IntegrityCheckBypass.cpp:805-810` |
| `op0 == REG(GPR) \|\| op0 == MEM(base+disp)` | `src/mods/IntegrityCheckBypass.cpp:529-531` |

Two derived values are also compared, because they are what a scanner actually returns
and a wrong value sends the scan to the wrong address while every field still matches:

- **RIP-relative memory target** — mirrors `utility::resolve_displacement`
  (`kananlib/src/Scan.cpp:2716`): walk *all* operands for a RIP-relative memory
  reference and use `Length + Disp`; if there is none, fall back to the
  instruction-level `HasDisp && IsRipRelative` pair with the sign-extended
  displacement. An earlier version of this tool looked only at `operands[0]` and
  reported 35,701 false differences — a `LOCK` prefix puts the memory operand in slot
  1 (e.g. `F0 0F C1 05 ...` = `lock xadd [rip+x], eax`).
- **Relative branch target** — `Length + Rel`.

## Structure

Both decoders define the same identifiers with different numeric values, so they must
never share a translation unit. `common.h` holds a POD result struct and *role*
enumerations (`InsRole`, `CatRole`, `OpRole`, `RegRole`); `ref.cpp` and `shim.cpp`
translate their own library's enums into roles, and `main.cpp` only ever sees roles.

`ref.cpp` renames `NdDecodeEx` to `bddisasm_NdDecodeEx` (and `build.sh` passes
`-DNdDecodeEx=bddisasm_NdDecodeEx` to the `bddisasm.c` compile) so the two definitions
can coexist in one binary.

## Running

```bash
bash tools/bdshim_diff/build.sh
./tools/bdshim_diff/.deps/out/bdshim_diff.exe "/d/Games/Resident Evil 4/re4.exe"
```

`build.sh` downloads bddisasm at the pinned commit into `.deps/` (git-ignored) and needs
`curl`/`unzip` plus a MinGW or MSVC `gcc`. It exits non-zero when a gating predicate
disagrees.

The walk uses `.pdata`, so every byte the comparison sees is inside a function body
rather than in data. On decode failure it resynchronises by one byte, exactly like a
scanner does.

## Result on `re4.exe` (230 MB image, 27,544,500 decode attempts)

```
predicate                                   hits   disagrees
follow_branch                            6689360           0
jmp_in_place                              511059           0
mnemonic == CALL                         2705947           0
mnemonic starts_with CALL                2705957           0
mnemonic starts_with RET                  383813           0
mnemonic starts_with INT3                   1844           0
mnemonic starts_with VMOVUPS                 428           0
mnemonic contains TEST                   1127230           0
mnemonic starts_with CMP                 1019602      293930  (prefix-only, not gating)
mnemonic == LEA                          1992421           0
Category==CALL && Instruction==CALLNI      143845           0
HasLock && INC && op0==MEM                  1150           0
CMP && op0==MEM && op1==IMM && imm==6        169           0
TEST && op0==REG && op1==IMM                 1554           0
op0==REG(GPR) || op0==MEM(base+disp)         1150           0

rip-relative memory target  : 1506022 checked, 0 disagree
relative branch target      : 5195796 checked, 0 disagree

RESULT: identical observable behaviour
```

## Known noise (reported, not gating)

- **`mnemonic starts_with CMP`: 293,930** — `ScanSelf` names `CMPS*`/`SCAS*`
  (`66 F3 A7` = `repe cmpsw`) as `X`. Unobservable: the only call site
  (`Graphics.cpp:1040`) uses the prefix test as a cheap filter and then requires
  `op0 == MEM && op1 == IMM`, which `CMPS*` cannot satisfy — the composite
  `CMP && op0==MEM && op1==IMM && imm==6` predicate shows 0 disagreements.
- **61 length mismatches, 92 refusals** — these are pre-existing gaps between
  `ScanSelf` and bddisasm, independent of the shim. A stand-alone run of `ScanSelf`
  against bddisasm over the whole image gives 74 and 108, so the shim is strictly
  closer than the code it replaces. The refused bytes are invalid-in-64-bit or
  data-shaped (`D6` = `SALC`, repeated 4-byte table entries); a refusal costs the
  pattern scanner exactly one candidate, since the walker resynchronises by one byte
  and keeps searching, so it can never silently return the wrong address.

## History

- `tools/scan_diff/` is the earlier, simpler tool that compares `ScanSelf` against
  bddisasm directly with a linear `.text` walk. It was used to bring `ScanSelf`
  itself up to parity before the shim existed.
