-- The dispatch half of the callback test.
--
-- Probe 07 registered two counters and snapshotted them before it did: one
-- on re.on_frame and one on re.on_gui_draw_element. The game has kept
-- rendering between the two runs, so a working dispatcher has moved them.
--
-- The counts themselves are not reported: they depend on how many frames the
-- game rendered between the two runs, which is whatever the machine felt
-- like. Whether each grew past its snapshot is the part that has to match
-- across builds.
--
-- re.on_frame's dispatch sits behind the scene check in ScriptRunner, so on
-- a game sitting at the title screen the frame counter stays where it was;
-- re.on_gui_draw_element dispatches from the GUI hook and moves immediately.
-- Both lines are stable per game state, which is what a diff needs.

rep("frame count grew", __probe_frame_count ~= nil and __probe_draw_snap ~= nil
    and __probe_frame_count > __probe_frame_snap)
rep("gui draw count grew", __probe_draw_count ~= nil and __probe_draw_snap ~= nil
    and __probe_draw_count > __probe_draw_snap)

-- The on_draw_ui and on_config_save registrations take the same shape as
-- on_frame and are never fired from here; they are pinned as registrations
-- because a rewrite that broke the arity or the storage would show here.
-- The registration lambdas return nothing, so a wrapper reports the call.
local function registers(f, ...)
    f(...)
    return "registered"
end

rep("on_draw_ui registers", registers(re.on_draw_ui, function() end))
rep("on_config_save registers", registers(re.on_config_save, function() end))

return finish()
