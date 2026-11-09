# tools/lua_conformance

Differential test for the hand-written Lua bindings in
`src/mods/bindings/*.cpp`. This is the gate a binding change has to pass.

## Why this exists

When the sol2 usertypes were rewritten by hand, the automation that used to
convert arguments, cache pointers and pair up metamethods was replaced by code
written once and rarely re-read. Three bugs shipped that way, and none of them
was visible to the compiler or to a grep:

- `push_borrowed` cached a pointer under the wrong key, so the *second* lookup
  of one address returned a userdata with no metatable. Only a script that
  fetched the same node twice noticed.
- the array `__newindex` thunks asked for a `T` userdata where the number to
  store sat, so every `arr[i] = n` threw.
- `set_pairs` overwrote the array bindings' own `__pairs`, so `pairs(arr)`
  walked the member names instead of the elements.

Each was found by running real scripts and staring at the output. This harness
does that comparison on purpose: it runs the same probes against two dlls and
reports every line that differs. A divergence is either a bug or a deliberate
change that has to be written down.

## Run

The game has to be installed; nothing here builds.

```bash
# 1. a report from the sol2 baseline dll (the reference)
python tools/lua_conformance/run.py --dll dinput8.dll_bak_sol2 --out /tmp/sol2.txt

# 2. a report from the dll under test
python tools/lua_conformance/run.py --dll build/dinput8.dll --out /tmp/hand.txt

# 3. compare
python tools/lua_conformance/diff.py /tmp/sol2.txt /tmp/hand.txt
```

`run.py` kills the game, backs up the installed dll, installs the one passed,
starts the game and waits for the RPC endpoint. `--no-launch` runs against a game
that is already up, which is what you want while iterating on a probe.

`diff.py` exits non-zero when the two reports differ, so it can be the last
command of a script that only proceeds on a match.

## What the probes cover

`probes/` holds a shared `_prelude.lua` and the probe bodies; the runner
concatenates the prelude onto each body, so no probe depends on a path inside the
game's filesystem.

| Probe | Covers |
| --- | --- |
| `01_surface.lua` | the global tables and the members scripts reach for |
| `02_plumbing.lua` | borrowed pointers: identity, metatable, repeat lookup |
| `03_arrays.lua` | `__index`, `__newindex`, `__len`, `__pairs`, error classes |
| `04_usertype.lua` | managed predicates, base-to-derived upcast, ref counting |
| `05_math.lua` | the five math types: constructors (loose and overload-resolved), fields, methods, operators, `__eq`, the `__pairs` refusal, and the borrowed row a matrix hands back |
| `06_reframework.lua` | the `reframework` usertype: members, key refusal, the sandbox `std::array` keyboard state |
| `07_re_log_thread.lua` | `re`/`log`/`thread` members, `CallbackNextAction`, the `os`/`debug` removals, registration shapes |
| `08_dispatch.lua` | the dispatch half of `re.on_frame`: probe 07's counter has to have grown |
| `09_sdk_values.lua` | sdk lookup refusals and their error texts, json round-trip, fs, the scratch types |

Probes 02-04 need the player context, so the game has to be in a loaded save
for them to do more than report SKIP.

A probe reports through `rep`/`try`, which strip addresses and hashes the run
happened to map; what is left is the type names, the small numbers and the error
text. Error text is compared on purpose: `unknown C++ exception` against
`expected BehaviorTreeNode, got number` is a real difference, and the second
one is the point of the `get_arg` diagnostics.

## Adding a probe

A probe is any `NN_name.lua` in `probes/`. It ends with `return finish()` and
guards anything that can fail with `try`, so one failure does not hide the rest.
Keep every write reversible — probe `03` restores the array slot it writes —
because the game stays up for the next run.

Reproduce a bug a user reports by adding the lines that show it, then check the
baseline report agrees. A line that differs between the baseline and the
hand-written build is the bug.