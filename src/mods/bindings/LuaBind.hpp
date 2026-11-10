#pragma once

#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include <lua.hpp>

#include "LuaStack.hpp"

// Raw lua_State helpers for the hand-written binding tables. The per-type stack
// primitives come from lua_stack (LuaStack.hpp), so a single binding no longer
// instantiates the argument marshalling chain for its own signature.
namespace lh {
// Lua strings can arrive as nil; ImGui expects non-null throughout.
inline const char* str(lua_State* L, int index) {
    return lua_isnoneornil(L, index) ? "" : luaL_checkstring(L, index);
}

inline bool is_none(lua_State* L, int index) { return lua_isnoneornil(L, index) != 0; }
inline bool is_int(lua_State* L, int index) { return lua_isinteger(L, index) != 0; }
inline bool is_num(lua_State* L, int index) { return lua_isnumber(L, index) != 0; }
inline bool is_bool(lua_State* L, int index) { return lua_isboolean(L, index) != 0; }
inline bool is_str(lua_State* L, int index) { return lua_type(L, index) == LUA_TSTRING; }
inline bool is_ptr(lua_State* L, int index) { return lua_type(L, index) == LUA_TLIGHTUSERDATA; }
inline bool is_table(lua_State* L, int index) { return lua_istable(L, index) != 0; }

// The key of an array or SystemArray access. sol2 read a typed integral
// parameter through Lua's own conversion, so 1, 1.0 and "1" all indexed an
// array; only a key Lua cannot turn into a number was refused.
inline bool is_index(lua_State* L, int index) { return lua_isnumber(L, index) != 0; }

inline int index_int(lua_State* L, int index) {
    return is_int(L, index) ? static_cast<int>(lua_tointeger(L, index)) : static_cast<int>(lua_tonumber(L, index));
}

inline unsigned index_uint(lua_State* L, int index) {
    return is_int(L, index) ? static_cast<unsigned>(lua_tointeger(L, index)) : static_cast<unsigned>(lua_tonumber(L, index));
}

// Optional arguments: the default is used whenever the argument is absent or
// of a different Lua type, matching what sol2 did for a typed parameter.
inline int opt_int(lua_State* L, int index, int def) {
    return is_int(L, index) ? static_cast<int>(lua_tointeger(L, index)) : def;
}

inline unsigned opt_uint(lua_State* L, int index, unsigned def) {
    return is_int(L, index) ? static_cast<unsigned>(lua_tointeger(L, index)) : def;
}

inline float opt_num(lua_State* L, int index, float def) {
    return is_num(L, index) ? static_cast<float>(lua_tonumber(L, index)) : def;
}

inline bool opt_bool(lua_State* L, int index, bool def) {
    return is_bool(L, index) ? lua_toboolean(L, index) != 0 : def;
}

inline const char* opt_str(lua_State* L, int index, const char* def) {
    return is_str(L, index) ? lua_tostring(L, index) : def;
}

inline void* opt_ptr(lua_State* L, int index) {
    return is_ptr(L, index) ? lua_touserdata(L, index) : nullptr;
}

// Required scalars.
inline int num_int(lua_State* L, int index) {
    return static_cast<int>(luaL_checkinteger(L, index));
}

inline unsigned num_uint(lua_State* L, int index) {
    return static_cast<unsigned>(luaL_checkinteger(L, index));
}

inline float num_float(lua_State* L, int index) {
    return static_cast<float>(luaL_checknumber(L, index));
}

inline bool num_bool(lua_State* L, int index) {
    luaL_checkany(L, index);
    return lua_toboolean(L, index) != 0;
}

template <typename T>
inline bool is(lua_State* L, int index) {
    return lua_stack::check<T>(L, index);
}

template <typename T>
inline T get(lua_State* L, int index) {
    return lua_stack::get<T>(L, index);
}

// A typed parameter that a Lua caller may not omit: the type mismatch becomes
// the same Lua error a sol2-checked argument produced.
template <typename T>
inline T get_checked(lua_State* L, int index, const char* what) {
    if (!lua_stack::check<T>(L, index)) {
        throw std::runtime_error(what);
    }

    return lua_stack::get<T>(L, index);
}

template <typename T>
inline T& get_ref(lua_State* L, int index) {
    return lua_stack::get_ref<T>(L, index);
}

// A typed argument read by reference: sol2 handed a `T&` parameter a reference
// into the userdata, so a thunk must not copy. Only arguments reach here; the
// receiver goes through get_self.
template <typename T>
inline T& get_arg_ref(lua_State* L, int index, const char* type_name) {
    if (!lua_stack::check<T*>(L, index)) {
        throw std::runtime_error(std::string("expected ") + type_name + ", got " + luaL_typename(L, index));
    }

    return lua_stack::get_ref<T>(L, index);
}

// Pushes a Lua value and reports one result, so a thunk body can end with a
// plain `return put(L, value);` however the value reaches the stack.
inline int put(lua_State* L, const lua_stack::nil_t&) {
    lua_pushnil(L);
    return 1;
}

// A reference carries whatever identity the function it came from made, so it
// is pushed through its own accessor instead of the value pusher.
inline int put(lua_State* L, const lua_stack::object& value) {
    return lua_stack::put(L, value);
}

inline int put(lua_State* L, const lua_stack::table& value) {
    return lua_stack::put(L, value);
}

template <typename T>
inline int put(lua_State* L, const T& value) {
    return lua_stack::put(L, value);
}

// Pushes a Lua table holding the elements of a flat sequence, which is what
// sol2 produced for a std::vector return.
template <typename T>
inline void put_seq(lua_State* L, const std::vector<T>& values) {
    lua_createtable(L, static_cast<int>(values.size()), 0);

    for (size_t i = 0; i < values.size(); ++i) {
        lh::put(L, values[i]);
        lua_rawseti(L, -2, static_cast<lua_Integer>(i + 1));
    }
}

template <typename T>
inline int push_borrowed(lua_State* L, T* obj);

// Pushes a pointer to memory the state does not own -- an element of a live game
// array. The pushed userdata is cached per address, so a repeated read yields
// the same object and comparing two elements is a pointer comparison.
template <typename T>
inline int put_borrowed(lua_State* L, T* obj) {
    return push_borrowed<T>(L, obj);
}

// Sets a name -> integer map on the table at the top of the stack.
template <size_t N>
inline void put_enum(lua_State* L, const char* name, const std::pair<const char*, lua_Integer> (&entries)[N]) {
    lua_createtable(L, 0, static_cast<int>(N));

    for (size_t i = 0; i < N; ++i) {
        lua_pushinteger(L, entries[i].second);
        lua_setfield(L, -2, entries[i].first);
    }

    lua_setfield(L, -2, name);
}

// A Lua argument that is not on the stack arrives as nil, which is what sol2
// handed to a sol::object parameter.
inline lua_stack::object get_object(lua_State* L, int index) {
    if (lua_isnone(L, index)) {
        lua_pushnil(L);
    }

    return lua_stack::object(L, index);
}

// The trailing arguments of a thunk, rooted at `first`, wrapped so that an
// existing variadic_args parameter keeps working unchanged.
inline lua_stack::variadic_args get_rest(lua_State* L, int first) {
    return lua_stack::variadic_args{L, first};
}

// How many Lua stack slots one C++ parameter consumes. A lua_State parameter is
// manufactured from the call instead of being read.
template <typename A>
struct slot_count : std::integral_constant<int, 1> {};

template <>
struct slot_count<lua_State*> : std::integral_constant<int, 0> {};

template <typename Tuple, size_t I>
struct slots_before
: std::integral_constant<int, slot_count<std::tuple_element_t<I - 1, Tuple>>::value + slots_before<Tuple, I - 1>::value> {};

template <typename Tuple>
struct slots_before<Tuple, 0> : std::integral_constant<int, 0> {};

template <typename A>
inline std::decay_t<A> get_arg(lua_State* L, int index) {
    using T = std::decay_t<A>;

    if constexpr (std::is_same_v<T, lua_State*>) {
        (void)index;
        return L;
    } else if constexpr (std::is_same_v<T, lua_stack::object>) {
        return get_object(L, index);
    } else if constexpr (std::is_same_v<T, lua_stack::variadic_args>) {
        // The tail of the call, rooted at the slot the parameter starts on. It
        // has no value in the stack to read, so it must not fall through to
        // the class branch (which would dereference a null pointer).
        return get_rest(L, index);
    } else {
        return lua_stack::get<T>(L, index);
    }
}

// A parameter taken by lvalue reference must stay attached to the userdata it
// came from, exactly as sol2 handed it. Only class types can be; arithmetic and
// pointer parameters are passed by value and never asked for.
template <typename A>
inline decltype(auto) get_param(lua_State* L, int index) {
    using T = std::decay_t<A>;

    if constexpr (std::is_lvalue_reference_v<A> && std::is_class_v<T> && !std::is_const_v<std::remove_reference_t<A>>
        && !std::is_same_v<T, lua_State*> && !std::is_same_v<T, lua_stack::object>
        && !std::is_same_v<T, lua_stack::variadic_args>) {
        return lua_stack::get_ref<T>(L, index);
    } else {
        return get_arg<A>(L, index);
    }
}

template <typename F>
struct callable_traits;

template <typename T, typename R, typename... A>
struct callable_traits<R (T::*)(A...)> {
    using cls = T;
    using ret = R;
    using args = std::tuple<A...>;
};

template <typename T, typename R, typename... A>
struct callable_traits<R (T::*)(A...) const> : callable_traits<R (T::*)(A...)> {};

template <typename T, typename R, typename... A>
struct callable_traits<R (T::*)(A...) noexcept> : callable_traits<R (T::*)(A...)> {};

template <typename T, typename R, typename... A>
struct callable_traits<R (T::*)(A...) const noexcept> : callable_traits<R (T::*)(A...)> {};

template <typename R, typename... A>
struct callable_traits<R (*)(A...)> {
    using cls = void;
    using ret = R;
    using args = std::tuple<A...>;
};

template <typename R, typename... A>
struct callable_traits<R (*)(A...) noexcept> : callable_traits<R (*)(A...)> {};

// A data member has no return type and no parameter list; the member type
// itself is what a reader has to push.
template <typename T, typename M>
struct callable_traits<M T::*> {
    using cls = T;
    using ret = M;
    using args = std::tuple<>;
};

// The receiver of a method call, always stack slot 1. Lua never lands here with
// nil for a `:` call (indexing nil already failed), so nil only reaches a caller
// that passed it explicitly, which sol2 would have dereferenced. There is no
// index parameter on purpose: a typed argument is read through get_arg, so a
// scalar can never be read as a userdata by passing the wrong slot.
template <typename T>
inline T* get_self(lua_State* L) {
    if (lua_isnoneornil(L, 1)) {
        return nullptr;
    }

    return lua_stack::get_pointer<T>(L, 1);
}

// A typed argument that has to arrive as a userdata of T. A mismatch names the
// type it expected and the type it got, so a binding reached from Lua reports
// what to fix instead of an opaque "unknown C++ exception".
template <typename T>
inline T* get_arg(lua_State* L, int index, const char* type_name) {
    if (lua_isnoneornil(L, index)) {
        return nullptr;
    }

    if (!lua_stack::check<T*>(L, index)) {
        throw std::runtime_error(std::string("expected ") + type_name + ", got " + luaL_typename(L, index));
    }

    return lua_stack::get_pointer<T>(L, index);
}

template <auto F, typename T, size_t... I>
inline int call_method(lua_State* L, T* self, std::index_sequence<I...>) {
    using traits = callable_traits<decltype(F)>;
    using args = typename traits::args;

    if constexpr (std::is_void_v<typename traits::ret>) {
        (self->*F)(get_param<std::tuple_element_t<I, args>>(L, 2 + slots_before<args, I>::value)...);
        return 0;
    } else if constexpr (std::is_lvalue_reference_v<typename traits::ret>) {
        // A reference return is put as what it refers to -- the engine's
        // arrays hand back a slot to be written through, not a copy.
        return lh::put(L, (self->*F)(get_param<std::tuple_element_t<I, args>>(L, 2 + slots_before<args, I>::value)...));
    } else {
        // `put` takes its value by reference, so an rvalue is bound to a local
        // first -- binding a T to a T&& overload is not a conversion MSVC makes.
        auto value = (self->*F)(get_param<std::tuple_element_t<I, args>>(L, 2 + slots_before<args, I>::value)...);
        return lh::put(L, value);
    }
}

template <auto F, size_t... I>
inline int call_free(lua_State* L, std::index_sequence<I...>) {
    using traits = callable_traits<decltype(F)>;
    using args = typename traits::args;

    if constexpr (std::is_void_v<typename traits::ret>) {
        F(get_param<std::tuple_element_t<I, args>>(L, 1 + slots_before<args, I>::value)...);
        return 0;
    } else if constexpr (std::is_lvalue_reference_v<typename traits::ret>) {
        return lh::put(L, F(get_param<std::tuple_element_t<I, args>>(L, 1 + slots_before<args, I>::value)...));
    } else {
        auto value = F(get_param<std::tuple_element_t<I, args>>(L, 1 + slots_before<args, I>::value)...);
        return lh::put(L, value);
    }
}

template <typename F>
inline int guarded(lua_State* L, F&& body) {
    try {
        return body();
    } catch (const std::exception& e) {
        return luaL_error(L, "%s", e.what());
    } catch (...) {
        lua_pushliteral(L, "caught (...) exception");
        return lua_error(L);
    }
}

template <auto F>
struct method_thunk {
    static int call(lua_State* L) {
        using traits = callable_traits<decltype(F)>;
        using cls = typename traits::cls;

        return guarded(L, [&] {
            cls* self = get_self<cls>(L);

            if (self == nullptr) {
                return luaL_error(L, "attempt to call a method on a nil usertype object");
            }

            return call_method<F>(L, self, std::make_index_sequence<std::tuple_size_v<typename traits::args>>{});
        });
    }
};

template <auto F>
struct function_thunk {
    static int call(lua_State* L) {
        using traits = callable_traits<decltype(F)>;

        return guarded(L, [&] {
            return call_free<F>(L, std::make_index_sequence<std::tuple_size_v<typename traits::args>>{});
        });
    }
};

template <auto F>
inline constexpr lua_CFunction mthunk = &method_thunk<F>::call;

// `lh::member_fn<decltype(&C::empty), &C::empty>` is the form that survives a
// macro: the comma inside `NativeArrayNoCapacity<uint32_t>` sits in a template
// argument list, so a macro that spells the type out would split it. Passing
// the pointer type first separates the `>` from the `,`.
template <typename F, F Fn>
inline constexpr lua_CFunction member_fn = &method_thunk<Fn>::call;

template <auto F>
inline constexpr lua_CFunction fthunk = &function_thunk<F>::call;

// A public data member read as a value. sol2 registered these as properties,
// so `view.size` yields a copy and never a writable reference.
template <auto M>
struct member_reader {
    static int call(lua_State* L) {
        using traits = callable_traits<decltype(M)>;
        using cls = typename traits::cls;

        return guarded(L, [&] {
            cls* self = get_self<cls>(L);

            if (self == nullptr) {
                return luaL_error(L, "attempt to call a method on a nil usertype object");
            }

            return lh::put(L, self->*M);
        });
    }
};

template <auto M>
inline constexpr lua_CFunction member = &member_reader<M>::call;

// A constructor is reached through the type table, so `Type(args)` builds a value
// the state owns. sol2 made these the __call of the metatable and handed back
// the userdata carrying the unique_usertype metatable, which is where the
// destructor lives.
template <auto Ctor>
struct constructor_thunk {
    static int call(lua_State* L) {
        using traits = callable_traits<decltype(Ctor)>;
        using args = typename traits::args;
        using cls = typename traits::cls;

        static_assert(std::tuple_size_v<args> == 1, "a constructor is called with exactly one argument");

        return guarded(L, [&] {
            void* storage = lua_newuserdatauv(L, sizeof(cls), 0);

            new (storage) cls(get_param<std::tuple_element_t<0, args>>(L, 1));

            luaL_getmetatable(L, lua_stack::unique_metatable<cls>().c_str());
            lua_setmetatable(L, -2);

            return 1;
        });
    }
};

template <auto Ctor>
inline constexpr lua_CFunction ctor = &constructor_thunk<Ctor>::call;

// The member table shared by every metatable of one usertype. It is left on the
// stack at a fixed index until install() consumes it. Metamethods live in a
// side list so that a caller can override __index or __newindex on a type whose
// instances are addressed differently from its members.
class methods {
public:
    explicit methods(lua_State* L) : m_L{L} {
        lua_createtable(L, 0, 32);
        m_index = lua_gettop(L);
    }

    methods(const methods&) = delete;
    methods& operator=(const methods&) = delete;

    methods& add(const char* name, lua_CFunction fn) {
        lua_pushcfunction(m_L, fn);
        lua_setfield(m_L, m_index, name);
        return *this;
    }

    methods& meta(const char* name, lua_CFunction fn) {
        m_meta.emplace_back(name, fn);
        return *this;
    }

    // The read fallback sol2 named meta_function::index. It is not a __index,
    // because __index first has to try the member table; install() builds that
    // dispatcher around this function.
    methods& fallback_index(lua_CFunction fn) {
        m_fallback_index = fn;
        return *this;
    }

    lua_CFunction fallback_index() const { return m_fallback_index; }

    bool has_meta(const char* name) const {
        for (const auto& [registered, fn] : m_meta) {
            if (std::strcmp(registered, name) == 0) {
                return true;
            }
        }

        return false;
    }

    int index() const { return m_index; }

    // Writes the collected metamethods into the metatable at the top. __index
    // is excluded: install() builds it around the member table so that a
    // fallback can coexist with the members. Every other metamethod, including
    // __newindex, is written here so the caller's version wins.
    void apply_meta() const {
        for (const auto& [name, fn] : m_meta) {
            if (std::strcmp(name, "__index") == 0) {
                continue;
            }

            lua_pushcfunction(m_L, fn);
            lua_setfield(m_L, -2, name);
        }
    }

private:
    lua_State* m_L;
    int m_index = 0;
    lua_CFunction m_fallback_index = nullptr;
    std::vector<std::pair<const char*, lua_CFunction>> m_meta;
};

// Writing an unknown field is what sol2 refused with this exact message.
inline int new_index_error(lua_State* L) {
    return luaL_error(L, "sol: cannot set (new_index) into this object: no defined new_index operation on usertype");
}

// Installs the write behavior for the metatable at the top, after apply_meta()
// has written the caller's metamethods. A type that addresses fields through
// the type database passes its own __newindex; every other type refuses writes
// the way a plain usertype did.
inline void set_new_index(lua_State* L, const methods& m) {
    if (m.has_meta("__newindex")) {
        return;
    }

    lua_pushcfunction(L, &new_index_error);
    lua_setfield(L, -2, "__newindex");
}

// The __index dispatcher sol2 generated: the member table is consulted first,
// and only a miss reaches the type's own index function. Types such as
// REManagedObject address fields through the type database, but their methods
// still live in the member table, so the two have to coexist.
inline int index_with_fallback(lua_State* L) {
    lua_settop(L, 2);

    // The key is nil only for a metatable-less read; lua_rawget would accept it,
    // but there is nothing to look up, so the fallback gets it directly.
    if (!lua_isnil(L, 2)) {
        lua_pushvalue(L, lua_upvalueindex(1));
        lua_pushvalue(L, 2);
        lua_rawget(L, -2);

        if (!lua_isnil(L, -1)) {
            return 1;
        }

        lua_pop(L, 2);
    }

    lua_pushvalue(L, lua_upvalueindex(2));
    lua_pushvalue(L, 1);
    lua_pushvalue(L, 2);
    lua_call(L, 2, 1);

    return 1;
}

// Pointer comparison, which is what sol2 fell back to for usertypes without
// operator==. A value of another usertype is simply not equal.
template <typename T>
inline int eq_ptr(lua_State* L) {
    T* lhs = is<T*>(L, 1) ? get<T*>(L, 1) : nullptr;
    T* rhs = is<T*>(L, 2) ? get<T*>(L, 2) : nullptr;

    lua_pushboolean(L, lhs == rhs);
    return 1;
}

// The base class descriptors sol2 recorded in the derived metatable, so that
// stack::check<std::remove_pointer_t<Base>*> accepts a derived userdata and
// stack::get<Base*> adjusts the pointer. sol2 stores raw function pointers as
// light userdata under these two names and reads them back the same way.
using inheritance_check = bool (*)(const std::string_view&);
using inheritance_cast = void* (*)(void*, const std::string_view&);

// One name check for the upcast chain, used both to answer "is this a Base?"
// and to decide which Base a cast should produce.
template <typename U>
inline bool names(const std::string_view& wanted) {
    return wanted == lua_stack::qualified_name<U>();
}

// One step of the upcast chain: does `Base` match the requested name, and if so
// which pointer does the derived object contribute for it.
template <typename T, typename Base>
inline void* cast_to_base(void* data, const std::string_view& wanted) {
    if (!names<Base>(wanted)) {
        return nullptr;
    }

    return static_cast<void*>(static_cast<Base*>(static_cast<T*>(data)));
}

// The name check and the upcast both walk the same base list.
template <typename T, typename... Bases>
inline bool type_check_with(const std::string_view& wanted) {
    if (names<T>(wanted)) {
        return true;
    }

    return ((names<Bases>(wanted)) || ...);
}

template <typename T, typename... Bases>
inline void* type_cast_with(void* data, const std::string_view& wanted) {
    if (names<T>(wanted)) {
        return data;
    }

    if constexpr (sizeof...(Bases) == 0) {
        return nullptr;
    } else {
        void* result = nullptr;
        ((result == nullptr ? static_cast<void>(result = cast_to_base<T, Bases>(data, wanted)) : static_cast<void>(0)), ...);
        return result;
    }
}

// A relative index follows the stack top, and every helper below pushes before
// it writes, so each one has to resolve its target while the top is unchanged.
inline int absolute_index(lua_State* L, int index) {
    return lua_stack::absolute_index(L, index);
}

// Sets __index on the metatable at `index`. Without a fallback the member table
// is the __index itself, which is what sol2 did for a plain usertype; with one,
// a closure takes over and keeps the table reachable as an upvalue.
inline void set_index(lua_State* L, int index, int member_table, lua_CFunction fallback) {
    index = absolute_index(L, index);

    if (fallback == nullptr) {
        lua_pushvalue(L, member_table);
        lua_setfield(L, index, "__index");
        return;
    }

    lua_pushvalue(L, member_table);
    lua_pushcfunction(L, fallback);
    lua_pushcclosure(L, &index_with_fallback, 2);
    lua_setfield(L, index, "__index");
}

// The __call of a type table. sol2 routed `ValueType(def)` through
// constructors<T(...)>, which read the constructor arguments from the first
// slot; a type table's __call receives itself there, so it is dropped before
// the constructor the pointer metatable also uses runs.
inline int type_call(lua_State* L) {
    auto constructor = lua_tocfunction(L, lua_upvalueindex(1));
    lua_remove(L, 1);
    return constructor(L);
}

// Copies every string keyed entry of `from` into `to` that `to` does not
// already define, so a derived type's own members win over its bases'.
inline void inherit_members(lua_State* L, int to, int from) {
    to = absolute_index(L, to);
    from = absolute_index(L, from);

    lua_pushnil(L);

    while (lua_next(L, from) != 0) {
        // The key stays on the stack for the next iteration, so it is copied
        // before the lookup below pushes anything else.
        lua_pushvalue(L, -2);
        lua_rawget(L, to);

        const bool absent = lua_isnil(L, -1);
        lua_pop(L, 1);

        if (absent) {
            lua_pushvalue(L, -2);
            lua_pushvalue(L, -2);
            lua_rawset(L, to);
        }

        lua_pop(L, 1);
    }
}

// Key under which a type's metatable stores its member table. sol2 reached a
// base's members through the base metatable, but a type with a read fallback
// keeps a closure in __index rather than the table, so each install parks the
// table here for a derived type to copy from.
inline constexpr const char* kMemberTable = "\x01members";

// Copies each base's members into the member table at `members`, then records
// the downcast helpers the type check uses. sol2 reached the bases through
// their metatables, so a derived type carried add_ref, call and the rest
// without repeating them; the copy gives the same reachable surface.
template <typename T, typename... Bases>
inline void set_bases(lua_State* L, int index, int members) {
    if constexpr (sizeof...(Bases) > 0) {
        index = absolute_index(L, index);
        members = absolute_index(L, members);

        lua_pushlightuserdata(L, reinterpret_cast<void*>(&type_check_with<T, Bases...>));
        lua_setfield(L, index, "class_check");

        lua_pushlightuserdata(L, reinterpret_cast<void*>(&type_cast_with<T, Bases...>));
        lua_setfield(L, index, "class_cast");

        auto inherit = [&]<typename Base>() {
            const std::string& key = lua_stack::value_metatable<Base>();

            // The base's member table hangs off its metatable under a private
            // key, so the lookup never depends on how the type's name
            // demangles.
            if (luaL_getmetatable(L, key.c_str()) != LUA_TTABLE) {
                lua_pop(L, 1);
                return;
            }

            lua_getfield(L, -1, kMemberTable);

            if (lua_istable(L, -1)) {
                inherit_members(L, members, lua_gettop(L));
            }

            lua_pop(L, 2);
        };

        (inherit.template operator()<Bases>(), ...);
    }
}

// The __pairs iterator. Lua calls it as f(state, key), where the state is the
// member table passed by pairs_members, so the table sits at index 1.
inline int next_member(lua_State* L) {
    lua_settop(L, 2);

    if (lua_next(L, 1) == 0) {
        lua_pushnil(L);
        return 1;
    }

    return 2;
}

// __pairs must return the iterator, its state and the initial key. Handing back
// only two values made `pairs` treat the member table as the iterator.
inline int pairs_members(lua_State* L) {
    lua_pushcfunction(L, &next_member);
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_pushnil(L);
    return 3;
}

// Sets __name on the metatable at `index`. Lua 5.4's tostring falls back to it
// for userdata, and sol2 set it to the string it also used as the registry key,
// so a script saw "sol.<type>: 0x...". The index is made absolute because the
// value has to be pushed before it can be stored.
inline void set_name(lua_State* L, int index, const std::string& key) {
    index = absolute_index(L, index);

    lua_pushlstring(L, key.data(), key.size());
    lua_setfield(L, index, "__name");
}

// Sets __pairs on the metatable at `index`. sol2 only gave a working __pairs to
// types it recognised as containers, so every other usertype raised "not
// recognised as a container"; this replaces that stub. The member table is
// captured as an upvalue because __index is a function on types such as
// REManagedObject, so it cannot be recovered from the metatable at call time.
//
// A type that defines its own __pairs keeps it: the array bindings iterate
// their elements, and the default below would iterate the member names instead.
// set_new_index treats an explicit __newindex the same way.
inline void set_pairs(lua_State* L, int index, const methods& m) {
    if (m.has_meta("__pairs")) {
        return;
    }

    index = absolute_index(L, index);

    lua_pushvalue(L, m.index());
    lua_pushcclosure(L, &pairs_members, 1);
    lua_setfield(L, index, "__pairs");
}

// Installs the same set of metatables sol2 built for a new_usertype, plus the
// type table under the given global name. The metatable names come from sol2's
// own traits so that stack::check<X> keeps resolving userdata to them.
//
// The defaults reproduce the plain usertype: members are read through __index,
// writes are refused, and __gc exists only where a caller installs one. A type
// whose instances are addressed differently from its members passes its own
// __index/__newindex through `m`.
//
// A value type that owns memory (a std::vector, say) sets owns_gc, so the
// metatable a pushed value carries has the destructor that frees it.
template <typename T, typename... Bases>
inline void install(lua_State* L, const char* name, const methods& m, lua_CFunction eq = nullptr, lua_CFunction call = nullptr,
                    bool owns_gc = false) {
    auto make_metatable = [&](const std::string& key) {
        luaL_newmetatable(L, key.c_str());

        set_name(L, -1, key);

        set_index(L, -1, m.index(), m.fallback_index());

        set_bases<T, Bases...>(L, -1, m.index());

        // Parked here so a derived type's set_bases can find it. The name
        // demangles differently for T and T*, so every metatable gets a copy.
        lua_pushvalue(L, m.index());
        lua_setfield(L, -2, kMemberTable);

        m.apply_meta();

        set_new_index(L, m);

        set_pairs(L, -1, m);

        lua_pop(L, 1);
    };

    make_metatable(lua_stack::value_metatable<T>());
    make_metatable(lua_stack::const_value_metatable<T>());

    // Only the pointer metatable also receives __eq/__call. A value pushed
    // through it is destructed by sol2's unique_usertype path, but a pointer is
    // a plain reference to memory this state does not own, so it is the
    // metatable that both forms can share.
    auto make_pointer_metatable = [&]() {
        const std::string& key = lua_stack::pointer_metatable<T>();

        luaL_newmetatable(L, key.c_str());

        set_name(L, -1, key);

        set_index(L, -1, m.index(), m.fallback_index());

        set_bases<T, Bases...>(L, -1, m.index());

        m.apply_meta();

        set_new_index(L, m);

        if (eq != nullptr) {
            lua_pushcfunction(L, eq);
            lua_setfield(L, -2, "__eq");
        }

        if (call != nullptr) {
            lua_pushcfunction(L, call);
            lua_setfield(L, -2, "__call");
        }

        set_pairs(L, -1, m);

        lua_pop(L, 1);
    };

    make_pointer_metatable();

    make_metatable(lua_stack::const_pointer_metatable<T>());

    // A value pushed through this metatable is owned by the state, so a type
    // that holds memory gets the destructor sol2 would have installed.
    const std::string& unique_key = lua_stack::unique_metatable<T>();
    make_metatable(unique_key);

    if (owns_gc) {
        luaL_getmetatable(L, unique_key.c_str());
        lua_pushcfunction(L, &lua_stack::value_gc<T>);
        lua_setfield(L, -2, "__gc");
        lua_pop(L, 1);
    }

    // The type table exposed as a global reads its members through a metatable,
    // which is how sol2 routed lookups into the named submetatable.
    const std::string& user_key = lua_stack::user_metatable<T>();

    luaL_newmetatable(L, user_key.c_str());

    set_name(L, -1, user_key);

    lua_createtable(L, 0, 2);
    set_index(L, -1, m.index(), m.fallback_index());
    lua_pushcfunction(L, &new_index_error);
    lua_setfield(L, -2, "__newindex");
    set_pairs(L, -1, m);

    if (call != nullptr) {
        lua_pushcfunction(L, call);
        lua_pushcclosure(L, &type_call, 1);
        lua_setfield(L, -2, "__call");
    }

    lua_setmetatable(L, -2);

    // A type sol2 registered without a name (a container it recognised but never
    // published as a global) has no type table to expose; drop it.
    if (name != nullptr) {
        lua_setglobal(L, name);
    } else {
        lua_pop(L, 1);
    }

    lua_remove(L, m.index());
}

// A pointer to memory the Lua state does not own -- a view of a live game array
// rather than a value sol2 constructed. It is cached per address so that
// repeated reads yield the same userdata, and its metatable carries no __gc, so
// nothing is destructed when Lua collects it.
inline void push_weak_table(lua_State* L, const char* key) {
    lua_getglobal(L, "_sol_lua_push_usertypes");

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

template <typename T>
inline int push_borrowed(lua_State* L, T* obj) {
    if (obj == nullptr) {
        lua_pushnil(L);
        return 1;
    }

    // The key is not a type name at all: nothing else in the state writes this
    // table, so any stable per-type string separates the caches.
    push_weak_table(L, lua_stack::value_metatable<T>().c_str());

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

    lua_stack::push_pointer_plain<T>(L, obj);

    // The new userdata becomes the result while a second reference goes into
    // the cache under the address that produced it.
    lua_pushlightuserdata(L, reinterpret_cast<void*>(obj));
    lua_pushvalue(L, -2);
    lua_rawset(L, cache);

    lua_replace(L, cache);
    lua_settop(L, cache);
    return 1;
}

// Installs the metatables for a type that is only ever reached as a borrowed
// pointer: no value or unique_usertype metatable is created, because the state
// must never construct or destruct one.
template <typename T>
inline void install_borrowed(lua_State* L, const char* name, const methods& m) {
    const std::string& pointer_key = lua_stack::pointer_metatable<T>();

    luaL_newmetatable(L, pointer_key.c_str());

    set_name(L, -1, pointer_key);

    set_index(L, -1, m.index(), m.fallback_index());

    m.apply_meta();

    set_new_index(L, m);
    set_pairs(L, -1, m);

    lua_pop(L, 1);

    const std::string& user_key = lua_stack::user_metatable<T>();

    luaL_newmetatable(L, user_key.c_str());

    set_name(L, -1, user_key);

    lua_createtable(L, 0, 2);
    set_index(L, -1, m.index(), m.fallback_index());
    lua_pushcfunction(L, &new_index_error);
    lua_setfield(L, -2, "__newindex");
    set_pairs(L, -1, m);
    lua_setmetatable(L, -2);

    lua_setglobal(L, name);

    lua_remove(L, m.index());
}
} // namespace lh

// Every C++ exception escaping a thunk becomes a Lua error, matching how sol2
// translated a throwing binding.
#define LH_BIND(name)                                                                                                  \
    static int name(lua_State* L) {                                                                                    \
        return lh::guarded(L, [&]() -> int {
#define LH_BIND_END(L)                                                                                                 \
        });                                                                                                            \
    }