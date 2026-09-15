#pragma once

#include <atomic>
#include <deque>
#include <shared_mutex>
#include <unordered_map>

#include <spdlog/spdlog.h>

#include <utility/FunctionHook.hpp>

#include "../Mod.hpp"

class LooseFileLoader : public Mod {
public:
    static std::shared_ptr<LooseFileLoader>& get();

    LooseFileLoader();
    std::string_view get_name() const override { return "LooseFileLoader"; }

    std::optional<std::string> on_initialize() override;
    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    void on_frame() override;
    void on_draw_ui() override;

    void hook();

    bool is_enabled() const {
        return m_enabled->value();
    }

private:
    // hash -> whether a loose file for it exists on disk. An absent hash means "not resolved yet".
    using FileCache = std::unordered_map<size_t, bool>;

    bool handle_path(const wchar_t* path, size_t hash);  // true => skip the packed file
    bool check_exists(const wchar_t* path, size_t hash); // thread-local -> shared cache -> disk
    void record_recent(std::deque<std::wstring>& recent, const wchar_t* path);

#if TDB_VER > 67
    static uint64_t path_to_hash_hook(const wchar_t* path);
#else
    static uint64_t path_to_hash_hook(void* This, const wchar_t* path);
#endif

    bool m_hook_success{false};
    bool m_attempted_hook{false};
    std::atomic<uint32_t> m_files_encountered{};
    std::atomic<uint32_t> m_uncached_hits{};
    std::atomic<uint32_t> m_cache_hits{};
    std::atomic<uint32_t> m_loose_files_loaded{};

    std::shared_mutex m_mutex{};
    std::deque<std::wstring> m_recent_accessed_files{}; // max 100
    std::deque<std::wstring> m_recent_loose_files{}; // max 100

    FileCache m_cache{};
    std::shared_mutex m_cache_mutex{};

    std::unique_ptr<FunctionHook> m_path_to_hash_hook{nullptr};

    ModToggle::Ptr m_enabled{ ModToggle::create(generate_name("Enabled")) };
    ModToggle::Ptr m_log_accessed_files{ ModToggle::create(generate_name("LogAccessedFiles")) };
    ModToggle::Ptr m_log_loose_files{ ModToggle::create(generate_name("LogLooseFiles")) };
    bool m_show_recent_files{false}; // Not persistent because its for dev purposes
    bool m_enable_file_cache{true};

    std::shared_ptr<spdlog::logger> m_logger{nullptr};
    std::shared_ptr<spdlog::logger> m_loose_file_logger{nullptr};

    ValueList m_options{
        *m_enabled,
        *m_log_accessed_files,
        *m_log_loose_files,
    };
};
