#include <cstring>

#include <imgui.h>
#include <imgui_internal.h>
#include <imnodes.h>

#include "../ScriptRunner.hpp"
#include "sdk/SceneManager.hpp"
#include "sdk/Renderer.hpp"
#include "REFramework.hpp"
#include "utility/ImGui.hpp"

#include "ImGui.hpp"
#include "LuaBind.hpp"

static constexpr const char* DRAW_LIST_MT = "REFramework.ImDrawList";
static constexpr const char* SORT_SPECS_MT = "REFramework.ImGuiTableSortSpecs";
static constexpr const char* COLUMN_SORT_SPECS_MT = "REFramework.ImGuiTableColumnSortSpecs";

namespace api::imgui {
int32_t g_disabled_counts{0};

void cleanup() {
    for (auto i = 0; i < g_disabled_counts; ++i) {
        ImGui::EndDisabled();
    }

    g_disabled_counts = 0;
}

static ImVec2 imvec2(lua_State* L, int index) {
    index = lua_absindex(L, index);

    ImVec2 out{0.0f, 0.0f};

    if (lh::is<Vector2f>(L, index)) {
        const auto vec = lh::get<Vector2f>(L, index);
        out.x = vec.x;
        out.y = vec.y;
    } else if (lua_istable(L, index)) {
        if (lua_rawlen(L, index) != 2) {
            throw std::runtime_error("Invalid table passed. Table size must be 2.");
        }

        lua_rawgeti(L, index, 1);
        out.x = static_cast<float>(lua_tonumber(L, -1));
        lua_pop(L, 1);
        lua_rawgeti(L, index, 2);
        out.y = static_cast<float>(lua_tonumber(L, -1));
        lua_pop(L, 1);
    } else if (lh::is<Vector3f>(L, index)) {
        const auto vec = lh::get<Vector3f>(L, index);
        out.x = vec.x;
        out.y = vec.y;
    } else if (lh::is<Vector4f>(L, index)) {
        const auto vec = lh::get<Vector4f>(L, index);
        out.x = vec.x;
        out.y = vec.y;
    }

    return out;
}

static ImVec4 imvec4(lua_State* L, int index) {
    index = lua_absindex(L, index);

    ImVec4 out{0.0f, 0.0f, 0.0f, 0.0f};

    if (lh::is<Vector4f>(L, index)) {
        const auto vec = lh::get<Vector4f>(L, index);
        out.x = vec.x;
        out.y = vec.y;
        out.z = vec.z;
        out.w = vec.w;
    } else if (lua_istable(L, index)) {
        if (lua_rawlen(L, index) != 4) {
            throw std::runtime_error("Invalid table passed. Table size must be 4.");
        }

        float* dst[4]{&out.x, &out.y, &out.z, &out.w};

        for (int i = 0; i < 4; ++i) {
            lua_rawgeti(L, index, i + 1);
            *dst[i] = static_cast<float>(lua_tonumber(L, -1));
            lua_pop(L, 1);
        }
    }

    return out;
}

static void put_vec2(lua_State* L, Vector2f value) {
    lh::put(L, value);
}

static int put_changed(lua_State* L, bool changed) {
    lua_pushboolean(L, changed);
    return 1;
}

LH_BIND(l_button) {
    lua_pushboolean(L, ImGui::Button(lh::str(L, 1), imvec2(L, 2)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_small_button) {
    lua_pushboolean(L, ImGui::SmallButton(lh::str(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_invisible_button) {
    lua_pushboolean(L, ImGui::InvisibleButton(lh::str(L, 1), imvec2(L, 2), (ImGuiButtonFlags)lh::opt_int(L, 3, 0)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_arrow_button) {
    lua_pushboolean(L, ImGui::ArrowButton(lh::str(L, 1), (ImGuiDir)lh::num_int(L, 2)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_combo) {
    const char* label = lh::str(L, 1);

    luaL_checktype(L, 3, LUA_TTABLE);

    lua_pushvalue(L, 2);

    const int selection = lua_gettop(L);
    const char* preview_value = "";

    if (lua_rawlen(L, 3) > 0) {
        bool use_first = lua_isnoneornil(L, selection);

        if (!use_first) {
            lua_pushvalue(L, selection);
            lua_gettable(L, 3);
            use_first = lua_isnoneornil(L, -1);
            lua_pop(L, 1);
        }

        if (use_first) {
            lua_pushnil(L);

            if (lua_next(L, 3) != 0) {
                lua_pushvalue(L, -2);
                lua_replace(L, selection);
                lua_pop(L, 2);
            }
        }

        lua_pushvalue(L, selection);
        lua_gettable(L, 3);

        if (lua_type(L, -1) == LUA_TSTRING) {
            preview_value = lua_tostring(L, -1);
        }

        lua_pop(L, 1);
    }

    bool selection_changed = false;

    if (ImGui::BeginCombo(label, preview_value)) {
        lua_pushnil(L);

        while (lua_next(L, 3) != 0) {
            if (lua_type(L, -1) == LUA_TSTRING) {
                const char* entry = lua_tostring(L, -1);

                lua_pushvalue(L, -2);
                lua_pushvalue(L, selection);

                const bool is_current = lua_compare(L, -2, -1, LUA_OPEQ) != 0;

                lua_pop(L, 2);

                if (ImGui::Selectable(entry, is_current)) {
                    lua_pushvalue(L, -2);
                    lua_replace(L, selection);
                    selection_changed = true;
                }
            }

            lua_pop(L, 1);
        }

        ImGui::EndCombo();
    }

    lua_pushboolean(L, selection_changed);
    lua_pushvalue(L, selection);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_drag_float) {
    float value = lh::num_float(L, 2);

    const auto changed = ImGui::DragFloat(
        lh::str(L, 1), &value, lh::num_float(L, 3), lh::num_float(L, 4), lh::num_float(L, 5), lh::opt_str(L, 6, "%.3f"), 0);

    lua_pushboolean(L, changed);
    lua_pushnumber(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_drag_float2) {
    auto value = lh::get_checked<Vector2f>(L, 2, "Vector2f expected for argument #2");

    const auto changed = ImGui::DragFloat2(
        lh::str(L, 1), (float*)&value, lh::num_float(L, 3), lh::num_float(L, 4), lh::num_float(L, 5), lh::opt_str(L, 6, "%.3f"), 0);

    lua_pushboolean(L, changed);
    put_vec2(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_drag_float3) {
    auto value = lh::get_checked<Vector3f>(L, 2, "Vector3f expected for argument #2");

    const auto changed = ImGui::DragFloat3(
        lh::str(L, 1), (float*)&value, lh::num_float(L, 3), lh::num_float(L, 4), lh::num_float(L, 5), lh::opt_str(L, 6, "%.3f"), 0);

    lua_pushboolean(L, changed);
    lh::put(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_drag_float4) {
    auto value = lh::get_checked<Vector4f>(L, 2, "Vector4f expected for argument #2");

    const auto changed = ImGui::DragFloat4(
        lh::str(L, 1), (float*)&value, lh::num_float(L, 3), lh::num_float(L, 4), lh::num_float(L, 5), lh::opt_str(L, 6, "%.3f"), 0);

    lua_pushboolean(L, changed);
    lh::put(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_drag_int) {
    int value = lh::num_int(L, 2);

    const auto changed = ImGui::DragInt(
        lh::str(L, 1), &value, lh::num_float(L, 3), lh::num_int(L, 4), lh::num_int(L, 5), lh::opt_str(L, 6, "%d"), 0);

    lua_pushboolean(L, changed);
    lua_pushinteger(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_slider_float) {
    float value = lh::num_float(L, 2);

    const auto changed = ImGui::SliderFloat(lh::str(L, 1), &value, lh::num_float(L, 3), lh::num_float(L, 4), lh::opt_str(L, 5, "%.3f"), 0);

    lua_pushboolean(L, changed);
    lua_pushnumber(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_slider_int) {
    int value = lh::num_int(L, 2);

    const auto changed = ImGui::SliderInt(lh::str(L, 1), &value, lh::num_int(L, 3), lh::num_int(L, 4), lh::opt_str(L, 5, "%d"), 0);

    lua_pushboolean(L, changed);
    lua_pushinteger(L, value);

    return 2;
}
LH_BIND_END(L)

static std::string g_input_text_buffer{""};
static int g_input_text_selection_start{0};
static int g_input_text_selection_end{0};

static int input_text_callback(ImGuiInputTextCallbackData* data) {
    if ((data->EventFlag & ImGuiInputTextFlags_CallbackResize) != 0) {
        g_input_text_buffer.resize(data->BufTextLen);
        data->Buf = (char*)g_input_text_buffer.c_str();
    }

    g_input_text_selection_start = data->SelectionStart;
    g_input_text_selection_end = data->SelectionEnd;

    return 0;
}

LH_BIND(l_input_text) {
    const auto flags = (ImGuiInputTextFlags)(lh::num_int(L, 3) | ImGuiInputTextFlags_CallbackResize | ImGuiInputTextFlags_CallbackAlways);

    g_input_text_buffer = lh::str(L, 2);

    const auto changed = ImGui::InputText(
        lh::str(L, 1), g_input_text_buffer.data(), g_input_text_buffer.capacity() + 1, flags, input_text_callback);

    lua_pushboolean(L, changed);
    lua_pushlstring(L, g_input_text_buffer.data(), g_input_text_buffer.size());
    lua_pushinteger(L, g_input_text_selection_start);
    lua_pushinteger(L, g_input_text_selection_end);

    return 4;
}
LH_BIND_END(L)

LH_BIND(l_input_text_multiline) {
    const auto flags = (ImGuiInputTextFlags)(lh::num_int(L, 4) | ImGuiInputTextFlags_CallbackResize | ImGuiInputTextFlags_CallbackAlways);

    g_input_text_buffer = lh::str(L, 2);

    const auto size = imvec2(L, 3);

    const auto changed = ImGui::InputTextMultiline(
        lh::str(L, 1), g_input_text_buffer.data(), g_input_text_buffer.capacity() + 1, size, flags, input_text_callback);

    lua_pushboolean(L, changed);
    lua_pushlstring(L, g_input_text_buffer.data(), g_input_text_buffer.size());
    lua_pushinteger(L, g_input_text_selection_start);
    lua_pushinteger(L, g_input_text_selection_end);

    return 4;
}
LH_BIND_END(L)

LH_BIND(l_text) {
    ImGui::TextUnformatted(lh::str(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_text_colored) {
    const auto color = (unsigned)lh::num_int(L, 2);

    const auto r = color & 0xFF;
    const auto g = (color >> 8) & 0xFF;
    const auto b = (color >> 16) & 0xFF;
    const auto a = (color >> 24) & 0xFF;

    ImGui::TextColored(ImVec4{(float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f}, "%s", lh::str(L, 1));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_checkbox) {
    bool value = lh::num_bool(L, 2);

    const auto changed = ImGui::Checkbox(lh::str(L, 1), &value);

    lua_pushboolean(L, changed);
    lua_pushboolean(L, value);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_tree_node) {
    lua_pushboolean(L, ImGui::TreeNode(lh::str(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_tree_node_ptr_id) {
    lua_pushboolean(L, ImGui::TreeNode(lua_topointer(L, 1), lh::str(L, 2)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_tree_node_str_id) {
    lua_pushboolean(L, ImGui::TreeNode(lh::str(L, 1), lh::str(L, 2)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_tree_pop) {
    ImGui::TreePop();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_same_line) {
    ImGui::SameLine();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_is_item_hovered) {
    lua_pushboolean(L, ImGui::IsItemHovered((ImGuiHoveredFlags)lh::opt_int(L, 1, 0)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_item_active) {
    lua_pushboolean(L, ImGui::IsItemActive());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_item_focused) {
    lua_pushboolean(L, ImGui::IsItemFocused());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_begin_window) {
    bool open = true;
    bool* open_p = nullptr;

    if (!lh::is_none(L, 2) && lh::is_bool(L, 2)) {
        open = lua_toboolean(L, 2) != 0;
        open_p = &open;
    }

    if (!open) {
        lua_pushboolean(L, false);
        return 1;
    }

    ImGui::Begin(lh::str(L, 1), open_p, (ImGuiWindowFlags)lh::opt_int(L, 3, 0));

    lua_pushboolean(L, open);

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_window) {
    ImGui::End();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_child_window) {
    lua_pushboolean(
        L, ImGui::BeginChild(lh::str(L, 1), imvec2(L, 2), lh::opt_bool(L, 3, false), (ImGuiWindowFlags)lh::opt_int(L, 4, 0)));

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_child_window) {
    ImGui::EndChild();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_group) {
    ImGui::BeginGroup();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_group) {
    ImGui::EndGroup();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_rect) {
    ImGui::BeginGroup();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_rect) {
    ImGui::EndGroup();

    float rounding = lh::opt_num(L, 2, ImGui::GetStyle().FrameRounding);
    float additional_size = lh::opt_num(L, 1, 0.0f);

    auto mins = ImGui::GetItemRectMin();
    mins.x -= additional_size;
    mins.y -= additional_size;

    auto maxs = ImGui::GetItemRectMax();
    maxs.x += additional_size;
    maxs.y += additional_size;

    ImGui::GetWindowDrawList()->AddRect(
        mins, maxs, ImGui::GetColorU32(ImGuiCol_Border), ImGui::GetStyle().FrameRounding, ImDrawFlags_RoundCornersAll, 1.0f);

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_disabled) {
    ++g_disabled_counts;
    ImGui::BeginDisabled(lh::opt_bool(L, 1, true));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_disabled) {
    if (g_disabled_counts > 0) {
        --g_disabled_counts;
        ImGui::EndDisabled();
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_separator) {
    ImGui::Separator();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_spacing) {
    ImGui::Spacing();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_new_line) {
    ImGui::NewLine();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_collapsing_header) {
    lua_pushboolean(L, ImGui::CollapsingHeader(lh::str(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_load_font) {
    namespace fs = std::filesystem;

    const char* filepath = "doesnt-exist.not-a-real-font";

    if (lh::is_str(L, 1)) {
        filepath = lua_tostring(L, 1);
    }

    const float size = lh::num_float(L, 2);

    if (std::filesystem::path(filepath).is_absolute()) {
        throw std::runtime_error("Font filepath must not be absolute.");
    }

    if (std::string{filepath}.find("..") != std::string::npos) {
        throw std::runtime_error("Font filepath cannot access parent directories.");
    }

    const auto fonts_path = REFramework::get_persistent_dir() / "reframework" / "fonts";
    const auto font_path = fonts_path / filepath;

    fs::create_directories(fonts_path);

    lua_pushinteger(L, g_framework->add_font(font_path, size));

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_push_font) {
    try {
        const int font = lh::num_int(L, 1);

        float size = g_framework->get_font_size();

        if (lh::is_num(L, 2)) {
            size = lh::opt_num(L, 2, size);
        } else {
            size = g_framework->get_font_size(font);
        }

        ImGui::PushFont(g_framework->get_font(font), size);
    } catch (const std::exception& e) {
        spdlog::error("Failed to push_font: {}", e.what());
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_font) {
    ImGui::PopFont();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_push_font_size) {
    ImGui::PushFont(nullptr, lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_font_size) {
    ImGui::PopFont();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_default_font_size) {
    lua_pushinteger(L, g_framework->get_font_size());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_color_picker) {
    const auto flags = (ImGuiColorEditFlags)lh::opt_int(L, 3, 0);
    const auto color = (unsigned)lh::num_int(L, 2);

    auto r = color & 0xFF;
    auto g = (color >> 8) & 0xFF;
    auto b = (color >> 16) & 0xFF;
    auto a = (color >> 24) & 0xFF;

    float col[4]{r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};

    const auto changed = ImGui::ColorPicker4(lh::str(L, 1), col, flags);

    r = (unsigned)(col[0] * 255.0f);
    g = (unsigned)(col[1] * 255.0f);
    b = (unsigned)(col[2] * 255.0f);
    a = (unsigned)(col[3] * 255.0f);

    unsigned new_color = 0;
    new_color |= r;
    new_color |= g << 8;
    new_color |= b << 16;
    new_color |= a << 24;

    lua_pushboolean(L, changed);
    lua_pushinteger(L, new_color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_picker_argb) {
    const auto flags = (ImGuiColorEditFlags)lh::opt_int(L, 3, 0);
    const auto color = (unsigned)lh::num_int(L, 2);

    auto r = (color >> 16) & 0xFF;
    auto g = (color >> 8) & 0xFF;
    auto b = color & 0xFF;
    auto a = (color >> 24) & 0xFF;

    float col[4]{r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};

    const auto changed = ImGui::ColorPicker4(lh::str(L, 1), col, flags);

    r = (unsigned)(col[0] * 255.0f);
    g = (unsigned)(col[1] * 255.0f);
    b = (unsigned)(col[2] * 255.0f);
    a = (unsigned)(col[3] * 255.0f);

    unsigned new_color = 0;
    new_color |= r << 16;
    new_color |= g << 8;
    new_color |= b;
    new_color |= a << 24;

    lua_pushboolean(L, changed);
    lua_pushinteger(L, new_color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_picker3) {
    auto color = lh::get_checked<Vector3f>(L, 2, "Vector3f expected for argument #2");

    const auto changed = ImGui::ColorPicker3(lh::str(L, 1), &color.x, (ImGuiColorEditFlags)lh::opt_int(L, 3, 0));

    lua_pushboolean(L, changed);
    lh::put(L, color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_picker4) {
    auto color = lh::get_checked<Vector4f>(L, 2, "Vector4f expected for argument #2");

    const auto changed = ImGui::ColorPicker4(lh::str(L, 1), &color.x, (ImGuiColorEditFlags)lh::opt_int(L, 3, 0));

    lua_pushboolean(L, changed);
    lh::put(L, color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_edit) {
    const auto flags = (ImGuiColorEditFlags)lh::opt_int(L, 3, 0);
    const auto color = (unsigned)lh::num_int(L, 2);

    auto r = color & 0xFF;
    auto g = (color >> 8) & 0xFF;
    auto b = (color >> 16) & 0xFF;
    auto a = (color >> 24) & 0xFF;

    float col[4]{r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};

    const auto changed = ImGui::ColorEdit4(lh::str(L, 1), col, flags);

    r = (unsigned)(col[0] * 255.0f);
    g = (unsigned)(col[1] * 255.0f);
    b = (unsigned)(col[2] * 255.0f);
    a = (unsigned)(col[3] * 255.0f);

    unsigned new_color = 0;
    new_color |= r;
    new_color |= g << 8;
    new_color |= b << 16;
    new_color |= a << 24;

    lua_pushboolean(L, changed);
    lua_pushinteger(L, new_color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_edit_argb) {
    const auto flags = (ImGuiColorEditFlags)lh::opt_int(L, 3, 0);
    const auto color = (unsigned)lh::num_int(L, 2);

    auto r = (color >> 16) & 0xFF;
    auto g = (color >> 8) & 0xFF;
    auto b = color & 0xFF;
    auto a = (color >> 24) & 0xFF;

    float col[4]{r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};

    const auto changed = ImGui::ColorEdit4(lh::str(L, 1), col, flags);

    r = (unsigned)(col[0] * 255.0f);
    g = (unsigned)(col[1] * 255.0f);
    b = (unsigned)(col[2] * 255.0f);
    a = (unsigned)(col[3] * 255.0f);

    unsigned new_color = 0;
    new_color |= r << 16;
    new_color |= g << 8;
    new_color |= b;
    new_color |= a << 24;

    lua_pushboolean(L, changed);
    lua_pushinteger(L, new_color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_edit3) {
    auto color = lh::get_checked<Vector3f>(L, 2, "Vector3f expected for argument #2");

    const auto changed = ImGui::ColorEdit3(lh::str(L, 1), &color.x, (ImGuiColorEditFlags)lh::opt_int(L, 3, 0));

    lua_pushboolean(L, changed);
    lh::put(L, color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_color_edit4) {
    auto color = lh::get_checked<Vector4f>(L, 2, "Vector4f expected for argument #2");

    const auto changed = ImGui::ColorEdit4(lh::str(L, 1), &color.x, (ImGuiColorEditFlags)lh::opt_int(L, 3, 0));

    lua_pushboolean(L, changed);
    lh::put(L, color);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_set_next_window_pos) {
    ImGui::SetNextWindowPos(imvec2(L, 1), (ImGuiCond)lh::opt_int(L, 2, 0), imvec2(L, 3));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_next_window_size) {
    ImGui::SetNextWindowSize(imvec2(L, 1), (ImGuiCond)lh::opt_int(L, 2, 0));
    return 0;
}
LH_BIND_END(L)

static const char* id_type_error = "Type must be int, const char* or void*";

LH_BIND(l_push_id) {
    if (lh::is_int(L, 1)) {
        ImGui::PushID((int)lua_tointeger(L, 1));
    } else if (lh::is_str(L, 1)) {
        ImGui::PushID(lua_tostring(L, 1));
    } else if (lh::is_ptr(L, 1)) {
        ImGui::PushID(lua_touserdata(L, 1));
    } else {
        throw std::runtime_error(id_type_error);
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_id) {
    ImGui::PopID();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_id) {
    if (lh::is_int(L, 1)) {
        lua_pushinteger(L, (ImGuiID)lua_tointeger(L, 1));
    } else if (lh::is_str(L, 1)) {
        lua_pushinteger(L, ImGui::GetID(lua_tostring(L, 1)));
    } else if (lh::is_ptr(L, 1)) {
        lua_pushinteger(L, ImGui::GetID(lua_touserdata(L, 1)));
    } else {
        throw std::runtime_error(id_type_error);
    }

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_mouse) {
    const auto mouse = ImGui::GetMousePos();

    put_vec2(L, Vector2f{mouse.x, mouse.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_key_index) {
    lua_pushinteger(L, (int)(ImGuiKey)lh::num_int(L, 1));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_key_down) {
    lua_pushboolean(L, ImGui::IsKeyDown((ImGuiKey)lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_key_pressed) {
    lua_pushboolean(L, ImGui::IsKeyPressed((ImGuiKey)lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_key_released) {
    lua_pushboolean(L, ImGui::IsKeyReleased((ImGuiKey)lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_mouse_down) {
    lua_pushboolean(L, ImGui::IsMouseDown(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_mouse_clicked) {
    lua_pushboolean(L, ImGui::IsMouseClicked(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_mouse_released) {
    lua_pushboolean(L, ImGui::IsMouseReleased(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_mouse_double_clicked) {
    lua_pushboolean(L, ImGui::IsMouseDoubleClicked(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_indent) {
    ImGui::Indent(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_unindent) {
    ImGui::Unindent(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_tooltip) {
    ImGui::BeginTooltip();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_tooltip) {
    ImGui::EndTooltip();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_tooltip) {
    ImGui::SetTooltip("%s", lh::str(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_open_popup) {
    ImGui::OpenPopup(lh::str(L, 1), (ImGuiWindowFlags)lh::opt_int(L, 2, 0));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_popup) {
    lua_pushboolean(L, ImGui::BeginPopup(lh::str(L, 1), lh::opt_int(L, 2, 0)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_begin_popup_context_item) {
    lua_pushboolean(L, ImGui::BeginPopupContextItem(lh::str(L, 1), lh::opt_int(L, 2, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_popup) {
    ImGui::EndPopup();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_close_current_popup) {
    ImGui::CloseCurrentPopup();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_is_popup_open) {
    lua_pushboolean(L, ImGui::IsPopupOpen(lh::str(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_calc_text_size) {
    const auto result = ImGui::CalcTextSize(lh::str(L, 1));

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_window_size) {
    const auto result = ImGui::GetWindowSize();

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_window_pos) {
    const auto result = ImGui::GetWindowPos();

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_set_next_item_open) {
    ImGui::SetNextItemOpen(lh::num_bool(L, 1), (ImGuiCond)lh::opt_int(L, 2, 0));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_list_box) {
    lua_pushboolean(L, ImGui::BeginListBox(lh::str(L, 1), imvec2(L, 2)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_list_box) {
    ImGui::EndListBox();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_menu_bar) {
    lua_pushboolean(L, ImGui::BeginMenuBar());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_menu_bar) {
    ImGui::EndMenuBar();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_main_menu_bar) {
    lua_pushboolean(L, ImGui::BeginMainMenuBar());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_main_menu_bar) {
    ImGui::EndMainMenuBar();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_menu) {
    lua_pushboolean(L, ImGui::BeginMenu(lh::str(L, 1), lh::opt_bool(L, 2, true)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_menu) {
    ImGui::EndMenu();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_menu_item) {
    const char* shortcut = lh::opt_str(L, 2, "");

    lua_pushboolean(L, ImGui::MenuItem(lh::str(L, 1), shortcut, lh::opt_bool(L, 3, false), lh::opt_bool(L, 4, true)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_display_size) {
    const auto& result = ImGui::GetIO().DisplaySize;

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

static int push_draw_list(lua_State* L, ImDrawList* draw_list) {
    if (draw_list == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    auto out = static_cast<ImDrawList**>(lua_newuserdatauv(L, sizeof(ImDrawList*), 0));
    *out = draw_list;
    luaL_setmetatable(L, DRAW_LIST_MT);

    return 1;
}

static ImDrawList* check_draw_list(lua_State* L, int index) {
    return *static_cast<ImDrawList**>(luaL_checkudata(L, index, DRAW_LIST_MT));
}

LH_BIND(l_get_window_draw_list) {
    return push_draw_list(L, ImGui::GetWindowDrawList());
}
LH_BIND_END(L)

LH_BIND(l_get_background_draw_list) {
    return push_draw_list(L, ImGui::GetBackgroundDrawList());
}
LH_BIND_END(L)

LH_BIND(l_get_foreground_draw_list) {
    return push_draw_list(L, ImGui::GetForegroundDrawList());
}
LH_BIND_END(L)

LH_BIND(l_push_item_width) {
    ImGui::PushItemWidth(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_item_width) {
    ImGui::PopItemWidth();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_next_item_width) {
    ImGui::SetNextItemWidth(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_calc_item_width) {
    lua_pushnumber(L, ImGui::CalcItemWidth());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_item_add) {
    const auto window = ImGui::GetCurrentWindow();

    if (window == nullptr) {
        lua_pushboolean(L, false);
        return 1;
    }

    const auto rect = ImRect{imvec2(L, 2), imvec2(L, 3)};

    lua_pushboolean(L, ImGui::ItemAdd(rect, window->GetID(lh::str(L, 1))));

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_item_size) {
    const auto rect = ImRect{imvec2(L, 1), imvec2(L, 2)};

    if (lh::is_num(L, 3)) {
        ImGui::ItemSize(rect, lh::opt_num(L, 3, 0.0f));
    } else {
        ImGui::ItemSize(rect);
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_push_style_color) {
    if (lh::is_int(L, 2)) {
        ImGui::PushStyleColor((ImGuiCol)lh::num_int(L, 1), (ImU32)lua_tointeger(L, 2));
    } else if (lh::is<Vector4f>(L, 2)) {
        ImGui::PushStyleColor((ImGuiCol)lh::num_int(L, 1), imvec4(L, 2));
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_style_color) {
    ImGui::PopStyleColor(lh::opt_int(L, 1, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_push_style_var) {
    if (lh::is_num(L, 2)) {
        ImGui::PushStyleVar((ImGuiStyleVar)lh::num_int(L, 1), lh::opt_num(L, 2, 0.0f));
    } else if (lh::is<Vector2f>(L, 2)) {
        ImGui::PushStyleVar((ImGuiStyleVar)lh::num_int(L, 1), imvec2(L, 2));
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_style_var) {
    ImGui::PopStyleVar(lh::opt_int(L, 1, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_cursor_pos) {
    const auto result = ImGui::GetCursorPos();

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_set_cursor_pos) {
    ImGui::SetCursorPos(imvec2(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_cursor_start_pos) {
    const auto result = ImGui::GetCursorStartPos();

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_cursor_screen_pos) {
    const auto result = ImGui::GetCursorScreenPos();

    put_vec2(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_set_cursor_screen_pos) {
    ImGui::SetCursorScreenPos(imvec2(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_item_default_focus) {
    ImGui::SetItemDefaultFocus();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_clipboard) {
    ImGui::SetClipboardText(lh::str(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_clipboard) {
    const auto text = ImGui::GetClipboardText();

    lua_pushstring(L, text == nullptr ? "" : text);

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_progress_bar) {
    ImGui::ProgressBar(lh::num_float(L, 1), imvec2(L, 2), lh::str(L, 3));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_draw_list_path_clear) {
    if (auto dl = ImGui::GetWindowDrawList(); dl != nullptr) {
        dl->PathClear();
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_draw_list_path_line_to) {
    const auto pos = imvec2(L, 1);

    if (auto dl = ImGui::GetWindowDrawList(); dl != nullptr) {
        dl->PathLineTo(pos);
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_draw_list_path_stroke) {
    if (auto dl = ImGui::GetWindowDrawList(); dl != nullptr) {
        dl->PathStroke((ImU32)lh::num_int(L, 1), lua_toboolean(L, 2) != 0, lh::num_float(L, 3));
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_scroll_x) {
    lua_pushnumber(L, ImGui::GetScrollX());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_scroll_y) {
    lua_pushnumber(L, ImGui::GetScrollY());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_x) {
    ImGui::SetScrollX(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_y) {
    ImGui::SetScrollY(lh::num_float(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_scroll_max_x) {
    lua_pushnumber(L, ImGui::GetScrollMaxX());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_scroll_max_y) {
    lua_pushnumber(L, ImGui::GetScrollMaxY());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_here_x) {
    ImGui::SetScrollHereX(lh::opt_num(L, 1, 0.5f));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_here_y) {
    ImGui::SetScrollHereY(lh::opt_num(L, 1, 0.5f));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_from_pos_x) {
    ImGui::SetScrollFromPosX(lh::num_float(L, 1), lh::opt_num(L, 2, 0.5f));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_scroll_from_pos_y) {
    ImGui::SetScrollFromPosY(lh::num_float(L, 1), lh::opt_num(L, 2, 0.5f));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_table) {
    ImVec2 outer_size{};

    if (lh::is<Vector2f>(L, 4)) {
        const auto vec = lh::get<Vector2f>(L, 4);
        outer_size = {vec.x, vec.y};
    }

    lua_pushboolean(L,
        ImGui::BeginTable(lh::str(L, 1), lh::num_int(L, 2), lh::opt_int(L, 3, 0), outer_size, lh::opt_num(L, 5, 0.0f)));

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_end_table) {
    ImGui::EndTable();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_next_row) {
    ImGui::TableNextRow(lh::opt_int(L, 1, 0), lh::opt_num(L, 2, 0.0f));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_next_column) {
    lua_pushboolean(L, ImGui::TableNextColumn());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_set_column_index) {
    lua_pushboolean(L, ImGui::TableSetColumnIndex(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_setup_column) {
    ImGui::TableSetupColumn(lh::str(L, 1),
        lh::opt_int(L, 2, 0),
        lh::opt_num(L, 3, 0.0f),
        (ImGuiID)lh::opt_uint(L, 4, 0));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_setup_scroll_freeze) {
    ImGui::TableSetupScrollFreeze(lh::num_int(L, 1), lh::num_int(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_headers_row) {
    ImGui::TableHeadersRow();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_header) {
    ImGui::TableHeader(lh::str(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_table_get_column_count) {
    lua_pushinteger(L, ImGui::TableGetColumnCount());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_get_column_index) {
    lua_pushinteger(L, ImGui::TableGetColumnIndex());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_get_row_index) {
    lua_pushinteger(L, ImGui::TableGetRowIndex());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_get_column_name) {
    const auto name = ImGui::TableGetColumnName(lh::opt_int(L, 1, -1));

    lua_pushstring(L, name == nullptr ? "" : name);

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_get_column_flags) {
    lua_pushinteger(L, (int)ImGui::TableGetColumnFlags(lh::opt_int(L, 1, -1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_table_set_bg_color) {
    ImGui::TableSetBgColor((ImGuiTableBgTarget)lh::num_int(L, 1), (ImU32)lh::num_int(L, 2), lh::opt_int(L, 3, -1));
    return 0;
}
LH_BIND_END(L)

static int push_sort_specs(lua_State* L, ImGuiTableSortSpecs* specs) {
    if (specs == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    auto out = static_cast<ImGuiTableSortSpecs**>(lua_newuserdatauv(L, sizeof(ImGuiTableSortSpecs*), 0));
    *out = specs;
    luaL_setmetatable(L, SORT_SPECS_MT);

    return 1;
}

static int push_column_sort_specs(lua_State* L, ImGuiTableColumnSortSpecs* specs) {
    if (specs == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    auto out = static_cast<ImGuiTableColumnSortSpecs**>(lua_newuserdatauv(L, sizeof(ImGuiTableColumnSortSpecs*), 0));
    *out = specs;
    luaL_setmetatable(L, COLUMN_SORT_SPECS_MT);

    return 1;
}

LH_BIND(l_table_get_sort_specs) {
    return push_sort_specs(L, ImGui::TableGetSortSpecs());
}
LH_BIND_END(L)
} // namespace api::imgui

namespace api::imgui {
LH_BIND(l_dl_push_clip_rect) {
    check_draw_list(L, 1)->PushClipRect(imvec2(L, 2), imvec2(L, 3), lh::num_bool(L, 4));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_push_clip_rect_fullscreen) {
    check_draw_list(L, 1)->PushClipRectFullScreen();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_pop_clip_rect) {
    check_draw_list(L, 1)->PopClipRect();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_line) {
    check_draw_list(L, 1)->AddLine(
        imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_float(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_rect) {
    check_draw_list(L, 1)->AddRect(imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_float(L, 5),
        (ImDrawFlags)lh::num_int(L, 6), lh::num_float(L, 7));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_rect_filled) {
    check_draw_list(L, 1)->AddRectFilled(imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_float(L, 5),
        (ImDrawFlags)lh::num_int(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_rect_filled_multi_color) {
    check_draw_list(L, 1)->AddRectFilledMultiColor(imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4),
        (ImU32)lh::num_uint(L, 5), (ImU32)lh::num_uint(L, 6), (ImU32)lh::num_uint(L, 7));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_quad) {
    check_draw_list(L, 1)->AddQuad(imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), imvec2(L, 5), (ImU32)lh::num_uint(L, 6),
        lh::num_float(L, 7));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_quad_filled) {
    check_draw_list(L, 1)->AddQuadFilled(
        imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), imvec2(L, 5), (ImU32)lh::num_uint(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_triangle) {
    check_draw_list(L, 1)->AddTriangle(
        imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), (ImU32)lh::num_uint(L, 5), lh::num_float(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_triangle_filled) {
    check_draw_list(L, 1)->AddTriangleFilled(imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), (ImU32)lh::num_uint(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_circle) {
    check_draw_list(L, 1)->AddCircle(
        imvec2(L, 2), lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_int(L, 5), lh::num_float(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_circle_filled) {
    check_draw_list(L, 1)->AddCircleFilled(
        imvec2(L, 2), lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_int(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_ngon) {
    check_draw_list(L, 1)->AddNgon(
        imvec2(L, 2), lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_int(L, 5), lh::num_float(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_ngon_filled) {
    check_draw_list(L, 1)->AddNgonFilled(
        imvec2(L, 2), lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_int(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_ellipse) {
    check_draw_list(L, 1)->AddEllipse(
        imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_float(L, 5), lh::num_int(L, 6), lh::num_float(L, 7));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_ellipse_filled) {
    check_draw_list(L, 1)->AddEllipseFilled(
        imvec2(L, 2), imvec2(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_float(L, 5), lh::num_int(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_text) {
    check_draw_list(L, 1)->AddText(imvec2(L, 2), (ImU32)lh::num_uint(L, 3), lh::str(L, 4));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_bezier_cubic) {
    check_draw_list(L, 1)->AddBezierCubic(imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), imvec2(L, 5),
        (ImU32)lh::num_uint(L, 6), lh::num_float(L, 7));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_add_bezier_quadratic) {
    check_draw_list(L, 1)->AddBezierQuadratic(
        imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), (ImU32)lh::num_uint(L, 5), lh::num_float(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_clear) {
    check_draw_list(L, 1)->PathClear();
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_line_to) {
    check_draw_list(L, 1)->PathLineTo(imvec2(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_line_to_merge_duplicate) {
    check_draw_list(L, 1)->PathLineToMergeDuplicate(imvec2(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_fill_convex) {
    check_draw_list(L, 1)->PathFillConvex((ImU32)lh::num_uint(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_fill_concave) {
    check_draw_list(L, 1)->PathFillConcave((ImU32)lh::num_uint(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_stroke) {
    check_draw_list(L, 1)->PathStroke(
        (ImU32)lh::num_uint(L, 2), (ImDrawFlags)lh::num_int(L, 3), lh::num_float(L, 4));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_arc_to) {
    check_draw_list(L, 1)->PathArcTo(imvec2(L, 2), lh::num_float(L, 3), lh::num_float(L, 4), lh::num_float(L, 5),
        lh::num_int(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_arc_to_fast) {
    check_draw_list(L, 1)->PathArcToFast(
        imvec2(L, 2), lh::num_float(L, 3), lh::num_int(L, 4), lh::num_int(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_elliptical_arc_to) {
    check_draw_list(L, 1)->PathEllipticalArcTo(
        imvec2(L, 2), imvec2(L, 3), 0.0f, lh::num_float(L, 4), lh::num_float(L, 5), lh::num_int(L, 6));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_bezier_cubic_curve_to) {
    check_draw_list(L, 1)->PathBezierCubicCurveTo(imvec2(L, 2), imvec2(L, 3), imvec2(L, 4), lh::num_int(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_bezier_quadratic_curve_to) {
    check_draw_list(L, 1)->PathBezierQuadraticCurveTo(imvec2(L, 2), imvec2(L, 3), lh::num_int(L, 4));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_dl_path_rect) {
    check_draw_list(L, 1)->PathRect(imvec2(L, 2), imvec2(L, 3), lh::num_float(L, 4), (ImDrawFlags)lh::num_int(L, 5));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_specs_get_specs) {
    const auto specs = *static_cast<ImGuiTableSortSpecs**>(luaL_checkudata(L, 1, SORT_SPECS_MT));

    lua_createtable(L, specs->SpecsCount, 0);

    for (int i = 0; i < specs->SpecsCount; ++i) {
        push_column_sort_specs(L, const_cast<ImGuiTableColumnSortSpecs*>(specs->Specs + i));
        lua_rawseti(L, -2, i + 1);
    }

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_specs_index) {
    const auto specs = *static_cast<ImGuiTableSortSpecs**>(luaL_checkudata(L, 1, SORT_SPECS_MT));
    const char* key = lua_type(L, 2) == LUA_TSTRING ? lua_tostring(L, 2) : nullptr;

    if (key == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    if (std::strcmp(key, "specs_dirty") == 0) {
        lua_pushboolean(L, specs->SpecsDirty);
        return 1;
    }

    if (std::strcmp(key, "get_specs") == 0) {
        lua_pushcfunction(L, l_specs_get_specs);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_specs_newindex) {
    const auto specs = *static_cast<ImGuiTableSortSpecs**>(luaL_checkudata(L, 1, SORT_SPECS_MT));
    const char* key = lua_type(L, 2) == LUA_TSTRING ? lua_tostring(L, 2) : nullptr;

    if (key != nullptr && std::strcmp(key, "specs_dirty") == 0) {
        specs->SpecsDirty = lua_toboolean(L, 3) != 0;
        return 0;
    }

    return luaL_error(L, "TableSortSpecs has no writable member '%s'", key == nullptr ? "" : key);
}
LH_BIND_END(L)

LH_BIND(l_column_specs_index) {
    const auto specs = *static_cast<ImGuiTableColumnSortSpecs**>(luaL_checkudata(L, 1, COLUMN_SORT_SPECS_MT));
    const char* key = lua_type(L, 2) == LUA_TSTRING ? lua_tostring(L, 2) : nullptr;

    if (key == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    if (std::strcmp(key, "user_id") == 0) {
        lua_pushinteger(L, (lua_Integer)specs->ColumnUserID);
        return 1;
    }

    if (std::strcmp(key, "column_index") == 0) {
        lua_pushinteger(L, specs->ColumnIndex);
        return 1;
    }

    if (std::strcmp(key, "sort_order") == 0) {
        lua_pushinteger(L, specs->SortOrder);
        return 1;
    }

    if (std::strcmp(key, "sort_direction") == 0) {
        lua_pushinteger(L, (lua_Integer)specs->SortDirection);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_column_specs_newindex) {
    const auto specs = *static_cast<ImGuiTableColumnSortSpecs**>(luaL_checkudata(L, 1, COLUMN_SORT_SPECS_MT));
    const char* key = lua_type(L, 2) == LUA_TSTRING ? lua_tostring(L, 2) : nullptr;

    if (key != nullptr && std::strcmp(key, "user_id") == 0) {
        specs->ColumnUserID = (ImGuiID)lh::num_uint(L, 3);
        return 0;
    }

    if (key != nullptr && std::strcmp(key, "column_index") == 0) {
        specs->ColumnIndex = (ImS16)lh::num_int(L, 3);
        return 0;
    }

    if (key != nullptr && std::strcmp(key, "sort_order") == 0) {
        specs->SortOrder = (ImS16)lh::num_int(L, 3);
        return 0;
    }

    if (key != nullptr && std::strcmp(key, "sort_direction") == 0) {
        return luaL_error(L, "'sort_direction' is a read-only member");
    }

    return luaL_error(L, "TableColumnSortSpecs has no writable member '%s'", key == nullptr ? "" : key);
}
LH_BIND_END(L)

// sol2 published `TableSortSpecs` and `TableColumnSortSpecs` under `imgui` as
// well as in the metatables, so a member could be read off the type table
// (`imgui.TableSortSpecs.get_specs`). A type table holds them as the function
// an instance offers, which is what these two produce.
LH_BIND(l_specs_get_specs_dirty) {
    const auto specs = *static_cast<ImGuiTableSortSpecs**>(luaL_checkudata(L, 1, SORT_SPECS_MT));

    lua_pushboolean(L, specs->SpecsDirty);
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_column_specs_get_value) {
    const auto specs = *static_cast<ImGuiTableColumnSortSpecs**>(luaL_checkudata(L, 1, COLUMN_SORT_SPECS_MT));

    switch (static_cast<int>(lua_tointeger(L, lua_upvalueindex(1)))) {
    case 0: lua_pushinteger(L, static_cast<lua_Integer>(specs->ColumnUserID)); break;
    case 1: lua_pushinteger(L, specs->ColumnIndex); break;
    case 2: lua_pushinteger(L, specs->SortOrder); break;
    default: lua_pushinteger(L, static_cast<lua_Integer>(specs->SortDirection)); break;
    }

    return 1;
}
LH_BIND_END(L)
} // namespace api::imgui

namespace api::draw {
static bool to_world_pos(lua_State* L, int index, Vector3f& out) {
    if (lh::is<Vector2f>(L, index)) {
        const auto& v = lh::get_ref<Vector2f>(L, index);
        out = Vector3f{v.x, v.y, 0.0f};
        return true;
    }

    if (lh::is<Vector3f>(L, index)) {
        out = lh::get_ref<Vector3f>(L, index);
        return true;
    }

    if (lh::is<Vector4f>(L, index)) {
        const auto& v = lh::get_ref<Vector4f>(L, index);
        out = Vector3f{v.x, v.y, v.z};
        return true;
    }

    return false;
}

static bool push_world_to_screen(lua_State* L, int index) {
    Vector3f world_pos{};

    if (!to_world_pos(L, index, world_pos)) {
        lua_pushnil(L);
        return false;
    }

    const auto result = ::sdk::renderer::world_to_screen(world_pos);

    if (!result.has_value()) {
        lua_pushnil(L);
        return false;
    }

    lh::put(L, *result);

    return true;
}

LH_BIND(l_world_to_screen) {
    push_world_to_screen(L, 1);
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_world_text) {
    const char* text = lh::str(L, 1);

    if (!push_world_to_screen(L, 2)) {
        lua_pop(L, 1);
        return 0;
    }

    const auto pos = lh::get<Vector2f>(L, -1);
    lua_pop(L, 1);

    ImGui::GetBackgroundDrawList()->AddText(ImVec2{pos.x, pos.y}, (ImU32)lh::opt_uint(L, 3, 0xFFFFFFFFu), text);

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_text) {
    ImGui::GetBackgroundDrawList()->AddText(
        ImVec2{lh::num_float(L, 2), lh::num_float(L, 3)}, (ImU32)lh::num_uint(L, 4), lh::str(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_filled_rect) {
    const auto x = lh::num_float(L, 1);
    const auto y = lh::num_float(L, 2);

    ImGui::GetBackgroundDrawList()->AddRectFilled(
        ImVec2{x, y}, ImVec2{x + lh::num_float(L, 3), y + lh::num_float(L, 4)}, (ImU32)lh::num_uint(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_outline_rect) {
    const auto x = lh::num_float(L, 1);
    const auto y = lh::num_float(L, 2);

    ImGui::GetBackgroundDrawList()->AddRect(
        ImVec2{x, y}, ImVec2{x + lh::num_float(L, 3), y + lh::num_float(L, 4)}, (ImU32)lh::num_uint(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_line) {
    ImGui::GetBackgroundDrawList()->AddLine(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)},
        ImVec2{lh::num_float(L, 3), lh::num_float(L, 4)}, (ImU32)lh::num_uint(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_outline_circle) {
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)},
        lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::is_none(L, 5) ? 32 : lh::num_int(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_filled_circle) {
    ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)},
        lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::is_none(L, 5) ? 32 : lh::num_int(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_outline_quad) {
    ImGui::GetBackgroundDrawList()->AddQuad(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)},
        ImVec2{lh::num_float(L, 3), lh::num_float(L, 4)}, ImVec2{lh::num_float(L, 5), lh::num_float(L, 6)},
        ImVec2{lh::num_float(L, 7), lh::num_float(L, 8)}, (ImU32)lh::num_uint(L, 9));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_filled_quad) {
    ImGui::GetBackgroundDrawList()->AddQuadFilled(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)},
        ImVec2{lh::num_float(L, 3), lh::num_float(L, 4)}, ImVec2{lh::num_float(L, 5), lh::num_float(L, 6)},
        ImVec2{lh::num_float(L, 7), lh::num_float(L, 8)}, (ImU32)lh::num_uint(L, 9));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_sphere) {
    Vector3f world_pos{};

    if (!to_world_pos(L, 1, world_pos)) {
        return 0;
    }

    ::imgui::draw_sphere(world_pos, lh::num_float(L, 2), (ImU32)lh::num_uint(L, 3), lh::num_bool(L, 4));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_capsule) {
    Vector3f start_pos{};
    Vector3f end_pos{};

    if (!to_world_pos(L, 1, start_pos) || !to_world_pos(L, 2, end_pos)) {
        return 0;
    }

    ::imgui::draw_capsule(
        start_pos, end_pos, lh::num_float(L, 3), (ImU32)lh::num_uint(L, 4), lh::num_bool(L, 5));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_gizmo) {
    if (!ImGui::GetIO().MouseDown[0]) {
        ImGuizmo::Enable(false);
        ImGuizmo::Enable(true);
    }

    ImGuizmo::MODE mode{};

    if (lh::is_none(L, 4)) {
        mode = ImGuizmo::MODE::WORLD;
    } else if (lh::is_int(L, 4)) {
        mode = (ImGuizmo::MODE)lh::num_int(L, 4);
    } else {
        throw std::runtime_error("Invalid mode passed to gizmo");
    }

    ImGuizmo::OPERATION operation{};

    if (lh::is_none(L, 3)) {
        operation = ImGuizmo::OPERATION::UNIVERSAL;
    } else if (lh::is_int(L, 3)) {
        operation = (ImGuizmo::OPERATION)lh::num_int(L, 3);
    } else {
        throw std::runtime_error("Invalid operation passed to gizmo");
    }

    if (!lh::is<Matrix4x4f>(L, 2)) {
        throw std::runtime_error("Matrix4x4f expected for argument #2");
    }

    auto& transform = lh::get_ref<Matrix4x4f>(L, 2);

    ImGuizmo::SetID((int)lh::num_int(L, 1));

    const auto changed = ::imgui::draw_gizmo(transform, operation, mode);

    lua_pushboolean(L, changed);
    lh::put(L, transform);

    return 2;
}
LH_BIND_END(L)

LH_BIND(l_cube) {
    if (!lh::is<Matrix4x4f>(L, 1)) {
        throw std::runtime_error("Matrix4x4f expected for argument #1");
    }

    ::imgui::draw_cube(lh::get_ref<Matrix4x4f>(L, 1));

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_grid) {
    if (!lh::is<Matrix4x4f>(L, 1)) {
        throw std::runtime_error("Matrix4x4f expected for argument #1");
    }

    ::imgui::draw_grid(lh::get_ref<Matrix4x4f>(L, 1), lh::num_float(L, 2));

    return 0;
}
LH_BIND_END(L)
} // namespace api::draw

namespace api::imnodes {
int32_t g_node_editor_counts{0};
int32_t g_node_counts{};
int32_t g_node_titlebar_counts{0};
int32_t g_color_style_counts{};
int32_t g_color_style_var_counts{};
int32_t g_input_attribute_counts{0};
int32_t g_output_attribute_counts{0};
int32_t g_static_attribute_counts{0};

static int push_id_result(lua_State* L, bool result, int id) {
    lua_pushboolean(L, result);
    lua_pushinteger(L, id);

    return 2;
}

LH_BIND(l_is_editor_hovered) {
    lua_pushboolean(L, ImNodes::IsEditorHovered());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_node_hovered) {
    int id{};
    const auto result = ImNodes::IsNodeHovered(&id);

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_is_link_hovered) {
    int id{};
    const auto result = ImNodes::IsLinkHovered(&id);

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_is_pin_hovered) {
    int id{};
    const auto result = ImNodes::IsPinHovered(&id);

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_begin_node_editor) {
    ImNodes::BeginNodeEditor();
    ++g_node_editor_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_node_editor) {
    ImNodes::EndNodeEditor();
    --g_node_editor_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_node) {
    ImNodes::BeginNode(lh::num_int(L, 1));
    ++g_node_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_node) {
    ImNodes::EndNode();
    --g_node_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_node_titlebar) {
    ImNodes::BeginNodeTitleBar();
    ++g_node_titlebar_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_node_titlebar) {
    ImNodes::EndNodeTitleBar();
    --g_node_titlebar_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_input_attribute) {
    ImNodes::BeginInputAttribute(lh::num_int(L, 1), (ImNodesPinShape)lh::num_int(L, 2));
    ++g_input_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_input_attribute) {
    ImNodes::EndInputAttribute();
    --g_input_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_output_attribute) {
    ImNodes::BeginOutputAttribute(lh::num_int(L, 1), (ImNodesPinShape)lh::num_int(L, 2));
    ++g_output_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_output_attribute) {
    ImNodes::EndOutputAttribute();
    --g_output_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_begin_static_attribute) {
    ImNodes::BeginStaticAttribute(lh::num_int(L, 1));
    ++g_static_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_end_static_attribute) {
    ImNodes::EndStaticAttribute();
    --g_static_attribute_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_minimap) {
    ImNodes::MiniMap(lh::num_float(L, 1), (ImNodesMiniMapLocation)lh::num_int(L, 2));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_link) {
    ImNodes::Link(lh::num_int(L, 1), lh::num_int(L, 2), lh::num_int(L, 3));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_node_dimensions) {
    const auto result = ImNodes::GetNodeDimensions(lh::num_int(L, 1));

    lh::put(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_push_color_style) {
    ImNodes::PushColorStyle((ImNodesCol)lh::num_int(L, 1), lh::num_uint(L, 2));
    ++g_color_style_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_color_style) {
    ImNodes::PopColorStyle();
    --g_color_style_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_push_style_var) {
    ImNodes::PushStyleVar((ImNodesStyleVar)lh::num_int(L, 1), lh::num_float(L, 2));
    ++g_color_style_var_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_push_style_var_vec2) {
    ImNodes::PushStyleVar(
        (ImNodesStyleVar)lh::num_int(L, 1), ImVec2{lh::num_float(L, 2), lh::num_float(L, 3)});
    ++g_color_style_var_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_pop_style_var) {
    ImNodes::PopStyleVar();
    --g_color_style_var_counts;
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_node_screen_space_pos) {
    ImNodes::SetNodeScreenSpacePos(lh::num_int(L, 1), ImVec2{lh::num_float(L, 2), lh::num_float(L, 3)});
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_node_editor_space_pos) {
    ImNodes::SetNodeEditorSpacePos(lh::num_int(L, 1), ImVec2{lh::num_float(L, 2), lh::num_float(L, 3)});
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_set_node_grid_space_pos) {
    ImNodes::SetNodeGridSpacePos(lh::num_int(L, 1), ImVec2{lh::num_float(L, 2), lh::num_float(L, 3)});
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_get_node_screen_space_pos) {
    const auto result = ImNodes::GetNodeScreenSpacePos(lh::num_int(L, 1));

    lh::put(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_node_editor_space_pos) {
    const auto result = ImNodes::GetNodeEditorSpacePos(lh::num_int(L, 1));

    lh::put(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_node_grid_space_pos) {
    const auto result = ImNodes::GetNodeGridSpacePos(lh::num_int(L, 1));

    lh::put(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_clear_node_selection) {
    if (lh::is_none(L, 1)) {
        ImNodes::ClearNodeSelection();
    } else if (lh::is_int(L, 1)) {
        ImNodes::ClearNodeSelection(lh::num_int(L, 1));
    } else {
        throw std::runtime_error("id_object must be nil or int");
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_clear_link_selection) {
    if (lh::is_none(L, 1)) {
        ImNodes::ClearLinkSelection();
    } else if (lh::is_int(L, 1)) {
        ImNodes::ClearLinkSelection(lh::num_int(L, 1));
    } else {
        throw std::runtime_error("id_object must be nil or int");
    }

    return 0;
}
LH_BIND_END(L)

LH_BIND(l_editor_reset_panning) {
    ImNodes::EditorContextResetPanning(ImVec2{lh::num_float(L, 1), lh::num_float(L, 2)});
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_editor_get_panning) {
    const auto result = ImNodes::EditorContextGetPanning();

    lh::put(L, Vector2f{result.x, result.y});

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_link_started) {
    int id{};
    const auto result = ImNodes::IsLinkStarted(&id);

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_is_link_dropped) {
    int id{};
    const auto result = ImNodes::IsLinkDropped(&id, lh::num_bool(L, 1));

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_is_link_destroyed) {
    int id{};
    const auto result = ImNodes::IsLinkDestroyed(&id);

    return push_id_result(L, result, id);
}
LH_BIND_END(L)

LH_BIND(l_is_link_created) {
    int started_at_node{};
    int started_at_attr{};
    int ended_at_node{};
    int ended_at_attr{};
    bool created_from_snap{};

    const auto result = ImNodes::IsLinkCreated(
        &started_at_node, &started_at_attr, &ended_at_node, &ended_at_attr, &created_from_snap);

    lua_pushboolean(L, result);
    lua_pushinteger(L, started_at_node);
    lua_pushinteger(L, started_at_attr);
    lua_pushinteger(L, ended_at_node);
    lua_pushinteger(L, ended_at_attr);
    lua_pushboolean(L, created_from_snap);

    return 6;
}
LH_BIND_END(L)

LH_BIND(l_get_selected_nodes) {
    const auto num_selected = ImNodes::NumSelectedNodes();

    lua_createtable(L, num_selected, 0);

    if (num_selected > 0) {
        std::vector<int> out(num_selected);
        ImNodes::GetSelectedNodes(out.data());

        for (int i = 0; i < num_selected; ++i) {
            lua_pushinteger(L, out[i]);
            lua_rawseti(L, -2, i + 1);
        }
    }

    return 1;
}
LH_BIND_END(L)

LH_BIND(l_get_selected_links) {
    const auto num_selected = ImNodes::NumSelectedLinks();

    lua_createtable(L, num_selected, 0);

    if (num_selected > 0) {
        std::vector<int> out(num_selected);
        ImNodes::GetSelectedLinks(out.data());

        for (int i = 0; i < num_selected; ++i) {
            lua_pushinteger(L, out[i]);
            lua_rawseti(L, -2, i + 1);
        }
    }

    return 1;
}
LH_BIND_END(L)

void cleanup() {
    for (auto i = 0; i < g_node_editor_counts; ++i) {
        ImNodes::EndNodeEditor();
    }

    g_node_editor_counts = 0;

    for (auto i = 0; i < g_node_counts; ++i) {
        ImNodes::EndNode();
    }

    g_node_counts = 0;

    for (auto i = 0; i < g_node_titlebar_counts; ++i) {
        ImNodes::EndNodeTitleBar();
    }

    g_node_titlebar_counts = 0;

    for (auto i = 0; i < g_color_style_counts; ++i) {
        ImNodes::PopColorStyle();
    }

    g_color_style_counts = 0;

    for (auto i = 0; i < g_color_style_var_counts; ++i) {
        ImNodes::PopStyleVar();
    }

    g_color_style_var_counts = 0;

    for (auto i = 0; i < g_input_attribute_counts; ++i) {
        ImNodes::EndInputAttribute();
    }

    g_input_attribute_counts = 0;

    for (auto i = 0; i < g_output_attribute_counts; ++i) {
        ImNodes::EndOutputAttribute();
    }

    g_output_attribute_counts = 0;

    for (auto i = 0; i < g_static_attribute_counts; ++i) {
        ImNodes::EndStaticAttribute();
    }

    g_static_attribute_counts = 0;
}
} // namespace api::imnodes

LH_BIND(l_imguizmo_is_over) {
    lua_pushboolean(L, ImGuizmo::IsOver());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_imguizmo_is_using) {
    lua_pushboolean(L, ImGuizmo::IsUsing());
    return 1;
}
LH_BIND_END(L)

namespace api::imnodes {
LH_BIND(l_is_node_selected) {
    lua_pushboolean(L, ImNodes::IsNodeSelected(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_is_link_selected) {
    lua_pushboolean(L, ImNodes::IsLinkSelected(lh::num_int(L, 1)));
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_num_selected_nodes) {
    lua_pushinteger(L, ImNodes::NumSelectedNodes());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_num_selected_links) {
    lua_pushinteger(L, ImNodes::NumSelectedLinks());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_select_node) {
    ImNodes::SelectNode(lh::num_int(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_select_link) {
    ImNodes::SelectLink(lh::num_int(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_is_attribute_active) {
    lua_pushboolean(L, ImNodes::IsAttributeActive());
    return 1;
}
LH_BIND_END(L)

LH_BIND(l_snap_node_to_grid) {
    ImNodes::SnapNodeToGrid(lh::num_int(L, 1));
    return 0;
}
LH_BIND_END(L)

LH_BIND(l_editor_move_to_node) {
    ImNodes::EditorContextMoveToNode(lh::num_int(L, 1));
    return 0;
}
LH_BIND_END(L)

} // namespace api::imnodes

static const std::pair<const char*, lua_Integer> IMGUIZMO_OPERATION[]{
        { "TRANSLATE", ImGuizmo::OPERATION::TRANSLATE },
        { "ROTATE", ImGuizmo::OPERATION::ROTATE },
        { "SCALE", ImGuizmo::OPERATION::SCALE },
        { "SCALEU", ImGuizmo::OPERATION::SCALEU },
        { "UNIVERSAL", ImGuizmo::OPERATION::UNIVERSAL },
};

static const std::pair<const char*, lua_Integer> IMGUIZMO_MODE[]{
        { "WORLD", ImGuizmo::MODE::WORLD },
        { "LOCAL", ImGuizmo::MODE::LOCAL },
};

static const std::pair<const char*, lua_Integer> IMGUI_TABLE_FLAGS[]{
        { "None", ImGuiTableFlags_None },
        { "Resizable", ImGuiTableFlags_Resizable },
        { "Reorderable", ImGuiTableFlags_Reorderable },
        { "Hideable", ImGuiTableFlags_Hideable },
        { "Sortable", ImGuiTableFlags_Sortable },
        { "NoSavedSettings", ImGuiTableFlags_NoSavedSettings },
        { "ContextMenuInBody", ImGuiTableFlags_ContextMenuInBody },
        { "RowBg", ImGuiTableFlags_RowBg },
        { "BordersInnerH", ImGuiTableFlags_BordersInnerH },
        { "BordersOuterH", ImGuiTableFlags_BordersOuterH },
        { "BordersInnerV", ImGuiTableFlags_BordersInnerV },
        { "BordersOuterV", ImGuiTableFlags_BordersOuterV },
        { "BordersH", ImGuiTableFlags_BordersH },
        { "BordersV", ImGuiTableFlags_BordersV },
        { "BordersInner", ImGuiTableFlags_BordersInner },
        { "BordersOuter", ImGuiTableFlags_BordersOuter },
        { "Borders", ImGuiTableFlags_Borders },
        { "NoBordersInBody", ImGuiTableFlags_NoBordersInBody },
        { "NoBordersInBodyUntilResize", ImGuiTableFlags_NoBordersInBodyUntilResize },
        { "SizingFixedFit", ImGuiTableFlags_SizingFixedFit },
        { "SizingFixedSame", ImGuiTableFlags_SizingFixedSame },
        { "SizingStretchProp", ImGuiTableFlags_SizingStretchProp },
        { "SizingStretchSame", ImGuiTableFlags_SizingStretchSame },
        { "NoHostExtendX", ImGuiTableFlags_NoHostExtendX },
        { "NoHostExtendY", ImGuiTableFlags_NoHostExtendY },
        { "NoKeepColumnsVisible", ImGuiTableFlags_NoKeepColumnsVisible },
        { "PreciseWidths", ImGuiTableFlags_PreciseWidths },
        { "NoClip", ImGuiTableFlags_NoClip },
        { "PadOuterX", ImGuiTableFlags_PadOuterX },
        { "NoPadOuterX", ImGuiTableFlags_NoPadOuterX },
        { "NoPadInnerX", ImGuiTableFlags_NoPadInnerX },
        { "ScrollX", ImGuiTableFlags_ScrollX },
        { "ScrollY", ImGuiTableFlags_ScrollY },
        { "SortMulti", ImGuiTableFlags_SortMulti },
        { "SortTristate", ImGuiTableFlags_SortTristate },
};

static const std::pair<const char*, lua_Integer> IMGUI_COLUMN_FLAGS[]{
        { "None", ImGuiTableColumnFlags_None },
        { "DefaultHide", ImGuiTableColumnFlags_DefaultHide },
        { "DefaultSort", ImGuiTableColumnFlags_DefaultSort },
        { "WidthStretch", ImGuiTableColumnFlags_WidthStretch },
        { "WidthFixed", ImGuiTableColumnFlags_WidthFixed },
        { "NoResize", ImGuiTableColumnFlags_NoResize },
        { "NoReorder", ImGuiTableColumnFlags_NoReorder },
        { "NoHide", ImGuiTableColumnFlags_NoHide },
        { "NoClip", ImGuiTableColumnFlags_NoClip },
        { "NoSort", ImGuiTableColumnFlags_NoSort },
        { "NoSortAscending", ImGuiTableColumnFlags_NoSortAscending },
        { "NoSortDescending", ImGuiTableColumnFlags_NoSortDescending },
        { "NoHeaderWidth", ImGuiTableColumnFlags_NoHeaderWidth },
        { "PreferSortAscending", ImGuiTableColumnFlags_PreferSortAscending },
        { "PreferSortDescending", ImGuiTableColumnFlags_PreferSortDescending },
        { "IndentEnable", ImGuiTableColumnFlags_IndentEnable },
        { "IndentDisable", ImGuiTableColumnFlags_IndentDisable },
        { "IsEnabled", ImGuiTableColumnFlags_IsEnabled },
        { "IsVisible", ImGuiTableColumnFlags_IsVisible },
        { "IsSorted", ImGuiTableColumnFlags_IsSorted },
        { "IsHovered", ImGuiTableColumnFlags_IsHovered },
};

static const std::pair<const char*, lua_Integer> IMGUI_KEY[]{
        // Keys
        { "Key_None", ImGuiKey_None },
        { "Key_Tab", ImGuiKey_Tab },
        { "Key_LeftArrow", ImGuiKey_LeftArrow },
        { "Key_RightArrow", ImGuiKey_RightArrow },
        { "Key_UpArrow", ImGuiKey_UpArrow },
        { "Key_DownArrow", ImGuiKey_DownArrow },
        { "Key_PageUp", ImGuiKey_PageUp },
        { "Key_PageDown", ImGuiKey_PageDown },
        { "Key_Home", ImGuiKey_Home },
        { "Key_End", ImGuiKey_End },
        { "Key_Insert", ImGuiKey_Insert },
        { "Key_Delete", ImGuiKey_Delete },
        { "Key_Backspace", ImGuiKey_Backspace },
        { "Key_Space", ImGuiKey_Space },
        { "Key_Enter", ImGuiKey_Enter },
        { "Key_Escape", ImGuiKey_Escape },
        { "Key_LeftCtrl", ImGuiKey_LeftCtrl },
        { "Key_LeftShift", ImGuiKey_LeftShift },
        { "Key_LeftAlt", ImGuiKey_LeftAlt },
        { "Key_LeftSuper", ImGuiKey_LeftSuper },
        { "Key_RightCtrl", ImGuiKey_RightCtrl },
        { "Key_RightShift", ImGuiKey_RightShift },
        { "Key_RightAlt", ImGuiKey_RightAlt },
        { "Key_RightSuper", ImGuiKey_RightSuper },
        { "Key_Menu", ImGuiKey_Menu },
        { "Key_0", ImGuiKey_0 },
        { "Key_1", ImGuiKey_1 },
        { "Key_2", ImGuiKey_2 },
        { "Key_3", ImGuiKey_3 },
        { "Key_4", ImGuiKey_4 },
        { "Key_5", ImGuiKey_5 },
        { "Key_6", ImGuiKey_6 },
        { "Key_7", ImGuiKey_7 },
        { "Key_8", ImGuiKey_8 },
        { "Key_9", ImGuiKey_9 },
        { "Key_A", ImGuiKey_A },
        { "Key_B", ImGuiKey_B },
        { "Key_C", ImGuiKey_C },
        { "Key_D", ImGuiKey_D },
        { "Key_E", ImGuiKey_E },
        { "Key_F", ImGuiKey_F },
        { "Key_G", ImGuiKey_G },
        { "Key_H", ImGuiKey_H },
        { "Key_I", ImGuiKey_I },
        { "Key_J", ImGuiKey_J },
        { "Key_K", ImGuiKey_K },
        { "Key_L", ImGuiKey_L },
        { "Key_M", ImGuiKey_M },
        { "Key_N", ImGuiKey_N },
        { "Key_O", ImGuiKey_O },
        { "Key_P", ImGuiKey_P },
        { "Key_Q", ImGuiKey_Q },
        { "Key_R", ImGuiKey_R },
        { "Key_S", ImGuiKey_S },
        { "Key_T", ImGuiKey_T },
        { "Key_U", ImGuiKey_U },
        { "Key_V", ImGuiKey_V },
        { "Key_W", ImGuiKey_W },
        { "Key_X", ImGuiKey_X },
        { "Key_Y", ImGuiKey_Y },
        { "Key_Z", ImGuiKey_Z },
        { "Key_F1", ImGuiKey_F1 },
        { "Key_F2", ImGuiKey_F2 },
        { "Key_F3", ImGuiKey_F3 },
        { "Key_F4", ImGuiKey_F4 },
        { "Key_F5", ImGuiKey_F5 },
        { "Key_F6", ImGuiKey_F6 },
        { "Key_F7", ImGuiKey_F7 },
        { "Key_F8", ImGuiKey_F8 },
        { "Key_F9", ImGuiKey_F9 },
        { "Key_F10", ImGuiKey_F10 },
        { "Key_F11", ImGuiKey_F11 },
        { "Key_F12", ImGuiKey_F12 },
        { "Key_F13", ImGuiKey_F13 },
        { "Key_F14", ImGuiKey_F14 },
        { "Key_F15", ImGuiKey_F15 },
        { "Key_F16", ImGuiKey_F16 },
        { "Key_F17", ImGuiKey_F17 },
        { "Key_F18", ImGuiKey_F18 },
        { "Key_F19", ImGuiKey_F19 },
        { "Key_F20", ImGuiKey_F20 },
        { "Key_F21", ImGuiKey_F21 },
        { "Key_F22", ImGuiKey_F22 },
        { "Key_F23", ImGuiKey_F23 },
        { "Key_F24", ImGuiKey_F24 },
        { "Key_Apostrophe", ImGuiKey_Apostrophe },
        { "Key_Comma", ImGuiKey_Comma },
        { "Key_Minus", ImGuiKey_Minus },
        { "Key_Period", ImGuiKey_Period },
        { "Key_Slash", ImGuiKey_Slash },
        { "Key_Semicolon", ImGuiKey_Semicolon },
        { "Key_Equal", ImGuiKey_Equal },
        { "Key_LeftBracket", ImGuiKey_LeftBracket },
        { "Key_Backslash", ImGuiKey_Backslash },
        { "Key_RightBracket", ImGuiKey_RightBracket },
        { "Key_GraveAccent", ImGuiKey_GraveAccent },
        { "Key_CapsLock", ImGuiKey_CapsLock },
        { "Key_ScrollLock", ImGuiKey_ScrollLock },
        { "Key_NumLock", ImGuiKey_NumLock },
        { "Key_PrintScreen", ImGuiKey_PrintScreen },
        { "Key_Pause", ImGuiKey_Pause },
        { "Key_Keypad0", ImGuiKey_Keypad0 },
        { "Key_Keypad1", ImGuiKey_Keypad1 },
        { "Key_Keypad2", ImGuiKey_Keypad2 },
        { "Key_Keypad3", ImGuiKey_Keypad3 },
        { "Key_Keypad4", ImGuiKey_Keypad4 },
        { "Key_Keypad5", ImGuiKey_Keypad5 },
        { "Key_Keypad6", ImGuiKey_Keypad6 },
        { "Key_Keypad7", ImGuiKey_Keypad7 },
        { "Key_Keypad8", ImGuiKey_Keypad8 },
        { "Key_Keypad9", ImGuiKey_Keypad9 },
        { "Key_KeypadDecimal", ImGuiKey_KeypadDecimal },
        { "Key_KeypadDivide", ImGuiKey_KeypadDivide },
        { "Key_KeypadMultiply", ImGuiKey_KeypadMultiply },
        { "Key_KeypadSubtract", ImGuiKey_KeypadSubtract },
        { "Key_KeypadAdd", ImGuiKey_KeypadAdd },
        { "Key_KeypadEnter", ImGuiKey_KeypadEnter },
        { "Key_KeypadEqual", ImGuiKey_KeypadEqual },
        { "Key_AppBack", ImGuiKey_AppBack },
        { "Key_AppForward", ImGuiKey_AppForward },
        { "Key_Oem102", ImGuiKey_Oem102 },
        { "Key_GamepadStart", ImGuiKey_GamepadStart },
        { "Key_GamepadBack", ImGuiKey_GamepadBack },
        { "Key_GamepadFaceLeft", ImGuiKey_GamepadFaceLeft },
        { "Key_GamepadFaceRight", ImGuiKey_GamepadFaceRight },
        { "Key_GamepadFaceUp", ImGuiKey_GamepadFaceUp },
        { "Key_GamepadFaceDown", ImGuiKey_GamepadFaceDown },
        { "Key_GamepadDpadLeft", ImGuiKey_GamepadDpadLeft },
        { "Key_GamepadDpadRight", ImGuiKey_GamepadDpadRight },
        { "Key_GamepadDpadUp", ImGuiKey_GamepadDpadUp },
        { "Key_GamepadDpadDown", ImGuiKey_GamepadDpadDown },
        { "Key_GamepadL1", ImGuiKey_GamepadL1 },
        { "Key_GamepadR1", ImGuiKey_GamepadR1 },
        { "Key_GamepadL2", ImGuiKey_GamepadL2 },
        { "Key_GamepadR2", ImGuiKey_GamepadR2 },
        { "Key_GamepadL3", ImGuiKey_GamepadL3 },
        { "Key_GamepadR3", ImGuiKey_GamepadR3 },
        { "Key_GamepadLStickLeft", ImGuiKey_GamepadLStickLeft },
        { "Key_GamepadLStickRight", ImGuiKey_GamepadLStickRight },
        { "Key_GamepadLStickUp", ImGuiKey_GamepadLStickUp },
        { "Key_GamepadLStickDown", ImGuiKey_GamepadLStickDown },
        { "Key_GamepadRStickLeft", ImGuiKey_GamepadRStickLeft },
        { "Key_GamepadRStickRight", ImGuiKey_GamepadRStickRight },
        { "Key_GamepadRStickUp", ImGuiKey_GamepadRStickUp },
        { "Key_GamepadRStickDown", ImGuiKey_GamepadRStickDown },
        { "Key_MouseLeft", ImGuiKey_MouseLeft },
        { "Key_MouseRight", ImGuiKey_MouseRight },
        { "Key_MouseMiddle", ImGuiKey_MouseMiddle },
        { "Key_MouseX1", ImGuiKey_MouseX1 },
        { "Key_MouseX2", ImGuiKey_MouseX2 },
        { "Key_MouseWheelX", ImGuiKey_MouseWheelX },
        { "Key_MouseWheelY", ImGuiKey_MouseWheelY },
        // Modifiers
        { "Mod_None", ImGuiMod_None },
        { "Mod_Ctrl", ImGuiMod_Ctrl },
        { "Mod_Shift", ImGuiMod_Shift },
        { "Mod_Alt", ImGuiMod_Alt },
        { "Mod_Super", ImGuiMod_Super },
        { "Mod_Mask_", ImGuiMod_Mask_ },
};

static const std::pair<const char*, lua_Integer> IMGUI_STYLE_VAR[]{
        { "Alpha", ImGuiStyleVar_Alpha },
        { "DisabledAlpha", ImGuiStyleVar_DisabledAlpha },
        { "WindowPadding", ImGuiStyleVar_WindowPadding },
        { "WindowRounding", ImGuiStyleVar_WindowRounding },
        { "WindowBorderSize", ImGuiStyleVar_WindowBorderSize },
        { "WindowMinSize", ImGuiStyleVar_WindowMinSize },
        { "WindowTitleAlign", ImGuiStyleVar_WindowTitleAlign },
        { "ChildRounding", ImGuiStyleVar_ChildRounding },
        { "ChildBorderSize", ImGuiStyleVar_ChildBorderSize },
        { "PopupRounding", ImGuiStyleVar_PopupRounding },
        { "PopupBorderSize", ImGuiStyleVar_PopupBorderSize },
        { "FramePadding", ImGuiStyleVar_FramePadding },
        { "FrameRounding", ImGuiStyleVar_FrameRounding },
        { "FrameBorderSize", ImGuiStyleVar_FrameBorderSize },
        { "ItemSpacing", ImGuiStyleVar_ItemSpacing },
        { "ItemInnerSpacing", ImGuiStyleVar_ItemInnerSpacing },
        { "IndentSpacing", ImGuiStyleVar_IndentSpacing },
        { "CellPadding", ImGuiStyleVar_CellPadding },
        { "ScrollbarSize", ImGuiStyleVar_ScrollbarSize },
        { "ScrollbarRounding", ImGuiStyleVar_ScrollbarRounding },
        { "GrabMinSize", ImGuiStyleVar_GrabMinSize },
        { "GrabRounding", ImGuiStyleVar_GrabRounding },
        { "ImageBorderSize", ImGuiStyleVar_ImageBorderSize },
        { "TabRounding", ImGuiStyleVar_TabRounding },
        { "TabBorderSize", ImGuiStyleVar_TabBorderSize },
        { "TabBarBorderSize", ImGuiStyleVar_TabBarBorderSize },
        { "TabBarOverlineSize", ImGuiStyleVar_TabBarOverlineSize },
        { "TableAngledHeadersAngle", ImGuiStyleVar_TableAngledHeadersAngle },
        { "TableAngledHeadersTextAlign", ImGuiStyleVar_TableAngledHeadersTextAlign },
        { "ButtonTextAlign", ImGuiStyleVar_ButtonTextAlign },
        { "SelectableTextAlign", ImGuiStyleVar_SelectableTextAlign },
        { "SeparatorTextBorderSize", ImGuiStyleVar_SeparatorTextBorderSize },
        { "SeparatorTextAlign", ImGuiStyleVar_SeparatorTextAlign },
        { "SeparatorTextPadding", ImGuiStyleVar_SeparatorTextPadding },
};

static const luaL_Reg IMGUI_FUNCS[]{
    {"button", api::imgui::l_button},
    {"small_button", api::imgui::l_small_button},
    {"invisible_button", api::imgui::l_invisible_button},
    {"arrow_button", api::imgui::l_arrow_button},
    {"combo", api::imgui::l_combo},
    {"drag_float", api::imgui::l_drag_float},
    {"drag_float2", api::imgui::l_drag_float2},
    {"drag_float3", api::imgui::l_drag_float3},
    {"drag_float4", api::imgui::l_drag_float4},
    {"drag_int", api::imgui::l_drag_int},
    {"slider_float", api::imgui::l_slider_float},
    {"slider_int", api::imgui::l_slider_int},
    {"input_text", api::imgui::l_input_text},
    {"input_text_multiline", api::imgui::l_input_text_multiline},
    {"text", api::imgui::l_text},
    {"text_colored", api::imgui::l_text_colored},
    {"checkbox", api::imgui::l_checkbox},
    {"tree_node", api::imgui::l_tree_node},
    {"tree_node_ptr_id", api::imgui::l_tree_node_ptr_id},
    {"tree_node_str_id", api::imgui::l_tree_node_str_id},
    {"tree_pop", api::imgui::l_tree_pop},
    {"same_line", api::imgui::l_same_line},
    {"is_item_hovered", api::imgui::l_is_item_hovered},
    {"is_item_active", api::imgui::l_is_item_active},
    {"is_item_focused", api::imgui::l_is_item_focused},
    {"begin_window", api::imgui::l_begin_window},
    {"end_window", api::imgui::l_end_window},
    {"begin_child_window", api::imgui::l_begin_child_window},
    {"end_child_window", api::imgui::l_end_child_window},
    {"begin_group", api::imgui::l_begin_group},
    {"end_group", api::imgui::l_end_group},
    {"begin_rect", api::imgui::l_begin_rect},
    {"end_rect", api::imgui::l_end_rect},
    {"begin_disabled", api::imgui::l_begin_disabled},
    {"end_disabled", api::imgui::l_end_disabled},
    {"separator", api::imgui::l_separator},
    {"spacing", api::imgui::l_spacing},
    {"new_line", api::imgui::l_new_line},
    {"collapsing_header", api::imgui::l_collapsing_header},
    {"load_font", api::imgui::l_load_font},
    {"push_font", api::imgui::l_push_font},
    {"pop_font", api::imgui::l_pop_font},
    {"push_font_size", api::imgui::l_push_font_size},
    {"pop_font_size", api::imgui::l_pop_font_size},
    {"get_default_font_size", api::imgui::l_get_default_font_size},
    {"color_picker", api::imgui::l_color_picker},
    {"color_picker_argb", api::imgui::l_color_picker_argb},
    {"color_picker3", api::imgui::l_color_picker3},
    {"color_picker4", api::imgui::l_color_picker4},
    {"color_edit", api::imgui::l_color_edit},
    {"color_edit_argb", api::imgui::l_color_edit_argb},
    {"color_edit3", api::imgui::l_color_edit3},
    {"color_edit4", api::imgui::l_color_edit4},
    {"set_next_window_pos", api::imgui::l_set_next_window_pos},
    {"set_next_window_size", api::imgui::l_set_next_window_size},
    {"push_id", api::imgui::l_push_id},
    {"pop_id", api::imgui::l_pop_id},
    {"get_id", api::imgui::l_get_id},
    {"get_mouse", api::imgui::l_get_mouse},
    {"get_key_index", api::imgui::l_get_key_index},
    {"is_key_down", api::imgui::l_is_key_down},
    {"is_key_pressed", api::imgui::l_is_key_pressed},
    {"is_key_released", api::imgui::l_is_key_released},
    {"is_mouse_down", api::imgui::l_is_mouse_down},
    {"is_mouse_clicked", api::imgui::l_is_mouse_clicked},
    {"is_mouse_released", api::imgui::l_is_mouse_released},
    {"is_mouse_double_clicked", api::imgui::l_is_mouse_double_clicked},
    {"indent", api::imgui::l_indent},
    {"unindent", api::imgui::l_unindent},
    {"begin_tooltip", api::imgui::l_begin_tooltip},
    {"end_tooltip", api::imgui::l_end_tooltip},
    {"set_tooltip", api::imgui::l_set_tooltip},
    {"open_popup", api::imgui::l_open_popup},
    {"begin_popup", api::imgui::l_begin_popup},
    {"begin_popup_context_item", api::imgui::l_begin_popup_context_item},
    {"end_popup", api::imgui::l_end_popup},
    {"close_current_popup", api::imgui::l_close_current_popup},
    {"is_popup_open", api::imgui::l_is_popup_open},
    {"calc_text_size", api::imgui::l_calc_text_size},
    {"get_window_size", api::imgui::l_get_window_size},
    {"get_window_pos", api::imgui::l_get_window_pos},
    {"set_next_item_open", api::imgui::l_set_next_item_open},
    {"begin_list_box", api::imgui::l_begin_list_box},
    {"end_list_box", api::imgui::l_end_list_box},
    {"begin_menu_bar", api::imgui::l_begin_menu_bar},
    {"end_menu_bar", api::imgui::l_end_menu_bar},
    {"begin_main_menu_bar", api::imgui::l_begin_main_menu_bar},
    {"end_main_menu_bar", api::imgui::l_end_main_menu_bar},
    {"begin_menu", api::imgui::l_begin_menu},
    {"end_menu", api::imgui::l_end_menu},
    {"menu_item", api::imgui::l_menu_item},
    {"get_display_size", api::imgui::l_get_display_size},
    {"get_window_draw_list", api::imgui::l_get_window_draw_list},
    {"get_background_draw_list", api::imgui::l_get_background_draw_list},
    {"get_foreground_draw_list", api::imgui::l_get_foreground_draw_list},
    {"push_item_width", api::imgui::l_push_item_width},
    {"pop_item_width", api::imgui::l_pop_item_width},
    {"set_next_item_width", api::imgui::l_set_next_item_width},
    {"calc_item_width", api::imgui::l_calc_item_width},
    {"item_add", api::imgui::l_item_add},
    {"item_size", api::imgui::l_item_size},
    {"push_style_color", api::imgui::l_push_style_color},
    {"pop_style_color", api::imgui::l_pop_style_color},
    {"push_style_var", api::imgui::l_push_style_var},
    {"pop_style_var", api::imgui::l_pop_style_var},
    {"get_cursor_pos", api::imgui::l_get_cursor_pos},
    {"set_cursor_pos", api::imgui::l_set_cursor_pos},
    {"get_cursor_start_pos", api::imgui::l_get_cursor_start_pos},
    {"get_cursor_screen_pos", api::imgui::l_get_cursor_screen_pos},
    {"set_cursor_screen_pos", api::imgui::l_set_cursor_screen_pos},
    {"set_item_default_focus", api::imgui::l_set_item_default_focus},
    {"set_clipboard", api::imgui::l_set_clipboard},
    {"get_clipboard", api::imgui::l_get_clipboard},
    {"progress_bar", api::imgui::l_progress_bar},
    {"draw_list_path_clear", api::imgui::l_draw_list_path_clear},
    {"draw_list_path_line_to", api::imgui::l_draw_list_path_line_to},
    {"draw_list_path_stroke", api::imgui::l_draw_list_path_stroke},
    {"get_scroll_x", api::imgui::l_get_scroll_x},
    {"get_scroll_y", api::imgui::l_get_scroll_y},
    {"set_scroll_x", api::imgui::l_set_scroll_x},
    {"set_scroll_y", api::imgui::l_set_scroll_y},
    {"get_scroll_max_x", api::imgui::l_get_scroll_max_x},
    {"get_scroll_max_y", api::imgui::l_get_scroll_max_y},
    {"set_scroll_here_x", api::imgui::l_set_scroll_here_x},
    {"set_scroll_here_y", api::imgui::l_set_scroll_here_y},
    {"set_scroll_from_pos_x", api::imgui::l_set_scroll_from_pos_x},
    {"set_scroll_from_pos_y", api::imgui::l_set_scroll_from_pos_y},
    {"begin_table", api::imgui::l_begin_table},
    {"end_table", api::imgui::l_end_table},
    {"table_next_row", api::imgui::l_table_next_row},
    {"table_next_column", api::imgui::l_table_next_column},
    {"table_set_column_index", api::imgui::l_table_set_column_index},
    {"table_setup_column", api::imgui::l_table_setup_column},
    {"table_setup_scroll_freeze", api::imgui::l_table_setup_scroll_freeze},
    {"table_headers_row", api::imgui::l_table_headers_row},
    {"table_header", api::imgui::l_table_header},
    {"table_get_sort_specs", api::imgui::l_table_get_sort_specs},
    {"table_get_column_count", api::imgui::l_table_get_column_count},
    {"table_get_column_index", api::imgui::l_table_get_column_index},
    {"table_get_row_index", api::imgui::l_table_get_row_index},
    {"table_get_column_name", api::imgui::l_table_get_column_name},
    {"table_get_column_flags", api::imgui::l_table_get_column_flags},
    {"table_set_bg_color", api::imgui::l_table_set_bg_color},
    {nullptr, nullptr},
};

static const luaL_Reg DRAW_LIST_METHODS[]{
    {"push_clip_rect", api::imgui::l_dl_push_clip_rect},
    {"push_clip_rect_fullscreen", api::imgui::l_dl_push_clip_rect_fullscreen},
    {"pop_clip_rect", api::imgui::l_dl_pop_clip_rect},
    {"add_line", api::imgui::l_dl_add_line},
    {"add_rect", api::imgui::l_dl_add_rect},
    {"add_rect_filled", api::imgui::l_dl_add_rect_filled},
    {"add_rect_filled_multi_color", api::imgui::l_dl_add_rect_filled_multi_color},
    {"add_quad", api::imgui::l_dl_add_quad},
    {"add_quad_filled", api::imgui::l_dl_add_quad_filled},
    {"add_triangle", api::imgui::l_dl_add_triangle},
    {"add_triangle_filled", api::imgui::l_dl_add_triangle_filled},
    {"add_circle", api::imgui::l_dl_add_circle},
    {"add_circle_filled", api::imgui::l_dl_add_circle_filled},
    {"add_ngon", api::imgui::l_dl_add_ngon},
    {"add_ngon_filled", api::imgui::l_dl_add_ngon_filled},
    {"add_ellipse", api::imgui::l_dl_add_ellipse},
    {"add_ellipse_filled", api::imgui::l_dl_add_ellipse_filled},
    {"add_text", api::imgui::l_dl_add_text},
    {"add_bezier_cubic", api::imgui::l_dl_add_bezier_cubic},
    {"add_bezier_quadratic", api::imgui::l_dl_add_bezier_quadratic},
    {"path_clear", api::imgui::l_dl_path_clear},
    {"path_line_to", api::imgui::l_dl_path_line_to},
    {"path_line_to_merge_duplicate", api::imgui::l_dl_path_line_to_merge_duplicate},
    {"path_fill_convex", api::imgui::l_dl_path_fill_convex},
    {"path_fill_concave", api::imgui::l_dl_path_fill_concave},
    {"path_stroke", api::imgui::l_dl_path_stroke},
    {"path_arc_to", api::imgui::l_dl_path_arc_to},
    {"path_arc_to_fast", api::imgui::l_dl_path_arc_to_fast},
    {"path_elliptical_arc_to", api::imgui::l_dl_path_elliptical_arc_to},
    {"path_bezier_cubic_curve_to", api::imgui::l_dl_path_bezier_cubic_curve_to},
    {"path_bezier_quadratic_curve_to", api::imgui::l_dl_path_bezier_quadratic_curve_to},
    {"path_rect", api::imgui::l_dl_path_rect},
    {nullptr, nullptr},
};

static const luaL_Reg DRAW_FUNCS[]{
    {"world_to_screen", api::draw::l_world_to_screen},
    {"world_text", api::draw::l_world_text},
    {"text", api::draw::l_text},
    {"filled_rect", api::draw::l_filled_rect},
    {"outline_rect", api::draw::l_outline_rect},
    {"line", api::draw::l_line},
    {"outline_circle", api::draw::l_outline_circle},
    {"filled_circle", api::draw::l_filled_circle},
    {"outline_quad", api::draw::l_outline_quad},
    {"filled_quad", api::draw::l_filled_quad},
    {"sphere", api::draw::l_sphere},
    {"capsule", api::draw::l_capsule},
    {"gizmo", api::draw::l_gizmo},
    {"cube", api::draw::l_cube},
    {"grid", api::draw::l_grid},
    {nullptr, nullptr},
};

static const luaL_Reg IMNODES_FUNCS[]{
    {"is_editor_hovered", api::imnodes::l_is_editor_hovered},
    {"is_node_hovered", api::imnodes::l_is_node_hovered},
    {"is_link_hovered", api::imnodes::l_is_link_hovered},
    {"is_pin_hovered", api::imnodes::l_is_pin_hovered},
    {"begin_node_editor", api::imnodes::l_begin_node_editor},
    {"end_node_editor", api::imnodes::l_end_node_editor},
    {"begin_node", api::imnodes::l_begin_node},
    {"end_node", api::imnodes::l_end_node},
    {"begin_node_titlebar", api::imnodes::l_begin_node_titlebar},
    {"end_node_titlebar", api::imnodes::l_end_node_titlebar},
    {"begin_input_attribute", api::imnodes::l_begin_input_attribute},
    {"end_input_attribute", api::imnodes::l_end_input_attribute},
    {"begin_output_attribute", api::imnodes::l_begin_output_attribute},
    {"end_output_attribute", api::imnodes::l_end_output_attribute},
    {"begin_static_attribute", api::imnodes::l_begin_static_attribute},
    {"end_static_attribute", api::imnodes::l_end_static_attribute},
    {"minimap", api::imnodes::l_minimap},
    {"link", api::imnodes::l_link},
    {"get_node_dimensions", api::imnodes::l_get_node_dimensions},
    {"push_color_style", api::imnodes::l_push_color_style},
    {"pop_color_style", api::imnodes::l_pop_color_style},
    {"push_style_var", api::imnodes::l_push_style_var},
    {"push_style_var_vec2", api::imnodes::l_push_style_var_vec2},
    {"pop_style_var", api::imnodes::l_pop_style_var},
    {"set_node_screen_space_pos", api::imnodes::l_set_node_screen_space_pos},
    {"set_node_editor_space_pos", api::imnodes::l_set_node_editor_space_pos},
    {"set_node_grid_space_pos", api::imnodes::l_set_node_grid_space_pos},
    {"get_node_screen_space_pos", api::imnodes::l_get_node_screen_space_pos},
    {"get_node_editor_space_pos", api::imnodes::l_get_node_editor_space_pos},
    {"get_node_grid_space_pos", api::imnodes::l_get_node_grid_space_pos},
    {"is_node_selected", api::imnodes::l_is_node_selected},
    {"is_link_selected", api::imnodes::l_is_link_selected},
    {"num_selected_nodes", api::imnodes::l_num_selected_nodes},
    {"num_selected_links", api::imnodes::l_num_selected_links},
    {"clear_node_selection", api::imnodes::l_clear_node_selection},
    {"clear_link_selection", api::imnodes::l_clear_link_selection},
    {"select_node", api::imnodes::l_select_node},
    {"select_link", api::imnodes::l_select_link},
    {"is_attribute_active", api::imnodes::l_is_attribute_active},
    {"snap_node_to_grid", api::imnodes::l_snap_node_to_grid},
    {"editor_move_to_node", api::imnodes::l_editor_move_to_node},
    {"editor_reset_panning", api::imnodes::l_editor_reset_panning},
    {"editor_get_panning", api::imnodes::l_editor_get_panning},
    {"is_link_started", api::imnodes::l_is_link_started},
    {"is_link_dropped", api::imnodes::l_is_link_dropped},
    {"is_link_created", api::imnodes::l_is_link_created},
    {"is_link_destroyed", api::imnodes::l_is_link_destroyed},
    {"get_selected_nodes", api::imnodes::l_get_selected_nodes},
    {"get_selected_links", api::imnodes::l_get_selected_links},
    {nullptr, nullptr},
};

static void open_draw_list_mt(lua_State* L) {
    luaL_newmetatable(L, DRAW_LIST_MT);

    luaL_setfuncs(L, DRAW_LIST_METHODS, 0);

    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");

    lua_pushliteral(L, "ImDrawList");
    lua_setfield(L, -2, "__name");

    lua_pop(L, 1);
}

static void open_sort_specs_mt(lua_State* L) {
    luaL_newmetatable(L, SORT_SPECS_MT);

    lua_pushcfunction(L, api::imgui::l_specs_index);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, api::imgui::l_specs_newindex);
    lua_setfield(L, -2, "__newindex");

    lua_pushliteral(L, "ImGuiTableSortSpecs");
    lua_setfield(L, -2, "__name");

    lua_pop(L, 1);
}

static void open_column_sort_specs_mt(lua_State* L) {
    luaL_newmetatable(L, COLUMN_SORT_SPECS_MT);

    lua_pushcfunction(L, api::imgui::l_column_specs_index);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, api::imgui::l_column_specs_newindex);
    lua_setfield(L, -2, "__newindex");

    lua_pushliteral(L, "ImGuiTableColumnSortSpecs");
    lua_setfield(L, -2, "__name");

    lua_pop(L, 1);
}

static void put_imgui_enums(lua_State* L) {
    lh::put_enum(L, "ImGuizmoOperation", IMGUIZMO_OPERATION);
    lh::put_enum(L, "ImGuizmoMode", IMGUIZMO_MODE);
    lh::put_enum(L, "TableFlags", IMGUI_TABLE_FLAGS);
    lh::put_enum(L, "ColumnFlags", IMGUI_COLUMN_FLAGS);
    lh::put_enum(L, "ImGuiKey", IMGUI_KEY);
    lh::put_enum(L, "ImGuiStyleVar", IMGUI_STYLE_VAR);
}

static void push_sort_specs_type(lua_State* L) {
    lua_createtable(L, 0, 2);

    lua_pushcfunction(L, api::imgui::l_specs_get_specs);
    lua_setfield(L, -2, "get_specs");

    lua_pushcfunction(L, api::imgui::l_specs_get_specs_dirty);
    lua_setfield(L, -2, "specs_dirty");
}

static void push_column_sort_specs_type(lua_State* L) {
    static const std::pair<const char*, lua_Integer> MEMBERS[]{
        { "user_id", 0 },
        { "column_index", 1 },
        { "sort_order", 2 },
        { "sort_direction", 3 },
    };

    lua_createtable(L, 0, 4);

    for (const auto& member : MEMBERS) {
        lua_pushinteger(L, member.second);
        lua_pushcclosure(L, api::imgui::l_column_specs_get_value, 1);
        lua_setfield(L, -2, member.first);
    }
}

void bindings::open_imgui(ScriptState* s) {
    auto L = s->lua().lua_state();

    open_draw_list_mt(L);
    open_sort_specs_mt(L);
    open_column_sort_specs_mt(L);

    lua_newtable(L);
    luaL_setfuncs(L, IMGUI_FUNCS, 0);
    put_imgui_enums(L);

    // sol2 published each of the three usertypes under `imgui` as well, so a
    // member is reachable off the table itself: `imgui.ImDrawList.add_text`.
    luaL_getmetatable(L, DRAW_LIST_MT);
    lua_setfield(L, -2, "ImDrawList");

    push_sort_specs_type(L);
    lua_setfield(L, -2, "TableSortSpecs");

    push_column_sort_specs_type(L);
    lua_setfield(L, -2, "TableColumnSortSpecs");

    lua_setglobal(L, "imgui");

    lua_newtable(L);
    luaL_setfuncs(L, DRAW_FUNCS, 0);
    lua_setglobal(L, "draw");

    lua_newtable(L);
    luaL_setfuncs(L, IMNODES_FUNCS, 0);
    lua_setglobal(L, "imnodes");

    lua_newtable(L);
    lua_pushcfunction(L, l_imguizmo_is_over);
    lua_setfield(L, -2, "is_over");
    lua_pushcfunction(L, l_imguizmo_is_using);
    lua_setfield(L, -2, "is_using");
    lua_setglobal(L, "imguizmo");
}