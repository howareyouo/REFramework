#include <array>
#include <shared_mutex>
#include <unordered_map>

#include "ReClass.hpp"

#include "RETypeDefinition.hpp"
#include "REType.hpp"

sdk::RETypeDefinition* utility::re_type::get_type_definition(REType* type) {
    if (type == nullptr || type->classInfo == nullptr) {
        return nullptr;
    }

    return (sdk::RETypeDefinition*)type->classInfo;
}

uint32_t utility::re_type::get_vm_type(::REType* t) {
    if (t == nullptr || t->classInfo == nullptr) {
        return (uint32_t)via::clr::VMObjType::NULL_;
    }

    const auto tdef = get_type_definition(t);

    if (tdef == nullptr) {
        return (uint32_t)via::clr::VMObjType::NULL_;
    }

    return (uint32_t)tdef->get_vm_obj_type();
}

uint32_t utility::re_type::get_value_type_size(::REType* t) {
    if (t == nullptr || t->classInfo == nullptr) {
        return 0;
    }

    if (get_vm_type(t) != (uint32_t)via::clr::VMObjType::ValType) {
        return t->size;
    }

    const auto tdef = get_type_definition(t);

    if (tdef == nullptr) {
        return 0;
    }

    return tdef->get_valuetype_size();
}

bool utility::re_type::is_clr_type(::REType* t) {
    return (t->flags & (int16_t)via::dti::decl::Script) != 0;
}

bool utility::re_type::is_singleton(::REType* t) {
    return (t->flags & (uint16_t)via::dti::decl::Singleton) != 0;
}

void* utility::re_type::get_singleton_instance(::REType* t) {
    if (!is_singleton(t)) {
        return nullptr;
    }

    using SingletonFunc = void (*)(::REType*, void**, void*);

    auto f = (*(SingletonFunc**)t)[1];

    void* out = nullptr;
    f(t, &out, nullptr);

    return out;
}

void* utility::re_type::create_instance(::REType* t) {
    using InstanceFunc = void (*)(::REType*, void**, void*);

    auto f = (*(InstanceFunc**)t)[1];

    void* out = nullptr;
    f(t, &out, nullptr);

    return out;
}

// Field and method lookups run on the render loop's hot path: the same handful of names
// resolves against the same types frame after frame. The old code built a "<type>.<field>"
// key (a heap allocation) and took a lock to search one shared map for each lookup. Two
// caches sit in front of the scan instead:
//
//   * a small per-thread memo, hit with an inline compare and no synchronisation at all;
//   * a shared table of everything resolved so far, so a cold thread or an evicted memo
//     entry only pays one hash instead of walking the type's variables.
//
// Only hits are cached, matching the previous behaviour: a field that is missing now may be
// added to the database later, and a remembered miss would hide it.
template <typename T>
class DescriptorCache {
public:
    T* find(const REType* type, std::string_view name) {
        auto& slot = memo()[bucket(type, name)];

        if (slot.type == type && slot.name == name) {
            return slot.value;
        }

        const auto descriptor = find_shared(type, name);

        if (descriptor != nullptr) {
            // The descriptor holds its own name in the reflection database, so the view
            // stays valid for as long as the memo entry does.
            slot = Entry{type, descriptor, descriptor->name};
        }

        return descriptor;
    }

    // The name has to be the descriptor's own, because the shared table keeps the view as key.
    void insert(const REType* type, std::string_view name, T* descriptor) {
        const std::unique_lock _{ m_mutex };
        m_table[type][name] = descriptor;
    }

private:
    struct Entry {
        const REType* type;
        T* value;
        std::string_view name;
    };

    static constexpr size_t bucket_count = 64;
    static_assert((bucket_count & (bucket_count - 1)) == 0, "bucket_count must be a power of two");

    static std::array<Entry, bucket_count>& memo() {
        static thread_local std::array<Entry, bucket_count> entries{};
        return entries;
    }

    static size_t bucket(const REType* type, std::string_view name) {
        const auto hash = std::hash<std::string_view>{}(name);
        return ((reinterpret_cast<uintptr_t>(type) >> 4) ^ hash) & (bucket_count - 1);
    }

    T* find_shared(const REType* type, std::string_view name) {
        const std::shared_lock _{ m_mutex };

        const auto types = m_table.find(type);

        if (types == m_table.end()) {
            return nullptr;
        }

        const auto descriptor = types->second.find(name);

        return descriptor == types->second.end() ? nullptr : descriptor->second;
    }

    std::shared_mutex m_mutex{};
    std::unordered_map<const REType*, std::unordered_map<std::string_view, T*>> m_table{};
};

DescriptorCache<VariableDescriptor> field_cache{};
DescriptorCache<FunctionDescriptor> method_cache{};

VariableDescriptor* utility::re_type::get_field_desc(::REType* t, std::string_view field) {
    if (t == nullptr) {
        return nullptr;
    }

    if (auto* cached = field_cache.find(t, field); cached != nullptr) {
        return cached;
    }

    // The table is keyed by the type the search started from, so any type only ever pays for
    // one walk of its hierarchy.
    for (auto* type = t; type != nullptr; type = type->super) {
        auto vars = get_variables(type);

        if (vars == nullptr) {
            continue;
        }

        for (auto i = 0; i < vars->num; ++i) {
            auto& var = vars->data->descriptors[i];

            if (var == nullptr || var->name == nullptr) {
                continue;
            }

            if (field == var->name) {
                field_cache.insert(t, var->name, var);
                return var;
            }
        }
    }

    return nullptr;
}

REVariableList* utility::re_type::get_variables(::REType* t) {
    if (t == nullptr || t->fields == nullptr || t->fields->variables == nullptr) {
        return nullptr;
    }

    auto vars = t->fields->variables;

    if (vars->data == nullptr || vars->num <= 0) {
        return nullptr;
    }

    return vars;
}

FunctionDescriptor* utility::re_type::get_method_desc(::REType* t, std::string_view name) {
    if (t == nullptr) {
        return nullptr;
    }

    if (auto* cached = method_cache.find(t, name); cached != nullptr) {
        return cached;
    }

    // The table is keyed by the type the search started from, so any type only ever pays for
    // one walk of its hierarchy.
    for (auto* type = t; type != nullptr; type = type->super) {
        auto fields = type->fields;

        if (fields == nullptr || fields->methods == nullptr) {
            continue;
        }

        auto methods = fields->methods;

        for (auto i = 0; i < fields->num; ++i) {
            auto top = (*methods)[i];

            if (top == nullptr || *top == nullptr) {
                continue;
            }

            auto& holder = **top;

            if (holder.descriptor == nullptr || holder.descriptor->name == nullptr) {
                continue;
            }

            if (name == holder.descriptor->name) {
                method_cache.insert(t, holder.descriptor->name, holder.descriptor);
                return holder.descriptor;
            }
        }
    }

    return nullptr;
}

