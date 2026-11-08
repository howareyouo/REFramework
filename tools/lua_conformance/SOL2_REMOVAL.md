# Removing sol2: the migration map

`src/mods/bindings/LuaStack.hpp` is the draft replacement for every
marshalling use of sol2 in the bindings. This document is the map from what
the four files do today to what they call after the swap: every distinct
`sol::` pattern with its occurrence count, the `lua_stack` primitive that
replaces it, and the places where behavior has to survive byte-for-byte
because `tools/lua_conformance` compares error text, type names and identity
against the sol2 baseline.

The counts are token occurrences (`grep -o`), measured on the tree at commit
`8d613a3e`. `ScriptRpc.cpp`, `ImGui.cpp`, `Json.cpp` and `FS.cpp` contain zero
`sol::` tokens; everything below is `LuaHand.hpp`, `Sdk.cpp`,
`ScriptRunner.cpp` and `ScriptRunner.hpp`.

## The primitives, one line each

| Primitive | Replaces | Shape |
| --- | --- | --- |
| `lua_stack::check<T>(L, i)` | `sol::stack::check<T>` | strict scalar checks, metatable-name checks for userdata |
| `lua_stack::get<T>(L, i)` | `sol::stack::get<T>` | loose scalar reads, block-deref reads for userdata |
| `lua_stack::get_pointer<T>` / `get_ref<T>` | `stack::get<T*>` / `stack::get<T&>` | block deref + `class_cast` chain |
| `lua_stack::check_userdata<T>(L, i, accept_nil)` | the four-name metatable check + `class_check` | shared by both check forms |
| `lua_stack::put(L, v)` | `sol::stack::push(L, v)` | scalars, strings, `void*` as lightuserdata |
| `lua_stack::push_value<T>(L, v)` | `stack::push<T>` for a registered value | `[T*][T]` block + value metatable |
| `lua_stack::push_pointer<T>(L, p)` | `stack::push<as_pointer_tag<T>>` | `[T*]` block + pointer metatable |
| `lua_stack::push_borrowed<T>(L, p)` | `lh::push_borrowed` | same, cached per address in a registry-owned weak table |
| `lua_stack::construct_value<T>(L, args...)` | the hand-written constructor bodies | `[T in place]` + unique metatable |
| `lua_stack::value_gc<T>` / `unique_value_gc<T>` | `sol::detail::make_destructor<T>` | `__gc` thunks, see the layout note |
| `lua_stack::object` / `reference` | `sol::object` / `sol::reference` | `lua_State*` + registry ref, RAII unref |
| `lua_stack::make_object<T>(L, v)` | `sol::make_object<T>` | push + ref + pop |
| `lua_stack::protected_function` | `sol::protected_function` | registry ref, `lua_pcall` under the `"sol.🔔"` handler |
| `lua_stack::protected_function_result` | `sol::protected_function_result` | stack index / return / pop counts, `valid()`, `get<T>()` |
| `lua_stack::script_default_on_error` | `sol::script_default_on_error` | `"sol: <status> error: <text>"`, then throws |
| `lua_stack::variadic_args` / `stack_proxy` | `sol::variadic_args` | `{L, index}` with a frozen top; iterates `stack_proxy` |
| `lua_stack::error` | `sol::error` | `std::runtime_error` the thunks translate |
| `value_metatable<T>()` etc. | `sol::usertype_traits<T>::...` | hard-coded names, see the inventory |

## Pattern map

### LuaHand.hpp — 50 occurrences

| Pattern | Count | Replacement |
| --- | --- | --- |
| `sol::stack::get` | 9 | `lua_stack::get` (scalars, `sol::object`), `get_pointer<T>` (`T*`), `get_ref<T>` (`T&`) |
| `sol::stack::check` | 4 | `lua_stack::check` — the `is<T>`/`get_checked`/`get_arg` helpers keep their shapes |
| `sol::stack::push` | 2 | `lua_stack::put` (the `put(L, value)` fallback), `push_pointer<T>` inside `push_borrowed` |
| `sol::usertype_traits<T>::metatable()` | 4 | `value_metatable<T>()` (`install`, `set_bases`, `push_borrowed` cache key) |
| `sol::usertype_traits<T*>::metatable()` | 2 | `pointer_metatable<T>()` (`install`, `install_borrowed`) |
| `sol::usertype_traits<const T>::metatable()` | 1 | `const_value_metatable<T>()` |
| `sol::usertype_traits<const T*>::metatable()` | 1 | `const_pointer_metatable<T>()` |
| `sol::usertype_traits<T>::user_metatable()` | 2 | `user_metatable<T>()` |
| `sol::usertype_traits<unique_usertype<T>>::metatable()` | 2 | `unique_metatable<T>()` (`install`'s `owns_gc` key, the ctor thunk) |
| `sol::usertype_traits<U>::qualified_name()` | 1 | `qualified_name<U>()` — the string the `class_check`/`class_cast` protocol compares |
| `sol::object` | 6 | `lua_stack::object` — `get_object`, the `put` overload, `get_arg`, `get_param` |
| `sol::variadic_args` | 4 | `lua_stack::variadic_args` (`get_rest`, `slot_count`, `get_param`) |
| `sol::this_state` / `this_main_state` / `this_environment` | 4/2/2 | plain `lua_State*` — `slot_count` specializes on raw `lua_State*` instead |
| `sol::weak_derive<First>::value` | 2 | deleted — `check_userdata` consults `class_check` whenever the metatable carries it (see flags) |
| `sol::nil_t` | 1 | `lua_stack::nil_t` (the `put(L, nil_t)` overload) |
| `sol::detail::make_destructor<T>()` | 1 | `value_gc<T>` for a 1:1 swap; `unique_value_gc<T>` if the layout is fixed (flag 4) |
| `sol::detail::as_pointer_tag<T>` | 1 | `push_pointer<T>` |

### Sdk.cpp — 428 occurrences

| Pattern | Count | Replacement |
| --- | --- | --- |
| `sol::make_object` | 115 | `lua_stack::make_object(L, v)` — nil returns become `make_object(L, lua_stack::lua_nil)` |
| `sol::object` (parameters, returns, `is<>`, `as<>`) | 86 | `lua_stack::object`; `is<X>`/`as<X>` keep their argument lists |
| `sol::this_state` | 68 | plain `lua_State*` in the rewritten signatures |
| `sol::nil` | 58 | `lua_stack::lua_nil` |
| `sol::error` | 24 | `lua_stack::error` |
| `sol::variadic_args` | 13 | `lua_stack::variadic_args` — `build_args` iterates the same way (`stack_index()`, `is<>`, `as<>`, `leftover_count()`) |
| `sol::stack::push<as_pointer_tag<T>>` | 8 | `lua_stack::push_pointer<T>` — the `sol_lua_push` overrides' backpedal pushes |
| `sol::stack::get<sol::object>` | 2 | `lua_stack::make_object(L, -backpedal)` or `get<object>` |
| `sol::stack::push(l, sol::nil)` | 2 | `lua_stack::put(L, lua_stack::lua_nil)` |
| `sol::usertype_traits<C*>::metatable()` | 8 | `pointer_metatable<C>()` — the `install_managed_gc` keys |
| `sol::usertype_traits<unique_usertype<ValueType>>::metatable()` | 1 | `unique_metatable<ValueType>()` |
| `sol::state_view` (9 sites) | 9 | `lua_getfield(L, LUA_REGISTRYINDEX, "state")` + `lua_touserdata` for the `ScriptState*`; the `"_sol_lua_push_*"` globals read with `lua_getglobal` |
| `sol::protected_function` | 9 | `lua_stack::protected_function` |
| `sol::lua_table` | 9 | raw `lua_getglobal`/`lua_setfield` table ops — not a `lua_stack` type, see flag 2 |
| `sol::types<T*>` | 4 | the `sol_lua_push(types<T*>, L, obj)` signature stays as the ADL seam while the machinery is rewired (flag 9) |
| `sol::nil_t` (`.is<sol::nil_t>()`) | 4 | `object::is_nil()` |

### ScriptRunner.cpp — 58 occurrences

| Pattern | Count | Replacement |
| --- | --- | --- |
| `sol::protected_function` | 14 | `lua_stack::protected_function` |
| `sol::function` (registration lambdas) | 8 | `lua_stack::protected_function` — it binds a stack function the same way |
| `sol::lib` | 10 | `luaL_requiref` calls when the `sol::state` itself is replaced (flag 2) |
| `sol::nil` | 7 | `lua_stack::lua_nil` |
| `sol::object` | 6 | `lua_stack::object` |
| `sol::stack::get<T&>` / `get<T*>` | 2 | `lua_stack::get_ref<T>` / `get_pointer<T>` in `math_arg` |
| `sol::stack::push` | 2 | `lua_stack::put` in `math_push`, and the `&self[index]` row push becomes `push_pointer<Vector4f>` |
| `sol::script_default_on_error` | 4 | `lua_stack::script_default_on_error` |
| `sol::nil_t` | 4 | `is_nil()` on the reference types |
| `sol::make_object` | 4 | `lua_stack::make_object` |
| `sol::protected_function_result` | 3 | `lua_stack::protected_function_result` |
| `sol::this_state` | 2 | `lua_State*` |
| `sol::table` / `sol::state_view` / `sol::state` | 3+ | stays until ScriptRunner's own rewrite (flag 2) |
| `sol::lua_nil` | 2 | `lua_stack::lua_nil` |
| `sol::usertype_traits<T>::metatable()` | 1 | `math_metatable<T>` becomes `value_metatable<T>().c_str()` |
| `sol::detail::demangle<sol::as_container_t<T>>` | 1 | `lua_stack::container_qualified_name<T>()` in `math_pairs` |

### ScriptRunner.hpp — 42 occurrences

| Pattern | Count | Replacement |
| --- | --- | --- |
| `sol::protected_function` (all the callback members) | 18 | `lua_stack::protected_function` |
| `sol::table` (`TablePool`, `script_args`) | 6 | stays until the ScriptRunner rewrite (flag 2) |
| `sol::reference` (`get_hook_storage`, `m_current_hook_storage`) | 5 | `lua_stack::reference` |
| `sol::nil` | 4 | `lua_stack::lua_nil` |
| `sol::protected_function_result` | 3 | `lua_stack::protected_function_result` |
| `sol::types<T*>` (the `sol_lua_push` declarations) | 2 | the ADL seam (flag 9) |
| `sol::object` | 2 | `lua_stack::object` |
| `sol::state` / `sol::state_view` | 2 | stays (flag 2) |

## Byte-for-byte preservation list

Everything in this section is compared by the conformance probes and must not
move by a byte.

- **Error texts**
  - `"caught (...) exception"` — `math_raise_no_position`, raised with `lua_error`
    so no position prefix is added (ScriptRunner.cpp, pinned by probe 05).
  - `"sol: cannot set (new_index) into this object: no defined new_index operation on usertype"` —
    `lua_hand::new_index_error`, duplicated as `lua_stack::new_index_error`.
  - `"sol: no matching function call takes this number of arguments and the specified types"` —
    the math constructors (`vec2_new` and friends).
  - `"sol: cannot call '__pairs/pairs' on type '<name>': it is not recognized as a container"` —
    where `<name>` is `sol::as_container_t<T>` demangled, i.e. exactly
    `container_qualified_name<T>()` (`"sol::as_container_t<glm::vec<3,float,0>>"`).
  - `"sol: <status> error: <lua message>"` — `script_default_on_error`; the
    status names are sol2's (`"runtime"` is the one script errors carry).
  - `"unknown C++ exception"` and `"expected <type>, got <lua type>"` —
    `LUA_HAND_CATCH` and `lh::get_arg`, unchanged by this migration.
  - `"attempt to call a method on a nil usertype object"` — `lh::method_thunk`.
- **Metatable names** — the registry keys in the inventory below. The check
  chain compares rawequal against `luaL_getmetatable` of these exact strings,
  and `math_metatable<T>` feeds them to `luaL_testudata`. The math metatables
  also set `__name` to the registry key, which is what `tostring` shows
  ("sol.glm::vec<3,float,0>: 0x..."); `open_math_metatable` owns that and
  nothing in `lua_stack` touches `__name`.
- **Weak-table caching identity** — `push_borrowed` must keep: one userdata
  per (type, address), a second read of the same address returning the same
  userdata, comparison between two reads being a pointer comparison, and the
  cache being weak-valued so an unreferenced element can die and be
  re-created. The probe pins identity and the metatable of a repeat lookup.
- **`__gc` timing** — a value-form userdata runs its destructor when Lua
  collects it (the block is freed by Lua either way); a pointer-form userdata
  never destructs anything; a borrowed cache entry dying does not destruct
  the element it pointed at.
- **`tostring` of the non-math usertypes** — `install()` writes no `__name`,
  so they report `userdata: 0x...`; keep it that way (the probes normalize the
  address and compare the word in front of it).

## Usertype name inventory

Every `usertype_name<T>` specialization in LuaStack.hpp, and where it comes
from. "Measured" means the string was taken from the running game (the
conformance probes or the metatable dump); "derived" means it follows from the
demangle rules the measured strings confirm (`struct`/`class` stripped, outer
`>` of a template cut by the demangler, cv trailing, MSVC canonical type
spellings: `uint8_t` -> `unsigned char`, `int32_t` -> `int`, `uint32_t` ->
`unsigned int`).

| Type | `usertype_name` value | Forms needed | Source |
| --- | --- | --- | --- |
| `glm::vec<2, float, 0>` (Vector2f) | `glm::vec<2,float,0>` | value, pointer, const, const ptr, user, unique, container | Measured (`sol.glm::vec<3,float,0>` pattern) |
| `glm::vec<3, float, 0>` (Vector3f) | `glm::vec<3,float,0>` | same | Measured |
| `glm::vec<4, float, 0>` (Vector4f) | `glm::vec<4,float,0>` | same | Measured |
| `glm::mat<4, 4, float, 0>` (Matrix4x4f) | `glm::mat<4,4,float,0>` | same | Measured |
| `glm::qua<float, 0>` (glm::quat) | `glm::qua<float,0>` | same | Measured |
| `::REManagedObject` | `REManagedObject` | value, pointer, const, const ptr, user, unique, container | Measured (`sol.REManagedObject*`) |
| `::REComponent` | `REComponent` | full set (base of RETransform's chain) | Derived |
| `::RETransform` | `RETransform` | full set | Derived |
| `::sdk::SystemArray` | `sdk::SystemArray` | full set | Derived |
| `::sdk::Delegate` | `sdk::Delegate` | full set | Derived |
| `::api::sdk::BehaviorTree` | `api::sdk::BehaviorTree` | pointer (the managed pusher's dispatch), full set from install | Derived |
| `::api::sdk::BehaviorTreeCoreHandle` | `api::sdk::BehaviorTreeCoreHandle` | same | Derived |
| `::sdk::RETypeDefinition` | `sdk::RETypeDefinition` | full set | Measured (`sol.sdk::RETypeDefinition*`) |
| `::sdk::REMethodDefinition` | `sdk::REMethodDefinition` | full set | Derived |
| `::sdk::REProperty` | `sdk::REProperty` | full set | Derived |
| `::sdk::REField` | `sdk::REField` | full set | Derived |
| `::sdk::Resource` | `sdk::Resource` | full set | Derived |
| `::api::sdk::ValueType` | `api::sdk::ValueType` | full set + unique (the ctor) | Derived |
| `::api::sdk::MemoryView` | `api::sdk::MemoryView` | value (pushed by value), full set from install | Derived |
| `::sdk::NativeArrayNoCapacity<uint8_t>` | `sdk::NativeArrayNoCapacity<unsigned char>` | full set | Derived |
| `::sdk::NativeArrayNoCapacity<int32_t>` | `sdk::NativeArrayNoCapacity<int>` | full set | Derived |
| `::sdk::NativeArrayNoCapacity<uint32_t>` | `sdk::NativeArrayNoCapacity<unsigned int>` | full set | Derived |
| `::sdk::NativeArray<::REManagedObject*>` | `sdk::NativeArray<REManagedObject*>` | full set | Derived |
| `::sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>` | `sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNode>` | full set | Derived |
| `::sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>` | `sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNodeData>` | full set | Derived |
| `::sdk::behaviortree::TreeNode` | `sdk::behaviortree::TreeNode` | full set | Derived |
| `::sdk::behaviortree::TreeNodeData` | `sdk::behaviortree::TreeNodeData` | full set | Derived |
| `::sdk::behaviortree::TreeObject` | `sdk::behaviortree::TreeObject` | full set | Derived |
| `::sdk::behaviortree::TreeObjectData` | `sdk::behaviortree::TreeObjectData` | full set | Derived |
| `::REFramework` | `REFramework` | value, pointer | Measured (`sol.REFramework*`) |
| `std::array<unsigned char, 256>` | `std::array<unsigned char,256>` | value, pointer, unique | Measured (`sol.std::array<unsigned char,256>`) |

A type pushed without a specialization fails to compile
(`usertype_name<T>` has no definition), so the list cannot silently rot. The
string functions build the forms: `value_metatable<T>()` = `"sol." + name`,
`pointer_metatable<T>()` = `"sol." + name + "*"`, `user_metatable<T>()` adds
`".user"`, `unique_metatable<T>()` = `"sol.sol::detail::unique_usertype<name>"`,
`container_qualified_name<T>()` = `"sol::as_container_t<name>"`.

## Flags: what is not 1:1

1. **The `_sol_lua_push_*` globals.** The managed-object machinery in Sdk.cpp
   keeps its bookkeeping in four real globals: `_sol_lua_push_objects`,
   `_sol_lua_push_ref_counts`, `_sol_lua_push_ephemeral_counts` and
   `_sol_lua_push_usertypes`. `lua_stack::push_borrowed` deliberately owns its
   container in the registry (`"\x01lua_stack.push_usertypes"`) instead. If
   the Sdk.cpp machinery is rewired onto `push_pointer`/`push_borrowed`, the
   cache identity changes from "the weak table under a `__FUNCSIG__` hash
   inside the global" to "the weak table under the metatable name in the
   registry" — same granularity (one per type), different table. Scripts or
   probes that read those globals would see it; the current probes only check
   userdata identity, which is preserved. Decision to make during wiring:
   keep the globals and rewire their contents, or move the cache into the
   registry for good.
2. **`sol::state`, `sol::table`, `sol::lua_table`, `sol::lib` are out of
   scope.** LuaStack.hpp is a marshalling layer; it has no state object, no
   table proxy and no library loader. ScriptRunner.cpp's state setup, the
   `TablePool`, `script_args`, `package.searchers` republishing and the
   `registry()["state"]` slot keep their sol2 shape until ScriptRunner's own
   rewrite. That is the bulk of what remains after this header lands.
3. **The `weak_derive` gate.** sol2 consulted `class_check` only when the
   requested type had been marked derived; `lua_stack::check_userdata`
   consults it whenever the metatable carries one. Every metatable that
   stores a `class_check` got it from a `set_bases` that marked its bases, so
   the two answer identically in practice, but the reasoning differs. If a
   future installer stores a `class_check` without marking bases, sol2 would
   refuse where this header accepts.
4. **Two owned-value layouts.** sol2's own constructor and `stack::push<T>`
   both produced a `[T*][T]` block under the value metatable; the
   hand-written constructors (and `lua_stack::construct_value`) produce a
   `[T in place]` block under the unique metatable. A `[T in place]` block
   read through `get_ref`/`get_pointer` dereferences its first eight bytes as
   a pointer, and sol2's `make_destructor` (still what `install(owns_gc)`
   writes) dereferences the same way — for `ValueType` that reads
   `std::vector`'s internal pointer. This mismatch is pre-existing (it shipped
   with the phase-1 rewrite and the ValueType probes pass because they only
   `tostring` the object), and this header reproduces it rather than
   silently changing it: `value_gc<T>` is the byte-exact slot-deref form,
   `unique_value_gc<T>` is the in-place form a fixing installer would want on
   the unique metatable. Wiring owns that decision. The ValueType probes pass
   today because they only `tostring` the object; a probe that reads a
   constructed ValueType's fields would surface the hazard.
5. **The const and `.user` key spellings are unmeasured.** Nothing pushes a
   `const T` userdata and nothing outside the installer reads those keys, so
   the `"X const"` / `"X const *"` forms only have to be self-consistent
   between `install`-shaped code that creates them and the check chain that
   never consults them. If a probe ever grows a const-form expectation, the
   two strings in LuaStack.hpp are the only thing to re-measure.
6. **Fresh-metatable defaults are a subset.** When `push_value`/`push_pointer`
   create a metatable nobody installed, sol2's undefined-methods setup also
   wrote `__lt`/`__le` (when the type had the operators) and `__tostring`;
   `lua_stack::ensure_metatable` writes `__gc` (value form only), an
   always-false `__eq` and the `__type` table (`name`, `is`). No current push
   path reaches a fresh metatable — every type is installed or
   `open_math_type`d before a push — so the subset is unexercised; add the
   operator thunks before relying on it. One ordering property is shared with
   sol2 and worth knowing either way: Lua 5.4 only finalizes a userdata whose
   metatable carried `__gc` at creation, and both pushers create the userdata
   before they create the metatable, so the first value pushed under a
   brand-new metatable is never finalized. Installers that want destructors
   must create the metatable with `__gc` first — which is exactly what
   `install(owns_gc)` does today.
7. **Include requirements.** LuaStack.hpp includes `<glm/fwd.hpp>` (for the
   primary templates the math specializations name) and forward-declares every
   sdk/engine type it names, so any TU can include it; it needs no other
   project header and no sol2.
8. **`script_default_on_error` on a valid result.** sol2's throw-on-error did
   its full (nonsensical) path even for a valid result; this one returns it
   unchanged. Every call site guards with `result.valid()` first, so the
   observed behavior is identical.
9. **No C++-exception catch arms in the protected call.** sol2's `invoke`
   caught C++ exceptions escaping through `lua_pcall`; in this codebase every
   binding thunk converts its own exceptions with `LUA_HAND_CATCH`, so a
   `lua_pcall` cannot throw across it. The pcall status is the only error
   channel, which `script_default_on_error` formats exactly as sol2 did.
10. **Ref counting is not in this header.** `put<T*>` and
   `push_call_argument` push a plain borrowed pointer. The
   `ManagedObjectBased` dispatch (add_ref, the ref-count tables, the runtime
   switch to the `RETransform*`/`BehaviorTree*`/`BehaviorTreeCoreHandle*`/
   `SystemArray*` metatables) and the `CachedUserType` caching live in
   Sdk.cpp's two `sol_lua_push` overloads and must survive the migration
   there — rewire their internals onto `push_pointer`/`push_borrowed`, keep
   the functions as the ADL seam (`push_call_argument` is the hook
   `ProtectedFunction::operator()` goes through, so a
   `push_call_argument(lua_State*, ::RETransform*)` overload in Sdk.cpp
   restores the counted push for callback arguments). A mechanical swap of
   `lh::put` call sites without this would silently stop counting references.
11. **The default error handler global.** `protected_function` reads the
    `"sol.\xF0\x9F\x94\xA9"` global sol2's state setup writes. While sol2
    initializes the states, the handler is shared; when ScriptRunner's state
    setup is rewritten, it must push `lua_stack::default_traceback_error_handler`
    under that global (or accept pcall without a handler, which changes the
    traceback text the error path spews).

## Probes to run when wiring

The swap order that keeps the diff green: rewire `Sdk.cpp`'s two
`sol_lua_push` overloads onto `push_pointer` first (probes 02-04 own the
borrowed-pointer identity and the managed predicates), then the
`usertype_traits` keys (probes 01/02), then the `make_object`/`object` sweep
(probes 04/09), then ScriptRunner's callback storage and
`script_default_on_error` (probes 07/08). The math region only needs the
`math_metatable` and `math_push` swaps, and `math_pairs`' demangle (probe 05
pins the refusal text).
