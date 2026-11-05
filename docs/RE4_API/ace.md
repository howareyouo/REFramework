# `ace.*`

30 types.

## `ace.cWind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DELETE_SEC` | `System.Single` | yes | 16 |
| `_WIND_SPEED_RANGE` | `via.vec2[]` | yes | 16 |
| `__ReadOnly__` | `System.Boolean` | yes | 16 |
| `__Setting__` | `System.Boolean` | yes | 16 |
| `_WIND_ANGLE` | `via.vec2[]` | yes | 24 |
| `_WIND_GAIN` | `System.Single[]` | yes | 32 |
| `IsActive` | `System.Boolean` |  | 16 |
| `IsDelete` | `System.Boolean` |  | 17 |
| `Life` | `System.Single` |  | 20 |
| `_LifeTimer` | `System.Single` |  | 24 |
| `_LifeRate` | `System.Single` |  | 28 |
| `Cycle0` | `System.Single` |  | 32 |
| `Cycle1` | `System.Single` |  | 36 |
| `_Cycle` | `System.Single` |  | 40 |
| `_CycleTimer` | `System.Single` |  | 44 |
| `_DeleteLife` | `System.Single` |  | 48 |
| `_DeleteTimer` | `System.Single` |  | 52 |
| `Speed0` | `System.Single` |  | 56 |
| `Speed1` | `System.Single` |  | 60 |
| `_SpeedAim` | `System.Single` |  | 64 |
| `_Speed` | `System.Single` |  | 68 |
| `_Gain` | `System.Single` |  | 72 |
| `_WindPower` | `ace.cWind.WIND_POWER` |  | 76 |

**Methods**

```lua
:System.Void .ctor()
:System.Void delete()
:System.Void forceSetAimSpeed()
:via.vec3 getWind(via.vec3)
:System.Single get_LifeRate()
:System.Single get_Speed()
:ace.cWind.WIND_POWER get_WindPower()
:System.Single get__WindSpeed()
:System.Void setSpeed(System.Single, System.Single)
:System.Void setSpeedRange(System.Single, System.Single)
:System.Void set_WindPower(ace.cWind.WIND_POWER)
:System.Void setup()
:System.Void update(System.Single)
:System.Void updateAim()
:System.Void updateCycle()
:System.Void updateParam(System.Single)
:System.Void updateSpeedAim()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getAttenuationRate", ...)  -- System.Single getAttenuationRate(System.Single, ace.cWind.ATTENUATION_RATE)
sdk.call_native_func(nil, type_def, "getWindAngle", ...)  -- via.vec2 getWindAngle(ace.cWind.WIND_DIRECTION)
sdk.call_native_func(nil, type_def, "getWindAngle", ...)  -- via.vec2 getWindAngle(System.UInt32)
sdk.call_native_func(nil, type_def, "getWindGain", ...)  -- System.Single getWindGain(ace.cWind.RECV_TARGET)
sdk.call_native_func(nil, type_def, "getWindSpeedRange", ...)  -- via.vec2 getWindSpeedRange(ace.cWind.WIND_POWER)
sdk.call_native_func(nil, type_def, "getWindSpeedRange", ...)  -- via.vec2 getWindSpeedRange(System.UInt32)
```

## `ace.cWind.ATTENUATION_RATE`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EXP2_CURVE` | `ace.cWind.ATTENUATION_RATE` | yes | 16 |
| `EXP_CURVE` | `ace.cWind.ATTENUATION_RATE` | yes | 16 |
| `HALF_LINEAR` | `ace.cWind.ATTENUATION_RATE` | yes | 16 |
| `LINEAR` | `ace.cWind.ATTENUATION_RATE` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `ace.cWind.ATTENUATION_RATE[]`

**Methods**

```lua
:System.Void Add(ace.cWind.ATTENUATION_RATE)
:ace.cWind.ATTENUATION_RATE Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWind.ATTENUATION_RATE)
:System.Void CopyTo(ace.cWind.ATTENUATION_RATE[], System.Int32)
:ace.cWind.ATTENUATION_RATE Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWind.ATTENUATION_RATE> GetEnumerator()
:System.Int32 IndexOf(ace.cWind.ATTENUATION_RATE)
:System.Void Insert(System.Int32, ace.cWind.ATTENUATION_RATE)
:System.Boolean Remove(ace.cWind.ATTENUATION_RATE)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWind.ATTENUATION_RATE)
:ace.cWind.ATTENUATION_RATE get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWind.ATTENUATION_RATE)
```

## `ace.cWind.RECV_TARGET`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CHAIN` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `CLOTH` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `EFFECT` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `GLASS` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `HAIR` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `NONE` | `ace.cWind.RECV_TARGET` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `ace.cWind.RECV_TARGET[]`

**Methods**

```lua
:System.Void Add(ace.cWind.RECV_TARGET)
:ace.cWind.RECV_TARGET Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWind.RECV_TARGET)
:System.Void CopyTo(ace.cWind.RECV_TARGET[], System.Int32)
:ace.cWind.RECV_TARGET Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWind.RECV_TARGET> GetEnumerator()
:System.Int32 IndexOf(ace.cWind.RECV_TARGET)
:System.Void Insert(System.Int32, ace.cWind.RECV_TARGET)
:System.Boolean Remove(ace.cWind.RECV_TARGET)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWind.RECV_TARGET)
:ace.cWind.RECV_TARGET get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWind.RECV_TARGET)
```

## `ace.cWind.WIND_DIRECTION`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EAST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `NORTH` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `NORTH_EAST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `NORTH_WEST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `SOUTH` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `SOUTH_EAST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `SOUTH_WEST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `WEST` | `ace.cWind.WIND_DIRECTION` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `ace.cWind.WIND_DIRECTION[]`

**Methods**

```lua
:System.Void Add(ace.cWind.WIND_DIRECTION)
:ace.cWind.WIND_DIRECTION Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWind.WIND_DIRECTION)
:System.Void CopyTo(ace.cWind.WIND_DIRECTION[], System.Int32)
:ace.cWind.WIND_DIRECTION Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWind.WIND_DIRECTION> GetEnumerator()
:System.Int32 IndexOf(ace.cWind.WIND_DIRECTION)
:System.Void Insert(System.Int32, ace.cWind.WIND_DIRECTION)
:System.Boolean Remove(ace.cWind.WIND_DIRECTION)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWind.WIND_DIRECTION)
:ace.cWind.WIND_DIRECTION get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWind.WIND_DIRECTION)
```

## `ace.cWind.WIND_POWER`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `POWER_0` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_1` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_10` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_11` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_12` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_13` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_14` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_15` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_2` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_3` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_4` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_5` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_6` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_7` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_8` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_9` | `ace.cWind.WIND_POWER` | yes | 16 |
| `POWER_ZERO` | `ace.cWind.WIND_POWER` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `ace.cWind.WIND_POWER[]`

**Methods**

```lua
:System.Void Add(ace.cWind.WIND_POWER)
:ace.cWind.WIND_POWER Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWind.WIND_POWER)
:System.Void CopyTo(ace.cWind.WIND_POWER[], System.Int32)
:ace.cWind.WIND_POWER Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWind.WIND_POWER> GetEnumerator()
:System.Int32 IndexOf(ace.cWind.WIND_POWER)
:System.Void Insert(System.Int32, ace.cWind.WIND_POWER)
:System.Boolean Remove(ace.cWind.WIND_POWER)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWind.WIND_POWER)
:ace.cWind.WIND_POWER get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWind.WIND_POWER)
```

## `ace.cWindDirectional`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingDirectional)
:via.vec3 getWind(via.vec3)
:System.Void setAngle(via.vec2, via.vec2)
:System.Void setAngleRange(via.vec2, via.vec2)
:System.Void setup()
:System.Void updateAim()
:System.Void updateAngleAim()
:System.Void updateParam(System.Single)
```

## `ace.cWindGlobal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Angle0` | `via.vec2` |  | 80 |
| `Angle1` | `via.vec2` |  | 96 |
| `_AngleAim` | `via.vec2` |  | 112 |
| `_Angle` | `via.vec2` |  | 128 |
| `_Direction` | `via.vec3` |  | 144 |

**Methods**

```lua
:System.Void .ctor()
```

## `ace.cWindGlobal[]`

**Methods**

```lua
:System.Void Add(ace.cWindGlobal)
:ace.cWindGlobal Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWindGlobal)
:System.Void CopyTo(ace.cWindGlobal[], System.Int32)
:ace.cWindGlobal Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWindGlobal> GetEnumerator()
:System.Int32 IndexOf(ace.cWindGlobal)
:System.Void Insert(System.Int32, ace.cWindGlobal)
:System.Boolean Remove(ace.cWindGlobal)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWindGlobal)
:ace.cWindGlobal get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWindGlobal)
```

## `ace.cWindLocal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Position` | `via.vec3` |  | 80 |
| `RadiusBegin` | `System.Single` |  | 96 |
| `RadiusEnd` | `System.Single` |  | 100 |
| `AttenuationRate` | `ace.cWind.ATTENUATION_RATE` |  | 104 |
| `IsInhale` | `System.Boolean` |  | 108 |

**Methods**

```lua
:System.Void .ctor()
```

## `ace.cWindLocal[]`

**Methods**

```lua
:System.Void Add(ace.cWindLocal)
:ace.cWindLocal Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWindLocal)
:System.Void CopyTo(ace.cWindLocal[], System.Int32)
:ace.cWindLocal Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWindLocal> GetEnumerator()
:System.Int32 IndexOf(ace.cWindLocal)
:System.Void Insert(System.Int32, ace.cWindLocal)
:System.Boolean Remove(ace.cWindLocal)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWindLocal)
:ace.cWindLocal get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWindLocal)
```

## `ace.cWindPoint`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingPoint)
:via.vec3 getWind(via.vec3)
```

## `ace.cWindSetting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Life` | `System.Single` |  | 16 |
| `Cycle0` | `System.Single` |  | 20 |
| `Cycle1` | `System.Single` |  | 24 |
| `Speed0` | `System.Single` |  | 28 |
| `Speed1` | `System.Single` |  | 32 |
| `_WindPower` | `ace.cWind.WIND_POWER` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSetting)
:ace.cWind.WIND_POWER get_WindPower()
:System.Void set_WindPower(ace.cWind.WIND_POWER)
```

## `ace.cWindSettingDirectional`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingDirectional, via.vec2)
```

## `ace.cWindSettingGlobal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Angle0` | `via.vec2` |  | 48 |
| `Angle1` | `via.vec2` |  | 64 |
| `_WindDirection` | `ace.cWind.WIND_DIRECTION` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingGlobal, via.vec2)
:ace.cWind.WIND_DIRECTION get_WindDirection()
:System.Void set_WindDirection(ace.cWind.WIND_DIRECTION)
```

## `ace.cWindSettingLocal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Position` | `via.vec3` |  | 48 |
| `RadiusBegin` | `System.Single` |  | 64 |
| `RadiusEnd` | `System.Single` |  | 68 |
| `AttenuationRate` | `ace.cWind.ATTENUATION_RATE` |  | 72 |
| `IsInhale` | `System.Boolean` |  | 76 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingLocal, via.vec3)
```

## `ace.cWindSettingPoint`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingPoint, via.vec3)
```

## `ace.cWindSettingSpot`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Angle0` | `via.vec2` |  | 80 |
| `Angle1` | `via.vec2` |  | 96 |
| `_Fov` | `System.Single` |  | 112 |
| `FanSize` | `System.Single` |  | 116 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingSpot, via.vec3, via.vec2)
:System.Single get_Fov()
:System.Void set_Fov(System.Single)
```

## `ace.cWindSpot`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Fov` | `System.Single` |  | 112 |
| `FanSize` | `System.Single` |  | 116 |
| `_PositionCone` | `via.vec3` |  | 128 |
| `Angle0` | `via.vec2` |  | 144 |
| `Angle1` | `via.vec2` |  | 160 |
| `_AngleAim` | `via.vec2` |  | 176 |
| `_Angle` | `via.vec2` |  | 192 |
| `_Direction` | `via.vec3` |  | 208 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(ace.cWindSettingSpot)
:via.vec3 getWind(via.vec3)
:System.Single get_Fov()
:via.vec3 get_PositionCone()
:System.Void setAngle(via.vec2, via.vec2)
:System.Void setAngleRange(via.vec2, via.vec2)
:System.Void set_Fov(System.Single)
:System.Void setup()
:System.Void updateAim()
:System.Void updateAngleAim()
:System.Void updateParam(System.Single)
```

## `ace.cWindSystem`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_WindListGlobal` | `System.Collections.Generic.List`1<ace.cWindGlobal>` |  | 16 |
| `_WindListLocal` | `System.Collections.Generic.List`1<ace.cWindLocal>` |  | 24 |
| `_CommandArray` | `ace.cWindSystem.COMMAND[]` |  | 32 |
| `_UseNumCommand` | `System.Int32` |  | 40 |
| `_UseNumCommandMax` | `System.Int32` |  | 44 |
| `_UseNumWindGlobal` | `System.Int32` |  | 48 |
| `_UseNumWindGlobalMax` | `System.Int32` |  | 52 |
| `_UseNumWindLocal` | `System.Int32` |  | 56 |
| `_UseNumWindLocalMax` | `System.Int32` |  | 60 |
| `_LockGlobal` | `System.Object` |  | 64 |
| `_LockLocal` | `System.Object` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Void add(ace.cWindGlobal)
:System.Void add(ace.cWindLocal)
:System.Void drawDebug(via.vec3)
:System.Void forceSetAimSpeed()
:via.vec3 getWind(via.vec3)
:via.vec3 getWindGlobal()
:System.Collections.Generic.List`1<ace.cWindLocal> get_WindListLocal()
:System.Void initialize(System.Int32)
:System.Void reset()
:System.Void update(System.Single)
```

## `ace.cWindSystem.COMMAND`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Wind` | `ace.cWind` |  | 16 |
| `Type` | `System.Int32` |  | 24 |

## `ace.cWindSystem.COMMAND.TYPE`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ADD_GLOBAL` | `System.Int32` | yes | 16 |
| `ADD_LOCAL` | `System.Int32` | yes | 16 |
| `NONE` | `System.Int32` | yes | 16 |

## `ace.cWindSystem.COMMAND[]`

**Methods**

```lua
:System.Void Add(ace.cWindSystem.COMMAND)
:ace.cWindSystem.COMMAND Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.cWindSystem.COMMAND)
:System.Void CopyTo(ace.cWindSystem.COMMAND[], System.Int32)
:ace.cWindSystem.COMMAND Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.cWindSystem.COMMAND> GetEnumerator()
:System.Int32 IndexOf(ace.cWindSystem.COMMAND)
:System.Void Insert(System.Int32, ace.cWindSystem.COMMAND)
:System.Boolean Remove(ace.cWindSystem.COMMAND)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.cWindSystem.COMMAND)
:ace.cWindSystem.COMMAND get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.cWindSystem.COMMAND)
```

## `ace.user_data.AceUserData`

_No fields or methods._

## `ace.user_data.EnumMaker`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_DataList` | `System.Collections.Generic.List`1<ace.user_data.EnumMaker.cData>` |  | 32 |
| `_FixedIDCounter` | `System.Int32` |  | 40 |
| `_ExportNamespaceName` | `System.String` |  | 48 |
| `_ExportClassName` | `System.String` |  | 56 |
| `_ExportEnumName` | `System.String` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
```

## `ace.user_data.EnumMaker.cData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_EnumName` | `System.String` |  | 16 |
| `_FixedID` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_EnumName()
:System.Int32 get_FixedID()
:System.Void set_EnumName(System.String)
:System.Void set_FixedID(System.Int32)
```

## `ace.user_data.EnumMaker.cData[]`

**Methods**

```lua
:System.Void Add(ace.user_data.EnumMaker.cData)
:ace.user_data.EnumMaker.cData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(ace.user_data.EnumMaker.cData)
:System.Void CopyTo(ace.user_data.EnumMaker.cData[], System.Int32)
:ace.user_data.EnumMaker.cData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<ace.user_data.EnumMaker.cData> GetEnumerator()
:System.Int32 IndexOf(ace.user_data.EnumMaker.cData)
:System.Void Insert(System.Int32, ace.user_data.EnumMaker.cData)
:System.Boolean Remove(ace.user_data.EnumMaker.cData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, ace.user_data.EnumMaker.cData)
:ace.user_data.EnumMaker.cData get_Item(System.Int32)
:System.Void set_Item(System.Int32, ace.user_data.EnumMaker.cData)
```
