# `ace.*`

19 types.

## `ace.cWind`

```lua
-- fields
DELETE_SEC: System.Single [static]
_WIND_ANGLE: via.vec2[] [static]
_WIND_GAIN: System.Single[] [static]
_WIND_SPEED_RANGE: via.vec2[] [static]
__ReadOnly__: System.Boolean [static]
__Setting__: System.Boolean [static]
Cycle0: System.Single
Cycle1: System.Single
IsActive: System.Boolean
IsDelete: System.Boolean
Life: System.Single
Speed0: System.Single
Speed1: System.Single
_Cycle: System.Single
_CycleTimer: System.Single
_DeleteLife: System.Single
_DeleteTimer: System.Single
_Gain: System.Single
_LifeRate: System.Single
_LifeTimer: System.Single
_Speed: System.Single
_SpeedAim: System.Single
_WindPower: ace.cWind.WIND_POWER
-- methods
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
-- static
:System.Single getAttenuationRate(System.Single, ace.cWind.ATTENUATION_RATE)
:via.vec2 getWindAngle(ace.cWind.WIND_DIRECTION)
:via.vec2 getWindAngle(System.UInt32)
:System.Single getWindGain(ace.cWind.RECV_TARGET)
:via.vec2 getWindSpeedRange(ace.cWind.WIND_POWER)
:via.vec2 getWindSpeedRange(System.UInt32)
```

## `ace.cWind.ATTENUATION_RATE`

```lua
-- values (System.Int32 enum)
EXP2_CURVE
EXP_CURVE
HALF_LINEAR
LINEAR
```

## `ace.cWind.RECV_TARGET`

```lua
-- values (System.Int32 enum)
CHAIN
CLOTH
EFFECT
GLASS
HAIR
NONE
```

## `ace.cWind.WIND_DIRECTION`

```lua
-- values (System.Int32 enum)
EAST
NORTH
NORTH_EAST
NORTH_WEST
SOUTH
SOUTH_EAST
SOUTH_WEST
WEST
```

## `ace.cWind.WIND_POWER`

```lua
-- values (System.Int32 enum)
POWER_0
POWER_1
POWER_10
POWER_11
POWER_12
POWER_13
POWER_14
POWER_15
POWER_2
POWER_3
POWER_4
POWER_5
POWER_6
POWER_7
POWER_8
POWER_9
POWER_ZERO
```

## `ace.cWindDirectional`

```lua
-- methods
:via.vec3 getWind(via.vec3)
:System.Void setAngle(via.vec2, via.vec2)
:System.Void setAngleRange(via.vec2, via.vec2)
:System.Void setup()
:System.Void updateAim()
:System.Void updateAngleAim()
:System.Void updateParam(System.Single)
```

## `ace.cWindGlobal`

```lua
-- fields
Angle0: via.vec2
Angle1: via.vec2
_Angle: via.vec2
_AngleAim: via.vec2
_Direction: via.vec3
```

## `ace.cWindLocal`

```lua
-- fields
AttenuationRate: ace.cWind.ATTENUATION_RATE
IsInhale: System.Boolean
Position: via.vec3
RadiusBegin: System.Single
RadiusEnd: System.Single
```

## `ace.cWindPoint`

```lua
-- methods
:via.vec3 getWind(via.vec3)
```

## `ace.cWindSetting`

```lua
-- fields
Cycle0: System.Single
Cycle1: System.Single
Life: System.Single
Speed0: System.Single
Speed1: System.Single
_WindPower: ace.cWind.WIND_POWER
-- methods
:ace.cWind.WIND_POWER get_WindPower()
:System.Void set_WindPower(ace.cWind.WIND_POWER)
```

## `ace.cWindSettingGlobal`

```lua
-- fields
Angle0: via.vec2
Angle1: via.vec2
_WindDirection: ace.cWind.WIND_DIRECTION
-- methods
:ace.cWind.WIND_DIRECTION get_WindDirection()
:System.Void set_WindDirection(ace.cWind.WIND_DIRECTION)
```

## `ace.cWindSettingLocal`

```lua
-- fields
AttenuationRate: ace.cWind.ATTENUATION_RATE
IsInhale: System.Boolean
Position: via.vec3
RadiusBegin: System.Single
RadiusEnd: System.Single
```

## `ace.cWindSettingSpot`

```lua
-- fields
Angle0: via.vec2
Angle1: via.vec2
FanSize: System.Single
_Fov: System.Single
-- methods
:System.Single get_Fov()
:System.Void set_Fov(System.Single)
```

## `ace.cWindSpot`

```lua
-- fields
Angle0: via.vec2
Angle1: via.vec2
FanSize: System.Single
_Angle: via.vec2
_AngleAim: via.vec2
_Direction: via.vec3
_Fov: System.Single
_PositionCone: via.vec3
-- methods
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

```lua
-- fields
_CommandArray: ace.cWindSystem.COMMAND[]
_LockGlobal: System.Object
_LockLocal: System.Object
_UseNumCommand: System.Int32
_UseNumCommandMax: System.Int32
_UseNumWindGlobal: System.Int32
_UseNumWindGlobalMax: System.Int32
_UseNumWindLocal: System.Int32
_UseNumWindLocalMax: System.Int32
_WindListGlobal: System.Collections.Generic.List`1<ace.cWindGlobal>
_WindListLocal: System.Collections.Generic.List`1<ace.cWindLocal>
-- methods
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

```lua
-- fields
Type: System.Int32
Wind: ace.cWind
```

## `ace.cWindSystem.COMMAND.TYPE`

```lua
-- fields
ADD_GLOBAL: System.Int32 [static]
ADD_LOCAL: System.Int32 [static]
NONE: System.Int32 [static]
```

## `ace.user_data.EnumMaker`

```lua
-- fields
_DataList: System.Collections.Generic.List`1<ace.user_data.EnumMaker.cData>
_ExportClassName: System.String
_ExportEnumName: System.String
_ExportNamespaceName: System.String
_FixedIDCounter: System.Int32
```

## `ace.user_data.EnumMaker.cData`

```lua
-- fields
_EnumName: System.String
_FixedID: System.Int32
-- methods
:System.String get_EnumName()
:System.Int32 get_FixedID()
:System.Void set_EnumName(System.String)
:System.Void set_FixedID(System.Int32)
```
