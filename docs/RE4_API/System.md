# `System.*`

423 types.

## `System.Action`

**Methods**

```lua
:System.Void Invoke()
```

## `System.Action[]`

**Methods**

```lua
:System.Void Add(System.Action)
:System.Action Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Action)
:System.Void CopyTo(System.Action[], System.Int32)
:System.Action Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Action> GetEnumerator()
:System.Int32 IndexOf(System.Action)
:System.Void Insert(System.Int32, System.Action)
:System.Boolean Remove(System.Action)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Action)
:System.Action get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Action)
```

## `System.Activator`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "CreateInstance", ...)  -- System.Object CreateInstance(System.Type)
sdk.call_native_func(nil, type_def, "createInstance", ...)  -- System.Object createInstance(System.Type)
```

## `System.AppDomain`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `UnhandledException` | `System.UnhandledExceptionEventHandler` |  | 16 |

**Methods**

```lua
:System.Reflection.Assembly[] GetAssemblies()
:System.Void add_UnhandledException(System.UnhandledExceptionEventHandler)
:System.Void remove_UnhandledException(System.UnhandledExceptionEventHandler)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "DefaultExceptionHandler", ...)  -- System.Void DefaultExceptionHandler(System.Object, System.Exception)
sdk.call_native_func(nil, type_def, "get_CurrentDomain", ...)  -- System.AppDomain get_CurrentDomain()
```

## `System.AppDomainUnloadedException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ApplicationException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ArgumentException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ArgumentNullException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ArgumentOutOfRangeException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ArithmeticException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Array`

**Methods**

```lua
:System.Void .ctor()
:System.Int32 Add(System.Object)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Array, System.Int64)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 GetLength(System.Int32)
:System.Int64 GetLongLength(System.Int32)
:System.Int32 GetLowerBound(System.Int32)
:System.Int32 GetUpperBound(System.Int32)
:System.Object GetValue(System.Int32)
:System.Object GetValue(System.Int32, System.Int32)
:System.Object GetValue(System.Int32, System.Int32, System.Int32)
:System.Object GetValue(System.Int64)
:System.Object GetValue(System.Int64, System.Int64)
:System.Object GetValue(System.Int64, System.Int64, System.Int64)
:System.Object GetValue(System.Int32[])
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void SetValue(System.Object, System.Int32)
:System.Void SetValue(System.Object, System.Int64)
:System.Void SetValue(System.Object, System.Int32, System.Int32)
:System.Void SetValue(System.Object, System.Int64, System.Int64)
:System.Void SetValue(System.Object, System.Int32, System.Int32, System.Int32)
:System.Void SetValue(System.Object, System.Int64, System.Int64, System.Int64)
:System.Void SetValue(System.Object, System.Int32[])
:System.String ToString()
:System.Int32 get_Count()
:System.Object get_Item(System.Int32)
:System.Int32 get_Length()
:System.Int32 get_Rank()
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Object)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "BinarySearch", ...)  -- System.Int32 BinarySearch(System.Array, System.Object)
sdk.call_native_func(nil, type_def, "BinarySearch", ...)  -- System.Int32 BinarySearch(System.Array, System.Int32, System.Int32, System.Object)
sdk.call_native_func(nil, type_def, "BinarySearch", ...)  -- System.Int32 BinarySearch(System.Array, System.Object, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "BinarySearch", ...)  -- System.Int32 BinarySearch(System.Array, System.Int32, System.Int32, System.Object, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "Clear", ...)  -- System.Void Clear(System.Array, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Copy", ...)  -- System.Void Copy(System.Array, System.Array, System.Int32)
sdk.call_native_func(nil, type_def, "Copy", ...)  -- System.Void Copy(System.Array, System.Array, System.Int64)
sdk.call_native_func(nil, type_def, "Copy", ...)  -- System.Void Copy(System.Array, System.Int32, System.Array, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Copy", ...)  -- System.Void Copy(System.Array, System.Int64, System.Array, System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "CreateInstance", ...)  -- System.Array CreateInstance(System.Type, System.Int32)
sdk.call_native_func(nil, type_def, "GetMedian", ...)  -- System.Int32 GetMedian(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "IndexOf", ...)  -- System.Int32 IndexOf(System.Array, System.Object)
sdk.call_native_func(nil, type_def, "IndexOf", ...)  -- System.Int32 IndexOf(System.Array, System.Object, System.Int32)
sdk.call_native_func(nil, type_def, "IndexOf", ...)  -- System.Int32 IndexOf(System.Array, System.Object, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "LastIndexOf", ...)  -- System.Int32 LastIndexOf(System.Array, System.Object)
sdk.call_native_func(nil, type_def, "LastIndexOf", ...)  -- System.Int32 LastIndexOf(System.Array, System.Object, System.Int32)
sdk.call_native_func(nil, type_def, "LastIndexOf", ...)  -- System.Int32 LastIndexOf(System.Array, System.Object, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Reverse", ...)  -- System.Void Reverse(System.Array)
sdk.call_native_func(nil, type_def, "Reverse", ...)  -- System.Void Reverse(System.Array, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "SZArraySort", ...)  -- System.Void SZArraySort(System.Array, System.Array, System.Int32, System.Int32, System.Object)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Array)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Array, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Array, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Int32, System.Int32, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "Sort", ...)  -- System.Void Sort(System.Array, System.Array, System.Int32, System.Int32, System.Collections.IComparer)
sdk.call_native_func(nil, type_def, "TrySZBinarySearch", ...)  -- System.Boolean TrySZBinarySearch(System.Array, System.Int32, System.Int32, System.Object, System.Int32)
```

## `System.Array.InternalEnumeratorDefault`

**Methods**

```lua
:System.Void .ctor()
```

## `System.Array.SZArrayEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mArray` | `System.Array` |  | 16 |
| `mIndex` | `System.Int32` |  | 24 |
| `mCount` | `System.Int32` |  | 28 |
| `mStart` | `System.Int32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Array)
:System.Void .ctor(System.Array, System.Int32)
:System.Void .ctor(System.Array, System.Int32, System.Int32)
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.ArrayTypeMismatchException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.AsyncCallback`

**Methods**

```lua
:System.Void Invoke(System.IAsyncResult)
```

## `System.Attribute`

**Methods**

```lua
:System.Boolean Match(System.Object)
:System.Object get_TypeId()
```

## `System.AttributeTargets`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `All` | `System.AttributeTargets` | yes | 16 |
| `Assembly` | `System.AttributeTargets` | yes | 16 |
| `Class` | `System.AttributeTargets` | yes | 16 |
| `Constructor` | `System.AttributeTargets` | yes | 16 |
| `Delegate` | `System.AttributeTargets` | yes | 16 |
| `Enum` | `System.AttributeTargets` | yes | 16 |
| `Event` | `System.AttributeTargets` | yes | 16 |
| `Field` | `System.AttributeTargets` | yes | 16 |
| `Interface` | `System.AttributeTargets` | yes | 16 |
| `Method` | `System.AttributeTargets` | yes | 16 |
| `Module` | `System.AttributeTargets` | yes | 16 |
| `Parameter` | `System.AttributeTargets` | yes | 16 |
| `Property` | `System.AttributeTargets` | yes | 16 |
| `ReturnValue` | `System.AttributeTargets` | yes | 16 |
| `Struct` | `System.AttributeTargets` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.AttributeTargets[]`

**Methods**

```lua
:System.Void Add(System.AttributeTargets)
:System.AttributeTargets Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.AttributeTargets)
:System.Void CopyTo(System.AttributeTargets[], System.Int32)
:System.AttributeTargets Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.AttributeTargets> GetEnumerator()
:System.Int32 IndexOf(System.AttributeTargets)
:System.Void Insert(System.Int32, System.AttributeTargets)
:System.Boolean Remove(System.AttributeTargets)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.AttributeTargets)
:System.AttributeTargets get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.AttributeTargets)
```

## `System.AttributeUsageAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Default` | `System.AttributeUsageAttribute` | yes | 16 |
| `mAttributeTarget` | `System.AttributeTargets` |  | 16 |
| `mAllowMultiple` | `System.Boolean` |  | 20 |
| `mInherited` | `System.Boolean` |  | 21 |

**Methods**

```lua
:System.Void .ctor(System.AttributeTargets)
:System.Boolean get_AllowMultiple()
:System.Boolean get_Inherited()
:System.AttributeTargets get_ValidOn()
:System.Void set_AllowMultiple(System.Boolean)
:System.Void set_Inherited(System.Boolean)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Base64FormattingOptions`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `InsertLineBreaks` | `System.Base64FormattingOptions` | yes | 16 |
| `None` | `System.Base64FormattingOptions` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Base64FormattingOptions[]`

**Methods**

```lua
:System.Void Add(System.Base64FormattingOptions)
:System.Base64FormattingOptions Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Base64FormattingOptions)
:System.Void CopyTo(System.Base64FormattingOptions[], System.Int32)
:System.Base64FormattingOptions Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Base64FormattingOptions> GetEnumerator()
:System.Int32 IndexOf(System.Base64FormattingOptions)
:System.Void Insert(System.Int32, System.Base64FormattingOptions)
:System.Boolean Remove(System.Base64FormattingOptions)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Base64FormattingOptions)
:System.Base64FormattingOptions get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Base64FormattingOptions)
```

## `System.BitConverter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IsLittleEndian` | `System.Boolean` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "DoubleToInt64Bits", ...)  -- System.Int64 DoubleToInt64Bits(System.Double)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Boolean)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Char)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Double)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Single)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Int32)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Int64)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.Int16)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.UInt32)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.UInt64)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Byte[] GetBytes(System.UInt16)
sdk.call_native_func(nil, type_def, "Int64BitsToDouble", ...)  -- System.Double Int64BitsToDouble(System.Int64)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Byte[])
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Byte[], System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Byte[], System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Byte[], System.Int32)
```

## `System.Boolean`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `False` | `System.Int32` | yes | 16 |
| `FalseString` | `System.String` | yes | 16 |
| `True` | `System.Int32` | yes | 16 |
| `TrueString` | `System.String` | yes | 24 |
| `mValue` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Boolean)
:System.Boolean Equals(System.Boolean)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Boolean Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Boolean)
```

## `System.Boolean[,]`

**Methods**

```lua
:System.Boolean Address(System.Int32, System.Int32)
:System.Boolean Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Boolean)
```

## `System.Boolean[]`

**Methods**

```lua
:System.Void Add(System.Boolean)
:System.Boolean Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Boolean)
:System.Void CopyTo(System.Boolean[], System.Int32)
:System.Boolean Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Boolean> GetEnumerator()
:System.Int32 IndexOf(System.Boolean)
:System.Void Insert(System.Int32, System.Boolean)
:System.Boolean Remove(System.Boolean)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Boolean)
:System.Boolean get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Boolean)
```

## `System.Boolean[][]`

**Methods**

```lua
:System.Void Add(System.Boolean[])
:System.Boolean[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Boolean[])
:System.Void CopyTo(System.Boolean[][], System.Int32)
:System.Boolean[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Boolean[]> GetEnumerator()
:System.Int32 IndexOf(System.Boolean[])
:System.Void Insert(System.Int32, System.Boolean[])
:System.Boolean Remove(System.Boolean[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Boolean[])
:System.Boolean[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Boolean[])
```

## `System.Byte`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.Byte` | yes | 16 |
| `MinValue` | `System.Byte` | yes | 16 |
| `mValue` | `System.Byte` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Byte)
:System.Boolean Equals(System.Byte)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Byte Parse(System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Byte Parse(System.String, System.NumberStyles)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Byte Parse(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Byte Parse(System.String, System.NumberStyles, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Byte)
```

## `System.Byte[]`

**Methods**

```lua
:System.Void Add(System.Byte)
:System.Byte Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Byte)
:System.Void CopyTo(System.Byte[], System.Int32)
:System.Byte Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Byte> GetEnumerator()
:System.Int32 IndexOf(System.Byte)
:System.Void Insert(System.Int32, System.Byte)
:System.Boolean Remove(System.Byte)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Byte)
:System.Byte get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Byte)
```

## `System.Byte[][]`

**Methods**

```lua
:System.Void Add(System.Byte[])
:System.Byte[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Byte[])
:System.Void CopyTo(System.Byte[][], System.Int32)
:System.Byte[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Byte[]> GetEnumerator()
:System.Int32 IndexOf(System.Byte[])
:System.Void Insert(System.Int32, System.Byte[])
:System.Boolean Remove(System.Byte[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Byte[])
:System.Byte[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Byte[])
```

## `System.Char`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HIGH_SURROGATE_START` | `System.Int32` | yes | 16 |
| `LOW_SURROGATE_END` | `System.Int32` | yes | 16 |
| `MaxValue` | `System.Char` | yes | 16 |
| `MinValue` | `System.Char` | yes | 16 |
| `UNICODE_PLANE00_END` | `System.Int32` | yes | 16 |
| `UNICODE_PLANE01_START` | `System.Int32` | yes | 16 |
| `UNICODE_PLANE16_END` | `System.Int32` | yes | 16 |
| `s_categoryForLatin1` | `System.Byte[]` | yes | 16 |
| `m_value` | `System.Char` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Char)
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.Char)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "CheckLetter", ...)  -- System.Boolean CheckLetter(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "CheckLetterOrDigit", ...)  -- System.Boolean CheckLetterOrDigit(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "CheckNumber", ...)  -- System.Boolean CheckNumber(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "CheckPunctuation", ...)  -- System.Boolean CheckPunctuation(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "CheckSeparator", ...)  -- System.Boolean CheckSeparator(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "CheckSymbol", ...)  -- System.Boolean CheckSymbol(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "ConvertFromUtf32", ...)  -- System.String ConvertFromUtf32(System.Int32)
sdk.call_native_func(nil, type_def, "ConvertToUtf32", ...)  -- System.Int32 ConvertToUtf32(System.Char, System.Char)
sdk.call_native_func(nil, type_def, "ConvertToUtf32", ...)  -- System.Int32 ConvertToUtf32(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "GetLatin1UnicodeCategory", ...)  -- System.Globalization.UnicodeCategory GetLatin1UnicodeCategory(System.Char)
sdk.call_native_func(nil, type_def, "GetNumericValue", ...)  -- System.Double GetNumericValue(System.Char)
sdk.call_native_func(nil, type_def, "GetNumericValue", ...)  -- System.Double GetNumericValue(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "GetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory GetUnicodeCategory(System.Char)
sdk.call_native_func(nil, type_def, "GetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory GetUnicodeCategory(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsAscii", ...)  -- System.Boolean IsAscii(System.Char)
sdk.call_native_func(nil, type_def, "IsControl", ...)  -- System.Boolean IsControl(System.Char)
sdk.call_native_func(nil, type_def, "IsControl", ...)  -- System.Boolean IsControl(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsDigit", ...)  -- System.Boolean IsDigit(System.Char)
sdk.call_native_func(nil, type_def, "IsDigit", ...)  -- System.Boolean IsDigit(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsHighSurrogate", ...)  -- System.Boolean IsHighSurrogate(System.Char)
sdk.call_native_func(nil, type_def, "IsHighSurrogate", ...)  -- System.Boolean IsHighSurrogate(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsLatin1", ...)  -- System.Boolean IsLatin1(System.Char)
sdk.call_native_func(nil, type_def, "IsLetter", ...)  -- System.Boolean IsLetter(System.Char)
sdk.call_native_func(nil, type_def, "IsLetter", ...)  -- System.Boolean IsLetter(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsLetterOrDigit", ...)  -- System.Boolean IsLetterOrDigit(System.Char)
sdk.call_native_func(nil, type_def, "IsLetterOrDigit", ...)  -- System.Boolean IsLetterOrDigit(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsLowSurrogate", ...)  -- System.Boolean IsLowSurrogate(System.Char)
sdk.call_native_func(nil, type_def, "IsLowSurrogate", ...)  -- System.Boolean IsLowSurrogate(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsLower", ...)  -- System.Boolean IsLower(System.Char)
sdk.call_native_func(nil, type_def, "IsLower", ...)  -- System.Boolean IsLower(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsNumber", ...)  -- System.Boolean IsNumber(System.Char)
sdk.call_native_func(nil, type_def, "IsNumber", ...)  -- System.Boolean IsNumber(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsPunctuation", ...)  -- System.Boolean IsPunctuation(System.Char)
sdk.call_native_func(nil, type_def, "IsPunctuation", ...)  -- System.Boolean IsPunctuation(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsSeparator", ...)  -- System.Boolean IsSeparator(System.Char)
sdk.call_native_func(nil, type_def, "IsSeparator", ...)  -- System.Boolean IsSeparator(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsSeparatorLatin1", ...)  -- System.Boolean IsSeparatorLatin1(System.Char)
sdk.call_native_func(nil, type_def, "IsSurrogate", ...)  -- System.Boolean IsSurrogate(System.Char)
sdk.call_native_func(nil, type_def, "IsSurrogate", ...)  -- System.Boolean IsSurrogate(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsSurrogatePair", ...)  -- System.Boolean IsSurrogatePair(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsSurrogatePair", ...)  -- System.Boolean IsSurrogatePair(System.Char, System.Char)
sdk.call_native_func(nil, type_def, "IsSymbol", ...)  -- System.Boolean IsSymbol(System.Char)
sdk.call_native_func(nil, type_def, "IsSymbol", ...)  -- System.Boolean IsSymbol(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsUpper", ...)  -- System.Boolean IsUpper(System.Char)
sdk.call_native_func(nil, type_def, "IsUpper", ...)  -- System.Boolean IsUpper(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsWhiteSpace", ...)  -- System.Boolean IsWhiteSpace(System.Char)
sdk.call_native_func(nil, type_def, "IsWhiteSpace", ...)  -- System.Boolean IsWhiteSpace(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsWhiteSpaceLatin1", ...)  -- System.Boolean IsWhiteSpaceLatin1(System.Char)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Char Parse(System.String)
sdk.call_native_func(nil, type_def, "ToLower", ...)  -- System.Char ToLower(System.Char, System.Globalization.CultureInfo)
sdk.call_native_func(nil, type_def, "ToLower", ...)  -- System.Char ToLower(System.Char)
sdk.call_native_func(nil, type_def, "ToLowerInvariant", ...)  -- System.Char ToLowerInvariant(System.Char)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Char)
sdk.call_native_func(nil, type_def, "ToUpper", ...)  -- System.Char ToUpper(System.Char, System.Globalization.CultureInfo)
sdk.call_native_func(nil, type_def, "ToUpper", ...)  -- System.Char ToUpper(System.Char)
sdk.call_native_func(nil, type_def, "ToUpperInvariant", ...)  -- System.Char ToUpperInvariant(System.Char)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Char)
```

## `System.CharEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_str` | `System.String` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_currentElement` | `System.Char` |  | 28 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Object Clone()
:System.Void Dispose()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object System.Collections.IEnumerator.get_Current()
:System.Char get_Current()
```

## `System.Char[]`

**Methods**

```lua
:System.Void Add(System.Char)
:System.Char Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Char)
:System.Void CopyTo(System.Char[], System.Int32)
:System.Char Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Char> GetEnumerator()
:System.Int32 IndexOf(System.Char)
:System.Void Insert(System.Int32, System.Char)
:System.Boolean Remove(System.Char)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Char)
:System.Char get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Char)
```

## `System.Collections.ArrayList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxArrayLength` | `System.Int32` | yes | 16 |
| `_defaultCapacity` | `System.Int32` | yes | 16 |
| `_items` | `System.Object[]` |  | 16 |
| `_size` | `System.Int32` |  | 24 |
| `_version` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Collections.ICollection)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Int32 BinarySearch(System.Object)
:System.Int32 BinarySearch(System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Void EnsureCapacity(System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse()
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort()
:System.Void Sort(System.Collections.IComparer)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Void TrimToSize()
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Adapter", ...)  -- System.Collections.ArrayList Adapter(System.Collections.IList)
sdk.call_native_func(nil, type_def, "FixedSize", ...)  -- System.Collections.IList FixedSize(System.Collections.IList)
sdk.call_native_func(nil, type_def, "FixedSize", ...)  -- System.Collections.ArrayList FixedSize(System.Collections.ArrayList)
sdk.call_native_func(nil, type_def, "ReadOnly", ...)  -- System.Collections.IList ReadOnly(System.Collections.IList)
sdk.call_native_func(nil, type_def, "ReadOnly", ...)  -- System.Collections.ArrayList ReadOnly(System.Collections.ArrayList)
sdk.call_native_func(nil, type_def, "Repeat", ...)  -- System.Collections.ArrayList Repeat(System.Object, System.Int32)
sdk.call_native_func(nil, type_def, "Synchronized", ...)  -- System.Collections.IList Synchronized(System.Collections.IList)
sdk.call_native_func(nil, type_def, "Synchronized", ...)  -- System.Collections.ArrayList Synchronized(System.Collections.ArrayList)
```

## `System.Collections.ArrayList.ArrayListEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.ArrayList` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_endIndex` | `System.Int32` |  | 28 |
| `_version` | `System.Int32` |  | 32 |
| `_currentElement` | `System.Object` |  | 40 |
| `_startIndex` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList, System.Int32, System.Int32)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.ArrayList.ArrayListEnumeratorSimple`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `s_dummyObject` | `System.Object` | yes | 16 |
| `_list` | `System.Collections.ArrayList` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_version` | `System.Int32` |  | 28 |
| `_currentElement` | `System.Object` |  | 32 |
| `_isArrayList` | `System.Boolean` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Collections.ArrayList.FixedSizeArrayList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.ArrayList` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Void TrimToSize()
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Boolean get_IsReadOnly()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.FixedSizeList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.IList` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Collections.IList)
:System.Int32 Add(System.Object)
:System.Void Clear()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_IsReadOnly()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.IListWrapper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.IList` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Collections.IList)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Boolean get_IsFixedSize()
:System.Boolean get_IsReadOnly()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.IListWrapper.IListWrapperEnumWrapper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_en` | `System.Collections.IEnumerator` |  | 16 |
| `_remaining` | `System.Int32` |  | 24 |
| `_initialStartIndex` | `System.Int32` |  | 28 |
| `_initialCount` | `System.Int32` |  | 32 |
| `_firstCall` | `System.Boolean` |  | 36 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList.IListWrapper, System.Int32, System.Int32)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.ArrayList.Range`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_baseList` | `System.Collections.ArrayList` |  | 32 |
| `_baseIndex` | `System.Int32` |  | 40 |
| `_baseSize` | `System.Int32` |  | 44 |
| `_baseVersion` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList, System.Int32, System.Int32)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Void InternalUpdateRange()
:System.Void InternalUpdateVersion()
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Void TrimToSize()
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Boolean get_IsFixedSize()
:System.Boolean get_IsReadOnly()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.ReadOnlyArrayList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.ArrayList` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Void TrimToSize()
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.ReadOnlyList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.IList` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Collections.IList)
:System.Int32 Add(System.Object)
:System.Void Clear()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.SyncArrayList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.ArrayList` |  | 32 |
| `_root` | `System.Object` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Collections.ArrayList)
:System.Int32 Add(System.Object)
:System.Void AddRange(System.Collections.ICollection)
:System.Int32 BinarySearch(System.Object)
:System.Int32 BinarySearch(System.Object, System.Collections.IComparer)
:System.Int32 BinarySearch(System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyTo(System.Int32, System.Array, System.Int32, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.IEnumerator GetEnumerator(System.Int32, System.Int32)
:System.Collections.ArrayList GetRange(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Object)
:System.Int32 IndexOf(System.Object, System.Int32)
:System.Int32 IndexOf(System.Object, System.Int32, System.Int32)
:System.Void Insert(System.Int32, System.Object)
:System.Void InsertRange(System.Int32, System.Collections.ICollection)
:System.Int32 LastIndexOf(System.Object)
:System.Int32 LastIndexOf(System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Object, System.Int32, System.Int32)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void RemoveRange(System.Int32, System.Int32)
:System.Void Reverse(System.Int32, System.Int32)
:System.Void SetRange(System.Int32, System.Collections.ICollection)
:System.Void Sort()
:System.Void Sort(System.Collections.IComparer)
:System.Void Sort(System.Int32, System.Int32, System.Collections.IComparer)
:System.Object[] ToArray()
:System.Array ToArray(System.Type)
:System.Void TrimToSize()
:System.Int32 get_Capacity()
:System.Int32 get_Count()
:System.Boolean get_IsFixedSize()
:System.Boolean get_IsReadOnly()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.ArrayList.SyncIList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.IList` |  | 16 |
| `_root` | `System.Object` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.Collections.IList)
:System.Int32 Add(System.Object)
:System.Void Clear()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_IsFixedSize()
:System.Boolean get_IsReadOnly()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.BitArray`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BitsPerByte` | `System.Int32` | yes | 16 |
| `BitsPerInt32` | `System.Int32` | yes | 16 |
| `BytesPerInt32` | `System.Int32` | yes | 16 |
| `_ShrinkThreshold` | `System.Int32` | yes | 16 |
| `mArray` | `System.Int32[]` |  | 16 |
| `mLength` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Int32, System.Boolean)
:System.Void .ctor(System.Byte[])
:System.Void .ctor(System.Boolean[])
:System.Void .ctor(System.Int32[])
:System.Void .ctor(System.Collections.BitArray)
:System.Collections.BitArray And(System.Collections.BitArray)
:System.Object Clone()
:System.Void CopyTo(System.Array, System.Int32)
:System.Boolean Get(System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Collections.BitArray Not()
:System.Collections.BitArray Or(System.Collections.BitArray)
:System.Void Set(System.Int32, System.Boolean)
:System.Void SetAll(System.Boolean)
:System.Collections.BitArray Xor(System.Collections.BitArray)
:System.Int32 get_Count()
:System.Boolean get_Item(System.Int32)
:System.Int32 get_Length()
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Boolean)
:System.Void set_Length(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getArrayLength", ...)  -- System.Int32 getArrayLength(System.Int32, System.Int32)
```

## `System.Collections.BitArray.Enumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mBitArray` | `System.Collections.BitArray` |  | 16 |
| `mIndex` | `System.Int32` |  | 24 |
| `mCurrentElement` | `System.Boolean` |  | 28 |

**Methods**

```lua
:System.Void .ctor(System.Collections.BitArray)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.CaseInsensitiveComparer`

**Methods**

```lua
:System.Int32 Compare(System.Object, System.Object)
```

## `System.Collections.Comparer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Default` | `System.Collections.Comparer` | yes | 16 |
| `DefaultInvariant` | `System.Collections.Comparer` | yes | 24 |

**Methods**

```lua
:System.Void .ctor(System.Globalization.CultureInfo)
:System.Int32 Compare(System.Object, System.Object)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Collections.Concurrent.PaddedHeadAndTail`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Head` | `System.Int32` |  | 80 |
| `Tail` | `System.Int32` |  | 144 |

## `System.Collections.DictionaryEntry`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mKey` | `System.Object` |  | 16 |
| `mValue` | `System.Object` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.Object, System.Object)
:System.Object get_Key()
:System.Object get_Value()
```

## `System.Collections.DictionaryEntry[]`

**Methods**

```lua
:System.Void Add(System.Collections.DictionaryEntry)
:System.Collections.DictionaryEntry Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.DictionaryEntry)
:System.Void CopyTo(System.Collections.DictionaryEntry[], System.Int32)
:System.Collections.DictionaryEntry Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.DictionaryEntry> GetEnumerator()
:System.Int32 IndexOf(System.Collections.DictionaryEntry)
:System.Void Insert(System.Int32, System.Collections.DictionaryEntry)
:System.Boolean Remove(System.Collections.DictionaryEntry)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.DictionaryEntry)
:System.Collections.DictionaryEntry get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.DictionaryEntry)
```

## `System.Collections.Generic.BitHelper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IntSize` | `System.Byte` | yes | 16 |
| `MarkedBitFlag` | `System.Byte` | yes | 16 |
| `mArray` | `System.Int32[]` |  | 16 |
| `mLength` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.Int32[], System.Int32)
:System.Boolean IsMarked(System.Int32)
:System.Void MarkBit(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "ToIntArrayLength", ...)  -- System.Int32 ToIntArrayLength(System.Int32)
```

## `System.Collections.Generic.BitHelper2`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IntSize` | `System.Byte` | yes | 16 |
| `MarkedBitFlag` | `System.Byte` | yes | 16 |
| `_length` | `System.Int32` |  | 16 |
| `_arrayPtr` | `System.Int32` |  | 24 |
| `_array` | `System.Int32[]` |  | 32 |
| `_useStackAlloc` | `System.Boolean` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.Int32)
:System.Void .ctor(System.Int32[], System.Int32)
:System.Boolean IsMarked(System.Int32)
:System.Void MarkBit(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "ToIntArrayLength", ...)  -- System.Int32 ToIntArrayLength(System.Int32)
```

## `System.Collections.Generic.CopyPosition`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Row>k__BackingField` | `System.Int32` |  | 16 |
| `<Column>k__BackingField` | `System.Int32` |  | 20 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.Int32)
:System.Collections.Generic.CopyPosition Normalize(System.Int32)
:System.Int32 get_Column()
:System.String get_DebuggerDisplay()
:System.Int32 get_Row()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_Start", ...)  -- System.Collections.Generic.CopyPosition get_Start()
```

## `System.Collections.Generic.EnumerableHelpers`

_No fields or methods._

## `System.Collections.Generic.EnumerableHelpers2`

_No fields or methods._

## `System.Collections.Generic.HashHelper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `primes` | `System.Int32[]` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetPrime", ...)  -- System.Int32 GetPrime(System.Int32)
sdk.call_native_func(nil, type_def, "IsPrime", ...)  -- System.Boolean IsPrime(System.Int32)
```

## `System.Collections.Generic.IntrospectiveSortUtilities`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IntrosortSizeThreshold` | `System.Int32` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "FloorLog2", ...)  -- System.Int32 FloorLog2(System.Int32)
sdk.call_native_func(nil, type_def, "ThrowOrIgnoreBadComparer", ...)  -- System.Void ThrowOrIgnoreBadComparer(System.Object)
```

## `System.Collections.Generic.KeyNotFoundException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Collections.Generic.Marker`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Count>k__BackingField` | `System.Int32` |  | 16 |
| `<Index>k__BackingField` | `System.Int32` |  | 20 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.Int32)
:System.Int32 get_Count()
:System.String get_DebuggerDisplay()
:System.Int32 get_Index()
```

## `System.Collections.Generic.Marker[]`

**Methods**

```lua
:System.Void Add(System.Collections.Generic.Marker)
:System.Collections.Generic.Marker Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.Generic.Marker)
:System.Void CopyTo(System.Collections.Generic.Marker[], System.Int32)
:System.Collections.Generic.Marker Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.Generic.Marker> GetEnumerator()
:System.Int32 IndexOf(System.Collections.Generic.Marker)
:System.Void Insert(System.Int32, System.Collections.Generic.Marker)
:System.Boolean Remove(System.Collections.Generic.Marker)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.Generic.Marker)
:System.Collections.Generic.Marker get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.Generic.Marker)
```

## `System.Collections.Generic.NodeColor`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Black` | `System.Collections.Generic.NodeColor` | yes | 16 |
| `Red` | `System.Collections.Generic.NodeColor` | yes | 16 |
| `value__` | `System.Byte` |  | 16 |

## `System.Collections.Generic.NodeColor[]`

**Methods**

```lua
:System.Void Add(System.Collections.Generic.NodeColor)
:System.Collections.Generic.NodeColor Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.Generic.NodeColor)
:System.Void CopyTo(System.Collections.Generic.NodeColor[], System.Int32)
:System.Collections.Generic.NodeColor Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.Generic.NodeColor> GetEnumerator()
:System.Int32 IndexOf(System.Collections.Generic.NodeColor)
:System.Void Insert(System.Int32, System.Collections.Generic.NodeColor)
:System.Boolean Remove(System.Collections.Generic.NodeColor)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.Generic.NodeColor)
:System.Collections.Generic.NodeColor get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.Generic.NodeColor)
```

## `System.Collections.Generic.TreeRotation`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Left` | `System.Collections.Generic.TreeRotation` | yes | 16 |
| `LeftRight` | `System.Collections.Generic.TreeRotation` | yes | 16 |
| `Right` | `System.Collections.Generic.TreeRotation` | yes | 16 |
| `RightLeft` | `System.Collections.Generic.TreeRotation` | yes | 16 |
| `value__` | `System.Byte` |  | 16 |

## `System.Collections.Generic.TreeRotation[]`

**Methods**

```lua
:System.Void Add(System.Collections.Generic.TreeRotation)
:System.Collections.Generic.TreeRotation Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.Generic.TreeRotation)
:System.Void CopyTo(System.Collections.Generic.TreeRotation[], System.Int32)
:System.Collections.Generic.TreeRotation Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.Generic.TreeRotation> GetEnumerator()
:System.Int32 IndexOf(System.Collections.Generic.TreeRotation)
:System.Void Insert(System.Int32, System.Collections.Generic.TreeRotation)
:System.Boolean Remove(System.Collections.Generic.TreeRotation)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.Generic.TreeRotation)
:System.Collections.Generic.TreeRotation get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.Generic.TreeRotation)
```

## `System.Collections.HashHelpers`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `primes` | `System.Int32[]` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetPrime", ...)  -- System.Int32 GetPrime(System.Int32)
sdk.call_native_func(nil, type_def, "IsPrime", ...)  -- System.Boolean IsPrime(System.Int32)
```

## `System.Collections.HashHelpersCoreFX`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HashCollisionThreshold` | `System.Int32` | yes | 16 |
| `MaxPrimeArrayLength` | `System.Int32` | yes | 16 |
| `primes` | `System.Int32[]` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "ExpandPrime", ...)  -- System.Int32 ExpandPrime(System.Int32)
sdk.call_native_func(nil, type_def, "GetPrime", ...)  -- System.Int32 GetPrime(System.Int32)
sdk.call_native_func(nil, type_def, "IsPrime", ...)  -- System.Boolean IsPrime(System.Int32)
```

## `System.Collections.Hashtable`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ComparerName` | `System.String` | yes | 16 |
| `HashCodeProviderName` | `System.String` | yes | 16 |
| `HashPrime` | `System.Int32` | yes | 16 |
| `HashSizeName` | `System.String` | yes | 16 |
| `InitialSize` | `System.Int32` | yes | 16 |
| `KeyComparerName` | `System.String` | yes | 16 |
| `KeysName` | `System.String` | yes | 16 |
| `LoadFactorName` | `System.String` | yes | 16 |
| `ValuesName` | `System.String` | yes | 16 |
| `VersionName` | `System.String` | yes | 16 |
| `buckets` | `System.Collections.Hashtable.bucket[]` |  | 16 |
| `count` | `System.Int32` |  | 24 |
| `occupancy` | `System.Int32` |  | 28 |
| `loadsize` | `System.Int32` |  | 32 |
| `loadFactor` | `System.Single` |  | 36 |
| `version` | `System.Int32` |  | 40 |
| `isWriterInProgress` | `System.Boolean` |  | 44 |
| `keys` | `System.Collections.ICollection` |  | 48 |
| `values` | `System.Collections.ICollection` |  | 56 |
| `_keycomparer` | `System.Collections.IEqualityComparer` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Int32, System.Single)
:System.Void .ctor(System.Int32, System.Single, System.Collections.IEqualityComparer)
:System.Void .ctor(System.Collections.IEqualityComparer)
:System.Void .ctor(System.Int32, System.Collections.IEqualityComparer)
:System.Void Add(System.Object, System.Object)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Boolean ContainsKey(System.Object)
:System.Void CopyEntries(System.Array, System.Int32)
:System.Void CopyKeys(System.Array, System.Int32)
:System.Void CopyTo(System.Array, System.Int32)
:System.Void CopyValues(System.Array, System.Int32)
:System.Collections.IDictionaryEnumerator GetEnumerator()
:System.Int32 GetHash(System.Object)
:System.UInt32 InitHash(System.Object, System.Int32, System.UInt32, System.UInt32)
:System.Void Insert(System.Object, System.Object, System.Boolean)
:System.Boolean KeyEquals(System.Object, System.Object)
:System.Void Remove(System.Object)
:System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
:System.Void UpdateVersion()
:System.Void expand()
:System.Int32 get_Count()
:System.Object get_Item(System.Object)
:System.Collections.ICollection get_Keys()
:System.Object get_SyncRoot()
:System.Collections.ICollection get_Values()
:System.Void putEntry(System.Collections.Hashtable.bucket[], System.Object, System.Object, System.Int32)
:System.Void rehash()
:System.Void rehash(System.Int32, System.Boolean)
:System.Void set_Item(System.Object, System.Object)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Synchronized", ...)  -- System.Collections.Hashtable Synchronized(System.Collections.Hashtable)
```

## `System.Collections.Hashtable.HashtableEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DictEntry` | `System.Int32` | yes | 16 |
| `Keys` | `System.Int32` | yes | 16 |
| `Values` | `System.Int32` | yes | 16 |
| `hashtable` | `System.Collections.Hashtable` |  | 16 |
| `bucket` | `System.Int32` |  | 24 |
| `version` | `System.Int32` |  | 28 |
| `current` | `System.Boolean` |  | 32 |
| `getObjectRetType` | `System.Int32` |  | 36 |
| `currentKey` | `System.Object` |  | 40 |
| `currentValue` | `System.Object` |  | 48 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Hashtable, System.Int32)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
:System.Collections.DictionaryEntry get_Entry()
:System.Object get_Key()
:System.Object get_Value()
```

## `System.Collections.Hashtable.KeyCollection`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_hashtable` | `System.Collections.Hashtable` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Hashtable)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_SyncRoot()
```

## `System.Collections.Hashtable.SyncHashtable`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_table` | `System.Collections.Hashtable` |  | 72 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Hashtable)
:System.Void Add(System.Object, System.Object)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Boolean ContainsKey(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IDictionaryEnumerator GetEnumerator()
:System.Void Remove(System.Object)
:System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
:System.Int32 get_Count()
:System.Boolean get_IsFixedSize()
:System.Boolean get_IsReadOnly()
:System.Object get_Item(System.Object)
:System.Collections.ICollection get_Keys()
:System.Object get_SyncRoot()
:System.Collections.ICollection get_Values()
:System.Void set_Item(System.Object, System.Object)
```

## `System.Collections.Hashtable.ValueCollection`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_hashtable` | `System.Collections.Hashtable` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Hashtable)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_SyncRoot()
```

## `System.Collections.Hashtable.bucket`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `key` | `System.Object` |  | 16 |
| `val` | `System.Object` |  | 24 |
| `hash_coll` | `System.Int32` |  | 32 |

## `System.Collections.Hashtable.bucket[]`

**Methods**

```lua
:System.Void Add(System.Collections.Hashtable.bucket)
:System.Collections.Hashtable.bucket Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.Hashtable.bucket)
:System.Void CopyTo(System.Collections.Hashtable.bucket[], System.Int32)
:System.Collections.Hashtable.bucket Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.Hashtable.bucket> GetEnumerator()
:System.Int32 IndexOf(System.Collections.Hashtable.bucket)
:System.Void Insert(System.Int32, System.Collections.Hashtable.bucket)
:System.Boolean Remove(System.Collections.Hashtable.bucket)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.Hashtable.bucket)
:System.Collections.Hashtable.bucket get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.Hashtable.bucket)
```

## `System.Collections.ICollection`

_No fields or methods._

## `System.Collections.IComparer`

_No fields or methods._

## `System.Collections.IDictionary`

_No fields or methods._

## `System.Collections.IDictionaryEnumerator`

_No fields or methods._

## `System.Collections.IEnumerable`

_No fields or methods._

## `System.Collections.IEnumerator`

_No fields or methods._

## `System.Collections.IEqualityComparer`

_No fields or methods._

## `System.Collections.IList`

_No fields or methods._

## `System.Collections.IStructuralComparable`

_No fields or methods._

## `System.Collections.IStructuralEquatable`

_No fields or methods._

## `System.Collections.ObjectModel.EventArgsCache`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CountPropertyChanged` | `System.ComponentModel.PropertyChangedEventArgs` | yes | 16 |
| `IndexerPropertyChanged` | `System.ComponentModel.PropertyChangedEventArgs` | yes | 24 |
| `ResetCollectionChanged` | `System.Collections.Specialized.NotifyCollectionChangedEventArgs` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Collections.Queue`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MinimumGrow` | `System.Int32` | yes | 16 |
| `_ShrinkThreshold` | `System.Int32` | yes | 16 |
| `_array` | `System.Object[]` |  | 16 |
| `_head` | `System.Int32` |  | 24 |
| `_tail` | `System.Int32` |  | 28 |
| `_size` | `System.Int32` |  | 32 |
| `_growFactor` | `System.Int32` |  | 36 |
| `_version` | `System.Int32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Int32, System.Single)
:System.Void .ctor(System.Collections.ICollection)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Object Dequeue()
:System.Void Enqueue(System.Object)
:System.Object GetElement(System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Object Peek()
:System.Void SetCapacity(System.Int32)
:System.Object[] ToArray()
:System.Void TrimToSize()
:System.Int32 get_Count()
:System.Object get_SyncRoot()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Synchronized", ...)  -- System.Collections.Queue Synchronized(System.Collections.Queue)
```

## `System.Collections.Queue.QueueEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_q` | `System.Collections.Queue` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_version` | `System.Int32` |  | 28 |
| `_currentElement` | `System.Object` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Queue)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.Queue.SynchronizedQueue`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_q` | `System.Collections.Queue` |  | 48 |
| `_root` | `System.Object` |  | 56 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Queue)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Object Dequeue()
:System.Void Enqueue(System.Object)
:System.Collections.IEnumerator GetEnumerator()
:System.Object Peek()
:System.Object[] ToArray()
:System.Void TrimToSize()
:System.Int32 get_Count()
:System.Object get_SyncRoot()
```

## `System.Collections.Specialized.INotifyCollectionChanged`

_No fields or methods._

## `System.Collections.Specialized.NotifyCollectionChangedAction`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Add` | `System.Collections.Specialized.NotifyCollectionChangedAction` | yes | 16 |
| `Move` | `System.Collections.Specialized.NotifyCollectionChangedAction` | yes | 16 |
| `Remove` | `System.Collections.Specialized.NotifyCollectionChangedAction` | yes | 16 |
| `Replace` | `System.Collections.Specialized.NotifyCollectionChangedAction` | yes | 16 |
| `Reset` | `System.Collections.Specialized.NotifyCollectionChangedAction` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Collections.Specialized.NotifyCollectionChangedAction[]`

**Methods**

```lua
:System.Void Add(System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Collections.Specialized.NotifyCollectionChangedAction Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Void CopyTo(System.Collections.Specialized.NotifyCollectionChangedAction[], System.Int32)
:System.Collections.Specialized.NotifyCollectionChangedAction Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Collections.Specialized.NotifyCollectionChangedAction> GetEnumerator()
:System.Int32 IndexOf(System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Void Insert(System.Int32, System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Boolean Remove(System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Collections.Specialized.NotifyCollectionChangedAction get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Collections.Specialized.NotifyCollectionChangedAction)
```

## `System.Collections.Specialized.NotifyCollectionChangedEventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_action` | `System.Collections.Specialized.NotifyCollectionChangedAction` |  | 16 |
| `_newItems` | `System.Collections.IList` |  | 24 |
| `_oldItems` | `System.Collections.IList` |  | 32 |
| `_newStartingIndex` | `System.Int32` |  | 40 |
| `_oldStartingIndex` | `System.Int32` |  | 44 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Object)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Object, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Object, System.Object)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Object, System.Object, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Collections.IList)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Collections.IList, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Object, System.Int32, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Int32, System.Int32)
:System.Void .ctor(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Collections.IList, System.Int32, System.Int32)
:System.Void InitializeAdd(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Int32)
:System.Void InitializeAddOrRemove(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Int32)
:System.Void InitializeMoveOrReplace(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Collections.IList, System.Int32, System.Int32)
:System.Void InitializeRemove(System.Collections.Specialized.NotifyCollectionChangedAction, System.Collections.IList, System.Int32)
:System.Collections.Specialized.NotifyCollectionChangedAction get_Action()
:System.Collections.IList get_NewItems()
:System.Int32 get_NewStartingIndex()
:System.Collections.IList get_OldItems()
:System.Int32 get_OldStartingIndex()
```

## `System.Collections.Specialized.NotifyCollectionChangedEventHandler`

**Methods**

```lua
:System.Void Invoke(System.Object, System.Collections.Specialized.NotifyCollectionChangedEventArgs)
```

## `System.Collections.Specialized.ReadOnlyList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_list` | `System.Collections.IList` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Collections.IList)
:System.Int32 Add(System.Object)
:System.Void Clear()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Void Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_Item(System.Int32)
:System.Object get_SyncRoot()
:System.Void set_Item(System.Int32, System.Object)
```

## `System.Collections.Stack`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_defaultCapacity` | `System.Int32` | yes | 16 |
| `_array` | `System.Object[]` |  | 16 |
| `_size` | `System.Int32` |  | 24 |
| `_version` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Collections.ICollection)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Object Peek()
:System.Object Pop()
:System.Void Push(System.Object)
:System.Object[] ToArray()
:System.Int32 get_Count()
:System.Object get_SyncRoot()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Synchronized", ...)  -- System.Collections.Stack Synchronized(System.Collections.Stack)
```

## `System.Collections.Stack.StackEnumerator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_stack` | `System.Collections.Stack` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_version` | `System.Int32` |  | 28 |
| `_currentElement` | `System.Object` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Stack)
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.Stack.SyncStack`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_s` | `System.Collections.Stack` |  | 32 |
| `_root` | `System.Object` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Collections.Stack)
:System.Void Clear()
:System.Object Clone()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Object Peek()
:System.Object Pop()
:System.Void Push(System.Object)
:System.Object[] ToArray()
:System.Int32 get_Count()
:System.Object get_SyncRoot()
```

## `System.ComponentModel.INotifyPropertyChanged`

_No fields or methods._

## `System.ComponentModel.PropertyChangedEventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_propertyName` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_PropertyName()
```

## `System.ComponentModel.PropertyChangedEventHandler`

**Methods**

```lua
:System.Void Invoke(System.Object, System.ComponentModel.PropertyChangedEventArgs)
```

## `System.Console`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Clear", ...)  -- System.Void Clear()
sdk.call_native_func(nil, type_def, "OpenStandardOutput", ...)  -- System.IO.Stream OpenStandardOutput()
sdk.call_native_func(nil, type_def, "OpenStandardOutput", ...)  -- System.IO.Stream OpenStandardOutput(System.Int32)
sdk.call_native_func(nil, type_def, "ReadLine", ...)  -- System.String ReadLine()
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Boolean)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Char)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Char[])
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Decimal)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Double)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Single)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.SByte)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Byte)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int16)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt16)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int32)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt32)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int64)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt64)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Object)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String, System.Object)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String, System.Object, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.String)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine()
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Boolean)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Char)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Char[])
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Decimal)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Double)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Single)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.SByte)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Byte)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Int16)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.UInt16)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Int32)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.UInt32)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Int64)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.UInt64)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.Object)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String, System.Object)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String, System.Object, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "WriteLine", ...)  -- System.Void WriteLine(System.String)
sdk.call_native_func(nil, type_def, "get_ForegroundColor", ...)  -- System.ConsoleColor get_ForegroundColor()
sdk.call_native_func(nil, type_def, "set_ForegroundColor", ...)  -- System.Void set_ForegroundColor(System.ConsoleColor)
```

## `System.Console.ConsoleStream`

**Methods**

```lua
:System.Int32 Read(System.Byte[], System.Int32, System.Int32)
:System.Int64 Seek(System.Int64, System.IO.SeekOrigin)
:System.Void Write(System.Byte[], System.Int32, System.Int32)
:System.Void set_Position(System.Int64)
```

## `System.ConsoleColor`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Black` | `System.ConsoleColor` | yes | 16 |
| `Blue` | `System.ConsoleColor` | yes | 16 |
| `Cyan` | `System.ConsoleColor` | yes | 16 |
| `DarkBlue` | `System.ConsoleColor` | yes | 16 |
| `DarkCyan` | `System.ConsoleColor` | yes | 16 |
| `DarkGray` | `System.ConsoleColor` | yes | 16 |
| `DarkGreen` | `System.ConsoleColor` | yes | 16 |
| `DarkMagenta` | `System.ConsoleColor` | yes | 16 |
| `DarkRed` | `System.ConsoleColor` | yes | 16 |
| `DarkYellow` | `System.ConsoleColor` | yes | 16 |
| `Gray` | `System.ConsoleColor` | yes | 16 |
| `Green` | `System.ConsoleColor` | yes | 16 |
| `Magenta` | `System.ConsoleColor` | yes | 16 |
| `Red` | `System.ConsoleColor` | yes | 16 |
| `White` | `System.ConsoleColor` | yes | 16 |
| `Yellow` | `System.ConsoleColor` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.ConsoleColor[]`

**Methods**

```lua
:System.Void Add(System.ConsoleColor)
:System.ConsoleColor Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.ConsoleColor)
:System.Void CopyTo(System.ConsoleColor[], System.Int32)
:System.ConsoleColor Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.ConsoleColor> GetEnumerator()
:System.Int32 IndexOf(System.ConsoleColor)
:System.Void Insert(System.Int32, System.ConsoleColor)
:System.Boolean Remove(System.ConsoleColor)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.ConsoleColor)
:System.ConsoleColor get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.ConsoleColor)
```

## `System.Convert`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "ChangeType", ...)  -- System.Object ChangeType(System.Object, System.TypeCode)
sdk.call_native_func(nil, type_def, "ChangeType", ...)  -- System.Object ChangeType(System.Object, System.TypeCode, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ChangeType", ...)  -- System.Object ChangeType(System.Object, System.Type)
sdk.call_native_func(nil, type_def, "ChangeType", ...)  -- System.Object ChangeType(System.Object, System.Type, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "FromBase64String", ...)  -- System.Byte[] FromBase64String(System.String)
sdk.call_native_func(nil, type_def, "GetTypeCode", ...)  -- System.TypeCode GetTypeCode(System.Object)
sdk.call_native_func(nil, type_def, "ToBase64String", ...)  -- System.String ToBase64String(System.Byte[])
sdk.call_native_func(nil, type_def, "ToBase64String", ...)  -- System.String ToBase64String(System.Byte[], System.Base64FormattingOptions)
sdk.call_native_func(nil, type_def, "ToBase64String", ...)  -- System.String ToBase64String(System.Byte[], System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "ToBase64String", ...)  -- System.String ToBase64String(System.Byte[], System.Int32, System.Int32, System.Base64FormattingOptions)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Object)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Boolean)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.SByte)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Char)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Byte)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Int16)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.UInt16)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Int32)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.UInt32)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Int64)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.UInt64)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.String)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Single)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Double)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.Decimal)
sdk.call_native_func(nil, type_def, "ToBoolean", ...)  -- System.Boolean ToBoolean(System.DateTime)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Object)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Boolean)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Byte)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Char)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.SByte)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Int16)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.UInt16)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Int32)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.UInt32)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Int64)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.UInt64)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Single)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Double)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Decimal)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.String)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.DateTime)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Object)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Boolean)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Char)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.SByte)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Byte)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Int16)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.UInt16)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Int32)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.UInt32)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Int64)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.UInt64)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.String)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Single)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Double)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.Decimal)
sdk.call_native_func(nil, type_def, "ToChar", ...)  -- System.Char ToChar(System.DateTime)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Object)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.DateTime)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.String)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.SByte)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Byte)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Int16)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.UInt16)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Int32)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.UInt32)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Int64)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.UInt64)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Boolean)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Char)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Single)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Double)
sdk.call_native_func(nil, type_def, "ToDateTime", ...)  -- System.DateTime ToDateTime(System.Decimal)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Object)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.SByte)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Byte)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Char)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Int16)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.UInt16)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Int32)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.UInt32)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Int64)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.UInt64)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Single)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Double)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.String)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Decimal)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Boolean)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.DateTime)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Object)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.SByte)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Byte)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Int16)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Char)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.UInt16)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Int32)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.UInt32)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Int64)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.UInt64)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Single)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Double)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Decimal)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Boolean)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.DateTime)
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.String)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Object)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Boolean)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Char)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.SByte)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Byte)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.UInt16)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Int32)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.UInt32)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Int16)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Int64)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.UInt64)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Single)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Double)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.String)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.DateTime)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Object)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Boolean)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Char)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.SByte)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Byte)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Int16)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.UInt16)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.UInt32)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Int32)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Int64)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.UInt64)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Single)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Double)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.String)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.DateTime)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Object)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Boolean)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Char)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.SByte)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Byte)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Int16)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.UInt16)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Int32)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.UInt32)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.UInt64)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Int64)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Single)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Double)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.String)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.DateTime)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.String, System.Boolean, System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Object)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Boolean)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.SByte)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Char)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Byte)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Int16)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.UInt16)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Int32)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.UInt32)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Int64)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.UInt64)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Single)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Double)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Decimal)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.String)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.DateTime)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Object)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.SByte)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Byte)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Char)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Int16)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.UInt16)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Int32)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.UInt32)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Int64)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.UInt64)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Single)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Double)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Decimal)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.String)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Boolean)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.DateTime)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Object)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Boolean)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Boolean, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Char)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Char, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.SByte)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.SByte, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Byte)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Byte, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int16)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int16, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt16)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt16, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int32)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int32, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt32)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt32, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int64)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Int64, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt64)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.UInt64, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Single)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Single, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Double)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Double, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Decimal)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.Decimal, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.DateTime)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.DateTime, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.String)
sdk.call_native_func(nil, type_def, "ToString", ...)  -- System.String ToString(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToType", ...)  -- System.Object ToType(System.Object, System.Type, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Object)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Boolean)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Char)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.SByte)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Byte)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Int16)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.UInt16)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.UInt32)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Int64)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.UInt64)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Single)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Double)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.String)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.DateTime)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Object)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Boolean)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Char)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.SByte)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Byte)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Int16)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.UInt16)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.UInt32)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Int64)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.UInt64)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Single)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Double)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.String)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.DateTime)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Object)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Object, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Boolean)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Char)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.SByte)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Byte)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Int16)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.UInt16)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Int32)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.UInt32)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Int64)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.UInt64)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Single)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Double)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.String)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.DateTime)
sdk.call_native_func(nil, type_def, "TryNumberToDouble", ...)  -- System.Boolean TryNumberToDouble(System.String, System.Double)
sdk.call_native_func(nil, type_def, "TryNumberToInt64", ...)  -- System.Boolean TryNumberToInt64(System.String, System.Boolean, System.Int64, System.Int64, System.Int64)
```

## `System.Currency`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `m_value` | `System.Int64` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Decimal)
:System.Void .ctor(System.Int64, System.Int32)
:System.Int64 ToOACurrency()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "FCallToDecimal", ...)  -- System.Void FCallToDecimal(System.Decimal, System.Currency)
sdk.call_native_func(nil, type_def, "FromOACurrency", ...)  -- System.Currency FromOACurrency(System.Int64)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Currency)
```

## `System.DBNull`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `System.DBNull` | yes | 16 |

**Methods**

```lua
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.DateTime`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MinValue` | `System.DateTime` | yes | 16 |
| `MaxValue` | `System.DateTime` | yes | 24 |
| `MonthShortNameTbl` | `System.String[]` | yes | 32 |
| `MonthLongNameTbl` | `System.String[]` | yes | 40 |
| `DayOfWeekShortNameTbl` | `System.String[]` | yes | 48 |
| `DayOfWeekLongNameTbl` | `System.String[]` | yes | 56 |
| `mDate` | `System.UInt64` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Int64)
:System.Void .ctor(System.Int64, System.DateTimeKind)
:System.Void .ctor(System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.DateTimeKind)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.DateTimeKind)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.DateTimeKind)
:System.DateTime Add(System.TimeSpan)
:System.DateTime AddDays(System.Double)
:System.DateTime AddHours(System.Double)
:System.DateTime AddMilliseconds(System.Double)
:System.DateTime AddMinutes(System.Double)
:System.DateTime AddSeconds(System.Double)
:System.DateTime AddTicks(System.Int64)
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.DateTime)
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.DateTime)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.TimeSpan Subtract(System.DateTime)
:System.DateTime Subtract(System.TimeSpan)
:System.TimeSpan SubtractDateTime(System.DateTime)
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.DateTime ToLocalTime()
:System.String ToLongDateString()
:System.String ToLongTimeString()
:System.String ToShortDateString()
:System.String ToShortTimeString()
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.IFormatProvider)
:System.String ToString(System.String, System.IFormatProvider)
:System.DateTime ToUniversalTime()
:System.DateTime get_Date()
:System.Int32 get_Day()
:System.DayOfWeek get_DayOfWeek()
:System.Int32 get_DayOfYear()
:System.Int32 get_Hour()
:System.DateTimeKind get_Kind()
:System.Int32 get_Millisecond()
:System.Int32 get_Minute()
:System.Int32 get_Month()
:System.Int32 get_Second()
:System.Int64 get_Ticks()
:System.TimeSpan get_TimeOfDay()
:System.Int32 get_Year()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "DaysInMonth", ...)  -- System.Int32 DaysInMonth(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.DateTime Parse(System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.DateTime Parse(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.DateTime Parse(System.String, System.IFormatProvider, System.Globalization.DateTimeStyles)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.DateTime ParseExact(System.String, System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.DateTime ParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.DateTimeStyles)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.DateTime ParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.DateTimeStyles)
sdk.call_native_func(nil, type_def, "SpecifyKind", ...)  -- System.DateTime SpecifyKind(System.DateTime, System.DateTimeKind)
sdk.call_native_func(nil, type_def, "SplitToken", ...)  -- System.Int32 SplitToken(System.String, System.String[])
sdk.call_native_func(nil, type_def, "ToCustomString", ...)  -- System.String ToCustomString(System.DateTime, System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.DateTime)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
sdk.call_native_func(nil, type_def, "TryParseInternal", ...)  -- System.Boolean TryParseInternal(System.String, System.String, System.DateTime, System.Globalization.DateTimeStyles)
sdk.call_native_func(nil, type_def, "get_Now", ...)  -- System.DateTime get_Now()
sdk.call_native_func(nil, type_def, "get_Today", ...)  -- System.DateTime get_Today()
sdk.call_native_func(nil, type_def, "get_UtcNow", ...)  -- System.DateTime get_UtcNow()
sdk.call_native_func(nil, type_def, "op_Addition", ...)  -- System.DateTime op_Addition(System.DateTime, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_GreaterThan", ...)  -- System.Boolean op_GreaterThan(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_GreaterThanOrEqual", ...)  -- System.Boolean op_GreaterThanOrEqual(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_LessThan", ...)  -- System.Boolean op_LessThan(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_LessThanOrEqual", ...)  -- System.Boolean op_LessThanOrEqual(System.DateTime, System.DateTime)
sdk.call_native_func(nil, type_def, "op_Subtraction", ...)  -- System.DateTime op_Subtraction(System.DateTime, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Subtraction", ...)  -- System.TimeSpan op_Subtraction(System.DateTime, System.DateTime)
```

## `System.DateTimeKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Local` | `System.DateTimeKind` | yes | 16 |
| `Unspecified` | `System.DateTimeKind` | yes | 16 |
| `Utc` | `System.DateTimeKind` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.DateTimeKind[]`

**Methods**

```lua
:System.Void Add(System.DateTimeKind)
:System.DateTimeKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.DateTimeKind)
:System.Void CopyTo(System.DateTimeKind[], System.Int32)
:System.DateTimeKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.DateTimeKind> GetEnumerator()
:System.Int32 IndexOf(System.DateTimeKind)
:System.Void Insert(System.Int32, System.DateTimeKind)
:System.Boolean Remove(System.DateTimeKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.DateTimeKind)
:System.DateTimeKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.DateTimeKind)
```

## `System.DayOfWeek`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Friday` | `System.DayOfWeek` | yes | 16 |
| `Monday` | `System.DayOfWeek` | yes | 16 |
| `Saturday` | `System.DayOfWeek` | yes | 16 |
| `Sunday` | `System.DayOfWeek` | yes | 16 |
| `Thursday` | `System.DayOfWeek` | yes | 16 |
| `Tuesday` | `System.DayOfWeek` | yes | 16 |
| `Wednesday` | `System.DayOfWeek` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.DayOfWeek[]`

**Methods**

```lua
:System.Void Add(System.DayOfWeek)
:System.DayOfWeek Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.DayOfWeek)
:System.Void CopyTo(System.DayOfWeek[], System.Int32)
:System.DayOfWeek Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.DayOfWeek> GetEnumerator()
:System.Int32 IndexOf(System.DayOfWeek)
:System.Void Insert(System.Int32, System.DayOfWeek)
:System.Boolean Remove(System.DayOfWeek)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.DayOfWeek)
:System.DayOfWeek get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.DayOfWeek)
```

## `System.Decimal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DECIMAL_ADD` | `System.Byte` | yes | 16 |
| `DECIMAL_NEG` | `System.Byte` | yes | 16 |
| `MaxInt32Scale` | `System.Int32` | yes | 16 |
| `Powers10` | `System.UInt32[]` | yes | 16 |
| `ScaleMask` | `System.Int32` | yes | 16 |
| `ScaleShift` | `System.Int32` | yes | 16 |
| `SignMask` | `System.Int32` | yes | 16 |
| `Zero` | `System.Decimal` | yes | 24 |
| `One` | `System.Decimal` | yes | 40 |
| `MinusOne` | `System.Decimal` | yes | 56 |
| `MaxValue` | `System.Decimal` | yes | 72 |
| `MinValue` | `System.Decimal` | yes | 88 |
| `NearNegativeZero` | `System.Decimal` | yes | 104 |
| `NearPositiveZero` | `System.Decimal` | yes | 120 |
| `flags` | `System.Int32` |  | 16 |
| `hi` | `System.Int32` |  | 20 |
| `lo` | `System.Int32` |  | 24 |
| `mid` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.UInt32)
:System.Void .ctor(System.Int64)
:System.Void .ctor(System.UInt64)
:System.Void .ctor(System.Single)
:System.Void .ctor(System.Double)
:System.Void .ctor(System.Currency)
:System.Void .ctor(System.Int32[])
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Boolean, System.Byte)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Decimal)
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.Decimal)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Void SetBits(System.Int32[])
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.IFormatProvider)
:System.String ToString(System.String, System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Decimal Abs(System.Decimal)
sdk.call_native_func(nil, type_def, "Add", ...)  -- System.Decimal Add(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Ceiling", ...)  -- System.Decimal Ceiling(System.Decimal)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Divide", ...)  -- System.Decimal Divide(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "FCallAddSub", ...)  -- System.Void FCallAddSub(System.Decimal, System.Decimal, System.Byte)
sdk.call_native_func(nil, type_def, "FCallCompare", ...)  -- System.Int32 FCallCompare(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "FCallDivide", ...)  -- System.Void FCallDivide(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "FCallFloor", ...)  -- System.Void FCallFloor(System.Decimal)
sdk.call_native_func(nil, type_def, "FCallMultiply", ...)  -- System.Void FCallMultiply(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "FCallRound", ...)  -- System.Void FCallRound(System.Decimal, System.Int32)
sdk.call_native_func(nil, type_def, "FCallToCurrency", ...)  -- System.Void FCallToCurrency(System.Currency, System.Decimal)
sdk.call_native_func(nil, type_def, "FCallToInt32", ...)  -- System.Int32 FCallToInt32(System.Decimal)
sdk.call_native_func(nil, type_def, "FCallTruncate", ...)  -- System.Void FCallTruncate(System.Decimal)
sdk.call_native_func(nil, type_def, "Floor", ...)  -- System.Decimal Floor(System.Decimal)
sdk.call_native_func(nil, type_def, "FromOACurrency", ...)  -- System.Decimal FromOACurrency(System.Int64)
sdk.call_native_func(nil, type_def, "GetBits", ...)  -- System.Int32[] GetBits(System.Decimal)
sdk.call_native_func(nil, type_def, "GetBytes", ...)  -- System.Void GetBytes(System.Decimal, System.Byte[])
sdk.call_native_func(nil, type_def, "InternalAddUInt32RawUnchecked", ...)  -- System.Void InternalAddUInt32RawUnchecked(System.Decimal, System.UInt32)
sdk.call_native_func(nil, type_def, "InternalDivRemUInt32", ...)  -- System.UInt32 InternalDivRemUInt32(System.Decimal, System.UInt32)
sdk.call_native_func(nil, type_def, "InternalRoundFromZero", ...)  -- System.Void InternalRoundFromZero(System.Decimal, System.Int32)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Decimal Max(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Decimal Min(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Multiply", ...)  -- System.Decimal Multiply(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Negate", ...)  -- System.Decimal Negate(System.Decimal)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Decimal Parse(System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Decimal Parse(System.String, System.NumberStyles)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Decimal Parse(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Decimal Parse(System.String, System.NumberStyles, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "Remainder", ...)  -- System.Decimal Remainder(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "Round", ...)  -- System.Decimal Round(System.Decimal)
sdk.call_native_func(nil, type_def, "Round", ...)  -- System.Decimal Round(System.Decimal, System.Int32)
sdk.call_native_func(nil, type_def, "Round", ...)  -- System.Decimal Round(System.Decimal, System.MidpointRounding)
sdk.call_native_func(nil, type_def, "Round", ...)  -- System.Decimal Round(System.Decimal, System.Int32, System.MidpointRounding)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Decimal)
sdk.call_native_func(nil, type_def, "Subtract", ...)  -- System.Decimal Subtract(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "ToByte", ...)  -- System.Byte ToByte(System.Decimal)
sdk.call_native_func(nil, type_def, "ToCurrency", ...)  -- System.Currency ToCurrency(System.Decimal)
sdk.call_native_func(nil, type_def, "ToDecimal", ...)  -- System.Decimal ToDecimal(System.Byte[])
sdk.call_native_func(nil, type_def, "ToDouble", ...)  -- System.Double ToDouble(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt16", ...)  -- System.Int16 ToInt16(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt32", ...)  -- System.Int32 ToInt32(System.Decimal)
sdk.call_native_func(nil, type_def, "ToInt64", ...)  -- System.Int64 ToInt64(System.Decimal)
sdk.call_native_func(nil, type_def, "ToOACurrency", ...)  -- System.Int64 ToOACurrency(System.Decimal)
sdk.call_native_func(nil, type_def, "ToSByte", ...)  -- System.SByte ToSByte(System.Decimal)
sdk.call_native_func(nil, type_def, "ToSingle", ...)  -- System.Single ToSingle(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt16", ...)  -- System.UInt16 ToUInt16(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt32", ...)  -- System.UInt32 ToUInt32(System.Decimal)
sdk.call_native_func(nil, type_def, "ToUInt64", ...)  -- System.UInt64 ToUInt64(System.Decimal)
sdk.call_native_func(nil, type_def, "Truncate", ...)  -- System.Decimal Truncate(System.Decimal)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Decimal)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.NumberStyles, System.IFormatProvider, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Addition", ...)  -- System.Decimal op_Addition(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Decrement", ...)  -- System.Decimal op_Decrement(System.Decimal)
sdk.call_native_func(nil, type_def, "op_Division", ...)  -- System.Decimal op_Division(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Explicit", ...)  -- System.Decimal op_Explicit(System.Single)
sdk.call_native_func(nil, type_def, "op_Explicit", ...)  -- System.Decimal op_Explicit(System.Double)
sdk.call_native_func(nil, type_def, "op_Explicit", ...)  -- System.Byte op_Explicit(System.Decimal)
sdk.call_native_func(nil, type_def, "op_GreaterThan", ...)  -- System.Boolean op_GreaterThan(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_GreaterThanOrEqual", ...)  -- System.Boolean op_GreaterThanOrEqual(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.Byte)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.SByte)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.Int16)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.UInt16)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.Char)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.Int32)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.UInt32)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.Int64)
sdk.call_native_func(nil, type_def, "op_Implicit", ...)  -- System.Decimal op_Implicit(System.UInt64)
sdk.call_native_func(nil, type_def, "op_Increment", ...)  -- System.Decimal op_Increment(System.Decimal)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_LessThan", ...)  -- System.Boolean op_LessThan(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_LessThanOrEqual", ...)  -- System.Boolean op_LessThanOrEqual(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Modulus", ...)  -- System.Decimal op_Modulus(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Multiply", ...)  -- System.Decimal op_Multiply(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_Subtraction", ...)  -- System.Decimal op_Subtraction(System.Decimal, System.Decimal)
sdk.call_native_func(nil, type_def, "op_UnaryNegation", ...)  -- System.Decimal op_UnaryNegation(System.Decimal)
sdk.call_native_func(nil, type_def, "op_UnaryPlus", ...)  -- System.Decimal op_UnaryPlus(System.Decimal)
```

## `System.Delegate`

**Methods**

```lua
:System.Object DynamicInvoke(System.Object[])
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Delegate[] GetInvocationList()
:System.Reflection.MethodInfo get_Method()
:System.Object get_Target()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Combine", ...)  -- System.Delegate Combine(System.Delegate, System.Delegate)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Object, System.String)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Object, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Object, System.String, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Type, System.String)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Type, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Type, System.String, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Reflection.MethodInfo, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Object, System.Reflection.MethodInfo)
sdk.call_native_func(nil, type_def, "CreateDelegate", ...)  -- System.Delegate CreateDelegate(System.Type, System.Object, System.Reflection.MethodInfo, System.Boolean)
sdk.call_native_func(nil, type_def, "CreateDelegateInternal", ...)  -- System.Delegate CreateDelegateInternal(System.Type, System.Object, System.Reflection.MethodInfo, System.Boolean)
sdk.call_native_func(nil, type_def, "Remove", ...)  -- System.Delegate Remove(System.Delegate, System.Delegate)
sdk.call_native_func(nil, type_def, "RemoveAll", ...)  -- System.Delegate RemoveAll(System.Delegate, System.Delegate)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Delegate, System.Delegate)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Delegate, System.Delegate)
```

## `System.Delegate[]`

**Methods**

```lua
:System.Void Add(System.Delegate)
:System.Delegate Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Delegate)
:System.Void CopyTo(System.Delegate[], System.Int32)
:System.Delegate Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Delegate> GetEnumerator()
:System.Int32 IndexOf(System.Delegate)
:System.Void Insert(System.Int32, System.Delegate)
:System.Boolean Remove(System.Delegate)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Delegate)
:System.Delegate get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Delegate)
```

## `System.Diagnostics.ConditionalAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mCondition` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_ConditionString()
```

## `System.Diagnostics.Debug`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Assert", ...)  -- System.Void Assert(System.Boolean)
sdk.call_native_func(nil, type_def, "Assert", ...)  -- System.Void Assert(System.Boolean, System.String)
sdk.call_native_func(nil, type_def, "Assert", ...)  -- System.Void Assert(System.Boolean, System.String, System.String)
sdk.call_native_func(nil, type_def, "Assert", ...)  -- System.Void Assert(System.Boolean, System.String, System.String, System.Object[])
```

## `System.Diagnostics.DebuggableAttribute`

_No fields or methods._

## `System.Diagnostics.DebuggableAttribute.DebuggingModes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Default` | `System.Diagnostics.DebuggableAttribute.DebuggingModes` | yes | 16 |
| `DisableOptimizations` | `System.Diagnostics.DebuggableAttribute.DebuggingModes` | yes | 16 |
| `EnableEditAndContinue` | `System.Diagnostics.DebuggableAttribute.DebuggingModes` | yes | 16 |
| `IgnoreSymbolStoreSequencePoints` | `System.Diagnostics.DebuggableAttribute.DebuggingModes` | yes | 16 |
| `None` | `System.Diagnostics.DebuggableAttribute.DebuggingModes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Diagnostics.DebuggableAttribute.DebuggingModes[]`

**Methods**

```lua
:System.Void Add(System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Diagnostics.DebuggableAttribute.DebuggingModes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Void CopyTo(System.Diagnostics.DebuggableAttribute.DebuggingModes[], System.Int32)
:System.Diagnostics.DebuggableAttribute.DebuggingModes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Diagnostics.DebuggableAttribute.DebuggingModes> GetEnumerator()
:System.Int32 IndexOf(System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Void Insert(System.Int32, System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Boolean Remove(System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Diagnostics.DebuggableAttribute.DebuggingModes)
:System.Diagnostics.DebuggableAttribute.DebuggingModes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Diagnostics.DebuggableAttribute.DebuggingModes)
```

## `System.Diagnostics.Debugger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultCategory` | `System.String` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Break", ...)  -- System.Void Break()
sdk.call_native_func(nil, type_def, "BreakCanThrow", ...)  -- System.Void BreakCanThrow()
sdk.call_native_func(nil, type_def, "BreakInternal", ...)  -- System.Void BreakInternal()
sdk.call_native_func(nil, type_def, "IsLogging", ...)  -- System.Boolean IsLogging()
sdk.call_native_func(nil, type_def, "Launch", ...)  -- System.Boolean Launch()
sdk.call_native_func(nil, type_def, "LaunchInternal", ...)  -- System.Boolean LaunchInternal()
sdk.call_native_func(nil, type_def, "Log", ...)  -- System.Void Log(System.Int32, System.String, System.String)
sdk.call_native_func(nil, type_def, "NotifyOfCrossThreadDependency", ...)  -- System.Void NotifyOfCrossThreadDependency()
sdk.call_native_func(nil, type_def, "get_IsAttached", ...)  -- System.Boolean get_IsAttached()
```

## `System.Diagnostics.DebuggerBrowsableAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mState` | `System.Diagnostics.DebuggerBrowsableState` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Diagnostics.DebuggerBrowsableState)
:System.Diagnostics.DebuggerBrowsableState get_State()
```

## `System.Diagnostics.DebuggerBrowsableState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Collapsed` | `System.Diagnostics.DebuggerBrowsableState` | yes | 16 |
| `Never` | `System.Diagnostics.DebuggerBrowsableState` | yes | 16 |
| `RootHidden` | `System.Diagnostics.DebuggerBrowsableState` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Diagnostics.DebuggerBrowsableState[]`

**Methods**

```lua
:System.Void Add(System.Diagnostics.DebuggerBrowsableState)
:System.Diagnostics.DebuggerBrowsableState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Diagnostics.DebuggerBrowsableState)
:System.Void CopyTo(System.Diagnostics.DebuggerBrowsableState[], System.Int32)
:System.Diagnostics.DebuggerBrowsableState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Diagnostics.DebuggerBrowsableState> GetEnumerator()
:System.Int32 IndexOf(System.Diagnostics.DebuggerBrowsableState)
:System.Void Insert(System.Int32, System.Diagnostics.DebuggerBrowsableState)
:System.Boolean Remove(System.Diagnostics.DebuggerBrowsableState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Diagnostics.DebuggerBrowsableState)
:System.Diagnostics.DebuggerBrowsableState get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Diagnostics.DebuggerBrowsableState)
```

## `System.Diagnostics.DebuggerDisplayAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mName` | `System.String` |  | 16 |
| `mValue` | `System.String` |  | 24 |
| `mType` | `System.String` |  | 32 |
| `mTargetName` | `System.String` |  | 40 |
| `mTarget` | `System.Type` |  | 48 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Name()
:System.Type get_Target()
:System.String get_TargetTypeName()
:System.String get_Type()
:System.String get_Value()
:System.Void set_Name(System.String)
:System.Void set_Target(System.Type)
:System.Void set_TargetTypeName(System.String)
:System.Void set_Type(System.String)
```

## `System.Diagnostics.DebuggerHiddenAttribute`

_No fields or methods._

## `System.Diagnostics.Stopwatch`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Frequency` | `System.Int64` | yes | 16 |
| `mElapsed` | `System.Int64` |  | 16 |
| `mStartTimeStamp` | `System.Int64` |  | 24 |
| `mIsRunning` | `System.Boolean` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void Reset()
:System.Void Restart()
:System.Void Start()
:System.Void Stop()
:System.Int64 getElapsedDateTimeTicks()
:System.Int64 getTicks()
:System.TimeSpan get_Elapsed()
:System.Int64 get_ElapsedMilliseconds()
:System.Int64 get_ElapsedTicks()
:System.Boolean get_IsRunning()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetTimestamp", ...)  -- System.Int64 GetTimestamp()
sdk.call_native_func(nil, type_def, "StartNew", ...)  -- System.Diagnostics.Stopwatch StartNew()
sdk.call_native_func(nil, type_def, "queryPerformanceCounter", ...)  -- System.Int64 queryPerformanceCounter()
sdk.call_native_func(nil, type_def, "queryPerformanceFrequency", ...)  -- System.Int64 queryPerformanceFrequency()
```

## `System.DivideByZeroException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Double`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Epsilon` | `System.Double` | yes | 16 |
| `MaxValue` | `System.Double` | yes | 16 |
| `MinValue` | `System.Double` | yes | 16 |
| `NaN` | `System.Double` | yes | 16 |
| `NegativeInfinity` | `System.Double` | yes | 16 |
| `PositiveInfinity` | `System.Double` | yes | 16 |
| `mValue` | `System.Double` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Double)
:System.Boolean Equals(System.Double)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "IsInfinity", ...)  -- System.Boolean IsInfinity(System.Double)
sdk.call_native_func(nil, type_def, "IsNaN", ...)  -- System.Boolean IsNaN(System.Double)
sdk.call_native_func(nil, type_def, "IsNegativeInfinity", ...)  -- System.Boolean IsNegativeInfinity(System.Double)
sdk.call_native_func(nil, type_def, "IsPositiveInfinity", ...)  -- System.Boolean IsPositiveInfinity(System.Double)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Double Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Double)
```

## `System.Double[]`

**Methods**

```lua
:System.Void Add(System.Double)
:System.Double Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Double)
:System.Void CopyTo(System.Double[], System.Int32)
:System.Double Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Double> GetEnumerator()
:System.Int32 IndexOf(System.Double)
:System.Void Insert(System.Int32, System.Double)
:System.Boolean Remove(System.Double)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Double)
:System.Double get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Double)
```

## `System.Enum`

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean HasFlag(System.Enum)
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.String System.IConvertible.ToString(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.Object getValue()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetName", ...)  -- System.String GetName(System.Type, System.Object)
sdk.call_native_func(nil, type_def, "GetNames", ...)  -- System.String[] GetNames(System.Type)
sdk.call_native_func(nil, type_def, "GetUnderlyingType", ...)  -- System.Type GetUnderlyingType(System.Type)
sdk.call_native_func(nil, type_def, "GetValues", ...)  -- System.Array GetValues(System.Type)
sdk.call_native_func(nil, type_def, "IsDefined", ...)  -- System.Boolean IsDefined(System.Type, System.Object)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Object Parse(System.Type, System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Object Parse(System.Type, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.Object)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.SByte)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.Int16)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.Int32)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.Byte)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.UInt16)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.UInt32)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.Int64)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.Type, System.UInt64)
sdk.call_native_func(nil, type_def, "TryParseInternal", ...)  -- System.Boolean TryParseInternal(System.Type, System.String, System.Boolean, System.Object)
sdk.call_native_func(nil, type_def, "boxEnum", ...)  -- System.Object boxEnum(System.Type, System.Int64)
```

## `System.Environment`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Exit", ...)  -- System.Void Exit(System.Int32)
sdk.call_native_func(nil, type_def, "GetCommandLineArgs", ...)  -- System.String[] GetCommandLineArgs()
sdk.call_native_func(nil, type_def, "GetEnvironmentVariable", ...)  -- System.String GetEnvironmentVariable(System.String)
sdk.call_native_func(nil, type_def, "get_CommandLine", ...)  -- System.String get_CommandLine()
sdk.call_native_func(nil, type_def, "get_CurrentDirectory", ...)  -- System.String get_CurrentDirectory()
sdk.call_native_func(nil, type_def, "get_CurrentManagedThreadId", ...)  -- System.Int32 get_CurrentManagedThreadId()
sdk.call_native_func(nil, type_def, "get_ExitCode", ...)  -- System.Int32 get_ExitCode()
sdk.call_native_func(nil, type_def, "get_HasShutdownStarted", ...)  -- System.Boolean get_HasShutdownStarted()
sdk.call_native_func(nil, type_def, "get_MachineName", ...)  -- System.String get_MachineName()
sdk.call_native_func(nil, type_def, "get_NewLine", ...)  -- System.String get_NewLine()
sdk.call_native_func(nil, type_def, "get_ProcessorCount", ...)  -- System.Int32 get_ProcessorCount()
sdk.call_native_func(nil, type_def, "get_StackTrace", ...)  -- System.String get_StackTrace()
sdk.call_native_func(nil, type_def, "get_SystemDirectory", ...)  -- System.String get_SystemDirectory()
sdk.call_native_func(nil, type_def, "get_SystemPageSize", ...)  -- System.Int32 get_SystemPageSize()
sdk.call_native_func(nil, type_def, "get_TickCount", ...)  -- System.Int32 get_TickCount()
sdk.call_native_func(nil, type_def, "get_UserDomainName", ...)  -- System.String get_UserDomainName()
sdk.call_native_func(nil, type_def, "get_UserInteractive", ...)  -- System.Boolean get_UserInteractive()
sdk.call_native_func(nil, type_def, "get_UserName", ...)  -- System.String get_UserName()
sdk.call_native_func(nil, type_def, "get_WorkingSet", ...)  -- System.Int64 get_WorkingSet()
sdk.call_native_func(nil, type_def, "set_CurrentDirectory", ...)  -- System.Void set_CurrentDirectory(System.String)
sdk.call_native_func(nil, type_def, "set_ExitCode", ...)  -- System.Void set_ExitCode(System.Int32)
```

## `System.EventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Empty` | `System.EventArgs` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Exception`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mCodeOffset` | `System.Int32` |  | 16 |
| `mThreadId` | `System.UInt32` |  | 20 |
| `mMessage` | `System.String` |  | 24 |
| `mInnerException` | `System.Exception` |  | 32 |
| `mFrameDump` | `System.Byte[]` |  | 40 |
| `mFramePtr` | `System.IntPtr` |  | 48 |
| `mReserved` | `System.IntPtr` |  | 56 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
:System.String GetStackTrace()
:System.Type GetType()
:System.String ToString()
:System.Exception get_InnerException()
:System.String get_Message()
:System.String get_StackTrace()
```

## `System.FieldAccessException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.FlagsAttribute`

_No fields or methods._

## `System.FormatException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.GC`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "AddMemoryPressure", ...)  -- System.Void AddMemoryPressure(System.Int64)
sdk.call_native_func(nil, type_def, "Collect", ...)  -- System.Void Collect()
sdk.call_native_func(nil, type_def, "Collect", ...)  -- System.Void Collect(System.Int32)
sdk.call_native_func(nil, type_def, "CollectionCount", ...)  -- System.Int32 CollectionCount(System.Int32)
sdk.call_native_func(nil, type_def, "GetGeneration", ...)  -- System.Int32 GetGeneration(System.Object)
sdk.call_native_func(nil, type_def, "GetTotalMemory", ...)  -- System.Int64 GetTotalMemory(System.Boolean)
sdk.call_native_func(nil, type_def, "KeepAlive", ...)  -- System.Void KeepAlive(System.Object)
sdk.call_native_func(nil, type_def, "ReRegisterForFinalize", ...)  -- System.Void ReRegisterForFinalize(System.Object)
sdk.call_native_func(nil, type_def, "RemoveMemoryPressure", ...)  -- System.Void RemoveMemoryPressure(System.Int64)
sdk.call_native_func(nil, type_def, "SuppressFinalize", ...)  -- System.Void SuppressFinalize(System.Object)
sdk.call_native_func(nil, type_def, "WaitForPendingFinalizers", ...)  -- System.Void WaitForPendingFinalizers()
sdk.call_native_func(nil, type_def, "get_MaxGeneration", ...)  -- System.Int32 get_MaxGeneration()
```

## `System.Globalization.CharUnicodeInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BIDI_CATEGORY_OFFSET` | `System.Int32` | yes | 16 |
| `HIGH_SURROGATE_END` | `System.Char` | yes | 16 |
| `HIGH_SURROGATE_START` | `System.Char` | yes | 16 |
| `LOW_SURROGATE_END` | `System.Char` | yes | 16 |
| `LOW_SURROGATE_START` | `System.Char` | yes | 16 |
| `UNICODE_CATEGORY_OFFSET` | `System.Int32` | yes | 16 |
| `UNICODE_PLANE01_START` | `System.Int32` | yes | 16 |
| `s_pCategoryLevel1Index` | `System.UInt16[]` | yes | 16 |
| `s_pCategoriesValue` | `System.Byte[]` | yes | 24 |
| `s_pNumericLevel1Index` | `System.UInt16[]` | yes | 32 |
| `s_pNumericValues` | `System.Byte[]` | yes | 40 |
| `s_pDigitValues` | `System.UInt16[]` | yes | 48 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetDecimalDigitValue", ...)  -- System.Int32 GetDecimalDigitValue(System.Char)
sdk.call_native_func(nil, type_def, "GetDecimalDigitValue", ...)  -- System.Int32 GetDecimalDigitValue(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "GetDigitValue", ...)  -- System.Int32 GetDigitValue(System.Char)
sdk.call_native_func(nil, type_def, "GetDigitValue", ...)  -- System.Int32 GetDigitValue(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "GetNumericValue", ...)  -- System.Double GetNumericValue(System.Char)
sdk.call_native_func(nil, type_def, "GetNumericValue", ...)  -- System.Double GetNumericValue(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "GetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory GetUnicodeCategory(System.Char)
sdk.call_native_func(nil, type_def, "GetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory GetUnicodeCategory(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "InternalConvertToUtf32", ...)  -- System.Int32 InternalConvertToUtf32(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "InternalConvertToUtf32", ...)  -- System.Int32 InternalConvertToUtf32(System.String, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetCategoryValue", ...)  -- System.Byte InternalGetCategoryValue(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetDigitValues", ...)  -- System.UInt16 InternalGetDigitValues(System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetNumericValue", ...)  -- System.Double InternalGetNumericValue(System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "InternalGetUnicodeCategory", ...)  -- System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.String, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "IsCombiningCategory", ...)  -- System.Boolean IsCombiningCategory(System.Globalization.UnicodeCategory)
sdk.call_native_func(nil, type_def, "IsWhiteSpace", ...)  -- System.Boolean IsWhiteSpace(System.String, System.Int32)
sdk.call_native_func(nil, type_def, "IsWhiteSpace", ...)  -- System.Boolean IsWhiteSpace(System.Char)
```

## `System.Globalization.CultureInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_invariantCulture` | `System.Globalization.CultureInfo` | yes | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Boolean)
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Int32, System.Boolean)
:System.Object Clone()
:System.Globalization.CultureInfo GetConsoleFallbackUICulture()
:System.Object GetFormat(System.Type)
:System.String ToString()
:System.Globalization.CultureTypes get_CultureTypes()
:System.Globalization.DateTimeFormatInfo get_DateTimeFormat()
:System.String get_DisplayName()
:System.String get_EnglishName()
:System.String get_IetfLanguageTag()
:System.Int32 get_KeyboardLayoutId()
:System.Int32 get_LCID()
:System.String get_Name()
:System.String get_NativeName()
:System.Globalization.NumberFormatInfo get_NumberFormat()
:System.Globalization.CultureInfo get_Parent()
:System.String get_ThreeLetterISOLanguageName()
:System.String get_ThreeLetterWindowsLanguageName()
:System.String get_TwoLetterISOLanguageName()
:System.Void set_DateTimeFormat(System.Globalization.DateTimeFormatInfo)
:System.Void set_NumberFormat(System.Globalization.NumberFormatInfo)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "CreateSpecificCulture", ...)  -- System.Globalization.CultureInfo CreateSpecificCulture(System.String)
sdk.call_native_func(nil, type_def, "GetCultureInfo", ...)  -- System.Globalization.CultureInfo GetCultureInfo(System.Int32)
sdk.call_native_func(nil, type_def, "GetCultureInfo", ...)  -- System.Globalization.CultureInfo GetCultureInfo(System.String)
sdk.call_native_func(nil, type_def, "GetCultureInfo", ...)  -- System.Globalization.CultureInfo GetCultureInfo(System.String, System.String)
sdk.call_native_func(nil, type_def, "GetCultureInfoByIetfLanguageTag", ...)  -- System.Globalization.CultureInfo GetCultureInfoByIetfLanguageTag(System.String)
sdk.call_native_func(nil, type_def, "GetCultures", ...)  -- System.Globalization.CultureInfo[] GetCultures(System.Globalization.CultureTypes)
sdk.call_native_func(nil, type_def, "ReadOnly", ...)  -- System.Globalization.CultureInfo ReadOnly(System.Globalization.CultureInfo)
sdk.call_native_func(nil, type_def, "get_DefaultThreadCurrentCulture", ...)  -- System.Globalization.CultureInfo get_DefaultThreadCurrentCulture()
sdk.call_native_func(nil, type_def, "get_DefaultThreadCurrentUICulture", ...)  -- System.Globalization.CultureInfo get_DefaultThreadCurrentUICulture()
sdk.call_native_func(nil, type_def, "get_InstalledUICulture", ...)  -- System.Globalization.CultureInfo get_InstalledUICulture()
sdk.call_native_func(nil, type_def, "get_InvariantCulture", ...)  -- System.Globalization.CultureInfo get_InvariantCulture()
sdk.call_native_func(nil, type_def, "set_DefaultThreadCurrentCulture", ...)  -- System.Void set_DefaultThreadCurrentCulture(System.Globalization.CultureInfo)
sdk.call_native_func(nil, type_def, "set_DefaultThreadCurrentUICulture", ...)  -- System.Void set_DefaultThreadCurrentUICulture(System.Globalization.CultureInfo)
```

## `System.Globalization.CultureInfo[]`

**Methods**

```lua
:System.Void Add(System.Globalization.CultureInfo)
:System.Globalization.CultureInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Globalization.CultureInfo)
:System.Void CopyTo(System.Globalization.CultureInfo[], System.Int32)
:System.Globalization.CultureInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Globalization.CultureInfo> GetEnumerator()
:System.Int32 IndexOf(System.Globalization.CultureInfo)
:System.Void Insert(System.Int32, System.Globalization.CultureInfo)
:System.Boolean Remove(System.Globalization.CultureInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Globalization.CultureInfo)
:System.Globalization.CultureInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Globalization.CultureInfo)
```

## `System.Globalization.CultureNotFoundException`

_No fields or methods._

## `System.Globalization.CultureTypes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AllCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `FrameworkCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `InstalledWin32Cultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `NeutralCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `ReplacementCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `SpecificCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `UserCustomCulture` | `System.Globalization.CultureTypes` | yes | 16 |
| `WindowsOnlyCultures` | `System.Globalization.CultureTypes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Globalization.CultureTypes[]`

**Methods**

```lua
:System.Void Add(System.Globalization.CultureTypes)
:System.Globalization.CultureTypes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Globalization.CultureTypes)
:System.Void CopyTo(System.Globalization.CultureTypes[], System.Int32)
:System.Globalization.CultureTypes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Globalization.CultureTypes> GetEnumerator()
:System.Int32 IndexOf(System.Globalization.CultureTypes)
:System.Void Insert(System.Int32, System.Globalization.CultureTypes)
:System.Boolean Remove(System.Globalization.CultureTypes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Globalization.CultureTypes)
:System.Globalization.CultureTypes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Globalization.CultureTypes)
```

## `System.Globalization.DateTimeFormatInfo`

_No fields or methods._

## `System.Globalization.DateTimeStyles`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AdjustToUniversal` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AllowInnerWhite` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AllowLeadingWhite` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AllowTrailingWhite` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AllowWhiteSpaces` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AssumeLocal` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `AssumeUniversal` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `NoCurrentDateDefault` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `None` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `RoundtripKind` | `System.Globalization.DateTimeStyles` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Globalization.DateTimeStyles[]`

**Methods**

```lua
:System.Void Add(System.Globalization.DateTimeStyles)
:System.Globalization.DateTimeStyles Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Globalization.DateTimeStyles)
:System.Void CopyTo(System.Globalization.DateTimeStyles[], System.Int32)
:System.Globalization.DateTimeStyles Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Globalization.DateTimeStyles> GetEnumerator()
:System.Int32 IndexOf(System.Globalization.DateTimeStyles)
:System.Void Insert(System.Int32, System.Globalization.DateTimeStyles)
:System.Boolean Remove(System.Globalization.DateTimeStyles)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Globalization.DateTimeStyles)
:System.Globalization.DateTimeStyles get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Globalization.DateTimeStyles)
```

## `System.Globalization.DaylightTime`

_No fields or methods._

## `System.Globalization.NumberFormatInfo`

_No fields or methods._

## `System.Globalization.TimeSpanStyles`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AssumeNegative` | `System.Globalization.TimeSpanStyles` | yes | 16 |
| `None` | `System.Globalization.TimeSpanStyles` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Globalization.TimeSpanStyles[]`

**Methods**

```lua
:System.Void Add(System.Globalization.TimeSpanStyles)
:System.Globalization.TimeSpanStyles Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Globalization.TimeSpanStyles)
:System.Void CopyTo(System.Globalization.TimeSpanStyles[], System.Int32)
:System.Globalization.TimeSpanStyles Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Globalization.TimeSpanStyles> GetEnumerator()
:System.Int32 IndexOf(System.Globalization.TimeSpanStyles)
:System.Void Insert(System.Int32, System.Globalization.TimeSpanStyles)
:System.Boolean Remove(System.Globalization.TimeSpanStyles)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Globalization.TimeSpanStyles)
:System.Globalization.TimeSpanStyles get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Globalization.TimeSpanStyles)
```

## `System.Globalization.UnicodeCategory`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ClosePunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `ConnectorPunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `Control` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `CurrencySymbol` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `DashPunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `DecimalDigitNumber` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `EnclosingMark` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `FinalQuotePunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `Format` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `InitialQuotePunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `LetterNumber` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `LineSeparator` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `LowercaseLetter` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `MathSymbol` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `ModifierLetter` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `ModifierSymbol` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `NonSpacingMark` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OpenPunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OtherLetter` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OtherNotAssigned` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OtherNumber` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OtherPunctuation` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `OtherSymbol` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `ParagraphSeparator` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `PrivateUse` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `SpaceSeparator` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `SpacingCombiningMark` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `Surrogate` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `TitlecaseLetter` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `UppercaseLetter` | `System.Globalization.UnicodeCategory` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Globalization.UnicodeCategory[]`

**Methods**

```lua
:System.Void Add(System.Globalization.UnicodeCategory)
:System.Globalization.UnicodeCategory Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Globalization.UnicodeCategory)
:System.Void CopyTo(System.Globalization.UnicodeCategory[], System.Int32)
:System.Globalization.UnicodeCategory Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Globalization.UnicodeCategory> GetEnumerator()
:System.Int32 IndexOf(System.Globalization.UnicodeCategory)
:System.Void Insert(System.Int32, System.Globalization.UnicodeCategory)
:System.Boolean Remove(System.Globalization.UnicodeCategory)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Globalization.UnicodeCategory)
:System.Globalization.UnicodeCategory get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Globalization.UnicodeCategory)
```

## `System.Guid`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Empty` | `System.Guid` | yes | 16 |
| `mData1` | `System.UInt32` |  | 16 |
| `mData2` | `System.UInt16` |  | 20 |
| `mData3` | `System.UInt16` |  | 22 |
| `mData4L` | `System.UInt64` |  | 24 |
| `mData4_0` | `System.Byte` |  | 24 |
| `mData4_1` | `System.Byte` |  | 25 |
| `mData4_2` | `System.Byte` |  | 26 |
| `mData4_3` | `System.Byte` |  | 27 |
| `mData4_4` | `System.Byte` |  | 28 |
| `mData4_5` | `System.Byte` |  | 29 |
| `mData4_6` | `System.Byte` |  | 30 |
| `mData4_7` | `System.Byte` |  | 31 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.Byte[])
:System.Void .ctor(System.Int32, System.Int16, System.Int16, System.Byte[])
:System.Void .ctor(System.Int32, System.Int16, System.Int16, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte)
:System.Void .ctor(System.UInt32, System.UInt16, System.UInt16, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte, System.Byte)
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Guid)
:System.Boolean Equals(System.Guid)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Byte[] ToByteArray()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "NewGuid", ...)  -- System.Guid NewGuid()
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Guid Parse(System.String)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Guid, System.Guid)
sdk.call_native_func(nil, type_def, "op_GreaterThan", ...)  -- System.Boolean op_GreaterThan(System.Guid, System.Guid)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Guid, System.Guid)
sdk.call_native_func(nil, type_def, "op_LessThan", ...)  -- System.Boolean op_LessThan(System.Guid, System.Guid)
```

## `System.Guid[]`

**Methods**

```lua
:System.Void Add(System.Guid)
:System.Guid Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Guid)
:System.Void CopyTo(System.Guid[], System.Int32)
:System.Guid Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Guid> GetEnumerator()
:System.Int32 IndexOf(System.Guid)
:System.Void Insert(System.Int32, System.Guid)
:System.Boolean Remove(System.Guid)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Guid)
:System.Guid get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Guid)
```

## `System.Guid[][]`

**Methods**

```lua
:System.Void Add(System.Guid[])
:System.Guid[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Guid[])
:System.Void CopyTo(System.Guid[][], System.Int32)
:System.Guid[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Guid[]> GetEnumerator()
:System.Int32 IndexOf(System.Guid[])
:System.Void Insert(System.Int32, System.Guid[])
:System.Boolean Remove(System.Guid[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Guid[])
:System.Guid[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Guid[])
```

## `System.IAsyncResult`

_No fields or methods._

## `System.ICloneable`

_No fields or methods._

## `System.IComparable`

_No fields or methods._

## `System.IConvertible`

_No fields or methods._

## `System.ICustomFormatter`

_No fields or methods._

## `System.IDisposable`

_No fields or methods._

## `System.IFormatProvider`

_No fields or methods._

## `System.IFormattable`

_No fields or methods._

## `System.IO.SeekOrigin`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Begin` | `System.IO.SeekOrigin` | yes | 16 |
| `Current` | `System.IO.SeekOrigin` | yes | 16 |
| `End` | `System.IO.SeekOrigin` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.IO.SeekOrigin[]`

**Methods**

```lua
:System.Void Add(System.IO.SeekOrigin)
:System.IO.SeekOrigin Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.IO.SeekOrigin)
:System.Void CopyTo(System.IO.SeekOrigin[], System.Int32)
:System.IO.SeekOrigin Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.IO.SeekOrigin> GetEnumerator()
:System.Int32 IndexOf(System.IO.SeekOrigin)
:System.Void Insert(System.Int32, System.IO.SeekOrigin)
:System.Boolean Remove(System.IO.SeekOrigin)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.IO.SeekOrigin)
:System.IO.SeekOrigin get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.IO.SeekOrigin)
```

## `System.IO.Stream`

**Methods**

```lua
:System.Void Close()
:System.Void CopyTo(System.IO.Stream)
:System.Void CopyTo(System.IO.Stream, System.Int32)
:System.Void Dispose()
:System.Int32 ReadByte()
:System.Void WriteByte(System.Byte)
:System.Int32 get_ReadTimeout()
:System.Int32 get_WriteTimeout()
:System.Void internalCopyTo(System.IO.Stream, System.Int32)
:System.Void set_ReadTimeout(System.Int32)
:System.Void set_WriteTimeout(System.Int32)
```

## `System.ITupleInternal`

_No fields or methods._

## `System.IValueTupleInternal`

_No fields or methods._

## `System.IndexOutOfRangeException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Int16`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.Int16` | yes | 16 |
| `MinValue` | `System.Int16` | yes | 16 |
| `mValue` | `System.Int16` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Int16)
:System.Boolean Equals(System.Int16)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Int16 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Int16)
```

## `System.Int16[]`

**Methods**

```lua
:System.Void Add(System.Int16)
:System.Int16 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Int16)
:System.Void CopyTo(System.Int16[], System.Int32)
:System.Int16 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Int16> GetEnumerator()
:System.Int32 IndexOf(System.Int16)
:System.Void Insert(System.Int32, System.Int16)
:System.Boolean Remove(System.Int16)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Int16)
:System.Int16 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Int16)
```

## `System.Int32`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.Int32` | yes | 16 |
| `MinValue` | `System.Int32` | yes | 16 |
| `mValue` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Int32)
:System.Boolean Equals(System.Int32)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Int32 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Int32)
```

## `System.Int32[,]`

**Methods**

```lua
:System.Int32 Address(System.Int32, System.Int32)
:System.Int32 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Int32)
```

## `System.Int32[]`

**Methods**

```lua
:System.Void Add(System.Int32)
:System.Int32 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Int32)
:System.Void CopyTo(System.Int32[], System.Int32)
:System.Int32 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Int32> GetEnumerator()
:System.Int32 IndexOf(System.Int32)
:System.Void Insert(System.Int32, System.Int32)
:System.Boolean Remove(System.Int32)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Int32)
:System.Int32 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Int32)
```

## `System.Int32[][]`

**Methods**

```lua
:System.Void Add(System.Int32[])
:System.Int32[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Int32[])
:System.Void CopyTo(System.Int32[][], System.Int32)
:System.Int32[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Int32[]> GetEnumerator()
:System.Int32 IndexOf(System.Int32[])
:System.Void Insert(System.Int32, System.Int32[])
:System.Boolean Remove(System.Int32[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Int32[])
:System.Int32[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Int32[])
```

## `System.Int64`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.Int64` | yes | 16 |
| `MinValue` | `System.Int64` | yes | 16 |
| `mValue` | `System.Int64` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Int64)
:System.Boolean Equals(System.Int64)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Int64 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Int64)
```

## `System.Int64[]`

**Methods**

```lua
:System.Void Add(System.Int64)
:System.Int64 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Int64)
:System.Void CopyTo(System.Int64[], System.Int32)
:System.Int64 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Int64> GetEnumerator()
:System.Int32 IndexOf(System.Int64)
:System.Void Insert(System.Int32, System.Int64)
:System.Boolean Remove(System.Int64)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Int64)
:System.Int64 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Int64)
```

## `System.IntPtr`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.Int64` |  | 16 |

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.String ToString()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_Size", ...)  -- System.Int32 get_Size()
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.IntPtr, System.IntPtr)
sdk.call_native_func(nil, type_def, "op_Explicit", ...)  -- System.IntPtr op_Explicit(System.Int32)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.IntPtr, System.IntPtr)
```

## `System.InvalidCastException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.InvalidOperationException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Linq.Enumerable`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Double Average(System.Collections.Generic.IEnumerable`1<System.Int32>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Double Average(System.Collections.Generic.IEnumerable`1<System.Int64>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Single Average(System.Collections.Generic.IEnumerable`1<System.Single>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Nullable`1<System.Single> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Double Average(System.Collections.Generic.IEnumerable`1<System.Double>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Decimal Average(System.Collections.Generic.IEnumerable`1<System.Decimal>)
sdk.call_native_func(nil, type_def, "Average", ...)  -- System.Nullable`1<System.Decimal> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Int32 Max(System.Collections.Generic.IEnumerable`1<System.Int32>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Nullable`1<System.Int32> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Int64 Max(System.Collections.Generic.IEnumerable`1<System.Int64>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Nullable`1<System.Int64> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Double Max(System.Collections.Generic.IEnumerable`1<System.Double>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Nullable`1<System.Double> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Single Max(System.Collections.Generic.IEnumerable`1<System.Single>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Nullable`1<System.Single> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Decimal Max(System.Collections.Generic.IEnumerable`1<System.Decimal>)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Nullable`1<System.Decimal> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Int32 Min(System.Collections.Generic.IEnumerable`1<System.Int32>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Nullable`1<System.Int32> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Int64 Min(System.Collections.Generic.IEnumerable`1<System.Int64>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Nullable`1<System.Int64> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Single Min(System.Collections.Generic.IEnumerable`1<System.Single>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Nullable`1<System.Single> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Double Min(System.Collections.Generic.IEnumerable`1<System.Double>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Nullable`1<System.Double> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Decimal Min(System.Collections.Generic.IEnumerable`1<System.Decimal>)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Nullable`1<System.Decimal> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
sdk.call_native_func(nil, type_def, "Range", ...)  -- System.Collections.Generic.IEnumerable`1<System.Int32> Range(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Int32 Sum(System.Collections.Generic.IEnumerable`1<System.Int32>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Nullable`1<System.Int32> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Int64 Sum(System.Collections.Generic.IEnumerable`1<System.Int64>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Nullable`1<System.Int64> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Single Sum(System.Collections.Generic.IEnumerable`1<System.Single>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Nullable`1<System.Single> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Double Sum(System.Collections.Generic.IEnumerable`1<System.Double>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Nullable`1<System.Double> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Decimal Sum(System.Collections.Generic.IEnumerable`1<System.Decimal>)
sdk.call_native_func(nil, type_def, "Sum", ...)  -- System.Nullable`1<System.Decimal> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
```

## `System.Linq.Enumerable.RangeIterator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_start` | `System.Int32` |  | 28 |
| `_end` | `System.Int32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.Int32)
:System.Linq.Enumerable.Iterator`1<System.Int32> Clone()
:System.Void Dispose()
:System.Int32 GetCount(System.Boolean)
:System.Boolean MoveNext()
:System.Linq.IPartition`1<System.Int32> Skip(System.Int32)
:System.Linq.IPartition`1<System.Int32> Take(System.Int32)
:System.Int32[] ToArray()
:System.Collections.Generic.List`1<System.Int32> ToList()
:System.Int32 TryGetElementAt(System.Int32, System.Boolean)
:System.Int32 TryGetFirst(System.Boolean)
:System.Int32 TryGetLast(System.Boolean)
```

## `System.Linq.Error`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "ArgumentNull", ...)  -- System.Exception ArgumentNull(System.String)
sdk.call_native_func(nil, type_def, "ArgumentOutOfRange", ...)  -- System.Exception ArgumentOutOfRange(System.String)
sdk.call_native_func(nil, type_def, "MoreThanOneElement", ...)  -- System.Exception MoreThanOneElement()
sdk.call_native_func(nil, type_def, "MoreThanOneMatch", ...)  -- System.Exception MoreThanOneMatch()
sdk.call_native_func(nil, type_def, "NoElements", ...)  -- System.Exception NoElements()
sdk.call_native_func(nil, type_def, "NoMatch", ...)  -- System.Exception NoMatch()
sdk.call_native_func(nil, type_def, "NotSupported", ...)  -- System.Exception NotSupported()
```

## `System.Linq.Utilities`

_No fields or methods._

## `System.MTAThreadAttribute`

_No fields or methods._

## `System.MarshalByRefObject`

_No fields or methods._

## `System.Math`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `E` | `System.Double` | yes | 16 |
| `PI` | `System.Double` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Double Abs(System.Double)
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Int16 Abs(System.Int16)
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Int32 Abs(System.Int32)
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Int64 Abs(System.Int64)
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.SByte Abs(System.SByte)
sdk.call_native_func(nil, type_def, "Abs", ...)  -- System.Single Abs(System.Single)
sdk.call_native_func(nil, type_def, "Ceiling", ...)  -- System.Double Ceiling(System.Double)
sdk.call_native_func(nil, type_def, "Cos", ...)  -- System.Double Cos(System.Double)
sdk.call_native_func(nil, type_def, "Cosh", ...)  -- System.Double Cosh(System.Double)
sdk.call_native_func(nil, type_def, "Exp", ...)  -- System.Double Exp(System.Double)
sdk.call_native_func(nil, type_def, "Floor", ...)  -- System.Double Floor(System.Double)
sdk.call_native_func(nil, type_def, "Log", ...)  -- System.Double Log(System.Double)
sdk.call_native_func(nil, type_def, "Log10", ...)  -- System.Double Log10(System.Double)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Byte Max(System.Byte, System.Byte)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.SByte Max(System.SByte, System.SByte)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Int16 Max(System.Int16, System.Int16)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.UInt16 Max(System.UInt16, System.UInt16)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Int32 Max(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.UInt32 Max(System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Int64 Max(System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.UInt64 Max(System.UInt64, System.UInt64)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Single Max(System.Single, System.Single)
sdk.call_native_func(nil, type_def, "Max", ...)  -- System.Double Max(System.Double, System.Double)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Byte Min(System.Byte, System.Byte)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.SByte Min(System.SByte, System.SByte)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Int16 Min(System.Int16, System.Int16)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.UInt16 Min(System.UInt16, System.UInt16)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Int32 Min(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.UInt32 Min(System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Int64 Min(System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.UInt64 Min(System.UInt64, System.UInt64)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Single Min(System.Single, System.Single)
sdk.call_native_func(nil, type_def, "Min", ...)  -- System.Double Min(System.Double, System.Double)
sdk.call_native_func(nil, type_def, "Pow", ...)  -- System.Double Pow(System.Double, System.Double)
sdk.call_native_func(nil, type_def, "Round", ...)  -- System.Double Round(System.Double)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.SByte)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Int16)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Int32)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Int64)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Single)
sdk.call_native_func(nil, type_def, "Sign", ...)  -- System.Int32 Sign(System.Double)
sdk.call_native_func(nil, type_def, "Sin", ...)  -- System.Double Sin(System.Double)
sdk.call_native_func(nil, type_def, "Sinh", ...)  -- System.Double Sinh(System.Double)
sdk.call_native_func(nil, type_def, "Sqrt", ...)  -- System.Double Sqrt(System.Double)
sdk.call_native_func(nil, type_def, "Tan", ...)  -- System.Double Tan(System.Double)
sdk.call_native_func(nil, type_def, "Tanh", ...)  -- System.Double Tanh(System.Double)
sdk.call_native_func(nil, type_def, "Truncate", ...)  -- System.Double Truncate(System.Double)
```

## `System.MemberAccessException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.MethodAccessException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.MidpointRounding`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AwayFromZero` | `System.MidpointRounding` | yes | 16 |
| `ToEven` | `System.MidpointRounding` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.MidpointRounding[]`

**Methods**

```lua
:System.Void Add(System.MidpointRounding)
:System.MidpointRounding Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.MidpointRounding)
:System.Void CopyTo(System.MidpointRounding[], System.Int32)
:System.MidpointRounding Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.MidpointRounding> GetEnumerator()
:System.Int32 IndexOf(System.MidpointRounding)
:System.Void Insert(System.Int32, System.MidpointRounding)
:System.Boolean Remove(System.MidpointRounding)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.MidpointRounding)
:System.MidpointRounding get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.MidpointRounding)
```

## `System.MissingFieldException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.MissingMemberException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.MissingMethodException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ModuleHandle`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EmptyHandle` | `System.ModuleHandle` | yes | 16 |
| `mValue` | `System.IntPtr` |  | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetEmptyMH", ...)  -- System.ModuleHandle GetEmptyMH()
```

## `System.MulticastDelegate`

**Methods**

```lua
:System.Void .ctor()
:System.Delegate[] GetInvocationList()
```

## `System.NonSerializedAttribute`

_No fields or methods._

## `System.NotFiniteNumberException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.NotImplementedException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.NotSupportedException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.NullReferenceException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.NumberStyles`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AllowCurrencySymbol` | `System.NumberStyles` | yes | 16 |
| `AllowDecimalPoint` | `System.NumberStyles` | yes | 16 |
| `AllowExponent` | `System.NumberStyles` | yes | 16 |
| `AllowHexSpecifier` | `System.NumberStyles` | yes | 16 |
| `AllowLeadingSign` | `System.NumberStyles` | yes | 16 |
| `AllowLeadingWhite` | `System.NumberStyles` | yes | 16 |
| `AllowParentheses` | `System.NumberStyles` | yes | 16 |
| `AllowThousands` | `System.NumberStyles` | yes | 16 |
| `AllowTrailingSign` | `System.NumberStyles` | yes | 16 |
| `AllowTrailingWhite` | `System.NumberStyles` | yes | 16 |
| `Any` | `System.NumberStyles` | yes | 16 |
| `Currency` | `System.NumberStyles` | yes | 16 |
| `Float` | `System.NumberStyles` | yes | 16 |
| `HexNumber` | `System.NumberStyles` | yes | 16 |
| `Integer` | `System.NumberStyles` | yes | 16 |
| `None` | `System.NumberStyles` | yes | 16 |
| `Number` | `System.NumberStyles` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.NumberStyles[]`

**Methods**

```lua
:System.Void Add(System.NumberStyles)
:System.NumberStyles Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.NumberStyles)
:System.Void CopyTo(System.NumberStyles[], System.Int32)
:System.NumberStyles Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.NumberStyles> GetEnumerator()
:System.Int32 IndexOf(System.NumberStyles)
:System.Void Insert(System.Int32, System.NumberStyles)
:System.Boolean Remove(System.NumberStyles)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.NumberStyles)
:System.NumberStyles get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.NumberStyles)
```

## `System.Object`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Type GetType()
:System.Object MemberwiseClone()
:System.String ToString()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.Object, System.Object)
sdk.call_native_func(nil, type_def, "ReferenceEquals", ...)  -- System.Boolean ReferenceEquals(System.Object, System.Object)
```

## `System.ObjectDisposedException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Object[]`

**Methods**

```lua
:System.Void Add(System.Object)
:System.Object Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Object)
:System.Void CopyTo(System.Object[], System.Int32)
:System.Object Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Object> GetEnumerator()
:System.Int32 IndexOf(System.Object)
:System.Void Insert(System.Int32, System.Object)
:System.Boolean Remove(System.Object)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Object)
:System.Object get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Object)
```

## `System.ObsoleteAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mMessage` | `System.String` |  | 16 |
| `mError` | `System.Boolean` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Boolean)
:System.Boolean get_IsError()
:System.String get_Message()
```

## `System.OutOfMemoryException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.OverflowException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.ParamArrayAttribute`

_No fields or methods._

## `System.PlatformNotSupportedException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Random`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `x` | `System.UInt32` |  | 16 |
| `y` | `System.UInt32` |  | 20 |
| `z` | `System.UInt32` |  | 24 |
| `w` | `System.UInt32` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Int32 Next()
:System.Int32 Next(System.Int32)
:System.Int32 Next(System.Int32, System.Int32)
:System.Void NextBytes(System.Byte[])
:System.Double NextDouble()
:System.Double Sample()
```

## `System.RankException`

_No fields or methods._

## `System.Reflection.Assembly`

**Methods**

```lua
:System.Object CreateInstance(System.String)
:System.Object CreateInstance(System.String, System.Boolean)
:System.Object CreateInstance(System.String, System.Boolean, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo, System.Object[])
:System.Boolean Equals(System.Object)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> GetCustomAttributesData()
:System.Type[] GetExportedTypes()
:System.Type[] GetForwardedTypes()
:System.Int32 GetHashCode()
:System.Reflection.Module[] GetLoadedModules()
:System.Reflection.Module[] GetLoadedModules(System.Boolean)
:System.String[] GetManifestResourceNames()
:System.IO.Stream GetManifestResourceStream(System.String)
:System.IO.Stream GetManifestResourceStream(System.Type, System.String)
:System.Reflection.Module GetModule(System.String)
:System.Reflection.Module[] GetModules()
:System.Reflection.Module[] GetModules(System.Boolean)
:System.Reflection.AssemblyName GetName()
:System.Reflection.AssemblyName GetName(System.Boolean)
:System.Reflection.AssemblyName[] GetReferencedAssemblies()
:System.Reflection.Assembly GetSatelliteAssembly(System.Globalization.CultureInfo)
:System.Reflection.Assembly GetSatelliteAssembly(System.Globalization.CultureInfo, System.Version)
:System.Type GetType(System.String)
:System.Type GetType(System.String, System.Boolean)
:System.Type GetType(System.String, System.Boolean, System.Boolean)
:System.Type[] GetTypes()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Reflection.Module LoadModule(System.String, System.Byte[])
:System.Reflection.Module LoadModule(System.String, System.Byte[], System.Byte[])
:System.String ToString()
:System.String get_CodeBase()
:System.Collections.Generic.IEnumerable`1<System.Reflection.CustomAttributeData> get_CustomAttributes()
:System.Collections.Generic.IEnumerable`1<System.Reflection.TypeInfo> get_DefinedTypes()
:System.Reflection.MethodInfo get_EntryPoint()
:System.Collections.Generic.IEnumerable`1<System.Type> get_ExportedTypes()
:System.String get_FullName()
:System.Boolean get_GlobalAssemblyCache()
:System.Int64 get_HostContext()
:System.String get_ImageRuntimeVersion()
:System.String get_Location()
:System.Reflection.Module get_ManifestModule()
:System.Collections.Generic.IEnumerable`1<System.Reflection.Module> get_Modules()
:System.Boolean get_ReflectionOnly()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "CreateQualifiedName", ...)  -- System.String CreateQualifiedName(System.String, System.String)
sdk.call_native_func(nil, type_def, "GetAssembly", ...)  -- System.Reflection.Assembly GetAssembly(System.Type)
sdk.call_native_func(nil, type_def, "ReflectionOnlyLoad", ...)  -- System.Reflection.Assembly ReflectionOnlyLoad(System.Byte[])
sdk.call_native_func(nil, type_def, "ReflectionOnlyLoad", ...)  -- System.Reflection.Assembly ReflectionOnlyLoad(System.String)
sdk.call_native_func(nil, type_def, "ReflectionOnlyLoadFrom", ...)  -- System.Reflection.Assembly ReflectionOnlyLoadFrom(System.String)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.Assembly, System.Reflection.Assembly)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.Assembly, System.Reflection.Assembly)
```

## `System.Reflection.AssemblyCompanyAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Company` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Company()
```

## `System.Reflection.AssemblyConfigurationAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Configuration` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Configuration()
```

## `System.Reflection.AssemblyCopyrightAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Copyright` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Copyright()
```

## `System.Reflection.AssemblyCultureAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Culture` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Culture()
```

## `System.Reflection.AssemblyDescriptionAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Description` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Description()
```

## `System.Reflection.AssemblyFileVersionAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Version` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Version()
```

## `System.Reflection.AssemblyName`

**Methods**

```lua
:System.Object Clone()
```

## `System.Reflection.AssemblyName[]`

**Methods**

```lua
:System.Void Add(System.Reflection.AssemblyName)
:System.Reflection.AssemblyName Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.AssemblyName)
:System.Void CopyTo(System.Reflection.AssemblyName[], System.Int32)
:System.Reflection.AssemblyName Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.AssemblyName> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.AssemblyName)
:System.Void Insert(System.Int32, System.Reflection.AssemblyName)
:System.Boolean Remove(System.Reflection.AssemblyName)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.AssemblyName)
:System.Reflection.AssemblyName get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.AssemblyName)
```

## `System.Reflection.AssemblyProductAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Product` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Product()
```

## `System.Reflection.AssemblyTitleAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Title` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Title()
```

## `System.Reflection.AssemblyTrademarkAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Trademark` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Trademark()
```

## `System.Reflection.AssemblyVersionAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Version` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Version()
```

## `System.Reflection.Assembly[]`

**Methods**

```lua
:System.Void Add(System.Reflection.Assembly)
:System.Reflection.Assembly Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.Assembly)
:System.Void CopyTo(System.Reflection.Assembly[], System.Int32)
:System.Reflection.Assembly Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.Assembly> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.Assembly)
:System.Void Insert(System.Int32, System.Reflection.Assembly)
:System.Boolean Remove(System.Reflection.Assembly)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.Assembly)
:System.Reflection.Assembly get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.Assembly)
```

## `System.Reflection.Binder`

_No fields or methods._

## `System.Reflection.BindingFlags`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CreateInstance` | `System.Reflection.BindingFlags` | yes | 16 |
| `DeclaredOnly` | `System.Reflection.BindingFlags` | yes | 16 |
| `Default` | `System.Reflection.BindingFlags` | yes | 16 |
| `ExactBinding` | `System.Reflection.BindingFlags` | yes | 16 |
| `FlattenHierarchy` | `System.Reflection.BindingFlags` | yes | 16 |
| `GetField` | `System.Reflection.BindingFlags` | yes | 16 |
| `GetProperty` | `System.Reflection.BindingFlags` | yes | 16 |
| `IgnoreCase` | `System.Reflection.BindingFlags` | yes | 16 |
| `IgnoreReturn` | `System.Reflection.BindingFlags` | yes | 16 |
| `Instance` | `System.Reflection.BindingFlags` | yes | 16 |
| `InvokeMethod` | `System.Reflection.BindingFlags` | yes | 16 |
| `NonPublic` | `System.Reflection.BindingFlags` | yes | 16 |
| `OptionalParamBinding` | `System.Reflection.BindingFlags` | yes | 16 |
| `Public` | `System.Reflection.BindingFlags` | yes | 16 |
| `PutDispProperty` | `System.Reflection.BindingFlags` | yes | 16 |
| `PutRefDispProperty` | `System.Reflection.BindingFlags` | yes | 16 |
| `SetField` | `System.Reflection.BindingFlags` | yes | 16 |
| `SetProperty` | `System.Reflection.BindingFlags` | yes | 16 |
| `Static` | `System.Reflection.BindingFlags` | yes | 16 |
| `SuppressChangeType` | `System.Reflection.BindingFlags` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.BindingFlags[]`

**Methods**

```lua
:System.Void Add(System.Reflection.BindingFlags)
:System.Reflection.BindingFlags Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.BindingFlags)
:System.Void CopyTo(System.Reflection.BindingFlags[], System.Int32)
:System.Reflection.BindingFlags Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.BindingFlags> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.BindingFlags)
:System.Void Insert(System.Int32, System.Reflection.BindingFlags)
:System.Boolean Remove(System.Reflection.BindingFlags)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.BindingFlags)
:System.Reflection.BindingFlags get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.BindingFlags)
```

## `System.Reflection.CallingConventions`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Any` | `System.Reflection.CallingConventions` | yes | 16 |
| `ExplicitThis` | `System.Reflection.CallingConventions` | yes | 16 |
| `HasThis` | `System.Reflection.CallingConventions` | yes | 16 |
| `Standard` | `System.Reflection.CallingConventions` | yes | 16 |
| `VarArgs` | `System.Reflection.CallingConventions` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.CallingConventions[]`

**Methods**

```lua
:System.Void Add(System.Reflection.CallingConventions)
:System.Reflection.CallingConventions Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.CallingConventions)
:System.Void CopyTo(System.Reflection.CallingConventions[], System.Int32)
:System.Reflection.CallingConventions Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.CallingConventions> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.CallingConventions)
:System.Void Insert(System.Int32, System.Reflection.CallingConventions)
:System.Boolean Remove(System.Reflection.CallingConventions)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.CallingConventions)
:System.Reflection.CallingConventions get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.CallingConventions)
```

## `System.Reflection.ConstructorInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ConstructorName` | `System.String` | yes | 16 |
| `TypeConstructorName` | `System.String` | yes | 24 |

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Object Invoke(System.Object[])
:System.Reflection.MemberTypes get_MemberType()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.ConstructorInfo, System.Reflection.ConstructorInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.ConstructorInfo, System.Reflection.ConstructorInfo)
```

## `System.Reflection.ConstructorInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.ConstructorInfo)
:System.Reflection.ConstructorInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.ConstructorInfo)
:System.Void CopyTo(System.Reflection.ConstructorInfo[], System.Int32)
:System.Reflection.ConstructorInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.ConstructorInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.ConstructorInfo)
:System.Void Insert(System.Int32, System.Reflection.ConstructorInfo)
:System.Boolean Remove(System.Reflection.ConstructorInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.ConstructorInfo)
:System.Reflection.ConstructorInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.ConstructorInfo)
```

## `System.Reflection.CustomAttributeData`

_No fields or methods._

## `System.Reflection.CustomAttributeData[]`

**Methods**

```lua
:System.Void Add(System.Reflection.CustomAttributeData)
:System.Reflection.CustomAttributeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.CustomAttributeData)
:System.Void CopyTo(System.Reflection.CustomAttributeData[], System.Int32)
:System.Reflection.CustomAttributeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.CustomAttributeData> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.CustomAttributeData)
:System.Void Insert(System.Int32, System.Reflection.CustomAttributeData)
:System.Boolean Remove(System.Reflection.CustomAttributeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.CustomAttributeData)
:System.Reflection.CustomAttributeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.CustomAttributeData)
```

## `System.Reflection.DefaultMemberAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MemberName` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_MemberName()
```

## `System.Reflection.EventAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `None` | `System.Reflection.EventAttributes` | yes | 16 |
| `RTSpecialName` | `System.Reflection.EventAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.EventAttributes` | yes | 16 |
| `SpecialName` | `System.Reflection.EventAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.EventAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.EventAttributes)
:System.Reflection.EventAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.EventAttributes)
:System.Void CopyTo(System.Reflection.EventAttributes[], System.Int32)
:System.Reflection.EventAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.EventAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.EventAttributes)
:System.Void Insert(System.Int32, System.Reflection.EventAttributes)
:System.Boolean Remove(System.Reflection.EventAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.EventAttributes)
:System.Reflection.EventAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.EventAttributes)
```

## `System.Reflection.EventInfo`

**Methods**

```lua
:System.Void AddEventHandler(System.Object, System.Delegate)
:System.Boolean Equals(System.Object)
:System.Reflection.MethodInfo GetAddMethod()
:System.Int32 GetHashCode()
:System.Reflection.MethodInfo[] GetOtherMethods()
:System.Reflection.MethodInfo[] GetOtherMethods(System.Boolean)
:System.Reflection.MethodInfo GetRaiseMethod()
:System.Reflection.MethodInfo GetRemoveMethod()
:System.Void RemoveEventHandler(System.Object, System.Delegate)
:System.Reflection.MethodInfo get_AddMethod()
:System.Type get_EventHandlerType()
:System.Boolean get_IsMulticast()
:System.Boolean get_IsSpecialName()
:System.Reflection.MemberTypes get_MemberType()
:System.Reflection.MethodInfo get_RaiseMethod()
:System.Reflection.MethodInfo get_RemoveMethod()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.EventInfo, System.Reflection.EventInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.EventInfo, System.Reflection.EventInfo)
```

## `System.Reflection.EventInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.EventInfo)
:System.Reflection.EventInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.EventInfo)
:System.Void CopyTo(System.Reflection.EventInfo[], System.Int32)
:System.Reflection.EventInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.EventInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.EventInfo)
:System.Void Insert(System.Int32, System.Reflection.EventInfo)
:System.Boolean Remove(System.Reflection.EventInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.EventInfo)
:System.Reflection.EventInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.EventInfo)
```

## `System.Reflection.FieldAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Assembly` | `System.Reflection.FieldAttributes` | yes | 16 |
| `FamANDAssem` | `System.Reflection.FieldAttributes` | yes | 16 |
| `FamORAssem` | `System.Reflection.FieldAttributes` | yes | 16 |
| `Family` | `System.Reflection.FieldAttributes` | yes | 16 |
| `FieldAccessMask` | `System.Reflection.FieldAttributes` | yes | 16 |
| `HasDefault` | `System.Reflection.FieldAttributes` | yes | 16 |
| `HasFieldMarshal` | `System.Reflection.FieldAttributes` | yes | 16 |
| `HasFieldRVA` | `System.Reflection.FieldAttributes` | yes | 16 |
| `InitOnly` | `System.Reflection.FieldAttributes` | yes | 16 |
| `Literal` | `System.Reflection.FieldAttributes` | yes | 16 |
| `NotSerialized` | `System.Reflection.FieldAttributes` | yes | 16 |
| `PinvokeImpl` | `System.Reflection.FieldAttributes` | yes | 16 |
| `Private` | `System.Reflection.FieldAttributes` | yes | 16 |
| `PrivateScope` | `System.Reflection.FieldAttributes` | yes | 16 |
| `Public` | `System.Reflection.FieldAttributes` | yes | 16 |
| `RTSpecialName` | `System.Reflection.FieldAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.FieldAttributes` | yes | 16 |
| `SpecialName` | `System.Reflection.FieldAttributes` | yes | 16 |
| `Static` | `System.Reflection.FieldAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.FieldAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.FieldAttributes)
:System.Reflection.FieldAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.FieldAttributes)
:System.Void CopyTo(System.Reflection.FieldAttributes[], System.Int32)
:System.Reflection.FieldAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.FieldAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.FieldAttributes)
:System.Void Insert(System.Int32, System.Reflection.FieldAttributes)
:System.Boolean Remove(System.Reflection.FieldAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.FieldAttributes)
:System.Reflection.FieldAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.FieldAttributes)
```

## `System.Reflection.FieldInfo`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Type[] GetOptionalCustomModifiers()
:System.Object GetRawConstantValue()
:System.Type[] GetRequiredCustomModifiers()
:System.Object GetValueDirect(System.TypedReference)
:System.Void SetValue(System.Object, System.Object)
:System.Void SetValueDirect(System.TypedReference, System.Object)
:System.String ToString()
:System.Boolean get_IsAssembly()
:System.Boolean get_IsFamily()
:System.Boolean get_IsFamilyAndAssembly()
:System.Boolean get_IsFamilyOrAssembly()
:System.Boolean get_IsInitOnly()
:System.Boolean get_IsLiteral()
:System.Boolean get_IsNotSerialized()
:System.Boolean get_IsPinvokeImpl()
:System.Boolean get_IsPrivate()
:System.Boolean get_IsPublic()
:System.Boolean get_IsSpecialName()
:System.Boolean get_IsStatic()
:System.Reflection.MemberTypes get_MemberType()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.FieldInfo, System.Reflection.FieldInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.FieldInfo, System.Reflection.FieldInfo)
```

## `System.Reflection.FieldInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.FieldInfo)
:System.Reflection.FieldInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.FieldInfo)
:System.Void CopyTo(System.Reflection.FieldInfo[], System.Int32)
:System.Reflection.FieldInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.FieldInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.FieldInfo)
:System.Void Insert(System.Int32, System.Reflection.FieldInfo)
:System.Boolean Remove(System.Reflection.FieldInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.FieldInfo)
:System.Reflection.FieldInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.FieldInfo)
```

## `System.Reflection.GenericParameterAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Contravariant` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `Covariant` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `DefaultConstructorConstraint` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `None` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `NotNullableValueTypeConstraint` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `ReferenceTypeConstraint` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `SpecialConstraintMask` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `VarianceMask` | `System.Reflection.GenericParameterAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.GenericParameterAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.GenericParameterAttributes)
:System.Reflection.GenericParameterAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.GenericParameterAttributes)
:System.Void CopyTo(System.Reflection.GenericParameterAttributes[], System.Int32)
:System.Reflection.GenericParameterAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.GenericParameterAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.GenericParameterAttributes)
:System.Void Insert(System.Int32, System.Reflection.GenericParameterAttributes)
:System.Boolean Remove(System.Reflection.GenericParameterAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.GenericParameterAttributes)
:System.Reflection.GenericParameterAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.GenericParameterAttributes)
```

## `System.Reflection.ICustomAttributeProvider`

_No fields or methods._

## `System.Reflection.IReflect`

_No fields or methods._

## `System.Reflection.IReflectableType`

_No fields or methods._

## `System.Reflection.InterfaceMapping`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TargetType` | `System.Type` |  | 16 |
| `InterfaceType` | `System.Type` |  | 24 |
| `TargetMethods` | `System.Reflection.MethodInfo[]` |  | 32 |
| `InterfaceMethods` | `System.Reflection.MethodInfo[]` |  | 40 |

## `System.Reflection.IntrospectionExtensions`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetTypeInfo", ...)  -- System.Reflection.TypeInfo GetTypeInfo(System.Type)
```

## `System.Reflection.InvalidFilterCriteriaException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Reflection.MemberFilter`

**Methods**

```lua
:System.Boolean Invoke(System.Reflection.MemberInfo, System.Object)
```

## `System.Reflection.MemberInfo`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> GetCustomAttributesData()
:System.Int32 GetHashCode()
:System.Boolean HasSameMetadataDefinitionAs(System.Reflection.MemberInfo)
:System.Collections.Generic.IEnumerable`1<System.Reflection.CustomAttributeData> get_CustomAttributes()
:System.Int32 get_MetadataToken()
:System.Reflection.Module get_Module()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.MemberInfo, System.Reflection.MemberInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.MemberInfo, System.Reflection.MemberInfo)
```

## `System.Reflection.MemberInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MemberInfo)
:System.Reflection.MemberInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MemberInfo)
:System.Void CopyTo(System.Reflection.MemberInfo[], System.Int32)
:System.Reflection.MemberInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MemberInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MemberInfo)
:System.Void Insert(System.Int32, System.Reflection.MemberInfo)
:System.Boolean Remove(System.Reflection.MemberInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MemberInfo)
:System.Reflection.MemberInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MemberInfo)
```

## `System.Reflection.MemberTypes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `All` | `System.Reflection.MemberTypes` | yes | 16 |
| `Constructor` | `System.Reflection.MemberTypes` | yes | 16 |
| `Custom` | `System.Reflection.MemberTypes` | yes | 16 |
| `Event` | `System.Reflection.MemberTypes` | yes | 16 |
| `Field` | `System.Reflection.MemberTypes` | yes | 16 |
| `Method` | `System.Reflection.MemberTypes` | yes | 16 |
| `NestedType` | `System.Reflection.MemberTypes` | yes | 16 |
| `Property` | `System.Reflection.MemberTypes` | yes | 16 |
| `TypeInfo` | `System.Reflection.MemberTypes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.MemberTypes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MemberTypes)
:System.Reflection.MemberTypes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MemberTypes)
:System.Void CopyTo(System.Reflection.MemberTypes[], System.Int32)
:System.Reflection.MemberTypes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MemberTypes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MemberTypes)
:System.Void Insert(System.Int32, System.Reflection.MemberTypes)
:System.Boolean Remove(System.Reflection.MemberTypes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MemberTypes)
:System.Reflection.MemberTypes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MemberTypes)
```

## `System.Reflection.MethodAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Abstract` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Assembly` | `System.Reflection.MethodAttributes` | yes | 16 |
| `CheckAccessOnOverride` | `System.Reflection.MethodAttributes` | yes | 16 |
| `FamANDAssem` | `System.Reflection.MethodAttributes` | yes | 16 |
| `FamORAssem` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Family` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Final` | `System.Reflection.MethodAttributes` | yes | 16 |
| `HasSecurity` | `System.Reflection.MethodAttributes` | yes | 16 |
| `HideBySig` | `System.Reflection.MethodAttributes` | yes | 16 |
| `MemberAccessMask` | `System.Reflection.MethodAttributes` | yes | 16 |
| `NewSlot` | `System.Reflection.MethodAttributes` | yes | 16 |
| `PinvokeImpl` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Private` | `System.Reflection.MethodAttributes` | yes | 16 |
| `PrivateScope` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Public` | `System.Reflection.MethodAttributes` | yes | 16 |
| `RTSpecialName` | `System.Reflection.MethodAttributes` | yes | 16 |
| `RequireSecObject` | `System.Reflection.MethodAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.MethodAttributes` | yes | 16 |
| `ReuseSlot` | `System.Reflection.MethodAttributes` | yes | 16 |
| `SpecialName` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Static` | `System.Reflection.MethodAttributes` | yes | 16 |
| `UnmanagedExport` | `System.Reflection.MethodAttributes` | yes | 16 |
| `Virtual` | `System.Reflection.MethodAttributes` | yes | 16 |
| `VtableLayoutMask` | `System.Reflection.MethodAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.MethodAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MethodAttributes)
:System.Reflection.MethodAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MethodAttributes)
:System.Void CopyTo(System.Reflection.MethodAttributes[], System.Int32)
:System.Reflection.MethodAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MethodAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MethodAttributes)
:System.Void Insert(System.Int32, System.Reflection.MethodAttributes)
:System.Boolean Remove(System.Reflection.MethodAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MethodAttributes)
:System.Reflection.MethodAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MethodAttributes)
```

## `System.Reflection.MethodBase`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Type[] GetGenericArguments()
:System.Int32 GetHashCode()
:System.Reflection.MethodBody GetMethodBody()
:System.Object Invoke(System.Object, System.Object[])
:System.Reflection.CallingConventions get_CallingConvention()
:System.Boolean get_IsAbstract()
:System.Boolean get_IsAssembly()
:System.Boolean get_IsConstructedGenericMethod()
:System.Boolean get_IsConstructor()
:System.Boolean get_IsFamily()
:System.Boolean get_IsFamilyAndAssembly()
:System.Boolean get_IsFamilyOrAssembly()
:System.Boolean get_IsFinal()
:System.Boolean get_IsHideBySig()
:System.Boolean get_IsPrivate()
:System.Boolean get_IsPublic()
:System.Boolean get_IsSecurityCritical()
:System.Boolean get_IsSecuritySafeCritical()
:System.Boolean get_IsSecurityTransparent()
:System.Boolean get_IsSpecialName()
:System.Boolean get_IsStatic()
:System.Boolean get_IsVirtual()
:System.Reflection.MethodImplAttributes get_MethodImplementationFlags()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.MethodBase, System.Reflection.MethodBase)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.MethodBase, System.Reflection.MethodBase)
```

## `System.Reflection.MethodBase[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MethodBase)
:System.Reflection.MethodBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MethodBase)
:System.Void CopyTo(System.Reflection.MethodBase[], System.Int32)
:System.Reflection.MethodBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MethodBase> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MethodBase)
:System.Void Insert(System.Int32, System.Reflection.MethodBase)
:System.Boolean Remove(System.Reflection.MethodBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MethodBase)
:System.Reflection.MethodBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MethodBase)
```

## `System.Reflection.MethodBody`

_No fields or methods._

## `System.Reflection.MethodImplAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AggressiveInlining` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `CodeTypeMask` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `ForwardRef` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `IL` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `InternalCall` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `Managed` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `ManagedMask` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `MaxMethodImplVal` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `Native` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `NoInlining` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `NoOptimization` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `OPTIL` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `PreserveSig` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `Runtime` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `Synchronized` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `Unmanaged` | `System.Reflection.MethodImplAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.MethodImplAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MethodImplAttributes)
:System.Reflection.MethodImplAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MethodImplAttributes)
:System.Void CopyTo(System.Reflection.MethodImplAttributes[], System.Int32)
:System.Reflection.MethodImplAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MethodImplAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MethodImplAttributes)
:System.Void Insert(System.Int32, System.Reflection.MethodImplAttributes)
:System.Boolean Remove(System.Reflection.MethodImplAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MethodImplAttributes)
:System.Reflection.MethodImplAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MethodImplAttributes)
```

## `System.Reflection.MethodInfo`

**Methods**

```lua
:System.Delegate CreateDelegate(System.Type)
:System.Delegate CreateDelegate(System.Type, System.Object)
:System.Boolean Equals(System.Object)
:System.Type[] GetGenericArguments()
:System.Reflection.MethodInfo GetGenericMethodDefinition()
:System.Int32 GetHashCode()
:System.Reflection.MethodInfo MakeGenericMethod(System.Type[])
:System.Reflection.MemberTypes get_MemberType()
:System.Reflection.ParameterInfo get_ReturnParameter()
:System.Type get_ReturnType()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.MethodInfo, System.Reflection.MethodInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.MethodInfo, System.Reflection.MethodInfo)
```

## `System.Reflection.MethodInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.MethodInfo)
:System.Reflection.MethodInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.MethodInfo)
:System.Void CopyTo(System.Reflection.MethodInfo[], System.Int32)
:System.Reflection.MethodInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.MethodInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.MethodInfo)
:System.Void Insert(System.Int32, System.Reflection.MethodInfo)
:System.Boolean Remove(System.Reflection.MethodInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.MethodInfo)
:System.Reflection.MethodInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.MethodInfo)
```

## `System.Reflection.Missing`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `System.Reflection.Missing` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Reflection.Module`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultLookup` | `System.Reflection.BindingFlags` | yes | 16 |
| `FilterTypeName` | `System.Reflection.TypeFilter` | yes | 16 |
| `FilterTypeNameIgnoreCase` | `System.Reflection.TypeFilter` | yes | 24 |

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Type[] FindTypes(System.Reflection.TypeFilter, System.Object)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> GetCustomAttributesData()
:System.Reflection.FieldInfo GetField(System.String)
:System.Reflection.FieldInfo GetField(System.String, System.Reflection.BindingFlags)
:System.Reflection.FieldInfo[] GetFields()
:System.Reflection.FieldInfo[] GetFields(System.Reflection.BindingFlags)
:System.Int32 GetHashCode()
:System.Reflection.MethodInfo GetMethod(System.String)
:System.Reflection.MethodInfo GetMethod(System.String, System.Type[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethodImpl(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo[] GetMethods()
:System.Reflection.MethodInfo[] GetMethods(System.Reflection.BindingFlags)
:System.ModuleHandle GetModuleHandleImpl()
:System.Type GetType(System.String)
:System.Type GetType(System.String, System.Boolean)
:System.Type GetType(System.String, System.Boolean, System.Boolean)
:System.Type[] GetTypes()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Boolean IsResource()
:System.Reflection.FieldInfo ResolveField(System.Int32)
:System.Reflection.FieldInfo ResolveField(System.Int32, System.Type[], System.Type[])
:System.Reflection.MemberInfo ResolveMember(System.Int32)
:System.Reflection.MemberInfo ResolveMember(System.Int32, System.Type[], System.Type[])
:System.Reflection.MethodBase ResolveMethod(System.Int32)
:System.Reflection.MethodBase ResolveMethod(System.Int32, System.Type[], System.Type[])
:System.Byte[] ResolveSignature(System.Int32)
:System.String ResolveString(System.Int32)
:System.Type ResolveType(System.Int32)
:System.Type ResolveType(System.Int32, System.Type[], System.Type[])
:System.String ToString()
:System.Reflection.Assembly get_Assembly()
:System.Collections.Generic.IEnumerable`1<System.Reflection.CustomAttributeData> get_CustomAttributes()
:System.String get_FullyQualifiedName()
:System.Int32 get_MDStreamVersion()
:System.Int32 get_MetadataToken()
:System.ModuleHandle get_ModuleHandle()
:System.Guid get_ModuleVersionId()
:System.String get_Name()
:System.String get_ScopeName()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "FilterTypeNameIgnoreCaseImpl", ...)  -- System.Boolean FilterTypeNameIgnoreCaseImpl(System.Type, System.Object)
sdk.call_native_func(nil, type_def, "FilterTypeNameImpl", ...)  -- System.Boolean FilterTypeNameImpl(System.Type, System.Object)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.Module, System.Reflection.Module)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.Module, System.Reflection.Module)
```

## `System.Reflection.Module[]`

**Methods**

```lua
:System.Void Add(System.Reflection.Module)
:System.Reflection.Module Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.Module)
:System.Void CopyTo(System.Reflection.Module[], System.Int32)
:System.Reflection.Module Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.Module> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.Module)
:System.Void Insert(System.Int32, System.Reflection.Module)
:System.Boolean Remove(System.Reflection.Module)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.Module)
:System.Reflection.Module get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.Module)
```

## `System.Reflection.ParameterAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HasDefault` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `HasFieldMarshal` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `In` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Lcid` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `None` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Optional` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Out` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Reserved3` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Reserved4` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `Retval` | `System.Reflection.ParameterAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.ParameterAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.ParameterAttributes)
:System.Reflection.ParameterAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.ParameterAttributes)
:System.Void CopyTo(System.Reflection.ParameterAttributes[], System.Int32)
:System.Reflection.ParameterAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.ParameterAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.ParameterAttributes)
:System.Void Insert(System.Int32, System.Reflection.ParameterAttributes)
:System.Boolean Remove(System.Reflection.ParameterAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.ParameterAttributes)
:System.Reflection.ParameterAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.ParameterAttributes)
```

## `System.Reflection.ParameterInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MetadataToken_ParamDef` | `System.Int32` | yes | 16 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> GetCustomAttributesData()
:System.Type[] GetOptionalCustomModifiers()
:System.Type[] GetRequiredCustomModifiers()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.ParameterAttributes get_Attributes()
:System.Collections.Generic.IEnumerable`1<System.Reflection.CustomAttributeData> get_CustomAttributes()
:System.Object get_DefaultValue()
:System.Boolean get_HasDefaultValue()
:System.Boolean get_IsIn()
:System.Boolean get_IsLcid()
:System.Boolean get_IsOptional()
:System.Boolean get_IsOut()
:System.Boolean get_IsRetval()
:System.Reflection.MemberInfo get_Member()
:System.Int32 get_MetadataToken()
:System.String get_Name()
:System.Type get_ParameterType()
:System.Int32 get_Position()
:System.Object get_RawDefaultValue()
```

## `System.Reflection.ParameterInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.ParameterInfo)
:System.Reflection.ParameterInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.ParameterInfo)
:System.Void CopyTo(System.Reflection.ParameterInfo[], System.Int32)
:System.Reflection.ParameterInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.ParameterInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.ParameterInfo)
:System.Void Insert(System.Int32, System.Reflection.ParameterInfo)
:System.Boolean Remove(System.Reflection.ParameterInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.ParameterInfo)
:System.Reflection.ParameterInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.ParameterInfo)
```

## `System.Reflection.ParameterModifier`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_byRef` | `System.Boolean[]` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Boolean get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Boolean)
```

## `System.Reflection.ParameterModifier[]`

**Methods**

```lua
:System.Void Add(System.Reflection.ParameterModifier)
:System.Reflection.ParameterModifier Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.ParameterModifier)
:System.Void CopyTo(System.Reflection.ParameterModifier[], System.Int32)
:System.Reflection.ParameterModifier Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.ParameterModifier> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.ParameterModifier)
:System.Void Insert(System.Int32, System.Reflection.ParameterModifier)
:System.Boolean Remove(System.Reflection.ParameterModifier)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.ParameterModifier)
:System.Reflection.ParameterModifier get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.ParameterModifier)
```

## `System.Reflection.PropertyAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HasDefault` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `None` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `RTSpecialName` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `Reserved2` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `Reserved3` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `Reserved4` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `SpecialName` | `System.Reflection.PropertyAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.PropertyAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.PropertyAttributes)
:System.Reflection.PropertyAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.PropertyAttributes)
:System.Void CopyTo(System.Reflection.PropertyAttributes[], System.Int32)
:System.Reflection.PropertyAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.PropertyAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.PropertyAttributes)
:System.Void Insert(System.Int32, System.Reflection.PropertyAttributes)
:System.Boolean Remove(System.Reflection.PropertyAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.PropertyAttributes)
:System.Reflection.PropertyAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.PropertyAttributes)
```

## `System.Reflection.PropertyInfo`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Reflection.MethodInfo[] GetAccessors()
:System.Object GetConstantValue()
:System.Reflection.MethodInfo GetGetMethod()
:System.Int32 GetHashCode()
:System.Type[] GetOptionalCustomModifiers()
:System.Object GetRawConstantValue()
:System.Type[] GetRequiredCustomModifiers()
:System.Reflection.MethodInfo GetSetMethod()
:System.Object GetValue(System.Object)
:System.Object GetValue(System.Object, System.Object[])
:System.Void SetValue(System.Object, System.Object)
:System.Void SetValue(System.Object, System.Object, System.Object[])
:System.Boolean get_IsSpecialName()
:System.Reflection.MemberTypes get_MemberType()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Reflection.PropertyInfo, System.Reflection.PropertyInfo)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Reflection.PropertyInfo, System.Reflection.PropertyInfo)
```

## `System.Reflection.PropertyInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.PropertyInfo)
:System.Reflection.PropertyInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.PropertyInfo)
:System.Void CopyTo(System.Reflection.PropertyInfo[], System.Int32)
:System.Reflection.PropertyInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.PropertyInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.PropertyInfo)
:System.Void Insert(System.Int32, System.Reflection.PropertyInfo)
:System.Boolean Remove(System.Reflection.PropertyInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.PropertyInfo)
:System.Reflection.PropertyInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.PropertyInfo)
```

## `System.Reflection.RuntimeAssembly`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Type[] GetExportedTypes()
:System.Reflection.Module[] GetLoadedModules(System.Boolean)
:System.Reflection.Module GetModule(System.String)
:System.Reflection.Module[] GetModules(System.Boolean)
:System.Reflection.AssemblyName GetName(System.Boolean)
:System.Type GetType(System.String, System.Boolean, System.Boolean)
:System.Type[] GetTypes()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.String get_CodeBase()
:System.Reflection.MethodInfo get_EntryPoint()
:System.String get_FullName()
:System.String get_Location()
```

## `System.Reflection.RuntimeConstructorInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Reflection.MethodImplAttributes GetMethodImplementationFlags()
:System.Reflection.ParameterInfo[] GetParameters()
:System.Object Invoke(System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo)
:System.Object Invoke(System.Object, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.MethodAttributes get_Attributes()
:System.Type get_DeclaringType()
:System.RuntimeMethodHandle get_MethodHandle()
:System.String get_Name()
:System.Type get_ReflectedType()
```

## `System.Reflection.RuntimeEventInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Reflection.MethodInfo GetAddMethod(System.Boolean)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Reflection.MethodInfo[] GetOtherMethods(System.Boolean)
:System.Reflection.MethodInfo GetRemoveMethod(System.Boolean)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.EventAttributes get_Attributes()
:System.Type get_DeclaringType()
:System.String get_Name()
:System.Type get_ReflectedType()
```

## `System.Reflection.RuntimeFieldInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Object GetRawConstantValue()
:System.Object GetValue(System.Object)
:System.Object GetValueDirect(System.TypedReference)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Void SetValue(System.Object, System.Object, System.Reflection.BindingFlags, System.Reflection.Binder, System.Globalization.CultureInfo)
:System.Void SetValueDirect(System.TypedReference, System.Object)
:System.Reflection.FieldAttributes get_Attributes()
:System.Type get_DeclaringType()
:System.RuntimeFieldHandle get_FieldHandle()
:System.Type get_FieldType()
:System.String get_Name()
:System.Type get_ReflectedType()
```

## `System.Reflection.RuntimeMethodInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Reflection.MethodInfo GetBaseDefinition()
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Reflection.MethodImplAttributes GetMethodImplementationFlags()
:System.Reflection.ParameterInfo[] GetParameters()
:System.Object Invoke(System.Object, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.MethodAttributes get_Attributes()
:System.Type get_DeclaringType()
:System.RuntimeMethodHandle get_MethodHandle()
:System.String get_Name()
:System.Type get_ReflectedType()
:System.Reflection.ParameterInfo get_ReturnParameter()
:System.Type get_ReturnType()
:System.Reflection.ICustomAttributeProvider get_ReturnTypeCustomAttributes()
```

## `System.Reflection.RuntimeModule`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Reflection.FieldInfo[] GetFields(System.Reflection.BindingFlags)
:System.Reflection.MethodInfo[] GetMethods(System.Reflection.BindingFlags)
:System.Type GetType(System.String, System.Boolean)
:System.Type GetType(System.String, System.Boolean, System.Boolean)
:System.Type[] GetTypes()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.Assembly get_Assembly()
:System.String get_FullyQualifiedName()
:System.Int32 get_MDStreamVersion()
:System.Guid get_ModuleVersionId()
:System.String get_Name()
:System.String get_ScopeName()
```

## `System.Reflection.RuntimeParameterInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeMethodHandle` | `System.IntPtr` |  | 16 |
| `_position` | `System.Int32` |  | 24 |
| `_kind` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.String ToString()
:System.Reflection.ParameterAttributes get_Attributes()
:System.Object get_DefaultValue()
:System.Boolean get_HasDefaultValue()
:System.Reflection.MemberInfo get_Member()
:System.String get_Name()
:System.Type get_ParameterType()
:System.Int32 get_Position()
:System.Object get_RawDefaultValue()
```

## `System.Reflection.RuntimePropertyInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeHandle` | `System.IntPtr` |  | 16 |

**Methods**

```lua
:System.Reflection.MethodInfo[] GetAccessors(System.Boolean)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Reflection.MethodInfo GetGetMethod(System.Boolean)
:System.Reflection.ParameterInfo[] GetIndexParameters()
:System.Reflection.MethodInfo GetSetMethod(System.Boolean)
:System.Object GetValue(System.Object, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo)
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Void SetValue(System.Object, System.Object, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object[], System.Globalization.CultureInfo)
:System.String ToString()
:System.Reflection.PropertyAttributes get_Attributes()
:System.Boolean get_CanRead()
:System.Boolean get_CanWrite()
:System.Type get_DeclaringType()
:System.String get_Name()
:System.Type get_PropertyType()
:System.Type get_ReflectedType()
```

## `System.Reflection.RuntimeReflectionExtensions`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Everything` | `System.Reflection.BindingFlags` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetMethodInfo", ...)  -- System.Reflection.MethodInfo GetMethodInfo(System.Delegate)
sdk.call_native_func(nil, type_def, "GetRuntimeBaseDefinition", ...)  -- System.Reflection.MethodInfo GetRuntimeBaseDefinition(System.Reflection.MethodInfo)
sdk.call_native_func(nil, type_def, "GetRuntimeEvent", ...)  -- System.Reflection.EventInfo GetRuntimeEvent(System.Type, System.String)
sdk.call_native_func(nil, type_def, "GetRuntimeEvents", ...)  -- System.Collections.Generic.IEnumerable`1<System.Reflection.EventInfo> GetRuntimeEvents(System.Type)
sdk.call_native_func(nil, type_def, "GetRuntimeField", ...)  -- System.Reflection.FieldInfo GetRuntimeField(System.Type, System.String)
sdk.call_native_func(nil, type_def, "GetRuntimeFields", ...)  -- System.Collections.Generic.IEnumerable`1<System.Reflection.FieldInfo> GetRuntimeFields(System.Type)
sdk.call_native_func(nil, type_def, "GetRuntimeInterfaceMap", ...)  -- System.Reflection.InterfaceMapping GetRuntimeInterfaceMap(System.Reflection.TypeInfo, System.Type)
sdk.call_native_func(nil, type_def, "GetRuntimeMethod", ...)  -- System.Reflection.MethodInfo GetRuntimeMethod(System.Type, System.String, System.Type[])
sdk.call_native_func(nil, type_def, "GetRuntimeMethods", ...)  -- System.Collections.Generic.IEnumerable`1<System.Reflection.MethodInfo> GetRuntimeMethods(System.Type)
sdk.call_native_func(nil, type_def, "GetRuntimeProperties", ...)  -- System.Collections.Generic.IEnumerable`1<System.Reflection.PropertyInfo> GetRuntimeProperties(System.Type)
sdk.call_native_func(nil, type_def, "GetRuntimeProperty", ...)  -- System.Reflection.PropertyInfo GetRuntimeProperty(System.Type, System.String)
```

## `System.Reflection.TargetException`

**Methods**

```lua
:System.Void .ctor(System.String, System.Exception)
```

## `System.Reflection.TargetInvocationException`

**Methods**

```lua
:System.Void .ctor(System.String, System.Exception)
```

## `System.Reflection.TypeAttributes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Abstract` | `System.Reflection.TypeAttributes` | yes | 16 |
| `AnsiClass` | `System.Reflection.TypeAttributes` | yes | 16 |
| `AutoClass` | `System.Reflection.TypeAttributes` | yes | 16 |
| `AutoLayout` | `System.Reflection.TypeAttributes` | yes | 16 |
| `BeforeFieldInit` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Class` | `System.Reflection.TypeAttributes` | yes | 16 |
| `ClassSemanticsMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `CustomFormatClass` | `System.Reflection.TypeAttributes` | yes | 16 |
| `CustomFormatMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `ExplicitLayout` | `System.Reflection.TypeAttributes` | yes | 16 |
| `HasSecurity` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Import` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Interface` | `System.Reflection.TypeAttributes` | yes | 16 |
| `LayoutMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedAssembly` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedFamANDAssem` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedFamORAssem` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedFamily` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedPrivate` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NestedPublic` | `System.Reflection.TypeAttributes` | yes | 16 |
| `NotPublic` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Public` | `System.Reflection.TypeAttributes` | yes | 16 |
| `RTSpecialName` | `System.Reflection.TypeAttributes` | yes | 16 |
| `ReservedMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Sealed` | `System.Reflection.TypeAttributes` | yes | 16 |
| `SequentialLayout` | `System.Reflection.TypeAttributes` | yes | 16 |
| `Serializable` | `System.Reflection.TypeAttributes` | yes | 16 |
| `SpecialName` | `System.Reflection.TypeAttributes` | yes | 16 |
| `StringFormatMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `UnicodeClass` | `System.Reflection.TypeAttributes` | yes | 16 |
| `VisibilityMask` | `System.Reflection.TypeAttributes` | yes | 16 |
| `WindowsRuntime` | `System.Reflection.TypeAttributes` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Reflection.TypeAttributes[]`

**Methods**

```lua
:System.Void Add(System.Reflection.TypeAttributes)
:System.Reflection.TypeAttributes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.TypeAttributes)
:System.Void CopyTo(System.Reflection.TypeAttributes[], System.Int32)
:System.Reflection.TypeAttributes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.TypeAttributes> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.TypeAttributes)
:System.Void Insert(System.Int32, System.Reflection.TypeAttributes)
:System.Boolean Remove(System.Reflection.TypeAttributes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.TypeAttributes)
:System.Reflection.TypeAttributes get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.TypeAttributes)
```

## `System.Reflection.TypeDelegator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `typeImpl` | `System.Type` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Type)
:System.Reflection.TypeAttributes GetAttributeFlagsImpl()
:System.Reflection.ConstructorInfo GetConstructorImpl(System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.ConstructorInfo[] GetConstructors(System.Reflection.BindingFlags)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Type GetElementType()
:System.Reflection.EventInfo GetEvent(System.String, System.Reflection.BindingFlags)
:System.Reflection.EventInfo[] GetEvents()
:System.Reflection.EventInfo[] GetEvents(System.Reflection.BindingFlags)
:System.Reflection.FieldInfo GetField(System.String, System.Reflection.BindingFlags)
:System.Reflection.FieldInfo[] GetFields(System.Reflection.BindingFlags)
:System.Type GetInterface(System.String, System.Boolean)
:System.Reflection.InterfaceMapping GetInterfaceMap(System.Type)
:System.Type[] GetInterfaces()
:System.Reflection.MemberInfo[] GetMember(System.String, System.Reflection.MemberTypes, System.Reflection.BindingFlags)
:System.Reflection.MemberInfo[] GetMembers(System.Reflection.BindingFlags)
:System.Reflection.MethodInfo GetMethodImpl(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo[] GetMethods(System.Reflection.BindingFlags)
:System.Type GetNestedType(System.String, System.Reflection.BindingFlags)
:System.Type[] GetNestedTypes(System.Reflection.BindingFlags)
:System.Reflection.PropertyInfo[] GetProperties(System.Reflection.BindingFlags)
:System.Reflection.PropertyInfo GetPropertyImpl(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Type, System.Type[], System.Reflection.ParameterModifier[])
:System.Boolean HasElementTypeImpl()
:System.Object InvokeMember(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object, System.Object[], System.Reflection.ParameterModifier[], System.Globalization.CultureInfo, System.String[])
:System.Boolean IsArrayImpl()
:System.Boolean IsAssignableFrom(System.Reflection.TypeInfo)
:System.Boolean IsByRefImpl()
:System.Boolean IsCOMObjectImpl()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Boolean IsPointerImpl()
:System.Boolean IsPrimitiveImpl()
:System.Boolean IsValueTypeImpl()
:System.Reflection.Assembly get_Assembly()
:System.String get_AssemblyQualifiedName()
:System.Type get_BaseType()
:System.String get_FullName()
:System.Guid get_GUID()
:System.Boolean get_IsByRefLike()
:System.Boolean get_IsConstructedGenericType()
:System.Int32 get_MetadataToken()
:System.Reflection.Module get_Module()
:System.String get_Name()
:System.String get_Namespace()
:System.RuntimeTypeHandle get_TypeHandle()
:System.Type get_UnderlyingSystemType()
```

## `System.Reflection.TypeFilter`

**Methods**

```lua
:System.Boolean Invoke(System.Type, System.Object)
```

## `System.Reflection.TypeInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DeclaredOnlyLookup` | `System.Reflection.BindingFlags` | yes | 16 |

**Methods**

```lua
:System.Type AsType()
:System.Reflection.EventInfo GetDeclaredEvent(System.String)
:System.Reflection.FieldInfo GetDeclaredField(System.String)
:System.Reflection.MethodInfo GetDeclaredMethod(System.String)
:System.Collections.Generic.IEnumerable`1<System.Reflection.MethodInfo> GetDeclaredMethods(System.String)
:System.Reflection.TypeInfo GetDeclaredNestedType(System.String)
:System.Reflection.PropertyInfo GetDeclaredProperty(System.String)
:System.Boolean IsAssignableFrom(System.Reflection.TypeInfo)
:System.Reflection.TypeInfo System.Reflection.IReflectableType.GetTypeInfo()
:System.Collections.Generic.IEnumerable`1<System.Reflection.ConstructorInfo> get_DeclaredConstructors()
:System.Collections.Generic.IEnumerable`1<System.Reflection.EventInfo> get_DeclaredEvents()
:System.Collections.Generic.IEnumerable`1<System.Reflection.FieldInfo> get_DeclaredFields()
:System.Collections.Generic.IEnumerable`1<System.Reflection.MemberInfo> get_DeclaredMembers()
:System.Collections.Generic.IEnumerable`1<System.Reflection.MethodInfo> get_DeclaredMethods()
:System.Collections.Generic.IEnumerable`1<System.Reflection.TypeInfo> get_DeclaredNestedTypes()
:System.Collections.Generic.IEnumerable`1<System.Reflection.PropertyInfo> get_DeclaredProperties()
:System.Type[] get_GenericTypeParameters()
:System.Collections.Generic.IEnumerable`1<System.Type> get_ImplementedInterfaces()
```

## `System.Reflection.TypeInfo[]`

**Methods**

```lua
:System.Void Add(System.Reflection.TypeInfo)
:System.Reflection.TypeInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Reflection.TypeInfo)
:System.Void CopyTo(System.Reflection.TypeInfo[], System.Int32)
:System.Reflection.TypeInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Reflection.TypeInfo> GetEnumerator()
:System.Int32 IndexOf(System.Reflection.TypeInfo)
:System.Void Insert(System.Int32, System.Reflection.TypeInfo)
:System.Boolean Remove(System.Reflection.TypeInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Reflection.TypeInfo)
:System.Reflection.TypeInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Reflection.TypeInfo)
```

## `System.Runtime.CompilerServices.CallerArgumentExpressionAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ParameterName>k__BackingField` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_ParameterName()
```

## `System.Runtime.CompilerServices.CallerFilePathAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.CallerLineNumberAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.CallerMemberNameAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.CompilationRelaxations`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NoStringInterning` | `System.Runtime.CompilerServices.CompilationRelaxations` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Runtime.CompilerServices.CompilationRelaxationsAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Relaxations` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Runtime.CompilerServices.CompilationRelaxations)
:System.Int32 get_CompilationRelaxations()
```

## `System.Runtime.CompilerServices.CompilationRelaxations[]`

**Methods**

```lua
:System.Void Add(System.Runtime.CompilerServices.CompilationRelaxations)
:System.Runtime.CompilerServices.CompilationRelaxations Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Runtime.CompilerServices.CompilationRelaxations)
:System.Void CopyTo(System.Runtime.CompilerServices.CompilationRelaxations[], System.Int32)
:System.Runtime.CompilerServices.CompilationRelaxations Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Runtime.CompilerServices.CompilationRelaxations> GetEnumerator()
:System.Int32 IndexOf(System.Runtime.CompilerServices.CompilationRelaxations)
:System.Void Insert(System.Int32, System.Runtime.CompilerServices.CompilationRelaxations)
:System.Boolean Remove(System.Runtime.CompilerServices.CompilationRelaxations)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Runtime.CompilerServices.CompilationRelaxations)
:System.Runtime.CompilerServices.CompilationRelaxations get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Runtime.CompilerServices.CompilationRelaxations)
```

## `System.Runtime.CompilerServices.CompilerGeneratedAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.ExtensionAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.ITuple`

_No fields or methods._

## `System.Runtime.CompilerServices.IndexerNameAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.InternalsVisibleToAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.IsReadOnlyAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.IsVolatile`

_No fields or methods._

## `System.Runtime.CompilerServices.IteratorStateMachineAttribute`

**Methods**

```lua
:System.Void .ctor(System.Type)
```

## `System.Runtime.CompilerServices.MethodCodeType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IL` | `System.Runtime.CompilerServices.MethodCodeType` | yes | 16 |
| `Native` | `System.Runtime.CompilerServices.MethodCodeType` | yes | 16 |
| `OPTIL` | `System.Runtime.CompilerServices.MethodCodeType` | yes | 16 |
| `Runtime` | `System.Runtime.CompilerServices.MethodCodeType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Runtime.CompilerServices.MethodCodeType[]`

**Methods**

```lua
:System.Void Add(System.Runtime.CompilerServices.MethodCodeType)
:System.Runtime.CompilerServices.MethodCodeType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Runtime.CompilerServices.MethodCodeType)
:System.Void CopyTo(System.Runtime.CompilerServices.MethodCodeType[], System.Int32)
:System.Runtime.CompilerServices.MethodCodeType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Runtime.CompilerServices.MethodCodeType> GetEnumerator()
:System.Int32 IndexOf(System.Runtime.CompilerServices.MethodCodeType)
:System.Void Insert(System.Int32, System.Runtime.CompilerServices.MethodCodeType)
:System.Boolean Remove(System.Runtime.CompilerServices.MethodCodeType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Runtime.CompilerServices.MethodCodeType)
:System.Runtime.CompilerServices.MethodCodeType get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Runtime.CompilerServices.MethodCodeType)
```

## `System.Runtime.CompilerServices.MethodImplAttribute`

_No fields or methods._

## `System.Runtime.CompilerServices.MethodImplOptions`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AggressiveInlining` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `ForwardRef` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `InternalCall` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `NoInlining` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `NoOptimization` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `PreserveSig` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `Synchronized` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `Unmanaged` | `System.Runtime.CompilerServices.MethodImplOptions` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Runtime.CompilerServices.MethodImplOptions[]`

**Methods**

```lua
:System.Void Add(System.Runtime.CompilerServices.MethodImplOptions)
:System.Runtime.CompilerServices.MethodImplOptions Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Runtime.CompilerServices.MethodImplOptions)
:System.Void CopyTo(System.Runtime.CompilerServices.MethodImplOptions[], System.Int32)
:System.Runtime.CompilerServices.MethodImplOptions Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Runtime.CompilerServices.MethodImplOptions> GetEnumerator()
:System.Int32 IndexOf(System.Runtime.CompilerServices.MethodImplOptions)
:System.Void Insert(System.Int32, System.Runtime.CompilerServices.MethodImplOptions)
:System.Boolean Remove(System.Runtime.CompilerServices.MethodImplOptions)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Runtime.CompilerServices.MethodImplOptions)
:System.Runtime.CompilerServices.MethodImplOptions get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Runtime.CompilerServices.MethodImplOptions)
```

## `System.Runtime.CompilerServices.RuntimeCompatibilityAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mWrapNonExceptionThrows` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Boolean get_WrapNonExceptionThrows()
:System.Void set_WrapNonExceptionThrows(System.Boolean)
```

## `System.Runtime.CompilerServices.RuntimeHelpers`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetObjectValue", ...)  -- System.Object GetObjectValue(System.Object)
sdk.call_native_func(nil, type_def, "InitializeArray", ...)  -- System.Void InitializeArray(System.Array, System.RuntimeFieldHandle)
sdk.call_native_func(nil, type_def, "RunClassConstructor", ...)  -- System.Void RunClassConstructor(System.RuntimeTypeHandle)
```

## `System.Runtime.CompilerServices.StateMachineAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<StateMachineType>k__BackingField` | `System.Type` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Type)
:System.Type get_StateMachineType()
:System.Void set_StateMachineType(System.Type)
```

## `System.Runtime.CompilerServices.TupleElementNamesAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_transformNames` | `System.String[]` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String[])
:System.Collections.Generic.IList`1<System.String> get_TransformNames()
```

## `System.Runtime.InteropServices.CharSet`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Ansi` | `System.Runtime.InteropServices.CharSet` | yes | 16 |
| `Auto` | `System.Runtime.InteropServices.CharSet` | yes | 16 |
| `None` | `System.Runtime.InteropServices.CharSet` | yes | 16 |
| `Unicode` | `System.Runtime.InteropServices.CharSet` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Runtime.InteropServices.CharSet[]`

**Methods**

```lua
:System.Void Add(System.Runtime.InteropServices.CharSet)
:System.Runtime.InteropServices.CharSet Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Runtime.InteropServices.CharSet)
:System.Void CopyTo(System.Runtime.InteropServices.CharSet[], System.Int32)
:System.Runtime.InteropServices.CharSet Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Runtime.InteropServices.CharSet> GetEnumerator()
:System.Int32 IndexOf(System.Runtime.InteropServices.CharSet)
:System.Void Insert(System.Int32, System.Runtime.InteropServices.CharSet)
:System.Boolean Remove(System.Runtime.InteropServices.CharSet)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Runtime.InteropServices.CharSet)
:System.Runtime.InteropServices.CharSet get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Runtime.InteropServices.CharSet)
```

## `System.Runtime.InteropServices.ComVisibleAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Val` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Boolean)
:System.Boolean get_Value()
```

## `System.Runtime.InteropServices.FieldOffsetAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Value>k__BackingField` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Int32 get_Value()
:System.Void set_Value(System.Int32)
```

## `System.Runtime.InteropServices.GuidAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Val` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_Value()
```

## `System.Runtime.InteropServices.InAttribute`

_No fields or methods._

## `System.Runtime.InteropServices.LayoutKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Auto` | `System.Runtime.InteropServices.LayoutKind` | yes | 16 |
| `Explicit` | `System.Runtime.InteropServices.LayoutKind` | yes | 16 |
| `Sequential` | `System.Runtime.InteropServices.LayoutKind` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Runtime.InteropServices.LayoutKind[]`

**Methods**

```lua
:System.Void Add(System.Runtime.InteropServices.LayoutKind)
:System.Runtime.InteropServices.LayoutKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Runtime.InteropServices.LayoutKind)
:System.Void CopyTo(System.Runtime.InteropServices.LayoutKind[], System.Int32)
:System.Runtime.InteropServices.LayoutKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Runtime.InteropServices.LayoutKind> GetEnumerator()
:System.Int32 IndexOf(System.Runtime.InteropServices.LayoutKind)
:System.Void Insert(System.Int32, System.Runtime.InteropServices.LayoutKind)
:System.Boolean Remove(System.Runtime.InteropServices.LayoutKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Runtime.InteropServices.LayoutKind)
:System.Runtime.InteropServices.LayoutKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Runtime.InteropServices.LayoutKind)
```

## `System.Runtime.InteropServices.Marshal`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "SizeOf", ...)  -- System.Int32 SizeOf(System.Object)
sdk.call_native_func(nil, type_def, "SizeOf", ...)  -- System.Int32 SizeOf(System.Type)
```

## `System.Runtime.InteropServices.OutAttribute`

_No fields or methods._

## `System.Runtime.InteropServices.StructLayoutAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DEFAULT_PACKING_SIZE` | `System.Int32` | yes | 16 |
| `_Val` | `System.Runtime.InteropServices.LayoutKind` |  | 16 |
| `Pack` | `System.Int32` |  | 20 |
| `Size` | `System.Int32` |  | 24 |
| `CharSet` | `System.Runtime.InteropServices.CharSet` |  | 28 |

**Methods**

```lua
:System.Void .ctor(System.Runtime.InteropServices.LayoutKind)
:System.Void .ctor(System.Int16)
:System.Runtime.InteropServices.LayoutKind get_Value()
```

## `System.Runtime.Versioning.TargetFrameworkAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mFrameworkName` | `System.String` |  | 16 |
| `mFrameworkDisplayName` | `System.String` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.String get_FrameworkDisplayName()
:System.String get_FrameworkName()
:System.Void set_FrameworkDisplayName(System.String)
```

## `System.RuntimeArgumentHandle`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.IntPtr` |  | 16 |

## `System.RuntimeFieldHandle`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.IntPtr` |  | 16 |

## `System.RuntimeMethodHandle`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.IntPtr` |  | 16 |

## `System.RuntimeType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeTypeHandle` | `System.IntPtr` |  | 16 |
| `_kind` | `System.Int32` |  | 24 |
| `_number` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.String FormatTypeName(System.Boolean)
:System.Int32 GetArrayRank()
:System.Reflection.TypeAttributes GetAttributeFlagsImpl()
:System.Reflection.ConstructorInfo GetConstructorImpl(System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.ConstructorInfo[] GetConstructors(System.Reflection.BindingFlags)
:System.Object[] GetCustomAttributes(System.Boolean)
:System.Object[] GetCustomAttributes(System.Type, System.Boolean)
:System.Type GetElementType()
:System.String GetEnumName(System.Object)
:System.String[] GetEnumNames()
:System.Type GetEnumUnderlyingType()
:System.Array GetEnumValues()
:System.Reflection.EventInfo GetEvent(System.String, System.Reflection.BindingFlags)
:System.Reflection.EventInfo[] GetEvents(System.Reflection.BindingFlags)
:System.Reflection.FieldInfo GetField(System.String, System.Reflection.BindingFlags)
:System.Reflection.FieldInfo[] GetFields(System.Reflection.BindingFlags)
:System.Type[] GetGenericArguments()
:System.Type[] GetGenericParameterConstraints()
:System.Type GetGenericTypeDefinition()
:System.Type GetInterface(System.String, System.Boolean)
:System.Type[] GetInterfaces()
:System.Reflection.MemberInfo[] GetMember(System.String, System.Reflection.MemberTypes, System.Reflection.BindingFlags)
:System.Reflection.MemberInfo[] GetMembers(System.Reflection.BindingFlags)
:System.Reflection.MemberInfo[] GetMembersImpl(System.String, System.Reflection.MemberTypes, System.Reflection.BindingFlags, System.Type)
:System.Reflection.MethodInfo GetMethodImpl(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo[] GetMethods(System.Reflection.BindingFlags)
:System.Type GetNestedType(System.String, System.Reflection.BindingFlags)
:System.Type[] GetNestedTypes(System.Reflection.BindingFlags)
:System.Reflection.PropertyInfo[] GetProperties(System.Reflection.BindingFlags)
:System.Reflection.PropertyInfo GetPropertyImpl(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Type, System.Type[], System.Reflection.ParameterModifier[])
:System.Boolean HasElementTypeImpl()
:System.Object InvokeMember(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object, System.Object[], System.Reflection.ParameterModifier[], System.Globalization.CultureInfo, System.String[])
:System.Boolean IsArrayImpl()
:System.Boolean IsByRefImpl()
:System.Boolean IsCOMObjectImpl()
:System.Boolean IsDefined(System.Type, System.Boolean)
:System.Boolean IsEnumDefined(System.Object)
:System.Boolean IsInstanceOfType(System.Object)
:System.Boolean IsPointerImpl()
:System.Boolean IsPrimitiveImpl()
:System.Boolean IsSubclassOf(System.Type)
:System.Boolean IsValueTypeImpl()
:System.Type MakeGenericType(System.Type[])
:System.String ToString()
:System.Reflection.Assembly get_Assembly()
:System.String get_AssemblyQualifiedName()
:System.Type get_BaseType()
:System.Boolean get_ContainsGenericParameters()
:System.Type get_DeclaringType()
:System.String get_FullName()
:System.Guid get_GUID()
:System.Reflection.GenericParameterAttributes get_GenericParameterAttributes()
:System.Int32 get_GenericParameterPosition()
:System.Boolean get_IsConstructedGenericType()
:System.Boolean get_IsGenericParameter()
:System.Boolean get_IsGenericType()
:System.Boolean get_IsGenericTypeDefinition()
:System.Reflection.Module get_Module()
:System.String get_Name()
:System.String get_Namespace()
:System.RuntimeTypeHandle get_TypeHandle()
:System.Type get_UnderlyingSystemType()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "CreateInstanceForAnotherGenericParameter", ...)  -- System.Object CreateInstanceForAnotherGenericParameter(System.Type, System.Type)
```

## `System.RuntimeTypeHandle`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.IntPtr` |  | 16 |

## `System.SByte`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.SByte` | yes | 16 |
| `MinValue` | `System.SByte` | yes | 16 |
| `mValue` | `System.SByte` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.SByte)
:System.Boolean Equals(System.SByte)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.SByte Parse(System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.SByte Parse(System.String, System.NumberStyles)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.SByte Parse(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.SByte Parse(System.String, System.NumberStyles, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.SByte)
```

## `System.SByte[]`

**Methods**

```lua
:System.Void Add(System.SByte)
:System.SByte Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.SByte)
:System.Void CopyTo(System.SByte[], System.Int32)
:System.SByte Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.SByte> GetEnumerator()
:System.Int32 IndexOf(System.SByte)
:System.Void Insert(System.Int32, System.SByte)
:System.Boolean Remove(System.SByte)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.SByte)
:System.SByte get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.SByte)
```

## `System.STAThreadAttribute`

_No fields or methods._

## `System.Security.Permissions.SecurityAction`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Assert` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `Demand` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `Deny` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `InheritanceDemand` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `LinkDemand` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `PermitOnly` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `RequestMinimum` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `RequestOptional` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `RequestRefuse` | `System.Security.Permissions.SecurityAction` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Security.Permissions.SecurityAction[]`

**Methods**

```lua
:System.Void Add(System.Security.Permissions.SecurityAction)
:System.Security.Permissions.SecurityAction Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Security.Permissions.SecurityAction)
:System.Void CopyTo(System.Security.Permissions.SecurityAction[], System.Int32)
:System.Security.Permissions.SecurityAction Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Security.Permissions.SecurityAction> GetEnumerator()
:System.Int32 IndexOf(System.Security.Permissions.SecurityAction)
:System.Void Insert(System.Int32, System.Security.Permissions.SecurityAction)
:System.Boolean Remove(System.Security.Permissions.SecurityAction)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Security.Permissions.SecurityAction)
:System.Security.Permissions.SecurityAction get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Security.Permissions.SecurityAction)
```

## `System.Security.Permissions.SecurityPermissionAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SkipVerification>k__BackingField` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Boolean get_SkipVerification()
:System.Void set_SkipVerification(System.Boolean)
```

## `System.Security.UnverifiableCodeAttribute`

_No fields or methods._

## `System.SerializableAttribute`

_No fields or methods._

## `System.Single`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Epsilon` | `System.Single` | yes | 16 |
| `MaxValue` | `System.Single` | yes | 16 |
| `MinValue` | `System.Single` | yes | 16 |
| `NaN` | `System.Single` | yes | 16 |
| `NegativeInfinity` | `System.Single` | yes | 16 |
| `PositiveInfinity` | `System.Single` | yes | 16 |
| `mValue` | `System.Single` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Single)
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Single)
:System.Boolean Equals(System.Single)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "IsInfinity", ...)  -- System.Boolean IsInfinity(System.Single)
sdk.call_native_func(nil, type_def, "IsNaN", ...)  -- System.Boolean IsNaN(System.Single)
sdk.call_native_func(nil, type_def, "IsNegativeInfinity", ...)  -- System.Boolean IsNegativeInfinity(System.Single)
sdk.call_native_func(nil, type_def, "IsPositiveInfinity", ...)  -- System.Boolean IsPositiveInfinity(System.Single)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.Single Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.Single)
```

## `System.Single[,]`

**Methods**

```lua
:System.Single Address(System.Int32, System.Int32)
:System.Single Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Single)
```

## `System.Single[]`

**Methods**

```lua
:System.Void Add(System.Single)
:System.Single Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Single)
:System.Void CopyTo(System.Single[], System.Int32)
:System.Single Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Single> GetEnumerator()
:System.Int32 IndexOf(System.Single)
:System.Void Insert(System.Int32, System.Single)
:System.Boolean Remove(System.Single)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Single)
:System.Single get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Single)
```

## `System.Single[][]`

**Methods**

```lua
:System.Void Add(System.Single[])
:System.Single[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Single[])
:System.Void CopyTo(System.Single[][], System.Int32)
:System.Single[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Single[]> GetEnumerator()
:System.Int32 IndexOf(System.Single[])
:System.Void Insert(System.Int32, System.Single[])
:System.Boolean Remove(System.Single[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Single[])
:System.Single[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Single[])
```

## `System.StackOverflowException`

_No fields or methods._

## `System.String`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Empty` | `System.String` | yes | 16 |

**Methods**

```lua
:System.Void .ctor(System.Char[])
:System.Void .ctor(System.Char, System.Int32)
:System.Void .ctor(System.Char[], System.Int32, System.Int32)
:System.Object Clone()
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.String)
:System.Boolean Contains(System.String)
:System.Void CopyTo(System.Int32, System.Char[], System.Int32, System.Int32)
:System.Boolean EndsWith(System.String)
:System.Boolean EndsWith(System.String, System.StringComparison)
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.String)
:System.Boolean Equals(System.String, System.StringComparison)
:System.CharEnumerator GetEnumerator()
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Int32 IndexOf(System.Char)
:System.Int32 IndexOf(System.String)
:System.Int32 IndexOf(System.String, System.StringComparison)
:System.Int32 IndexOf(System.Char, System.Int32)
:System.Int32 IndexOf(System.String, System.Int32)
:System.Int32 IndexOf(System.String, System.Int32, System.StringComparison)
:System.Int32 IndexOf(System.Char, System.Int32, System.Int32)
:System.Int32 IndexOf(System.String, System.Int32, System.Int32)
:System.Int32 IndexOf(System.String, System.Int32, System.Int32, System.StringComparison)
:System.Int32 IndexOfAny(System.Char[])
:System.Int32 IndexOfAny(System.Char[], System.Int32)
:System.Int32 IndexOfAny(System.Char[], System.Int32, System.Int32)
:System.String Insert(System.Int32, System.String)
:System.Boolean IsNormalized()
:System.Int32 LastIndexOf(System.Char)
:System.Int32 LastIndexOf(System.String)
:System.Int32 LastIndexOf(System.String, System.StringComparison)
:System.Int32 LastIndexOf(System.Char, System.Int32)
:System.Int32 LastIndexOf(System.String, System.Int32)
:System.Int32 LastIndexOf(System.String, System.Int32, System.StringComparison)
:System.Int32 LastIndexOf(System.Char, System.Int32, System.Int32)
:System.Int32 LastIndexOf(System.String, System.Int32, System.Int32)
:System.Int32 LastIndexOf(System.String, System.Int32, System.Int32, System.StringComparison)
:System.Int32 LastIndexOfAny(System.Char[])
:System.Int32 LastIndexOfAny(System.Char[], System.Int32)
:System.Int32 LastIndexOfAny(System.Char[], System.Int32, System.Int32)
:System.String PadLeft(System.Int32)
:System.String PadLeft(System.Int32, System.Char)
:System.String PadRight(System.Int32)
:System.String PadRight(System.Int32, System.Char)
:System.String Remove(System.Int32)
:System.String Remove(System.Int32, System.Int32)
:System.String Replace(System.Char, System.Char)
:System.String Replace(System.String, System.String)
:System.String[] Split(System.Char[])
:System.String[] Split(System.Char[], System.Int32)
:System.String[] Split(System.Char[], System.StringSplitOptions)
:System.String[] Split(System.Char[], System.Int32, System.StringSplitOptions)
:System.String[] Split(System.String[], System.StringSplitOptions)
:System.String[] Split(System.String[], System.Int32, System.StringSplitOptions)
:System.String[] SplitChar(System.Char[], System.Int32, System.StringSplitOptions)
:System.String[] SplitString(System.String[], System.Int32, System.StringSplitOptions)
:System.Boolean StartsWith(System.String)
:System.Boolean StartsWith(System.String, System.StringComparison)
:System.String Substring(System.Int32)
:System.String Substring(System.Int32, System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Char> System.Collections.Generic.IEnumerable<System.Char>.GetEnumerator()
:System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.Char[] ToCharArray()
:System.Char[] ToCharArray(System.Int32, System.Int32)
:System.String ToLower()
:System.String ToLowerInvariant()
:System.String ToString()
:System.String ToString(System.IFormatProvider)
:System.String ToUpper()
:System.String ToUpperInvariant()
:System.String Trim()
:System.String Trim(System.Char[])
:System.String TrimEnd()
:System.String TrimEnd(System.Char[])
:System.String TrimStart()
:System.String TrimStart(System.Char[])
:System.TypeCode getTypeCode()
:System.Char get_Chars(System.Int32)
:System.Char get_Item(System.Int32)
:System.Int32 get_Length()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.String)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.String, System.StringComparison)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32, System.Boolean)
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32, System.StringComparison)
sdk.call_native_func(nil, type_def, "CompareOrdinal", ...)  -- System.Int32 CompareOrdinal(System.String, System.String)
sdk.call_native_func(nil, type_def, "CompareOrdinal", ...)  -- System.Int32 CompareOrdinal(System.String, System.Int32, System.String, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.Object)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.String[])
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.Object[])
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.Object, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.String, System.String)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.String, System.String, System.String)
sdk.call_native_func(nil, type_def, "Concat", ...)  -- System.String Concat(System.String, System.String, System.String, System.String)
sdk.call_native_func(nil, type_def, "Copy", ...)  -- System.String Copy(System.String)
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.String, System.String)
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.String, System.String, System.StringComparison)
sdk.call_native_func(nil, type_def, "Format", ...)  -- System.String Format(System.String, System.Object)
sdk.call_native_func(nil, type_def, "Format", ...)  -- System.String Format(System.String, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Format", ...)  -- System.String Format(System.String, System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Format", ...)  -- System.String Format(System.IFormatProvider, System.String, System.Object[])
sdk.call_native_func(nil, type_def, "Format", ...)  -- System.String Format(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "Intern", ...)  -- System.String Intern(System.String)
sdk.call_native_func(nil, type_def, "IsInterned", ...)  -- System.String IsInterned(System.String)
sdk.call_native_func(nil, type_def, "IsNullOrEmpty", ...)  -- System.Boolean IsNullOrEmpty(System.String)
sdk.call_native_func(nil, type_def, "IsNullOrWhiteSpace", ...)  -- System.Boolean IsNullOrWhiteSpace(System.String)
sdk.call_native_func(nil, type_def, "Join", ...)  -- System.String Join(System.String, System.String[])
sdk.call_native_func(nil, type_def, "Join", ...)  -- System.String Join(System.String, System.String[], System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Join", ...)  -- System.String Join(System.String, System.Collections.Generic.IEnumerable`1<System.String>)
sdk.call_native_func(nil, type_def, "Join", ...)  -- System.String Join(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.String, System.String)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.String, System.String)
```

## `System.StringComparison`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CurrentCulture` | `System.StringComparison` | yes | 16 |
| `CurrentCultureIgnoreCase` | `System.StringComparison` | yes | 16 |
| `InvariantCulture` | `System.StringComparison` | yes | 16 |
| `InvariantCultureIgnoreCase` | `System.StringComparison` | yes | 16 |
| `Ordinal` | `System.StringComparison` | yes | 16 |
| `OrdinalIgnoreCase` | `System.StringComparison` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.StringComparison[]`

**Methods**

```lua
:System.Void Add(System.StringComparison)
:System.StringComparison Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.StringComparison)
:System.Void CopyTo(System.StringComparison[], System.Int32)
:System.StringComparison Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.StringComparison> GetEnumerator()
:System.Int32 IndexOf(System.StringComparison)
:System.Void Insert(System.Int32, System.StringComparison)
:System.Boolean Remove(System.StringComparison)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.StringComparison)
:System.StringComparison get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.StringComparison)
```

## `System.StringSplitOptions`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `None` | `System.StringSplitOptions` | yes | 16 |
| `RemoveEmptyEntries` | `System.StringSplitOptions` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.StringSplitOptions[]`

**Methods**

```lua
:System.Void Add(System.StringSplitOptions)
:System.StringSplitOptions Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.StringSplitOptions)
:System.Void CopyTo(System.StringSplitOptions[], System.Int32)
:System.StringSplitOptions Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.StringSplitOptions> GetEnumerator()
:System.Int32 IndexOf(System.StringSplitOptions)
:System.Void Insert(System.Int32, System.StringSplitOptions)
:System.Boolean Remove(System.StringSplitOptions)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.StringSplitOptions)
:System.StringSplitOptions get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.StringSplitOptions)
```

## `System.String[]`

**Methods**

```lua
:System.Void Add(System.String)
:System.String Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.String)
:System.Void CopyTo(System.String[], System.Int32)
:System.String Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.String> GetEnumerator()
:System.Int32 IndexOf(System.String)
:System.Void Insert(System.Int32, System.String)
:System.Boolean Remove(System.String)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.String)
:System.String get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.String)
```

## `System.String[][]`

**Methods**

```lua
:System.Void Add(System.String[])
:System.String[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.String[])
:System.Void CopyTo(System.String[][], System.Int32)
:System.String[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.String[]> GetEnumerator()
:System.Int32 IndexOf(System.String[])
:System.Void Insert(System.Int32, System.String[])
:System.Boolean Remove(System.String[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.String[])
:System.String[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.String[])
```

## `System.SystemException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Text.ASCIIEncoding`

**Methods**

```lua
:System.Int32 GetByteCount(System.Char[], System.Int32, System.Int32)
:System.Int32 GetBytes(System.Char[], System.Int32, System.Int32, System.Byte[], System.Int32)
:System.Int32 GetCharCount(System.Byte[], System.Int32, System.Int32)
:System.Int32 GetChars(System.Byte[], System.Int32, System.Int32, System.Char[], System.Int32)
:System.Int32 GetMaxByteCount(System.Int32)
:System.Int32 GetMaxCharCount(System.Int32)
:System.String get_BodyName()
:System.Int32 get_CodePage()
:System.String get_EncodingName()
:System.String get_HeaderName()
:System.String get_WebName()
:System.Int32 get_WindowsCodePage()
```

## `System.Text.Encoding`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `defaultEncoding` | `System.Text.Encoding` | yes | 16 |
| `unicodeEncoding` | `System.Text.Encoding` | yes | 24 |
| `bigEndianUnicode` | `System.Text.Encoding` | yes | 32 |
| `utf7Encoding` | `System.Text.Encoding` | yes | 40 |
| `utf8Encoding` | `System.Text.Encoding` | yes | 48 |
| `utf32Encoding` | `System.Text.Encoding` | yes | 56 |
| `mASCIIEncoding` | `System.Text.Encoding` | yes | 64 |
| `latin1Encoding` | `System.Text.Encoding` | yes | 72 |

**Methods**

```lua
:System.Object Clone()
:System.Boolean Equals(System.Object)
:System.Int32 GetByteCount(System.Char[])
:System.Int32 GetByteCount(System.String)
:System.Byte[] GetBytes(System.Char[])
:System.Byte[] GetBytes(System.Char[], System.Int32, System.Int32)
:System.Byte[] GetBytes(System.String)
:System.Int32 GetBytes(System.String, System.Int32, System.Int32, System.Byte[], System.Int32)
:System.Int32 GetCharCount(System.Byte[])
:System.Char[] GetChars(System.Byte[])
:System.Char[] GetChars(System.Byte[], System.Int32, System.Int32)
:System.Void GetDataItem()
:System.Int32 GetHashCode()
:System.Byte[] GetPreamble()
:System.String GetString(System.Byte[])
:System.String GetString(System.Byte[], System.Int32, System.Int32)
:System.Boolean IsAlwaysNormalized()
:System.Boolean IsAlwaysNormalized(System.Text.NormalizationForm)
:System.String get_BodyName()
:System.String get_EncodingName()
:System.String get_HeaderName()
:System.String get_WebName()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Convert", ...)  -- System.Byte[] Convert(System.Text.Encoding, System.Text.Encoding, System.Byte[])
sdk.call_native_func(nil, type_def, "Convert", ...)  -- System.Byte[] Convert(System.Text.Encoding, System.Text.Encoding, System.Byte[], System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "GetEncoding", ...)  -- System.Text.Encoding GetEncoding(System.Int32)
sdk.call_native_func(nil, type_def, "GetEncoding", ...)  -- System.Text.Encoding GetEncoding(System.String)
sdk.call_native_func(nil, type_def, "GetEncodings", ...)  -- System.Text.EncodingInfo[] GetEncodings()
sdk.call_native_func(nil, type_def, "get_ASCII", ...)  -- System.Text.Encoding get_ASCII()
sdk.call_native_func(nil, type_def, "get_Default", ...)  -- System.Text.Encoding get_Default()
sdk.call_native_func(nil, type_def, "get_UTF8", ...)  -- System.Text.Encoding get_UTF8()
sdk.call_native_func(nil, type_def, "get_Unicode", ...)  -- System.Text.Encoding get_Unicode()
```

## `System.Text.EncodingInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mCodePage` | `System.Int32` |  | 16 |
| `mEncodingName` | `System.String` |  | 24 |
| `mDisplayName` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.String, System.String)
:System.Boolean Equals(System.Object)
:System.Text.Encoding GetEncoding()
:System.Int32 GetHashCode()
:System.Int32 get_CodePage()
:System.String get_DisplayName()
:System.String get_Name()
```

## `System.Text.EncodingInfo[]`

**Methods**

```lua
:System.Void Add(System.Text.EncodingInfo)
:System.Text.EncodingInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Text.EncodingInfo)
:System.Void CopyTo(System.Text.EncodingInfo[], System.Int32)
:System.Text.EncodingInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Text.EncodingInfo> GetEnumerator()
:System.Int32 IndexOf(System.Text.EncodingInfo)
:System.Void Insert(System.Int32, System.Text.EncodingInfo)
:System.Boolean Remove(System.Text.EncodingInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Text.EncodingInfo)
:System.Text.EncodingInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Text.EncodingInfo)
```

## `System.Text.NormalizationForm`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FormC` | `System.Text.NormalizationForm` | yes | 16 |
| `FormD` | `System.Text.NormalizationForm` | yes | 16 |
| `FormKC` | `System.Text.NormalizationForm` | yes | 16 |
| `FormKD` | `System.Text.NormalizationForm` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Text.NormalizationForm[]`

**Methods**

```lua
:System.Void Add(System.Text.NormalizationForm)
:System.Text.NormalizationForm Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Text.NormalizationForm)
:System.Void CopyTo(System.Text.NormalizationForm[], System.Int32)
:System.Text.NormalizationForm Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Text.NormalizationForm> GetEnumerator()
:System.Int32 IndexOf(System.Text.NormalizationForm)
:System.Void Insert(System.Int32, System.Text.NormalizationForm)
:System.Boolean Remove(System.Text.NormalizationForm)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Text.NormalizationForm)
:System.Text.NormalizationForm get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Text.NormalizationForm)
```

## `System.Text.StringBuilder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultCapacity` | `System.Int32` | yes | 16 |
| `MaxChunkSize` | `System.Int32` | yes | 16 |
| `m_ChunkChars` | `System.Char[]` |  | 16 |
| `m_ChunkPrevious` | `System.Text.StringBuilder` |  | 24 |
| `m_ChunkLength` | `System.Int32` |  | 32 |
| `m_ChunkOffset` | `System.Int32` |  | 36 |
| `m_MaxCapacity` | `System.Int32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Int32)
:System.Void .ctor(System.String, System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32)
:System.Void .ctor(System.Text.StringBuilder)
:System.Void .ctor(System.Int32, System.Int32, System.Text.StringBuilder)
:System.Text.StringBuilder Append(System.Char, System.Int32)
:System.Text.StringBuilder Append(System.Char[], System.Int32, System.Int32)
:System.Text.StringBuilder Append(System.String)
:System.Text.StringBuilder Append(System.String, System.Int32, System.Int32)
:System.Text.StringBuilder Append(System.Boolean)
:System.Text.StringBuilder Append(System.SByte)
:System.Text.StringBuilder Append(System.Byte)
:System.Text.StringBuilder Append(System.Char)
:System.Text.StringBuilder Append(System.Int16)
:System.Text.StringBuilder Append(System.Int32)
:System.Text.StringBuilder Append(System.Int64)
:System.Text.StringBuilder Append(System.Single)
:System.Text.StringBuilder Append(System.Double)
:System.Text.StringBuilder Append(System.Decimal)
:System.Text.StringBuilder Append(System.UInt16)
:System.Text.StringBuilder Append(System.UInt32)
:System.Text.StringBuilder Append(System.UInt64)
:System.Text.StringBuilder Append(System.Object)
:System.Text.StringBuilder Append(System.Char[])
:System.Text.StringBuilder AppendFormat(System.String, System.Object)
:System.Text.StringBuilder AppendFormat(System.String, System.Object, System.Object)
:System.Text.StringBuilder AppendFormat(System.String, System.Object, System.Object, System.Object)
:System.Text.StringBuilder AppendFormat(System.String, System.Object[])
:System.Text.StringBuilder AppendFormat(System.IFormatProvider, System.String, System.Object[])
:System.Text.StringBuilder AppendLine()
:System.Text.StringBuilder AppendLine(System.String)
:System.Text.StringBuilder Clear()
:System.Void CopyTo(System.Int32, System.Char[], System.Int32, System.Int32)
:System.Int32 EnsureCapacity(System.Int32)
:System.Boolean Equals(System.Text.StringBuilder)
:System.Void ExpandByABlock(System.Int32)
:System.Text.StringBuilder FindChunkForByte(System.Int32)
:System.Text.StringBuilder FindChunkForIndex(System.Int32)
:System.Text.StringBuilder Insert(System.Int32, System.String, System.Int32)
:System.Text.StringBuilder Insert(System.Int32, System.String)
:System.Text.StringBuilder Insert(System.Int32, System.Boolean)
:System.Text.StringBuilder Insert(System.Int32, System.SByte)
:System.Text.StringBuilder Insert(System.Int32, System.Byte)
:System.Text.StringBuilder Insert(System.Int32, System.Int16)
:System.Text.StringBuilder Insert(System.Int32, System.Char)
:System.Text.StringBuilder Insert(System.Int32, System.Char[])
:System.Text.StringBuilder Insert(System.Int32, System.Char[], System.Int32, System.Int32)
:System.Text.StringBuilder Insert(System.Int32, System.Int32)
:System.Text.StringBuilder Insert(System.Int32, System.Int64)
:System.Text.StringBuilder Insert(System.Int32, System.Single)
:System.Text.StringBuilder Insert(System.Int32, System.Double)
:System.Text.StringBuilder Insert(System.Int32, System.Decimal)
:System.Text.StringBuilder Insert(System.Int32, System.UInt16)
:System.Text.StringBuilder Insert(System.Int32, System.UInt32)
:System.Text.StringBuilder Insert(System.Int32, System.UInt64)
:System.Text.StringBuilder Insert(System.Int32, System.Object)
:System.Void MakeRoom(System.Int32, System.Int32, System.Text.StringBuilder, System.Int32, System.Boolean)
:System.Text.StringBuilder Next(System.Text.StringBuilder)
:System.Text.StringBuilder Real_Append(System.Char[], System.Int32, System.Int32)
:System.Void Real_Insert(System.Int32, System.Char[], System.Int32, System.Int32)
:System.Text.StringBuilder Remove(System.Int32, System.Int32)
:System.Void Remove(System.Int32, System.Int32, System.Text.StringBuilder, System.Int32)
:System.Text.StringBuilder Replace(System.String, System.String)
:System.Text.StringBuilder Replace(System.String, System.String, System.Int32, System.Int32)
:System.Text.StringBuilder Replace(System.Char, System.Char)
:System.Text.StringBuilder Replace(System.Char, System.Char, System.Int32, System.Int32)
:System.Void ReplaceAllInChunk(System.Int32[], System.Int32, System.Text.StringBuilder, System.Int32, System.String)
:System.Void ReplaceInPlaceAtChunk(System.Text.StringBuilder, System.Int32, System.Char[], System.Int32, System.Int32)
:System.Boolean StartsWith(System.Text.StringBuilder, System.Int32, System.Int32, System.String)
:System.String ToString()
:System.String ToString(System.Int32, System.Int32)
:System.Int32 get_Capacity()
:System.Char get_Item(System.Int32)
:System.Int32 get_Length()
:System.Int32 get_MaxCapacity()
:System.Void set_Capacity(System.Int32)
:System.Void set_Item(System.Int32, System.Char)
:System.Void set_Length(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "FormatError", ...)  -- System.Void FormatError()
sdk.call_native_func(nil, type_def, "InternalCopy", ...)  -- System.Void InternalCopy(System.Char[], System.Int32, System.Char[], System.Int32, System.Int32)
```

## `System.Text.UTF8Encoding`

**Methods**

```lua
:System.Int32 GetByteCount(System.Char[], System.Int32, System.Int32)
:System.Int32 GetBytes(System.Char[], System.Int32, System.Int32, System.Byte[], System.Int32)
:System.Int32 GetCharCount(System.Byte[], System.Int32, System.Int32)
:System.Int32 GetChars(System.Byte[], System.Int32, System.Int32, System.Char[], System.Int32)
:System.Int32 GetMaxByteCount(System.Int32)
:System.Int32 GetMaxCharCount(System.Int32)
:System.Byte[] GetPreamble()
:System.String get_BodyName()
:System.Int32 get_CodePage()
:System.String get_EncodingName()
:System.String get_HeaderName()
:System.String get_WebName()
:System.Int32 get_WindowsCodePage()
```

## `System.Text.UnicodeEncoding`

**Methods**

```lua
:System.Int32 GetByteCount(System.Char[], System.Int32, System.Int32)
:System.Int32 GetBytes(System.Char[], System.Int32, System.Int32, System.Byte[], System.Int32)
:System.Int32 GetCharCount(System.Byte[], System.Int32, System.Int32)
:System.Int32 GetChars(System.Byte[], System.Int32, System.Int32, System.Char[], System.Int32)
:System.Int32 GetMaxByteCount(System.Int32)
:System.Int32 GetMaxCharCount(System.Int32)
:System.String get_BodyName()
:System.Int32 get_CodePage()
:System.String get_EncodingName()
:System.String get_HeaderName()
:System.String get_WebName()
:System.Int32 get_WindowsCodePage()
```

## `System.Threading.ApartmentState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MTA` | `System.Threading.ApartmentState` | yes | 16 |
| `STA` | `System.Threading.ApartmentState` | yes | 16 |
| `Unknown` | `System.Threading.ApartmentState` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Threading.ApartmentState[]`

**Methods**

```lua
:System.Void Add(System.Threading.ApartmentState)
:System.Threading.ApartmentState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Threading.ApartmentState)
:System.Void CopyTo(System.Threading.ApartmentState[], System.Int32)
:System.Threading.ApartmentState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Threading.ApartmentState> GetEnumerator()
:System.Int32 IndexOf(System.Threading.ApartmentState)
:System.Void Insert(System.Int32, System.Threading.ApartmentState)
:System.Boolean Remove(System.Threading.ApartmentState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Threading.ApartmentState)
:System.Threading.ApartmentState get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Threading.ApartmentState)
```

## `System.Threading.Interlocked`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Add", ...)  -- System.Int32 Add(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Add", ...)  -- System.Int64 Add(System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.Double CompareExchange(System.Double, System.Double, System.Double)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.Int32 CompareExchange(System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.Int64 CompareExchange(System.Int64, System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.IntPtr CompareExchange(System.IntPtr, System.IntPtr, System.IntPtr)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.Object CompareExchange(System.Object, System.Object, System.Object)
sdk.call_native_func(nil, type_def, "CompareExchange", ...)  -- System.Single CompareExchange(System.Single, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "Decrement", ...)  -- System.Int32 Decrement(System.Int32)
sdk.call_native_func(nil, type_def, "Decrement", ...)  -- System.Int64 Decrement(System.Int64)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.Double Exchange(System.Double, System.Double)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.Int32 Exchange(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.Int64 Exchange(System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.IntPtr Exchange(System.IntPtr, System.IntPtr)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.Object Exchange(System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Exchange", ...)  -- System.Single Exchange(System.Single, System.Single)
sdk.call_native_func(nil, type_def, "Increment", ...)  -- System.Int32 Increment(System.Int32)
sdk.call_native_func(nil, type_def, "Increment", ...)  -- System.Int64 Increment(System.Int64)
sdk.call_native_func(nil, type_def, "MemoryBarrier", ...)  -- System.Void MemoryBarrier()
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Int64 Read(System.Int64)
```

## `System.Threading.Monitor`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Enter", ...)  -- System.Void Enter(System.Object)
sdk.call_native_func(nil, type_def, "Enter", ...)  -- System.Void Enter(System.Object, System.Boolean)
sdk.call_native_func(nil, type_def, "Exit", ...)  -- System.Void Exit(System.Object)
sdk.call_native_func(nil, type_def, "Pulse", ...)  -- System.Void Pulse(System.Object)
sdk.call_native_func(nil, type_def, "PulseAll", ...)  -- System.Void PulseAll(System.Object)
sdk.call_native_func(nil, type_def, "TryEnter", ...)  -- System.Boolean TryEnter(System.Object)
sdk.call_native_func(nil, type_def, "TryEnter", ...)  -- System.Boolean TryEnter(System.Object, System.Boolean)
sdk.call_native_func(nil, type_def, "TryEnter", ...)  -- System.Boolean TryEnter(System.Object, System.Int32)
sdk.call_native_func(nil, type_def, "Wait", ...)  -- System.Boolean Wait(System.Object)
```

## `System.Threading.ParameterizedThreadStart`

**Methods**

```lua
:System.Void Invoke(System.Object)
```

## `System.Threading.PlatformHelper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PROCESSOR_COUNT_REFRESH_INTERVAL_MS` | `System.Int32` | yes | 16 |
| `s_processorCount` | `System.Int32` | yes | 16 |
| `s_lastProcessorCountRefreshTicks` | `System.Int32` | yes | 20 |
| `IsSingleProcessor` | `System.Boolean` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "get_ProcessorCount", ...)  -- System.Int32 get_ProcessorCount()
```

## `System.Threading.SpinWait`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultSleep1Threshold` | `System.Int32` | yes | 16 |
| `Sleep0EveryHowManyYields` | `System.Int32` | yes | 16 |
| `Sleep1ThresholdForSpinBeforeWait` | `System.Int32` | yes | 16 |
| `SpinCountforSpinBeforeWait` | `System.Int32` | yes | 16 |
| `YieldThreshold` | `System.Int32` | yes | 16 |
| `_count` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Void Reset()
:System.Void SpinOnce()
:System.Void SpinOnce(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_NextSpinWillYield()
:System.Void set_Count(System.Int32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "SpinUntil", ...)  -- System.Void SpinUntil(System.Func`1<System.Boolean>)
sdk.call_native_func(nil, type_def, "SpinUntil", ...)  -- System.Boolean SpinUntil(System.Func`1<System.Boolean>, System.TimeSpan)
sdk.call_native_func(nil, type_def, "SpinUntil", ...)  -- System.Boolean SpinUntil(System.Func`1<System.Boolean>, System.Int32)
```

## `System.Threading.Tasks.Parallel`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DEFAULT_LOOP_STRIDE` | `System.Int32` | yes | 16 |
| `s_forkJoinContextID` | `System.Int32` | yes | 16 |
| `s_defaultParallelOptions` | `System.Threading.Tasks.ParallelOptions` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "CheckTimeoutReached", ...)  -- System.Boolean CheckTimeoutReached(System.Int32)
sdk.call_native_func(nil, type_def, "ComputeTimeoutPoint", ...)  -- System.Int32 ComputeTimeoutPoint(System.Int32)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Action`1<System.Int32>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Action`1<System.Int64>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Threading.Tasks.ParallelOptions, System.Action`1<System.Int32>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Threading.Tasks.ParallelOptions, System.Action`1<System.Int64>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Action`2<System.Int32,System.Threading.Tasks.ParallelLoopState>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Action`2<System.Int64,System.Threading.Tasks.ParallelLoopState>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Threading.Tasks.ParallelOptions, System.Action`2<System.Int32,System.Threading.Tasks.ParallelLoopState>)
sdk.call_native_func(nil, type_def, "For", ...)  -- System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Threading.Tasks.ParallelOptions, System.Action`2<System.Int64,System.Threading.Tasks.ParallelLoopState>)
sdk.call_native_func(nil, type_def, "ForWorker", ...)  -- System.Void ForWorker(System.Int32, System.Int32, System.Action`1<System.Int32>)
sdk.call_native_func(nil, type_def, "Invoke", ...)  -- System.Void Invoke(System.Action[])
sdk.call_native_func(nil, type_def, "Invoke", ...)  -- System.Void Invoke(System.Threading.Tasks.ParallelOptions, System.Action[])
```

## `System.Threading.Tasks.ParallelLoopResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_completed` | `System.Boolean` |  | 16 |
| `_lowestBreakIteration` | `System.Nullable`1<System.Int64>` |  | 24 |

**Methods**

```lua
:System.Boolean get_IsCompleted()
:System.Nullable`1<System.Int64> get_LowestBreakIteration()
```

## `System.Threading.Tasks.ParallelLoopState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_flagsBase` | `System.Threading.Tasks.ParallelLoopStateFlags` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Threading.Tasks.ParallelLoopStateFlags)
:System.Void Break()
:System.Void InternalBreak()
:System.Void Stop()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Boolean get_IsExceptional()
:System.Boolean get_IsStopped()
:System.Nullable`1<System.Int64> get_LowestBreakIteration()
:System.Boolean get_ShouldExitCurrentIteration()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Break", ...)  -- System.Void Break(System.Int32, System.Threading.Tasks.ParallelLoopStateFlags32)
sdk.call_native_func(nil, type_def, "Break", ...)  -- System.Void Break(System.Int64, System.Threading.Tasks.ParallelLoopStateFlags64)
```

## `System.Threading.Tasks.ParallelLoopState32`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_sharedParallelStateFlags` | `System.Threading.Tasks.ParallelLoopStateFlags32` |  | 24 |
| `_currentIteration` | `System.Int32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Threading.Tasks.ParallelLoopStateFlags32)
:System.Void InternalBreak()
:System.Int32 get_CurrentIteration()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Void set_CurrentIteration(System.Int32)
```

## `System.Threading.Tasks.ParallelLoopState64`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_sharedParallelStateFlags` | `System.Threading.Tasks.ParallelLoopStateFlags64` |  | 24 |
| `_currentIteration` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Threading.Tasks.ParallelLoopStateFlags64)
:System.Void InternalBreak()
:System.Int64 get_CurrentIteration()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Void set_CurrentIteration(System.Int64)
```

## `System.Threading.Tasks.ParallelLoopStateFlags`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ParallelLoopStateBroken` | `System.Int32` | yes | 16 |
| `ParallelLoopStateCanceled` | `System.Int32` | yes | 16 |
| `ParallelLoopStateExceptional` | `System.Int32` | yes | 16 |
| `ParallelLoopStateNone` | `System.Int32` | yes | 16 |
| `ParallelLoopStateStopped` | `System.Int32` | yes | 16 |
| `_loopStateFlags` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Boolean AtomicLoopStateUpdate(System.Int32, System.Int32)
:System.Boolean AtomicLoopStateUpdate(System.Int32, System.Int32, System.Int32)
:System.Boolean Cancel()
:System.Void SetExceptional()
:System.Void Stop()
:System.Int32 get_LoopStateFlags()
```

## `System.Threading.Tasks.ParallelLoopStateFlags32`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_lowestBreakIteration` | `System.Int32` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean ShouldExitLoop(System.Int32)
:System.Boolean ShouldExitLoop()
:System.Int32 get_LowestBreakIteration()
:System.Nullable`1<System.Int64> get_NullableLowestBreakIteration()
```

## `System.Threading.Tasks.ParallelLoopStateFlags64`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_lowestBreakIteration` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean ShouldExitLoop(System.Int64)
:System.Boolean ShouldExitLoop()
:System.Int64 get_LowestBreakIteration()
:System.Nullable`1<System.Int64> get_NullableLowestBreakIteration()
```

## `System.Threading.Tasks.ParallelOptions`

_No fields or methods._

## `System.Threading.Thread`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mAppDomain` | `System.AppDomain` | yes | 16 |
| `mThreadName` | `System.String` |  | 16 |
| `mThreadStart` | `System.Threading.ThreadStart` |  | 24 |
| `mThreadParam` | `System.Object` |  | 32 |
| `mThreadPtr` | `System.IntPtr` |  | 40 |
| `mThreadId` | `System.Int32` |  | 48 |
| `mThreadState` | `System.Threading.ThreadState` |  | 52 |
| `mApartmentState` | `System.Threading.ApartmentState` |  | 56 |

**Methods**

```lua
:System.Void .ctor(System.Threading.ThreadStart)
:System.Void .ctor(System.Threading.ThreadStart, System.Int32)
:System.Void .ctor(System.Threading.ParameterizedThreadStart)
:System.Void .ctor(System.Threading.ParameterizedThreadStart, System.Int32)
:System.Void .ctor(System.Int32)
:System.Void Abort()
:System.Void Finalize()
:System.Threading.ApartmentState GetApartmentState()
:System.Void Join()
:System.Boolean Join(System.Int32)
:System.Boolean Join(System.TimeSpan)
:System.Void Resume()
:System.Void SetApartmentState(System.Threading.ApartmentState)
:System.Void Start()
:System.Void Start(System.Object)
:System.Void Suspend()
:System.Void createThread(System.Object, System.Int32)
:System.Boolean get_IsAlive()
:System.Int32 get_ManagedThreadId()
:System.String get_Name()
:System.Threading.ThreadState get_ThreadState()
:System.Void set_Name(System.String)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetDomain", ...)  -- System.AppDomain GetDomain()
sdk.call_native_func(nil, type_def, "Sleep", ...)  -- System.Void Sleep(System.Int32)
sdk.call_native_func(nil, type_def, "SpinWait", ...)  -- System.Void SpinWait(System.Int32)
sdk.call_native_func(nil, type_def, "ThreadStartInvoke", ...)  -- System.Void ThreadStartInvoke(System.Object, System.Object)
sdk.call_native_func(nil, type_def, "Yield", ...)  -- System.Void Yield()
sdk.call_native_func(nil, type_def, "get_CurrentThread", ...)  -- System.Threading.Thread get_CurrentThread()
```

## `System.Threading.ThreadAbortException`

_No fields or methods._

## `System.Threading.ThreadStart`

**Methods**

```lua
:System.Void Invoke()
```

## `System.Threading.ThreadStartException`

_No fields or methods._

## `System.Threading.ThreadState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AbortRequested` | `System.Threading.ThreadState` | yes | 16 |
| `Aborted` | `System.Threading.ThreadState` | yes | 16 |
| `Background` | `System.Threading.ThreadState` | yes | 16 |
| `Running` | `System.Threading.ThreadState` | yes | 16 |
| `StopRequested` | `System.Threading.ThreadState` | yes | 16 |
| `Stopped` | `System.Threading.ThreadState` | yes | 16 |
| `SuspendRequested` | `System.Threading.ThreadState` | yes | 16 |
| `Suspended` | `System.Threading.ThreadState` | yes | 16 |
| `Unstarted` | `System.Threading.ThreadState` | yes | 16 |
| `WaitSleepJoin` | `System.Threading.ThreadState` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.Threading.ThreadStateException`

_No fields or methods._

## `System.Threading.ThreadState[]`

**Methods**

```lua
:System.Void Add(System.Threading.ThreadState)
:System.Threading.ThreadState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Threading.ThreadState)
:System.Void CopyTo(System.Threading.ThreadState[], System.Int32)
:System.Threading.ThreadState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Threading.ThreadState> GetEnumerator()
:System.Int32 IndexOf(System.Threading.ThreadState)
:System.Void Insert(System.Int32, System.Threading.ThreadState)
:System.Boolean Remove(System.Threading.ThreadState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Threading.ThreadState)
:System.Threading.ThreadState get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Threading.ThreadState)
```

## `System.Threading.Timeout`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Infinite` | `System.Int32` | yes | 16 |
| `InfiniteTimeSpan` | `System.TimeSpan` | yes | 16 |
| `UnsignedInfinite` | `System.UInt32` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `System.Threading.TimeoutHelper`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetTime", ...)  -- System.UInt32 GetTime()
sdk.call_native_func(nil, type_def, "UpdateTimeOut", ...)  -- System.Int32 UpdateTimeOut(System.UInt32, System.Int32)
```

## `System.Threading.Volatile`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Boolean Read(System.Boolean)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.SByte Read(System.SByte)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Byte Read(System.Byte)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Int16 Read(System.Int16)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.UInt16 Read(System.UInt16)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Int32 Read(System.Int32)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.UInt32 Read(System.UInt32)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Int64 Read(System.Int64)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.UInt64 Read(System.UInt64)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.IntPtr Read(System.IntPtr)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.UIntPtr Read(System.UIntPtr)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Single Read(System.Single)
sdk.call_native_func(nil, type_def, "Read", ...)  -- System.Double Read(System.Double)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.SByte, System.SByte)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Byte, System.Byte)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int16, System.Int16)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt16, System.UInt16)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Int64, System.Int64)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UInt64, System.UInt64)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.IntPtr, System.IntPtr)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.UIntPtr, System.UIntPtr)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Single, System.Single)
sdk.call_native_func(nil, type_def, "Write", ...)  -- System.Void Write(System.Double, System.Double)
```

## `System.TimeSpan`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TicksPerDay` | `System.Int64` | yes | 16 |
| `TicksPerHour` | `System.Int64` | yes | 16 |
| `TicksPerMillisecond` | `System.Int64` | yes | 16 |
| `TicksPerMinute` | `System.Int64` | yes | 16 |
| `TicksPerSecond` | `System.Int64` | yes | 16 |
| `Zero` | `System.TimeSpan` | yes | 16 |
| `MaxValue` | `System.TimeSpan` | yes | 24 |
| `MinValue` | `System.TimeSpan` | yes | 32 |
| `mThicks` | `System.Int64` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Int64)
:System.Void .ctor(System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32)
:System.Void .ctor(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.TimeSpan Add(System.TimeSpan)
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.TimeSpan)
:System.TimeSpan Duration()
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.TimeSpan)
:System.Int32 GetHashCode()
:System.TimeSpan Negate()
:System.TimeSpan Subtract(System.TimeSpan)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.Int32 get_Days()
:System.Int32 get_Hours()
:System.Int32 get_Milliseconds()
:System.Int32 get_Minutes()
:System.Int32 get_Seconds()
:System.Int64 get_Ticks()
:System.Double get_TotalDays()
:System.Double get_TotalHours()
:System.Double get_TotalMilliseconds()
:System.Double get_TotalMinutes()
:System.Double get_TotalSeconds()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "Compare", ...)  -- System.Int32 Compare(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "Equals", ...)  -- System.Boolean Equals(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "FromDays", ...)  -- System.TimeSpan FromDays(System.Double)
sdk.call_native_func(nil, type_def, "FromHours", ...)  -- System.TimeSpan FromHours(System.Double)
sdk.call_native_func(nil, type_def, "FromMilliseconds", ...)  -- System.TimeSpan FromMilliseconds(System.Double)
sdk.call_native_func(nil, type_def, "FromMinutes", ...)  -- System.TimeSpan FromMinutes(System.Double)
sdk.call_native_func(nil, type_def, "FromSeconds", ...)  -- System.TimeSpan FromSeconds(System.Double)
sdk.call_native_func(nil, type_def, "FromTicks", ...)  -- System.TimeSpan FromTicks(System.Int64)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.TimeSpan Parse(System.String)
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.TimeSpan Parse(System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.TimeSpan ParseExact(System.String, System.String, System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.TimeSpan ParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.TimeSpanStyles)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.TimeSpan ParseExact(System.String, System.String[], System.IFormatProvider)
sdk.call_native_func(nil, type_def, "ParseExact", ...)  -- System.TimeSpan ParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.TimeSpanStyles)
sdk.call_native_func(nil, type_def, "SplitToken", ...)  -- System.Int32 SplitToken(System.String, System.Int32[], System.Int32[], System.Char[])
sdk.call_native_func(nil, type_def, "ToCustomString", ...)  -- System.String ToCustomString(System.TimeSpan, System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.IFormatProvider, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.TimeSpanStyles, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParseExact", ...)  -- System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.TimeSpanStyles, System.TimeSpan)
sdk.call_native_func(nil, type_def, "TryParseInternal", ...)  -- System.Boolean TryParseInternal(System.String, System.String, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Addition", ...)  -- System.TimeSpan op_Addition(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_GreaterThan", ...)  -- System.Boolean op_GreaterThan(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_GreaterThanOrEqual", ...)  -- System.Boolean op_GreaterThanOrEqual(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_LessThan", ...)  -- System.Boolean op_LessThan(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_LessThanOrEqual", ...)  -- System.Boolean op_LessThanOrEqual(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_Subtraction", ...)  -- System.TimeSpan op_Subtraction(System.TimeSpan, System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_UnaryNegation", ...)  -- System.TimeSpan op_UnaryNegation(System.TimeSpan)
sdk.call_native_func(nil, type_def, "op_UnaryPlus", ...)  -- System.TimeSpan op_UnaryPlus(System.TimeSpan)
```

## `System.TimeZone`

_No fields or methods._

## `System.Tuple`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
```

## `System.Type`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultLookup` | `System.Reflection.BindingFlags` | yes | 16 |
| `s_defaultBinder` | `System.Reflection.Binder` | yes | 16 |
| `Delimiter` | `System.Char` | yes | 24 |
| `EmptyTypes` | `System.Type[]` | yes | 32 |
| `Missing` | `System.Object` | yes | 40 |
| `FilterAttribute` | `System.Reflection.MemberFilter` | yes | 48 |
| `FilterName` | `System.Reflection.MemberFilter` | yes | 56 |
| `FilterNameIgnoreCase` | `System.Reflection.MemberFilter` | yes | 64 |

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Boolean Equals(System.Type)
:System.Type[] FindInterfaces(System.Reflection.TypeFilter, System.Object)
:System.Reflection.MemberInfo[] FindMembers(System.Reflection.MemberTypes, System.Reflection.BindingFlags, System.Reflection.MemberFilter, System.Object)
:System.String FormatTypeName()
:System.String FormatTypeName(System.Boolean)
:System.Int32 GetArrayRank()
:System.Reflection.ConstructorInfo GetConstructor(System.Type[])
:System.Reflection.ConstructorInfo GetConstructor(System.Reflection.BindingFlags, System.Reflection.Binder, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.ConstructorInfo GetConstructor(System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.ConstructorInfo[] GetConstructors()
:System.Reflection.MemberInfo[] GetDefaultMembers()
:System.String GetEnumName(System.Object)
:System.String[] GetEnumNames()
:System.Type GetEnumUnderlyingType()
:System.Array GetEnumValues()
:System.Reflection.EventInfo GetEvent(System.String)
:System.Reflection.EventInfo[] GetEvents()
:System.Reflection.FieldInfo GetField(System.String)
:System.Reflection.FieldInfo[] GetFields()
:System.Type[] GetGenericArguments()
:System.Type[] GetGenericParameterConstraints()
:System.Type GetGenericTypeDefinition()
:System.Int32 GetHashCode()
:System.Type GetInterface(System.String)
:System.Reflection.InterfaceMapping GetInterfaceMap(System.Type)
:System.Reflection.MemberInfo[] GetMember(System.String)
:System.Reflection.MemberInfo[] GetMember(System.String, System.Reflection.BindingFlags)
:System.Reflection.MemberInfo[] GetMember(System.String, System.Reflection.MemberTypes, System.Reflection.BindingFlags)
:System.Reflection.MemberInfo[] GetMembers()
:System.Reflection.MethodInfo GetMethod(System.String)
:System.Reflection.MethodInfo GetMethod(System.String, System.Reflection.BindingFlags)
:System.Reflection.MethodInfo GetMethod(System.String, System.Type[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Int32, System.Type[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Int32, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Int32, System.Reflection.BindingFlags, System.Reflection.Binder, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethod(System.String, System.Int32, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo GetMethodImpl(System.String, System.Int32, System.Reflection.BindingFlags, System.Reflection.Binder, System.Reflection.CallingConventions, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.MethodInfo[] GetMethods()
:System.Type GetNestedType(System.String)
:System.Type[] GetNestedTypes()
:System.Reflection.PropertyInfo[] GetProperties()
:System.Reflection.PropertyInfo GetProperty(System.String)
:System.Reflection.PropertyInfo GetProperty(System.String, System.Reflection.BindingFlags)
:System.Reflection.PropertyInfo GetProperty(System.String, System.Type)
:System.Reflection.PropertyInfo GetProperty(System.String, System.Type[])
:System.Reflection.PropertyInfo GetProperty(System.String, System.Type, System.Type[])
:System.Reflection.PropertyInfo GetProperty(System.String, System.Type, System.Type[], System.Reflection.ParameterModifier[])
:System.Reflection.PropertyInfo GetProperty(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Type, System.Type[], System.Reflection.ParameterModifier[])
:System.Type GetRootElementType()
:System.Type GetType()
:System.Boolean ImplementInterface(System.Type)
:System.Object InvokeMember(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object, System.Object[])
:System.Object InvokeMember(System.String, System.Reflection.BindingFlags, System.Reflection.Binder, System.Object, System.Object[], System.Globalization.CultureInfo)
:System.Boolean IsAssignableFrom(System.Type)
:System.Boolean IsEnumDefined(System.Object)
:System.Boolean IsEquivalentTo(System.Type)
:System.Boolean IsInstanceOfType(System.Object)
:System.Boolean IsRuntimeImplemented()
:System.Boolean IsSubclassOf(System.Type)
:System.Boolean IsValueTypeImpl()
:System.Type MakeArrayType()
:System.Type MakeArrayType(System.Int32)
:System.Type MakeByRefType()
:System.Type MakeGenericType(System.Type[])
:System.Type MakePointerType()
:System.String ToString()
:System.Reflection.TypeAttributes get_Attributes()
:System.Boolean get_ContainsGenericParameters()
:System.Reflection.GenericParameterAttributes get_GenericParameterAttributes()
:System.Int32 get_GenericParameterPosition()
:System.Type[] get_GenericTypeArguments()
:System.Boolean get_HasElementType()
:System.Boolean get_IsAbstract()
:System.Boolean get_IsAnsiClass()
:System.Boolean get_IsArray()
:System.Boolean get_IsAutoClass()
:System.Boolean get_IsAutoLayout()
:System.Boolean get_IsByRef()
:System.Boolean get_IsByRefLike()
:System.Boolean get_IsCOMObject()
:System.Boolean get_IsClass()
:System.Boolean get_IsConstructedGenericType()
:System.Boolean get_IsEnum()
:System.Boolean get_IsExplicitLayout()
:System.Boolean get_IsImport()
:System.Boolean get_IsInterface()
:System.Boolean get_IsLayoutSequential()
:System.Boolean get_IsNested()
:System.Boolean get_IsNestedAssembly()
:System.Boolean get_IsNestedFamANDAssem()
:System.Boolean get_IsNestedFamORAssem()
:System.Boolean get_IsNestedFamily()
:System.Boolean get_IsNestedPrivate()
:System.Boolean get_IsNestedPublic()
:System.Boolean get_IsNotPublic()
:System.Boolean get_IsPointer()
:System.Boolean get_IsPrimitive()
:System.Boolean get_IsPublic()
:System.Boolean get_IsSealed()
:System.Boolean get_IsSecurityCritical()
:System.Boolean get_IsSecuritySafeCritical()
:System.Boolean get_IsSecurityTransparent()
:System.Boolean get_IsSerializable()
:System.Boolean get_IsSpecialName()
:System.Boolean get_IsUnicodeClass()
:System.Boolean get_IsValueType()
:System.Boolean get_IsVisible()
:System.Reflection.MemberTypes get_MemberType()
:System.Type get_ReflectedType()
:System.Runtime.InteropServices.StructLayoutAttribute get_StructLayoutAttribute()
:System.RuntimeTypeHandle get_TypeHandle()
:System.Reflection.ConstructorInfo get_TypeInitializer()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "FilterAttributeImpl", ...)  -- System.Boolean FilterAttributeImpl(System.Reflection.MemberInfo, System.Object)
sdk.call_native_func(nil, type_def, "FilterNameIgnoreCaseImpl", ...)  -- System.Boolean FilterNameIgnoreCaseImpl(System.Reflection.MemberInfo, System.Object)
sdk.call_native_func(nil, type_def, "FilterNameImpl", ...)  -- System.Boolean FilterNameImpl(System.Reflection.MemberInfo, System.Object)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>, System.Boolean)
sdk.call_native_func(nil, type_def, "GetType", ...)  -- System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "GetTypeArray", ...)  -- System.Type[] GetTypeArray(System.Object[])
sdk.call_native_func(nil, type_def, "GetTypeCode", ...)  -- System.TypeCode GetTypeCode(System.Type)
sdk.call_native_func(nil, type_def, "GetTypeFromCLSID", ...)  -- System.Type GetTypeFromCLSID(System.Guid)
sdk.call_native_func(nil, type_def, "GetTypeFromCLSID", ...)  -- System.Type GetTypeFromCLSID(System.Guid, System.Boolean)
sdk.call_native_func(nil, type_def, "GetTypeFromCLSID", ...)  -- System.Type GetTypeFromCLSID(System.Guid, System.String)
sdk.call_native_func(nil, type_def, "GetTypeFromCLSID", ...)  -- System.Type GetTypeFromCLSID(System.Guid, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "GetTypeFromHandle", ...)  -- System.Type GetTypeFromHandle(System.RuntimeTypeHandle)
sdk.call_native_func(nil, type_def, "GetTypeFromProgID", ...)  -- System.Type GetTypeFromProgID(System.String)
sdk.call_native_func(nil, type_def, "GetTypeFromProgID", ...)  -- System.Type GetTypeFromProgID(System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "GetTypeFromProgID", ...)  -- System.Type GetTypeFromProgID(System.String, System.String)
sdk.call_native_func(nil, type_def, "GetTypeFromProgID", ...)  -- System.Type GetTypeFromProgID(System.String, System.String, System.Boolean)
sdk.call_native_func(nil, type_def, "GetTypeHandle", ...)  -- System.RuntimeTypeHandle GetTypeHandle(System.Object)
sdk.call_native_func(nil, type_def, "MakeGenericMethodParameter", ...)  -- System.Type MakeGenericMethodParameter(System.Int32)
sdk.call_native_func(nil, type_def, "ReflectionOnlyGetType", ...)  -- System.Type ReflectionOnlyGetType(System.String, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "op_Equality", ...)  -- System.Boolean op_Equality(System.Type, System.Type)
sdk.call_native_func(nil, type_def, "op_Inequality", ...)  -- System.Boolean op_Inequality(System.Type, System.Type)
```

## `System.TypeAccessException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.TypeCode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Boolean` | `System.TypeCode` | yes | 16 |
| `Byte` | `System.TypeCode` | yes | 16 |
| `Char` | `System.TypeCode` | yes | 16 |
| `DBNull` | `System.TypeCode` | yes | 16 |
| `DateTime` | `System.TypeCode` | yes | 16 |
| `Decimal` | `System.TypeCode` | yes | 16 |
| `Double` | `System.TypeCode` | yes | 16 |
| `Empty` | `System.TypeCode` | yes | 16 |
| `Int16` | `System.TypeCode` | yes | 16 |
| `Int32` | `System.TypeCode` | yes | 16 |
| `Int64` | `System.TypeCode` | yes | 16 |
| `Object` | `System.TypeCode` | yes | 16 |
| `SByte` | `System.TypeCode` | yes | 16 |
| `Single` | `System.TypeCode` | yes | 16 |
| `String` | `System.TypeCode` | yes | 16 |
| `UInt16` | `System.TypeCode` | yes | 16 |
| `UInt32` | `System.TypeCode` | yes | 16 |
| `UInt64` | `System.TypeCode` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `System.TypeCode[]`

**Methods**

```lua
:System.Void Add(System.TypeCode)
:System.TypeCode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.TypeCode)
:System.Void CopyTo(System.TypeCode[], System.Int32)
:System.TypeCode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.TypeCode> GetEnumerator()
:System.Int32 IndexOf(System.TypeCode)
:System.Void Insert(System.Int32, System.TypeCode)
:System.Boolean Remove(System.TypeCode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.TypeCode)
:System.TypeCode get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.TypeCode)
```

## `System.TypeLoadException`

**Methods**

```lua
:System.Void .ctor(System.String)
:System.Void .ctor(System.String, System.Exception)
```

## `System.Type[]`

**Methods**

```lua
:System.Void Add(System.Type)
:System.Type Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Type)
:System.Void CopyTo(System.Type[], System.Int32)
:System.Type Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Type> GetEnumerator()
:System.Int32 IndexOf(System.Type)
:System.Void Insert(System.Int32, System.Type)
:System.Boolean Remove(System.Type)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Type)
:System.Type get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Type)
```

## `System.Type[][]`

**Methods**

```lua
:System.Void Add(System.Type[])
:System.Type[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.Type[])
:System.Void CopyTo(System.Type[][], System.Int32)
:System.Type[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.Type[]> GetEnumerator()
:System.Int32 IndexOf(System.Type[])
:System.Void Insert(System.Int32, System.Type[])
:System.Boolean Remove(System.Type[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.Type[])
:System.Type[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Type[])
```

## `System.TypedReference`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.IntPtr` |  | 16 |
| `mType` | `System.IntPtr` |  | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GetTargetType", ...)  -- System.Type GetTargetType(System.TypedReference)
sdk.call_native_func(nil, type_def, "MakeTypedReference", ...)  -- System.TypedReference MakeTypedReference(System.Object, System.Reflection.FieldInfo[])
sdk.call_native_func(nil, type_def, "SetTypedReference", ...)  -- System.Void SetTypedReference(System.TypedReference, System.Object)
sdk.call_native_func(nil, type_def, "TargetTypeToken", ...)  -- System.RuntimeTypeHandle TargetTypeToken(System.TypedReference)
sdk.call_native_func(nil, type_def, "ToObject", ...)  -- System.Object ToObject(System.TypedReference)
```

## `System.UInt16`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.UInt16` | yes | 16 |
| `MinValue` | `System.UInt16` | yes | 16 |
| `mValue` | `System.UInt16` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.UInt16)
:System.Boolean Equals(System.UInt16)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.UInt16 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.UInt16)
```

## `System.UInt16[,]`

**Methods**

```lua
:System.UInt16 Address(System.Int32, System.Int32)
:System.UInt16 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.UInt16)
```

## `System.UInt16[]`

**Methods**

```lua
:System.Void Add(System.UInt16)
:System.UInt16 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.UInt16)
:System.Void CopyTo(System.UInt16[], System.Int32)
:System.UInt16 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.UInt16> GetEnumerator()
:System.Int32 IndexOf(System.UInt16)
:System.Void Insert(System.Int32, System.UInt16)
:System.Boolean Remove(System.UInt16)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.UInt16)
:System.UInt16 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.UInt16)
```

## `System.UInt32`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.UInt32` | yes | 16 |
| `MinValue` | `System.UInt32` | yes | 16 |
| `mValue` | `System.UInt32` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.UInt32)
:System.Boolean Equals(System.UInt32)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.UInt32 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.UInt32)
```

## `System.UInt32[,]`

**Methods**

```lua
:System.UInt32 Address(System.Int32, System.Int32)
:System.UInt32 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.UInt32)
```

## `System.UInt32[]`

**Methods**

```lua
:System.Void Add(System.UInt32)
:System.UInt32 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.UInt32)
:System.Void CopyTo(System.UInt32[], System.Int32)
:System.UInt32 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.UInt32> GetEnumerator()
:System.Int32 IndexOf(System.UInt32)
:System.Void Insert(System.Int32, System.UInt32)
:System.Boolean Remove(System.UInt32)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.UInt32)
:System.UInt32 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.UInt32)
```

## `System.UInt32[][]`

**Methods**

```lua
:System.Void Add(System.UInt32[])
:System.UInt32[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.UInt32[])
:System.Void CopyTo(System.UInt32[][], System.Int32)
:System.UInt32[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.UInt32[]> GetEnumerator()
:System.Int32 IndexOf(System.UInt32[])
:System.Void Insert(System.Int32, System.UInt32[])
:System.Boolean Remove(System.UInt32[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.UInt32[])
:System.UInt32[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.UInt32[])
```

## `System.UInt64`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxValue` | `System.UInt64` | yes | 16 |
| `MinValue` | `System.UInt64` | yes | 16 |
| `mValue` | `System.UInt64` |  | 16 |

**Methods**

```lua
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.UInt64)
:System.Boolean Equals(System.UInt64)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.TypeCode GetTypeCode()
:System.Boolean System.IConvertible.ToBoolean(System.IFormatProvider)
:System.Byte System.IConvertible.ToByte(System.IFormatProvider)
:System.Char System.IConvertible.ToChar(System.IFormatProvider)
:System.DateTime System.IConvertible.ToDateTime(System.IFormatProvider)
:System.Decimal System.IConvertible.ToDecimal(System.IFormatProvider)
:System.Double System.IConvertible.ToDouble(System.IFormatProvider)
:System.Int16 System.IConvertible.ToInt16(System.IFormatProvider)
:System.Int32 System.IConvertible.ToInt32(System.IFormatProvider)
:System.Int64 System.IConvertible.ToInt64(System.IFormatProvider)
:System.SByte System.IConvertible.ToSByte(System.IFormatProvider)
:System.Single System.IConvertible.ToSingle(System.IFormatProvider)
:System.Object System.IConvertible.ToType(System.Type, System.IFormatProvider)
:System.UInt16 System.IConvertible.ToUInt16(System.IFormatProvider)
:System.UInt32 System.IConvertible.ToUInt32(System.IFormatProvider)
:System.UInt64 System.IConvertible.ToUInt64(System.IFormatProvider)
:System.String ToString()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString(System.IFormatProvider)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Parse", ...)  -- System.UInt64 Parse(System.String)
sdk.call_native_func(nil, type_def, "TryParse", ...)  -- System.Boolean TryParse(System.String, System.UInt64)
```

## `System.UInt64[]`

**Methods**

```lua
:System.Void Add(System.UInt64)
:System.UInt64 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(System.UInt64)
:System.Void CopyTo(System.UInt64[], System.Int32)
:System.UInt64 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<System.UInt64> GetEnumerator()
:System.Int32 IndexOf(System.UInt64)
:System.Void Insert(System.Int32, System.UInt64)
:System.Boolean Remove(System.UInt64)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, System.UInt64)
:System.UInt64 get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.UInt64)
```

## `System.UIntPtr`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mValue` | `System.UInt64` |  | 16 |

**Methods**

```lua
:System.Int32 GetHashCode()
:System.String ToString()
```

## `System.UnhandledExceptionEventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `mException` | `System.Object` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Object, System.Boolean)
:System.Object get_ExceptionObject()
```

## `System.UnhandledExceptionEventHandler`

**Methods**

```lua
:System.Void Invoke(System.Object, System.UnhandledExceptionEventArgs)
```

## `System.ValueTuple`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 System.Collections.IStructuralComparable.CompareTo(System.Object, System.Collections.IComparer)
:System.Boolean System.Collections.IStructuralEquatable.Equals(System.Object, System.Collections.IEqualityComparer)
:System.Int32 System.IComparable.CompareTo(System.Object)
:System.String System.IValueTupleInternal.ToStringEnd()
:System.Object System.Runtime.CompilerServices.ITuple.get_Item(System.Int32)
:System.String ToString()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "CombineHashCodes", ...)  -- System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "Create", ...)  -- System.ValueTuple Create()
```

## `System.ValueType`

**Methods**

```lua
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.String ToString()
```

## `System.Version`

_No fields or methods._

## `System.Void`

_No fields or methods._

## `System.WeakReference`

_No fields or methods._
