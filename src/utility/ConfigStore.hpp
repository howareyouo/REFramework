#pragma once

#include <filesystem>
#include <string>
#include <string_view>
#include <utility>

#include <utility/Config.hpp>
#include <utility/String.hpp>

// Owns the framework's configuration file.
//
// The file is read exactly once, at the configuration phase of startup, and
// every consumer reads the same snapshot from here. Nothing else opens the
// file, so there is exactly one place that knows where it lives and what a
// missing file means (an empty configuration, i.e. "no stored values", rather
// than an error).
//
// The snapshot is immutable once loaded; writing the file back does not change
// it. Callers that write are expected to hold the framework's config lock.
class ConfigStore {
public:
    // Name of the framework's configuration file inside the persistent directory.
    static inline constexpr std::string_view CONFIG_FILE_NAME{ "reframework_config.txt" };

    explicit ConfigStore(std::string file_path)
        : m_file_path{ std::move(file_path) }
    {
    }

    // Reads the file into the snapshot. Returns true when the file existed
    // and could be read.
    bool load() {
        utility::Config cfg{};

        if (!cfg.load(m_file_path)) {
            return false;
        }

        m_config = std::move(cfg);

        return true;
    }

    // The loaded configuration. Empty until load() is called.
    const utility::Config& config() const {
        return m_config;
    }

    // Writes the given configuration to the file. Returns false when the file
    // could not be written.
    bool save(utility::Config& cfg) const {
        return cfg.save(m_file_path);
    }

    bool file_exists() const {
        return std::filesystem::exists(utility::widen(m_file_path));
    }

    const std::string& file_path() const {
        return m_file_path;
    }

private:
    std::string m_file_path{};
    utility::Config m_config{};
};
