#include <algorithm>
#include <spdlog/spdlog.h>

#include "utility/Scan.hpp"
#include "utility/Module.hpp"

#include "RETypeDB.hpp"
#include "REType.hpp"
#include "RETypes.hpp"

#include "REGlobals.hpp"

// Replacement for deprecated IsBadReadPtr - uses VirtualQuery instead
static bool is_readable(const void* addr, size_t size) {
    MEMORY_BASIC_INFORMATION mbi{};
    if (!VirtualQuery(addr, &mbi, sizeof(mbi))) {
        return false;
    }
    if (mbi.State != MEM_COMMIT) {
        return false;
    }
    if (mbi.Protect & PAGE_NOACCESS) {
        return false;
    }
    return (mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) != 0;
}

namespace reframework {
std::unique_ptr<REGlobals>& get_globals() {
    static auto globals = std::make_unique<REGlobals>();
    return globals;
}
}

REGlobals::REGlobals() {
    spdlog::info("REGlobals initialization");

    m_objects.reserve(2048);

    auto mod = utility::get_executable();
    auto start = (uintptr_t)mod;
    auto end = (uintptr_t)start + *utility::get_module_size(mod);

    end -= 0x1000;

    spdlog::info("start: {:x}", start);
    spdlog::info("end: {:x}", end);

    // generic pattern used for all these globals
    auto pat = std::string{ "48 8D ? ? ? ? ? 48 B8 00 00 00 00 00 00 00 80" };

    // find all the globals
    for (auto i = utility::scan(start, end - start, pat); i.has_value(); i = utility::scan(*i + 1, end - (*i + 1), pat)) try {
        auto ptr = utility::calculate_absolute(*i + 3);

        // Make sure the global is within the module boundaries
        if (ptr < start || ptr > (end - 8)) {
            continue;
        }

        // Make sure the pointer is aligned on an 8-byte boundary.
        if (ptr == 0 || ((uintptr_t)ptr & (sizeof(void*) - 1)) != 0) {
            continue;
        }

        if (!is_readable((void*)ptr, sizeof(void*))) {
            continue;
        }

        auto obj_ptr = (REManagedObject**)ptr;

        if (m_objects.find(obj_ptr) != m_objects.end()) {
            continue;
        }
        
        m_objects.insert(obj_ptr);
    } catch(...) {
        
    }

    // Create a list of getter functions instead
    if (m_objects.empty()) {
        spdlog::info("Usual pattern for REGlobals not working, falling back to scanning for SingletonBehavior types");

        auto& types = reframework::get_types();
        auto& type_list = types->get_types();

        size_t i = 0;

        for (auto t : type_list) {
            auto name = std::string{t->name};

            if (name.find(game_namespace("SingletonBehavior`1")) != std::string::npos ||
                name.find(game_namespace("SingletonBehaviorRoot`1")) != std::string::npos ||
                name.find(game_namespace("SnowSingletonBehaviorRoot`1")) != std::string::npos ||
                name.find(game_namespace("RopewaySingletonBehaviorRoot`1")) != std::string::npos)
            {
                const auto type_definition = utility::re_type::get_type_definition(t);

                if (type_definition == nullptr) {
                    spdlog::info("Failed to get type definition for {}", name);
                    continue;
                }

                //using asdf = decltype(m_getters)::value_type::second_type::_Func_class;
                using Getter = REManagedObject* (*)();
                auto getter = (Getter)sdk::find_native_method(type_definition, "get_Instance");

                if (getter == nullptr) {
                    continue;
                }

                // Get the contained type by grabbing the string between the "`1<"" and the ">""
                auto type_name = name.substr(name.find("`1<") + 3, name.find(">") - name.find("`1<") - 3);

                if (i++ < 100) {
                    spdlog::info("{}", type_name);
                }

                m_getters[type_name] = getter;
            }
        }
    }

    spdlog::info("Found {} REGlobals", m_objects.size());
    spdlog::info("Found {} getters", m_getters.size());

    spdlog::info("Finished REGlobals initialization");
}

std::unordered_set<REManagedObject*> REGlobals::get_objects() {
    std::unordered_set<REManagedObject*> out{};

    if (!m_objects.empty()) {
        for (auto obj_ptr : m_objects) {
            if (*obj_ptr != nullptr && is_readable(*obj_ptr, sizeof(void*))) {
                out.insert(*obj_ptr);
            }
        }
    } else {
        for (auto getter : m_getters) {
            auto result = getter.second();

            if (result != nullptr) {
                out.insert(result);
            }
        }
    }

    return out;
}

REType* REGlobals::get_native(std::string_view name) {
    std::lock_guard _{ m_map_mutex };

    if (m_native_singleton_types.empty()) {
        refresh_natives();
    }

    // Separate throttle timestamp for native lookups to avoid
    // interfering with object map refresh cadence
    const auto key = std::string{name};
    auto it = m_native_singleton_map.find(key);

    if (it == m_native_singleton_map.end()) {
        // Throttle refresh to avoid repeated full scans
        const auto now = std::chrono::steady_clock::now();
        if (now - m_last_native_refresh_time > std::chrono::seconds(1)) {
            m_last_native_refresh_time = now;
            refresh_natives();
        }

        it = m_native_singleton_map.find(key);
    }

    if (it == m_native_singleton_map.end()) {
        return nullptr;
    }

    return it->second;
}

std::vector<::REType*>& REGlobals::get_native_singleton_types() {
    if (m_native_singleton_types.empty()) {
        refresh_natives();
    }

    return m_native_singleton_types;
}

REManagedObject* REGlobals::get(std::string_view name) {
    std::lock_guard _{ m_map_mutex };

    // Construct the key once and reuse for all lookups
    const auto key = std::string{name};

    auto get_obj = [&]() -> REManagedObject* {
        if (m_object_map.empty()) {
            auto getter = m_getters.find(key);

            if (getter != m_getters.end()) {
                return getter->second();
            }
        }

        if (auto it = m_object_map.find(key); it != m_object_map.end()) {
            return *it->second;
        }

        return nullptr;
    };

    auto obj = get_obj();

    // try to refresh the map if the object doesnt exist.
    // assume the user knows this object exists.
    // Throttle refresh to avoid spamming on every call - only refresh
    // if it's been at least 1 second since the last refresh.
    if (obj == nullptr) {
        const auto now = std::chrono::steady_clock::now();
        if (now - m_last_refresh_time > std::chrono::seconds(1)) {
            m_last_refresh_time = now;
            refresh_map();
        }
    }

    // try again after refreshing the map
    return obj == nullptr ? get_obj() : obj;
}

REManagedObject* REGlobals::operator[](std::string_view name) {
    return get(name);
}

void REGlobals::safe_refresh() {
    std::lock_guard _{ m_map_mutex };
    refresh_map();
}

void REGlobals::safe_refresh_native() {
    std::lock_guard _{m_map_mutex};
    refresh_natives();
}

void REGlobals::refresh_natives() {
    auto& types = reframework::get_types()->get_types();

    m_native_singleton_types.clear();

    for (auto t : types) {
        if (t == nullptr) {
            continue;
        }
        
        if (!utility::re_type::is_singleton(t)) {
            continue;
        }

        m_native_singleton_types.push_back(t);
        m_native_singleton_map[t->name] = t;
    }

    std::sort(m_native_singleton_types.begin(), m_native_singleton_types.end(), [](auto a, auto b) {
        return std::string{ a->name } < std::string{ b->name };
    });
}

void REGlobals::refresh_map() {
    for (auto obj_ptr : m_objects) {
        auto obj = *obj_ptr;

        // Make sure the pointer is aligned on an 8-byte boundary.
        if (obj == nullptr || ((uintptr_t)obj & (sizeof(void*) - 1)) != 0) {
            continue;
        }

        if (!is_readable(obj, sizeof(REManagedObject))) {
            continue;
        }

        auto t = utility::re_managed_object::safe_get_type(obj);

        if (t == nullptr || t->name == nullptr) {
            continue;
        }

        if (m_acknowledged_objects.find(obj_ptr) == m_acknowledged_objects.end()) {
#ifdef DEVELOPER
            spdlog::info("{:x}->{:x} ({:s})", (uintptr_t)obj_ptr, (uintptr_t)*obj_ptr, t->name);
#endif
            m_acknowledged_objects.insert(obj_ptr);
        }

        m_object_map[t->name] = obj_ptr;
    }
}
