# `app.*`

444 types.

## `app.Accessor_GimmickActorCharacterMFsmUserVariables`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Keys` | `System.UInt64[]` | yes | 16 |
| `<Hub>k__BackingField` | `via.userdata.UserVariablesHub` |  | 16 |
| `_OnJacked` | `via.userdata.Variable` |  | 24 |
| `_MoveDir` | `via.userdata.Variable` |  | 32 |
| `_TargetMoveDir` | `via.userdata.Variable` |  | 40 |
| `_MoveSpeed` | `via.userdata.Variable` |  | 48 |
| `_MoveDirectionLRFB` | `via.userdata.Variable` |  | 56 |
| `_MoveDirectionIsFront` | `via.userdata.Variable` |  | 64 |
| `_MoveDirectionIsLeft` | `via.userdata.Variable` |  | 72 |
| `_MoveDirectionIsRight` | `via.userdata.Variable` |  | 80 |
| `_MoveDirectionIsBack` | `via.userdata.Variable` |  | 88 |
| `_MoveArrival` | `via.userdata.Variable` |  | 96 |
| `_LastDamageDirectionLRFB` | `via.userdata.Variable` |  | 104 |
| `_IsLastDamageFromFront` | `via.userdata.Variable` |  | 112 |
| `_IsLastDamageFromLeft` | `via.userdata.Variable` |  | 120 |
| `_IsLastDamageFromAbove` | `via.userdata.Variable` |  | 128 |
| `_IsLastDamageFrontLeft` | `via.userdata.Variable` |  | 136 |
| `_IsLastDamageFrontRight` | `via.userdata.Variable` |  | 144 |
| `_ActionTargetDirectionLRFB` | `via.userdata.Variable` |  | 152 |
| `_ActionTargetDirectionIsFront` | `via.userdata.Variable` |  | 160 |
| `_ActionTargetDirectionIsLeft` | `via.userdata.Variable` |  | 168 |
| `_ActionTargetDirectionIsRight` | `via.userdata.Variable` |  | 176 |
| `_ActionTargetDirectionIsBack` | `via.userdata.Variable` |  | 184 |
| `_IsWalk` | `via.userdata.Variable` |  | 192 |

**Methods**

```lua
:System.Void .ctor(via.userdata.UserVariablesHub)
:System.Void Setup()
:System.Boolean get_ActionTargetDirectionIsBack()
:System.Boolean get_ActionTargetDirectionIsFront()
:System.Boolean get_ActionTargetDirectionIsLeft()
:System.Boolean get_ActionTargetDirectionIsRight()
:System.UInt32 get_ActionTargetDirectionLRFB()
:via.userdata.UserVariablesHub get_Hub()
:System.Boolean get_IsLastDamageFromAbove()
:System.Boolean get_IsLastDamageFromFront()
:System.Boolean get_IsLastDamageFromLeft()
:System.Boolean get_IsLastDamageFrontLeft()
:System.Boolean get_IsLastDamageFrontRight()
:System.Boolean get_IsWalk()
:System.UInt32 get_LastDamageDirectionLRFB()
:System.Boolean get_MoveArrival()
:System.Single get_MoveDir()
:System.Boolean get_MoveDirectionIsBack()
:System.Boolean get_MoveDirectionIsFront()
:System.Boolean get_MoveDirectionIsLeft()
:System.Boolean get_MoveDirectionIsRight()
:System.UInt32 get_MoveDirectionLRFB()
:System.Single get_MoveSpeed()
:System.Boolean get_OnJacked()
:System.Single get_TargetMoveDir()
:System.Void set_ActionTargetDirectionIsBack(System.Boolean)
:System.Void set_ActionTargetDirectionIsFront(System.Boolean)
:System.Void set_ActionTargetDirectionIsLeft(System.Boolean)
:System.Void set_ActionTargetDirectionIsRight(System.Boolean)
:System.Void set_ActionTargetDirectionLRFB(System.UInt32)
:System.Void set_Hub(via.userdata.UserVariablesHub)
:System.Void set_IsLastDamageFromAbove(System.Boolean)
:System.Void set_IsLastDamageFromFront(System.Boolean)
:System.Void set_IsLastDamageFromLeft(System.Boolean)
:System.Void set_IsLastDamageFrontLeft(System.Boolean)
:System.Void set_IsLastDamageFrontRight(System.Boolean)
:System.Void set_IsWalk(System.Boolean)
:System.Void set_LastDamageDirectionLRFB(System.UInt32)
:System.Void set_MoveArrival(System.Boolean)
:System.Void set_MoveDir(System.Single)
:System.Void set_MoveDirectionIsBack(System.Boolean)
:System.Void set_MoveDirectionIsFront(System.Boolean)
:System.Void set_MoveDirectionIsLeft(System.Boolean)
:System.Void set_MoveDirectionIsRight(System.Boolean)
:System.Void set_MoveDirectionLRFB(System.UInt32)
:System.Void set_MoveSpeed(System.Single)
:System.Void set_OnJacked(System.Boolean)
:System.Void set_TargetMoveDir(System.Single)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "<Setup>g__find|94_0", ...)  -- via.userdata.Variable <Setup>g__find|94_0(app.Accessor_GimmickActorCharacterMFsmUserVariables.<>c__DisplayClass94_0, app.Accessor_GimmickActorCharacterMFsmUserVariables.<>c__DisplayClass94_1)
```

## `app.Accessor_GimmickActorPlayerMFsmUserVariables`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Keys` | `System.UInt64[]` | yes | 16 |
| `<Hub>k__BackingField` | `via.userdata.UserVariablesHub` |  | 16 |
| `_Jogging` | `via.userdata.Variable` |  | 24 |
| `_GimmickActorCharacterMFsmUserVariables_OnJacked` | `via.userdata.Variable` |  | 32 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDir` | `via.userdata.Variable` |  | 40 |
| `_GimmickActorCharacterMFsmUserVariables_TargetMoveDir` | `via.userdata.Variable` |  | 48 |
| `_GimmickActorCharacterMFsmUserVariables_MoveSpeed` | `via.userdata.Variable` |  | 56 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDirectionLRFB` | `via.userdata.Variable` |  | 64 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsFront` | `via.userdata.Variable` |  | 72 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsLeft` | `via.userdata.Variable` |  | 80 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsRight` | `via.userdata.Variable` |  | 88 |
| `_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsBack` | `via.userdata.Variable` |  | 96 |
| `_GimmickActorCharacterMFsmUserVariables_MoveArrival` | `via.userdata.Variable` |  | 104 |
| `_GimmickActorCharacterMFsmUserVariables_LastDamageDirectionLRFB` | `via.userdata.Variable` |  | 112 |
| `_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromFront` | `via.userdata.Variable` |  | 120 |
| `_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromLeft` | `via.userdata.Variable` |  | 128 |
| `_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromAbove` | `via.userdata.Variable` |  | 136 |
| `_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontLeft` | `via.userdata.Variable` |  | 144 |
| `_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontRight` | `via.userdata.Variable` |  | 152 |
| `_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionLRFB` | `via.userdata.Variable` |  | 160 |
| `_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsFront` | `via.userdata.Variable` |  | 168 |
| `_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsLeft` | `via.userdata.Variable` |  | 176 |
| `_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsRight` | `via.userdata.Variable` |  | 184 |
| `_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsBack` | `via.userdata.Variable` |  | 192 |
| `_GimmickActorCharacterMFsmUserVariables_IsWalk` | `via.userdata.Variable` |  | 200 |

**Methods**

```lua
:System.Void .ctor(via.userdata.UserVariablesHub)
:System.Void Setup()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsBack()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsFront()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsLeft()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsRight()
:System.UInt32 get_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionLRFB()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromAbove()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromFront()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromLeft()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontLeft()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontRight()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_IsWalk()
:System.UInt32 get_GimmickActorCharacterMFsmUserVariables_LastDamageDirectionLRFB()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_MoveArrival()
:System.Single get_GimmickActorCharacterMFsmUserVariables_MoveDir()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsBack()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsFront()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsLeft()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsRight()
:System.UInt32 get_GimmickActorCharacterMFsmUserVariables_MoveDirectionLRFB()
:System.Single get_GimmickActorCharacterMFsmUserVariables_MoveSpeed()
:System.Boolean get_GimmickActorCharacterMFsmUserVariables_OnJacked()
:System.Single get_GimmickActorCharacterMFsmUserVariables_TargetMoveDir()
:via.userdata.UserVariablesHub get_Hub()
:System.Boolean get_Jogging()
:System.Void set_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsBack(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsFront(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsLeft(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionIsRight(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_ActionTargetDirectionLRFB(System.UInt32)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromAbove(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromFront(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsLastDamageFromLeft(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontLeft(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsLastDamageFrontRight(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_IsWalk(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_LastDamageDirectionLRFB(System.UInt32)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveArrival(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDir(System.Single)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsBack(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsFront(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsLeft(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDirectionIsRight(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveDirectionLRFB(System.UInt32)
:System.Void set_GimmickActorCharacterMFsmUserVariables_MoveSpeed(System.Single)
:System.Void set_GimmickActorCharacterMFsmUserVariables_OnJacked(System.Boolean)
:System.Void set_GimmickActorCharacterMFsmUserVariables_TargetMoveDir(System.Single)
:System.Void set_Hub(via.userdata.UserVariablesHub)
:System.Void set_Jogging(System.Boolean)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "<Setup>g__find|98_0", ...)  -- via.userdata.Variable <Setup>g__find|98_0(app.Accessor_GimmickActorPlayerMFsmUserVariables.<>c__DisplayClass98_0, app.Accessor_GimmickActorPlayerMFsmUserVariables.<>c__DisplayClass98_1)
```

## `app.AssetLabelData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RootData` | `app.LabelData` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.CommonUserdataBase`

_No fields or methods._

## `app.EffectorLocator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AIMap` | `via.GameObjectRef` |  | 80 |
| `_AIMap` | `via.navigation.AIMap` |  | 96 |
| `Effector` | `via.GameObjectRef` |  | 104 |
| `_Effector` | `via.navigation.AIMapEffector` |  | 120 |
| `UpdateTime` | `System.Single` |  | 128 |
| `<Timer>k__BackingField` | `System.Single` |  | 132 |
| `_RequestFix` | `System.Boolean` |  | 136 |
| `_NodeQueryInfo` | `via.navigation.NodeQueryInfo` |  | 144 |
| `_Sphere` | `via.Sphere` |  | 160 |
| `SearchRange` | `System.Single` |  | 176 |
| `EnableProfile` | `System.Boolean` |  | 180 |

**Methods**

```lua
:System.Void .ctor()
:System.Void EffectorFixCheck()
:System.Boolean IsRestartTimeOver()
:System.Single get_Timer()
:System.Void set_Timer(System.Single)
:System.Void start()
:System.Void update()
```

## `app.LabelData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Name` | `System.String` |  | 16 |
| `Color` | `via.Color` |  | 24 |
| `Children` | `System.Collections.Generic.List`1<app.LabelData>` |  | 32 |
| `Depended` | `System.Collections.Generic.List`1<System.String>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.LabelData[]`

**Methods**

```lua
:System.Void Add(app.LabelData)
:app.LabelData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.LabelData)
:System.Void CopyTo(app.LabelData[], System.Int32)
:app.LabelData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.LabelData> GetEnumerator()
:System.Int32 IndexOf(app.LabelData)
:System.Void Insert(System.Int32, app.LabelData)
:System.Boolean Remove(app.LabelData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.LabelData)
:app.LabelData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.LabelData)
```

## `app.MotionUtil`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HumanJointHashList` | `System.Collections.Generic.List`1<System.UInt32>` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "drawSkeletonAll", ...)  -- System.Void drawSkeletonAll(via.GameObject, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonAll", ...)  -- System.Void drawSkeletonAll(via.motion.Motion, System.UInt32, System.UInt32, System.UInt32, System.Single, via.mat4, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonCore", ...)  -- System.Void drawSkeletonCore(System.Collections.Generic.List`1<app.MotionUtil.JointInfo>, via.mat4, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonHuman", ...)  -- System.Void drawSkeletonHuman(via.GameObject, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonHuman", ...)  -- System.Void drawSkeletonHuman(via.GameObject, via.motion.TreeLayer, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonHuman", ...)  -- System.Void drawSkeletonHuman(via.motion.Motion, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawSkeletonHuman", ...)  -- System.Void drawSkeletonHuman(via.motion.Motion, System.UInt32, System.UInt32, System.UInt32, System.Single, via.mat4, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.GameObject, System.Collections.Generic.List`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.GameObject, System.Func`2<via.Joint,System.Boolean>)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.motion.Motion, System.Collections.Generic.List`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.GameObject, via.motion.TreeLayer, System.Collections.Generic.List`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.GameObject, via.motion.TreeLayer, System.Func`2<via.Joint,System.Boolean>)
sdk.call_native_func(nil, type_def, "getJointInfoList", ...)  -- System.Collections.Generic.List`1<app.MotionUtil.JointInfo> getJointInfoList(via.motion.Motion, System.UInt32, System.UInt32, System.UInt32, System.Single, System.Func`2<via.Joint,System.Boolean>)
sdk.call_native_func(nil, type_def, "specify", ...)  -- System.Boolean specify(via.Joint)
```

## `app.MotionUtil.JointInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Mode` | `app.MotionUtil.JointInfo.Mode` |  | 16 |
| `Joint` | `via.Joint` |  | 24 |
| `WorldPosition` | `via.vec3` |  | 32 |
| `WorldMatrix` | `via.mat4` |  | 48 |
| `LocalPosition` | `via.vec3` |  | 112 |
| `LocalRotation` | `via.Quaternion` |  | 128 |
| `ParentInfo` | `app.MotionUtil.JointInfo` |  | 144 |

**Methods**

```lua
:System.Void .ctor(via.Joint, via.vec3, via.Quaternion)
:System.Void .ctor(via.Joint)
:System.Void .ctor(via.Joint, via.mat4, app.MotionUtil.JointInfo.Mode)
:System.Void calcWorld(via.mat4)
```

## `app.MotionUtil.JointInfo.Mode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Local` | `app.MotionUtil.JointInfo.Mode` | yes | 16 |
| `Model` | `app.MotionUtil.JointInfo.Mode` | yes | 16 |
| `World` | `app.MotionUtil.JointInfo.Mode` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.MotionUtil.JointInfo.Mode[]`

**Methods**

```lua
:System.Void Add(app.MotionUtil.JointInfo.Mode)
:app.MotionUtil.JointInfo.Mode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.MotionUtil.JointInfo.Mode)
:System.Void CopyTo(app.MotionUtil.JointInfo.Mode[], System.Int32)
:app.MotionUtil.JointInfo.Mode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.MotionUtil.JointInfo.Mode> GetEnumerator()
:System.Int32 IndexOf(app.MotionUtil.JointInfo.Mode)
:System.Void Insert(System.Int32, app.MotionUtil.JointInfo.Mode)
:System.Boolean Remove(app.MotionUtil.JointInfo.Mode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.MotionUtil.JointInfo.Mode)
:app.MotionUtil.JointInfo.Mode get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.MotionUtil.JointInfo.Mode)
```

## `app.MotionUtil.JointInfo[]`

**Methods**

```lua
:System.Void Add(app.MotionUtil.JointInfo)
:app.MotionUtil.JointInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.MotionUtil.JointInfo)
:System.Void CopyTo(app.MotionUtil.JointInfo[], System.Int32)
:app.MotionUtil.JointInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.MotionUtil.JointInfo> GetEnumerator()
:System.Int32 IndexOf(app.MotionUtil.JointInfo)
:System.Void Insert(System.Int32, app.MotionUtil.JointInfo)
:System.Boolean Remove(app.MotionUtil.JointInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.MotionUtil.JointInfo)
:app.MotionUtil.JointInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.MotionUtil.JointInfo)
```

## `app.PathCalculator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Target` | `via.GameObjectRef` |  | 80 |
| `_NavWaypoint` | `via.navigation.NavigationWaypoint` |  | 96 |

**Methods**

```lua
:System.Void NavigationRequestTester()
:System.Void NavigationStart()
:System.Void awake()
```

## `app.dev1lab.AnalysisLogEventParamActive`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `extra_chapter_best_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData>` |  | 16 |
| `chapter_best_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData>` |  | 24 |
| `extra_best_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData>` |  | 32 |
| `best_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.BestClearData>` |  | 40 |
| `data_id` | `System.String` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.BestClearData> get_BestClearDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData> get_ChapterBestClearDataList()
:System.String get_DataId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData> get_ExtraBestClearDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData> get_ExtraChapterBestClearDataList()
:System.Void set_BestClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.BestClearData>)
:System.Void set_ChapterBestClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData>)
:System.Void set_DataId(System.String)
:System.Void set_ExtraBestClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData>)
:System.Void set_ExtraChapterBestClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData>)
```

## `app.dev1lab.AnalysisLogEventParamActive.BestClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `best_clear_time` | `System.Int64` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `hit_rate` | `System.Int64` |  | 32 |
| `clear_difficulty` | `System.String` |  | 40 |
| `total_playtime` | `System.Int64` |  | 48 |
| `gameover_count` | `System.Int64` |  | 56 |
| `clear_rank` | `System.String` |  | 64 |
| `save_count` | `System.Int64` |  | 72 |
| `game_id` | `System.String` |  | 80 |
| `damage_count` | `System.Int64` |  | 88 |

**Methods**

```lua
:System.Int64 get_BestClearTime()
:System.String get_ClearDifficulty()
:System.String get_ClearRank()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.String get_GameId()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_SaveCount()
:System.Int64 get_TotalPlaytime()
:System.Void set_BestClearTime(System.Int64)
:System.Void set_ClearDifficulty(System.String)
:System.Void set_ClearRank(System.String)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameId(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_TotalPlaytime(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamActive.BestClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:app.dev1lab.AnalysisLogEventParamActive.BestClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamActive.BestClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamActive.BestClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamActive.BestClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamActive.BestClearData)
:app.dev1lab.AnalysisLogEventParamActive.BestClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamActive.BestClearData)
```

## `app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `best_clear_time` | `System.Int64` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `hit_rate` | `System.Int64` |  | 32 |
| `clear_difficulty` | `System.String` |  | 40 |
| `total_playtime` | `System.Int64` |  | 48 |
| `gameover_count` | `System.Int64` |  | 56 |
| `clear_chapter` | `System.String` |  | 64 |
| `save_count` | `System.Int64` |  | 72 |
| `damage_count` | `System.Int64` |  | 80 |

**Methods**

```lua
:System.Int64 get_BestClearTime()
:System.String get_ClearChapter()
:System.String get_ClearDifficulty()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_SaveCount()
:System.Int64 get_TotalPlaytime()
:System.Void set_BestClearTime(System.Int64)
:System.Void set_ClearChapter(System.String)
:System.Void set_ClearDifficulty(System.String)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_TotalPlaytime(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData)
```

## `app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `best_clear_time` | `System.Int64` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `hit_rate` | `System.Int64` |  | 32 |
| `clear_difficulty` | `System.String` |  | 40 |
| `total_playtime` | `System.Int64` |  | 48 |
| `gameover_count` | `System.Int64` |  | 56 |
| `clear_rank` | `System.String` |  | 64 |
| `save_count` | `System.Int64` |  | 72 |
| `game_id` | `System.String` |  | 80 |
| `damage_count` | `System.Int64` |  | 88 |

**Methods**

```lua
:System.Int64 get_BestClearTime()
:System.String get_ClearDifficulty()
:System.String get_ClearRank()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.String get_GameId()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_SaveCount()
:System.Int64 get_TotalPlaytime()
:System.Void set_BestClearTime(System.Int64)
:System.Void set_ClearDifficulty(System.String)
:System.Void set_ClearRank(System.String)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameId(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_TotalPlaytime(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData)
```

## `app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `best_clear_time` | `System.Int64` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `hit_rate` | `System.Int64` |  | 32 |
| `clear_difficulty` | `System.String` |  | 40 |
| `total_playtime` | `System.Int64` |  | 48 |
| `gameover_count` | `System.Int64` |  | 56 |
| `clear_chapter` | `System.String` |  | 64 |
| `save_count` | `System.Int64` |  | 72 |
| `damage_count` | `System.Int64` |  | 80 |

**Methods**

```lua
:System.Int64 get_BestClearTime()
:System.String get_ClearChapter()
:System.String get_ClearDifficulty()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_SaveCount()
:System.Int64 get_TotalPlaytime()
:System.Void set_BestClearTime(System.Int64)
:System.Void set_ClearChapter(System.String)
:System.Void set_ClearDifficulty(System.String)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_TotalPlaytime(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
:app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData)
```

## `app.dev1lab.AnalysisLogEventParamAnalysis_accept`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `type` | `System.String` |  | 16 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_Type()
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamAnalysis_accept_cid`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `result` | `System.Int64` |  | 16 |

**Methods**

```lua
:System.String GetEventName()
:System.Int64 get_Result()
:System.Void set_Result(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamBase`

_No fields or methods._

## `app.dev1lab.AnalysisLogEventParamBonus_mode_play`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `bonus_modes` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes> get_BonusModesList()
:System.Void set_BonusModesList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes>)
```

## `app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `type` | `System.String` |  | 16 |
| `time` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Time()
:System.String get_Type()
:System.Void set_Time(System.Int64)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes[], System.Int32)
:app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
:app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes)
```

## `app.dev1lab.AnalysisLogEventParamChange_difficulty`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `game_id` | `System.String` |  | 16 |
| `progress_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData>` |  | 24 |
| `is_change` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.String get_GameId()
:System.Int64 get_IsChange()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData> get_ProgressDataList()
:System.Void set_GameId(System.String)
:System.Void set_IsChange(System.Int64)
:System.Void set_ProgressDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData>)
```

## `app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `type` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_Type()
:System.Void set_Id(System.String)
:System.Void set_Type(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
:app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData)
```

## `app.dev1lab.AnalysisLogEventParamDlc_get`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `game_id` | `System.String` |  | 16 |
| `dlcs` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs>` |  | 24 |
| `slot_no` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs> get_DlcsList()
:System.String get_GameId()
:System.String get_SlotNo()
:System.Void set_DlcsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs>)
:System.Void set_GameId(System.String)
:System.Void set_SlotNo(System.String)
```

## `app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs[], System.Int32)
:app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
:app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs)
```

## `app.dev1lab.AnalysisLogEventParamDlc_install`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `dlcs` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs> get_DlcsList()
:System.Void set_DlcsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs>)
```

## `app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs[], System.Int32)
:app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
:app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs)
```

## `app.dev1lab.AnalysisLogEventParamDlc_use_time`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `use_dlcs` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs> get_UseDlcsList()
:System.Void set_UseDlcsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs>)
```

## `app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `use_time_sec` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_UseTimeSec()
:System.Void set_Id(System.String)
:System.Void set_UseTimeSec(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs[], System.Int32)
:app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
:app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs)
```

## `app.dev1lab.AnalysisLogEventParamExtra_contents_shop`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `purchase_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData> get_PurchaseDataList()
:System.Void set_PurchaseDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData>)
```

## `app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
:app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_proceed`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `clear_type` | `System.Int64` |  | 16 |
| `costume_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData>` |  | 24 |
| `defeat_count` | `System.Int64` |  | 32 |
| `hit_rate` | `System.Int64` |  | 40 |
| `hookshot_count` | `System.Int64` |  | 48 |
| `is_plus` | `System.Int64` |  | 56 |
| `action_point` | `System.Int64` |  | 64 |
| `gameover_count` | `System.Int64` |  | 72 |
| `game_rank` | `System.String` |  | 80 |
| `clear_time` | `System.Int64` |  | 88 |
| `clear_chapter` | `System.String` |  | 96 |
| `clear_rank` | `System.String` |  | 104 |
| `save_count` | `System.Int64` |  | 112 |
| `game_id` | `System.String` |  | 120 |
| `resource_point` | `System.Int64` |  | 128 |
| `damage_count` | `System.Int64` |  | 136 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Int64 get_ActionPoint()
:System.String get_ClearChapter()
:System.String get_ClearRank()
:System.Int64 get_ClearTime()
:System.Int64 get_ClearType()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData> get_CostumeDataList()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.String get_GameId()
:System.String get_GameRank()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_HookshotCount()
:System.Int64 get_IsPlus()
:System.Int64 get_ResourcePoint()
:System.Int64 get_SaveCount()
:System.Void set_ActionPoint(System.Int64)
:System.Void set_ClearChapter(System.String)
:System.Void set_ClearRank(System.String)
:System.Void set_ClearTime(System.Int64)
:System.Void set_ClearType(System.Int64)
:System.Void set_CostumeDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData>)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameId(System.String)
:System.Void set_GameRank(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_HookshotCount(System.Int64)
:System.Void set_IsPlus(System.Int64)
:System.Void set_ResourcePoint(System.Int64)
:System.Void set_SaveCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `type` | `System.String` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.String get_Type()
:System.Void set_Id(System.String)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
:app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `counter_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CounterData>` |  | 16 |
| `map_id` | `System.String` |  | 24 |
| `tresure_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.TresureData>` |  | 32 |
| `acquired_ptas` | `System.Int64` |  | 40 |
| `game_rank` | `System.String` |  | 48 |
| `gameover_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData>` |  | 56 |
| `merchant_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData>` |  | 64 |
| `coin_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CoinData>` |  | 72 |
| `hookshot_move_count` | `System.Int64` |  | 80 |
| `progress_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData>` |  | 88 |
| `extra_chapter` | `System.String` |  | 96 |
| `reinforce_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData>` |  | 104 |
| `file_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.FileData>` |  | 112 |
| `hookshot_attack_count` | `System.Int64` |  | 120 |
| `animal_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData>` |  | 128 |
| `ptas_amount` | `System.Int64` |  | 136 |
| `game_id` | `System.String` |  | 144 |
| `case_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CaseData>` |  | 152 |
| `is_plus` | `System.Int64` |  | 160 |
| `save_count` | `System.Int64` |  | 168 |
| `photo_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData>` |  | 176 |
| `hookshot_move_distance` | `System.Int64` |  | 184 |
| `craft_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems>` |  | 192 |
| `boss_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData>` |  | 200 |
| `use_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.UseItems>` |  | 208 |
| `battle_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BattleData>` |  | 216 |
| `hookshot_shield_count` | `System.Int64` |  | 224 |
| `doll_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.DollData>` |  | 232 |
| `mission_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MissionData>` |  | 240 |
| `attached_parts_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData>` |  | 248 |
| `action_point` | `System.Int64` |  | 256 |
| `resource_point` | `System.Int64` |  | 264 |
| `attack_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttackData>` |  | 272 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Int64 get_AcquiredPtas()
:System.Int64 get_ActionPoint()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData> get_AnimalDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData> get_AttachedPartsDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttackData> get_AttackDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BattleData> get_BattleDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData> get_BossClearDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CaseData> get_CaseDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CoinData> get_CoinDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CounterData> get_CounterDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems> get_CraftItemsList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.DollData> get_DollDataList()
:System.String get_ExtraChapter()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.FileData> get_FileDataList()
:System.String get_GameId()
:System.String get_GameRank()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData> get_GameoverDataList()
:System.Int64 get_HookshotAttackCount()
:System.Int64 get_HookshotMoveCount()
:System.Int64 get_HookshotMoveDistance()
:System.Int64 get_HookshotShieldCount()
:System.Int64 get_IsPlus()
:System.String get_MapId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData> get_MerchantDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MissionData> get_MissionDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData> get_PhotoDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData> get_ProgressDataList()
:System.Int64 get_PtasAmount()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData> get_ReinforceDataList()
:System.Int64 get_ResourcePoint()
:System.Int64 get_SaveCount()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.TresureData> get_TresureDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.UseItems> get_UseItemsList()
:System.Void set_AcquiredPtas(System.Int64)
:System.Void set_ActionPoint(System.Int64)
:System.Void set_AnimalDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData>)
:System.Void set_AttachedPartsDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData>)
:System.Void set_AttackDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttackData>)
:System.Void set_BattleDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BattleData>)
:System.Void set_BossClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData>)
:System.Void set_CaseDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CaseData>)
:System.Void set_CoinDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CoinData>)
:System.Void set_CounterDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CounterData>)
:System.Void set_CraftItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems>)
:System.Void set_DollDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.DollData>)
:System.Void set_ExtraChapter(System.String)
:System.Void set_FileDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.FileData>)
:System.Void set_GameId(System.String)
:System.Void set_GameRank(System.String)
:System.Void set_GameoverDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData>)
:System.Void set_HookshotAttackCount(System.Int64)
:System.Void set_HookshotMoveCount(System.Int64)
:System.Void set_HookshotMoveDistance(System.Int64)
:System.Void set_HookshotShieldCount(System.Int64)
:System.Void set_IsPlus(System.Int64)
:System.Void set_MapId(System.String)
:System.Void set_MerchantDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData>)
:System.Void set_MissionDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MissionData>)
:System.Void set_PhotoDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData>)
:System.Void set_ProgressDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData>)
:System.Void set_PtasAmount(System.Int64)
:System.Void set_ReinforceDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData>)
:System.Void set_ResourcePoint(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_TresureDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.TresureData>)
:System.Void set_UseItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.UseItems>)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `counter_count` | `System.Int64` |  | 24 |
| `count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.Int64 get_CounterCount()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_CounterCount(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `is_attached` | `System.Int64` |  | 24 |
| `parts_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_IsAttached()
:System.String get_PartsId()
:System.String get_WeaponId()
:System.Void set_IsAttached(System.Int64)
:System.Void set_PartsId(System.String)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AttackData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `success_count` | `System.Int64` |  | 24 |
| `time` | `System.Int64` |  | 32 |
| `attack_count` | `System.Int64` |  | 40 |

**Methods**

```lua
:System.Int64 get_AttackCount()
:System.String get_Id()
:System.Int64 get_SuccessCount()
:System.Int64 get_Time()
:System.Void set_AttackCount(System.Int64)
:System.Void set_Id(System.String)
:System.Void set_SuccessCount(System.Int64)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.AttackData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttackData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.AttackData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttackData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttackData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
:app.dev1lab.AnalysisLogEventParamExtra_record.AttackData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.AttackData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.BattleData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `enemy_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_DefeatCount()
:System.String get_EnemyId()
:System.String get_WeaponId()
:System.Void set_DefeatCount(System.Int64)
:System.Void set_EnemyId(System.String)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.BattleData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:app.dev1lab.AnalysisLogEventParamExtra_record.BattleData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.BattleData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.BattleData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.BattleData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
:app.dev1lab.AnalysisLogEventParamExtra_record.BattleData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BattleData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `enemy_id` | `System.String` |  | 16 |
| `time` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_EnemyId()
:System.Int64 get_Time()
:System.Void set_EnemyId(System.String)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
:app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CaseData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `count` | `System.Int64` |  | 16 |
| `item_id` | `System.String` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_ItemId()
:System.Void set_Count(System.Int64)
:System.Void set_ItemId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CaseData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CaseData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.CaseData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.CaseData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.CaseData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CaseData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CaseData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CoinData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_destroy` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsDestroy()
:System.Void set_Id(System.String)
:System.Void set_IsDestroy(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CoinData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CoinData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.CoinData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.CoinData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.CoinData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CoinData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CoinData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CounterData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `enemy_id` | `System.String` |  | 16 |
| `type` | `System.String` |  | 24 |
| `count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_EnemyId()
:System.String get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_EnemyId(System.String)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CounterData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CounterData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.CounterData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.CounterData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.CounterData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
:app.dev1lab.AnalysisLogEventParamExtra_record.CounterData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CounterData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
:app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.DollData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_destroyed` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsDestroyed()
:System.Void set_Id(System.String)
:System.Void set_IsDestroyed(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.DollData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:app.dev1lab.AnalysisLogEventParamExtra_record.DollData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.DollData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.DollData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.DollData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
:app.dev1lab.AnalysisLogEventParamExtra_record.DollData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.DollData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.FileData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.FileData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:app.dev1lab.AnalysisLogEventParamExtra_record.FileData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.FileData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.FileData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.FileData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
:app.dev1lab.AnalysisLogEventParamExtra_record.FileData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.FileData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `gameover_map` | `System.String` |  | 16 |
| `enemy_id` | `System.String` |  | 24 |
| `death_id` | `System.String` |  | 32 |
| `gameover_count` | `System.Int64` |  | 40 |

**Methods**

```lua
:System.String get_DeathId()
:System.String get_EnemyId()
:System.Int64 get_GameoverCount()
:System.String get_GameoverMap()
:System.Void set_DeathId(System.String)
:System.Void set_EnemyId(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_GameoverMap(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
:app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `spinel_count` | `System.Int64` |  | 16 |
| `ptas_amount` | `System.Int64` |  | 24 |
| `id` | `System.String` |  | 32 |
| `count` | `System.Int64` |  | 40 |
| `type` | `System.Int64` |  | 48 |
| `tresure_set` | `System.String` |  | 56 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Int64 get_PtasAmount()
:System.Int64 get_SpinelCount()
:System.String get_TresureSet()
:System.Int64 get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
:System.Void set_PtasAmount(System.Int64)
:System.Void set_SpinelCount(System.Int64)
:System.Void set_TresureSet(System.String)
:System.Void set_Type(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.MissionData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `is_clear` | `System.Int64` |  | 16 |
| `id` | `System.String` |  | 24 |
| `spinel_count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsClear()
:System.Int64 get_SpinelCount()
:System.Void set_Id(System.String)
:System.Void set_IsClear(System.Int64)
:System.Void set_SpinelCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.MissionData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MissionData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.MissionData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.MissionData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.MissionData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MissionData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.MissionData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `time` | `System.Int64` |  | 16 |
| `count` | `System.Int64` |  | 24 |
| `map_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_MapId()
:System.Int64 get_Time()
:System.Void set_Count(System.Int64)
:System.Void set_MapId(System.String)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
:app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `type` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_Type()
:System.Void set_Id(System.String)
:System.Void set_Type(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
:app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `enhance_id` | `System.String` |  | 24 |
| `status` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.String get_EnhanceId()
:System.Int64 get_Status()
:System.String get_WeaponId()
:System.Void set_EnhanceId(System.String)
:System.Void set_Status(System.Int64)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
:app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.TresureData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.TresureData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:app.dev1lab.AnalysisLogEventParamExtra_record.TresureData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.TresureData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.TresureData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.TresureData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
:app.dev1lab.AnalysisLogEventParamExtra_record.TresureData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.TresureData)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.UseItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamExtra_record.UseItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:app.dev1lab.AnalysisLogEventParamExtra_record.UseItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamExtra_record.UseItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamExtra_record.UseItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamExtra_record.UseItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
:app.dev1lab.AnalysisLogEventParamExtra_record.UseItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamExtra_record.UseItems)
```

## `app.dev1lab.AnalysisLogEventParamGacha`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `get_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.GetItems>` |  | 16 |
| `place_id` | `System.String` |  | 24 |
| `slot_no` | `System.String` |  | 32 |
| `use_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.UseItems>` |  | 40 |
| `game_id` | `System.String` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.String get_GameId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.GetItems> get_GetItemsList()
:System.String get_PlaceId()
:System.String get_SlotNo()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.UseItems> get_UseItemsList()
:System.Void set_GameId(System.String)
:System.Void set_GetItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.GetItems>)
:System.Void set_PlaceId(System.String)
:System.Void set_SlotNo(System.String)
:System.Void set_UseItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.UseItems>)
```

## `app.dev1lab.AnalysisLogEventParamGacha.GetItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamGacha.GetItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:app.dev1lab.AnalysisLogEventParamGacha.GetItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamGacha.GetItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamGacha.GetItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamGacha.GetItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.GetItems)
:app.dev1lab.AnalysisLogEventParamGacha.GetItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.GetItems)
```

## `app.dev1lab.AnalysisLogEventParamGacha.UseItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamGacha.UseItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:app.dev1lab.AnalysisLogEventParamGacha.UseItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamGacha.UseItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamGacha.UseItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamGacha.UseItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.UseItems)
:app.dev1lab.AnalysisLogEventParamGacha.UseItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamGacha.UseItems)
```

## `app.dev1lab.AnalysisLogEventParamInitial_setting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `settings` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamInitial_setting.Settings>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamInitial_setting.Settings> get_SettingsList()
:System.Void set_SettingsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamInitial_setting.Settings>)
```

## `app.dev1lab.AnalysisLogEventParamInitial_setting.Settings`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `set_value` | `System.String` |  | 16 |
| `set_name` | `System.String` |  | 24 |

**Methods**

```lua
:System.String get_SetName()
:System.String get_SetValue()
:System.Void set_SetName(System.String)
:System.Void set_SetValue(System.String)
```

## `app.dev1lab.AnalysisLogEventParamInitial_setting.Settings[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:app.dev1lab.AnalysisLogEventParamInitial_setting.Settings Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamInitial_setting.Settings[], System.Int32)
:app.dev1lab.AnalysisLogEventParamInitial_setting.Settings Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamInitial_setting.Settings> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
:app.dev1lab.AnalysisLogEventParamInitial_setting.Settings get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamInitial_setting.Settings)
```

## `app.dev1lab.AnalysisLogEventParamMain_proceed`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `clear_type` | `System.Int64` |  | 16 |
| `costume_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData>` |  | 24 |
| `defeat_count` | `System.Int64` |  | 32 |
| `hit_rate` | `System.Int64` |  | 40 |
| `is_plus` | `System.Int64` |  | 48 |
| `action_point` | `System.Int64` |  | 56 |
| `gameover_count` | `System.Int64` |  | 64 |
| `game_rank` | `System.String` |  | 72 |
| `clear_time` | `System.Int64` |  | 80 |
| `clear_chapter` | `System.String` |  | 88 |
| `clear_rank` | `System.String` |  | 96 |
| `save_count` | `System.Int64` |  | 104 |
| `slot_no` | `System.String` |  | 112 |
| `game_id` | `System.String` |  | 120 |
| `resource_point` | `System.Int64` |  | 128 |
| `damage_count` | `System.Int64` |  | 136 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Int64 get_ActionPoint()
:System.String get_ClearChapter()
:System.String get_ClearRank()
:System.Int64 get_ClearTime()
:System.Int64 get_ClearType()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData> get_CostumeDataList()
:System.Int64 get_DamageCount()
:System.Int64 get_DefeatCount()
:System.String get_GameId()
:System.String get_GameRank()
:System.Int64 get_GameoverCount()
:System.Int64 get_HitRate()
:System.Int64 get_IsPlus()
:System.Int64 get_ResourcePoint()
:System.Int64 get_SaveCount()
:System.String get_SlotNo()
:System.Void set_ActionPoint(System.Int64)
:System.Void set_ClearChapter(System.String)
:System.Void set_ClearRank(System.String)
:System.Void set_ClearTime(System.Int64)
:System.Void set_ClearType(System.Int64)
:System.Void set_CostumeDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData>)
:System.Void set_DamageCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_GameId(System.String)
:System.Void set_GameRank(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_HitRate(System.Int64)
:System.Void set_IsPlus(System.Int64)
:System.Void set_ResourcePoint(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_SlotNo(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `type` | `System.String` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.String get_Type()
:System.Void set_Id(System.String)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
:app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `counter_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CounterData>` |  | 16 |
| `map_id` | `System.String` |  | 24 |
| `spent_time_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData>` |  | 32 |
| `tresure_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.TresureData>` |  | 40 |
| `acquired_ptas` | `System.Int64` |  | 48 |
| `game_rank` | `System.String` |  | 56 |
| `gameover_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.GameoverData>` |  | 64 |
| `merchant_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MerchantData>` |  | 72 |
| `coin_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CoinData>` |  | 80 |
| `progress_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ProgressData>` |  | 88 |
| `puzzle_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData>` |  | 96 |
| `reinforce_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData>` |  | 104 |
| `file_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.FileData>` |  | 112 |
| `animal_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AnimalData>` |  | 120 |
| `ptas_amount` | `System.Int64` |  | 128 |
| `game_id` | `System.String` |  | 136 |
| `case_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CaseData>` |  | 144 |
| `is_plus` | `System.Int64` |  | 152 |
| `save_count` | `System.Int64` |  | 160 |
| `photo_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PhotoData>` |  | 168 |
| `craft_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CraftItems>` |  | 176 |
| `boss_clear_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BossClearData>` |  | 184 |
| `use_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.UseItems>` |  | 192 |
| `battle_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BattleData>` |  | 200 |
| `play_id` | `System.String` |  | 208 |
| `slot_no` | `System.String` |  | 216 |
| `doll_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.DollData>` |  | 224 |
| `mission_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MissionData>` |  | 232 |
| `attached_parts_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData>` |  | 240 |
| `action_point` | `System.Int64` |  | 248 |
| `resource_point` | `System.Int64` |  | 256 |
| `attack_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttackData>` |  | 264 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Int64 get_AcquiredPtas()
:System.Int64 get_ActionPoint()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AnimalData> get_AnimalDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData> get_AttachedPartsDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttackData> get_AttackDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BattleData> get_BattleDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BossClearData> get_BossClearDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CaseData> get_CaseDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CoinData> get_CoinDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CounterData> get_CounterDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CraftItems> get_CraftItemsList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.DollData> get_DollDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.FileData> get_FileDataList()
:System.String get_GameId()
:System.String get_GameRank()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.GameoverData> get_GameoverDataList()
:System.Int64 get_IsPlus()
:System.String get_MapId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MerchantData> get_MerchantDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MissionData> get_MissionDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PhotoData> get_PhotoDataList()
:System.String get_PlayId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ProgressData> get_ProgressDataList()
:System.Int64 get_PtasAmount()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData> get_PuzzleDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData> get_ReinforceDataList()
:System.Int64 get_ResourcePoint()
:System.Int64 get_SaveCount()
:System.String get_SlotNo()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData> get_SpentTimeDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.TresureData> get_TresureDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.UseItems> get_UseItemsList()
:System.Void set_AcquiredPtas(System.Int64)
:System.Void set_ActionPoint(System.Int64)
:System.Void set_AnimalDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AnimalData>)
:System.Void set_AttachedPartsDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData>)
:System.Void set_AttackDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttackData>)
:System.Void set_BattleDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BattleData>)
:System.Void set_BossClearDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BossClearData>)
:System.Void set_CaseDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CaseData>)
:System.Void set_CoinDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CoinData>)
:System.Void set_CounterDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CounterData>)
:System.Void set_CraftItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CraftItems>)
:System.Void set_DollDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.DollData>)
:System.Void set_FileDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.FileData>)
:System.Void set_GameId(System.String)
:System.Void set_GameRank(System.String)
:System.Void set_GameoverDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.GameoverData>)
:System.Void set_IsPlus(System.Int64)
:System.Void set_MapId(System.String)
:System.Void set_MerchantDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MerchantData>)
:System.Void set_MissionDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MissionData>)
:System.Void set_PhotoDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PhotoData>)
:System.Void set_PlayId(System.String)
:System.Void set_ProgressDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ProgressData>)
:System.Void set_PtasAmount(System.Int64)
:System.Void set_PuzzleDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData>)
:System.Void set_ReinforceDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData>)
:System.Void set_ResourcePoint(System.Int64)
:System.Void set_SaveCount(System.Int64)
:System.Void set_SlotNo(System.String)
:System.Void set_SpentTimeDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData>)
:System.Void set_TresureDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.TresureData>)
:System.Void set_UseItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.UseItems>)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AnimalData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `counter_count` | `System.Int64` |  | 24 |
| `count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.Int64 get_CounterCount()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_CounterCount(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AnimalData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:app.dev1lab.AnalysisLogEventParamMain_record.AnimalData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.AnimalData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.AnimalData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.AnimalData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
:app.dev1lab.AnalysisLogEventParamMain_record.AnimalData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AnimalData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `is_attached` | `System.Int64` |  | 24 |
| `parts_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_IsAttached()
:System.String get_PartsId()
:System.String get_WeaponId()
:System.Void set_IsAttached(System.Int64)
:System.Void set_PartsId(System.String)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
:app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AttackData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `success_count` | `System.Int64` |  | 24 |
| `time` | `System.Int64` |  | 32 |
| `attack_count` | `System.Int64` |  | 40 |

**Methods**

```lua
:System.Int64 get_AttackCount()
:System.String get_Id()
:System.Int64 get_SuccessCount()
:System.Int64 get_Time()
:System.Void set_AttackCount(System.Int64)
:System.Void set_Id(System.String)
:System.Void set_SuccessCount(System.Int64)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.AttackData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:app.dev1lab.AnalysisLogEventParamMain_record.AttackData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.AttackData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.AttackData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.AttackData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
:app.dev1lab.AnalysisLogEventParamMain_record.AttackData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.AttackData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.BattleData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `enemy_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_DefeatCount()
:System.String get_EnemyId()
:System.String get_WeaponId()
:System.Void set_DefeatCount(System.Int64)
:System.Void set_EnemyId(System.String)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.BattleData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:app.dev1lab.AnalysisLogEventParamMain_record.BattleData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.BattleData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.BattleData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.BattleData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
:app.dev1lab.AnalysisLogEventParamMain_record.BattleData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BattleData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.BossClearData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `enemy_id` | `System.String` |  | 16 |
| `time` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_EnemyId()
:System.Int64 get_Time()
:System.Void set_EnemyId(System.String)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.BossClearData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:app.dev1lab.AnalysisLogEventParamMain_record.BossClearData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.BossClearData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.BossClearData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.BossClearData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
:app.dev1lab.AnalysisLogEventParamMain_record.BossClearData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.BossClearData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CaseData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `count` | `System.Int64` |  | 16 |
| `item_id` | `System.String` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_ItemId()
:System.Void set_Count(System.Int64)
:System.Void set_ItemId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CaseData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:app.dev1lab.AnalysisLogEventParamMain_record.CaseData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.CaseData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.CaseData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.CaseData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
:app.dev1lab.AnalysisLogEventParamMain_record.CaseData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CaseData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CoinData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_destroy` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsDestroy()
:System.Void set_Id(System.String)
:System.Void set_IsDestroy(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CoinData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:app.dev1lab.AnalysisLogEventParamMain_record.CoinData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.CoinData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.CoinData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.CoinData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
:app.dev1lab.AnalysisLogEventParamMain_record.CoinData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CoinData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CounterData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `enemy_id` | `System.String` |  | 16 |
| `type` | `System.String` |  | 24 |
| `count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_EnemyId()
:System.String get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_EnemyId(System.String)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CounterData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:app.dev1lab.AnalysisLogEventParamMain_record.CounterData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.CounterData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.CounterData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.CounterData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
:app.dev1lab.AnalysisLogEventParamMain_record.CounterData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CounterData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CraftItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.CraftItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:app.dev1lab.AnalysisLogEventParamMain_record.CraftItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.CraftItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.CraftItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.CraftItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
:app.dev1lab.AnalysisLogEventParamMain_record.CraftItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.CraftItems)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.DollData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_destroyed` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsDestroyed()
:System.Void set_Id(System.String)
:System.Void set_IsDestroyed(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.DollData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:app.dev1lab.AnalysisLogEventParamMain_record.DollData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.DollData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.DollData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.DollData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.DollData)
:app.dev1lab.AnalysisLogEventParamMain_record.DollData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.DollData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.FileData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.FileData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:app.dev1lab.AnalysisLogEventParamMain_record.FileData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.FileData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.FileData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.FileData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:app.dev1lab.AnalysisLogEventParamMain_record.FileData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.FileData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.GameoverData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `gameover_map` | `System.String` |  | 16 |
| `character_id` | `System.String` |  | 24 |
| `gameover_count` | `System.Int64` |  | 32 |
| `death_id` | `System.String` |  | 40 |
| `enemy_id` | `System.String` |  | 48 |

**Methods**

```lua
:System.String get_CharacterId()
:System.String get_DeathId()
:System.String get_EnemyId()
:System.Int64 get_GameoverCount()
:System.String get_GameoverMap()
:System.Void set_CharacterId(System.String)
:System.Void set_DeathId(System.String)
:System.Void set_EnemyId(System.String)
:System.Void set_GameoverCount(System.Int64)
:System.Void set_GameoverMap(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.GameoverData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:app.dev1lab.AnalysisLogEventParamMain_record.GameoverData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.GameoverData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.GameoverData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:app.dev1lab.AnalysisLogEventParamMain_record.GameoverData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.MerchantData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `spinel_count` | `System.Int64` |  | 16 |
| `ptas_amount` | `System.Int64` |  | 24 |
| `id` | `System.String` |  | 32 |
| `count` | `System.Int64` |  | 40 |
| `type` | `System.Int64` |  | 48 |
| `tresure_set` | `System.String` |  | 56 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Int64 get_PtasAmount()
:System.Int64 get_SpinelCount()
:System.String get_TresureSet()
:System.Int64 get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
:System.Void set_PtasAmount(System.Int64)
:System.Void set_SpinelCount(System.Int64)
:System.Void set_TresureSet(System.String)
:System.Void set_Type(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.MerchantData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:app.dev1lab.AnalysisLogEventParamMain_record.MerchantData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.MerchantData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.MerchantData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:app.dev1lab.AnalysisLogEventParamMain_record.MerchantData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.MissionData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `is_clear` | `System.Int64` |  | 16 |
| `id` | `System.String` |  | 24 |
| `spinel_count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsClear()
:System.Int64 get_SpinelCount()
:System.Void set_Id(System.String)
:System.Void set_IsClear(System.Int64)
:System.Void set_SpinelCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.MissionData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:app.dev1lab.AnalysisLogEventParamMain_record.MissionData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.MissionData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.MissionData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.MissionData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:app.dev1lab.AnalysisLogEventParamMain_record.MissionData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.PhotoData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `time` | `System.Int64` |  | 16 |
| `count` | `System.Int64` |  | 24 |
| `map_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_MapId()
:System.Int64 get_Time()
:System.Void set_Count(System.Int64)
:System.Void set_MapId(System.String)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.PhotoData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:app.dev1lab.AnalysisLogEventParamMain_record.PhotoData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.PhotoData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.PhotoData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.PhotoData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
:app.dev1lab.AnalysisLogEventParamMain_record.PhotoData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PhotoData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.ProgressData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `type` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_Type()
:System.Void set_Id(System.String)
:System.Void set_Type(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.ProgressData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:app.dev1lab.AnalysisLogEventParamMain_record.ProgressData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.ProgressData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.ProgressData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.ProgressData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
:app.dev1lab.AnalysisLogEventParamMain_record.ProgressData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ProgressData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `is_success` | `System.Int64` |  | 16 |
| `id` | `System.String` |  | 24 |
| `time` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsSuccess()
:System.Int64 get_Time()
:System.Void set_Id(System.String)
:System.Void set_IsSuccess(System.Int64)
:System.Void set_Time(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
:app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `enhance_id` | `System.String` |  | 24 |
| `status` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.String get_EnhanceId()
:System.Int64 get_Status()
:System.String get_WeaponId()
:System.Void set_EnhanceId(System.String)
:System.Void set_Status(System.Int64)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
:app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `type` | `System.String` |  | 16 |
| `time` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Time()
:System.String get_Type()
:System.Void set_Time(System.Int64)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
:app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.TresureData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.TresureData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:app.dev1lab.AnalysisLogEventParamMain_record.TresureData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.TresureData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.TresureData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.TresureData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
:app.dev1lab.AnalysisLogEventParamMain_record.TresureData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.TresureData)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.UseItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMain_record.UseItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:app.dev1lab.AnalysisLogEventParamMain_record.UseItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMain_record.UseItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMain_record.UseItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMain_record.UseItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
:app.dev1lab.AnalysisLogEventParamMain_record.UseItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMain_record.UseItems)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `score` | `System.Int64` |  | 16 |
| `get_items` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems>` |  | 24 |
| `costume_id` | `System.String` |  | 32 |
| `battle_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData>` |  | 40 |
| `stage_id` | `System.String` |  | 48 |
| `character_id` | `System.String` |  | 56 |
| `end_type` | `System.String` |  | 64 |
| `rank` | `System.String` |  | 72 |
| `survival_time` | `System.Int64` |  | 80 |
| `max_combo` | `System.Int64` |  | 88 |
| `total_defeat_count` | `System.Int64` |  | 96 |
| `game_id` | `System.String` |  | 104 |
| `weapon_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData>` |  | 112 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData> get_BattleDataList()
:System.String get_CharacterId()
:System.String get_CostumeId()
:System.String get_EndType()
:System.String get_GameId()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems> get_GetItemsList()
:System.Int64 get_MaxCombo()
:System.String get_Rank()
:System.Int64 get_Score()
:System.String get_StageId()
:System.Int64 get_SurvivalTime()
:System.Int64 get_TotalDefeatCount()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData> get_WeaponDataList()
:System.Void set_BattleDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData>)
:System.Void set_CharacterId(System.String)
:System.Void set_CostumeId(System.String)
:System.Void set_EndType(System.String)
:System.Void set_GameId(System.String)
:System.Void set_GetItemsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems>)
:System.Void set_MaxCombo(System.Int64)
:System.Void set_Rank(System.String)
:System.Void set_Score(System.Int64)
:System.Void set_StageId(System.String)
:System.Void set_SurvivalTime(System.Int64)
:System.Void set_TotalDefeatCount(System.Int64)
:System.Void set_WeaponDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData>)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `weapon_id` | `System.String` |  | 16 |
| `defeat_count` | `System.Int64` |  | 24 |
| `enemy_id` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_DefeatCount()
:System.String get_EnemyId()
:System.String get_WeaponId()
:System.Void set_DefeatCount(System.Int64)
:System.Void set_EnemyId(System.String)
:System.Void set_WeaponId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `shot_count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_ShotCount()
:System.Void set_Id(System.String)
:System.Void set_ShotCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
:app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData)
```

## `app.dev1lab.AnalysisLogEventParamMercenaries_start`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `game_id` | `System.String` |  | 16 |
| `costume_id` | `System.String` |  | 24 |
| `stage_id` | `System.String` |  | 32 |
| `character_id` | `System.String` |  | 40 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_CharacterId()
:System.String get_CostumeId()
:System.String get_GameId()
:System.String get_StageId()
:System.Void set_CharacterId(System.String)
:System.Void set_CostumeId(System.String)
:System.Void set_GameId(System.String)
:System.Void set_StageId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamOption`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `options` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOption.Options>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOption.Options> get_OptionsList()
:System.Void set_OptionsList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOption.Options>)
```

## `app.dev1lab.AnalysisLogEventParamOption.Options`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `opt_value` | `System.String` |  | 16 |
| `is_default` | `System.Int64` |  | 24 |
| `opt_name` | `System.String` |  | 32 |

**Methods**

```lua
:System.Int64 get_IsDefault()
:System.String get_OptName()
:System.String get_OptValue()
:System.Void set_IsDefault(System.Int64)
:System.Void set_OptName(System.String)
:System.Void set_OptValue(System.String)
```

## `app.dev1lab.AnalysisLogEventParamOption.Options[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOption.Options)
:app.dev1lab.AnalysisLogEventParamOption.Options Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOption.Options)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOption.Options[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOption.Options Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOption.Options> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOption.Options)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOption.Options)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOption.Options)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOption.Options)
:app.dev1lab.AnalysisLogEventParamOption.Options get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOption.Options)
```

## `app.dev1lab.AnalysisLogEventParamOther`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `men_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.MenData>` |  | 16 |
| `egg_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.EggData>` |  | 24 |
| `destroy_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.DestroyData>` |  | 32 |
| `snake_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.SnakeData>` |  | 40 |
| `women_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.WomenData>` |  | 48 |
| `elavator_data` | `System.String` |  | 56 |
| `broken_knife_count` | `System.Int64` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Int64 get_BrokenKnifeCount()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.DestroyData> get_DestroyDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.EggData> get_EggDataList()
:System.String get_ElavatorData()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.MenData> get_MenDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.SnakeData> get_SnakeDataList()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.WomenData> get_WomenDataList()
:System.Void set_BrokenKnifeCount(System.Int64)
:System.Void set_DestroyDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.DestroyData>)
:System.Void set_EggDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.EggData>)
:System.Void set_ElavatorData(System.String)
:System.Void set_MenDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.MenData>)
:System.Void set_SnakeDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.SnakeData>)
:System.Void set_WomenDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.WomenData>)
```

## `app.dev1lab.AnalysisLogEventParamOther.DestroyData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Id()
:System.Void set_Count(System.Int64)
:System.Void set_Id(System.String)
```

## `app.dev1lab.AnalysisLogEventParamOther.DestroyData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:app.dev1lab.AnalysisLogEventParamOther.DestroyData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOther.DestroyData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOther.DestroyData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOther.DestroyData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOther.DestroyData)
:app.dev1lab.AnalysisLogEventParamOther.DestroyData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOther.DestroyData)
```

## `app.dev1lab.AnalysisLogEventParamOther.EggData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `type` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamOther.EggData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOther.EggData)
:app.dev1lab.AnalysisLogEventParamOther.EggData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOther.EggData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOther.EggData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOther.EggData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOther.EggData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOther.EggData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOther.EggData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOther.EggData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOther.EggData)
:app.dev1lab.AnalysisLogEventParamOther.EggData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOther.EggData)
```

## `app.dev1lab.AnalysisLogEventParamOther.MenData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `defeat_count` | `System.Int64` |  | 16 |
| `leon_missshot_count` | `System.Int64` |  | 24 |
| `attacked_count` | `System.Int64` |  | 32 |

**Methods**

```lua
:System.Int64 get_AttackedCount()
:System.Int64 get_DefeatCount()
:System.Int64 get_LeonMissshotCount()
:System.Void set_AttackedCount(System.Int64)
:System.Void set_DefeatCount(System.Int64)
:System.Void set_LeonMissshotCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamOther.MenData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOther.MenData)
:app.dev1lab.AnalysisLogEventParamOther.MenData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOther.MenData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOther.MenData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOther.MenData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOther.MenData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOther.MenData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOther.MenData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOther.MenData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOther.MenData)
:app.dev1lab.AnalysisLogEventParamOther.MenData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOther.MenData)
```

## `app.dev1lab.AnalysisLogEventParamOther.SnakeData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `type` | `System.String` |  | 16 |
| `count` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.Int64 get_Count()
:System.String get_Type()
:System.Void set_Count(System.Int64)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamOther.SnakeData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:app.dev1lab.AnalysisLogEventParamOther.SnakeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOther.SnakeData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOther.SnakeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOther.SnakeData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOther.SnakeData)
:app.dev1lab.AnalysisLogEventParamOther.SnakeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOther.SnakeData)
```

## `app.dev1lab.AnalysisLogEventParamOther.WomenData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `rescue_success_count` | `System.Int64` |  | 16 |
| `rescue_failure_count` | `System.Int64` |  | 24 |
| `crane_defeat_count` | `System.Int64` |  | 32 |
| `attacked_count` | `System.Int64` |  | 40 |
| `leon_missshot_count` | `System.Int64` |  | 48 |

**Methods**

```lua
:System.Int64 get_AttackedCount()
:System.Int64 get_CraneDefeatCount()
:System.Int64 get_LeonMissshotCount()
:System.Int64 get_RescueFailureCount()
:System.Int64 get_RescueSuccessCount()
:System.Void set_AttackedCount(System.Int64)
:System.Void set_CraneDefeatCount(System.Int64)
:System.Void set_LeonMissshotCount(System.Int64)
:System.Void set_RescueFailureCount(System.Int64)
:System.Void set_RescueSuccessCount(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamOther.WomenData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamOther.WomenData)
:app.dev1lab.AnalysisLogEventParamOther.WomenData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamOther.WomenData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamOther.WomenData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamOther.WomenData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamOther.WomenData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamOther.WomenData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamOther.WomenData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamOther.WomenData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamOther.WomenData)
:app.dev1lab.AnalysisLogEventParamOther.WomenData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamOther.WomenData)
```

## `app.dev1lab.AnalysisLogEventParamRecord`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `record_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData> get_RecordDataList()
:System.Void set_RecordDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData>)
```

## `app.dev1lab.AnalysisLogEventParamRecord.RecordData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamRecord.RecordData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:app.dev1lab.AnalysisLogEventParamRecord.RecordData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamRecord.RecordData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamRecord.RecordData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamRecord.RecordData)
:app.dev1lab.AnalysisLogEventParamRecord.RecordData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamRecord.RecordData)
```

## `app.dev1lab.AnalysisLogEventParamShooting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `score` | `System.Int64` |  | 16 |
| `place_id` | `System.String` |  | 24 |
| `best_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.BestData>` |  | 32 |
| `rank` | `System.String` |  | 40 |
| `clear_time` | `System.Int64` |  | 48 |
| `hit_count` | `System.Int64` |  | 56 |
| `type` | `System.String` |  | 64 |
| `game_id` | `System.String` |  | 72 |
| `remaining_time` | `System.Int64` |  | 80 |
| `reward_item_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData>` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.BestData> get_BestDataList()
:System.Int64 get_ClearTime()
:System.String get_GameId()
:System.Int64 get_HitCount()
:System.String get_PlaceId()
:System.String get_Rank()
:System.Int64 get_RemainingTime()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData> get_RewardItemDataList()
:System.Int64 get_Score()
:System.String get_Type()
:System.Void set_BestDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.BestData>)
:System.Void set_ClearTime(System.Int64)
:System.Void set_GameId(System.String)
:System.Void set_HitCount(System.Int64)
:System.Void set_PlaceId(System.String)
:System.Void set_Rank(System.String)
:System.Void set_RemainingTime(System.Int64)
:System.Void set_RewardItemDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData>)
:System.Void set_Score(System.Int64)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamShooting.BestData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `high_score` | `System.Int64` |  | 16 |
| `high_score_savedata` | `System.Int64` |  | 24 |
| `place_id` | `System.String` |  | 32 |
| `is_clear` | `System.Int64` |  | 40 |
| `is_allcoin` | `System.Int64` |  | 48 |
| `best_rank` | `System.String` |  | 56 |
| `type` | `System.String` |  | 64 |

**Methods**

```lua
:System.String get_BestRank()
:System.Int64 get_HighScore()
:System.Int64 get_HighScoreSavedata()
:System.Int64 get_IsAllcoin()
:System.Int64 get_IsClear()
:System.String get_PlaceId()
:System.String get_Type()
:System.Void set_BestRank(System.String)
:System.Void set_HighScore(System.Int64)
:System.Void set_HighScoreSavedata(System.Int64)
:System.Void set_IsAllcoin(System.Int64)
:System.Void set_IsClear(System.Int64)
:System.Void set_PlaceId(System.String)
:System.Void set_Type(System.String)
```

## `app.dev1lab.AnalysisLogEventParamShooting.BestData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamShooting.BestData)
:app.dev1lab.AnalysisLogEventParamShooting.BestData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamShooting.BestData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamShooting.BestData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamShooting.BestData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamShooting.BestData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamShooting.BestData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.BestData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamShooting.BestData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.BestData)
:app.dev1lab.AnalysisLogEventParamShooting.BestData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.BestData)
```

## `app.dev1lab.AnalysisLogEventParamShooting.RewardItemData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamShooting.RewardItemData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:app.dev1lab.AnalysisLogEventParamShooting.RewardItemData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamShooting.RewardItemData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamShooting.RewardItemData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
:app.dev1lab.AnalysisLogEventParamShooting.RewardItemData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamShooting.RewardItemData)
```

## `app.dev1lab.AnalysisLogEventParamStore_transition`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `item_id` | `System.String` |  | 16 |
| `place` | `System.String` |  | 24 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_ItemId()
:System.String get_Place()
:System.Void set_ItemId(System.String)
:System.Void set_Place(System.String)
```

## `app.dev1lab.AnalysisLogEventParamTransfer_save_data`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `situation_id` | `System.String` |  | 16 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_SituationId()
:System.Void set_SituationId(System.String)
```

## `app.dev1lab.AnalysisLogEventParamTrophy`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `trophy_data` | `System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.String GetEventName()
:System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData> get_TrophyDataList()
:System.Void set_TrophyDataList(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData>)
```

## `app.dev1lab.AnalysisLogEventParamTrophy.TrophyData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `id` | `System.String` |  | 16 |
| `is_get` | `System.Int64` |  | 24 |

**Methods**

```lua
:System.String get_Id()
:System.Int64 get_IsGet()
:System.Void set_Id(System.String)
:System.Void set_IsGet(System.Int64)
```

## `app.dev1lab.AnalysisLogEventParamTrophy.TrophyData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:app.dev1lab.AnalysisLogEventParamTrophy.TrophyData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:System.Void CopyTo(app.dev1lab.AnalysisLogEventParamTrophy.TrophyData[], System.Int32)
:app.dev1lab.AnalysisLogEventParamTrophy.TrophyData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:System.Boolean Remove(app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
:app.dev1lab.AnalysisLogEventParamTrophy.TrophyData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogEventParamTrophy.TrophyData)
```

## `app.dev1lab.AnalysisLogManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnSetCommonParamSetting` | `System.Action`2<app.dev1lab.AnalysisLogParam,System.String>` |  | 80 |
| `_Transmitter` | `app.dev1lab.AnalysisLogTransmitter` |  | 88 |
| `_IsAllowedToSend` | `System.Boolean` |  | 96 |

**Methods**

```lua
:System.Void clearRequestQueue()
:System.Boolean get_IsAllowedToSend()
:System.Void requestActive(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraChapterBestClearData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ChapterBestClearData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.ExtraBestClearData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamActive.BestClearData>)
:System.Void requestAnalysis_accept(via.UserIndex, System.String)
:System.Void requestAnalysis_accept_cid(via.UserIndex, System.Int64)
:System.Void requestBonus_mode_play(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes>)
:System.Void requestChange_difficulty(via.UserIndex, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData>, System.Int64)
:System.Void requestDlc_get(via.UserIndex, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_get.Dlcs>, System.String)
:System.Void requestDlc_install(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_install.Dlcs>)
:System.Void requestDlc_use_time(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamDlc_use_time.UseDlcs>)
:System.Void requestExtra_contents_shop(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData>)
:System.Void requestExtra_proceed(via.UserIndex, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_proceed.CostumeData>, System.Int64, System.Int64, System.Int64, System.Int64, System.Int64, System.Int64, System.String, System.Int64, System.String, System.String, System.Int64, System.String, System.Int64, System.Int64)
:System.Void requestExtra_record(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CounterData>, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.TresureData>, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CoinData>, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ProgressData>, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.ReinforceData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.FileData>, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AnimalData>, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CaseData>, System.Int64, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.PhotoData>, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.CraftItems>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BossClearData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.UseItems>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.BattleData>, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.DollData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.MissionData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttachedPartsData>, System.Int64, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_record.AttackData>)
:System.Void requestGacha(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.GetItems>, System.String, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamGacha.UseItems>, System.String)
:System.Void requestInitial_setting(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamInitial_setting.Settings>)
:System.Void requestMain_proceed(via.UserIndex, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_proceed.CostumeData>, System.Int64, System.Int64, System.Int64, System.Int64, System.Int64, System.String, System.Int64, System.String, System.String, System.Int64, System.String, System.String, System.Int64, System.Int64)
:System.Void requestMain_record(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CounterData>, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.SpentTimeData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.TresureData>, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.GameoverData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MerchantData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CoinData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ProgressData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PuzzleData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.ReinforceData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.FileData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AnimalData>, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CaseData>, System.Int64, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.PhotoData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.CraftItems>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BossClearData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.UseItems>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.BattleData>, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.DollData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.MissionData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttachedPartsData>, System.Int64, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMain_record.AttackData>)
:System.Void requestMercenaries_end(via.UserIndex, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.GetItems>, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.BattleData>, System.String, System.String, System.String, System.String, System.Int64, System.Int64, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamMercenaries_end.WeaponData>)
:System.Void requestMercenaries_start(via.UserIndex, System.String, System.String, System.String, System.String)
:System.Void requestOption(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOption.Options>)
:System.Void requestOther(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.MenData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.EggData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.DestroyData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.SnakeData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamOther.WomenData>, System.String, System.Int64)
:System.Void requestRecord(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData>)
:System.Void requestShooting(via.UserIndex, System.Int64, System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.BestData>, System.String, System.Int64, System.Int64, System.String, System.String, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData>)
:System.Void requestStore_transition(via.UserIndex, System.String, System.String)
:System.Void requestTransfer_save_data(via.UserIndex, System.String)
:System.Void requestTrophy(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData>)
:System.Void set_IsAllowedToSend(System.Boolean)
:System.Void startup(System.Func`1<via.UserIndex>)
:System.Void startup(via.network.HttpClient, System.Func`1<via.UserIndex>)
:System.Void update()
```

## `app.dev1lab.AnalysisLogParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `unique_id` | `System.String` |  | 16 |
| `event_name` | `System.String` |  | 24 |
| `ts_micro` | `System.Int64` |  | 32 |
| `user_params` | `app.dev1lab.AnalysisLogUserParam` |  | 40 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_EventName()
:System.Int64 get_TsMicro()
:System.String get_UniqueId()
:app.dev1lab.AnalysisLogUserParam get_UserParams()
:System.Void set_EventName(System.String)
:System.Void set_TsMicro(System.Int64)
:System.Void set_UniqueId(System.String)
:System.Void set_UserParams(app.dev1lab.AnalysisLogUserParam)
```

## `app.dev1lab.AnalysisLogParamTypeBase`

_No fields or methods._

## `app.dev1lab.AnalysisLogParamType_Date`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Type>k__BackingField` | `System.String` |  | 16 |
| `<Year>k__BackingField` | `System.UInt32` |  | 24 |
| `<Month>k__BackingField` | `System.UInt32` |  | 28 |
| `<Day>k__BackingField` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.UInt32, System.UInt32, System.UInt32)
:System.String get()
:System.UInt32 get_Day()
:System.UInt32 get_Month()
:System.String get_Type()
:System.UInt32 get_Year()
:System.Boolean set(System.UInt32, System.UInt32, System.UInt32)
:System.Void set_Day(System.UInt32)
:System.Void set_Month(System.UInt32)
:System.Void set_Year(System.UInt32)
```

## `app.dev1lab.AnalysisLogParamType_DateTime`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Type>k__BackingField` | `System.String` |  | 16 |
| `<Year>k__BackingField` | `System.UInt32` |  | 24 |
| `<Month>k__BackingField` | `System.UInt32` |  | 28 |
| `<Day>k__BackingField` | `System.UInt32` |  | 32 |
| `<Hour>k__BackingField` | `System.UInt32` |  | 36 |
| `<Minute>k__BackingField` | `System.UInt32` |  | 40 |
| `<Second>k__BackingField` | `System.UInt32` |  | 44 |
| `<Millisecond>k__BackingField` | `System.UInt32` |  | 48 |

**Methods**

```lua
:System.Void .ctor(System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32)
:System.String get()
:System.UInt32 get_Day()
:System.UInt32 get_Hour()
:System.UInt32 get_Millisecond()
:System.UInt32 get_Minute()
:System.UInt32 get_Month()
:System.UInt32 get_Second()
:System.String get_Type()
:System.UInt32 get_Year()
:System.Boolean set(System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32)
:System.Void set_Day(System.UInt32)
:System.Void set_Hour(System.UInt32)
:System.Void set_Millisecond(System.UInt32)
:System.Void set_Minute(System.UInt32)
:System.Void set_Month(System.UInt32)
:System.Void set_Second(System.UInt32)
:System.Void set_Year(System.UInt32)
```

## `app.dev1lab.AnalysisLogParamType_TimeStamp`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Type>k__BackingField` | `System.String` |  | 16 |
| `<Year>k__BackingField` | `System.UInt32` |  | 24 |
| `<Month>k__BackingField` | `System.UInt32` |  | 28 |
| `<Day>k__BackingField` | `System.UInt32` |  | 32 |
| `<Hour>k__BackingField` | `System.UInt32` |  | 36 |
| `<Minute>k__BackingField` | `System.UInt32` |  | 40 |
| `<Second>k__BackingField` | `System.UInt32` |  | 44 |
| `<Millisecond>k__BackingField` | `System.UInt32` |  | 48 |
| `<Timezone>k__BackingField` | `System.String` |  | 56 |

**Methods**

```lua
:System.Void .ctor(System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.String)
:System.String get()
:System.UInt32 get_Day()
:System.UInt32 get_Hour()
:System.UInt32 get_Millisecond()
:System.UInt32 get_Minute()
:System.UInt32 get_Month()
:System.UInt32 get_Second()
:System.String get_Timezone()
:System.String get_Type()
:System.UInt32 get_Year()
:System.Boolean set(System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.UInt32, System.String)
:System.Void set_Day(System.UInt32)
:System.Void set_Hour(System.UInt32)
:System.Void set_Millisecond(System.UInt32)
:System.Void set_Minute(System.UInt32)
:System.Void set_Month(System.UInt32)
:System.Void set_Second(System.UInt32)
:System.Void set_Timezone(System.String)
:System.Void set_Year(System.UInt32)
```

## `app.dev1lab.AnalysisLogSendParamActive`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamActive` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamActive get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamActive)
```

## `app.dev1lab.AnalysisLogSendParamAnalysis_accept`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamAnalysis_accept` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamAnalysis_accept get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamAnalysis_accept)
```

## `app.dev1lab.AnalysisLogSendParamAnalysis_accept_cid`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamAnalysis_accept_cid` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamAnalysis_accept_cid get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamAnalysis_accept_cid)
```

## `app.dev1lab.AnalysisLogSendParamBase`

**Methods**

```lua
:System.Byte[] serialize()
```

## `app.dev1lab.AnalysisLogSendParamBonus_mode_play`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamBonus_mode_play` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamBonus_mode_play get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamBonus_mode_play)
```

## `app.dev1lab.AnalysisLogSendParamChange_difficulty`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamChange_difficulty` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamChange_difficulty get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamChange_difficulty)
```

## `app.dev1lab.AnalysisLogSendParamDlc_get`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamDlc_get` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamDlc_get get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamDlc_get)
```

## `app.dev1lab.AnalysisLogSendParamDlc_install`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamDlc_install` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamDlc_install get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamDlc_install)
```

## `app.dev1lab.AnalysisLogSendParamDlc_use_time`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamDlc_use_time` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamDlc_use_time get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamDlc_use_time)
```

## `app.dev1lab.AnalysisLogSendParamExtra_contents_shop`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamExtra_contents_shop` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamExtra_contents_shop get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamExtra_contents_shop)
```

## `app.dev1lab.AnalysisLogSendParamExtra_proceed`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamExtra_proceed` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamExtra_proceed get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamExtra_proceed)
```

## `app.dev1lab.AnalysisLogSendParamExtra_record`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamExtra_record` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamExtra_record get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamExtra_record)
```

## `app.dev1lab.AnalysisLogSendParamGacha`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamGacha` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamGacha get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamGacha)
```

## `app.dev1lab.AnalysisLogSendParamInitial_setting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamInitial_setting` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamInitial_setting get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamInitial_setting)
```

## `app.dev1lab.AnalysisLogSendParamMain_proceed`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamMain_proceed` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamMain_proceed get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamMain_proceed)
```

## `app.dev1lab.AnalysisLogSendParamMain_record`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamMain_record` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamMain_record get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamMain_record)
```

## `app.dev1lab.AnalysisLogSendParamMercenaries_end`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamMercenaries_end` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamMercenaries_end get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamMercenaries_end)
```

## `app.dev1lab.AnalysisLogSendParamMercenaries_start`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamMercenaries_start` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamMercenaries_start get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamMercenaries_start)
```

## `app.dev1lab.AnalysisLogSendParamOption`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamOption` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamOption get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamOption)
```

## `app.dev1lab.AnalysisLogSendParamOther`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamOther` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamOther get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamOther)
```

## `app.dev1lab.AnalysisLogSendParamRecord`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamRecord` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamRecord get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamRecord)
```

## `app.dev1lab.AnalysisLogSendParamShooting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamShooting` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamShooting get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamShooting)
```

## `app.dev1lab.AnalysisLogSendParamStore_transition`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamStore_transition` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamStore_transition get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamStore_transition)
```

## `app.dev1lab.AnalysisLogSendParamTransfer_save_data`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamTransfer_save_data` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamTransfer_save_data get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamTransfer_save_data)
```

## `app.dev1lab.AnalysisLogSendParamTrophy`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `event_params` | `app.dev1lab.AnalysisLogEventParamTrophy` |  | 48 |

**Methods**

```lua
:app.dev1lab.AnalysisLogEventParamTrophy get_EventParams()
:System.Byte[] serialize()
:System.Void set_EventParams(app.dev1lab.AnalysisLogEventParamTrophy)
```

## `app.dev1lab.AnalysisLogTransmitter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CurrentUserIndex>k__BackingField` | `System.Func`1<via.UserIndex>` |  | 16 |
| `_HttpClient` | `via.network.HttpClient` |  | 24 |
| `_CurrPhase` | `app.dev1lab.AnalysisLogTransmitter.Phase` |  | 32 |
| `_CurrHttpRequest` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest` |  | 40 |
| `_RequestContainer` | `System.Collections.Concurrent.ConcurrentQueue`1<app.dev1lab.AnalysisLogTransmitter.Request>` |  | 48 |
| `_CurrRequest` | `app.dev1lab.AnalysisLogTransmitter.Request` |  | 56 |
| `_TargetEnvironment` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` |  | 64 |
| `_LogsBuilder` | `app.dev1lab.AnalysisLogUtil.LogsBuilder` |  | 72 |
| `_BaseParam` | `via.auth_token.BaseParam` |  | 80 |
| `_LastAuthenticatedUserPair` | `app.dev1lab.AnalysisLogTransmitter.UserServicePair` |  | 88 |

**Methods**

```lua
:System.Void .ctor(via.network.HttpClient, app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:System.Boolean IsAuthProcessRequired()
:System.Boolean IsSameCurrentUser(app.dev1lab.AnalysisLogTransmitter.UserServicePair)
:System.Void clearRequestQueue()
:System.String getAudFromJWT(System.String)
:System.String getDecodedBase64url(System.String)
:System.Void getJsonElements(System.String, System.String[], System.String[])
:System.Func`1<via.UserIndex> get_CurrentUserIndex()
:app.dev1lab.AnalysisLogUtil.SupportEnvironment get_TargetEnvironment()
:System.Void onAnsRequestFail(via.network.Error)
:System.Void onAnsRequestSucceed()
:System.Void onNtcFinalize()
:System.Void onNtcReceiveData(via.network.utility.BinaryInfo)
:System.Void onNtcReceiveResponceHeader(via.network.http_client.ResponseHeader)
:System.Void onNtcRequestComplate()
:System.Void request(via.UserIndex, System.String, app.dev1lab.AnalysisLogParam)
:System.Void requestHttpClient(System.String, System.String, via.os.http_client.Method, System.String, via.network.utility.BinaryInfo)
:System.Void set_CurrentUserIndex(System.Func`1<via.UserIndex>)
:System.Void transitPhase(app.dev1lab.AnalysisLogTransmitter.Phase)
:System.Void update(app.dev1lab.AnalysisLogManager)
```

## `app.dev1lab.AnalysisLogTransmitter.HttpRequest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Succeed>k__BackingField` | `System.Boolean` |  | 16 |
| `<CurrPhase>k__BackingField` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` |  | 20 |
| `<ResponseHeader>k__BackingField` | `via.network.http_client.ResponseHeader` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
:app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase get_CurrPhase()
:via.network.http_client.ResponseHeader get_ResponseHeader()
:System.Boolean get_Succeed()
:System.Void set_CurrPhase(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:System.Void set_ResponseHeader(via.network.http_client.ResponseHeader)
:System.Void set_Succeed(System.Boolean)
:System.Void transit(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
```

## `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Complate` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `Finalize` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `None` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `ReceiveResponseBody` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `ReceiveResponseHeader` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `Request` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `RequestFaild` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `RequestSucceed` | `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:System.Void CopyTo(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase[], System.Int32)
:app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:System.Boolean Remove(app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
:app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogTransmitter.HttpRequest.Phase)
```

## `app.dev1lab.AnalysisLogTransmitter.Phase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ComplateSendLog` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `Failed` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `Initialize` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `PrepareTheLog` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `ReqSendLog` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `Wait` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `WaitRebeAuth` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `WaitSendLog` | `app.dev1lab.AnalysisLogTransmitter.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.AnalysisLogTransmitter.Phase[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogTransmitter.Phase)
:app.dev1lab.AnalysisLogTransmitter.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogTransmitter.Phase)
:System.Void CopyTo(app.dev1lab.AnalysisLogTransmitter.Phase[], System.Int32)
:app.dev1lab.AnalysisLogTransmitter.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogTransmitter.Phase> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogTransmitter.Phase)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogTransmitter.Phase)
:System.Boolean Remove(app.dev1lab.AnalysisLogTransmitter.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogTransmitter.Phase)
:app.dev1lab.AnalysisLogTransmitter.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogTransmitter.Phase)
```

## `app.dev1lab.AnalysisLogTransmitter.Request`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `UserPair` | `app.dev1lab.AnalysisLogTransmitter.UserServicePair` |  | 16 |
| `EventType` | `System.String` |  | 24 |
| `EventParam` | `app.dev1lab.AnalysisLogParam` |  | 32 |

**Methods**

```lua
:System.Void .ctor(via.UserIndex, System.String, app.dev1lab.AnalysisLogParam)
```

## `app.dev1lab.AnalysisLogTransmitter.Request[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogTransmitter.Request)
:app.dev1lab.AnalysisLogTransmitter.Request Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogTransmitter.Request)
:System.Void CopyTo(app.dev1lab.AnalysisLogTransmitter.Request[], System.Int32)
:app.dev1lab.AnalysisLogTransmitter.Request Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogTransmitter.Request> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogTransmitter.Request)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogTransmitter.Request)
:System.Boolean Remove(app.dev1lab.AnalysisLogTransmitter.Request)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogTransmitter.Request)
:app.dev1lab.AnalysisLogTransmitter.Request get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogTransmitter.Request)
```

## `app.dev1lab.AnalysisLogTransmitter.UserServicePair`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `UserIndex` | `via.UserIndex` |  | 16 |
| `NativeUserId` | `System.Int32` |  | 20 |

**Methods**

```lua
:System.Void .ctor(via.UserIndex)
:System.Boolean IsSameUserPair(app.dev1lab.AnalysisLogTransmitter.UserServicePair)
```

## `app.dev1lab.AnalysisLogUserParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `main_playtime` | `System.Int64` |  | 16 |
| `extra_playtime` | `System.Int64` |  | 24 |
| `count_new_game_plus` | `System.Int64` |  | 32 |
| `difficulty` | `System.String` |  | 40 |
| `version` | `System.String` |  | 48 |
| `is_extra_clear` | `System.Int64` |  | 56 |
| `count_new_game` | `System.Int64` |  | 64 |
| `cero` | `System.String` |  | 72 |
| `mercenaries_right` | `System.Int64` |  | 80 |
| `aud` | `System.String` |  | 88 |
| `revision` | `System.String` |  | 96 |
| `mode` | `System.String` |  | 104 |
| `ex_clear_count` | `System.Int64` |  | 112 |
| `ex_count_new_game_plus` | `System.Int64` |  | 120 |
| `playtime` | `System.Int64` |  | 128 |
| `is_debug` | `System.Int64` |  | 136 |
| `region` | `System.String` |  | 144 |
| `platform` | `System.String` |  | 152 |
| `ex_count_new_game` | `System.Int64` |  | 160 |
| `user_id` | `System.String` |  | 168 |
| `main_real_playtime` | `System.Int64` |  | 176 |
| `main_chapter` | `System.String` |  | 184 |
| `is_trial` | `System.Int64` |  | 192 |
| `clear_count` | `System.Int64` |  | 200 |
| `extra_right` | `System.Int64` |  | 208 |

**Methods**

```lua
:System.String GetEventName()
:System.String get_Aud()
:System.String get_Cero()
:System.Int64 get_ClearCount()
:System.Int64 get_CountNewGame()
:System.Int64 get_CountNewGamePlus()
:System.String get_Difficulty()
:System.Int64 get_ExClearCount()
:System.Int64 get_ExCountNewGame()
:System.Int64 get_ExCountNewGamePlus()
:System.Int64 get_ExtraPlaytime()
:System.Int64 get_ExtraRight()
:System.Int64 get_IsDebug()
:System.Int64 get_IsExtraClear()
:System.Int64 get_IsTrial()
:System.String get_MainChapter()
:System.Int64 get_MainPlaytime()
:System.Int64 get_MainRealPlaytime()
:System.Int64 get_MercenariesRight()
:System.String get_Mode()
:System.String get_Platform()
:System.Int64 get_Playtime()
:System.String get_Region()
:System.String get_Revision()
:System.String get_UserId()
:System.String get_Version()
:System.Void set_Aud(System.String)
:System.Void set_Cero(System.String)
:System.Void set_ClearCount(System.Int64)
:System.Void set_CountNewGame(System.Int64)
:System.Void set_CountNewGamePlus(System.Int64)
:System.Void set_Difficulty(System.String)
:System.Void set_ExClearCount(System.Int64)
:System.Void set_ExCountNewGame(System.Int64)
:System.Void set_ExCountNewGamePlus(System.Int64)
:System.Void set_ExtraPlaytime(System.Int64)
:System.Void set_ExtraRight(System.Int64)
:System.Void set_IsDebug(System.Int64)
:System.Void set_IsExtraClear(System.Int64)
:System.Void set_IsTrial(System.Int64)
:System.Void set_MainChapter(System.String)
:System.Void set_MainPlaytime(System.Int64)
:System.Void set_MainRealPlaytime(System.Int64)
:System.Void set_MercenariesRight(System.Int64)
:System.Void set_Mode(System.String)
:System.Void set_Platform(System.String)
:System.Void set_Playtime(System.Int64)
:System.Void set_Region(System.String)
:System.Void set_Revision(System.String)
:System.Void set_UserId(System.String)
:System.Void set_Version(System.String)
```

## `app.dev1lab.AnalysisLogUtil`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `UnixEpoch` | `System.DateTime` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "GetExecutionEnvironment", ...)  -- app.dev1lab.AnalysisLogUtil.SupportEnvironment GetExecutionEnvironment()
sdk.call_native_func(nil, type_def, "GetTimeStampMicro", ...)  -- System.Int64 GetTimeStampMicro()
sdk.call_native_func(nil, type_def, "IsSupportedExecutionEnvironment", ...)  -- System.Boolean IsSupportedExecutionEnvironment(app.dev1lab.AnalysisLogUtil.SupportEnvironment)
sdk.call_native_func(nil, type_def, "makeId", ...)  -- System.Byte[] makeId(System.UInt64)
```

## `app.dev1lab.AnalysisLogUtil.LogsBuilder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Header` | `System.Byte[]` | yes | 16 |
| `_buffer` | `System.Byte[]` |  | 16 |
| `_index` | `System.Int32` |  | 24 |
| `_count` | `System.UInt16` |  | 28 |
| `_binaryInfo` | `via.network.utility.BinaryInfo` |  | 32 |
| `_encoder` | `app.dev1lab.AnalysisLogUtil.LogsBuilder.Base64Encoder` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
:System.Boolean Append(app.dev1lab.AnalysisLogParam)
:System.Boolean Build()
:System.String CreateUuid()
:System.UInt16 GetCount()
:System.String GetFooter()
:System.String GetHeader()
:via.network.utility.BinaryInfo GetResult()
:System.Void Reset()
:System.Void ToMsgPack()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.dev1lab.AnalysisLogUtil.LogsBuilder.Base64Encoder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultEncodeByteSize` | `System.Int32` | yes | 16 |
| `<_encodeByteSize>k__BackingField` | `System.Int32` |  | 16 |
| `_encodeSource` | `System.Byte[]` |  | 24 |
| `_encodeWorkBuffer` | `System.Byte[]` |  | 32 |
| `_EncodeSourceLength` | `System.Int32` |  | 40 |
| `_currentIdx` | `System.Int32` |  | 44 |

**Methods**

```lua
:System.Void .ctor(System.Byte[], System.Int32, System.Int32)
:System.Int32 get__encodeByteSize()
:System.Boolean isEnd()
:System.Void set__encodeByteSize(System.Int32)
:System.Boolean updateEncode(via.network.utility.BinaryInfo)
```

## `app.dev1lab.AnalysisLogUtil.SupportEnvironment`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Invalid` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `MSG` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `PS4` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `PS5` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `Steam` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `XBS` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `XboxOne` | `app.dev1lab.AnalysisLogUtil.SupportEnvironment` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.AnalysisLogUtil.SupportEnvironment[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:app.dev1lab.AnalysisLogUtil.SupportEnvironment Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:System.Void CopyTo(app.dev1lab.AnalysisLogUtil.SupportEnvironment[], System.Int32)
:app.dev1lab.AnalysisLogUtil.SupportEnvironment Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.AnalysisLogUtil.SupportEnvironment> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:System.Void Insert(System.Int32, app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:System.Boolean Remove(app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.AnalysisLogUtil.SupportEnvironment)
:app.dev1lab.AnalysisLogUtil.SupportEnvironment get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.AnalysisLogUtil.SupportEnvironment)
```

## `app.dev1lab.CommonGraphicsOptionController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<IsStartWithDirectX12>k__BackingField` | `System.Boolean` |  | 16 |
| `<LastCrashReport>k__BackingField` | `System.String` |  | 24 |
| `<SettingAsset>k__BackingField` | `app.dev1lab.CommonGraphicsOptionUserData` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean IsDefinedEnumValue(System.Type, System.Int32)
:System.Void enableBloom(System.Boolean)
:System.Void enableDepthOfField(System.Boolean)
:System.Void enableDynamicObjectShadow(System.Boolean)
:System.Void enableFilmGrainNoise(System.Boolean)
:System.Void enableHDRMode(System.Boolean)
:System.Void enableLensFlare(System.Boolean)
:System.Void enableMotionBlur(System.Boolean)
:System.Void enableParticleLighting(System.Boolean)
:System.Void enableShadowCache(System.Boolean)
:System.Void enableVerticalSync(System.Boolean)
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getSetting()
:System.Single getWindows10RecommendVramRate()
:System.Boolean get_IsStartWithDirectX12()
:System.String get_LastCrashReport()
:app.dev1lab.CommonGraphicsOptionUserData get_SettingAsset()
:System.Void initialize(app.dev1lab.CommonGraphicsOptionUserData)
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void setAmbientOcclusion(app.dev1lab.GraphicsOption.AmbientOcclusionType)
:System.Void setAntiAliasingType(via.render.RenderConfig.AntiAliasingType)
:System.Void setBrightnessLimitConfigImageIntensity(System.Single)
:System.Void setBrightnessLimitConfigImageIntensityAlpha(System.Single)
:System.Void setBrightnessOutputLimitConfigImage(via.render.TextureResourceHolder)
:System.Void setBrightnessOutputLimitConfigMode(via.render.OutputLimitConfigMode)
:System.Void setBrightnessOutputLimitConfigRect(via.Rect)
:System.Void setColorSpace(app.dev1lab.GraphicsOption.ColorSpaceType)
:System.Void setContactShadow(via.render.RenderConfig.OptionSetting)
:System.Void setEffectVolume(via.render.RenderConfig.Quality)
:System.Void setFrameRate(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void setImageQuality(app.dev1lab.GraphicsOption.ImageQuality_Value)
:System.Void setLensDistortionSetting(via.render.RenderConfig.LensDistortionSetting)
:System.Void setMeshQuality(via.render.RenderConfig.Quality)
:System.Void setRenderingMethod(via.render.RenderConfig.RenderingMethod)
:System.Void setSDRGamma(System.Single)
:System.Void setSDROutputLowerLimit(System.Single)
:System.Void setSDROutputUpperLimit(System.Single)
:System.Void setSSReflection(via.render.RenderConfig.OptionSetting)
:System.Void setSSSSSetting(via.render.RenderConfig.OptionSetting)
:System.Void setScreenSafeArea(System.Single)
:System.Void setShadowQuality(via.render.RenderConfig.Quality)
:System.Void setTextureFilterQuality(via.render.SamplerQuality)
:System.Void setTextureQuality(app.dev1lab.GraphicsOption.TextureQualityType)
:System.Void setVolumeLightQuality(via.render.RenderConfig.Quality)
:System.Void set_IsStartWithDirectX12(System.Boolean)
:System.Void set_LastCrashReport(System.String)
:System.Void set_SettingAsset(app.dev1lab.CommonGraphicsOptionUserData)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "GB2Byte", ...)  -- System.Single GB2Byte(System.Single)
```

## `app.dev1lab.CommonGraphicsOptionControllerForPC`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Windows10LimitVramRate` | `System.Single` | yes | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean checkLastPlayClash()
:System.Boolean checkUseUnavailableDirectX12()
:app.dev1lab.GraphicsPresetType getGraphicsPresetType()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getInitialUserData()
:app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType getResolutionMaxType()
:System.Int64 get_VramLowThreshold()
:System.Int64 get_VramMediumThreshold()
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void setDisplayMode(System.Int32)
:System.Void setWindowMode(via.render.WindowMode)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.dev1lab.CommonGraphicsOptionControllerForPS4`

**Methods**

```lua
:System.Void .ctor()
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `app.dev1lab.CommonGraphicsOptionControllerForXB1`

**Methods**

```lua
:System.Void .ctor()
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `app.dev1lab.CommonGraphicsOptionDefaultValueUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_defaultValues` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues get_defaultValues()
:System.Void set_defaultValues(app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PCTargetRenderAPI` | `System.Nullable`1<via.render.PCTargetAPI>` |  | 16 |
| `_FrameRate` | `System.Nullable`1<app.dev1lab.GraphicsOption.FrameRateType>` |  | 24 |
| `_WindowModeValue` | `System.Nullable`1<via.render.WindowMode>` |  | 32 |
| `_HDRModeValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 40 |
| `_ColorSpaceTypeValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ColorSpaceType>` |  | 48 |
| `_VSyncValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 56 |
| `_ShadowQualityValue` | `System.Nullable`1<via.render.RenderConfig.Quality>` |  | 64 |
| `_ShadowCacheValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 72 |
| `_DynamicObjectShadowValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 80 |
| `_ContactShadowValue` | `System.Nullable`1<via.render.RenderConfig.OptionSetting>` |  | 88 |
| `_VolumeLightQualityValue` | `System.Nullable`1<via.render.RenderConfig.Quality>` |  | 96 |
| `_BloomValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 104 |
| `_SSReflectionValue` | `System.Nullable`1<via.render.RenderConfig.OptionSetting>` |  | 112 |
| `_SSSSSettingValue` | `System.Nullable`1<via.render.RenderConfig.OptionSetting>` |  | 120 |
| `_AmbientOcclusionValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.AmbientOcclusionType>` |  | 128 |
| `_ParticleLightingValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 136 |
| `_LensFlareValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 144 |
| `_ImageQualityValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ImageQuality_Value>` |  | 152 |
| `_RenderingMethodValue` | `System.Nullable`1<via.render.RenderConfig.RenderingMethod>` |  | 160 |
| `_TextureQualityValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.TextureQualityType>` |  | 168 |
| `_TextureFilterQualityValue` | `System.Nullable`1<via.render.RenderConfig.Quality>` |  | 176 |
| `_MeshQualityValue` | `System.Nullable`1<via.render.RenderConfig.Quality>` |  | 184 |
| `_AntiAliasQualityValue` | `System.Nullable`1<via.render.RenderConfig.AntiAliasingType>` |  | 192 |
| `_LensDistortionValue` | `System.Nullable`1<via.render.RenderConfig.LensDistortionSetting>` |  | 200 |
| `_DepthOfFieldValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 208 |
| `_MotionBlurValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 216 |
| `_FilmGrainNoiseValue` | `System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff>` |  | 224 |
| `_EffectVolumeValue` | `System.Nullable`1<via.render.RenderConfig.Quality>` |  | 232 |
| `_Brightness_DarkValue` | `System.Nullable`1<System.Int32>` |  | 240 |
| `_Brightness_LightValue` | `System.Nullable`1<System.Int32>` |  | 248 |
| `_Brightness_GammaValue` | `System.Nullable`1<System.Int32>` |  | 256 |
| `_ScreenScaleValue` | `System.Nullable`1<System.Single>` |  | 264 |

**Methods**

```lua
:System.Void .ctor()
:System.Nullable`1<app.dev1lab.GraphicsOption.AmbientOcclusionType> get_AmbientOcclusionValue()
:System.Nullable`1<via.render.RenderConfig.AntiAliasingType> get_AntiAliasQualityValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_BloomValue()
:System.Nullable`1<System.Int32> get_Brightness_DarkValue()
:System.Nullable`1<System.Int32> get_Brightness_GammaValue()
:System.Nullable`1<System.Int32> get_Brightness_LightValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ColorSpaceType> get_ColorSpaceTypeValue()
:System.Nullable`1<via.render.RenderConfig.OptionSetting> get_ContactShadowValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_DepthOfFieldValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_DynamicObjectShadowValue()
:System.Nullable`1<via.render.RenderConfig.Quality> get_EffectVolumeValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_FilmGrainNoiseValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.FrameRateType> get_FrameRateValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_HDRModeValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ImageQuality_Value> get_ImageQualityValue()
:System.Nullable`1<via.render.RenderConfig.LensDistortionSetting> get_LensDistortionValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_LensFlareValue()
:System.Nullable`1<via.render.RenderConfig.Quality> get_MeshQualityValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_MotionBlurValue()
:System.Nullable`1<via.render.PCTargetAPI> get_PCTargetRenderAPIValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_ParticleLightingValue()
:System.Nullable`1<via.render.RenderConfig.RenderingMethod> get_RenderingMethodValue()
:System.Nullable`1<via.render.RenderConfig.OptionSetting> get_SSReflectionValue()
:System.Nullable`1<via.render.RenderConfig.OptionSetting> get_SSSSSettingValue()
:System.Nullable`1<System.Single> get_ScreenScaleValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_ShadowCacheValue()
:System.Nullable`1<via.render.RenderConfig.Quality> get_ShadowQualityValue()
:System.Nullable`1<via.render.RenderConfig.Quality> get_TextureFilterQualityValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.TextureQualityType> get_TextureQualityValue()
:System.Nullable`1<app.dev1lab.GraphicsOption.ParamOnOff> get_VSyncValue()
:System.Nullable`1<via.render.RenderConfig.Quality> get_VolumeLightQualityValue()
:System.Nullable`1<via.render.WindowMode> get_WindowModeValue()
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ResolutionList` | `System.Collections.Generic.List`1<app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo>` |  | 16 |
| `RefreshRateList` | `System.Collections.Generic.List`1<app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo>` |  | 24 |

**Methods**

```lua
:System.Void SortResolutionList(System.Collections.Generic.List`1<app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo>)
:System.Int32 convertDisplayModeIndex(System.Int32, System.Int32)
:System.Void createRefreshRateList(System.Int32)
:System.Void createRefreshRateList(System.Collections.Generic.List`1<System.String>, System.Int32)
:System.Void createResolutionList()
:System.Void createResolutionList(System.Collections.Generic.List`1<System.String>)
:System.Collections.Generic.List`1<app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo> createResolutionListCore(System.Collections.Generic.List`1<System.String>)
:System.Void finalize()
:System.Int32 getDefaultRefreshRateListIndex()
:System.Int32 getDefaultResolution(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:System.Int32 getDisplayModeIndex(System.Int32)
:System.Int32 getNearestDisplayListIndex()
:System.Int32 getNearestDisplayListIndex(System.Int32)
:System.Int32 getNowDisplayListIndex()
:System.Int32 getRefreshRateListIndex(System.Int32)
:System.Int32 getRefreshRateListOffset(System.Int32)
:System.Int32 getRefreshRateNum()
:System.String getRefreshRateString(System.Int32)
:System.Int32 getResolutionNum()
:System.String getResolutionString(System.Int32)
:System.Void init()
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `INFINITE` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType` | yes | 16 |
| `MAX1080P` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType` | yes | 16 |
| `MAX2160P` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:System.Void CopyTo(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType[], System.Int32)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:System.Void Insert(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:System.Boolean Remove(app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType)
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DispKind` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol` | yes | 16 |
| `RefreshRate` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol` | yes | 16 |
| `Resolution` | `app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:System.Void CopyTo(app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol[], System.Int32)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:System.Void Insert(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:System.Boolean Remove(app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.DisplayModeCol)
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RefreshRate>k__BackingField` | `System.String` |  | 16 |
| `<Value>k__BackingField` | `System.Int32` |  | 24 |
| `<Index>k__BackingField` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32, System.String)
:System.String ToString()
:System.Int32 get_Index()
:System.String get_RefreshRate()
:System.Int32 get_Value()
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:System.Void CopyTo(app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo[], System.Int32)
:app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:System.Void Insert(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:System.Boolean Remove(app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
:app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.RefreshRateInfo)
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Index>k__BackingField` | `System.Int32` |  | 16 |
| `<Resolution>k__BackingField` | `System.String` |  | 24 |
| `<ResolutionSize>k__BackingField` | `via.Size` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.String)
:System.String ToString()
:System.Int32 get_Index()
:System.String get_Resolution()
:via.Size get_ResolutionSize()
```

## `app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:System.Void CopyTo(app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo[], System.Int32)
:app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:System.Void Insert(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:System.Boolean Remove(app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
:app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.CommonGraphicsOptionDisplayMode.ResolutionInfo)
```

## `app.dev1lab.CommonGraphicsOptionDisplayModeTest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CurrentEngineDisplayModeList>k__BackingField` | `System.Collections.Generic.List`1<System.String>` |  | 80 |
| `<CurrentEngineFullScreenDisplayMode>k__BackingField` | `System.Int32` |  | 88 |
| `<CurrentListIndex>k__BackingField` | `System.Int32` |  | 92 |
| `<currentResIndex>k__BackingField` | `System.Int32` |  | 96 |
| `DisplayMode` | `app.dev1lab.CommonGraphicsOptionDisplayMode` |  | 104 |

**Methods**

```lua
:System.Void .ctor()
:System.Void ResetCurrentList()
:System.Void createCurrentEnvironmentInfo()
:System.Void createCustomList()
:System.Collections.Generic.List`1<System.String> createListEngine()
:System.Collections.Generic.List`1<System.String> createListSelf()
:System.Collections.Generic.List`1<System.String> createListSelf2()
:System.Collections.Generic.List`1<System.String> get_CurrentEngineDisplayModeList()
:System.Int32 get_CurrentEngineFullScreenDisplayMode()
:System.Int32 get_CurrentListIndex()
:System.Int32 get_currentResIndex()
:System.Void revertList()
:System.Void set_CurrentEngineDisplayModeList(System.Collections.Generic.List`1<System.String>)
:System.Void set_CurrentEngineFullScreenDisplayMode(System.Int32)
:System.Void set_CurrentListIndex(System.Int32)
:System.Void set_currentResIndex(System.Int32)
```

## `app.dev1lab.CommonGraphicsOptionManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Controller>k__BackingField` | `app.dev1lab.CommonGraphicsOptionController` |  | 16 |
| `<DisplayMode>k__BackingField` | `app.dev1lab.CommonGraphicsOptionDisplayMode` |  | 24 |
| `_GraphicsItems` | `System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>` |  | 32 |
| `_SettingAsset` | `app.dev1lab.CommonGraphicsOptionUserData` |  | 40 |

**Methods**

```lua
:System.Boolean <registerCallBack>b__21_0(System.Int32)
:System.Boolean <registerCallBack>b__21_12(System.Int32)
:System.Boolean <registerCallBack>b__21_15(System.Int32)
:System.Boolean <registerCallBack>b__21_18(System.Int32)
:System.Boolean <registerCallBack>b__21_21(System.Int32)
:System.Boolean <registerCallBack>b__21_24(System.Int32)
:System.Boolean <registerCallBack>b__21_27(System.Int32)
:System.Boolean <registerCallBack>b__21_3(System.Int32)
:System.Boolean <registerCallBack>b__21_30(System.Int32)
:System.Boolean <registerCallBack>b__21_33(System.Int32)
:System.Boolean <registerCallBack>b__21_36(System.Int32)
:System.Boolean <registerCallBack>b__21_39(System.Int32)
:System.Boolean <registerCallBack>b__21_42(System.Int32)
:System.Boolean <registerCallBack>b__21_45(System.Int32)
:System.Boolean <registerCallBack>b__21_48(System.Int32)
:System.Boolean <registerCallBack>b__21_51(System.Int32)
:System.Boolean <registerCallBack>b__21_54(System.Int32)
:System.Boolean <registerCallBack>b__21_57(System.Int32)
:System.Boolean <registerCallBack>b__21_6(System.Int32)
:System.Boolean <registerCallBack>b__21_60(System.Int32)
:System.Boolean <registerCallBack>b__21_63(System.Int32)
:System.Boolean <registerCallBack>b__21_66(System.Int32)
:System.Boolean <registerCallBack>b__21_69(System.Int32)
:System.Boolean <registerCallBack>b__21_72(System.Int32)
:System.Boolean <registerCallBack>b__21_75(System.Int32)
:System.Boolean <registerCallBack>b__21_78(System.Int32)
:System.Boolean <registerCallBack>b__21_81(System.Int32)
:System.Boolean <registerCallBack>b__21_84(System.Int32)
:System.Boolean <registerCallBack>b__21_87(System.Int32)
:System.Boolean <registerCallBack>b__21_9(System.Int32)
:System.Boolean <registerCallBack>b__21_90(System.Int32)
:System.Boolean <registerCallBack>b__21_93(System.Int32)
:System.Boolean <registerCallBack>b__21_96(System.Int32)
:System.Boolean <registerCallBack>b__21_99(System.Int32)
:System.Boolean IsDefinedEnumValue(System.Type, System.Int32)
:System.Boolean IsOnOffValue(System.Int32)
:System.Void applyAmbientOcclusion(System.Int32)
:System.Void applyAntiAliasQuality(System.Int32)
:System.Void applyBloomSetting(System.Int32)
:System.Void applyBrightness_Dark(System.Int32)
:System.Void applyBrightness_Gamma(System.Int32)
:System.Void applyBrightness_Light(System.Int32)
:System.Void applyColorSpaceSetting(System.Int32)
:System.Void applyContactShadowSetting(System.Int32)
:System.Void applyDepthOfField(System.Int32)
:System.Void applyDirectXSetting(System.Int32)
:System.Void applyDynamicObjectShadowSetting(System.Int32)
:System.Void applyEffectVolume(System.Int32)
:System.Void applyFilmGrainNoise(System.Int32)
:System.Void applyFrameRateSetting(System.Int32)
:System.Void applyHDRModeSetting(System.Int32)
:System.Void applyImageQuality(System.Int32)
:System.Void applyLensDistortion(System.Int32)
:System.Void applyLensFlare(System.Int32)
:System.Void applyMeshQuality(System.Int32)
:System.Void applyMotionBlur(System.Int32)
:System.Void applyParticleLighting(System.Int32)
:System.Void applyRefreshRateSetting(System.Int32)
:System.Void applyRenderingMethod(System.Int32)
:System.Void applyResolutionSetting(System.Int32)
:System.Void applySSReflectionSetting(System.Int32)
:System.Void applySSSSSetting(System.Int32)
:System.Void applyScreenScale(System.Int32)
:System.Void applySettings()
:System.Void applyShadowCacheSetting(System.Int32)
:System.Void applyShadowQualitySetting(System.Int32)
:System.Void applyTextureFilterQuality(System.Int32)
:System.Void applyTextureQuality(System.Int32)
:System.Void applyVSyncSetting(System.Int32)
:System.Void applyVolumeLightQualitySetting(System.Int32)
:System.Void applyWindowModeSetting(System.Int32)
:System.Void awake()
:System.Boolean checkValueAmbientOcclusionSetting(System.Int32)
:System.Boolean checkValueAntiAliasQualitySetting(System.Int32)
:System.Boolean checkValueBloomSetting(System.Int32)
:System.Boolean checkValueBrightness_DarkSetting(System.Int32)
:System.Boolean checkValueBrightness_GammaSetting(System.Int32)
:System.Boolean checkValueBrightness_LightSetting(System.Int32)
:System.Boolean checkValueColorSpaceSetting(System.Int32)
:System.Boolean checkValueContactShadowSetting(System.Int32)
:System.Boolean checkValueDepthOfFieldSetting(System.Int32)
:System.Boolean checkValueDirectXSetting(System.Int32)
:System.Boolean checkValueDynamicObjectShadowSetting(System.Int32)
:System.Boolean checkValueEffectVolumeSetting(System.Int32)
:System.Boolean checkValueFilmGrainSetting(System.Int32)
:System.Boolean checkValueFrameRateSetting(System.Int32)
:System.Boolean checkValueHDRmodeSetting(System.Int32)
:System.Boolean checkValueImageQualitySetting(System.Int32)
:System.Boolean checkValueLensDistortionSetting(System.Int32)
:System.Boolean checkValueLensFlareSetting(System.Int32)
:System.Boolean checkValueMeshQualitySetting(System.Int32)
:System.Boolean checkValueMotionBlurSetting(System.Int32)
:System.Boolean checkValueParticleLightingSetting(System.Int32)
:System.Boolean checkValueRefreshRateSetting(System.Int32)
:System.Boolean checkValueRenderingMethodSetting(System.Int32)
:System.Boolean checkValueResolutionSetting(System.Int32)
:System.Boolean checkValueSSReflectionSetting(System.Int32)
:System.Boolean checkValueSSSSSettingSetting(System.Int32)
:System.Boolean checkValueScreenScaleSetting(System.Int32)
:System.Boolean checkValueShadowCacheSetting(System.Int32)
:System.Boolean checkValueShadowQualitySetting(System.Int32)
:System.Boolean checkValueTextureFilterQualitySetting(System.Int32)
:System.Boolean checkValueTextureQualitySetting(System.Int32)
:System.Boolean checkValueVSyncSetting(System.Int32)
:System.Boolean checkValueVolumeLightQualitySetting(System.Int32)
:System.Boolean checkValueWindowModeSetting(System.Int32)
:System.Single convertLevel2Intensity(System.Int32, app.dev1lab.SliderConfig)
:System.Void finalize()
:System.Void finalizeBrightnessSetting()
:System.Void finalizeDisplayMode()
:System.Void getValueFromGraphicsItems(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,System.Int32>)
:app.dev1lab.CommonGraphicsOptionController get_Controller()
:app.dev1lab.CommonGraphicsOptionDisplayMode get_DisplayMode()
:System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem> get_GraphicsItems()
:app.dev1lab.CommonGraphicsOptionUserData get_SettingAsset()
:System.Void initDisplayMode()
:System.Void onDestroy()
:System.Void onWindowModeChangeEvent(via.render.WindowModeChangeStatus)
:System.Void registerCallBack(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void resetAllToPlatformDefaultValues(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void resetToDisplayDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void setValueToGraphicsItems(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,System.Int32>)
:System.Void set_Controller(app.dev1lab.CommonGraphicsOptionController)
:System.Void set_DisplayMode(app.dev1lab.CommonGraphicsOptionDisplayMode)
:System.Void set_GraphicsItems(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void set_SettingAsset(app.dev1lab.CommonGraphicsOptionUserData)
:System.Void setupBrightnessSetting(via.Rect, via.render.TextureResourceHolder, System.Single)
:System.Void setupBrightnessSetting_Dark(via.Rect, via.render.TextureResourceHolder, System.Single)
:System.Void setupBrightnessSetting_Gamma()
:System.Void setupBrightnessSetting_Light(via.Rect, via.render.TextureResourceHolder, System.Single)
:System.Void showBrightnessTestImage(System.Boolean, via.render.OutputLimitConfigMode)
:System.Void valueChangeBrightness_Dark(System.Int32)
:System.Void valueChangeBrightness_Light(System.Int32)
```

## `app.dev1lab.CommonGraphicsOptionUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ps4SettingValue` | `app.dev1lab.CommonGraphicsOptionUserData.PS4Setting` |  | 32 |
| `_xboxoneSettingValue` | `app.dev1lab.CommonGraphicsOptionUserData.XBoxOneSetting` |  | 40 |
| `_pcSettingValue` | `app.dev1lab.CommonGraphicsOptionUserData.PCSetting` |  | 48 |
| `_graphicsParam` | `app.dev1lab.CommonGraphicsOptionUserData.GraphicsOptionCustom` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionUserData.PlatformSetting getPlatformSetting()
:app.dev1lab.CommonGraphicsOptionUserData.GraphicsOptionCustom get_GraphicsParam()
:app.dev1lab.CommonGraphicsOptionUserData.PCSetting get_PCSettingValue()
:app.dev1lab.CommonGraphicsOptionUserData.PS4Setting get_PS4SettingValue()
:app.dev1lab.CommonGraphicsOptionUserData.XBoxOneSetting get_XBoxOneSettingValue()
:System.Void set_GraphicsParam(app.dev1lab.CommonGraphicsOptionUserData.GraphicsOptionCustom)
:System.Void set_PCSettingValue(app.dev1lab.CommonGraphicsOptionUserData.PCSetting)
:System.Void set_PS4SettingValue(app.dev1lab.CommonGraphicsOptionUserData.PS4Setting)
:System.Void set_XBoxOneSettingValue(app.dev1lab.CommonGraphicsOptionUserData.XBoxOneSetting)
```

## `app.dev1lab.CommonGraphicsOptionUserData.GraphicsOptionCustom`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BrightnessSection` | `System.Boolean` | yes | 16 |
| `BrightnessSectionEnd` | `System.Boolean` | yes | 16 |
| `ScreenAreaSection` | `System.Boolean` | yes | 16 |
| `ScreenAreaSectionEnd` | `System.Boolean` | yes | 16 |
| `_SDR_DARK_CONFIG` | `app.dev1lab.SliderConfig` |  | 16 |
| `_SDR_LIGHT_CONFIG` | `app.dev1lab.SliderConfig` |  | 24 |
| `_SDR_GAMMA_CONFIG` | `app.dev1lab.SliderConfig` |  | 32 |
| `_MIN_SCREEN_AREA_SCALE` | `System.Single` |  | 40 |
| `_MAX_SCREEN_AREA_SCALE` | `System.Single` |  | 44 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_MAX_SCREEN_AREA_SCALE()
:System.Single get_MIN_SCREEN_AREA_SCALE()
:app.dev1lab.SliderConfig get_SDR_DARK_CONFIG()
:app.dev1lab.SliderConfig get_SDR_GAMMA_CONFIG()
:app.dev1lab.SliderConfig get_SDR_LIGHT_CONFIG()
:System.Void set_MAX_SCREEN_AREA_SCALE(System.Single)
:System.Void set_MIN_SCREEN_AREA_SCALE(System.Single)
:System.Void set_SDR_DARK_CONFIG(app.dev1lab.SliderConfig)
:System.Void set_SDR_GAMMA_CONFIG(app.dev1lab.SliderConfig)
:System.Void set_SDR_LIGHT_CONFIG(app.dev1lab.SliderConfig)
```

## `app.dev1lab.CommonGraphicsOptionUserData.PCSetting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SectionEnd` | `System.Boolean` | yes | 16 |
| `SpecSection` | `System.Boolean` | yes | 16 |
| `_VramLowThreshold_GB` | `System.Single` |  | 16 |
| `_VramMediumThreshold_GB` | `System.Single` |  | 20 |
| `_Windows10RecomendVramRate` | `System.Single` |  | 24 |
| `_pcLowDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 32 |
| `_pcMediumDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 40 |
| `_pcHighDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_PCHighDefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_PCLowDefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_PCMediumDefaultAsset()
:System.Single get_VramLowThreshold_GB()
:System.Single get_VramMediumThreshold_GB()
:System.Single get_Windows10RecomendVramRate()
:System.Void set_PCHighDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
:System.Void set_PCLowDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
:System.Void set_PCMediumDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
:System.Void set_VramLowThreshold_GB(System.Single)
:System.Void set_VramMediumThreshold_GB(System.Single)
:System.Void set_Windows10RecomendVramRate(System.Single)
```

## `app.dev1lab.CommonGraphicsOptionUserData.PS4Setting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PS4DefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 16 |
| `_PS4ProDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 24 |

**Methods**

```lua
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_PS4DefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_PS4ProDefaultAsset()
:System.Void set_PS4DefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
:System.Void set_PS4ProDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
```

## `app.dev1lab.CommonGraphicsOptionUserData.PlatformSetting`

_No fields or methods._

## `app.dev1lab.CommonGraphicsOptionUserData.XBoxOneSetting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_XBoxOneDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 16 |
| `_XBoxOne_XDefaultAsset` | `app.dev1lab.CommonGraphicsOptionDefaultValueUserData` |  | 24 |

**Methods**

```lua
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_XBoxOneDefaultAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData get_XBoxOne_XDefaultAsset()
:System.Void set_XBoxOneDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
:System.Void set_XBoxOne_XDefaultAsset(app.dev1lab.CommonGraphicsOptionDefaultValueUserData)
```

## `app.dev1lab.CommonObjectBase`

_No fields or methods._

## `app.dev1lab.CommonRuntimeArgument`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_runtimeArguments` | `System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>>` |  | 16 |

**Methods**

```lua
:System.Void analyze(System.String)
:System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit> getUnit(System.String)
:System.Collections.Generic.Dictionary`2<System.String,System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>> get_ParsedArguments()
:System.Char get_Separator()
:System.Void setup(System.Collections.Generic.List`1<System.String>, System.Collections.Generic.List`1<System.String>)
:System.Void updateUnitList(System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>, app.dev1lab.CommonRuntimeArgument.Unit)
```

## `app.dev1lab.CommonRuntimeArgument.Unit`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<label>k__BackingField` | `System.String` |  | 16 |
| `<value>k__BackingField` | `System.String` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String, System.String)
:System.String get_label()
:System.String get_value()
:System.Void set_label(System.String)
:System.Void set_value(System.String)
```

## `app.dev1lab.CommonRuntimeArgument.Unit[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.CommonRuntimeArgument.Unit)
:app.dev1lab.CommonRuntimeArgument.Unit Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.CommonRuntimeArgument.Unit)
:System.Void CopyTo(app.dev1lab.CommonRuntimeArgument.Unit[], System.Int32)
:app.dev1lab.CommonRuntimeArgument.Unit Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.CommonRuntimeArgument.Unit> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.CommonRuntimeArgument.Unit)
:System.Void Insert(System.Int32, app.dev1lab.CommonRuntimeArgument.Unit)
:System.Boolean Remove(app.dev1lab.CommonRuntimeArgument.Unit)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.CommonRuntimeArgument.Unit)
:app.dev1lab.CommonRuntimeArgument.Unit get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.CommonRuntimeArgument.Unit)
```

## `app.dev1lab.CommonSingleton`

**Methods**

```lua
:System.Single getScaledDeltaTime()
```

## `app.dev1lab.DictionaryExtension`

_No fields or methods._

## `app.dev1lab.GameOption`

_No fields or methods._

## `app.dev1lab.GameOption.ID`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CameraHorizontalDirection` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `CameraVerticalDirection` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `CameraVibration` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `DynamicRangeControl` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `KeyConfig` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `LanguageCaption` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `LanguageText` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `LanguageVoice` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `PlayerHorizontalDirection` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `PlayerVerticalDirection` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `RealtimeBinaural` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `SpeakerType` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `VolumeBGM` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `VolumeSE` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `VolumeVoice` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `invalid` | `app.dev1lab.GameOption.ID` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GameOption.ID[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GameOption.ID)
:app.dev1lab.GameOption.ID Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GameOption.ID)
:System.Void CopyTo(app.dev1lab.GameOption.ID[], System.Int32)
:app.dev1lab.GameOption.ID Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GameOption.ID> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GameOption.ID)
:System.Void Insert(System.Int32, app.dev1lab.GameOption.ID)
:System.Boolean Remove(app.dev1lab.GameOption.ID)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GameOption.ID)
:app.dev1lab.GameOption.ID get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GameOption.ID)
```

## `app.dev1lab.GameOptionManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GameItems` | `System.Collections.Generic.Dictionary`2<app.dev1lab.GameOption.ID,app.dev1lab.OptionValueItem>` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Collections.Generic.Dictionary`2<app.dev1lab.GameOption.ID,app.dev1lab.OptionValueItem> get_GameItems()
:System.Void onDestroy()
:System.Void registerCallBack()
:System.Void set_GameItems(System.Collections.Generic.Dictionary`2<app.dev1lab.GameOption.ID,app.dev1lab.OptionValueItem>)
```

## `app.dev1lab.GraphicsOption`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IDList` | `app.dev1lab.GraphicsOption.ID[]` | yes | 16 |
| `IDCount` | `System.Int32` | yes | 24 |
| `ImageQuality_ValueNum` | `System.Int32` | yes | 28 |
| `FrameRateTypeNum` | `System.Int32` | yes | 32 |
| `ColorSpaceTypeNum` | `System.Int32` | yes | 36 |
| `TextureQualityTypeNum` | `System.Int32` | yes | 40 |
| `AmbientOcclusionTypeNum` | `System.Int32` | yes | 44 |
| `ParamOnOffNum` | `System.Int32` | yes | 48 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "createIDList", ...)  -- app.dev1lab.GraphicsOption.ID[] createIDList()
```

## `app.dev1lab.GraphicsOption.AmbientOcclusionType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HBAO` | `app.dev1lab.GraphicsOption.AmbientOcclusionType` | yes | 16 |
| `HDAO` | `app.dev1lab.GraphicsOption.AmbientOcclusionType` | yes | 16 |
| `OFF` | `app.dev1lab.GraphicsOption.AmbientOcclusionType` | yes | 16 |
| `SSAO` | `app.dev1lab.GraphicsOption.AmbientOcclusionType` | yes | 16 |
| `SSAO_FLEXIBLE` | `app.dev1lab.GraphicsOption.AmbientOcclusionType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.AmbientOcclusionType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.AmbientOcclusionType)
:app.dev1lab.GraphicsOption.AmbientOcclusionType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.AmbientOcclusionType)
:System.Void CopyTo(app.dev1lab.GraphicsOption.AmbientOcclusionType[], System.Int32)
:app.dev1lab.GraphicsOption.AmbientOcclusionType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.AmbientOcclusionType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.AmbientOcclusionType)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.AmbientOcclusionType)
:System.Boolean Remove(app.dev1lab.GraphicsOption.AmbientOcclusionType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.AmbientOcclusionType)
:app.dev1lab.GraphicsOption.AmbientOcclusionType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.AmbientOcclusionType)
```

## `app.dev1lab.GraphicsOption.ColorSpaceType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Rec2020` | `app.dev1lab.GraphicsOption.ColorSpaceType` | yes | 16 |
| `Rec709` | `app.dev1lab.GraphicsOption.ColorSpaceType` | yes | 16 |
| `sRGB` | `app.dev1lab.GraphicsOption.ColorSpaceType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.ColorSpaceType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.ColorSpaceType)
:app.dev1lab.GraphicsOption.ColorSpaceType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.ColorSpaceType)
:System.Void CopyTo(app.dev1lab.GraphicsOption.ColorSpaceType[], System.Int32)
:app.dev1lab.GraphicsOption.ColorSpaceType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.ColorSpaceType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.ColorSpaceType)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.ColorSpaceType)
:System.Boolean Remove(app.dev1lab.GraphicsOption.ColorSpaceType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.ColorSpaceType)
:app.dev1lab.GraphicsOption.ColorSpaceType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.ColorSpaceType)
```

## `app.dev1lab.GraphicsOption.FrameRateType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FPS120` | `app.dev1lab.GraphicsOption.FrameRateType` | yes | 16 |
| `FPS30` | `app.dev1lab.GraphicsOption.FrameRateType` | yes | 16 |
| `FPS60` | `app.dev1lab.GraphicsOption.FrameRateType` | yes | 16 |
| `VARIABLE` | `app.dev1lab.GraphicsOption.FrameRateType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.FrameRateType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.FrameRateType)
:app.dev1lab.GraphicsOption.FrameRateType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void CopyTo(app.dev1lab.GraphicsOption.FrameRateType[], System.Int32)
:app.dev1lab.GraphicsOption.FrameRateType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.FrameRateType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.FrameRateType)
:System.Boolean Remove(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.FrameRateType)
:app.dev1lab.GraphicsOption.FrameRateType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.FrameRateType)
```

## `app.dev1lab.GraphicsOption.ID`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AmbientOcclusion` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `AntiAliasQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Bloom` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Brightness_Dark` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Brightness_Gamma` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Brightness_Light` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ColorSpace` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ContactShadow` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `DepthOfField` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `DirectX` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `DynamicObjectShadow` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `EffectVolume` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `FilmGrainNoise` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `FrameRate` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `HDRmode` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ImageQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `LensDistortion` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `LensFlare` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `MAX` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `MeshQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `MotionBlur` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ParticleLighting` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `RefreshRate` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `RenderingMethod` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Resolution` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `SSReflection` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `SSSSSetting` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ScreenScale` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ShadowCache` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `ShadowQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `TextureFilterQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `TextureQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `VolumeLightQuality` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `Vsync` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `WindowMode` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `invalid` | `app.dev1lab.GraphicsOption.ID` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.IDComparer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Instance` | `app.dev1lab.GraphicsOption.IDComparer` | yes | 16 |

**Methods**

```lua
:System.Boolean Equals(app.dev1lab.GraphicsOption.ID, app.dev1lab.GraphicsOption.ID)
:System.Int32 GetHashCode(app.dev1lab.GraphicsOption.ID)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.dev1lab.GraphicsOption.ID[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.ID)
:app.dev1lab.GraphicsOption.ID Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.ID)
:System.Void CopyTo(app.dev1lab.GraphicsOption.ID[], System.Int32)
:app.dev1lab.GraphicsOption.ID Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.ID> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.ID)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.ID)
:System.Boolean Remove(app.dev1lab.GraphicsOption.ID)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.ID)
:app.dev1lab.GraphicsOption.ID get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.ID)
```

## `app.dev1lab.GraphicsOption.ImageQuality_Value`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IQ_05` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_06` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_07` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_08` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_09` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_10` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_11` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_12` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_13` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_14` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_15` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_16` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_17` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_18` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_19` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `IQ_20` | `app.dev1lab.GraphicsOption.ImageQuality_Value` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.ImageQuality_Value[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.ImageQuality_Value)
:app.dev1lab.GraphicsOption.ImageQuality_Value Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.ImageQuality_Value)
:System.Void CopyTo(app.dev1lab.GraphicsOption.ImageQuality_Value[], System.Int32)
:app.dev1lab.GraphicsOption.ImageQuality_Value Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.ImageQuality_Value> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.ImageQuality_Value)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.ImageQuality_Value)
:System.Boolean Remove(app.dev1lab.GraphicsOption.ImageQuality_Value)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.ImageQuality_Value)
:app.dev1lab.GraphicsOption.ImageQuality_Value get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.ImageQuality_Value)
```

## `app.dev1lab.GraphicsOption.ParamOnOff`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Off` | `app.dev1lab.GraphicsOption.ParamOnOff` | yes | 16 |
| `On` | `app.dev1lab.GraphicsOption.ParamOnOff` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.ParamOnOff[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.ParamOnOff)
:app.dev1lab.GraphicsOption.ParamOnOff Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.ParamOnOff)
:System.Void CopyTo(app.dev1lab.GraphicsOption.ParamOnOff[], System.Int32)
:app.dev1lab.GraphicsOption.ParamOnOff Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.ParamOnOff> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.ParamOnOff)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.ParamOnOff)
:System.Boolean Remove(app.dev1lab.GraphicsOption.ParamOnOff)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.ParamOnOff)
:app.dev1lab.GraphicsOption.ParamOnOff get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.ParamOnOff)
```

## `app.dev1lab.GraphicsOption.TextureQualityType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HIGH_025` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_05` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_1` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_2` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_3` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_4` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_6` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `HIGH_8` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `LOW` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `STANDARD_025` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `STANDARD_05` | `app.dev1lab.GraphicsOption.TextureQualityType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsOption.TextureQualityType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsOption.TextureQualityType)
:app.dev1lab.GraphicsOption.TextureQualityType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsOption.TextureQualityType)
:System.Void CopyTo(app.dev1lab.GraphicsOption.TextureQualityType[], System.Int32)
:app.dev1lab.GraphicsOption.TextureQualityType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsOption.TextureQualityType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsOption.TextureQualityType)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsOption.TextureQualityType)
:System.Boolean Remove(app.dev1lab.GraphicsOption.TextureQualityType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsOption.TextureQualityType)
:app.dev1lab.GraphicsOption.TextureQualityType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsOption.TextureQualityType)
```

## `app.dev1lab.GraphicsPresetType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Default` | `app.dev1lab.GraphicsPresetType` | yes | 16 |
| `High` | `app.dev1lab.GraphicsPresetType` | yes | 16 |
| `Low` | `app.dev1lab.GraphicsPresetType` | yes | 16 |
| `Medium` | `app.dev1lab.GraphicsPresetType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.GraphicsPresetType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.GraphicsPresetType)
:app.dev1lab.GraphicsPresetType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.GraphicsPresetType)
:System.Void CopyTo(app.dev1lab.GraphicsPresetType[], System.Int32)
:app.dev1lab.GraphicsPresetType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.GraphicsPresetType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.GraphicsPresetType)
:System.Void Insert(System.Int32, app.dev1lab.GraphicsPresetType)
:System.Boolean Remove(app.dev1lab.GraphicsPresetType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.GraphicsPresetType)
:app.dev1lab.GraphicsPresetType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.GraphicsPresetType)
```

## `app.dev1lab.ICommonInterfaceBase`

_No fields or methods._

## `app.dev1lab.LocalSaveIO`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<_lockObject>k__BackingField` | `System.Object` | yes | 16 |
| `FALLBACK_STRING` | `System.String` | yes | 24 |

**Methods**

```lua
:System.Void loadAndSaveSingle(app.dev1lab.LocalSaveIO.SaveDescription, app.dev1lab.LocalSaveIO.onCreateSaveValue)
:System.Boolean loadSingle(app.dev1lab.LocalSaveIO.SaveDescription, System.String)
:System.Boolean loadSingleCore(System.String, System.String, System.String, System.String)
:System.Void saveRenderConfig()
:System.Void saveSingle(app.dev1lab.LocalSaveIO.SaveDescription)
:System.Void saveSingleCore(System.String, System.String, System.String)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "get__lockObject", ...)  -- System.Object get__lockObject()
```

## `app.dev1lab.LocalSaveIO.SaveDescription`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_group` | `System.String` |  | 16 |
| `_name` | `System.String` |  | 24 |
| `_val` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(app.dev1lab.LocalSaveIO.SaveDescription)
:System.Void .ctor(System.String, System.String, System.String, System.Boolean)
:System.String getPostFix()
:System.String get_ElementName()
:System.String get_GroupName()
:System.String get_Val()
:System.Void set_ElementName(System.String)
:System.Void set_GroupName(System.String)
:System.Void set_Val(System.String)
```

## `app.dev1lab.LocalSaveIO.onCreateSaveValue`

**Methods**

```lua
:app.dev1lab.LocalSaveIO.SaveDescription Invoke(System.String, System.Boolean)
```

## `app.dev1lab.LocalSaveIOTestBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GraphicsManager` | `app.dev1lab.TitleGraphicsOptionManager` |  | 80 |
| `GameManager` | `app.dev1lab.GameOptionManager` |  | 88 |
| `_GROUP_RENDER` | `System.String` |  | 96 |
| `_GROUP_GAME` | `System.String` |  | 104 |
| `_applyPostfix` | `System.Boolean` |  | 112 |

**Methods**

```lua
:System.Void .ctor()
:System.Void applyLoadedValue(app.dev1lab.GraphicsOption.ID, System.String, System.Boolean)
:System.Void awake()
:System.String get_GROUP_GAME()
:System.String get_GROUP_RENDER()
:System.Boolean get_applyPostfix()
:System.Void readLocalSave()
:System.Void readLocalSaveGroup()
:System.Void readLocalSave_GameOption()
:System.Void setOptionManager()
:System.Void set_GROUP_GAME(System.String)
:System.Void set_GROUP_RENDER(System.String)
:System.Void set_applyPostfix(System.Boolean)
:System.Void writeLocalSave()
:System.Void writeLocalSaveGroup()
:System.Void writeLocalSave_GameOption()
:System.Void writeLocalSave_RenderConfig()
```

## `app.dev1lab.LocalSaveLockTest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `lockObj` | `System.Object` | yes | 80 |
| `enableLock` | `System.Boolean` | yes | 88 |
| `GROUP` | `System.String` |  | 80 |
| `NAME` | `System.String` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Void CSAccessWithLock()
:System.Void CSAccessWithoutLock()
:System.Boolean get_EnableLock()
:System.Void set_EnableLock(System.Boolean)
:System.Void update()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.dev1lab.OptionCategory`

_No fields or methods._

## `app.dev1lab.OptionCategory.ID`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Audio` | `app.dev1lab.OptionCategory.ID` | yes | 16 |
| `Controller` | `app.dev1lab.OptionCategory.ID` | yes | 16 |
| `Game` | `app.dev1lab.OptionCategory.ID` | yes | 16 |
| `Graphics` | `app.dev1lab.OptionCategory.ID` | yes | 16 |
| `Language` | `app.dev1lab.OptionCategory.ID` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.OptionCategory.ID[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionCategory.ID)
:app.dev1lab.OptionCategory.ID Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionCategory.ID)
:System.Void CopyTo(app.dev1lab.OptionCategory.ID[], System.Int32)
:app.dev1lab.OptionCategory.ID Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionCategory.ID> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionCategory.ID)
:System.Void Insert(System.Int32, app.dev1lab.OptionCategory.ID)
:System.Boolean Remove(app.dev1lab.OptionCategory.ID)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionCategory.ID)
:app.dev1lab.OptionCategory.ID get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionCategory.ID)
```

## `app.dev1lab.OptionGraphicsItemData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GraphicsId` | `app.dev1lab.GraphicsOption.ID` |  | 16 |
| `CategoryId` | `app.dev1lab.OptionCategory.ID` |  | 20 |
| `ItemMessage` | `app.dev1lab.OptionGraphicsItemData.OptionMessage` |  | 24 |
| `OptionSelectType` | `app.dev1lab.OptionGraphicsItemData.SelectType` |  | 32 |
| `SelectMessage` | `System.Collections.Generic.List`1<app.dev1lab.OptionGraphicsItemData.OptionMessage>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_DisplayName()
```

## `app.dev1lab.OptionGraphicsItemData.OptionMessage`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NameId` | `System.Guid` |  | 16 |
| `NameStr` | `System.String` |  | 32 |
| `DescId` | `System.Guid` |  | 40 |
| `DescStr` | `System.String` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_MessageDisplayName()
```

## `app.dev1lab.OptionGraphicsItemData.OptionMessage[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionGraphicsItemData.OptionMessage)
:app.dev1lab.OptionGraphicsItemData.OptionMessage Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionGraphicsItemData.OptionMessage)
:System.Void CopyTo(app.dev1lab.OptionGraphicsItemData.OptionMessage[], System.Int32)
:app.dev1lab.OptionGraphicsItemData.OptionMessage Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionGraphicsItemData.OptionMessage> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionGraphicsItemData.OptionMessage)
:System.Void Insert(System.Int32, app.dev1lab.OptionGraphicsItemData.OptionMessage)
:System.Boolean Remove(app.dev1lab.OptionGraphicsItemData.OptionMessage)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionGraphicsItemData.OptionMessage)
:app.dev1lab.OptionGraphicsItemData.OptionMessage get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionGraphicsItemData.OptionMessage)
```

## `app.dev1lab.OptionGraphicsItemData.SelectType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Custom` | `app.dev1lab.OptionGraphicsItemData.SelectType` | yes | 16 |
| `OnOff` | `app.dev1lab.OptionGraphicsItemData.SelectType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.OptionGraphicsItemData.SelectType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionGraphicsItemData.SelectType)
:app.dev1lab.OptionGraphicsItemData.SelectType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionGraphicsItemData.SelectType)
:System.Void CopyTo(app.dev1lab.OptionGraphicsItemData.SelectType[], System.Int32)
:app.dev1lab.OptionGraphicsItemData.SelectType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionGraphicsItemData.SelectType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionGraphicsItemData.SelectType)
:System.Void Insert(System.Int32, app.dev1lab.OptionGraphicsItemData.SelectType)
:System.Boolean Remove(app.dev1lab.OptionGraphicsItemData.SelectType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionGraphicsItemData.SelectType)
:app.dev1lab.OptionGraphicsItemData.SelectType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionGraphicsItemData.SelectType)
```

## `app.dev1lab.OptionGraphicsItemData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionGraphicsItemData)
:app.dev1lab.OptionGraphicsItemData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionGraphicsItemData)
:System.Void CopyTo(app.dev1lab.OptionGraphicsItemData[], System.Int32)
:app.dev1lab.OptionGraphicsItemData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionGraphicsItemData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionGraphicsItemData)
:System.Void Insert(System.Int32, app.dev1lab.OptionGraphicsItemData)
:System.Boolean Remove(app.dev1lab.OptionGraphicsItemData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionGraphicsItemData)
:app.dev1lab.OptionGraphicsItemData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionGraphicsItemData)
```

## `app.dev1lab.OptionItemData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GameId` | `app.dev1lab.GameOption.ID` |  | 16 |
| `CategoryId` | `app.dev1lab.OptionCategory.ID` |  | 20 |
| `ItemMessage` | `app.dev1lab.OptionItemData.OptionMessage` |  | 24 |
| `OptionSelectType` | `app.dev1lab.OptionItemData.SelectType` |  | 32 |
| `SelectMessage` | `System.Collections.Generic.List`1<app.dev1lab.OptionItemData.OptionMessage>` |  | 40 |
| `DefaultParam` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.String get_DisplayName()
```

## `app.dev1lab.OptionItemData.OptionMessage`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NameId` | `System.Guid` |  | 16 |
| `NameStr` | `System.String` |  | 32 |
| `DescId` | `System.Guid` |  | 40 |
| `DescStr` | `System.String` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_MessageDisplayName()
```

## `app.dev1lab.OptionItemData.OptionMessage[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionItemData.OptionMessage)
:app.dev1lab.OptionItemData.OptionMessage Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionItemData.OptionMessage)
:System.Void CopyTo(app.dev1lab.OptionItemData.OptionMessage[], System.Int32)
:app.dev1lab.OptionItemData.OptionMessage Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionItemData.OptionMessage> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionItemData.OptionMessage)
:System.Void Insert(System.Int32, app.dev1lab.OptionItemData.OptionMessage)
:System.Boolean Remove(app.dev1lab.OptionItemData.OptionMessage)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionItemData.OptionMessage)
:app.dev1lab.OptionItemData.OptionMessage get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionItemData.OptionMessage)
```

## `app.dev1lab.OptionItemData.SelectType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Custom` | `app.dev1lab.OptionItemData.SelectType` | yes | 16 |
| `OnOff` | `app.dev1lab.OptionItemData.SelectType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.OptionItemData.SelectType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionItemData.SelectType)
:app.dev1lab.OptionItemData.SelectType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionItemData.SelectType)
:System.Void CopyTo(app.dev1lab.OptionItemData.SelectType[], System.Int32)
:app.dev1lab.OptionItemData.SelectType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionItemData.SelectType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionItemData.SelectType)
:System.Void Insert(System.Int32, app.dev1lab.OptionItemData.SelectType)
:System.Boolean Remove(app.dev1lab.OptionItemData.SelectType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionItemData.SelectType)
:app.dev1lab.OptionItemData.SelectType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionItemData.SelectType)
```

## `app.dev1lab.OptionItemData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionItemData)
:app.dev1lab.OptionItemData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionItemData)
:System.Void CopyTo(app.dev1lab.OptionItemData[], System.Int32)
:app.dev1lab.OptionItemData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionItemData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionItemData)
:System.Void Insert(System.Int32, app.dev1lab.OptionItemData)
:System.Boolean Remove(app.dev1lab.OptionItemData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionItemData)
:app.dev1lab.OptionItemData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionItemData)
```

## `app.dev1lab.OptionList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `selectIndex` | `System.Int32` |  | 16 |
| `items` | `System.Collections.Generic.List`1<app.dev1lab.OptionListItem>` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addItem(app.dev1lab.OptionListItem)
:System.Void clear()
:System.Collections.Generic.List`1<app.dev1lab.OptionListItem> get_Items()
:System.Int32 get_SelectIndex()
:System.Void replaceItem(app.dev1lab.OptionListItem, System.Int32)
:System.Void restoreValue()
:System.Void setActive(System.Int32)
:System.Void set_SelectIndex(System.Int32)
```

## `app.dev1lab.OptionListItem`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ItemID>k__BackingField` | `System.Int32` |  | 16 |
| `<IsActive>k__BackingField` | `System.Boolean` |  | 20 |
| `<LabelMessage>k__BackingField` | `System.String` |  | 24 |
| `<DescMessage>k__BackingField` | `System.String` |  | 32 |
| `selectIndex` | `System.Int32` |  | 40 |
| `indexNo` | `System.Int32` |  | 44 |
| `isLoop` | `System.Boolean` |  | 48 |
| `isUnlock` | `System.Boolean` |  | 49 |
| `isSelectable` | `System.Boolean` |  | 50 |
| `selectDataList` | `System.Collections.Generic.List`1<app.dev1lab.OptionListItem.SelectData>` |  | 56 |
| `valueItem` | `app.dev1lab.OptionValueItem` |  | 64 |
| `selectIndexEventHandler` | `app.dev1lab.OptionListItem.SelectIndexEventHandler` |  | 72 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.String, System.String, System.Boolean, System.Boolean, System.Boolean, app.dev1lab.OptionListItem.SelectIndexEventHandler)
:System.Void addItem(app.dev1lab.OptionListItem.SelectData)
:System.Void attachValueItem(app.dev1lab.OptionValueItem)
:System.Void callApply(System.Int32)
:System.Int32 getSelectValue()
:System.String get_DescMessage()
:System.Int32 get_IndexNo()
:System.Boolean get_IsActive()
:System.Boolean get_IsCanSelect()
:System.Boolean get_IsLoop()
:System.Boolean get_IsUnlock()
:System.Int32 get_ItemID()
:System.String get_LabelMessage()
:System.Collections.Generic.List`1<app.dev1lab.OptionListItem.SelectData> get_SelectDataList()
:System.Int32 get_SelectIndex()
:app.dev1lab.OptionValueItem get_ValueItem()
:System.Boolean isChangeValue()
:System.Void restoreValue()
:System.Boolean selectItemFromValue(System.Int32)
:System.Void set_DescMessage(System.String)
:System.Void set_IndexNo(System.Int32)
:System.Void set_IsActive(System.Boolean)
:System.Void set_IsCanSelect(System.Boolean)
:System.Void set_IsLoop(System.Boolean)
:System.Void set_IsUnlock(System.Boolean)
:System.Void set_ItemID(System.Int32)
:System.Void set_LabelMessage(System.String)
:System.Void set_SelectIndex(System.Int32)
```

## `app.dev1lab.OptionListItem.SelectData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<LabelMessage>k__BackingField` | `System.String` |  | 16 |
| `<DescMessage>k__BackingField` | `System.String` |  | 24 |
| `<Value>k__BackingField` | `System.Int32` |  | 32 |
| `<LabelMessageFormat>k__BackingField` | `System.Func`2<System.String,System.String>` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.String, System.String, System.Int32)
:System.Void .ctor(System.String, System.String, System.Func`2<System.String,System.String>)
:System.String get_DescMessage()
:System.String get_LabelMessage()
:System.Func`2<System.String,System.String> get_LabelMessageFormat()
:System.Int32 get_Value()
:System.Void set_DescMessage(System.String)
:System.Void set_LabelMessage(System.String)
:System.Void set_LabelMessageFormat(System.Func`2<System.String,System.String>)
:System.Void set_Value(System.Int32)
```

## `app.dev1lab.OptionListItem.SelectData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionListItem.SelectData)
:app.dev1lab.OptionListItem.SelectData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionListItem.SelectData)
:System.Void CopyTo(app.dev1lab.OptionListItem.SelectData[], System.Int32)
:app.dev1lab.OptionListItem.SelectData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionListItem.SelectData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionListItem.SelectData)
:System.Void Insert(System.Int32, app.dev1lab.OptionListItem.SelectData)
:System.Boolean Remove(app.dev1lab.OptionListItem.SelectData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionListItem.SelectData)
:app.dev1lab.OptionListItem.SelectData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionListItem.SelectData)
```

## `app.dev1lab.OptionListItem.SelectIndexEventHandler`

**Methods**

```lua
:System.Void Invoke(System.Int32)
```

## `app.dev1lab.OptionListItem[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionListItem)
:app.dev1lab.OptionListItem Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionListItem)
:System.Void CopyTo(app.dev1lab.OptionListItem[], System.Int32)
:app.dev1lab.OptionListItem Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionListItem> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionListItem)
:System.Void Insert(System.Int32, app.dev1lab.OptionListItem)
:System.Boolean Remove(app.dev1lab.OptionListItem)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionListItem)
:app.dev1lab.OptionListItem get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionListItem)
```

## `app.dev1lab.OptionTitleData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CategoryId` | `app.dev1lab.OptionCategory.ID` |  | 16 |
| `TitleMessage` | `app.dev1lab.OptionTitleData.OptionMessage` |  | 24 |

**Methods**

```lua
:System.String get_DisplayName()
```

## `app.dev1lab.OptionTitleData.OptionMessage`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NameId` | `System.Guid` |  | 16 |
| `NameStr` | `System.String` |  | 32 |
| `DescId` | `System.Guid` |  | 40 |
| `DescStr` | `System.String` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_MessageDisplayName()
```

## `app.dev1lab.OptionTitleData[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionTitleData)
:app.dev1lab.OptionTitleData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionTitleData)
:System.Void CopyTo(app.dev1lab.OptionTitleData[], System.Int32)
:app.dev1lab.OptionTitleData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionTitleData> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionTitleData)
:System.Void Insert(System.Int32, app.dev1lab.OptionTitleData)
:System.Boolean Remove(app.dev1lab.OptionTitleData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionTitleData)
:app.dev1lab.OptionTitleData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionTitleData)
```

## `app.dev1lab.OptionUIBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Param>k__BackingField` | `app.dev1lab.OptionUIParamSetup` |  | 80 |
| `<Controller>k__BackingField` | `via.gui.GUIController` |  | 88 |
| `<MenuList>k__BackingField` | `via.gui.SimpleList` |  | 96 |
| `<ContentList>k__BackingField` | `via.gui.ScrollList` |  | 104 |
| `<ContentPanel>k__BackingField` | `via.gui.Panel` |  | 112 |
| `<ResultPanel>k__BackingField` | `via.gui.Panel` |  | 120 |
| `<MaskRect>k__BackingField` | `via.gui.Rect` |  | 128 |
| `<ContentBar>k__BackingField` | `via.gui.ScrollBar` |  | 136 |
| `<ContentBarBgLong>k__BackingField` | `via.gui.TextureSet` |  | 144 |
| `<ContentBarBgShort>k__BackingField` | `via.gui.TextureSet` |  | 152 |
| `<GaugePanel>k__BackingField` | `System.Collections.Generic.List`1<via.gui.Panel>` |  | 160 |
| `<CheckPanel>k__BackingField` | `System.Collections.Generic.List`1<via.gui.Panel>` |  | 168 |
| `<MemoryPanel>k__BackingField` | `via.gui.Panel` |  | 176 |
| `<MemoryText>k__BackingField` | `via.gui.Text` |  | 184 |
| `<DialogPanel>k__BackingField` | `via.gui.Panel` |  | 192 |
| `<DialogCursorList>k__BackingField` | `via.gui.ScrollList` |  | 200 |
| `<DescriptionText>k__BackingField` | `via.gui.Text` |  | 208 |
| `<CallbackSelectEnd>k__BackingField` | `System.Action`1<System.Boolean>` |  | 216 |
| `<BakIndex>k__BackingField` | `System.Int32` |  | 224 |
| `<IsUpdatePage>k__BackingField` | `System.Boolean` |  | 228 |
| `_TitleUserData` | `app.dev1lab.OptionUITitleUserData` |  | 232 |
| `_ItemUserData` | `app.dev1lab.OptionUIItemUserData` |  | 240 |
| `_GraphicsItemUserData` | `app.dev1lab.OptionUIGraphicsItemUserData` |  | 248 |
| `_State` | `app.dev1lab.OptionUIBehavior.InputState` |  | 256 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean <updateMenu>b__102_0()
:System.Boolean <updateMenu>b__102_1()
:System.Boolean <updateMenu>b__102_2()
:System.Boolean <updateMenu>b__102_3()
:System.Boolean <updateMenu>b__102_4()
:System.Void awake()
:System.Void changeSelectIndex(System.Boolean)
:System.Boolean contentInputCheckEvent(via.gui.ListInputDirection)
:System.Void contentSelectionChanged()
:System.Void contentStateFinish(via.gui.Control)
:System.Boolean dialogInputCheckEvent(via.gui.ListInputDirection)
:System.Void dialogStateFinished(via.gui.Control)
:System.Int32 get_BakIndex()
:System.Action`1<System.Boolean> get_CallbackSelectEnd()
:System.Collections.Generic.List`1<via.gui.Panel> get_CheckPanel()
:via.gui.ScrollBar get_ContentBar()
:via.gui.TextureSet get_ContentBarBgLong()
:via.gui.TextureSet get_ContentBarBgShort()
:via.gui.ScrollList get_ContentList()
:via.gui.Panel get_ContentPanel()
:via.gui.GUIController get_Controller()
:via.gui.Text get_DescriptionText()
:via.gui.ScrollList get_DialogCursorList()
:via.gui.Panel get_DialogPanel()
:System.Collections.Generic.List`1<via.gui.Panel> get_GaugePanel()
:app.dev1lab.OptionUIGraphicsItemUserData get_GraphicsItemUserData()
:System.Boolean get_IsUpdatePage()
:app.dev1lab.OptionUIItemUserData get_ItemUserData()
:via.gui.Rect get_MaskRect()
:via.gui.Panel get_MemoryPanel()
:via.gui.Text get_MemoryText()
:via.gui.SimpleList get_MenuList()
:app.dev1lab.OptionUIParamSetup get_Param()
:via.gui.Panel get_ResultPanel()
:app.dev1lab.OptionUIBehavior.InputState get_State()
:app.dev1lab.OptionUITitleUserData get_TitleUserData()
:System.Void menuSelectionChanged()
:System.Void openDialog(System.String, System.String, System.Action`1<System.Boolean>)
:System.Void set_BakIndex(System.Int32)
:System.Void set_CallbackSelectEnd(System.Action`1<System.Boolean>)
:System.Void set_CheckPanel(System.Collections.Generic.List`1<via.gui.Panel>)
:System.Void set_ContentBar(via.gui.ScrollBar)
:System.Void set_ContentBarBgLong(via.gui.TextureSet)
:System.Void set_ContentBarBgShort(via.gui.TextureSet)
:System.Void set_ContentList(via.gui.ScrollList)
:System.Void set_ContentPanel(via.gui.Panel)
:System.Void set_Controller(via.gui.GUIController)
:System.Void set_DescriptionText(via.gui.Text)
:System.Void set_DialogCursorList(via.gui.ScrollList)
:System.Void set_DialogPanel(via.gui.Panel)
:System.Void set_GaugePanel(System.Collections.Generic.List`1<via.gui.Panel>)
:System.Void set_GraphicsItemUserData(app.dev1lab.OptionUIGraphicsItemUserData)
:System.Void set_IsUpdatePage(System.Boolean)
:System.Void set_ItemUserData(app.dev1lab.OptionUIItemUserData)
:System.Void set_MaskRect(via.gui.Rect)
:System.Void set_MemoryPanel(via.gui.Panel)
:System.Void set_MemoryText(via.gui.Text)
:System.Void set_MenuList(via.gui.SimpleList)
:System.Void set_Param(app.dev1lab.OptionUIParamSetup)
:System.Void set_ResultPanel(via.gui.Panel)
:System.Void set_State(app.dev1lab.OptionUIBehavior.InputState)
:System.Void set_TitleUserData(app.dev1lab.OptionUITitleUserData)
:System.Void start()
:System.Void update()
:System.Void updateContent()
:System.Void updateMenu(System.Boolean)
```

## `app.dev1lab.OptionUIBehavior.InputState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ContentMode` | `app.dev1lab.OptionUIBehavior.InputState` | yes | 16 |
| `DialogMode` | `app.dev1lab.OptionUIBehavior.InputState` | yes | 16 |
| `MenuMode` | `app.dev1lab.OptionUIBehavior.InputState` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.OptionUIBehavior.InputState[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionUIBehavior.InputState)
:app.dev1lab.OptionUIBehavior.InputState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionUIBehavior.InputState)
:System.Void CopyTo(app.dev1lab.OptionUIBehavior.InputState[], System.Int32)
:app.dev1lab.OptionUIBehavior.InputState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionUIBehavior.InputState> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionUIBehavior.InputState)
:System.Void Insert(System.Int32, app.dev1lab.OptionUIBehavior.InputState)
:System.Boolean Remove(app.dev1lab.OptionUIBehavior.InputState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionUIBehavior.InputState)
:app.dev1lab.OptionUIBehavior.InputState get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionUIBehavior.InputState)
```

## `app.dev1lab.OptionUIBehavior.ResultType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Effect` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `Image` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `Light` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `Memory` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `Model` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `Process` | `app.dev1lab.OptionUIBehavior.ResultType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.OptionUIBehavior.ResultType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionUIBehavior.ResultType)
:app.dev1lab.OptionUIBehavior.ResultType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionUIBehavior.ResultType)
:System.Void CopyTo(app.dev1lab.OptionUIBehavior.ResultType[], System.Int32)
:app.dev1lab.OptionUIBehavior.ResultType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionUIBehavior.ResultType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionUIBehavior.ResultType)
:System.Void Insert(System.Int32, app.dev1lab.OptionUIBehavior.ResultType)
:System.Boolean Remove(app.dev1lab.OptionUIBehavior.ResultType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionUIBehavior.ResultType)
:app.dev1lab.OptionUIBehavior.ResultType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionUIBehavior.ResultType)
```

## `app.dev1lab.OptionUIGraphicsItemUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GraphicsOptionItemList` | `System.Collections.Generic.List`1<app.dev1lab.OptionGraphicsItemData>` |  | 32 |

## `app.dev1lab.OptionUIItemUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OptionItemList` | `System.Collections.Generic.List`1<app.dev1lab.OptionItemData>` |  | 32 |

## `app.dev1lab.OptionUIParamSetup`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<OptionList>k__BackingField` | `app.dev1lab.OptionList` |  | 16 |
| `GraphicsManager` | `app.dev1lab.TitleGraphicsOptionManager` |  | 24 |
| `GameManager` | `app.dev1lab.GameOptionManager` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean addItem(app.dev1lab.OptionUIGraphicsItemUserData, app.dev1lab.GraphicsOption.ID, System.Int32[], System.Boolean)
:System.Boolean addItem(app.dev1lab.OptionUIItemUserData, app.dev1lab.GameOption.ID, System.Int32[], System.Boolean)
:System.Boolean addItemRefreshRate(app.dev1lab.OptionUIGraphicsItemUserData)
:System.Boolean addItemResolution(app.dev1lab.OptionUIGraphicsItemUserData, System.Int32)
:System.Void applySettings()
:System.Boolean createAudioPage(app.dev1lab.OptionUIItemUserData)
:System.Boolean createControllerPage(app.dev1lab.OptionUIItemUserData)
:System.Boolean createGamePage(app.dev1lab.OptionUIItemUserData)
:System.Boolean createGraphicsPage(app.dev1lab.OptionUIGraphicsItemUserData)
:System.Boolean createLanguagePage(app.dev1lab.OptionUIItemUserData)
:System.String getMessage(System.Guid)
:System.Void getOptionManager()
:app.dev1lab.OptionList get_OptionList()
:System.Void set_OptionList(app.dev1lab.OptionList)
:System.Void updateRefreashRateList(System.Int32, System.Int32)
```

## `app.dev1lab.OptionUITitleUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OptionTitleList` | `System.Collections.Generic.List`1<app.dev1lab.OptionTitleData>` |  | 32 |

## `app.dev1lab.OptionValueItem`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `LoadSavedValue` | `System.Int32` | yes | 16 |
| `NORM_VAL` | `System.Single` | yes | 16 |
| `defaultValue` | `System.Int32` |  | 16 |
| `nowValue` | `System.Int32` |  | 20 |
| `beforeValue` | `System.Int32` |  | 24 |
| `onApply` | `app.dev1lab.onOptionApply` |  | 32 |
| `onValueChange` | `app.dev1lab.onOptionValueChange` |  | 40 |
| `onDecide` | `app.dev1lab.onOptionDecide` |  | 48 |
| `onCheck` | `app.dev1lab.onCheckValue` |  | 56 |

**Methods**

```lua
:System.Void callApply(System.Int32)
:System.Boolean callCheck(System.Int32)
:System.Void callDecide(System.Int32)
:System.Void callValueChange(System.Int32)
:System.Void finalize()
:System.Int32 getStoredValue()
:System.Int32 get_DefaultValue()
:System.Int32 get_Value()
:System.Boolean isChangeValue()
:System.Void restoreValue()
:System.Void setApply(app.dev1lab.onOptionApply)
:System.Void setCheckValue(app.dev1lab.onCheckValue)
:System.Void setDecide(app.dev1lab.onOptionDecide)
:System.Void setDefault()
:System.Void setValueChange(app.dev1lab.onOptionValueChange)
:System.Void set_DefaultValue(System.Int32)
:System.Void set_Value(System.Int32)
:System.Void storeValue()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "DENORMALIZE_INT_TO_FLOAT", ...)  -- System.Single DENORMALIZE_INT_TO_FLOAT(System.Int32)
sdk.call_native_func(nil, type_def, "NORMALIZE_FLOAT_TO_INT", ...)  -- System.Int32 NORMALIZE_FLOAT_TO_INT(System.Single)
```

## `app.dev1lab.OptionValueItem[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.OptionValueItem)
:app.dev1lab.OptionValueItem Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.OptionValueItem)
:System.Void CopyTo(app.dev1lab.OptionValueItem[], System.Int32)
:app.dev1lab.OptionValueItem Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.OptionValueItem> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.OptionValueItem)
:System.Void Insert(System.Int32, app.dev1lab.OptionValueItem)
:System.Boolean Remove(app.dev1lab.OptionValueItem)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.OptionValueItem)
:app.dev1lab.OptionValueItem get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.OptionValueItem)
```

## `app.dev1lab.RuntimeEnvironment`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_isDefault", ...)  -- System.Boolean get_isDefault()
sdk.call_native_func(nil, type_def, "get_isPC", ...)  -- System.Boolean get_isPC()
sdk.call_native_func(nil, type_def, "get_isPC_Lamm", ...)  -- System.Boolean get_isPC_Lamm()
sdk.call_native_func(nil, type_def, "get_isPC_Steam", ...)  -- System.Boolean get_isPC_Steam()
sdk.call_native_func(nil, type_def, "get_isPC_SteamDeck", ...)  -- System.Boolean get_isPC_SteamDeck()
sdk.call_native_func(nil, type_def, "get_isPC_UWP", ...)  -- System.Boolean get_isPC_UWP()
sdk.call_native_func(nil, type_def, "get_isPC_WeGame", ...)  -- System.Boolean get_isPC_WeGame()
sdk.call_native_func(nil, type_def, "get_isPS4", ...)  -- System.Boolean get_isPS4()
sdk.call_native_func(nil, type_def, "get_isPS4_Base", ...)  -- System.Boolean get_isPS4_Base()
sdk.call_native_func(nil, type_def, "get_isPS4_Pro", ...)  -- System.Boolean get_isPS4_Pro()
sdk.call_native_func(nil, type_def, "get_isPS5", ...)  -- System.Boolean get_isPS5()
sdk.call_native_func(nil, type_def, "get_isPackage", ...)  -- System.Boolean get_isPackage()
sdk.call_native_func(nil, type_def, "get_isPlayStation", ...)  -- System.Boolean get_isPlayStation()
sdk.call_native_func(nil, type_def, "get_isStadia", ...)  -- System.Boolean get_isStadia()
sdk.call_native_func(nil, type_def, "get_isWindows10", ...)  -- System.Boolean get_isWindows10()
sdk.call_native_func(nil, type_def, "get_isXbox", ...)  -- System.Boolean get_isXbox()
sdk.call_native_func(nil, type_def, "get_isXboxOne", ...)  -- System.Boolean get_isXboxOne()
sdk.call_native_func(nil, type_def, "get_isXboxOneOnly", ...)  -- System.Boolean get_isXboxOneOnly()
sdk.call_native_func(nil, type_def, "get_isXboxOne_X", ...)  -- System.Boolean get_isXboxOne_X()
sdk.call_native_func(nil, type_def, "get_isXboxSS", ...)  -- System.Boolean get_isXboxSS()
sdk.call_native_func(nil, type_def, "get_isXboxSX", ...)  -- System.Boolean get_isXboxSX()
sdk.call_native_func(nil, type_def, "get_isXboxScarlet", ...)  -- System.Boolean get_isXboxScarlet()
sdk.call_native_func(nil, type_def, "get_targetMachine", ...)  -- System.UInt32 get_targetMachine()
sdk.call_native_func(nil, type_def, "get_targetMachineDetail", ...)  -- System.UInt32 get_targetMachineDetail()
sdk.call_native_func(nil, type_def, "get_targetOS", ...)  -- System.UInt32 get_targetOS()
sdk.call_native_func(nil, type_def, "get_targetServicePlatform", ...)  -- System.UInt32 get_targetServicePlatform()
sdk.call_native_func(nil, type_def, "isTargetMachine", ...)  -- System.Boolean isTargetMachine(via.Application.RuntimeTargetType)
sdk.call_native_func(nil, type_def, "isTargetMachineDetail", ...)  -- System.Boolean isTargetMachineDetail(via.Application.RuntimeTargetType)
sdk.call_native_func(nil, type_def, "isTargetOS", ...)  -- System.Boolean isTargetOS(via.Application.RuntimeTargetType)
sdk.call_native_func(nil, type_def, "isTargetServicePlatform", ...)  -- System.Boolean isTargetServicePlatform(via.Application.RuntimeTargetType)
```

## `app.dev1lab.SliderConfig`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Min` | `System.Single` |  | 16 |
| `_Max` | `System.Single` |  | 20 |
| `_Step` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single, System.Int32)
:System.Single getDelta()
:System.Single get_Max()
:System.Single get_Min()
:System.Int32 get_Step()
:System.Void set_Max(System.Single)
:System.Void set_Min(System.Single)
:System.Void set_Step(System.Int32)
```

## `app.dev1lab.StartupTestBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<runtimeArgs>k__BackingField` | `app.dev1lab.TitleRuntimeArgument` | yes | 80 |
| `<regionRecognizer>k__BackingField` | `app.dev1lab.TitleRegionRecognizer` | yes | 88 |

**Methods**

```lua
:System.Void doTest()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_regionRecognizer", ...)  -- app.dev1lab.TitleRegionRecognizer get_regionRecognizer()
sdk.call_native_func(nil, type_def, "get_runtimeArgs", ...)  -- app.dev1lab.TitleRuntimeArgument get_runtimeArgs()
sdk.call_native_func(nil, type_def, "set_regionRecognizer", ...)  -- System.Void set_regionRecognizer(app.dev1lab.TitleRegionRecognizer)
sdk.call_native_func(nil, type_def, "set_runtimeArgs", ...)  -- System.Void set_runtimeArgs(app.dev1lab.TitleRuntimeArgument)
```

## `app.dev1lab.TitleGraphicsOptionControllerForPC`

**Methods**

```lua
:System.Void .ctor()
:System.Void setTextureQuality(app.dev1lab.GraphicsOption.TextureQualityType)
```

## `app.dev1lab.TitleGraphicsOptionManager`

**Methods**

```lua
:System.Boolean checkValueTextureQualitySetting(System.Int32)
:app.dev1lab.CommonGraphicsOptionController createController()
```

## `app.dev1lab.TitleGraphicsOptionManagerHolder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Core` | `app.dev1lab.TitleGraphicsOptionManager` |  | 80 |
| `_SettingAsset` | `app.dev1lab.CommonGraphicsOptionUserData` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:app.dev1lab.TitleGraphicsOptionManager get_Core()
:app.dev1lab.CommonGraphicsOptionUserData get_SettingAsset()
:System.Void onDestroy()
:System.Void set_SettingAsset(app.dev1lab.CommonGraphicsOptionUserData)
```

## `app.dev1lab.TitleLocalSaveIO`

_No fields or methods._

## `app.dev1lab.TitleLocalSaveIO.TitleSaveDescription`

**Methods**

```lua
:System.Void .ctor(System.String, System.String, System.String, System.Boolean)
:System.String getPostFix()
```

## `app.dev1lab.TitleLocalSaveIO.TitleSaveDescription[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:app.dev1lab.TitleLocalSaveIO.TitleSaveDescription Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:System.Void CopyTo(app.dev1lab.TitleLocalSaveIO.TitleSaveDescription[], System.Int32)
:app.dev1lab.TitleLocalSaveIO.TitleSaveDescription Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.TitleLocalSaveIO.TitleSaveDescription> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:System.Void Insert(System.Int32, app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:System.Boolean Remove(app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
:app.dev1lab.TitleLocalSaveIO.TitleSaveDescription get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.TitleLocalSaveIO.TitleSaveDescription)
```

## `app.dev1lab.TitleRegionRecognizer`

**Methods**

```lua
:System.Void captureRegionByPlatform()
:System.Boolean captureRegionByRuntimeArgument(System.String)
:app.dev1lab.TitleRegionRecognizer.AppExtraRegionType get_AppExtraRegion()
:System.Boolean get_isGCAMRegion()
:System.Void set_AppExtraRegion(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
```

## `app.dev1lab.TitleRegionRecognizer.AppExtraRegionType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `German` | `app.dev1lab.TitleRegionRecognizer.AppExtraRegionType` | yes | 16 |
| `ME` | `app.dev1lab.TitleRegionRecognizer.AppExtraRegionType` | yes | 16 |
| `Unknown` | `app.dev1lab.TitleRegionRecognizer.AppExtraRegionType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.TitleRegionRecognizer.AppExtraRegionType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:app.dev1lab.TitleRegionRecognizer.AppExtraRegionType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:System.Void CopyTo(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType[], System.Int32)
:app.dev1lab.TitleRegionRecognizer.AppExtraRegionType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.TitleRegionRecognizer.AppExtraRegionType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:System.Void Insert(System.Int32, app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:System.Boolean Remove(app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
:app.dev1lab.TitleRegionRecognizer.AppExtraRegionType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.TitleRegionRecognizer.AppExtraRegionType)
```

## `app.dev1lab.TitleRegionRecognizer.AppRegionType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Asia` | `app.dev1lab.TitleRegionRecognizer.AppRegionType` | yes | 16 |
| `Europe` | `app.dev1lab.TitleRegionRecognizer.AppRegionType` | yes | 16 |
| `Japan` | `app.dev1lab.TitleRegionRecognizer.AppRegionType` | yes | 16 |
| `USA` | `app.dev1lab.TitleRegionRecognizer.AppRegionType` | yes | 16 |
| `Unknown` | `app.dev1lab.TitleRegionRecognizer.AppRegionType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.dev1lab.TitleRegionRecognizer.AppRegionType[]`

**Methods**

```lua
:System.Void Add(app.dev1lab.TitleRegionRecognizer.AppRegionType)
:app.dev1lab.TitleRegionRecognizer.AppRegionType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.dev1lab.TitleRegionRecognizer.AppRegionType)
:System.Void CopyTo(app.dev1lab.TitleRegionRecognizer.AppRegionType[], System.Int32)
:app.dev1lab.TitleRegionRecognizer.AppRegionType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.dev1lab.TitleRegionRecognizer.AppRegionType> GetEnumerator()
:System.Int32 IndexOf(app.dev1lab.TitleRegionRecognizer.AppRegionType)
:System.Void Insert(System.Int32, app.dev1lab.TitleRegionRecognizer.AppRegionType)
:System.Boolean Remove(app.dev1lab.TitleRegionRecognizer.AppRegionType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.dev1lab.TitleRegionRecognizer.AppRegionType)
:app.dev1lab.TitleRegionRecognizer.AppRegionType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.dev1lab.TitleRegionRecognizer.AppRegionType)
```

## `app.dev1lab.TitleRuntimeArgument`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ArgWidget` | `System.String` | yes | 16 |
| `ArgDip` | `System.String` | yes | 24 |
| `ArgVer` | `System.String` | yes | 32 |
| `ArgRegion` | `System.String` | yes | 40 |

**Methods**

```lua
:System.Void updateUnitList(System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>, app.dev1lab.CommonRuntimeArgument.Unit)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.dev1lab.onCheckValue`

**Methods**

```lua
:System.Boolean Invoke(System.Int32)
```

## `app.dev1lab.onOptionApply`

**Methods**

```lua
:System.Void Invoke(System.Int32)
```

## `app.dev1lab.onOptionDecide`

**Methods**

```lua
:System.Void Invoke(System.Int32)
```

## `app.dev1lab.onOptionValueChange`

**Methods**

```lua
:System.Void Invoke(System.Int32)
```

## `app.facial.Damper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Order>k__BackingField` | `System.Nullable`1<System.Int32>` |  | 16 |
| `<RegisterParam>k__BackingField` | `app.facial.Damper.Parameter` |  | 24 |
| `_Param` | `app.facial.Damper.Parameter` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Single getRate(System.Single)
:System.Nullable`1<System.Int32> get_Order()
:app.facial.Damper.Parameter get_RegisterParam()
:System.Void registerParameter(app.facial.Damper.Parameter, System.Int32)
:System.Void setParameter(System.Single, System.Single)
:System.Void setParameter(app.facial.Damper.Parameter)
:System.Void setParameterRef(app.facial.Damper.Parameter)
:System.Void set_Order(System.Nullable`1<System.Int32>)
:System.Void set_RegisterParam(app.facial.Damper.Parameter)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getRate", ...)  -- System.Single getRate(System.Single, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "getRate", ...)  -- System.Single getRate(app.facial.Damper.Parameter, System.Single)
```

## `app.facial.Damper.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Rate` | `System.Single` |  | 16 |
| `_Time` | `System.Single` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Void copy(app.facial.Damper.Parameter)
:System.Single get_Rate()
:System.Single get_Time()
:System.Void set_Rate(System.Single)
:System.Void set_Time(System.Single)
```

## `app.facial.Eyelid`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<BlinkPairArray>k__BackingField` | `app.facial.Eyelid.BlinkPair[]` |  | 48 |
| `<Interface>k__BackingField` | `app.facial.IEyelid` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.GameObject, app.facial.Eyelid.Parameter)
:app.facial.Eyelid.BlinkPair[] get_BlinkPairArray()
:app.facial.IEyelid get_Interface()
:System.Single get_Rate()
:System.Void lateUpdateInherit()
:System.Void set_BlinkPairArray(app.facial.Eyelid.BlinkPair[])
:System.Void set_Interface(app.facial.IEyelid)
```

## `app.facial.Eyelid.BlinkPair`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Enabled>k__BackingField` | `System.Boolean` |  | 16 |
| `<MoveJoint>k__BackingField` | `via.Joint` |  | 24 |
| `<TargetLocalPosition>k__BackingField` | `via.vec3` |  | 32 |
| `<TargetLocalRotation>k__BackingField` | `via.Quaternion` |  | 48 |
| `<BaseJoint>k__BackingField` | `via.Joint` |  | 64 |
| `<OffsetPosition>k__BackingField` | `via.vec3` |  | 80 |
| `<OffsetRotation>k__BackingField` | `via.Quaternion` |  | 96 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.GameObject, app.facial.Eyelid.BlinkPair.Parameter)
:via.Joint get_BaseJoint()
:System.String get_BaseJointName()
:System.Boolean get_Enabled()
:System.Boolean get_EnabledBaseJoint()
:via.Joint get_MoveJoint()
:System.String get_MoveJointName()
:via.vec3 get_OffsetPosition()
:via.Quaternion get_OffsetRotation()
:via.vec3 get_TargetLocalPosition()
:via.Quaternion get_TargetLocalRotation()
:System.Void set_BaseJoint(via.Joint)
:System.Void set_Enabled(System.Boolean)
:System.Void set_MoveJoint(via.Joint)
:System.Void set_OffsetPosition(via.vec3)
:System.Void set_OffsetRotation(via.Quaternion)
:System.Void set_TargetLocalPosition(via.vec3)
:System.Void set_TargetLocalRotation(via.Quaternion)
:System.Void update(System.Single)
```

## `app.facial.Eyelid.BlinkPair.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Enabled` | `System.Boolean` |  | 16 |
| `_MoveJointName` | `System.String` |  | 24 |
| `_TargetLocalPosition` | `via.vec3` |  | 32 |
| `_TargetLocalRotation` | `via.Quaternion` |  | 48 |
| `_BaseJointName` | `System.String` |  | 64 |
| `_OffsetPosition` | `via.vec3` |  | 80 |
| `_OffsetRotation` | `via.Quaternion` |  | 96 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String, System.String)
:System.Void calculate(via.GameObject)
:System.String get_BaseJointName()
:System.String get_DisplayName()
:System.Boolean get_Enabled()
:System.String get_MoveJointName()
:via.vec3 get_OffsetPosition()
:via.Quaternion get_OffsetRotation()
:via.vec3 get_TargetLocalPosition()
:via.Quaternion get_TargetLocalRotation()
:System.Boolean get_Valid()
```

## `app.facial.Eyelid.BlinkPair.Parameter[]`

**Methods**

```lua
:System.Void Add(app.facial.Eyelid.BlinkPair.Parameter)
:app.facial.Eyelid.BlinkPair.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.Eyelid.BlinkPair.Parameter)
:System.Void CopyTo(app.facial.Eyelid.BlinkPair.Parameter[], System.Int32)
:app.facial.Eyelid.BlinkPair.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.Eyelid.BlinkPair.Parameter> GetEnumerator()
:System.Int32 IndexOf(app.facial.Eyelid.BlinkPair.Parameter)
:System.Void Insert(System.Int32, app.facial.Eyelid.BlinkPair.Parameter)
:System.Boolean Remove(app.facial.Eyelid.BlinkPair.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.Eyelid.BlinkPair.Parameter)
:app.facial.Eyelid.BlinkPair.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.Eyelid.BlinkPair.Parameter)
```

## `app.facial.Eyelid.BlinkPair[]`

**Methods**

```lua
:System.Void Add(app.facial.Eyelid.BlinkPair)
:app.facial.Eyelid.BlinkPair Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.Eyelid.BlinkPair)
:System.Void CopyTo(app.facial.Eyelid.BlinkPair[], System.Int32)
:app.facial.Eyelid.BlinkPair Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.Eyelid.BlinkPair> GetEnumerator()
:System.Int32 IndexOf(app.facial.Eyelid.BlinkPair)
:System.Void Insert(System.Int32, app.facial.Eyelid.BlinkPair)
:System.Boolean Remove(app.facial.Eyelid.BlinkPair)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.Eyelid.BlinkPair)
:app.facial.Eyelid.BlinkPair get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.Eyelid.BlinkPair)
```

## `app.facial.Eyelid.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BlinkPairParamArray` | `app.facial.Eyelid.BlinkPair.Parameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:app.facial.Module createModule(via.GameObject)
:app.facial.Eyelid.BlinkPair.Parameter[] get_BlinkPairParamArray()
```

## `app.facial.Facial`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DisplayOrder_Default` | `System.Int32` | yes | 80 |
| `DisplayOrder_Develop` | `System.Int32` | yes | 80 |
| `DisplayOrder_Settings` | `System.Int32` | yes | 80 |
| `DisplayOrder_Settings_ModuleParameter` | `System.Int32` | yes | 80 |
| `ModuleCapacity` | `System.Int32` | yes | 80 |
| `<Modules>k__BackingField` | `System.Collections.Generic.List`1<app.facial.Module>` |  | 80 |
| `<ElapsedSecond>k__BackingField` | `System.Single` |  | 88 |
| `_ParamArray` | `app.facial.Module.Parameter[]` |  | 96 |
| `<Motion>k__BackingField` | `via.motion.Motion` |  | 104 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addModule(app.facial.Module.Parameter)
:System.Void addModule(app.facial.Module)
:System.Void awake()
:System.Single get_ElapsedSecond()
:System.Collections.Generic.List`1<app.facial.Module> get_Modules()
:via.motion.Motion get_Motion()
:app.facial.Module.Parameter[] get_ParamArray()
:System.Void lateUpdate()
:System.Void set_ElapsedSecond(System.Single)
:System.Void set_Modules(System.Collections.Generic.List`1<app.facial.Module>)
:System.Void set_Motion(via.motion.Motion)
:System.Void start()
:System.Void update()
```

## `app.facial.FacialCamera`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NearClipPlane` | `System.Single` | yes | 80 |
| `<Target>k__BackingField` | `via.GameObject` |  | 80 |
| `<TargetJoint>k__BackingField` | `via.Joint` |  | 88 |
| `<Distance>k__BackingField` | `System.Single` |  | 96 |
| `<Pitch>k__BackingField` | `System.Single` |  | 100 |
| `<Yaw>k__BackingField` | `System.Single` |  | 104 |
| `_TargetRef` | `via.GameObjectRef` |  | 112 |
| `_TargetJointIndex` | `System.Int32` |  | 128 |
| `_TargetJointName` | `System.String` |  | 136 |
| `_TargetJointNames` | `System.String[]` |  | 144 |
| `<Camera>k__BackingField` | `via.Camera` |  | 152 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:via.Camera get_Camera()
:System.Single get_Distance()
:System.Single get_Pitch()
:via.GameObject get_Target()
:via.Joint get_TargetJoint()
:System.Int32 get_TargetJointIndex()
:System.String get_TargetJointName()
:via.GameObjectRef get_TargetRef()
:System.Single get_Yaw()
:System.Void lateUpdate()
:System.Void set_Camera(via.Camera)
:System.Void set_Distance(System.Single)
:System.Void set_Pitch(System.Single)
:System.Void set_Target(via.GameObject)
:System.Void set_TargetJoint(via.Joint)
:System.Void set_TargetJointIndex(System.Int32)
:System.Void set_TargetJointName(System.String)
:System.Void set_TargetRef(via.GameObjectRef)
:System.Void set_Yaw(System.Single)
:System.Void start()
```

## `app.facial.FloatDamper`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(System.Single, System.Single, System.Single)
:System.Void .ctor(System.Single, System.Single, System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Void .ctor(System.Single, app.facial.Damper.Parameter)
:System.Void .ctor(System.Single, System.Single, app.facial.Damper.Parameter)
:System.Void update(System.Single)
```

## `app.facial.FloatRangeDamper`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Range` | `via.Range` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, via.Range, System.Single, System.Single)
:System.Void .ctor(System.Single, System.Single, via.Range, System.Single, System.Single)
:System.Void .ctor(System.Single, via.Range, app.facial.Damper.Parameter)
:System.Void .ctor(System.Single, System.Single, via.Range, app.facial.Damper.Parameter)
:System.Single get_Current()
:System.Single get_Target()
:System.Void set_Current(System.Single)
:System.Void set_Target(System.Single)
:System.Void update(System.Single)
:System.Void update(System.Single, System.Boolean, System.Single)
```

## `app.facial.IEyelid`

_No fields or methods._

## `app.facial.ILipSync`

_No fields or methods._

## `app.facial.ILookAt`

_No fields or methods._

## `app.facial.LipSync`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Interface>k__BackingField` | `app.facial.ILipSync` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.GameObject, app.facial.LipSync.Parameter)
:System.UInt32 convertToMotionID(app.facial.VowelKind)
:System.UInt32 convertToMotionID(app.facial.VowelJPNKind)
:System.ValueTuple`2<System.UInt32,System.UInt32> getMotionData()
:app.facial.ILipSync get_Interface()
:System.Single get_Volume()
:app.facial.VowelKind get_Vowel()
:System.Void set_Interface(app.facial.ILipSync)
:System.Void updateInherit()
:System.Void updateMotion()
:System.Void updateVolume()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertToVowel", ...)  -- app.facial.VowelKind convertToVowel(app.facial.VowelJPNKind)
sdk.call_native_func(nil, type_def, "convertToVowelJPN", ...)  -- app.facial.VowelJPNKind convertToVowelJPN(app.facial.VowelKind)
```

## `app.facial.LipSync.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_VolumeDamperParam` | `app.facial.Damper.Parameter` |  | 48 |
| `_VowelMotionPlayDataArray` | `app.facial.LipSync.VowelMotionPlayData[]` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:app.facial.Module createModule(via.GameObject)
:app.facial.Damper.Parameter get_VolumeDamperParam()
:System.Collections.Generic.IReadOnlyList`1<app.facial.LipSync.VowelMotionPlayData> get_VowelMotionPlayDatas()
```

## `app.facial.LipSync.Sequence`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MediaID` | `System.UInt32` |  | 16 |
| `_KeyFrameArray` | `app.facial.LipSync.Sequence.KeyFrame[]` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.IReadOnlyList`1<app.facial.LipSync.Sequence.KeyFrame> get_KeyFrames()
:System.UInt32 get_MediaID()
```

## `app.facial.LipSync.Sequence.KeyFrame`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Time` | `System.Single` |  | 16 |
| `_VowelKind` | `app.facial.VowelKind` |  | 20 |

**Methods**

```lua
:System.Single get_Time()
:app.facial.VowelKind get_VowelKind()
```

## `app.facial.LipSync.Sequence.KeyFrame[]`

**Methods**

```lua
:System.Void Add(app.facial.LipSync.Sequence.KeyFrame)
:app.facial.LipSync.Sequence.KeyFrame Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LipSync.Sequence.KeyFrame)
:System.Void CopyTo(app.facial.LipSync.Sequence.KeyFrame[], System.Int32)
:app.facial.LipSync.Sequence.KeyFrame Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LipSync.Sequence.KeyFrame> GetEnumerator()
:System.Int32 IndexOf(app.facial.LipSync.Sequence.KeyFrame)
:System.Void Insert(System.Int32, app.facial.LipSync.Sequence.KeyFrame)
:System.Boolean Remove(app.facial.LipSync.Sequence.KeyFrame)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LipSync.Sequence.KeyFrame)
:app.facial.LipSync.Sequence.KeyFrame get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LipSync.Sequence.KeyFrame)
```

## `app.facial.LipSync.SequenceTableUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ElementArray` | `app.facial.LipSync.SequenceTableUserData.Element[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.IReadOnlyList`1<app.facial.LipSync.SequenceTableUserData.Element> get_Elements()
```

## `app.facial.LipSync.SequenceTableUserData.Element`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MediaID` | `System.Nullable`1<System.UInt32>` |  | 16 |
| `_UseUserData` | `System.Boolean` |  | 24 |
| `_UserData` | `app.facial.LipSync.SequenceUserData` |  | 32 |
| `_KeyFrameArray` | `app.facial.LipSync.Sequence.KeyFrame[]` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.IReadOnlyList`1<app.facial.LipSync.Sequence.KeyFrame> get_KeyFrames()
:System.UInt32 get_MediaID()
```

## `app.facial.LipSync.SequenceTableUserData.Element[]`

**Methods**

```lua
:System.Void Add(app.facial.LipSync.SequenceTableUserData.Element)
:app.facial.LipSync.SequenceTableUserData.Element Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LipSync.SequenceTableUserData.Element)
:System.Void CopyTo(app.facial.LipSync.SequenceTableUserData.Element[], System.Int32)
:app.facial.LipSync.SequenceTableUserData.Element Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LipSync.SequenceTableUserData.Element> GetEnumerator()
:System.Int32 IndexOf(app.facial.LipSync.SequenceTableUserData.Element)
:System.Void Insert(System.Int32, app.facial.LipSync.SequenceTableUserData.Element)
:System.Boolean Remove(app.facial.LipSync.SequenceTableUserData.Element)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LipSync.SequenceTableUserData.Element)
:app.facial.LipSync.SequenceTableUserData.Element get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LipSync.SequenceTableUserData.Element)
```

## `app.facial.LipSync.SequenceUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MediaID` | `System.UInt32` |  | 32 |
| `_KeyFrameArray` | `app.facial.LipSync.Sequence.KeyFrame[]` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.IReadOnlyList`1<app.facial.LipSync.Sequence.KeyFrame> get_KeyFrames()
:System.UInt32 get_MediaID()
```

## `app.facial.LipSync.VowelMotionPlayData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Vowel` | `app.facial.VowelKind` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(app.facial.VowelKind, System.Nullable`1<System.UInt32>, System.Nullable`1<System.UInt32>)
:System.String get_DisplayName()
:app.facial.VowelKind get_Vowel()
```

## `app.facial.LipSync.VowelMotionPlayData[]`

**Methods**

```lua
:System.Void Add(app.facial.LipSync.VowelMotionPlayData)
:app.facial.LipSync.VowelMotionPlayData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LipSync.VowelMotionPlayData)
:System.Void CopyTo(app.facial.LipSync.VowelMotionPlayData[], System.Int32)
:app.facial.LipSync.VowelMotionPlayData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LipSync.VowelMotionPlayData> GetEnumerator()
:System.Int32 IndexOf(app.facial.LipSync.VowelMotionPlayData)
:System.Void Insert(System.Int32, app.facial.LipSync.VowelMotionPlayData)
:System.Boolean Remove(app.facial.LipSync.VowelMotionPlayData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LipSync.VowelMotionPlayData)
:app.facial.LipSync.VowelMotionPlayData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LipSync.VowelMotionPlayData)
```

## `app.facial.LookAt`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Interface>k__BackingField` | `app.facial.ILookAt` |  | 48 |
| `<EyeArray>k__BackingField` | `app.facial.LookAt.Eye[]` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.GameObject, app.facial.LookAt.Parameter)
:app.facial.LookAt.Eye[] get_EyeArray()
:app.facial.ILookAt get_Interface()
:System.Nullable`1<via.vec3> get_LookAtPosition()
:System.Void lateUpdateInherit()
:System.Void set_EyeArray(app.facial.LookAt.Eye[])
:System.Void set_Interface(app.facial.ILookAt)
```

## `app.facial.LookAt.Eye`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 16 |
| `<Joint>k__BackingField` | `via.Joint` |  | 24 |
| `<Param>k__BackingField` | `app.facial.LookAt.Eye.Parameter` |  | 32 |

**Methods**

```lua
:System.Void .ctor(via.GameObject, app.facial.LookAt.Eye.Parameter)
:via.GameObject get_GameObject()
:via.Joint get_Joint()
:app.facial.LookAt.Eye.Parameter get_Param()
:System.Void lookAt(via.vec3)
:System.Void set_GameObject(via.GameObject)
:System.Void set_Joint(via.Joint)
:System.Void set_Param(app.facial.LookAt.Eye.Parameter)
```

## `app.facial.LookAt.Eye.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointName` | `System.String` |  | 16 |
| `_XRotationRange` | `via.Range` |  | 24 |
| `_YRotationlRange` | `via.Range` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:via.Range deg2rad(via.Range)
:System.String get_DisplayName()
:System.String get_JointName()
:via.Range get_XRotationRange()
:via.Range get_YRotationRange()
```

## `app.facial.LookAt.Eye.Parameter[]`

**Methods**

```lua
:System.Void Add(app.facial.LookAt.Eye.Parameter)
:app.facial.LookAt.Eye.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LookAt.Eye.Parameter)
:System.Void CopyTo(app.facial.LookAt.Eye.Parameter[], System.Int32)
:app.facial.LookAt.Eye.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LookAt.Eye.Parameter> GetEnumerator()
:System.Int32 IndexOf(app.facial.LookAt.Eye.Parameter)
:System.Void Insert(System.Int32, app.facial.LookAt.Eye.Parameter)
:System.Boolean Remove(app.facial.LookAt.Eye.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LookAt.Eye.Parameter)
:app.facial.LookAt.Eye.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LookAt.Eye.Parameter)
```

## `app.facial.LookAt.Eye.Util`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "clamp", ...)  -- via.vec3 clamp(via.vec3, via.Range, via.Range, app.facial.LookAt.Eye.Util.ClampType)
```

## `app.facial.LookAt.Eye.Util.ClampType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Ellipse` | `app.facial.LookAt.Eye.Util.ClampType` | yes | 16 |
| `Rectangle` | `app.facial.LookAt.Eye.Util.ClampType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.facial.LookAt.Eye.Util.ClampType[]`

**Methods**

```lua
:System.Void Add(app.facial.LookAt.Eye.Util.ClampType)
:app.facial.LookAt.Eye.Util.ClampType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LookAt.Eye.Util.ClampType)
:System.Void CopyTo(app.facial.LookAt.Eye.Util.ClampType[], System.Int32)
:app.facial.LookAt.Eye.Util.ClampType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LookAt.Eye.Util.ClampType> GetEnumerator()
:System.Int32 IndexOf(app.facial.LookAt.Eye.Util.ClampType)
:System.Void Insert(System.Int32, app.facial.LookAt.Eye.Util.ClampType)
:System.Boolean Remove(app.facial.LookAt.Eye.Util.ClampType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LookAt.Eye.Util.ClampType)
:app.facial.LookAt.Eye.Util.ClampType get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LookAt.Eye.Util.ClampType)
```

## `app.facial.LookAt.Eye[]`

**Methods**

```lua
:System.Void Add(app.facial.LookAt.Eye)
:app.facial.LookAt.Eye Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.LookAt.Eye)
:System.Void CopyTo(app.facial.LookAt.Eye[], System.Int32)
:app.facial.LookAt.Eye Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.LookAt.Eye> GetEnumerator()
:System.Int32 IndexOf(app.facial.LookAt.Eye)
:System.Void Insert(System.Int32, app.facial.LookAt.Eye)
:System.Boolean Remove(app.facial.LookAt.Eye)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.LookAt.Eye)
:app.facial.LookAt.Eye get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.LookAt.Eye)
```

## `app.facial.LookAt.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_EyeParamArray` | `app.facial.LookAt.Eye.Parameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:app.facial.Module createModule(via.GameObject)
:System.Collections.Generic.IReadOnlyList`1<app.facial.LookAt.Eye.Parameter> get_EyeParams()
```

## `app.facial.Mat4Damper`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(via.mat4, System.Single, System.Single)
:System.Void .ctor(via.mat4, via.mat4, System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Void .ctor(via.mat4, app.facial.Damper.Parameter)
:System.Void .ctor(via.mat4, via.mat4, app.facial.Damper.Parameter)
:System.Void update(System.Single)
:System.Void update(System.Single, System.Boolean)
```

## `app.facial.Module`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Order>k__BackingField` | `System.Int32` |  | 16 |
| `<ElapsedSecond>k__BackingField` | `System.Single` |  | 20 |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 24 |
| `<DisplayName>k__BackingField` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.GameObject, app.facial.Module.Parameter)
:System.String get_DisplayName()
:System.Single get_ElapsedSecond()
:via.GameObject get_GameObject()
:System.Int32 get_Order()
:System.Void lateUpdate()
:System.Void set_DisplayName(System.String)
:System.Void set_ElapsedSecond(System.Single)
:System.Void set_GameObject(via.GameObject)
:System.Void set_Order(System.Int32)
:System.Void update(System.Single)
```

## `app.facial.Module.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<DisplayName>k__BackingField` | `System.String` |  | 16 |
| `_Order` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_DisplayName()
:System.Int32 get_Order()
:System.Void set_DisplayName(System.String)
```

## `app.facial.Module.Parameter[]`

**Methods**

```lua
:System.Void Add(app.facial.Module.Parameter)
:app.facial.Module.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.Module.Parameter)
:System.Void CopyTo(app.facial.Module.Parameter[], System.Int32)
:app.facial.Module.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.Module.Parameter> GetEnumerator()
:System.Int32 IndexOf(app.facial.Module.Parameter)
:System.Void Insert(System.Int32, app.facial.Module.Parameter)
:System.Boolean Remove(app.facial.Module.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.Module.Parameter)
:app.facial.Module.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.Module.Parameter)
```

## `app.facial.Module[]`

**Methods**

```lua
:System.Void Add(app.facial.Module)
:app.facial.Module Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.Module)
:System.Void CopyTo(app.facial.Module[], System.Int32)
:app.facial.Module Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.Module> GetEnumerator()
:System.Int32 IndexOf(app.facial.Module)
:System.Void Insert(System.Int32, app.facial.Module)
:System.Boolean Remove(app.facial.Module)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.Module)
:app.facial.Module get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.Module)
```

## `app.facial.QuatDamper`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(via.Quaternion, System.Single, System.Single)
:System.Void .ctor(via.Quaternion, via.Quaternion, System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Void .ctor(via.Quaternion, app.facial.Damper.Parameter)
:System.Void .ctor(via.Quaternion, via.Quaternion, app.facial.Damper.Parameter)
:System.Void update(System.Single)
:System.Void update(System.Single, System.Boolean)
```

## `app.facial.Vec3Damper`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Single, System.Single)
:System.Void .ctor(via.vec3, System.Single, System.Single)
:System.Void .ctor(app.facial.Damper.Parameter)
:System.Void .ctor(via.vec3, app.facial.Damper.Parameter)
:System.Void .ctor(via.vec3, via.vec3, System.Single, System.Single)
:System.Void .ctor(via.vec3, via.vec3, app.facial.Damper.Parameter)
:via.vec3 polarLerp(via.vec3, via.vec3, System.Single, via.vec3)
:System.Void update(System.Single)
:System.Void update(System.Single, System.Boolean)
:System.Void update(System.Single, via.vec3)
:System.Void update(System.Single, via.vec3, via.vec3)
:System.Void update(System.Single, via.Quaternion, System.Boolean)
:System.Void update(System.Single, via.mat4, System.Boolean)
```

## `app.facial.VowelJPNKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `A` | `app.facial.VowelJPNKind` | yes | 16 |
| `E` | `app.facial.VowelJPNKind` | yes | 16 |
| `I` | `app.facial.VowelJPNKind` | yes | 16 |
| `None` | `app.facial.VowelJPNKind` | yes | 16 |
| `O` | `app.facial.VowelJPNKind` | yes | 16 |
| `U` | `app.facial.VowelJPNKind` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `app.facial.VowelJPNKind[]`

**Methods**

```lua
:System.Void Add(app.facial.VowelJPNKind)
:app.facial.VowelJPNKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.VowelJPNKind)
:System.Void CopyTo(app.facial.VowelJPNKind[], System.Int32)
:app.facial.VowelJPNKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.VowelJPNKind> GetEnumerator()
:System.Int32 IndexOf(app.facial.VowelJPNKind)
:System.Void Insert(System.Int32, app.facial.VowelJPNKind)
:System.Boolean Remove(app.facial.VowelJPNKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.VowelJPNKind)
:app.facial.VowelJPNKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.VowelJPNKind)
```

## `app.facial.VowelKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `None` | `app.facial.VowelKind` | yes | 16 |
| `Vowel01` | `app.facial.VowelKind` | yes | 16 |
| `Vowel02` | `app.facial.VowelKind` | yes | 16 |
| `Vowel03` | `app.facial.VowelKind` | yes | 16 |
| `Vowel04` | `app.facial.VowelKind` | yes | 16 |
| `Vowel05` | `app.facial.VowelKind` | yes | 16 |
| `Vowel06` | `app.facial.VowelKind` | yes | 16 |
| `Vowel07` | `app.facial.VowelKind` | yes | 16 |
| `Vowel08` | `app.facial.VowelKind` | yes | 16 |
| `Vowel09` | `app.facial.VowelKind` | yes | 16 |
| `Vowel10` | `app.facial.VowelKind` | yes | 16 |
| `Vowel11` | `app.facial.VowelKind` | yes | 16 |
| `Vowel12` | `app.facial.VowelKind` | yes | 16 |
| `Vowel13` | `app.facial.VowelKind` | yes | 16 |
| `Vowel14` | `app.facial.VowelKind` | yes | 16 |
| `Vowel15` | `app.facial.VowelKind` | yes | 16 |
| `Vowel16` | `app.facial.VowelKind` | yes | 16 |
| `Vowel17` | `app.facial.VowelKind` | yes | 16 |
| `Vowel18` | `app.facial.VowelKind` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `app.facial.VowelKind[]`

**Methods**

```lua
:System.Void Add(app.facial.VowelKind)
:app.facial.VowelKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.facial.VowelKind)
:System.Void CopyTo(app.facial.VowelKind[], System.Int32)
:app.facial.VowelKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.facial.VowelKind> GetEnumerator()
:System.Int32 IndexOf(app.facial.VowelKind)
:System.Void Insert(System.Int32, app.facial.VowelKind)
:System.Boolean Remove(app.facial.VowelKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.facial.VowelKind)
:app.facial.VowelKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.facial.VowelKind)
```

## `app.render.MaterialAnimation`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Entities>k__BackingField` | `System.Collections.Generic.List`1<app.render.MaterialAnimation.Entity>` |  | 80 |
| `<Mesh>k__BackingField` | `via.render.Mesh` |  | 88 |
| `<Motion>k__BackingField` | `via.motion.Motion` |  | 96 |
| `_UserData` | `app.render.MaterialAnimationUserData` |  | 104 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Collections.Generic.List`1<app.render.MaterialAnimation.Entity> get_Entities()
:via.render.Mesh get_Mesh()
:via.motion.Motion get_Motion()
:app.render.MaterialAnimationUserData get_UserData()
:System.Void lateUpdate()
:System.Void set_Entities(System.Collections.Generic.List`1<app.render.MaterialAnimation.Entity>)
:System.Void set_Mesh(via.render.Mesh)
:System.Void set_Motion(via.motion.Motion)
:System.Void set_UserData(app.render.MaterialAnimationUserData)
:System.Void setupDeformAnimation()
:System.Void setupMaterialAnimation()
:System.Void start()
:System.Void updateDeformAnimation()
:System.Void updateMaterialAnimation()
```

## `app.render.MaterialAnimation.Entity`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<DeformIndex>k__BackingField` | `System.Int32` |  | 16 |
| `<ExternMaterialParam>k__BackingField` | `System.Boolean` |  | 20 |
| `<MaterialParam>k__BackingField` | `via.render.MaterialParam` |  | 24 |
| `<Mesh>k__BackingField` | `via.render.Mesh` |  | 32 |
| `<Motion>k__BackingField` | `via.motion.Motion` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.render.Mesh, via.motion.Motion, System.String, System.String, System.UInt32)
:System.Void Dispose()
:System.Void apply()
:System.Int32 get_DeformIndex()
:System.Boolean get_ExternMaterialParam()
:System.String get_MaterialName()
:via.render.MaterialParam get_MaterialParam()
:via.render.Mesh get_Mesh()
:via.motion.Motion get_Motion()
:System.Boolean get_Valid()
:System.String get_VariableName()
:System.Void set_DeformIndex(System.Int32)
:System.Void set_ExternMaterialParam(System.Boolean)
:System.Void set_MaterialParam(via.render.MaterialParam)
:System.Void set_Mesh(via.render.Mesh)
:System.Void set_Motion(via.motion.Motion)
```

## `app.render.MaterialAnimation.Entity[]`

**Methods**

```lua
:System.Void Add(app.render.MaterialAnimation.Entity)
:app.render.MaterialAnimation.Entity Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.render.MaterialAnimation.Entity)
:System.Void CopyTo(app.render.MaterialAnimation.Entity[], System.Int32)
:app.render.MaterialAnimation.Entity Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.render.MaterialAnimation.Entity> GetEnumerator()
:System.Int32 IndexOf(app.render.MaterialAnimation.Entity)
:System.Void Insert(System.Int32, app.render.MaterialAnimation.Entity)
:System.Boolean Remove(app.render.MaterialAnimation.Entity)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.render.MaterialAnimation.Entity)
:app.render.MaterialAnimation.Entity get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.render.MaterialAnimation.Entity)
```

## `app.render.MaterialAnimation.MaterialParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MaterialName` | `System.String` |  | 16 |
| `_VariableParams` | `app.render.MaterialAnimation.VariableParameter[]` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String, app.render.MaterialAnimation.VariableParameter[])
:System.String get_DisplayName()
:System.String get_MaterialName()
:System.Collections.Generic.IReadOnlyCollection`1<app.render.MaterialAnimation.VariableParameter> get_VariableParams()
```

## `app.render.MaterialAnimation.MaterialParameter[]`

**Methods**

```lua
:System.Void Add(app.render.MaterialAnimation.MaterialParameter)
:app.render.MaterialAnimation.MaterialParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.render.MaterialAnimation.MaterialParameter)
:System.Void CopyTo(app.render.MaterialAnimation.MaterialParameter[], System.Int32)
:app.render.MaterialAnimation.MaterialParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.render.MaterialAnimation.MaterialParameter> GetEnumerator()
:System.Int32 IndexOf(app.render.MaterialAnimation.MaterialParameter)
:System.Void Insert(System.Int32, app.render.MaterialAnimation.MaterialParameter)
:System.Boolean Remove(app.render.MaterialAnimation.MaterialParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.render.MaterialAnimation.MaterialParameter)
:app.render.MaterialAnimation.MaterialParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.render.MaterialAnimation.MaterialParameter)
```

## `app.render.MaterialAnimation.VariableParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PropertyName` | `System.String` |  | 16 |
| `_PropertyNameHash` | `System.UInt32` |  | 24 |
| `_VariableName` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String, System.String)
:System.String get_DisplayName()
:System.String get_PropertyName()
:System.UInt32 get_PropertyNameHash()
:System.String get_VariableName()
:System.Void set_PropertyName(System.String)
```

## `app.render.MaterialAnimation.VariableParameter[]`

**Methods**

```lua
:System.Void Add(app.render.MaterialAnimation.VariableParameter)
:app.render.MaterialAnimation.VariableParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.render.MaterialAnimation.VariableParameter)
:System.Void CopyTo(app.render.MaterialAnimation.VariableParameter[], System.Int32)
:app.render.MaterialAnimation.VariableParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.render.MaterialAnimation.VariableParameter> GetEnumerator()
:System.Int32 IndexOf(app.render.MaterialAnimation.VariableParameter)
:System.Void Insert(System.Int32, app.render.MaterialAnimation.VariableParameter)
:System.Boolean Remove(app.render.MaterialAnimation.VariableParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.render.MaterialAnimation.VariableParameter)
:app.render.MaterialAnimation.VariableParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.render.MaterialAnimation.VariableParameter)
```

## `app.render.MaterialAnimationUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MaterialParams` | `app.render.MaterialAnimation.MaterialParameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.IReadOnlyCollection`1<app.render.MaterialAnimation.MaterialParameter> get_MaterialParams()
```

## `app.sku.SkuSettings`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_CERO_D", ...)  -- System.Boolean get_CERO_D()
sdk.call_native_func(nil, type_def, "get_CERO_Z", ...)  -- System.Boolean get_CERO_Z()
sdk.call_native_func(nil, type_def, "get_DisableChc0Meat", ...)  -- System.Boolean get_DisableChc0Meat()
sdk.call_native_func(nil, type_def, "get_DisableChd4Meat", ...)  -- System.Boolean get_DisableChd4Meat()
sdk.call_native_func(nil, type_def, "get_DisablePlayerBodyCut", ...)  -- System.Boolean get_DisablePlayerBodyCut()
```

## `app.tram.ClipTag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BankIndex` | `System.Int32` |  | 16 |
| `ClipIndex` | `System.Int32` |  | 20 |
| `IsMirrorByMotionList` | `System.Boolean` |  | 24 |
| `IsMirrorByUser` | `System.Boolean` |  | 25 |

**Methods**

```lua
:System.Void .ctor(System.Int32, System.Int32, System.Boolean, System.Boolean)
:System.Void .ctor(app.tram.ClipTag)
:System.ValueTuple`3<System.Int32,System.Int32,System.UInt32> getInfo(System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>)
:System.Boolean get_IsMirror()
```

## `app.tram.ClipTag[]`

**Methods**

```lua
:System.Void Add(app.tram.ClipTag)
:app.tram.ClipTag Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.ClipTag)
:System.Void CopyTo(app.tram.ClipTag[], System.Int32)
:app.tram.ClipTag Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.ClipTag> GetEnumerator()
:System.Int32 IndexOf(app.tram.ClipTag)
:System.Void Insert(System.Int32, app.tram.ClipTag)
:System.Boolean Remove(app.tram.ClipTag)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.ClipTag)
:app.tram.ClipTag get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.ClipTag)
```

## `app.tram.Hash`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Clear` | `System.UInt32` | yes | 16 |
| `Blank` | `System.UInt32` | yes | 20 |
| `Empty` | `System.UInt32` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "isValid", ...)  -- System.Boolean isValid(System.UInt32)
```

## `app.tram.Label`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Name` | `System.String` |  | 16 |
| `_Hash` | `System.UInt32` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.String)
:System.UInt32 get_Hash()
:System.String get_Name()
:System.Boolean isSameLabel(System.UInt32)
:System.Void set_Hash(System.UInt32)
:System.Void set_Name(System.String)
```

## `app.tram.TramAnimationId`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BankId` | `System.UInt32` |  | 16 |
| `MotionId` | `System.UInt32` |  | 20 |
| `IsMirror` | `System.Boolean` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.UInt32, System.UInt32, System.Boolean)
:System.String get_displayName()
```

## `app.tram.TramAnimationId[]`

**Methods**

```lua
:System.Void Add(app.tram.TramAnimationId)
:app.tram.TramAnimationId Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramAnimationId)
:System.Void CopyTo(app.tram.TramAnimationId[], System.Int32)
:app.tram.TramAnimationId Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramAnimationId> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramAnimationId)
:System.Void Insert(System.Int32, app.tram.TramAnimationId)
:System.Boolean Remove(app.tram.TramAnimationId)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramAnimationId)
:app.tram.TramAnimationId get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramAnimationId)
```

## `app.tram.TramBankData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Name` | `System.String` |  | 32 |
| `PoseList` | `System.Collections.Generic.List`1<app.tram.TramPose>` |  | 40 |
| `BankList` | `System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>` |  | 48 |
| `EnabledTypeMaskBit` | `System.Boolean` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:app.tram.TramFragment fragment(System.Int32, System.Int32, System.Int32)
```

## `app.tram.TramBankData.TramBank`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Name` | `System.String` |  | 16 |
| `Enable` | `System.Boolean` |  | 24 |
| `BankType` | `System.Int32` |  | 28 |
| `BankTypeMaskBit` | `System.UInt32` |  | 32 |
| `BankId` | `System.Int32` |  | 36 |
| `ClipList` | `System.Collections.Generic.List`1<app.tram.TramBankData.TramBank.TramClip>` |  | 40 |
| `FrameSize` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_displayName()
```

## `app.tram.TramBankData.TramBank.TramClip`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FragmentData` | `app.tram.TramFragmentData` |  | 16 |
| `Enable` | `System.Boolean` |  | 24 |
| `MotionId` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_displayName()
```

## `app.tram.TramBankData.TramBank.TramClip[]`

**Methods**

```lua
:System.Void Add(app.tram.TramBankData.TramBank.TramClip)
:app.tram.TramBankData.TramBank.TramClip Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramBankData.TramBank.TramClip)
:System.Void CopyTo(app.tram.TramBankData.TramBank.TramClip[], System.Int32)
:app.tram.TramBankData.TramBank.TramClip Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramBankData.TramBank.TramClip> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramBankData.TramBank.TramClip)
:System.Void Insert(System.Int32, app.tram.TramBankData.TramBank.TramClip)
:System.Boolean Remove(app.tram.TramBankData.TramBank.TramClip)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramBankData.TramBank.TramClip)
:app.tram.TramBankData.TramBank.TramClip get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramBankData.TramBank.TramClip)
```

## `app.tram.TramBankData.TramBank[]`

**Methods**

```lua
:System.Void Add(app.tram.TramBankData.TramBank)
:app.tram.TramBankData.TramBank Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramBankData.TramBank)
:System.Void CopyTo(app.tram.TramBankData.TramBank[], System.Int32)
:app.tram.TramBankData.TramBank Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramBankData.TramBank> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramBankData.TramBank)
:System.Void Insert(System.Int32, app.tram.TramBankData.TramBank)
:System.Boolean Remove(app.tram.TramBankData.TramBank)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramBankData.TramBank)
:app.tram.TramBankData.TramBank get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramBankData.TramBank)
```

## `app.tram.TramCompat`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "isBit", ...)  -- System.Boolean isBit(System.UInt32, System.Int32)
```

## `app.tram.TramCore`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultParameterHash` | `System.UInt32` | yes | 16 |
| `DisplayOrderCommon` | `System.Int32` | yes | 16 |
| `DisplayOrderDebug` | `System.Int32` | yes | 16 |
| `DisplayOrderSettings` | `System.Int32` | yes | 16 |
| `GroupSeparatorCommon` | `System.Boolean` | yes | 16 |
| `GroupSeparatorDebug` | `System.Boolean` | yes | 16 |
| `GroupSeparatorSettings` | `System.Boolean` | yes | 16 |
| `OctSyncBlendHash` | `System.UInt32` | yes | 20 |
| `SelectMotionHash` | `System.UInt32` | yes | 24 |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 16 |
| `Motion` | `via.motion.Motion` |  | 24 |
| `_Query` | `app.tram.TramQuery` |  | 32 |
| `DefaultSolver` | `app.tram.TramSolverBase` |  | 40 |
| `Solver` | `app.tram.TramSolverBase` |  | 48 |
| `_NodeDataList` | `System.Collections.Generic.List`1<app.tram.TramNodeData>` |  | 56 |
| `_BankData` | `app.tram.TramBankData` |  | 64 |
| `_ParameterList` | `System.Collections.Generic.List`1<app.tram.TramParameter>` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:app.tram.TramParameter createDefaultParameter()
:app.tram.TramParameter createDefaultParameter(System.Collections.Generic.List`1<app.tram.TramPose>)
:app.tram.ClipTag findClip(System.UInt32, System.Int32, System.UInt32, System.Boolean)
:System.Collections.Generic.List`1<app.tram.ClipTag> getClipTagList(app.tram.TramNode, System.Int32)
:app.tram.TramMatchingResult getMatchingResult(System.Int32, System.Int32, System.Int32, System.Boolean)
:app.tram.TramAnimationId getTramAnimationIdByChildNode(via.motion.MotionInfo, System.UInt32, System.Int32)
:app.tram.TramNode getTramNode(System.UInt32, System.UInt32, System.UInt32)
:app.tram.TramNode getTramNode(System.UInt32, System.UInt32)
:app.tram.TramNode getTramNode(System.UInt32)
:app.tram.TramNode getTramNode(app.tram.TramNodeHash)
:app.tram.TramBankData get_BankData()
:via.GameObject get_GameObject()
:System.Collections.Generic.List`1<app.tram.TramNodeData> get_NodeDataList()
:System.Collections.Generic.List`1<app.tram.TramParameter> get_ParameterList()
:app.tram.TramQuery get_Query()
:System.Void initialize(via.GameObject)
:System.Boolean isTargetBank(app.tram.TramBankData.TramBank, System.UInt32, System.Int32)
:System.Boolean isUndefId(System.UInt32)
:System.Void lateUpdate()
:app.tram.TramMatchingResult poseMatching(app.tram.TramNode, System.Int32, System.Int32, System.UInt32)
:app.tram.TramMatchingResult poseMatching(app.tram.TramAnimationId, System.Int32, System.Int32, System.UInt32)
:app.tram.TramMatchingResult poseMatching(System.UInt32, System.Int32, System.UInt32, System.Int32, System.UInt32, System.Boolean)
:app.tram.TramMatchingResult poseMatching(System.UInt32, System.UInt32, System.Int32, System.Int32)
:app.tram.TramMatchingResult poseMatchingCore(app.tram.TramNode, System.Int32, System.Int32, System.UInt32)
:app.tram.TramNode searchBlendTreeNode(System.Int32, app.tram.TramNode, via.motion.MotionInfo, System.UInt32)
:System.Void setSolver(app.tram.TramSolverBase)
:System.Void setTramNodeByAnimationId(app.tram.TramNode, via.motion.MotionInfo, System.UInt32, System.Int32)
:System.Void set_BankData(app.tram.TramBankData)
:System.Void set_GameObject(via.GameObject)
:System.Void set_NodeDataList(System.Collections.Generic.List`1<app.tram.TramNodeData>)
:System.Void set_ParameterList(System.Collections.Generic.List`1<app.tram.TramParameter>)
:System.Void setting(app.tram.TramSetting)
:System.Void updateQuery(via.motion.Motion, via.motion.TreeLayer)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.tram.TramData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Data` | `System.Single[]` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
:System.Void .ctor(System.Single[])
:System.String ToString()
:System.Single distance(app.tram.TramData)
:System.Int32 get_Dimension()
:System.Single get_Item(System.Int32)
:System.Single norm()
:System.Void set_Item(System.Int32, System.Single)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "op_Addition", ...)  -- app.tram.TramData op_Addition(app.tram.TramData, app.tram.TramData)
sdk.call_native_func(nil, type_def, "op_Multiply", ...)  -- app.tram.TramData op_Multiply(app.tram.TramData, app.tram.TramData)
sdk.call_native_func(nil, type_def, "op_Multiply", ...)  -- app.tram.TramData op_Multiply(app.tram.TramData, System.Single)
sdk.call_native_func(nil, type_def, "op_Subtraction", ...)  -- app.tram.TramData op_Subtraction(app.tram.TramData, app.tram.TramData)
```

## `app.tram.TramDebug`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `setMotionFrame` | `System.Collections.Generic.Dictionary`2<System.Int32,System.Int32>` | yes | 16 |
| `setMotionCheckDuration` | `System.Int32` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `app.tram.TramDraw`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "boneHuman", ...)  -- System.Void boneHuman(via.motion.Motion, System.UInt32, System.UInt32, System.UInt32, System.Single, via.mat4, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
sdk.call_native_func(nil, type_def, "drawBone", ...)  -- System.Void drawBone(via.motion.Motion, System.UInt32, System.UInt32, System.UInt32, System.Single, via.mat4, via.Color, System.UInt32, System.Boolean, System.Boolean, System.Boolean, System.Boolean, System.Single, System.Single)
```

## `app.tram.TramFragment`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Frame` | `System.Single` |  | 16 |
| `Data` | `app.tram.TramData` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramFragmentData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FragmentList` | `System.Collections.Generic.List`1<app.tram.TramFragment>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramFragment[]`

**Methods**

```lua
:System.Void Add(app.tram.TramFragment)
:app.tram.TramFragment Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramFragment)
:System.Void CopyTo(app.tram.TramFragment[], System.Int32)
:app.tram.TramFragment Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramFragment> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramFragment)
:System.Void Insert(System.Int32, app.tram.TramFragment)
:System.Boolean Remove(app.tram.TramFragment)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramFragment)
:app.tram.TramFragment get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramFragment)
```

## `app.tram.TramMatchingResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BankId` | `System.UInt32` |  | 16 |
| `MotionId` | `System.UInt32` |  | 20 |
| `StartFrame` | `System.Single` |  | 24 |
| `IsNeedMirror` | `System.Boolean` |  | 28 |

**Methods**

```lua
:System.Void .ctor(System.UInt32, System.UInt32, System.Single, System.Boolean)
:System.Void debugTrace()
```

## `app.tram.TramMirrorCalculator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `InvertAxisDict` | `System.Collections.Generic.Dictionary`2<System.UInt32,app.tram.TramMirrorCalculator.InvertAxis>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Void calcAxis(via.Quaternion, via.vec3, via.vec3, via.vec3)
:System.Void calcAxis(via.mat4, via.vec3, via.vec3, via.vec3)
:via.Quaternion calcBaseWorldRotations(via.Joint, System.Collections.Generic.Dictionary`2<System.UInt32,via.Quaternion>)
:System.Void calcInvertAxisOfCenterJoint(via.Joint, System.Collections.Generic.Dictionary`2<System.UInt32,via.Quaternion>)
:System.Void calcInvertAxisOfLRJoint(System.Collections.Generic.Dictionary`2<System.UInt32,via.Quaternion>, via.Joint, via.Joint)
:via.mat4 calcMirrorMatrix(via.Joint, via.Transform)
:via.mat4 calcMirrorMatrix(via.Joint, via.motion.Motion)
:via.mat4 calcMirrorMatrix(via.Joint, via.mat4)
:System.Void setup(via.Transform)
:System.Void setupInvertAxis(via.Transform)
```

## `app.tram.TramMirrorCalculator.InvertAxis`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AxisX` | `app.tram.TramMirrorCalculator.InvertAxis` | yes | 16 |
| `AxisY` | `app.tram.TramMirrorCalculator.InvertAxis` | yes | 16 |
| `AxisZ` | `app.tram.TramMirrorCalculator.InvertAxis` | yes | 16 |
| `None` | `app.tram.TramMirrorCalculator.InvertAxis` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `app.tram.TramMirrorCalculator.InvertAxis[]`

**Methods**

```lua
:System.Void Add(app.tram.TramMirrorCalculator.InvertAxis)
:app.tram.TramMirrorCalculator.InvertAxis Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramMirrorCalculator.InvertAxis)
:System.Void CopyTo(app.tram.TramMirrorCalculator.InvertAxis[], System.Int32)
:app.tram.TramMirrorCalculator.InvertAxis Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramMirrorCalculator.InvertAxis> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramMirrorCalculator.InvertAxis)
:System.Void Insert(System.Int32, app.tram.TramMirrorCalculator.InvertAxis)
:System.Boolean Remove(app.tram.TramMirrorCalculator.InvertAxis)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramMirrorCalculator.InvertAxis)
:app.tram.TramMirrorCalculator.InvertAxis get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramMirrorCalculator.InvertAxis)
```

## `app.tram.TramNode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Label` | `app.tram.Label` |  | 16 |
| `UseLaterFrame` | `System.Boolean` |  | 24 |
| `IsLoop` | `System.Boolean` |  | 25 |
| `MaxStartFrame` | `System.Single` |  | 28 |
| `AnimationIdList` | `System.Collections.Generic.List`1<app.tram.TramAnimationId>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.String)
:System.String get_displayName()
```

## `app.tram.TramNodeData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Label` | `app.tram.Label` |  | 32 |
| `NodeGroupList` | `System.Collections.Generic.List`1<app.tram.TramNodeGroup>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramNodeData[]`

**Methods**

```lua
:System.Void Add(app.tram.TramNodeData)
:app.tram.TramNodeData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramNodeData)
:System.Void CopyTo(app.tram.TramNodeData[], System.Int32)
:app.tram.TramNodeData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramNodeData> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramNodeData)
:System.Void Insert(System.Int32, app.tram.TramNodeData)
:System.Boolean Remove(app.tram.TramNodeData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramNodeData)
:app.tram.TramNodeData get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramNodeData)
```

## `app.tram.TramNodeGroup`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Label` | `app.tram.Label` |  | 16 |
| `NodeList` | `System.Collections.Generic.List`1<app.tram.TramNode>` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramNodeGroup[]`

**Methods**

```lua
:System.Void Add(app.tram.TramNodeGroup)
:app.tram.TramNodeGroup Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramNodeGroup)
:System.Void CopyTo(app.tram.TramNodeGroup[], System.Int32)
:app.tram.TramNodeGroup Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramNodeGroup> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramNodeGroup)
:System.Void Insert(System.Int32, app.tram.TramNodeGroup)
:System.Boolean Remove(app.tram.TramNodeGroup)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramNodeGroup)
:app.tram.TramNodeGroup get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramNodeGroup)
```

## `app.tram.TramNodeHash`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Data` | `System.UInt32` |  | 16 |
| `Group` | `System.UInt32` |  | 20 |
| `Node` | `System.UInt32` |  | 24 |

## `app.tram.TramNode[]`

**Methods**

```lua
:System.Void Add(app.tram.TramNode)
:app.tram.TramNode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramNode)
:System.Void CopyTo(app.tram.TramNode[], System.Int32)
:app.tram.TramNode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramNode> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramNode)
:System.Void Insert(System.Int32, app.tram.TramNode)
:System.Boolean Remove(app.tram.TramNode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramNode)
:app.tram.TramNode get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramNode)
```

## `app.tram.TramParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Label` | `app.tram.Label` |  | 16 |
| `FragmentSize` | `System.Int32` |  | 24 |
| `ParameterBankList` | `System.Collections.Generic.List`1<app.tram.TramParameter.TramParameterBank>` |  | 32 |
| `WeightList` | `System.Collections.Generic.List`1<app.tram.TramWeight>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_displayName()
:System.Boolean isSameParameter(System.Int32, System.Int32)
:System.Void setDefaultValue()
:System.Void setDefaultValue(System.Collections.Generic.List`1<app.tram.TramPose>)
```

## `app.tram.TramParameter.TramParameterBank`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BankId` | `System.Int32` |  | 16 |
| `BankType` | `System.Int32` |  | 20 |
| `Label` | `app.tram.Label` |  | 24 |
| `emptyNameHash` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_displayName()
:System.Boolean isSameParameterBank(System.Int32, System.Int32)
```

## `app.tram.TramParameter.TramParameterBank[]`

**Methods**

```lua
:System.Void Add(app.tram.TramParameter.TramParameterBank)
:app.tram.TramParameter.TramParameterBank Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramParameter.TramParameterBank)
:System.Void CopyTo(app.tram.TramParameter.TramParameterBank[], System.Int32)
:app.tram.TramParameter.TramParameterBank Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramParameter.TramParameterBank> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramParameter.TramParameterBank)
:System.Void Insert(System.Int32, app.tram.TramParameter.TramParameterBank)
:System.Boolean Remove(app.tram.TramParameter.TramParameterBank)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramParameter.TramParameterBank)
:app.tram.TramParameter.TramParameterBank get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramParameter.TramParameterBank)
```

## `app.tram.TramParameterData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ParameterList` | `System.Collections.Generic.List`1<app.tram.TramParameter>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:app.tram.TramParameter createDefaultParameter()
```

## `app.tram.TramParameter[]`

**Methods**

```lua
:System.Void Add(app.tram.TramParameter)
:app.tram.TramParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramParameter)
:System.Void CopyTo(app.tram.TramParameter[], System.Int32)
:app.tram.TramParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramParameter> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramParameter)
:System.Void Insert(System.Int32, app.tram.TramParameter)
:System.Boolean Remove(app.tram.TramParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramParameter)
:app.tram.TramParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramParameter)
```

## `app.tram.TramPose`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Axis_X` | `System.Int32` | yes | 16 |
| `Axis_XY` | `System.Int32` | yes | 16 |
| `Axis_XYZ` | `System.Int32` | yes | 16 |
| `Axis_XYZW` | `System.Int32` | yes | 16 |
| `Axis_XZ` | `System.Int32` | yes | 16 |
| `Axis_Y` | `System.Int32` | yes | 16 |
| `Axis_YZ` | `System.Int32` | yes | 16 |
| `Axis_Z` | `System.Int32` | yes | 16 |
| `Type_Axis` | `System.Int32` | yes | 16 |
| `Type_None` | `System.Int32` | yes | 16 |
| `Type_Position` | `System.Int32` | yes | 16 |
| `Type_Rotation_Euler` | `System.Int32` | yes | 16 |
| `Type_Rotation_Quaternion` | `System.Int32` | yes | 16 |
| `Type_Speed` | `System.Int32` | yes | 16 |
| `Label` | `app.tram.Label` |  | 16 |
| `JointLabel` | `app.tram.Label` |  | 24 |
| `TypeID` | `System.Int32` |  | 32 |
| `AxisID` | `System.Int32` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.Int32 dimension()
:System.String get_Axis()
:System.String get_Type()
:System.String get_displayName()
:System.Void set_Axis(System.String)
:System.Void set_Type(System.String)
:System.Boolean useXAxis()
:System.Boolean useYAxis()
:System.Boolean useZAxis()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_JointAnalysisAxis", ...)  -- System.String[] get_JointAnalysisAxis()
sdk.call_native_func(nil, type_def, "get_JointAnalysisTypes", ...)  -- System.String[] get_JointAnalysisTypes()
```

## `app.tram.TramPoseData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PoseList` | `System.Collections.Generic.List`1<app.tram.TramPose>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramPose[]`

**Methods**

```lua
:System.Void Add(app.tram.TramPose)
:app.tram.TramPose Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramPose)
:System.Void CopyTo(app.tram.TramPose[], System.Int32)
:app.tram.TramPose Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramPose> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramPose)
:System.Void Insert(System.Int32, app.tram.TramPose)
:System.Boolean Remove(app.tram.TramPose)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramPose)
:app.tram.TramPose get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramPose)
```

## `app.tram.TramQuery`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 16 |
| `<Dimension>k__BackingField` | `System.Int32` |  | 24 |
| `JointList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.Joint>` |  | 32 |
| `JointPrevPositionList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 40 |
| `JointPositionList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 48 |
| `JointRotationEulerList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 56 |
| `JointPrevMirrorPositionList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 64 |
| `JointMirrorPositionList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 72 |
| `JointMirrorRotationEulerList` | `System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>` |  | 80 |
| `DeltaTime` | `System.Single` |  | 88 |
| `MirrorCalculator` | `app.tram.TramMirrorCalculator` |  | 96 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addJoint(System.UInt32, System.Boolean)
:System.Void clear()
:via.Joint getJoint(System.UInt32)
:via.vec3 getPosition(System.UInt32, System.Boolean)
:via.vec3 getPosition(System.UInt32, System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>)
:via.vec3 getRotationEuler(System.UInt32, System.Boolean)
:via.vec3 getRotationEuler(System.UInt32, System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>)
:via.vec3 getSpeed(System.UInt32, System.Boolean)
:via.vec3 getSpeed(System.UInt32, System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>, System.Collections.Generic.SortedList`2<System.UInt32,via.vec3>)
:System.Int32 get_Dimension()
:via.GameObject get_GameObject()
:System.Boolean hasJointRegistered(System.UInt32, System.Boolean)
:System.Void initialize(via.GameObject, System.Collections.Generic.List`1<app.tram.TramPose>)
:System.Void setMirrorCoord(System.UInt32, via.mat4)
:System.Void set_Dimension(System.Int32)
:System.Void set_GameObject(via.GameObject)
:System.Void update(via.motion.Motion, via.motion.TreeLayer)
:System.Void updateByTransform()
:System.Void updateByTreeLayer(via.motion.Motion, via.motion.TreeLayer)
```

## `app.tram.TramSetting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NodeDataList` | `System.Collections.Generic.List`1<app.tram.TramNodeData>` |  | 16 |
| `BankData` | `app.tram.TramBankData` |  | 24 |
| `ParameterData` | `app.tram.TramParameterData` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
```

## `app.tram.TramSolverBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SolverName` | `System.String` |  | 16 |
| `GameObject` | `via.GameObject` |  | 24 |
| `Motion` | `via.motion.Motion` |  | 32 |
| `ParameterList` | `System.Collections.Generic.List`1<app.tram.TramParameter>` |  | 40 |
| `BankList` | `System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>` |  | 48 |
| `PoseList` | `System.Collections.Generic.List`1<app.tram.TramPose>` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean applyActionForFragmentData(System.Collections.Generic.List`1<app.tram.ClipTag>, System.Single, System.Action`6<app.tram.ClipTag,app.tram.TramFragmentData,System.Single,System.Nullable`1<System.Single>,System.Collections.Generic.List`1<System.Single>,System.Int32>)
:System.Single calcDistanceSq(app.tram.TramData, System.Boolean[], app.tram.TramFragment, System.Collections.Generic.List`1<System.Single>)
:System.Int32 calcIndexIncrement(System.Int32, System.Int32)
:app.tram.TramData getQueryData(app.tram.TramQuery, System.Boolean)
:System.Boolean[] getQuerySkip(app.tram.TramQuery, System.Int32)
:app.tram.TramParameter getTramParameter(System.Int32, System.Int32)
:System.Collections.Generic.List`1<System.Single> getWeightList(app.tram.TramParameter)
:System.Void initialize(via.GameObject, System.Collections.Generic.List`1<app.tram.TramParameter>, System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>, System.Collections.Generic.List`1<app.tram.TramPose>)
:System.Boolean isValidMaxStartFrame(System.Nullable`1<System.Single>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "isValidDataType", ...)  -- System.Boolean isValidDataType(System.Int32, System.Int32)
```

## `app.tram.TramSolverBase.FragmentTag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FragmentIndex` | `System.Int32` |  | 28 |

**Methods**

```lua
:System.Void .ctor(app.tram.ClipTag, System.Int32)
:System.Void .ctor(app.tram.TramSolverBase.FragmentTag)
:System.ValueTuple`4<System.Int32,System.Int32,System.UInt32,System.Single> getInfo(System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>)
```

## `app.tram.TramSolverBase.OptionFlag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `UseLaterFrame` | `System.Int32` | yes | 16 |

## `app.tram.TramSolverDefault`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CandidateNum` | `System.Int32` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:app.tram.TramSolverBase.FragmentTag bestFragmentTag(System.Boolean, System.Boolean, System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo>)
:System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo> calcDistanceList(app.tram.TramData, System.Boolean[], app.tram.ClipTag, app.tram.TramFragmentData, System.Single, System.Nullable`1<System.Single>, System.Collections.Generic.List`1<System.Single>, System.Int32)
:app.tram.TramData selectQueryData(app.tram.ClipTag, app.tram.TramData, app.tram.TramData)
:app.tram.TramSolverBase.FragmentTag solve(System.Collections.Generic.List`1<app.tram.ClipTag>, app.tram.TramQuery, System.Single, System.UInt32)
:System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo> sortByPosition(System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo>, app.tram.TramData, app.tram.TramData, System.Boolean[], System.Int32)
:System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo> sortBySpeed(System.Collections.Generic.List`1<app.tram.TramSolverDefault.DistanceInfo>, app.tram.TramData, app.tram.TramData, System.Boolean[], System.Int32)
```

## `app.tram.TramSolverDefault.DistanceInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PositionDist` | `System.Single` |  | 32 |
| `SpeedDist` | `System.Single` |  | 36 |

**Methods**

```lua
:System.Void .ctor(app.tram.TramSolverBase.FragmentTag, System.Single, System.Single)
:System.Void debugTrace(System.Collections.Generic.List`1<app.tram.TramBankData.TramBank>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "debugTraceLabel", ...)  -- System.Void debugTraceLabel()
```

## `app.tram.TramSolverDefault.DistanceInfo[]`

**Methods**

```lua
:System.Void Add(app.tram.TramSolverDefault.DistanceInfo)
:app.tram.TramSolverDefault.DistanceInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramSolverDefault.DistanceInfo)
:System.Void CopyTo(app.tram.TramSolverDefault.DistanceInfo[], System.Int32)
:app.tram.TramSolverDefault.DistanceInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramSolverDefault.DistanceInfo> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramSolverDefault.DistanceInfo)
:System.Void Insert(System.Int32, app.tram.TramSolverDefault.DistanceInfo)
:System.Boolean Remove(app.tram.TramSolverDefault.DistanceInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramSolverDefault.DistanceInfo)
:app.tram.TramSolverDefault.DistanceInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramSolverDefault.DistanceInfo)
```

## `app.tram.TramSolverWeightedDistance`

**Methods**

```lua
:System.Void .ctor()
:app.tram.TramSolverBase.FragmentTag bestFragmentTag(System.Boolean, System.Boolean, System.Collections.Generic.List`1<app.tram.TramSolverWeightedDistance.DistanceInfo>)
:app.tram.TramSolverWeightedDistance.DistanceInfo findClosestDistanceInfo(app.tram.TramData, app.tram.ClipTag, app.tram.TramFragmentData, System.Single, System.Nullable`1<System.Single>, System.Collections.Generic.List`1<System.Single>, System.Int32)
:app.tram.TramSolverBase.FragmentTag solve(System.Collections.Generic.List`1<app.tram.ClipTag>, app.tram.TramQuery, System.Single, System.UInt32)
```

## `app.tram.TramSolverWeightedDistance.DistanceInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Distance` | `System.Single` |  | 32 |

**Methods**

```lua
:System.Void .ctor(app.tram.TramSolverBase.FragmentTag, System.Single)
```

## `app.tram.TramSolverWeightedDistance.DistanceInfo[]`

**Methods**

```lua
:System.Void Add(app.tram.TramSolverWeightedDistance.DistanceInfo)
:app.tram.TramSolverWeightedDistance.DistanceInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramSolverWeightedDistance.DistanceInfo)
:System.Void CopyTo(app.tram.TramSolverWeightedDistance.DistanceInfo[], System.Int32)
:app.tram.TramSolverWeightedDistance.DistanceInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramSolverWeightedDistance.DistanceInfo> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramSolverWeightedDistance.DistanceInfo)
:System.Void Insert(System.Int32, app.tram.TramSolverWeightedDistance.DistanceInfo)
:System.Boolean Remove(app.tram.TramSolverWeightedDistance.DistanceInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramSolverWeightedDistance.DistanceInfo)
:app.tram.TramSolverWeightedDistance.DistanceInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramSolverWeightedDistance.DistanceInfo)
```

## `app.tram.TramTrace`

_No fields or methods._

## `app.tram.TramTrack`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxStartFrame` | `System.Boolean` |  | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getMaxStartFrame", ...)  -- System.Nullable`1<System.Single> getMaxStartFrame(via.motion.MotionInfo, System.Single)
```

## `app.tram.TramWeight`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `WeightType_Scalar` | `System.Int32` | yes | 16 |
| `WeightType_Vec2` | `System.Int32` | yes | 16 |
| `WeightType_Vec3` | `System.Int32` | yes | 16 |
| `WeightType_Vec4` | `System.Int32` | yes | 16 |
| `WeightTypeID` | `System.Int32` |  | 16 |
| `Label` | `app.tram.Label` |  | 24 |
| `WeightValue` | `app.tram.TramWeightBase` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_DisplayName()
:System.String get_WeightType()
:System.Void set_WeightType(System.String)
:System.Collections.Generic.List`1<System.Single> toList()
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_WeightTypeList", ...)  -- System.String[] get_WeightTypeList()
```

## `app.tram.TramWeightBase`

_No fields or methods._

## `app.tram.TramWeightScalar`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `System.Single` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.List`1<System.Single> toList()
```

## `app.tram.TramWeightVec2`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `via.vec2` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.List`1<System.Single> toList()
```

## `app.tram.TramWeightVec3`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `via.vec3` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.List`1<System.Single> toList()
```

## `app.tram.TramWeightVec4`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Value` | `via.vec4` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.List`1<System.Single> toList()
```

## `app.tram.TramWeight[]`

**Methods**

```lua
:System.Void Add(app.tram.TramWeight)
:app.tram.TramWeight Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(app.tram.TramWeight)
:System.Void CopyTo(app.tram.TramWeight[], System.Int32)
:app.tram.TramWeight Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<app.tram.TramWeight> GetEnumerator()
:System.Int32 IndexOf(app.tram.TramWeight)
:System.Void Insert(System.Int32, app.tram.TramWeight)
:System.Boolean Remove(app.tram.TramWeight)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, app.tram.TramWeight)
:app.tram.TramWeight get_Item(System.Int32)
:System.Void set_Item(System.Int32, app.tram.TramWeight)
```
