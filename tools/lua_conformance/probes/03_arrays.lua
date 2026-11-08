-- Array semantics: __index, __newindex, __len, __pairs and the error a wrong
-- element type raises.
--
-- The write round-trip is the check that matters: the binding used to read the
-- incoming element as a userdata, so `arr[1] = 148` threw instead of storing and
-- a script that set a value every frame never changed anything. Every write here
-- is restored to the value it found, so running the probe leaves the array alone.

local body = player_body()

if not body then
    rep("body", "SKIP (no player context)")
    return finish()
end

local tree
try("tree", function()
    local mfsm2 = body:call("getComponent(System.Type)", sdk.typeof("via.motion.MotionFsm2"))

    tree = mfsm2:get_Layer():add_ref():get_Item(0):get_tree_object()

    return typename(tree)
end)

if not tree then
    rep("tree", "SKIP (no behaviour tree)")
    return finish()
end

-- A uint32 array owned by the tree.
local states = tree:get_node_by_name("WalkStart"):get_data():get_start_states()

rep("u32 array typename", typename(states))
rep("u32 array size", states:size())
rep("u32 array len", #states)
rep("u32 array index 0 is number", math.type(states[0]))
rep("u32 array out of range", states[states:size()])

-- Write round-trip: read the slot, write a known value, read it back, restore.
try("u32 array write round-trip", function()
    local saved = states[1]

    states[1] = 148
    local stored = states[1]

    states[1] = saved

    return stored
end)

try("u32 array restore", function()
    return states[1] == nil or math.type(states[1])
end)

-- A value the element type cannot hold must fail without touching the slot.
try("u32 array write table", function()
    states[1] = {}

    return "accepted"
end)

try("u32 array pairs count", function()
    local n = 0

    for _ in pairs(states) do
        n = n + 1
    end

    return n
end)

-- A count alone would still pass if the iterator handed back the wrong key, so
-- the first step is checked against the index: the key must be the index the
-- value lives at, and the value must be the one __index returns there.
try("u32 array pairs first", function()
    for k, v in pairs(states) do
        return "k=" .. tostring(k) .. " same=" .. tostring(v == states[k])
    end

    return "empty"
end)

-- An array of structs: the element is borrowed, and a scalar there must be
-- refused with the type it wanted.
local nodes = tree:get_nodes()

rep("struct array typename", typename(nodes))
rep("struct array size", nodes:size())
rep("struct array out of range", nodes[nodes:size()])

try("struct array push_back number", function()
    nodes:push_back(5)

    return "accepted"
end)

try("struct array index with string", function()
    return nodes["x"]
end)

return finish()