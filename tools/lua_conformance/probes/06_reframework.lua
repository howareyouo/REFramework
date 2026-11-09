-- The reframework usertype: every member a script reaches for, the shapes a
-- wrong call produces, and the write refusal.
--
-- Values that vary per build -- the branch name, the commit fields, the build
-- date -- are reported as types only. The version constants and the game name
-- are compiled in and identical across the builds being compared.

rep("typename", typename(reframework))
rep("type", type(reframework))

-- Static members answer a dot call; a value comparison is safe here.
rep("get_game_name", reframework.get_game_name())
rep("get_version_string", reframework.get_version_string())

-- Members read off the instance. is_drawing_ui depends on whether a menu is
-- open, so it is reported as a type.
rep("get_version_major", reframework:get_version_major())
rep("get_version_minor", reframework:get_version_minor())
rep("get_version_patch", reframework:get_version_patch())
rep("is_drawing_ui type", type(reframework:is_drawing_ui()))
rep("keyboard state typename", typename(reframework:get_keyboard_state()))
rep("keyboard state [0]", tostring(reframework:get_keyboard_state()[0]))
rep("keyboard state [1]", math.type(reframework:get_keyboard_state()[1]))
rep("is_key_down 0", reframework:is_key_down(0))
rep("is_key_down -1", reframework:is_key_down(-1))
rep("is_key_down 300", reframework:is_key_down(300))
rep("get_first_key_down type", type(reframework:get_first_key_down()))
rep("get_branch type", type(reframework:get_branch()))
rep("get_commit_count type", type(reframework:get_commit_count()))
rep("get_commit_hash type", type(reframework:get_commit_hash()))
rep("get_tag type", type(reframework:get_tag()))
rep("get_tag_long type", type(reframework:get_tag_long()))
rep("get_commits_past_tag type", type(reframework:get_commits_past_tag()))
rep("get_build_date type", type(reframework:get_build_date()))
rep("get_build_time type", type(reframework:get_build_time()))
rep("save_config type", type(reframework.save_config))

-- The refusals: a key that is not a number, a write, and the value a missing
-- member reads back.
try("is_key_down string", function() return reframework:is_key_down("a") end)
try("write new key", function() reframework.probe_no_such = 1 end)
rep("missing member", tostring(reframework.probe_no_such))
rep("unknown member read", tostring(reframework.no_such_member))

-- The keyboard state is a fixed 256-entry array; its size travels with the
-- type, so the report pins the length.
try("keyboard state length", function()
    local n = 0

    for _ in pairs(reframework:get_keyboard_state()) do
        n = n + 1
    end

    return n
end)

return finish()
