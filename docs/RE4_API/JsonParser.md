# `JsonParser.*`

7 types.

## `JsonParser.Array`

```lua
-- fields
Elements: System.Collections.Generic.List`1<JsonParser.Value>
-- methods
:System.Void enumValues(System.Action`1<JsonParser.Value>)
```

## `JsonParser.Object`

```lua
-- fields
Elements: System.Collections.Generic.List`1<JsonParser.ObjectElement>
-- methods
:System.Void enumValues(System.Action`1<JsonParser.Value>)
:System.Void findValue(System.String, System.Action`1<JsonParser.Value>)
:JsonParser.Array getArray(System.String)
:JsonParser.Object getObject(System.String)
:System.String getString(System.String)
```

## `JsonParser.ObjectElement`

```lua
-- fields
Name: System.String
Value: JsonParser.Value
```

## `JsonParser.Phase`

```lua
-- values (System.Int32 enum)
Idle
Name
Value
```

## `JsonParser.StringConsumer`

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

## `JsonParser.Value`

```lua
-- fields
Name: System.String
Raw: System.String
Type: JsonParser.ValueType
-- methods
:JsonParser.Array asArray()
:System.Boolean asBoolean()
:System.Double asDouble()
:System.Int16 asInt16()
:System.Int32 asInt32()
:System.Int64 asInt64()
:System.SByte asInt8()
:JsonParser.Object asObject()
:System.Single asSingle()
:System.String asString()
:System.UInt16 asUInt16()
:System.UInt32 asUInt32()
:System.UInt64 asUInt64()
:System.Byte asUInt8()
:System.Boolean isArray()
:System.Boolean isBoolean()
:System.Boolean isNull()
:System.Boolean isNumber()
:System.Boolean isObject()
:System.Boolean isString()
```

## `JsonParser.ValueType`

```lua
-- values (System.Int32 enum)
Array
False
Null
Number
Object
String
True
Unknown
```
