#pragma once

#include <functional>
#include <string>
#include <vector>

class REFramework;

class StartupPipeline {
public:
    using Step = std::function<bool(REFramework&)>;

    StartupPipeline& add(const char* name, Step step);
    bool run(REFramework& fw);

private:
    struct Entry {
        const char* name;
        Step step;
    };
    std::vector<Entry> m_steps{};
};
