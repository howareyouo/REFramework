#pragma once

#include "Mod.hpp"

class REFrameworkConfig : public Mod {
public:
    static inline constexpr std::string_view REFRAMEWORK_CONFIG_NAME{ "reframework_config.txt" };
    static std::shared_ptr<REFrameworkConfig>& get();

public:
    std::string_view get_name() const override {
        return "REFrameworkConfig";
    }

    std::optional<std::string> on_initialize() override;
    void on_draw_ui() override;
    void on_frame() override;
    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    auto& get_menu_key() {
        return m_menu_key;
    }

    auto& get_menu_open() {
        return m_menu_open;
    }

    bool is_always_show_cursor() const {
        return m_always_show_cursor->value();
    }

private:
    ModKey::Ptr m_menu_key{ make_option<ModKey>("MenuKey_V2", VK_INSERT) };
    ModToggle::Ptr m_menu_open{ make_option<ModToggle>("MenuOpen", true) };
    ModToggle::Ptr m_remember_menu_state{ make_option<ModToggle>("RememberMenuState", false) };
#ifdef RE8
    ModToggle::Ptr m_always_show_cursor{ make_option<ModToggle>("DrawCursorWithMenuOpen", true) };
#else
    ModToggle::Ptr m_always_show_cursor{ make_option<ModToggle>("DrawCursorWithMenuOpen", false) };
#endif
    ModKey::Ptr m_show_cursor_key{ make_option<ModKey>("ShowCursorKey") };
    ModInt32::Ptr m_font_size{ make_option<ModInt32>("FontSize", 16) };
    std::vector<std::string> fonts{};
    // Created in on_initialize once the font directory has been scanned; it
    // registers itself into the inherited m_options there.
    ModComboString::Ptr m_font_file{};
};
