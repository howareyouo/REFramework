#include "../REFramework.hpp"

#include <cstdio>

#include <utility/String.hpp>

#include "REFrameworkConfig.hpp"

std::shared_ptr<REFrameworkConfig>& REFrameworkConfig::get() {
     static std::shared_ptr<REFrameworkConfig> instance{std::make_shared<REFrameworkConfig>()};
     return instance;
}

std::optional<std::string> REFrameworkConfig::on_initialize() {
    namespace fs = std::filesystem;
    fonts.clear();
    // No default font - users must provide their own TTF/OTF files

    const auto fonts_path = REFramework::get_persistent_dir() / "reframework" / "fonts";
    fs::create_directories(fonts_path);

    for (const auto& entry : fs::directory_iterator(fonts_path)) {
        if (fs::is_regular_file(entry)) {
            const auto ext = entry.path().extension();
            if (ext == ".otf" || ext == ".ttf") {
                fonts.push_back(entry.path().filename().string());
            }
        }
    }

    m_font_file = ModComboString::create(generate_name("FontFile"), fonts, "");

    g_framework->set_font(m_font_file->value());

    m_options.push_back(*m_font_file);

    return Mod::on_initialize();
}

void REFrameworkConfig::on_draw_ui() {
    if (!ImGui::CollapsingHeader("Configuration")) {
        return;
    }

    ImGui::TreePush("Configuration");

    bool changed = false;

    changed |= m_menu_key->draw("Menu Key");
    changed |= m_show_cursor_key->draw("Show Cursor Key");
    changed |= m_remember_menu_state->draw("Remember Menu Open/Closed State");
    changed |= m_always_show_cursor->draw("Draw Cursor With Menu Open");

    changed |= m_ui_transparent->draw("Transparency");
    ImGui::SameLine();
    ImGui::Text("(?)");
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Makes the UI transparent when not focused.");

    changed |= m_input_passthrough->draw("Input Passthrough");
    ImGui::SameLine();
    ImGui::Text("(?)");
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Allows mouse and keyboard inputs to register to the game while the UI is focused.");

    if (m_font_file->draw("Font")) {
        g_framework->set_font(m_font_file->value());
        changed = true;
    }

    if (m_font_size->draw("Font Size")) {
        g_framework->set_font_size(m_font_size->value());
        changed = true;
    }

    if (changed) {
        g_framework->request_save_config();
    }

    ImGui::TreePop();
}

void REFrameworkConfig::on_frame() {
    if (m_show_cursor_key->is_key_down_once()) {
        m_always_show_cursor->toggle();
    }
}

std::string REFrameworkConfig::get_menu_key_name() const {
    const auto key = m_menu_key->value();

    switch (key) {
    case VK_LBUTTON:  return "Left Mouse";
    case VK_RBUTTON:  return "Right Mouse";
    case VK_MBUTTON:  return "Middle Mouse";
    case VK_XBUTTON1: return "Mouse 4";
    case VK_XBUTTON2: return "Mouse 5";
    default: break;
    }

    if (key <= 0 || key > 255) {
        return "Not bound";
    }

    // MAPVK_VK_TO_VSC_EX 对扩展键（Insert/Delete/方向键等）返回 0xE0 前缀，
    // GetKeyNameText 需要该位才能取到正确的名字。
    const auto scancode = MapVirtualKeyW(static_cast<UINT>(key), MAPVK_VK_TO_VSC_EX);
    const auto l_param = static_cast<LPARAM>(
        ((scancode & 0xFF) << 16) | ((scancode & 0xFF00) != 0 ? (1 << 24) : 0));

    wchar_t name[64]{};
    if (GetKeyNameTextW(static_cast<LONG>(l_param), name, static_cast<int>(std::size(name))) > 0) {
        return utility::narrow(name);
    }

    char fallback[16]{};
    snprintf(fallback, sizeof(fallback), "VK 0x%x", static_cast<unsigned>(key));
    return fallback;
}

void REFrameworkConfig::on_config_load(const utility::Config& cfg) {
    config_load_options(cfg, m_options);

    if (m_remember_menu_state->value()) {
        g_framework->set_draw_ui(m_menu_open->value(), false);
    }
    
    g_framework->set_font(m_font_file->value());
    g_framework->set_font_size(m_font_size->value());
}

void REFrameworkConfig::on_config_save(utility::Config& cfg) {
    config_save_options(cfg, m_options);
}
