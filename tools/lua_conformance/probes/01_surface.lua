-- The bound surface: the names a script can reach and the methods on them.
-- A binding that loses a member shows up here without needing a game object.

local globals = {
    "sdk", "json", "fs", "imgui", "re", "log", "draw", "imnodes",
    "reframework", "thread", "memory",
}

for _, name in ipairs(globals) do
    rep("global " .. name, type(_G[name]))
end

local sdk_methods = {
    "typeof", "type_definition", "find_type_definition", "get_managed_singleton",
    "create_instance", "get_native_field", "set_native_field", "get_native_property",
    "to_managed_object", "is_managed_object", "get_native_object", "get_managed_object",
    "get_primary_camera", "get_types", "get_tdb_version",
}

for _, name in ipairs(sdk_methods) do
    rep("sdk." .. name, type(sdk[name]))
end

local re_methods = {
    "on_frame", "on_pre_application_entry", "on_post_application_entry",
    "on_script_reset", "on_draw_ui", "on_present", "on_pre_gui_draw_element",
    "on_device_reset", "on_message", "on_mod_loaded", "on_inside_loop",
}

for _, name in ipairs(re_methods) do
    rep("re." .. name, type(re[name]))
end

local imgui_methods = {
    "begin_window", "end_window", "text", "button", "checkbox", "slider_float",
    "tree_node", "input_text", "combo", "color_edit", "draw_list",
}

for _, name in ipairs(imgui_methods) do
    rep("imgui." .. name, type(imgui[name]))
end

return finish()