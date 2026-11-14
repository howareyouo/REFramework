-- The owned-value layout behind `ValueType(def)`.
--
-- A constructed ValueType is a std::vector-backed buffer the Lua state owns.
-- Reading it through get_pointer has to land on the value itself, and the
-- state has to run the destructor when it collects the userdata. Both halves
-- were broken by the [T in place] / [T*][T] mismatch (flag 4): the read
-- landed on the vector's internal pointer and the destructor ran on it.
--
-- The baseline refuses ValueType(...) altogether, so `v` stays nil there and
-- only the skip line is reported; on the hand-written layer the block below
-- runs. Every write goes to the probe's own buffer, never to game memory.
--
-- `v.data` and `v.type` are properties, as they were under sol2: the read
-- yields the value. The hand-written layer used to put the getter itself in
-- the member table, so `v.data` came back as a function.

local ty = sdk.find_type_definition("System.Int32")
local v

try("owned construct", function()
    v = ValueType(ty)
    return typename(v)
end)

if v == nil then
    rep("owned value", "SKIP (constructor refused)")
else
    rep("owned metatable", typename(v))
    rep("owned type definition", typename(v:get_type_definition()))
    rep("owned type full name", v:get_type_definition():get_full_name())

    rep("owned initial dword", v:read_dword(0))
    v:write_dword(0, 1234)
    rep("owned written dword", v:read_dword(0))

    -- The property form sol2 exposed. System.Int32 is four bytes, so the dword
    -- appears as its little-endian bytes: 1234 is 0xD2 0x04 0x00 0x00.
    local bytes = v.data
    rep("owned data kind", type(bytes))
    rep("owned data length", #bytes)
    rep("owned data bytes", table.concat({ bytes[1], bytes[2], bytes[3], bytes[4] }, " "))
    rep("owned property type", v.type:get_full_name())

    -- A second value must not share the first one's buffer. Under the broken
    -- layout both reads came off the same vector pointer, so this line is what
    -- separates "the write landed" from "the read went somewhere else".
    local other = ValueType(ty)
    rep("owned second dword", other:read_dword(0))
    rep("owned buffers differ", tostring(v:address() ~= other:address()))

    -- Two full collections: the first queues the userdata, the second runs
    -- __gc. A destructor pointed at the wrong address crashes here.
    v = nil
    other = nil
    collectgarbage()
    collectgarbage()

    local again = ValueType(ty)
    rep("owned after collection", again:read_dword(0))
    again = nil
    collectgarbage()
    collectgarbage()
end

return finish()
