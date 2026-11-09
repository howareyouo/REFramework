-- Shared prelude for the conformance probes.
--
-- The runner concatenates this with one probe body and sends the result to the
-- game, so the probes rely on no path inside the game's filesystem.
--
-- Everything a probe reports goes through rep/try, which normalise the value
-- first: a diff between two dlls must show what the binding did, not the
-- address this run happened to map.

local R = {}

local function norm(s)
    -- Pointer addresses are 16 hex digits in every tostring the bindings
    -- produce. Twelve is the floor so a large but ordinary number survives.
    s = s:gsub("%x%x%x%x%x%x%x%x%x%x%x%x+", "<addr>")
    s = s:gsub("0x%x+", "<hex>")

    return s
end

function rep(key, value)
    R[#R + 1] = key .. " = " .. norm(tostring(value))
end

-- Runs f and reports either its value or the error it raised. The error text is
-- the point: "unknown C++ exception" and "expected BehaviorTreeNode, got
-- number" must show up as a difference.
function try(key, f, ...)
    local ok, value = pcall(f, ...)

    if ok then
        R[#R + 1] = key .. " = " .. norm(tostring(value))
    else
        R[#R + 1] = key .. " = ERR: " .. norm(tostring(value))
    end
end

-- The type name a value reports, without the address. tostring puts the two
-- behind a colon ("sol.Foo*: <addr>"), and the address is what varies per run.
function typename(value)
    local name = norm(tostring(value)):gsub("%s*<addr>%s*$", "")

    return (name:gsub(":%s*$", ""))
end

function finish()
    return table.concat(R, "\n")
end

-- The packed player state every object-reaching probe starts from. Returns nil
-- when the game is still on a loading screen; a probe then reports SKIP and
-- that line stays identical across runs.
function player_body()
    local ok, body = pcall(function()
        local cm = sdk.get_managed_singleton("chainsaw.CharacterManager")
        local ctx = cm and cm:call("getPlayerContextRef")

        return ctx and ctx:get_BodyGameObject()
    end)

    return ok and body or nil
end