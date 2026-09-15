#include <filesystem>

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "REFramework.hpp"
#include "reframework/API.hpp"
#include "utility/String.hpp"
#include "utility/Module.hpp"

#include "sdk/ResourceManager.hpp"
#include "sdk/Memory.hpp"

#include "APIProxy.hpp"
#include "ScriptRunner.hpp"
#include "HookManager.hpp"

#include "PluginLoader.hpp"

REFrameworkPluginVersion g_plugin_version{
    REFRAMEWORK_PLUGIN_VERSION_MAJOR, REFRAMEWORK_PLUGIN_VERSION_MINOR, REFRAMEWORK_PLUGIN_VERSION_PATCH, REFRAMEWORK_GAME_NAME};

namespace reframework {
REFrameworkRendererData g_renderer_data{
    REFRAMEWORK_RENDERER_D3D12, nullptr, nullptr, nullptr
};

// Plugin-facing logging, prefixed so plugin output is identifiable.
#define REFRAMEWORK_PLUGIN_LOG(name, level)                                 \
    void name(const char* format, ...) {                                    \
        va_list args{};                                                     \
        va_start(args, format);                                             \
        spdlog::level("[Plugin] {}", utility::format_string(format, args)); \
        va_end(args);                                                       \
    }

REFRAMEWORK_PLUGIN_LOG(log_error, error)
REFRAMEWORK_PLUGIN_LOG(log_warn, warn)
REFRAMEWORK_PLUGIN_LOG(log_info, info)

#undef REFRAMEWORK_PLUGIN_LOG

bool is_drawing_ui() {
    return g_framework->is_drawing_ui();
}

void update_renderer_data() {
    auto& data = g_renderer_data;
    data.renderer_type = (int)g_framework->get_renderer_type();

    if (data.renderer_type == REFRAMEWORK_RENDERER_D3D11) {
        auto& d3d11 = g_framework->get_d3d11_hook();

        data.device = d3d11->get_device();
        data.swapchain = d3d11->get_swap_chain();
    } else if (data.renderer_type == REFRAMEWORK_RENDERER_D3D12) {
        auto& d3d12 = g_framework->get_d3d12_hook();

        data.device = d3d12->get_device();
        data.swapchain = d3d12->get_swap_chain();
        data.command_queue = d3d12->get_command_queue();
    }
}
}

namespace {
// Writes a range of engine objects into a caller-provided handle buffer with the size/count
// bookkeeping the C API expects. `to_handle` converts one element into its exposed handle type.
template <typename THandle, typename TRange, typename TConvert>
REFrameworkResult write_handle_range(const TRange& range, THandle* out, unsigned int out_size, unsigned int* out_len, TConvert to_handle) {
    const auto count = range.size();

    if (count == 0) {
        return REFRAMEWORK_ERROR_NONE;
    }

    if (count * sizeof(THandle) > out_size) {
        return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
    }

    for (const auto& value : range) {
        *out++ = to_handle(value);
    }

    if (out_len != nullptr) {
        *out_len = (unsigned int)count;
    }

    return REFRAMEWORK_ERROR_NONE;
}
}

constexpr REFrameworkPluginFunctions g_plugin_functions {
    reframework_on_lua_state_created,
    reframework_on_lua_state_destroyed,
    reframework_on_present,
    reframework_on_pre_application_entry,
    reframework_on_post_application_entry,
    reframework_lock_lua,
    reframework_unlock_lua,
    reframework_on_device_reset,
    reframework_on_message,
    reframework::log_error,
    reframework::log_warn,
    reframework::log_info,
    reframework::is_drawing_ui,
    reframework_create_script_state,
    reframework_destroy_script_state,

    reframework_on_imgui_frame,
    reframework_on_imgui_draw_ui,
    reframework_on_pre_gui_draw_element,
};

constexpr REFrameworkSDKFunctions g_sdk_functions {
    []() -> REFrameworkTDBHandle { return (REFrameworkTDBHandle)sdk::RETypeDB::get(); },
    []() { return (REFrameworkResourceManagerHandle)sdk::ResourceManager::get(); },
    []() { return (REFrameworkVMContextHandle)sdk::get_thread_context(); }, // get_vm_context
    [](const char* name) -> REFrameworkManagedObjectHandle { // typeof
        auto tdef = sdk::find_type_definition(name);

        if (tdef == nullptr) {
            return nullptr;
        }

        return (REFrameworkManagedObjectHandle)tdef->get_runtime_type();
    },
    [](const char* name) -> REFrameworkManagedObjectHandle {
        if (const auto singleton = (REFrameworkManagedObjectHandle)sdk::get_managed_singleton<void*>(name); singleton != nullptr) {
            return singleton;
        }

        return (REFrameworkManagedObjectHandle)reframework::get_globals()->get(name);
    },
    [](const char* name) {
        return sdk::get_native_singleton(name);
    },
    // get_managed_singletons
    [](REFrameworkManagedSingleton* out, unsigned int out_size, unsigned int* out_count) -> REFrameworkResult {
        auto singletons = reframework::get_globals()->get_objects();

        if (out_size < singletons.size() * sizeof(REFrameworkManagedSingleton)) {
            return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
        }

        uint32_t out_written = 0;

        for (auto instance : singletons) {
            if (instance == nullptr) {
                continue;
            }

            auto tdef = utility::re_managed_object::get_type_definition(instance);

            out[out_written].instance = (REFrameworkManagedObjectHandle)instance;
            out[out_written].t = (REFrameworkTypeDefinitionHandle)tdef;
            out[out_written].type_info = (REFrameworkTypeInfoHandle)tdef->get_type();

            ++out_written;
        }

        if (out_count != nullptr) {
            *out_count = out_written;
        }

        return REFRAMEWORK_ERROR_NONE;
    },
    // get_native_singletons
    [](REFrameworkNativeSingleton* out, unsigned int out_size, unsigned int* out_count) -> REFrameworkResult {
        auto& native_singletons = reframework::get_globals()->get_native_singleton_types();

        if (out_size < native_singletons.size() * sizeof(REFrameworkNativeSingleton)) {
            return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
        }

        uint32_t out_written = 0;

        for (auto t : native_singletons) {
            if (t == nullptr) {
                continue;
            }

            auto instance = utility::re_type::get_singleton_instance(t);

            if (instance == nullptr) {
                continue;
            }

            out[out_written].instance = instance;
            out[out_written].t = (REFrameworkTypeDefinitionHandle)utility::re_type::get_type_definition(t);
            out[out_written].type_info = (REFrameworkTypeInfoHandle)t;
            out[out_written].name = t->name;

            ++out_written;
        }

        if (out_count != nullptr) {
            *out_count = out_written;
        }

        return REFRAMEWORK_ERROR_NONE;
    },
    // create_managed_string
    [](const wchar_t* str) -> REFrameworkManagedObjectHandle {
        return (REFrameworkManagedObjectHandle)sdk::VM::create_managed_string(str);
    },
    [](const char* str) -> REFrameworkManagedObjectHandle {
        return (REFrameworkManagedObjectHandle)sdk::VM::create_managed_string(utility::widen(str));
    },
    [](REFrameworkMethodHandle fn, REFPreHookFn pre_fn, REFPostHookFn post_fn, bool ignore_jmp) -> unsigned int {
        return g_hookman.add((sdk::REMethodDefinition*)fn, [pre_fn](auto& args, auto& arg_tys, uintptr_t ret_addr) {
                if (pre_fn != nullptr) {
                    return (HookManager::PreHookResult)pre_fn((int)args.size(),
                        (void**)args.data(), (REFrameworkTypeDefinitionHandle*)arg_tys.data(), ret_addr);
                } else {
                    return (HookManager::PreHookResult)REFRAMEWORK_HOOK_CALL_ORIGINAL;
                }
            },
            [post_fn](auto& ret_val, auto* ret_ty, uintptr_t ret_addr) {
                if (post_fn != nullptr) {
                    post_fn((void**)&ret_val, (REFrameworkTypeDefinitionHandle)ret_ty, ret_addr);
                }
            },
            ignore_jmp);
    },
    [](REFrameworkMethodHandle fn, unsigned int id) { g_hookman.remove((sdk::REMethodDefinition*)fn, (HookManager::HookId)id); },
    &sdk::memory::detail::allocate_plugin_loader,
    &sdk::memory::deallocate,
    [](REFrameworkTypeDefinitionHandle tdef, unsigned int size) -> REFrameworkManagedObjectHandle {
        if (tdef == nullptr) {
            return nullptr;
        }

        auto runtime_type = ((sdk::RETypeDefinition*)tdef)->get_runtime_type();
        return (REFrameworkManagedObjectHandle)sdk::VM::create_managed_array(runtime_type, size);
    },
};

// Handle -> engine object casts used by the tables below.
#define RETYPEDEF(var) ((sdk::RETypeDefinition*)var)
#define REMETHOD(var) ((sdk::REMethodDefinition*)var)
#define REFIELD(var) ((sdk::REField*)var)
#define RETDB(var) ((sdk::RETypeDB*)var)
#define REMANAGEDOBJECT(var) ((::REManagedObject*)var)
#define RERESOURCEMGR(var) ((sdk::ResourceManager*)var)
#define RERESOURCE(var) ((sdk::Resource*)var)
#define RETYPEINFO(var) ((::REType*)var)
#define VMCONTEXT(var) ((sdk::VMContext*)var)
#define REFLMETHOD(var) ((::FunctionDescriptor*)var)
#define REFLPROP(var) ((::VariableDescriptor*)var)
#define RE_MODULE(x) ((sdk::REModule*)x)

constexpr REFrameworkTDBTypeDefinition g_type_definition_data {
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_index(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_size(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_valuetype_size(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_fqn_hash(); },

    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_name(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_namespace(); },
    [](REFrameworkTypeDefinitionHandle tdef, char* out, unsigned int size, unsigned int* out_len) {
        auto full_name = RETYPEDEF(tdef)->get_full_name();

        if (full_name.size() > size) {
            return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
        }

        memcpy(out, full_name.c_str(), full_name.size());

        if (out_len != nullptr) {
            *out_len = full_name.size();
        }

        return REFRAMEWORK_ERROR_NONE;
    },

    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->has_fieldptr_offset(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_fieldptr_offset(); },

    [](REFrameworkTypeDefinitionHandle tdef) -> uint32_t { return RETYPEDEF(tdef)->get_methods().size(); },
    [](REFrameworkTypeDefinitionHandle tdef) -> uint32_t { return RETYPEDEF(tdef)->get_fields().size(); },
    [](REFrameworkTypeDefinitionHandle tdef) -> uint32_t { return RETYPEDEF(tdef)->get_properties().size(); },

    [](REFrameworkTypeDefinitionHandle tdef, REFrameworkTypeDefinitionHandle other) { return RETYPEDEF(tdef)->is_a(RETYPEDEF(other)); },
    [](REFrameworkTypeDefinitionHandle tdef, const char* name) { return RETYPEDEF(tdef)->is_a(name); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->is_value_type(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->is_enum(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->is_by_ref(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->is_pointer(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->is_primitive(); },

    [](REFrameworkTypeDefinitionHandle tdef) { return (unsigned int)RETYPEDEF(tdef)->get_vm_obj_type(); },

    [](REFrameworkTypeDefinitionHandle tdef, const char* name) { return (REFrameworkMethodHandle)RETYPEDEF(tdef)->get_method(name); },
    [](REFrameworkTypeDefinitionHandle tdef, const char* name) { return (REFrameworkFieldHandle)RETYPEDEF(tdef)->get_field(name); },
    [](REFrameworkTypeDefinitionHandle tdef, const char* name) { return (REFrameworkPropertyHandle)nullptr; },

    [](REFrameworkTypeDefinitionHandle tdef, REFrameworkMethodHandle* out, unsigned int out_size, unsigned int* out_len) {
        return write_handle_range(RETYPEDEF(tdef)->get_methods(), out, out_size, out_len,
            [](const auto& method) { return (REFrameworkMethodHandle)&method; });
    },
    [](REFrameworkTypeDefinitionHandle tdef, REFrameworkFieldHandle* out, unsigned int out_size, unsigned int* out_len) {
        return write_handle_range(RETYPEDEF(tdef)->get_fields(), out, out_size, out_len,
            [](const auto& field) { return (REFrameworkFieldHandle)field; });
    },

    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->get_instance(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return RETYPEDEF(tdef)->create_instance(); },
    [](REFrameworkTypeDefinitionHandle tdef, unsigned int flags) { return (REFrameworkManagedObjectHandle)RETYPEDEF(tdef)->create_instance_full(flags == REFRAMEWORK_CREATE_INSTANCE_FLAGS_SIMPLIFY); },

    [](REFrameworkTypeDefinitionHandle tdef) { return (REFrameworkTypeDefinitionHandle)RETYPEDEF(tdef)->get_parent_type(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return (REFrameworkTypeDefinitionHandle)RETYPEDEF(tdef)->get_declaring_type(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return (REFrameworkTypeDefinitionHandle)RETYPEDEF(tdef)->get_underlying_type(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return (REFrameworkTypeInfoHandle)RETYPEDEF(tdef)->get_type(); },
    [](REFrameworkTypeDefinitionHandle tdef) { return (REFrameworkManagedObjectHandle)RETYPEDEF(tdef)->get_runtime_type(); }
};

constexpr REFrameworkTDBMethod g_tdb_method_data {
    [](REFrameworkMethodHandle method, void* thisptr, void** in_args, unsigned int in_args_size, void* out, unsigned int out_size) {
        if (sizeof(reframework::InvokeRet) > out_size) {
            return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
        }

        auto m = REMETHOD(method);

        if (m->get_num_params() != in_args_size / sizeof(void*)) {
            return REFRAMEWORK_ERROR_IN_ARGS_SIZE_MISMATCH;
        }

        const auto arg_count = in_args_size / sizeof(void*);
        m->invoke(thisptr, std::span<void*>(in_args, arg_count), *(reframework::InvokeRet*)out);

        if (((reframework::InvokeRet*)out)->exception_thrown) {
            return REFRAMEWORK_ERROR_EXCEPTION;
        }

        return REFRAMEWORK_ERROR_NONE;
    },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_function(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_name(); },
    [](REFrameworkMethodHandle method) { return (REFrameworkTypeDefinitionHandle)REMETHOD(method)->get_declaring_type(); },
    [](REFrameworkMethodHandle method) { return (REFrameworkTypeDefinitionHandle)REMETHOD(method)->get_return_type(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_num_params(); },
    [](REFrameworkMethodHandle method, REFrameworkMethodParameter* out, unsigned int out_size, unsigned int* out_len) {
        const auto num_params = REMETHOD(method)->get_num_params();

        if (num_params == 0) {
            return REFRAMEWORK_ERROR_NONE;
        }

        if (num_params * sizeof(REFrameworkMethodParameter) > out_size) {
            return REFRAMEWORK_ERROR_OUT_TOO_SMALL;
        }

        const auto param_names = REMETHOD(method)->get_param_names();
        const auto param_types = REMETHOD(method)->get_param_types();

        for (auto i = 0; i < num_params; ++i) {
            out[i].name = param_names[i];
            out[i].t = (REFrameworkTypeDefinitionHandle)param_types[i];
        }

        if (out_len != nullptr) {
            *out_len = num_params;
        }

        return REFRAMEWORK_ERROR_NONE;
    },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_index(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_virtual_index(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->is_static(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_flags(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_impl_flags(); },
    [](REFrameworkMethodHandle method) { return REMETHOD(method)->get_invoke_id(); }
};

constexpr REFrameworkTDBField g_tdb_field_data {
    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_name(); },

    [](REFrameworkFieldHandle field) { return (REFrameworkTypeDefinitionHandle)REFIELD(field)->get_declaring_type(); },
    [](REFrameworkFieldHandle field) { return (REFrameworkTypeDefinitionHandle)REFIELD(field)->get_type(); },

    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_offset_from_base(); },
    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_offset_from_fieldptr(); },
    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_flags(); },

    [](REFrameworkFieldHandle field) { return REFIELD(field)->is_static(); },
    [](REFrameworkFieldHandle field) { return REFIELD(field)->is_literal(); },

    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_init_data(); },
    [](REFrameworkFieldHandle field, void* obj, bool is_value_type) { return REFIELD(field)->get_data_raw(obj, is_value_type); },

    [](REFrameworkFieldHandle field) { return REFIELD(field)->get_index(); },
};

constexpr REFrameworkTDBProperty g_tdb_property_data {
    // todo
};

constexpr REFrameworkTDB g_tdb_data {
    [](REFrameworkTDBHandle tdb) { return RETDB(tdb)->numTypes; },
    [](REFrameworkTDBHandle tdb) { return RETDB(tdb)->numMethods; },
    [](REFrameworkTDBHandle tdb) { return RETDB(tdb)->numFields; },
    [](REFrameworkTDBHandle tdb) { return RETDB(tdb)->numProperties; },
    [](REFrameworkTDBHandle tdb) { return (unsigned int)RETDB(tdb)->numStringPool; },
    [](REFrameworkTDBHandle tdb) { return (unsigned int)RETDB(tdb)->numBytePool; },
    [](REFrameworkTDBHandle tdb) { return (const char*)RETDB(tdb)->stringPool; },
    [](REFrameworkTDBHandle tdb) { return (unsigned char*)RETDB(tdb)->bytePool; },

    [](REFrameworkTDBHandle tdb, unsigned int index) { return (REFrameworkTypeDefinitionHandle)RETDB(tdb)->get_type(index); },
    [](REFrameworkTDBHandle tdb, const char* name) { return (REFrameworkTypeDefinitionHandle)RETDB(tdb)->find_type(name); },
    [](REFrameworkTDBHandle tdb, unsigned int fqn) { return (REFrameworkTypeDefinitionHandle)RETDB(tdb)->find_type_by_fqn(fqn); },
    [](REFrameworkTDBHandle tdb, unsigned int index) { return (REFrameworkMethodHandle)RETDB(tdb)->get_method(index); },
    [](REFrameworkTDBHandle tdb, const char* type_name, const char* method_name) -> REFrameworkMethodHandle {
        auto t = RETDB(tdb)->find_type(type_name);

        if (t == nullptr) {
            return nullptr;
        }

        return (REFrameworkMethodHandle)t->get_method(method_name);
    },

    [](REFrameworkTDBHandle tdb, unsigned int index) { return (REFrameworkFieldHandle)RETDB(tdb)->get_field(index); },
    [](REFrameworkTDBHandle tdb, const char* type_name, const char* field_name) -> REFrameworkFieldHandle {
        auto t = RETDB(tdb)->find_type(type_name);

        if (t == nullptr) {
            return nullptr;
        }

        return (REFrameworkFieldHandle)t->get_field(field_name);
    },

    [](REFrameworkTDBHandle tdb, unsigned int index) { return (REFrameworkPropertyHandle)RETDB(tdb)->get_property(index); },

    [](REFrameworkTDBHandle tdb, unsigned int index) { return (REFrameworkModuleHandle)RETDB(tdb)->get_module(index); },
    [](REFrameworkTDBHandle tdb) { return RETDB(tdb)->get_num_modules(); }
};

constexpr REFrameworkManagedObject g_managed_object_data {
    [](REFrameworkManagedObjectHandle obj) { utility::re_managed_object::add_ref(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj) { utility::re_managed_object::release(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj) { return (REFrameworkTypeDefinitionHandle)utility::re_managed_object::get_type_definition(REMANAGEDOBJECT(obj)); },
    [](void* potential_obj) { return utility::re_managed_object::is_managed_object(potential_obj); },
    [](REFrameworkManagedObjectHandle obj) { return REMANAGEDOBJECT(obj)->referenceCount; },
    [](REFrameworkManagedObjectHandle obj) { return utility::re_managed_object::get_size(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj) { return (unsigned int)utility::re_managed_object::get_vm_type(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj) { return (REFrameworkTypeInfoHandle)utility::re_managed_object::get_type(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj) { return (void*)utility::re_managed_object::get_variables(REMANAGEDOBJECT(obj)); },
    [](REFrameworkManagedObjectHandle obj, const char* name) { return (REFrameworkReflectionPropertyHandle)utility::re_managed_object::get_field_desc(REMANAGEDOBJECT(obj), name); },
    [](REFrameworkManagedObjectHandle obj, const char* name) { return (REFrameworkReflectionMethodHandle)utility::re_managed_object::get_method_desc(REMANAGEDOBJECT(obj), name); },
};

constexpr REFrameworkResourceManager g_resource_manager_data {
    [](REFrameworkResourceManagerHandle mgr, const char* type_name, const char* name) -> REFrameworkResourceHandle {
        // NOT a type definition.
        auto t = reframework::get_types()->get(type_name);

        if (t == nullptr) {
            return nullptr;
        }

        return (REFrameworkResourceHandle)RERESOURCEMGR(mgr)->create_resource(t, utility::widen(name).c_str());
    },
    [](REFrameworkResourceManagerHandle mgr, const char* type_name, const char* name) -> REFrameworkManagedObjectHandle {
        // NOT a type definition.
        auto t = reframework::get_types()->get(type_name);

        if (t == nullptr) {
            return nullptr;
        }

        auto obj = RERESOURCEMGR(mgr)->create_userdata(t, utility::widen(name).c_str());

        if (!obj.has_value()) {
            return nullptr;
        }

        // The intrusive_ptr holds the reference for us initially, but when we return it back to the plugin
        // we need to add another reference so that the plugin can hold onto it before we release it.
        utility::re_managed_object::add_ref(obj.get());
        return (REFrameworkManagedObjectHandle)obj.get();
    }
};

constexpr REFrameworkResource g_resource_data {
    [](REFrameworkResourceHandle res) { RERESOURCE(res)->add_ref(); },
    [](REFrameworkResourceHandle res) { RERESOURCE(res)->release(); },
    [](REFrameworkResourceHandle res, const char* type_name) -> REFrameworkManagedObjectHandle {
        if (type_name == nullptr) {
            return nullptr;
        }

        const auto t = sdk::find_type_definition(type_name);

        if (t == nullptr) {
            return nullptr;
        }

        return (REFrameworkManagedObjectHandle)RERESOURCE(res)->create_holder(t);
    }
};

constexpr REFrameworkTypeInfo g_type_info_data {
    [](REFrameworkTypeInfoHandle ti) -> const char* { return RETYPEINFO(ti)->name; },
    [](REFrameworkTypeInfoHandle ti) { return (REFrameworkTypeDefinitionHandle)utility::re_type::get_type_definition(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti) { return utility::re_type::is_clr_type(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti) { return utility::re_type::is_singleton(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti) { return utility::re_type::get_singleton_instance(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti) { return utility::re_type::create_instance(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti) { return (void*)utility::re_type::get_variables(RETYPEINFO(ti)); },
    [](REFrameworkTypeInfoHandle ti, const char* name) { return (REFrameworkReflectionPropertyHandle)utility::re_type::get_field_desc(RETYPEINFO(ti), name); },
    [](REFrameworkTypeInfoHandle ti, const char* name) { return (REFrameworkReflectionMethodHandle)utility::re_type::get_method_desc(RETYPEINFO(ti), name); },
    [](REFrameworkTypeInfoHandle ti) -> void* {
        if (RETYPEINFO(ti)->fields == nullptr) {
            return nullptr;
        }

        return RETYPEINFO(ti)->fields->deserializer;
    },
    [](REFrameworkTypeInfoHandle ti) -> REFrameworkTypeInfoHandle {
        return (REFrameworkTypeInfoHandle)RETYPEINFO(ti)->super;
    },
    [](REFrameworkTypeInfoHandle ti) {
        return RETYPEINFO(ti)->typeCRC;
    }
};

constexpr REFrameworkVMContext g_vm_context_data {
    // has exception
    [](REFrameworkVMContextHandle ctx) { return VMCONTEXT(ctx)->unkPtr->unkPtr != nullptr; },
    [](REFrameworkVMContextHandle ctx) { VMCONTEXT(ctx)->unhandled_exception(); },
    [](REFrameworkVMContextHandle ctx) { VMCONTEXT(ctx)->local_frame_gc(); },
    [](REFrameworkVMContextHandle ctx, int32_t old) { VMCONTEXT(ctx)->cleanup_after_exception(old); },
};

constexpr REFrameworkReflectionMethod g_reflection_method_data {
    [](REFrameworkReflectionMethodHandle method) -> REFrameworkInvokeMethod {
        return (REFrameworkInvokeMethod)REFLMETHOD(method)->functionPtr;
    }
};

constexpr REFrameworkReflectionProperty g_reflection_prop_data {
    [](REFrameworkReflectionPropertyHandle prop) -> REFrameworkReflectionPropertyMethod {
        return (REFrameworkReflectionPropertyMethod)REFLPROP(prop)->function;
    },
    [](REFrameworkReflectionPropertyHandle prop) {
        return utility::reflection_property::is_static(REFLPROP(prop));
    },
    [](REFrameworkReflectionPropertyHandle prop) {
        return utility::reflection_property::get_size(REFLPROP(prop));
    }
};

constexpr REFrameworkModule g_tdb_module_data {
    .get_major = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_major(); },
    .get_minor = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_minor(); },
    .get_build = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_build(); },
    .get_revision = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_revision(); },
    .get_assembly_name = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_assembly_name(); },
    .get_location = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_location(); },
    .get_module_name = [](REFrameworkModuleHandle mod) { return RE_MODULE(mod)->get_module_name(); },
    .get_num_types = [](REFrameworkModuleHandle mod) -> uint32_t { return RE_MODULE(mod)->get_types().size(); },
    .get_types = [](REFrameworkModuleHandle mod) { return (uint32_t*)RE_MODULE(mod)->get_types().data(); },
    .get_num_methods = [](REFrameworkModuleHandle mod) -> uint32_t  { return RE_MODULE(mod)->get_methods().size(); },
    .get_methods = [](REFrameworkModuleHandle mod) { return (uint32_t*)RE_MODULE(mod)->get_methods().data(); },
    .get_num_member_references = [](REFrameworkModuleHandle mod) -> uint32_t  { return RE_MODULE(mod)->get_member_references().size(); },
    .get_member_references = [](REFrameworkModuleHandle mod) { return (uint32_t*)RE_MODULE(mod)->get_member_references().data(); },
};

constexpr REFrameworkSDKData g_sdk_data {
    &g_sdk_functions,
    &g_tdb_data,
    &g_type_definition_data,
    &g_tdb_method_data,
    &g_tdb_field_data,
    &g_tdb_property_data,
    &g_managed_object_data,
    &g_resource_manager_data,
    &g_resource_data,
    &g_type_info_data,
    &g_vm_context_data,
    &g_reflection_method_data,
    &g_reflection_prop_data,
    &g_tdb_module_data
};

REFrameworkPluginInitializeParam g_plugin_initialize_param{
    nullptr,
    &g_plugin_version,
    &g_plugin_functions,
    &reframework::g_renderer_data,
    &g_sdk_data
};

namespace {
// Sanity check run once before plugin init: every exposed function pointer must be filled in.
void verify_sdk_pointers() {
    spdlog::info("Verifying SDK pointers...");

    auto verify = [](const char* name, const void* const* table, size_t count) {
        for (size_t i = 0; i < count; ++i) {
            if (table[i] == nullptr) {
                spdlog::error("SDK pointer is null in {} at index {}", name, i);
            }
        }
    };

#define REFRAMEWORK_VERIFY_TABLE(table) verify(#table, reinterpret_cast<const void* const*>(&table), sizeof(table) / sizeof(void*))

    REFRAMEWORK_VERIFY_TABLE(g_plugin_functions);
    REFRAMEWORK_VERIFY_TABLE(g_sdk_functions);
    REFRAMEWORK_VERIFY_TABLE(g_sdk_data);
    REFRAMEWORK_VERIFY_TABLE(g_tdb_data);
    REFRAMEWORK_VERIFY_TABLE(g_type_definition_data);
    REFRAMEWORK_VERIFY_TABLE(g_tdb_method_data);
    REFRAMEWORK_VERIFY_TABLE(g_tdb_field_data);
    REFRAMEWORK_VERIFY_TABLE(g_tdb_property_data);
    REFRAMEWORK_VERIFY_TABLE(g_managed_object_data);
    REFRAMEWORK_VERIFY_TABLE(g_resource_manager_data);
    REFRAMEWORK_VERIFY_TABLE(g_resource_data);
    REFRAMEWORK_VERIFY_TABLE(g_type_info_data);
    REFRAMEWORK_VERIFY_TABLE(g_vm_context_data);
    REFRAMEWORK_VERIFY_TABLE(g_reflection_method_data);
    REFRAMEWORK_VERIFY_TABLE(g_reflection_prop_data);

#undef REFRAMEWORK_VERIFY_TABLE
}
}

std::shared_ptr<PluginLoader> PluginLoader::get() {
    static auto instance = std::make_shared<PluginLoader>();
    return instance;
}

void PluginLoader::early_init() try {
    namespace fs = std::filesystem;

    std::scoped_lock _{m_mux};

    spdlog::info("[PluginLoader] Module path {}", *utility::get_module_path(utility::get_executable()));
    spdlog::info("[PluginLoader] Actual dir: {}", REFramework::get_persistent_dir().string());

    const auto plugin_path = REFramework::get_persistent_dir() / "reframework" / "plugins";

    spdlog::info("[PluginLoader] Creating directories {}", plugin_path.string());

    if (!fs::create_directories(plugin_path) && !fs::exists(plugin_path)) {
        spdlog::error("[PluginLoader] Failed to create directory for plugins: {}", plugin_path.string());
    } else {
        spdlog::info("[PluginLoader] Created directory for plugins: {}", plugin_path.string());
    }

    spdlog::info("[PluginLoader] Loading plugins...");

    // Load all dlls in the plugins directory.
    for (auto&& entry : fs::directory_iterator{plugin_path}) {
        auto&& path = entry.path();

        if (path.has_extension() && path.extension() == ".dll") {
            auto module = LoadLibraryW(path.operator std::wstring().c_str());

            if (module == nullptr) {
                spdlog::error("[PluginLoader] Failed to load {}", path.string());
                m_plugin_load_errors.emplace(path.stem().string(), "Failed to load");
                continue;
            }

            spdlog::info("[PluginLoader] Loaded {}", path.string());
            m_plugins.emplace(path.stem().string(), module);
        }
    }
} catch(const std::exception& e) {
    spdlog::error("[PluginLoader] Exception during early init {}", e.what());
} catch(...) {
    spdlog::error("[PluginLoader] Unknown exception during early init");
}

void PluginLoader::on_frame() {
    reframework::update_renderer_data();

    if (auto error = initialize_plugins(); error.has_value()) {
        spdlog::error("[PluginLoader] Failed to initialize plugins: {}", error.value());
    }
}

PluginLoader::PluginMap::iterator PluginLoader::unload_plugin(PluginMap::iterator it, const char* reason) {
    m_plugin_load_errors.emplace(it->first, reason);
    FreeLibrary(it->second);

    return m_plugins.erase(it);
}

std::optional<std::string> PluginLoader::initialize_plugins() {
    if (m_plugins_loaded) {
        return std::nullopt;
    }

    // Plugin init can take a really long time so don't try to re-hook d3d while it's happening.
    auto do_not_hook_d3d = g_framework->acquire_do_not_hook_d3d();

    std::scoped_lock _{m_mux};

    verify_sdk_pointers();

    g_plugin_initialize_param.reframework_module = g_framework->get_reframework_module();

    // Reject plugins that were built against an incompatible REFramework version.
    for (auto it = m_plugins.begin(); it != m_plugins.end();) {
        const auto name = it->first;
        const auto mod = it->second;
        auto required_version_fn = (REFPluginRequiredVersionFn)GetProcAddress(mod, "reframework_plugin_required_version");

        if (required_version_fn == nullptr) {
            spdlog::info("[PluginLoader] {} has no reframework_plugin_required_version function, skipping...", name);

            ++it;
            continue;
        }

        REFrameworkPluginVersion required_version{};

        try {
            required_version_fn(&required_version);
        } catch(...) {
            spdlog::error("[PluginLoader] {} has an exception in reframework_plugin_required_version, skipping...", name);
            it = unload_plugin(it, "Exception occurred in reframework_plugin_required_version");
            continue;
        }

        spdlog::info(
            "[PluginLoader] {} requires version {}.{}.{}", name, required_version.major, required_version.minor, required_version.patch);

        if (required_version.major != g_plugin_version.major) {
            spdlog::error("[PluginLoader] Plugin {} requires a different major version", name);
            it = unload_plugin(it, "Requires a different major version");
            continue;
        }

        if (required_version.minor > g_plugin_version.minor) {
            spdlog::error("[PluginLoader] Plugin {} requires a newer minor version", name);
            it = unload_plugin(it, "Requires a newer minor version");
            continue;
        }

        if (required_version.patch > g_plugin_version.patch && required_version.minor == g_plugin_version.minor) {
            spdlog::warn("[PluginLoader] Plugin {} desires a newer patch version", name);
            m_plugin_load_warnings.emplace(name, "Desires a newer patch version");
        }

        if (required_version.game_name != nullptr && std::string_view{required_version.game_name} != g_plugin_version.game_name) {
            spdlog::error("[PluginLoader] Plugin {} is for a different game {}", name, required_version.game_name);
            it = unload_plugin(it, "Is for a different game");
            continue;
        }

        ++it;
    }

    // Call reframework_plugin_initialize on any dlls that export it.
    for (auto it = m_plugins.begin(); it != m_plugins.end();) {
        const auto name = it->first;
        const auto mod = it->second;
        auto init_fn = (REFPluginInitializeFn)GetProcAddress(mod, "reframework_plugin_initialize");

        if (init_fn == nullptr) {
            ++it;
            continue;
        }

        spdlog::info("[PluginLoader] Initializing {}...", name);

        try {
            if (init_fn(&g_plugin_initialize_param)) {
                ++it;
                continue;
            }

            spdlog::error("[PluginLoader] Failed to initialize {}", name);
            it = unload_plugin(it, "Failed to initialize");
        } catch(...) {
            spdlog::error("[PluginLoader] {} has an exception in reframework_plugin_initialize, skipping...", name);
            it = unload_plugin(it, "Exception occurred in reframework_plugin_initialize");
        }
    }

    m_plugins_loaded = true;

    return Mod::on_initialize();
}

void PluginLoader::on_draw_ui() {
    ImGui::SetNextItemOpen(false, ImGuiCond_Once);

    if (ImGui::CollapsingHeader(get_name().data())) {
        std::scoped_lock _{m_mux};

        if (!m_plugins.empty()) {
            ImGui::Text("Loaded plugins:");

            for (auto&& [name, _] : m_plugins) {
                ImGui::Text("%s", name.c_str());
            }
        } else {
            ImGui::Text("No plugins loaded.");
        }

        auto draw_entries = [](const char* label, const auto& entries) {
            if (entries.empty()) {
                return;
            }

            ImGui::Spacing();
            ImGui::Text("%s:", label);

            for (auto&& [name, text] : entries) {
                ImGui::Text("%s - %s", name.c_str(), text.c_str());
            }
        };

        draw_entries("Errors", m_plugin_load_errors);
        draw_entries("Warnings", m_plugin_load_warnings);
    }
}

namespace {
// Ignores a null plugin callback, otherwise registers it through APIProxy.
template <typename TCb>
bool add_api_callback(TCb cb, bool (APIProxy::*add)(TCb)) {
    return cb != nullptr && (APIProxy::get().get()->*add)(cb);
}
}

bool reframework_on_lua_state_created(REFLuaStateCreatedCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_lua_state_created);
}

bool reframework_on_lua_state_destroyed(REFLuaStateDestroyedCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_lua_state_destroyed);
}

bool reframework_on_present(REFOnPresentCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_present);
}

bool reframework_on_pre_application_entry(const char* name, REFOnPreApplicationEntryCb cb) {
    if (cb == nullptr || name == nullptr || *name == '\0') {
        return false;
    }

    return APIProxy::get()->add_on_pre_application_entry(name, cb);
}

bool reframework_on_post_application_entry(const char* name, REFOnPostApplicationEntryCb cb) {
    if (cb == nullptr || name == nullptr || *name == '\0') {
        return false;
    }

    return APIProxy::get()->add_on_post_application_entry(name, cb);
}

void reframework_lock_lua() {
    ScriptRunner::get()->lock();
}

void reframework_unlock_lua() {
    ScriptRunner::get()->unlock();
}

bool reframework_on_device_reset(REFOnDeviceResetCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_device_reset);
}

bool reframework_on_message(REFOnMessageCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_message);
}

bool reframework_on_imgui_frame(REFOnImGuiFrameCb cb) {
    if (cb == nullptr) {
        return false;
    }

    reframework::update_renderer_data();

    return APIProxy::get()->add_on_imgui_frame(cb);
}

bool reframework_on_imgui_draw_ui(REFOnImGuiDrawUICb cb) {
    if (cb == nullptr) {
        return false;
    }

    reframework::update_renderer_data();

    return APIProxy::get()->add_on_imgui_draw_ui(cb);
}

bool reframework_on_pre_gui_draw_element(REFOnPreGuiDrawElementCb cb) {
    return add_api_callback(cb, &APIProxy::add_on_pre_gui_draw_element);
}

lua_State* reframework_create_script_state() {
    return ScriptRunner::get()->create_state();
}

void reframework_destroy_script_state(lua_State* lua_state) {
    ScriptRunner::get()->delete_state(lua_state);
}
