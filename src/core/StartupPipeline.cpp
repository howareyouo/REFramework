#include "StartupPipeline.hpp"
#include "REFramework.hpp"
#include <spdlog/spdlog.h>

StartupPipeline& StartupPipeline::add(const char* name, Step step) {
    m_steps.push_back({name, std::move(step)});
    return *this;
}

bool StartupPipeline::run(REFramework& fw) {
    for (const auto& e : m_steps) {
        spdlog::info("[Startup] {}", e.name);
        if (!e.step(fw)) {
            spdlog::error("[Startup] {} failed", e.name);
            return false;
        }
    }
    return true;
}
