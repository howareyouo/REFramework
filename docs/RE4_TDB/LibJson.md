# `LibJson.*`

9 types.

## `LibJson.Array`

```lua
-- methods
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

```lua
-- fields
Colon: System.String [static]
Comma: System.String [static]
CrLf: System.String [static]
IdentRawArray: System.String [static]
IdentRawNull: System.String [static]
IdentRawObject: System.String [static]
IdentUnknownValue: System.String [static]
LeftCurlyBracket: System.String [static]
LeftSquareBracket: System.String [static]
NameArrayArray: System.String [static]
NameArrayObject: System.String [static]
NameArrayValue: System.String [static]
RightCurlyBracket: System.String [static]
RightSquareBracket: System.String [static]
Space: System.String [static]
Tab: System.String [static]
ValueBoolFalse: System.String [static]
ValueBoolTrue: System.String [static]
ValueIntTbl: System.String[] [static]
WQuote: System.String [static]
```

## `LibJson.JsonBase`

```lua
-- fields
JsonRootValueName: System.String [static]
-- methods
:LibJson.Value get_RootValue()
:System.Void set_RootValue(LibJson.Value)
```

## `LibJson.JsonReader`

```lua
-- fields
PhaseIdle: System.Int32 [static]
PhaseName: System.Int32 [static]
PhaseValue: System.Int32 [static]
_Consumer: LibJson.StringConsumer
-- methods
:LibJson.Value parseArray(System.String, LibJson.StringConsumer)
:LibJson.Value parseObject(System.String, LibJson.StringConsumer)
:System.String parseString(LibJson.StringConsumer)
:LibJson.Value parseValue(System.String, LibJson.StringConsumer)
:System.Void raiseError(System.String)
:System.Byte toByte(System.Char)
:System.Char toUnicodeChar(System.String)
:System.Void trace()
-- static
:LibJson.Value parse(System.String)
```

## `LibJson.JsonWriter`

```lua
-- fields
SegmentTbl: System.Collections.Generic.List`1<System.String>
-- methods
:System.String flush()
:System.Void writeArray(LibJson.Array, System.Collections.Generic.List`1<System.String>, System.Int32)
:System.Void writeObject(LibJson.Object, System.Collections.Generic.List`1<System.String>, System.Int32)
:System.Void writeValue(LibJson.Value, System.Collections.Generic.List`1<System.String>, System.Int32)
-- static
:System.String escapeString(System.String)
```

## `LibJson.Object`

```lua
-- methods
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

```lua
-- fields
Pt: System.Int32
RawLength: System.Int32
RawString: System.String
-- methods
:System.Char consume()
:System.String get_Data()
:System.Boolean isEnd()
:System.String nextToken()
:System.Char skipWhiteSpace()
:System.Void unConsume()
```

## `LibJson.Value`

```lua
-- methods
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
-- static
:System.String ToRawConstant(System.Int32)
:System.String ToRawConstant(System.Single)
:System.String ToRawConstant(System.Boolean)
```

## `LibJson.ValueType`

```lua
-- fields
Array: System.Int32 [static]
False: System.Int32 [static]
Null: System.Int32 [static]
Number: System.Int32 [static]
Object: System.Int32 [static]
String: System.Int32 [static]
True: System.Int32 [static]
Unknown: System.Int32 [static]
```
