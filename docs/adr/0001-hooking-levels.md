# 0001 — Hooking stays two-level: managed methods vs raw addresses

## Status

Accepted. Recorded after an architecture review that proposed one seam for
"a hook".

## Context

This framework installs hooks at two different levels.

`HookManager` (`src/HookManager.hpp`) hooks **reflected managed methods**. Its
interface is typed: it resolves an `sdk::REMethodDefinition`, hooks the resolved
native body through `utility::FunctionHook`, generates a facilitator function
with asmjit from `arg_tys` and `ret_ty`, and hands callbacks
`PreHookFn(std::vector<uintptr_t>& args, std::vector<sdk::RETypeDefinition*>& arg_tys, ...)`
and `PostHookFn(uintptr_t& ret_val, sdk::RETypeDefinition* ret_ty, ...)`. Virtual
calls go through `sdk::REVTableHook`. Everything it knows, it knows from the type
database.

Nine modules install **raw hooks** instead, through `utility::FunctionHook`,
`utility::Patch`, or `safetyhook::MidHook` at a hardcoded or scanned address:
`D3D12Hook`, `DInputHook`, `APIProxy`, `Graphics`, `Hooks`, `IntegrityCheckBypass`,
`LooseFileLoader`, `REFramework`, plus the `shared/utility/FunctionHook` primitive
itself. These targets have no `RETypeDefinition` at all — Win32 exports such as
`VirtualProtect`, `RtlExitUserProcess`, `AddVectoredExceptionHandler`, and
DirectInput's `GetDeviceState` — or they are mid-function instruction addresses
where the useful information is a register value or a branch decision, not a call
signature (`IntegrityCheckBypass` reads the version-check register and rewrites a
path pointer in place through `safetyhook::Context`).

## Decision

Keep the two levels separate. `HookManager` is not the seam for raw hooks, and no
third module gets created to sit above both.

## Consequences

- `HookManager`'s interface stays typed. Accepting raw addresses would force it to
  carry a caller-supplied marshalling spec for every target, which is exactly the
  knowledge its interface exists to hide.
- A raw hook site reads as what it is: hook this address, rewrite these bytes or
  this register. Understanding one of those sites needs no trip through the hook
  manager.
- The cost is that "what is hooked right now" has no single answer. Enumerating it
  means reading the nine call sites. Accepted: the alternative was an enumeration
  layer that would only be correct if each site also declared its own semantics.
- A new raw hook belongs next to the module that owns the behaviour, not in
  `HookManager`.