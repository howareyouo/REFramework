#include <spdlog/spdlog.h>

#include "utility/Scan.hpp"
#include "utility/Module.hpp"

#include "RETypeDB.hpp"
#include "RETypes.hpp"

namespace reframework {
std::unique_ptr<RETypes>& get_types() {
    static auto types = std::make_unique<RETypes>();
    return types;
}
}

std::string& game_namespace(std::string_view base_name)
{
    using namespace std::string_view_literals;

    static constexpr std::string_view prefix{
    "chainsaw."sv
    };

    static thread_local std::string buffer = [&]
    {
        std::string result{prefix};
        result.reserve(128);
        return result;
    }();

    buffer.resize(prefix.size());
    buffer.insert(prefix.size(), base_name.data());

    return buffer;
}

RETypes::RETypes() {
    spdlog::info("RETypes initialization");

    const auto mod = utility::get_executable();

    // RE4 reaches its type list through this load. The RE2/RE3/RE8/DMC5 pattern,
    // the RE7 TypeInfoNone hash and the 20-reference scan that depended on them
    // match nothing here, so this build does not carry them.
    const auto type_list_pat = "48 8B 0D ? ? ? ? 8B F0 48 85 C9 74 ? E8 ? ? ? ?";
    const auto type_list_ref = utility::scan(mod, type_list_pat);

    if (!type_list_ref) {
        spdlog::info("Could not find the type list reference, filling types from TDB instead");
        fill_types_from_tdb();
        return;
    }

    spdlog::info("Found type list ref: {:x}", (uintptr_t)*type_list_ref);

    m_raw_types = (TypeList*)utility::calculate_absolute(*type_list_ref + 3);

    refresh_map();

    spdlog::info("Finished RETypes initialization");
}

sdk::RETypeDB* RETypes::get_type_db() const {
    auto c = sdk::VM::get();

    if (c == nullptr) {
        return nullptr;
    }

    return c->get_type_db();
}

REType* RETypes::get(std::string_view name) {
    auto getObj = [&]() -> REType* {
        std::shared_lock _{ m_map_mutex };

        if (auto it = m_type_map.find(name.data()); it != m_type_map.end()) {
            return it->second;
        }

        return nullptr;
    };

    auto obj = getObj();

    // try to refresh the map if the object doesnt exist.
    // assume the user knows this object exists.
    if (obj == nullptr) {
        refresh_map();
    }

    // try again after refreshing the map
    return obj == nullptr ? getObj() : obj;
}

REType* RETypes::operator[](std::string_view name) {
    return get(name);
}

void RETypes::safe_refresh() {
    std::unique_lock _{ m_map_mutex };
    refresh_map();
}

void RETypes::fill_types_from_tdb() {
    auto tdb = sdk::RETypeDB::get();

    if (tdb == nullptr) {
        return;
    }
    
    spdlog::info("Filling types from TDB");

    for (auto i = 0; i < tdb->get_num_types(); ++i) {
        auto t = tdb->get_type(i);

        if (t == nullptr) {
            continue;
        }

        const auto re_type = t->get_type();

        if (re_type == nullptr) {
            continue;
        }

        m_type_map[t->get_full_name()] = t->get_type();
        m_types.insert(t->get_type());
        m_type_list.push_back(t->get_type());
    }

    spdlog::info("filled {} types from TDB", m_types.size());
}

void RETypes::refresh_map() {
    if (m_raw_types == nullptr) {
        return;
    }

    auto& typeList = *m_raw_types;

    // I don't know why but it can extend past the size.
    for (auto i = 0; i < typeList.numAllocated; ++i) {
        auto t = (*typeList.data)[i];

        if (t == nullptr || IsBadReadPtr(t, sizeof(REType)) || ((uintptr_t)t & (sizeof(void*) - 1)) != 0) {
            continue;
        }

        if (t->name == nullptr) {
            continue;
        }

        auto name = std::string{ t->name };

        if (name.empty()) {
            continue;
        }

        m_type_map[name] = t;

        if (m_types.count(t) == 0) {
            if (i < 100) {
                spdlog::info("{:s}", name);
            }
            m_types.insert(t);
            m_type_list.push_back(t);
        }
    }
}
