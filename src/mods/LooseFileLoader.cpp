#include <unordered_set>

#include <sdk/RETypeDB.hpp>
#include <utility/Scan.hpp>
#include <utility/Module.hpp>
#include <utility/String.hpp>

#include <spdlog/sinks/basic_file_sink.h>

#include "REFramework.hpp"
#include "LooseFileLoader.hpp"

LooseFileLoader* g_loose_file_loader{nullptr};

namespace {
    constexpr size_t kMaxRecentFiles = 100;
    constexpr size_t kThreadCacheMax = 4096; // per-thread cap before falling back to the shared cache

    bool file_exists(const wchar_t* path) {
        return GetFileAttributesW(path) != INVALID_FILE_ATTRIBUTES;
    }

    std::shared_ptr<spdlog::logger> make_logger(std::string_view name, std::string_view file) {
        auto logger = spdlog::basic_logger_mt(name.data(), REFramework::get_persistent_dir(file.data()).string(), true);
        logger->set_level(spdlog::level::info);
        logger->flush_on(spdlog::level::info);
        return logger;
    }

    // Returns the `via.io.file.exists` method pointers, or empty when the type database
    // isn't usable yet. Walked manually because this loader runs before the VM is ready.
    std::vector<uintptr_t> find_exists_methods(sdk::RETypeDB* tdb) {
        for (auto i = 0; i < tdb->get_num_types(); ++i) {
            const auto t = tdb->get_type(i);

            if (t == nullptr || t->get_name() == nullptr || std::string_view{t->get_name()} != "file" ||
                t->get_declaring_type() == nullptr || std::string_view{t->get_declaring_type()->get_name()} != "io") {
                continue;
            }

            spdlog::info("[LooseFileLoader] Found via.io.file");

            std::vector<uintptr_t> candidates;

            for (auto& method : t->get_methods()) {
                if (method.get_name() != nullptr && std::string_view{method.get_name()} == "exists") {
                    if (auto fn = method.get_function(); fn != nullptr) {
                        candidates.push_back((uintptr_t)fn);
                    }
                }
            }

            if (candidates.empty()) {
                spdlog::error("[LooseFileLoader] Failed to find via.io.file.exists methods");
            }

            return candidates;
        }

        spdlog::error("[LooseFileLoader] Failed to find via.io.file");
        return {};
    }

    // Landmark scan fallback: path_to_hash is the only function that contains a
    // "mov r8d, 800h", a "mov r8d, 400h" and another "mov r8d, 800h". They don't need
    // to be adjacent, just in the same function.
    std::vector<uintptr_t> find_landmark_functions(HMODULE module, uintptr_t module_end) {
        static const std::string start{"41 B8 00 08 00 00"}; // mov r8d, 800h
        static const std::vector<std::string> landmarks{"BA 00 04 00 00", "41 B8 00 08 00 00"};

        std::vector<uintptr_t> functions;
        std::unordered_set<uintptr_t> analyzed;

        for (auto c = utility::find_landmark_sequence(module, start, landmarks, false); c.has_value();
             c = utility::find_landmark_sequence(c->addr + c->instrux.Length, module_end - (c->addr + 1), start, landmarks, false)) {
            if (auto fn = utility::find_function_start_with_call(c->addr); fn.has_value() && analyzed.insert(*fn).second) {
                functions.push_back(*fn);
            }
        }

        return functions;
    }

    // Scans one candidate function and returns the address of path_to_hash, if it's there.
    std::optional<uintptr_t> scan_for_path_to_hash(uintptr_t fn, uintptr_t module, uintptr_t module_end) {
        spdlog::info("[LooseFileLoader] Scanning for path_to_hash candidate at {:x}", fn);

        std::optional<uintptr_t> result;

        utility::exhaustive_decode((uint8_t*)fn, 500, [&](utility::ExhaustionContext& ctx) -> utility::ExhaustionResult {
            // Ignore anything outside the game module (e.g. inside kernel32.dll).
            if (result || ctx.addr < module || ctx.addr > module_end) {
                return utility::ExhaustionResult::BREAK;
            }

            // branch_start == addr means we just entered a call/branch target. path_to_hash
            // is identified by its UTF-16 backslash reference and the murmur hash constant
            // that System.String::GetHashCode uses.
            if (ctx.branch_start == ctx.addr &&
                utility::find_string_reference_in_path(ctx.branch_start, L"\\", false).has_value() &&
                utility::find_pattern_in_path((uint8_t*)ctx.branch_start, 500, true, "? ? 6B CA EB 85")) {
                spdlog::info("[LooseFileLoader] Found path_to_hash candidate at {:x}", ctx.branch_start);
                result = ctx.branch_start;
            }

            return utility::ExhaustionResult::CONTINUE;
        });

        return result;
    }
}

LooseFileLoader::LooseFileLoader() {
    g_loose_file_loader = this;

    m_logger = make_logger("LooseFileLoader", "reframework_accessed_files.txt");
    m_loose_file_logger = make_logger("LooseFileLoader2", "reframework_loose_files.txt");

    m_logger->info("LooseFileLoader constructed");
    m_loose_file_logger->info("LooseFileLoader constructed");
}

std::shared_ptr<LooseFileLoader>& LooseFileLoader::get() {
    static auto instance = std::shared_ptr<LooseFileLoader>(new LooseFileLoader());
    return instance;
}

std::optional<std::string> LooseFileLoader::on_initialize() {
    return Mod::on_initialize();
}

void LooseFileLoader::on_frame() {
    if (!m_attempted_hook && m_enabled->value()) {
        hook();
    }
}

void LooseFileLoader::on_config_load(const utility::Config& cfg) {
    config_load_options(cfg, m_options);
}

void LooseFileLoader::on_config_save(utility::Config& cfg) {
    config_save_options(cfg, m_options);
}

void LooseFileLoader::on_draw_ui() {
    if (!ImGui::CollapsingHeader(get_name().data())) {
        return;
    }

    if (m_attempted_hook && !m_hook_success) {
        ImGui::TextWrapped("Failed to hook successfully. This mod will not work.");
        return;
    }

    auto clear_existence_cache = [&]() {
        std::unique_lock _{m_cache_mutex};
        m_cache.clear();
        m_cache_hits = 0;
        m_uncached_hits = 0;
    };

    if (m_enabled->draw("Enable Loose File Loader")) {
        clear_existence_cache();
        g_framework->request_save_config();
    }

    if (!m_hook_success) {
        return;
    }

    ImGui::TextWrapped("Files encountered: %d", m_files_encountered.load());
    ImGui::TextWrapped("Loose files loaded: %d", m_loose_files_loaded.load());

    if (ImGui::Button("Clear stats")) {
        m_files_encountered = 0;
        m_loose_files_loaded = 0;

        std::unique_lock _{m_mutex};
        m_recent_accessed_files.clear();
        m_recent_loose_files.clear();
    }

    if (ImGui::TreeNode("Debug")) {
        ImGui::Checkbox("Enable file cache", &m_enable_file_cache);
        ImGui::TextWrapped("Cache hits: %d", m_cache_hits.load());
        ImGui::TextWrapped("Uncached hits: %d", m_uncached_hits.load());

        if (ImGui::Button("Clear existence cache")) {
            clear_existence_cache();
        }

        ImGui::TreePop();
    }

    auto draw_toggle = [](ModToggle::Ptr& toggle, const char* label, const char* tooltip) {
        toggle->draw(label);

        if (ImGui::IsItemHovered()) {
            ImGui::SetTooltip("%s", tooltip);
        }
    };

    draw_toggle(m_log_accessed_files, "Log accessed files", "Logs all accessed files to <game_dir>/reframework_accessed_files.txt");
    draw_toggle(m_log_loose_files, "Log loose files", "Logs loaded loose files to <game_dir>/reframework_loose_files.txt");

    ImGui::Checkbox("Show recent files", &m_show_recent_files);

    if (!m_show_recent_files) {
        return;
    }

    std::shared_lock _{m_mutex};

    auto draw_files = [](const char* label, const std::deque<std::wstring>& files) {
        if (ImGui::TreeNode(label)) {
            for (const auto& file : files) {
                ImGui::TextWrapped("%s", utility::narrow(file).c_str());
            }

            ImGui::TreePop();
        }
    };

    draw_files("Recent accessed files", m_recent_accessed_files);
    draw_files("Recent loose files", m_recent_loose_files);
}

void LooseFileLoader::hook() {
    if (m_attempted_hook) {
        return;
    }

    m_attempted_hook = true;

    spdlog::info("[LooseFileLoader] Attempting to find path_to_hash");

    const auto tdb = sdk::RETypeDB::get();

    if (tdb == nullptr) {
        spdlog::error("[LooseFileLoader] Failed to get type database");
        return;
    }

    const auto module = utility::get_executable();
    const auto module_addr = (uintptr_t)module;
    const auto module_end = module_addr + utility::get_module_size(module).value_or(0);

    // Prefer the real via.io.file.exists methods; fall back to a landmark scan of the exe.
    auto candidates = find_exists_methods(tdb);

    if (candidates.empty()) {
        candidates = find_landmark_functions(module, module_end);
    }

    std::optional<uintptr_t> candidate;

    for (const auto fn : candidates) {
        candidate = scan_for_path_to_hash(fn, module_addr, module_end);

        if (candidate) {
            break;
        }
    }

    if (!candidate) {
        spdlog::error("[LooseFileLoader] Failed to find path_to_hash candidate, cannot continue");
        return;
    }

    m_path_to_hash_hook = std::make_unique<FunctionHook>(*candidate, (uintptr_t)&path_to_hash_hook);

    if (!m_path_to_hash_hook->create()) {
        spdlog::error("[LooseFileLoader] Failed to hook path_to_hash");
        return;
    }

    m_hook_success = true;
}

bool LooseFileLoader::check_exists(const wchar_t* path, size_t hash) {
    // Per-thread cache that keeps the common path entirely lock-free.
    static thread_local FileCache tl_cache;

    if (const auto it = tl_cache.find(hash); it != tl_cache.end()) {
        ++m_cache_hits;
        return it->second;
    }

    // Once the local cache saturates it can no longer absorb new hashes, so a cheap shared
    // read of the global cache keeps unknown hashes off the unique lock + disk path.
    if (tl_cache.size() >= kThreadCacheMax) {
        std::shared_lock _{m_cache_mutex};

        if (const auto it = m_cache.find(hash); it != m_cache.end()) {
            ++m_cache_hits;
            return it->second;
        }
    }

    bool on_disk{false};

    {
        // Purpose of this is to only hit the disk once per unique file.
        std::unique_lock _{m_cache_mutex};

        const auto [it, inserted] = m_cache.try_emplace(hash, false);

        if (inserted) {
            it->second = file_exists(path);

            if (m_log_accessed_files->value()) {
                m_logger->info("{}", utility::narrow(path));
            }

            if (it->second && m_log_loose_files->value()) {
                m_loose_file_logger->info("{}", utility::narrow(path));
            }
        }

        on_disk = it->second;
    }

    ++m_uncached_hits;

    if (tl_cache.size() < kThreadCacheMax) {
        tl_cache.emplace(hash, on_disk);
    }

    return on_disk;
}

void LooseFileLoader::record_recent(std::deque<std::wstring>& recent, const wchar_t* path) {
    std::unique_lock _{m_mutex};

    recent.push_front(path);

    if (recent.size() > kMaxRecentFiles) {
        recent.pop_back();
    }
}

bool LooseFileLoader::handle_path(const wchar_t* path, size_t hash) {
    if (path == nullptr || path[0] == L'\0') {
        return false;
    }

    ++m_files_encountered;

    if (m_show_recent_files) {
        record_recent(m_recent_accessed_files, path);
    }

    if (!m_enabled->value()) {
        return false;
    }

    bool on_disk{false};

    if (m_enable_file_cache) {
        on_disk = check_exists(path, hash);
    } else {
        on_disk = file_exists(path);
        ++m_uncached_hits;
    }

    if (!on_disk) {
        return false;
    }

    if (m_show_recent_files) {
        record_recent(m_recent_loose_files, path);
    }

    ++m_loose_files_loaded;
    return true;
}

#if TDB_VER > 67
uint64_t LooseFileLoader::path_to_hash_hook(const wchar_t* path) {
#else
uint64_t LooseFileLoader::path_to_hash_hook(void* This, const wchar_t* path) {
#endif
    const auto og = g_loose_file_loader->m_path_to_hash_hook->get_original<decltype(path_to_hash_hook)>();

#if TDB_VER > 67
    const auto result = og(path);
#else
    const auto result = og(This, path);
#endif

    // true to skip.
    if (g_loose_file_loader->handle_path(path, result)) {
#if TDB_VER > 67
        return 4294967296;
#else
        return 0xFFFFFFFF;
#endif
    }

    return result;
}
