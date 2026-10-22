#include <spdlog/spdlog.h>
#include <utility/Scan.hpp>
#include <utility/Module.hpp>

#include "reframework/API.hpp"
#include "RETypeDB.hpp"

namespace sdk {
RETypeDB* RETypeDB::get() {
    auto vm = VM::get();

    if (vm == nullptr) {
        return nullptr;
    }

    return vm->get_type_db();
}

static std::shared_mutex g_tdb_type_mtx{};

// Transparent hash so lookups by std::string_view don't materialize a temporary
// std::string (heap-allocated for names longer than the SSO buffer).
struct TransparentStringHash {
    using is_transparent = void;

    size_t operator()(std::string_view sv) const noexcept {
        return std::hash<std::string_view>{}(sv);
    }
};

static std::unordered_map<std::string, sdk::RETypeDefinition*, TransparentStringHash, std::equal_to<>> g_tdb_type_map{};

reframework::InvokeRet invoke_object_func(void* obj, sdk::RETypeDefinition* t, std::string_view name, std::vector<void*>& args) {
    const auto method = t->get_method(name);

    if (method == nullptr) {
        return reframework::InvokeRet{};
    }

    return method->invoke(obj, std::span<void*>(args));
}

reframework::InvokeRet invoke_object_func(::REManagedObject* obj, std::string_view name, const std::vector<void*>& args) {
    const auto t = utility::re_managed_object::get_type_definition(obj);

    if (t == nullptr) {
        return reframework::InvokeRet{};
    }

    const auto method = t->get_method(name);

    if (method == nullptr) {
        return reframework::InvokeRet{};
    }

    return method->invoke(obj, std::span<void*>(*const_cast<std::vector<void*>*>(&args)));
}


sdk::REModule* RETypeDB::get_module(uint32_t index) const {
    if (index >= this->get_num_modules()) {
        return nullptr;
    }

    return &(this->modules)[index];
}

sdk::RETypeDefinition* RETypeDB::find_type(std::string_view name) const {
    static bool map_populated = false;

    {
        std::shared_lock _{ g_tdb_type_mtx };

        if (auto it = g_tdb_type_map.find(name); it != g_tdb_type_map.end()) {
            return it->second;
        }

        if (map_populated) {
            return nullptr;
        }
    }

    {
        std::unique_lock _{ g_tdb_type_mtx };

        // Double-checked: another thread may have populated while we waited
        if (auto it = g_tdb_type_map.find(name.data()); it != g_tdb_type_map.end()) {
            return it->second;
        }

        if (map_populated) {
            return nullptr;
        }

        map_populated = true;

        for (uint32_t i = 0; i < this->numTypes; ++i) {
            auto t = get_type(i);

            g_tdb_type_map[t->get_full_name()] = t;
        }
    }

    // Re-check the map after population
    {
        std::shared_lock _{ g_tdb_type_mtx };
        if (auto it = g_tdb_type_map.find(name.data()); it != g_tdb_type_map.end()) {
            return it->second;
        }
    }

    return nullptr;
}

// Cache for find_type_by_fqn
static std::shared_mutex g_tdb_fqn_mtx{};
static std::unordered_map<uint32_t, sdk::RETypeDefinition*> g_tdb_fqn_map{};
static bool g_tdb_fqn_populated = false;

sdk::RETypeDefinition* RETypeDB::find_type_by_fqn(uint32_t fqn) const {
    {
        std::shared_lock _{ g_tdb_fqn_mtx };

        if (auto it = g_tdb_fqn_map.find(fqn); it != g_tdb_fqn_map.end()) {
            return it->second;
        }

        if (g_tdb_fqn_populated) {
            return nullptr;
        }
    }

    {
        std::unique_lock _{ g_tdb_fqn_mtx };

        // Double-checked
        if (auto it = g_tdb_fqn_map.find(fqn); it != g_tdb_fqn_map.end()) {
            return it->second;
        }

        if (g_tdb_fqn_populated) {
            return nullptr;
        }

        g_tdb_fqn_populated = true;

        for (uint32_t i = 0; i < this->numTypes; ++i) {
            auto t = get_type(i);

            if (t == nullptr) {
                continue;
            }

            g_tdb_fqn_map[t->get_fqn_hash()] = t;
        }
    }

    {
        std::shared_lock _{ g_tdb_fqn_mtx };
        if (auto it = g_tdb_fqn_map.find(fqn); it != g_tdb_fqn_map.end()) {
            return it->second;
        }
    }

    return nullptr;
}

sdk::REMethodDefinition* get_object_method(::REManagedObject* object, std::string_view name) {
    auto t = utility::re_managed_object::get_type_definition(object);

    if (t == nullptr) {
        return nullptr;
    }

    return t->get_method(name);
}


sdk::RETypeDefinition* find_type_definition(std::string_view type_name) {
    auto tdb = sdk::RETypeDB::get();

    if (tdb == nullptr) {
        return nullptr;
    }

    return tdb->find_type(type_name);
}

sdk::RETypeDefinition* find_type_definition_by_fqn(uint32_t fqn) {
    auto tdb = sdk::RETypeDB::get();

    if (tdb == nullptr) {
        return nullptr;
    }

    return tdb->find_type_by_fqn(fqn);
}

sdk::REMethodDefinition* find_method_definition(std::string_view type_name, std::string_view method_name) {
    auto t = find_type_definition(type_name);

    if (t == nullptr) {
        return nullptr;
    }

    return t->get_method(method_name);
}

void* find_native_method(sdk::RETypeDefinition* t, std::string_view method_name) {
    const auto method = t->get_method(method_name);

    if (method == nullptr) {
        // spdlog::error("Cannot find {:s}", method_name.data());
        return nullptr;
    }

    return method->get_function();
}

void* find_native_method(std::string_view type_name, std::string_view method_name) {
    auto t = sdk::find_type_definition(type_name);

    if (t == nullptr) {
        //spdlog::error("Cannot find type {:s}", type_name.data());
        return nullptr;
    }

    return find_native_method(t, method_name);
}

sdk::RETypeDefinition* RETypeDB::get_type(uint32_t index) const {
    index &= get_type_bitmask();

    if (index >= this->get_num_types()) {
        return nullptr;
    }

    return &(*this->types)[index];
}

sdk::REMethodDefinition* RETypeDB::get_method(uint32_t index) const {
    if (index >= this->numMethods) {
        return nullptr;
    }

    return &(*this->methods)[index];
}

sdk::REField* RETypeDB::get_field(uint32_t index) const {
    if (index >= this->numFields) {
        return nullptr;
    }

    return &(*this->fields)[index];
}

sdk::REProperty* RETypeDB::get_property(uint32_t index) const {
    if (index >= this->numProperties) {
        return nullptr;
    }

    return &(*this->properties)[index];
}

const char* RETypeDB::get_string(uint32_t offset) const {
    offset &= get_string_pool_bitmask();

    if (offset >= this->numStringPool) {
        return nullptr;
    }

    return (const char*)((uintptr_t)this->stringPool + offset);
}

uint8_t* RETypeDB::get_bytes(uint32_t offset) const {
    offset &= get_byte_pool_bitmask();

    if (offset >= this->numBytePool) {
        return nullptr;
    }

    return (uint8_t*)((uintptr_t)this->bytePool + offset);
}
}

namespace sdk {
sdk::RETypeDefinition* REField::get_declaring_type() const {
    auto tdb = RETypeDB::get();

    if (this->declaring_typeid == 0) {
        return nullptr;
    }

    return tdb->get_type(this->declaring_typeid);
}

sdk::RETypeDefinition* REField::get_type() const {
    auto tdb = RETypeDB::get();

    const auto field_typeid = this->field_typeid;

    if (field_typeid == 0) {
        return nullptr;
    }

    return tdb->get_type(field_typeid);
}

const char* REField::get_name() const {
    auto tdb = RETypeDB::get();

    auto& impl = (*tdb->fieldsImpl)[this->impl_id];
    const auto name_offset = impl.name_offset & tdb->get_string_pool_bitmask();

    return tdb->get_string(name_offset);
}

uint32_t REField::get_flags() const {
    auto tdb = RETypeDB::get();

    auto& impl = (*tdb->fieldsImpl)[this->impl_id];
    return impl.flags;
}

uint32_t REField::get_init_data_index() const {
    auto tdb = RETypeDB::get();
    
    auto& impl = (*tdb->fieldsImpl)[this->impl_id];
    const auto init_data_index = impl.init_data_lo | (impl.init_data_mid << 6) | (this->init_data_hi << 10); // what the FUCK!!! IS THIS SHIT!!!

    return init_data_index;
}

void* REField::get_init_data() const {
    auto tdb = RETypeDB::get();

    const auto init_data_index = get_init_data_index();

    const auto init_data_offset = (*tdb->initData)[init_data_index];

    auto init_data = tdb->get_bytes(init_data_offset);

    // WACKY
    if (init_data_offset < 0) {
        init_data = (uint8_t*)tdb->get_string(init_data_offset * -1);
    }

    return init_data;
}

uint32_t REField::get_offset_from_fieldptr() const {
    const auto tdb = sdk::RETypeDB::get();
    return (*tdb->fieldsImpl)[this->impl_id].offset;
}

uint32_t REField::get_offset_from_base() const {
    auto offset_from_fieldptr = get_offset_from_fieldptr();
    auto declaring_type = this->get_declaring_type();

    if (declaring_type != nullptr) {
        if (declaring_type->has_fieldptr_offset()) {
            return declaring_type->get_fieldptr_offset() + offset_from_fieldptr;
        }
    }

    return offset_from_fieldptr;
}

bool sdk::REField::is_static() const {
    const auto field_flags = this->get_flags();

    return (field_flags & (uint16_t)::via::clr::FieldFlag::Static) != 0;
}

bool sdk::REField::is_literal() const  {
    const auto field_flags = this->get_flags();

    return (field_flags & (uint16_t)::via::clr::FieldFlag::Literal) != 0;
}

void* REField::get_data_raw(void* object, bool is_value_type) const {
    const auto field_flags = get_flags();

    if ((field_flags & (uint16_t)::via::clr::FieldFlag::Static) != 0) {
        if ((field_flags & (uint16_t)::via::clr::FieldFlag::Literal) != 0) {
            return this->get_init_data();
        }

        auto tbl = sdk::VM::get()->get_static_tbl_for_type(this->get_declaring_type()->get_index());

        if (tbl != nullptr) {
            return Address{tbl}.get(this->get_offset_from_fieldptr());
        }
    } else {
        if (is_value_type) {
            return Address{object}.get(this->get_offset_from_fieldptr());
        }


        return Address{object}.get(this->get_offset_from_base());
    }

    return nullptr;
}

uint32_t sdk::REField::get_index() const {
    auto tdb = RETypeDB::get();

    return (uint32_t)(((uintptr_t)this - (uintptr_t)tdb->fields) / sizeof(sdk::REField));
}
} // namespace sdk

// methods
namespace sdk {
sdk::RETypeDefinition* REMethodDefinition::get_declaring_type() const {
    auto tdb = RETypeDB::get();

    if (this->declaring_typeid == 0) {
        return nullptr;
    }

    return tdb->get_type(this->declaring_typeid);
}

sdk::RETypeDefinition* REMethodDefinition::get_return_type() const {
    auto tdb = RETypeDB::get();
    const auto params_index = get_param_index();

    auto param_ids = tdb->get_data<sdk::ParamList>(params_index);
    
    const auto return_param_id = param_ids->returnType;
    const auto& p = (*tdb->params)[return_param_id];

    if (p.type_id == 0) {
        return nullptr;
    }

    const auto return_typeid = p.type_id;

    if (return_typeid == 0) {
        return nullptr;
    }

    return tdb->get_type(return_typeid);
}

const char* REMethodDefinition::get_name() const {
    auto tdb = RETypeDB::get();

    auto& impl = (*tdb->methodsImpl)[this->impl_id];
    const auto name_offset = impl.name_offset & tdb->get_string_pool_bitmask();

    return tdb->get_string(name_offset);
}

std::unordered_set<REMethodDefinition*> logged_encoded_0_methods{};
std::shared_mutex logged_encoded_0_methods_mtx{};

void* REMethodDefinition::get_function() const {
    if (this->encoded_offset == 0) {
        /*const auto dt = this->get_declaring_type();
        
        if (dt != nullptr) {
            if ((dt->type_flags & (uint32_t)via::clr::TypeFlag::Interface) != 0) {
                spdlog::error("[REMethodDefinition::get_function] Interface methods are not implemented yet (method: {})", this->get_name());
                return nullptr;
            }

            if (dt->managed_vt != nullptr && this->get_virtual_index() != -1) {
                auto tdb = RETypeDB::get();
                const auto& impl = (*tdb->typesImpl)[this->impl_id];

                const auto vt = (void**)(dt->managed_vt + impl.num_native_vtable);
                const auto r = vt[this->get_virtual_index()];

                spdlog::info("[REMethodDefinition] {} Found function {:s} at {:x}", this->get_index(), this->get_name(), (uintptr_t)r);

                return r;
            }
        }*/

        {
            std::shared_lock _{ logged_encoded_0_methods_mtx };

            if (logged_encoded_0_methods.contains(const_cast<REMethodDefinition*>(this))) {
                return nullptr;
            }
        }

        std::unique_lock _{ logged_encoded_0_methods_mtx };
        logged_encoded_0_methods.insert(const_cast<REMethodDefinition*>(this));

        auto decl_type = this->get_declaring_type();
        auto name = decl_type != nullptr ? decl_type->get_full_name() : std::string{"null"};
        SPDLOG_DEBUG("[REMethodDefinition::get_function] Encoded offset is 0 (vindex {}) (method: {}.{})", this->get_virtual_index(), name, this->get_name());
        return nullptr;
    }

    // The function this function uses to offset from has a predictable pattern as well.
    // So the pattern for that can be searched for if this one breaks.
    // It remains to be seen if this "encoding" is used in games other than MHRise.
    static uintptr_t encoded_function_base = [&]() -> uintptr_t {
        const auto game = utility::get_executable();
        const auto invoke_table = sdk::VM::get_invoke_table();

        if (invoke_table == nullptr) {
            spdlog::error("[REMethodDefinition] Failed to find invoke table, cannot find encoded_function_base");
            return 0;
        }

        const auto first_fn = invoke_table[1];

        if (first_fn == nullptr) {
            spdlog::error("[REMethodDefinition] Failed to find first function in invoke table, cannot find encoded_function_base");
            return 0;
        }

        uintptr_t result = 0;

        utility::exhaustive_decode((uint8_t*)first_fn, 100, [&](utility::ExhaustionContext& ctx) -> utility::ExhaustionResult {
            if (result != 0) {
                return utility::ExhaustionResult::BREAK;
            }

            if (std::string_view{ctx.instrux.Mnemonic} != "LEA") {
                return utility::ExhaustionResult::CONTINUE;
            }

            const auto disp = utility::resolve_displacement(ctx.addr);

            if (!disp) {
                return utility::ExhaustionResult::CONTINUE;
            }

            if (utility::get_module_within(*disp).value_or(nullptr) != game) {
                return utility::ExhaustionResult::CONTINUE;
            }

            result = *disp;
            return utility::ExhaustionResult::BREAK;
        });

        spdlog::info("[REMethodDefinition] Found encoded_function_base at {:x}", result);

        return result;
    }();

    static void* (*get_encoded_pointer)(int32_t offset) = []() {
        spdlog::info("[REMethodDefinition] Finding get_encoded_pointer");

        auto fn = utility::scan(utility::get_executable(), "85 C9 75 03 33 C0 C3 48 63 C1 48 8d 0D ? ? ? ? 48 03 C1 C3");

        // Alternative scan where we find the first LEA instruction that loads a pointer to a function basically
        // inside the invoke table.
        if (!fn) {
            spdlog::error("[REMethodDefinition] Failed to find get_encoded_pointer");

            return (void* (*)(int32_t))nullptr;
        }

        spdlog::info("[REMethodDefinition] Found get_encoded_pointer at {:x}", *fn);

        return (void* (*)(int32_t))*fn;
    }();

    if (get_encoded_pointer == nullptr) {
        if (encoded_function_base != 0) {
            return (void*)(encoded_function_base + this->encoded_offset);
        }

        return nullptr;
    }

    auto result = get_encoded_pointer(this->encoded_offset);

    if (result == nullptr) {
        spdlog::error("[REMethodDefinition] Failed to get function from encoded offset, method index: {}", this->get_index());
    }

    return result;
}

uint32_t sdk::REMethodDefinition::get_invoke_id() const {
    auto tdb = RETypeDB::get();

    const auto params_index = get_param_index();

    const auto param_list = params_index;
    const auto param_ids = tdb->get_data<sdk::ParamList>(param_list);
    const auto num_params = param_ids->numParams;
    const auto invoke_id = param_ids->invokeID;

    return invoke_id;
}

reframework::InvokeRet sdk::REMethodDefinition::invoke(void* object, const std::span<void*>& args) const {
    ::reframework::InvokeRet out{};
    invoke(object, args, out);

    return out;
}

void sdk::REMethodDefinition::invoke(void* object, const std::span<void*>& args, ::reframework::InvokeRet& out) const {
    const auto num_params = get_num_params();

    if (num_params != args.size()) {
        //throw std::runtime_error("Invalid number of arguments");
        const auto declaring_type = get_declaring_type();
        const auto decltype_name = declaring_type != nullptr ? declaring_type->get_full_name() : "unknownclass";
        spdlog::warn("Invalid number of arguments passed to REMethodDefinition::invoke for {}.{}", decltype_name, get_name());
        return;
    }

    const auto invoke_tbl = sdk::get_invoke_table();
    auto invoke_wrapper = invoke_tbl[get_invoke_id()];

    struct StackFrame {
        char pad_0000[8+8]; //0x0000
        const sdk::REMethodDefinition* method;
        char pad_0010[24]; //0x0018
        void* in_data; //0x0030 can point to data
        void* out_data; //0x0038 can be whatever, can be a dword, can point to data
        void* object_ptr; //0x0040 aka "this" pointer
    };

    StackFrame stack_frame{};
    stack_frame.method = this;
    stack_frame.object_ptr = object;
    stack_frame.in_data = (void*)args.data();
    
    auto ret_ty = get_return_type();
    bool is_ptr = false;
 
    // vec3 and stuff that is > sizeof(void*) requires special handling
    // by preallocating the output buffer
    if (ret_ty != nullptr && ret_ty->is_value_type()) {
        if (ret_ty->get_valuetype_size() > sizeof(void*) || (!ret_ty->is_primitive() && !ret_ty->is_enum())) {
            stack_frame.out_data = &out;
            is_ptr = false;
        } else {
            stack_frame.out_data = nullptr;
            is_ptr = true;
        }
    } else {
        stack_frame.out_data = nullptr;
        is_ptr = true;
    }
    
    {
        auto context = sdk::get_thread_context();
        sdk::VMContext::ScopedTranslator scoped_translator{context};

        bool corrupted_before_call = context->unkPtr != nullptr && context->unkPtr->unkPtr != nullptr;

        try {
            invoke_wrapper((void*)&stack_frame, context);
            out.exception_thrown = false;

            // exception pointer
            if (context->unkPtr->unkPtr != nullptr) {
                const auto declaring_type = get_declaring_type();
                const auto decltype_name = declaring_type != nullptr ? declaring_type->get_full_name() : "unknownclass";
                spdlog::error("Internal game exception thrown in REMethodDefinition::invoke for {}.{}", decltype_name, get_name());

                const auto exception_managed_object = (::REManagedObject*)context->unkPtr->unkPtr;

                if (utility::re_managed_object::is_managed_object(exception_managed_object)) {
                    const auto exception_tdb_type = utility::re_managed_object::get_type_definition(exception_managed_object);

                    if (exception_tdb_type != nullptr) {
                        const auto exception_name = exception_tdb_type->get_full_name();
                        spdlog::error(" Exception name: {}", exception_name.data());
                    }
                }

                if (corrupted_before_call) {
                    spdlog::error("VMContext was already corrupted before this call, a previous exception may not have been handled properly");
                }

                out.exception_thrown = true;

                context->unkPtr->unkPtr = nullptr;
            }
        } catch (sdk::VMContext::Exception&) {
            const auto declaring_type = get_declaring_type();
            const auto decltype_name = declaring_type != nullptr ? declaring_type->get_full_name() : "unknownclass";

            spdlog::error("Exception thrown in REMethodDefinition::invoke for {}.{}", decltype_name, get_name());
            context->cleanup_after_exception(scoped_translator.get_prev_reference_count());
            
            memset(&out, 0, sizeof(out));

            if (!is_ptr) {
                out.ptr = out.bytes.data();
            }

            out.exception_thrown = true;

            return;
        }
    }

    if (stack_frame.out_data != &out) {
        out.ptr = stack_frame.out_data;
        return;
    }

    return;
}

uint32_t sdk::REMethodDefinition::get_index() const {
    auto tdb = RETypeDB::get();

    return (uint32_t)(((uintptr_t)this - (uintptr_t)tdb->methods) / sizeof(sdk::REMethodDefinition));
}

int32_t REMethodDefinition::get_virtual_index() const {
    auto tdb = RETypeDB::get();
    auto& impl = (*tdb->methodsImpl)[this->impl_id];
    return impl.vtable_index;
}

uint16_t REMethodDefinition::get_flags() const {
    auto tdb = RETypeDB::get();
    auto& impl = (*tdb->methodsImpl)[this->impl_id];
    return impl.flags;
}

uint16_t REMethodDefinition::get_impl_flags() const {
    auto tdb = RETypeDB::get();
    auto& impl = (*tdb->methodsImpl)[this->impl_id];
    return impl.impl_flags;
}

bool REMethodDefinition::is_static() const {
    const auto method_flags = this->get_flags();

    return (method_flags & (uint16_t)::via::clr::MethodFlag::Static) != 0;
}

uint32_t sdk::REMethodDefinition::get_num_params() const {
    const auto params_index = get_param_index();

    auto tdb = RETypeDB::get();
    const auto param_list = params_index;
    const auto param_ids = tdb->get_data<sdk::ParamList>(param_list);
    return param_ids->numParams;
}

std::vector<uint32_t> REMethodDefinition::get_param_typeids() const {
    const auto param_list = get_param_index();

    auto tdb = RETypeDB::get();

    std::vector<uint32_t> out{};

    // Parameters
    auto param_ids = tdb->get_data<sdk::ParamList>(param_list);
    const auto num_params = param_ids->numParams;

    // Parse all params
    for (auto f = 0; f < num_params; ++f) {
        const auto param_index = param_ids->params[f] & tdb->get_param_bitmask();

        if (param_index >= tdb->numParams) {
            break;
        }

        auto& p = (*tdb->params)[param_index];

        out.push_back(p.type_id);
    }

    return out;
}

std::vector<sdk::RETypeDefinition*> REMethodDefinition::get_param_types() const {
    auto typeids = get_param_typeids();

    if (typeids.empty()) {
        return {};
    }

    auto tdb = RETypeDB::get();
    std::vector<sdk::RETypeDefinition*> out{};

    static const auto system_object = tdb->find_type("System.Object");

    for (auto id : typeids) {
        const auto t = tdb->get_type(id);

        if (t == nullptr) {
            out.push_back(system_object); // TODO: this is a hack. not sure why this happens
            continue;
        }
        out.push_back(t);
    }

    return out;
}

std::vector<const char*> REMethodDefinition::get_param_names() const {
    std::vector<const char*> out{};

    auto tdb = RETypeDB::get();
    const auto param_list = get_param_index();

    auto param_ids = tdb->get_data<sdk::ParamList>(param_list);
    const auto num_params = param_ids->numParams;

    // Parse all params
    for (auto f = 0; f < num_params; ++f) {
        const auto param_index = param_ids->params[f];

        if (param_index >= tdb->numParams) {
            break;
        }

        auto& p = (*tdb->params)[param_index];

        out.push_back(tdb->get_string(p.name_offset));
    }

    return out;
}

const char* REModule::get_assembly_name() const {
    auto tdb = RETypeDB::get();
    return tdb->get_string(this->assembly_name_offset);
}

const char* REModule::get_location() const {
    auto tdb = RETypeDB::get();
    return tdb->get_string(this->location_offset);
}

const char* REModule::get_module_name() const {
    auto tdb = RETypeDB::get();
    return tdb->get_string(this->module_name_offset);
}

std::span<uint32_t> REModule::get_types() const {
    auto tdb = RETypeDB::get();
    return std::span<uint32_t>{(uint32_t*)tdb->get_bytes(this->types_start), (size_t)this->types_count};
}

std::span<uint32_t> REModule::get_methods() const {
    auto tdb = RETypeDB::get();

    return std::span<uint32_t>{(uint32_t*)tdb->get_bytes(this->methods_start), (size_t)this->methods_count};
}

std::span<uint32_t> REModule::get_instantiated_methods() const {
    auto tdb = RETypeDB::get();

    return std::span<uint32_t>{(uint32_t*)tdb->get_bytes(this->method_instantiations_start), (size_t)this->method_instantiations_count};
}

std::span<uint32_t> REModule::get_member_references() const {
    auto tdb = RETypeDB::get();

    return std::span<uint32_t>{(uint32_t*)tdb->get_bytes(this->member_references_start), (size_t)this->member_references_count};
}
} // namespace sdk
