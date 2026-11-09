#include <cstdint>
#include <cstring>

#include <spdlog/fmt/fmt.h>

#include "HookManager.hpp"
#include "sdk/REContext.hpp"
#include "sdk/REManagedObject.hpp"
#include "sdk/REDelegate.hpp"
#include "sdk/RETypeDB.hpp"
#include "sdk/SceneManager.hpp"
#include "sdk/ResourceManager.hpp"
#include "sdk/MotionFsm2Layer.hpp"
#include "sdk/TDBVer.hpp"
#include "utility/Memory.hpp"

#include "../ScriptRunner.hpp"
#include <lstate.h> // weird include order because of sol
#include <lgc.h>

#include "Sdk.hpp"
#include "LuaHand.hpp"

namespace lh = lua_hand;

namespace api {
namespace sdk {
static std::unordered_map<::sdk::RETypeDefinition*, uint32_t> s_fnv_cache{};

struct BehaviorTreeCoreHandle : public ::REManagedObject {
    int unused;
};

struct BehaviorTree : public ::REManagedObject {
    int unused;
    int unused2;
};
}
}

namespace detail {
constexpr uintptr_t FAKE_OBJECT_ADDR = 12345;
}

namespace api::cached_usertype {
namespace detail {
    
}
}

namespace api::re_managed_object {
namespace detail {
void add_ref(lua_State* l, ::REManagedObject* obj, bool force = false) {
    // we shouldn't really do this very much
    // so it shouldn't be too terrible on performance
    if (!utility::re_managed_object::is_managed_object(obj)) {
        throw lua_stack::error{(std::stringstream{} << "sol_lua_push: " << (uintptr_t)obj << " is not a managed object").str()};
    }

    // The counts are keyed by the address the object lives at.
    const auto key = static_cast<lua_Integer>(reinterpret_cast<uintptr_t>(obj));

    // Throwing automatic add_ref on the backburner; it doesn't seem to work
    // very well with lua's garbage collector.
    // addendum: maybe figured it out

    // only add a reference if it's a "local" object, indicated by a negative reference count
    //if ((int32_t)obj->referenceCount < 0 || (current_ref_count && *current_ref_count > 0)) {
    // addendum: only do it when reference count is > 0, local objects seem buggy...
    if (force || (int32_t)obj->referenceCount > 0) {
        if (!force) {
            utility::re_managed_object::add_ref(obj);
        }

        // the reference counting is not necessary, but it will let us
        // catch bugs if an REManagedObject pointer is being created
        // without coming through our sol_lua_push function
        lua_stack::table ref_counts = lua_stack::global_table(l, "_sol_lua_push_ref_counts");
        lua_stack::table ephemeral_counts = lua_stack::global_table(l, "_sol_lua_push_ephemeral_counts");
        std::optional<int> current_ref_count = ref_counts.get_optional<int>(key);

        if (current_ref_count && *current_ref_count > 0) {
            // don't unnecessarily increase the ref count
            // if the user is the one doing it
            if (force) {
                return;
            }

            ref_counts.set(key, *current_ref_count + 1);
        } else {
            // only add the ref once when the user requests it
            // so they don't screw something up
            if (force) {
                utility::re_managed_object::add_ref(obj);
            }

            ref_counts.set(key, 1);
        }

        // when the user adds a ref to an ephemeral object
        if (force) {
            std::optional<int> current_ephemeral_count = ephemeral_counts.get_optional<int>(key);

            if (current_ephemeral_count && *current_ephemeral_count > 0) {
                ephemeral_counts.set(key, *current_ephemeral_count - 1);
            } else {
                ephemeral_counts.set_nil(key);
            }
        }
    } else {
        // ephemeral counts is just a table
        // to help with tracking the local objects
        // so we don't spam the log with warnings when they get gc'd
        lua_stack::table ephemeral_counts = lua_stack::global_table(l, "_sol_lua_push_ephemeral_counts");
        std::optional<int> current_ref_count = ephemeral_counts.get_optional<int>(key);

        if (current_ref_count) {
            ephemeral_counts.set(key, *current_ref_count + 1);
        } else {
            ephemeral_counts.set(key, 1);
        }
    }
}
}

// used by metatable for REManagedObject
::REManagedObject* add_ref(lua_State* s, ::REManagedObject* obj) {
    detail::add_ref(s, obj, true);

    return obj;
}

::REManagedObject* add_ref_permanent(lua_State* s, ::REManagedObject* obj) {
    if (!utility::re_managed_object::is_managed_object(obj)) {
        throw lua_stack::error{(std::stringstream{} << "add_ref_permanent: " << (uintptr_t)obj << " is not a managed object").str()};
    } 

    utility::re_managed_object::add_ref(obj);

    return obj;
}

void release(lua_State* s, ::REManagedObject* obj, bool force = false) {
    auto l = s;
    const auto key = static_cast<lua_Integer>(reinterpret_cast<uintptr_t>(obj));

    lua_stack::table objects = lua_stack::global_table(l, "_sol_lua_push_objects");
    lua_stack::table ref_counts = lua_stack::global_table(l, "_sol_lua_push_ref_counts");
    lua_stack::table ephemeral_counts = lua_stack::global_table(l, "_sol_lua_push_ephemeral_counts");

    if (std::optional<int> ref_count = ref_counts.get_optional<int>(key); ref_count && *ref_count > 0) {
        // because of our internal refcount keeping, we shouldn't need to double check
        // whether it's an actual object or not. hopefully?
        //if (utility::re_managed_object::is_managed_object(obj)) {
            utility::re_managed_object::release(obj);
        //}

        int new_ref_count = *ref_count - 1;

        if (new_ref_count == 0) {
            if (!ephemeral_counts.get_optional<lua_stack::object>(key).has_value()) {
                objects.set_nil(key);
            }

            ref_counts.set_nil(key);
        } else {
            ref_counts.set(key, new_ref_count);
        }
    } else if (std::optional<int> ephemeral_count = ephemeral_counts.get_optional<int>(key); ephemeral_count && *ephemeral_count > 0) {
        if (force && utility::re_managed_object::is_managed_object(obj)) {
            utility::re_managed_object::release(obj);
        }

        // ephemeral counts don't actually release the object, they just decrement the count.
        int new_ephemeral_count = *ephemeral_count - 1;

        if (new_ephemeral_count == 0) {
            objects.set_nil(key);
            ephemeral_counts.set_nil(key);
        } else {
            ephemeral_counts.set(key, new_ephemeral_count);
        }
    } else {
        if (force) {
            if (utility::re_managed_object::is_managed_object(obj)) {
                utility::re_managed_object::release(obj);
            }
        } else {
            spdlog::warn("REManagedObject:release attempted to release an object that was not managed by our Lua state");
        }
    }
}
}

// specialization for REManagedObject to automatically add a reference
// when lua pushes a pointer to the object onto the stack
template<detail::ManagedObjectBased T>
int lua_stack_push(lua_stack::pointer_tag<T>, lua_State* l, T* obj) {
    if (obj != nullptr) {
        const auto key = static_cast<lua_Integer>(reinterpret_cast<uintptr_t>(obj));
        lua_stack::table objects = lua_stack::global_table(l, "_sol_lua_push_objects");

        if (auto lua_obj = objects.get_optional<lua_stack::object>(key); lua_obj.has_value()) {
            // renew the reference so it doesn't get collected
            // had to dig deep in the lua source to figure out this nonsense
            lua_obj->push();
            auto g = G(l);
            auto tv = s2v(l->top - 1);
            auto& gc = tv->value_.gc;
            resetbits(gc->marked, bitmask(BLACKBIT) | WHITEBITS); // "touches" the object, marking it gray. lowers the insane GC frequency on our weak table

            return 1;
        } else {
            if ((uintptr_t)obj != detail::FAKE_OBJECT_ADDR) {
                api::re_managed_object::detail::add_ref(l, (::REManagedObject*)obj, false);
            }

            int32_t backpedal = 0;

            if ((uintptr_t)obj != detail::FAKE_OBJECT_ADDR) {
                uint32_t typename_hash = 0;
                const auto td = utility::re_managed_object::get_type_definition(obj);

                if (td != nullptr) {
                    if (auto it = api::sdk::s_fnv_cache.find(td); it != api::sdk::s_fnv_cache.end()) {
                        typename_hash = it->second;
                    } else {
                        typename_hash = utility::hash(td->get_full_name());
                        api::sdk::s_fnv_cache[td] = typename_hash;
                    }

                    switch (typename_hash) {
                    case "via.Transform"_fnv:
                        backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<::RETransform>>(l, (::RETransform*)obj);
                        break;
                    case "via.behaviortree.BehaviorTree"_fnv:[[fallthrough]];
                    case "via.motion.MotionFsm2"_fnv:[[fallthrough]];
                    case "via.motion.MotionJackFsm2"_fnv:[[fallthrough]];
                    case "snow.PlayerMotionFsm"_fnv:
                        backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<api::sdk::BehaviorTree>>(l, (api::sdk::BehaviorTree*)obj);
                        break;
                    case "via.behaviortree.BehaviorTree.CoreHandle"_fnv: [[fallthrough]];
                    case "via.motion.MotionFsm2Layer"_fnv: [[fallthrough]];
                    case "via.timeline.TimelineFsm2Layer"_fnv:
                        backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<api::sdk::BehaviorTreeCoreHandle>>(l, (api::sdk::BehaviorTreeCoreHandle*)obj);
                        break;
                    default:
                        {
                            const auto vm_obj_type = td->get_vm_obj_type();
                            if (vm_obj_type == via::clr::VMObjType::Array) {
                                backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<sdk::SystemArray>>(l, (sdk::SystemArray*)obj);
                            } else {
                                backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<T>>(l, obj);
                            }
                        }
                        
                        break;
                    };
                } else {
                    backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<T>>(l, obj);
                }

                auto ref = lua_stack::get<lua_stack::object>(l, -backpedal);

                // keep a weak reference to the object for caching
                objects.set(key, ref);

                return backpedal;
            } else {
                backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<T>>(l, obj);
            }

            return backpedal;
        }
    }

    return lua_stack::put(l, lua_stack::lua_nil);
}

// specialization for any custom usertype we exposed to sol to automatically add a reference
// when lua pushes a pointer to the object onto the stack
template<detail::CachedUserType T>
int lua_stack_push(lua_stack::pointer_tag<T>, lua_State* l, T* obj) {
    if (obj != nullptr) {
        // this is a weak table, so we don't need to set the index to nil when the object is no longer referenced
        const auto key = static_cast<lua_Integer>(reinterpret_cast<uintptr_t>(obj));
        lua_stack::table objects_top = lua_stack::global_table(l, "_sol_lua_push_usertypes");
        constexpr auto function_sig = utility::hash(__FUNCSIG__);
        const auto type_key = static_cast<lua_Integer>(function_sig);

        if (!objects_top.get_optional<lua_stack::table>(type_key).has_value()) {
            spdlog::info("About to create a weak table for usertype {}", __FUNCSIG__);

            lua_newtable(l);
            lua_newtable(l);
            lua_pushstring(l, "v");
            lua_setfield(l, -2, "__mode");
            lua_setmetatable(l, -2);
            objects_top.set(type_key, lua_stack::table{l, -1});
            lua_pop(l, 1);

            spdlog::info("Created a weak table for usertype {}", __FUNCSIG__);
        }

        lua_stack::table objects = objects_top.get<lua_stack::table>(type_key);

        if (auto lua_obj = objects.get_optional<lua_stack::object>(key); lua_obj.has_value()) {
            // renew the reference so it doesn't get collected
            // had to dig deep in the lua source to figure out this nonsense
            lua_obj->push();
            auto g = G(l);
            auto tv = s2v(l->top - 1);
            auto& gc = tv->value_.gc;
            resetbits(gc->marked, bitmask(BLACKBIT) | WHITEBITS); // "touches" the object, marking it gray. lowers the insane GC frequency on our weak table

            return 1;
        } else {
            int32_t backpedal = lua_stack::push_pointer_plain<std::remove_pointer_t<T>>(l, obj);

            if ((uintptr_t)obj != detail::FAKE_OBJECT_ADDR) {
                auto ref = lua_stack::get<lua_stack::object>(l, -backpedal);

                // keep a weak reference to the object for caching
                objects.set(key, ref);

                return backpedal;
            }

            return backpedal;
        }
    }

    return lua_stack::put(l, lua_stack::lua_nil);
}

namespace api::delegate {
void add_lua_delegate(lua_State* s, ::sdk::Delegate* delegate, uint32_t index, lua_stack::protected_function callback) {
    if (index >= delegate->num_methods) {
        throw lua_stack::error("Delegate index out of bounds");
    }

    auto& invo = delegate->methods[index];
    auto state = lua_stack::registry_get<ScriptState*>(s, "state");

    state->add_delegate_callback(invo, callback);
}

// newindex
void new_index(lua_State* s, ::sdk::Delegate* delegate, lua_stack::object lua_obj, lua_stack::variadic_args args) {
    if (lua_obj.is<uint32_t>()) {
        auto index = lua_obj.as<uint32_t>();

        if (args[0].is<lua_stack::protected_function>()) {
            auto callback = args[0].get<lua_stack::protected_function>();

            add_lua_delegate(s, delegate, index, callback);
        } else {
            throw lua_stack::error("Delegate callback must be a function");
        }
    }
}
}

namespace api::sdk {
std::vector<void*>& build_args(lua_stack::variadic_args va);
lua_stack::object parse_data(lua_State* l, void* data, ::sdk::RETypeDefinition* data_type, bool from_method);
lua_stack::object get_native_field(lua_stack::object obj, ::sdk::RETypeDefinition* ty, const char* name);
lua_stack::object get_native_field_from_field(lua_stack::object obj, ::sdk::RETypeDefinition* ty, ::sdk::REField* field);
lua_stack::object get_field_or_method(lua_stack::object obj, const char* name);
void set_native_field(lua_State* s, lua_stack::object obj, ::sdk::RETypeDefinition* ty, const char* name, lua_stack::object value);

struct ValueType {
    std::vector<uint8_t> data{};
    ::sdk::RETypeDefinition* type{nullptr};

    ValueType(::sdk::RETypeDefinition* t)
        : type(t)
    {
        if (type != nullptr) {
            data.resize(type->get_size());
        }
    }

    ValueType(::sdk::RETypeDefinition* t, void* addr): type(t) {
        if (t != nullptr && addr != nullptr) {
            uint8_t* raw_data = reinterpret_cast<uint8_t*>(addr);
            data.reserve(t->get_size());
            data.insert(data.begin(), raw_data, raw_data + t->get_size());
        }
    }

    ValueType(const void* raw_data, size_t raw_data_size) {
        if (raw_data_size > 0 && raw_data != nullptr) {
            data.resize(raw_data_size);
            memcpy(data.data(), raw_data, raw_data_size);
        }
    }

    template <typename T>
    bool is_valid_offset(int32_t offset, T& value) const {
        return offset >= 0 && (size_t)offset + sizeof(T) <= data.size();
    }

    bool is_valid_offset(int32_t offset) const {
        return offset >= 0 && (size_t)offset <= data.size();
    }

    template <typename T>
    void write_memory(int32_t offset, T value) {
        if (!is_valid_offset(offset, value)) {
            return;
        }

        *(T*)((uintptr_t)data.data() + offset) = value;
    }

    template <typename T>
    T read_memory(int32_t offset) {
        T value{};
        if (!is_valid_offset(offset, value)) {
            return {};
        }

        return *(T*)((uintptr_t)data.data() + offset);
    }

    uintptr_t address() const {
        return (uintptr_t)data.data();
    }

    lua_stack::object call(lua_State* l, const char* name, lua_stack::variadic_args va) {
        if (type == nullptr) {
            return lua_stack::make_object(l, lua_stack::lua_nil);
        }

        auto real_obj = (void*)address();
        auto def = type->get_method(name);

        if (def == nullptr) {
            return lua_stack::make_object(l, lua_stack::lua_nil);
        }

        auto vec_args = ::api::sdk::build_args(va);
        auto ret_val = def->invoke(real_obj, std::span(vec_args));

        if (ret_val.exception_thrown) {
            throw lua_stack::error("Invoke threw an exception");
        }

        // Convert return values to the correct Lua types.
        auto ret_ty = def->get_return_type();

        return ::api::sdk::parse_data(l, &ret_val, ret_ty, true);
    }

    lua_stack::object get_field(lua_State* l, const char* name) {
        if (type == nullptr) {
            return lua_stack::make_object(l, lua_stack::lua_nil);
        }

        return ::api::sdk::get_native_field(lua_stack::make_object(l, (void*)address()), type, name);
    }

    void set_field(lua_State* l, const char* name, lua_stack::object value) {
        if (type == nullptr) {
            return;
        }

        ::api::sdk::set_native_field(l, lua_stack::make_object(l, (void*)address()), type, name, value);
    }

    lua_stack::object index(lua_State* s, const char* name) {
        if (type == nullptr) {
            return lua_stack::make_object(s, lua_stack::lua_nil);
        }


        auto field = type->get_field(name);
        if (field != nullptr) {
            return api::sdk::get_native_field_from_field(lua_stack::make_object(s, (void*)address()), type, field);
        }
        auto method = type->get_method(name);
        if (method != nullptr) {
            return lua_stack::make_object(s, method);
        }

        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    void new_index(lua_State* s, const char* name, lua_stack::object assign) {
        if (type == nullptr) {
            return;
        }
        return api::sdk::set_native_field(s, lua_stack::make_object(s, (void*)address()), type, name, assign);
    };
};

struct MemoryView {
    uint8_t* data{nullptr};
    size_t size{0};

    MemoryView(uint8_t* d, size_t s)
        : data(d)
        , size(s)
    {
    }

    template <typename T>
    bool is_valid_offset(int32_t offset, T& value) const {
        return offset >= 0 && (size_t)offset + sizeof(T) <= size;
    }

    bool is_valid_offset(int32_t offset) const {
        return offset >= 0 && (size_t)offset <= size;
    }

    template <typename T>
    void write_memory(int32_t offset, T value) {
        if (!is_valid_offset(offset, value)) {
            return;
        }

        *(T*)((uintptr_t)data + offset) = value;
    }

    template <typename T>
    T read_memory(int32_t offset) {
        T value{};
        if (!is_valid_offset(offset, value)) {
            return {};
        }

        return *(T*)((uintptr_t)data + offset);
    }

    uintptr_t address() const {
        return (uintptr_t)data;
    }

    void wipe() {
        memset(data, 0, size);
    }
};

void* get_thread_context() {
    return (void*)::sdk::get_thread_context();
}

auto find_type_definition(const char* name) {
    return ::sdk::find_type_definition(name);
}

uint32_t get_num_types() {
    const auto tdb = ::sdk::RETypeDB::get();
    return tdb == nullptr ? 0 : tdb->get_num_types();
}

lua_stack::object get_type(lua_State* s, uint32_t index) {
    const auto tdb = ::sdk::RETypeDB::get();

    if (tdb == nullptr || index >= tdb->get_num_types()) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, tdb->get_type(index));
}

lua_stack::object typeof(lua_State* s, const char* name) {
    auto type_definition = find_type_definition(name);

    if (type_definition == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, type_definition->get_runtime_type());
}

void* get_native_singleton(const char* name) {
    return (void*)::sdk::get_native_singleton<void>(name);
}

auto get_managed_singleton(lua_State* s, const char* name) {
    if (name == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto out = ::sdk::get_managed_singleton<::REManagedObject>(name);

    if (out == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, out);
}

lua_stack::object create_managed_string(lua_State* s, const char* text) {
    if (text == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto new_str = ::sdk::VM::create_managed_string(utility::widen(text));

    if (new_str == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_str);
}

// Length is read as int64_t, not uint32_t: a negative Lua number wrapped to
// ~4e9 and the VM attempted a multi-GB allocation that hung the process.
lua_stack::object create_managed_array(lua_State* s, lua_stack::object t_obj, int64_t length) {
    constexpr int64_t max_length = 0x1000000; // 16.7M elements

    if (length < 0) {
        throw lua_stack::error("create_managed_array: length cannot be negative");
    }

    if (length > max_length) {
        throw lua_stack::error("create_managed_array: length " + std::to_string(length)
            + " exceeds the maximum of " + std::to_string(max_length));
    }

    ::REManagedObject* t{nullptr};

    if (t_obj.is<::REManagedObject*>()) {
        t = t_obj.as<::REManagedObject*>();
    } else if (t_obj.is<::sdk::RETypeDefinition*>()) {
        t = t_obj.as<::sdk::RETypeDefinition*>()->get_runtime_type();
    } else if (t_obj.is<const char*>()) {
        const auto tdef = ::sdk::find_type_definition(t_obj.as<const char*>());

        if (tdef != nullptr) {
            t = tdef->get_runtime_type();
        }
    } else {
        throw lua_stack::error("Invalid type passed to create_managed_array. Must be a runtime type, a type definition, or a type name.");
    }

    if (t == nullptr) {
        throw lua_stack::error("Type passed to create_managed_array resolved to null.");
    }

    auto out = ::sdk::VM::create_managed_array(t, (uint32_t)length);

    if (out == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::sdk::SystemArray*)out);
}

lua_stack::object create_delegate(lua_State* s, lua_stack::object t_obj, uint32_t num_methods) {
    ::REManagedObject* t{nullptr};

    if (t_obj.is<::REManagedObject*>()) {
        t = t_obj.as<::REManagedObject*>();
    } else if (t_obj.is<::sdk::RETypeDefinition*>()) {
        t = t_obj.as<::sdk::RETypeDefinition*>()->get_runtime_type();
    } else if (t_obj.is<const char*>()) {
        const auto tdef = ::sdk::find_type_definition(t_obj.as<const char*>());

        if (tdef != nullptr) {
            t = tdef->get_runtime_type();
        }
    } else {
        throw lua_stack::error("Invalid type passed to create_delegate. Must be a runtime type, a type definition, or a type name.");
    }

    if (t == nullptr) {
        throw lua_stack::error("Type passed to create_delegate resolved to null.");
    }

    auto out = ::sdk::VM::create_delegate(t, num_methods);

    if (out == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, out);
}

lua_stack::object create_sbyte(lua_State* s, int8_t value) {
    auto new_obj = ::sdk::VM::create_sbyte(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_byte(lua_State* s, uint8_t value) {
    auto new_obj = ::sdk::VM::create_byte(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_int16(lua_State* s, int16_t value)  {
    auto new_obj = ::sdk::VM::create_int16(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_uint16(lua_State* s, uint16_t value)  {
    auto new_obj = ::sdk::VM::create_uint16(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_int32(lua_State* s, int32_t value)  {
    auto new_obj = ::sdk::VM::create_int32(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_uint32(lua_State* s, int32_t value)  {
    auto new_obj = ::sdk::VM::create_uint32(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_int64(lua_State* s, int64_t value)  {
    auto new_obj = ::sdk::VM::create_int64(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_uint64(lua_State* s, int64_t value)  {
    auto new_obj = ::sdk::VM::create_uint64(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_single(lua_State* s, float value)  {
    auto new_obj = ::sdk::VM::create_single(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_double(lua_State* s, double value)  {
    auto new_obj = ::sdk::VM::create_double(value);

    if (new_obj == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, (::REManagedObject*)new_obj);
}

lua_stack::object create_resource(lua_State* s, std::string type_name, std::string name) {
    auto& types = reframework::get_types();

    // NOT a type definition!!
    // this is a via::typeinfo::TypeInfo
    const auto t = types->get(type_name);

    if (t == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto resource_manager = ::sdk::ResourceManager::get();
    return lua_stack::make_object(s, resource_manager->create_resource(t, utility::widen(name)));
}

lua_stack::object create_global_object(lua_State* s, ::REManagedObject *obj) {
    bool is_currently_local = static_cast<std::int32_t>(obj->referenceCount) <= 0;

    // Mark object as global so that lua knows
    if (is_currently_local) {
        utility::re_managed_object::add_ref(obj);
    }

    auto obj_safe = lua_stack::make_object(s, obj);

    if (is_currently_local) {
        utility::re_managed_object::release(obj);
    }

    return obj_safe;
}

lua_stack::object create_userdata_impl(lua_State* s, std::string type_name, std::string name, bool global) {
    auto& types = reframework::get_types();

    // NOT a type definition!!
    // this is a via::typeinfo::TypeInfo
    const auto t = types->get(type_name);

    if (t == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto resource_manager = ::sdk::ResourceManager::get();
    auto obj = resource_manager->create_userdata(t, utility::widen(name));

    if (!obj.has_value()) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto re_obj = (::REManagedObject*)obj.get();

    if (global) {
        return create_global_object(s, re_obj);
    } else {
        return lua_stack::make_object(s, re_obj);
    }
}

lua_stack::object create_userdata(lua_State* s, std::string type_name, std::string name) {
    return create_userdata_impl(s, type_name, name, false);
}

lua_stack::object create_userdata_global(lua_State* s, std::string type_name, std::string name) {
    return create_userdata_impl(s, type_name, name, true);
}

lua_stack::object create_instance_impl(lua_State* s, const char* name, lua_stack::object simplify_obj, bool global) {
    bool simplify = false;

    if (simplify_obj.is<bool>()) {
        simplify = simplify_obj.as<bool>();
    }

    if (name == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto type_definition = find_type_definition(name);

    if (type_definition == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto instance_full = type_definition->create_instance_full(simplify);

    if (global) {
        return create_global_object(s, instance_full);
    } else {
        return lua_stack::make_object(s, instance_full);
    }
}

lua_stack::object create_instance(lua_State* s, const char* name, lua_stack::object simplify_obj) {
    return create_instance_impl(s, name, simplify_obj, false);
}

lua_stack::object create_instance_global(lua_State* s, const char* name, lua_stack::object simplify_obj) {
    return create_instance_impl(s, name, simplify_obj, true);
}

lua_stack::object create_holder_impl(lua_State* s, ::sdk::Resource* res, const char* tn, bool global) {
    if (tn == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    const auto t = sdk::find_type_definition(tn);

    if (t == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    auto holder = res->create_holder(t);

    if (holder == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    if (global) {
        return create_global_object(s, holder);
    } else {
        return lua_stack::make_object(s, holder);
    }
}

lua_stack::object create_holder(lua_State* s, ::sdk::Resource* res, const char* tn) {
    return create_holder_impl(s, res, tn, false);
}

lua_stack::object create_holder_global(lua_State* s, ::sdk::Resource* res, const char* tn) {
    return create_holder_impl(s, res, tn, true);
}

bool copy_to_clipboard(lua_State* s, const char* text) {
    if (text == nullptr) {
        return false;
    }

    if (OpenClipboard(nullptr)) {
        EmptyClipboard();

        size_t len = strlen(text) + 1;
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);

        if (hMem) {
            memcpy(GlobalLock(hMem), text, len);
            GlobalUnlock(hMem);

            SetClipboardData(CF_TEXT, hMem);
        } else {
            return false;
        }

        CloseClipboard();
    } else {
        return false;
    }

    return true;
}

void* get_real_obj(lua_stack::object obj) {
    void* real_obj = nullptr;

    if (!obj.is<lua_stack::nil_t>()) {
        if (obj.is<REManagedObject*>()) {
            real_obj = (void*)obj.as<REManagedObject*>();
        } else if (obj.is<::sdk::Resource*>()) {
            real_obj = (void*)obj.as<::sdk::Resource*>();
        } else if (obj.is<ValueType>()) {
            real_obj = (void*)obj.as<ValueType&>().address();
        } else if (obj.is<void*>()) {
            real_obj = obj.as<void*>();
        } else {
            real_obj = (void*)obj.as<uintptr_t>();
        }
    }

    return real_obj;
}

// Hash used to dispatch on a type's full name; enums hash by their underlying
// type so they marshal like their primitive representation.
static size_t type_dispatch_hash(::sdk::RETypeDefinition* data_type) {
    if (data_type->is_enum()) {
        auto underlying_type = data_type->get_underlying_type();

        if (underlying_type != nullptr) {
            return utility::hash(underlying_type->get_full_name());
        }

        return 0;
    }

    return utility::hash(data_type->get_full_name());
}

lua_stack::object parse_data(lua_State* l, void* data, ::sdk::RETypeDefinition* data_type, bool from_method) {
    if (data_type != nullptr) {
        if (!data_type->is_value_type()) {
            if (data == nullptr || *(void**)data == nullptr) {
                return lua_stack::make_object(l, lua_stack::lua_nil);
            }
        }

        const auto full_name_hash = type_dispatch_hash(data_type);

        const auto vm_obj_type = data_type->get_vm_obj_type();

        switch (full_name_hash) {
        case "System.String"_fnv: {
            const auto managed_ret_val = *(::REManagedObject**)data;
            const auto managed_str = (SystemString*)((uintptr_t)utility::re_managed_object::get_field_ptr(managed_ret_val) - sizeof(::REManagedObject));
            const auto str = utility::narrow(managed_str->data);

            return lua_stack::make_object(l, str);
        }
        case "System.Single"_fnv: {
            if (from_method) {
                // even though it's a single, it's actually a double because of the invoke wrapper conversion
                auto ret_val_f = *(double*)data;
                return lua_stack::make_object(l, ret_val_f);
            } else {
                auto ret_val_f = *(float*)data;
                return lua_stack::make_object(l, ret_val_f);
            }
        }
        case "System.Double"_fnv: {
            auto ret_val_d = *(double*)data;
            return lua_stack::make_object(l, ret_val_d);
        }
        case "System.Boolean"_fnv: {
            auto ret_val_b = *(bool*)data;
            return lua_stack::make_object(l, ret_val_b);
        }
        case "System.SByte"_fnv: {
            auto ret_val_i = *(int8_t*)data;
            return lua_stack::make_object(l, ret_val_i);
        }
        case "System.Byte"_fnv: {
            auto ret_val_b = *(uint8_t*)data;
            return lua_stack::make_object(l, ret_val_b);
        }
        case "System.Int16"_fnv: {
            auto ret_val_i = *(int16_t*)data;
            return lua_stack::make_object(l, ret_val_i);
        }
        case "System.UInt16"_fnv: {
            auto ret_val_i = *(uint16_t*)data;
            return lua_stack::make_object(l, ret_val_i);
        }
        case "System.UInt32"_fnv: {
            auto ret_val_u = *(uint32_t*)data;
            return lua_stack::make_object(l, ret_val_u);
        }
        case "System.Int32"_fnv: {
            auto ret_val_u = *(int32_t*)data;
            return lua_stack::make_object(l, ret_val_u);
        }
        case "System.Int64"_fnv: {
            auto ret_val_u = *(int64_t*)data;
            return lua_stack::make_object(l, ret_val_u);
        }
        case "System.UInt64"_fnv: {
            //auto ret_val_u = *(uint64_t*)data;
            // so, sol is converting the unsigned version incorrectly into some 1.blah e+19 number
            // so just return it as signed since Lua only has signed integers
            auto ret_val_u = *(int64_t*)data;
            return lua_stack::make_object(l, ret_val_u);
        }
        case "via.Float2"_fnv: [[fallthrough]];
        case "via.vec2"_fnv: {
            auto ret_val_v = *(Vector2f*)data;
            return lua_stack::make_object(l, ret_val_v);
        }
        case "via.Float3"_fnv: [[fallthrough]];
        case "via.vec3"_fnv: {
            auto ret_val_v = *(Vector3f*)data;
            return lua_stack::make_object(l, ret_val_v);
        }
        case "via.Float4"_fnv: [[fallthrough]];
        case "via.vec4"_fnv: {
            auto ret_val_v = *(Vector4f*)data;
            return lua_stack::make_object(l, ret_val_v);
        }
        case "via.mat4"_fnv: {
            auto ret_val_m = *(Matrix4x4f*)data;
            return lua_stack::make_object(l, ret_val_m);
        }
        case "via.Quaternion"_fnv: {
            auto ret_val_q = *(glm::quat*)data;
            return lua_stack::make_object(l, ret_val_q);
        }
        case "via.GameObjectRef"_fnv: {
            auto obj = ::sdk::call_method_safe<::REManagedObject*>("via.GameObjectRef", "get_Target", sdk::get_thread_context(), data);

            if (obj == nullptr) {
                return lua_stack::make_object(l, lua_stack::lua_nil);
            }

            return lua_stack::make_object(l, obj);
        }
        default:
            if (vm_obj_type > via::clr::VMObjType::NULL_ && vm_obj_type < via::clr::VMObjType::ValType) {
                switch (vm_obj_type) {
                case via::clr::VMObjType::Array:
                    return lua_stack::make_object(l, *(::sdk::SystemArray**)data);
                default: {
                    const auto td = utility::re_managed_object::get_type_definition(*(::REManagedObject**)data);

                    // another fallback incase the method returns an object which is an array
                    if (td != nullptr && td->get_vm_obj_type() == via::clr::VMObjType::Array) {
                        return lua_stack::make_object(l, *(::sdk::SystemArray**)data);
                    }

                    return lua_stack::make_object(l, *(::REManagedObject**)data);
                }
                }
            }
            break;
        }

        // so, we managed to get here, but we don't know what to do with the data
        // check if it's a valuetype first
        if (data_type->is_value_type()) {
            auto new_obj = lua_stack::make_object(l, ValueType{ data_type });
            auto& bytes = new_obj.as<ValueType&>();
            
            memcpy(bytes.data.data(), data, data_type->get_size());

            return new_obj;
        }
    }

    // A null void* will get converted into an userdata with value 0. That's not very useful in Lua, so
    // let's return nil instead since that's a much more usable value.
    if (data == nullptr || *(void**)data == nullptr) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }

    return lua_stack::make_object(l, *(void**)data);
}

void set_data(void* data, ::sdk::RETypeDefinition* data_type, lua_stack::object& value) {
    if (data_type != nullptr) {
        const auto full_name_hash = type_dispatch_hash(data_type);
        const auto vm_obj_type = data_type->get_vm_obj_type();

        // Commemorating the moment I finally added support for this
        // ....... 2 years after the Lua API was first created
        // This allows us to pass arbitrary ValueTypes and set fields with them
        // So we don't need to hardcode every possible ValueType, just the most important ones like Int32, Single, vec3, etc...
        if (data != nullptr && vm_obj_type == via::clr::VMObjType::ValType && value.is<ValueType*>()) {
            auto vt = value.as<ValueType*>();

            if (vt->type != data_type) {
                if (vt->type != nullptr && data_type != nullptr) {
                    throw lua_stack::error(fmt::format("Attempted to set ValueType of type {} to field of type {}", vt->type->get_full_name(), data_type->get_full_name()));
                }

                throw lua_stack::error("Attempted to set ValueType to field of unknown type");
            }

            memcpy(data, vt->data.data(), vt->data.size());
            return;
        }

        switch (full_name_hash) {
        case "System.Single"_fnv:
            *(float*)data = value.as<float>();
            return;
        case "System.Double"_fnv:
            *(double*)data = value.as<double>();
            return;
        case "System.Boolean"_fnv:
            *(bool*)data = value.as<bool>();
            return;
        case "System.SByte"_fnv:
            *(int8_t*)data = value.as<int8_t>();
            return;
        case "System.Byte"_fnv:
            *(uint8_t*)data = value.as<uint8_t>();
            return;
        case "System.Int16"_fnv:
            *(int16_t*)data = value.as<int16_t>();
            return;
        case "System.UInt16"_fnv:
            *(uint16_t*)data = value.as<uint16_t>();
            return;
        case "System.UInt32"_fnv:
            *(uint32_t*)data = value.as<uint32_t>();
            return;
        case "System.Int32"_fnv:
            *(int32_t*)data = value.as<int32_t>();
            return;
        case "System.Int64"_fnv:
            *(int64_t*)data = value.as<int64_t>();
            return;
        case "System.UInt64"_fnv:
            *(int64_t*)data = value.as<int64_t>();
            return;
        case "via.Float2"_fnv: [[fallthrough]];
        case "via.vec2"_fnv:
            *(Vector2f*)data = value.as<Vector2f>();
            return;
        case "via.Float3"_fnv: [[fallthrough]];
        case "via.vec3"_fnv:
            *(Vector3f*)data = value.as<Vector3f>();
            return;
        case "via.Float4"_fnv: [[fallthrough]];
        case "via.vec4"_fnv:
            *(Vector4f*)data = value.as<Vector4f>();
            return;
        case "via.mat4"_fnv:
            *(Matrix4x4f*)data = value.as<Matrix4x4f>();
            return;
        case "via.Quaternion"_fnv:
            *(glm::quat*)data = value.as<glm::quat>();
            return;
        default:
            if (vm_obj_type > via::clr::VMObjType::NULL_ && vm_obj_type < via::clr::VMObjType::ValType) {
                REManagedObject* new_data;
                if (value.is<const char*>()) {
                    new_data = ::sdk::VM::create_managed_string(utility::widen(value.as<const char*>()));
                } else {
                    new_data = value.as<::REManagedObject*>();
                }

                REManagedObject** field = (REManagedObject**) data;
                if (field != nullptr && *field != new_data) {
                    if (new_data != nullptr) {
                        utility::re_managed_object::add_ref(new_data);
                    }

                    // Use a thread-safe atomic exchange. This is what Capcom does for all field assignments.
                    auto old = *field;
                    while (_InterlockedCompareExchangePointer((PVOID*)field, new_data, old) != old) {
                        old = *field;
                    }

                    if (old != nullptr) {
                        utility::re_managed_object::release(old);
                    }
                }

                return;
            }
        }
    }

    // A null void* will get converted into an userdata with value 0. That's not very useful in Lua, so
    // let's return nil instead since that's a much more usable value.
    if (data == nullptr || *(void**)data == nullptr) {
        return;
    }

    *(void**)data = value.as<void*>();
}

void set_native_field_from_field(lua_stack::object obj, ::sdk::RETypeDefinition* ty, ::sdk::REField* field, lua_stack::object value) {

    auto real_obj = get_real_obj(obj);
    bool managed_obj_passed = obj.is<REManagedObject*>();

    const auto field_type = field->get_type();

    if (!field->is_static() && !field_type->is_value_type() && real_obj == nullptr) {
        return;
    }

    auto data = field->get_data_raw(real_obj, ty->is_value_type() && !managed_obj_passed);

    if (data == nullptr) {
        return;
    }

    set_data(data, field_type, value);
}

void set_native_field(lua_State* s, lua_stack::object obj, ::sdk::RETypeDefinition* ty, const char* name, lua_stack::object value) {
    const auto field = ty->get_field(name);
    if (field == nullptr) {
        auto l = s;
        //throw lua_stack::error("Attempted to set invalid REManagedObject field:" + std::string(name));
        luaL_traceback(l, l, ("Attempted to set invalid REManagedObject field:" + std::string(name)).c_str(), 1);
        std::string traceback_err = lua_tostring(l, -1);
        lua_pop(l, 1);
        ScriptRunner::get()->spew_error(traceback_err); // allows us to log the error without failing script execution altogether.
        return;
    }
    return set_native_field_from_field(obj, ty, field, value);
}

lua_stack::object get_native_field_from_field(lua_stack::object obj, ::sdk::RETypeDefinition* ty, ::sdk::REField* field) {
    auto l = obj.lua_state();

    auto real_obj = get_real_obj(obj);
    bool managed_obj_passed = obj.is<REManagedObject*>();

    if (field == nullptr || (!field->is_static() && real_obj == nullptr)) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }

    const auto field_type = field->get_type();
    auto data = field->get_data_raw(real_obj, ty->is_value_type() && !managed_obj_passed);

    if (data == nullptr) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }

    return parse_data(l, data, field_type, false);
}

lua_stack::object get_native_field(lua_stack::object obj, ::sdk::RETypeDefinition* ty, const char* name) {
    auto l = obj.lua_state();
    const auto field = ty->get_field(name);

    if (field == nullptr) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }

    return get_native_field_from_field(obj, ty, field);
}

std::vector<void*>& build_args(lua_stack::variadic_args va) {
    auto l = va.lua_state();

    // thread_local so concurrent Lua callers can't clobber each other's
    // argument storage mid-invoke.
    static thread_local std::vector<void*> args{};
    static thread_local std::vector<Vector4f> vec_storage{};

    args.clear();
    vec_storage.clear();

    // Reserve up front: emplace_back below may otherwise reallocate vec_storage
    // (invalidating pointers already pushed into args) after the initial calls
    // that established its capacity.
    vec_storage.reserve(va.leftover_count());

    for (auto&& arg : va) {
        auto i = arg.stack_index();

        if (lua_isnil(l, i)) {
            args.push_back(nullptr);
            continue;
        }

        // sol2 doesn't seem to differentiate between Lua integers and numbers. So
        // we must do it ourselves.
        if (lua_isboolean(l, i)) {
            auto b = lua_toboolean(l, i);
            args.push_back((void*)(intptr_t)b);
        } else if (lua_type(l, i) == LUA_TSTRING) {
            // Raw type: lua_isnumber accepts a numeric string, so checking the
            // numbers first turned "42" into a double instead of a managed string.
            auto s = lua_tostring(l, i);
            args.push_back(::sdk::VM::create_managed_string(utility::widen(s)));
        } else if (lua_isinteger(l, i)) {
            auto n = (intptr_t)lua_tointeger(l, i);
            args.push_back((void*)n);
        } else if (lua_isnumber(l, i)) {
            auto f = lua_tonumber(l, i);
            auto n = *(intptr_t*)&f;
            args.push_back((void*)n);
        } else if (arg.is<Vector2f>()) {
            auto& v = arg.as<Vector2f&>();
            args.push_back((void*)&vec_storage.emplace_back(v.x, v.y, 0.0f, 0.0f));
        } else if (arg.is<Vector3f>()) {
            auto& v = arg.as<Vector3f&>();
            args.push_back((void*)&vec_storage.emplace_back(v.x, v.y, v.z, 0.0f));
        } else if (arg.is<Vector4f>()) {
            auto& v = arg.as<Vector4f&>();
            args.push_back((void*)&v);
        } else if (arg.is<Matrix4x4f>()) {
            auto& v = arg.as<Matrix4x4f&>();
            args.push_back((void*)&v);
        } else if (arg.is<glm::quat>()) {
            auto& v = arg.as<glm::quat&>();
            args.push_back((void*)&v);
        } else if (arg.is<::REManagedObject*>()) {
            args.push_back(arg.as<::REManagedObject*>());
        } else if (arg.is<ValueType>()) {
            auto& b = arg.as<ValueType&>();
            args.push_back((void*)b.address());
        } else {
            args.push_back(arg.as<void*>());
        }
    }

    return args;
}

lua_stack::object call_native_func_direct(lua_stack::object obj, ::sdk::REMethodDefinition* fn, lua_stack::variadic_args va) {
    auto l = va.lua_state();
    auto ret_ty = fn->get_return_type();

    if (ret_ty == nullptr) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }

    auto real_obj = get_real_obj(obj);
    auto ret_val = fn->invoke(real_obj, build_args(va));

    if (ret_val.exception_thrown) {
        throw lua_stack::error("Invoke threw an exception");
    }

    return parse_data(l, &ret_val, ret_ty, true);
}

lua_stack::object call_native_func(lua_stack::object obj, ::sdk::RETypeDefinition* ty, const char* name, lua_stack::variadic_args va) {
    auto l = va.lua_state();
    
    // Convert return values to the correct Lua types.
    auto fn = ty->get_method(name);

    if (fn == nullptr) {
        return lua_stack::make_object(l, lua_stack::lua_nil);
    }
    return call_native_func_direct(obj, fn, va);
}

auto call_object_func(lua_stack::object obj, const char* name, lua_stack::variadic_args va) {
    auto real_obj = get_real_obj(obj);

    if (real_obj == nullptr) {
        return lua_stack::make_object(obj.lua_state(), lua_stack::lua_nil);
    }

    auto def = utility::re_managed_object::get_type_definition((::REManagedObject*)real_obj);

    if (def == nullptr) {
        return lua_stack::make_object(obj.lua_state(), lua_stack::lua_nil);
    }

    return call_native_func(obj, def, name, va);
}

lua_stack::object get_primary_camera(lua_State* s) {
    return lua_stack::make_object(s, (::REManagedObject*)::sdk::get_primary_camera());
}

bool is_managed_object(lua_stack::object obj) {
    auto real_obj = get_real_obj(obj);

    if (real_obj == nullptr) {
        return false;
    }

    return utility::re_managed_object::is_managed_object(real_obj);
}

void hook(lua_State* s, ::sdk::REMethodDefinition* fn, lua_stack::protected_function pre_cb, lua_stack::protected_function post_cb, lua_stack::object ignore_jmp_object) {
    auto state = lua_stack::registry_get<ScriptState*>(s, "state");
    state->add_hook(fn, pre_cb, post_cb, ignore_jmp_object);
}

void hook_vtable(lua_State* s, ::REManagedObject* obj, ::sdk::REMethodDefinition* fn, lua_stack::protected_function pre_cb, lua_stack::protected_function post_cb) {
    if (obj == nullptr) {
        throw lua_stack::error("Object is null");
        return;
    }
    
    auto state = lua_stack::registry_get<ScriptState*>(s, "state");
    state->add_vtable(obj, fn, pre_cb, post_cb);
}
}

namespace api::re_managed_object {
lua_stack::object index(lua_State* s, lua_stack::object lua_obj, lua_stack::variadic_args args);
void new_index(lua_State* s, lua_stack::object lua_obj, lua_stack::variadic_args args);
// Reads a SystemArray slot key, refusing anything that is not a number inside
// the array: sol2's implicit conversions otherwise let a fractional or
// out-of-bounds key reach get_element/set_element.
int32_t checked_array_index(lua_State* s, int index, ::sdk::SystemArray* arr);
}

namespace api::re_managed_object {
lua_stack::object index(lua_State* s, lua_stack::object lua_obj, lua_stack::variadic_args args) {
    auto obj = lua_obj.as<REManagedObject*>();
    if (obj == nullptr) {
        throw lua_stack::error("Attempted to index invalid REManagedObject");
    }
    auto index = args[0];

    auto type_def = utility::re_managed_object::get_type_definition(obj);
    if (type_def == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }
    std::string name;
    if (index.is<const char*>()) {
        name = index.as<const char*>();
        auto field = type_def->get_field(name.c_str());
        if (field != nullptr) {
            return api::sdk::get_native_field_from_field(lua_obj, type_def, field);
        }
        auto method = type_def->get_method(name.c_str());
        if (method != nullptr) {
            return lua_stack::make_object(s, method);
        }
    }

    if (auto fn = type_def->get_method("get_Item"); fn != nullptr) {
        try {
            const auto params = fn->get_param_types();

            if (!params.empty()) {
                static auto system_object = sdk::find_type_definition("System.Object");
                static auto system_string = sdk::find_type_definition("System.String");

                const auto first_param = params[0];

                // If it's a System.Object it's always okay, our arg will get auto converted.
                if (first_param != nullptr && first_param != system_object) {
                    if (index.is<const char*>()) {
                        if (first_param != system_string) {
                            return lua_stack::make_object(s, lua_stack::lua_nil);
                        }
                    }
                }
            }

            return ::api::sdk::call_native_func_direct(lua_obj, fn, args);
        } catch (...) {
            
        }
    }

    //throw lua_stack::error("Attempted to index invalid REManagedObject field: " + name);
    return lua_stack::make_object(s, lua_stack::lua_nil);
}

int32_t checked_array_index(lua_State* s, int index, ::sdk::SystemArray* arr) {
    if (lua_type(s, index) != LUA_TNUMBER) {
        throw lua_stack::error("Array index must be a number");
    }

    const auto d = lua_tonumber(s, index);

    if (d != (double)(int64_t)d) {
        throw lua_stack::error("Array index must be an integer");
    }

    if (d < 0.0 || d >= (double)arr->get_size()) {
        throw lua_stack::error("Array index out of range: " + std::to_string((int64_t)d));
    }

    return (int32_t)d;
}

void new_index(lua_State* s, lua_stack::object lua_obj, lua_stack::variadic_args args) {
    auto obj = lua_obj.as<REManagedObject*>();
    if (obj == nullptr) {
        throw lua_stack::error("Attempted to new_index invalid REManagedObject");
    }

    auto index = args[0];
    auto assign = args[1];

    auto type_def = utility::re_managed_object::get_type_definition(obj);
    if (type_def == nullptr) {
        return;
    }
    std::string name;
    if (index.is<const char*>()) {
        name = index.as<const char*>();
        auto field = type_def->get_field(name.c_str());

        if (field != nullptr) {
            return api::sdk::set_native_field_from_field(lua_obj, type_def, field, assign.get<lua_stack::object>());
        }
    }

    if (auto fn = type_def->get_method("set_Item"); fn != nullptr) {
        const auto params = fn->get_param_types();

        if (!params.empty()) {
            static auto system_object = sdk::find_type_definition("System.Object");
            static auto system_string = sdk::find_type_definition("System.String");
            
            const auto first_param = params[0];

            // If it's a System.Object it's always okay, our arg will get auto converted.
            if (first_param != nullptr && first_param != system_object) {
                if (index.is<const char*>()) {
                    if (first_param != system_string) {
                        throw lua_stack::error("Attempted to new_index invalid REManagedObject field: " + name);
                    }
                }
            }
        }

        ::api::sdk::call_native_func_direct(lua_obj, fn, args);
        return;
    }

    // System.Int32 -> object
    if (auto set_method = type_def->get_method("Set"); set_method != nullptr) {
        static auto system_int32 = sdk::find_type_definition("System.Int32");
        const auto params = set_method->get_param_types();

        if (params.size() == 2 && params[0] == system_int32) {
            if (type_def->is_array()) {
                checked_array_index(s, index.stack_index(), static_cast<::sdk::SystemArray*>(obj));

                // Reject type-confused raw writes (a string into a value element
                // would store the managed string's pointer bits). Dispatch on the
                // real Lua type: is<const char*>/is<double> are true for both.
                const auto elem_type = params[1];

                if (elem_type != nullptr) {
                    const auto lua_t = lua_type(s, assign.stack_index());
                    const auto is_string = lua_t == LUA_TSTRING;
                    const auto is_number = lua_t == LUA_TNUMBER || lua_t == LUA_TBOOLEAN;

                    if (elem_type->is_value_type() && is_string) {
                        throw lua_stack::error("Cannot assign a string to a " + elem_type->get_full_name() + " element");
                    }

                    if (!elem_type->is_value_type() && is_number) {
                        throw lua_stack::error("Cannot assign a number to a " + elem_type->get_full_name() + " element");
                    }
                }
            }

            ::api::sdk::call_native_func_direct(lua_obj, set_method, args);
            return;
        }
    }

    throw lua_stack::error("Attempted to new_index invalid REManagedObject field: " + name);
}

bool is_valid_offset(::REManagedObject* obj, int32_t offset) {
    if (obj == nullptr || !::utility::re_managed_object::is_managed_object(obj)) {
        return false;
    }

    const auto typedefinition = ::utility::re_managed_object::get_type_definition(obj);

    if (typedefinition == nullptr) {
        return false;
    }

    auto size = typedefinition->get_size();

    if (typedefinition->is_array()) {
        size = utility::re_managed_object::get_size(obj);
    }

    // trying to limit the impact of this function.
    if (offset < -0x1000 || (uint32_t)offset >= size) {
        return false;
    }

    return true;
}

template <typename T>
void write_memory(::REManagedObject* obj, int32_t offset, T value) {
    if (!is_valid_offset(obj, offset)) {
        return;
    }

    *(T*)((uintptr_t)obj + offset) = value;
}

template <typename T>
T read_memory(::REManagedObject* obj, int32_t offset) {
    if (!is_valid_offset(obj, offset)) {
        return 0;
    }

    return *(T*)((uintptr_t)obj + offset);
}
}

// Members whose body is more than a direct member pointer call.
LUA_HAND_FUNC(sdk_hand_type_definition_get_methods)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    std::vector<::sdk::REMethodDefinition*> methods{};

    for (auto& method : def->get_methods()) {
        const auto func = method.get_function();

        if (func == nullptr) {
            continue;
        }

        if (utility::is_stub_code((uint8_t*)func)) {
            continue;
        }

        methods.push_back(&method);
    }

    lh::put_seq(L, methods);
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_get_fields)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    std::vector<::sdk::REField*> fields{};

    for (auto field : def->get_fields()) {
        fields.push_back(field);
    }

    lh::put_seq(L, fields);
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_get_properties)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    std::vector<::sdk::REProperty*> properties{};

    for (auto& prop : def->get_properties()) {
        properties.push_back(&prop);
    }

    lh::put_seq(L, properties);
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_is_a)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    bool result = false;

    if (lh::is<::sdk::RETypeDefinition*>(L, 2)) {
        result = def->is_a(lh::get<::sdk::RETypeDefinition*>(L, 2));
    } else if (lh::is_str(L, 2)) {
        result = def->is_a(std::string_view{lua_tostring(L, 2)});
    }

    lua_pushboolean(L, result);
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_create_instance)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    return lh::put(L, def->create_instance_full(lh::opt_bool(L, 2, false)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_create_instance_gc_safe)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    return lh::put(L, ::api::sdk::create_global_object(L, def->create_instance_full()));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_type_definition_get_vm_obj_type)
    auto def = lh::get_self<::sdk::RETypeDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "RETypeDefinition is nil");
    }

    // via::clr::VMObjType is not registered as a Lua type, so it stays an int.
    return lh::put(L, (int)def->get_vm_obj_type());
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_method_call)
    auto def = lh::get_self<::sdk::REMethodDefinition>(L);

    if (def == nullptr) {
        return luaL_error(L, "REMethodDefinition is nil");
    }

    auto obj = lh::get_object(L, 2);
    lua_stack::variadic_args va{L, 3};

    auto real_obj = ::api::sdk::get_real_obj(obj);
    auto ret_val = def->invoke(real_obj, ::api::sdk::build_args(va));

    if (ret_val.exception_thrown) {
        throw lua_stack::error("Invoke threw an exception");
    }

    // Convert return values to the correct Lua types.
    auto ret_ty = def->get_return_type();

    return lh::put(L, ::api::sdk::parse_data(L, &ret_val, ret_ty, true));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_field_get_data)
    auto field = lh::get_self<::sdk::REField>(L);

    if (field == nullptr) {
        return luaL_error(L, "REField is nil");
    }

    auto obj = lh::get_object(L, 2);

    if (lh::is<::REManagedObject*>(L, 2)) {
        auto managed_obj = lh::get<::REManagedObject*>(L, 2);

        if (managed_obj == nullptr) {
            lua_pushnil(L);
            return 1;
        }

        auto ty = utility::re_managed_object::get_type_definition(managed_obj);

        if (ty == nullptr) {
            lua_pushnil(L);
            return 1;
        }

        return lh::put(L, ::api::sdk::get_native_field_from_field(obj, ty, field));
    }

    auto ty = field->get_declaring_type();

    if (ty == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, ::api::sdk::get_native_field_from_field(obj, ty, field));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_resource_add_ref)
    auto res = lh::get_self<::sdk::Resource>(L);

    if (res == nullptr) {
        return luaL_error(L, "REResource is nil");
    }

    res->add_ref();
    lua_pushvalue(L, 1);
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_resource_get_address)
    auto res = lh::get_self<::sdk::Resource>(L);

    if (res == nullptr) {
        return luaL_error(L, "REResource is nil");
    }

    return lh::put(L, (uintptr_t)res);
LUA_HAND_CATCH(L)

static int sdk_hand_managed_object_index(lua_State* L);

// sol2's SystemArray __index reads an integer key through get_element, which
// boxes the element -- value types included -- and sends every other key to
// the type database.
LUA_HAND_FUNC(sdk_hand_system_array_index)
    auto arr = lh::get_self<::sdk::SystemArray>(L);

    if (arr == nullptr) {
        return luaL_error(L, "SystemArray is nil");
    }

    if (lua_type(L, 2) == LUA_TNUMBER) {
        // Fractional and out-of-range keys read as nil instead of reaching
        // get_element, which would truncate or walk past the array.
        const auto d = lua_tonumber(L, 2);

        if (d != (double)(int64_t)d || d < 0.0 || d >= (double)arr->get_size()) {
            lua_pushnil(L);
            return 1;
        }

        return lh::put(L, arr->get_element((int32_t)d));
    }

    return sdk_hand_managed_object_index(L);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_system_array_new_index)
    auto arr = lh::get_self<::sdk::SystemArray>(L);

    if (arr == nullptr) {
        return luaL_error(L, "SystemArray is nil");
    }

    if (lua_type(L, 2) == LUA_TNUMBER && lh::is<::REManagedObject*>(L, 3)) {
        arr->set_element(::api::re_managed_object::checked_array_index(L, 2, arr), lh::get<::REManagedObject*>(L, 3));
        return 0;
    }

    // The key belongs in the variadic args: new_index reads args[0] as the key
    // and args[1] as the value, so the tail must start at the key, not past it.
    ::api::re_managed_object::new_index(L, lh::get_object(L, 1), lh::get_rest(L, 2));
    return 0;
LUA_HAND_CATCH(L)

// The iterator of the __pairs triple: f(state, key) walks the live array, and
// __pairs itself returns iterator, state and initial key -- Lua 5.4 reads three
// values back, so the trailing nil cannot be left to the stack top.
LUA_HAND_FUNC(sdk_hand_system_array_next)
    auto arr = lh::get_self<::sdk::SystemArray>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    lh::put(L, arr->get_element(i));

    return 2;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_system_array_pairs)
    if (lh::get_self<::sdk::SystemArray>(L) == nullptr) {
        return luaL_error(L, "SystemArray is nil");
    }

    lua_pushcfunction(L, &sdk_hand_system_array_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_delegate_add)
    ::api::delegate::add_lua_delegate(L, lh::get_self<::sdk::Delegate>(L), lh::num_uint(L, 2),
        lh::get<lua_stack::protected_function>(L, 3));

    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_delegate_new_index)
    auto delegate = lh::get_self<::sdk::Delegate>(L);

    if (delegate == nullptr) {
        return luaL_error(L, "Delegate is nil");
    }

    ::api::delegate::new_index(L, delegate, lh::get_object(L, 2), lh::get_rest(L, 3));

    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_index)
    // The type table `ValueType` reaches this through the metatable it shares
    // with an instance, and a table is not a value sol2 converted to a
    // ValueType* -- an unknown key off the type table read as nil there.
    if (lua_type(L, 1) != LUA_TUSERDATA) {
        lua_pushnil(L);
        return 1;
    }

    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        return luaL_error(L, "ValueType is nil");
    }

    return lh::put(L, self->index(L, lh::str(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_new_index)
    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        return luaL_error(L, "ValueType is nil");
    }

    self->new_index(L, lh::str(L, 2), lh::get_object(L, 3));

    return 0;
LUA_HAND_CATCH(L)

// The __call of ValueType: `ValueType(retype)` builds a value the state owns,
// which is what constructors<ValueType(RETypeDefinition*)> did under sol2.
LUA_HAND_FUNC(sdk_hand_value_type_construct)
    auto type = lh::get<::sdk::RETypeDefinition*>(L, 1);

    void* storage = lua_newuserdatauv(L, sizeof(api::sdk::ValueType), 0);
    new (storage) api::sdk::ValueType(type);

    luaL_getmetatable(L, lua_stack::unique_metatable<api::sdk::ValueType>().c_str());
    lua_setmetatable(L, -2);

    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_call)
    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        return luaL_error(L, "ValueType is nil");
    }

    return lh::put(L, self->call(L, lh::str(L, 2), lh::get_rest(L, 3)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_get_field)
    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        return luaL_error(L, "ValueType is nil");
    }

    return lh::put(L, self->get_field(L, lh::str(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_set_field)
    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        return luaL_error(L, "ValueType is nil");
    }

    self->set_field(L, lh::str(L, 2), lh::get_object(L, 3));

    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_value_type_get_type_definition)
    auto self = lh::get_self<::api::sdk::ValueType>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, self->type);
LUA_HAND_CATCH(L)

// __pairs hands out the iteration function before it is defined.
static int sdk_hand_dyn_u32arr_next(lua_State* L);
static int sdk_hand_dyn_tn_next(lua_State* L);
static int sdk_hand_dyn_tnd_next(lua_State* L);
static int sdk_hand_dyn_u8_next(lua_State* L);
static int sdk_hand_dyn_i32_next(lua_State* L);
static int sdk_hand_dyn_u32_next(lua_State* L);

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_u32arr is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_u32arr is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    (*arr)[i] = lh::get<uint32_t>(L, 3);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr || lh::is_none(L, 2)) {
        return 0;
    }

    uint32_t value = lh::get<uint32_t>(L, 2);
    arr->push_back(value);

    return 0;
LUA_HAND_CATCH(L)

static int sdk_hand_dyn_mo_pairs(lua_State* L);

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_u32arr_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    lh::put(L, (*arr)[i]);

    return 2;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32arr_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<uint32_t>)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_tn is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_tn is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put_borrowed(L, &(*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    const auto* element = lh::get_arg<::sdk::behaviortree::TreeNode>(L, 3, "BehaviorTreeNode");

    if (element == nullptr) {
        return 0;
    }

    (*arr)[i] = *element;
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    auto value = lh::get_arg<::sdk::behaviortree::TreeNode>(L, 2, "BehaviorTreeNode");

    if (arr == nullptr || value == nullptr) {
        return 0;
    }

    arr->push_back(*value);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_tn_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    lh::put_borrowed(L, &(*arr)[i]);

    return 2;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tn_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_tnd is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_tnd is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put_borrowed(L, &(*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    const auto* element = lh::get_arg<::sdk::behaviortree::TreeNodeData>(L, 3, "BehaviorTreeNodeData");

    if (element == nullptr) {
        return 0;
    }

    (*arr)[i] = *element;
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    auto value = lh::get_arg<::sdk::behaviortree::TreeNodeData>(L, 2, "BehaviorTreeNodeData");

    if (arr == nullptr || value == nullptr) {
        return 0;
    }

    arr->push_back(*value);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_tnd_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    lh::put_borrowed(L, &(*arr)[i]);

    return 2;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_tnd_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>)));
LUA_HAND_CATCH(L)
LUA_HAND_FUNC(sdk_hand_dyn_u8_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_u8 is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_u8 is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    (*arr)[i] = lh::get<uint8_t>(L, 3);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr || lh::is_none(L, 2)) {
        return 0;
    }

    uint8_t value = lh::get<uint8_t>(L, 2);
    arr->push_back(value);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_u8_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u8_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint8_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<uint8_t>)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_i32 is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_i32 is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    (*arr)[i] = lh::get<int32_t>(L, 3);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr || lh::is_none(L, 2)) {
        return 0;
    }

    int32_t value = lh::get<int32_t>(L, 2);
    arr->push_back(value);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_i32_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_i32_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<int32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<int32_t>)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_size)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_len)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "dyn_u32 is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "dyn_u32 is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_new_index)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr || !lh::is_index(L, 2) || lh::is_none(L, 3)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    (*arr)[i] = lh::get<uint32_t>(L, 3);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_push_back)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr || lh::is_none(L, 2)) {
        return 0;
    }

    uint32_t value = lh::get<uint32_t>(L, 2);
    arr->push_back(value);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_pairs)
    if (lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_u32_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_next)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, i);
    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_clear)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear(lh::opt_bool(L, 2, false));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_u32_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArrayNoCapacity<uint32_t>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArrayNoCapacity<uint32_t>)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_size)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

static int sdk_hand_dyn_mo_next(lua_State* L);

LUA_HAND_FUNC(sdk_hand_dyn_mo_pairs)
    if (lh::get_self<sdk::NativeArray<::REManagedObject*>>(L) == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushcfunction(L, &sdk_hand_dyn_mo_next);
    lua_pushvalue(L, 1);
    lua_pushnil(L);

    return 3;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_next)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    const uint32_t i = lh::is_none(L, 2) ? 0 : static_cast<uint32_t>(lua_tointeger(L, 2)) + 1;

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(i));
    return lh::put(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_len)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, static_cast<lua_Integer>(arr->size()));
    return 1;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_index)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        return luaL_error(L, "DynamicArrayManagedObject is nil");
    }

    if (!lh::is_index(L, 2)) {
        return luaL_error(L, "DynamicArrayManagedObject is indexed by an integer");
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put_borrowed(L, (*arr)[i]);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_new_index)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr || !lh::is_index(L, 2)) {
        return 0;
    }

    const uint32_t i = lh::index_uint(L, 2);

    if (i >= arr->size()) {
        return 0;
    }

    (*arr)[i] = lh::get<::REManagedObject*>(L, 3);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_push_back)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        return 0;
    }

    ::REManagedObject* value = lh::get_arg<::REManagedObject>(L, 2, "REManagedObject");

    // push_back takes T&, so write through the slot emplace returns instead of
    // handing it a temporary.
    arr->emplace() = value;
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_clear)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        return 0;
    }

    arr->clear();
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_dyn_mo_as_memoryview)
    auto arr = lh::get_self<sdk::NativeArray<::REManagedObject*>>(L);

    if (arr == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(arr), sizeof(sdk::NativeArray<::REManagedObject*>)));
LUA_HAND_CATCH(L)

// The wide-string accessors cannot go through a member thunk, because sol2
// converted std::wstring_view to a UTF-8 Lua string and a raw read would push
// a usertype. These repeat the conversion explicitly.
LUA_HAND_FUNC(sdk_hand_tnd_get_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeNodeData>(L);

    if (self == nullptr) {
        lua_pushstring(L, "");
        return 1;
    }

    return lh::put(L, utility::narrow(self->get_name()));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tnd_set_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeNodeData>(L);

    if (self == nullptr) {
        return 0;
    }

    self->set_name(utility::widen(lh::str(L, 2)));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_get_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        lua_pushstring(L, "");
        return 1;
    }

    return lh::put(L, utility::narrow(self->get_name()));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_set_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        return 0;
    }

    self->set_name(utility::widen(lh::str(L, 2)));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_get_full_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        lua_pushstring(L, "");
        return 1;
    }

    return lh::put(L, utility::narrow(self->get_full_name()));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_get_selector)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put_borrowed<::REManagedObject>(L, reinterpret_cast<::REManagedObject*>(self->get_selector()));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_to_get_node_by_name)
    auto self = lh::get_self<::sdk::behaviortree::TreeObject>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put_borrowed(L, self->get_node_by_name(lh::str(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tnd_as_memoryview)
    auto self = lh::get_self<::sdk::behaviortree::TreeNodeData>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(self), sizeof(::sdk::behaviortree::TreeNodeData)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_as_memoryview)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(self), sizeof(::sdk::behaviortree::TreeNode)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tod_as_memoryview)
    auto self = lh::get_self<::sdk::behaviortree::TreeObjectData>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(self), sizeof(::sdk::behaviortree::TreeObjectData)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_to_as_memoryview)
    auto self = lh::get_self<::sdk::behaviortree::TreeObject>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, api::sdk::MemoryView(reinterpret_cast<uint8_t*>(self), sizeof(::sdk::behaviortree::TreeObject)));
LUA_HAND_CATCH(L)

// to_valuetype hands back a copy of the live structure, which is the value
// semantics the sol2 binding had.
LUA_HAND_FUNC(sdk_hand_tnd_to_valuetype)
    auto self = lh::get_self<::sdk::behaviortree::TreeNodeData>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, *self);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tn_to_valuetype)
    auto self = lh::get_self<::sdk::behaviortree::TreeNode>(L);

    if (self == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    return lh::put(L, *self);
LUA_HAND_CATCH(L)

// REManagedObject and every type derived from it route field access through
// the type database instead of their member table, so the receiver arrives as
// an ordinary lua_stack::object and the trailing arguments as lua_stack::variadic_args.
LUA_HAND_FUNC(sdk_hand_managed_object_index)
    return lh::put(L, ::api::re_managed_object::index(L, lh::get_object(L, 1), lh::get_rest(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_new_index)
    ::api::re_managed_object::new_index(L, lh::get_object(L, 1), lh::get_rest(L, 2));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_add_ref)
    return lh::put(L, ::api::re_managed_object::add_ref(L, lh::get_self<::REManagedObject>(L)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_add_ref_permanent)
    return lh::put(L, ::api::re_managed_object::add_ref_permanent(L, lh::get_self<::REManagedObject>(L)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_force_release)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return 0;
    }

    ::api::re_managed_object::release(L, obj, true);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_release)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return 0;
    }

    ::api::re_managed_object::release(L, obj, false);
    return 0;
LUA_HAND_CATCH(L)

// The metatable __gc sol2 installed through a Lua snippet: drop the reference
// this state added, without forcing a release the game did not ask for.
LUA_HAND_FUNC(sdk_hand_managed_object_gc)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return 0;
    }

    ::api::re_managed_object::release(L, obj, false);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_deserialize_native)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return 0;
    }

    auto data_obj = lh::get_object(L, 2);

    if (!data_obj.is<std::vector<uint8_t>>()) {
        throw lua_stack::error("Data must be a vector of bytes");
    }

    auto data = data_obj.as<std::vector<uint8_t>>();
    std::vector<::REManagedObject*> objects{};

    if (lh::is_table(L, 3)) {
        const auto count = (lua_Integer)lua_rawlen(L, 3);

        for (lua_Integer i = 1; i <= count; ++i) {
            lua_rawgeti(L, 3, i);
            objects.push_back(lh::get<::REManagedObject*>(L, -1));
            lua_pop(L, 1);
        }
    }

    ::utility::re_managed_object::deserialize_native(obj, data.data(), data.size(), objects);
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_get_reference_count)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return luaL_error(L, "REManagedObject is nil");
    }

    return lh::put(L, (int32_t)obj->referenceCount);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_get_address)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return luaL_error(L, "REManagedObject is nil");
    }

    return lh::put(L, (uintptr_t)obj);
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_get_type_definition)
    return lh::put(L, ::utility::re_managed_object::get_type_definition(lh::get_self<::REManagedObject>(L)));
LUA_HAND_CATCH(L)

// Field access on a null receiver answers nil rather than failing, which is
// what the sol2 lambdas did before the type definition was ever looked up.
LUA_HAND_FUNC(sdk_hand_managed_object_get_field)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return lh::put(L, lua_stack::lua_nil);
    }

    return lh::put(L, ::api::sdk::get_native_field(lua_stack::make_object(L, obj), ::utility::re_managed_object::get_type_definition(obj),
                                                  lh::str(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_set_field)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return 0;
    }

    ::api::sdk::set_native_field(L, lua_stack::make_object(L, obj), ::utility::re_managed_object::get_type_definition(obj),
                                lh::str(L, 2), lh::get_object(L, 3));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_managed_object_call)
    auto obj = lh::get_self<::REManagedObject>(L);

    if (obj == nullptr) {
        return lh::put(L, lua_stack::lua_nil);
    }

    return lh::put(L, ::api::sdk::call_object_func(lua_stack::make_object(L, obj), lh::str(L, 2), lh::get_rest(L, 3)));
LUA_HAND_CATCH(L)

// sol2 installs no __gc on a pointer metatable, so the reference drop is added
// explicitly for every type pushed as a managed object pointer.
void install_managed_gc(lua_State* L, const std::string& metatable) {
    luaL_getmetatable(L, metatable.c_str());
    lua_pushcfunction(L, &sdk_hand_managed_object_gc);
    lua_setfield(L, -2, "__gc");
    lua_pop(L, 1);
}

LUA_HAND_FUNC(sdk_hand_apply_joints_tpose)
    auto t = lh::get_self<::RETransform>(L);

    if (t == nullptr) {
        return 0;
    }

    if (!lh::is_table(L, 2)) {
        throw lua_stack::error("RETransform:apply_joints_tpose expected a table of joints");
    }

    std::vector<::REJoint*> joints{};

    const auto count = (lua_Integer)lua_rawlen(L, 2);
    for (lua_Integer i = 1; i <= count; ++i) {
        lua_rawgeti(L, 2, i);
        joints.push_back((::REJoint*)lh::get<::REManagedObject*>(L, -1));
        lua_pop(L, 1);
    }

    ::utility::re_transform::apply_joints_tpose(*t, joints, lh::opt_uint(L, 3, 0));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_transform_hook_update)
    auto transform = lh::get_self<::RETransform>(L);

    if (transform == nullptr) {
        return 0;
    }

    auto state = lua_stack::registry_get<ScriptState*>(L, "state");
    state->add_update_transform(transform, lh::get<lua_stack::protected_function>(L, 2));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_get_tree_object)
    auto handle = lh::get_self<::api::sdk::BehaviorTreeCoreHandle>(L);

    if (handle == nullptr) {
        return 0;
    }

    return lh::put(L, ((sdk::behaviortree::CoreHandle*)handle)->get_tree_object());
LUA_HAND_CATCH(L)

// The node array is borrowed from the caller: NativeArrayNoCapacity owns its
// elements and frees them on destruction, so the thunk passes the Lua userdata
// through by reference and never copies it.
LUA_HAND_FUNC(sdk_hand_core_handle_relocate)
    auto handle = lh::get_self<::api::sdk::BehaviorTreeCoreHandle>(L);

    if (handle == nullptr) {
        return 0;
    }

    ((sdk::behaviortree::CoreHandle*)handle)
        ->relocate(lh::get<uintptr_t>(L, 2), lh::get<uintptr_t>(L, 3), lh::get_arg_ref<sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNode>>(L, 4, "DynamicArrayNoCapacityTreeNode"));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_core_handle_relocate_datas)
    auto handle = lh::get_self<::api::sdk::BehaviorTreeCoreHandle>(L);

    if (handle == nullptr) {
        return 0;
    }

    ((sdk::behaviortree::CoreHandle*)handle)
        ->relocate_datas(lh::get<uintptr_t>(L, 2), lh::get<uintptr_t>(L, 3),
                         lh::get_arg_ref<sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNodeData>>(L, 4, "DynamicArrayNoCapacityTreeNodeData"));
    return 0;
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tree_get_tree)
    auto tree = lh::get_self<::api::sdk::BehaviorTree>(L);

    if (tree == nullptr) {
        return 0;
    }

    return lh::put(L, ((sdk::behaviortree::BehaviorTree*)tree)->get_tree<::api::sdk::BehaviorTreeCoreHandle>(lh::num_uint(L, 2)));
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tree_get_tree_count)
    auto tree = lh::get_self<::api::sdk::BehaviorTree>(L);

    if (tree == nullptr) {
        return 0;
    }

    return lh::put(L, ((sdk::behaviortree::BehaviorTree*)tree)->get_tree_count());
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(sdk_hand_tree_get_trees)
    auto tree = lh::get_self<::api::sdk::BehaviorTree>(L);

    if (tree == nullptr) {
        return 0;
    }

    lh::put_seq(L, ((sdk::behaviortree::BehaviorTree*)tree)->get_trees<::api::sdk::BehaviorTreeCoreHandle>());
    return 1;
LUA_HAND_CATCH(L)

// sol2 registered size as the data member it is, so reading it hands back the
// number itself and calling it fails the way calling any number fails. The
// member table only carries the methods, so the read falls to this index
// fallback.
static int sdk_hand_memoryview_index(lua_State* L) {
    if (std::strcmp(lh::opt_str(L, 2, ""), "size") == 0) {
        auto* self = lh::get_arg<api::sdk::MemoryView>(L, 1, "MemoryView");

        if (self == nullptr) {
            return luaL_error(L, "attempt to call a method on a nil usertype object");
        }

        lua_pushinteger(L, static_cast<lua_Integer>(self->size));
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

namespace {
int sdk_get_tdb_version() {
    return sdk::RETypeDB::get()->version;
}

lua_stack::object sdk_to_managed_object(lua_State* s, lua_stack::object ptr) {
    if (ptr.is<::REManagedObject*>()) {
        // no need to convert to managed object.
        return lua_stack::make_object(s, ptr.as<::REManagedObject*>());
    } else if (ptr.is<uintptr_t>()) {
        return lua_stack::make_object(s, (::REManagedObject*)ptr.as<uintptr_t>());
    } else if (ptr.is<void*>()) {
        return lua_stack::make_object(s, (::REManagedObject*)ptr.as<void*>());
    }

    // the object passed was not a managed object, uintptr_t, or void*.
    return lua_stack::make_object(s, lua_stack::lua_nil);
}

lua_stack::object sdk_to_valuetype(lua_State* s, lua_stack::object ptr, lua_stack::object type) {
    if (ptr.is<api::sdk::ValueType>()) {
        return ptr;
    }

    ::sdk::RETypeDefinition* ty = nullptr;

    if (type.is<::sdk::RETypeDefinition*>()) {
        ty = type.as<::sdk::RETypeDefinition*>();
    } else if (type.is<const char*>()) {
        ty = api::sdk::find_type_definition(type.as<const char*>());
    }

    if (ty == nullptr || !ty->is_value_type()) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    void* addr = nullptr;

    if (ptr.is<uintptr_t>()) {
        addr = (void*)ptr.as<uintptr_t>();
    } else if (ptr.is<void*>()) {
        addr = ptr.as<void*>();
    }

    if (addr == nullptr) {
        return lua_stack::make_object(s, lua_stack::lua_nil);
    }

    return lua_stack::make_object(s, api::sdk::ValueType{ty, addr});
}

lua_stack::table sdk_deserialize(lua_State* s, lua_stack::object data_obj) {
    if (!data_obj.is<std::vector<uint8_t>>()) {
        throw lua_stack::error("Data must be a vector of bytes");
    }

    auto data = data_obj.as<std::vector<uint8_t>>();
    auto result = ::utility::re_managed_object::deserialize(data.data(), data.size(), false);

    // Explicitly create a lua table so we know for certain we are
    // pushing the REManagedObjects to the stack, adding a reference to them.
    auto final_result = lua_stack::create_table(s);

    for (auto obj : result) {
        const auto index = static_cast<lua_Integer>(final_result.size()) + 1;
        final_result.set(index, obj);
    }

    return final_result;
}

::sdk::Resource* sdk_to_resource(void* ptr) {
    return (::sdk::Resource*)ptr;
}

double sdk_to_double(void* ptr) {
    return *(double*)&ptr;
}

float sdk_to_float(void* ptr) {
    return *(float*)&ptr;
}

int64_t sdk_to_int64(void* ptr) {
    return *(int64_t*)&ptr;
}

void* sdk_to_ptr(lua_stack::object obj) {
    if (obj.is<int64_t>()) {
        const auto n = obj.as<int64_t>();
        return *(void**)&n;
    } else if (obj.is<::REManagedObject*>()) {
        return (void*)obj.as<::REManagedObject*>();
    } else if (obj.is<double>()) {
        const auto n = obj.as<double>();
        return *(void**)&n;
    } else if (obj.is<bool>()) {
        const auto n = (uintptr_t)obj.as<bool>();
        return *(void**)&n;
    }

    return obj.as<void*>();
}

void* sdk_float_to_ptr(float f) {
    // Read only the 4 bytes of the float, then zero-extend to pointer width.
    // Reinterpreting as uintptr_t directly would read 8 bytes from a 4-byte
    // value (OOB on the stack).
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));
    return (void*)(uintptr_t)bits;
}

api::sdk::MemoryView sdk_to_memoryview(uintptr_t addr, size_t size) {
    return api::sdk::MemoryView((uint8_t*)addr, size);
}

// game_namespace is a free function, which the table cannot hold as a value;
// the wrapper gives it a signature a thunk can marshal.
std::string sdk_game_namespace(std::string base_name) {
    return game_namespace(base_name);
}
} // namespace

void bindings::open_sdk(ScriptState* s) {
    auto& lua = s->lua();
    lua_State* L = lua.lua_state();

    //lua_stack::global_table(L, "_sol_lua_push_objects") = ...;
    lua.do_string(R"(
        _sol_lua_push_objects = setmetatable({}, { __mode = "v" })
        _sol_lua_push_usertypes = {}
        _sol_lua_push_ref_counts = {}
        _sol_lua_push_ephemeral_counts = {}
    )");

    auto sdk = lua.create_table();
    sdk.set_cfunction("get_tdb_version", lh::fthunk<&sdk_get_tdb_version>);
    sdk.set_cfunction("game_namespace", lh::fthunk<&sdk_game_namespace>);
    sdk.set_cfunction("get_thread_context", lh::fthunk<&api::sdk::get_thread_context>);
    sdk.set_cfunction("get_native_singleton", lh::fthunk<&api::sdk::get_native_singleton>);
    sdk.set_cfunction("get_managed_singleton", lh::fthunk<&api::sdk::get_managed_singleton>);
    sdk.set_cfunction("create_managed_string", lh::fthunk<&api::sdk::create_managed_string>);
    sdk.set_cfunction("create_managed_array", lh::fthunk<&api::sdk::create_managed_array>);
    sdk.set_cfunction("create_delegate", lh::fthunk<&api::sdk::create_delegate>);
    sdk.set_cfunction("create_sbyte", lh::fthunk<&api::sdk::create_sbyte>);
    sdk.set_cfunction("create_byte", lh::fthunk<&api::sdk::create_byte>);
    sdk.set_cfunction("create_int16", lh::fthunk<&api::sdk::create_int16>);
    sdk.set_cfunction("create_uint16", lh::fthunk<&api::sdk::create_uint16>);
    sdk.set_cfunction("create_int32", lh::fthunk<&api::sdk::create_int32>);
    sdk.set_cfunction("create_uint32", lh::fthunk<&api::sdk::create_uint32>);
    sdk.set_cfunction("create_int64", lh::fthunk<&api::sdk::create_int64>);
    sdk.set_cfunction("create_uint64", lh::fthunk<&api::sdk::create_uint64>);
    sdk.set_cfunction("create_single", lh::fthunk<&api::sdk::create_single>);
    sdk.set_cfunction("create_double", lh::fthunk<&api::sdk::create_double>);
    sdk.set_cfunction("create_resource", lh::fthunk<&api::sdk::create_resource>);
    sdk.set_cfunction("create_userdata", lh::fthunk<&api::sdk::create_userdata>);
    sdk.set_cfunction("create_userdata_global", lh::fthunk<&api::sdk::create_userdata_global>);
    sdk.set_cfunction("create_instance", lh::fthunk<&api::sdk::create_instance>);
    sdk.set_cfunction("create_instance_global", lh::fthunk<&api::sdk::create_instance_global>);
    sdk.set_cfunction("find_type_definition", lh::fthunk<&api::sdk::find_type_definition>);
    sdk.set_cfunction("get_num_types", lh::fthunk<&api::sdk::get_num_types>);
    sdk.set_cfunction("get_type", lh::fthunk<&api::sdk::get_type>);
    sdk.set_cfunction("typeof", lh::fthunk<&api::sdk::typeof>);
    sdk.set_cfunction("call_native_func", lh::fthunk<&api::sdk::call_native_func>);
    sdk.set_cfunction("call_object_func", lh::fthunk<&api::sdk::call_object_func>);
    sdk.set_cfunction("get_native_field", lh::fthunk<&api::sdk::get_native_field>);
    sdk.set_cfunction("set_native_field", lh::fthunk<&api::sdk::set_native_field>);
    sdk.set_cfunction("get_primary_camera", lh::fthunk<&api::sdk::get_primary_camera>);
    sdk.set_cfunction("copy_to_clipboard", lh::fthunk<&api::sdk::copy_to_clipboard>);
    sdk.set_cfunction("hook", lh::fthunk<&api::sdk::hook>);
    sdk.set_cfunction("hook_vtable", lh::fthunk<&api::sdk::hook_vtable>);

    auto pre_hook_result = lua_stack::create_table(L);
    pre_hook_result.set("CALL_ORIGINAL", (int)HookManager::PreHookResult::CALL_ORIGINAL);
    pre_hook_result.set("SKIP_ORIGINAL", (int)HookManager::PreHookResult::SKIP_ORIGINAL);
    sdk.set("PreHookResult", pre_hook_result);

    sdk.set_cfunction("is_managed_object", lh::fthunk<&api::sdk::is_managed_object>);
    sdk.set_cfunction("to_managed_object", lh::fthunk<&sdk_to_managed_object>);
    sdk.set_cfunction("to_valuetype", lh::fthunk<&sdk_to_valuetype>);
    sdk.set_cfunction("deserialize", lh::fthunk<&sdk_deserialize>);
    sdk.set_cfunction("to_resource", lh::fthunk<&sdk_to_resource>);
    sdk.set_cfunction("to_double", lh::fthunk<&sdk_to_double>);
    sdk.set_cfunction("to_float", lh::fthunk<&sdk_to_float>);
    sdk.set_cfunction("to_int64", lh::fthunk<&sdk_to_int64>);
    sdk.set_cfunction("to_ptr", lh::fthunk<&sdk_to_ptr>);
    sdk.set_cfunction("float_to_ptr", lh::fthunk<&sdk_float_to_ptr>);
    // Raw read-only view over an arbitrary native address. The texture resource
    // lives behind a pure C++ factory type (no RETypeDefinition), so its decode
    // state (inner +0x58 / status cache +0x74) has no named field to read; this
    // lets probes read those offsets directly, e.g.
    //   local addr = holder:read_qword(0x10)
    //   local inner = sdk.to_memoryview(addr, 0x100):read_qword(0x58)
    sdk.set_cfunction("to_memoryview", lh::fthunk<&sdk_to_memoryview>);

    lua_stack::put(L, sdk);
    lua_setglobal(L, "sdk");

    lh::methods type_definition(L);

    type_definition.add("get_methods", &sdk_hand_type_definition_get_methods)
        .add("get_fields", &sdk_hand_type_definition_get_fields)
        .add("get_properties", &sdk_hand_type_definition_get_properties)
        .add("get_full_name", lh::mthunk<&::sdk::RETypeDefinition::get_full_name>)
        .add("get_name", lh::mthunk<&::sdk::RETypeDefinition::get_name>)
        .add("get_namespace", lh::mthunk<&::sdk::RETypeDefinition::get_namespace>)
        .add("get_method", lh::mthunk<&::sdk::RETypeDefinition::get_method>)
        .add("get_field", lh::mthunk<&::sdk::RETypeDefinition::get_field>)
        .add("get_runtime_type", lh::mthunk<&::sdk::RETypeDefinition::get_runtime_type>)
        .add("get_parent_type", lh::mthunk<&::sdk::RETypeDefinition::get_parent_type>)
        .add("get_fqn_hash", lh::mthunk<&::sdk::RETypeDefinition::get_fqn_hash>)
        .add("get_crc_hash", lh::mthunk<&::sdk::RETypeDefinition::get_crc_hash>)
        .add("get_size", lh::mthunk<&::sdk::RETypeDefinition::get_size>)
        .add("get_valuetype_size", lh::mthunk<&::sdk::RETypeDefinition::get_valuetype_size>)
        .add("get_generic_argument_types", lh::mthunk<&::sdk::RETypeDefinition::get_generic_argument_types>)
        .add("get_generic_type_definition", lh::mthunk<&::sdk::RETypeDefinition::get_generic_type_definition>)
        .add("is_value_type", lh::mthunk<&::sdk::RETypeDefinition::is_value_type>)
        .add("is_enum", lh::mthunk<&::sdk::RETypeDefinition::is_enum>)
        .add("is_array", lh::mthunk<&::sdk::RETypeDefinition::is_array>)
        .add("is_by_ref", lh::mthunk<&::sdk::RETypeDefinition::is_by_ref>)
        .add("is_pointer", lh::mthunk<&::sdk::RETypeDefinition::is_pointer>)
        .add("is_primitive", lh::mthunk<&::sdk::RETypeDefinition::is_primitive>)
        .add("is_generic_type", lh::mthunk<&::sdk::RETypeDefinition::is_generic_type>)
        .add("is_generic_type_definition", lh::mthunk<&::sdk::RETypeDefinition::is_generic_type_definition>)
        .add("is_a", &sdk_hand_type_definition_is_a)
        .add("create_instance", &sdk_hand_type_definition_create_instance)
        .add("create_instance_gc_safe", &sdk_hand_type_definition_create_instance_gc_safe)
        .add("get_types_inheriting_from_this", lh::mthunk<&::sdk::RETypeDefinition::get_types_inherting_from_this>)
        .add("get_index", lh::mthunk<&::sdk::RETypeDefinition::get_index>)
        .add("get_flags", lh::mthunk<&::sdk::RETypeDefinition::get_flags>)
        .add("get_name_hierarchy", lh::mthunk<&::sdk::RETypeDefinition::get_name_hierarchy>)
        .add("get_fieldptr_offset", lh::mthunk<&::sdk::RETypeDefinition::get_fieldptr_offset>)
        .add("has_fieldptr_offset", lh::mthunk<&::sdk::RETypeDefinition::has_fieldptr_offset>)
        .add("get_declaring_type", lh::mthunk<&::sdk::RETypeDefinition::get_declaring_type>)
        .add("get_underlying_type", lh::mthunk<&::sdk::RETypeDefinition::get_underlying_type>)
        .add("get_managed_vt", lh::mthunk<&::sdk::RETypeDefinition::get_managed_vt>)
        .add("get_vm_obj_type", &sdk_hand_type_definition_get_vm_obj_type)
        .add("should_pass_by_pointer", lh::mthunk<&::sdk::RETypeDefinition::should_pass_by_pointer>);

    lh::install<::sdk::RETypeDefinition>(L, "RETypeDefinition", type_definition, &lh::eq_ptr<::sdk::RETypeDefinition>);

    lh::methods method_definition(L);

    method_definition.add("get_name", lh::mthunk<&::sdk::REMethodDefinition::get_name>)
        .add("get_return_type", lh::mthunk<&::sdk::REMethodDefinition::get_return_type>)
        .add("get_function", lh::mthunk<&::sdk::REMethodDefinition::get_function>)
        .add("get_declaring_type", lh::mthunk<&::sdk::REMethodDefinition::get_declaring_type>)
        .add("get_num_params", lh::mthunk<&::sdk::REMethodDefinition::get_num_params>)
        .add("get_param_types", lh::mthunk<&::sdk::REMethodDefinition::get_param_types>)
        .add("get_param_names", lh::mthunk<&::sdk::REMethodDefinition::get_param_names>)
        .add("is_static", lh::mthunk<&::sdk::REMethodDefinition::is_static>)
        .add("get_index", lh::mthunk<&::sdk::REMethodDefinition::get_index>)
        .add("get_virtual_index", lh::mthunk<&::sdk::REMethodDefinition::get_virtual_index>)
        .add("get_flags", lh::mthunk<&::sdk::REMethodDefinition::get_flags>)
        .add("get_impl_flags", lh::mthunk<&::sdk::REMethodDefinition::get_impl_flags>)
        .add("get_param_typeids", lh::mthunk<&::sdk::REMethodDefinition::get_param_typeids>)
        .add("call", &sdk_hand_method_call);

    lh::install<::sdk::REMethodDefinition>(
        L, "REMethodDefinition", method_definition, &lh::eq_ptr<::sdk::REMethodDefinition>, &sdk_hand_method_call);

    lh::methods property(L);

    property.add("get_name", lh::mthunk<&::sdk::REProperty::get_name>)
        .add("get_flags", lh::mthunk<&::sdk::REProperty::get_flags>)
        .add("get_getter", lh::mthunk<&::sdk::REProperty::get_getter>)
        .add("get_setter", lh::mthunk<&::sdk::REProperty::get_setter>);

    lh::install<::sdk::REProperty>(L, "REProperty", property, &lh::eq_ptr<::sdk::REProperty>);

    lh::methods field(L);

    field.add("get_name", lh::mthunk<&::sdk::REField::get_name>)
        .add("get_type", lh::mthunk<&::sdk::REField::get_type>)
        .add("get_offset_from_base", lh::mthunk<&::sdk::REField::get_offset_from_base>)
        .add("get_offset_from_fieldptr", lh::mthunk<&::sdk::REField::get_offset_from_fieldptr>)
        .add("get_declaring_type", lh::mthunk<&::sdk::REField::get_declaring_type>)
        .add("get_flags", lh::mthunk<&::sdk::REField::get_flags>)
        .add("is_static", lh::mthunk<&::sdk::REField::is_static>)
        .add("is_literal", lh::mthunk<&::sdk::REField::is_literal>)
        .add("get_data", &sdk_hand_field_get_data);

    lh::install<::sdk::REField>(L, "REField", field, &lh::eq_ptr<::sdk::REField>);

    lh::methods managed_object(L);

    managed_object.fallback_index(&sdk_hand_managed_object_index)
        .meta("__newindex", &sdk_hand_managed_object_new_index)
        .add("add_ref", &sdk_hand_managed_object_add_ref)
        .add("add_ref_permanent", &sdk_hand_managed_object_add_ref_permanent)
        .add("force_release", &sdk_hand_managed_object_force_release)
        .add("release", &sdk_hand_managed_object_release)
        .add("deserialize_native", &sdk_hand_managed_object_deserialize_native)
        .add("get_reference_count", &sdk_hand_managed_object_get_reference_count)
        .add("get_address", &sdk_hand_managed_object_get_address)
        .add("get_type_definition", &sdk_hand_managed_object_get_type_definition)
        .add("get_field", &sdk_hand_managed_object_get_field)
        .add("get_object_size", lh::fthunk<&utility::re_managed_object::get_size>)
        .add("set_field", &sdk_hand_managed_object_set_field)
        .add("call", &sdk_hand_managed_object_call)
        .add("write_byte", lh::fthunk<&api::re_managed_object::write_memory<uint8_t>>)
        .add("write_short", lh::fthunk<&api::re_managed_object::write_memory<uint16_t>>)
        .add("write_dword", lh::fthunk<&api::re_managed_object::write_memory<uint32_t>>)
        .add("write_qword", lh::fthunk<&api::re_managed_object::write_memory<int64_t>>)
        .add("write_float", lh::fthunk<&api::re_managed_object::write_memory<float>>)
        .add("write_double", lh::fthunk<&api::re_managed_object::write_memory<double>>)
        .add("read_byte", lh::fthunk<&api::re_managed_object::read_memory<uint8_t>>)
        .add("read_short", lh::fthunk<&api::re_managed_object::read_memory<uint16_t>>)
        .add("read_dword", lh::fthunk<&api::re_managed_object::read_memory<uint32_t>>)
        .add("read_qword", lh::fthunk<&api::re_managed_object::read_memory<int64_t>>)
        .add("read_float", lh::fthunk<&api::re_managed_object::read_memory<float>>)
        .add("read_double", lh::fthunk<&api::re_managed_object::read_memory<double>>);

    lh::install<::REManagedObject>(L, "REManagedObject", managed_object, &lh::eq_ptr<::REManagedObject>);

    // Every type derived from REManagedObject drops its reference when Lua
    // collects the userdata; the metatable carries that directly, so no startup
    // snippet has to reach in and install it.
    install_managed_gc(L, lua_stack::pointer_metatable<::REManagedObject>());

    lh::methods component(L);

    component.fallback_index(&sdk_hand_managed_object_index).meta("__newindex", &sdk_hand_managed_object_new_index);

    lh::install<::REComponent, ::REManagedObject>(L, "REComponent", component);

    install_managed_gc(L, lua_stack::pointer_metatable<::REComponent>());

    lh::methods transform(L);

    transform.fallback_index(&sdk_hand_managed_object_index)
        .meta("__newindex", &sdk_hand_managed_object_new_index)
        .add("calculate_base_transform", lh::fthunk<&utility::re_transform::calculate_base_transform>)
        .add("calculate_tpose_pos_world", lh::fthunk<&utility::re_transform::calculate_tpose_pos_world>)
        .add("apply_joints_tpose", &sdk_hand_apply_joints_tpose)
        .add("set_position", lh::fthunk<&sdk::set_transform_position>)
        .add("set_rotation", lh::fthunk<&sdk::set_transform_rotation>)
        .add("get_position", lh::fthunk<&sdk::get_transform_position>)
        .add("get_rotation", lh::fthunk<&sdk::get_transform_rotation>)
        .add("hook_update", &sdk_hand_transform_hook_update);

    lh::install<::RETransform, ::REComponent, ::REManagedObject>(L, "RETransform", transform);

    install_managed_gc(L, lua_stack::pointer_metatable<::RETransform>());

    lh::methods system_array(L);

    system_array.fallback_index(&sdk_hand_system_array_index)
        .meta("__newindex", &sdk_hand_system_array_new_index)
        .meta("__pairs", &sdk_hand_system_array_pairs)
        .add("get_size", lh::mthunk<&sdk::SystemArray::get_size>)
        .add("get_element", lh::mthunk<&sdk::SystemArray::get_element>)
        .add("get_elements", lh::mthunk<&sdk::SystemArray::get_elements>);

    lh::install<::sdk::SystemArray, ::REManagedObject>(L, "SystemArray", system_array, &lh::eq_ptr<::sdk::SystemArray>);

    install_managed_gc(L, lua_stack::pointer_metatable<::sdk::SystemArray>());

    lh::methods delegate(L);

    delegate.fallback_index(&sdk_hand_managed_object_index)
        .meta("__newindex", &sdk_hand_delegate_new_index)
        .add("add", &sdk_hand_delegate_add)
        .add("invoke", lh::mthunk<&sdk::Delegate::invoke>);

    lh::install<::sdk::Delegate, ::REManagedObject>(L, "Delegate", delegate, &lh::eq_ptr<::sdk::Delegate>);

    install_managed_gc(L, lua_stack::pointer_metatable<::sdk::Delegate>());

    lh::methods value_type(L);

    value_type.fallback_index(&sdk_hand_value_type_index)
        .meta("__newindex", &sdk_hand_value_type_new_index)
        .add("data", lh::member<&api::sdk::ValueType::data>)
        .add("type", lh::member<&api::sdk::ValueType::type>)
        .add("write_byte", lh::mthunk<&api::sdk::ValueType::write_memory<uint8_t>>)
        .add("write_short", lh::mthunk<&api::sdk::ValueType::write_memory<uint16_t>>)
        .add("write_dword", lh::mthunk<&api::sdk::ValueType::write_memory<uint32_t>>)
        .add("write_qword", lh::mthunk<&api::sdk::ValueType::write_memory<int64_t>>)
        .add("write_float", lh::mthunk<&api::sdk::ValueType::write_memory<float>>)
        .add("write_double", lh::mthunk<&api::sdk::ValueType::write_memory<double>>)
        .add("read_byte", lh::mthunk<&api::sdk::ValueType::read_memory<uint8_t>>)
        .add("read_short", lh::mthunk<&api::sdk::ValueType::read_memory<uint16_t>>)
        .add("read_dword", lh::mthunk<&api::sdk::ValueType::read_memory<uint32_t>>)
        .add("read_qword", lh::mthunk<&api::sdk::ValueType::read_memory<int64_t>>)
        .add("read_float", lh::mthunk<&api::sdk::ValueType::read_memory<float>>)
        .add("read_double", lh::mthunk<&api::sdk::ValueType::read_memory<double>>)
        .add("address", lh::mthunk<&api::sdk::ValueType::address>)
        .add("get_address", lh::mthunk<&api::sdk::ValueType::address>)
        .add("call", &sdk_hand_value_type_call)
        .add("get_field", &sdk_hand_value_type_get_field)
        .add("set_field", &sdk_hand_value_type_set_field)
        .add("get_type_definition", &sdk_hand_value_type_get_type_definition)
        // sol2 kept `construct` in the same string keys as the members, so
        // `ValueType.new(def)` built a value alongside the methods.
        .add("new", &sdk_hand_value_type_construct);

    // ValueType owns a std::vector, so the value it is pushed as has to be
    // destructed by the state. construct is the __call sol2 built from
    // constructors<ValueType(RETypeDefinition*)>. The three overloads take
    // (RETypeDefinition*), (RETypeDefinition*, void*) and (const void*, size_t),
    // so naming the pointer type is what picks the one sol2 exposed.
    // MSVC will not take the address of an overloaded constructor inside a
    // template argument, so the call goes through a function that names the
    // overload with a plain cast.
    using value_type_ctor = api::sdk::ValueType (api::sdk::ValueType::*)(::sdk::RETypeDefinition*);

    lh::install<api::sdk::ValueType>(L, "ValueType", value_type, nullptr, &sdk_hand_value_type_construct, true);

    lh::methods memory_view(L);

    memory_view.add("write_byte", lh::mthunk<&api::sdk::MemoryView::write_memory<uint8_t>>)
        .add("write_short", lh::mthunk<&api::sdk::MemoryView::write_memory<uint16_t>>)
        .add("write_dword", lh::mthunk<&api::sdk::MemoryView::write_memory<uint32_t>>)
        .add("write_qword", lh::mthunk<&api::sdk::MemoryView::write_memory<int64_t>>)
        .add("write_float", lh::mthunk<&api::sdk::MemoryView::write_memory<float>>)
        .add("write_double", lh::mthunk<&api::sdk::MemoryView::write_memory<double>>)
        .add("read_byte", lh::mthunk<&api::sdk::MemoryView::read_memory<uint8_t>>)
        .add("read_short", lh::mthunk<&api::sdk::MemoryView::read_memory<uint16_t>>)
        .add("read_dword", lh::mthunk<&api::sdk::MemoryView::read_memory<uint32_t>>)
        .add("read_qword", lh::mthunk<&api::sdk::MemoryView::read_memory<int64_t>>)
        .add("read_float", lh::mthunk<&api::sdk::MemoryView::read_memory<float>>)
        .add("read_double", lh::mthunk<&api::sdk::MemoryView::read_memory<double>>)
        .add("address", lh::mthunk<&api::sdk::MemoryView::address>)
        .add("get_address", lh::mthunk<&api::sdk::MemoryView::address>)
        .add("wipe", lh::mthunk<&api::sdk::MemoryView::wipe>);
    memory_view.fallback_index(&sdk_hand_memoryview_index);

    lh::install<api::sdk::MemoryView>(L, "MemoryView", memory_view);

    lh::methods resource(L);

    resource.add("add_ref", &sdk_hand_resource_add_ref)
        .add("release", lh::mthunk<&::sdk::Resource::release>)
        .add("create_holder", lh::fthunk<&::api::sdk::create_holder>)
        .add("create_holder_global", lh::fthunk<&::api::sdk::create_holder_global>)
        .add("get_address", &sdk_hand_resource_get_address);

    lh::install<::sdk::Resource>(L, "REResource", resource, &lh::eq_ptr<::sdk::Resource>);

// Every array exposes the same shape, so one macro builds the member table and
// registers the type. TAG names the thunks, which keep the short prefixes the
// bindings are filed under; the Lua name is spelled out because the C++ type of
// a macro argument cannot be turned back into the string sol2 used.
#define LUA_HAND_DYNAMIC_ARRAY(L, NAME, TAG, LUA_NAME, C) \
    lh::methods NAME(L); \
    NAME.meta("__newindex", &sdk_hand_##TAG##_new_index) \
        .meta("__pairs", &sdk_hand_##TAG##_pairs) \
        .meta("__len", &sdk_hand_##TAG##_len) \
        .add("as_memoryview", &sdk_hand_##TAG##_as_memoryview) \
        .add("empty", lh::member_fn<decltype(&C::empty), &C::empty>) \
        .add("emplace", lh::member_fn<decltype(&C::emplace), &C::emplace>) \
        .add("pop_back", lh::member_fn<decltype(&C::pop_back), &C::pop_back>) \
        .add("size", &sdk_hand_##TAG##_size) \
        .add("get_size", &sdk_hand_##TAG##_size) \
        .add("erase", lh::member_fn<decltype(&C::erase), &C::erase>) \
        .add("clear", &sdk_hand_##TAG##_clear) \
        .add("push_back", &sdk_hand_##TAG##_push_back); \
\
    NAME.fallback_index(&sdk_hand_##TAG##_index); \
\
    lh::install<C>(L, LUA_NAME, NAME); \
\
    install_managed_gc(L, lua_stack::pointer_metatable<C>());

    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityUInt8, dyn_u8, "DynamicArrayNoCapacityUInt8", sdk::NativeArrayNoCapacity<uint8_t>)
    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityInt32, dyn_i32, "DynamicArrayNoCapacityInt32", sdk::NativeArrayNoCapacity<int32_t>)
    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityUInt32, dyn_u32, "DynamicArrayNoCapacityUInt32", sdk::NativeArrayNoCapacity<uint32_t>)

    // An array of arrays: a read is pushed as a borrowed pointer and push_back
    // copies what the pointer addresses.
    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityUInt32Array, dyn_u32arr, "DynamicArrayNoCapacityUInt32Array", sdk::NativeArrayNoCapacity<uint32_t>)

    // The behaviour tree types register their arrays once the tree binding
    // below has installed them.
    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityTreeNode, dyn_tn, "DynamicArrayNoCapacityTreeNode", sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>)
    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayNoCapacityTreeNodeData, dyn_tnd, "DynamicArrayNoCapacityTreeNodeData", sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>)

    LUA_HAND_DYNAMIC_ARRAY(L, DynamicArrayManagedObject, dyn_mo, "DynamicArrayManagedObject", sdk::NativeArray<::REManagedObject*>)

#undef LUA_HAND_DYNAMIC_ARRAY

    lh::methods tree_node_data(L);

    tree_node_data.add("as_memoryview", &sdk_hand_tnd_as_memoryview)
        .add("to_valuetype", &sdk_hand_tnd_to_valuetype)
        .add("id", lh::member<&::sdk::behaviortree::TreeNodeData::id>)
        .add("parent", lh::member<&::sdk::behaviortree::TreeNodeData::parent>)
        .add("is_branch", lh::member<&::sdk::behaviortree::TreeNodeData::is_branch>)
        .add("is_end", lh::member<&::sdk::behaviortree::TreeNodeData::is_end>)
        .add("has_selector", lh::member<&::sdk::behaviortree::TreeNodeData::has_selector>)
        .add("attr", lh::member<&::sdk::behaviortree::TreeNodeData::attr>)
        .add("parent_2", lh::member<&::sdk::behaviortree::TreeNodeData::parent_2>)
        .add("get_children", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_children>)
        .add("get_actions", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_actions>)
        .add("get_states", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_states>)
        .add("get_states_2", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_states_2>)
        .add("get_start_states", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_start_states>)
        .add("get_start_transitions", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_start_transitions>)
        .add("get_conditions", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_conditions>)
        .add("get_transition_conditions", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_transition_conditions>)
        .add("get_transition_events", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_transition_events>)
        .add("get_transition_ids", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_transition_ids>)
        .add("get_transition_attributes", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_transition_attributes>)
        .add("get_tags", lh::mthunk<&::sdk::behaviortree::TreeNodeData::get_tags>)
        .add("get_name", &sdk_hand_tnd_get_name)
        .add("set_name", &sdk_hand_tnd_set_name);

    lh::install<::sdk::behaviortree::TreeNodeData>(L, "BehaviorTreeNodeData", tree_node_data);

    lh::methods tree_node(L);

    tree_node.add("as_memoryview", &sdk_hand_tn_as_memoryview)
        .add("to_valuetype", &sdk_hand_tn_to_valuetype)
        .add("id", lh::member<&::sdk::behaviortree::TreeNode::id>)
        .add("get_id", lh::mthunk<&::sdk::behaviortree::TreeNode::get_id>)
        .add("get_data", lh::mthunk<&::sdk::behaviortree::TreeNode::get_data>)
        .add("get_owner", lh::mthunk<&::sdk::behaviortree::TreeNode::get_owner>)
        .add("get_parent", lh::mthunk<&::sdk::behaviortree::TreeNode::get_parent>)
        .add("get_name", &sdk_hand_tn_get_name)
        .add("set_name", &sdk_hand_tn_set_name)
        .add("get_full_name", &sdk_hand_tn_get_full_name)
        .add("get_children", lh::mthunk<&::sdk::behaviortree::TreeNode::get_children>)
        .add("get_actions", lh::mthunk<&::sdk::behaviortree::TreeNode::get_actions>)
        .add("get_unloaded_actions", lh::mthunk<&::sdk::behaviortree::TreeNode::get_unloaded_actions>)
        .add("get_conditions", lh::mthunk<&::sdk::behaviortree::TreeNode::get_conditions>)
        .add("get_transition_conditions", lh::mthunk<&::sdk::behaviortree::TreeNode::get_transition_conditions>)
        .add("get_transition_events", lh::mthunk<&::sdk::behaviortree::TreeNode::get_transition_events>)
        .add("get_states", lh::mthunk<&::sdk::behaviortree::TreeNode::get_states>)
        .add("get_start_states", lh::mthunk<&::sdk::behaviortree::TreeNode::get_start_states>)
        .add("get_status1", lh::mthunk<&::sdk::behaviortree::TreeNode::get_status1>)
        .add("get_status2", lh::mthunk<&::sdk::behaviortree::TreeNode::get_status2>)
        .add("relocate", lh::mthunk<&::sdk::behaviortree::TreeNode::relocate>)
        .add("get_selector", &sdk_hand_tn_get_selector);

    lh::install<::sdk::behaviortree::TreeNode>(L, "BehaviorTreeNode", tree_node);

    lh::methods tree_object_data(L);

    tree_object_data.add("as_memoryview", &sdk_hand_tod_as_memoryview)
        .add("get_nodes", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_nodes>)
        .add("get_static_actions", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_static_actions>)
        .add("get_static_conditions", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_static_conditions>)
        .add("get_static_transitions", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_static_transitions>)
        .add("get_expression_tree_conditions", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_expression_tree_conditions>)
        .add("get_action_methods", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_action_methods>)
        .add("get_static_action_methods", lh::mthunk<&::sdk::behaviortree::TreeObjectData::get_static_action_methods>);

    lh::install<::sdk::behaviortree::TreeObjectData>(L, "BehaviorTreeObjectData", tree_object_data);

    lh::methods tree_object(L);

    tree_object.add("as_memoryview", &sdk_hand_to_as_memoryview)
        .add("get_data", lh::mthunk<&::sdk::behaviortree::TreeObject::get_data>)
        .add("get_node_by_id", lh::mthunk<&::sdk::behaviortree::TreeObject::get_node_by_id>)
        .add("get_node_by_name", &sdk_hand_to_get_node_by_name)
        .add("get_actions", lh::mthunk<&::sdk::behaviortree::TreeObject::get_action_array>)
        .add("get_nodes", lh::mthunk<&::sdk::behaviortree::TreeObject::get_node_array>)
        .add("get_conditions", lh::mthunk<&::sdk::behaviortree::TreeObject::get_condition_array>)
        .add("get_transitions", lh::mthunk<&::sdk::behaviortree::TreeObject::get_transition_array>)
        .add("get_selectors", lh::mthunk<&::sdk::behaviortree::TreeObject::get_selector_array>)
        .add("get_node", lh::mthunk<&::sdk::behaviortree::TreeObject::get_node>)
        .add("get_node_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_node_count>)
        .add("get_action", lh::mthunk<&::sdk::behaviortree::TreeObject::get_action>)
        .add("get_unloaded_action", lh::mthunk<&::sdk::behaviortree::TreeObject::get_unloaded_action>)
        .add("get_transition", lh::mthunk<&::sdk::behaviortree::TreeObject::get_transition>)
        .add("get_condition", lh::mthunk<&::sdk::behaviortree::TreeObject::get_condition>)
        .add("get_action_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_action_count>)
        .add("get_condition_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_condition_count>)
        .add("get_transition_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_transition_count>)
        .add("get_unloaded_action_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_unloaded_action_count>)
        .add("get_static_action_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_static_action_count>)
        .add("get_static_condition_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_static_condition_count>)
        .add("get_static_transition_count", lh::mthunk<&::sdk::behaviortree::TreeObject::get_static_transition_count>)
        .add("relocate", lh::mthunk<&::sdk::behaviortree::TreeObject::relocate>)
        .add("get_uservariable_hub", lh::mthunk<&::sdk::behaviortree::TreeObject::get_uservariable_hub>);

    lh::install<::sdk::behaviortree::TreeObject>(L, "BehaviorTreeObject", tree_object);


    lh::methods core_handle(L);

    core_handle.fallback_index(&sdk_hand_managed_object_index)
        .meta("__newindex", &sdk_hand_managed_object_new_index)
        .add("get_tree_object", &sdk_hand_get_tree_object)
        .add("relocate", &sdk_hand_core_handle_relocate)
        .add("relocate_datas", &sdk_hand_core_handle_relocate_datas);

    lh::install<::api::sdk::BehaviorTreeCoreHandle, ::REManagedObject>(L, "BehaviorTreeCoreHandle", core_handle);

    install_managed_gc(L, lua_stack::pointer_metatable<::api::sdk::BehaviorTreeCoreHandle>());

    lh::methods tree(L);

    tree.fallback_index(&sdk_hand_managed_object_index)
        .meta("__newindex", &sdk_hand_managed_object_new_index)
        .add("get_tree", &sdk_hand_tree_get_tree)
        .add("get_tree_count", &sdk_hand_tree_get_tree_count)
        .add("get_trees", &sdk_hand_tree_get_trees);

    lh::install<::api::sdk::BehaviorTree, ::REManagedObject>(L, "BehaviorTree", tree);

    install_managed_gc(L, lua_stack::pointer_metatable<::api::sdk::BehaviorTree>());
}

// ScriptRunner pushes these two by pointer from its own translation unit, which
// only sees the declaration. The sol2 usertypes used to instantiate the
// definition as a side effect of their pusher; the hand-written metatables no
// longer do, so the two instances are named here.
template int lua_stack_push<::REComponent>(lua_stack::pointer_tag<::REComponent>, lua_State*, ::REComponent*);
template int lua_stack_push<::RETransform>(lua_stack::pointer_tag<::RETransform>, lua_State*, ::RETransform*);
