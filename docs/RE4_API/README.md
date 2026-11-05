# RE Engine API index

Generated from a running game over Lua RPC (see [`docs/LUA_RPC.md`](../LUA_RPC.md)). Names are dotted, so every type is one grep away: `rg -A30 '^## `chainsaw\.CharacterManager`$' chainsaw.md`.

Each page lists a type's members in a single `lua` block:

```lua
-- fields
Health: System.Single          -- read `obj.Health` / `obj:get_field("Health")`
MaxHp: System.Int32 [static]   -- same names, but on the type, not the instance
-- methods
:System.Void set_Health(System.Single)   -- obj:call("set_Health", 100)
-- static
:System.Void Foo(System.Int32)   -- sdk.call_native_func(nil, td, "Foo", 1)
```

The leading `:` marks a method line and is not part of the name; the `--` lines are group labels. Instance fields can be read and written directly as `obj.FieldName`.

An enum is printed as its value names only:

```lua
-- values (System.Int32 enum)
File_000
Invalid
```

Those names are the constants the game compares against -- e.g. `td:get_field("File_000")` on `chainsaw.DocumentID`. The numeric values are not dumped: resolve them at runtime from the field.

Left out on purpose, because a modder never needs them and they were most of the bytes: `<X>k__BackingField` (use the `get_X`/`set_X` accessor), `.ctor`/`.cctor`, field offsets, generic instantiations such as ``List`1<...>``, and the `T[]` array types below.

Any `T[]` field or parameter is the engine's fixed-size array of `T`. All
9399 such types expose exactly the same members, so they are not
listed per type -- given `arr` of type `T[]`, with `T` the element type:

```lua
-- methods
:System.Void Add(T)
:T Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(T)
:System.Void CopyTo(T[], System.Int32)
:T Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<T> GetEnumerator()
:System.Int32 IndexOf(T)
:System.Void Insert(System.Int32, T)
:System.Boolean Remove(T)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, T)
:T get_Item(System.Int32)
:System.Void set_Item(System.Int32, T)
```

Call them on the instance like any other member: `arr:call("get_Item", i)`.
Integer indexing works too and is 0-based: `arr[i]` on a `SystemArray` reads
`get_element(i)`, and on any other managed object it forwards to `get_Item`
(assignment goes to `set_Item`). There is still no `#arr` and no count getter,
so the length is whatever the code that owns the array decided, and
`Get`/`Address` do not bounds check.


| root namespace | types | file |
| --- | --- | --- |
| `(global)` | 213 | [_global_.md](_global_.md) |
| `ace` | 19 | [ace.md](ace.md) |
| `app` | 294 | [app.md](app.md) |
| `chainsaw` | 18769 | [chainsaw.md](chainsaw.md) |
| `GlobalService` | 2 | [GlobalService.md](GlobalService.md) |
| `JsonParser` | 7 | [JsonParser.md](JsonParser.md) |
| `LibJson` | 9 | [LibJson.md](LibJson.md) |
| `rds_external` | 6 | [rds_external.md](rds_external.md) |
| `share` | 309 | [share.md](share.md) |
| `soundlib` | 136 | [soundlib.md](soundlib.md) |
| `System` | 235 | [System.md](System.md) |
| `via` | 4430 | [via.md](via.md) |
