#pragma once

#include <array>
#include <cstdint>

#include "RENativeArray.hpp"

#include "ReClass.hpp"



// Structures for CLR types
// Same structure across all the games so we don't care about the ReClass header
namespace sdk {
struct RETypeDefinition;

struct DeserializeSequence {
    uint32_t code : 8;
    uint32_t size : 8;
    uint32_t align : 8;
    uint32_t depth : 6;
    uint32_t is_array_ : 1;
    uint32_t is_static_ : 1;

    uint32_t offset;

    sdk::RETypeDefinition* native_type;

// Helper functions
public:
    sdk::RETypeDefinition* get_native_type() const {
        return native_type;
    }

    uint16_t get_code() const {
        return code;
    }

    uint16_t get_size() const {
        return size;
    }

    uint16_t get_align() const {
        return align;
    }

    uint16_t get_depth() const {
        return depth;
    }

    uint16_t get_offset() const {
        return offset;
    }

    bool is_array() const {
        return is_array_;
    }

    bool is_static() const {
        return is_static_;
    }
};

struct RETypeCLR : public ::REType {
    sdk::NativeArray<sdk::DeserializeSequence> deserializers;

    class ::REType* native_type;
    char* name2;
};
} // namespace sdk