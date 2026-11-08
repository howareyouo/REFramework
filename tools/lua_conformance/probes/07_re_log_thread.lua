-- The re, log and thread tables, the sandbox the os and debug libraries live
-- in, and the registration half of the callback API.
--
-- Nothing here registers a callback that can fire with a visible effect
-- except the frame counter at the end: it only increments a global, and the
-- dispatch half of that test is probe 08, which reads the global after a few
-- frames have passed.

rep("re.msg", type(re.msg))
rep("log.info", type(log.info))
rep("log.warn", type(log.warn))
rep("log.error", type(log.error))
rep("log.debug", type(log.debug))
rep("thread.get_hash", type(thread.get_hash))
rep("thread.get_id", type(thread.get_id))
rep("thread.get_hook_storage", type(thread.get_hook_storage))

-- thread values: the id is a 32-bit OS id, the hash is a 64-bit integer, and
-- outside a hook the storage is empty.
rep("thread.get_id", math.type(thread.get_id()))
-- A 64-bit hash only reports as an integer while its top bit is clear, so
-- the kind a build shows depends on which thread ran the chunk; the Lua type
-- is what has to match.
rep("thread.get_hash", type(thread.get_hash()))
rep("thread.get_hook_storage outside hook", tostring(thread.get_hook_storage()))

-- The enum re.CallbackNextAction is what a callback returns to stop the
-- dispatch; a callback returning STOP has to hand back this exact table.
rep("CallbackNextAction CONTINUE", re.CallbackNextAction.CONTINUE)
rep("CallbackNextAction STOP", re.CallbackNextAction.STOP)
rep("CallbackNextAction unknown", tostring(re.CallbackNextAction.no_such))

-- The sandbox: these os and debug entries were removed on purpose, and a
-- script that reaches for them must see nil rather than a working function.
rep("os.remove", tostring(os.remove))
rep("os.rename", tostring(os.rename))
rep("os.execute", tostring(os.execute))
rep("os.exit", tostring(os.exit))
rep("os.setlocale", tostring(os.setlocale))
rep("os.getenv", tostring(os.getenv))
rep("debug.getregistry", tostring(debug.getregistry))
rep("os.time still works", math.type(os.time()))
rep("os.clock still works", math.type(os.clock()))
rep("os.date still works", type(os.date()))
rep("debug.traceback still works", type(debug.traceback))

-- Registration shapes: both calls take a function, the never-fired entry
-- name hashes to a slot no engine code calls, so neither callback runs. The
-- registration lambdas return nothing, so the call goes through a wrapper
-- that reports on the call itself rather than on the missing return value.
local function registers(f, ...)
    f(...)
    return "registered"
end

rep("on_pre_application_entry registers", registers(re.on_pre_application_entry, "ProbeNeverEntry", function() end))
rep("on_application_entry registers", registers(re.on_application_entry, "ProbeNeverEntry", function() end))

-- The wrong shapes a registration can take. on_frame with a number returns
-- nothing at all, so the parentheses are what turn the missing value into a
-- reportable nil.
try("on_frame no args", function() return (re.on_frame()) end)
rep("on_frame number", tostring((re.on_frame(123))))
try("on_application_entry no function", function() return (re.on_application_entry("ProbeNeverEntry", 123)) end)

-- The frame counter. Probe 08 reads it back after a few frames, which turns
-- "the dispatcher calls what on_frame registered" into a report line. The
-- gui-draw counter is the same test on a callback the title screen does
-- dispatch, so the dispatch half of the API is exercised even before a save
-- is loaded.
__probe_frame_count = (__probe_frame_count or 0)
__probe_frame_snap = __probe_frame_count
rep("frame count before", __probe_frame_count)
re.on_frame(function()
    __probe_frame_count = __probe_frame_count + 1
end)
rep("on_frame registers", type(re.on_frame))

__probe_draw_count = (__probe_draw_count or 0)
__probe_draw_snap = __probe_draw_count
re.on_gui_draw_element(function()
    __probe_draw_count = __probe_draw_count + 1
end)
rep("on_gui_draw_element registers", type(re.on_gui_draw_element))

return finish()
