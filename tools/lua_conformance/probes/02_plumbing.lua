-- The borrowed-pointer plumbing: push_borrowed / put_borrowed.
--
-- A borrowed pointer is cached under the address it came from, so the second
-- lookup of one address must return the same userdata. When that cache wrote
-- the wrong key, the second lookup returned a bare userdata with no metatable,
-- and this probe is where it shows: the type name loses its "sol." prefix and
-- the metatable line flips to nil.

local body = player_body()

if not body then
    rep("body", "SKIP (no player context)")
    return finish()
end

rep("body", typename(body))

local function layer_items()
    local mfsm2 = body:call("getComponent(System.Type)", sdk.typeof("via.motion.MotionFsm2"))
    rep("component", typename(mfsm2))

    local layers = mfsm2:get_Layer():add_ref()
    rep("layers count", layers:get_Count())

    local handle = layers:get_Item(0)
    rep("handle", typename(handle))

    local tree = handle:get_tree_object()
    rep("tree", typename(tree))

    return tree
end

local tree = layer_items()

if not tree then
    rep("tree", "SKIP (no behaviour tree)")
    return finish()
end

-- The same address twice: the second call must hit the cache and hand back the
-- same userdata, metatable and all.
local function node_by_name()
    return tree:get_node_by_name("WalkStart")
end

local first = node_by_name()
rep("get_node_by_name typename", typename(first))
rep("get_node_by_name metatable", getmetatable(first) ~= nil)

local second = node_by_name()
rep("get_node_by_name repeat typename", typename(second))
rep("get_node_by_name repeat metatable", getmetatable(second) ~= nil)
rep("get_node_by_name same object", rawequal(first, second))

try("get_node_by_name get_id", function() return first:get_id() end)
try("get_node_by_name get_full_name", function() return first:get_full_name() ~= nil end)

-- The element of an array of structs is borrowed too.
local nodes = tree:get_nodes()
rep("get_nodes typename", typename(nodes))
rep("get_nodes size", nodes:size())

local node0 = nodes[0]
rep("nodes[0] typename", typename(node0))
rep("nodes[0] metatable", getmetatable(node0) ~= nil)
rep("nodes[0] same object on repeat index", rawequal(nodes[0], nodes[0]))

try("nodes[0] get_full_name", function() return nodes[0]:get_full_name() ~= nil end)

-- pairs walks the live array through the same borrowed path. The metamethod is
-- __pairs, so this has to be pairs(nodes); `for _ in nodes` would try to call
-- the array itself as the iterator.
try("get_nodes pairs count", function()
    local n = 0

    for _ in pairs(nodes) do
        n = n + 1
    end

    return n
end)

-- The key must be the index the element lives at, and the value must be the
-- same userdata pushing_borrowed hands out for that address.
try("get_nodes pairs first", function()
    for k, v in pairs(nodes) do
        return "k=" .. tostring(k) .. " same=" .. tostring(rawequal(v, nodes[k]))
    end

    return "empty"
end)

return finish()