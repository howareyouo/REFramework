# `soundlib.*`

203 types.

## `soundlib.EnumBool`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `False` | `soundlib.EnumBool` | yes | 16 |
| `True` | `soundlib.EnumBool` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.EnumBool[]`

**Methods**

```lua
:System.Void Add(soundlib.EnumBool)
:soundlib.EnumBool Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.EnumBool)
:System.Void CopyTo(soundlib.EnumBool[], System.Int32)
:soundlib.EnumBool Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.EnumBool> GetEnumerator()
:System.Int32 IndexOf(soundlib.EnumBool)
:System.Void Insert(System.Int32, soundlib.EnumBool)
:System.Boolean Remove(soundlib.EnumBool)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.EnumBool)
:soundlib.EnumBool get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.EnumBool)
```

## `soundlib.JointParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointHash` | `System.UInt32` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_JointHash()
:System.Void set_JointHash(System.UInt32)
```

## `soundlib.PhysicsValueType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AngularMomemtum` | `soundlib.PhysicsValueType` | yes | 16 |
| `AngularVelocity` | `soundlib.PhysicsValueType` | yes | 16 |
| `FrictionFactor` | `soundlib.PhysicsValueType` | yes | 16 |
| `LinearVelocity` | `soundlib.PhysicsValueType` | yes | 16 |
| `MassTimesFrictionFactor` | `soundlib.PhysicsValueType` | yes | 16 |
| `Momentum` | `soundlib.PhysicsValueType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.PhysicsValueType[]`

**Methods**

```lua
:System.Void Add(soundlib.PhysicsValueType)
:soundlib.PhysicsValueType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.PhysicsValueType)
:System.Void CopyTo(soundlib.PhysicsValueType[], System.Int32)
:soundlib.PhysicsValueType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.PhysicsValueType> GetEnumerator()
:System.Int32 IndexOf(soundlib.PhysicsValueType)
:System.Void Insert(System.Int32, soundlib.PhysicsValueType)
:System.Boolean Remove(soundlib.PhysicsValueType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.PhysicsValueType)
:soundlib.PhysicsValueType get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.PhysicsValueType)
```

## `soundlib.SoundAABB`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_AABB` | `via.AABB` |  | 64 |
| `_TransformedAABB` | `via.AABB` |  | 96 |

**Methods**

```lua
:System.Void .ctor()
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.AABB getBoundingAABB()
:via.AABB get_AABB()
:via.vec3 get_Position()
:via.AABB get_TransformedAABB()
:System.Void set_AABB(via.AABB)
:System.Void set_TransformedAABB(via.AABB)
:System.Void update()
```

## `soundlib.SoundAudioInput`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_RequestInfoPtr` | `soundlib.SoundManager.RequestInfo` |  | 144 |

**Methods**

```lua
:System.Void onCreateRequestInfo(System.UInt32, System.Boolean, via.Transform)
:System.Void onPostEvent(via.GameObject)
:System.Void onSetRequestInfo()
:System.Void onStopEvent(via.GameObject)
:System.Void register()
:System.Void unregister()
```

## `soundlib.SoundAudioInputCaller`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `channelCount` | `System.UInt32` |  | 128 |
| `samplingRate` | `System.UInt32` |  | 132 |
| `_Container` | `soundlib.SoundContainer` |  | 136 |
| `_RequestInfo` | `soundlib.SoundManager.RequestInfo` |  | 144 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean action_initAudioInput()
:System.Void action_play()
:System.Void action_release()
:System.Void action_setWaveFormParameter()
:System.Void action_stop()
:System.Void awake()
:System.Void onCheckAvailable()
:System.Void onDestroy()
:System.Void onPlay(System.UInt32)
:System.Void onStop(System.UInt32)
:System.Void start()
```

## `soundlib.SoundAudioInput[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundAudioInput)
:soundlib.SoundAudioInput Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundAudioInput)
:System.Void CopyTo(soundlib.SoundAudioInput[], System.Int32)
:soundlib.SoundAudioInput Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundAudioInput> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundAudioInput)
:System.Void Insert(System.Int32, soundlib.SoundAudioInput)
:System.Boolean Remove(soundlib.SoundAudioInput)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundAudioInput)
:soundlib.SoundAudioInput get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundAudioInput)
```

## `soundlib.SoundBakeTriggerTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BakeCategory` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundBankListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BankList` | `via.simplewwise.BankResourceHolder[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:via.simplewwise.BankResourceHolder[] get_BankList()
```

## `soundlib.SoundBehaviorTreeActionBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Timing` | `soundlib.SoundBehaviorTreeActionBase.SetTiming` |  | 32 |

**Methods**

```lua
:soundlib.SoundBehaviorTreeActionBase.SetTiming get_Timing()
```

## `soundlib.SoundBehaviorTreeActionBase.SetTiming`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `End` | `soundlib.SoundBehaviorTreeActionBase.SetTiming` | yes | 16 |
| `Start` | `soundlib.SoundBehaviorTreeActionBase.SetTiming` | yes | 16 |
| `Update` | `soundlib.SoundBehaviorTreeActionBase.SetTiming` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundBehaviorTreeActionBase.SetTiming[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundBehaviorTreeActionBase.SetTiming)
:soundlib.SoundBehaviorTreeActionBase.SetTiming Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundBehaviorTreeActionBase.SetTiming)
:System.Void CopyTo(soundlib.SoundBehaviorTreeActionBase.SetTiming[], System.Int32)
:soundlib.SoundBehaviorTreeActionBase.SetTiming Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundBehaviorTreeActionBase.SetTiming> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundBehaviorTreeActionBase.SetTiming)
:System.Void Insert(System.Int32, soundlib.SoundBehaviorTreeActionBase.SetTiming)
:System.Boolean Remove(soundlib.SoundBehaviorTreeActionBase.SetTiming)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundBehaviorTreeActionBase.SetTiming)
:soundlib.SoundBehaviorTreeActionBase.SetTiming get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundBehaviorTreeActionBase.SetTiming)
```

## `soundlib.SoundBodyMaterialParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CastingRay>k__BackingField` | `System.Boolean` |  | 16 |
| `_BodyId` | `System.Int32` |  | 20 |
| `_UpdateOverlapping` | `System.Boolean` |  | 24 |
| `_MaterialId` | `System.UInt32` |  | 28 |
| `_RayFilter` | `via.physics.CollisionFilterResourceHolder` |  | 32 |
| `_RayLength` | `System.Single` |  | 40 |
| `_RayQuery` | `via.physics.CastRayQuery` |  | 48 |
| `_RayResult` | `via.physics.CastRayResult` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundBodyMaterialParam, via.physics.CollisionFilterResourceHolder, System.Single)
:System.Void castRay(via.vec3, via.vec3)
:System.Int32 get_BodyId()
:System.Boolean get_CastingRay()
:System.UInt32 get_MaterialId()
:System.Boolean get_UpdateOverlapping()
:System.Void reset()
:System.Void set_CastingRay(System.Boolean)
:System.Void set_MaterialId(System.UInt32)
:System.Void updateCastRayResult()
```

## `soundlib.SoundBodyMaterialParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundBodyMaterialParam)
:soundlib.SoundBodyMaterialParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundBodyMaterialParam)
:System.Void CopyTo(soundlib.SoundBodyMaterialParam[], System.Int32)
:soundlib.SoundBodyMaterialParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundBodyMaterialParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundBodyMaterialParam)
:System.Void Insert(System.Int32, soundlib.SoundBodyMaterialParam)
:System.Boolean Remove(soundlib.SoundBodyMaterialParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundBodyMaterialParam)
:soundlib.SoundBodyMaterialParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundBodyMaterialParam)
```

## `soundlib.SoundCapsule`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Capsule` | `via.Capsule` |  | 64 |
| `_TransformedCapsule` | `via.Capsule` |  | 112 |

**Methods**

```lua
:System.Void .ctor()
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.AABB getBoundingAABB()
:via.Capsule get_Capsule()
:via.vec3 get_Position()
:via.Capsule get_TransformedCapsule()
:System.Void set_Capsule(via.Capsule)
:System.Void set_TransformedCapsule(via.Capsule)
:System.Void update()
```

## `soundlib.SoundClipStateList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_OverrideStateList` | `System.Collections.Generic.List`1<soundlib.SoundOverrideState>` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void finalize()
:System.Collections.Generic.List`1<soundlib.SoundOverrideState> get_OverrideStateList()
:System.Void onClipHalfwayPlay()
:System.Void onClipHalfwayPlayEnd()
:System.Void onUnload()
:System.Void set_OverrideStateList(System.Collections.Generic.List`1<soundlib.SoundOverrideState>)
```

## `soundlib.SoundClipTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ClipPlaying>k__BackingField` | `System.Boolean` |  | 16 |
| `_TriggerId` | `System.UInt32` |  | 20 |
| `PrevDiffFrame` | `System.Single` |  | 24 |
| `OnTriggerAction` | `System.Action` |  | 32 |
| `_EnableTrigger` | `System.Boolean` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_ClipPlaying()
:System.UInt32 get_TriggerId()
:System.Void onClipEnd()
:System.Void onClipStart()
:System.Void onClipUpdate()
:System.Void resetFlag()
:System.Void set_ClipPlaying(System.Boolean)
:System.Void set_TriggerId(System.UInt32)
```

## `soundlib.SoundClipTriggerList`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ClipTriggerList` | `System.Collections.Generic.List`1<soundlib.SoundClipTrigger>` |  | 80 |
| `_Container` | `soundlib.SoundContainer` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Collections.Generic.List`1<soundlib.SoundClipTrigger> get_ClipTriggerList()
:System.Void onClipHalfwayPlay()
:System.Void onClipHalfwayPlayEnd()
:System.Void onUnload()
:System.Void set_ClipTriggerList(System.Collections.Generic.List`1<soundlib.SoundClipTrigger>)
```

## `soundlib.SoundClipTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundClipTrigger)
:soundlib.SoundClipTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundClipTrigger)
:System.Void CopyTo(soundlib.SoundClipTrigger[], System.Int32)
:soundlib.SoundClipTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundClipTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundClipTrigger)
:System.Void Insert(System.Int32, soundlib.SoundClipTrigger)
:System.Boolean Remove(soundlib.SoundClipTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundClipTrigger)
:soundlib.SoundClipTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundClipTrigger)
```

## `soundlib.SoundConstants`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EmptyStrHash` | `System.UInt32` | yes | 16 |
| `InvalidBlendedLastLayerIdx` | `System.Int32` | yes | 16 |
| `InvalidCullingId` | `System.UInt32` | yes | 16 |
| `InvalidGameObjId` | `System.UInt64` | yes | 16 |
| `InvalidId` | `System.UInt32` | yes | 16 |
| `InvalidPlayingId` | `System.UInt32` | yes | 16 |
| `MaxCentVal` | `System.Single` | yes | 16 |
| `MaxContactPoints` | `System.Int32` | yes | 16 |
| `MaxDbVal` | `System.Single` | yes | 16 |
| `MaxPadNum` | `System.UInt32` | yes | 16 |
| `MinCentVal` | `System.Single` | yes | 16 |
| `MinDbVal` | `System.Single` | yes | 16 |
| `RootJointHash` | `System.UInt32` | yes | 16 |
| `StopDuration` | `System.Single` | yes | 16 |
| `ZeroDbVal` | `System.Single` | yes | 16 |
| `PadBitMask` | `System.UInt32[]` | yes | 24 |
| `AllPadBitMask` | `System.UInt32` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `soundlib.SoundConstants.PadIndex`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pad_00` | `soundlib.SoundConstants.PadIndex` | yes | 16 |
| `Pad_01` | `soundlib.SoundConstants.PadIndex` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundConstants.PadIndex[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundConstants.PadIndex)
:soundlib.SoundConstants.PadIndex Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundConstants.PadIndex)
:System.Void CopyTo(soundlib.SoundConstants.PadIndex[], System.Int32)
:soundlib.SoundConstants.PadIndex Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundConstants.PadIndex> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundConstants.PadIndex)
:System.Void Insert(System.Int32, soundlib.SoundConstants.PadIndex)
:System.Boolean Remove(soundlib.SoundConstants.PadIndex)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundConstants.PadIndex)
:soundlib.SoundConstants.PadIndex get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundConstants.PadIndex)
```

## `soundlib.SoundContainableUserData[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundContainableUserData)
:soundlib.SoundContainableUserData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundContainableUserData)
:System.Void CopyTo(soundlib.SoundContainableUserData[], System.Int32)
:soundlib.SoundContainableUserData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundContainableUserData> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundContainableUserData)
:System.Void Insert(System.Int32, soundlib.SoundContainableUserData)
:System.Boolean Remove(soundlib.SoundContainableUserData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundContainableUserData)
:soundlib.SoundContainableUserData get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundContainableUserData)
```

## `soundlib.SoundContainer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HasTriggerInfo` | `System.Boolean` | yes | 80 |
| `_GroupCore` | `System.Boolean` | yes | 80 |
| `_GroupDebug` | `System.Boolean` | yes | 80 |
| `_GroupResource` | `System.Boolean` | yes | 80 |
| `_AdditionalContentIdSet` | `System.Collections.Generic.HashSet`1<System.UInt32>` |  | 80 |
| `_UserDataList` | `System.Collections.Generic.List`1<soundlib.SoundContainableUserData>` |  | 88 |
| `_ExtensionList` | `System.Collections.Generic.List`1<soundlib.SoundContainerExtensionBase>` |  | 96 |
| `_ExtensionDict` | `System.Collections.Generic.Dictionary`2<System.Type,soundlib.SoundContainerExtensionBase>` |  | 104 |
| `_TriggerInfoList` | `System.Collections.Generic.List`1<soundlib.SoundTriggerInfo>` |  | 112 |
| `OnStart` | `System.Action` |  | 120 |
| `OnUpdate` | `System.Action` |  | 128 |
| `OnUnload` | `System.Action` |  | 136 |
| `<PlayingRequestIdDict>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>` |  | 144 |
| `<BankResourceList>k__BackingField` | `System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder>` |  | 152 |
| `<PackageResourceList>k__BackingField` | `System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder>` |  | 160 |
| `<AllTriggerInfoListData>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundTriggerInfoListData>` |  | 168 |
| `OnPostRequestInfoStart` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 176 |
| `OnPostRequestInfoEnd` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 184 |
| `_FailedRequestInfo` | `soundlib.SoundManager.RequestInfo` |  | 192 |
| `_Rand` | `via.Random` |  | 200 |
| `_LoadedData` | `System.Boolean` |  | 208 |
| `_SortedInfo` | `System.Boolean` |  | 209 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addRequestId(System.UInt32, System.Boolean)
:System.Void add_OnPostRequestInfoEnd(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void add_OnPostRequestInfoStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void add_OnStart(System.Action)
:System.Void add_OnUnload(System.Action)
:System.Void add_OnUpdate(System.Action)
:System.Void awake()
:soundlib.SoundManager.RequestInfo createRequestInfo(System.Int32, via.GameObject, via.GameObject, System.UInt32, System.Boolean, System.Boolean, System.UInt32, via.simplewwise.CallbackType, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>)
:soundlib.SoundManager.RequestInfo createRequestInfo(soundlib.SoundTriggerInfo, via.GameObject, via.GameObject, System.UInt32, System.Boolean, System.Boolean, System.UInt32, via.simplewwise.CallbackType, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>)
:soundlib.SoundContainerExtensionBase getExtension(System.Type)
:soundlib.SoundContainerExtensionBase getSameExtension(System.Type)
:soundlib.SoundTriggerInfo getTriggerInfo(System.Int32)
:System.Boolean getTriggerInfoIdx(System.UInt32, System.Int32, System.Int32, System.Boolean)
:System.Collections.Generic.List`1<soundlib.SoundTriggerInfoListData> get_AllTriggerInfoListData()
:System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder> get_BankResourceList()
:System.Boolean get_NotUpdate()
:System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder> get_PackageResourceList()
:System.Int32 get_PlayingCount()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean> get_PlayingRequestIdDict()
:System.Collections.Generic.List`1<soundlib.SoundContainableUserData> get_UserDataList()
:System.Void invokeFailedEndOfEvent(System.UInt32, via.GameObject, via.GameObject, System.UInt32, System.Boolean, System.UInt32, via.simplewwise.CallbackType, System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void loadContainableUserData(soundlib.SoundContainableUserData)
:System.Void loadContainableUserDataApp(soundlib.SoundContainableUserData)
:System.Void onUnload()
:System.Void onUpdate()
:System.Void removeRequestId(System.UInt32, System.Boolean)
:System.Void remove_OnPostRequestInfoEnd(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void remove_OnPostRequestInfoStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void remove_OnStart(System.Action)
:System.Void remove_OnUnload(System.Action)
:System.Void remove_OnUpdate(System.Action)
:System.Void set_AllTriggerInfoListData(System.Collections.Generic.List`1<soundlib.SoundTriggerInfoListData>)
:System.Void start()
:System.Void stopTriggered(System.UInt32, via.GameObject, System.UInt32)
:System.Void stopTriggeredTarget(System.UInt32, via.GameObject, System.UInt32)
:System.UInt32 trigger(soundlib.SoundTriggerInfo)
:System.UInt32 trigger(soundlib.SoundManager.RequestInfo)
:System.Void trigger(System.UInt32)
:System.Void trigger(System.UInt32, via.GameObject, via.GameObject, System.UInt32, System.Boolean, System.UInt32, via.simplewwise.CallbackType, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void trigger(System.UInt32, via.vec3, via.GameObject, System.UInt32, via.simplewwise.CallbackType, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>, System.Action`1<soundlib.SoundManager.RequestInfo>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "<createRequestInfo>g__isNeedSetSwitch|67_0", ...)  -- System.Boolean <createRequestInfo>g__isNeedSetSwitch|67_0(System.UInt32[], System.UInt32)
sdk.call_native_func(nil, type_def, "<trigger>g__withinTriggerRange|56_0", ...)  -- System.Boolean <trigger>g__withinTriggerRange|56_0(soundlib.SoundContainer.<>c__DisplayClass56_0)
```

## `soundlib.SoundContainerExtensionBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Enabled` | `System.Boolean` |  | 16 |
| `_GameObject` | `via.GameObject` |  | 24 |
| `_Container` | `soundlib.SoundContainer` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_Enabled()
:System.String get_ExtensionName()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onDisable()
:System.Void onEnable()
:System.Void set_Enabled(System.Boolean)
```

## `soundlib.SoundContainerExtensionBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundContainerExtensionBase)
:soundlib.SoundContainerExtensionBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundContainerExtensionBase)
:System.Void CopyTo(soundlib.SoundContainerExtensionBase[], System.Int32)
:soundlib.SoundContainerExtensionBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundContainerExtensionBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundContainerExtensionBase)
:System.Void Insert(System.Int32, soundlib.SoundContainerExtensionBase)
:System.Boolean Remove(soundlib.SoundContainerExtensionBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundContainerExtensionBase)
:soundlib.SoundContainerExtensionBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundContainerExtensionBase)
```

## `soundlib.SoundContainerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BaseUserDataList` | `soundlib.SoundContainableUserData[]` |  | 32 |
| `_UserDataList` | `soundlib.SoundContainableUserData[]` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainableUserData[] get_BaseUserDataList()
:soundlib.SoundContainableUserData[] get_UserDataList()
```

## `soundlib.SoundContainerListData[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundContainerListData)
:soundlib.SoundContainerListData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundContainerListData)
:System.Void CopyTo(soundlib.SoundContainerListData[], System.Int32)
:soundlib.SoundContainerListData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundContainerListData> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundContainerListData)
:System.Void Insert(System.Int32, soundlib.SoundContainerListData)
:System.Boolean Remove(soundlib.SoundContainerListData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundContainerListData)
:soundlib.SoundContainerListData get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundContainerListData)
```

## `soundlib.SoundCountRepeatTriggerTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TriggerCount` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundDisableAnimFootContactTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Disable` | `System.Boolean` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundDisplayOrder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Body` | `System.Int32` | yes | 16 |
| `Footer` | `System.Int32` | yes | 16 |
| `Header` | `System.Int32` | yes | 16 |

## `soundlib.SoundGameParameterApp`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_RtpcId` | `System.UInt32` |  | 16 |
| `_JointHash` | `System.UInt32[]` |  | 24 |
| `_Global` | `System.Boolean` |  | 32 |
| `_SetOnce` | `System.Boolean` |  | 33 |
| `_RestrictUpdate` | `System.Boolean` |  | 34 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_Global()
:System.UInt32[] get_JointHash()
:System.Boolean get_RestrictUpdate()
:System.UInt32 get_RtpcId()
:System.Boolean get_SetOnce()
:System.Boolean isTargetJoint(System.UInt32)
:System.Void setRtpcValue(via.GameObject, System.UInt64, System.Single, System.Boolean)
:System.Void set_RtpcId(System.UInt32)
```

## `soundlib.SoundGameParameterAppListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameParameterAppParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundGameParameterAppParam>` |  | 40 |
| `_GameObjId` | `System.UInt64` |  | 48 |
| `_Released` | `System.Boolean` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Void addGameParameterApp(soundlib.SoundManager.RequestInfo)
:System.Collections.Generic.List`1<soundlib.SoundGameParameterAppParam> get_GameParameterAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGameParameterAppListData`

**Methods**

```lua
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundGameParameterAppParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameParameterApp>k__BackingField` | `soundlib.SoundGameParameterApp` |  | 16 |

**Methods**

```lua
:System.Void .ctor(soundlib.SoundGameParameterApp)
:soundlib.SoundGameParameterApp get_GameParameterApp()
:System.Void set_GameParameterApp(soundlib.SoundGameParameterApp)
```

## `soundlib.SoundGameParameterAppParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGameParameterAppParam)
:soundlib.SoundGameParameterAppParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGameParameterAppParam)
:System.Void CopyTo(soundlib.SoundGameParameterAppParam[], System.Int32)
:soundlib.SoundGameParameterAppParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGameParameterAppParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGameParameterAppParam)
:System.Void Insert(System.Int32, soundlib.SoundGameParameterAppParam)
:System.Boolean Remove(soundlib.SoundGameParameterAppParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGameParameterAppParam)
:soundlib.SoundGameParameterAppParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGameParameterAppParam)
```

## `soundlib.SoundGetGameParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GameParameterName` | `System.String` | yes | 16 |
| `_GameParameterId` | `System.UInt32` |  | 16 |
| `_Global` | `System.Boolean` |  | 20 |
| `_JointHash` | `System.UInt32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_GameParameterId()
:System.Boolean get_Global()
:System.UInt32 get_JointHash()
:System.Void set_GameParameterId(System.UInt32)
```

## `soundlib.SoundGetGameParameterListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GetGameParameterParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundGetGameParameterParam>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundGetGameParameterParam> get_GetGameParameterParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGetGameParameterListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GetGameParameterList` | `soundlib.SoundGetGameParameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGetGameParameter[] get_GetGameParameterList()
```

## `soundlib.SoundGetGameParameterParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GetGameParameter>k__BackingField` | `soundlib.SoundGetGameParameter` |  | 16 |
| `<CurrentValue>k__BackingField` | `System.Single` |  | 24 |
| `<PositionObject>k__BackingField` | `via.GameObject` |  | 32 |
| `<GameObjectId>k__BackingField` | `System.UInt64` |  | 40 |
| `<RequestId>k__BackingField` | `System.UInt32` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundGetGameParameter, via.GameObject)
:System.Single get_CurrentValue()
:System.UInt64 get_GameObjectId()
:soundlib.SoundGetGameParameter get_GetGameParameter()
:via.GameObject get_PositionObject()
:System.UInt32 get_RequestId()
:System.Void set_CurrentValue(System.Single)
:System.Void set_GameObjectId(System.UInt64)
:System.Void set_GetGameParameter(soundlib.SoundGetGameParameter)
:System.Void set_RequestId(System.UInt32)
```

## `soundlib.SoundGetGameParameterParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGetGameParameterParam)
:soundlib.SoundGetGameParameterParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGetGameParameterParam)
:System.Void CopyTo(soundlib.SoundGetGameParameterParam[], System.Int32)
:soundlib.SoundGetGameParameterParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGetGameParameterParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGetGameParameterParam)
:System.Void Insert(System.Int32, soundlib.SoundGetGameParameterParam)
:System.Boolean Remove(soundlib.SoundGetGameParameterParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGetGameParameterParam)
:soundlib.SoundGetGameParameterParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGetGameParameterParam)
```

## `soundlib.SoundGetGameParameter[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGetGameParameter)
:soundlib.SoundGetGameParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGetGameParameter)
:System.Void CopyTo(soundlib.SoundGetGameParameter[], System.Int32)
:soundlib.SoundGetGameParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGetGameParameter> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGetGameParameter)
:System.Void Insert(System.Int32, soundlib.SoundGetGameParameter)
:System.Boolean Remove(soundlib.SoundGetGameParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGetGameParameter)
:soundlib.SoundGetGameParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGetGameParameter)
```

## `soundlib.SoundGpuClothTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_TriggerType` | `soundlib.SoundGpuClothTrigger.Type` |  | 16 |
| `_AntiRepeatTime` | `System.Single` |  | 20 |
| `_TriggerAll` | `System.Boolean` |  | 24 |
| `_ThresholdTriggerList` | `soundlib.ThresholdTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_AntiRepeatTime()
:soundlib.ThresholdTrigger[] get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
:soundlib.SoundGpuClothTrigger.Type get_TriggerType()
```

## `soundlib.SoundGpuClothTrigger.Type`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Acceleration` | `soundlib.SoundGpuClothTrigger.Type` | yes | 16 |
| `Movement` | `soundlib.SoundGpuClothTrigger.Type` | yes | 16 |
| `Speed` | `soundlib.SoundGpuClothTrigger.Type` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundGpuClothTrigger.Type[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGpuClothTrigger.Type)
:soundlib.SoundGpuClothTrigger.Type Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGpuClothTrigger.Type)
:System.Void CopyTo(soundlib.SoundGpuClothTrigger.Type[], System.Int32)
:soundlib.SoundGpuClothTrigger.Type Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGpuClothTrigger.Type> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGpuClothTrigger.Type)
:System.Void Insert(System.Int32, soundlib.SoundGpuClothTrigger.Type)
:System.Boolean Remove(soundlib.SoundGpuClothTrigger.Type)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGpuClothTrigger.Type)
:soundlib.SoundGpuClothTrigger.Type get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGpuClothTrigger.Type)
```

## `soundlib.SoundGpuClothTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupParam` | `System.Boolean` | yes | 16 |
| `<GpuClothTriggerParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundGpuClothTriggerParam>` |  | 40 |
| `<Movement>k__BackingField` | `System.Single` |  | 48 |
| `<Speed>k__BackingField` | `System.Single` |  | 52 |
| `<Acceleration>k__BackingField` | `System.Single` |  | 56 |
| `_GpuCloth` | `via.dynamics.GpuCloth` |  | 64 |
| `_UseSpeed` | `System.Boolean` |  | 72 |
| `_UseAcceleration` | `System.Boolean` |  | 73 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Single get_Acceleration()
:System.Collections.Generic.List`1<soundlib.SoundGpuClothTriggerParam> get_GpuClothTriggerParamList()
:System.Single get_Movement()
:System.Single get_Speed()
:System.Void initialize(soundlib.SoundContainer)
:System.Void set_Acceleration(System.Single)
:System.Void set_Movement(System.Single)
:System.Void set_Speed(System.Single)
:System.Void update()
```

## `soundlib.SoundGpuClothTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GpuClothTriggerList` | `soundlib.SoundGpuClothTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGpuClothTrigger[] get_GpuClothTriggerList()
```

## `soundlib.SoundGpuClothTriggerParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GpuClothTrigger>k__BackingField` | `soundlib.SoundGpuClothTrigger` |  | 16 |
| `<Posted>k__BackingField` | `System.Boolean` |  | 24 |
| `<ElapsedSecond>k__BackingField` | `System.Single` |  | 28 |

**Methods**

```lua
:System.Void .ctor(soundlib.SoundGpuClothTrigger)
:System.Single get_ElapsedSecond()
:soundlib.SoundGpuClothTrigger get_GpuClothTrigger()
:System.Boolean get_Posted()
:System.Void set_ElapsedSecond(System.Single)
:System.Void set_Posted(System.Boolean)
```

## `soundlib.SoundGpuClothTriggerParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGpuClothTriggerParam)
:soundlib.SoundGpuClothTriggerParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGpuClothTriggerParam)
:System.Void CopyTo(soundlib.SoundGpuClothTriggerParam[], System.Int32)
:soundlib.SoundGpuClothTriggerParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGpuClothTriggerParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGpuClothTriggerParam)
:System.Void Insert(System.Int32, soundlib.SoundGpuClothTriggerParam)
:System.Boolean Remove(soundlib.SoundGpuClothTriggerParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGpuClothTriggerParam)
:soundlib.SoundGpuClothTriggerParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGpuClothTriggerParam)
```

## `soundlib.SoundGpuClothTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGpuClothTrigger)
:soundlib.SoundGpuClothTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGpuClothTrigger)
:System.Void CopyTo(soundlib.SoundGpuClothTrigger[], System.Int32)
:soundlib.SoundGpuClothTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGpuClothTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGpuClothTrigger)
:System.Void Insert(System.Int32, soundlib.SoundGpuClothTrigger)
:System.Boolean Remove(soundlib.SoundGpuClothTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGpuClothTrigger)
:soundlib.SoundGpuClothTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGpuClothTrigger)
```

## `soundlib.SoundGuvSetState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SetStateListData` | `soundlib.SoundSetStateListData` |  | 16 |
| `_ValueList` | `soundlib.SoundGuvSetState.GuvSetStateValue[]` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundSetStateListData get_SetStateListData()
:soundlib.SoundGuvSetState.GuvSetStateValue[] get_ValueList()
```

## `soundlib.SoundGuvSetState.GuvSetStateValue`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_IsVariableTypeBool` | `System.Boolean` | yes | 16 |
| `_IsVariableTypeFloat` | `System.Boolean` | yes | 16 |
| `_IsVariableTypeInt` | `System.Boolean` | yes | 16 |
| `_IsVariableTypeUint` | `System.Boolean` | yes | 16 |
| `<VariableType>k__BackingField` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` |  | 16 |
| `_GlobalVariableGuid` | `System.Guid` |  | 24 |
| `_OperatorType` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` |  | 40 |
| `_GlobalVariable` | `via.userdata.Variable` |  | 48 |
| `_ComparisonBool` | `System.Boolean` |  | 56 |
| `_ComparisonInt` | `System.Int32` |  | 60 |
| `_ComparisonMinInt` | `System.Int32` |  | 64 |
| `_ComparisonMaxInt` | `System.Int32` |  | 68 |
| `_ComparisonUint` | `System.UInt32` |  | 72 |
| `_ComparisonMinUint` | `System.UInt32` |  | 76 |
| `_ComparisonMaxUint` | `System.UInt32` |  | 80 |
| `_ComparisonFloat` | `System.Single` |  | 84 |
| `_ComparisonMinFloat` | `System.Single` |  | 88 |
| `_ComparisonMaxFloat` | `System.Single` |  | 92 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean checkMatchValue()
:System.Guid get_GlobalVariableGuid()
:soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType get_VariableType()
:System.Void set_GlobalVariableGuid(System.Guid)
:System.Void set_VariableType(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Void updateVariable(System.Guid)
```

## `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Between` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `Equal` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `GreaterThan` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `GreaterThanOrEqual` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `LessThan` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `LessThanOrEqual` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `NotEqual` | `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:System.Void CopyTo(soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType[], System.Int32)
:soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:System.Void Insert(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:System.Boolean Remove(soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
:soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType)
```

## `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Boolean` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` | yes | 16 |
| `Float` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` | yes | 16 |
| `Int` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` | yes | 16 |
| `Uint` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` | yes | 16 |
| `Unknown` | `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Void CopyTo(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType[], System.Int32)
:soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Void Insert(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Boolean Remove(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
```

## `soundlib.SoundGuvSetState.GuvSetStateValue[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGuvSetState.GuvSetStateValue)
:soundlib.SoundGuvSetState.GuvSetStateValue Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGuvSetState.GuvSetStateValue)
:System.Void CopyTo(soundlib.SoundGuvSetState.GuvSetStateValue[], System.Int32)
:soundlib.SoundGuvSetState.GuvSetStateValue Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGuvSetState.GuvSetStateValue> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGuvSetState.GuvSetStateValue)
:System.Void Insert(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue)
:System.Boolean Remove(soundlib.SoundGuvSetState.GuvSetStateValue)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue)
:soundlib.SoundGuvSetState.GuvSetStateValue get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGuvSetState.GuvSetStateValue)
```

## `soundlib.SoundGuvSetStateListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GuvSetStateParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundGuvSetStateParam>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundGuvSetStateParam> get_GuvSetStateParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGuvSetStateListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GuvSetStateList` | `soundlib.SoundGuvSetState[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGuvSetState[] get_GuvSetStateList()
```

## `soundlib.SoundGuvSetStateParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GuvSetState>k__BackingField` | `soundlib.SoundGuvSetState` |  | 16 |
| `<Matched>k__BackingField` | `System.Boolean` |  | 24 |

**Methods**

```lua
:System.Void .ctor(soundlib.SoundGuvSetState)
:soundlib.SoundGuvSetState get_GuvSetState()
:System.Boolean get_Matched()
:System.Void set_GuvSetState(soundlib.SoundGuvSetState)
:System.Void set_Matched(System.Boolean)
```

## `soundlib.SoundGuvSetStateParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGuvSetStateParam)
:soundlib.SoundGuvSetStateParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGuvSetStateParam)
:System.Void CopyTo(soundlib.SoundGuvSetStateParam[], System.Int32)
:soundlib.SoundGuvSetStateParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGuvSetStateParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGuvSetStateParam)
:System.Void Insert(System.Int32, soundlib.SoundGuvSetStateParam)
:System.Boolean Remove(soundlib.SoundGuvSetStateParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGuvSetStateParam)
:soundlib.SoundGuvSetStateParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGuvSetStateParam)
```

## `soundlib.SoundGuvSetState[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundGuvSetState)
:soundlib.SoundGuvSetState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundGuvSetState)
:System.Void CopyTo(soundlib.SoundGuvSetState[], System.Int32)
:soundlib.SoundGuvSetState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundGuvSetState> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundGuvSetState)
:System.Void Insert(System.Int32, soundlib.SoundGuvSetState)
:System.Boolean Remove(soundlib.SoundGuvSetState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundGuvSetState)
:soundlib.SoundGuvSetState get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundGuvSetState)
```

## `soundlib.SoundIdCategory`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AdditionalContent` | `System.Int32` | yes | 16 |
| `BakeCategory` | `System.Int32` | yes | 16 |
| `CullingId1` | `System.Int32` | yes | 16 |
| `CullingId2` | `System.Int32` | yes | 16 |
| `CullingId3` | `System.Int32` | yes | 16 |
| `Joint` | `System.Int32` | yes | 16 |
| `MotionStatus` | `System.Int32` | yes | 16 |
| `None` | `System.Int32` | yes | 16 |
| `PartsCategory` | `System.Int32` | yes | 16 |
| `Portal` | `System.Int32` | yes | 16 |
| `RandomTonePreset` | `System.Int32` | yes | 16 |
| `Space` | `System.Int32` | yes | 16 |
| `Trigger` | `System.Int32` | yes | 16 |
| `TriggerTarget` | `System.Int32` | yes | 16 |
| `TriggerType` | `System.Int32` | yes | 16 |
| `VibrationTrigger` | `System.Int32` | yes | 16 |
| `VibrationType` | `System.Int32` | yes | 16 |

## `soundlib.SoundJointAngleTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BakeCategory` | `System.UInt32` |  | 16 |
| `_JointCenterHash` | `System.UInt32` |  | 20 |
| `_JointAHash` | `System.UInt32` |  | 24 |
| `_JointBHash` | `System.UInt32` |  | 28 |
| `_JointAxis` | `System.Byte` |  | 32 |
| `_AntiRepeatTime` | `System.Single` |  | 36 |
| `_TriggerAll` | `System.Boolean` |  | 40 |
| `_Absolute` | `System.Boolean` |  | 41 |
| `_ThresholdTriggerList` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_Absolute()
:System.Single get_AntiRepeatTime()
:System.UInt32 get_BakeCategory()
:System.UInt32 get_JointAHash()
:System.Byte get_JointAxis()
:System.UInt32 get_JointBHash()
:System.UInt32 get_JointCenterHash()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundJointAngleTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointAngleTriggerParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundJointAngleTriggerParam>` |  | 40 |
| `_PrevMute` | `System.Boolean` |  | 48 |
| `_MotSeq` | `chainsaw.SoundMotionSequenceApp` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointAngleTriggerParam> get_JointAngleTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Boolean isPlayingBakeCategory(System.UInt32)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointAngleTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointAngleTriggerList` | `soundlib.SoundJointAngleTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointAngleTrigger[] get_JointAngleTriggerList()
```

## `soundlib.SoundJointAngleTriggerParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointAngleTrigger>k__BackingField` | `soundlib.SoundJointAngleTrigger` |  | 16 |
| `<ThresholdTriggerList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 24 |
| `<JointCenter>k__BackingField` | `via.Joint` |  | 32 |
| `<JointA>k__BackingField` | `via.Joint` |  | 40 |
| `<JointB>k__BackingField` | `via.Joint` |  | 48 |
| `<VectorA>k__BackingField` | `via.vec3` |  | 64 |
| `<VectorB>k__BackingField` | `via.vec3` |  | 80 |
| `<Angle>k__BackingField` | `System.Single` |  | 96 |
| `<AngularVelocity>k__BackingField` | `System.Single` |  | 100 |
| `<Initialized>k__BackingField` | `System.Boolean` |  | 104 |
| `<Posted>k__BackingField` | `System.Boolean` |  | 105 |
| `<ElapsedTime>k__BackingField` | `System.Single` |  | 108 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundJointAngleTrigger)
:System.Single get_Angle()
:System.Single get_AngularVelocity()
:System.Single get_ElapsedTime()
:System.Boolean get_Initialized()
:via.Joint get_JointA()
:soundlib.SoundJointAngleTrigger get_JointAngleTrigger()
:via.Joint get_JointB()
:via.Joint get_JointCenter()
:System.Boolean get_Posted()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:via.vec3 get_VectorA()
:via.vec3 get_VectorB()
:System.Boolean setAngle()
:System.Void set_Angle(System.Single)
:System.Void set_AngularVelocity(System.Single)
:System.Void set_ElapsedTime(System.Single)
:System.Void set_Initialized(System.Boolean)
:System.Void set_JointA(via.Joint)
:System.Void set_JointAngleTrigger(soundlib.SoundJointAngleTrigger)
:System.Void set_JointB(via.Joint)
:System.Void set_JointCenter(via.Joint)
:System.Void set_Posted(System.Boolean)
:System.Void set_VectorA(via.vec3)
:System.Void set_VectorB(via.vec3)
```

## `soundlib.SoundJointAngleTriggerParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointAngleTriggerParam)
:soundlib.SoundJointAngleTriggerParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointAngleTriggerParam)
:System.Void CopyTo(soundlib.SoundJointAngleTriggerParam[], System.Int32)
:soundlib.SoundJointAngleTriggerParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointAngleTriggerParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointAngleTriggerParam)
:System.Void Insert(System.Int32, soundlib.SoundJointAngleTriggerParam)
:System.Boolean Remove(soundlib.SoundJointAngleTriggerParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointAngleTriggerParam)
:soundlib.SoundJointAngleTriggerParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointAngleTriggerParam)
```

## `soundlib.SoundJointAngleTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointAngleTrigger)
:soundlib.SoundJointAngleTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointAngleTrigger)
:System.Void CopyTo(soundlib.SoundJointAngleTrigger[], System.Int32)
:soundlib.SoundJointAngleTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointAngleTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointAngleTrigger)
:System.Void Insert(System.Int32, soundlib.SoundJointAngleTrigger)
:System.Boolean Remove(soundlib.SoundJointAngleTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointAngleTrigger)
:soundlib.SoundJointAngleTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointAngleTrigger)
```

## `soundlib.SoundJointContactTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_OffsetY` | `System.Single` |  | 16 |
| `_ThresholdDistance` | `System.Single` |  | 20 |
| `_JointHash` | `System.UInt32` |  | 24 |
| `_AntiRepeatTime` | `System.Single` |  | 28 |
| `_ThresholdTriggerList` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Single get_OffsetY()
:System.Single get_ThresholdDistance()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
```

## `soundlib.SoundJointContactTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointContactTriggerParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundJointContactTriggerParam>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointContactTriggerParam> get_JointContactTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointContactTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointContactTriggerList` | `soundlib.SoundJointContactTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointContactTrigger[] get_JointContactTriggerList()
```

## `soundlib.SoundJointContactTriggerParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointContactTrigger>k__BackingField` | `soundlib.SoundJointContactTrigger` |  | 16 |
| `<ThresholdTriggerList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 24 |
| `<CurrentDistance>k__BackingField` | `System.Single` |  | 32 |
| `<CurrentVelocity>k__BackingField` | `System.Single` |  | 36 |
| `<Posted>k__BackingField` | `System.Boolean` |  | 40 |
| `<ElapsedTime>k__BackingField` | `System.Single` |  | 44 |
| `<Contacted>k__BackingField` | `System.Boolean` |  | 48 |
| `<GameObjectPtr>k__BackingField` | `via.GameObject` |  | 56 |
| `<Joint>k__BackingField` | `via.Joint` |  | 64 |
| `<LastPos>k__BackingField` | `via.vec3` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundJointContactTrigger)
:System.UInt32 getTrigger(System.Single)
:System.Boolean get_Contacted()
:System.Single get_CurrentDistance()
:System.Single get_CurrentVelocity()
:System.Single get_ElapsedTime()
:via.GameObject get_GameObjectPtr()
:via.Joint get_Joint()
:soundlib.SoundJointContactTrigger get_JointContactTrigger()
:via.vec3 get_LastPos()
:System.Boolean get_Posted()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean isJustGrounded(System.Single)
:System.Void set_Contacted(System.Boolean)
:System.Void set_CurrentDistance(System.Single)
:System.Void set_CurrentVelocity(System.Single)
:System.Void set_ElapsedTime(System.Single)
:System.Void set_GameObjectPtr(via.GameObject)
:System.Void set_Joint(via.Joint)
:System.Void set_JointContactTrigger(soundlib.SoundJointContactTrigger)
:System.Void set_LastPos(via.vec3)
:System.Void set_Posted(System.Boolean)
```

## `soundlib.SoundJointContactTriggerParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointContactTriggerParam)
:soundlib.SoundJointContactTriggerParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointContactTriggerParam)
:System.Void CopyTo(soundlib.SoundJointContactTriggerParam[], System.Int32)
:soundlib.SoundJointContactTriggerParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointContactTriggerParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointContactTriggerParam)
:System.Void Insert(System.Int32, soundlib.SoundJointContactTriggerParam)
:System.Boolean Remove(soundlib.SoundJointContactTriggerParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointContactTriggerParam)
:soundlib.SoundJointContactTriggerParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointContactTriggerParam)
```

## `soundlib.SoundJointContactTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointContactTrigger)
:soundlib.SoundJointContactTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointContactTrigger)
:System.Void CopyTo(soundlib.SoundJointContactTrigger[], System.Int32)
:soundlib.SoundJointContactTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointContactTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointContactTrigger)
:System.Void Insert(System.Int32, soundlib.SoundJointContactTrigger)
:System.Boolean Remove(soundlib.SoundJointContactTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointContactTrigger)
:soundlib.SoundJointContactTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointContactTrigger)
```

## `soundlib.SoundJointRotationTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointHash` | `System.UInt32` |  | 16 |
| `_AntiRepeatTime` | `System.Single` |  | 20 |
| `_TriggerAll` | `System.Boolean` |  | 24 |
| `_ThresholdTriggerList` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundJointRotationTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointRotationTriggerParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundJointRotationTriggerParam>` |  | 40 |
| `_PrevMute` | `System.Boolean` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointRotationTriggerParam> get_JointRotationTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointRotationTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointRotationTriggerList` | `soundlib.SoundJointRotationTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointRotationTrigger[] get_JointRotationTriggerList()
```

## `soundlib.SoundJointRotationTriggerParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointRotationTrigger>k__BackingField` | `soundlib.SoundJointRotationTrigger` |  | 16 |
| `<ThresholdTriggerList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 24 |
| `<Joint>k__BackingField` | `via.Joint` |  | 32 |
| `<Rotation>k__BackingField` | `via.Quaternion` |  | 48 |
| `<AngularVelocity>k__BackingField` | `System.Single` |  | 64 |
| `<Initialized>k__BackingField` | `System.Boolean` |  | 68 |
| `<Posted>k__BackingField` | `System.Boolean` |  | 69 |
| `<ElapsedTime>k__BackingField` | `System.Single` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundJointRotationTrigger)
:System.Single get_AngularVelocity()
:System.Single get_ElapsedTime()
:System.Boolean get_Initialized()
:via.Joint get_Joint()
:soundlib.SoundJointRotationTrigger get_JointRotationTrigger()
:System.Boolean get_Posted()
:via.Quaternion get_Rotation()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Void set_AngularVelocity(System.Single)
:System.Void set_ElapsedTime(System.Single)
:System.Void set_Initialized(System.Boolean)
:System.Void set_Joint(via.Joint)
:System.Void set_JointRotationTrigger(soundlib.SoundJointRotationTrigger)
:System.Void set_Posted(System.Boolean)
:System.Void set_Rotation(via.Quaternion)
```

## `soundlib.SoundJointRotationTriggerParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointRotationTriggerParam)
:soundlib.SoundJointRotationTriggerParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointRotationTriggerParam)
:System.Void CopyTo(soundlib.SoundJointRotationTriggerParam[], System.Int32)
:soundlib.SoundJointRotationTriggerParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointRotationTriggerParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointRotationTriggerParam)
:System.Void Insert(System.Int32, soundlib.SoundJointRotationTriggerParam)
:System.Boolean Remove(soundlib.SoundJointRotationTriggerParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointRotationTriggerParam)
:soundlib.SoundJointRotationTriggerParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointRotationTriggerParam)
```

## `soundlib.SoundJointRotationTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointRotationTrigger)
:soundlib.SoundJointRotationTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointRotationTrigger)
:System.Void CopyTo(soundlib.SoundJointRotationTrigger[], System.Int32)
:soundlib.SoundJointRotationTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointRotationTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointRotationTrigger)
:System.Void Insert(System.Int32, soundlib.SoundJointRotationTrigger)
:System.Boolean Remove(soundlib.SoundJointRotationTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointRotationTrigger)
:soundlib.SoundJointRotationTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointRotationTrigger)
```

## `soundlib.SoundJointVelocityTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointHash` | `System.UInt32` |  | 16 |
| `_AntiRepeatTime` | `System.Single` |  | 20 |
| `_TriggerAll` | `System.Boolean` |  | 24 |
| `_ThresholdTriggerList` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundJointVelocityTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointVelocityTriggerParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundJointVelocityTriggerParam>` |  | 40 |
| `_PrevMute` | `System.Boolean` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointVelocityTriggerParam> get_JointVelocityTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onWorldOffset(via.vec3)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointVelocityTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointVelocityTriggerList` | `soundlib.SoundJointVelocityTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointVelocityTrigger[] get_JointVelocityTriggerList()
```

## `soundlib.SoundJointVelocityTriggerParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<JointVelocityTrigger>k__BackingField` | `soundlib.SoundJointVelocityTrigger` |  | 16 |
| `<ThresholdTriggerList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 24 |
| `<Joint>k__BackingField` | `via.Joint` |  | 32 |
| `<Position>k__BackingField` | `via.vec3` |  | 48 |
| `<Velocity>k__BackingField` | `System.Single` |  | 64 |
| `<Initialized>k__BackingField` | `System.Boolean` |  | 68 |
| `<Posted>k__BackingField` | `System.Boolean` |  | 69 |
| `<ElapsedTime>k__BackingField` | `System.Single` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundJointVelocityTrigger)
:System.Single get_ElapsedTime()
:System.Boolean get_Initialized()
:via.Joint get_Joint()
:soundlib.SoundJointVelocityTrigger get_JointVelocityTrigger()
:via.vec3 get_Position()
:System.Boolean get_Posted()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Single get_Velocity()
:System.Void set_ElapsedTime(System.Single)
:System.Void set_Initialized(System.Boolean)
:System.Void set_Joint(via.Joint)
:System.Void set_JointVelocityTrigger(soundlib.SoundJointVelocityTrigger)
:System.Void set_Position(via.vec3)
:System.Void set_Posted(System.Boolean)
:System.Void set_Velocity(System.Single)
```

## `soundlib.SoundJointVelocityTriggerParam[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointVelocityTriggerParam)
:soundlib.SoundJointVelocityTriggerParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointVelocityTriggerParam)
:System.Void CopyTo(soundlib.SoundJointVelocityTriggerParam[], System.Int32)
:soundlib.SoundJointVelocityTriggerParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointVelocityTriggerParam> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointVelocityTriggerParam)
:System.Void Insert(System.Int32, soundlib.SoundJointVelocityTriggerParam)
:System.Boolean Remove(soundlib.SoundJointVelocityTriggerParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointVelocityTriggerParam)
:soundlib.SoundJointVelocityTriggerParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointVelocityTriggerParam)
```

## `soundlib.SoundJointVelocityTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundJointVelocityTrigger)
:soundlib.SoundJointVelocityTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundJointVelocityTrigger)
:System.Void CopyTo(soundlib.SoundJointVelocityTrigger[], System.Int32)
:soundlib.SoundJointVelocityTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundJointVelocityTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundJointVelocityTrigger)
:System.Void Insert(System.Int32, soundlib.SoundJointVelocityTrigger)
:System.Boolean Remove(soundlib.SoundJointVelocityTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundJointVelocityTrigger)
:soundlib.SoundJointVelocityTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundJointVelocityTrigger)
```

## `soundlib.SoundListener`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupDebug` | `System.Boolean` | yes | 80 |
| `_MinSpeakerAngleLR` | `System.Single` |  | 80 |
| `_MaxSpeakerAngleLR` | `System.Single` |  | 84 |
| `<OffsetGameObj>k__BackingField` | `via.GameObject` |  | 88 |
| `_ListenerIdx` | `soundlib.SoundListener.ListenerIndex` |  | 96 |
| `_SyncFOV` | `System.Boolean` |  | 100 |
| `_SyncNearClipPlane` | `System.Boolean` |  | 101 |
| `_EnableAxisY` | `System.Boolean` |  | 102 |
| `_InvertAxisZ` | `System.Boolean` |  | 103 |
| `_Offset` | `via.vec3` |  | 112 |
| `_LastPos` | `via.vec3` |  | 128 |
| `_LastAxisX` | `via.vec3` |  | 144 |
| `_LastAxisY` | `via.vec3` |  | 160 |
| `_LastAxisZ` | `via.vec3` |  | 176 |
| `_AngleLR` | `System.Single` |  | 192 |
| `_Camera` | `via.Camera` |  | 200 |
| `_Fov` | `System.Single` |  | 208 |
| `_Activated` | `System.Boolean` |  | 212 |
| `_Update` | `System.Boolean` |  | 213 |

**Methods**

```lua
:System.Void .ctor()
:System.Void activateListener()
:System.Void awake()
:System.Void deactivateListener()
:System.Single get_AngleLR()
:System.Boolean get_EnableAxisY()
:soundlib.SoundListener.ListenerIndex get_ListenerIdx()
:via.GameObject get_OffsetGameObj()
:System.Boolean isEnableListenerUpdate()
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void onDisable()
:System.Void onEnable()
:System.Void setListenerPosition(via.Transform, via.vec3)
:System.Void setListenerUpdated()
:System.Void set_AngleLR(System.Single)
:System.Void set_OffsetGameObj(via.GameObject)
```

## `soundlib.SoundListener.ListenerIndex`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Max` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No0` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No1` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No2` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No3` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No4` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No5` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No6` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `No7` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `None` | `soundlib.SoundListener.ListenerIndex` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundListener.ListenerIndex[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundListener.ListenerIndex)
:soundlib.SoundListener.ListenerIndex Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundListener.ListenerIndex)
:System.Void CopyTo(soundlib.SoundListener.ListenerIndex[], System.Int32)
:soundlib.SoundListener.ListenerIndex Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundListener.ListenerIndex> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundListener.ListenerIndex)
:System.Void Insert(System.Int32, soundlib.SoundListener.ListenerIndex)
:System.Boolean Remove(soundlib.SoundListener.ListenerIndex)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundListener.ListenerIndex)
:soundlib.SoundListener.ListenerIndex get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundListener.ListenerIndex)
```

## `soundlib.SoundListener[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundListener)
:soundlib.SoundListener Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundListener)
:System.Void CopyTo(soundlib.SoundListener[], System.Int32)
:soundlib.SoundListener Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundListener> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundListener)
:System.Void Insert(System.Int32, soundlib.SoundListener)
:System.Boolean Remove(soundlib.SoundListener)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundListener)
:soundlib.SoundListener get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundListener)
```

## `soundlib.SoundLoopTriggerTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Mute` | `soundlib.EnumBool` |  | 16 |
| `TriggerId` | `System.UInt32` |  | 20 |
| `JointHash` | `System.UInt32` |  | 24 |
| `ForceTriggerOverwrittenJoint` | `soundlib.EnumBool` |  | 28 |
| `FadeDuration` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Material>k__BackingField` | `via.simplewwise.Material` | yes | 16 |
| `<UpdateGameObjectStateFreq>k__BackingField` | `System.UInt32` | yes | 24 |
| `<SystemBank>k__BackingField` | `via.simplewwise.BankResourceHolder` | yes | 32 |
| `<SystemGameObjId>k__BackingField` | `System.UInt64` | yes | 40 |
| `<PauseAllEvent>k__BackingField` | `System.UInt32` | yes | 48 |
| `<ResumeAllEvent>k__BackingField` | `System.UInt32` | yes | 52 |
| `<PlayPositionGetterSilentEvent>k__BackingField` | `System.UInt32` | yes | 56 |
| `_VolGameParIdList` | `System.UInt32[]` | yes | 64 |
| `<SpatialAudioManager>k__BackingField` | `chainsaw.SoundSpatialAudioManagerApp` | yes | 72 |
| `OnEndOfEventRequestId` | `System.Action`1<System.UInt32>` | yes | 80 |
| `OnMusicSync` | `System.Action`1<soundlib.SoundManager.MusicSyncInfo>` | yes | 88 |
| `OnMusicSyncExit` | `System.Action`1<soundlib.SoundManager.MusicSyncInfo>` | yes | 96 |
| `OnMusicCustomCue` | `System.Action`1<soundlib.SoundManager.MusicSyncInfo>` | yes | 104 |
| `OnMarker` | `System.Action`1<soundlib.SoundManager.MarkerInfo>` | yes | 112 |
| `OnDuration` | `System.Action`1<soundlib.SoundManager.DurationInfo>` | yes | 120 |
| `OnTriggerStart` | `System.Action`1<System.UInt32>` | yes | 128 |
| `_StartTriggerQueue` | `System.Collections.Generic.Queue`1<System.UInt32>` | yes | 136 |
| `OnTriggerEnd` | `System.Action`1<System.UInt32>` | yes | 144 |
| `_EndTriggerQueue` | `System.Collections.Generic.Queue`1<System.UInt32>` | yes | 152 |
| `_GameObjectInfoDict` | `System.Collections.Generic.Dictionary`2<System.UInt64,soundlib.SoundManager.GameObjectInfo>` | yes | 160 |
| `_RequestInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 168 |
| `_RequestInfoDict` | `System.Collections.Generic.Dictionary`2<System.UInt32,soundlib.SoundManager.RequestInfo>` | yes | 176 |
| `_UpdatedReqIdPlayingIdQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`2<System.UInt32,System.UInt32>>` | yes | 184 |
| `_EndOfEventQueue` | `System.Collections.Generic.Queue`1<via.simplewwise.EventCallbackInfo>` | yes | 192 |
| `_EndOfReqIdQueue` | `System.Collections.Generic.Queue`1<System.UInt32>` | yes | 200 |
| `_EndedReqIdGameObjIdQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`2<System.UInt32,System.UInt64>>` | yes | 208 |
| `_UnloadContainerResourcesQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`3<System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>,System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder>,System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder>>>` | yes | 216 |
| `_ResidualResourcesDict` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.ValueTuple`2<System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder>,System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder>>>` | yes | 224 |
| `_StoppedEventParametersList` | `System.Collections.Generic.List`1<System.ValueTuple`4<via.GameObject,System.UInt32,System.UInt32,soundlib.SoundManager.StoppedEventType>>` | yes | 232 |
| `_CullingInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 240 |
| `_CullingCache` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 248 |
| `_RemoveCullingCache` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 256 |
| `_VirtualReqInfoQueue` | `System.Collections.Generic.Queue`1<soundlib.SoundManager.RequestInfo>` | yes | 264 |
| `_VirtualReqInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 272 |
| `_SyncDrawReqInfoQueue` | `System.Collections.Generic.Queue`1<soundlib.SoundManager.RequestInfo>` | yes | 280 |
| `_SyncDrawReqInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` | yes | 288 |
| `_MusicSyncCallbackInfoQueue` | `System.Collections.Generic.Queue`1<via.simplewwise.MusicSyncCallbackInfo>` | yes | 296 |
| `_MusicSyncInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.MusicSyncInfo>` | yes | 304 |
| `_MarkerCallbackInfoQueue` | `System.Collections.Generic.Queue`1<via.simplewwise.MarkerCallbackInfo>` | yes | 312 |
| `_DurationCallbackInfoQueue` | `System.Collections.Generic.Queue`1<via.simplewwise.DurationCallbackInfo>` | yes | 320 |
| `_GetGameParameterParamQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundGetGameParameterParam,System.Boolean>>` | yes | 328 |
| `_GetGameParameterParamList` | `System.Collections.Generic.List`1<soundlib.SoundGetGameParameterParam>` | yes | 336 |
| `_AudioInputList` | `System.Collections.Generic.List`1<soundlib.SoundAudioInput>` | yes | 344 |
| `_Rand` | `via.Random` | yes | 352 |
| `<Initialized>k__BackingField` | `System.Boolean` | yes | 360 |
| `<CurrentFrame>k__BackingField` | `System.UInt32` | yes | 364 |
| `<CurrentStateDict>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>` | yes | 368 |
| `<SaveStateInfoList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundManager.SaveStateInfo>` | yes | 376 |
| `<MuteAutoTrigger>k__BackingField` | `System.Boolean` | yes | 384 |
| `<SrcPositionUpdateFreq>k__BackingField` | `System.Byte` | yes | 385 |
| `<GameParameterUpdateFreq>k__BackingField` | `System.Byte` | yes | 386 |
| `<BypassGameParameterInterpolationOnPlay>k__BackingField` | `System.Boolean` | yes | 387 |
| `<GeneratorClosestUpdateFreq>k__BackingField` | `System.UInt32` | yes | 388 |
| `_SoundListeners` | `soundlib.SoundListener[]` | yes | 392 |
| `_HalfwayPlayClipCount` | `System.UInt32` | yes | 400 |
| `_OverrideStateList` | `System.Collections.Generic.List`1<soundlib.SoundOverrideState>` | yes | 408 |
| `_GameParameterAppInfoDict` | `System.Collections.Generic.Dictionary`2<System.UInt64,System.Collections.Generic.List`1<soundlib.SoundManager.GameParameterAppInfo>>` | yes | 416 |
| `_GlobalGameParameterAppInfoList` | `System.Collections.Generic.List`1<soundlib.SoundManager.GameParameterAppInfo>` | yes | 424 |
| `_StateAppDict` | `System.Collections.Generic.Dictionary`2<soundlib.SoundStateAppParamBase,System.Int32>` | yes | 432 |
| `_GuvSetStateParamList` | `System.Collections.Generic.HashSet`1<soundlib.SoundGuvSetStateParam>` | yes | 440 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "<postRequestInfo>g__culling|107_0", ...)  -- System.Boolean <postRequestInfo>g__culling|107_0(soundlib.SoundManager.<>c__DisplayClass107_0)
sdk.call_native_func(nil, type_def, "<updateQueue>g__addGetGameParameter|130_0", ...)  -- System.Void <updateQueue>g__addGetGameParameter|130_0(soundlib.SoundGetGameParameterParam)
sdk.call_native_func(nil, type_def, "<updateQueue>g__removeGetGameParameter|130_1", ...)  -- System.Void <updateQueue>g__removeGetGameParameter|130_1(soundlib.SoundGetGameParameterParam)
sdk.call_native_func(nil, type_def, "<updateRemoveRequest>g__removeMusicSync|122_0", ...)  -- System.Void <updateRemoveRequest>g__removeMusicSync|122_0(System.UInt32)
sdk.call_native_func(nil, type_def, "<updateStopEvent>g__removeParam|120_0", ...)  -- System.Void <updateStopEvent>g__removeParam|120_0(soundlib.SoundManager.<>c__DisplayClass120_0)
sdk.call_native_func(nil, type_def, "addGameObjectInfo", ...)  -- soundlib.SoundManager.GameObjectInfo addGameObjectInfo(soundlib.SoundManager.RequestInfo)
sdk.call_native_func(nil, type_def, "addGameParameterApp", ...)  -- System.Void addGameParameterApp(System.UInt64, System.UInt32, soundlib.SoundGameParameterAppParam)
sdk.call_native_func(nil, type_def, "addGetGameParameter", ...)  -- System.Void addGetGameParameter(soundlib.SoundGetGameParameterParam)
sdk.call_native_func(nil, type_def, "addGloablGameParameterApp", ...)  -- System.Void addGloablGameParameterApp(soundlib.SoundGameParameterAppParam)
sdk.call_native_func(nil, type_def, "addGuvSetStateParam", ...)  -- System.Void addGuvSetStateParam(soundlib.SoundGuvSetStateParam)
sdk.call_native_func(nil, type_def, "addListener", ...)  -- System.Void addListener(soundlib.SoundListener)
sdk.call_native_func(nil, type_def, "addOverrideStateList", ...)  -- System.Void addOverrideStateList(soundlib.SoundOverrideState)
sdk.call_native_func(nil, type_def, "addStateApp", ...)  -- System.Void addStateApp(soundlib.SoundStateAppParamBase)
sdk.call_native_func(nil, type_def, "add_OnDuration", ...)  -- System.Void add_OnDuration(System.Action`1<soundlib.SoundManager.DurationInfo>)
sdk.call_native_func(nil, type_def, "add_OnEndOfEventRequestId", ...)  -- System.Void add_OnEndOfEventRequestId(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "add_OnMarker", ...)  -- System.Void add_OnMarker(System.Action`1<soundlib.SoundManager.MarkerInfo>)
sdk.call_native_func(nil, type_def, "add_OnMusicCustomCue", ...)  -- System.Void add_OnMusicCustomCue(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "add_OnMusicSync", ...)  -- System.Void add_OnMusicSync(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "add_OnMusicSyncExit", ...)  -- System.Void add_OnMusicSyncExit(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "add_OnTriggerEnd", ...)  -- System.Void add_OnTriggerEnd(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "add_OnTriggerStart", ...)  -- System.Void add_OnTriggerStart(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "decHalfwayPlayClipCount", ...)  -- System.Void decHalfwayPlayClipCount()
sdk.call_native_func(nil, type_def, "existHalfwayPlayClip", ...)  -- System.Boolean existHalfwayPlayClip()
sdk.call_native_func(nil, type_def, "getListener", ...)  -- soundlib.SoundListener getListener(soundlib.SoundListener.ListenerIndex)
sdk.call_native_func(nil, type_def, "get_BypassGameParameterInterpolationOnPlay", ...)  -- System.Boolean get_BypassGameParameterInterpolationOnPlay()
sdk.call_native_func(nil, type_def, "get_CurrentFrame", ...)  -- System.UInt32 get_CurrentFrame()
sdk.call_native_func(nil, type_def, "get_CurrentStateDict", ...)  -- System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32> get_CurrentStateDict()
sdk.call_native_func(nil, type_def, "get_GameParameterUpdateFreq", ...)  -- System.Byte get_GameParameterUpdateFreq()
sdk.call_native_func(nil, type_def, "get_GeneratorClosestUpdateFreq", ...)  -- System.UInt32 get_GeneratorClosestUpdateFreq()
sdk.call_native_func(nil, type_def, "get_Initialized", ...)  -- System.Boolean get_Initialized()
sdk.call_native_func(nil, type_def, "get_Material", ...)  -- via.simplewwise.Material get_Material()
sdk.call_native_func(nil, type_def, "get_MuteAutoTrigger", ...)  -- System.Boolean get_MuteAutoTrigger()
sdk.call_native_func(nil, type_def, "get_PauseAllEvent", ...)  -- System.UInt32 get_PauseAllEvent()
sdk.call_native_func(nil, type_def, "get_PlayPositionGetterSilentEvent", ...)  -- System.UInt32 get_PlayPositionGetterSilentEvent()
sdk.call_native_func(nil, type_def, "get_ResumeAllEvent", ...)  -- System.UInt32 get_ResumeAllEvent()
sdk.call_native_func(nil, type_def, "get_SaveStateInfoList", ...)  -- System.Collections.Generic.List`1<soundlib.SoundManager.SaveStateInfo> get_SaveStateInfoList()
sdk.call_native_func(nil, type_def, "get_SpatialAudioManager", ...)  -- chainsaw.SoundSpatialAudioManagerApp get_SpatialAudioManager()
sdk.call_native_func(nil, type_def, "get_SrcPositionUpdateFreq", ...)  -- System.Byte get_SrcPositionUpdateFreq()
sdk.call_native_func(nil, type_def, "get_SystemBank", ...)  -- via.simplewwise.BankResourceHolder get_SystemBank()
sdk.call_native_func(nil, type_def, "get_SystemGameObjId", ...)  -- System.UInt64 get_SystemGameObjId()
sdk.call_native_func(nil, type_def, "get_UpdateGameObjectStateFreq", ...)  -- System.UInt32 get_UpdateGameObjectStateFreq()
sdk.call_native_func(nil, type_def, "get_VolGameParIdList", ...)  -- System.UInt32[] get_VolGameParIdList()
sdk.call_native_func(nil, type_def, "incCurrentFrame", ...)  -- System.Void incCurrentFrame()
sdk.call_native_func(nil, type_def, "incHalfwayPlayClipCount", ...)  -- System.Void incHalfwayPlayClipCount()
sdk.call_native_func(nil, type_def, "initialize", ...)  -- System.Void initialize(soundlib.SoundManagerSettings)
sdk.call_native_func(nil, type_def, "onDeletedRequestIdGameObjectIdPairThisFrame", ...)  -- System.Void onDeletedRequestIdGameObjectIdPairThisFrame(System.UInt32, System.UInt64)
sdk.call_native_func(nil, type_def, "onDuration", ...)  -- System.Void onDuration(via.simplewwise.DurationCallbackInfo)
sdk.call_native_func(nil, type_def, "onEndOfEvent", ...)  -- System.Void onEndOfEvent(via.simplewwise.EventCallbackInfo)
sdk.call_native_func(nil, type_def, "onMarker", ...)  -- System.Void onMarker(via.simplewwise.MarkerCallbackInfo)
sdk.call_native_func(nil, type_def, "onMusicSync", ...)  -- System.Void onMusicSync(via.simplewwise.MusicSyncCallbackInfo)
sdk.call_native_func(nil, type_def, "onPostedRequstIdPlayingIdPairThisFrame", ...)  -- System.Void onPostedRequstIdPlayingIdPairThisFrame(System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "pauseAll", ...)  -- System.Void pauseAll()
sdk.call_native_func(nil, type_def, "postEvent", ...)  -- System.Void postEvent(System.UInt64, System.UInt32, System.UInt32, via.simplewwise.CallbackType, System.Boolean, System.Int32, via.wwiselib.CurveInterpolationType)
sdk.call_native_func(nil, type_def, "postRequestInfo", ...)  -- System.UInt32 postRequestInfo(soundlib.SoundManager.RequestInfo)
sdk.call_native_func(nil, type_def, "registerSpatialAudioManager", ...)  -- System.Void registerSpatialAudioManager(soundlib.SoundSpatialAudioManager)
sdk.call_native_func(nil, type_def, "removeGameParameterApp", ...)  -- System.Void removeGameParameterApp(System.UInt64, System.UInt32)
sdk.call_native_func(nil, type_def, "removeGetGameParameter", ...)  -- System.Void removeGetGameParameter(soundlib.SoundGetGameParameterParam)
sdk.call_native_func(nil, type_def, "removeGlobalGameParameterApp", ...)  -- System.Void removeGlobalGameParameterApp(soundlib.SoundGameParameterAppParam)
sdk.call_native_func(nil, type_def, "removeGuvSetStateParam", ...)  -- System.Void removeGuvSetStateParam(soundlib.SoundGuvSetStateParam)
sdk.call_native_func(nil, type_def, "removeListener", ...)  -- System.Void removeListener(soundlib.SoundListener)
sdk.call_native_func(nil, type_def, "removeOverrideStateList", ...)  -- System.Void removeOverrideStateList(soundlib.SoundOverrideState)
sdk.call_native_func(nil, type_def, "removeRequestInfo", ...)  -- System.Void removeRequestInfo(System.UInt32)
sdk.call_native_func(nil, type_def, "removeStateApp", ...)  -- System.Void removeStateApp(soundlib.SoundStateAppParamBase)
sdk.call_native_func(nil, type_def, "remove_OnDuration", ...)  -- System.Void remove_OnDuration(System.Action`1<soundlib.SoundManager.DurationInfo>)
sdk.call_native_func(nil, type_def, "remove_OnEndOfEventRequestId", ...)  -- System.Void remove_OnEndOfEventRequestId(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "remove_OnMarker", ...)  -- System.Void remove_OnMarker(System.Action`1<soundlib.SoundManager.MarkerInfo>)
sdk.call_native_func(nil, type_def, "remove_OnMusicCustomCue", ...)  -- System.Void remove_OnMusicCustomCue(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "remove_OnMusicSync", ...)  -- System.Void remove_OnMusicSync(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "remove_OnMusicSyncExit", ...)  -- System.Void remove_OnMusicSyncExit(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
sdk.call_native_func(nil, type_def, "remove_OnTriggerEnd", ...)  -- System.Void remove_OnTriggerEnd(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "remove_OnTriggerStart", ...)  -- System.Void remove_OnTriggerStart(System.Action`1<System.UInt32>)
sdk.call_native_func(nil, type_def, "resetState", ...)  -- System.Void resetState(System.UInt32)
sdk.call_native_func(nil, type_def, "resumeAll", ...)  -- System.Void resumeAll()
sdk.call_native_func(nil, type_def, "setRtpcValue", ...)  -- System.Void setRtpcValue(System.UInt64, System.UInt32, System.Single, System.Boolean, System.Single, System.Boolean)
sdk.call_native_func(nil, type_def, "setState", ...)  -- System.Void setState(System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "set_BypassGameParameterInterpolationOnPlay", ...)  -- System.Void set_BypassGameParameterInterpolationOnPlay(System.Boolean)
sdk.call_native_func(nil, type_def, "set_CurrentFrame", ...)  -- System.Void set_CurrentFrame(System.UInt32)
sdk.call_native_func(nil, type_def, "set_CurrentStateDict", ...)  -- System.Void set_CurrentStateDict(System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>)
sdk.call_native_func(nil, type_def, "set_GameParameterUpdateFreq", ...)  -- System.Void set_GameParameterUpdateFreq(System.Byte)
sdk.call_native_func(nil, type_def, "set_GeneratorClosestUpdateFreq", ...)  -- System.Void set_GeneratorClosestUpdateFreq(System.UInt32)
sdk.call_native_func(nil, type_def, "set_Initialized", ...)  -- System.Void set_Initialized(System.Boolean)
sdk.call_native_func(nil, type_def, "set_MuteAutoTrigger", ...)  -- System.Void set_MuteAutoTrigger(System.Boolean)
sdk.call_native_func(nil, type_def, "set_PauseAllEvent", ...)  -- System.Void set_PauseAllEvent(System.UInt32)
sdk.call_native_func(nil, type_def, "set_PlayPositionGetterSilentEvent", ...)  -- System.Void set_PlayPositionGetterSilentEvent(System.UInt32)
sdk.call_native_func(nil, type_def, "set_ResumeAllEvent", ...)  -- System.Void set_ResumeAllEvent(System.UInt32)
sdk.call_native_func(nil, type_def, "set_SaveStateInfoList", ...)  -- System.Void set_SaveStateInfoList(System.Collections.Generic.List`1<soundlib.SoundManager.SaveStateInfo>)
sdk.call_native_func(nil, type_def, "set_SpatialAudioManager", ...)  -- System.Void set_SpatialAudioManager(chainsaw.SoundSpatialAudioManagerApp)
sdk.call_native_func(nil, type_def, "set_SrcPositionUpdateFreq", ...)  -- System.Void set_SrcPositionUpdateFreq(System.Byte)
sdk.call_native_func(nil, type_def, "set_SystemBank", ...)  -- System.Void set_SystemBank(via.simplewwise.BankResourceHolder)
sdk.call_native_func(nil, type_def, "set_UpdateGameObjectStateFreq", ...)  -- System.Void set_UpdateGameObjectStateFreq(System.UInt32)
sdk.call_native_func(nil, type_def, "set_VolGameParIdList", ...)  -- System.Void set_VolGameParIdList(System.UInt32[])
sdk.call_native_func(nil, type_def, "stopAll", ...)  -- System.Void stopAll()
sdk.call_native_func(nil, type_def, "stopEvent", ...)  -- System.Void stopEvent(via.GameObject, System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "stopEvent", ...)  -- System.Void stopEvent(System.UInt32[], System.UInt32)
sdk.call_native_func(nil, type_def, "stopEventByRequestId", ...)  -- System.Void stopEventByRequestId(via.GameObject, System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "stopEventTarget", ...)  -- System.Void stopEventTarget(via.GameObject, System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "terminate", ...)  -- System.Void terminate()
sdk.call_native_func(nil, type_def, "unloadContainer", ...)  -- System.Void unloadContainer(soundlib.SoundContainer)
sdk.call_native_func(nil, type_def, "unregisterSpatialAudioManager", ...)  -- System.Void unregisterSpatialAudioManager()
sdk.call_native_func(nil, type_def, "update", ...)  -- System.Void update()
sdk.call_native_func(nil, type_def, "updateCulling", ...)  -- System.Void updateCulling()
sdk.call_native_func(nil, type_def, "updateDuration", ...)  -- System.Void updateDuration()
sdk.call_native_func(nil, type_def, "updateEndOfEvent", ...)  -- System.Void updateEndOfEvent()
sdk.call_native_func(nil, type_def, "updateEndOfEventRequestId", ...)  -- System.Void updateEndOfEventRequestId()
sdk.call_native_func(nil, type_def, "updateGameObjectState", ...)  -- System.Void updateGameObjectState()
sdk.call_native_func(nil, type_def, "updateGameParameter", ...)  -- System.Void updateGameParameter()
sdk.call_native_func(nil, type_def, "updateMarker", ...)  -- System.Void updateMarker()
sdk.call_native_func(nil, type_def, "updateMusicSync", ...)  -- System.Void updateMusicSync()
sdk.call_native_func(nil, type_def, "updatePlayingId", ...)  -- System.Void updatePlayingId()
sdk.call_native_func(nil, type_def, "updatePosition", ...)  -- System.Void updatePosition(System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "updatePostRequestInfo", ...)  -- System.Void updatePostRequestInfo()
sdk.call_native_func(nil, type_def, "updateQueue", ...)  -- System.Void updateQueue()
sdk.call_native_func(nil, type_def, "updateRemoveRequest", ...)  -- System.Void updateRemoveRequest()
sdk.call_native_func(nil, type_def, "updateRtpcValue", ...)  -- System.Void updateRtpcValue()
sdk.call_native_func(nil, type_def, "updateState", ...)  -- System.Void updateState()
sdk.call_native_func(nil, type_def, "updateStopEvent", ...)  -- System.Void updateStopEvent()
sdk.call_native_func(nil, type_def, "updateSyncDraw", ...)  -- System.Void updateSyncDraw()
sdk.call_native_func(nil, type_def, "updateUnloadContainer", ...)  -- System.Void updateUnloadContainer()
sdk.call_native_func(nil, type_def, "updateVirtualDistance", ...)  -- System.Void updateVirtualDistance(System.Int32)
```

## `soundlib.SoundManager.DurationInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameObjectId>k__BackingField` | `System.UInt64` |  | 16 |
| `<RequestId>k__BackingField` | `System.UInt32` |  | 24 |
| `<TriggerId>k__BackingField` | `System.UInt32` |  | 28 |
| `<MediaId>k__BackingField` | `System.UInt32` |  | 32 |
| `<EstimatedDuration>k__BackingField` | `System.Single` |  | 36 |

**Methods**

```lua
:System.Void .ctor(System.UInt64, System.UInt32, System.UInt32, System.UInt32, System.Single)
:System.Single get_EstimatedDuration()
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MediaId()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
```

## `soundlib.SoundManager.GameObjectInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RequestInfoList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo>` |  | 16 |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 24 |
| `<JointHash>k__BackingField` | `System.UInt32` |  | 32 |
| `<GameObjId>k__BackingField` | `System.UInt64` |  | 40 |
| `<Position>k__BackingField` | `via.vec3` |  | 48 |
| `<Forward>k__BackingField` | `via.vec3` |  | 64 |
| `<Top>k__BackingField` | `via.vec3` |  | 80 |
| `<ListenerMask>k__BackingField` | `System.UInt32` |  | 96 |
| `<Positioned>k__BackingField` | `System.Boolean` |  | 100 |
| `<OffsetFollowReqCount>k__BackingField` | `System.Int32` |  | 104 |
| `<NeedToUpdatePosition>k__BackingField` | `System.Boolean` |  | 108 |
| `<Rotation>k__BackingField` | `System.Boolean` |  | 109 |
| `<SetRoom>k__BackingField` | `System.Boolean` |  | 110 |
| `<SrcSpace>k__BackingField` | `System.UInt32` |  | 112 |
| `<RoomId>k__BackingField` | `System.UInt64` |  | 120 |
| `UpdateGameObject` | `System.Boolean` |  | 128 |
| `DrawGameObject` | `System.Boolean` |  | 129 |
| `<LastRoomChangedFrame>k__BackingField` | `System.UInt32` |  | 132 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundManager.RequestInfo)
:System.Void addRequestInfo(soundlib.SoundManager.RequestInfo)
:via.vec3 get_Forward()
:System.UInt64 get_GameObjId()
:via.GameObject get_GameObject()
:System.UInt32 get_JointHash()
:System.UInt32 get_LastRoomChangedFrame()
:System.UInt32 get_ListenerMask()
:System.Boolean get_NeedToUpdatePosition()
:System.Int32 get_OffsetFollowReqCount()
:via.vec3 get_Position()
:System.Boolean get_Positioned()
:System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> get_RequestInfoList()
:System.UInt64 get_RoomId()
:System.Boolean get_Rotation()
:System.Boolean get_SetRoom()
:System.UInt32 get_SrcSpace()
:via.vec3 get_Top()
:System.Void removeRequestInfo(soundlib.SoundManager.RequestInfo)
:System.Boolean setPosition(via.vec3, via.vec3, via.vec3)
:System.Void set_Forward(via.vec3)
:System.Void set_LastRoomChangedFrame(System.UInt32)
:System.Void set_ListenerMask(System.UInt32)
:System.Void set_NeedToUpdatePosition(System.Boolean)
:System.Void set_OffsetFollowReqCount(System.Int32)
:System.Void set_Position(via.vec3)
:System.Void set_RoomId(System.UInt64)
:System.Void set_Rotation(System.Boolean)
:System.Void set_SetRoom(System.Boolean)
:System.Void set_SrcSpace(System.UInt32)
:System.Void set_Top(via.vec3)
```

## `soundlib.SoundManager.GameObjectInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.GameObjectInfo)
:soundlib.SoundManager.GameObjectInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.GameObjectInfo)
:System.Void CopyTo(soundlib.SoundManager.GameObjectInfo[], System.Int32)
:soundlib.SoundManager.GameObjectInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.GameObjectInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.GameObjectInfo)
:System.Void Insert(System.Int32, soundlib.SoundManager.GameObjectInfo)
:System.Boolean Remove(soundlib.SoundManager.GameObjectInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.GameObjectInfo)
:soundlib.SoundManager.GameObjectInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.GameObjectInfo)
```

## `soundlib.SoundManager.GameParameterAppInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameParameterAppParam>k__BackingField` | `soundlib.SoundGameParameterAppParam` |  | 16 |
| `<GameObjId>k__BackingField` | `System.UInt64` |  | 24 |
| `<RtpcId>k__BackingField` | `System.UInt32` |  | 32 |
| `<Global>k__BackingField` | `System.Boolean` |  | 36 |
| `<LastValue>k__BackingField` | `System.Single` |  | 40 |
| `<Frame>k__BackingField` | `System.UInt32` |  | 44 |
| `<Count>k__BackingField` | `System.UInt32` |  | 48 |
| `<RequestIdSet>k__BackingField` | `System.Collections.Generic.HashSet`1<System.UInt32>` |  | 56 |

**Methods**

```lua
:System.Void .ctor(soundlib.SoundGameParameterAppParam, System.UInt64, System.UInt32)
:System.Void .ctor(soundlib.SoundGameParameterAppParam, System.UInt64, System.UInt32, System.UInt32)
:System.UInt32 get_Count()
:System.UInt32 get_Frame()
:System.UInt64 get_GameObjId()
:soundlib.SoundGameParameterAppParam get_GameParameterAppParam()
:System.Boolean get_Global()
:System.Single get_LastValue()
:System.Collections.Generic.HashSet`1<System.UInt32> get_RequestIdSet()
:System.UInt32 get_RtpcId()
:System.Void setRtpcValue()
:System.Void set_Count(System.UInt32)
:System.Void set_Frame(System.UInt32)
:System.Void set_LastValue(System.Single)
```

## `soundlib.SoundManager.GameParameterAppInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.GameParameterAppInfo)
:soundlib.SoundManager.GameParameterAppInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.GameParameterAppInfo)
:System.Void CopyTo(soundlib.SoundManager.GameParameterAppInfo[], System.Int32)
:soundlib.SoundManager.GameParameterAppInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.GameParameterAppInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.GameParameterAppInfo)
:System.Void Insert(System.Int32, soundlib.SoundManager.GameParameterAppInfo)
:System.Boolean Remove(soundlib.SoundManager.GameParameterAppInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.GameParameterAppInfo)
:soundlib.SoundManager.GameParameterAppInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.GameParameterAppInfo)
```

## `soundlib.SoundManager.MarkerInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameObjectId>k__BackingField` | `System.UInt64` |  | 16 |
| `<RequestId>k__BackingField` | `System.UInt32` |  | 24 |
| `<TriggerId>k__BackingField` | `System.UInt32` |  | 28 |
| `<MarkerHash>k__BackingField` | `System.UInt32` |  | 32 |

**Methods**

```lua
:System.Void .ctor(System.UInt64, System.UInt32, System.UInt32, System.UInt32)
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MarkerHash()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
```

## `soundlib.SoundManager.MusicSyncInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameObjectId>k__BackingField` | `System.UInt64` |  | 16 |
| `<MusicSyncBeat>k__BackingField` | `System.UInt32` |  | 24 |
| `<MusicSyncBar>k__BackingField` | `System.UInt32` |  | 28 |
| `<MusicCustomCueNameHash>k__BackingField` | `System.UInt32` |  | 32 |
| `<RequestId>k__BackingField` | `System.UInt32` |  | 36 |
| `<TriggerId>k__BackingField` | `System.UInt32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.UInt64, System.UInt32, System.UInt32, System.UInt32)
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MusicCustomCueNameHash()
:System.UInt32 get_MusicSyncBar()
:System.UInt32 get_MusicSyncBeat()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
:System.Void set_MusicSyncBar(System.UInt32)
:System.Void set_MusicSyncBeat(System.UInt32)
```

## `soundlib.SoundManager.MusicSyncInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.MusicSyncInfo)
:soundlib.SoundManager.MusicSyncInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.MusicSyncInfo)
:System.Void CopyTo(soundlib.SoundManager.MusicSyncInfo[], System.Int32)
:soundlib.SoundManager.MusicSyncInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.MusicSyncInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.MusicSyncInfo)
:System.Void Insert(System.Int32, soundlib.SoundManager.MusicSyncInfo)
:System.Boolean Remove(soundlib.SoundManager.MusicSyncInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.MusicSyncInfo)
:soundlib.SoundManager.MusicSyncInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.MusicSyncInfo)
```

## `soundlib.SoundManager.RequestInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RequestId>k__BackingField` | `System.UInt32` |  | 160 |
| `<PlayingId>k__BackingField` | `System.UInt32` |  | 164 |
| `<Playing>k__BackingField` | `System.Boolean` |  | 168 |
| `<SrcGameObj>k__BackingField` | `via.GameObject` |  | 176 |
| `<GameObjId>k__BackingField` | `System.UInt64` |  | 184 |
| `<GameObjectRegistered>k__BackingField` | `System.Boolean` |  | 192 |
| `<TargetGameObj>k__BackingField` | `via.GameObject` |  | 200 |
| `<Container>k__BackingField` | `soundlib.SoundContainer` |  | 208 |
| `<Symmetry>k__BackingField` | `System.Boolean` |  | 216 |
| `<Positioned>k__BackingField` | `System.Boolean` |  | 217 |
| `<Offset>k__BackingField` | `System.Boolean` |  | 218 |
| `<SeekTime>k__BackingField` | `System.UInt32` |  | 220 |
| `<Callback>k__BackingField` | `via.simplewwise.CallbackType` |  | 224 |
| `<Position>k__BackingField` | `via.vec3` |  | 240 |
| `<Forward>k__BackingField` | `via.vec3` |  | 256 |
| `<Top>k__BackingField` | `via.vec3` |  | 272 |
| `<AttenuationScalingFactor>k__BackingField` | `System.Single` |  | 288 |
| `<ForceTriggerOverwrittenJoint>k__BackingField` | `System.Boolean` |  | 292 |
| `<RoomId>k__BackingField` | `System.UInt64` |  | 296 |
| `<PlayEnded>k__BackingField` | `System.Boolean` |  | 304 |
| `<LeftBookingTime>k__BackingField` | `System.Single` |  | 308 |
| `<LeftFlangingTime>k__BackingField` | `System.Single` |  | 312 |
| `<VirtualRangeSq>k__BackingField` | `System.Single` |  | 316 |
| `<SwitchInfoDict>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>` |  | 320 |
| `<IsAudioInputEvent>k__BackingField` | `System.Boolean` |  | 328 |
| `<ContainerUnloaded>k__BackingField` | `System.Boolean` |  | 329 |
| `OnPostRequestInfoStart` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 336 |
| `OnPostRequestInfoEnd` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 344 |
| `OnPostEventStart` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 352 |
| `OnEndOfEvent` | `System.Action`1<soundlib.SoundManager.RequestInfo>` |  | 360 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundTriggerInfo)
:System.Void add_OnEndOfEvent(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void add_OnPostEventStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void add_OnPostRequestInfoEnd(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void add_OnPostRequestInfoStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void clear()
:System.Int32 comparePriority(soundlib.SoundManager.RequestInfo)
:System.Single get_AttenuationScalingFactor()
:via.simplewwise.CallbackType get_Callback()
:soundlib.SoundContainer get_Container()
:System.Boolean get_ContainerUnloaded()
:System.UInt32 get_EventId()
:System.Boolean get_ForceTriggerOverwrittenJoint()
:via.vec3 get_Forward()
:System.UInt64 get_GameObjId()
:System.Boolean get_GameObjectRegistered()
:System.Boolean get_Invalid()
:System.Boolean get_IsAudioInputEvent()
:System.Single get_LeftBookingTime()
:System.Single get_LeftFlangingTime()
:System.Byte get_ListenerBitMask()
:System.Boolean get_Offset()
:System.Boolean get_OffsetFollow()
:System.UInt32 get_OffsetJointHash()
:soundlib.SoundListener.ListenerIndex get_OffsetLisIdx()
:System.Boolean get_PlayEnded()
:System.Boolean get_Playing()
:System.UInt32 get_PlayingId()
:via.vec3 get_Position()
:System.Boolean get_Positioned()
:System.UInt32 get_RequestId()
:System.UInt64 get_RoomId()
:System.UInt32 get_SeekTime()
:via.GameObject get_SrcGameObj()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32> get_SwitchInfoDict()
:System.Boolean get_Symmetry()
:via.GameObject get_TargetGameObj()
:via.vec3 get_Top()
:System.UInt32 get_TriggerId()
:System.Single get_VirtualRangeSq()
:System.Boolean initPosition()
:System.Void onEndOfEventInvoke()
:System.Void onPostEventStartInvoke()
:System.Void onPostRequestInfoEndInvoke()
:System.Void onPostRequestInfoStartInvoke()
:System.Void remove_OnEndOfEvent(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void remove_OnPostEventStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void remove_OnPostRequestInfoEnd(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void remove_OnPostRequestInfoStart(System.Action`1<soundlib.SoundManager.RequestInfo>)
:System.Void set_AttenuationScalingFactor(System.Single)
:System.Void set_Callback(via.simplewwise.CallbackType)
:System.Void set_Container(soundlib.SoundContainer)
:System.Void set_ContainerUnloaded(System.Boolean)
:System.Void set_EventId(System.UInt32)
:System.Void set_ForceTriggerOverwrittenJoint(System.Boolean)
:System.Void set_Forward(via.vec3)
:System.Void set_GameObjId(System.UInt64)
:System.Void set_GameObjectRegistered(System.Boolean)
:System.Void set_IsAudioInputEvent(System.Boolean)
:System.Void set_LeftBookingTime(System.Single)
:System.Void set_LeftFlangingTime(System.Single)
:System.Void set_ListenerBitMask(System.Byte)
:System.Void set_Offset(System.Boolean)
:System.Void set_OffsetFollow(System.Boolean)
:System.Void set_OffsetJointHash(System.UInt32)
:System.Void set_OffsetLisIdx(soundlib.SoundListener.ListenerIndex)
:System.Void set_PlayEnded(System.Boolean)
:System.Void set_Playing(System.Boolean)
:System.Void set_PlayingId(System.UInt32)
:System.Void set_Position(via.vec3)
:System.Void set_Positioned(System.Boolean)
:System.Void set_RequestId(System.UInt32)
:System.Void set_RoomId(System.UInt64)
:System.Void set_SeekTime(System.UInt32)
:System.Void set_SrcGameObj(via.GameObject)
:System.Void set_Symmetry(System.Boolean)
:System.Void set_TargetGameObj(via.GameObject)
:System.Void set_Top(via.vec3)
:System.Void set_TriggerId(System.UInt32)
```

## `soundlib.SoundManager.RequestInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.RequestInfo)
:soundlib.SoundManager.RequestInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.RequestInfo)
:System.Void CopyTo(soundlib.SoundManager.RequestInfo[], System.Int32)
:soundlib.SoundManager.RequestInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.RequestInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.RequestInfo)
:System.Void Insert(System.Int32, soundlib.SoundManager.RequestInfo)
:System.Boolean Remove(soundlib.SoundManager.RequestInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.RequestInfo)
:soundlib.SoundManager.RequestInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.RequestInfo)
```

## `soundlib.SoundManager.SaveStateInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<StateGroupId>k__BackingField` | `System.UInt32` |  | 16 |
| `<StateId>k__BackingField` | `System.UInt32` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.UInt32, System.UInt32)
:System.UInt32 get_StateGroupId()
:System.UInt32 get_StateId()
:System.Void set_StateGroupId(System.UInt32)
:System.Void set_StateId(System.UInt32)
```

## `soundlib.SoundManager.SaveStateInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.SaveStateInfo)
:soundlib.SoundManager.SaveStateInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.SaveStateInfo)
:System.Void CopyTo(soundlib.SoundManager.SaveStateInfo[], System.Int32)
:soundlib.SoundManager.SaveStateInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.SaveStateInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.SaveStateInfo)
:System.Void Insert(System.Int32, soundlib.SoundManager.SaveStateInfo)
:System.Boolean Remove(soundlib.SoundManager.SaveStateInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.SaveStateInfo)
:soundlib.SoundManager.SaveStateInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.SaveStateInfo)
```

## `soundlib.SoundManager.StoppedEventType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GameObjectEventIdDuration` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `GameObjectRequestIdDuration` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `Max` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `None` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `RequestIdDuration` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `TargetEventIdDuration` | `soundlib.SoundManager.StoppedEventType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundManager.StoppedEventType[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundManager.StoppedEventType)
:soundlib.SoundManager.StoppedEventType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundManager.StoppedEventType)
:System.Void CopyTo(soundlib.SoundManager.StoppedEventType[], System.Int32)
:soundlib.SoundManager.StoppedEventType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundManager.StoppedEventType> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundManager.StoppedEventType)
:System.Void Insert(System.Int32, soundlib.SoundManager.StoppedEventType)
:System.Boolean Remove(soundlib.SoundManager.StoppedEventType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundManager.StoppedEventType)
:soundlib.SoundManager.StoppedEventType get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundManager.StoppedEventType)
```

## `soundlib.SoundManagerSettings`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupOption` | `System.Boolean` | yes | 32 |
| `_GroupSystem` | `System.Boolean` | yes | 32 |
| `_SrcPositionUpdateFreq` | `System.Byte` |  | 32 |
| `_GameParameterUpdateFrame` | `System.Byte` |  | 33 |
| `_BypassGameParameterInterpolationOnPlay` | `System.Boolean` |  | 34 |
| `_GeneratorClosestUpdateFreq` | `System.UInt32` |  | 36 |
| `_SystemBank` | `via.simplewwise.BankResourceHolder` |  | 40 |
| `_SystemBankId` | `System.UInt32` |  | 48 |
| `_PauseAllEvent` | `System.UInt32` |  | 52 |
| `_ResumeAllEvent` | `System.UInt32` |  | 56 |
| `_PlayPositionGetterSilentEvent` | `System.UInt32` |  | 60 |
| `_VolGameParIdList` | `System.UInt32[]` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void applySettings()
:via.simplewwise.BankResourceHolder get_SystemBank()
:System.Void set_SystemBank(via.simplewwise.BankResourceHolder)
```

## `soundlib.SoundOBB`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_OBB` | `via.OBB` |  | 64 |
| `_TransformedOBB` | `via.OBB` |  | 144 |

**Methods**

```lua
:System.Void .ctor()
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.AABB getBoundingAABB()
:via.OBB get_OBB()
:via.vec3 get_Position()
:via.OBB get_TransformedOBB()
:System.Void set_OBB(via.OBB)
:System.Void set_TransformedOBB(via.OBB)
:System.Void update()
```

## `soundlib.SoundOverrideState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `InKeyRange` | `System.Boolean` |  | 16 |
| `<ClipPlaying>k__BackingField` | `System.Boolean` |  | 17 |
| `_StateGroupId` | `System.UInt32` |  | 20 |
| `_StateId` | `System.UInt32` |  | 24 |
| `_UnableOverride` | `System.Boolean` |  | 28 |
| `_Added` | `System.Boolean` |  | 29 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_ClipPlaying()
:System.UInt32 get_StateGroupId()
:System.UInt32 get_StateId()
:System.Boolean get_UnableOverride()
:System.Void onClipEnd()
:System.Void onClipStart()
:System.Void onClipUpdate()
:System.Void resetFlag()
:System.Void set_ClipPlaying(System.Boolean)
:System.Void set_StateGroupId(System.UInt32)
:System.Void set_StateId(System.UInt32)
:System.Void set_UnableOverride(System.Boolean)
```

## `soundlib.SoundOverrideState[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundOverrideState)
:soundlib.SoundOverrideState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundOverrideState)
:System.Void CopyTo(soundlib.SoundOverrideState[], System.Int32)
:soundlib.SoundOverrideState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundOverrideState> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundOverrideState)
:System.Void Insert(System.Int32, soundlib.SoundOverrideState)
:System.Boolean Remove(soundlib.SoundOverrideState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundOverrideState)
:soundlib.SoundOverrideState get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundOverrideState)
```

## `soundlib.SoundPackageListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PackageList` | `via.simplewwise.PackageResourceHolder[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:via.simplewwise.PackageResourceHolder[] get_PackageList()
```

## `soundlib.SoundPeriodicalTriggerTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TriggerPeriod` | `System.UInt32` |  | 32 |
| `MinOffset` | `System.UInt32` |  | 36 |
| `MaxOffset` | `System.UInt32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundPhysicsListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_TriggerInfoReserveNum` | `System.Int32` | yes | 16 |
| `<PhysicsSettingList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundPhysicsSettings>` |  | 40 |
| `<BodyMaterialParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundBodyMaterialParam>` |  | 48 |
| `<PhysicsValueList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundPhysicsValues>` |  | 56 |
| `_DynamicsComponent` | `via.dynamics.RigidBodySet` |  | 64 |
| `_Contact` | `System.Boolean` |  | 72 |
| `_ContactBodyId` | `System.Int32` |  | 76 |
| `_ContactPosition` | `via.vec3` |  | 80 |
| `_ContactNormal` | `via.vec3` |  | 96 |
| `_ContactLinearVelocity` | `System.Single` |  | 112 |
| `_ContactAngleVelocity` | `System.Single` |  | 116 |
| `_ContactFrictionFactor` | `System.Single` |  | 120 |
| `_Overlapping` | `System.Boolean` |  | 124 |
| `_OverlappingBodyId` | `System.Int32` |  | 128 |
| `_OverlappingPosition` | `via.vec3` |  | 144 |
| `_OverlappingNormal` | `via.vec3` |  | 160 |
| `_OverlappingLinearVelocity` | `System.Single` |  | 176 |
| `_OverlappingAngleVelocity` | `System.Single` |  | 180 |
| `_OverlappingFrictionFactor` | `System.Single` |  | 184 |
| `_Separate` | `System.Boolean` |  | 188 |
| `_SeparateBody` | `System.Collections.Generic.HashSet`1<System.Int32>` |  | 192 |
| `_PhysicsTriggerInfoList` | `System.Collections.Generic.List`1<soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo>` |  | 200 |

**Methods**

```lua
:System.Void .ctor()
:System.Void <start>b__30_0(via.dynamics.InitializedEventArgs)
:System.Boolean <update>b__32_0(soundlib.SoundBodyMaterialParam)
:System.Boolean <update>b__32_1(soundlib.SoundBodyMaterialParam)
:System.Collections.Generic.List`1<soundlib.SoundBodyMaterialParam> get_BodyMaterialParamList()
:System.Collections.Generic.List`1<soundlib.SoundPhysicsSettings> get_PhysicsSettingList()
:System.Collections.Generic.List`1<soundlib.SoundPhysicsValues> get_PhysicsValueList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onDestroy()
:System.Void onDynamicsContact(via.dynamics.ContactEventArgs)
:System.Void onDynamicsOverlapping(via.dynamics.OverlappingEventArgs)
:System.Void onDynamicsSeparate(via.dynamics.SeparateEventArgs)
:System.Void reset()
:System.Void start()
:System.Void update()
:System.Void updateFriction(System.Int32, via.vec3, System.Single)
:System.Void updateVelocity(System.Int32, via.vec3, System.Single, System.Single)
```

## `soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TriggerId` | `System.UInt32` |  | 16 |
| `ContactPoint` | `System.Boolean` |  | 20 |
| `Position` | `via.vec3` |  | 32 |
| `BodyId` | `System.Int32` |  | 48 |
| `FinishedCastRay` | `System.Boolean` |  | 52 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.UInt32, System.Boolean, via.vec3, System.Int32)
```

## `soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:System.Void CopyTo(soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo[], System.Int32)
:soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:System.Void Insert(System.Int32, soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:System.Boolean Remove(soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
:soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo)
```

## `soundlib.SoundPhysicsListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupMaterial` | `System.Boolean` | yes | 32 |
| `_PhysicsSettingList` | `soundlib.SoundPhysicsSettings[]` |  | 32 |
| `_BodyMaterialParamList` | `soundlib.SoundBodyMaterialParam[]` |  | 40 |
| `_RayFilter` | `via.physics.CollisionFilterResourceHolder` |  | 48 |
| `_RayLength` | `System.Single` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundBodyMaterialParam[] get_BodyMaterialParamList()
:soundlib.SoundPhysicsSettings[] get_PhysicsSettingList()
:via.physics.CollisionFilterResourceHolder get_RayFilter()
:System.Single get_RayLength()
```

## `soundlib.SoundPhysicsSettings`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BodyIdList` | `System.Collections.Generic.List`1<System.Int32>` |  | 16 |
| `_PhysicsValueType` | `soundlib.PhysicsValueType` |  | 24 |
| `_ContactPoint` | `System.Boolean` |  | 28 |
| `_AntiRepeatTime` | `System.Single` |  | 32 |
| `_TriggerAll` | `System.Boolean` |  | 36 |
| `_ThresholdTriggerList` | `System.Collections.Generic.List`1<soundlib.ThresholdTrigger>` |  | 40 |
| `CurrentValue` | `System.Single` |  | 48 |
| `Posted` | `System.Boolean` |  | 52 |
| `ElapsedTime` | `System.Single` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundPhysicsSettings)
:System.Single get_AntiRepeatTime()
:System.Collections.Generic.List`1<System.Int32> get_BodyIdList()
:System.Boolean get_ContactPoint()
:soundlib.PhysicsValueType get_PhysicsValueType()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundPhysicsSettings[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundPhysicsSettings)
:soundlib.SoundPhysicsSettings Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundPhysicsSettings)
:System.Void CopyTo(soundlib.SoundPhysicsSettings[], System.Int32)
:soundlib.SoundPhysicsSettings Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundPhysicsSettings> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundPhysicsSettings)
:System.Void Insert(System.Int32, soundlib.SoundPhysicsSettings)
:System.Boolean Remove(soundlib.SoundPhysicsSettings)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundPhysicsSettings)
:soundlib.SoundPhysicsSettings get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundPhysicsSettings)
```

## `soundlib.SoundPhysicsValues`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Enabled>k__BackingField` | `System.Boolean` |  | 16 |
| `<BodyId>k__BackingField` | `System.Int32` |  | 20 |
| `<Mass>k__BackingField` | `System.Single` |  | 24 |
| `<Contact>k__BackingField` | `System.Boolean` |  | 28 |
| `<MaterialId>k__BackingField` | `System.UInt32` |  | 32 |
| `<LinearVelocity>k__BackingField` | `System.Single` |  | 36 |
| `<AngularVelocity>k__BackingField` | `System.Single` |  | 40 |
| `<FrictionFactorRow>k__BackingField` | `System.Single` |  | 44 |
| `<FrictionFactor>k__BackingField` | `System.Single` |  | 48 |
| `<Momentum>k__BackingField` | `System.Single` |  | 52 |
| `<AngularMomentum>k__BackingField` | `System.Single` |  | 56 |
| `<MassTimesFrictionFactor>k__BackingField` | `System.Single` |  | 60 |
| `<SettingIndexList>k__BackingField` | `System.Collections.Generic.List`1<System.Int32>` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32, via.dynamics.RigidBodySet)
:System.Single get_AngularMomentum()
:System.Single get_AngularVelocity()
:System.Int32 get_BodyId()
:System.Boolean get_Contact()
:System.Boolean get_Enabled()
:System.Single get_FrictionFactor()
:System.Single get_FrictionFactorRow()
:System.Single get_LinearVelocity()
:System.Single get_Mass()
:System.Single get_MassTimesFrictionFactor()
:System.UInt32 get_MaterialId()
:System.Single get_Momentum()
:System.Collections.Generic.List`1<System.Int32> get_SettingIndexList()
:System.Void resetPhysicsValue()
:System.Void set_AngularMomentum(System.Single)
:System.Void set_AngularVelocity(System.Single)
:System.Void set_Contact(System.Boolean)
:System.Void set_Enabled(System.Boolean)
:System.Void set_FrictionFactor(System.Single)
:System.Void set_FrictionFactorRow(System.Single)
:System.Void set_LinearVelocity(System.Single)
:System.Void set_MassTimesFrictionFactor(System.Single)
:System.Void set_MaterialId(System.UInt32)
:System.Void set_Momentum(System.Single)
```

## `soundlib.SoundPhysicsValues[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundPhysicsValues)
:soundlib.SoundPhysicsValues Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundPhysicsValues)
:System.Void CopyTo(soundlib.SoundPhysicsValues[], System.Int32)
:soundlib.SoundPhysicsValues Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundPhysicsValues> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundPhysicsValues)
:System.Void Insert(System.Int32, soundlib.SoundPhysicsValues)
:System.Boolean Remove(soundlib.SoundPhysicsValues)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundPhysicsValues)
:soundlib.SoundPhysicsValues get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundPhysicsValues)
```

## `soundlib.SoundPlayPositionGetter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Container` | `soundlib.SoundContainer` |  | 80 |
| `_RequestId` | `System.UInt32` |  | 88 |

**Methods**

```lua
:System.Int32 get_SourcePlayPosition()
:System.Void onDestroy()
:System.Void onPostRequestInfo(soundlib.SoundManager.RequestInfo)
:System.Void start()
```

## `soundlib.SoundPoint`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Position` | `via.vec3` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.vec3 get_Position()
```

## `soundlib.SoundPortal`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<PortalId>k__BackingField` | `System.UInt64` |  | 16 |
| `_Enable` | `System.Boolean` |  | 24 |
| `_OBB` | `via.OBB` |  | 32 |
| `_BackRoomHash` | `System.UInt32` |  | 112 |
| `_FrontRoomHash` | `System.UInt32` |  | 116 |
| `_Obstruction` | `System.Single` |  | 120 |
| `_Occlusion` | `System.Single` |  | 124 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_BackRoomHash()
:System.Boolean get_Enable()
:System.UInt32 get_FrontRoomHash()
:via.OBB get_OBB()
:System.Single get_Obstruction()
:System.Single get_Occlusion()
:System.UInt64 get_PortalId()
:System.Void set_BackRoomHash(System.UInt32)
:System.Void set_Enable(System.Boolean)
:System.Void set_FrontRoomHash(System.UInt32)
:System.Void set_OBB(via.OBB)
:System.Void set_Obstruction(System.Single)
:System.Void set_Occlusion(System.Single)
```

## `soundlib.SoundPortalListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<PortalList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundPortal>` |  | 40 |
| `_SpMgr` | `soundlib.SoundSpatialAudioManager` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundPortal> get_PortalList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundPortalListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PortalList` | `soundlib.SoundPortal[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundPortal[] get_PortalList()
```

## `soundlib.SoundPortal[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundPortal)
:soundlib.SoundPortal Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundPortal)
:System.Void CopyTo(soundlib.SoundPortal[], System.Int32)
:soundlib.SoundPortal Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundPortal> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundPortal)
:System.Void Insert(System.Int32, soundlib.SoundPortal)
:System.Boolean Remove(soundlib.SoundPortal)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundPortal)
:soundlib.SoundPortal get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundPortal)
```

## `soundlib.SoundRagdollListBehavior`

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
```

## `soundlib.SoundRagdollListData`

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundRigidBodyListBehavior`

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
```

## `soundlib.SoundRigidBodyListData`

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundRoom`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RoomId>k__BackingField` | `System.UInt64` |  | 16 |
| `_RoomHash` | `System.UInt32` |  | 24 |
| `_Rotation` | `via.Quaternion` |  | 32 |
| `_AuxBusId` | `System.UInt32` |  | 48 |
| `_ReverbLevel` | `System.Single` |  | 52 |
| `_WallOcclusion` | `System.Single` |  | 56 |
| `_AuxSendLevelToSelf` | `System.Single` |  | 60 |
| `_KeepRegistered` | `System.Boolean` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_AuxBusId()
:System.Single get_AuxSendLevelToSelf()
:System.Boolean get_KeepRegistered()
:System.Single get_ReverbLevel()
:System.UInt32 get_RoomHash()
:System.UInt64 get_RoomId()
:via.Quaternion get_Rotation()
:System.Single get_WallOcclusion()
:System.Void set_AuxBusId(System.UInt32)
:System.Void set_AuxSendLevelToSelf(System.Single)
:System.Void set_KeepRegistered(System.Boolean)
:System.Void set_ReverbLevel(System.Single)
:System.Void set_RoomHash(System.UInt32)
:System.Void set_RoomId(System.UInt64)
:System.Void set_Rotation(via.Quaternion)
:System.Void set_WallOcclusion(System.Single)
```

## `soundlib.SoundRoomListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RoomList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundRoom>` |  | 40 |
| `_SpMgr` | `soundlib.SoundSpatialAudioManager` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundRoom> get_RoomList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundRoomListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_RoomList` | `soundlib.SoundRoom[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundRoom[] get_RoomList()
```

## `soundlib.SoundRoom[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundRoom)
:soundlib.SoundRoom Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundRoom)
:System.Void CopyTo(soundlib.SoundRoom[], System.Int32)
:soundlib.SoundRoom Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundRoom> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundRoom)
:System.Void Insert(System.Int32, soundlib.SoundRoom)
:System.Boolean Remove(soundlib.SoundRoom)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundRoom)
:soundlib.SoundRoom get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundRoom)
```

## `soundlib.SoundSetState`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_StateGroupId` | `System.UInt32` |  | 16 |
| `_StateId` | `System.UInt32` |  | 20 |
| `_SetOnStart` | `System.Boolean` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_SetOnStart()
:System.UInt32 get_StateGroupId()
:System.UInt32 get_StateId()
:System.Void setState()
:System.Void set_StateGroupId(System.UInt32)
```

## `soundlib.SoundSetStateListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SetStateList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundSetState>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundSetState> get_SetStateList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void setState()
:System.Void start()
```

## `soundlib.SoundSetStateListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SetStateList` | `soundlib.SoundSetState[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundSetState[] get_SetStateList()
```

## `soundlib.SoundSetState[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundSetState)
:soundlib.SoundSetState Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundSetState)
:System.Void CopyTo(soundlib.SoundSetState[], System.Int32)
:soundlib.SoundSetState Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundSetState> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundSetState)
:System.Void Insert(System.Int32, soundlib.SoundSetState)
:System.Boolean Remove(soundlib.SoundSetState)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundSetState)
:soundlib.SoundSetState get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundSetState)
```

## `soundlib.SoundShape`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<EnableUpdate>k__BackingField` | `System.Boolean` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:via.AABB getBoundingAABB()
:System.Boolean get_EnableUpdate()
:via.vec3 get_Position()
:System.Void set_EnableUpdate(System.Boolean)
```

## `soundlib.SoundShape[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundShape)
:soundlib.SoundShape Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundShape)
:System.Void CopyTo(soundlib.SoundShape[], System.Int32)
:soundlib.SoundShape Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundShape> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundShape)
:System.Void Insert(System.Int32, soundlib.SoundShape)
:System.Boolean Remove(soundlib.SoundShape)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundShape)
:soundlib.SoundShape get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundShape)
```

## `soundlib.SoundSpatialAudioManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnListenerRoomIdChanged` | `System.Action`1<System.UInt64>` |  | 24 |
| `OnListenerRoomChanged` | `System.Action`1<soundlib.SoundRoom>` |  | 32 |

## `soundlib.SoundSphere`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Sphere` | `via.Sphere` |  | 64 |
| `_TransformedSphere` | `via.Sphere` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.AABB getBoundingAABB()
:via.vec3 get_Position()
:via.Sphere get_Sphere()
:via.Sphere get_TransformedSphere()
:System.Void set_Sphere(via.Sphere)
:System.Void set_TransformedSphere(via.Sphere)
:System.Void update()
```

## `soundlib.SoundStateAppBase.SoundStateEnumPairBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:soundlib.SoundStateAppBase.SoundStateEnumPairBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:System.Void CopyTo(soundlib.SoundStateAppBase.SoundStateEnumPairBase[], System.Int32)
:soundlib.SoundStateAppBase.SoundStateEnumPairBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundStateAppBase.SoundStateEnumPairBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:System.Void Insert(System.Int32, soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:System.Boolean Remove(soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundStateAppBase.SoundStateEnumPairBase)
:soundlib.SoundStateAppBase.SoundStateEnumPairBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundStateAppBase.SoundStateEnumPairBase)
```

## `soundlib.SoundStateAppListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<StateAppParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundStateAppParamBase>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Void commonStart()
:System.Collections.Generic.List`1<soundlib.SoundStateAppParamBase> get_StateAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundStateAppListData`

**Methods**

```lua
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundStateAppParamBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<StateApp>k__BackingField` | `soundlib.SoundStateAppBase` |  | 16 |

**Methods**

```lua
:soundlib.SoundStateAppBase get_StateApp()
:System.Void set_StateApp(soundlib.SoundStateAppBase)
```

## `soundlib.SoundStateAppParamBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundStateAppParamBase)
:soundlib.SoundStateAppParamBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundStateAppParamBase)
:System.Void CopyTo(soundlib.SoundStateAppParamBase[], System.Int32)
:soundlib.SoundStateAppParamBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundStateAppParamBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundStateAppParamBase)
:System.Void Insert(System.Int32, soundlib.SoundStateAppParamBase)
:System.Boolean Remove(soundlib.SoundStateAppParamBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundStateAppParamBase)
:soundlib.SoundStateAppParamBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundStateAppParamBase)
```

## `soundlib.SoundStateTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `StateGroupId` | `System.UInt32` |  | 20 |
| `StateId` | `System.UInt32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundSubManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Initialized>k__BackingField` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Boolean get_Initialized()
:System.Void initialize(soundlib.SoundManagerSettingsBase)
:System.Void set_Initialized(System.Boolean)
:System.Void terminate()
```

## `soundlib.SoundSwitchAppBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_JointHash` | `System.UInt32[]` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32[] get_JointHash()
```

## `soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:System.Void CopyTo(soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase[], System.Int32)
:soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:System.Void Insert(System.Int32, soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:System.Boolean Remove(soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
:soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundSwitchAppBase.SoundSwitchEnumPairBase)
```

## `soundlib.SoundSwitchAppListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SwitchAppParamList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundSwitchAppParamBase>` |  | 40 |
| `_Released` | `System.Boolean` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.ValueTuple`2[[System.UInt32, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[System.UInt32, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][] getSwitch()
:System.Collections.Generic.List`1<soundlib.SoundSwitchAppParamBase> get_SwitchAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundSwitchAppListData`

**Methods**

```lua
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundSwitchAppParamBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SwitchApp>k__BackingField` | `soundlib.SoundSwitchAppBase` |  | 16 |

**Methods**

```lua
:soundlib.SoundSwitchAppBase get_SwitchApp()
:System.Void set_SwitchApp(soundlib.SoundSwitchAppBase)
```

## `soundlib.SoundSwitchAppParamBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundSwitchAppParamBase)
:soundlib.SoundSwitchAppParamBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundSwitchAppParamBase)
:System.Void CopyTo(soundlib.SoundSwitchAppParamBase[], System.Int32)
:soundlib.SoundSwitchAppParamBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundSwitchAppParamBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundSwitchAppParamBase)
:System.Void Insert(System.Int32, soundlib.SoundSwitchAppParamBase)
:System.Boolean Remove(soundlib.SoundSwitchAppParamBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundSwitchAppParamBase)
:soundlib.SoundSwitchAppParamBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundSwitchAppParamBase)
```

## `soundlib.SoundTargetOperationTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GuiTriggerId` | `System.UInt32` |  | 16 |
| `_SoundTriggerId` | `System.UInt32` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_GuiTriggerId()
:System.UInt32 get_SoundTriggerId()
```

## `soundlib.SoundTargetOperationTriggerListBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<TargetOperationTriggerList>k__BackingField` | `System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger>` |  | 40 |
| `_TargetOperationTriggerDict` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger> get_TargetOperationTriggerList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void stopTriggered(System.UInt32, System.UInt32)
:System.Void trigger(System.UInt32)
```

## `soundlib.SoundTargetOperationTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupEdit` | `System.Boolean` | yes | 32 |
| `_GroupScriptSettings` | `System.Boolean` | yes | 32 |
| `_GroupTargetOperationDefinition` | `System.Boolean` | yes | 32 |
| `_TargetOperationTriggerList` | `System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger> get_TargetOperationTriggerList()
```

## `soundlib.SoundTargetOperationTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundTargetOperationTrigger)
:soundlib.SoundTargetOperationTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundTargetOperationTrigger)
:System.Void CopyTo(soundlib.SoundTargetOperationTrigger[], System.Int32)
:soundlib.SoundTargetOperationTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundTargetOperationTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundTargetOperationTrigger)
:System.Void Insert(System.Int32, soundlib.SoundTargetOperationTrigger)
:System.Boolean Remove(soundlib.SoundTargetOperationTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundTargetOperationTrigger)
:soundlib.SoundTargetOperationTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundTargetOperationTrigger)
```

## `soundlib.SoundTracksBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Mute` | `soundlib.EnumBool` |  | 16 |

**Methods**

```lua
:System.Void clear()
```

## `soundlib.SoundTriggerInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_TriggerId` | `System.UInt32` |  | 16 |
| `_EventId` | `System.UInt32` |  | 20 |
| `_OffsetJointHash` | `System.UInt32` |  | 24 |
| `_OffsetJointRotation` | `System.Boolean` |  | 28 |
| `_OffsetGameObj` | `System.String` |  | 32 |
| `_OffsetLisIdx` | `soundlib.SoundListener.ListenerIndex` |  | 40 |
| `_OffsetValue` | `via.vec3` |  | 48 |
| `_OffsetIgnoreRot` | `System.Boolean` |  | 64 |
| `_OffsetToListener` | `System.Single` |  | 68 |
| `_OffsetRandomPanning` | `via.vec3` |  | 80 |
| `_OffsetFollow` | `System.Boolean` |  | 96 |
| `_StayAlive` | `System.Boolean` |  | 97 |
| `_SyncGameObjectState` | `System.Boolean` |  | 98 |
| `_SyncGameObjectDraw` | `System.Boolean` |  | 99 |
| `_Global` | `System.Boolean` |  | 100 |
| `_CullingId1` | `System.UInt32` |  | 104 |
| `_CullingId2` | `System.UInt32` |  | 108 |
| `_CullingId3` | `System.UInt32` |  | 112 |
| `_Priority` | `System.Byte` |  | 116 |
| `_PrioritizeFirst` | `System.Boolean` |  | 117 |
| `_Limit` | `System.Byte` |  | 118 |
| `_BookingTime` | `System.UInt16` |  | 120 |
| `_FlangingTime` | `System.UInt16` |  | 122 |
| `_ReleaseTime` | `System.UInt16` |  | 124 |
| `_Mute` | `System.Boolean` |  | 126 |
| `_SkipRate` | `System.Single` |  | 128 |
| `_TriggerRange` | `System.Single` |  | 132 |
| `_VirtualRange` | `System.Single` |  | 136 |
| `_CalcObsOcl` | `System.Boolean` |  | 140 |
| `_UpdateObsOcl` | `System.Boolean` |  | 141 |
| `_UnlimitObsOclDist` | `System.Boolean` |  | 142 |
| `_ListenerBitMask` | `System.Byte` |  | 143 |
| `_SetRoom` | `System.Boolean` |  | 144 |
| `_Spatialization` | `System.UInt32` |  | 148 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(soundlib.SoundTriggerInfo)
:System.Int32 CompareTo(soundlib.SoundTriggerInfo)
:System.UInt16 get_BookingTime()
:System.Boolean get_CalcObsOcl()
:System.UInt32 get_EventId()
:System.UInt16 get_FlangingTime()
:System.Boolean get_Global()
:System.UInt32 get_Id1()
:System.UInt32 get_Id2()
:System.UInt32 get_Id3()
:System.Byte get_Limit()
:System.Boolean get_Lis0()
:System.Boolean get_Lis1()
:System.Boolean get_Lis2()
:System.Boolean get_Lis3()
:System.Boolean get_Lis4()
:System.Boolean get_Lis5()
:System.Boolean get_Lis6()
:System.Boolean get_Lis7()
:System.Byte get_ListenerBitMask()
:System.Boolean get_Mute()
:System.Boolean get_OffsetFollow()
:System.String get_OffsetGameObj()
:System.Boolean get_OffsetIgnoreRot()
:System.UInt32 get_OffsetJointHash()
:System.Boolean get_OffsetJointRotation()
:soundlib.SoundListener.ListenerIndex get_OffsetLisIdx()
:via.vec3 get_OffsetRandomPanning()
:System.Single get_OffsetRandomX()
:System.Single get_OffsetRandomY()
:System.Single get_OffsetRandomZ()
:System.Single get_OffsetToListener()
:via.vec3 get_OffsetValue()
:System.Single get_OffsetX()
:System.Single get_OffsetY()
:System.Single get_OffsetZ()
:System.Boolean get_PrioritizeFirst()
:System.Byte get_Priority()
:System.UInt16 get_ReleaseTime()
:System.Boolean get_SetRoom()
:System.Single get_SkipRate()
:System.UInt32 get_Spatialization()
:System.Boolean get_StayAlive()
:System.Boolean get_SyncGameObjectDraw()
:System.Boolean get_SyncGameObjectState()
:System.UInt32 get_TriggerId()
:System.Single get_TriggerRange()
:System.Boolean get_UnlimitObsOclDist()
:System.Boolean get_UpdateObsOcl()
:System.Boolean get_Valid()
:System.Single get_VirtualRange()
:System.Boolean get__IsNotOffsetLis()
:System.Boolean hasSameCullingId(soundlib.SoundTriggerInfo)
:System.Void set_Lis0(System.Boolean)
:System.Void set_Lis1(System.Boolean)
:System.Void set_Lis2(System.Boolean)
:System.Void set_Lis3(System.Boolean)
:System.Void set_Lis4(System.Boolean)
:System.Void set_Lis5(System.Boolean)
:System.Void set_Lis6(System.Boolean)
:System.Void set_Lis7(System.Boolean)
:System.Void set_OffsetRandomX(System.Single)
:System.Void set_OffsetRandomY(System.Single)
:System.Void set_OffsetRandomZ(System.Single)
:System.Void set_OffsetValue(via.vec3)
:System.Void set_OffsetX(System.Single)
:System.Void set_OffsetY(System.Single)
:System.Void set_OffsetZ(System.Single)
```

## `soundlib.SoundTriggerInfoListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Bank` | `via.simplewwise.BankResourceHolder` |  | 32 |
| `_TriggerInfoList` | `System.Collections.Generic.List`1<soundlib.SoundTriggerInfo>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:via.simplewwise.BankResourceHolder get_Bank()
:System.Collections.Generic.List`1<soundlib.SoundTriggerInfo> get_TriggerInfoList()
:System.Void set_Bank(via.simplewwise.BankResourceHolder)
```

## `soundlib.SoundTriggerInfoListData[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundTriggerInfoListData)
:soundlib.SoundTriggerInfoListData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundTriggerInfoListData)
:System.Void CopyTo(soundlib.SoundTriggerInfoListData[], System.Int32)
:soundlib.SoundTriggerInfoListData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundTriggerInfoListData> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundTriggerInfoListData)
:System.Void Insert(System.Int32, soundlib.SoundTriggerInfoListData)
:System.Boolean Remove(soundlib.SoundTriggerInfoListData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundTriggerInfoListData)
:soundlib.SoundTriggerInfoListData get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundTriggerInfoListData)
```

## `soundlib.SoundTriggerInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundTriggerInfo)
:soundlib.SoundTriggerInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundTriggerInfo)
:System.Void CopyTo(soundlib.SoundTriggerInfo[], System.Int32)
:soundlib.SoundTriggerInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundTriggerInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundTriggerInfo)
:System.Void Insert(System.Int32, soundlib.SoundTriggerInfo)
:System.Boolean Remove(soundlib.SoundTriggerInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundTriggerInfo)
:soundlib.SoundTriggerInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundTriggerInfo)
```

## `soundlib.SoundTriggerTracks`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TriggerId` | `System.UInt32` |  | 20 |
| `JointHash` | `System.UInt32` |  | 24 |
| `ForceTriggerOverwrittenJoint` | `soundlib.EnumBool` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `soundlib.SoundUtility`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnLog` | `System.Action`2<soundlib.SoundUtility.LogLevel,System.String>` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "add_OnLog", ...)  -- System.Void add_OnLog(System.Action`2<soundlib.SoundUtility.LogLevel,System.String>)
sdk.call_native_func(nil, type_def, "errorLine", ...)  -- System.Void errorLine(System.String)
sdk.call_native_func(nil, type_def, "errorLine", ...)  -- System.Void errorLine(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "errorLine", ...)  -- System.Void errorLine(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "errorLine", ...)  -- System.Void errorLine(via.GameObject, System.String, System.Object[])
sdk.call_native_func(nil, type_def, "fatalLine", ...)  -- System.Void fatalLine(System.String)
sdk.call_native_func(nil, type_def, "fatalLine", ...)  -- System.Void fatalLine(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "getAllChildRecursive", ...)  -- System.Void getAllChildRecursive(via.GameObject, System.Collections.Generic.List`1<via.GameObject>, System.Type)
sdk.call_native_func(nil, type_def, "getChildObjRecursively", ...)  -- via.GameObject getChildObjRecursively(via.GameObject, System.UInt32)
sdk.call_native_func(nil, type_def, "getId", ...)  -- System.Guid getId(via.GameObject)
sdk.call_native_func(nil, type_def, "getNameFromSoundId", ...)  -- System.String getNameFromSoundId(System.UInt32)
sdk.call_native_func(nil, type_def, "getNameFromWwiseId", ...)  -- System.String getNameFromWwiseId(System.UInt32, via.simplewwise.IdType)
sdk.call_native_func(nil, type_def, "infoLine", ...)  -- System.Void infoLine(System.String)
sdk.call_native_func(nil, type_def, "infoLine", ...)  -- System.Void infoLine(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "infoLine", ...)  -- System.Void infoLine(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "infoLine", ...)  -- System.Void infoLine(via.GameObject, System.String, System.Object[])
sdk.call_native_func(nil, type_def, "remove_OnLog", ...)  -- System.Void remove_OnLog(System.Action`2<soundlib.SoundUtility.LogLevel,System.String>)
sdk.call_native_func(nil, type_def, "warningLine", ...)  -- System.Void warningLine(System.String)
sdk.call_native_func(nil, type_def, "warningLine", ...)  -- System.Void warningLine(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "warningLine", ...)  -- System.Void warningLine(System.String, System.Object[])
sdk.call_native_func(nil, type_def, "warningLine", ...)  -- System.Void warningLine(via.GameObject, System.String, System.Object[])
```

## `soundlib.SoundUtility.BitOperation`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "bitOff", ...)  -- System.Void bitOff(System.UInt32, System.Int32)
sdk.call_native_func(nil, type_def, "bitOn", ...)  -- System.Void bitOn(System.UInt32, System.Int32)
sdk.call_native_func(nil, type_def, "isBit", ...)  -- System.Boolean isBit(System.UInt32, System.Int32)
```

## `soundlib.SoundUtility.LogLevel`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Error` | `soundlib.SoundUtility.LogLevel` | yes | 16 |
| `Fatal` | `soundlib.SoundUtility.LogLevel` | yes | 16 |
| `Info` | `soundlib.SoundUtility.LogLevel` | yes | 16 |
| `Warning` | `soundlib.SoundUtility.LogLevel` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundUtility.LogLevel[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundUtility.LogLevel)
:soundlib.SoundUtility.LogLevel Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundUtility.LogLevel)
:System.Void CopyTo(soundlib.SoundUtility.LogLevel[], System.Int32)
:soundlib.SoundUtility.LogLevel Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundUtility.LogLevel> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundUtility.LogLevel)
:System.Void Insert(System.Int32, soundlib.SoundUtility.LogLevel)
:System.Boolean Remove(soundlib.SoundUtility.LogLevel)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundUtility.LogLevel)
:soundlib.SoundUtility.LogLevel get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundUtility.LogLevel)
```

## `soundlib.SoundVibInfoBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<PadDisplayName>k__BackingField` | `System.String[]` |  | 16 |
| `_Ignore` | `System.Boolean` |  | 24 |
| `_VibrationTrigger` | `System.UInt32` |  | 28 |
| `_SendPad` | `System.UInt32` |  | 32 |
| `_VibrationTypeId` | `System.UInt32` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_Ignore()
:System.Boolean get_IsBehaviorCallable()
:System.String[] get_PadDisplayName()
:System.UInt32 get_SendPad()
:System.Boolean get_SendPad0()
:System.Boolean get_SendPad1()
:System.UInt32 get_VibrationTrigger()
:System.UInt32 get_VibrationTypeId()
:System.Void set_SendPad0(System.Boolean)
:System.Void set_SendPad1(System.Boolean)
```

## `soundlib.SoundVibInfoBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibInfoBase)
:soundlib.SoundVibInfoBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibInfoBase)
:System.Void CopyTo(soundlib.SoundVibInfoBase[], System.Int32)
:soundlib.SoundVibInfoBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibInfoBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibInfoBase)
:System.Void Insert(System.Int32, soundlib.SoundVibInfoBase)
:System.Boolean Remove(soundlib.SoundVibInfoBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibInfoBase)
:soundlib.SoundVibInfoBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibInfoBase)
```

## `soundlib.SoundVibInfoByTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SoundTriggerId` | `System.UInt32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 get_TriggerId()
:System.Boolean get_Valid()
```

## `soundlib.SoundVibInfoByTriggerListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_VibrationInfoList` | `soundlib.SoundVibInfoByTrigger[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundVibInfoBase[] get_DataList()
```

## `soundlib.SoundVibInfoByTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibInfoByTrigger)
:soundlib.SoundVibInfoByTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibInfoByTrigger)
:System.Void CopyTo(soundlib.SoundVibInfoByTrigger[], System.Int32)
:soundlib.SoundVibInfoByTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibInfoByTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibInfoByTrigger)
:System.Void Insert(System.Int32, soundlib.SoundVibInfoByTrigger)
:System.Boolean Remove(soundlib.SoundVibInfoByTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibInfoByTrigger)
:soundlib.SoundVibInfoByTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibInfoByTrigger)
```

## `soundlib.SoundVibInfoByWav`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_WaveId` | `System.UInt32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean get_Valid()
:System.UInt32 get_WaveId()
```

## `soundlib.SoundVibInfoByWavListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_VibrationInfoList` | `soundlib.SoundVibInfoByWav[]` |  | 32 |
| `_Lock` | `soundlib.SoundVibInfoByWavListData.LockObj` |  | 40 |
| `_RefCnt` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:soundlib.SoundVibInfoBase[] get_DataList()
:System.Void requestRegister()
:System.Void requestUnRegister()
```

## `soundlib.SoundVibInfoByWav[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibInfoByWav)
:soundlib.SoundVibInfoByWav Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibInfoByWav)
:System.Void CopyTo(soundlib.SoundVibInfoByWav[], System.Int32)
:soundlib.SoundVibInfoByWav Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibInfoByWav> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibInfoByWav)
:System.Void Insert(System.Int32, soundlib.SoundVibInfoByWav)
:System.Boolean Remove(soundlib.SoundVibInfoByWav)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibInfoByWav)
:soundlib.SoundVibInfoByWav get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibInfoByWav)
```

## `soundlib.SoundVibInfoByWav[][]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibInfoByWav[])
:soundlib.SoundVibInfoByWav[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibInfoByWav[])
:System.Void CopyTo(soundlib.SoundVibInfoByWav[][], System.Int32)
:soundlib.SoundVibInfoByWav[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibInfoByWav[]> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibInfoByWav[])
:System.Void Insert(System.Int32, soundlib.SoundVibInfoByWav[])
:System.Boolean Remove(soundlib.SoundVibInfoByWav[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibInfoByWav[])
:soundlib.SoundVibInfoByWav[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibInfoByWav[])
```

## `soundlib.SoundVibInfoListDataBase[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibInfoListDataBase)
:soundlib.SoundVibInfoListDataBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibInfoListDataBase)
:System.Void CopyTo(soundlib.SoundVibInfoListDataBase[], System.Int32)
:soundlib.SoundVibInfoListDataBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibInfoListDataBase> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibInfoListDataBase)
:System.Void Insert(System.Int32, soundlib.SoundVibInfoListDataBase)
:System.Boolean Remove(soundlib.SoundVibInfoListDataBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibInfoListDataBase)
:soundlib.SoundVibInfoListDataBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibInfoListDataBase)
```

## `soundlib.SoundVibrationBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GroupDebug` | `System.Boolean` | yes | 80 |
| `_GroupSettings` | `System.Boolean` | yes | 80 |
| `_GroupUserData` | `System.Boolean` | yes | 80 |
| `_VibrationManager` | `soundlib.SoundVibrationManager` |  | 80 |
| `_Container` | `soundlib.SoundContainer` |  | 88 |
| `_AssetList` | `soundlib.SoundVibInfoListDataBase[]` |  | 96 |
| `_WavIdAssetCount` | `System.Int32` |  | 104 |
| `_TriggerInfoList` | `System.Collections.Generic.List`1<soundlib.SoundVibInfoBase>` |  | 112 |
| `_ByTrgDict` | `System.Collections.Generic.Dictionary`2<System.UInt32,soundlib.SoundVibInfoByTrigger>` |  | 120 |

**Methods**

```lua
:System.Void .ctor()
:System.UInt32 getVibrationTypeId(soundlib.SoundVibInfoBase)
:System.Boolean isPlayingTrigger(System.UInt32)
:System.Void onDestroy()
:System.Void setCallbackFlag(soundlib.SoundManager.RequestInfo)
:System.Void start()
:System.Void stopTrigger(System.UInt32, System.UInt32)
:System.Void trigger(System.UInt32, soundlib.SoundVibrationBehavior.Option)
:System.Void vibrationByTrigger(soundlib.SoundManager.RequestInfo)
```

## `soundlib.SoundVibrationBehavior.Option`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TargetPadMask` | `System.UInt32` |  | 16 |
| `Side` | `soundlib.SoundVibrationManager.SideType` |  | 20 |
| `Power` | `System.Single` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
```

## `soundlib.SoundVibrationDefineInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Playing>k__BackingField` | `System.Boolean` |  | 16 |
| `_Ignore` | `System.Boolean` |  | 17 |
| `_VibrationTrigger` | `System.UInt32` |  | 20 |
| `_VibAudioSource` | `via.audiorender.VibrationSourceResourceHolder` |  | 24 |
| `_Volume` | `System.Single` |  | 32 |
| `_SendPadMask` | `System.UInt32` |  | 36 |
| `_MotorPower0` | `System.Single` |  | 40 |
| `_MotorPower1` | `System.Single` |  | 44 |
| `_DurationMsecHD` | `System.Single` |  | 48 |
| `_DurationMsec` | `System.Single` |  | 52 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_DurationMsec()
:System.Single get_DurationMsecHD()
:System.Boolean get_Ignore()
:System.Single get_MotorPower0()
:System.Single get_MotorPower1()
:System.String[] get_PadDisplayName()
:System.Boolean get_Playing()
:System.Boolean get_SendPad0()
:System.Boolean get_SendPad1()
:System.UInt32 get_SendPadMask()
:via.audiorender.VibrationSourceResourceHolder get_VibAudioSource()
:System.UInt32 get_VibrationTrigger()
:System.Single get_Volume()
:System.Void set_Playing(System.Boolean)
:System.Void set_SendPad0(System.Boolean)
:System.Void set_SendPad1(System.Boolean)
```

## `soundlib.SoundVibrationDefineInfoListData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_VibrationDefineInfoList` | `soundlib.SoundVibrationDefineInfo[]` |  | 32 |
| `_RefCnt` | `System.Int32` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Int32 addRefCnt()
:soundlib.SoundVibrationDefineInfo[] get_SoundVibrationDefineInfoList()
:System.Int32 subRefCnt()
```

## `soundlib.SoundVibrationDefineInfoListDataHolder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Data` | `soundlib.SoundVibrationDefineInfoListData[]` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Void onDestroy()
```

## `soundlib.SoundVibrationDefineInfoListData[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibrationDefineInfoListData)
:soundlib.SoundVibrationDefineInfoListData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibrationDefineInfoListData)
:System.Void CopyTo(soundlib.SoundVibrationDefineInfoListData[], System.Int32)
:soundlib.SoundVibrationDefineInfoListData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibrationDefineInfoListData> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibrationDefineInfoListData)
:System.Void Insert(System.Int32, soundlib.SoundVibrationDefineInfoListData)
:System.Boolean Remove(soundlib.SoundVibrationDefineInfoListData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibrationDefineInfoListData)
:soundlib.SoundVibrationDefineInfoListData get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibrationDefineInfoListData)
```

## `soundlib.SoundVibrationDefineInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibrationDefineInfo)
:soundlib.SoundVibrationDefineInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibrationDefineInfo)
:System.Void CopyTo(soundlib.SoundVibrationDefineInfo[], System.Int32)
:soundlib.SoundVibrationDefineInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibrationDefineInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibrationDefineInfo)
:System.Void Insert(System.Int32, soundlib.SoundVibrationDefineInfo)
:System.Boolean Remove(soundlib.SoundVibrationDefineInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibrationDefineInfo)
:soundlib.SoundVibrationDefineInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibrationDefineInfo)
```

## `soundlib.SoundVibrationDefinePair`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Info>k__BackingField` | `soundlib.SoundVibrationDefineInfo` |  | 16 |
| `<UserData>k__BackingField` | `soundlib.SoundVibrationDefineInfoListData` |  | 24 |

**Methods**

```lua
:System.Void .ctor(soundlib.SoundVibrationDefineInfo, soundlib.SoundVibrationDefineInfoListData)
:soundlib.SoundVibrationDefineInfo get_Info()
:soundlib.SoundVibrationDefineInfoListData get_UserData()
:System.UInt32 get_VibrationTrigger()
:System.Void set_Info(soundlib.SoundVibrationDefineInfo)
:System.Void set_UserData(soundlib.SoundVibrationDefineInfoListData)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "createDefinePair", ...)  -- System.Collections.Generic.List`1<soundlib.SoundVibrationDefinePair> createDefinePair(soundlib.SoundVibrationDefineInfoListData)
```

## `soundlib.SoundVibrationDefinePair[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibrationDefinePair)
:soundlib.SoundVibrationDefinePair Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibrationDefinePair)
:System.Void CopyTo(soundlib.SoundVibrationDefinePair[], System.Int32)
:soundlib.SoundVibrationDefinePair Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibrationDefinePair> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibrationDefinePair)
:System.Void Insert(System.Int32, soundlib.SoundVibrationDefinePair)
:System.Boolean Remove(soundlib.SoundVibrationDefinePair)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibrationDefinePair)
:soundlib.SoundVibrationDefinePair get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibrationDefinePair)
```

## `soundlib.SoundVibrationManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Deg2Rad30` | `System.Single` | yes | 80 |
| `_GroupDebug` | `System.Boolean` | yes | 80 |
| `_GroupParams` | `System.Boolean` | yes | 80 |
| `_GroupSettings` | `System.Boolean` | yes | 80 |
| `<PadDisplayName>k__BackingField` | `System.String[]` | yes | 88 |
| `<Instance>k__BackingField` | `soundlib.SoundVibrationManager` | yes | 96 |
| `<IsTargetPlatform>k__BackingField` | `System.Boolean` | yes | 104 |
| `_ActivePadBits` | `System.UInt32` |  | 80 |
| `_BusIdTbl` | `System.UInt32[]` |  | 88 |
| `_MaxHdVibCnt` | `System.Int32` |  | 96 |
| `_SineWavResourceL` | `via.audiorender.VibrationSourceResourceHolder` |  | 104 |
| `_SineWavResourceR` | `via.audiorender.VibrationSourceResourceHolder` |  | 112 |
| `_MaxContinuousSec` | `System.Single` |  | 120 |
| `_VibDefDataQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundVibrationDefineInfoListData,System.Boolean>>` |  | 128 |
| `_VibDefPairList` | `System.Collections.Generic.List`1<soundlib.SoundVibrationDefinePair>` |  | 136 |
| `_SoundVibInfoByWavQueue` | `System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundVibInfoByWav[],System.Boolean>>` |  | 144 |
| `_SoundVibInfoByWavList` | `System.Collections.Generic.List`1<soundlib.SoundVibInfoByWav>` |  | 152 |
| `_DurationCallbackQueue` | `System.Collections.Generic.Queue`1<via.simplewwise.DurationCallbackInfo>` |  | 160 |
| `_VibrationInfoList` | `System.Collections.Generic.List`1<soundlib.SoundVibrationManager.VibrationInfo>` |  | 168 |
| `_PlayingPadIdxSet` | `System.Collections.Generic.HashSet`1<System.Int32>` |  | 176 |
| `_StoppedReqIdList` | `System.Collections.Generic.List`1<System.UInt32>` |  | 184 |
| `_LegacyVibratingPad` | `System.UInt32` |  | 192 |
| `_LegacyVibReqIdList` | `System.UInt32[,]` |  | 200 |
| `_PreviousBits` | `System.UInt32` |  | 208 |
| `_ContinuousSec` | `System.Single[]` |  | 216 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean <triggerVibration>g__getDefineIdx|38_0(soundlib.SoundVibrationManager.<>c__DisplayClass38_0)
:System.Void <update>g__updateDefData|36_0()
:System.Void <update>g__updateDurationCallback|36_2()
:System.Void <update>g__updateHDVibration|36_3()
:System.Void <update>g__updateLeftTime|36_5()
:System.Void <update>g__updateStopped|36_4()
:System.Void <update>g__updateWavData|36_1()
:System.Void addDefinition(soundlib.SoundVibrationDefineInfoListData)
:System.Void addVibByWavData(soundlib.SoundVibInfoByWav[])
:System.Void awake()
:System.Void changeVibrationPower(System.UInt32, System.Single, System.UInt32)
:System.UInt32 getWavIdFromVibInfoByWav(soundlib.SoundVibInfoByWav)
:System.Boolean isActivePad(System.Int32)
:System.Boolean isActivePadAny()
:System.Boolean isPlayingLegacyVib(System.Int32)
:System.Boolean isPlayingTrigger(System.UInt32)
:System.Void mute(System.Int32)
:System.Void onDestroy()
:System.Void onGamePadConnectedEvent(via.hid.GamePadDevice)
:System.Void onGameStartSetOption()
:System.Void onPostVibrationEvent(System.UInt32, System.Single, System.Single)
:System.Void onSetOptionData(chainsaw.option.OptionID, System.Int32, System.Int32)
:System.Void onUpdateInfo()
:System.Void onWwiseDurationCallback(via.simplewwise.DurationCallbackInfo)
:System.Void registerVibrationWaveIndex()
:System.Void removeDefinition(soundlib.SoundVibrationDefineInfoListData)
:System.Void removeVibByWavData(soundlib.SoundVibInfoByWav[])
:System.Void resetMotors(System.Int32)
:System.Void setMotorPower(System.Int32, System.Single, System.Single)
:System.Void stopAll()
:System.Void stopVibration(System.UInt32, System.UInt32)
:System.Void switchAllActivePad(System.Boolean)
:System.Void triggerVibration(System.UInt32, System.UInt32, soundlib.SoundVibrationManager.SideType, System.Single, System.Single)
:System.Void unmute(System.Int32)
:System.Void update()
:System.Void updateLegacyVibration(System.Boolean)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "get_Instance", ...)  -- soundlib.SoundVibrationManager get_Instance()
sdk.call_native_func(nil, type_def, "get_IsTargetPlatform", ...)  -- System.Boolean get_IsTargetPlatform()
sdk.call_native_func(nil, type_def, "get_PadDisplayName", ...)  -- System.String[] get_PadDisplayName()
sdk.call_native_func(nil, type_def, "set_Instance", ...)  -- System.Void set_Instance(soundlib.SoundVibrationManager)
sdk.call_native_func(nil, type_def, "set_IsTargetPlatform", ...)  -- System.Void set_IsTargetPlatform(System.Boolean)
```

## `soundlib.SoundVibrationManager.SideType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BothSides` | `soundlib.SoundVibrationManager.SideType` | yes | 16 |
| `LeftSide` | `soundlib.SoundVibrationManager.SideType` | yes | 16 |
| `RightSide` | `soundlib.SoundVibrationManager.SideType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `soundlib.SoundVibrationManager.SideType[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibrationManager.SideType)
:soundlib.SoundVibrationManager.SideType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibrationManager.SideType)
:System.Void CopyTo(soundlib.SoundVibrationManager.SideType[], System.Int32)
:soundlib.SoundVibrationManager.SideType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibrationManager.SideType> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibrationManager.SideType)
:System.Void Insert(System.Int32, soundlib.SoundVibrationManager.SideType)
:System.Boolean Remove(soundlib.SoundVibrationManager.SideType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibrationManager.SideType)
:soundlib.SoundVibrationManager.SideType get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibrationManager.SideType)
```

## `soundlib.SoundVibrationManager.VibrationInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IsHD` | `System.Boolean` |  | 16 |
| `IsLegacy` | `System.Boolean` |  | 17 |
| `PadIdx` | `System.Int32` |  | 20 |
| `VibTrgId` | `System.UInt32` |  | 24 |
| `ReqId` | `System.UInt32` |  | 28 |
| `VibAudioSource` | `via.audiorender.VibrationSourceResourceHolder` |  | 32 |
| `SideType` | `soundlib.SoundVibrationManager.SideType` |  | 40 |
| `Volume` | `System.Single` |  | 44 |
| `DefPowerL` | `System.Single` |  | 48 |
| `DefPowerR` | `System.Single` |  | 52 |
| `DefPowerAverage` | `System.Single` |  | 56 |
| `PowerL` | `System.Single` |  | 60 |
| `PowerR` | `System.Single` |  | 64 |
| `Playing` | `System.Boolean` |  | 68 |
| `LeftTimeSec` | `System.Single` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
```

## `soundlib.SoundVibrationManager.VibrationInfo[]`

**Methods**

```lua
:System.Void Add(soundlib.SoundVibrationManager.VibrationInfo)
:soundlib.SoundVibrationManager.VibrationInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.SoundVibrationManager.VibrationInfo)
:System.Void CopyTo(soundlib.SoundVibrationManager.VibrationInfo[], System.Int32)
:soundlib.SoundVibrationManager.VibrationInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.SoundVibrationManager.VibrationInfo> GetEnumerator()
:System.Int32 IndexOf(soundlib.SoundVibrationManager.VibrationInfo)
:System.Void Insert(System.Int32, soundlib.SoundVibrationManager.VibrationInfo)
:System.Boolean Remove(soundlib.SoundVibrationManager.VibrationInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.SoundVibrationManager.VibrationInfo)
:soundlib.SoundVibrationManager.VibrationInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.SoundVibrationManager.VibrationInfo)
```

## `soundlib.SoundZoneBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_StaticCollider` | `System.Boolean` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Boolean get_StaticCollider()
:System.Void set_StaticCollider(System.Boolean)
```

## `soundlib.SoundZoneGenerator`

**Methods**

```lua
:System.Void .ctor()
```

## `soundlib.SoundZoneMaterial`

**Methods**

```lua
:System.Void .ctor()
```

## `soundlib.SoundZoneObsOcl`

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
```

## `soundlib.SoundZoneSpace`

**Methods**

```lua
:System.Void .ctor()
```

## `soundlib.ThresholdTrigger`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Threshold` | `System.Single` |  | 16 |
| `_TriggerId` | `System.UInt32` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_Threshold()
:System.UInt32 get_TriggerId()
```

## `soundlib.ThresholdTrigger[]`

**Methods**

```lua
:System.Void Add(soundlib.ThresholdTrigger)
:soundlib.ThresholdTrigger Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(soundlib.ThresholdTrigger)
:System.Void CopyTo(soundlib.ThresholdTrigger[], System.Int32)
:soundlib.ThresholdTrigger Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<soundlib.ThresholdTrigger> GetEnumerator()
:System.Int32 IndexOf(soundlib.ThresholdTrigger)
:System.Void Insert(System.Int32, soundlib.ThresholdTrigger)
:System.Boolean Remove(soundlib.ThresholdTrigger)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, soundlib.ThresholdTrigger)
:soundlib.ThresholdTrigger get_Item(System.Int32)
:System.Void set_Item(System.Int32, soundlib.ThresholdTrigger)
```
