# `soundlib.*`

136 types.

## `soundlib.EnumBool`

```lua
-- values (System.Int32 enum)
False
True
```

## `soundlib.JointParam`

```lua
-- fields
_JointHash: System.UInt32
-- methods
:System.UInt32 get_JointHash()
:System.Void set_JointHash(System.UInt32)
```

## `soundlib.PhysicsValueType`

```lua
-- values (System.Int32 enum)
AngularMomemtum
AngularVelocity
FrictionFactor
LinearVelocity
MassTimesFrictionFactor
Momentum
```

## `soundlib.SoundAABB`

```lua
-- fields
_AABB: via.AABB
_TransformedAABB: via.AABB
-- methods
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

```lua
-- fields
_RequestInfoPtr: soundlib.SoundManager.RequestInfo
-- methods
:System.Void onCreateRequestInfo(System.UInt32, System.Boolean, via.Transform)
:System.Void onPostEvent(via.GameObject)
:System.Void onSetRequestInfo()
:System.Void onStopEvent(via.GameObject)
:System.Void register()
:System.Void unregister()
```

## `soundlib.SoundAudioInputCaller`

```lua
-- fields
_Container: soundlib.SoundContainer
_RequestInfo: soundlib.SoundManager.RequestInfo
channelCount: System.UInt32
samplingRate: System.UInt32
-- methods
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

## `soundlib.SoundBakeTriggerTracks`

```lua
-- fields
BakeCategory: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundBankListData`

```lua
-- fields
_BankList: via.simplewwise.BankResourceHolder[]
-- methods
:via.simplewwise.BankResourceHolder[] get_BankList()
```

## `soundlib.SoundBehaviorTreeActionBase`

```lua
-- fields
_Timing: soundlib.SoundBehaviorTreeActionBase.SetTiming
-- methods
:soundlib.SoundBehaviorTreeActionBase.SetTiming get_Timing()
```

## `soundlib.SoundBehaviorTreeActionBase.SetTiming`

```lua
-- values (System.Int32 enum)
End
Start
Update
```

## `soundlib.SoundBodyMaterialParam`

```lua
-- fields
_BodyId: System.Int32
_MaterialId: System.UInt32
_RayFilter: via.physics.CollisionFilterResourceHolder
_RayLength: System.Single
_RayQuery: via.physics.CastRayQuery
_RayResult: via.physics.CastRayResult
_UpdateOverlapping: System.Boolean
-- methods
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

## `soundlib.SoundCapsule`

```lua
-- fields
_Capsule: via.Capsule
_TransformedCapsule: via.Capsule
-- methods
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

```lua
-- fields
_OverrideStateList: System.Collections.Generic.List`1<soundlib.SoundOverrideState>
-- methods
:System.Void finalize()
:System.Collections.Generic.List`1<soundlib.SoundOverrideState> get_OverrideStateList()
:System.Void onClipHalfwayPlay()
:System.Void onClipHalfwayPlayEnd()
:System.Void onUnload()
:System.Void set_OverrideStateList(System.Collections.Generic.List`1<soundlib.SoundOverrideState>)
```

## `soundlib.SoundClipTrigger`

```lua
-- fields
OnTriggerAction: System.Action
PrevDiffFrame: System.Single
_EnableTrigger: System.Boolean
_TriggerId: System.UInt32
-- methods
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

```lua
-- fields
_ClipTriggerList: System.Collections.Generic.List`1<soundlib.SoundClipTrigger>
_Container: soundlib.SoundContainer
-- methods
:System.Void awake()
:System.Collections.Generic.List`1<soundlib.SoundClipTrigger> get_ClipTriggerList()
:System.Void onClipHalfwayPlay()
:System.Void onClipHalfwayPlayEnd()
:System.Void onUnload()
:System.Void set_ClipTriggerList(System.Collections.Generic.List`1<soundlib.SoundClipTrigger>)
```

## `soundlib.SoundConstants`

```lua
-- fields
AllPadBitMask: System.UInt32 [static]
EmptyStrHash: System.UInt32 [static]
InvalidBlendedLastLayerIdx: System.Int32 [static]
InvalidCullingId: System.UInt32 [static]
InvalidGameObjId: System.UInt64 [static]
InvalidId: System.UInt32 [static]
InvalidPlayingId: System.UInt32 [static]
MaxCentVal: System.Single [static]
MaxContactPoints: System.Int32 [static]
MaxDbVal: System.Single [static]
MaxPadNum: System.UInt32 [static]
MinCentVal: System.Single [static]
MinDbVal: System.Single [static]
PadBitMask: System.UInt32[] [static]
RootJointHash: System.UInt32 [static]
StopDuration: System.Single [static]
ZeroDbVal: System.Single [static]
```

## `soundlib.SoundConstants.PadIndex`

```lua
-- values (System.Int32 enum)
Pad_00
Pad_01
```

## `soundlib.SoundContainer`

```lua
-- fields
HasTriggerInfo: System.Boolean [static]
_GroupCore: System.Boolean [static]
_GroupDebug: System.Boolean [static]
_GroupResource: System.Boolean [static]
OnPostRequestInfoEnd: System.Action`1<soundlib.SoundManager.RequestInfo>
OnPostRequestInfoStart: System.Action`1<soundlib.SoundManager.RequestInfo>
OnStart: System.Action
OnUnload: System.Action
OnUpdate: System.Action
_AdditionalContentIdSet: System.Collections.Generic.HashSet`1<System.UInt32>
_ExtensionDict: System.Collections.Generic.Dictionary`2<System.Type,soundlib.SoundContainerExtensionBase>
_ExtensionList: System.Collections.Generic.List`1<soundlib.SoundContainerExtensionBase>
_FailedRequestInfo: soundlib.SoundManager.RequestInfo
_LoadedData: System.Boolean
_Rand: via.Random
_SortedInfo: System.Boolean
_TriggerInfoList: System.Collections.Generic.List`1<soundlib.SoundTriggerInfo>
_UserDataList: System.Collections.Generic.List`1<soundlib.SoundContainableUserData>
-- methods
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
-- static
:System.Boolean <createRequestInfo>g__isNeedSetSwitch|67_0(System.UInt32[], System.UInt32)
:System.Boolean <trigger>g__withinTriggerRange|56_0(soundlib.SoundContainer.<>c__DisplayClass56_0)
```

## `soundlib.SoundContainerExtensionBase`

```lua
-- fields
_Container: soundlib.SoundContainer
_Enabled: System.Boolean
_GameObject: via.GameObject
-- methods
:System.Boolean get_Enabled()
:System.String get_ExtensionName()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onDisable()
:System.Void onEnable()
:System.Void set_Enabled(System.Boolean)
```

## `soundlib.SoundContainerListData`

```lua
-- fields
_BaseUserDataList: soundlib.SoundContainableUserData[]
_UserDataList: soundlib.SoundContainableUserData[]
-- methods
:soundlib.SoundContainableUserData[] get_BaseUserDataList()
:soundlib.SoundContainableUserData[] get_UserDataList()
```

## `soundlib.SoundCountRepeatTriggerTracks`

```lua
-- fields
TriggerCount: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundDisableAnimFootContactTracks`

```lua
-- fields
Disable: System.Boolean
-- methods
:System.Void clear()
```

## `soundlib.SoundDisplayOrder`

```lua
-- fields
Body: System.Int32 [static]
Footer: System.Int32 [static]
Header: System.Int32 [static]
```

## `soundlib.SoundGameParameterApp`

```lua
-- fields
_Global: System.Boolean
_JointHash: System.UInt32[]
_RestrictUpdate: System.Boolean
_RtpcId: System.UInt32
_SetOnce: System.Boolean
-- methods
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

```lua
-- fields
_GameObjId: System.UInt64
_Released: System.Boolean
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Void addGameParameterApp(soundlib.SoundManager.RequestInfo)
:System.Collections.Generic.List`1<soundlib.SoundGameParameterAppParam> get_GameParameterAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGameParameterAppListData`

```lua
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundGameParameterAppParam`

```lua
-- methods
:soundlib.SoundGameParameterApp get_GameParameterApp()
:System.Void set_GameParameterApp(soundlib.SoundGameParameterApp)
```

## `soundlib.SoundGetGameParameter`

```lua
-- fields
_GameParameterName: System.String [static]
_GameParameterId: System.UInt32
_Global: System.Boolean
_JointHash: System.UInt32
-- methods
:System.UInt32 get_GameParameterId()
:System.Boolean get_Global()
:System.UInt32 get_JointHash()
:System.Void set_GameParameterId(System.UInt32)
```

## `soundlib.SoundGetGameParameterListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundGetGameParameterParam> get_GetGameParameterParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGetGameParameterListData`

```lua
-- fields
_GetGameParameterList: soundlib.SoundGetGameParameter[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGetGameParameter[] get_GetGameParameterList()
```

## `soundlib.SoundGetGameParameterParam`

```lua
-- methods
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

## `soundlib.SoundGpuClothTrigger`

```lua
-- fields
_AntiRepeatTime: System.Single
_ThresholdTriggerList: soundlib.ThresholdTrigger[]
_TriggerAll: System.Boolean
_TriggerType: soundlib.SoundGpuClothTrigger.Type
-- methods
:System.Single get_AntiRepeatTime()
:soundlib.ThresholdTrigger[] get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
:soundlib.SoundGpuClothTrigger.Type get_TriggerType()
```

## `soundlib.SoundGpuClothTrigger.Type`

```lua
-- values (System.Int32 enum)
Acceleration
Movement
Speed
```

## `soundlib.SoundGpuClothTriggerListBehavior`

```lua
-- fields
_GroupParam: System.Boolean [static]
_GpuCloth: via.dynamics.GpuCloth
_UseAcceleration: System.Boolean
_UseSpeed: System.Boolean
-- methods
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

```lua
-- fields
_GpuClothTriggerList: soundlib.SoundGpuClothTrigger[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGpuClothTrigger[] get_GpuClothTriggerList()
```

## `soundlib.SoundGpuClothTriggerParam`

```lua
-- methods
:System.Single get_ElapsedSecond()
:soundlib.SoundGpuClothTrigger get_GpuClothTrigger()
:System.Boolean get_Posted()
:System.Void set_ElapsedSecond(System.Single)
:System.Void set_Posted(System.Boolean)
```

## `soundlib.SoundGuvSetState`

```lua
-- fields
_SetStateListData: soundlib.SoundSetStateListData
_ValueList: soundlib.SoundGuvSetState.GuvSetStateValue[]
-- methods
:soundlib.SoundSetStateListData get_SetStateListData()
:soundlib.SoundGuvSetState.GuvSetStateValue[] get_ValueList()
```

## `soundlib.SoundGuvSetState.GuvSetStateValue`

```lua
-- fields
_IsVariableTypeBool: System.Boolean [static]
_IsVariableTypeFloat: System.Boolean [static]
_IsVariableTypeInt: System.Boolean [static]
_IsVariableTypeUint: System.Boolean [static]
_ComparisonBool: System.Boolean
_ComparisonFloat: System.Single
_ComparisonInt: System.Int32
_ComparisonMaxFloat: System.Single
_ComparisonMaxInt: System.Int32
_ComparisonMaxUint: System.UInt32
_ComparisonMinFloat: System.Single
_ComparisonMinInt: System.Int32
_ComparisonMinUint: System.UInt32
_ComparisonUint: System.UInt32
_GlobalVariable: via.userdata.Variable
_GlobalVariableGuid: System.Guid
_OperatorType: soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType
-- methods
:System.Boolean checkMatchValue()
:System.Guid get_GlobalVariableGuid()
:soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType get_VariableType()
:System.Void set_GlobalVariableGuid(System.Guid)
:System.Void set_VariableType(soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType)
:System.Void updateVariable(System.Guid)
```

## `soundlib.SoundGuvSetState.GuvSetStateValue.ComparisonOperatorType`

```lua
-- values (System.Int32 enum)
Between
Equal
GreaterThan
GreaterThanOrEqual
LessThan
LessThanOrEqual
NotEqual
```

## `soundlib.SoundGuvSetState.GuvSetStateValue.GuvVariableType`

```lua
-- values (System.Int32 enum)
Boolean
Float
Int
Uint
Unknown
```

## `soundlib.SoundGuvSetStateListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundGuvSetStateParam> get_GuvSetStateParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundGuvSetStateListData`

```lua
-- fields
_GuvSetStateList: soundlib.SoundGuvSetState[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundGuvSetState[] get_GuvSetStateList()
```

## `soundlib.SoundGuvSetStateParam`

```lua
-- methods
:soundlib.SoundGuvSetState get_GuvSetState()
:System.Boolean get_Matched()
:System.Void set_GuvSetState(soundlib.SoundGuvSetState)
:System.Void set_Matched(System.Boolean)
```

## `soundlib.SoundIdCategory`

```lua
-- fields
AdditionalContent: System.Int32 [static]
BakeCategory: System.Int32 [static]
CullingId1: System.Int32 [static]
CullingId2: System.Int32 [static]
CullingId3: System.Int32 [static]
Joint: System.Int32 [static]
MotionStatus: System.Int32 [static]
None: System.Int32 [static]
PartsCategory: System.Int32 [static]
Portal: System.Int32 [static]
RandomTonePreset: System.Int32 [static]
Space: System.Int32 [static]
Trigger: System.Int32 [static]
TriggerTarget: System.Int32 [static]
TriggerType: System.Int32 [static]
VibrationTrigger: System.Int32 [static]
VibrationType: System.Int32 [static]
```

## `soundlib.SoundJointAngleTrigger`

```lua
-- fields
_Absolute: System.Boolean
_AntiRepeatTime: System.Single
_BakeCategory: System.UInt32
_JointAHash: System.UInt32
_JointAxis: System.Byte
_JointBHash: System.UInt32
_JointCenterHash: System.UInt32
_ThresholdTriggerList: System.Collections.Generic.List`1<soundlib.ThresholdTrigger>
_TriggerAll: System.Boolean
-- methods
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

```lua
-- fields
_MotSeq: chainsaw.SoundMotionSequenceApp
_PrevMute: System.Boolean
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointAngleTriggerParam> get_JointAngleTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Boolean isPlayingBakeCategory(System.UInt32)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointAngleTriggerListData`

```lua
-- fields
_JointAngleTriggerList: soundlib.SoundJointAngleTrigger[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointAngleTrigger[] get_JointAngleTriggerList()
```

## `soundlib.SoundJointAngleTriggerParam`

```lua
-- methods
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

## `soundlib.SoundJointContactTrigger`

```lua
-- fields
_AntiRepeatTime: System.Single
_JointHash: System.UInt32
_OffsetY: System.Single
_ThresholdDistance: System.Single
_ThresholdTriggerList: System.Collections.Generic.List`1<soundlib.ThresholdTrigger>
-- methods
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Single get_OffsetY()
:System.Single get_ThresholdDistance()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
```

## `soundlib.SoundJointContactTriggerListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointContactTriggerParam> get_JointContactTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointContactTriggerListData`

```lua
-- fields
_JointContactTriggerList: soundlib.SoundJointContactTrigger[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointContactTrigger[] get_JointContactTriggerList()
```

## `soundlib.SoundJointContactTriggerParam`

```lua
-- methods
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

## `soundlib.SoundJointRotationTrigger`

```lua
-- fields
_AntiRepeatTime: System.Single
_JointHash: System.UInt32
_ThresholdTriggerList: System.Collections.Generic.List`1<soundlib.ThresholdTrigger>
_TriggerAll: System.Boolean
-- methods
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundJointRotationTriggerListBehavior`

```lua
-- fields
_PrevMute: System.Boolean
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointRotationTriggerParam> get_JointRotationTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointRotationTriggerListData`

```lua
-- fields
_JointRotationTriggerList: soundlib.SoundJointRotationTrigger[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointRotationTrigger[] get_JointRotationTriggerList()
```

## `soundlib.SoundJointRotationTriggerParam`

```lua
-- methods
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

## `soundlib.SoundJointVelocityTrigger`

```lua
-- fields
_AntiRepeatTime: System.Single
_JointHash: System.UInt32
_ThresholdTriggerList: System.Collections.Generic.List`1<soundlib.ThresholdTrigger>
_TriggerAll: System.Boolean
-- methods
:System.Single get_AntiRepeatTime()
:System.UInt32 get_JointHash()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundJointVelocityTriggerListBehavior`

```lua
-- fields
_PrevMute: System.Boolean
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundJointVelocityTriggerParam> get_JointVelocityTriggerParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onWorldOffset(via.vec3)
:System.Void start()
:System.Void update()
```

## `soundlib.SoundJointVelocityTriggerListData`

```lua
-- fields
_JointVelocityTriggerList: soundlib.SoundJointVelocityTrigger[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundJointVelocityTrigger[] get_JointVelocityTriggerList()
```

## `soundlib.SoundJointVelocityTriggerParam`

```lua
-- methods
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

## `soundlib.SoundListener`

```lua
-- fields
_GroupDebug: System.Boolean [static]
_Activated: System.Boolean
_AngleLR: System.Single
_Camera: via.Camera
_EnableAxisY: System.Boolean
_Fov: System.Single
_InvertAxisZ: System.Boolean
_LastAxisX: via.vec3
_LastAxisY: via.vec3
_LastAxisZ: via.vec3
_LastPos: via.vec3
_ListenerIdx: soundlib.SoundListener.ListenerIndex
_MaxSpeakerAngleLR: System.Single
_MinSpeakerAngleLR: System.Single
_Offset: via.vec3
_SyncFOV: System.Boolean
_SyncNearClipPlane: System.Boolean
_Update: System.Boolean
-- methods
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

```lua
-- values (System.Int32 enum)
Max
No0
No1
No2
No3
No4
No5
No6
No7
None
```

## `soundlib.SoundLoopTriggerTracks`

```lua
-- fields
FadeDuration: System.UInt32
ForceTriggerOverwrittenJoint: soundlib.EnumBool
JointHash: System.UInt32
Mute: soundlib.EnumBool
TriggerId: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundManager`

```lua
-- fields
OnDuration: System.Action`1<soundlib.SoundManager.DurationInfo> [static]
OnEndOfEventRequestId: System.Action`1<System.UInt32> [static]
OnMarker: System.Action`1<soundlib.SoundManager.MarkerInfo> [static]
OnMusicCustomCue: System.Action`1<soundlib.SoundManager.MusicSyncInfo> [static]
OnMusicSync: System.Action`1<soundlib.SoundManager.MusicSyncInfo> [static]
OnMusicSyncExit: System.Action`1<soundlib.SoundManager.MusicSyncInfo> [static]
OnTriggerEnd: System.Action`1<System.UInt32> [static]
OnTriggerStart: System.Action`1<System.UInt32> [static]
_AudioInputList: System.Collections.Generic.List`1<soundlib.SoundAudioInput> [static]
_CullingCache: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_CullingInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_DurationCallbackInfoQueue: System.Collections.Generic.Queue`1<via.simplewwise.DurationCallbackInfo> [static]
_EndOfEventQueue: System.Collections.Generic.Queue`1<via.simplewwise.EventCallbackInfo> [static]
_EndOfReqIdQueue: System.Collections.Generic.Queue`1<System.UInt32> [static]
_EndTriggerQueue: System.Collections.Generic.Queue`1<System.UInt32> [static]
_EndedReqIdGameObjIdQueue: System.Collections.Generic.Queue`1<System.ValueTuple`2<System.UInt32,System.UInt64>> [static]
_GameObjectInfoDict: System.Collections.Generic.Dictionary`2<System.UInt64,soundlib.SoundManager.GameObjectInfo> [static]
_GameParameterAppInfoDict: System.Collections.Generic.Dictionary`2<System.UInt64,System.Collections.Generic.List`1<soundlib.SoundManager.GameParameterAppInfo>> [static]
_GetGameParameterParamList: System.Collections.Generic.List`1<soundlib.SoundGetGameParameterParam> [static]
_GetGameParameterParamQueue: System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundGetGameParameterParam,System.Boolean>> [static]
_GlobalGameParameterAppInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.GameParameterAppInfo> [static]
_GuvSetStateParamList: System.Collections.Generic.HashSet`1<soundlib.SoundGuvSetStateParam> [static]
_HalfwayPlayClipCount: System.UInt32 [static]
_MarkerCallbackInfoQueue: System.Collections.Generic.Queue`1<via.simplewwise.MarkerCallbackInfo> [static]
_MusicSyncCallbackInfoQueue: System.Collections.Generic.Queue`1<via.simplewwise.MusicSyncCallbackInfo> [static]
_MusicSyncInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.MusicSyncInfo> [static]
_OverrideStateList: System.Collections.Generic.List`1<soundlib.SoundOverrideState> [static]
_Rand: via.Random [static]
_RemoveCullingCache: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_RequestInfoDict: System.Collections.Generic.Dictionary`2<System.UInt32,soundlib.SoundManager.RequestInfo> [static]
_RequestInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_ResidualResourcesDict: System.Collections.Generic.Dictionary`2<System.UInt32,System.ValueTuple`2<System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder>,System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder>>> [static]
_SoundListeners: soundlib.SoundListener[] [static]
_StartTriggerQueue: System.Collections.Generic.Queue`1<System.UInt32> [static]
_StateAppDict: System.Collections.Generic.Dictionary`2<soundlib.SoundStateAppParamBase,System.Int32> [static]
_StoppedEventParametersList: System.Collections.Generic.List`1<System.ValueTuple`4<via.GameObject,System.UInt32,System.UInt32,soundlib.SoundManager.StoppedEventType>> [static]
_SyncDrawReqInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_SyncDrawReqInfoQueue: System.Collections.Generic.Queue`1<soundlib.SoundManager.RequestInfo> [static]
_UnloadContainerResourcesQueue: System.Collections.Generic.Queue`1<System.ValueTuple`3<System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>,System.Collections.Generic.List`1<via.simplewwise.BankResourceHolder>,System.Collections.Generic.List`1<via.simplewwise.PackageResourceHolder>>> [static]
_UpdatedReqIdPlayingIdQueue: System.Collections.Generic.Queue`1<System.ValueTuple`2<System.UInt32,System.UInt32>> [static]
_VirtualReqInfoList: System.Collections.Generic.List`1<soundlib.SoundManager.RequestInfo> [static]
_VirtualReqInfoQueue: System.Collections.Generic.Queue`1<soundlib.SoundManager.RequestInfo> [static]
_VolGameParIdList: System.UInt32[] [static]
-- static
:System.Boolean <postRequestInfo>g__culling|107_0(soundlib.SoundManager.<>c__DisplayClass107_0)
:System.Void <updateQueue>g__addGetGameParameter|130_0(soundlib.SoundGetGameParameterParam)
:System.Void <updateQueue>g__removeGetGameParameter|130_1(soundlib.SoundGetGameParameterParam)
:System.Void <updateRemoveRequest>g__removeMusicSync|122_0(System.UInt32)
:System.Void <updateStopEvent>g__removeParam|120_0(soundlib.SoundManager.<>c__DisplayClass120_0)
:soundlib.SoundManager.GameObjectInfo addGameObjectInfo(soundlib.SoundManager.RequestInfo)
:System.Void addGameParameterApp(System.UInt64, System.UInt32, soundlib.SoundGameParameterAppParam)
:System.Void addGetGameParameter(soundlib.SoundGetGameParameterParam)
:System.Void addGloablGameParameterApp(soundlib.SoundGameParameterAppParam)
:System.Void addGuvSetStateParam(soundlib.SoundGuvSetStateParam)
:System.Void addListener(soundlib.SoundListener)
:System.Void addOverrideStateList(soundlib.SoundOverrideState)
:System.Void addStateApp(soundlib.SoundStateAppParamBase)
:System.Void add_OnDuration(System.Action`1<soundlib.SoundManager.DurationInfo>)
:System.Void add_OnEndOfEventRequestId(System.Action`1<System.UInt32>)
:System.Void add_OnMarker(System.Action`1<soundlib.SoundManager.MarkerInfo>)
:System.Void add_OnMusicCustomCue(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void add_OnMusicSync(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void add_OnMusicSyncExit(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void add_OnTriggerEnd(System.Action`1<System.UInt32>)
:System.Void add_OnTriggerStart(System.Action`1<System.UInt32>)
:System.Void decHalfwayPlayClipCount()
:System.Boolean existHalfwayPlayClip()
:soundlib.SoundListener getListener(soundlib.SoundListener.ListenerIndex)
:System.Boolean get_BypassGameParameterInterpolationOnPlay()
:System.UInt32 get_CurrentFrame()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32> get_CurrentStateDict()
:System.Byte get_GameParameterUpdateFreq()
:System.UInt32 get_GeneratorClosestUpdateFreq()
:System.Boolean get_Initialized()
:via.simplewwise.Material get_Material()
:System.Boolean get_MuteAutoTrigger()
:System.UInt32 get_PauseAllEvent()
:System.UInt32 get_PlayPositionGetterSilentEvent()
:System.UInt32 get_ResumeAllEvent()
:System.Collections.Generic.List`1<soundlib.SoundManager.SaveStateInfo> get_SaveStateInfoList()
:chainsaw.SoundSpatialAudioManagerApp get_SpatialAudioManager()
:System.Byte get_SrcPositionUpdateFreq()
:via.simplewwise.BankResourceHolder get_SystemBank()
:System.UInt64 get_SystemGameObjId()
:System.UInt32 get_UpdateGameObjectStateFreq()
:System.UInt32[] get_VolGameParIdList()
:System.Void incCurrentFrame()
:System.Void incHalfwayPlayClipCount()
:System.Void initialize(soundlib.SoundManagerSettings)
:System.Void onDeletedRequestIdGameObjectIdPairThisFrame(System.UInt32, System.UInt64)
:System.Void onDuration(via.simplewwise.DurationCallbackInfo)
:System.Void onEndOfEvent(via.simplewwise.EventCallbackInfo)
:System.Void onMarker(via.simplewwise.MarkerCallbackInfo)
:System.Void onMusicSync(via.simplewwise.MusicSyncCallbackInfo)
:System.Void onPostedRequstIdPlayingIdPairThisFrame(System.UInt32, System.UInt32)
:System.Void pauseAll()
:System.Void postEvent(System.UInt64, System.UInt32, System.UInt32, via.simplewwise.CallbackType, System.Boolean, System.Int32, via.wwiselib.CurveInterpolationType)
:System.UInt32 postRequestInfo(soundlib.SoundManager.RequestInfo)
:System.Void registerSpatialAudioManager(soundlib.SoundSpatialAudioManager)
:System.Void removeGameParameterApp(System.UInt64, System.UInt32)
:System.Void removeGetGameParameter(soundlib.SoundGetGameParameterParam)
:System.Void removeGlobalGameParameterApp(soundlib.SoundGameParameterAppParam)
:System.Void removeGuvSetStateParam(soundlib.SoundGuvSetStateParam)
:System.Void removeListener(soundlib.SoundListener)
:System.Void removeOverrideStateList(soundlib.SoundOverrideState)
:System.Void removeRequestInfo(System.UInt32)
:System.Void removeStateApp(soundlib.SoundStateAppParamBase)
:System.Void remove_OnDuration(System.Action`1<soundlib.SoundManager.DurationInfo>)
:System.Void remove_OnEndOfEventRequestId(System.Action`1<System.UInt32>)
:System.Void remove_OnMarker(System.Action`1<soundlib.SoundManager.MarkerInfo>)
:System.Void remove_OnMusicCustomCue(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void remove_OnMusicSync(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void remove_OnMusicSyncExit(System.Action`1<soundlib.SoundManager.MusicSyncInfo>)
:System.Void remove_OnTriggerEnd(System.Action`1<System.UInt32>)
:System.Void remove_OnTriggerStart(System.Action`1<System.UInt32>)
:System.Void resetState(System.UInt32)
:System.Void resumeAll()
:System.Void setRtpcValue(System.UInt64, System.UInt32, System.Single, System.Boolean, System.Single, System.Boolean)
:System.Void setState(System.UInt32, System.UInt32)
:System.Void set_BypassGameParameterInterpolationOnPlay(System.Boolean)
:System.Void set_CurrentFrame(System.UInt32)
:System.Void set_CurrentStateDict(System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>)
:System.Void set_GameParameterUpdateFreq(System.Byte)
:System.Void set_GeneratorClosestUpdateFreq(System.UInt32)
:System.Void set_Initialized(System.Boolean)
:System.Void set_MuteAutoTrigger(System.Boolean)
:System.Void set_PauseAllEvent(System.UInt32)
:System.Void set_PlayPositionGetterSilentEvent(System.UInt32)
:System.Void set_ResumeAllEvent(System.UInt32)
:System.Void set_SaveStateInfoList(System.Collections.Generic.List`1<soundlib.SoundManager.SaveStateInfo>)
:System.Void set_SpatialAudioManager(chainsaw.SoundSpatialAudioManagerApp)
:System.Void set_SrcPositionUpdateFreq(System.Byte)
:System.Void set_SystemBank(via.simplewwise.BankResourceHolder)
:System.Void set_UpdateGameObjectStateFreq(System.UInt32)
:System.Void set_VolGameParIdList(System.UInt32[])
:System.Void stopAll()
:System.Void stopEvent(via.GameObject, System.UInt32, System.UInt32)
:System.Void stopEvent(System.UInt32[], System.UInt32)
:System.Void stopEventByRequestId(via.GameObject, System.UInt32, System.UInt32)
:System.Void stopEventTarget(via.GameObject, System.UInt32, System.UInt32)
:System.Void terminate()
:System.Void unloadContainer(soundlib.SoundContainer)
:System.Void unregisterSpatialAudioManager()
:System.Void update()
:System.Void updateCulling()
:System.Void updateDuration()
:System.Void updateEndOfEvent()
:System.Void updateEndOfEventRequestId()
:System.Void updateGameObjectState()
:System.Void updateGameParameter()
:System.Void updateMarker()
:System.Void updateMusicSync()
:System.Void updatePlayingId()
:System.Void updatePosition(System.Int32, System.Int32)
:System.Void updatePostRequestInfo()
:System.Void updateQueue()
:System.Void updateRemoveRequest()
:System.Void updateRtpcValue()
:System.Void updateState()
:System.Void updateStopEvent()
:System.Void updateSyncDraw()
:System.Void updateUnloadContainer()
:System.Void updateVirtualDistance(System.Int32)
```

## `soundlib.SoundManager.DurationInfo`

```lua
-- methods
:System.Single get_EstimatedDuration()
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MediaId()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
```

## `soundlib.SoundManager.GameObjectInfo`

```lua
-- fields
DrawGameObject: System.Boolean
UpdateGameObject: System.Boolean
-- methods
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

## `soundlib.SoundManager.GameParameterAppInfo`

```lua
-- methods
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

## `soundlib.SoundManager.MarkerInfo`

```lua
-- methods
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MarkerHash()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
```

## `soundlib.SoundManager.MusicSyncInfo`

```lua
-- methods
:System.UInt64 get_GameObjectId()
:System.UInt32 get_MusicCustomCueNameHash()
:System.UInt32 get_MusicSyncBar()
:System.UInt32 get_MusicSyncBeat()
:System.UInt32 get_RequestId()
:System.UInt32 get_TriggerId()
:System.Void set_MusicSyncBar(System.UInt32)
:System.Void set_MusicSyncBeat(System.UInt32)
```

## `soundlib.SoundManager.RequestInfo`

```lua
-- fields
OnEndOfEvent: System.Action`1<soundlib.SoundManager.RequestInfo>
OnPostEventStart: System.Action`1<soundlib.SoundManager.RequestInfo>
OnPostRequestInfoEnd: System.Action`1<soundlib.SoundManager.RequestInfo>
OnPostRequestInfoStart: System.Action`1<soundlib.SoundManager.RequestInfo>
-- methods
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

## `soundlib.SoundManager.SaveStateInfo`

```lua
-- methods
:System.UInt32 get_StateGroupId()
:System.UInt32 get_StateId()
:System.Void set_StateGroupId(System.UInt32)
:System.Void set_StateId(System.UInt32)
```

## `soundlib.SoundManager.StoppedEventType`

```lua
-- values (System.Int32 enum)
GameObjectEventIdDuration
GameObjectRequestIdDuration
Max
None
RequestIdDuration
TargetEventIdDuration
```

## `soundlib.SoundManagerSettings`

```lua
-- fields
_GroupOption: System.Boolean [static]
_GroupSystem: System.Boolean [static]
_BypassGameParameterInterpolationOnPlay: System.Boolean
_GameParameterUpdateFrame: System.Byte
_GeneratorClosestUpdateFreq: System.UInt32
_PauseAllEvent: System.UInt32
_PlayPositionGetterSilentEvent: System.UInt32
_ResumeAllEvent: System.UInt32
_SrcPositionUpdateFreq: System.Byte
_SystemBank: via.simplewwise.BankResourceHolder
_SystemBankId: System.UInt32
_VolGameParIdList: System.UInt32[]
-- methods
:System.Void applySettings()
:via.simplewwise.BankResourceHolder get_SystemBank()
:System.Void set_SystemBank(via.simplewwise.BankResourceHolder)
```

## `soundlib.SoundOBB`

```lua
-- fields
_OBB: via.OBB
_TransformedOBB: via.OBB
-- methods
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

```lua
-- fields
InKeyRange: System.Boolean
_Added: System.Boolean
_StateGroupId: System.UInt32
_StateId: System.UInt32
_UnableOverride: System.Boolean
-- methods
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

## `soundlib.SoundPackageListData`

```lua
-- fields
_PackageList: via.simplewwise.PackageResourceHolder[]
-- methods
:via.simplewwise.PackageResourceHolder[] get_PackageList()
```

## `soundlib.SoundPeriodicalTriggerTracks`

```lua
-- fields
MaxOffset: System.UInt32
MinOffset: System.UInt32
TriggerPeriod: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundPhysicsListBehavior`

```lua
-- fields
_TriggerInfoReserveNum: System.Int32 [static]
_Contact: System.Boolean
_ContactAngleVelocity: System.Single
_ContactBodyId: System.Int32
_ContactFrictionFactor: System.Single
_ContactLinearVelocity: System.Single
_ContactNormal: via.vec3
_ContactPosition: via.vec3
_DynamicsComponent: via.dynamics.RigidBodySet
_Overlapping: System.Boolean
_OverlappingAngleVelocity: System.Single
_OverlappingBodyId: System.Int32
_OverlappingFrictionFactor: System.Single
_OverlappingLinearVelocity: System.Single
_OverlappingNormal: via.vec3
_OverlappingPosition: via.vec3
_PhysicsTriggerInfoList: System.Collections.Generic.List`1<soundlib.SoundPhysicsListBehavior.PhysicsTriggerInfo>
_Separate: System.Boolean
_SeparateBody: System.Collections.Generic.HashSet`1<System.Int32>
-- methods
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

```lua
-- fields
BodyId: System.Int32
ContactPoint: System.Boolean
FinishedCastRay: System.Boolean
Position: via.vec3
TriggerId: System.UInt32
```

## `soundlib.SoundPhysicsListData`

```lua
-- fields
_GroupMaterial: System.Boolean [static]
_BodyMaterialParamList: soundlib.SoundBodyMaterialParam[]
_PhysicsSettingList: soundlib.SoundPhysicsSettings[]
_RayFilter: via.physics.CollisionFilterResourceHolder
_RayLength: System.Single
-- methods
:soundlib.SoundBodyMaterialParam[] get_BodyMaterialParamList()
:soundlib.SoundPhysicsSettings[] get_PhysicsSettingList()
:via.physics.CollisionFilterResourceHolder get_RayFilter()
:System.Single get_RayLength()
```

## `soundlib.SoundPhysicsSettings`

```lua
-- fields
CurrentValue: System.Single
ElapsedTime: System.Single
Posted: System.Boolean
_AntiRepeatTime: System.Single
_BodyIdList: System.Collections.Generic.List`1<System.Int32>
_ContactPoint: System.Boolean
_PhysicsValueType: soundlib.PhysicsValueType
_ThresholdTriggerList: System.Collections.Generic.List`1<soundlib.ThresholdTrigger>
_TriggerAll: System.Boolean
-- methods
:System.Single get_AntiRepeatTime()
:System.Collections.Generic.List`1<System.Int32> get_BodyIdList()
:System.Boolean get_ContactPoint()
:soundlib.PhysicsValueType get_PhysicsValueType()
:System.Collections.Generic.List`1<soundlib.ThresholdTrigger> get_ThresholdTriggerList()
:System.Boolean get_TriggerAll()
```

## `soundlib.SoundPhysicsValues`

```lua
-- methods
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

## `soundlib.SoundPlayPositionGetter`

```lua
-- fields
_Container: soundlib.SoundContainer
_RequestId: System.UInt32
-- methods
:System.Int32 get_SourcePlayPosition()
:System.Void onDestroy()
:System.Void onPostRequestInfo(soundlib.SoundManager.RequestInfo)
:System.Void start()
```

## `soundlib.SoundPoint`

```lua
-- fields
_Position: via.vec3
-- methods
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.vec3 get_Position()
```

## `soundlib.SoundPortal`

```lua
-- fields
_BackRoomHash: System.UInt32
_Enable: System.Boolean
_FrontRoomHash: System.UInt32
_OBB: via.OBB
_Obstruction: System.Single
_Occlusion: System.Single
-- methods
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

```lua
-- fields
_SpMgr: soundlib.SoundSpatialAudioManager
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundPortal> get_PortalList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundPortalListData`

```lua
-- fields
_PortalList: soundlib.SoundPortal[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundPortal[] get_PortalList()
```

## `soundlib.SoundRagdollListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
```

## `soundlib.SoundRagdollListData`

```lua
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundRigidBodyListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
```

## `soundlib.SoundRigidBodyListData`

```lua
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundRoom`

```lua
-- fields
_AuxBusId: System.UInt32
_AuxSendLevelToSelf: System.Single
_KeepRegistered: System.Boolean
_ReverbLevel: System.Single
_RoomHash: System.UInt32
_Rotation: via.Quaternion
_WallOcclusion: System.Single
-- methods
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

```lua
-- fields
_SpMgr: soundlib.SoundSpatialAudioManager
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundRoom> get_RoomList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundRoomListData`

```lua
-- fields
_RoomList: soundlib.SoundRoom[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundRoom[] get_RoomList()
```

## `soundlib.SoundSetState`

```lua
-- fields
_SetOnStart: System.Boolean
_StateGroupId: System.UInt32
_StateId: System.UInt32
-- methods
:System.Boolean get_SetOnStart()
:System.UInt32 get_StateGroupId()
:System.UInt32 get_StateId()
:System.Void setState()
:System.Void set_StateGroupId(System.UInt32)
```

## `soundlib.SoundSetStateListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundSetState> get_SetStateList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void setState()
:System.Void start()
```

## `soundlib.SoundSetStateListData`

```lua
-- fields
_SetStateList: soundlib.SoundSetState[]
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:soundlib.SoundSetState[] get_SetStateList()
```

## `soundlib.SoundShape`

```lua
-- methods
:via.AABB getBoundingAABB()
:System.Boolean get_EnableUpdate()
:via.vec3 get_Position()
:System.Void set_EnableUpdate(System.Boolean)
```

## `soundlib.SoundSpatialAudioManager`

```lua
-- fields
OnListenerRoomChanged: System.Action`1<soundlib.SoundRoom>
OnListenerRoomIdChanged: System.Action`1<System.UInt64>
```

## `soundlib.SoundSphere`

```lua
-- fields
_Sphere: via.Sphere
_TransformedSphere: via.Sphere
-- methods
:System.Void closest(via.vec3, via.vec3, System.Single)
:via.AABB getBoundingAABB()
:via.vec3 get_Position()
:via.Sphere get_Sphere()
:via.Sphere get_TransformedSphere()
:System.Void set_Sphere(via.Sphere)
:System.Void set_TransformedSphere(via.Sphere)
:System.Void update()
```

## `soundlib.SoundStateAppListBehavior`

```lua
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Void commonStart()
:System.Collections.Generic.List`1<soundlib.SoundStateAppParamBase> get_StateAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundStateAppListData`

```lua
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundStateAppParamBase`

```lua
-- methods
:soundlib.SoundStateAppBase get_StateApp()
:System.Void set_StateApp(soundlib.SoundStateAppBase)
```

## `soundlib.SoundStateTracks`

```lua
-- fields
StateGroupId: System.UInt32
StateId: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundSubManager`

```lua
-- methods
:System.Boolean get_Initialized()
:System.Void initialize(soundlib.SoundManagerSettingsBase)
:System.Void set_Initialized(System.Boolean)
:System.Void terminate()
```

## `soundlib.SoundSwitchAppBase`

```lua
-- fields
_JointHash: System.UInt32[]
-- methods
:System.UInt32[] get_JointHash()
```

## `soundlib.SoundSwitchAppListBehavior`

```lua
-- fields
_Released: System.Boolean
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.ValueTuple`2[[System.UInt32, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[System.UInt32, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][] getSwitch()
:System.Collections.Generic.List`1<soundlib.SoundSwitchAppParamBase> get_SwitchAppParamList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void onUnload()
:System.Void start()
```

## `soundlib.SoundSwitchAppListData`

```lua
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
```

## `soundlib.SoundSwitchAppParamBase`

```lua
-- methods
:soundlib.SoundSwitchAppBase get_SwitchApp()
:System.Void set_SwitchApp(soundlib.SoundSwitchAppBase)
```

## `soundlib.SoundTargetOperationTrigger`

```lua
-- fields
_GuiTriggerId: System.UInt32
_SoundTriggerId: System.UInt32
-- methods
:System.UInt32 get_GuiTriggerId()
:System.UInt32 get_SoundTriggerId()
```

## `soundlib.SoundTargetOperationTriggerListBehavior`

```lua
-- fields
_TargetOperationTriggerDict: System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>
-- methods
:System.Void addData(soundlib.SoundContainerExtensionDataBase)
:System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger> get_TargetOperationTriggerList()
:System.Void initialize(soundlib.SoundContainer)
:System.Void start()
:System.Void stopTriggered(System.UInt32, System.UInt32)
:System.Void trigger(System.UInt32)
```

## `soundlib.SoundTargetOperationTriggerListData`

```lua
-- fields
_GroupEdit: System.Boolean [static]
_GroupScriptSettings: System.Boolean [static]
_GroupTargetOperationDefinition: System.Boolean [static]
_TargetOperationTriggerList: System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger>
-- methods
:soundlib.SoundContainerExtensionBase createExtension()
:System.Type get_ExtensionType()
:System.Collections.Generic.List`1<soundlib.SoundTargetOperationTrigger> get_TargetOperationTriggerList()
```

## `soundlib.SoundTracksBase`

```lua
-- fields
Mute: soundlib.EnumBool
-- methods
:System.Void clear()
```

## `soundlib.SoundTriggerInfo`

```lua
-- fields
_BookingTime: System.UInt16
_CalcObsOcl: System.Boolean
_CullingId1: System.UInt32
_CullingId2: System.UInt32
_CullingId3: System.UInt32
_EventId: System.UInt32
_FlangingTime: System.UInt16
_Global: System.Boolean
_Limit: System.Byte
_ListenerBitMask: System.Byte
_Mute: System.Boolean
_OffsetFollow: System.Boolean
_OffsetGameObj: System.String
_OffsetIgnoreRot: System.Boolean
_OffsetJointHash: System.UInt32
_OffsetJointRotation: System.Boolean
_OffsetLisIdx: soundlib.SoundListener.ListenerIndex
_OffsetRandomPanning: via.vec3
_OffsetToListener: System.Single
_OffsetValue: via.vec3
_PrioritizeFirst: System.Boolean
_Priority: System.Byte
_ReleaseTime: System.UInt16
_SetRoom: System.Boolean
_SkipRate: System.Single
_Spatialization: System.UInt32
_StayAlive: System.Boolean
_SyncGameObjectDraw: System.Boolean
_SyncGameObjectState: System.Boolean
_TriggerId: System.UInt32
_TriggerRange: System.Single
_UnlimitObsOclDist: System.Boolean
_UpdateObsOcl: System.Boolean
_VirtualRange: System.Single
-- methods
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

```lua
-- fields
_Bank: via.simplewwise.BankResourceHolder
_TriggerInfoList: System.Collections.Generic.List`1<soundlib.SoundTriggerInfo>
-- methods
:via.simplewwise.BankResourceHolder get_Bank()
:System.Collections.Generic.List`1<soundlib.SoundTriggerInfo> get_TriggerInfoList()
:System.Void set_Bank(via.simplewwise.BankResourceHolder)
```

## `soundlib.SoundTriggerTracks`

```lua
-- fields
ForceTriggerOverwrittenJoint: soundlib.EnumBool
JointHash: System.UInt32
TriggerId: System.UInt32
-- methods
:System.Void clear()
```

## `soundlib.SoundUtility`

```lua
-- fields
OnLog: System.Action`2<soundlib.SoundUtility.LogLevel,System.String> [static]
-- static
:System.Void add_OnLog(System.Action`2<soundlib.SoundUtility.LogLevel,System.String>)
:System.Void errorLine(System.String)
:System.Void errorLine(via.GameObject, System.String)
:System.Void errorLine(System.String, System.Object[])
:System.Void errorLine(via.GameObject, System.String, System.Object[])
:System.Void fatalLine(System.String)
:System.Void fatalLine(System.String, System.Object[])
:System.Void getAllChildRecursive(via.GameObject, System.Collections.Generic.List`1<via.GameObject>, System.Type)
:via.GameObject getChildObjRecursively(via.GameObject, System.UInt32)
:System.Guid getId(via.GameObject)
:System.String getNameFromSoundId(System.UInt32)
:System.String getNameFromWwiseId(System.UInt32, via.simplewwise.IdType)
:System.Void infoLine(System.String)
:System.Void infoLine(via.GameObject, System.String)
:System.Void infoLine(System.String, System.Object[])
:System.Void infoLine(via.GameObject, System.String, System.Object[])
:System.Void remove_OnLog(System.Action`2<soundlib.SoundUtility.LogLevel,System.String>)
:System.Void warningLine(System.String)
:System.Void warningLine(via.GameObject, System.String)
:System.Void warningLine(System.String, System.Object[])
:System.Void warningLine(via.GameObject, System.String, System.Object[])
```

## `soundlib.SoundUtility.BitOperation`

```lua
-- static
:System.Void bitOff(System.UInt32, System.Int32)
:System.Void bitOn(System.UInt32, System.Int32)
:System.Boolean isBit(System.UInt32, System.Int32)
```

## `soundlib.SoundUtility.LogLevel`

```lua
-- values (System.Int32 enum)
Error
Fatal
Info
Warning
```

## `soundlib.SoundVibInfoBase`

```lua
-- fields
_Ignore: System.Boolean
_SendPad: System.UInt32
_VibrationTrigger: System.UInt32
_VibrationTypeId: System.UInt32
-- methods
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

## `soundlib.SoundVibInfoByTrigger`

```lua
-- fields
_SoundTriggerId: System.UInt32
-- methods
:System.UInt32 get_TriggerId()
:System.Boolean get_Valid()
```

## `soundlib.SoundVibInfoByTriggerListData`

```lua
-- fields
_VibrationInfoList: soundlib.SoundVibInfoByTrigger[]
-- methods
:soundlib.SoundVibInfoBase[] get_DataList()
```

## `soundlib.SoundVibInfoByWav`

```lua
-- fields
_WaveId: System.UInt32
-- methods
:System.Boolean get_Valid()
:System.UInt32 get_WaveId()
```

## `soundlib.SoundVibInfoByWavListData`

```lua
-- fields
_Lock: soundlib.SoundVibInfoByWavListData.LockObj
_RefCnt: System.Int32
_VibrationInfoList: soundlib.SoundVibInfoByWav[]
-- methods
:soundlib.SoundVibInfoBase[] get_DataList()
:System.Void requestRegister()
:System.Void requestUnRegister()
```

## `soundlib.SoundVibrationBehavior`

```lua
-- fields
_GroupDebug: System.Boolean [static]
_GroupSettings: System.Boolean [static]
_GroupUserData: System.Boolean [static]
_AssetList: soundlib.SoundVibInfoListDataBase[]
_ByTrgDict: System.Collections.Generic.Dictionary`2<System.UInt32,soundlib.SoundVibInfoByTrigger>
_Container: soundlib.SoundContainer
_TriggerInfoList: System.Collections.Generic.List`1<soundlib.SoundVibInfoBase>
_VibrationManager: soundlib.SoundVibrationManager
_WavIdAssetCount: System.Int32
-- methods
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

```lua
-- fields
Power: System.Single
Side: soundlib.SoundVibrationManager.SideType
TargetPadMask: System.UInt32
```

## `soundlib.SoundVibrationDefineInfo`

```lua
-- fields
_DurationMsec: System.Single
_DurationMsecHD: System.Single
_Ignore: System.Boolean
_MotorPower0: System.Single
_MotorPower1: System.Single
_SendPadMask: System.UInt32
_VibAudioSource: via.audiorender.VibrationSourceResourceHolder
_VibrationTrigger: System.UInt32
_Volume: System.Single
-- methods
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

```lua
-- fields
_RefCnt: System.Int32
_VibrationDefineInfoList: soundlib.SoundVibrationDefineInfo[]
-- methods
:System.Int32 addRefCnt()
:soundlib.SoundVibrationDefineInfo[] get_SoundVibrationDefineInfoList()
:System.Int32 subRefCnt()
```

## `soundlib.SoundVibrationDefineInfoListDataHolder`

```lua
-- fields
_Data: soundlib.SoundVibrationDefineInfoListData[]
-- methods
:System.Void awake()
:System.Void onDestroy()
```

## `soundlib.SoundVibrationDefinePair`

```lua
-- methods
:soundlib.SoundVibrationDefineInfo get_Info()
:soundlib.SoundVibrationDefineInfoListData get_UserData()
:System.UInt32 get_VibrationTrigger()
:System.Void set_Info(soundlib.SoundVibrationDefineInfo)
:System.Void set_UserData(soundlib.SoundVibrationDefineInfoListData)
-- static
:System.Collections.Generic.List`1<soundlib.SoundVibrationDefinePair> createDefinePair(soundlib.SoundVibrationDefineInfoListData)
```

## `soundlib.SoundVibrationManager`

```lua
-- fields
Deg2Rad30: System.Single [static]
_GroupDebug: System.Boolean [static]
_GroupParams: System.Boolean [static]
_GroupSettings: System.Boolean [static]
_ActivePadBits: System.UInt32
_BusIdTbl: System.UInt32[]
_ContinuousSec: System.Single[]
_DurationCallbackQueue: System.Collections.Generic.Queue`1<via.simplewwise.DurationCallbackInfo>
_LegacyVibReqIdList: System.UInt32[,]
_LegacyVibratingPad: System.UInt32
_MaxContinuousSec: System.Single
_MaxHdVibCnt: System.Int32
_PlayingPadIdxSet: System.Collections.Generic.HashSet`1<System.Int32>
_PreviousBits: System.UInt32
_SineWavResourceL: via.audiorender.VibrationSourceResourceHolder
_SineWavResourceR: via.audiorender.VibrationSourceResourceHolder
_SoundVibInfoByWavList: System.Collections.Generic.List`1<soundlib.SoundVibInfoByWav>
_SoundVibInfoByWavQueue: System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundVibInfoByWav[],System.Boolean>>
_StoppedReqIdList: System.Collections.Generic.List`1<System.UInt32>
_VibDefDataQueue: System.Collections.Generic.Queue`1<System.ValueTuple`2<soundlib.SoundVibrationDefineInfoListData,System.Boolean>>
_VibDefPairList: System.Collections.Generic.List`1<soundlib.SoundVibrationDefinePair>
_VibrationInfoList: System.Collections.Generic.List`1<soundlib.SoundVibrationManager.VibrationInfo>
-- methods
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
-- static
:soundlib.SoundVibrationManager get_Instance()
:System.Boolean get_IsTargetPlatform()
:System.String[] get_PadDisplayName()
:System.Void set_Instance(soundlib.SoundVibrationManager)
:System.Void set_IsTargetPlatform(System.Boolean)
```

## `soundlib.SoundVibrationManager.SideType`

```lua
-- values (System.Int32 enum)
BothSides
LeftSide
RightSide
```

## `soundlib.SoundVibrationManager.VibrationInfo`

```lua
-- fields
DefPowerAverage: System.Single
DefPowerL: System.Single
DefPowerR: System.Single
IsHD: System.Boolean
IsLegacy: System.Boolean
LeftTimeSec: System.Single
PadIdx: System.Int32
Playing: System.Boolean
PowerL: System.Single
PowerR: System.Single
ReqId: System.UInt32
SideType: soundlib.SoundVibrationManager.SideType
VibAudioSource: via.audiorender.VibrationSourceResourceHolder
VibTrgId: System.UInt32
Volume: System.Single
```

## `soundlib.SoundZoneBase`

```lua
-- fields
_StaticCollider: System.Boolean
-- methods
:System.Void awake()
:System.Boolean get_StaticCollider()
:System.Void set_StaticCollider(System.Boolean)
```

## `soundlib.SoundZoneObsOcl`

```lua
-- methods
:System.Void awake()
```

## `soundlib.ThresholdTrigger`

```lua
-- fields
_Threshold: System.Single
_TriggerId: System.UInt32
-- methods
:System.Single get_Threshold()
:System.UInt32 get_TriggerId()
```
