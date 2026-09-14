#pragma once

#define TDB_VER 71

namespace sdk {
struct RETypeDefVersion71;

struct REField;
struct REMethodDefinition;
struct REProperty;
struct RETypeDefinition;

#define TYPE_INDEX_BITS 19
#define FIELD_BITS 19
using RETypeDefinition_ = sdk::RETypeDefVersion71;
} // namespace sdk
