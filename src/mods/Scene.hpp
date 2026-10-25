#pragma once

#include "Mod.hpp"

class REManagedObject;

class SceneMods : public Mod {
public:
    SceneMods() = default;

    std::string_view get_name() const override { return "Scene"; }


    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    void on_frame() override;
    void on_draw_ui() override;

private:
    const ModKey::Ptr m_timescale_toggle_key{make_option<ModKey>("TimeScaleToggleKey")};
    const ModKey::Ptr m_timescale_continuous_key{make_option<ModKey>("TimeScaleContinuousKey")};
    const ModToggle::Ptr m_use_application_timescale{make_option<ModToggle>("UseApplicationTimescale", true)};
    const ModToggle::Ptr m_set_timescale{make_option<ModToggle>("TimeScaleEnabled")};
    const ModSlider::Ptr m_timescale{make_option<ModSlider>("TimeScale", -5.0f, 5.0f, 1.0f)};

    bool m_was_continuous_down{ false };
    bool m_timescale_before_continuous{ false };
};