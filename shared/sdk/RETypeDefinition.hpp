#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

#include "RETypeCLR.hpp"
#include "ReClass.hpp"
#include "TDBVer.hpp"

class REManagedObject;

// Manual definitions of REClassInfo because ReClass doesn't have bitfields like this.
namespace sdk {
struct RETypeDefVersion71;

struct REField;
struct REMethodDefinition;
struct REProperty;
struct RETypeDefinition;
struct GenericListData;


struct RETypeDefVersion71 {
    uint64_t index : TYPE_INDEX_BITS;
    uint64_t parent_typeid : TYPE_INDEX_BITS;
    uint64_t declaring_typeid : TYPE_INDEX_BITS;
    uint64_t underlying_typeid : 7;

   	uint64_t array_typeid_TBD : TYPE_INDEX_BITS;
   	uint64_t element_typeid_TBD : TYPE_INDEX_BITS;

    uint64_t impl_index : 18;
    uint64_t system_typeid : 7;

    uint32_t type_flags;
    uint32_t size;
    uint32_t fqn_hash;
    uint32_t type_crc;
    uint64_t default_ctor : 22;
    uint64_t member_method : 22;
    uint64_t member_field : TYPE_INDEX_BITS;
    uint32_t num_member_prop : 12;
    uint32_t member_prop : TYPE_INDEX_BITS;

    uint32_t unk_data : 26;
    uint32_t object_type : 3;

    int64_t unk_data_before_generics : 26;
	int64_t generics : 26;
  	int64_t interfaces : 12;
    struct sdk::RETypeCLR* type;
    class ::REObjectInfo* managed_vt;
};

static_assert(sizeof(RETypeDefVersion71) == 0x48, "RETypeDefVersion71 has wrong size");
static_assert(offsetof(RETypeDefVersion71, type_crc) == 0x1C);


#pragma pack(push, 1)
#pragma pack(pop)

} // namespace sdk

// helper class
namespace sdk {
struct RETypeDefinition : public sdk::RETypeDefinition_ {
    class MethodIterator {
    public:
        MethodIterator(const sdk::RETypeDefinition* parent)
            : m_parent{parent} {}

        sdk::REMethodDefinition* begin() const;
        sdk::REMethodDefinition* end() const;
        size_t size() const;

    private:
        const sdk::RETypeDefinition* m_parent;
    };

    class FieldIterator {
    public:
        FieldIterator(const sdk::RETypeDefinition* parent) : m_parent{parent} {}

        // We need this because RE7's fields are non-contiguous in memory
        // and because we want parity with the other games without ifdefs everywhere
        class REFieldIterator {
        public:
            REFieldIterator(const sdk::RETypeDefinition* parent, size_t start = 0)
                : m_parent{parent},
                m_index{start}
            {
            }

            sdk::REField* operator*() const;
            REFieldIterator& operator++() {
                m_index++;
                return *this;
            }

            bool operator==(const REFieldIterator& other) const {
                return m_index == other.m_index && m_parent == other.m_parent;
            }
            
            bool operator!=(const REFieldIterator& other) const {
                return m_index != other.m_index || m_parent != other.m_parent;
            }
        private:
            const sdk::RETypeDefinition* m_parent;
            size_t m_index{0};
        };

        REFieldIterator begin() const {
            return REFieldIterator{m_parent};
        }

        REFieldIterator end() const {
            return REFieldIterator{m_parent, size()};
        }

        size_t size() const;

    private:
        const sdk::RETypeDefinition* m_parent;
    };

    class PropertyIterator {
    public:
        PropertyIterator(const sdk::RETypeDefinition* parent)
            : m_parent{parent} {}

        sdk::REProperty* begin() const;
        sdk::REProperty* end() const;

        size_t size() const;

    private:
        const sdk::RETypeDefinition* m_parent;
    };

    MethodIterator get_methods() const { return MethodIterator{this}; }
    FieldIterator get_fields() const { return FieldIterator{this}; }
    PropertyIterator get_properties() const { return PropertyIterator{this}; }

    const char* get_namespace() const;
    const char* get_name() const;

    std::string get_full_name() const;
    std::vector<std::string> get_name_hierarchy() const;

    sdk::RETypeDefinition* get_declaring_type() const;
    sdk::RETypeDefinition* get_parent_type() const;
    sdk::RETypeDefinition* get_underlying_type() const;
    sdk::RETypeDefinition* get_generic_type_definition() const;
    sdk::REField* get_field(std::string_view name) const;
    sdk::REMethodDefinition* get_method(std::string_view name) const;
    std::vector<sdk::REMethodDefinition*> get_methods(std::string_view name) const;
    std::vector<sdk::RETypeDefinition*> get_generic_argument_types() const;
    sdk::GenericListData* get_generic_data() const;

    uint32_t get_index() const;
    int32_t get_fieldptr_offset() const;
    bool has_fieldptr_offset() const;
    bool is_a(const sdk::RETypeDefinition* other) const;
    bool is_a(std::string_view other) const;

    ::via::clr::VMObjType get_vm_obj_type() const;
    bool is_value_type() const;
    bool is_enum() const;
    bool is_array() const;
    bool is_by_ref() const;
    bool is_pointer() const;
    bool is_primitive() const;
    bool is_generic_type_definition() const;
    bool is_generic_type() const;
    bool has_attribute(::REManagedObject* attribute_runtime_type, bool inherit = false) const;

    bool should_pass_by_pointer() const;

    uint32_t get_crc_hash() const;
    uint32_t get_fqn_hash() const;
    uint32_t get_size() const;
    uint32_t get_valuetype_size() const;
    ::REType* get_type() const;
    ::REManagedObject* get_runtime_type() const;

    void* get_instance() const;
    void* create_instance() const;
    ::REManagedObject* create_instance_full(bool simplify = false);
    ::REObjectInfo* get_managed_vt() const;
    uint32_t get_flags() const;

    std::vector<RETypeDefinition*> get_types_inherting_from_this() const;

private:    
    void set_vm_obj_type(::via::clr::VMObjType type); // for REFramework shenanigans only!
};
} // namespace sdk