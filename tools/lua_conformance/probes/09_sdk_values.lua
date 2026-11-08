-- The sdk value plumbing the rewrite touches most: how lookups and calls
-- refuse bad input, the json and fs round-trips, and the scratch types.
--
-- Every line pins an observable shape: a nil, a type, or the exact error text
-- a mismatch produces. None of these calls write to the game.

-- find_type_definition: a real type, a name that does not exist, a key of the
-- wrong kind, and no key at all.
local tdb = sdk.find_type_definition("via.vec2")
rep("find_type_definition", typename(tdb))
rep("find_type_definition missing", tostring(sdk.find_type_definition("no.such.type")))
rep("find_type_definition number", tostring(sdk.find_type_definition(123)))
try("find_type_definition no args", function() return sdk.find_type_definition() end)
rep("typeof", typename(sdk.typeof("via.vec3")))
rep("typeof missing", tostring(sdk.typeof("no.such.type")))
rep("get_managed_singleton missing", tostring(sdk.get_managed_singleton("no.such.singleton")))

-- Calls through the type database: the method lookup refuses a wrong name by
-- handing back nil, and a method that exists answers through the context.
rep("get_method missing", tostring(tdb:get_method("no_such_method")))
rep("get_field missing", tostring(tdb:get_field("no_such_field")))

local cam = sdk.get_primary_camera()

if not cam then
    rep("camera", "SKIP (no camera)")
else
    rep("camera call missing method", tostring(cam:call("no_such_method_xyz")))
    rep("camera call extra args", tostring(cam:call("get_Position", 1, 2)))
    rep("camera get_field missing", tostring(cam:get_field("no_such_field_xyz")))
    rep("camera type definition", typename(cam:get_type_definition()))
    rep("camera type full name", cam:get_type_definition():get_full_name())
    try("camera native field bad type", function() return sdk.get_native_field(cam, "no.such.type", "x") end)
end

-- The scratch types: a pointer view and a value type wrapper are created
-- without touching game memory. The ValueType constructor is a documented
-- addition of the hand-written bindings; the baseline refuses the call, so
-- both shapes travel through try and the diff is expected to carry it.
rep("to_memoryview", typename(sdk.to_memoryview(sdk.to_ptr(1), 16)))
rep("memoryview size type", type(sdk.to_memoryview(sdk.to_ptr(1), 16).size))
rep("memoryview size value", sdk.to_memoryview(sdk.to_ptr(1), 16).size)
try("memoryview size call", function() return sdk.to_memoryview(sdk.to_ptr(1), 16):size() end)

try("ValueType construct", function() return typename(ValueType(sdk.find_type_definition("System.Int32"))) end)
try("ValueType get_type_definition", function()
    return typename(ValueType(sdk.find_type_definition("System.Int32")):get_type_definition())
end)

-- json round-trip: parse a literal, dump it back, and parse what came out.
local round
try("json round-trip", function()
    local value = json.load_string('{"a":1,"b":[true,2.5,"x"],"c":{"d":null}}')
    round = json.dump_string(value)
    return round
end)
rep("json reparsed matches",
    type(round) == "string" and tostring(json.load_string(round).a == 1 and json.load_string(round).b[1] == true)
        or "skip")
rep("json null", tostring(json.load_string('{"d":null}').d))

-- fs: the two shapes of a lookup. The game's working directory is the
-- install directory, so re4.exe is always there. Each call is wrapped: the
-- exact set of fs members is part of what the diff reports.
try("fs.cwd type", function() return type(fs.cwd()) end)
try("fs.file_exists exe", function() return fs.file_exists("re4.exe") end)
try("fs.file_exists missing", function() return fs.file_exists("probe_no_such_file.xyz") end)

-- The memory pool accessors report types only; the sizes depend on the
-- session.
try("sdk.get_root_memory_pool type", function() return type(sdk.get_root_memory_pool()) end)

return finish()
