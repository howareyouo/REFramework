#pragma once

#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

// The five math types are named by the specializations below; the fwd header
// declares their primary templates and nothing else.
#include <glm/fwd.hpp>

#include <lua.hpp> // wraps the C headers in extern "C"; lua.h alone mismatches the C-built runtime

// The engine and sdk types the specializations name. Declaring them here
// keeps every including TU self-sufficient; glm cannot be forward declared
// (its templates carry default arguments), which is why the fwd header above
// is included instead.
namespace sdk {
struct SystemArray;
struct RETypeDefinition;
struct REMethodDefinition;
struct REProperty;
struct REField;
class Resource;
struct Delegate;

template <typename T>
struct NativeArray;

template <typename T>
struct NativeArrayNoCapacity;

namespace behaviortree {
class TreeNode;
class TreeNodeData;
class TreeObject;
class TreeObjectData;
}
} // namespace sdk

namespace api::sdk {
struct ValueType;
struct MemoryView;
struct BehaviorTree;
struct BehaviorTreeCoreHandle;
} // namespace api::sdk

class REManagedObject;
class REComponent;
class RETransform;
class REFramework;
class REObjectInfo;

// The marshalling layer the hand-written bindings marshal their arguments and
// returns through, with no sol2 on the include path. Every primitive here
// reproduces one observable behavior of the sol2 stack layer it replaces:
//
//   - numeric reads go through lua_tonumber/lua_tointeger and are loose the
//     way sol2's unchecked getters were loose (a string argument read as a
//     float became 0, not an error);
//   - userdata is recognized by the metatable names sol2 stamped on it, which
//     are hard-coded per type in usertype_name below rather than re-demangled;
//   - a value pushed as a userdata is a block whose first pointer-sized slot
//     aims at the value, which is what every getter dereferences;
//   - an owned value carries a __gc that runs the destructor, a borrowed
//     pointer never does.
//
// The userdata protocol is shared with lua_hand (LuaHand.hpp): the
// "class_check"/"class_cast" lightuserdata entries its install() stores are
// read here exactly as sol2 read them, so both layers answer inheritance
// questions about the same metatables.
namespace lua_stack {
// The error type a binding throws to fail a call. lua_hand's thunks translate
// what() into the Lua error, the way sol2 translated its own exceptions.
class error : public std::runtime_error {
public:
    explicit error(const std::string& message)
        : std::runtime_error(message) {}
    explicit error(const char* message)
        : std::runtime_error(message) {}
};

// The tag for an absent value. A pushed one is nil; one held in a reference
// means the reference points at nil (which is not the same as no reference).
struct nil_t {};

inline constexpr nil_t lua_nil{};

// Declared here so the check/get dispatch below can name the reference types;
// they are defined further down.
class reference;
class object;
class table;
class protected_function;

// The seam a binding plugs a managed pointer pusher into. Sdk.cpp declares
// overloads of lua_stack_push(pointer_tag<T>, lua_State*, T*) for the engine
// types whose pointer must add a reference before it reaches Lua; every other
// type falls through to the plain block push.
template <typename T>
struct pointer_tag {};

namespace detail {
template <typename T, typename = void>
struct pointer_push_override : std::false_type {};

template <typename T>
struct pointer_push_override<T,
    std::void_t<decltype(lua_stack_push(pointer_tag<T>{}, static_cast<lua_State*>(nullptr), static_cast<T*>(nullptr)))>>
: std::true_type {};
} // namespace detail

// Whether the value at `index` can be called the way sol2 checked a function
// parameter: a function always was, a nil was (an omitted callback read as a
// nil function), and a table or userdata was one when a __call sat on it.
inline bool check_callable(lua_State* L, int index) {
    const int actual = lua_type(L, index);

    if (actual == LUA_TNIL || actual == LUA_TNONE || actual == LUA_TFUNCTION) {
        return true;
    }

    if (actual != LUA_TUSERDATA && actual != LUA_TTABLE) {
        return false;
    }

    if (lua_getmetatable(L, index) == 0) {
        return false;
    }

    lua_getfield(L, -1, "__call");
    const bool callable = lua_isnoneornil(L, -1) == 0;
    lua_pop(L, 2);
    return callable;
}

// The registry keys sol2 gave a usertype. sol::usertype_traits<T> derived them
// from __FUNCSIG__-based demangling, so the string is MSVC's canonical
// rendering of the type: the outermost template's own '>' is cut by the
// demangler, "struct"/"class" are stripped, and cv-qualifiers trail the type.
// One name per type is spelled out here instead -- these were measured from
// the running game, and a demangle re-run would put the byte-exactness of the
// registry keys at the mercy of the compiler's formatting.
//
// qualified_name<T>() is the bare string; it is what the class_check/
// class_cast protocol compares against. The metatable functions add the
// "sol." prefix and the form suffixes.
template <typename T>
struct usertype_name; // No definition: a use without a specialization must not compile.

namespace detail {
// Whether the type has a registered name. A type without one is never a usertype
// in this layer (a base class that only the engine knows about, say), so reading
// it as a pointer answers nullptr rather than demanding a name.
template <typename T, typename = void>
struct has_usertype_name : std::false_type {};

template <typename T>
struct has_usertype_name<T, std::void_t<decltype(usertype_name<T>::value)>> : std::true_type {};

// Whether the type is a std::vector. sol2 pushed a vector return as a flat
// sequence table (the form lua_hand::put_seq builds), not as a usertype, so
// put() needs no usertype name for it.
template <typename T>
struct is_std_vector : std::false_type {};

template <typename T, typename Alloc>
struct is_std_vector<std::vector<T, Alloc>> : std::true_type {};
} // namespace detail

// The specializations are written out longhand: a macro would split a type
// whose template argument list holds a comma, and half of these have one.

// The five math types. Vector2f/Vector3f/Vector4f are glm::vec<2|3|4, float,
// defaultp>, Matrix4x4f is glm::mat<4, 4, float, defaultp>, and glm::quat is
// glm::qua<float, defaultp>; defaultp is highp here, whose enumerator value is
// 0 -- the form MSVC's rendering of the template argument takes, which is what
// the measured "sol.glm::vec<3,float,0>" keys show. Both the value form a
// constructor produces and the pointer form a matrix element is handed out as
// are registered, so both names are needed.
template <>
struct usertype_name<glm::vec<2, float, glm::highp>> {
    static constexpr const char* value = "glm::vec<2,float,0>";
};

template <>
struct usertype_name<glm::vec<3, float, glm::highp>> {
    static constexpr const char* value = "glm::vec<3,float,0>";
};

template <>
struct usertype_name<glm::vec<4, float, glm::highp>> {
    static constexpr const char* value = "glm::vec<4,float,0>";
};

template <>
struct usertype_name<glm::mat<4, 4, float, glm::highp>> {
    static constexpr const char* value = "glm::mat<4,4,float,0>";
};

template <>
struct usertype_name<glm::qua<float, glm::highp>> {
    static constexpr const char* value = "glm::qua<float,0>";
};

// The engine classes. Every one of them is reached as a pointer; the value
// name exists because install() builds the full form set sol2 built.
template <>
struct usertype_name<::REManagedObject> {
    static constexpr const char* value = "REManagedObject";
};

template <>
struct usertype_name<::REComponent> {
    static constexpr const char* value = "REComponent";
};

template <>
struct usertype_name<::RETransform> {
    static constexpr const char* value = "RETransform";
};

// The managed vtable a type definition points at. Nothing installs it; sol2
// only ever pushed the pointer, under the metatable this name builds.
template <>
struct usertype_name<::REObjectInfo> {
    static constexpr const char* value = "REObjectInfo";
};

template <>
struct usertype_name<::sdk::SystemArray> {
    static constexpr const char* value = "sdk::SystemArray";
};

template <>
struct usertype_name<::sdk::Delegate> {
    static constexpr const char* value = "sdk::Delegate";
};

template <>
struct usertype_name<::api::sdk::BehaviorTree> {
    static constexpr const char* value = "api::sdk::BehaviorTree";
};

template <>
struct usertype_name<::api::sdk::BehaviorTreeCoreHandle> {
    static constexpr const char* value = "api::sdk::BehaviorTreeCoreHandle";
};

// The type database types.
template <>
struct usertype_name<::sdk::RETypeDefinition> {
    static constexpr const char* value = "sdk::RETypeDefinition";
};

template <>
struct usertype_name<::sdk::REMethodDefinition> {
    static constexpr const char* value = "sdk::REMethodDefinition";
};

template <>
struct usertype_name<::sdk::REProperty> {
    static constexpr const char* value = "sdk::REProperty";
};

template <>
struct usertype_name<::sdk::REField> {
    static constexpr const char* value = "sdk::REField";
};

template <>
struct usertype_name<::sdk::Resource> {
    static constexpr const char* value = "sdk::Resource";
};

// The wrappers and the view the bindings hand out.
template <>
struct usertype_name<::api::sdk::ValueType> {
    static constexpr const char* value = "api::sdk::ValueType";
};

template <>
struct usertype_name<::api::sdk::MemoryView> {
    static constexpr const char* value = "api::sdk::MemoryView";
};

// The borrowed arrays. MSVC spells the element types out: uint8_t is "unsigned
// char", int32_t is "int", uint32_t is "unsigned int", and a pointer element
// keeps its star.
template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<uint8_t>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<unsigned char>";
};

template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<int32_t>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<int>";
};

template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<uint32_t>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<unsigned int>";
};

template <>
struct usertype_name<::sdk::NativeArray<::REManagedObject*>> {
    static constexpr const char* value = "sdk::NativeArray<REManagedObject*>";
};

template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNode>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNode>";
};

template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<::sdk::behaviortree::TreeNodeData>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<sdk::behaviortree::TreeNodeData>";
};

// The transition-event array is an array of arrays. Nothing installs it; sol2
// only ever pushed it as a value block, so the name exists to give that block
// its own metatable.
template <>
struct usertype_name<::sdk::NativeArrayNoCapacity<::sdk::NativeArrayNoCapacity<uint32_t>>> {
    static constexpr const char* value = "sdk::NativeArrayNoCapacity<sdk::NativeArrayNoCapacity<unsigned int>>";
};

// The behavior tree types.
template <>
struct usertype_name<::sdk::behaviortree::TreeNode> {
    static constexpr const char* value = "sdk::behaviortree::TreeNode";
};

template <>
struct usertype_name<::sdk::behaviortree::TreeNodeData> {
    static constexpr const char* value = "sdk::behaviortree::TreeNodeData";
};

template <>
struct usertype_name<::sdk::behaviortree::TreeObject> {
    static constexpr const char* value = "sdk::behaviortree::TreeObject";
};

template <>
struct usertype_name<::sdk::behaviortree::TreeObjectData> {
    static constexpr const char* value = "sdk::behaviortree::TreeObjectData";
};

// The two ScriptRunner-owned shapes. REFramework is installed by name from
// ScriptRunner.cpp; the keyboard state is a std::array reference return, which
// is how the "unsigned char" spelling below arises.
template <>
struct usertype_name<::REFramework> {
    static constexpr const char* value = "REFramework";
};

template <>
struct usertype_name<std::array<unsigned char, 256>> {
    static constexpr const char* value = "std::array<unsigned char,256>";
};

// The byte buffer a native deserialize takes. sol2 exposed it as a container,
// so the name it was registered under is the container spelling.
template <>
struct usertype_name<std::vector<uint8_t>> {
    static constexpr const char* value = "std::vector<unsigned char,std::allocator<unsigned char>>";
};

// The bare demangled name the inheritance protocol compares against.
template <typename T>
inline const std::string& qualified_name() {
    static const std::string name = usertype_name<T>::value;
    return name;
}

// The value-form registry key, e.g. "sol.glm::vec<3,float,0>".
template <typename T>
inline const std::string& value_metatable() {
    static const std::string name = std::string("sol.") + usertype_name<T>::value;
    return name;
}

// The pointer-form registry key, e.g. "sol.glm::vec<3,float,0>*".
template <typename T>
inline const std::string& pointer_metatable() {
    static const std::string name = std::string("sol.") + usertype_name<T>::value + "*";
    return name;
}

// The const forms install() also builds. MSVC puts the cv-qualifier after the
// type it qualifies; nothing reads these keys back except the code that made
// them, so only self-consistency is load-bearing here (see
// tools/lua_conformance/SOL2_REMOVAL.md).
template <typename T>
inline const std::string& const_value_metatable() {
    static const std::string name = std::string("sol.") + usertype_name<T>::value + " const";
    return name;
}

template <typename T>
inline const std::string& const_pointer_metatable() {
    static const std::string name = std::string("sol.") + usertype_name<T>::value + " const *";
    return name;
}

// The type-table key install() publishes a global under.
template <typename T>
inline const std::string& user_metatable() {
    static const std::string name = std::string("sol.") + usertype_name<T>::value + ".user";
    return name;
}

// The owned-value registry key. sol2 spelled it after its own
// sol::detail::unique_usertype wrapper, whose '>' survives the demangle cut
// because the demangler only removes the outermost one.
template <typename T>
inline const std::string& unique_metatable() {
    static const std::string name = std::string("sol.sol::detail::unique_usertype<") + usertype_name<T>::value + ">";
    return name;
}

// The container wrapper name the __pairs refusal reports. This is a demangled
// type name, not a registry key, so it carries no "sol." prefix. MSVC's
// demangler separates two closing angle brackets with a space ("vec<3,float,0> >"),
// and the message has to match it byte for byte.
template <typename T>
inline const std::string& container_qualified_name() {
    static const std::string name = [] {
        const std::string inner = usertype_name<T>::value;
        const bool nested = !inner.empty() && inner.back() == '>';

        return std::string("sol::as_container_t<") + inner + (nested ? " >" : ">");
    }();

    return name;
}

// The __pairs refusal of a type sol2 did not treat as a container. Raised with
// lua_error so the text reaches Lua without a position prefix, exactly as the
// stub sol2 generated did.
template <typename T>
inline int raise_not_a_container(lua_State* L) {
    lua_pushfstring(L, "sol: cannot call '__pairs/pairs' on type '%s': it is not recognized as a container",
        container_qualified_name<T>().c_str());
    return lua_error(L);
}

// The write refusal of a plain usertype. Byte-identical to the message sol2
// raised, which lua_hand::new_index_error already pins; kept here so this
// header stands alone.
inline int new_index_error(lua_State* L) {
    return luaL_error(L, "sol: cannot set (new_index) into this object: no defined new_index operation on usertype");
}

// A relative index would shift once helpers below start pushing, so every
// helper that takes an index it means to keep resolves it first.
inline int absolute_index(lua_State* L, int index) {
    return index < 0 && index > LUA_REGISTRYINDEX ? lua_gettop(L) + index + 1 : index;
}

// sol2 aligned the first pointer slot of every userdata block to the pointer
// alignment (its SOL_ALIGN_MEMORY default), so a reader aligns before it
// dereferences. lua_newuserdata hands out malloc-sized alignment on this
// platform, which makes the adjustment a no-op, but the read is kept exact.
inline void* align_pointer_slot(void* ptr) {
    const std::uintptr_t alignment = alignof(void*);
    const std::uintptr_t initial = reinterpret_cast<std::uintptr_t>(ptr);
    const std::uintptr_t padding = (alignment - (initial % alignment)) % alignment;
    return reinterpret_cast<void*>(initial + padding);
}

// The size of a value block: a pointer slot, then the value at its own
// alignment. This is the allocation sol2 made for a pushed value.
template <typename T>
inline std::size_t value_block_size() {
    std::size_t slot = sizeof(void*);
    const std::size_t alignment = alignof(T);

    if (alignment > slot) {
        slot += (alignment - (slot % alignment)) % alignment;
    }

    return slot + sizeof(T);
}

// The address a value block's T* slot aims at: after the slot, at the value's
// own alignment.
template <typename T>
inline void* value_block_target(void* slot) {
    char* after = static_cast<char*>(slot) + sizeof(void*);
    const std::uintptr_t alignment = alignof(T);
    const std::uintptr_t initial = reinterpret_cast<std::uintptr_t>(after);
    const std::uintptr_t padding = (alignment - (initial % alignment)) % alignment;
    return reinterpret_cast<void*>(initial + padding);
}

// The __gc of a value-form metatable: dereference the block's own slot and run
// the destructor. This is what sol2's usertype_alloc_destruct did, and what
// install(owns_gc) parked on the unique metatable.
template <typename T>
inline int value_gc(lua_State* L) {
    static_assert(std::is_destructible_v<T>, "a value metatable can only carry a destructor for a destructible type");

    void* memory = align_pointer_slot(lua_touserdata(L, 1));
    T* data = *static_cast<T**>(memory);
    data->~T();
    return 0;
}

// The __gc for a value sitting in place in its block, which is the shape
// construct_value makes. The destructor runs on the block itself, with no
// slot in front of it. An installer that hands the unique metatable to
// constructor-made values points __gc here; sol2's make_destructor pointed at
// the slot-deref form instead, which is a mismatch this header keeps
// separate so the migration can choose (see SOL2_REMOVAL.md).
template <typename T>
inline int unique_value_gc(lua_State* L) {
    static_assert(std::is_destructible_v<T>, "a value metatable can only carry a destructor for a destructible type");

    static_cast<T*>(lua_touserdata(L, 1))->~T();
    return 0;
}

// The inheritance protocol lua_hand::set_bases stores: raw function pointers
// kept as lightuserdata under these two metatable fields, called with the
// qualified name of the type the question is about.
using inheritance_check = bool (*)(const std::string_view&);
using inheritance_cast = void* (*)(void*, const std::string_view&);

inline constexpr const char* kClassCheckKey = "class_check";
inline constexpr const char* kClassCastKey = "class_cast";

// Whether the userdata at `index` carries one of the metatables of T. sol2
// answered a usertype check with four name comparisons and then the base
// chain: the value form, the pointer form, the owned-value form and the
// container wrapper -- a userdata with no metatable at all was accepted.
// `accept_nil` is what separates a T* parameter (nil accepted, it is a valid
// null) from a T& or T parameter (nil refused).
template <typename T>
inline bool check_userdata(lua_State* L, int index, bool accept_nil) {
    if constexpr (!detail::has_usertype_name<T>::value) {
        (void)L;
        (void)index;
        (void)accept_nil;
        return false;
    } else {
        const int actual = lua_type(L, index);

        if (actual == LUA_TNIL) {
            return accept_nil;
        }

        if (actual != LUA_TUSERDATA) {
            return false;
        }

        if (lua_getmetatable(L, index) == 0) {
            // A metatable-less userdata was never refused by sol2.
            return true;
        }

        bool matched = false;

        const auto has_name = [&](const std::string& name) {
            if (matched) {
                return;
            }

            luaL_getmetatable(L, name.c_str());

            if (lua_type(L, -1) != LUA_TNIL && lua_rawequal(L, -1, -2) == 1) {
                matched = true;
            }

            lua_pop(L, 1);
        };

        has_name(value_metatable<T>());
        has_name(pointer_metatable<T>());
        has_name(unique_metatable<T>());
        has_name(std::string("sol.") + container_qualified_name<T>());

        if (!matched) {
            // The base chain. sol2 only asked it when the requested type was
            // known to be derived from somewhere; every metatable that carries
            // a class_check was made by a set_bases that marked its bases, so
            // consulting it whenever it is present answers the same questions.
            lua_getfield(L, -1, kClassCheckKey);

            if (void* fn = lua_touserdata(L, -1); fn != nullptr) {
                matched = reinterpret_cast<inheritance_check>(fn)(qualified_name<T>());
            }

            lua_pop(L, 1);
        }

        lua_pop(L, 1); // the metatable
        return matched;
    }
}

// Reads a userdata of T as a pointer: the block's own slot, then the base
// chain, which adjusts the pointer for the requested base. A nil argument
// reads as a null pointer, which is what a T* parameter made of an omitted
// argument.
template <typename T>
inline T* get_pointer(lua_State* L, int index) {
    if constexpr (!detail::has_usertype_name<T>::value) {
        (void)L;
        (void)index;
        return nullptr;
    } else {
        if (lua_type(L, index) == LUA_TNIL) {
            return nullptr;
        }

        void* memory = align_pointer_slot(lua_touserdata(L, index));
        void* udata = *static_cast<void**>(memory);

        if (lua_getmetatable(L, index) == 1) {
            lua_getfield(L, -1, kClassCastKey);

            if (void* fn = lua_touserdata(L, -1); fn != nullptr) {
                udata = reinterpret_cast<inheritance_cast>(fn)(udata, qualified_name<T>());
            }

            lua_pop(L, 2);
        }

        return static_cast<T*>(udata);
    }
}

// Reads a userdata of T as the value it holds, without copying. The receiver
// of a method call and every by-reference parameter go through here.
template <typename T>
inline T& get_ref(lua_State* L, int index) {
    return *get_pointer<T>(L, index);
}

// Whether the value at `index` can be read as T. The scalar branches pin
// sol2's checks: a bool had to be a bool, a number had to be a number (either
// subtype, and a numeric string was not one), a string had to be a string.
template <typename T>
inline bool check(lua_State* L, int index) {
    using U = std::remove_const_t<std::remove_reference_t<T>>;

    if constexpr (std::is_same_v<U, bool>) {
        return lua_isboolean(L, index) == 1;
    } else if constexpr (std::is_integral_v<U> || std::is_enum_v<U>) {
        return lua_type(L, index) == LUA_TNUMBER;
    } else if constexpr (std::is_floating_point_v<U>) {
        return lua_type(L, index) == LUA_TNUMBER;
    } else if constexpr (std::is_same_v<U, std::string> || std::is_same_v<U, std::string_view>
        || std::is_same_v<U, const char*> || std::is_same_v<U, char*>) {
        return lua_type(L, index) == LUA_TSTRING;
    } else if constexpr (std::is_same_v<U, void*> || std::is_same_v<U, const void*>) {
        const int actual = lua_type(L, index);
        return actual == LUA_TUSERDATA || actual == LUA_TLIGHTUSERDATA;
    } else if constexpr (std::is_same_v<U, object> || std::is_same_v<U, reference>) {
        // A reference parameter binds to anything, the way sol2's poly check
        // always answered yes for its own reference types.
        return true;
    } else if constexpr (std::is_same_v<U, protected_function>) {
        return check_callable(L, index);
    } else if constexpr (std::is_pointer_v<U>) {
        return check_userdata<std::remove_pointer_t<U>>(L, index, true);
    } else {
        return check_userdata<U>(L, index, false);
    }
}

// Reads the value at `index` as T. The reads are the loose ones sol2's getters
// performed: a float read is a lua_tonumber (0 for anything else), an integral
// read rounds a float through llround and lets lua_tonumber convert a numeric
// string, an enum read is a bare lua_tointegerx. Only callers that first ran
// check reach the class branches.
template <typename T>
inline decltype(auto) get(lua_State* L, int index) {
    using U = std::remove_const_t<std::remove_reference_t<T>>;

    if constexpr (std::is_same_v<U, bool>) {
        return lua_toboolean(L, index) != 0;
    } else if constexpr (std::is_enum_v<U>) {
        return static_cast<U>(lua_tointegerx(L, index, nullptr));
    } else if constexpr (std::is_integral_v<U>) {
        if (lua_isinteger(L, index) != 0) {
            return static_cast<U>(lua_tointeger(L, index));
        }

        return static_cast<U>(llround(lua_tonumber(L, index)));
    } else if constexpr (std::is_floating_point_v<U>) {
        return static_cast<U>(lua_tonumber(L, index));
    } else if constexpr (std::is_same_v<U, std::string>) {
        std::size_t len = 0;
        const char* str = lua_tolstring(L, index, &len);
        return str != nullptr ? std::string(str, len) : std::string();
    } else if constexpr (std::is_same_v<U, std::string_view>) {
        // A view into the Lua string itself: valid only for the duration of the
        // call, which is what a string_view parameter was under sol2.
        std::size_t len = 0;
        const char* str = lua_tolstring(L, index, &len);
        return str != nullptr ? std::string_view(str, len) : std::string_view();
    } else if constexpr (std::is_same_v<U, const char*> || std::is_same_v<U, char*>) {
        std::size_t len = 0;
        return lua_tolstring(L, index, &len);
    } else if constexpr (std::is_same_v<U, void*> || std::is_same_v<U, const void*>) {
        // A read of void* is the raw block: userdata and lightuserdata alike,
        // which is what made sol2's get<void*> usable on both shapes.
        return lua_touserdata(L, index);
    } else if constexpr (std::is_same_v<U, object> || std::is_same_v<U, reference>) {
        // A read into a reference type makes a new reference to the slot; a
        // none or nil there becomes a nil reference, which is how an omitted
        // argument reached a sol::object parameter.
        return U(L, index);
    } else if constexpr (std::is_same_v<U, protected_function>) {
        return protected_function(L, index);
    } else if constexpr (std::is_pointer_v<U>) {
        return get_pointer<std::remove_pointer_t<U>>(L, index);
    } else {
        // A class read, by reference or by value, is the value the block
        // holds; sol2's getter returned the reference either way.
        return get_ref<U>(L, index);
    }
}

// Pushes nil.
inline int put(lua_State* L, nil_t) {
    lua_pushnil(L);
    return 1;
}

// Pushes what a reference holds. An invalid reference lands as nil, which is
// the shape every sol::object return of the bindings relied on.
inline int put(lua_State* L, const class object& value);

// Pushes a plain reference by value, for a return that only had a reference.
inline int put(lua_State* L, const class reference& value);

// Pushes a table by reference, never as a value block.
inline int put(lua_State* L, const class table& value);

// Pushes a scalar, a string, a math value or a pointer. The branches are the
// pushers sol2 selected for the same types: an integral becomes an integer, a
// floating becomes a number, a class becomes a value block under its value
// metatable, a pointer becomes a block holding it under its pointer metatable.
template <typename T>
inline int put(lua_State* L, const T& value);

template <typename T>
inline int push_value(lua_State* L, const T& value);

template <typename T>
inline int push_pointer(lua_State* L, T* obj);

template <typename T>
inline int put(lua_State* L, const T& value) {
    // Decayed, so a string literal or a char array lands on the string branch
    // instead of being read as a pointer to its first character.
    using U = std::decay_t<T>;

    if constexpr (std::is_same_v<U, bool>) {
        lua_pushboolean(L, value != 0);
        return 1;
    } else if constexpr (std::is_enum_v<U>) {
        lua_pushinteger(L, static_cast<lua_Integer>(value));
        return 1;
    } else if constexpr (std::is_integral_v<U>) {
        lua_pushinteger(L, static_cast<lua_Integer>(value));
        return 1;
    } else if constexpr (std::is_floating_point_v<U>) {
        lua_pushnumber(L, static_cast<lua_Number>(value));
        return 1;
    } else if constexpr (std::is_same_v<U, std::string>) {
        lua_pushlstring(L, value.data(), value.size());
        return 1;
    } else if constexpr (std::is_same_v<U, const char*> || std::is_same_v<U, char*>) {
        lua_pushstring(L, value);
        return 1;
    } else if constexpr (std::is_same_v<U, void*> || std::is_same_v<U, const void*>) {
        // sol2 pushed a void* as a lightuserdata, never as a userdata block.
        lua_pushlightuserdata(L, const_cast<void*>(value));
        return 1;
    } else if constexpr (detail::is_std_vector<U>::value) {
        // A vector return is the flat sequence table sol2 produced for it.
        lua_createtable(L, static_cast<int>(value.size()), 0);

        for (std::size_t i = 0; i < value.size(); ++i) {
            put(L, static_cast<const typename U::value_type&>(value[i]));
            lua_rawseti(L, -2, static_cast<lua_Integer>(i + 1));
        }

        return 1;
    } else if constexpr (std::is_pointer_v<U>) {
        return push_pointer<std::remove_pointer_t<U>>(L, value);
    } else {
        return push_value(L, value);
    }
}

// Sets the metatable named `key` on the userdata at the top, creating it when
// it does not exist. A fresh metatable receives what sol2's undefined-methods
// setup wrote: a destructor for a value form (pointers are never destructed),
// an always-false __eq, and a __type table naming the type.
template <typename T>
inline void ensure_metatable(lua_State* L, const std::string& key, bool value_form) {
    if (luaL_newmetatable(L, key.c_str()) == 1) {
        // Lua 5.4's tostring falls back to __name, and sol2 set it to the same
        // string it used as the registry key.
        lua_pushlstring(L, key.data(), key.size());
        lua_setfield(L, -2, "__name");

        if (value_form) {
            lua_pushcfunction(L, &value_gc<T>);
            lua_setfield(L, -2, "__gc");
        }

        lua_pushcfunction(
            L, [](lua_State* ls) {
                lua_pushboolean(ls, 0);
                return 1;
            });
        lua_setfield(L, -2, "__eq");

        lua_createtable(L, 0, 2);
        lua_pushstring(L, usertype_name<T>::value);
        lua_setfield(L, -2, "name");
        lua_pushcclosure(
            L,
            [](lua_State* ls) -> int {
                return put(ls, check_userdata<T>(ls, 1, false));
            },
            0);
        lua_setfield(L, -2, "is");
        lua_setfield(L, -2, "__type");
    }

    lua_setmetatable(L, -2);
}

// Pushes a value the state owns: a block with a pointer slot aiming at the
// value, under the value-form metatable. The destructor runs from __gc when
// Lua collects it.
template <typename T>
inline int push_value(lua_State* L, const T& value) {
    void* block = lua_newuserdatauv(L, value_block_size<T>(), 0);
    void* slot = align_pointer_slot(block);
    T* data = static_cast<T*>(value_block_target<T>(slot));
    *static_cast<T**>(slot) = data;
    new (data) T(value);

    ensure_metatable<T>(L, value_metatable<T>(), true);
    return 1;
}

// Pushes a plain pointer to a T: a block holding it, under the pointer-form
// metatable, with no destructor -- the memory belongs to someone else.
template <typename T>
inline int push_pointer_plain(lua_State* L, T* obj) {
    if (obj == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    void* block = lua_newuserdatauv(L, sizeof(void*), 0);
    *static_cast<T**>(align_pointer_slot(block)) = obj;

    ensure_metatable<T>(L, pointer_metatable<T>(), false);
    return 1;
}

// A pointer push goes through the binding's own pusher when it has one, so the
// reference accounting Sdk.cpp keeps for engine objects still runs; every other
// type gets the plain block.
template <typename T>
inline int push_pointer(lua_State* L, T* obj) {
    if constexpr (detail::pointer_push_override<T>::value) {
        return lua_stack_push(pointer_tag<T>{}, L, obj);
    } else {
        return push_pointer_plain(L, obj);
    }
}

// The container table the borrowed cache lives in: one weak-valued table per
// type, keyed by the value-form name. It is owned here instead of the
// "_sol_lua_push_usertypes" global sol2's pusher managed, so the container is
// reachable only through the registry and cannot collide with a script global.
inline constexpr const char* kBorrowedContainerKey = "\x01lua_stack.push_usertypes";

// Leaves the per-type weak table on the stack.
inline void push_borrowed_cache(lua_State* L, const char* key) {
    lua_getfield(L, LUA_REGISTRYINDEX, kBorrowedContainerKey);

    if (lua_type(L, -1) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_REGISTRYINDEX, kBorrowedContainerKey);
    }

    lua_pushstring(L, key);
    lua_rawget(L, -2);

    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);

        lua_createtable(L, 0, 0);
        lua_createtable(L, 0, 1);
        lua_pushstring(L, "v");
        lua_setfield(L, -2, "__mode");
        lua_setmetatable(L, -2);

        lua_pushstring(L, key);
        lua_pushvalue(L, -2);
        lua_rawset(L, -4);
    }

    // Leaves the weak table on the stack and drops the container.
    lua_remove(L, -2);
}

// Pushes a pointer to memory the state does not own, cached per address so a
// repeated read yields the same userdata and comparing two reads is a pointer
// comparison. The cache is weak-valued: an unreferenced element can be
// collected, and the next read makes a fresh userdata. No reference counting
// happens here -- engine pointers that must be counted go through the
// managed pusher in Sdk.cpp, which is where that bookkeeping lives.
template <typename T>
inline int push_borrowed(lua_State* L, T* obj) {
    if (obj == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    push_borrowed_cache(L, value_metatable<T>().c_str());

    // Absolute, because the relative index would shift as the stack grows.
    const int cache = lua_gettop(L);

    lua_pushlightuserdata(L, reinterpret_cast<void*>(obj));
    lua_rawget(L, cache);

    if (!lua_isnil(L, -1)) {
        // The cached userdata replaces the cache table below it.
        lua_replace(L, cache);
        lua_settop(L, cache);
        return 1;
    }

    lua_pop(L, 1);

    push_pointer_plain<T>(L, obj);

    // The new userdata becomes the result while a second reference goes into
    // the cache under the address that produced it.
    lua_pushlightuserdata(L, reinterpret_cast<void*>(obj));
    lua_pushvalue(L, -2);
    lua_rawset(L, cache);

    lua_replace(L, cache);
    lua_settop(L, cache);
    return 1;
}

// Builds a value the state owns the way a constructor does: the value in place
// in the userdata block, under the owned-value metatable the installer gave a
// __gc. This is the shape the hand-written constructors already produce; it
// differs from push_value's block, which is why the two carry different
// metatable names (see SOL2_REMOVAL.md for the layout note).
template <typename T, typename... Args>
inline int construct_value(lua_State* L, Args&&... args) {
    void* storage = lua_newuserdatauv(L, sizeof(T), 0);
    new (storage) T(std::forward<Args>(args)...);

    // The installer owns this metatable and the __gc on it; it is only created
    // here when a constructor ran without one, so the value is never left
    // metatable-less.
    if (luaL_getmetatable(L, unique_metatable<T>().c_str()) == LUA_TNIL) {
        lua_pop(L, 1);
        luaL_newmetatable(L, unique_metatable<T>().c_str());
    }

    lua_setmetatable(L, -2);

    return 1;
}

// A registry reference. The ref is LUA_NOREF when there is nothing behind it
// and LUA_REFNIL when it names nil, which is what a luaL_ref of a nil made of
// it; valid() is false for both -- sol2 never counted a nil as a live
// reference.
class reference {
public:
    reference() noexcept : m_L(nullptr), m_ref(LUA_NOREF) {}

    reference(nil_t) noexcept : reference() {}

    // References the value at `index`. A none or nil there becomes LUA_REFNIL,
    // which is how an omitted argument reached a sol::object parameter.
    reference(lua_State* L, int index) noexcept {
        lua_pushvalue(L, index);
        m_L = L;
        m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    }

    reference(const reference& other) noexcept {
        if (other.m_ref == LUA_NOREF) {
            m_L = other.m_L;
            m_ref = LUA_NOREF;
            return;
        }

        other.push();
        m_L = other.m_L;
        m_ref = luaL_ref(m_L, LUA_REGISTRYINDEX);
    }

    reference(reference&& other) noexcept : m_L(other.m_L), m_ref(other.m_ref) {
        other.m_ref = LUA_NOREF;
    }

    reference& operator=(const reference& other) noexcept {
        if (this != &other) {
            unref();

            if (other.m_ref == LUA_NOREF) {
                m_L = other.m_L;
                m_ref = LUA_NOREF;
            } else {
                other.push();
                m_L = other.m_L;
                m_ref = luaL_ref(m_L, LUA_REGISTRYINDEX);
            }
        }

        return *this;
    }

    reference& operator=(reference&& other) noexcept {
        if (this != &other) {
            unref();
            m_L = other.m_L;
            m_ref = other.m_ref;
            other.m_ref = LUA_NOREF;
        }

        return *this;
    }

    ~reference() noexcept {
        unref();
    }

    lua_State* lua_state() const noexcept { return m_L; }

    int registry_index() const noexcept { return m_ref; }

    bool valid() const noexcept { return !(m_ref == LUA_NOREF || m_ref == LUA_REFNIL); }

    // Pushes what the reference holds; a dead or nil reference pushes nil.
    int push(lua_State* L) const noexcept {
        lua_rawgeti(L, LUA_REGISTRYINDEX, m_ref);
        return 1;
    }

    int push() const noexcept { return push(m_L); }

    int type() const noexcept {
        push();
        const int actual = lua_type(m_L, -1);
        lua_pop(m_L, 1);
        return actual;
    }

    // Drops the reference without running the destructor's unref, for a
    // reference handed to Lua or to another owner.
    void abandon() noexcept {
        m_L = nullptr;
        m_ref = LUA_NOREF;
    }

    // Points the reference at nil, which is how a pooled table handle is marked
    // dead after its contents moved elsewhere.
    reference& operator=(nil_t) noexcept {
        unref();
        m_ref = LUA_REFNIL;
        return *this;
    }

protected:
    void unref() noexcept {
        if (m_L == nullptr || m_ref == LUA_NOREF) {
            return;
        }

        luaL_unref(m_L, LUA_REGISTRYINDEX, m_ref);
        m_ref = LUA_NOREF;
    }

    lua_State* m_L;
    int m_ref;
};

inline int put(lua_State* L, const object& value);

// A reference that answers type questions about what it holds. An omitted
// argument arrived as nil, which is what sol::object handed a binding.
class object : public reference {
public:
    using reference::reference;

    object() noexcept = default;

    // Whether the reference names nil (or holds nothing at all), which is what
    // a sol::object::is<nil_t>() test answered in the reference-counting code.
    bool is_nil() const noexcept { return m_ref == LUA_REFNIL || m_ref == LUA_NOREF; }

    template <typename T>
    bool is() const {
        if constexpr (std::is_same_v<std::remove_const_t<std::remove_reference_t<T>>, nil_t>) {
            return m_ref == LUA_REFNIL;
        } else {
            if (m_ref == LUA_REFNIL) {
                return false;
            }

            if (m_ref == LUA_NOREF) {
                return false;
            }

            push();
            const bool matched = check<T>(m_L, -1);
            lua_pop(m_L, 1);
            return matched;
        }
    }

    template <typename T>
    decltype(auto) as() const {
        push();
        decltype(auto) value = get<T>(m_L, -1);
        lua_pop(m_L, 1);
        return value;
    }
};

// Builds an object holding a freshly pushed value, which is what
// sol::make_object did for every return the bindings produce.
template <typename T>
inline object make_object(lua_State* L, T&& value) {
    put(L, std::forward<T>(value));
    object made(L, -1);
    lua_pop(L, 1);
    return made;
}

// Pushes what an object holds. An invalid object lands as nil, which is the
// shape every sol::object return of the bindings relied on.
inline int put(lua_State* L, const object& value) {
    if (!value.valid()) {
        lua_pushnil(L);
        return 1;
    }

    value.push();
    return 1;
}

inline int put(lua_State* L, const reference& value) {
    if (!value.valid()) {
        lua_pushnil(L);
        return 1;
    }

    value.push();
    return 1;
}

// One element of a variadic argument list, answering the same questions a
// sol::object would about its own slot.
class stack_proxy {
public:
    stack_proxy(lua_State* L, int index) noexcept : m_L(L), m_index(index) {}

    lua_State* lua_state() const noexcept { return m_L; }

    int stack_index() const noexcept { return m_index; }

    template <typename T>
    bool is() const {
        return check<T>(m_L, m_index);
    }

    template <typename T>
    decltype(auto) as() const {
        // Qualified: the member get above would otherwise hide the stack layer's
        // get and the call would resolve back into this class.
        return lua_stack::get<T>(m_L, m_index);
    }

    template <typename T>
    decltype(auto) get() const {
        return lua_stack::get<T>(m_L, m_index);
    }

private:
    lua_State* m_L;
    int m_index;
};

// The trailing arguments of a call, rooted at `index`. sol2 froze the stack
// top when the list was built, and so does this: the count is what the caller
// pushed, not what the stack says later.
class variadic_args {
public:
    variadic_args(lua_State* L, int index) noexcept : m_L(L), m_index(index), m_top(lua_gettop(L)) {}

    lua_State* lua_state() const noexcept { return m_L; }

    int stack_index() const noexcept { return m_index; }

    int leftover_count() const noexcept { return m_top - (m_index - 1); }

    std::size_t size() const noexcept { return static_cast<std::size_t>(leftover_count()); }

    stack_proxy operator[](int offset) const noexcept { return stack_proxy(m_L, m_index + offset); }

    template <typename T>
    decltype(auto) get(int offset = 0) const {
        return lua_stack::get<T>(m_L, m_index + offset);
    }

    // Pushes every remaining argument, which is how a pass-through forwards
    // the tail of a call to the next function.
    int push(lua_State* target = nullptr) const {
        lua_State* to = target != nullptr ? target : m_L;
        int count = 0;

        for (int i = m_index; i <= m_top; ++i) {
            lua_pushvalue(m_L, i);
            ++count;
        }

        if (to != m_L) {
            lua_xmove(m_L, to, count);
        }

        return count;
    }

    class iterator {
    public:
        iterator(lua_State* L, int index) noexcept : m_L(L), m_index(index) {}

        stack_proxy operator*() const noexcept { return stack_proxy(m_L, m_index); }

        iterator& operator++() noexcept {
            ++m_index;
            return *this;
        }

        bool operator!=(const iterator& other) const noexcept { return m_index != other.m_index; }

    private:
        lua_State* m_L;
        int m_index;
    };

    iterator begin() const noexcept { return iterator(m_L, m_index); }

    iterator end() const noexcept { return iterator(m_L, m_top + 1); }

private:
    lua_State* m_L;
    int m_index;
    int m_top;
};

// How a protected call came out. The status values are Lua's own pcall codes,
// which is what sol2's call_status carried; Lua 5.4 dropped the gc code sol2
// named for 5.3, so it has no entry here.
struct call_status {
    enum value : int {
        ok = LUA_OK,
        yielded = LUA_YIELD,
        runtime = LUA_ERRRUN,
        syntax = LUA_ERRSYNTAX,
        memory = LUA_ERRMEM,
        handler = LUA_ERRERR,
        file = LUA_ERRFILE,
    };
};

// What a protected_function call left on the stack: where the first result
// sits, how many there are, and how many of them a replacement error handler
// would have to remove. Nothing is popped here -- sol2 left the values where
// they landed, and so does this.
class protected_function_result {
public:
    protected_function_result() noexcept = default;

    protected_function_result(lua_State* L, int index, int return_count, int pop_count, int status) noexcept
        : m_L(L), m_index(index), m_return_count(return_count), m_pop_count(pop_count), m_status(status) {}

    protected_function_result(protected_function_result&& other) noexcept
        : m_L(other.m_L), m_index(other.m_index), m_return_count(other.m_return_count), m_pop_count(other.m_pop_count),
        m_status(other.m_status) {
        other.abandon();
    }

    protected_function_result& operator=(protected_function_result&& other) noexcept {
        if (this != &other) {
            m_L = other.m_L;
            m_index = other.m_index;
            m_return_count = other.m_return_count;
            m_pop_count = other.m_pop_count;
            m_status = other.m_status;
            other.abandon();
        }

        return *this;
    }

    protected_function_result(const protected_function_result&) = delete;
    protected_function_result& operator=(const protected_function_result&) = delete;

    lua_State* lua_state() const noexcept { return m_L; }

    int stack_index() const noexcept { return m_index; }

    int return_count() const noexcept { return m_return_count; }

    int pop_count() const noexcept { return m_pop_count; }

    int status() const noexcept { return m_status; }

    bool valid() const noexcept { return m_status == call_status::ok || m_status == call_status::yielded; }

    // The first result, or the error object on a failed call. sol2 read the
    // slot the same way either way; callers that care check valid() first.
    template <typename T>
    decltype(auto) get(int offset = 0) const {
        return lua_stack::get<T>(m_L, m_index + offset);
    }

    void abandon() noexcept {
        m_L = nullptr;
        m_index = 0;
        m_return_count = 0;
        m_pop_count = 0;
        m_status = call_status::ok;
    }

private:
    lua_State* m_L = nullptr;
    int m_index = 0;
    int m_return_count = 0;
    int m_pop_count = 0;
    int m_status = call_status::ok;
};

// Pushes one call argument. A class-type pointer is pushed as a plain borrowed
// pointer; a binding that must count references to the object it hands over
// overloads this for its own pointer types (that is the seam Sdk.cpp's managed
// pusher plugs into).
template <typename T>
inline int push_call_argument(lua_State* L, T&& value) {
    return put(L, std::forward<T>(value));
}

// The global sol2 stored its default error handler under, and the handler
// itself: a traceback wrapped around whatever error reached it. A
// protected_function reads the same global so calls made through either
// library report through the same handler.
inline constexpr const char* kDefaultErrorHandlerKey = "sol.\xF0\x9F\x94\xA9";

inline int default_traceback_error_handler(lua_State* L) {
    std::string message = "An unknown error has triggered the default error handler";

    if (const char* top = lua_tostring(L, 1); top != nullptr) {
        message = top;
    }

    luaL_traceback(L, L, message.c_str(), 1);

    if (const char* traceback = lua_tostring(L, -1); traceback != nullptr) {
        message = traceback;
        lua_pop(L, 1);
        lua_pushlstring(L, message.data(), message.size());
    }

    return 1;
}

// A stored callback. The function is kept as a registry reference, exactly as
// sol::protected_function kept one, and called through lua_pcall with the
// default handler below it. A call made through a state sol2 initialized
// shares sol2's own handler; a call made through a state this header set up
// uses default_traceback_error_handler.
class protected_function {
public:
    protected_function() noexcept : m_L(nullptr), m_ref(LUA_NOREF), m_handler(LUA_NOREF) {}

    protected_function(nil_t) noexcept : protected_function() {}

    protected_function(lua_State* L, int index) noexcept {
        m_L = L;
        lua_pushvalue(L, index);
        m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
        m_handler = ref_default_handler(L);
    }

    protected_function(const protected_function& other) noexcept {
        copy_from(other);
    }

    protected_function(protected_function&& other) noexcept
        : m_L(other.m_L), m_ref(other.m_ref), m_handler(other.m_handler) {
        other.m_ref = LUA_NOREF;
        other.m_handler = LUA_NOREF;
    }

    protected_function& operator=(const protected_function& other) noexcept {
        if (this != &other) {
            unref();
            copy_from(other);
        }

        return *this;
    }

    protected_function& operator=(protected_function&& other) noexcept {
        if (this != &other) {
            unref();
            m_L = other.m_L;
            m_ref = other.m_ref;
            m_handler = other.m_handler;
            other.m_ref = LUA_NOREF;
            other.m_handler = LUA_NOREF;
        }

        return *this;
    }

    ~protected_function() noexcept {
        unref();
    }

    lua_State* lua_state() const noexcept { return m_L; }

    bool valid() const noexcept { return !(m_ref == LUA_NOREF || m_ref == LUA_REFNIL); }

    // Whether the stored value is nil, which is how the hook dispatch skips a
    // callback that was never provided. A function that holds nothing behaves
    // like one holding nil, the way a pushed sol2 function did.
    bool is_nil() const noexcept { return m_ref == LUA_REFNIL || m_ref == LUA_NOREF; }

    // Identity the way sol2 compared its references: two handles to the same
    // Lua value are equal even when they came from distinct registry entries.
    bool operator==(const protected_function& other) const noexcept {
        if (m_L != other.m_L) {
            return false;
        }

        if (m_ref == other.m_ref) {
            return true;
        }

        if (m_ref < 0 || other.m_ref < 0) {
            return false;
        }

        lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, other.m_ref);
        const bool equal = lua_rawequal(m_L, -1, -2) == 1;
        lua_pop(m_L, 2);
        return equal;
    }

    bool operator!=(const protected_function& other) const noexcept { return !(*this == other); }

    // Drops the stored function without unref, when ownership moved elsewhere.
    void abandon() noexcept {
        m_ref = LUA_NOREF;
        m_handler = LUA_NOREF;
    }

    // The stored function pushed onto the stack.
    int push() const noexcept {
        lua_rawgeti(m_L, LUA_REGISTRYINDEX, m_ref);
        return 1;
    }

    template <typename... Args>
    protected_function_result operator()(Args&&... args) const {
        lua_State* L = m_L;

        // The handler sits below the function for the whole call and is
        // removed after it, which is the placement sol2's protected handler
        // used; pcall leaves it on the stack in both the success and the
        // error case.
        int handler_index = 0;

        if (m_handler != LUA_NOREF && m_handler != LUA_REFNIL) {
            handler_index = lua_gettop(L) + 1;
            lua_rawgeti(L, LUA_REGISTRYINDEX, m_handler);
        }

        push();
        const int argument_count = (0 + ... + push_call_argument(L, std::forward<Args>(args)));

        const int stack_size = lua_gettop(L);
        int first_return = stack_size - argument_count - (handler_index != 0 ? 1 : 0);

        if (first_return < 1) {
            first_return = 1;
        }

        const int status = lua_pcall(L, argument_count, LUA_MULTRET, handler_index);

        const int post_stack_size = lua_gettop(L) - (handler_index != 0 ? 1 : 0);
        const int return_count = post_stack_size - (first_return - 1);

        if (handler_index != 0) {
            lua_remove(L, handler_index);
        }

        return protected_function_result(L, first_return, return_count, return_count, status);
    }

private:
    static int ref_default_handler(lua_State* L) {
        lua_getglobal(L, kDefaultErrorHandlerKey);
        const int ref = luaL_ref(L, LUA_REGISTRYINDEX);
        return ref;
    }

    void copy_from(const protected_function& other) noexcept {
        m_L = other.m_L;

        if (other.m_ref == LUA_NOREF) {
            m_ref = LUA_NOREF;
        } else {
            other.push();
            m_ref = luaL_ref(m_L, LUA_REGISTRYINDEX);
        }

        if (other.m_handler == LUA_NOREF || other.m_handler == LUA_REFNIL) {
            m_handler = other.m_handler;
        } else {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, other.m_handler);
            m_handler = luaL_ref(m_L, LUA_REGISTRYINDEX);
        }
    }

    void unref() noexcept {
        if (m_L == nullptr) {
            return;
        }

        if (m_ref != LUA_NOREF) {
            luaL_unref(m_L, LUA_REGISTRYINDEX, m_ref);
            m_ref = LUA_NOREF;
        }

        if (m_handler != LUA_NOREF) {
            luaL_unref(m_L, LUA_REGISTRYINDEX, m_handler);
            m_handler = LUA_NOREF;
        }
    }

    lua_State* m_L;
    int m_ref;
    int m_handler;
};

// The error path of a failed callback: format the status into the message
// sol2 produced, swap it for the error object on the stack, and raise. The
// message is "sol: <status> error: <what Lua reported>", and the runtime
// status is the one every script error carries.
inline protected_function_result script_default_on_error(lua_State* L, protected_function_result result) {
    if (result.valid()) {
        return result;
    }

    // Indexed by Lua's own pcall status codes, which is what a result
    // carries; the names are sol2's.
    static const char* status_names[8] = {"ok", "yielded", "runtime", "syntax", "memory", "gc", "handler", "file"};

    const int status = result.status();
    const char* status_name = "CRITICAL_INDETERMINATE_STATE_FAILURE";

    if (status >= call_status::ok && status <= call_status::file) {
        status_name = status_names[status];
    }

    std::string message = std::string("sol: ") + status_name + " error";

    if (const char* reported = lua_tostring(L, result.stack_index()); reported != nullptr) {
        message += ": ";
        message += reported;
    }

    // The error object sits where the first result would have been; remove it
    // before the message takes its place, which is the replacement sol2's
    // throw-on-error did.
    for (int removed = 0; removed < result.pop_count(); ++removed) {
        lua_remove(L, result.stack_index());
    }

    lua_pushlstring(L, message.data(), message.size());
    throw error(message);
}

// A Lua table held by registry reference. It answers the reads and writes the
// script state's own tables need: a scalar or a reference at a string or an
// integer key, the nil write that clears an entry, and the clear() a pooled
// table handle runs before it is handed out again.
class table : public reference {
public:
    using reference::reference;
    using reference::operator=;

    table() noexcept = default;
    table(nil_t) noexcept {}
    table(lua_State* L, int index) noexcept
        : reference(L, index) {}

    template <typename T>
    T get(const char* key) const {
        push();
        lua_getfield(m_L, -1, key);
        T value = read_slot<T>(m_L, -1);
        lua_pop(m_L, 2);
        return value;
    }

    template <typename T>
    T get(lua_Integer key) const {
        push();
        lua_geti(m_L, -1, key);
        T value = read_slot<T>(m_L, -1);
        lua_pop(m_L, 2);
        return value;
    }

    template <typename T>
    std::optional<T> get_optional(const char* key) const {
        push();
        lua_getfield(m_L, -1, key);
        std::optional<T> value = read_optional<T>(m_L, -1);
        lua_pop(m_L, 2);
        return value;
    }

    template <typename T>
    std::optional<T> get_optional(lua_Integer key) const {
        push();
        lua_geti(m_L, -1, key);
        std::optional<T> value = read_optional<T>(m_L, -1);
        lua_pop(m_L, 2);
        return value;
    }

    template <typename V>
    void set(const char* key, V&& value) {
        push();
        put(m_L, std::forward<V>(value));
        lua_setfield(m_L, -2, key);
        lua_pop(m_L, 1);
    }

    template <typename V>
    void set(lua_Integer key, V&& value) {
        push();
        put(m_L, std::forward<V>(value));
        lua_seti(m_L, -2, key);
        lua_pop(m_L, 1);
    }

    void set_nil(const char* key) { set(key, lua_nil); }
    void set_nil(lua_Integer key) { set(key, lua_nil); }

    void set_cfunction(const char* key, lua_CFunction fn) {
        push();
        lua_pushcfunction(m_L, fn);
        lua_setfield(m_L, -2, key);
        lua_pop(m_L, 1);
    }

    int size() const {
        push();
        const int length = static_cast<int>(luaL_len(m_L, -1));
        lua_pop(m_L, 1);
        return length;
    }

    // Empties the table in place, which is what a pooled table needs before it
    // is reused: the handle survives, the contents do not.
    void clear() {
        push();
        const int table_index = lua_gettop(m_L);

        lua_pushnil(m_L);

        while (lua_next(m_L, table_index) != 0) {
            lua_pop(m_L, 1);            // the value
            lua_pushvalue(m_L, -1);     // the key, for the write
            lua_pushnil(m_L);
            lua_rawset(m_L, table_index);
        }

        lua_pop(m_L, 1);
    }

private:
    template <typename T>
    static T read_slot(lua_State* L, int index) {
        using U = std::remove_const_t<std::remove_reference_t<T>>;

        if constexpr (std::is_same_v<U, object> || std::is_same_v<U, table> || std::is_same_v<U, reference>) {
            return U(L, index);
        } else {
            return lua_stack::get<T>(L, index);
        }
    }

    template <typename T>
    static std::optional<T> read_optional(lua_State* L, int index) {
        using U = std::remove_const_t<std::remove_reference_t<T>>;
        std::optional<T> value;

        if (lua_isnil(L, index)) {
            return value;
        }

        if constexpr (std::is_same_v<U, object> || std::is_same_v<U, table> || std::is_same_v<U, reference>) {
            value.emplace(L, index);
        } else if (check<T>(L, index)) {
            value.emplace(lua_stack::get<T>(L, index));
        }

        return value;
    }
};

inline int put(lua_State* L, const table& value) {
    if (!value.valid()) {
        lua_pushnil(L);
        return 1;
    }

    value.push();
    return 1;
}

// A fresh table held by reference, for code that has a lua_State but no state
// object at hand.
inline table create_table(lua_State* L, int array = 0, int hash = 0) {
    lua_createtable(L, array, hash);
    table result(L, -1);
    lua_pop(L, 1);
    return result;
}

// The global table named `key`, created empty when nothing is there yet.
inline table global_table(lua_State* L, const char* key) {
    lua_getglobal(L, key);

    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_setglobal(L, key);
    }

    table result(L, -1);
    lua_pop(L, 1);
    return result;
}

// The registry table named `key`, created empty when nothing is there yet.
inline table registry_table(lua_State* L, const char* key) {
    lua_getfield(L, LUA_REGISTRYINDEX, key);

    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_setfield(L, LUA_REGISTRYINDEX, key);
    }

    table result(L, -1);
    lua_pop(L, 1);
    return result;
}

// Reads the registry entry named `key`. A pointer type reads the entry as the
// lightuserdata it was written as.
template <typename T>
inline T registry_get(lua_State* L, const char* key) {
    lua_getfield(L, LUA_REGISTRYINDEX, key);

    if constexpr (std::is_pointer_v<T>) {
        T value = static_cast<T>(lua_touserdata(L, -1));
        lua_pop(L, 1);
        return value;
    } else {
        T value = lua_stack::get<T>(L, -1);
        lua_pop(L, 1);
        return value;
    }
}

template <typename V>
inline void registry_set(lua_State* L, const char* key, V&& value) {
    put(L, std::forward<V>(value));
    lua_setfield(L, LUA_REGISTRYINDEX, key);
}

// A pointer written into the registry as a lightuserdata: the script state
// records itself under "state" this way, and every reader casts it back.
inline void registry_set_pointer(lua_State* L, const char* key, void* value) {
    lua_pushlightuserdata(L, value);
    lua_setfield(L, LUA_REGISTRYINDEX, key);
}

// The five status names a failed protected call reports. Lua 5.4 dropped the
// gc code sol2 named for 5.3, so it has no entry here.
inline const char* status_name(int status) {
    switch (status) {
    case LUA_OK:
        return "ok";
    case LUA_YIELD:
        return "yielded";
    case LUA_ERRRUN:
        return "runtime";
    case LUA_ERRSYNTAX:
        return "syntax";
    case LUA_ERRMEM:
        return "memory";
    case LUA_ERRERR:
        return "handler";
    case LUA_ERRFILE:
        return "file";
    default:
        return "CRITICAL_INDETERMINATE_STATE_FAILURE";
    }
}

// A Lua state owned outright. It replaces the `sol::state` member ScriptState
// held: the same libraries are opened, the same default traceback handler is
// installed under the global sol2 read it from, and a script file is loaded and
// called with the same error text a failed sol2 load produced.
class state {
public:
    state() {
        m_L = luaL_newstate();

        if (m_L == nullptr) {
            throw error("luaL_newstate failed");
        }

        lua_pushcfunction(m_L, &default_traceback_error_handler);
        lua_setglobal(m_L, kDefaultErrorHandlerKey);
    }

    ~state() {
        if (m_L != nullptr) {
            lua_close(m_L);
        }
    }

    state(const state&) = delete;
    state& operator=(const state&) = delete;

    state(state&& other) noexcept
        : m_L(other.m_L) {
        other.m_L = nullptr;
    }

    state& operator=(state&& other) noexcept {
        if (this != &other) {
            if (m_L != nullptr) {
                lua_close(m_L);
            }

            m_L = other.m_L;
            other.m_L = nullptr;
        }

        return *this;
    }

    lua_State* lua_state() const noexcept { return m_L; }

    // The libraries sol::state opened: its constructor opened the full set
    // (including io) before ScriptState asked for its own list, so io is part
    // of the surface every script saw. bit32 is absent on this Lua version,
    // exactly as sol2's lib::bit32 was.
    void open_libraries() {
        static const luaL_Reg libraries[] = {
            {"base", luaopen_base},
            {"package", luaopen_package},
            {"coroutine", luaopen_coroutine},
            {"string", luaopen_string},
            {"os", luaopen_os},
            {"io", luaopen_io},
            {"table", luaopen_table},
            {"math", luaopen_math},
            {"utf8", luaopen_utf8},
            {"debug", luaopen_debug},
        };

        for (const auto& library : libraries) {
            luaL_requiref(m_L, library.name, library.func, 1);
            lua_pop(m_L, 1);
        }
    }

    table create_table(int array = 0, int hash = 0) {
        return lua_stack::create_table(m_L, array, hash);
    }

    // Runs a chunk and drops its results; a failure leaves nothing behind, the
    // way the ignored sol2 do_string return did.
    void do_string(const char* code) {
        if (luaL_dostring(m_L, code) != LUA_OK) {
            lua_pop(m_L, 1);
        }
    }

    void safe_script_file(const std::string& path) {
        const int load_status = luaL_loadfile(m_L, path.c_str());

        if (load_status != LUA_OK) {
            const char* reported = lua_tostring(m_L, -1);
            const std::string message = reported != nullptr ? reported : "unknown error";
            lua_pop(m_L, 1);
            throw error(std::string("sol: ") + status_name(load_status) + " error: " + message);
        }

        protected_function chunk(m_L, -1);
        lua_pop(m_L, 1);

        protected_function_result result = chunk();

        if (!result.valid()) {
            script_default_on_error(m_L, std::move(result));
        }

        lua_settop(m_L, result.stack_index() - 1);
    }

private:
    lua_State* m_L{nullptr};
};
} // namespace lua_stack
