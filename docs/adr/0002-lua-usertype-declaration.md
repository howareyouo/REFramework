# 0002 — Lua usertypes are declared as sol tables, not generated

## Status

Accepted. Recorded after an architecture review proposed extracting a declarative
member list that a binding adapter would read.

## Context

`src/mods/bindings/Sdk.cpp` registers each SDK type with
`lua.new_usertype<T>("T", "member", &T::member, ...)`. The `sdk::RETypeDefinition`
block lists 29 members in a single argument list, most of them bare member
pointers, with hand-written lambdas only where the Lua value genuinely differs
from the C++ one: `get_methods` drops stub bodies, `get_vm_obj_type` returns an int
because `via::clr::VMObjType` is not registered, `is_a` accepts either a definition
or a name, `create_instance_gc_safe` wraps the result in a global object.

The review's proposal — a declarative member list plus an adapter — describes
`new_usertype` itself. The surface is already declared exactly once per type, and
the member names appear nowhere else in the tree: the docs generator that used to
duplicate them was removed in `1ecc09c0`.

## Decision

Usertypes stay as direct sol tables. No member list, no adapter, no docs
generation.

## Consequences

- Every bound name greps to its registration site.
- Classes whose Lua mapping is a straight passthrough cost one line each; the
  extra lambdas in the file are all load-bearing conversions.
- A member list would only pay off if a second consumer existed. There is none,
  and building one would need a loop over a runtime table, which is slower at
  startup and no easier to navigate than the argument list it replaces.