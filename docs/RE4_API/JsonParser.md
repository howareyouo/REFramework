# `JsonParser.*`

11 types.

## `JsonParser.Array`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Elements` | `System.Collections.Generic.List`1<JsonParser.Value>` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void enumValues(System.Action`1<JsonParser.Value>)
```

## `JsonParser.Object`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Elements` | `System.Collections.Generic.List`1<JsonParser.ObjectElement>` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void enumValues(System.Action`1<JsonParser.Value>)
:System.Void findValue(System.String, System.Action`1<JsonParser.Value>)
:JsonParser.Array getArray(System.String)
:JsonParser.Object getObject(System.String)
:System.String getString(System.String)
```

## `JsonParser.ObjectElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Name` | `System.String` |  | 16 |
| `Value` | `JsonParser.Value` |  | 24 |

## `JsonParser.ObjectElement[]`

**Methods**

```lua
:System.Void Add(JsonParser.ObjectElement)
:JsonParser.ObjectElement Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(JsonParser.ObjectElement)
:System.Void CopyTo(JsonParser.ObjectElement[], System.Int32)
:JsonParser.ObjectElement Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<JsonParser.ObjectElement> GetEnumerator()
:System.Int32 IndexOf(JsonParser.ObjectElement)
:System.Void Insert(System.Int32, JsonParser.ObjectElement)
:System.Boolean Remove(JsonParser.ObjectElement)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, JsonParser.ObjectElement)
:JsonParser.ObjectElement get_Item(System.Int32)
:System.Void set_Item(System.Int32, JsonParser.ObjectElement)
```

## `JsonParser.Phase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Idle` | `JsonParser.Phase` | yes | 16 |
| `Name` | `JsonParser.Phase` | yes | 16 |
| `Value` | `JsonParser.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `JsonParser.Phase[]`

**Methods**

```lua
:System.Void Add(JsonParser.Phase)
:JsonParser.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(JsonParser.Phase)
:System.Void CopyTo(JsonParser.Phase[], System.Int32)
:JsonParser.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<JsonParser.Phase> GetEnumerator()
:System.Int32 IndexOf(JsonParser.Phase)
:System.Void Insert(System.Int32, JsonParser.Phase)
:System.Boolean Remove(JsonParser.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, JsonParser.Phase)
:JsonParser.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, JsonParser.Phase)
```

## `JsonParser.StringConsumer`

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

## `JsonParser.Value`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Raw` | `System.String` |  | 16 |
| `Type` | `JsonParser.ValueType` |  | 24 |
| `Name` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.String, System.String)
:System.Void .ctor(System.String, JsonParser.ValueType, System.String)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Array` | `JsonParser.ValueType` | yes | 16 |
| `False` | `JsonParser.ValueType` | yes | 16 |
| `Null` | `JsonParser.ValueType` | yes | 16 |
| `Number` | `JsonParser.ValueType` | yes | 16 |
| `Object` | `JsonParser.ValueType` | yes | 16 |
| `String` | `JsonParser.ValueType` | yes | 16 |
| `True` | `JsonParser.ValueType` | yes | 16 |
| `Unknown` | `JsonParser.ValueType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `JsonParser.ValueType[]`

**Methods**

```lua
:System.Void Add(JsonParser.ValueType)
:JsonParser.ValueType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(JsonParser.ValueType)
:System.Void CopyTo(JsonParser.ValueType[], System.Int32)
:JsonParser.ValueType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<JsonParser.ValueType> GetEnumerator()
:System.Int32 IndexOf(JsonParser.ValueType)
:System.Void Insert(System.Int32, JsonParser.ValueType)
:System.Boolean Remove(JsonParser.ValueType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, JsonParser.ValueType)
:JsonParser.ValueType get_Item(System.Int32)
:System.Void set_Item(System.Int32, JsonParser.ValueType)
```

## `JsonParser.Value[]`

**Methods**

```lua
:System.Void Add(JsonParser.Value)
:JsonParser.Value Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(JsonParser.Value)
:System.Void CopyTo(JsonParser.Value[], System.Int32)
:JsonParser.Value Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<JsonParser.Value> GetEnumerator()
:System.Int32 IndexOf(JsonParser.Value)
:System.Void Insert(System.Int32, JsonParser.Value)
:System.Boolean Remove(JsonParser.Value)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, JsonParser.Value)
:JsonParser.Value get_Item(System.Int32)
:System.Void set_Item(System.Int32, JsonParser.Value)
```
