# `LibJson.*`

10 types.

## `LibJson.Array`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Elements>k__BackingField` | `System.Collections.Generic.List`1<LibJson.Value>` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.Int32)
:LibJson.Array addArray()
:LibJson.Value addNullValue()
:LibJson.Object addObject()
:LibJson.Value addValue(System.String)
:LibJson.Value addValue(System.Int32)
:LibJson.Value addValue(System.Single)
:LibJson.Value addValue(System.Boolean)
:System.Collections.Generic.List`1<LibJson.Value> get_Elements()
:System.Void set_Elements(System.Collections.Generic.List`1<LibJson.Value>)
```

## `LibJson.Constant`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Colon` | `System.String` | yes | 16 |
| `Comma` | `System.String` | yes | 16 |
| `CrLf` | `System.String` | yes | 16 |
| `IdentRawArray` | `System.String` | yes | 16 |
| `IdentRawNull` | `System.String` | yes | 16 |
| `IdentRawObject` | `System.String` | yes | 16 |
| `IdentUnknownValue` | `System.String` | yes | 16 |
| `LeftCurlyBracket` | `System.String` | yes | 16 |
| `LeftSquareBracket` | `System.String` | yes | 16 |
| `NameArrayArray` | `System.String` | yes | 16 |
| `NameArrayObject` | `System.String` | yes | 16 |
| `NameArrayValue` | `System.String` | yes | 16 |
| `RightCurlyBracket` | `System.String` | yes | 16 |
| `RightSquareBracket` | `System.String` | yes | 16 |
| `Space` | `System.String` | yes | 16 |
| `Tab` | `System.String` | yes | 16 |
| `ValueBoolFalse` | `System.String` | yes | 16 |
| `ValueBoolTrue` | `System.String` | yes | 16 |
| `ValueIntTbl` | `System.String[]` | yes | 16 |
| `WQuote` | `System.String` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `LibJson.JsonBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `JsonRootValueName` | `System.String` | yes | 16 |
| `<RootValue>k__BackingField` | `LibJson.Value` |  | 16 |

**Methods**

```lua
:LibJson.Value get_RootValue()
:System.Void set_RootValue(LibJson.Value)
```

## `LibJson.JsonReader`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PhaseIdle` | `System.Int32` | yes | 16 |
| `PhaseName` | `System.Int32` | yes | 16 |
| `PhaseValue` | `System.Int32` | yes | 16 |
| `_Consumer` | `LibJson.StringConsumer` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.String)
:LibJson.Value parseArray(System.String, LibJson.StringConsumer)
:LibJson.Value parseObject(System.String, LibJson.StringConsumer)
:System.String parseString(LibJson.StringConsumer)
:LibJson.Value parseValue(System.String, LibJson.StringConsumer)
:System.Void raiseError(System.String)
:System.Byte toByte(System.Char)
:System.Char toUnicodeChar(System.String)
:System.Void trace()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "parse", ...)  -- LibJson.Value parse(System.String)
```

## `LibJson.JsonWriter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SegmentTbl` | `System.Collections.Generic.List`1<System.String>` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String flush()
:System.Void writeArray(LibJson.Array, System.Collections.Generic.List`1<System.String>, System.Int32)
:System.Void writeObject(LibJson.Object, System.Collections.Generic.List`1<System.String>, System.Int32)
:System.Void writeValue(LibJson.Value, System.Collections.Generic.List`1<System.String>, System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "escapeString", ...)  -- System.String escapeString(System.String)
```

## `LibJson.Object`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Elements>k__BackingField` | `System.Collections.Generic.List`1<LibJson.Value>` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.Int32)
:LibJson.Array addArray(System.String)
:LibJson.Value addNullValue(System.String)
:LibJson.Object addObject(System.String)
:LibJson.Value addValue(System.String, System.String)
:LibJson.Value addValue(System.String, System.Int32)
:LibJson.Value addValue(System.String, System.Single)
:LibJson.Value addValue(System.String, System.Boolean)
:LibJson.Value findValue(System.String)
:LibJson.Array getArray(System.String)
:LibJson.Object getObject(System.String)
:System.String getString(System.String)
:System.Collections.Generic.List`1<LibJson.Value> get_Elements()
:System.Void set_Elements(System.Collections.Generic.List`1<LibJson.Value>)
```

## `LibJson.StringConsumer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pt` | `System.Int32` |  | 16 |
| `RawString` | `System.String` |  | 24 |
| `RawLength` | `System.Int32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Char consume()
:System.String get_Data()
:System.Boolean isEnd()
:System.String nextToken()
:System.Char skipWhiteSpace()
:System.Void unConsume()
```

## `LibJson.Value`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Raw>k__BackingField` | `System.String` |  | 16 |
| `<Type>k__BackingField` | `System.Int32` |  | 24 |
| `<Name>k__BackingField` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.String, System.String)
:System.Void .ctor(System.String, System.Int32, System.String)
:System.Void .ctor(System.String, System.Int32, System.Int32)
:System.Void .ctor(System.String, System.Int32, System.Single)
:System.Void .ctor(System.String, System.Int32, System.Boolean)
:System.Void .ctor(System.Int32, System.Int32, System.String)
:System.Void .ctor(System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Single)
:System.Void .ctor(System.Int32, System.Int32, System.Boolean)
:LibJson.Array asArray()
:System.Boolean asBoolean()
:System.Double asDouble()
:System.Int16 asInt16()
:System.Int32 asInt32()
:System.Int64 asInt64()
:System.SByte asInt8()
:LibJson.Object asObject()
:System.Single asSingle()
:System.String asString()
:System.UInt16 asUInt16()
:System.UInt32 asUInt32()
:System.UInt64 asUInt64()
:System.Byte asUInt8()
:System.String get_Name()
:System.String get_Raw()
:System.Int32 get_Type()
:System.Boolean isArray()
:System.Boolean isBoolean()
:System.Boolean isNull()
:System.Boolean isNumber()
:System.Boolean isObject()
:System.Boolean isString()
:System.Void set_Name(System.String)
:System.Void set_Raw(System.String)
:System.Void set_Type(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "ToRawConstant", ...)  -- System.String ToRawConstant(System.Int32)
sdk.call_native_func(nil, type_def, "ToRawConstant", ...)  -- System.String ToRawConstant(System.Single)
sdk.call_native_func(nil, type_def, "ToRawConstant", ...)  -- System.String ToRawConstant(System.Boolean)
```

## `LibJson.ValueType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Array` | `System.Int32` | yes | 16 |
| `False` | `System.Int32` | yes | 16 |
| `Null` | `System.Int32` | yes | 16 |
| `Number` | `System.Int32` | yes | 16 |
| `Object` | `System.Int32` | yes | 16 |
| `String` | `System.Int32` | yes | 16 |
| `True` | `System.Int32` | yes | 16 |
| `Unknown` | `System.Int32` | yes | 16 |

## `LibJson.Value[]`

**Methods**

```lua
:System.Void Add(LibJson.Value)
:LibJson.Value Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(LibJson.Value)
:System.Void CopyTo(LibJson.Value[], System.Int32)
:LibJson.Value Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<LibJson.Value> GetEnumerator()
:System.Int32 IndexOf(LibJson.Value)
:System.Void Insert(System.Int32, LibJson.Value)
:System.Boolean Remove(LibJson.Value)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, LibJson.Value)
:LibJson.Value get_Item(System.Int32)
:System.Void set_Item(System.Int32, LibJson.Value)
```
