# `System.*`

235 types.

## `System.Action`

```lua
-- methods
:System.Void Invoke()
```

## `System.Activator`

```lua
-- static
:System.Object CreateInstance(System.Type)
:System.Object createInstance(System.Type)
```

## `System.AppDomain`

```lua
-- fields
UnhandledException: System.UnhandledExceptionEventHandler
-- methods
:System.Reflection.Assembly[] GetAssemblies()
:System.Void add_UnhandledException(System.UnhandledExceptionEventHandler)
:System.Void remove_UnhandledException(System.UnhandledExceptionEventHandler)
-- static
:System.Void DefaultExceptionHandler(System.Object, System.Exception)
:System.AppDomain get_CurrentDomain()
```

## `System.Array`

```lua
-- methods
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
-- static
:System.Int32 BinarySearch(System.Array, System.Object)
:System.Int32 BinarySearch(System.Array, System.Int32, System.Int32, System.Object)
:System.Int32 BinarySearch(System.Array, System.Object, System.Collections.IComparer)
:System.Int32 BinarySearch(System.Array, System.Int32, System.Int32, System.Object, System.Collections.IComparer)
:System.Void Clear(System.Array, System.Int32, System.Int32)
:System.Void Copy(System.Array, System.Array, System.Int32)
:System.Void Copy(System.Array, System.Array, System.Int64)
:System.Void Copy(System.Array, System.Int32, System.Array, System.Int32, System.Int32)
:System.Void Copy(System.Array, System.Int64, System.Array, System.Int64, System.Int64)
:System.Array CreateInstance(System.Type, System.Int32)
:System.Int32 GetMedian(System.Int32, System.Int32)
:System.Int32 IndexOf(System.Array, System.Object)
:System.Int32 IndexOf(System.Array, System.Object, System.Int32)
:System.Int32 IndexOf(System.Array, System.Object, System.Int32, System.Int32)
:System.Int32 LastIndexOf(System.Array, System.Object)
:System.Int32 LastIndexOf(System.Array, System.Object, System.Int32)
:System.Int32 LastIndexOf(System.Array, System.Object, System.Int32, System.Int32)
:System.Void Reverse(System.Array)
:System.Void Reverse(System.Array, System.Int32, System.Int32)
:System.Void SZArraySort(System.Array, System.Array, System.Int32, System.Int32, System.Object)
:System.Void Sort(System.Array)
:System.Void Sort(System.Array, System.Array)
:System.Void Sort(System.Array, System.Int32, System.Int32)
:System.Void Sort(System.Array, System.Array, System.Int32, System.Int32)
:System.Void Sort(System.Array, System.Collections.IComparer)
:System.Void Sort(System.Array, System.Array, System.Collections.IComparer)
:System.Void Sort(System.Array, System.Int32, System.Int32, System.Collections.IComparer)
:System.Void Sort(System.Array, System.Array, System.Int32, System.Int32, System.Collections.IComparer)
:System.Boolean TrySZBinarySearch(System.Array, System.Int32, System.Int32, System.Object, System.Int32)
```

## `System.Array.SZArrayEnumerator`

```lua
-- fields
mArray: System.Array
mCount: System.Int32
mIndex: System.Int32
mStart: System.Int32
-- methods
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.AsyncCallback`

```lua
-- methods
:System.Void Invoke(System.IAsyncResult)
```

## `System.Attribute`

```lua
-- methods
:System.Boolean Match(System.Object)
:System.Object get_TypeId()
```

## `System.AttributeTargets`

```lua
-- values (System.Int32 enum)
All
Assembly
Class
Constructor
Delegate
Enum
Event
Field
Interface
Method
Module
Parameter
Property
ReturnValue
Struct
```

## `System.AttributeUsageAttribute`

```lua
-- fields
Default: System.AttributeUsageAttribute [static]
mAllowMultiple: System.Boolean
mAttributeTarget: System.AttributeTargets
mInherited: System.Boolean
-- methods
:System.Boolean get_AllowMultiple()
:System.Boolean get_Inherited()
:System.AttributeTargets get_ValidOn()
:System.Void set_AllowMultiple(System.Boolean)
:System.Void set_Inherited(System.Boolean)
```

## `System.Base64FormattingOptions`

```lua
-- values (System.Int32 enum)
InsertLineBreaks
None
```

## `System.BitConverter`

```lua
-- fields
IsLittleEndian: System.Boolean [static]
-- static
:System.Int64 DoubleToInt64Bits(System.Double)
:System.Byte[] GetBytes(System.Boolean)
:System.Byte[] GetBytes(System.Char)
:System.Byte[] GetBytes(System.Double)
:System.Byte[] GetBytes(System.Single)
:System.Byte[] GetBytes(System.Int32)
:System.Byte[] GetBytes(System.Int64)
:System.Byte[] GetBytes(System.Int16)
:System.Byte[] GetBytes(System.UInt32)
:System.Byte[] GetBytes(System.UInt64)
:System.Byte[] GetBytes(System.UInt16)
:System.Double Int64BitsToDouble(System.Int64)
:System.Boolean ToBoolean(System.Byte[], System.Int32)
:System.Char ToChar(System.Byte[], System.Int32)
:System.Double ToDouble(System.Byte[], System.Int32)
:System.Int16 ToInt16(System.Byte[], System.Int32)
:System.Int32 ToInt32(System.Byte[], System.Int32)
:System.Int64 ToInt64(System.Byte[], System.Int32)
:System.Single ToSingle(System.Byte[], System.Int32)
:System.String ToString(System.Byte[])
:System.String ToString(System.Byte[], System.Int32)
:System.String ToString(System.Byte[], System.Int32, System.Int32)
:System.UInt16 ToUInt16(System.Byte[], System.Int32)
:System.UInt32 ToUInt32(System.Byte[], System.Int32)
:System.UInt64 ToUInt64(System.Byte[], System.Int32)
```

## `System.Boolean`

```lua
-- fields
False: System.Int32 [static]
FalseString: System.String [static]
True: System.Int32 [static]
TrueString: System.String [static]
mValue: System.Boolean
-- methods
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
-- static
:System.Boolean Parse(System.String)
:System.Boolean TryParse(System.String, System.Boolean)
```

## `System.Boolean[,]`

```lua
-- methods
:System.Boolean Address(System.Int32, System.Int32)
:System.Boolean Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Boolean)
```

## `System.Byte`

```lua
-- fields
MaxValue: System.Byte [static]
MinValue: System.Byte [static]
mValue: System.Byte
-- methods
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
-- static
:System.Byte Parse(System.String)
:System.Byte Parse(System.String, System.NumberStyles)
:System.Byte Parse(System.String, System.IFormatProvider)
:System.Byte Parse(System.String, System.NumberStyles, System.IFormatProvider)
:System.Boolean TryParse(System.String, System.Byte)
```

## `System.Char`

```lua
-- fields
HIGH_SURROGATE_START: System.Int32 [static]
LOW_SURROGATE_END: System.Int32 [static]
MaxValue: System.Char [static]
MinValue: System.Char [static]
UNICODE_PLANE00_END: System.Int32 [static]
UNICODE_PLANE01_START: System.Int32 [static]
UNICODE_PLANE16_END: System.Int32 [static]
s_categoryForLatin1: System.Byte[] [static]
m_value: System.Char
-- methods
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
-- static
:System.Boolean CheckLetter(System.Globalization.UnicodeCategory)
:System.Boolean CheckLetterOrDigit(System.Globalization.UnicodeCategory)
:System.Boolean CheckNumber(System.Globalization.UnicodeCategory)
:System.Boolean CheckPunctuation(System.Globalization.UnicodeCategory)
:System.Boolean CheckSeparator(System.Globalization.UnicodeCategory)
:System.Boolean CheckSymbol(System.Globalization.UnicodeCategory)
:System.String ConvertFromUtf32(System.Int32)
:System.Int32 ConvertToUtf32(System.Char, System.Char)
:System.Int32 ConvertToUtf32(System.String, System.Int32)
:System.Globalization.UnicodeCategory GetLatin1UnicodeCategory(System.Char)
:System.Double GetNumericValue(System.Char)
:System.Double GetNumericValue(System.String, System.Int32)
:System.Globalization.UnicodeCategory GetUnicodeCategory(System.Char)
:System.Globalization.UnicodeCategory GetUnicodeCategory(System.String, System.Int32)
:System.Boolean IsAscii(System.Char)
:System.Boolean IsControl(System.Char)
:System.Boolean IsControl(System.String, System.Int32)
:System.Boolean IsDigit(System.Char)
:System.Boolean IsDigit(System.String, System.Int32)
:System.Boolean IsHighSurrogate(System.Char)
:System.Boolean IsHighSurrogate(System.String, System.Int32)
:System.Boolean IsLatin1(System.Char)
:System.Boolean IsLetter(System.Char)
:System.Boolean IsLetter(System.String, System.Int32)
:System.Boolean IsLetterOrDigit(System.Char)
:System.Boolean IsLetterOrDigit(System.String, System.Int32)
:System.Boolean IsLowSurrogate(System.Char)
:System.Boolean IsLowSurrogate(System.String, System.Int32)
:System.Boolean IsLower(System.Char)
:System.Boolean IsLower(System.String, System.Int32)
:System.Boolean IsNumber(System.Char)
:System.Boolean IsNumber(System.String, System.Int32)
:System.Boolean IsPunctuation(System.Char)
:System.Boolean IsPunctuation(System.String, System.Int32)
:System.Boolean IsSeparator(System.Char)
:System.Boolean IsSeparator(System.String, System.Int32)
:System.Boolean IsSeparatorLatin1(System.Char)
:System.Boolean IsSurrogate(System.Char)
:System.Boolean IsSurrogate(System.String, System.Int32)
:System.Boolean IsSurrogatePair(System.String, System.Int32)
:System.Boolean IsSurrogatePair(System.Char, System.Char)
:System.Boolean IsSymbol(System.Char)
:System.Boolean IsSymbol(System.String, System.Int32)
:System.Boolean IsUpper(System.Char)
:System.Boolean IsUpper(System.String, System.Int32)
:System.Boolean IsWhiteSpace(System.Char)
:System.Boolean IsWhiteSpace(System.String, System.Int32)
:System.Boolean IsWhiteSpaceLatin1(System.Char)
:System.Char Parse(System.String)
:System.Char ToLower(System.Char, System.Globalization.CultureInfo)
:System.Char ToLower(System.Char)
:System.Char ToLowerInvariant(System.Char)
:System.String ToString(System.Char)
:System.Char ToUpper(System.Char, System.Globalization.CultureInfo)
:System.Char ToUpper(System.Char)
:System.Char ToUpperInvariant(System.Char)
:System.Boolean TryParse(System.String, System.Char)
```

## `System.CharEnumerator`

```lua
-- fields
_currentElement: System.Char
_index: System.Int32
_str: System.String
-- methods
:System.Object Clone()
:System.Void Dispose()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object System.Collections.IEnumerator.get_Current()
:System.Char get_Current()
```

## `System.Collections.ArrayList`

```lua
-- fields
MaxArrayLength: System.Int32 [static]
_defaultCapacity: System.Int32 [static]
_items: System.Object[]
_size: System.Int32
_version: System.Int32
-- methods
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
-- static
:System.Collections.ArrayList Adapter(System.Collections.IList)
:System.Collections.IList FixedSize(System.Collections.IList)
:System.Collections.ArrayList FixedSize(System.Collections.ArrayList)
:System.Collections.IList ReadOnly(System.Collections.IList)
:System.Collections.ArrayList ReadOnly(System.Collections.ArrayList)
:System.Collections.ArrayList Repeat(System.Object, System.Int32)
:System.Collections.IList Synchronized(System.Collections.IList)
:System.Collections.ArrayList Synchronized(System.Collections.ArrayList)
```

## `System.Collections.ArrayList.ArrayListEnumerator`

```lua
-- fields
_currentElement: System.Object
_endIndex: System.Int32
_index: System.Int32
_list: System.Collections.ArrayList
_startIndex: System.Int32
_version: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.ArrayList.ArrayListEnumeratorSimple`

```lua
-- fields
s_dummyObject: System.Object [static]
_currentElement: System.Object
_index: System.Int32
_isArrayList: System.Boolean
_list: System.Collections.ArrayList
_version: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.ArrayList.FixedSizeArrayList`

```lua
-- fields
_list: System.Collections.ArrayList
-- methods
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

```lua
-- fields
_list: System.Collections.IList
-- methods
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

```lua
-- fields
_list: System.Collections.IList
-- methods
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

```lua
-- fields
_en: System.Collections.IEnumerator
_firstCall: System.Boolean
_initialCount: System.Int32
_initialStartIndex: System.Int32
_remaining: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.ArrayList.Range`

```lua
-- fields
_baseIndex: System.Int32
_baseList: System.Collections.ArrayList
_baseSize: System.Int32
_baseVersion: System.Int32
-- methods
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

```lua
-- fields
_list: System.Collections.ArrayList
-- methods
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

```lua
-- fields
_list: System.Collections.IList
-- methods
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

```lua
-- fields
_list: System.Collections.ArrayList
_root: System.Object
-- methods
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

```lua
-- fields
_list: System.Collections.IList
_root: System.Object
-- methods
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

```lua
-- fields
BitsPerByte: System.Int32 [static]
BitsPerInt32: System.Int32 [static]
BytesPerInt32: System.Int32 [static]
_ShrinkThreshold: System.Int32 [static]
mArray: System.Int32[]
mLength: System.Int32
-- methods
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
-- static
:System.Int32 getArrayLength(System.Int32, System.Int32)
```

## `System.Collections.BitArray.Enumerator`

```lua
-- fields
mBitArray: System.Collections.BitArray
mCurrentElement: System.Boolean
mIndex: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.CaseInsensitiveComparer`

```lua
-- methods
:System.Int32 Compare(System.Object, System.Object)
```

## `System.Collections.Comparer`

```lua
-- fields
Default: System.Collections.Comparer [static]
DefaultInvariant: System.Collections.Comparer [static]
-- methods
:System.Int32 Compare(System.Object, System.Object)
```

## `System.Collections.Concurrent.PaddedHeadAndTail`

```lua
-- fields
Head: System.Int32
Tail: System.Int32
```

## `System.Collections.DictionaryEntry`

```lua
-- fields
mKey: System.Object
mValue: System.Object
-- methods
:System.Object get_Key()
:System.Object get_Value()
```

## `System.Collections.Generic.BitHelper`

```lua
-- fields
IntSize: System.Byte [static]
MarkedBitFlag: System.Byte [static]
mArray: System.Int32[]
mLength: System.Int32
-- methods
:System.Boolean IsMarked(System.Int32)
:System.Void MarkBit(System.Int32)
-- static
:System.Int32 ToIntArrayLength(System.Int32)
```

## `System.Collections.Generic.BitHelper2`

```lua
-- fields
IntSize: System.Byte [static]
MarkedBitFlag: System.Byte [static]
_array: System.Int32[]
_arrayPtr: System.Int32
_length: System.Int32
_useStackAlloc: System.Boolean
-- methods
:System.Boolean IsMarked(System.Int32)
:System.Void MarkBit(System.Int32)
-- static
:System.Int32 ToIntArrayLength(System.Int32)
```

## `System.Collections.Generic.CopyPosition`

```lua
-- methods
:System.Collections.Generic.CopyPosition Normalize(System.Int32)
:System.Int32 get_Column()
:System.String get_DebuggerDisplay()
:System.Int32 get_Row()
-- static
:System.Collections.Generic.CopyPosition get_Start()
```

## `System.Collections.Generic.HashHelper`

```lua
-- fields
primes: System.Int32[] [static]
-- static
:System.Int32 GetPrime(System.Int32)
:System.Boolean IsPrime(System.Int32)
```

## `System.Collections.Generic.IntrospectiveSortUtilities`

```lua
-- fields
IntrosortSizeThreshold: System.Int32 [static]
-- static
:System.Int32 FloorLog2(System.Int32)
:System.Void ThrowOrIgnoreBadComparer(System.Object)
```

## `System.Collections.Generic.Marker`

```lua
-- methods
:System.Int32 get_Count()
:System.String get_DebuggerDisplay()
:System.Int32 get_Index()
```

## `System.Collections.Generic.NodeColor`

```lua
-- values (System.Byte enum)
Black
Red
```

## `System.Collections.Generic.TreeRotation`

```lua
-- values (System.Byte enum)
Left
LeftRight
Right
RightLeft
```

## `System.Collections.HashHelpers`

```lua
-- fields
primes: System.Int32[] [static]
-- static
:System.Int32 GetPrime(System.Int32)
:System.Boolean IsPrime(System.Int32)
```

## `System.Collections.HashHelpersCoreFX`

```lua
-- fields
HashCollisionThreshold: System.Int32 [static]
MaxPrimeArrayLength: System.Int32 [static]
primes: System.Int32[] [static]
-- static
:System.Int32 ExpandPrime(System.Int32)
:System.Int32 GetPrime(System.Int32)
:System.Boolean IsPrime(System.Int32)
```

## `System.Collections.Hashtable`

```lua
-- fields
ComparerName: System.String [static]
HashCodeProviderName: System.String [static]
HashPrime: System.Int32 [static]
HashSizeName: System.String [static]
InitialSize: System.Int32 [static]
KeyComparerName: System.String [static]
KeysName: System.String [static]
LoadFactorName: System.String [static]
ValuesName: System.String [static]
VersionName: System.String [static]
_keycomparer: System.Collections.IEqualityComparer
buckets: System.Collections.Hashtable.bucket[]
count: System.Int32
isWriterInProgress: System.Boolean
keys: System.Collections.ICollection
loadFactor: System.Single
loadsize: System.Int32
occupancy: System.Int32
values: System.Collections.ICollection
version: System.Int32
-- methods
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
-- static
:System.Collections.Hashtable Synchronized(System.Collections.Hashtable)
```

## `System.Collections.Hashtable.HashtableEnumerator`

```lua
-- fields
DictEntry: System.Int32 [static]
Keys: System.Int32 [static]
Values: System.Int32 [static]
bucket: System.Int32
current: System.Boolean
currentKey: System.Object
currentValue: System.Object
getObjectRetType: System.Int32
hashtable: System.Collections.Hashtable
version: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
:System.Collections.DictionaryEntry get_Entry()
:System.Object get_Key()
:System.Object get_Value()
```

## `System.Collections.Hashtable.KeyCollection`

```lua
-- fields
_hashtable: System.Collections.Hashtable
-- methods
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_SyncRoot()
```

## `System.Collections.Hashtable.SyncHashtable`

```lua
-- fields
_table: System.Collections.Hashtable
-- methods
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

```lua
-- fields
_hashtable: System.Collections.Hashtable
-- methods
:System.Void CopyTo(System.Array, System.Int32)
:System.Collections.IEnumerator GetEnumerator()
:System.Int32 get_Count()
:System.Boolean get_IsSynchronized()
:System.Object get_SyncRoot()
```

## `System.Collections.Hashtable.bucket`

```lua
-- fields
hash_coll: System.Int32
key: System.Object
val: System.Object
```

## `System.Collections.ObjectModel.EventArgsCache`

```lua
-- fields
CountPropertyChanged: System.ComponentModel.PropertyChangedEventArgs [static]
IndexerPropertyChanged: System.ComponentModel.PropertyChangedEventArgs [static]
ResetCollectionChanged: System.Collections.Specialized.NotifyCollectionChangedEventArgs [static]
```

## `System.Collections.Queue`

```lua
-- fields
_MinimumGrow: System.Int32 [static]
_ShrinkThreshold: System.Int32 [static]
_array: System.Object[]
_growFactor: System.Int32
_head: System.Int32
_size: System.Int32
_tail: System.Int32
_version: System.Int32
-- methods
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
-- static
:System.Collections.Queue Synchronized(System.Collections.Queue)
```

## `System.Collections.Queue.QueueEnumerator`

```lua
-- fields
_currentElement: System.Object
_index: System.Int32
_q: System.Collections.Queue
_version: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.Queue.SynchronizedQueue`

```lua
-- fields
_q: System.Collections.Queue
_root: System.Object
-- methods
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

## `System.Collections.Specialized.NotifyCollectionChangedAction`

```lua
-- values (System.Int32 enum)
Add
Move
Remove
Replace
Reset
```

## `System.Collections.Specialized.NotifyCollectionChangedEventArgs`

```lua
-- fields
_action: System.Collections.Specialized.NotifyCollectionChangedAction
_newItems: System.Collections.IList
_newStartingIndex: System.Int32
_oldItems: System.Collections.IList
_oldStartingIndex: System.Int32
-- methods
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

```lua
-- methods
:System.Void Invoke(System.Object, System.Collections.Specialized.NotifyCollectionChangedEventArgs)
```

## `System.Collections.Specialized.ReadOnlyList`

```lua
-- fields
_list: System.Collections.IList
-- methods
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

```lua
-- fields
_defaultCapacity: System.Int32 [static]
_array: System.Object[]
_size: System.Int32
_version: System.Int32
-- methods
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
-- static
:System.Collections.Stack Synchronized(System.Collections.Stack)
```

## `System.Collections.Stack.StackEnumerator`

```lua
-- fields
_currentElement: System.Object
_index: System.Int32
_stack: System.Collections.Stack
_version: System.Int32
-- methods
:System.Object Clone()
:System.Boolean MoveNext()
:System.Void Reset()
:System.Object get_Current()
```

## `System.Collections.Stack.SyncStack`

```lua
-- fields
_root: System.Object
_s: System.Collections.Stack
-- methods
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

## `System.ComponentModel.PropertyChangedEventArgs`

```lua
-- fields
_propertyName: System.String
-- methods
:System.String get_PropertyName()
```

## `System.ComponentModel.PropertyChangedEventHandler`

```lua
-- methods
:System.Void Invoke(System.Object, System.ComponentModel.PropertyChangedEventArgs)
```

## `System.Console`

```lua
-- static
:System.Void Clear()
:System.IO.Stream OpenStandardOutput()
:System.IO.Stream OpenStandardOutput(System.Int32)
:System.String ReadLine()
:System.Void Write(System.Boolean)
:System.Void Write(System.Char)
:System.Void Write(System.Char[])
:System.Void Write(System.Decimal)
:System.Void Write(System.Double)
:System.Void Write(System.Single)
:System.Void Write(System.SByte)
:System.Void Write(System.Byte)
:System.Void Write(System.Int16)
:System.Void Write(System.UInt16)
:System.Void Write(System.Int32)
:System.Void Write(System.UInt32)
:System.Void Write(System.Int64)
:System.Void Write(System.UInt64)
:System.Void Write(System.Object)
:System.Void Write(System.String, System.Object[])
:System.Void Write(System.String, System.Object)
:System.Void Write(System.String, System.Object, System.Object)
:System.Void Write(System.String, System.Object, System.Object, System.Object)
:System.Void Write(System.String, System.Object, System.Object, System.Object, System.Object)
:System.Void Write(System.String)
:System.Void WriteLine()
:System.Void WriteLine(System.Boolean)
:System.Void WriteLine(System.Char)
:System.Void WriteLine(System.Char[])
:System.Void WriteLine(System.Decimal)
:System.Void WriteLine(System.Double)
:System.Void WriteLine(System.Single)
:System.Void WriteLine(System.SByte)
:System.Void WriteLine(System.Byte)
:System.Void WriteLine(System.Int16)
:System.Void WriteLine(System.UInt16)
:System.Void WriteLine(System.Int32)
:System.Void WriteLine(System.UInt32)
:System.Void WriteLine(System.Int64)
:System.Void WriteLine(System.UInt64)
:System.Void WriteLine(System.Object)
:System.Void WriteLine(System.String, System.Object[])
:System.Void WriteLine(System.String, System.Object)
:System.Void WriteLine(System.String, System.Object, System.Object)
:System.Void WriteLine(System.String, System.Object, System.Object, System.Object)
:System.Void WriteLine(System.String, System.Object, System.Object, System.Object, System.Object)
:System.Void WriteLine(System.String)
:System.ConsoleColor get_ForegroundColor()
:System.Void set_ForegroundColor(System.ConsoleColor)
```

## `System.Console.ConsoleStream`

```lua
-- methods
:System.Int32 Read(System.Byte[], System.Int32, System.Int32)
:System.Int64 Seek(System.Int64, System.IO.SeekOrigin)
:System.Void Write(System.Byte[], System.Int32, System.Int32)
:System.Void set_Position(System.Int64)
```

## `System.ConsoleColor`

```lua
-- values (System.Int32 enum)
Black
Blue
Cyan
DarkBlue
DarkCyan
DarkGray
DarkGreen
DarkMagenta
DarkRed
DarkYellow
Gray
Green
Magenta
Red
White
Yellow
```

## `System.Convert`

```lua
-- static
:System.Object ChangeType(System.Object, System.TypeCode)
:System.Object ChangeType(System.Object, System.TypeCode, System.IFormatProvider)
:System.Object ChangeType(System.Object, System.Type)
:System.Object ChangeType(System.Object, System.Type, System.IFormatProvider)
:System.Byte[] FromBase64String(System.String)
:System.TypeCode GetTypeCode(System.Object)
:System.String ToBase64String(System.Byte[])
:System.String ToBase64String(System.Byte[], System.Base64FormattingOptions)
:System.String ToBase64String(System.Byte[], System.Int32, System.Int32)
:System.String ToBase64String(System.Byte[], System.Int32, System.Int32, System.Base64FormattingOptions)
:System.Boolean ToBoolean(System.Object)
:System.Boolean ToBoolean(System.Object, System.IFormatProvider)
:System.Boolean ToBoolean(System.Boolean)
:System.Boolean ToBoolean(System.SByte)
:System.Boolean ToBoolean(System.Char)
:System.Boolean ToBoolean(System.Byte)
:System.Boolean ToBoolean(System.Int16)
:System.Boolean ToBoolean(System.UInt16)
:System.Boolean ToBoolean(System.Int32)
:System.Boolean ToBoolean(System.UInt32)
:System.Boolean ToBoolean(System.Int64)
:System.Boolean ToBoolean(System.UInt64)
:System.Boolean ToBoolean(System.String)
:System.Boolean ToBoolean(System.String, System.IFormatProvider)
:System.Boolean ToBoolean(System.Single)
:System.Boolean ToBoolean(System.Double)
:System.Boolean ToBoolean(System.Decimal)
:System.Boolean ToBoolean(System.DateTime)
:System.Byte ToByte(System.Object)
:System.Byte ToByte(System.Object, System.IFormatProvider)
:System.Byte ToByte(System.Boolean)
:System.Byte ToByte(System.Byte)
:System.Byte ToByte(System.Char)
:System.Byte ToByte(System.SByte)
:System.Byte ToByte(System.Int16)
:System.Byte ToByte(System.UInt16)
:System.Byte ToByte(System.Int32)
:System.Byte ToByte(System.UInt32)
:System.Byte ToByte(System.Int64)
:System.Byte ToByte(System.UInt64)
:System.Byte ToByte(System.Single)
:System.Byte ToByte(System.Double)
:System.Byte ToByte(System.Decimal)
:System.Byte ToByte(System.String)
:System.Byte ToByte(System.String, System.IFormatProvider)
:System.Byte ToByte(System.DateTime)
:System.Char ToChar(System.Object)
:System.Char ToChar(System.Object, System.IFormatProvider)
:System.Char ToChar(System.Boolean)
:System.Char ToChar(System.Char)
:System.Char ToChar(System.SByte)
:System.Char ToChar(System.Byte)
:System.Char ToChar(System.Int16)
:System.Char ToChar(System.UInt16)
:System.Char ToChar(System.Int32)
:System.Char ToChar(System.UInt32)
:System.Char ToChar(System.Int64)
:System.Char ToChar(System.UInt64)
:System.Char ToChar(System.String)
:System.Char ToChar(System.String, System.IFormatProvider)
:System.Char ToChar(System.Single)
:System.Char ToChar(System.Double)
:System.Char ToChar(System.Decimal)
:System.Char ToChar(System.DateTime)
:System.DateTime ToDateTime(System.Object)
:System.DateTime ToDateTime(System.Object, System.IFormatProvider)
:System.DateTime ToDateTime(System.DateTime)
:System.DateTime ToDateTime(System.String)
:System.DateTime ToDateTime(System.String, System.IFormatProvider)
:System.DateTime ToDateTime(System.SByte)
:System.DateTime ToDateTime(System.Byte)
:System.DateTime ToDateTime(System.Int16)
:System.DateTime ToDateTime(System.UInt16)
:System.DateTime ToDateTime(System.Int32)
:System.DateTime ToDateTime(System.UInt32)
:System.DateTime ToDateTime(System.Int64)
:System.DateTime ToDateTime(System.UInt64)
:System.DateTime ToDateTime(System.Boolean)
:System.DateTime ToDateTime(System.Char)
:System.DateTime ToDateTime(System.Single)
:System.DateTime ToDateTime(System.Double)
:System.DateTime ToDateTime(System.Decimal)
:System.Decimal ToDecimal(System.Object)
:System.Decimal ToDecimal(System.Object, System.IFormatProvider)
:System.Decimal ToDecimal(System.SByte)
:System.Decimal ToDecimal(System.Byte)
:System.Decimal ToDecimal(System.Char)
:System.Decimal ToDecimal(System.Int16)
:System.Decimal ToDecimal(System.UInt16)
:System.Decimal ToDecimal(System.Int32)
:System.Decimal ToDecimal(System.UInt32)
:System.Decimal ToDecimal(System.Int64)
:System.Decimal ToDecimal(System.UInt64)
:System.Decimal ToDecimal(System.Single)
:System.Decimal ToDecimal(System.Double)
:System.Decimal ToDecimal(System.String)
:System.Decimal ToDecimal(System.String, System.IFormatProvider)
:System.Decimal ToDecimal(System.Decimal)
:System.Decimal ToDecimal(System.Boolean)
:System.Decimal ToDecimal(System.DateTime)
:System.Double ToDouble(System.Object)
:System.Double ToDouble(System.Object, System.IFormatProvider)
:System.Double ToDouble(System.SByte)
:System.Double ToDouble(System.Byte)
:System.Double ToDouble(System.Int16)
:System.Double ToDouble(System.Char)
:System.Double ToDouble(System.UInt16)
:System.Double ToDouble(System.Int32)
:System.Double ToDouble(System.UInt32)
:System.Double ToDouble(System.Int64)
:System.Double ToDouble(System.UInt64)
:System.Double ToDouble(System.Single)
:System.Double ToDouble(System.Double)
:System.Double ToDouble(System.Decimal)
:System.Double ToDouble(System.String, System.IFormatProvider)
:System.Double ToDouble(System.Boolean)
:System.Double ToDouble(System.DateTime)
:System.Double ToDouble(System.String)
:System.Int16 ToInt16(System.Object)
:System.Int16 ToInt16(System.Object, System.IFormatProvider)
:System.Int16 ToInt16(System.Boolean)
:System.Int16 ToInt16(System.Char)
:System.Int16 ToInt16(System.SByte)
:System.Int16 ToInt16(System.Byte)
:System.Int16 ToInt16(System.UInt16)
:System.Int16 ToInt16(System.Int32)
:System.Int16 ToInt16(System.UInt32)
:System.Int16 ToInt16(System.Int16)
:System.Int16 ToInt16(System.Int64)
:System.Int16 ToInt16(System.UInt64)
:System.Int16 ToInt16(System.Single)
:System.Int16 ToInt16(System.Double)
:System.Int16 ToInt16(System.Decimal)
:System.Int16 ToInt16(System.String)
:System.Int16 ToInt16(System.String, System.IFormatProvider)
:System.Int16 ToInt16(System.DateTime)
:System.Int32 ToInt32(System.Object)
:System.Int32 ToInt32(System.Object, System.IFormatProvider)
:System.Int32 ToInt32(System.Boolean)
:System.Int32 ToInt32(System.Char)
:System.Int32 ToInt32(System.SByte)
:System.Int32 ToInt32(System.Byte)
:System.Int32 ToInt32(System.Int16)
:System.Int32 ToInt32(System.UInt16)
:System.Int32 ToInt32(System.UInt32)
:System.Int32 ToInt32(System.Int32)
:System.Int32 ToInt32(System.Int64)
:System.Int32 ToInt32(System.UInt64)
:System.Int32 ToInt32(System.Single)
:System.Int32 ToInt32(System.Double)
:System.Int32 ToInt32(System.Decimal)
:System.Int32 ToInt32(System.String)
:System.Int32 ToInt32(System.String, System.IFormatProvider)
:System.Int32 ToInt32(System.DateTime)
:System.Int32 ToInt32(System.String, System.Int32)
:System.Int64 ToInt64(System.Object)
:System.Int64 ToInt64(System.Object, System.IFormatProvider)
:System.Int64 ToInt64(System.Boolean)
:System.Int64 ToInt64(System.Char)
:System.Int64 ToInt64(System.SByte)
:System.Int64 ToInt64(System.Byte)
:System.Int64 ToInt64(System.Int16)
:System.Int64 ToInt64(System.UInt16)
:System.Int64 ToInt64(System.Int32)
:System.Int64 ToInt64(System.UInt32)
:System.Int64 ToInt64(System.UInt64)
:System.Int64 ToInt64(System.Int64)
:System.Int64 ToInt64(System.Single)
:System.Int64 ToInt64(System.Double)
:System.Int64 ToInt64(System.Decimal)
:System.Int64 ToInt64(System.String)
:System.Int64 ToInt64(System.String, System.IFormatProvider)
:System.Int64 ToInt64(System.DateTime)
:System.Int64 ToInt64(System.String, System.Boolean, System.Int64, System.Int64)
:System.SByte ToSByte(System.Object)
:System.SByte ToSByte(System.Object, System.IFormatProvider)
:System.SByte ToSByte(System.Boolean)
:System.SByte ToSByte(System.SByte)
:System.SByte ToSByte(System.Char)
:System.SByte ToSByte(System.Byte)
:System.SByte ToSByte(System.Int16)
:System.SByte ToSByte(System.UInt16)
:System.SByte ToSByte(System.Int32)
:System.SByte ToSByte(System.UInt32)
:System.SByte ToSByte(System.Int64)
:System.SByte ToSByte(System.UInt64)
:System.SByte ToSByte(System.Single)
:System.SByte ToSByte(System.Double)
:System.SByte ToSByte(System.Decimal)
:System.SByte ToSByte(System.String)
:System.SByte ToSByte(System.String, System.IFormatProvider)
:System.SByte ToSByte(System.DateTime)
:System.Single ToSingle(System.Object)
:System.Single ToSingle(System.Object, System.IFormatProvider)
:System.Single ToSingle(System.SByte)
:System.Single ToSingle(System.Byte)
:System.Single ToSingle(System.Char)
:System.Single ToSingle(System.Int16)
:System.Single ToSingle(System.UInt16)
:System.Single ToSingle(System.Int32)
:System.Single ToSingle(System.UInt32)
:System.Single ToSingle(System.Int64)
:System.Single ToSingle(System.UInt64)
:System.Single ToSingle(System.Single)
:System.Single ToSingle(System.Double)
:System.Single ToSingle(System.Decimal)
:System.Single ToSingle(System.String)
:System.Single ToSingle(System.String, System.IFormatProvider)
:System.Single ToSingle(System.Boolean)
:System.Single ToSingle(System.DateTime)
:System.String ToString(System.Object)
:System.String ToString(System.Object, System.IFormatProvider)
:System.String ToString(System.Boolean)
:System.String ToString(System.Boolean, System.IFormatProvider)
:System.String ToString(System.Char)
:System.String ToString(System.Char, System.IFormatProvider)
:System.String ToString(System.SByte)
:System.String ToString(System.SByte, System.IFormatProvider)
:System.String ToString(System.Byte)
:System.String ToString(System.Byte, System.IFormatProvider)
:System.String ToString(System.Int16)
:System.String ToString(System.Int16, System.IFormatProvider)
:System.String ToString(System.UInt16)
:System.String ToString(System.UInt16, System.IFormatProvider)
:System.String ToString(System.Int32)
:System.String ToString(System.Int32, System.IFormatProvider)
:System.String ToString(System.UInt32)
:System.String ToString(System.UInt32, System.IFormatProvider)
:System.String ToString(System.Int64)
:System.String ToString(System.Int64, System.IFormatProvider)
:System.String ToString(System.UInt64)
:System.String ToString(System.UInt64, System.IFormatProvider)
:System.String ToString(System.Single)
:System.String ToString(System.Single, System.IFormatProvider)
:System.String ToString(System.Double)
:System.String ToString(System.Double, System.IFormatProvider)
:System.String ToString(System.Decimal)
:System.String ToString(System.Decimal, System.IFormatProvider)
:System.String ToString(System.DateTime)
:System.String ToString(System.DateTime, System.IFormatProvider)
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.Object ToType(System.Object, System.Type, System.IFormatProvider)
:System.UInt16 ToUInt16(System.Object)
:System.UInt16 ToUInt16(System.Object, System.IFormatProvider)
:System.UInt16 ToUInt16(System.Boolean)
:System.UInt16 ToUInt16(System.Char)
:System.UInt16 ToUInt16(System.SByte)
:System.UInt16 ToUInt16(System.Byte)
:System.UInt16 ToUInt16(System.Int16)
:System.UInt16 ToUInt16(System.Int32)
:System.UInt16 ToUInt16(System.UInt16)
:System.UInt16 ToUInt16(System.UInt32)
:System.UInt16 ToUInt16(System.Int64)
:System.UInt16 ToUInt16(System.UInt64)
:System.UInt16 ToUInt16(System.Single)
:System.UInt16 ToUInt16(System.Double)
:System.UInt16 ToUInt16(System.Decimal)
:System.UInt16 ToUInt16(System.String)
:System.UInt16 ToUInt16(System.String, System.IFormatProvider)
:System.UInt16 ToUInt16(System.DateTime)
:System.UInt32 ToUInt32(System.Object)
:System.UInt32 ToUInt32(System.Object, System.IFormatProvider)
:System.UInt32 ToUInt32(System.Boolean)
:System.UInt32 ToUInt32(System.Char)
:System.UInt32 ToUInt32(System.SByte)
:System.UInt32 ToUInt32(System.Byte)
:System.UInt32 ToUInt32(System.Int16)
:System.UInt32 ToUInt32(System.UInt16)
:System.UInt32 ToUInt32(System.Int32)
:System.UInt32 ToUInt32(System.UInt32)
:System.UInt32 ToUInt32(System.Int64)
:System.UInt32 ToUInt32(System.UInt64)
:System.UInt32 ToUInt32(System.Single)
:System.UInt32 ToUInt32(System.Double)
:System.UInt32 ToUInt32(System.Decimal)
:System.UInt32 ToUInt32(System.String)
:System.UInt32 ToUInt32(System.String, System.IFormatProvider)
:System.UInt32 ToUInt32(System.DateTime)
:System.UInt64 ToUInt64(System.Object)
:System.UInt64 ToUInt64(System.Object, System.IFormatProvider)
:System.UInt64 ToUInt64(System.Boolean)
:System.UInt64 ToUInt64(System.Char)
:System.UInt64 ToUInt64(System.SByte)
:System.UInt64 ToUInt64(System.Byte)
:System.UInt64 ToUInt64(System.Int16)
:System.UInt64 ToUInt64(System.UInt16)
:System.UInt64 ToUInt64(System.Int32)
:System.UInt64 ToUInt64(System.UInt32)
:System.UInt64 ToUInt64(System.Int64)
:System.UInt64 ToUInt64(System.UInt64)
:System.UInt64 ToUInt64(System.Single)
:System.UInt64 ToUInt64(System.Double)
:System.UInt64 ToUInt64(System.Decimal)
:System.UInt64 ToUInt64(System.String)
:System.UInt64 ToUInt64(System.String, System.IFormatProvider)
:System.UInt64 ToUInt64(System.DateTime)
:System.Boolean TryNumberToDouble(System.String, System.Double)
:System.Boolean TryNumberToInt64(System.String, System.Boolean, System.Int64, System.Int64, System.Int64)
```

## `System.Currency`

```lua
-- fields
m_value: System.Int64
-- methods
:System.Int64 ToOACurrency()
-- static
:System.Void FCallToDecimal(System.Decimal, System.Currency)
:System.Currency FromOACurrency(System.Int64)
:System.Decimal ToDecimal(System.Currency)
```

## `System.DBNull`

```lua
-- fields
Value: System.DBNull [static]
-- methods
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

## `System.DateTime`

```lua
-- fields
DayOfWeekLongNameTbl: System.String[] [static]
DayOfWeekShortNameTbl: System.String[] [static]
MaxValue: System.DateTime [static]
MinValue: System.DateTime [static]
MonthLongNameTbl: System.String[] [static]
MonthShortNameTbl: System.String[] [static]
mDate: System.UInt64
-- methods
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
-- static
:System.Int32 Compare(System.DateTime, System.DateTime)
:System.Int32 DaysInMonth(System.Int32, System.Int32)
:System.Boolean Equals(System.DateTime, System.DateTime)
:System.DateTime Parse(System.String)
:System.DateTime Parse(System.String, System.IFormatProvider)
:System.DateTime Parse(System.String, System.IFormatProvider, System.Globalization.DateTimeStyles)
:System.DateTime ParseExact(System.String, System.String, System.IFormatProvider)
:System.DateTime ParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.DateTimeStyles)
:System.DateTime ParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.DateTimeStyles)
:System.DateTime SpecifyKind(System.DateTime, System.DateTimeKind)
:System.Int32 SplitToken(System.String, System.String[])
:System.String ToCustomString(System.DateTime, System.String)
:System.Boolean TryParse(System.String, System.DateTime)
:System.Boolean TryParse(System.String, System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
:System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
:System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.DateTimeStyles, System.DateTime)
:System.Boolean TryParseInternal(System.String, System.String, System.DateTime, System.Globalization.DateTimeStyles)
:System.DateTime get_Now()
:System.DateTime get_Today()
:System.DateTime get_UtcNow()
:System.DateTime op_Addition(System.DateTime, System.TimeSpan)
:System.Boolean op_Equality(System.DateTime, System.DateTime)
:System.Boolean op_GreaterThan(System.DateTime, System.DateTime)
:System.Boolean op_GreaterThanOrEqual(System.DateTime, System.DateTime)
:System.Boolean op_Inequality(System.DateTime, System.DateTime)
:System.Boolean op_LessThan(System.DateTime, System.DateTime)
:System.Boolean op_LessThanOrEqual(System.DateTime, System.DateTime)
:System.DateTime op_Subtraction(System.DateTime, System.TimeSpan)
:System.TimeSpan op_Subtraction(System.DateTime, System.DateTime)
```

## `System.DateTimeKind`

```lua
-- values (System.Int32 enum)
Local
Unspecified
Utc
```

## `System.DayOfWeek`

```lua
-- values (System.Int32 enum)
Friday
Monday
Saturday
Sunday
Thursday
Tuesday
Wednesday
```

## `System.Decimal`

```lua
-- fields
DECIMAL_ADD: System.Byte [static]
DECIMAL_NEG: System.Byte [static]
MaxInt32Scale: System.Int32 [static]
MaxValue: System.Decimal [static]
MinValue: System.Decimal [static]
MinusOne: System.Decimal [static]
NearNegativeZero: System.Decimal [static]
NearPositiveZero: System.Decimal [static]
One: System.Decimal [static]
Powers10: System.UInt32[] [static]
ScaleMask: System.Int32 [static]
ScaleShift: System.Int32 [static]
SignMask: System.Int32 [static]
Zero: System.Decimal [static]
flags: System.Int32
hi: System.Int32
lo: System.Int32
mid: System.Int32
-- methods
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
-- static
:System.Decimal Abs(System.Decimal)
:System.Decimal Add(System.Decimal, System.Decimal)
:System.Decimal Ceiling(System.Decimal)
:System.Int32 Compare(System.Decimal, System.Decimal)
:System.Decimal Divide(System.Decimal, System.Decimal)
:System.Boolean Equals(System.Decimal, System.Decimal)
:System.Void FCallAddSub(System.Decimal, System.Decimal, System.Byte)
:System.Int32 FCallCompare(System.Decimal, System.Decimal)
:System.Void FCallDivide(System.Decimal, System.Decimal)
:System.Void FCallFloor(System.Decimal)
:System.Void FCallMultiply(System.Decimal, System.Decimal)
:System.Void FCallRound(System.Decimal, System.Int32)
:System.Void FCallToCurrency(System.Currency, System.Decimal)
:System.Int32 FCallToInt32(System.Decimal)
:System.Void FCallTruncate(System.Decimal)
:System.Decimal Floor(System.Decimal)
:System.Decimal FromOACurrency(System.Int64)
:System.Int32[] GetBits(System.Decimal)
:System.Void GetBytes(System.Decimal, System.Byte[])
:System.Void InternalAddUInt32RawUnchecked(System.Decimal, System.UInt32)
:System.UInt32 InternalDivRemUInt32(System.Decimal, System.UInt32)
:System.Void InternalRoundFromZero(System.Decimal, System.Int32)
:System.Decimal Max(System.Decimal, System.Decimal)
:System.Decimal Min(System.Decimal, System.Decimal)
:System.Decimal Multiply(System.Decimal, System.Decimal)
:System.Decimal Negate(System.Decimal)
:System.Decimal Parse(System.String)
:System.Decimal Parse(System.String, System.NumberStyles)
:System.Decimal Parse(System.String, System.IFormatProvider)
:System.Decimal Parse(System.String, System.NumberStyles, System.IFormatProvider)
:System.Decimal Remainder(System.Decimal, System.Decimal)
:System.Decimal Round(System.Decimal)
:System.Decimal Round(System.Decimal, System.Int32)
:System.Decimal Round(System.Decimal, System.MidpointRounding)
:System.Decimal Round(System.Decimal, System.Int32, System.MidpointRounding)
:System.Int32 Sign(System.Decimal)
:System.Decimal Subtract(System.Decimal, System.Decimal)
:System.Byte ToByte(System.Decimal)
:System.Currency ToCurrency(System.Decimal)
:System.Decimal ToDecimal(System.Byte[])
:System.Double ToDouble(System.Decimal)
:System.Int16 ToInt16(System.Decimal)
:System.Int32 ToInt32(System.Decimal)
:System.Int64 ToInt64(System.Decimal)
:System.Int64 ToOACurrency(System.Decimal)
:System.SByte ToSByte(System.Decimal)
:System.Single ToSingle(System.Decimal)
:System.UInt16 ToUInt16(System.Decimal)
:System.UInt32 ToUInt32(System.Decimal)
:System.UInt64 ToUInt64(System.Decimal)
:System.Decimal Truncate(System.Decimal)
:System.Boolean TryParse(System.String, System.Decimal)
:System.Boolean TryParse(System.String, System.NumberStyles, System.IFormatProvider, System.Decimal)
:System.Decimal op_Addition(System.Decimal, System.Decimal)
:System.Decimal op_Decrement(System.Decimal)
:System.Decimal op_Division(System.Decimal, System.Decimal)
:System.Boolean op_Equality(System.Decimal, System.Decimal)
:System.Decimal op_Explicit(System.Single)
:System.Decimal op_Explicit(System.Double)
:System.Byte op_Explicit(System.Decimal)
:System.Boolean op_GreaterThan(System.Decimal, System.Decimal)
:System.Boolean op_GreaterThanOrEqual(System.Decimal, System.Decimal)
:System.Decimal op_Implicit(System.Byte)
:System.Decimal op_Implicit(System.SByte)
:System.Decimal op_Implicit(System.Int16)
:System.Decimal op_Implicit(System.UInt16)
:System.Decimal op_Implicit(System.Char)
:System.Decimal op_Implicit(System.Int32)
:System.Decimal op_Implicit(System.UInt32)
:System.Decimal op_Implicit(System.Int64)
:System.Decimal op_Implicit(System.UInt64)
:System.Decimal op_Increment(System.Decimal)
:System.Boolean op_Inequality(System.Decimal, System.Decimal)
:System.Boolean op_LessThan(System.Decimal, System.Decimal)
:System.Boolean op_LessThanOrEqual(System.Decimal, System.Decimal)
:System.Decimal op_Modulus(System.Decimal, System.Decimal)
:System.Decimal op_Multiply(System.Decimal, System.Decimal)
:System.Decimal op_Subtraction(System.Decimal, System.Decimal)
:System.Decimal op_UnaryNegation(System.Decimal)
:System.Decimal op_UnaryPlus(System.Decimal)
```

## `System.Delegate`

```lua
-- methods
:System.Object DynamicInvoke(System.Object[])
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Delegate[] GetInvocationList()
:System.Reflection.MethodInfo get_Method()
:System.Object get_Target()
-- static
:System.Delegate Combine(System.Delegate, System.Delegate)
:System.Delegate CreateDelegate(System.Type, System.Object, System.String)
:System.Delegate CreateDelegate(System.Type, System.Object, System.String, System.Boolean)
:System.Delegate CreateDelegate(System.Type, System.Object, System.String, System.Boolean, System.Boolean)
:System.Delegate CreateDelegate(System.Type, System.Type, System.String)
:System.Delegate CreateDelegate(System.Type, System.Type, System.String, System.Boolean)
:System.Delegate CreateDelegate(System.Type, System.Type, System.String, System.Boolean, System.Boolean)
:System.Delegate CreateDelegate(System.Type, System.Reflection.MethodInfo, System.Boolean)
:System.Delegate CreateDelegate(System.Type, System.Object, System.Reflection.MethodInfo)
:System.Delegate CreateDelegate(System.Type, System.Object, System.Reflection.MethodInfo, System.Boolean)
:System.Delegate CreateDelegateInternal(System.Type, System.Object, System.Reflection.MethodInfo, System.Boolean)
:System.Delegate Remove(System.Delegate, System.Delegate)
:System.Delegate RemoveAll(System.Delegate, System.Delegate)
:System.Boolean op_Equality(System.Delegate, System.Delegate)
:System.Boolean op_Inequality(System.Delegate, System.Delegate)
```

## `System.Diagnostics.ConditionalAttribute`

```lua
-- fields
mCondition: System.String
-- methods
:System.String get_ConditionString()
```

## `System.Diagnostics.Debug`

```lua
-- static
:System.Void Assert(System.Boolean)
:System.Void Assert(System.Boolean, System.String)
:System.Void Assert(System.Boolean, System.String, System.String)
:System.Void Assert(System.Boolean, System.String, System.String, System.Object[])
```

## `System.Diagnostics.DebuggableAttribute.DebuggingModes`

```lua
-- values (System.Int32 enum)
Default
DisableOptimizations
EnableEditAndContinue
IgnoreSymbolStoreSequencePoints
None
```

## `System.Diagnostics.Debugger`

```lua
-- fields
DefaultCategory: System.String [static]
-- static
:System.Void Break()
:System.Void BreakCanThrow()
:System.Void BreakInternal()
:System.Boolean IsLogging()
:System.Boolean Launch()
:System.Boolean LaunchInternal()
:System.Void Log(System.Int32, System.String, System.String)
:System.Void NotifyOfCrossThreadDependency()
:System.Boolean get_IsAttached()
```

## `System.Diagnostics.DebuggerBrowsableAttribute`

```lua
-- fields
mState: System.Diagnostics.DebuggerBrowsableState
-- methods
:System.Diagnostics.DebuggerBrowsableState get_State()
```

## `System.Diagnostics.DebuggerBrowsableState`

```lua
-- values (System.Int32 enum)
Collapsed
Never
RootHidden
```

## `System.Diagnostics.DebuggerDisplayAttribute`

```lua
-- fields
mName: System.String
mTarget: System.Type
mTargetName: System.String
mType: System.String
mValue: System.String
-- methods
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

## `System.Diagnostics.Stopwatch`

```lua
-- fields
Frequency: System.Int64 [static]
mElapsed: System.Int64
mIsRunning: System.Boolean
mStartTimeStamp: System.Int64
-- methods
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
-- static
:System.Int64 GetTimestamp()
:System.Diagnostics.Stopwatch StartNew()
:System.Int64 queryPerformanceCounter()
:System.Int64 queryPerformanceFrequency()
```

## `System.Double`

```lua
-- fields
Epsilon: System.Double [static]
MaxValue: System.Double [static]
MinValue: System.Double [static]
NaN: System.Double [static]
NegativeInfinity: System.Double [static]
PositiveInfinity: System.Double [static]
mValue: System.Double
-- methods
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
-- static
:System.Boolean IsInfinity(System.Double)
:System.Boolean IsNaN(System.Double)
:System.Boolean IsNegativeInfinity(System.Double)
:System.Boolean IsPositiveInfinity(System.Double)
:System.Double Parse(System.String)
:System.Boolean TryParse(System.String, System.Double)
```

## `System.Enum`

```lua
-- methods
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
-- static
:System.String GetName(System.Type, System.Object)
:System.String[] GetNames(System.Type)
:System.Type GetUnderlyingType(System.Type)
:System.Array GetValues(System.Type)
:System.Boolean IsDefined(System.Type, System.Object)
:System.Object Parse(System.Type, System.String)
:System.Object Parse(System.Type, System.String, System.Boolean)
:System.Object ToObject(System.Type, System.Object)
:System.Object ToObject(System.Type, System.SByte)
:System.Object ToObject(System.Type, System.Int16)
:System.Object ToObject(System.Type, System.Int32)
:System.Object ToObject(System.Type, System.Byte)
:System.Object ToObject(System.Type, System.UInt16)
:System.Object ToObject(System.Type, System.UInt32)
:System.Object ToObject(System.Type, System.Int64)
:System.Object ToObject(System.Type, System.UInt64)
:System.Boolean TryParseInternal(System.Type, System.String, System.Boolean, System.Object)
:System.Object boxEnum(System.Type, System.Int64)
```

## `System.Environment`

```lua
-- static
:System.Void Exit(System.Int32)
:System.String[] GetCommandLineArgs()
:System.String GetEnvironmentVariable(System.String)
:System.String get_CommandLine()
:System.String get_CurrentDirectory()
:System.Int32 get_CurrentManagedThreadId()
:System.Int32 get_ExitCode()
:System.Boolean get_HasShutdownStarted()
:System.String get_MachineName()
:System.String get_NewLine()
:System.Int32 get_ProcessorCount()
:System.String get_StackTrace()
:System.String get_SystemDirectory()
:System.Int32 get_SystemPageSize()
:System.Int32 get_TickCount()
:System.String get_UserDomainName()
:System.Boolean get_UserInteractive()
:System.String get_UserName()
:System.Int64 get_WorkingSet()
:System.Void set_CurrentDirectory(System.String)
:System.Void set_ExitCode(System.Int32)
```

## `System.EventArgs`

```lua
-- fields
Empty: System.EventArgs [static]
```

## `System.Exception`

```lua
-- fields
mCodeOffset: System.Int32
mFrameDump: System.Byte[]
mFramePtr: System.IntPtr
mInnerException: System.Exception
mMessage: System.String
mReserved: System.IntPtr
mThreadId: System.UInt32
-- methods
:System.String GetStackTrace()
:System.Type GetType()
:System.String ToString()
:System.Exception get_InnerException()
:System.String get_Message()
:System.String get_StackTrace()
```

## `System.GC`

```lua
-- static
:System.Void AddMemoryPressure(System.Int64)
:System.Void Collect()
:System.Void Collect(System.Int32)
:System.Int32 CollectionCount(System.Int32)
:System.Int32 GetGeneration(System.Object)
:System.Int64 GetTotalMemory(System.Boolean)
:System.Void KeepAlive(System.Object)
:System.Void ReRegisterForFinalize(System.Object)
:System.Void RemoveMemoryPressure(System.Int64)
:System.Void SuppressFinalize(System.Object)
:System.Void WaitForPendingFinalizers()
:System.Int32 get_MaxGeneration()
```

## `System.Globalization.CharUnicodeInfo`

```lua
-- fields
BIDI_CATEGORY_OFFSET: System.Int32 [static]
HIGH_SURROGATE_END: System.Char [static]
HIGH_SURROGATE_START: System.Char [static]
LOW_SURROGATE_END: System.Char [static]
LOW_SURROGATE_START: System.Char [static]
UNICODE_CATEGORY_OFFSET: System.Int32 [static]
UNICODE_PLANE01_START: System.Int32 [static]
s_pCategoriesValue: System.Byte[] [static]
s_pCategoryLevel1Index: System.UInt16[] [static]
s_pDigitValues: System.UInt16[] [static]
s_pNumericLevel1Index: System.UInt16[] [static]
s_pNumericValues: System.Byte[] [static]
-- static
:System.Int32 GetDecimalDigitValue(System.Char)
:System.Int32 GetDecimalDigitValue(System.String, System.Int32)
:System.Int32 GetDigitValue(System.Char)
:System.Int32 GetDigitValue(System.String, System.Int32)
:System.Double GetNumericValue(System.Char)
:System.Double GetNumericValue(System.String, System.Int32)
:System.Globalization.UnicodeCategory GetUnicodeCategory(System.Char)
:System.Globalization.UnicodeCategory GetUnicodeCategory(System.String, System.Int32)
:System.Int32 InternalConvertToUtf32(System.String, System.Int32)
:System.Int32 InternalConvertToUtf32(System.String, System.Int32, System.Int32)
:System.Byte InternalGetCategoryValue(System.Int32, System.Int32)
:System.UInt16 InternalGetDigitValues(System.Int32)
:System.Double InternalGetNumericValue(System.Int32)
:System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.Int32)
:System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.String, System.Int32)
:System.Globalization.UnicodeCategory InternalGetUnicodeCategory(System.String, System.Int32, System.Int32)
:System.Boolean IsCombiningCategory(System.Globalization.UnicodeCategory)
:System.Boolean IsWhiteSpace(System.String, System.Int32)
:System.Boolean IsWhiteSpace(System.Char)
```

## `System.Globalization.CultureInfo`

```lua
-- fields
_invariantCulture: System.Globalization.CultureInfo [static]
-- methods
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
-- static
:System.Globalization.CultureInfo CreateSpecificCulture(System.String)
:System.Globalization.CultureInfo GetCultureInfo(System.Int32)
:System.Globalization.CultureInfo GetCultureInfo(System.String)
:System.Globalization.CultureInfo GetCultureInfo(System.String, System.String)
:System.Globalization.CultureInfo GetCultureInfoByIetfLanguageTag(System.String)
:System.Globalization.CultureInfo[] GetCultures(System.Globalization.CultureTypes)
:System.Globalization.CultureInfo ReadOnly(System.Globalization.CultureInfo)
:System.Globalization.CultureInfo get_DefaultThreadCurrentCulture()
:System.Globalization.CultureInfo get_DefaultThreadCurrentUICulture()
:System.Globalization.CultureInfo get_InstalledUICulture()
:System.Globalization.CultureInfo get_InvariantCulture()
:System.Void set_DefaultThreadCurrentCulture(System.Globalization.CultureInfo)
:System.Void set_DefaultThreadCurrentUICulture(System.Globalization.CultureInfo)
```

## `System.Globalization.CultureTypes`

```lua
-- values (System.Int32 enum)
AllCultures
FrameworkCultures
InstalledWin32Cultures
NeutralCultures
ReplacementCultures
SpecificCultures
UserCustomCulture
WindowsOnlyCultures
```

## `System.Globalization.DateTimeStyles`

```lua
-- values (System.Int32 enum)
AdjustToUniversal
AllowInnerWhite
AllowLeadingWhite
AllowTrailingWhite
AllowWhiteSpaces
AssumeLocal
AssumeUniversal
NoCurrentDateDefault
None
RoundtripKind
```

## `System.Globalization.TimeSpanStyles`

```lua
-- values (System.Int32 enum)
AssumeNegative
None
```

## `System.Globalization.UnicodeCategory`

```lua
-- values (System.Int32 enum)
ClosePunctuation
ConnectorPunctuation
Control
CurrencySymbol
DashPunctuation
DecimalDigitNumber
EnclosingMark
FinalQuotePunctuation
Format
InitialQuotePunctuation
LetterNumber
LineSeparator
LowercaseLetter
MathSymbol
ModifierLetter
ModifierSymbol
NonSpacingMark
OpenPunctuation
OtherLetter
OtherNotAssigned
OtherNumber
OtherPunctuation
OtherSymbol
ParagraphSeparator
PrivateUse
SpaceSeparator
SpacingCombiningMark
Surrogate
TitlecaseLetter
UppercaseLetter
```

## `System.Guid`

```lua
-- fields
Empty: System.Guid [static]
mData1: System.UInt32
mData2: System.UInt16
mData3: System.UInt16
mData4L: System.UInt64
mData4_0: System.Byte
mData4_1: System.Byte
mData4_2: System.Byte
mData4_3: System.Byte
mData4_4: System.Byte
mData4_5: System.Byte
mData4_6: System.Byte
mData4_7: System.Byte
-- methods
:System.Int32 CompareTo(System.Object)
:System.Int32 CompareTo(System.Guid)
:System.Boolean Equals(System.Guid)
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Byte[] ToByteArray()
:System.String ToString(System.String)
:System.String ToString(System.String, System.IFormatProvider)
:System.String ToString()
-- static
:System.Guid NewGuid()
:System.Guid Parse(System.String)
:System.Boolean op_Equality(System.Guid, System.Guid)
:System.Boolean op_GreaterThan(System.Guid, System.Guid)
:System.Boolean op_Inequality(System.Guid, System.Guid)
:System.Boolean op_LessThan(System.Guid, System.Guid)
```

## `System.IO.SeekOrigin`

```lua
-- values (System.Int32 enum)
Begin
Current
End
```

## `System.IO.Stream`

```lua
-- methods
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

## `System.Int16`

```lua
-- fields
MaxValue: System.Int16 [static]
MinValue: System.Int16 [static]
mValue: System.Int16
-- methods
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
-- static
:System.Int16 Parse(System.String)
:System.Boolean TryParse(System.String, System.Int16)
```

## `System.Int32`

```lua
-- fields
MaxValue: System.Int32 [static]
MinValue: System.Int32 [static]
mValue: System.Int32
-- methods
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
-- static
:System.Int32 Parse(System.String)
:System.Boolean TryParse(System.String, System.Int32)
```

## `System.Int32[,]`

```lua
-- methods
:System.Int32 Address(System.Int32, System.Int32)
:System.Int32 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Int32)
```

## `System.Int64`

```lua
-- fields
MaxValue: System.Int64 [static]
MinValue: System.Int64 [static]
mValue: System.Int64
-- methods
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
-- static
:System.Int64 Parse(System.String)
:System.Boolean TryParse(System.String, System.Int64)
```

## `System.IntPtr`

```lua
-- fields
mValue: System.Int64
-- methods
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.String ToString()
-- static
:System.Int32 get_Size()
:System.Boolean op_Equality(System.IntPtr, System.IntPtr)
:System.IntPtr op_Explicit(System.Int32)
:System.Boolean op_Inequality(System.IntPtr, System.IntPtr)
```

## `System.Linq.Enumerable`

```lua
-- static
:System.Double Average(System.Collections.Generic.IEnumerable`1<System.Int32>)
:System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
:System.Double Average(System.Collections.Generic.IEnumerable`1<System.Int64>)
:System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
:System.Single Average(System.Collections.Generic.IEnumerable`1<System.Single>)
:System.Nullable`1<System.Single> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
:System.Double Average(System.Collections.Generic.IEnumerable`1<System.Double>)
:System.Nullable`1<System.Double> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
:System.Decimal Average(System.Collections.Generic.IEnumerable`1<System.Decimal>)
:System.Nullable`1<System.Decimal> Average(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
:System.Int32 Max(System.Collections.Generic.IEnumerable`1<System.Int32>)
:System.Nullable`1<System.Int32> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
:System.Int64 Max(System.Collections.Generic.IEnumerable`1<System.Int64>)
:System.Nullable`1<System.Int64> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
:System.Double Max(System.Collections.Generic.IEnumerable`1<System.Double>)
:System.Nullable`1<System.Double> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
:System.Single Max(System.Collections.Generic.IEnumerable`1<System.Single>)
:System.Nullable`1<System.Single> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
:System.Decimal Max(System.Collections.Generic.IEnumerable`1<System.Decimal>)
:System.Nullable`1<System.Decimal> Max(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
:System.Int32 Min(System.Collections.Generic.IEnumerable`1<System.Int32>)
:System.Nullable`1<System.Int32> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
:System.Int64 Min(System.Collections.Generic.IEnumerable`1<System.Int64>)
:System.Nullable`1<System.Int64> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
:System.Single Min(System.Collections.Generic.IEnumerable`1<System.Single>)
:System.Nullable`1<System.Single> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
:System.Double Min(System.Collections.Generic.IEnumerable`1<System.Double>)
:System.Nullable`1<System.Double> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
:System.Decimal Min(System.Collections.Generic.IEnumerable`1<System.Decimal>)
:System.Nullable`1<System.Decimal> Min(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
:System.Collections.Generic.IEnumerable`1<System.Int32> Range(System.Int32, System.Int32)
:System.Int32 Sum(System.Collections.Generic.IEnumerable`1<System.Int32>)
:System.Nullable`1<System.Int32> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int32>>)
:System.Int64 Sum(System.Collections.Generic.IEnumerable`1<System.Int64>)
:System.Nullable`1<System.Int64> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Int64>>)
:System.Single Sum(System.Collections.Generic.IEnumerable`1<System.Single>)
:System.Nullable`1<System.Single> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Single>>)
:System.Double Sum(System.Collections.Generic.IEnumerable`1<System.Double>)
:System.Nullable`1<System.Double> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Double>>)
:System.Decimal Sum(System.Collections.Generic.IEnumerable`1<System.Decimal>)
:System.Nullable`1<System.Decimal> Sum(System.Collections.Generic.IEnumerable`1<System.Nullable`1<System.Decimal>>)
```

## `System.Linq.Enumerable.RangeIterator`

```lua
-- fields
_end: System.Int32
_start: System.Int32
-- methods
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

```lua
-- static
:System.Exception ArgumentNull(System.String)
:System.Exception ArgumentOutOfRange(System.String)
:System.Exception MoreThanOneElement()
:System.Exception MoreThanOneMatch()
:System.Exception NoElements()
:System.Exception NoMatch()
:System.Exception NotSupported()
```

## `System.Math`

```lua
-- fields
E: System.Double [static]
PI: System.Double [static]
-- static
:System.Double Abs(System.Double)
:System.Int16 Abs(System.Int16)
:System.Int32 Abs(System.Int32)
:System.Int64 Abs(System.Int64)
:System.SByte Abs(System.SByte)
:System.Single Abs(System.Single)
:System.Double Ceiling(System.Double)
:System.Double Cos(System.Double)
:System.Double Cosh(System.Double)
:System.Double Exp(System.Double)
:System.Double Floor(System.Double)
:System.Double Log(System.Double)
:System.Double Log10(System.Double)
:System.Byte Max(System.Byte, System.Byte)
:System.SByte Max(System.SByte, System.SByte)
:System.Int16 Max(System.Int16, System.Int16)
:System.UInt16 Max(System.UInt16, System.UInt16)
:System.Int32 Max(System.Int32, System.Int32)
:System.UInt32 Max(System.UInt32, System.UInt32)
:System.Int64 Max(System.Int64, System.Int64)
:System.UInt64 Max(System.UInt64, System.UInt64)
:System.Single Max(System.Single, System.Single)
:System.Double Max(System.Double, System.Double)
:System.Byte Min(System.Byte, System.Byte)
:System.SByte Min(System.SByte, System.SByte)
:System.Int16 Min(System.Int16, System.Int16)
:System.UInt16 Min(System.UInt16, System.UInt16)
:System.Int32 Min(System.Int32, System.Int32)
:System.UInt32 Min(System.UInt32, System.UInt32)
:System.Int64 Min(System.Int64, System.Int64)
:System.UInt64 Min(System.UInt64, System.UInt64)
:System.Single Min(System.Single, System.Single)
:System.Double Min(System.Double, System.Double)
:System.Double Pow(System.Double, System.Double)
:System.Double Round(System.Double)
:System.Int32 Sign(System.SByte)
:System.Int32 Sign(System.Int16)
:System.Int32 Sign(System.Int32)
:System.Int32 Sign(System.Int64)
:System.Int32 Sign(System.Single)
:System.Int32 Sign(System.Double)
:System.Double Sin(System.Double)
:System.Double Sinh(System.Double)
:System.Double Sqrt(System.Double)
:System.Double Tan(System.Double)
:System.Double Tanh(System.Double)
:System.Double Truncate(System.Double)
```

## `System.MidpointRounding`

```lua
-- values (System.Int32 enum)
AwayFromZero
ToEven
```

## `System.ModuleHandle`

```lua
-- fields
EmptyHandle: System.ModuleHandle [static]
mValue: System.IntPtr
-- static
:System.ModuleHandle GetEmptyMH()
```

## `System.MulticastDelegate`

```lua
-- methods
:System.Delegate[] GetInvocationList()
```

## `System.NumberStyles`

```lua
-- values (System.Int32 enum)
AllowCurrencySymbol
AllowDecimalPoint
AllowExponent
AllowHexSpecifier
AllowLeadingSign
AllowLeadingWhite
AllowParentheses
AllowThousands
AllowTrailingSign
AllowTrailingWhite
Any
Currency
Float
HexNumber
Integer
None
Number
```

## `System.Object`

```lua
-- methods
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Type GetType()
:System.Object MemberwiseClone()
:System.String ToString()
-- static
:System.Boolean Equals(System.Object, System.Object)
:System.Boolean ReferenceEquals(System.Object, System.Object)
```

## `System.ObsoleteAttribute`

```lua
-- fields
mError: System.Boolean
mMessage: System.String
-- methods
:System.Boolean get_IsError()
:System.String get_Message()
```

## `System.Random`

```lua
-- fields
w: System.UInt32
x: System.UInt32
y: System.UInt32
z: System.UInt32
-- methods
:System.Int32 Next()
:System.Int32 Next(System.Int32)
:System.Int32 Next(System.Int32, System.Int32)
:System.Void NextBytes(System.Byte[])
:System.Double NextDouble()
:System.Double Sample()
```

## `System.Reflection.Assembly`

```lua
-- methods
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
-- static
:System.String CreateQualifiedName(System.String, System.String)
:System.Reflection.Assembly GetAssembly(System.Type)
:System.Reflection.Assembly ReflectionOnlyLoad(System.Byte[])
:System.Reflection.Assembly ReflectionOnlyLoad(System.String)
:System.Reflection.Assembly ReflectionOnlyLoadFrom(System.String)
:System.Boolean op_Equality(System.Reflection.Assembly, System.Reflection.Assembly)
:System.Boolean op_Inequality(System.Reflection.Assembly, System.Reflection.Assembly)
```

## `System.Reflection.AssemblyCompanyAttribute`

```lua
-- fields
_Company: System.String
-- methods
:System.String get_Company()
```

## `System.Reflection.AssemblyConfigurationAttribute`

```lua
-- fields
_Configuration: System.String
-- methods
:System.String get_Configuration()
```

## `System.Reflection.AssemblyCopyrightAttribute`

```lua
-- fields
_Copyright: System.String
-- methods
:System.String get_Copyright()
```

## `System.Reflection.AssemblyCultureAttribute`

```lua
-- fields
_Culture: System.String
-- methods
:System.String get_Culture()
```

## `System.Reflection.AssemblyDescriptionAttribute`

```lua
-- fields
_Description: System.String
-- methods
:System.String get_Description()
```

## `System.Reflection.AssemblyFileVersionAttribute`

```lua
-- fields
_Version: System.String
-- methods
:System.String get_Version()
```

## `System.Reflection.AssemblyName`

```lua
-- methods
:System.Object Clone()
```

## `System.Reflection.AssemblyProductAttribute`

```lua
-- fields
_Product: System.String
-- methods
:System.String get_Product()
```

## `System.Reflection.AssemblyTitleAttribute`

```lua
-- fields
_Title: System.String
-- methods
:System.String get_Title()
```

## `System.Reflection.AssemblyTrademarkAttribute`

```lua
-- fields
_Trademark: System.String
-- methods
:System.String get_Trademark()
```

## `System.Reflection.AssemblyVersionAttribute`

```lua
-- fields
_Version: System.String
-- methods
:System.String get_Version()
```

## `System.Reflection.BindingFlags`

```lua
-- values (System.Int32 enum)
CreateInstance
DeclaredOnly
Default
ExactBinding
FlattenHierarchy
GetField
GetProperty
IgnoreCase
IgnoreReturn
Instance
InvokeMethod
NonPublic
OptionalParamBinding
Public
PutDispProperty
PutRefDispProperty
SetField
SetProperty
Static
SuppressChangeType
```

## `System.Reflection.CallingConventions`

```lua
-- values (System.Int32 enum)
Any
ExplicitThis
HasThis
Standard
VarArgs
```

## `System.Reflection.ConstructorInfo`

```lua
-- fields
ConstructorName: System.String [static]
TypeConstructorName: System.String [static]
-- methods
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.Object Invoke(System.Object[])
:System.Reflection.MemberTypes get_MemberType()
-- static
:System.Boolean op_Equality(System.Reflection.ConstructorInfo, System.Reflection.ConstructorInfo)
:System.Boolean op_Inequality(System.Reflection.ConstructorInfo, System.Reflection.ConstructorInfo)
```

## `System.Reflection.DefaultMemberAttribute`

```lua
-- fields
_MemberName: System.String
-- methods
:System.String get_MemberName()
```

## `System.Reflection.EventAttributes`

```lua
-- values (System.Int32 enum)
None
RTSpecialName
ReservedMask
SpecialName
```

## `System.Reflection.EventInfo`

```lua
-- methods
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
-- static
:System.Boolean op_Equality(System.Reflection.EventInfo, System.Reflection.EventInfo)
:System.Boolean op_Inequality(System.Reflection.EventInfo, System.Reflection.EventInfo)
```

## `System.Reflection.FieldAttributes`

```lua
-- values (System.Int32 enum)
Assembly
FamANDAssem
FamORAssem
Family
FieldAccessMask
HasDefault
HasFieldMarshal
HasFieldRVA
InitOnly
Literal
NotSerialized
PinvokeImpl
Private
PrivateScope
Public
RTSpecialName
ReservedMask
SpecialName
Static
```

## `System.Reflection.FieldInfo`

```lua
-- methods
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
-- static
:System.Boolean op_Equality(System.Reflection.FieldInfo, System.Reflection.FieldInfo)
:System.Boolean op_Inequality(System.Reflection.FieldInfo, System.Reflection.FieldInfo)
```

## `System.Reflection.GenericParameterAttributes`

```lua
-- values (System.Int32 enum)
Contravariant
Covariant
DefaultConstructorConstraint
None
NotNullableValueTypeConstraint
ReferenceTypeConstraint
SpecialConstraintMask
VarianceMask
```

## `System.Reflection.InterfaceMapping`

```lua
-- fields
InterfaceMethods: System.Reflection.MethodInfo[]
InterfaceType: System.Type
TargetMethods: System.Reflection.MethodInfo[]
TargetType: System.Type
```

## `System.Reflection.IntrospectionExtensions`

```lua
-- static
:System.Reflection.TypeInfo GetTypeInfo(System.Type)
```

## `System.Reflection.MemberFilter`

```lua
-- methods
:System.Boolean Invoke(System.Reflection.MemberInfo, System.Object)
```

## `System.Reflection.MemberInfo`

```lua
-- methods
:System.Boolean Equals(System.Object)
:System.Collections.Generic.IList`1<System.Reflection.CustomAttributeData> GetCustomAttributesData()
:System.Int32 GetHashCode()
:System.Boolean HasSameMetadataDefinitionAs(System.Reflection.MemberInfo)
:System.Collections.Generic.IEnumerable`1<System.Reflection.CustomAttributeData> get_CustomAttributes()
:System.Int32 get_MetadataToken()
:System.Reflection.Module get_Module()
-- static
:System.Boolean op_Equality(System.Reflection.MemberInfo, System.Reflection.MemberInfo)
:System.Boolean op_Inequality(System.Reflection.MemberInfo, System.Reflection.MemberInfo)
```

## `System.Reflection.MemberTypes`

```lua
-- values (System.Int32 enum)
All
Constructor
Custom
Event
Field
Method
NestedType
Property
TypeInfo
```

## `System.Reflection.MethodAttributes`

```lua
-- values (System.Int32 enum)
Abstract
Assembly
CheckAccessOnOverride
FamANDAssem
FamORAssem
Family
Final
HasSecurity
HideBySig
MemberAccessMask
NewSlot
PinvokeImpl
Private
PrivateScope
Public
RTSpecialName
RequireSecObject
ReservedMask
ReuseSlot
SpecialName
Static
UnmanagedExport
Virtual
VtableLayoutMask
```

## `System.Reflection.MethodBase`

```lua
-- methods
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
-- static
:System.Boolean op_Equality(System.Reflection.MethodBase, System.Reflection.MethodBase)
:System.Boolean op_Inequality(System.Reflection.MethodBase, System.Reflection.MethodBase)
```

## `System.Reflection.MethodImplAttributes`

```lua
-- values (System.Int32 enum)
AggressiveInlining
CodeTypeMask
ForwardRef
IL
InternalCall
Managed
ManagedMask
MaxMethodImplVal
Native
NoInlining
NoOptimization
OPTIL
PreserveSig
Runtime
Synchronized
Unmanaged
```

## `System.Reflection.MethodInfo`

```lua
-- methods
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
-- static
:System.Boolean op_Equality(System.Reflection.MethodInfo, System.Reflection.MethodInfo)
:System.Boolean op_Inequality(System.Reflection.MethodInfo, System.Reflection.MethodInfo)
```

## `System.Reflection.Missing`

```lua
-- fields
Value: System.Reflection.Missing [static]
```

## `System.Reflection.Module`

```lua
-- fields
DefaultLookup: System.Reflection.BindingFlags [static]
FilterTypeName: System.Reflection.TypeFilter [static]
FilterTypeNameIgnoreCase: System.Reflection.TypeFilter [static]
-- methods
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
-- static
:System.Boolean FilterTypeNameIgnoreCaseImpl(System.Type, System.Object)
:System.Boolean FilterTypeNameImpl(System.Type, System.Object)
:System.Boolean op_Equality(System.Reflection.Module, System.Reflection.Module)
:System.Boolean op_Inequality(System.Reflection.Module, System.Reflection.Module)
```

## `System.Reflection.ParameterAttributes`

```lua
-- values (System.Int32 enum)
HasDefault
HasFieldMarshal
In
Lcid
None
Optional
Out
Reserved3
Reserved4
ReservedMask
Retval
```

## `System.Reflection.ParameterInfo`

```lua
-- fields
MetadataToken_ParamDef: System.Int32 [static]
-- methods
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

## `System.Reflection.ParameterModifier`

```lua
-- fields
_byRef: System.Boolean[]
-- methods
:System.Boolean get_Item(System.Int32)
:System.Void set_Item(System.Int32, System.Boolean)
```

## `System.Reflection.PropertyAttributes`

```lua
-- values (System.Int32 enum)
HasDefault
None
RTSpecialName
Reserved2
Reserved3
Reserved4
ReservedMask
SpecialName
```

## `System.Reflection.PropertyInfo`

```lua
-- methods
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
-- static
:System.Boolean op_Equality(System.Reflection.PropertyInfo, System.Reflection.PropertyInfo)
:System.Boolean op_Inequality(System.Reflection.PropertyInfo, System.Reflection.PropertyInfo)
```

## `System.Reflection.RuntimeAssembly`

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
_kind: System.Int32
_position: System.Int32
_runtimeMethodHandle: System.IntPtr
-- methods
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

```lua
-- fields
_runtimeHandle: System.IntPtr
-- methods
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

```lua
-- fields
Everything: System.Reflection.BindingFlags [static]
-- static
:System.Reflection.MethodInfo GetMethodInfo(System.Delegate)
:System.Reflection.MethodInfo GetRuntimeBaseDefinition(System.Reflection.MethodInfo)
:System.Reflection.EventInfo GetRuntimeEvent(System.Type, System.String)
:System.Collections.Generic.IEnumerable`1<System.Reflection.EventInfo> GetRuntimeEvents(System.Type)
:System.Reflection.FieldInfo GetRuntimeField(System.Type, System.String)
:System.Collections.Generic.IEnumerable`1<System.Reflection.FieldInfo> GetRuntimeFields(System.Type)
:System.Reflection.InterfaceMapping GetRuntimeInterfaceMap(System.Reflection.TypeInfo, System.Type)
:System.Reflection.MethodInfo GetRuntimeMethod(System.Type, System.String, System.Type[])
:System.Collections.Generic.IEnumerable`1<System.Reflection.MethodInfo> GetRuntimeMethods(System.Type)
:System.Collections.Generic.IEnumerable`1<System.Reflection.PropertyInfo> GetRuntimeProperties(System.Type)
:System.Reflection.PropertyInfo GetRuntimeProperty(System.Type, System.String)
```

## `System.Reflection.TypeAttributes`

```lua
-- values (System.Int32 enum)
Abstract
AnsiClass
AutoClass
AutoLayout
BeforeFieldInit
Class
ClassSemanticsMask
CustomFormatClass
CustomFormatMask
ExplicitLayout
HasSecurity
Import
Interface
LayoutMask
NestedAssembly
NestedFamANDAssem
NestedFamORAssem
NestedFamily
NestedPrivate
NestedPublic
NotPublic
Public
RTSpecialName
ReservedMask
Sealed
SequentialLayout
Serializable
SpecialName
StringFormatMask
UnicodeClass
VisibilityMask
WindowsRuntime
```

## `System.Reflection.TypeDelegator`

```lua
-- fields
typeImpl: System.Type
-- methods
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

```lua
-- methods
:System.Boolean Invoke(System.Type, System.Object)
```

## `System.Reflection.TypeInfo`

```lua
-- fields
DeclaredOnlyLookup: System.Reflection.BindingFlags [static]
-- methods
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

## `System.Runtime.CompilerServices.CallerArgumentExpressionAttribute`

```lua
-- methods
:System.String get_ParameterName()
```

## `System.Runtime.CompilerServices.CompilationRelaxations`

```lua
-- values (System.Int32 enum)
NoStringInterning
```

## `System.Runtime.CompilerServices.CompilationRelaxationsAttribute`

```lua
-- fields
_Relaxations: System.Int32
-- methods
:System.Int32 get_CompilationRelaxations()
```

## `System.Runtime.CompilerServices.MethodCodeType`

```lua
-- values (System.Int32 enum)
IL
Native
OPTIL
Runtime
```

## `System.Runtime.CompilerServices.MethodImplOptions`

```lua
-- values (System.Int32 enum)
AggressiveInlining
ForwardRef
InternalCall
NoInlining
NoOptimization
PreserveSig
Synchronized
Unmanaged
```

## `System.Runtime.CompilerServices.RuntimeCompatibilityAttribute`

```lua
-- fields
mWrapNonExceptionThrows: System.Boolean
-- methods
:System.Boolean get_WrapNonExceptionThrows()
:System.Void set_WrapNonExceptionThrows(System.Boolean)
```

## `System.Runtime.CompilerServices.RuntimeHelpers`

```lua
-- static
:System.Object GetObjectValue(System.Object)
:System.Void InitializeArray(System.Array, System.RuntimeFieldHandle)
:System.Void RunClassConstructor(System.RuntimeTypeHandle)
```

## `System.Runtime.CompilerServices.StateMachineAttribute`

```lua
-- methods
:System.Type get_StateMachineType()
:System.Void set_StateMachineType(System.Type)
```

## `System.Runtime.CompilerServices.TupleElementNamesAttribute`

```lua
-- fields
_transformNames: System.String[]
-- methods
:System.Collections.Generic.IList`1<System.String> get_TransformNames()
```

## `System.Runtime.InteropServices.CharSet`

```lua
-- values (System.Int32 enum)
Ansi
Auto
None
Unicode
```

## `System.Runtime.InteropServices.ComVisibleAttribute`

```lua
-- fields
_Val: System.Boolean
-- methods
:System.Boolean get_Value()
```

## `System.Runtime.InteropServices.FieldOffsetAttribute`

```lua
-- methods
:System.Int32 get_Value()
:System.Void set_Value(System.Int32)
```

## `System.Runtime.InteropServices.GuidAttribute`

```lua
-- fields
_Val: System.String
-- methods
:System.String get_Value()
```

## `System.Runtime.InteropServices.LayoutKind`

```lua
-- values (System.Int32 enum)
Auto
Explicit
Sequential
```

## `System.Runtime.InteropServices.Marshal`

```lua
-- static
:System.Int32 SizeOf(System.Object)
:System.Int32 SizeOf(System.Type)
```

## `System.Runtime.InteropServices.StructLayoutAttribute`

```lua
-- fields
DEFAULT_PACKING_SIZE: System.Int32 [static]
CharSet: System.Runtime.InteropServices.CharSet
Pack: System.Int32
Size: System.Int32
_Val: System.Runtime.InteropServices.LayoutKind
-- methods
:System.Runtime.InteropServices.LayoutKind get_Value()
```

## `System.Runtime.Versioning.TargetFrameworkAttribute`

```lua
-- fields
mFrameworkDisplayName: System.String
mFrameworkName: System.String
-- methods
:System.String get_FrameworkDisplayName()
:System.String get_FrameworkName()
:System.Void set_FrameworkDisplayName(System.String)
```

## `System.RuntimeArgumentHandle`

```lua
-- fields
mValue: System.IntPtr
```

## `System.RuntimeFieldHandle`

```lua
-- fields
mValue: System.IntPtr
```

## `System.RuntimeMethodHandle`

```lua
-- fields
mValue: System.IntPtr
```

## `System.RuntimeType`

```lua
-- fields
_kind: System.Int32
_number: System.Int32
_runtimeTypeHandle: System.IntPtr
-- methods
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
-- static
:System.Object CreateInstanceForAnotherGenericParameter(System.Type, System.Type)
```

## `System.RuntimeTypeHandle`

```lua
-- fields
mValue: System.IntPtr
```

## `System.SByte`

```lua
-- fields
MaxValue: System.SByte [static]
MinValue: System.SByte [static]
mValue: System.SByte
-- methods
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
-- static
:System.SByte Parse(System.String)
:System.SByte Parse(System.String, System.NumberStyles)
:System.SByte Parse(System.String, System.IFormatProvider)
:System.SByte Parse(System.String, System.NumberStyles, System.IFormatProvider)
:System.Boolean TryParse(System.String, System.SByte)
```

## `System.Security.Permissions.SecurityAction`

```lua
-- values (System.Int32 enum)
Assert
Demand
Deny
InheritanceDemand
LinkDemand
PermitOnly
RequestMinimum
RequestOptional
RequestRefuse
```

## `System.Security.Permissions.SecurityPermissionAttribute`

```lua
-- methods
:System.Boolean get_SkipVerification()
:System.Void set_SkipVerification(System.Boolean)
```

## `System.Single`

```lua
-- fields
Epsilon: System.Single [static]
MaxValue: System.Single [static]
MinValue: System.Single [static]
NaN: System.Single [static]
NegativeInfinity: System.Single [static]
PositiveInfinity: System.Single [static]
mValue: System.Single
-- methods
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
-- static
:System.Boolean IsInfinity(System.Single)
:System.Boolean IsNaN(System.Single)
:System.Boolean IsNegativeInfinity(System.Single)
:System.Boolean IsPositiveInfinity(System.Single)
:System.Single Parse(System.String)
:System.Boolean TryParse(System.String, System.Single)
```

## `System.Single[,]`

```lua
-- methods
:System.Single Address(System.Int32, System.Int32)
:System.Single Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.Single)
```

## `System.String`

```lua
-- fields
Empty: System.String [static]
-- methods
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
-- static
:System.Int32 Compare(System.String, System.String)
:System.Int32 Compare(System.String, System.String, System.Boolean)
:System.Int32 Compare(System.String, System.String, System.StringComparison)
:System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32)
:System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32, System.Boolean)
:System.Int32 Compare(System.String, System.Int32, System.String, System.Int32, System.Int32, System.StringComparison)
:System.Int32 CompareOrdinal(System.String, System.String)
:System.Int32 CompareOrdinal(System.String, System.Int32, System.String, System.Int32, System.Int32)
:System.String Concat(System.Object)
:System.String Concat(System.String[])
:System.String Concat(System.Object[])
:System.String Concat(System.Object, System.Object)
:System.String Concat(System.Object, System.Object, System.Object)
:System.String Concat(System.Object, System.Object, System.Object, System.Object)
:System.String Concat(System.String, System.String)
:System.String Concat(System.String, System.String, System.String)
:System.String Concat(System.String, System.String, System.String, System.String)
:System.String Copy(System.String)
:System.Boolean Equals(System.String, System.String)
:System.Boolean Equals(System.String, System.String, System.StringComparison)
:System.String Format(System.String, System.Object)
:System.String Format(System.String, System.Object, System.Object)
:System.String Format(System.String, System.Object, System.Object, System.Object)
:System.String Format(System.IFormatProvider, System.String, System.Object[])
:System.String Format(System.String, System.Object[])
:System.String Intern(System.String)
:System.String IsInterned(System.String)
:System.Boolean IsNullOrEmpty(System.String)
:System.Boolean IsNullOrWhiteSpace(System.String)
:System.String Join(System.String, System.String[])
:System.String Join(System.String, System.String[], System.Int32, System.Int32)
:System.String Join(System.String, System.Collections.Generic.IEnumerable`1<System.String>)
:System.String Join(System.String, System.Object[])
:System.Boolean op_Equality(System.String, System.String)
:System.Boolean op_Inequality(System.String, System.String)
```

## `System.StringComparison`

```lua
-- values (System.Int32 enum)
CurrentCulture
CurrentCultureIgnoreCase
InvariantCulture
InvariantCultureIgnoreCase
Ordinal
OrdinalIgnoreCase
```

## `System.StringSplitOptions`

```lua
-- values (System.Int32 enum)
None
RemoveEmptyEntries
```

## `System.Text.ASCIIEncoding`

```lua
-- methods
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

```lua
-- fields
bigEndianUnicode: System.Text.Encoding [static]
defaultEncoding: System.Text.Encoding [static]
latin1Encoding: System.Text.Encoding [static]
mASCIIEncoding: System.Text.Encoding [static]
unicodeEncoding: System.Text.Encoding [static]
utf32Encoding: System.Text.Encoding [static]
utf7Encoding: System.Text.Encoding [static]
utf8Encoding: System.Text.Encoding [static]
-- methods
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
-- static
:System.Byte[] Convert(System.Text.Encoding, System.Text.Encoding, System.Byte[])
:System.Byte[] Convert(System.Text.Encoding, System.Text.Encoding, System.Byte[], System.Int32, System.Int32)
:System.Text.Encoding GetEncoding(System.Int32)
:System.Text.Encoding GetEncoding(System.String)
:System.Text.EncodingInfo[] GetEncodings()
:System.Text.Encoding get_ASCII()
:System.Text.Encoding get_Default()
:System.Text.Encoding get_UTF8()
:System.Text.Encoding get_Unicode()
```

## `System.Text.EncodingInfo`

```lua
-- fields
mCodePage: System.Int32
mDisplayName: System.String
mEncodingName: System.String
-- methods
:System.Boolean Equals(System.Object)
:System.Text.Encoding GetEncoding()
:System.Int32 GetHashCode()
:System.Int32 get_CodePage()
:System.String get_DisplayName()
:System.String get_Name()
```

## `System.Text.NormalizationForm`

```lua
-- values (System.Int32 enum)
FormC
FormD
FormKC
FormKD
```

## `System.Text.StringBuilder`

```lua
-- fields
DefaultCapacity: System.Int32 [static]
MaxChunkSize: System.Int32 [static]
m_ChunkChars: System.Char[]
m_ChunkLength: System.Int32
m_ChunkOffset: System.Int32
m_ChunkPrevious: System.Text.StringBuilder
m_MaxCapacity: System.Int32
-- methods
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
-- static
:System.Void FormatError()
:System.Void InternalCopy(System.Char[], System.Int32, System.Char[], System.Int32, System.Int32)
```

## `System.Text.UTF8Encoding`

```lua
-- methods
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

```lua
-- methods
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

```lua
-- values (System.Int32 enum)
MTA
STA
Unknown
```

## `System.Threading.Interlocked`

```lua
-- static
:System.Int32 Add(System.Int32, System.Int32)
:System.Int64 Add(System.Int64, System.Int64)
:System.Double CompareExchange(System.Double, System.Double, System.Double)
:System.Int32 CompareExchange(System.Int32, System.Int32, System.Int32)
:System.Int64 CompareExchange(System.Int64, System.Int64, System.Int64)
:System.IntPtr CompareExchange(System.IntPtr, System.IntPtr, System.IntPtr)
:System.Object CompareExchange(System.Object, System.Object, System.Object)
:System.Single CompareExchange(System.Single, System.Single, System.Single)
:System.Int32 Decrement(System.Int32)
:System.Int64 Decrement(System.Int64)
:System.Double Exchange(System.Double, System.Double)
:System.Int32 Exchange(System.Int32, System.Int32)
:System.Int64 Exchange(System.Int64, System.Int64)
:System.IntPtr Exchange(System.IntPtr, System.IntPtr)
:System.Object Exchange(System.Object, System.Object)
:System.Single Exchange(System.Single, System.Single)
:System.Int32 Increment(System.Int32)
:System.Int64 Increment(System.Int64)
:System.Void MemoryBarrier()
:System.Int64 Read(System.Int64)
```

## `System.Threading.Monitor`

```lua
-- static
:System.Void Enter(System.Object)
:System.Void Enter(System.Object, System.Boolean)
:System.Void Exit(System.Object)
:System.Void Pulse(System.Object)
:System.Void PulseAll(System.Object)
:System.Boolean TryEnter(System.Object)
:System.Boolean TryEnter(System.Object, System.Boolean)
:System.Boolean TryEnter(System.Object, System.Int32)
:System.Boolean Wait(System.Object)
```

## `System.Threading.ParameterizedThreadStart`

```lua
-- methods
:System.Void Invoke(System.Object)
```

## `System.Threading.PlatformHelper`

```lua
-- fields
IsSingleProcessor: System.Boolean [static]
PROCESSOR_COUNT_REFRESH_INTERVAL_MS: System.Int32 [static]
s_lastProcessorCountRefreshTicks: System.Int32 [static]
s_processorCount: System.Int32 [static]
-- static
:System.Int32 get_ProcessorCount()
```

## `System.Threading.SpinWait`

```lua
-- fields
DefaultSleep1Threshold: System.Int32 [static]
Sleep0EveryHowManyYields: System.Int32 [static]
Sleep1ThresholdForSpinBeforeWait: System.Int32 [static]
SpinCountforSpinBeforeWait: System.Int32 [static]
YieldThreshold: System.Int32 [static]
_count: System.Int32
-- methods
:System.Void Reset()
:System.Void SpinOnce()
:System.Void SpinOnce(System.Int32)
:System.Int32 get_Count()
:System.Boolean get_NextSpinWillYield()
:System.Void set_Count(System.Int32)
-- static
:System.Void SpinUntil(System.Func`1<System.Boolean>)
:System.Boolean SpinUntil(System.Func`1<System.Boolean>, System.TimeSpan)
:System.Boolean SpinUntil(System.Func`1<System.Boolean>, System.Int32)
```

## `System.Threading.Tasks.Parallel`

```lua
-- fields
DEFAULT_LOOP_STRIDE: System.Int32 [static]
s_defaultParallelOptions: System.Threading.Tasks.ParallelOptions [static]
s_forkJoinContextID: System.Int32 [static]
-- static
:System.Boolean CheckTimeoutReached(System.Int32)
:System.Int32 ComputeTimeoutPoint(System.Int32)
:System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Action`1<System.Int32>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Action`1<System.Int64>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Threading.Tasks.ParallelOptions, System.Action`1<System.Int32>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Threading.Tasks.ParallelOptions, System.Action`1<System.Int64>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Action`2<System.Int32,System.Threading.Tasks.ParallelLoopState>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Action`2<System.Int64,System.Threading.Tasks.ParallelLoopState>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int32, System.Int32, System.Threading.Tasks.ParallelOptions, System.Action`2<System.Int32,System.Threading.Tasks.ParallelLoopState>)
:System.Threading.Tasks.ParallelLoopResult For(System.Int64, System.Int64, System.Threading.Tasks.ParallelOptions, System.Action`2<System.Int64,System.Threading.Tasks.ParallelLoopState>)
:System.Void ForWorker(System.Int32, System.Int32, System.Action`1<System.Int32>)
:System.Void Invoke(System.Action[])
:System.Void Invoke(System.Threading.Tasks.ParallelOptions, System.Action[])
```

## `System.Threading.Tasks.ParallelLoopResult`

```lua
-- fields
_completed: System.Boolean
_lowestBreakIteration: System.Nullable`1<System.Int64>
-- methods
:System.Boolean get_IsCompleted()
:System.Nullable`1<System.Int64> get_LowestBreakIteration()
```

## `System.Threading.Tasks.ParallelLoopState`

```lua
-- fields
_flagsBase: System.Threading.Tasks.ParallelLoopStateFlags
-- methods
:System.Void Break()
:System.Void InternalBreak()
:System.Void Stop()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Boolean get_IsExceptional()
:System.Boolean get_IsStopped()
:System.Nullable`1<System.Int64> get_LowestBreakIteration()
:System.Boolean get_ShouldExitCurrentIteration()
-- static
:System.Void Break(System.Int32, System.Threading.Tasks.ParallelLoopStateFlags32)
:System.Void Break(System.Int64, System.Threading.Tasks.ParallelLoopStateFlags64)
```

## `System.Threading.Tasks.ParallelLoopState32`

```lua
-- fields
_currentIteration: System.Int32
_sharedParallelStateFlags: System.Threading.Tasks.ParallelLoopStateFlags32
-- methods
:System.Void InternalBreak()
:System.Int32 get_CurrentIteration()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Void set_CurrentIteration(System.Int32)
```

## `System.Threading.Tasks.ParallelLoopState64`

```lua
-- fields
_currentIteration: System.Int64
_sharedParallelStateFlags: System.Threading.Tasks.ParallelLoopStateFlags64
-- methods
:System.Void InternalBreak()
:System.Int64 get_CurrentIteration()
:System.Nullable`1<System.Int64> get_InternalLowestBreakIteration()
:System.Boolean get_InternalShouldExitCurrentIteration()
:System.Void set_CurrentIteration(System.Int64)
```

## `System.Threading.Tasks.ParallelLoopStateFlags`

```lua
-- fields
ParallelLoopStateBroken: System.Int32 [static]
ParallelLoopStateCanceled: System.Int32 [static]
ParallelLoopStateExceptional: System.Int32 [static]
ParallelLoopStateNone: System.Int32 [static]
ParallelLoopStateStopped: System.Int32 [static]
_loopStateFlags: System.Int32
-- methods
:System.Boolean AtomicLoopStateUpdate(System.Int32, System.Int32)
:System.Boolean AtomicLoopStateUpdate(System.Int32, System.Int32, System.Int32)
:System.Boolean Cancel()
:System.Void SetExceptional()
:System.Void Stop()
:System.Int32 get_LoopStateFlags()
```

## `System.Threading.Tasks.ParallelLoopStateFlags32`

```lua
-- fields
_lowestBreakIteration: System.Int32
-- methods
:System.Boolean ShouldExitLoop(System.Int32)
:System.Boolean ShouldExitLoop()
:System.Int32 get_LowestBreakIteration()
:System.Nullable`1<System.Int64> get_NullableLowestBreakIteration()
```

## `System.Threading.Tasks.ParallelLoopStateFlags64`

```lua
-- fields
_lowestBreakIteration: System.Int64
-- methods
:System.Boolean ShouldExitLoop(System.Int64)
:System.Boolean ShouldExitLoop()
:System.Int64 get_LowestBreakIteration()
:System.Nullable`1<System.Int64> get_NullableLowestBreakIteration()
```

## `System.Threading.Thread`

```lua
-- fields
mAppDomain: System.AppDomain [static]
mApartmentState: System.Threading.ApartmentState
mThreadId: System.Int32
mThreadName: System.String
mThreadParam: System.Object
mThreadPtr: System.IntPtr
mThreadStart: System.Threading.ThreadStart
mThreadState: System.Threading.ThreadState
-- methods
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
-- static
:System.AppDomain GetDomain()
:System.Void Sleep(System.Int32)
:System.Void SpinWait(System.Int32)
:System.Void ThreadStartInvoke(System.Object, System.Object)
:System.Void Yield()
:System.Threading.Thread get_CurrentThread()
```

## `System.Threading.ThreadStart`

```lua
-- methods
:System.Void Invoke()
```

## `System.Threading.ThreadState`

```lua
-- values (System.Int32 enum)
AbortRequested
Aborted
Background
Running
StopRequested
Stopped
SuspendRequested
Suspended
Unstarted
WaitSleepJoin
```

## `System.Threading.Timeout`

```lua
-- fields
Infinite: System.Int32 [static]
InfiniteTimeSpan: System.TimeSpan [static]
UnsignedInfinite: System.UInt32 [static]
```

## `System.Threading.TimeoutHelper`

```lua
-- static
:System.UInt32 GetTime()
:System.Int32 UpdateTimeOut(System.UInt32, System.Int32)
```

## `System.Threading.Volatile`

```lua
-- static
:System.Boolean Read(System.Boolean)
:System.SByte Read(System.SByte)
:System.Byte Read(System.Byte)
:System.Int16 Read(System.Int16)
:System.UInt16 Read(System.UInt16)
:System.Int32 Read(System.Int32)
:System.UInt32 Read(System.UInt32)
:System.Int64 Read(System.Int64)
:System.UInt64 Read(System.UInt64)
:System.IntPtr Read(System.IntPtr)
:System.UIntPtr Read(System.UIntPtr)
:System.Single Read(System.Single)
:System.Double Read(System.Double)
:System.Void Write(System.Boolean, System.Boolean)
:System.Void Write(System.SByte, System.SByte)
:System.Void Write(System.Byte, System.Byte)
:System.Void Write(System.Int16, System.Int16)
:System.Void Write(System.UInt16, System.UInt16)
:System.Void Write(System.Int32, System.Int32)
:System.Void Write(System.UInt32, System.UInt32)
:System.Void Write(System.Int64, System.Int64)
:System.Void Write(System.UInt64, System.UInt64)
:System.Void Write(System.IntPtr, System.IntPtr)
:System.Void Write(System.UIntPtr, System.UIntPtr)
:System.Void Write(System.Single, System.Single)
:System.Void Write(System.Double, System.Double)
```

## `System.TimeSpan`

```lua
-- fields
MaxValue: System.TimeSpan [static]
MinValue: System.TimeSpan [static]
TicksPerDay: System.Int64 [static]
TicksPerHour: System.Int64 [static]
TicksPerMillisecond: System.Int64 [static]
TicksPerMinute: System.Int64 [static]
TicksPerSecond: System.Int64 [static]
Zero: System.TimeSpan [static]
mThicks: System.Int64
-- methods
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
-- static
:System.Int32 Compare(System.TimeSpan, System.TimeSpan)
:System.Boolean Equals(System.TimeSpan, System.TimeSpan)
:System.TimeSpan FromDays(System.Double)
:System.TimeSpan FromHours(System.Double)
:System.TimeSpan FromMilliseconds(System.Double)
:System.TimeSpan FromMinutes(System.Double)
:System.TimeSpan FromSeconds(System.Double)
:System.TimeSpan FromTicks(System.Int64)
:System.TimeSpan Parse(System.String)
:System.TimeSpan Parse(System.String, System.IFormatProvider)
:System.TimeSpan ParseExact(System.String, System.String, System.IFormatProvider)
:System.TimeSpan ParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.TimeSpanStyles)
:System.TimeSpan ParseExact(System.String, System.String[], System.IFormatProvider)
:System.TimeSpan ParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.TimeSpanStyles)
:System.Int32 SplitToken(System.String, System.Int32[], System.Int32[], System.Char[])
:System.String ToCustomString(System.TimeSpan, System.String)
:System.Boolean TryParse(System.String, System.TimeSpan)
:System.Boolean TryParse(System.String, System.IFormatProvider, System.TimeSpan)
:System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.TimeSpan)
:System.Boolean TryParseExact(System.String, System.String, System.IFormatProvider, System.Globalization.TimeSpanStyles, System.TimeSpan)
:System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.TimeSpan)
:System.Boolean TryParseExact(System.String, System.String[], System.IFormatProvider, System.Globalization.TimeSpanStyles, System.TimeSpan)
:System.Boolean TryParseInternal(System.String, System.String, System.TimeSpan)
:System.TimeSpan op_Addition(System.TimeSpan, System.TimeSpan)
:System.Boolean op_Equality(System.TimeSpan, System.TimeSpan)
:System.Boolean op_GreaterThan(System.TimeSpan, System.TimeSpan)
:System.Boolean op_GreaterThanOrEqual(System.TimeSpan, System.TimeSpan)
:System.Boolean op_Inequality(System.TimeSpan, System.TimeSpan)
:System.Boolean op_LessThan(System.TimeSpan, System.TimeSpan)
:System.Boolean op_LessThanOrEqual(System.TimeSpan, System.TimeSpan)
:System.TimeSpan op_Subtraction(System.TimeSpan, System.TimeSpan)
:System.TimeSpan op_UnaryNegation(System.TimeSpan)
:System.TimeSpan op_UnaryPlus(System.TimeSpan)
```

## `System.Tuple`

```lua
-- static
:System.Int32 CombineHashCodes(System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
```

## `System.Type`

```lua
-- fields
DefaultLookup: System.Reflection.BindingFlags [static]
Delimiter: System.Char [static]
EmptyTypes: System.Type[] [static]
FilterAttribute: System.Reflection.MemberFilter [static]
FilterName: System.Reflection.MemberFilter [static]
FilterNameIgnoreCase: System.Reflection.MemberFilter [static]
Missing: System.Object [static]
s_defaultBinder: System.Reflection.Binder [static]
-- methods
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
-- static
:System.Boolean FilterAttributeImpl(System.Reflection.MemberInfo, System.Object)
:System.Boolean FilterNameIgnoreCaseImpl(System.Reflection.MemberInfo, System.Object)
:System.Boolean FilterNameImpl(System.Reflection.MemberInfo, System.Object)
:System.Type GetType(System.String, System.Boolean, System.Boolean)
:System.Type GetType(System.String, System.Boolean)
:System.Type GetType(System.String)
:System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>)
:System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>, System.Boolean)
:System.Type GetType(System.String, System.Func`2<System.Reflection.AssemblyName,System.Reflection.Assembly>, System.Func`4<System.Reflection.Assembly,System.String,System.Boolean,System.Type>, System.Boolean, System.Boolean)
:System.Type[] GetTypeArray(System.Object[])
:System.TypeCode GetTypeCode(System.Type)
:System.Type GetTypeFromCLSID(System.Guid)
:System.Type GetTypeFromCLSID(System.Guid, System.Boolean)
:System.Type GetTypeFromCLSID(System.Guid, System.String)
:System.Type GetTypeFromCLSID(System.Guid, System.String, System.Boolean)
:System.Type GetTypeFromHandle(System.RuntimeTypeHandle)
:System.Type GetTypeFromProgID(System.String)
:System.Type GetTypeFromProgID(System.String, System.Boolean)
:System.Type GetTypeFromProgID(System.String, System.String)
:System.Type GetTypeFromProgID(System.String, System.String, System.Boolean)
:System.RuntimeTypeHandle GetTypeHandle(System.Object)
:System.Type MakeGenericMethodParameter(System.Int32)
:System.Type ReflectionOnlyGetType(System.String, System.Boolean, System.Boolean)
:System.Boolean op_Equality(System.Type, System.Type)
:System.Boolean op_Inequality(System.Type, System.Type)
```

## `System.TypeCode`

```lua
-- values (System.Int32 enum)
Boolean
Byte
Char
DBNull
DateTime
Decimal
Double
Empty
Int16
Int32
Int64
Object
SByte
Single
String
UInt16
UInt32
UInt64
```

## `System.TypedReference`

```lua
-- fields
mType: System.IntPtr
mValue: System.IntPtr
-- static
:System.Type GetTargetType(System.TypedReference)
:System.TypedReference MakeTypedReference(System.Object, System.Reflection.FieldInfo[])
:System.Void SetTypedReference(System.TypedReference, System.Object)
:System.RuntimeTypeHandle TargetTypeToken(System.TypedReference)
:System.Object ToObject(System.TypedReference)
```

## `System.UInt16`

```lua
-- fields
MaxValue: System.UInt16 [static]
MinValue: System.UInt16 [static]
mValue: System.UInt16
-- methods
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
-- static
:System.UInt16 Parse(System.String)
:System.Boolean TryParse(System.String, System.UInt16)
```

## `System.UInt16[,]`

```lua
-- methods
:System.UInt16 Address(System.Int32, System.Int32)
:System.UInt16 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.UInt16)
```

## `System.UInt32`

```lua
-- fields
MaxValue: System.UInt32 [static]
MinValue: System.UInt32 [static]
mValue: System.UInt32
-- methods
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
-- static
:System.UInt32 Parse(System.String)
:System.Boolean TryParse(System.String, System.UInt32)
```

## `System.UInt32[,]`

```lua
-- methods
:System.UInt32 Address(System.Int32, System.Int32)
:System.UInt32 Get(System.Int32, System.Int32)
:System.Void Set(System.Int32, System.Int32, System.UInt32)
```

## `System.UInt64`

```lua
-- fields
MaxValue: System.UInt64 [static]
MinValue: System.UInt64 [static]
mValue: System.UInt64
-- methods
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
-- static
:System.UInt64 Parse(System.String)
:System.Boolean TryParse(System.String, System.UInt64)
```

## `System.UIntPtr`

```lua
-- fields
mValue: System.UInt64
-- methods
:System.Int32 GetHashCode()
:System.String ToString()
```

## `System.UnhandledExceptionEventArgs`

```lua
-- fields
mException: System.Object
-- methods
:System.Object get_ExceptionObject()
```

## `System.UnhandledExceptionEventHandler`

```lua
-- methods
:System.Void Invoke(System.Object, System.UnhandledExceptionEventArgs)
```

## `System.ValueTuple`

```lua
-- methods
:System.Boolean Equals(System.Object)
:System.Int32 System.Collections.IStructuralComparable.CompareTo(System.Object, System.Collections.IComparer)
:System.Boolean System.Collections.IStructuralEquatable.Equals(System.Object, System.Collections.IEqualityComparer)
:System.Int32 System.IComparable.CompareTo(System.Object)
:System.String System.IValueTupleInternal.ToStringEnd()
:System.Object System.Runtime.CompilerServices.ITuple.get_Item(System.Int32)
:System.String ToString()
-- static
:System.Int32 CombineHashCodes(System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.Int32 CombineHashCodes(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.ValueTuple Create()
```

## `System.ValueType`

```lua
-- methods
:System.Boolean Equals(System.Object)
:System.Int32 GetHashCode()
:System.String ToString()
```
