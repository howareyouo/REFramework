--[[
    Leon 服装切换（RE4 / chainsaw 命名空间）

    主角 Leon（chainsaw.PlayerBaseContext / ch0_a0z0）的服装。
    用法（要么贴进 ScriptRunner 直接跑，要么通过 Lua RPC 发出去）：
        127.0.0.1:13377/rpc  {"code": "<本文件内容>; return set_costume(104)", "mode": "chunk"}

    模型侧换装是可靠的；游戏内换装菜单的选中项（GuiCostumeManager）不会被同步，
    详见 docs/lua_snippets/README.md。
]]

local KIND_CH0 = 100000 -- chainsaw.CharacterKindID.ch0_a0z0，Leon，PlayerBaseContext

-- Leon 可用服装：CostumeCharacter 枚举值 -> CostumeManager preset ID
local PRESETS = {
    [102] = 160198385,  -- Costume_02（Leon 初始默认）
    [103] = 2384654012, -- Costume_03
    [104] = 837708748,  -- Costume_04
    [105] = 3577398239, -- Costume_05
    [106] = 2228037905, -- Costume_06
    [107] = 1778690504, -- Costume_07
    [108] = 96070055,   -- Costume_08（Leon 经典造型）
    [110] = 160198385,  -- Costume_10
    [111] = 3293582865, -- Costume_11
    [112] = 96070055,   -- Costume_12
    [113] = 837708748,  -- Costume_13
    [114] = 1778690504, -- Costume_14
    [200] = 160198385,  -- AO_Costume_00
    [201] = 2384654012, -- AO_Costume_01
    [202] = 3840938514, -- AO_Costume_02
    [211] = 2384654012, -- AO_Costume_11
    [221] = 2384654012, -- AO_Costume_21
    [301] = 3488836432, -- MC_Costume_01
}

local function costume_manager()
    local cm = sdk.get_managed_singleton("chainsaw.CharacterManager")
    return cm, cm and cm:call("get_CostumeManager") or nil
end

-- 主控的 via.GameObject：CostumeApplyingInfoList 里 KindID == KIND_CH0 那条的 Key
local function player_game_object(cst)
    local it = cst:call("get_CostumeApplyingInfoList"):call("GetEnumerator")
    while it:call("MoveNext") do
        local kv = it:call("get_Current")
        if kv:call("get_Value"):get_field("<KindID>k__BackingField") == KIND_CH0 then
            return kv:call("get_Key")
        end
    end
end

local function player_context(cm)
    return cm:call("getPlayerContextRefs"):call("get_Item", 0)
end

-- 返回 (ok, 说明)
function set_costume(costume)
    local preset = PRESETS[costume]
    if not preset then
        return false, "未知套装 " .. tostring(costume) .. "，可用值见 PRESETS"
    end

    local cm, cst = costume_manager()
    if not cst then return false, "找不到 chainsaw.CharacterManager / CostumeManager" end

    local go = player_game_object(cst)
    if not go then return false, "找不到主控 GameObject（KindID 100000）" end

    local ctx = player_context(cm)
    if not ctx then return false, "找不到 PlayerBaseContext" end

    -- 两步缺一不可：光写记录模型不会重建
    local ok1, err1 = pcall(function() cst:call("requestCostumeChange", go, KIND_CH0, preset, nil) end)
    local ok2, err2 = pcall(function() cm:call("requestCostumeChange", ctx, preset, nil) end)

    if not (ok1 and ok2) then
        return false, "调用失败: " .. tostring(err1) .. " / " .. tostring(err2)
    end
    return true, string.format("已请求 Costume_%03d (preset %d)", costume, preset)
end

-- 当前套装：读 Context 上真正生效的 preset，反查成枚举值
function get_costume()
    local _, cst = costume_manager()
    if not cst then return nil end
    local ctx = player_context(sdk.get_managed_singleton("chainsaw.CharacterManager"))
    local preset = ctx and ctx:call("get_CostumePresetID")
    if not preset then return nil end
    for costume, p in pairs(PRESETS) do
        if p == preset then return costume end
    end
    return preset -- 映射表外，直接返回 preset ID
end

function list_costumes()
    local out = {}
    for costume, preset in pairs(PRESETS) do
        out[#out + 1] = { costume = costume, preset = preset }
    end
    table.sort(out, function(a, b) return a.costume < b.costume end)
    return out
end
