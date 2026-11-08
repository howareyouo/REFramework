-- Managed-object usertypes: the predicates, the base-to-derived upcast that
-- weak_derive flags, and reference counting.
--
-- A type whose bases are not marked derived reads back as "not a managed
-- object" and refuses every method that takes the base, which is silent until a
-- script calls one.

local body = player_body()

if not body then
    rep("body", "SKIP (no player context)")
    return finish()
end

rep("body typename", typename(body))
rep("is_managed(body)", sdk.is_managed_object(body))
try("to_managed_object(body)", function() return typename(sdk.to_managed_object(body)) end)
try("body get_type_definition", function() return typename(body:get_type_definition()) end)

local transform = body:get_Transform()

rep("transform typename", typename(transform))
rep("is_managed(transform)", sdk.is_managed_object(transform))
try("to_managed_object(transform)", function() return typename(sdk.to_managed_object(transform)) end)

-- A method that takes the base: the derived userdata must satisfy the base
-- check, which is what weak_derive enables.
try("transform call get_Children", function() return typename(transform:call("get_Children")) end)
try("transform add_ref member", function() return type(transform.add_ref) end)

-- SystemArray derives from REManagedObject. Before the derived bases were
-- marked, the base check refused it, so is_managed_object said false and every
-- method taking the base threw. create_managed_array produces one without
-- touching game state, which makes this the steadiest probe in the suite.
local system_array = sdk.create_managed_array("System.Int32", 3)

rep("system_array typename", typename(system_array))
rep("is_managed(system_array)", sdk.is_managed_object(system_array))
try("to_managed_object(system_array)", function() return typename(sdk.to_managed_object(system_array)) end)
try("system_array call get_Length", function() return system_array:call("get_Length") end)
try("system_array write round-trip", function()
    system_array[0] = 42

    return system_array[0]
end)

-- A raw struct reached as a borrowed pointer: managed-object conversion is
-- expected to fail there, and this line pins that expectation.
local tree
try("tree", function()
    local mfsm2 = body:call("getComponent(System.Type)", sdk.typeof("via.motion.MotionFsm2"))

    tree = mfsm2:get_Layer():add_ref():get_Item(0):get_tree_object()

    return typename(tree)
end)

if tree then
    rep("is_managed(tree)", sdk.is_managed_object(tree))
    try("to_managed_object(tree)", function() return typename(sdk.to_managed_object(tree)) end)
    try("tree get_data", function() return type(tree.get_data) end)
end

-- Reference counting round-trip on a managed object.
try("add_ref / release round-trip", function()
    local refed = body:add_ref()

    refed:release()

    return typename(refed)
end)

return finish()