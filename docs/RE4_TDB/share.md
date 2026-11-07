# `share.*`

309 types.

## `share.AccountPickerResult`

```lua
-- values (System.Int32 enum)
DeviceDisconnected
Failed
GuestUser
InvalidUser
UserChanged
UserFirstChanged
UserUnchanged
```

## `share.AnalysisLogManagerAccessor`

```lua
-- fields
OPTION_ID_LIST: chainsaw.option.OptionID[] [static]
ChapterIDGameClear: System.String
ExtraChapterIDGameClear: System.String
InvalidDataStr: System.String
_AcquiredPtas: System.Int64
_BrokenKnifeCount: System.Int32
_CurrFrameMainPlayTime: share.AnalysisLogManagerAccessor.CurrentFramePlayTime
_DefaultUserIndex: via.UserIndex
_LastActiveSendTime: System.UInt64
_ReNetUnit_AnimalData: chainsaw.ReNetUnit_AnimalData
_ReNetUnit_AttackData: chainsaw.ReNetUnit_AttackData
_ReNetUnit_BattleData: chainsaw.ReNetUnit_BattleData
_ReNetUnit_BlueCoinData: chainsaw.ReNetUnit_BlueCoinData
_ReNetUnit_BonusMenuData: chainsaw.ReNetUnit_BonusMenuData
_ReNetUnit_BossClearData: chainsaw.ReNetUnit_BossClearData
_ReNetUnit_CraftData: chainsaw.ReNetUnit_CraftData
_ReNetUnit_DlcUse: chainsaw.ReNetUnit_DlcUse
_ReNetUnit_DollData: chainsaw.ReNetUnit_DollData
_ReNetUnit_EggData: chainsaw.ReNetUnit_EggData
_ReNetUnit_HookShotData: chainsaw.ReNetUnit_HookShotData
_ReNetUnit_MenData: chainsaw.ReNetUnit_MenData
_ReNetUnit_MercenariesGetItemsData: chainsaw.ReNetUnit_GetItemsData
_ReNetUnit_MercenariesInGame: chainsaw.ReNetUnit_MercenariesInGame
_ReNetUnit_ObjectDestroyData: chainsaw.ReNetUnit_ObjectDestroyData
_ReNetUnit_ParryData: chainsaw.ReNetUnit_ParryData
_ReNetUnit_PhotoModeData: chainsaw.ReNetUnit_PhotoModeData
_ReNetUnit_ReinforceData: chainsaw.ReNetUnit_ReinforceData
_ReNetUnit_SnakeData: chainsaw.ReNetUnit_SnakeData
_ReNetUnit_SpentTimeData: chainsaw.ReNetUnit_SpentTimeData
_ReNetUnit_TreasureData: chainsaw.ReNetUnit_TreasureData
_ReNetUnit_UseItemsData: chainsaw.ReNetUnit_UseItemsData
_ReNetUnit_WomenData: chainsaw.ReNetUnit_WomenData
_Record_FileCount: System.Int32
_Record_FileData: app.dev1lab.AnalysisLogEventParamMain_record.FileData[]
_Record_GameOverCount: System.Int32
_Record_GameOverList: app.dev1lab.AnalysisLogEventParamMain_record.GameoverData[]
_Record_MerchantCount: System.Int32
_Record_MerchantData: app.dev1lab.AnalysisLogEventParamMain_record.MerchantData[]
_Record_MissionCount: System.Int32
_Record_MissionData: app.dev1lab.AnalysisLogEventParamMain_record.MissionData[]
_RefAnalysisLogManager: app.dev1lab.AnalysisLogManager
_ValudugoResult: System.Int32
-- methods
:System.Void <onStart>b__60_0(app.dev1lab.AnalysisLogParam, System.String)
:System.Void addLogMerchantData(System.Int32, chainsaw.ItemID, chainsaw.TreasureCombineBonusType, System.Int32, System.Int32, System.Int32)
:System.Void addSteamOnlyOptions(System.Collections.Generic.List`1<System.Collections.Generic.KeyValuePair`2<System.String,System.String>>)
:System.Void clearRequestQueue()
:System.Void endTemporaryStop()
:app.dev1lab.AnalysisLogEventParamExtra_record.FileData getExtraRecordFileData(app.dev1lab.AnalysisLogEventParamMain_record.FileData)
:app.dev1lab.AnalysisLogEventParamExtra_record.GameoverData getExtraRecordGameoverData(app.dev1lab.AnalysisLogEventParamMain_record.GameoverData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MerchantData getExtraRecordMerchantData(app.dev1lab.AnalysisLogEventParamMain_record.MerchantData)
:app.dev1lab.AnalysisLogEventParamExtra_record.MissionData getExtraRecordMissionData(app.dev1lab.AnalysisLogEventParamMain_record.MissionData)
:System.Void getJsonElements(System.String, System.String[], System.String[])
:via.network.HttpClient get_HttpClient()
:System.Boolean get_IsTemporaryForbidSend()
:System.String get__CharacterKindIDStr()
:share.CampaignIdentifier get__CurrentCampaign()
:System.String get__CurrentGameId()
:System.String get__CurrentGameSlotId()
:System.Void notifyAshleyAttacked()
:System.Void notifyAshleyKidnapSaved()
:System.Void notifyAshleyMissShot()
:System.Void notifyBossTime(chainsaw.BossLapTime)
:System.Void notifyDLCItemBought(System.UInt32)
:System.Void notifyDamagedByAnimal(System.String)
:System.Void notifyEggUse(chainsaw.ReNetEggUseType, System.Int32)
:System.Void notifyEmDeadByGmIronBallCrane()
:System.Void notifyEmDeadByLuisAttack()
:System.Void notifyInGameToMainMenu()
:System.Void notifyItemCustomized(chainsaw.ItemID, chainsaw.gui.ItemCustomCategory, System.Int32)
:System.Void notifyLuisAttacked()
:System.Void notifyLuisMissShot()
:System.Void notifyMercenariesDestory()
:System.Void notifyMerchantData(System.Int32, chainsaw.ItemID, chainsaw.TreasureCombineBonusType, System.Int32, System.Int32, System.Int32)
:System.Void notifyMerchantData_Custom(chainsaw.ItemID, System.Int32)
:System.Void notifyMerchantData_Purchase(chainsaw.ItemID, System.Int32, System.Int32)
:System.Void notifyMerchantData_Sell(chainsaw.gui.NotifyMerchantData)
:System.Void notifyMerchantData_Trade(chainsaw.ItemID, System.Int32, System.Int32)
:System.Void notifyOpenOption()
:System.Void notifyParry(chainsaw.CharacterKindID, chainsaw.PlayerDefine.ParryInfoType, System.Int32)
:System.Void notifySnakeResult(System.Int32)
:System.Void notifySuccessHookshotShield()
:System.Void notifyTreasureData(chainsaw.ItemID, System.Int32)
:System.Void notifyUseHookshot(System.Single)
:System.Void notifyUseHookshotLandingKick()
:System.Void notifyUseHookshotMelee()
:System.Void notifyUseHookshotShield()
:System.Void notifyVerdugoResult(System.Int32)
:System.Void notifyWeaponAttackCause(chainsaw.WeaponID, System.Int32)
:System.Void notifyWeaponAttackSuccess(chainsaw.WeaponID, System.Int32)
:System.Void notifyWeaponChanged(chainsaw.WeaponID)
:System.Void onCauseGameOccurrence(chainsaw.GameOccurrenceCollectionType, chainsaw.GameOccurrenceType, chainsaw.IGameOccurrenceIdentifier, chainsaw.IGameOccurrenceIdentifier, System.Int32, System.Int32)
:System.Void onDestroy()
:System.Void onLateUpdate()
:System.Void onStart(app.dev1lab.AnalysisLogManager, via.network.HttpClient)
:System.String parseAUD()
:System.Void requestActive(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void requestAnalysis_accept(System.Boolean)
:System.Void requestAnalysis_accept_cid(System.Int32)
:System.Void requestBonus_mode_play(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamBonus_mode_play.BonusModes>)
:System.Void requestChange_difficulty(System.String, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamChange_difficulty.ProgressData>, System.Int64)
:System.Void requestDlc_install()
:System.Void requestDlc_use_time()
:System.Void requestExtra_contents_shop(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamExtra_contents_shop.PurchaseData>)
:System.Void requestExtra_proceed(share.AnalysisLogManagerAccessor.RequestFrom, chainsaw.ChapterStatsRecord, chainsaw.CampaignStatsRecord)
:System.Void requestExtra_record(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void requestGacha(System.Int32, chainsaw.ItemID, chainsaw.ItemID, chainsaw.ContextID)
:System.Void requestInitial_setting()
:System.Void requestMain_proceed(share.AnalysisLogManagerAccessor.RequestFrom, chainsaw.ChapterStatsRecord, chainsaw.CampaignStatsRecord)
:System.Void requestMain_record(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void requestMercenaries_end(chainsaw.MercenariesDefine.EndGameType, System.Int32, System.Int32, System.Int32, chainsaw.MercenariesDefine.ScoreRank, System.Int64)
:System.Void requestMercenaries_start(chainsaw.MercenariesDefine.StageKind, chainsaw.MercenariesDefine.PlayerCharacterKind, System.Int32)
:System.Void requestOption()
:System.Boolean requestOptionCid(System.Int32, chainsaw.NetworkErrorMediator.ReNetSituation)
:System.Boolean requestOptionReNet(System.Int32, chainsaw.NetworkErrorMediator.ReNetSituation)
:System.Void requestOther(System.Boolean, share.CampaignIdentifier)
:System.Void requestRecord(System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamRecord.RecordData>)
:System.Void requestShooting(System.Int64, System.String, System.String, System.Int64, System.Int64, System.String, System.Int64, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.RewardItemData>, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamShooting.BestData>)
:System.Void requestStart()
:System.Void requestStop()
:System.Void requestStore_transition()
:System.Void requestTransfer_save_data(via.UserIndex, System.String)
:System.Void requestTrophy(via.UserIndex, System.Collections.Generic.List`1<app.dev1lab.AnalysisLogEventParamTrophy.TrophyData>)
:System.Void set_HttpClient(via.network.HttpClient)
:System.Void set_IsTemporaryForbidSend(System.Boolean)
:System.Void startAshleyTogetherTime(chainsaw.Npc.PositioningType)
:System.Void startBonusSceneTime(System.Int32)
:System.Void startPhotoModeTime(chainsaw.StageID)
:System.Void startTemporaryStop()
:System.Void startup(System.Func`1<via.UserIndex>)
:System.Void startup(via.network.HttpClient, System.Func`1<via.UserIndex>)
:System.Void stopAshleyTogetherTime()
:System.Void stopBonusSceneTime()
:System.Void stopPhotoModeTime()
```

## `share.AnalysisLogManagerAccessor.CurrentFramePlayTime`

```lua
-- fields
CurrPlayTime: System.UInt64
DeltaTime: System.UInt64
LastPlayTime: System.UInt64
MeasuredFrame: System.UInt32
-- methods
:System.Void updatePlayTime(System.UInt64)
```

## `share.AnalysisLogManagerAccessor.RequestFrom`

```lua
-- values (System.Int32 enum)
OnBoot
OnChapterClear
OnGameClaer
OnIngameCleanup
OnMainMenu
OnManualSave
OnPeriodic
```

## `share.AnalysisLogManagerAccessorBehavior`

```lua
-- methods
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.AppGraphicsOptionControllerForPC`

```lua
-- methods
:System.Void onWindowModeChangeEvent(via.render.WindowModeChangeStatus)
:System.Void setAntiAliasingType(via.render.RenderConfig.AntiAliasingType)
:System.Void setFrameRate(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void setTextureFilterQuality(via.render.SamplerQuality)
```

## `share.AppGraphicsOptionControllerForPS5`

```lua
-- methods
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `share.AppGraphicsOptionControllerForXBS`

```lua
-- methods
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `share.AppGraphicsOptionManager`

```lua
-- fields
_conectableHDR: System.Boolean
_core: share.AppGraphicsOptionManagerCore
-- methods
:System.Void awake()
:System.Void finalize()
:share.AppGraphicsOptionManagerCore get_Core()
:System.Boolean get_IsAbleHDRMode()
:System.Void onUpdate()
:System.Void registerDefaultGrapihcsOption(share.AppGraphicsOptionUserData)
:System.Void setup()
:System.Void unregisterDefaultGraphicsOption()
:System.Void updateConectableHDR()
```

## `share.AppGraphicsOptionManagerBehavior`

```lua
-- fields
_SettingAsset: share.AppGraphicsOptionUserData
-- methods
:System.Void awake()
:share.AppGraphicsOptionUserData get_SettingAsset()
:System.Void onDestroy()
:System.Void set_SettingAsset(share.AppGraphicsOptionUserData)
:System.Void update()
```

## `share.AppGraphicsOptionManagerCore`

```lua
-- fields
INVALID_VALUE: System.Int32 [static]
_PlatformInitDataCache: System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>
-- methods
:System.Collections.Generic.List`1<app.dev1lab.GraphicsOption.ID> GetIDs()
:System.Void applyAntiAliasQuality(System.Int32)
:System.Void applyTextureFilterQuality(System.Int32)
:System.Void awake()
:System.Boolean checkValueAntiAliasQualitySetting(System.Int32)
:System.Boolean checkValueTextureFilterQualitySetting(System.Int32)
:app.dev1lab.CommonGraphicsOptionController createController()
:System.Boolean enableOption(app.dev1lab.GraphicsOption.ID)
:System.Void finalize()
:System.Void findDefaultResolutionAndRefreshrate(System.Int32, System.Int32)
:System.Int32 getCurrentValue(app.dev1lab.GraphicsOption.ID)
:System.Int32 getDefaultValue(app.dev1lab.GraphicsOption.ID)
:System.Int32 getPlatformInitValue(app.dev1lab.GraphicsOption.ID)
:app.dev1lab.CommonGraphicsOptionDisplayMode.DefaultResolutionMaxType getResolutionMaxType()
:System.Collections.Generic.IReadOnlyDictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem> get_PlatformInitDataCache()
:System.Void resetAllToPlatformDefaultValues(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>)
:System.Void resetDefaultByUser(app.dev1lab.GraphicsOption.ID)
:System.Void setAndApplyCurrentValue(app.dev1lab.GraphicsOption.ID, System.Int32)
:System.Void setDefaultValue(app.dev1lab.GraphicsOption.ID, System.Int32)
```

## `share.AppGraphicsOptionUserData`

```lua
-- fields
_XBoxSeriesSettingValue: share.AppGraphicsOptionUserData.XBosScarletSetting
_ps5SettingValue: share.AppGraphicsOptionUserData.PS5Setting
-- methods
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionUserData.PlatformSetting getPlatformSetting()
:share.AppGraphicsOptionUserData.PS5Setting get_PS5SettingValue()
:share.AppGraphicsOptionUserData.XBosScarletSetting get_XBoxSeriesSettingValue()
:System.Void set_PS5SettingValue(share.AppGraphicsOptionUserData.PS5Setting)
```

## `share.AppGraphicsOptionUserData.PS5Setting`

```lua
-- fields
_PS5DefaultAsset: share.AppGraphicsOptionDefaultValueUserData
-- methods
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:share.AppGraphicsOptionDefaultValueUserData get_PS5DefaultAsset()
:System.Void set_PS5DefaultAsset(share.AppGraphicsOptionDefaultValueUserData)
```

## `share.AppGraphicsOptionUserData.XBosScarletSetting`

```lua
-- fields
_XBoxSeriesSAsset: share.AppGraphicsOptionDefaultValueUserData
_XBoxSeriesXAsset: share.AppGraphicsOptionDefaultValueUserData
-- methods
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:share.AppGraphicsOptionDefaultValueUserData get_XBoxSeriesSAsset()
:share.AppGraphicsOptionDefaultValueUserData get_XBoxSeriesXAsset()
```

## `share.AppInterfaceBaseExtension`

```lua
-- static
:System.Boolean isValid(share.IAppInterfaceBase)
:System.Boolean isValid(share.IValidatable)
```

## `share.AppRegionRecognizer`

```lua
-- fields
Cero: share.CERO
-- methods
:System.Void captureRegionByPlatform()
:System.Boolean captureRegionByRuntimeArgument(System.String)
:System.Void decideCERO()
:share.TitleNameType getTitleNameType()
:share.ExtraRegionType get_AppExtraRegion()
:share.RegionType get_AppRegion()
:share.CERO get_cero()
:System.Boolean isLocaleUS(via.Language, via.Country)
:System.Boolean recognizeCEROByRuntimeArgument()
:System.Void set_AppExtraRegion(share.ExtraRegionType)
:System.Void set_AppRegion(share.RegionType)
:System.Void set_cero(share.CERO)
:System.Void setup()
```

## `share.AppRuntimeArgument`

```lua
-- fields
ArgCERO: System.String [static]
ArgDip: System.String [static]
ArgGraphicsOption: System.String [static]
ArgRegion: System.String [static]
ArgRevision: System.String [static]
ArgVer: System.String [static]
ArgWidget: System.String [static]
-- methods
:System.Void startUp()
:System.Void updateUnitList(System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>, app.dev1lab.CommonRuntimeArgument.Unit)
```

## `share.AppSaveFileDetail`

```lua
-- methods
:System.Boolean get_IsEmpty()
:via.storage.saveService.SaveFileDetail get_SaveFileDetail()
:System.Void set_IsEmpty(System.Boolean)
:System.Void set_SaveFileDetail(via.storage.saveService.SaveFileDetail)
```

## `share.AppSaveLoadFailedResult`

```lua
-- values (System.Int32 enum)
ExcludeGameSave
Invalid
None
RegionInvalid
UnCollectable
```

## `share.AppSaveSlot`

```lua
-- values (System.Int32 enum)
Campaign1001_Auto
Campaign1001_GameSaveEnd
Campaign1001_GameSaveLimit
Campaign1001_GameSaveStart
Campaign1001_SystemSave
Campaign1011_Auto
Campaign1011_GameSaveEnd
Campaign1011_GameSaveLimit
Campaign1011_GameSaveStart
Campaign1011_SystemSave
Campaign1021_Auto
Campaign1021_GameSaveEnd
Campaign1021_GameSaveLimit
Campaign1021_GameSaveStart
Campaign1021_SystemSave
Campaign1031_Auto
Campaign1031_GameSaveEnd
Campaign1031_GameSaveLimit
Campaign1031_GameSaveStart
Invalid
Share_SystemSave
Share_Transfer_Testing
SlotMax
SystemMaxOffset
```

## `share.AppSaveSlotUtil`

```lua
-- fields
AllCampaign1001GameSaveSlotNo: System.Int32[] [static]
AllCampaign1011GameSaveSlotNo: System.Int32[] [static]
AllCampaign1021GameSaveSlotNo: System.Int32[] [static]
AllCampaign1031GameSaveSlotNo: System.Int32[] [static]
AllSystemSaveSlotNo: System.Int32[] [static]
```

## `share.AppSendPacketInfo`

```lua
-- fields
memberIndex: System.Int32
option: via.network.protocol.SendOption
payload: share.AppPayloadBase
```

## `share.AppTracksBase`

```lua
-- methods
:System.Int32 get_LayerNo()
:System.Void initialize(System.Int32)
:System.Void set_LayerNo(System.Int32)
:System.Void setup(System.Int32)
```

## `share.ApplicationVersion`

```lua
-- fields
InvalidAssetVersion: System.String [static]
-- static
:System.String getAssetRevision()
:System.String getEngineRevision()
:System.UInt32 getSaveDataVersion()
:System.UInt32 getVersion()
:System.String getVersionString()
```

## `share.AverageTimeProfiler`

```lua
-- fields
DefaultTimeLogCount: System.Int32 [static]
_RecentWeight: System.Single
-- methods
:System.Void addData(System.Single)
:System.Void addDataWithProfile(System.Single)
:System.Single get_BygoneAvarageTime()
:System.Boolean get_IsNeedUpdateBygoneTimeLog()
:System.Single get_ProfiledAvarageTime()
:System.Single get_RecentAvarageTime()
:System.Single get_RecentWeight()
:System.Single[] get_TimeLog()
:System.Int32 get_TimeLogIndicator()
:System.Single[] makeInitializedLog(System.Int32)
:System.Void profile()
:System.Void reset()
:System.Void set_BygoneAvarageTime(System.Single)
:System.Void set_IsNeedUpdateBygoneTimeLog(System.Boolean)
:System.Void set_ProfiledAvarageTime(System.Single)
:System.Void set_RecentAvarageTime(System.Single)
:System.Void set_RecentWeight(System.Single)
:System.Void set_TimeLog(System.Single[])
:System.Void set_TimeLogIndicator(System.Int32)
```

## `share.BehaviorTreeActionTiming`

```lua
-- values (System.Int32 enum)
End
Start
Update
```

## `share.Bool`

```lua
-- values (System.Int32 enum)
False
True
```

## `share.BootController`

```lua
-- fields
_BootSettingsUserData: share.BootSettingsUserData
-- methods
:share.BootSettingsUserData get_BootSettingsUserData()
:System.Void onDestroy()
:System.Void set_BootSettingsUserData(share.BootSettingsUserData)
:System.Void start()
:System.Void update()
```

## `share.BootSystem`

```lua
-- fields
APPLICATION_VERSION_LAUNCH: System.UInt32 [static]
APPLICATION_VERSION_TU1: System.UInt32 [static]
APPLICATION_VERSION_TU1_2: System.UInt32 [static]
APPLICATION_VERSION_TU2: System.UInt32 [static]
APPLICATION_VERSION_TU3: System.UInt32 [static]
NOTIFIER_COUNT: System.Int32 [static]
CURREENT_APPLICATION_VERSION: System.UInt32
CallbackOnCompletedActivatingAppResident: System.Action
CoreSystemSetupFinishNotifierList: System.Collections.Generic.List`1<System.Object>
CoreSystemShutdownFinishNotifierList: System.Collections.Generic.List`1<System.Object>
RefGameCoreFolder: share.SceneFolderController
RequestedReset: System.Boolean
_OriginalGlobalCollectionBaseStep: System.UInt32
_RequestedGC: System.Boolean
-- methods
:System.Void add_CallbackOnCompletedActivatingAppResident(System.Action)
:System.Void changePhase(share.BootSystem.Phase)
:System.Action createCoreSystemSetupFinishNotifier(System.Object)
:System.Action createCoreSystemShutdownFinishNotifier(System.Object)
:System.Void execFullGC()
:System.Void exit()
:System.UInt32 get_APPLICATION_VERSION()
:share.BootSettingsUserData get_BootSettingsUserData()
:share.BootType get_CurrentBootType()
:share.BootSystem.Phase get_CurrentPhase()
:System.Collections.Generic.List`1<share.SceneFolderController> get_FolderControllerList()
:System.Boolean get_IsCompletedBoot()
:System.Boolean get_NeedToApplicationUpdate()
:System.Void init(share.BootSettingsUserData, via.GameObject)
:System.Void notifyNeedToApplicationUpdate()
:System.Void onBoot()
:System.Void onCompletedActivatingAppResident()
:System.Void remove_CallbackOnCompletedActivatingAppResident(System.Action)
:System.Void requestFullGC()
:System.Void requestReset()
:System.Void resetGlobalCollectionBaseStep()
:System.Void setGlobalCollectionBaseStep(System.UInt32)
:System.Void set_BootSettingsUserData(share.BootSettingsUserData)
:System.Void set_CurrentBootType(share.BootType)
:System.Void set_CurrentPhase(share.BootSystem.Phase)
:System.Void set_FolderControllerList(System.Collections.Generic.List`1<share.SceneFolderController>)
:System.Void set_NeedToApplicationUpdate(System.Boolean)
:System.Void update()
```

## `share.BootSystem.Phase`

```lua
-- values (System.Int32 enum)
Boot
Completed
CoreSystemSetupRequest
CoreSystemSetupWait
CoreSystemShutdownWait
Deactivated
Invalid
ReadyForBoot
ReadyForDeactiveFolders
ReadyForDeactiveGameCore
ReadyForGameCoreActive
Reset
```

## `share.BootType`

```lua
-- values (System.Int32 enum)
Develop
Invalid
Master
```

## `share.CERO`

```lua
-- values (System.Int32 enum)
D
None
Z
```

## `share.CampaignCollector`

```lua
-- fields
RegistedCampaignList: System.Collections.Generic.List`1<share.CampaignIdentifier>
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.CampaignController`

```lua
-- fields
FolderController: share.SceneFolderController
RequestedActivate: System.Boolean
RequestedDeactivate: System.Boolean
_RefCatalogController: share.CatalogCollector
-- methods
:share.CampaignIdentifier get_CampaignID()
:share.CampaignController.Phase get_CurrentPhase()
:System.Boolean isActivated()
:System.Boolean isDeactivated()
:System.Void requestActivate()
:System.Void requestDeactivate()
:System.Void set_CampaignID(share.CampaignIdentifier)
:System.Void set_CurrentPhase(share.CampaignController.Phase)
:System.Void transit(share.CampaignController.Phase)
:System.Void update()
```

## `share.CampaignController.Phase`

```lua
-- values (System.Int32 enum)
Active
CloseFolderWait
CloseWaitCatalog
OpenFolderWait
OpenWaitCatalog
Sleep
```

## `share.CampaignIdentifier`

```lua
-- values (System.Int32 enum)
Campaign1001
Campaign1011
Campaign1021
Campaign2001
Invalid
```

## `share.CatalogCollector`

```lua
-- fields
_2ndChunkFolderName: System.String
_ChunkFolderInfoList: share.CatalogCollector.ChunkFolderInfo[]
_ControllerList: share.CatalogFolderController[]
_Has2ndChunkChecker: System.Boolean
-- methods
:System.Boolean isLoadedOrWaitingExist()
:System.Boolean isReady2ndChunk()
:System.Boolean isUnloaded()
:System.Void onDestroy()
:System.Void requestUnload()
:System.Void start()
:System.Void update()
```

## `share.CatalogCollector.ChunkFolderInfo`

```lua
-- fields
Chunk: System.Int32
FolderName: System.String
```

## `share.CatalogFolderController`

```lua
-- fields
Controller: share.SceneFolderController
Folder: via.Folder
-- methods
:System.Int32 get_ChunkID()
:share.CatalogFolderController.Phase get_CurrentPhase()
:System.String get_FolderName()
:share.CatalogFolderController.Phase get_TargetPhase()
:System.Void loaded()
:System.Void requestUnload()
:System.Void set_ChunkID(System.Int32)
:System.Void set_CurrentPhase(share.CatalogFolderController.Phase)
:System.Void set_TargetPhase(share.CatalogFolderController.Phase)
:System.Void unloaded()
:System.Void update()
```

## `share.CatalogFolderController.Phase`

```lua
-- values (System.Int32 enum)
Initial
KickLoad
Loaded
Unloaded
Unloading
WaitExist
WaitLoad
```

## `share.CatalogManager`

```lua
-- fields
CatalogCollectorList: System.Collections.Generic.List`1<share.CatalogCollector>
-- methods
:System.Int32 getRegistedCatalogNum()
:System.Boolean hasAllChunk()
:System.Boolean isLoadedOrWaitingExistAll()
:System.Boolean isUnloadedAll()
:System.Void onDestroy()
:System.Void registCatalogController(share.CatalogCollector)
:System.Void requestUnloadAll()
:System.Void unregistCatalogController(share.CatalogCollector)
```

## `share.CatalogManagerBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.CatalogRegisterBase`

```lua
-- methods
:System.Boolean get_IsRegisteredCatalog()
:System.Void onUnload()
:System.Void set_IsRegisteredCatalog(System.Boolean)
:System.Void update()
```

## `share.CollectType`

```lua
-- values (System.Int32 enum)
Any
Include
Match
```

## `share.CompareType`

```lua
-- values (System.Int32 enum)
Equal
Greater
GreaterEq
Less
LessEq
NotEqual
```

## `share.ComponentEnableController`

```lua
-- fields
HashBehavior: System.UInt32 [static]
_OnChangeCallbacks: System.Collections.Generic.Dictionary`2<System.UInt32,share.ComponentEnableController.Callback>
_StopLayers: System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>
-- methods
:System.Void appendOnChange(via.Component, System.Action`1<System.Boolean>)
:System.Boolean applyEnabled(via.Component, System.Boolean)
:System.Void dependOnChange(via.Component, System.Action`1<System.Boolean>)
:System.Void fireEvent(System.UInt32, System.Boolean)
:System.Boolean getEnabled(via.Component)
:System.Void onDestroy()
:System.Void setEnabledInLock(via.Component, System.Boolean, System.UInt32)
:System.Void setEnabledNoLock(via.Component, System.Boolean, System.UInt32)
-- static
:share.ComponentEnableController readyController(via.Component)
:System.Boolean setEnabled(via.Component, System.Boolean, System.UInt32, System.Boolean)
```

## `share.ComponentEnableController.Callback`

```lua
-- fields
OnChange: System.Action`1<System.Boolean>
-- methods
:System.Void add_OnChange(System.Action`1<System.Boolean>)
:System.Void appendEvent(System.Action`1<System.Boolean>)
:System.Void clear()
:System.Void dependEvent(System.Action`1<System.Boolean>)
:System.Void invoke(System.Boolean)
:System.Void remove_OnChange(System.Action`1<System.Boolean>)
```

## `share.ComponentEnableMediator`

```lua
-- methods
:System.Void apply(via.Component, System.Boolean, System.UInt32, share.ComponentEnableMediator.ArgsParam)
:System.Void clearRequest()
:share.ComponentEnableMediator.RequestParam[] confirmRequest()
:share.ComponentEnableMediator.RequestParam[] confirmRequestUnderLock()
:System.Void execRequest(System.Boolean)
:System.Void finish()
:System.Collections.Generic.List`1<share.ComponentEnableMediator.RequestParam> get__Requested()
:System.Void init()
:System.Void request(via.Component, System.Boolean, System.UInt32, share.ComponentEnableMediator.ArgsParam)
:System.Void set__Requested(System.Collections.Generic.List`1<share.ComponentEnableMediator.RequestParam>)
:System.Void updateOnFrameHead()
-- static
:share.ComponentEnableMediator.ArgsParam get_DEFAULT()
```

## `share.ComponentEnableMediator.ArgsParam`

```lua
-- fields
AppliedEvent: System.Action`1<System.Boolean>
-- methods
:System.Void add_AppliedEvent(System.Action`1<System.Boolean>)
:share.ComponentEnableMediator.SetPhase get_Phase()
:System.Void onApplied(System.Boolean)
:System.Void remove_AppliedEvent(System.Action`1<System.Boolean>)
:System.Void set_Phase(share.ComponentEnableMediator.SetPhase)
```

## `share.ComponentEnableMediator.RequestParam`

```lua
-- methods
:share.ComponentEnableMediator.ArgsParam get_Args()
:System.Boolean get_Enabled()
:System.UInt32 get_Layer()
:via.Component get_Target()
:System.Void set_Args(share.ComponentEnableMediator.ArgsParam)
:System.Void set_Enabled(System.Boolean)
:System.Void set_Layer(System.UInt32)
:System.Void set_Target(via.Component)
```

## `share.ComponentEnableMediator.SetPhase`

```lua
-- values (System.Int32 enum)
FrameHead
Immediate
```

## `share.ComponentEnableMediatorBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.ContentsHash`

```lua
-- fields
DLC_0001: System.UInt32 [static]
DLC_0002: System.UInt32 [static]
DLC_0004: System.UInt32 [static]
DLC_1001: System.UInt32 [static]
DLC_1002: System.UInt32 [static]
DLC_1003: System.UInt32 [static]
DLC_1004: System.UInt32 [static]
DLC_1005: System.UInt32 [static]
DLC_1006: System.UInt32 [static]
DLC_1101: System.UInt32 [static]
DLC_1102: System.UInt32 [static]
DLC_1201: System.UInt32 [static]
DLC_1202: System.UInt32 [static]
DLC_1301: System.UInt32 [static]
DLC_1401: System.UInt32 [static]
DLC_1402: System.UInt32 [static]
DLC_2001: System.UInt32 [static]
DLC_3001: System.UInt32 [static]
DLC_3101: System.UInt32 [static]
DLC_4001: System.UInt32 [static]
DLC_4002: System.UInt32 [static]
DLC_4003: System.UInt32 [static]
DLC_4004: System.UInt32 [static]
DLC_4005: System.UInt32 [static]
DLC_4006: System.UInt32 [static]
DLC_4007: System.UInt32 [static]
DLC_4008: System.UInt32 [static]
DLC_4009: System.UInt32 [static]
DLC_4010: System.UInt32 [static]
DLC_4011: System.UInt32 [static]
DLC_4012: System.UInt32 [static]
DLC_4013: System.UInt32 [static]
DLC_4014: System.UInt32 [static]
DLC_4015: System.UInt32 [static]
DLC_4016: System.UInt32 [static]
DLC_4017: System.UInt32 [static]
DLC_4018: System.UInt32 [static]
DLC_4019: System.UInt32 [static]
DLC_4020: System.UInt32 [static]
DLC_4021: System.UInt32 [static]
DLC_4022: System.UInt32 [static]
DLC_4023: System.UInt32 [static]
DLC_4024: System.UInt32 [static]
DLC_4025: System.UInt32 [static]
DLC_4026: System.UInt32 [static]
DLC_4027: System.UInt32 [static]
DLC_4028: System.UInt32 [static]
DLC_4029: System.UInt32 [static]
DLC_4030: System.UInt32 [static]
DLC_9001: System.UInt32 [static]
```

## `share.ContentsManager`

```lua
-- fields
CampaignCollection: System.Collections.Generic.Dictionary`2<share.CampaignIdentifier,share.CampaignController>
CurrentPhase: share.ContentsManager.Phase
GameCollection: System.Collections.Generic.Dictionary`2<share.GameIdentifier,share.GameController>
RefMainContents: share.SceneFolderController
_CurrentCampaign: share.CampaignController
_CurrentCampaignIdentifer: share.CampaignIdentifier
_CurrentGame: share.GameController
_CurrentGameIdentifier: share.GameIdentifier
_DoNothing: System.Action
_OnFinishActivateCampaign: System.Action
_OnFinishActivateGame: System.Action
_OnFinishActivateLaunchContents: System.Action
_OnFinishDeactivateCampaign: System.Action
_OnFinishDeactivateGame: System.Action
_OnFinishDeactivateLaunchContents: System.Action
-- methods
:share.CampaignIdentifier[] getRegistedCampaignList()
:share.GameIdentifier[] getRegistedGameList()
:System.Boolean get_CampaignLoaded()
:share.CampaignIdentifier get_CurrentCampaignID()
:share.GameIdentifier get_CurrentGameID()
:System.Boolean get_GameLoaded()
:System.Void init()
:System.Boolean isAvailableCampaign(share.CampaignIdentifier)
:System.Void registCampaign(share.CampaignIdentifier, via.Folder)
:System.Void registGame(share.GameIdentifier, via.Folder)
:System.Void requestToCloseLaunchContents(System.Action)
:System.Void requestToEndCampaign(System.Action)
:System.Void requestToEndGame(System.Action)
:System.Void requestToOpenLaunchContents(System.Action)
:System.Void requestToStartCampaign(share.CampaignIdentifier, System.Action)
:System.Void requestToStartGame(share.GameIdentifier, System.Action)
:System.Void transit(share.ContentsManager.Phase)
:System.Void unregistCampaign(share.CampaignIdentifier)
:System.Void unregistGame(share.GameIdentifier)
:System.Void update()
:System.Void updateControllers()
:System.Void updateProcess()
```

## `share.ContentsManager.Phase`

```lua
-- values (System.Int32 enum)
ActivateLaunchContents
Active
DeactivateLaunchContents
EndCampaignWait
EndGameWait
EndSequenceKick
Sleep
Stable
StartCampaignWait
StartComplete
StartGameWait
```

## `share.ContentsManagerBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.CpuQualityPerformanceBalancer`

```lua
-- fields
Balancer: share.QualityPerformanceBalancer
-- methods
:System.Void addController(share.QualityPerformanceControllable, System.Int32, System.String)
:System.Void init(System.Single, System.Single, System.Int32)
:System.Void qualityUp()
:System.Void removeController(share.QualityPerformanceControllable)
:System.Void requestPauseControl(share.QualityPerformanceBalancer.PauseReason, System.Boolean)
:System.Void requestResumeControl(share.QualityPerformanceBalancer.PauseReason)
:System.Void requestToEndQualityControl()
:System.Void requestToStartQualityControl()
:System.Void speedUp()
:System.Void term()
```

## `share.ExpressionDefine`

```lua
-- fields
CompareTypeNames: System.String[] [static]
SimpleCompareTypeNames: System.String[] [static]
-- static
:System.Boolean compare(System.Single, share.CompareType, System.Single)
:System.Boolean compare(System.Int32, share.CompareType, System.Int32)
:System.Boolean compare(System.UInt64, share.CompareType, System.UInt64)
:System.String makeExpressionLabel(System.String, share.SimpleCompareType, System.String)
:System.String makeExpressionLabel(System.String, share.CompareType, System.String)
```

## `share.ExtraContentsController`

```lua
-- fields
ActivateFolders: System.Collections.Generic.List`1<via.Folder>
HolderFolders: System.Collections.Generic.List`1<share.ExtraContentsController.Context>
-- methods
:System.Boolean checkActivated()
:System.Void collectFolder()
:System.Void onDestroy()
:System.Boolean requestActivate()
:System.Boolean requestDeactivate()
:System.Void start()
:System.Void update()
```

## `share.ExtraContentsController.Context`

```lua
-- fields
Holder: via.Folder
Installed: System.Boolean
```

## `share.ExtraContentsManager`

```lua
-- fields
WaitTimerSec: System.Single [static]
ExtraContentsList: System.Collections.Generic.List`1<System.UInt32>
ExtraContentsListMutex: via.threading.SimpleReaderWriterLock
ExtraContentsProcess: share.ExtraContentsManager.ExtraContentsProcessType
OnCheckEndEvent: System.Action
OnDeactivateEndEvent: System.Action
OnPrepareCheckEndEvent: System.Action
RefDLC: via.storage.DLC
RefExtraContentsController: share.ExtraContentsController
SteamContentTable: System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt64>
WaitTimer: System.Single
-- methods
:System.Boolean checkDLCSystemAvaliable()
:System.Void exit()
:System.Collections.Generic.List`1<System.UInt32> get_GetExtraContentsList()
:System.Boolean get_NeedInstallFinishAnnounce()
:System.Boolean hasContents(System.UInt32)
:System.Void init()
:System.Void markAsReadInstallFinishAnnounce()
:System.Void notifyToNeedInstallFinishAnnounce()
:System.Void registerController(share.ExtraContentsController)
:System.Void registerExtraContents(System.UInt32)
:System.Boolean requestCheckExtraContents(System.Action)
:System.Boolean requestDeactivateExtraContents(System.Action)
:System.Void requestPrepareCheckExtraContents(System.Action)
:System.Void set_NeedInstallFinishAnnounce(System.Boolean)
:System.Void unregisterController(share.ExtraContentsController)
:System.Void unregisterExtraContents(System.UInt32)
:System.Void update()
```

## `share.ExtraContentsManager.ExtraContentsProcessType`

```lua
-- values (System.Int32 enum)
Check
Deactivate
None
PrepareCheck
WaitDeactivate
WaitMounted
```

## `share.ExtraContentsRegister`

```lua
-- fields
_ContentsHash: chainsaw.NameHash
-- methods
:System.Void awake()
:System.Void onDestroy()
```

## `share.ExtraRegionType`

```lua
-- values (System.Int32 enum)
German
Unknown
```

## `share.FadeController`

```lua
-- fields
FadeColors: share.FadeController.FadeColor[] [static]
_DefaultTimeSecond: System.Single
_FadeColor: share.FadeController.FadeColor
_FadeType: share.FadeManager.FadeType
_OnComplete: System.Action
_Phase: share.FadeController.Phase
_RefCounter: share.SyncRefCounter`1<System.Int32>
_SegmentOrder: System.UInt32
_TargetInfos: share.FadeController.FadeTargetInfo[]
-- methods
:System.Void awake()
:System.Void fadeIn(System.Single, System.Action)
:System.Void fadeOut(share.FadeController.FadeColor, System.Single, System.Action)
:share.FadeController.FadeTargetInfo findTargetInfo(share.FadeController.FadeColor, System.String)
:share.FadeController.Phase get_CurrPhase()
:share.FadeManager.FadeType get_FadeType()
:System.Boolean get_IsBusy()
:System.Boolean get_IsCompletedFadeIn()
:System.Boolean get_IsCompletedFadeOut()
:System.Boolean get_IsFadeIn()
:System.Boolean get_IsFadeOut()
:System.Void onDestroy()
:System.Void requestEnd(via.gui.FadeMode, System.UInt32)
:System.Void transitPhase(share.FadeController.Phase)
```

## `share.FadeController.FadeColor`

```lua
-- values (System.Int32 enum)
Black
Invalid
White
```

## `share.FadeController.FadeTargetInfo`

```lua
-- fields
_FadeColor: share.FadeController.FadeColor
_IsSetupped: System.Boolean
_Target: via.GameObjectRef
-- methods
:share.FadeController.FadeColor get_FadeColor()
:via.gui.SystemImageSlide get_ImageSlide()
:System.Boolean get_IsValid()
:via.GameObjectRef get_Target()
:System.Void set_ImageSlide(via.gui.SystemImageSlide)
:System.Void setup(via.GameObject, System.UInt32)
```

## `share.FadeController.Phase`

```lua
-- values (System.Int32 enum)
FadeIn_Idle
FadeIn_Wait
FadeOut_Idle
FadeOut_Wait
Invalid
```

## `share.FadeManager`

```lua
-- fields
FadeTypes: share.FadeManager.FadeType[] [static]
_FadeControllers: share.FadeController[]
-- methods
:share.FadeController findController(share.FadeManager.FadeType, System.String)
:System.Boolean isAnyFadeIn()
:System.Boolean isAnyFadeOut()
:System.Boolean isCompletedFadeIn(share.FadeManager.FadeType)
:System.Boolean isCompletedFadeInAll()
:System.Boolean isCompletedFadeOut(share.FadeManager.FadeType)
:System.Boolean isCompletedFadeOutAll()
:System.Boolean isFadeBusy(share.FadeManager.FadeType)
:System.Boolean isFadeIn(share.FadeManager.FadeType)
:System.Boolean isFadeOut(share.FadeManager.FadeType)
:System.Boolean isValid(share.FadeManager.FadeType)
:System.Void registerFadeContrller(share.FadeController)
:System.Void requestFadeIn(share.FadeManager.FadeType, System.Single, System.String, System.Action)
:System.Void requestFadeOutBlack(share.FadeManager.FadeType, System.Single, System.String, System.Action)
:System.Void requestFadeOutWhite(share.FadeManager.FadeType, System.Single, System.String, System.Action)
:System.Void unregisterFadeController(share.FadeManager.FadeType)
```

## `share.FadeManager.FadeType`

```lua
-- values (System.Int32 enum)
CAMPAIGN_JUMPER
CAMPAIGN_MANAGER
EVENT
GAMESTATE
GIMMICK
GUI
INTER_GAMESTATE
INVALID
TEXT_CHANGE
```

## `share.FadeManagerBehavior`

```lua
-- methods
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.FolderKind`

```lua
-- values (System.Int32 enum)
Body
Head
Nobody
```

## `share.FolderService`

```lua
-- methods
:via.Folder getFolder(share.FolderKind)
:System.Collections.Generic.Dictionary`2<share.FolderKind,via.Folder> get_Folders()
:via.Folder get_InstanceFolderRoot()
:System.Void onDestroy()
:System.Void onStart(via.GameObject)
:System.Void set_Folders(System.Collections.Generic.Dictionary`2<share.FolderKind,via.Folder>)
:System.Void set_InstanceFolderRoot(via.Folder)
```

## `share.FolderServiceBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.FolderServiceDefinition`

```lua
-- fields
FolderKindMax: System.Int32 [static]
FolderKinds: System.Collections.ObjectModel.ReadOnlyCollection`1<share.FolderKind> [static]
_FolderKindsRaw: share.FolderKind[] [static]
```

## `share.GameClock`

```lua
-- fields
_GameSaveData: share.GameClock.GameSaveData
_GameSaveData_Reset: share.GameClock.GameSaveData
_MeasureDemoSpendingTime: System.Boolean
_MeasureGameElapsedTime: System.Boolean
_MeasureInventorySpendingTime: System.Boolean
_MeasurePauseSpendingTime: System.Boolean
_SystemSaveData: share.GameClock.SystemSaveData
-- methods
:System.Void clear()
:System.Void clearSystemSaveData()
:share.SaveDataBase convertGameSaveData(share.SaveDataBase)
:share.SaveDataBase convertSystemSaveData(share.SaveDataBase)
:System.Void endMeasureDemoSpendingTime()
:System.Void endMeasureGameElapsedTime()
:System.Void endMeasureInventorySpendingTime()
:System.Void endMeasurePauseSpendingTime()
:System.Void exit()
:System.UInt64 getElapsedTime(share.GameClock.Kind)
:System.UInt64 get_ActualPlayingTime()
:System.UInt64 get_ActualPlayingTime_Reset()
:System.UInt64 get_ActualRecordTime()
:System.UInt64 get_ActualRecordTime_Reset()
:System.UInt64 get_DemoSpendingTime()
:System.UInt64 get_DemoSpendingTime_Reset()
:System.UInt64 get_GameElapsedTime()
:System.UInt64 get_GameElapsedTime_Reset()
:System.UInt32 get_GameSaveDataHash()
:System.UInt32 get_GameSaveDataVersion()
:System.UInt64 get_InSceneTime()
:System.UInt64 get_InSceneTime_Reset()
:System.UInt64 get_InventorySpendingTime()
:System.UInt64 get_InventorySpendingTime_Reset()
:System.Boolean get_IsNotClearGameElapsedTime()
:System.UInt64 get_PauseSpendingTime()
:System.UInt64 get_PauseSpendingTime_Reset()
:System.UInt64 get_SystemElapsedTime()
:System.UInt32 get_SystemSaveDataHash()
:System.UInt32 get_SystemSaveDataVersion()
:System.UInt64 get__DemoSpendingTime()
:System.UInt64 get__DemoSpendingTime_Reset()
:System.UInt64 get__GameElapsedTime()
:System.UInt64 get__GameElapsedTime_Reset()
:System.UInt64 get__InventorySpendingTime()
:System.UInt64 get__InventorySpendingTime_Reset()
:System.UInt64 get__PauseSpendingTime()
:System.UInt64 get__PauseSpendingTime_Reset()
:System.UInt64 get__SystemElapsedTime()
:System.Void init()
:System.Void loadGameSaveData(share.SaveDataBase)
:System.Void loadSystemSaveData(share.SaveDataBase)
:System.Void registerGameSaveData()
:System.Void registerSystemSaveData()
:share.SaveDataBase saveGameSaveData()
:share.SaveDataBase saveSystemSaveData()
:System.Void set__DemoSpendingTime(System.UInt64)
:System.Void set__DemoSpendingTime_Reset(System.UInt64)
:System.Void set__GameElapsedTime(System.UInt64)
:System.Void set__GameElapsedTime_Reset(System.UInt64)
:System.Void set__InventorySpendingTime(System.UInt64)
:System.Void set__InventorySpendingTime_Reset(System.UInt64)
:System.Void set__PauseSpendingTime(System.UInt64)
:System.Void set__PauseSpendingTime_Reset(System.UInt64)
:System.Void set__SystemElapsedTime(System.UInt64)
:System.Void startMeasureDemoSpendingTime()
:System.Void startMeasureGameElapsedTime()
:System.Void startMeasureInventorySpendingTime()
:System.Void startMeasurePauseSpendingTime()
:System.Void update(System.Single)
-- static
:System.Void calcDateFromUlongTime(System.UInt64, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.UInt64 calcUlongTimeFromDate(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
:System.String convertReadableTime(System.UInt64)
```

## `share.GameClock.GameSaveData`

```lua
-- fields
_DemoSpendingTime: System.UInt64
_GameElapsedTime: System.UInt64
_InventorySpendingTime: System.UInt64
_PauseSpendingTime: System.UInt64
-- methods
:System.Void copyFrom(share.GameClock.GameSaveData)
```

## `share.GameClock.Kind`

```lua
-- values (System.Int32 enum)
ActualPlaying
ActualRecord
DemoSpending
Game
InventorySpending
PauseSpending
System
```

## `share.GameClock.SystemSaveData`

```lua
-- fields
_SystemElapsedTime: System.UInt64
-- methods
:System.Void copyFrom(share.GameClock.SystemSaveData)
```

## `share.GameClockBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.GameCollector`

```lua
-- fields
RegistedGameList: System.Collections.Generic.List`1<share.GameIdentifier>
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.GameController`

```lua
-- fields
FolderController: share.SceneFolderController
GameCoreFolderController: share.SceneFolderController
RequestedActivate: System.Boolean
RequestedDeactivate: System.Boolean
SubFolderControllerList: System.Collections.Generic.List`1<share.SceneFolderController>
_RefCatalogController: share.CatalogCollector
-- methods
:share.GameController.Phase get_CurrentPhase()
:share.GameIdentifier get_GameID()
:System.Boolean isActivated()
:System.Boolean isDeactivated()
:System.Void requestActivate()
:System.Void requestDeactivate()
:System.Void set_CurrentPhase(share.GameController.Phase)
:System.Void set_GameID(share.GameIdentifier)
:System.Void transit(share.GameController.Phase)
:System.Void update()
```

## `share.GameController.Phase`

```lua
-- values (System.Int32 enum)
Active
CloseCoreWait
CloseGameWait
CloseSubFoldersWait
CloseWaitCatalog
OpenCoreWait
OpenGame
OpenGameWait
OpenSubFoldersWait
OpenWaitCatalog
Sleep
```

## `share.GameIdentifier`

```lua
-- values (System.Int32 enum)
Game10
Game20
Invalid
```

## `share.GameLoadCompletedEventArgs`

```lua
-- methods
:share.SaveLoadProcessResult get_Result()
:System.Int32 get_SlotId()
:System.Void set_Result(share.SaveLoadProcessResult)
:System.Void set_SlotId(System.Int32)
```

## `share.GameLoadRequestArgs`

```lua
-- methods
:share.SaveLoadRequestArgs getCopy()
```

## `share.GameModeType`

```lua
-- values (System.Int32 enum)
Invalid
OfflineCoop
OfflineSolo
OnlineCoop
```

## `share.GameObjectExtension`

```lua
-- static
:System.Void addTag(via.GameObject, share.Tag.List)
:System.Int32 convTagBits(System.String)
:System.Int32 convTagBits(share.Tag.List)
:System.Int32 convTagBits(share.Tag.List[])
:via.GameObject findChild(via.GameObject, System.String)
:via.GameObject getGameObjectInChildren(via.GameObject, System.String)
:via.GameObject getParentObject(via.GameObject)
:System.Int32 getTagBits(via.GameObject)
:via.Component readyComponent(via.GameObject, System.Type)
:via.Component readyComponent(via.GameObject, System.Type, System.Boolean)
:System.Void removeTag(via.GameObject, share.Tag.List)
:System.Boolean testAndTag(via.GameObject, System.String)
:System.Boolean testAndTag(via.GameObject, share.Tag.List)
:System.Boolean testAndTag(via.GameObject, share.Tag.List[])
:System.Boolean testAnyTag(via.GameObject, System.String)
:System.Boolean testAnyTag(via.GameObject, share.Tag.List)
:System.Boolean testAnyTag(via.GameObject, share.Tag.List[])
:System.Boolean testMatchTag(via.GameObject, System.String)
:System.Boolean testMatchTag(via.GameObject, share.Tag.List)
:System.Boolean testMatchTag(via.GameObject, share.Tag.List[])
:System.Boolean testTag(via.GameObject, share.CollectType, System.String)
:System.Boolean testTag(via.GameObject, share.CollectType, share.Tag.List)
:System.Boolean testTag(via.GameObject, share.CollectType, share.Tag.List[])
```

## `share.GameObjectJointSetArgs`

```lua
-- fields
AppliedEvent: System.Action`1<share.GameObjectStateSetResult>
-- methods
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectParentSetArgs`

```lua
-- fields
AppliedEvent: System.Action`1<share.GameObjectStateSetResult>
-- methods
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectStateController`

```lua
-- fields
Group_StopControl: System.Boolean [static]
OnSetDrawEvent: System.Action`1<System.Boolean>
OnSetParentEvent: System.Action`1<via.GameObject>
OnSetUpdateEvent: System.Action`1<System.Boolean>
-- methods
:System.Void add_OnSetDrawEvent(System.Action`1<System.Boolean>)
:System.Void add_OnSetParentEvent(System.Action`1<via.GameObject>)
:System.Void add_OnSetUpdateEvent(System.Action`1<System.Boolean>)
:System.Void applyParent(via.GameObject)
:System.Void applyParentJoint(System.UInt32)
:System.Void applySameJointsConstraint(System.Boolean)
:System.Void applyStateSet(share.ValidatedBool, share.ValidatedBool, System.UInt32)
:System.Void awake()
:System.UInt32 get_StopDrawLayerBits()
:System.UInt32 get_StopDrawLayers()
:System.UInt32 get_StopUpdateLayerBits()
:System.UInt32 get_StopUpdateLayers()
:System.Void remove_OnSetDrawEvent(System.Action`1<System.Boolean>)
:System.Void remove_OnSetParentEvent(System.Action`1<via.GameObject>)
:System.Void remove_OnSetUpdateEvent(System.Action`1<System.Boolean>)
:System.Void set_StopDrawLayers(System.UInt32)
:System.Void set_StopUpdateLayers(System.UInt32)
-- static
:System.Boolean applyParent(via.GameObject, via.GameObject)
:System.Boolean applyParentJoint(via.GameObject, System.UInt32)
:System.Boolean applySameJointsConstraint(via.GameObject, System.Boolean)
:System.Boolean applyStateSet(via.GameObject, share.ValidatedBool, share.ValidatedBool, System.UInt32)
:share.GameObjectStateController readyStateController(via.GameObject)
```

## `share.GameObjectStateSetArgs`

```lua
-- fields
AppliedEvent: System.Action`1<share.GameObjectStateSetResult>
-- methods
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectStateSetMediator`

```lua
-- fields
PSR_DEFAULT_CAPACITY: System.Int32 [static]
SSR_DEFAULT_CAPACITY: System.Int32 [static]
-- methods
:System.Void execParentJointSet(via.GameObject, System.UInt32, share.GameObjectJointSetArgs)
:System.Void execParentSet(via.GameObject, via.GameObject, share.GameObjectParentSetArgs)
:System.Void execSameJointsConstraint(via.GameObject, System.Boolean, share.GameObjectJointSetArgs)
:System.Void execStateSet(via.GameObject, share.ValidatedBool, share.ValidatedBool, System.UInt32, share.GameObjectStateSetArgs)
:share.GameObjectJointSetArgs get_GameObjectJointSetArgsDefault()
:share.GameObjectParentSetArgs get_GameObjectParentSetArgsDefault()
:share.GameObjectStateSetArgs get_GameObjectStateSetArgsDefault()
:System.Boolean get_IsRejectPhase()
:System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentJointSetRequest> get_ParentJointSetRequestEntry()
:System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentSetRequest> get_ParentSetRequestEntry()
:System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest> get_SameJointsConstraintSetRequestEntry()
:System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectStateSetRequest> get_StateSetRequestEntry()
:System.Void notifyJointSetResult(via.GameObject, share.GameObjectJointSetArgs, share.GameObjectStateSetResult)
:System.Void notifyParentSetResult(via.GameObject, share.GameObjectParentSetArgs, share.GameObjectStateSetResult)
:System.Void notifyStateSetResult(via.GameObject, share.GameObjectStateSetArgs, share.GameObjectStateSetResult)
:System.Void onDestroy()
:System.Void onStart()
:System.Void procParentJointSetRequests()
:System.Void procParentSetRequests()
:System.Void procSameJointsConstraintSetRequests()
:System.Void procStateSetRequests()
:System.Void requestSetParent(via.GameObject, via.GameObject, share.GameObjectParentSetArgs)
:System.Void requestSetParentJoint(via.GameObject, System.UInt32, share.GameObjectJointSetArgs)
:System.Void requestSetSameJointsConstraint(via.GameObject, System.Boolean, share.GameObjectJointSetArgs)
:System.Void requestSetState(via.GameObject, share.ValidatedBool, share.ValidatedBool, System.UInt32, share.GameObjectStateSetArgs)
:System.Void set_IsRejectPhase(System.Boolean)
:System.Void set_ParentJointSetRequestEntry(System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentJointSetRequest>)
:System.Void set_ParentSetRequestEntry(System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentSetRequest>)
:System.Void set_SameJointsConstraintSetRequestEntry(System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest>)
:System.Void set_StateSetRequestEntry(System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectStateSetRequest>)
:System.Void updateOnFrameHead()
```

## `share.GameObjectStateSetMediator.GameObjectParentJointSetRequest`

```lua
-- methods
:share.GameObjectJointSetArgs get_Args()
:System.UInt32 get_JointHash()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectJointSetArgs)
:System.Void set_JointHash(System.UInt32)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectParentSetRequest`

```lua
-- methods
:share.GameObjectParentSetArgs get_Args()
:via.GameObject get_Parent()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectParentSetArgs)
:System.Void set_Parent(via.GameObject)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest`

```lua
-- methods
:share.GameObjectJointSetArgs get_Args()
:System.Boolean get_SameJointConstreint()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectJointSetArgs)
:System.Void set_SameJointConstreint(System.Boolean)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectStateSetRequest`

```lua
-- methods
:share.GameObjectStateSetArgs get_Args()
:share.ValidatedBool get_DrawSelf()
:System.UInt32 get_Layer()
:via.GameObject get_Target()
:share.ValidatedBool get_UpdateSelf()
:System.Void set_Args(share.GameObjectStateSetArgs)
:System.Void set_DrawSelf(share.ValidatedBool)
:System.Void set_Layer(System.UInt32)
:System.Void set_Target(via.GameObject)
:System.Void set_UpdateSelf(share.ValidatedBool)
```

## `share.GameObjectStateSetMediatorBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
```

## `share.GameObjectStateSetPhase`

```lua
-- values (System.Int32 enum)
FrameHead
Immediate
```

## `share.GameObjectStateSetResult`

```lua
-- values (System.Int32 enum)
Canceled
InvalidArgs
Rejected
Success
Unknown
```

## `share.GameRemoveRequestArgs`

```lua
-- methods
:share.SaveLoadRequestArgs getCopy()
```

## `share.GameSaveCompletedEventArgs`

```lua
-- methods
:share.SaveLoadProcessResult get_Result()
:System.Int32 get_SlotId()
:System.Void set_Result(share.SaveLoadProcessResult)
:System.Void set_SlotId(System.Int32)
```

## `share.GameSaveRequestArgs`

```lua
-- methods
:share.SaveLoadRequestArgs getCopy()
:System.UInt64 getSaveDataSize()
```

## `share.GameSaveTakeOverArgs`

```lua
-- methods
:share.GameSaveTakeOverArgs getCopy()
:chainsaw.CampaignManager.Difficulty get_Difficulty()
:System.Int32 get_NextRoundCount()
:System.Void set_Difficulty(chainsaw.CampaignManager.Difficulty)
:System.Void set_NextRoundCount(System.Int32)
```

## `share.GameStateBase`

```lua
-- fields
CurrentArgument: share.GameStateArgument
OnEnter: System.Action
OnEnterOnce: System.Action
OnLeave: System.Action
OnLeaveOnce: System.Action
OnSetup: System.Action
OnSetupOnce: System.Action
TargetPhase: share.GameStateBase.ControlPhase
-- methods
:System.Void add_OnEnter(System.Action)
:System.Void add_OnEnterOnce(System.Action)
:System.Void add_OnLeave(System.Action)
:System.Void add_OnLeaveOnce(System.Action)
:System.Void add_OnSetup(System.Action)
:System.Void add_OnSetupOnce(System.Action)
:share.GameStateBase.ControlPhase get_CurrentPhase()
:System.Int32 get_Hash()
:System.Boolean get_StateChangeable()
:System.Void process()
:System.Void processFinalize()
:System.Void processInitalize()
:System.Void processLeave()
:System.Void processNone()
:System.Void processSetup()
:System.Void processUpdate()
:System.Void processWait()
:System.Void remove_OnEnter(System.Action)
:System.Void remove_OnEnterOnce(System.Action)
:System.Void remove_OnLeave(System.Action)
:System.Void remove_OnLeaveOnce(System.Action)
:System.Void remove_OnSetup(System.Action)
:System.Void remove_OnSetupOnce(System.Action)
:System.Void requestFinalize()
:System.Void requestInitalize()
:System.Void requestLeave()
:System.Void requestSetup(share.GameStateArgument)
:System.Void set_CurrentPhase(share.GameStateBase.ControlPhase)
:System.Void set_StateChangeable(System.Boolean)
:System.Void transit(share.GameStateBase.ControlPhase)
:System.Void transitFinalize()
:System.Void transitInitalize()
:System.Void transitLeave()
:System.Void transitSetup()
:System.Void transitUpdate()
```

## `share.GameStateBase.ControlPhase`

```lua
-- values (System.Int32 enum)
Finalize
Initialize
Leave
None
Setup
Update
Wait
```

## `share.GpuQualityPerformanceBalancer`

```lua
-- fields
Balancer: share.QualityPerformanceBalancer
-- methods
:System.Void addController(share.QualityPerformanceControllable, System.Int32, System.String)
:System.Void init(System.Single, System.Single, System.Int32)
:System.Void qualityUp()
:System.Void removeController(share.QualityPerformanceControllable)
:System.Void requestPauseControl(share.QualityPerformanceBalancer.PauseReason, System.Boolean)
:System.Void requestResumeControl(share.QualityPerformanceBalancer.PauseReason)
:System.Void requestToEndQualityControl()
:System.Void requestToStartQualityControl()
:System.Void speedUp()
:System.Void term()
```

## `share.GuidExtention`

```lua
-- static
:System.Int32 convertHexToInt(System.Char)
:System.Void toUint64(System.Guid, System.UInt64, System.UInt64)
:System.UInt64 toUint64Lower(System.Guid)
:System.UInt64 toUint64Upper(System.Guid)
```

## `share.HIDDefine`

```lua
-- fields
AllKeyList: via.hid.KeyboardKey[] [static]
AnyKeyList: System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> [static]
BindableKeyList: System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> [static]
KeyboardKeyToHidMouseButton: System.Collections.Generic.Dictionary`2<via.hid.KeyboardKey,via.hid.MouseButton> [static]
MouseAnyButton: via.hid.MouseButton [static]
S_Command_None: System.UInt32 [static]
-- static
:System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> getBindableKeyList()
```

## `share.Log`

```lua
-- fields
INVALID_OBJECT_PREFIX: System.String [static]
LOCK: System.Object [static]
TRACE_PREFIX: System.String [static]
_Logs: System.String[] [static]
_LogsIndex: System.Int32 [static]
-- static
:System.String getHistory()
:System.String makeFormat(System.String)
```

## `share.Log.Level`

```lua
-- values (System.Int32 enum)
Critical
Debug
Error
Info
Notice
Warning
WarningOnlyLog
```

## `share.LogicalOperationAndOr`

```lua
-- values (System.Int32 enum)
AND
OR
```

## `share.MainModeDefine`

```lua
-- static
:System.Boolean isCoop(share.GameModeType)
```

## `share.MainModeManager`

```lua
-- fields
CurrentGameState: share.MainModeManager.GameStateControl
GameStateCollection: System.Collections.Generic.Dictionary`2<System.Type,share.MainModeManager.GameStateControl>
NextGameState: share.MainModeManager.GameStateControl
PreviousGameState: share.MainModeManager.GameStateControl
StartupGameState: System.Type
StateChangeRequestQueue: System.Collections.Generic.Queue`1<share.MainModeManager.GameStateChangeRequest>
-- methods
:System.Void addEvent(System.Type, share.GameStateBase.ControlPhase, System.Action, System.Boolean)
:System.Void changeMainModeManagerPhase(share.MainModeManager.Phase)
:share.MainModeManager.GameStateControl dequeueStateChangeRequest()
:System.Void enqueueChangeGameState(System.Type, share.GameStateArgument)
:System.Void exit()
:share.GameModeType get_CurrGameModeType()
:share.MainModeManager.Phase get_CurrPhase()
:System.Type get_CurrStateType()
:System.Boolean get_IsInGame()
:System.Type get_NextStateType()
:System.Type get_PrevStateType()
:System.Void init()
:System.Void onDestroy()
:System.Void onStart()
:System.Void onUpdate()
:System.Void removeEvent(System.Type, share.GameStateBase.ControlPhase, System.Action)
:System.Void requestToChangeGameState(System.Type, share.GameStateArgument)
:System.Void set_CurrGameModeType(share.GameModeType)
:System.Void set_CurrPhase(share.MainModeManager.Phase)
```

## `share.MainModeManager.GameStateChangeRequest`

```lua
-- methods
:share.GameStateArgument get_Argument()
:System.Type get_NextState()
:System.Void set_Argument(share.GameStateArgument)
:System.Void set_NextState(System.Type)
```

## `share.MainModeManager.GameStateControl`

```lua
-- fields
Argument: share.GameStateArgument
GameState: share.GameStateBase
```

## `share.MainModeManager.Phase`

```lua
-- values (System.Int32 enum)
FinalizeGameState
FinalizingGameState
GameStateLeave
GameStateSetup
GameStateUpdate
InitializeGameState
InitializingGameState
Invalid
ModeInitalize
ReadyForSetup
```

## `share.MainModeManagerBehavior`

```lua
-- methods
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.MotionFsmActionTiming`

```lua
-- values (System.Int32 enum)
End
Sequence
Start
Update
```

## `share.ObjectRelationType`

```lua
-- values (System.Int32 enum)
Child
Children
Parent
Self
```

## `share.PauseManager`

```lua
-- fields
_CacheTagValues: System.UInt32[] [static]
_CachePause: System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>
_CntGimmickInUseHandle: System.UInt32
_CurrentTargetPauseDraw: System.UInt32
_CurrentTargetPauseUpdate: System.UInt32
_CustomPause: System.Collections.Generic.List`1<share.PauseManager.CustomPauseInfo>
_CustomPauseParameters: System.Collections.Generic.Dictionary`2<System.UInt32,share.PauseManager.PauseParameter>
_EventHolders: share.PauseManager.EventHolder[]
_GimmickInUseInfos: System.Collections.Generic.List`1<share.PauseManager.GimmickInUseInfo>
_LockDelegate: share.MutexObject
_OnApplyed: System.Action`1<share.PauseManager.ArgApplyed>
_OnBeforeApply: System.Action`1<share.PauseManager.ArgBeforeApply>
_Pause: System.Collections.Generic.List`1<share.PauseManager.PauseInfo>
_PauseParameters: share.PauseManager.PauseParameter[]
_Request: share.PauseManager.Requests
_RequestLate: share.PauseManager.Requests
_RequestLockObject: via.threading.SimpleReaderWriterLock
_TargetParameters: share.PauseManager.TargetParameter[]
_TmpExecInvoker: System.Collections.Generic.List`1<share.PauseManager.RequestBase>
-- methods
:System.Void add__OnApplyed(System.Action`1<share.PauseManager.ArgApplyed>)
:System.Void add__OnBeforeApply(System.Action`1<share.PauseManager.ArgBeforeApply>)
:System.Void appendOnApplyed(System.Action`1<share.PauseManager.ArgApplyed>)
:System.Void appendOnBeforeApply(System.Action`1<share.PauseManager.ArgBeforeApply>)
:System.Void appendOnChangeDraw(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void appendOnChangeUpdate(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void apply(share.PauseManager.Requests)
:System.Void applyOnLateUpdate(share.PauseManager.Requests)
:System.Void calcPausedUpdate(System.UInt32[], System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>)
:System.Boolean calcPausedUpdate(System.UInt32)
:System.Void clear()
:System.Void dependOnApplyed(System.Action`1<share.PauseManager.ArgApplyed>)
:System.Void dependOnBeforeApply(System.Action`1<share.PauseManager.ArgBeforeApply>)
:System.Void detachOnChangeDraw(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void detachOnChangeUpdate(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:share.PauseManager.PauseParameter getCustomPauseParam(System.UInt32)
:share.PauseManager.PauseParameter getPauseParam(share.PauseManager.PauseType)
:share.PauseManager.Requests getRequests(share.PauseManager.Option)
:share.PauseManager.TargetParameter getTargetParameter(share.PauseManager.TargetType)
:System.Boolean isPauseCustom(System.UInt32)
:System.Boolean isPaused(share.PauseManager.PauseType)
:System.Boolean isPaused()
:System.Boolean isPausedDraw(share.PauseManager.TargetType)
:System.Boolean isPausedDraw(via.GameObject)
:System.Boolean isPausedDraw(System.UInt32)
:System.Boolean isPausedUpdate(share.PauseManager.TargetType)
:System.Boolean isPausedUpdate(via.GameObject)
:System.Boolean isPausedUpdate(System.UInt32)
:System.Void onDestroy()
:System.Void onStart()
:System.Void registerCustomPauseParameter(System.UInt32, share.PauseManager.PauseParameter)
:System.UInt32 registerInUse(via.GameObject, share.PauseManager.GimmickInUseInfo.UserType)
:System.UInt32 registerInUseByEnemy(via.GameObject)
:System.UInt32 registerInUseByPlayer(via.GameObject)
:System.Void registerOnChangePauseDraw(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void registerOnChangePauseUpdate(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void remove__OnApplyed(System.Action`1<share.PauseManager.ArgApplyed>)
:System.Void remove__OnBeforeApply(System.Action`1<share.PauseManager.ArgBeforeApply>)
:System.Void requestEndCustomPause(System.UInt32, System.String, System.Action)
:System.Void requestEndCustomPause(System.UInt32, System.String, share.PauseManager.Option)
:System.Void requestEndPause(share.PauseManager.PauseType, System.String, System.Action)
:System.Void requestEndPause(share.PauseManager.PauseType, System.String, share.PauseManager.Option)
:System.Void requestStartCustomPause(System.UInt32, System.String, System.String, System.Action)
:System.Void requestStartCustomPause(System.UInt32, System.String, System.String, share.PauseManager.Option)
:System.Void requestStartPause(share.PauseManager.PauseType, System.String, System.Action)
:System.Void requestStartPause(share.PauseManager.PauseType, System.String, share.PauseManager.Option)
:System.Void unregisterCustomPauseParameter(System.UInt32)
:System.Void unregisterInUse(System.UInt32)
:System.Void unregisterOnChangePauseDraw(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void unregisterOnChangePauseUpdate(share.PauseManager.TargetType, System.Action`1<System.Boolean>)
:System.Void updateOnFrameHead()
:System.Void updateOnLateUpdate()
```

## `share.PauseManager.ApplyTiming`

```lua
-- values (System.Int32 enum)
FrameHead
LateUpdate
```

## `share.PauseManager.CustomPauseInfo`

```lua
-- fields
OwnerName: System.String
Pause: System.UInt32
```

## `share.PauseManager.CustomRequestInfo`

```lua
-- fields
OwnerName: System.String
Pause: System.UInt32
```

## `share.PauseManager.EventHolder`

```lua
-- fields
OnChangePauseDraw: System.Action`1<System.Boolean>
OnChangePauseUpdate: System.Action`1<System.Boolean>
-- methods
:System.Void add_OnChangePauseDraw(System.Action`1<System.Boolean>)
:System.Void add_OnChangePauseUpdate(System.Action`1<System.Boolean>)
:System.Void fireOnChangePauseDraw(System.Boolean)
:System.Void fireOnChangePauseUpdate(System.Boolean)
:System.Void remove_OnChangePauseDraw(System.Action`1<System.Boolean>)
:System.Void remove_OnChangePauseUpdate(System.Action`1<System.Boolean>)
```

## `share.PauseManager.GimmickInUseInfo`

```lua
-- fields
Gimmick: via.GameObject
HandleID: System.UInt32
RequestUnregister: System.Boolean
User: share.PauseManager.GimmickInUseInfo.UserType
```

## `share.PauseManager.GimmickInUseInfo.UserType`

```lua
-- values (System.Int32 enum)
Enemy
Player
```

## `share.PauseManager.Option`

```lua
-- fields
OnExec: System.Action
Timing: share.PauseManager.ApplyTiming
```

## `share.PauseManager.PauseFlag`

```lua
-- values (System.Int32 enum)
DebugPause
Dip
EventMovie
EventStop
EventTimeline
Loading
None
PhotoEnemy
PhotoEnvAnimal
PhotoNPC
PhotoPlayer
StopUpdate
StopUpdateWithoutCamera
Title
```

## `share.PauseManager.PauseInfo`

```lua
-- fields
OwnerName: System.String
Pause: share.PauseManager.PauseType
-- methods
:System.String ToString()
```

## `share.PauseManager.PauseParameter`

```lua
-- fields
TargetDraw: share.PauseManager.TargetFlag
TargetUpdate: share.PauseManager.TargetFlag
-- methods
:System.UInt32 get_TargetDrawBit()
:System.UInt32 get_TargetUpdateBit()
```

## `share.PauseManager.PauseType`

```lua
-- values (System.Int32 enum)
CampaignJumpA
CampaignJumpB
CampaignJumpC
CampaignManagerEnvSceneLoader
DebugPause
Dip
EventMovie
EventStop
EventTimeline
Loading
None
PhotoEnemy
PhotoEnvAnimal
PhotoMode
PhotoNPC
PhotoPlayer
StopUpdate
StopUpdateWithoutCamera
Title
```

## `share.PauseManager.RequestBase`

```lua
-- fields
OnExec: System.Action
```

## `share.PauseManager.RequestInfo`

```lua
-- fields
OwnerName: System.String
Pause: share.PauseManager.PauseType
```

## `share.PauseManager.Requests`

```lua
-- fields
CustomEnd: System.Collections.Generic.List`1<share.PauseManager.CustomRequestInfo>
CustomStart: System.Collections.Generic.List`1<share.PauseManager.CustomRequestInfo>
End: System.Collections.Generic.List`1<share.PauseManager.RequestInfo>
Start: System.Collections.Generic.List`1<share.PauseManager.RequestInfo>
-- methods
:System.Void clear()
```

## `share.PauseManager.TargetFlag`

```lua
-- values (System.Int32 enum)
Dynamics
None
Sound
TagCamera
TagDoll
TagEffect
TagEnemy
TagEnvironment
TagEvent
TagEventStop
TagEventStopUpdate
TagGUI
TagGimmick
TagGmPause
TagItem
TagLevel
TagPhotoDrawOff
TagPhotoEnemy
TagPhotoEnvAnimal
TagPhotoNPC
TagPhotoPlayer
TagPlayer
TagShell
TagWeaponMerchant
TagZone
```

## `share.PauseManager.TargetParameter`

```lua
-- fields
_OnChangeDraw: System.Action`1<System.Boolean>
_OnChangeUpdate: System.Action`1<System.Boolean>
-- methods
:System.Void add__OnChangeDraw(System.Action`1<System.Boolean>)
:System.Void add__OnChangeUpdate(System.Action`1<System.Boolean>)
:System.Void appendOnChangeDraw(System.Action`1<System.Boolean>)
:System.Void appendOnChangeUpdate(System.Action`1<System.Boolean>)
:System.Void clear()
:System.Void detachOnChangeDraw(System.Action`1<System.Boolean>)
:System.Void detachOnChangeUpdate(System.Action`1<System.Boolean>)
:System.Boolean get_IsPausedDraw()
:System.Boolean get_IsPausedUpdate()
:System.Void remove__OnChangeDraw(System.Action`1<System.Boolean>)
:System.Void remove__OnChangeUpdate(System.Action`1<System.Boolean>)
:System.Void requestPauseDraw(System.Boolean)
:System.Void requestPauseUpdate(System.Boolean)
:System.Void set_IsPausedDraw(System.Boolean)
:System.Void set_IsPausedUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameterDynamics`

```lua
-- fields
PauseDynamics: System.Action`1<System.Boolean> [static]
-- methods
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameterSound`

```lua
-- fields
PauseSound: System.Action`1<System.Boolean> [static]
-- methods
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameterTag`

```lua
-- fields
TagBit: System.Int32
TagName: System.String
-- methods
:System.Void pauseDraw(System.Boolean)
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetType`

```lua
-- values (System.Int32 enum)
Dynamics
Max
Sound
TagCamera
TagDoll
TagEffect
TagEnemy
TagEnvironment
TagEvent
TagEventStop
TagEventStopUpdate
TagGUI
TagGimmick
TagGmPause
TagItem
TagLevel
TagPhotoDrawOff
TagPhotoEnemy
TagPhotoEnvAnimal
TagPhotoNPC
TagPhotoPlayer
TagPlayer
TagShell
TagWeaponMerchant
TagZone
```

## `share.PauseManagerBehavior`

```lua
-- methods
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.PrefabController`

```lua
-- fields
_IsConvertVec3ToPosition: System.Boolean
_LastRefCount: System.Int32
_LoadPriority: System.Int16
-- methods
:System.Int16 getDynamicLoadPriority()
:System.String get_DisplayName()
:System.Func`2<share.PrefabController,System.Int16> get_DynamicLoadPriority()
:System.Boolean get_HasDynamicLoadPriority()
:System.Boolean get_IsConvertVec3ToPosition()
:System.Int16 get_LoadPriority()
:System.Boolean get_Ready()
:System.String get_ResourcePath()
:System.Boolean requestInstantiate(System.Object, via.vec3, via.Quaternion, via.Folder, share.PrefabInstantiateArgs)
:System.Boolean requestInstantiate(System.Object, via.vec3, via.Quaternion, share.FolderKind, share.PrefabInstantiateArgs)
:System.Boolean requestInstantiate(System.Object, via.Position, via.Quaternion, via.Folder, share.PrefabInstantiateArgs)
:System.Boolean requestInstantiate(System.Object, via.Position, via.Quaternion, share.FolderKind, share.PrefabInstantiateArgs)
:System.Void set_DynamicLoadPriority(System.Func`2<share.PrefabController,System.Int16>)
:System.Void set_IsConvertVec3ToPosition(System.Boolean)
:System.Void set_LoadPriority(System.Int16)
:System.Void update()
```

## `share.PrefabInstantiateArgs`

```lua
-- fields
DefaultImmidiate: share.PrefabInstantiateArgs [static]
DynamicPriority: System.Func`1<System.Int16>
InstantiatedEvent: System.Action`1<share.PrefabInstantiateResults>
WithdrawEvent: System.Func`1<System.Boolean>
-- methods
:System.Void add_DynamicPriority(System.Func`1<System.Int16>)
:System.Void add_InstantiatedEvent(System.Action`1<share.PrefabInstantiateResults>)
:System.Void add_WithdrawEvent(System.Func`1<System.Boolean>)
:System.Int16 getInstantiatePriority()
:share.PrefabInstantiatePhase get_Phase()
:System.Int16 get_Priority()
:System.Nullable`1<via.vec3> get_Scale()
:System.Boolean isWithdraw()
:System.Void notifyResult(share.PrefabInstantiateResults)
:System.Void remove_DynamicPriority(System.Func`1<System.Int16>)
:System.Void remove_InstantiatedEvent(System.Action`1<share.PrefabInstantiateResults>)
:System.Void remove_WithdrawEvent(System.Func`1<System.Boolean>)
:System.Void set_Phase(share.PrefabInstantiatePhase)
:System.Void set_Priority(System.Int16)
:System.Void set_Scale(System.Nullable`1<via.vec3>)
```

## `share.PrefabInstantiateDistributor`

```lua
-- methods
:System.Boolean get_ProcFinished()
:System.Int32 get_ProcGroupID()
:System.Int32 get_ProcRequestSkipIndex()
:System.Void lateUpdate()
:System.Void notifyProcFinished()
:System.Void onDestroy()
:System.Void requestFrameTailProc(System.Int32, System.Int32)
:System.Void set_ProcFinished(System.Boolean)
:System.Void set_ProcGroupID(System.Int32)
:System.Void set_ProcRequestSkipIndex(System.Int32)
:System.Void start()
```

## `share.PrefabInstantiateMediator`

```lua
-- fields
PIE_DEFAULT_CAPACITY: System.Int32 [static]
PIR_DEFAULT_CAPACITY: System.Int32 [static]
_InstantiateTimeBudgetFree: System.Boolean
-- methods
:System.Void disassemblyRequests()
:System.Void distributeRequests()
:System.Void endInstantiateTimeBudgetFree()
:System.Boolean execInstantiate(share.PrefabController, via.Position, via.Quaternion, via.Folder, share.PrefabInstantiateArgs, System.Single, System.Single)
:System.Void gc()
:System.Collections.Generic.List`1<share.PrefabInstantiateDistributor> get_Distributors()
:System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest> get_ExecuteFrameHeadEntry()
:System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest> get_ExecuteFrameTailEntry()
:System.Boolean get_HasInstantiateRequest()
:share.AverageTimeProfiler get_InstantiateFrameHeadProfile()
:share.AverageTimeProfiler get_InstantiateFrameTailProfile()
:System.Single get_InstantiateTimeBudgetOnFrameHead()
:System.Single get_InstantiateTimeBudgetOnFrameTail()
:System.Boolean get_IsRejectPhase()
:share.PrefabInstantiateArgs get_PrefabInstantiateArgsDefault()
:System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest> get_RequestEntry()
:System.Void notifyInstantiateResult(share.PrefabController, share.PrefabInstantiateArgs, share.PrefabInstantiateResults)
:System.Void onAwake()
:System.Void onDestroy()
:System.Void procFrameTailRequests(share.PrefabInstantiateDistributor)
:System.Int32 procRequests(System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>, System.Single, share.AverageTimeProfiler, System.Int32, System.Int32)
:System.Void registerDistributor(share.PrefabInstantiateDistributor)
:System.Boolean requestInstantiate(share.PrefabController, System.Object, via.Position, via.Quaternion, via.Folder, share.PrefabInstantiateArgs)
:System.Boolean requestInstantiateInternal(share.PrefabController, System.Object, via.Position, via.Quaternion, via.Folder, share.PrefabInstantiateArgs)
:System.Void set_Distributors(System.Collections.Generic.List`1<share.PrefabInstantiateDistributor>)
:System.Void set_ExecuteFrameHeadEntry(System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>)
:System.Void set_ExecuteFrameTailEntry(System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>)
:System.Void set_HasInstantiateRequest(System.Boolean)
:System.Void set_InstantiateFrameHeadProfile(share.AverageTimeProfiler)
:System.Void set_InstantiateFrameTailProfile(share.AverageTimeProfiler)
:System.Void set_InstantiateTimeBudgetOnFrameHead(System.Single)
:System.Void set_InstantiateTimeBudgetOnFrameTail(System.Single)
:System.Void set_IsRejectPhase(System.Boolean)
:System.Void set_RequestEntry(System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>)
:System.Void startInstantiateTimeBudgetFree()
:System.Void unregisterDistributor(share.PrefabInstantiateDistributor)
:System.Void updateOnFrameHead()
```

## `share.PrefabInstantiateMediator.PrefabInstantiateRequest`

```lua
-- methods
:share.PrefabInstantiateArgs get_Args()
:System.Boolean get_Executed()
:via.Folder get_Folder()
:System.Boolean get_IsValidRequester()
:via.Position get_Position()
:share.PrefabController get_Prefab()
:System.Int32 get_Priority()
:System.Single get_ProgressedFrame()
:System.Object get_Requester()
:System.Boolean get_Reserved()
:via.Quaternion get_Rotation()
:System.Void reserveProc()
:System.Void set_Args(share.PrefabInstantiateArgs)
:System.Void set_Executed(System.Boolean)
:System.Void set_Folder(via.Folder)
:System.Void set_Position(via.Position)
:System.Void set_Prefab(share.PrefabController)
:System.Void set_Priority(System.Int32)
:System.Void set_ProgressedFrame(System.Single)
:System.Void set_Requester(System.Object)
:System.Void set_Reserved(System.Boolean)
:System.Void set_Rotation(via.Quaternion)
:System.Void update(System.Single)
```

## `share.PrefabInstantiateMediatorBehavior`

```lua
-- fields
_InstantiateTimeBudgetOnFrameHead: System.Single
_InstantiateTimeBudgetOnFrameTail: System.Single
-- methods
:System.Void awake()
:System.Single get_InstantiateTimeBudgetOnFrameHead()
:System.Single get_InstantiateTimeBudgetOnFrameTail()
:System.Void onDestroy()
:System.Void set_InstantiateTimeBudgetOnFrameHead(System.Single)
:System.Void set_InstantiateTimeBudgetOnFrameTail(System.Single)
:System.Void start()
```

## `share.PrefabInstantiatePhase`

```lua
-- values (System.Int32 enum)
FrameHead
FrameTail
Immediate
```

## `share.PrefabInstantiateResult`

```lua
-- values (System.Int32 enum)
Canceled
EmptyAsset
InvalidArgs
IsNotReady
LostRequester
Rejected
Success
Unknown
```

## `share.PrefabInstantiateResults`

```lua
-- methods
:via.GameObject get_GameObject()
:System.Single get_InstantiateTime()
:System.Single get_ProgressTime()
:share.PrefabInstantiateResult get_Result()
```

## `share.QualityPerformanceBalancer`

```lua
-- fields
ControlTargetList: System.Collections.Generic.LinkedList`1<share.QualityPerformanceBalancer.ControlTarget>
CurrentControlTarget: System.Collections.Generic.LinkedListNode`1<share.QualityPerformanceBalancer.ControlTarget>
NullControlTarget: share.QualityPerformanceBalancer.NullControl
QualityChangeComboThreshold: System.Int32
QualityUpBorder: System.Single
SpeedUpBorder: System.Single
-- methods
:System.Void addController(share.QualityPerformanceControllable, System.Int32, System.String)
:share.QualityPerformanceBalancer.PauseReason get_CurrentPauseReason()
:System.String get_CurrentQualityName()
:System.Int32 get_CurrentQualityRank()
:System.Boolean get_OnWork()
:System.Int32 get_TimeOverComboCount()
:System.Int32 get_TimeUnderComboCount()
:System.Void init(System.Single, System.Single, System.Int32)
:System.Void qualityUp()
:System.Void removeController(share.QualityPerformanceControllable)
:System.Void requestPauseControl(share.QualityPerformanceBalancer.PauseReason, System.Boolean)
:System.Void requestResumeControl(share.QualityPerformanceBalancer.PauseReason)
:System.Void requestToEndQualityControl()
:System.Void requestToStartQualityControl()
:System.Void set_CurrentPauseReason(share.QualityPerformanceBalancer.PauseReason)
:System.Void set_OnWork(System.Boolean)
:System.Void set_TimeOverComboCount(System.Int32)
:System.Void set_TimeUnderComboCount(System.Int32)
:System.Void speedUp()
:System.Void term()
:System.Void updateLevel(System.Single)
```

## `share.QualityPerformanceBalancer.ControlTarget`

```lua
-- fields
Name: System.String
Rank: System.Int32
Target: share.QualityPerformanceControllable
```

## `share.QualityPerformanceBalancer.NullControl`

```lua
-- methods
:System.Single getQualityUpBorder(System.Int32, System.Single)
:System.Single getSpeedUpBorder(System.Int32, System.Single)
```

## `share.QualityPerformanceBalancer.PauseReason`

```lua
-- values (System.Int32 enum)
Debug
Event
None
```

## `share.QualityPerformanceBalancerBehavior`

```lua
-- fields
_CpuControlThresholdFrameCount: System.Int32
_CpuQualityupThreshold: System.Single
_CpuSpeedupThreadold: System.Single
_GpuControlThresholdFrameCount: System.Int32
_GpuQualityupThreshold: System.Single
_GpuSpeedupThreadold: System.Single
-- methods
:System.Int32 get_CpuControlThresholdFrameCount()
:System.Single get_CpuQualityupThreshold()
:System.Single get_CpuSpeedupThreadold()
:System.Int32 get_GpuControlThresholdFrameCount()
:System.Single get_GpuQualityupThreshold()
:System.Single get_GpuSpeedupThreadold()
:System.Void onDestroy()
:System.Void set_CpuControlThresholdFrameCount(System.Int32)
:System.Void set_CpuQualityupThreshold(System.Single)
:System.Void set_CpuSpeedupThreadold(System.Single)
:System.Void set_GpuControlThresholdFrameCount(System.Int32)
:System.Void set_GpuQualityupThreshold(System.Single)
:System.Void set_GpuSpeedupThreadold(System.Single)
:System.Void start()
:System.Void update()
```

## `share.RegionType`

```lua
-- values (System.Int32 enum)
Asia
Europe
Japan
USA
Unknown
WW
```

## `share.ResourceController`

```lua
-- fields
_InitialActivateInterval: System.Int32
_InitialMaxParallelReadingCount: System.Int32
-- methods
:System.Int32 get_InitialActivateInterval()
:System.Int32 get_InitialMaxParallelReadingCount()
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void set_InitialActivateInterval(System.Int32)
:System.Void set_InitialMaxParallelReadingCount(System.Int32)
:System.Void start()
```

## `share.ResourceStandbyMediator`

```lua
-- fields
NameAppResident: System.String [static]
MaxParallelReadingCount: System.Int32
NeedToFastTrackProcedure: System.Boolean
NeedToGCExecute: System.Boolean
ReadingList: System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>
RequestList: System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>
RequestLockObject: System.Object
StandbyList: System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>
_CurrentMode: share.ResourceStandbyMediator.Mode
-- methods
:System.Void FullClean()
:System.Void FullCleanWithoutAppResident()
:System.Void GC()
:System.Boolean GcExec(share.ResourceStandbyMediator.Entry)
:System.Void registStandbyFolder(via.Folder, System.Action)
:System.Boolean releaseWithoutAppResident(share.ResourceStandbyMediator.Entry)
:System.Void requestChangeMode(share.ResourceStandbyMediator.Mode)
:System.Void requestRelease(via.Folder)
:System.Void requestRelease(via.Prefab)
:System.Boolean requestRelease(share.ResourceStandbyMediator.Entry, System.Boolean)
:System.Void requestStandby(via.Folder, System.Int16, System.Action)
:System.Void requestStandby(via.Folder, System.Func`1<System.Int16>, System.Action)
:System.Void requestStandby(via.Prefab, System.Int16, System.Action)
:System.Void requestStandby(via.Prefab, System.Func`1<System.Int16>, System.Action)
:System.Void requestStandby(share.ResourceStandbyMediator.Entry)
:System.Void setMaxParallelReadingCount(System.Int32)
:System.Void updateLoading()
:System.Void updateLoading_DoneCheck()
:System.Void updateLoading_KickRequest()
```

## `share.ResourceStandbyMediator.Entry`

```lua
-- fields
AliveFrame: System.Int32
DynamicPriority: System.Func`1<System.Int16>
FastTrack: System.Boolean
FinishAction: System.Action
Priority: System.Int16
RefFolder: via.Folder
RefPrefab: via.Prefab
-- methods
:System.Boolean isSameEntity(share.ResourceStandbyMediator.Entry)
:System.Void updatePriority()
```

## `share.ResourceStandbyMediator.FolderEntry`

```lua
-- fields
FolderPath: System.String
IncluderList: System.Collections.Generic.List`1<share.ResourceStandbyMediator.FolderEntry>
_ReleaseReserved: System.Boolean
-- methods
:System.Void cancelRelease()
:System.Boolean get_ReleaseReserved()
:System.Boolean hasAccident()
:System.Boolean isExist()
:System.Boolean isInclusive(share.ResourceStandbyMediator.Entry)
:System.Boolean isReady()
:System.Boolean isStandby()
:System.Void linkInclusive(share.ResourceStandbyMediator.Entry)
:System.Boolean release()
:System.Void reserveRelease()
:System.Boolean standby()
```

## `share.ResourceStandbyMediator.Mode`

```lua
-- values (System.Int32 enum)
ReadWait
Standard
```

## `share.ResourceStandbyMediator.PrefabEntry`

```lua
-- fields
_ReleaseReserved: System.Boolean
-- methods
:System.Void cancelRelease()
:System.Boolean get_ReleaseReserved()
:System.Boolean hasAccident()
:System.Boolean isExist()
:System.Boolean isReady()
:System.Boolean isStandby()
:System.Boolean release()
:System.Void reserveRelease()
:System.Boolean standby()
```

## `share.ResourceStandbyMediatorPriority`

```lua
-- fields
ACCESSORY_PREFAB: System.Int16 [static]
BOOT_EXTRA_CONTENTS: System.Int16 [static]
BOOT_GAME_CORE: System.Int16 [static]
BOOT_MAIN_CONTENTS: System.Int16 [static]
BOOT_RESIDENT_CONTENTS: System.Int16 [static]
CAMPAIGN_CONTENTS: System.Int16 [static]
CATALOG_FOLDER: System.Int16 [static]
CATALOG_FOLDER_FIRST_CHANK: System.Int16 [static]
CHAPTER: System.Int16 [static]
CHARACTER_PREFAB: System.Int16 [static]
DROPITEM_PREFAB: System.Int16 [static]
FAST_TRACK_BORDER: System.Int16 [static]
GAME_CONTENTS: System.Int16 [static]
GUI_GAMESTATE_CONTROL: System.Int16 [static]
GUI_PREFAB_INSTANTIATE: System.Int16 [static]
LOCATION: System.Int16 [static]
PREFECTURE: System.Int16 [static]
STAGE_ACTIVATE_HIGH: System.Int16 [static]
STAGE_ACTIVATE_LOW: System.Int16 [static]
STAGE_STANDBY_HIGH: System.Int16 [static]
STAGE_STANDBY_LOW: System.Int16 [static]
STAGE_TIED_SCENE: System.Int16 [static]
TEST: System.Int16 [static]
TIMELINE_ALL_SCENE_CONTROLER: System.Int16 [static]
TIMELINE_EVENT_CONTEXT: System.Int16 [static]
TIMELINE_FLOW: System.Int16 [static]
UNDEFINED: System.Int16 [static]
WEAPON_PREFAB: System.Int16 [static]
ZONE_SCENE: System.Int16 [static]
```

## `share.RuntimeEnvironment`

```lua
-- static
:System.Void analyzeAppRuntimeArgument()
:System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit> getAppRuntimeArgument(System.String)
:share.AppRegionRecognizer get_appRegionRecognizer()
:share.AppRuntimeArgument get_appRuntimeArguments()
:System.Boolean get_isDefault()
:System.Boolean get_isPC()
:System.Boolean get_isPC_Lamm()
:System.Boolean get_isPC_Steam()
:System.Boolean get_isPC_SteamDeck()
:System.Boolean get_isPC_UWP()
:System.Boolean get_isPC_WeGame()
:System.Boolean get_isPS4()
:System.Boolean get_isPS4_Base()
:System.Boolean get_isPS4_Pro()
:System.Boolean get_isPS5()
:System.Boolean get_isPackage()
:System.Boolean get_isPlayStation()
:System.Boolean get_isStadia()
:System.Boolean get_isWindows10()
:System.Boolean get_isXbox()
:System.Boolean get_isXboxOne()
:System.Boolean get_isXboxOneOnly()
:System.Boolean get_isXboxOne_X()
:System.Boolean get_isXboxSS()
:System.Boolean get_isXboxSX()
:System.Boolean get_isXboxScarlet()
:System.Void recognizeRegion()
:System.Void set_appRegionRecognizer(share.AppRegionRecognizer)
:System.Void set_appRuntimeArguments(share.AppRuntimeArgument)
```

## `share.SaveDataBase`

```lua
-- fields
HashValue: System.UInt32
VersionValue: System.UInt32
-- methods
:System.UInt32 get_Hash()
:System.UInt32 get_Version()
:System.Void setHashAndVersion(System.UInt32, System.UInt32)
:System.Void set_Hash(System.UInt32)
:System.Void set_Version(System.UInt32)
```

## `share.SaveDataDefinition`

```lua
-- fields
GAME_SAVE_DATA_COUNT: System.Int32 [static]
GAME_SAVE_DATA_SIZE: System.UInt64 [static]
SYSTEM_SAVE_DATA_COUNT: System.Int32 [static]
SYSTEM_SAVE_DATA_SIZE: System.UInt64 [static]
```

## `share.SaveDataManager`

```lua
-- fields
_BaseGroup000Begin: System.Boolean [static]
_BaseGroup000End: System.Boolean [static]
OnGameLoadCompleted: System.Action`1<share.GameLoadCompletedEventArgs>
OnGameSaveCompleted: System.Action`1<share.GameSaveCompletedEventArgs>
OnPrepareTimeout: System.Action
OnUpdateInIdle: System.Action
_CurrentRequest: share.SaveDataManager.Request
_ExcludeGameSaveCaller: System.Collections.Generic.List`1<System.Object>
_ExcludeGameSaveDelegate: System.Collections.Generic.List`1<share.SaveDataManager.ExcludeGameSaveDelegate>
_GameSaveData: share.SaveDataManager.GameSaveData
_GameSaveResistrantTable: System.Collections.Generic.Dictionary`2<System.UInt32,share.IGameSaveData>
_GameSaveSlotDetailHolder: share.IGameSaveSlotDetailHolder
_GameSaveValidateData: share.SaveDataManager.GameSaveValidateData
_IsExcludeGameSaveInQuit: System.Boolean
_IsTimeoutEventFired: System.Boolean
_RemoveFlowController: chainsaw.SaveRemoveFlowController
_RequestQueue: System.Collections.Generic.Queue`1<share.SaveDataManager.Request>
_SaveFlowController: chainsaw.SaveFlowController
_SaveLoadEventReciever: share.ISaveLoadEventReciever
_SuspendGameSaveCaller: System.Collections.Generic.List`1<System.Object>
_SystemSaveData: share.SaveDataManager.SystemSaveData
_SystemSaveResistrantTable: System.Collections.Generic.Dictionary`2<System.UInt32,share.ISystemSaveData>
_SystemSaveSlotDetailHolder: share.ISystemSaveSlotDetailHolder
_SystemSaveValidateData: share.SaveDataManager.SystemSaveValidateData
_TimeoutTimer: System.Single
-- methods
:System.Boolean IsAutoSaveFlow()
:System.Void add_OnGameLoadCompleted(System.Action`1<share.GameLoadCompletedEventArgs>)
:System.Void add_OnGameSaveCompleted(System.Action`1<share.GameSaveCompletedEventArgs>)
:System.Void add_OnPrepareTimeout(System.Action)
:System.Void add_OnUpdateInIdle(System.Action)
:System.Void applyLoadedGameSaveData()
:System.Void applyLoadedSystemSaveData()
:System.Void changeProcess(share.SaveDataManager.Process)
:System.Boolean checkCERO(share.CERO)
:System.Boolean checkExcludeGameSave()
:System.Boolean checkGameClearData()
:System.Boolean checkRegionCero(share.RegionType, share.CERO)
:System.Boolean checkRegionLoadData()
:System.Boolean checkRegionType(share.RegionType)
:System.Void cleanSaveServiceData()
:System.Void clearExcludeGameSave()
:System.Void collectGameSaveData()
:System.Void collectSystemSaveData()
:System.Void enqueueLoadRequest(System.Int32, share.SaveLoadRequestArgs)
:System.Void enqueueRemoveRequest(System.Int32, share.SaveLoadRequestArgs)
:System.Void enqueueSaveRequest(System.Int32, share.SaveLoadRequestArgs)
:System.Void entryExcludeGameSave(System.Object)
:System.Void entrySuspendGameSave(System.Object)
:System.Void execLoad()
:System.Void execRemove()
:System.Void execSave()
:System.Void exitExcludeGameSave(System.Object)
:System.Void exitSuspendGameSave(System.Object)
:System.Collections.Generic.List`1<System.Int32> getAllCampaignGameSaveSlotNo()
:System.Collections.Generic.List`1<System.Int32> getAllSaveSlotNo()
:System.Collections.Generic.Dictionary`2<share.CampaignIdentifier,System.Collections.Generic.List`1<System.Int32>> getCampaignSlotNo()
:share.SaveDataManager.CursorSaveData getCursorLoadData()
:System.Collections.Generic.List`1<share.AppSaveFileDetail> getSaveFileDetailList(System.Int32, System.Int32)
:System.UInt32 get_CurrentGameSaveValidateDataVersion()
:share.SaveDataManager.Process get_CurrentProcess()
:share.IGameSaveSlotDetailHolder get_GameSaveSlotDetailHolder()
:System.Boolean get_IsBusy()
:System.Boolean get_IsBusyForInteract()
:System.Boolean get_IsProcessing()
:System.Boolean get_IsShowSaveIcon()
:System.Boolean get_IsShowSaveIconTransferring()
:System.Int32 get_LastLoadSlot()
:System.Int32 get_LastLoadSuccessedGameSlot()
:System.Boolean get_LoadedGamedataApplyable()
:share.ISystemSaveSlotDetailHolder get_SystemSaveSlotDetailHolder()
:share.SaveDataManager.CursorSaveData get_TempPlayLoadData()
:System.Boolean isAutoSaveDataIndex(System.Int32)
:System.Boolean isAutoSaving()
:System.Boolean isExcludeGameSave(System.Boolean)
:System.Boolean isExistSaveData(System.Int32)
:System.Boolean isSuspendGameSave()
:System.Boolean isSystemSaveDataIndex(System.Int32)
:System.Void onDestroy()
:System.Void onLeaveIngameCleanup()
:System.Void onStart()
:System.Void onUpdate()
:System.Void registerExcludeGameSaveDelegate(System.Object, System.Func`1<System.Boolean>)
:System.Void registerGameSaveData(share.IGameSaveData)
:System.Void registerGameSaveSlotDetailHolder(share.IGameSaveSlotDetailHolder)
:System.Void registerSaveLoadEventReciever(share.ISaveLoadEventReciever)
:System.Void registerSystemSaveData(share.ISystemSaveData)
:System.Void registerSystemSaveSlotDetailHolder(share.ISystemSaveSlotDetailHolder)
:System.Void remove_OnGameLoadCompleted(System.Action`1<share.GameLoadCompletedEventArgs>)
:System.Void remove_OnGameSaveCompleted(System.Action`1<share.GameSaveCompletedEventArgs>)
:System.Void remove_OnPrepareTimeout(System.Action)
:System.Void remove_OnUpdateInIdle(System.Action)
:System.Void requestExcludeGameSaveInQuit()
:System.Void requestLoadGameData(System.Int32, share.GameLoadRequestArgs)
:System.Void requestLoadSystemData(share.AppSaveSlot, share.SystemLoadRequestArgs)
:System.Void requestRemoveGameData(System.Int32, share.GameRemoveRequestArgs)
:System.Void requestSaveGameData(System.Int32, share.GameSaveRequestArgs)
:System.Void requestSaveSystemData(share.AppSaveSlot, share.SystemSaveRequestArgs)
:System.Void requestStartRemoveGameDataFlow(System.Int32, share.GameRemoveRequestArgs)
:System.Void requestStartSaveGameDataFlow(System.Int32, share.GameSaveRequestArgs)
:System.Void reset()
:System.Void setPlayLoadData(System.Boolean, System.Int32)
:System.Void setPlayLoadData(System.Boolean)
:System.Void set_CurrentProcess(share.SaveDataManager.Process)
:System.Void set_IsShowSaveIconTransferring(System.Boolean)
:System.Void set_LastLoadSlot(System.Int32)
:System.Void set_LastLoadSuccessedGameSlot(System.Int32)
:System.Void set_LoadedGamedataApplyable(System.Boolean)
:System.Void set_TempPlayLoadData(share.SaveDataManager.CursorSaveData)
:System.Void triggerOnTakeOver(share.GameSaveTakeOverArgs)
:System.Void unregisterExcludeGameSaveDelegate(System.Object)
```

## `share.SaveDataManager.CursorSaveData`

```lua
-- fields
IsAutoSaveData: System.Boolean
IsConsentSaved: System.Boolean
IsSaved: System.Boolean
Slot: System.Int32
```

## `share.SaveDataManager.ExcludeGameSaveDelegate`

```lua
-- fields
CantGameSave: System.Func`1<System.Boolean>
Owner: System.Object
```

## `share.SaveDataManager.GameSaveData`

```lua
-- fields
GameSaveDataList: System.Collections.Generic.List`1<share.SaveDataBase>
```

## `share.SaveDataManager.GameSaveValidateData`

```lua
-- fields
CeroType: share.CERO
IsOverPlayGo: System.Boolean
RegionType: share.RegionType
Version: System.UInt32
```

## `share.SaveDataManager.Process`

```lua
-- values (System.Int32 enum)
GameLoadWait
Idle
LoadWait
PreIdle
Processing
RemoveWait
SaveWait
```

## `share.SaveDataManager.Request`

```lua
-- fields
Command: share.SaveDataManager.Request.CommandType
RequestArgs: share.SaveLoadRequestArgs
SlotId: System.Int32
-- methods
:System.Void calcKey()
:share.SaveLoadKey get_GameSaveLoadKey()
:share.SaveLoadKey get_GameSaveLoadValidateKey()
:share.SaveLoadKey get_SystemSaveLoadKey()
:share.SaveLoadKey get_SystemSaveLoadValidateKey()
:System.Void set_GameSaveLoadKey(share.SaveLoadKey)
:System.Void set_GameSaveLoadValidateKey(share.SaveLoadKey)
:System.Void set_SystemSaveLoadKey(share.SaveLoadKey)
:System.Void set_SystemSaveLoadValidateKey(share.SaveLoadKey)
```

## `share.SaveDataManager.Request.CommandType`

```lua
-- values (System.Int32 enum)
Invalid
Load
Remove
Save
```

## `share.SaveDataManager.SystemSaveData`

```lua
-- fields
SystemSaveDataList: System.Collections.Generic.List`1<share.SaveDataBase>
```

## `share.SaveDataManager.SystemSaveValidateData`

```lua
-- fields
CeroType: share.CERO
IsOverPlayGo: System.Boolean
RegionType: share.RegionType
Version: System.UInt32
```

## `share.SaveDataManagerBehavior`

```lua
-- methods
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.SaveDataManagerEnumExtension`

```lua
-- static
:System.String getKeyString(share.SaveLoadKey)
```

## `share.SaveDataUtil`

```lua
-- static
:share.AppSaveSlot getAutoSaveSlot(share.CampaignIdentifier)
:share.CampaignIdentifier getCampaignIdentifier(System.Int32)
:share.AppSaveSlot getCurrentAutoSaveSlot()
:via.storage.saveService.SaveIcon getSaveIcon(System.Int32)
:System.Boolean isAutoSaveSlotIndex(System.Int32)
:System.Boolean isCampaign1011()
:System.Boolean isEnableAccessSaveFileDetailTbl()
```

## `share.SaveLoadKey`

```lua
-- values (System.Int32 enum)
Chainsaw_GameSave_Key
Chainsaw_GameSave_Validate_Key
Chainsaw_SystemSave_Key
Chainsaw_SystemSave_Validate_Key
Highway_GameSave_Key
Highway_GameSave_Validate_Key
Highway_SystemSave_Key
Highway_SystemSave_Validate_Key
Invalid
Share_SystemSave_Key
Share_SystemSave_TransferTest_Key
Share_SystemSave_Validate_Key
```

## `share.SaveLoadProcessResult`

```lua
-- values (System.Int32 enum)
Failed
Invalid
Success
```

## `share.SaveLoadProcessResults`

```lua
-- methods
:share.AppSaveLoadFailedResult get_AppSaveResult()
:share.SaveLoadProcessResult get_ResultType()
:via.storage.saveService.SaveResult get_SaveResult()
:System.Void set_AppSaveResult(share.AppSaveLoadFailedResult)
:System.Void set_ResultType(share.SaveLoadProcessResult)
:System.Void set_SaveResult(via.storage.saveService.SaveResult)
```

## `share.SaveLoadRequestArgs`

```lua
-- fields
OnCheckCollectable: System.Func`1<System.Boolean>
ProcessedEvent: System.Action`1<share.SaveLoadProcessResults>
RequestedEvent: System.Action`1<share.SaveLoadRequestResults>
-- methods
:System.Void add_ProcessedEvent(System.Action`1<share.SaveLoadProcessResults>)
:System.Void add_RequestedEvent(System.Action`1<share.SaveLoadRequestResults>)
:System.Boolean get_IsCollectable()
:System.Void notifyProcessResult(share.SaveLoadProcessResults)
:System.Void notifyRequestResult(share.SaveLoadRequestResults)
:System.Void remove_ProcessedEvent(System.Action`1<share.SaveLoadProcessResults>)
:System.Void remove_RequestedEvent(System.Action`1<share.SaveLoadRequestResults>)
```

## `share.SaveLoadRequestResult`

```lua
-- values (System.Int32 enum)
Failed
Invalid
Success
```

## `share.SaveLoadRequestResults`

```lua
-- methods
:share.SaveLoadRequestResult get_ResultType()
:System.Void set_ResultType(share.SaveLoadRequestResult)
```

## `share.SceneActivateMediator`

```lua
-- fields
EntryProcInterval: System.Int32
EntryProcIntervalTimer: System.Int32
RequestEntryList: System.Collections.Generic.LinkedList`1<share.SceneActivateMediator.Entry>
WorkingEntryList: System.Collections.Generic.List`1<share.SceneActivateMediator.Entry>
_BurstMode: System.Boolean
_RequestLockObject: via.threading.SimpleReaderWriterLock
-- methods
:System.Void FullClean()
:System.Void beginBurstMode()
:System.Boolean checkBurstMode()
:System.Void endBurstMode()
:share.SceneActivateMediator.Entry findEntry(via.Folder)
:System.Int32 getEntryProcIntervalTime()
:share.SceneActivateMediator.Entry getNextProcEntry()
:System.Boolean get_isBusy()
:System.Void requestActivate(via.Folder, System.Action)
:System.Void requestDeactivate(via.Folder, System.Action)
:System.Void resetBurstMode()
:System.Void setInterval(System.Int32)
:System.Void update()
```

## `share.SceneActivateMediator.Entry`

```lua
-- fields
ActivateHandle: System.Action
DeactivateHandle: System.Action
-- methods
:System.Void addActivateHandle(System.Action)
:System.Void addDeactivateHandle(System.Action)
:share.SceneActivateMediator.Entry.Phase get_CurrentPhase()
:share.SceneActivateMediator.Entry.Target get_CurrentTarget()
:via.Folder get_RefFolder()
:System.Boolean isStable()
:System.Void setTarget(share.SceneActivateMediator.Entry.Target)
:System.Void set_CurrentPhase(share.SceneActivateMediator.Entry.Phase)
:System.Void set_CurrentTarget(share.SceneActivateMediator.Entry.Target)
:System.Void set_RefFolder(via.Folder)
:System.Action update()
```

## `share.SceneActivateMediator.Entry.Phase`

```lua
-- values (System.Int32 enum)
Closing
Off
On
Opening
```

## `share.SceneActivateMediator.Entry.Target`

```lua
-- values (System.Int32 enum)
Off
On
```

## `share.SceneFolderController`

```lua
-- fields
CurrentStandbyPriority: System.Int16
DynamicPriorityCalcFunc: System.Func`1<System.Int16>
IsFixedPriority: System.Boolean
LockObject: System.Object
OnActiveHandler: System.Action
OnDeactiveHandler: System.Action
OnReleaseHandler: System.Action
OnStandbyHandler: System.Action
-- methods
:System.Void Activate()
:System.Int16 CalcStandbyPriority()
:System.Void Deactivate()
:System.Void OnActivateFinish()
:System.Void OnDeactivateFinish()
:System.Void OnStandbyFinish()
:System.Void OnTransitActivate(share.SceneFolderController.Phase)
:System.Void OnTransitNone(share.SceneFolderController.Phase)
:System.Void OnTransitStandby(share.SceneFolderController.Phase)
:System.Void Release()
:System.Void SetPriority(System.Int16)
:System.Void SetTarget(share.SceneFolderController.Status)
:System.Void Standby()
:System.Void TransitPhase(share.SceneFolderController.Phase)
:System.Void add_OnActiveHandler(System.Action)
:System.Void add_OnDeactiveHandler(System.Action)
:System.Void add_OnReleaseHandler(System.Action)
:System.Void add_OnStandbyHandler(System.Action)
:System.Void clearActiveHandler()
:System.Void clearDeactiveHandler()
:System.Void clearReleaseHandler()
:System.Void clearStandbyHandler()
:share.SceneFolderController.Phase get_CurrentPhase()
:via.Folder get_TargetFolder()
:share.SceneFolderController.Status get_TargetStatus()
:System.Void initFolderContext(via.Folder)
:System.Void onTransitNoneToStandby(share.SceneFolderController.Phase)
:System.Void remove_OnActiveHandler(System.Action)
:System.Void remove_OnDeactiveHandler(System.Action)
:System.Void remove_OnReleaseHandler(System.Action)
:System.Void remove_OnStandbyHandler(System.Action)
:System.Void set_CurrentPhase(share.SceneFolderController.Phase)
:System.Void set_TargetFolder(via.Folder)
:System.Void set_TargetStatus(share.SceneFolderController.Status)
```

## `share.SceneFolderController.Phase`

```lua
-- values (System.Int32 enum)
Active
ActiveToStandby
Inavlid
None
NoneToStandaby
Standby
StandbyToActive
StandbyToNone
```

## `share.SceneFolderController.PrioritySetMode`

```lua
-- values (System.Int32 enum)
Method
Value
```

## `share.SceneFolderController.Status`

```lua
-- values (System.Int32 enum)
Active
None
Standby
```

## `share.ShareOptionDefine`

```lua
-- fields
INVALID_OPTION_VALUE: System.Int32 [static]
```

## `share.SimpleCompareType`

```lua
-- values (System.Int32 enum)
Equal
NotEqual
```

## `share.Startup`

```lua
-- fields
VolatilizeEvent: System.Action [static]
_FrameHeadActionCount: System.Int32 [static]
_FrameHeadActionList: System.Action[] [static]
-- static
:System.Void Main(System.String[])
:System.Void add_VolatilizeEvent(System.Action)
:System.Void remove_VolatilizeEvent(System.Action)
:System.Void setupSocialSetting()
:System.Void updateOnFrameHead()
```

## `share.StringExtension`

```lua
-- fields
FileExtensionChar: System.Char [static]
FileSeparatorChar: System.Char[] [static]
RandomBase: System.String [static]
-- static
:System.String getFileName(System.String)
:System.String getFileNameWithoutExtension(System.String)
:System.String getFolderName(System.String)
:System.UInt32 hash(System.String)
:System.Boolean isEmpty(System.String)
:System.String random(System.Int32)
```

## `share.SystemLoadRequestArgs`

```lua
-- methods
:share.SaveLoadRequestArgs getCopy()
```

## `share.SystemSaveRequestArgs`

```lua
-- methods
:share.SaveLoadRequestArgs getCopy()
:System.UInt64 getSaveDataSize()
```

## `share.Tag`

```lua
-- fields
TagNameHash: System.Int32[] [static]
-- static
:System.Void buildTagNameHash()
```

## `share.Tag.Bit`

```lua
-- values (System.Int32 enum)
AIMap
Camera
Catalog
Doll
Effect
Enemy
Environment
Event
EventStop
EventStopUpdate
GUI
Gimmick
GmPause
Invalid
Item
Level
PhotoDrawOff
PhotoEnemy
PhotoEnvAnimal
PhotoNPC
PhotoPlayer
Player
Shell
WeaponMerchant
Zone
```

## `share.Tag.List`

```lua
-- values (System.Int32 enum)
AIMap
Camera
Catalog
Doll
Effect
Enemy
Environment
Event
EventStop
EventStopUpdate
GUI
Gimmick
GmPause
Invalid
Item
Level
PhotoDrawOff
PhotoEnemy
PhotoEnvAnimal
PhotoNPC
PhotoPlayer
Player
Shell
WeaponMerchant
Zone
```

## `share.TitleNameType`

```lua
-- values (System.Int32 enum)
BIO
Invalid
RE
```

## `share.TypeExtension`

```lua
-- static
:System.Type[] getBaseTypes(System.Type, System.Boolean)
:System.Type[] getBaseTypes(System.Type, System.Type, System.Boolean)
:System.String[] getSubclassFullNames(System.Type, System.Boolean)
:System.Type[] getSubclassTypes(System.Type, System.Boolean)
:System.Type[] getSubclassTypes(System.Type, System.Type, System.Boolean)
```

## `share.TypeTo`

```lua
-- fields
_HasSetuped: System.Boolean [static]
_IsEnabled: System.Collections.Generic.Dictionary`2<System.UInt32,System.Func`2<via.Component,System.Boolean>> [static]
_SetEnabled: System.Collections.Generic.Dictionary`2<System.UInt32,System.Func`3<via.Component,System.Boolean,System.Boolean>> [static]
-- static
:System.Void appendProcess(System.Type, System.Func`3<via.Component,System.Boolean,System.Boolean>, System.Func`2<via.Component,System.Boolean>)
:System.Func`2<via.Component,System.Boolean> findIsEnabled(System.Type)
:System.Func`3<via.Component,System.Boolean,System.Boolean> findSetEnabled(System.Type)
:System.Boolean isEnabled(via.Component)
:System.Void requestSetup()
:System.Boolean setEnabled(via.Component, System.Boolean)
:System.Void setup()
```

## `share.TypeToHashUserdata`

```lua
-- fields
TypeNames: System.String[]
```

## `share.User`

```lua
-- values (System.Int32 enum)
Invalid
User_00
User_01
User_02
User_03
```

## `share.UserServiceManager`

```lua
-- fields
OnAccountPickerResultHandler: System.Action`1<share.AccountPickerResult>
OnApplicationActivated: System.Action
OnApplicationDeactivated: System.Action
OnApplicationResumed: System.Action
OnApplicationSuspended: System.Action
OnBackgroundExecutionEntered: System.Action
OnBackgroundExecutionReturned: System.Action
OnChangedActiveUserHandler: System.Action
OnLoginUserHandler: System.Action
OnNecessaryActiveUserPairing: System.Action
_AccountPickerPhase: share.UserServiceManager.AccountPickerPhaseType
_ActiveUserIndex: via.UserIndex
-- methods
:System.Void add_OnAccountPickerResultHandler(System.Action`1<share.AccountPickerResult>)
:System.Void add_OnApplicationActivated(System.Action)
:System.Void add_OnApplicationDeactivated(System.Action)
:System.Void add_OnApplicationResumed(System.Action)
:System.Void add_OnApplicationSuspended(System.Action)
:System.Void add_OnBackgroundExecutionEntered(System.Action)
:System.Void add_OnBackgroundExecutionReturned(System.Action)
:System.Void add_OnChangedActiveUserHandler(System.Action)
:System.Void add_OnLoginUserHandler(System.Action)
:System.Void add_OnNecessaryActiveUserPairing(System.Action)
:System.Void applyGuiParam(chainsaw.InGameMenuGuiBehavior.OpenParam)
:System.Void bootAccountCheck()
:System.Void chainsaw.IGuiParameterApplier<chainsaw.InGameMenuGuiBehavior.OpenParam>.applyGuiParam(chainsaw.InGameMenuGuiBehavior.OpenParam)
:via.hid.GamePadDevice getActivePadDevice()
:share.hid.Device getDevice(via.hid.GamePadDevice)
:via.hid.GamePadDevice getLastInputDevice()
:share.UserServiceManager.AccountPickerPhaseType get_AccountPickerPhase()
:via.UserIndex get_ActiveUserIndex()
:System.Int32 get_ActiveUserNativeId()
:System.String get_ActiveUserOnlineAccountNameStr()
:System.Boolean get_DoneActiveUserPairing()
:System.Boolean get_DoneFirstActiveUserPairing()
:System.Boolean get_IsApplicationDeactivated()
:System.Boolean get_IsApplicationSuspended()
:System.Boolean get_IsBackgroundExecution()
:System.Boolean get_IsNecessaryPauseOnBackground()
:System.Boolean get_IsNeedPause()
:System.Boolean get_IsNeedPauseRequest()
:System.Boolean get_IsSystemUiOverlaid()
:System.Boolean get_IsValid()
:System.Boolean get_IsWaitConnectDevice()
:via.UserIndex get_LastActiveUserIndex()
:System.String get_LastActiveUserOnlineAccountNameStr()
:share.UserServiceManager.UserServicePhaseType get__CurrentPhase()
:System.Boolean isEqualActiveUser(via.UserIndex)
:System.Boolean isGuestUser(via.UserIndex)
:System.Boolean isValidUser(via.UserIndex)
:System.Void onApplicationActivated()
:System.Void onApplicationDeactivated()
:System.Void onApplicationResumed()
:System.Void onApplicationSuspended()
:System.Void onAwake()
:System.Void onBackgroundExecutionEntered()
:System.Void onBackgroundExecutionReturned()
:System.Void onCheckInputCloseDialog(chainsaw.DialogDecidedResult)
:System.Void onCheckInputCloseDialog()
:System.Void onDestroy()
:System.Void onStart()
:System.Void onUpdate()
:System.Void onUserLoginEvent(via.UserIndex)
:System.Void registerOnApplicationActivedHandler(System.Action)
:System.Void registerOnApplicationDeactivedHandler(System.Action)
:System.Void registerOnApplicationResumedHandler(System.Action)
:System.Void registerOnApplicationSuspendedHandler(System.Action)
:System.Void registerOnBackgroundExecutionEnteredHandler(System.Action)
:System.Void registerOnBackgroundExecutionReturnedHandler(System.Action)
:System.Void remove_OnAccountPickerResultHandler(System.Action`1<share.AccountPickerResult>)
:System.Void remove_OnApplicationActivated(System.Action)
:System.Void remove_OnApplicationDeactivated(System.Action)
:System.Void remove_OnApplicationResumed(System.Action)
:System.Void remove_OnApplicationSuspended(System.Action)
:System.Void remove_OnBackgroundExecutionEntered(System.Action)
:System.Void remove_OnBackgroundExecutionReturned(System.Action)
:System.Void remove_OnChangedActiveUserHandler(System.Action)
:System.Void remove_OnLoginUserHandler(System.Action)
:System.Void remove_OnNecessaryActiveUserPairing(System.Action)
:System.Void setPairingActiveUserPad(via.hid.GamePadDevice)
:System.Void set_AccountPickerPhase(share.UserServiceManager.AccountPickerPhaseType)
:System.Void set_ActiveUserIndex(via.UserIndex)
:System.Void set_ActiveUserNativeId(System.Int32)
:System.Void set_DoneActiveUserPairing(System.Boolean)
:System.Void set_DoneFirstActiveUserPairing(System.Boolean)
:System.Void set_IsApplicationDeactivated(System.Boolean)
:System.Void set_IsApplicationSuspended(System.Boolean)
:System.Void set_IsBackgroundExecution(System.Boolean)
:System.Void set_IsNeedPause(System.Boolean)
:System.Void set_IsNeedPauseRequest(System.Boolean)
:System.Void set_IsWaitConnectDevice(System.Boolean)
:System.Void set_LastActiveUserIndex(via.UserIndex)
:System.Void set__CurrentPhase(share.UserServiceManager.UserServicePhaseType)
:System.Void setup()
:share.UserServiceManager.ActiveUserPadPairingResultType tryFirstPairingUser()
:share.UserServiceManager.ActiveUserPadPairingResultType tryPairingActiveUserPad()
:System.Void unregisterOnApplicationActivedHandler(System.Action)
:System.Void unregisterOnApplicationDeactivedHandler(System.Action)
:System.Void unregisterOnApplicationResumedHandler(System.Action)
:System.Void unregisterOnApplicationSuspendedHandler(System.Action)
:System.Void unregisterOnBackgroundExecutionEnteredHandler(System.Action)
:System.Void unregisterOnBackgroundExecutionReturnedHandler(System.Action)
:System.Void updateActiveUserPairing()
:System.Void updateNeedPauseStatus()
```

## `share.UserServiceManager.AccountPickerPhaseType`

```lua
-- values (System.Int32 enum)
ChangeUser
CheckAccountPicker
CheckReboot
Initialize
InputCheckRequest
InputChecking
Monitoring
Unset
WaitReboot
```

## `share.UserServiceManager.ActiveUserPadPairingResultType`

```lua
-- values (System.Int32 enum)
NG
NecessaryLastInputDevice
OK
```

## `share.UserServiceManager.UserServicePhaseType`

```lua
-- values (System.Int32 enum)
Normal
Wait
```

## `share.UserServiceManagerBehavior`

```lua
-- methods
:System.Void awake()
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.ValidatedBool`

```lua
-- values (System.Int32 enum)
False
None
True
```

## `share.attribute.GameStateArgumentTypeAttribute`

```lua
-- fields
ArgumentType: System.Type
```

## `share.attribute.PackageBuiltInAttribute`

```lua
-- methods
:System.Boolean get_Enabled()
:System.Void set_Enabled(System.Boolean)
```

## `share.hid.Command`

```lua
-- fields
_AdaptiveTriggerRange_Left: System.Nullable`1<via.Range>
_AdaptiveTriggerRange_Right: System.Nullable`1<via.Range>
_Downs: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>
_Floats: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Single>
_Inhibits: System.Collections.Generic.HashSet`1<System.UInt32>
_Points: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.Point>
_Quaternions: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.Quaternion>
_Releases: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>
_Triggers: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>
_Vec2s: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.vec2>
_Vec3s: System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.vec3>
-- methods
:System.Nullable`1<via.Range> getAdaptiveTriggerRange(via.hid.AdaptiveTriggerMotor)
:System.Single getFloat(System.UInt32)
:System.Single getFloat(System.String)
:via.Point getPoint(System.UInt32)
:via.Point getPoint(System.String)
:via.Quaternion getQuaternion(System.UInt32)
:via.Quaternion getQuaternion(System.String)
:via.vec2 getVec2(System.UInt32)
:via.vec2 getVec2(System.String)
:via.vec3 getVec3(System.UInt32)
:via.vec3 getVec3(System.String)
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,System.Boolean> get_Downs()
:System.Boolean get_Enabled()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,System.Single> get_Floats()
:System.Collections.Generic.List`1<System.UInt32> get_Inhibits()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,via.Point> get_Points()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,via.Quaternion> get_Quaternions()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,System.Boolean> get_Releases()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,System.Boolean> get_Triggers()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,via.vec2> get_Vec2s()
:System.Collections.Generic.IReadOnlyDictionary`2<System.UInt32,via.vec3> get_Vec3s()
:System.Boolean isDown(System.UInt32)
:System.Boolean isDown(System.String)
:System.Boolean isRelease(System.UInt32)
:System.Boolean isRelease(System.String)
:System.Boolean isTrigger(System.UInt32)
:System.Boolean isTrigger(System.String)
:System.Boolean isValidHash(System.UInt32)
:System.Void reset()
:System.Void setInhibit(System.String)
:System.Void setInhibit(System.UInt32)
:System.Void setValue(System.UInt32)
:System.Void setValue(System.UInt32, System.Single)
:System.Void setValue(System.UInt32, via.Point)
:System.Void setValue(System.UInt32, via.vec2)
:System.Void setValue(System.UInt32, via.vec3)
:System.Void setValue(System.UInt32, via.Quaternion)
:System.Void set_Enabled(System.Boolean)
:System.Void update()
:System.Void update(share.hid.KeyAssign, share.hid.User)
:System.Void update(share.hid.ExtraCommand, System.Single)
:System.Void update(share.hid.KeyAssign, share.hid.User, share.hid.ExtraCommand, System.Single)
:System.Void updateAdaptiveTrigger(share.hid.User)
:System.Void updateExtraCommand(share.hid.ExtraCommand, System.Single)
:System.Void updateKeyAssign(share.hid.KeyAssign, share.hid.User)
```

## `share.hid.CommandTag`

```lua
-- values (System.UInt32 enum)
All
Character
Develop
None
System
```

## `share.hid.CommandUtil`

```lua
-- static
:System.Boolean compare(share.hid.ComparisonType, System.UInt32, System.UInt32, System.UInt32)
:System.String[] getSubclassFullNames(System.Type, System.Boolean)
:System.String[] getSubclassNames(System.Type, System.Boolean)
:System.Type[] getSubclassTypes(System.Type, System.Boolean)
:System.Boolean isWithin(System.Single, via.Range, System.Boolean, System.Boolean)
:System.Boolean isWithin(System.Single, via.Range, System.Boolean, System.Boolean, System.Boolean)
:System.Boolean isWithin(System.Single, via.Range, share.hid.ExtraCommand.RangeStatus)
```

## `share.hid.CommandValueType`

```lua
-- values (System.Int32 enum)
Bool
Float
Point
Quaternion
Vec2
Vec3
```

## `share.hid.ComparisonType`

```lua
-- values (System.Int32 enum)
Any
Include
Match
```

## `share.hid.Device`

```lua
-- fields
AxisIntensityThreshold: System.Single [static]
DisplayOrder_Base: System.Int32 [static]
DisplayOrder_Debug: System.Int32 [static]
DisplayOrder_GamePad: System.Int32 [static]
DisplayOrder_GroupEnd: System.Int32 [static]
DisplayOrder_Keyboard: System.Int32 [static]
DisplayOrder_Mouse: System.Int32 [static]
KeyboardKeyToMouseButton: System.Collections.Generic.Dictionary`2<via.hid.KeyboardKey,via.hid.MouseButton> [static]
MaxAdaptiveTriggerMotor: System.Int32 [static]
MousePositionThreshold: System.Single [static]
DragEvent: void__via_hid_DragGestureInfo_
OnChangedDevice: System.Action`2<via.hid.NativeDeviceBase,via.hid.NativeDeviceBase>
PinchInOutEvent: void__via_hid_PinchInOutGestureInfo_
_CurrentAdaptiveTriggerFeedbackParams: share.hid.Device.AdaptiveTriggerFeedbackParameter[]
_NativeDevice: via.hid.NativeDeviceBase
_NativeDevices: System.Collections.Generic.HashSet`1<via.hid.NativeDeviceBase>
_SimpleGesture: share.hid.Device.SimpleGesture
-- methods
:System.Void add_DragEvent(void__via_hid_DragGestureInfo_)
:System.Void add_OnChangedDevice(System.Action`2<via.hid.NativeDeviceBase,via.hid.NativeDeviceBase>)
:System.Void add_PinchInOutEvent(void__via_hid_PinchInOutGestureInfo_)
:via.hid.MouseButton applyOptionMouseButtonReverse(via.hid.MouseButton)
:via.hid.MouseButton applyOptionMouseWheelReverse(via.hid.MouseButton)
:System.Boolean compare(via.hid.GamePadButton, via.hid.GamePadButton, share.CollectType)
:System.Boolean compare(via.hid.MouseButton, via.hid.MouseButton, share.CollectType)
:via.vec2 correctPadAxis(via.vec2, via.vec2, via.hid.DeviceType)
:via.vec2 correctPadAxisCirclizePS(via.vec2, via.vec2, via.hid.DeviceType)
:via.vec2 correctPadAxisCirclizeXB(via.vec2, via.vec2, via.hid.DeviceType)
:share.hid.Device.AdaptiveTriggerFeedbackParameter getAdaptiveTriggerFeedbackParameter(via.hid.AdaptiveTriggerMotor)
:System.Single getMotorPower(via.hid.GamePadMotor)
:System.UInt64 getTouchCount()
:System.Collections.Generic.List`1<via.hid.TouchInfo> getTouchInfo()
:via.hid.TouchInfo getTouchInfo(System.Int32)
:via.vec3 get_Acceleration()
:via.vec3 get_AccelerationLeft()
:via.vec3 get_AccelerationRight()
:System.Collections.Generic.Dictionary`2<via.hid.AdaptiveTriggerMotor,share.hid.Device.AdaptiveTriggerFeedbackParameter> get_AdaptiveTriggerFeedbackParams()
:System.Single get_AnalogL()
:share.hid.GamePadAnalog get_AnalogLeft()
:System.Single get_AnalogR()
:share.hid.GamePadAnalog get_AnalogRight()
:via.vec3 get_AngularVelocity()
:via.vec3 get_AngularVelocityLeft()
:via.vec3 get_AngularVelocityRight()
:System.Collections.Generic.HashSet`1<via.hid.AdaptiveTriggerMotor> get_ApplyAdaptiveTriggerFeedbackMotors()
:System.Nullable`1<System.Single> get_AxisAngleL()
:System.Nullable`1<System.Single> get_AxisAngleR()
:System.Single get_AxisIntensityL()
:System.Single get_AxisIntensityR()
:via.vec2 get_AxisL()
:System.Boolean get_AxisOnL()
:System.Boolean get_AxisOnR()
:via.vec2 get_AxisR()
:System.Boolean get_AxisReleaseL()
:System.Boolean get_AxisReleaseR()
:System.Boolean get_AxisTriggerL()
:System.Boolean get_AxisTriggerR()
:System.Single get_DeltaDistance()
:via.hid.DeviceIndex get_DeviceIndex()
:via.hid.DeviceKind get_DeviceKind()
:via.hid.DeviceKindDetails get_DeviceKindDetails()
:via.hid.DeviceType get_DeviceType()
:System.Boolean get_EnabledDevice()
:via.hid.GamePadButton get_GamePadButtonDown()
:via.hid.GamePadButton get_GamePadButtonRelease()
:via.hid.GamePadButton get_GamePadButtonRepeat()
:via.hid.GamePadButton get_GamePadButtonTrigger()
:via.hid.GestureManager get_GestureManager()
:System.Boolean get_IsDualSenseDevice()
:System.Boolean get_IsGamePadDevice()
:System.Boolean get_IsKeyboardDevice()
:System.Boolean get_IsMouseDevice()
:System.Boolean get_IsPSGamePadDevice()
:System.Boolean get_Merged()
:System.Single get_MotorPower()
:via.hid.MouseButton get_MouseButtonDown()
:via.hid.MouseButton get_MouseButtonRelease()
:via.hid.MouseButton get_MouseButtonRepeat()
:via.hid.MouseButton get_MouseButtonTrigger()
:via.Point get_MovePosition()
:via.hid.NativeDeviceBase get_NativeDevice()
:via.Quaternion get_Orientation()
:via.Quaternion get_OrientationLeft()
:via.Quaternion get_OrientationRight()
:via.Point get_Position()
:via.vec3 get_PositionLeft()
:via.vec3 get_PositionRight()
:System.Nullable`1<System.Single> get_RawAxisAngleL()
:System.Nullable`1<System.Single> get_RawAxisAngleR()
:System.Single get_RawAxisIntensityL()
:System.Single get_RawAxisIntensityR()
:via.vec2 get_RawAxisL()
:via.vec2 get_RawAxisR()
:via.Point get_RawMovePosition()
:System.Boolean get_RemotePlay()
:share.hid.GamePadStick get_StickLeft()
:share.hid.GamePadStick get_StickRight()
:System.UInt64 get_UniqueId()
:share.hid.User get_User()
:via.UserIndex get_UserIndex()
:System.Boolean get_ValidDevice()
:System.Boolean get_VitaRemotePlay()
:System.Single get_Wheel()
:System.Single get_WheelDelta()
:System.Boolean isAnyInput(via.hid.MouseDevice, System.Boolean)
:System.Boolean isAnyInput(via.hid.KeyboardDevice)
:System.Boolean isDown(via.hid.GamePadButton, share.CollectType, via.hid.GamePadButton)
:System.Boolean isDown(via.hid.MouseButton, share.CollectType)
:System.Boolean isDown(via.hid.KeyboardKey)
:System.Boolean isRelease(via.hid.GamePadButton, share.CollectType, via.hid.GamePadButton)
:System.Boolean isRelease(via.hid.MouseButton, share.CollectType)
:System.Boolean isRelease(via.hid.KeyboardKey)
:System.Boolean isRepeat(via.hid.GamePadButton, share.CollectType, via.hid.GamePadButton)
:System.Boolean isRepeat(via.hid.MouseButton, share.CollectType)
:System.Boolean isRepeat(via.hid.KeyboardKey)
:System.Boolean isTrigger(via.hid.GamePadButton, share.CollectType, via.hid.GamePadButton)
:System.Boolean isTrigger(via.hid.MouseButton, share.CollectType)
:System.Boolean isTrigger(via.hid.KeyboardKey)
:System.Void onChangedDevice()
:System.Void onDestroy()
:System.Void onDrag(via.hid.DragGestureInfo)
:System.Void onPinchInOut(via.hid.PinchInOutGestureInfo)
:System.Void remove_DragEvent(void__via_hid_DragGestureInfo_)
:System.Void remove_OnChangedDevice(System.Action`2<via.hid.NativeDeviceBase,via.hid.NativeDeviceBase>)
:System.Void remove_PinchInOutEvent(void__via_hid_PinchInOutGestureInfo_)
:System.Boolean resetAdaptiveTriggerFeedback()
:System.Boolean resetLightBarColor()
:System.Boolean resetMotorPower()
:System.Boolean resetOrientation()
:System.Void resetParam()
:System.Boolean setAdaptiveTriggerFeedback(via.hid.AdaptiveTriggerMotor, System.Single, System.Single, System.Single, System.Single)
:System.Boolean setAdaptiveTriggerFeedback(via.hid.AdaptiveTriggerMotor, share.hid.Device.AdaptiveTriggerFeedbackParameter)
:System.Boolean setLightBarColor(via.Color)
:System.Boolean setMotorPower(System.Single, via.hid.GamePadMotor)
:System.Void set_Acceleration(via.vec3)
:System.Void set_AccelerationLeft(via.vec3)
:System.Void set_AccelerationRight(via.vec3)
:System.Void set_AdaptiveTriggerFeedbackParams(System.Collections.Generic.Dictionary`2<via.hid.AdaptiveTriggerMotor,share.hid.Device.AdaptiveTriggerFeedbackParameter>)
:System.Void set_AnalogLeft(share.hid.GamePadAnalog)
:System.Void set_AnalogRight(share.hid.GamePadAnalog)
:System.Void set_AngularVelocity(via.vec3)
:System.Void set_AngularVelocityLeft(via.vec3)
:System.Void set_AngularVelocityRight(via.vec3)
:System.Void set_ApplyAdaptiveTriggerFeedbackMotors(System.Collections.Generic.HashSet`1<via.hid.AdaptiveTriggerMotor>)
:System.Void set_GamePadButtonDown(via.hid.GamePadButton)
:System.Void set_GamePadButtonRelease(via.hid.GamePadButton)
:System.Void set_GamePadButtonRepeat(via.hid.GamePadButton)
:System.Void set_GamePadButtonTrigger(via.hid.GamePadButton)
:System.Void set_GestureManager(via.hid.GestureManager)
:System.Void set_IsDualSenseDevice(System.Boolean)
:System.Void set_IsGamePadDevice(System.Boolean)
:System.Void set_IsKeyboardDevice(System.Boolean)
:System.Void set_IsMouseDevice(System.Boolean)
:System.Void set_IsPSGamePadDevice(System.Boolean)
:System.Void set_MotorPower(System.Single)
:System.Void set_MouseButtonDown(via.hid.MouseButton)
:System.Void set_MouseButtonRelease(via.hid.MouseButton)
:System.Void set_MouseButtonRepeat(via.hid.MouseButton)
:System.Void set_MouseButtonTrigger(via.hid.MouseButton)
:System.Void set_MovePosition(via.Point)
:System.Void set_NativeDevice(via.hid.NativeDeviceBase)
:System.Void set_Orientation(via.Quaternion)
:System.Void set_OrientationLeft(via.Quaternion)
:System.Void set_OrientationRight(via.Quaternion)
:System.Void set_Position(via.Point)
:System.Void set_PositionLeft(via.vec3)
:System.Void set_PositionRight(via.vec3)
:System.Void set_RawMovePosition(via.Point)
:System.Void set_StickLeft(share.hid.GamePadStick)
:System.Void set_StickRight(share.hid.GamePadStick)
:System.Void set_User(share.hid.User)
:System.Void set_Wheel(System.Single)
:System.Void set_WheelDelta(System.Single)
:System.Void setup(share.hid.User)
:System.Void update()
:System.Void updateCurrentAdaptiveTriggerFeedbackParam(via.hid.AdaptiveTriggerMotor, share.hid.Device.AdaptiveTriggerFeedbackParameter)
-- static
:System.Boolean isAnyInput(via.hid.GamePadDevice)
:System.Boolean isAnyTrigger(via.hid.GamePadDevice)
```

## `share.hid.Device.AdaptiveTriggerFeedbackParameter`

```lua
-- methods
:System.Single get_EndPos()
:System.Single get_Frequency()
:System.Single get_Power()
:System.Single get_StartPos()
:System.Void set_EndPos(System.Single)
:System.Void set_Frequency(System.Single)
:System.Void set_Power(System.Single)
:System.Void set_StartPos(System.Single)
```

## `share.hid.Device.SimpleGesture`

```lua
-- fields
MaxDragInfo: System.Int32 [static]
DragInfos: via.hid.DragGestureInfo[]
PinchInOutInfo: via.hid.PinchInOutGestureInfo
-- methods
:System.Void clear()
:System.Void setDragInfo(via.hid.TouchInfo, System.Int32)
:System.Void update(share.hid.Device)
:System.Void updateDrag(share.hid.Device, via.hid.PSGamePadDevice)
:System.Void updatePintchInOut(share.hid.Device, via.hid.PSGamePadDevice)
```

## `share.hid.DeviceSystem`

```lua
-- fields
OnChangedActiveCommandTag: System.Action`1<share.hid.CommandTag>
_ActiveCommand: share.hid.CommandTag
-- methods
:System.Boolean <get_LastInputFreeGamePadDevice>b__21_0(via.hid.GamePadDevice)
:System.Collections.Generic.List`1<share.hid.Device> GetDeviceList(share.hid.User)
:System.Void add_OnChangedActiveCommandTag(System.Action`1<share.hid.CommandTag>)
:System.Void awake(via.Prefab)
:System.Void createDevice(share.hid.User)
:System.Void entryDelegate()
:System.Boolean entryDevice(share.hid.Device)
:System.Void exitDelegate()
:System.Boolean exitDevice(share.hid.User)
:System.Boolean exitDevice(share.hid.Device)
:share.hid.Device getDevice(share.hid.User)
:System.Collections.Generic.List`1<share.hid.Device> getDevices(via.hid.DeviceKind)
:share.hid.Device getGamePadDevice(share.hid.User)
:via.hid.GamePadDevice getGamePadNativeDevice(share.hid.User)
:share.hid.Device getKeyboardDevice()
:via.hid.KeyboardDevice getKeyboardNativeDevice()
:share.hid.Device getMouseDevice()
:via.hid.MouseDevice getMouseNativeDevice()
:share.hid.CommandTag get_ActiveCommand()
:System.Collections.Generic.Dictionary`2<share.hid.User,System.Collections.Generic.List`1<share.hid.Device>> get_Devices()
:share.hid.InputMode get_HIDInputMode()
:System.Boolean get_IsInputMouseBack()
:System.Boolean get_IsInputMouseCamera()
:System.Boolean get_IsInputMouseCameraNoCheck()
:via.hid.GamePadDevice get_LastInputFreeGamePadDevice()
:via.hid.GamePadDevice get_LastInputGamePadDevice()
:System.Collections.Generic.LinkedList`1<via.hid.GamePadDevice> get_LastInputGamePadDevices()
:System.Collections.Generic.List`1<share.hid.DeviceSystem.LinkRequest> get_LinkRequests()
:share.PrefabController get_Prefab()
:chainsaw.KeyBindManager get__KeyBindManager()
:System.Boolean get_isAnyInputKeyboardMouse()
:System.Boolean get_isEnableKeyboardMouseInput()
:System.Boolean get_isEnableOperateKeyboardMouse()
:System.Boolean get_isEventSkipInputKeyboardMouse()
:System.Boolean linkDevice(share.hid.User, via.hid.NativeDeviceBase)
:System.Boolean linkDevice(share.hid.Device, via.hid.NativeDeviceBase)
:System.Void onApplicationDeactivated()
:System.Void onBackgroundExecutionEnterd()
:System.Void onChangedActiveCommandTag(share.hid.CommandTag)
:System.Void onDestroy()
:System.Void onDeviceConnectedEvent(via.hid.NativeDeviceBase)
:System.Void onDeviceDisconnectedEvent(via.hid.NativeDeviceBase)
:System.Void onGamePadConnectedEvent(via.hid.GamePadDevice)
:System.Void onGamePadDisconnectedEvent(via.hid.GamePadDevice)
:System.Void onKeyboardConnectedEvent(via.hid.KeyboardDevice)
:System.Void onKeyboardDisconnectedEvent(via.hid.KeyboardDevice)
:System.Void onMouseConnectedEvent(via.hid.MouseDevice)
:System.Void onMouseDisconnectedEvent(via.hid.MouseDevice)
:System.Void onSystemUiOverlaid()
:System.Void remove_OnChangedActiveCommandTag(System.Action`1<share.hid.CommandTag>)
:System.Void requestLinkDevice(share.hid.Device, via.hid.NativeDeviceBase)
:System.Void set_ActiveCommand(share.hid.CommandTag)
:System.Void set_Devices(System.Collections.Generic.Dictionary`2<share.hid.User,System.Collections.Generic.List`1<share.hid.Device>>)
:System.Void set_HIDInputMode(share.hid.InputMode)
:System.Void set_LinkRequests(System.Collections.Generic.List`1<share.hid.DeviceSystem.LinkRequest>)
:System.Void set_Prefab(share.PrefabController)
:System.Void setupPrefab(via.Prefab)
:System.Void start()
:System.Boolean tryGetDevice(share.hid.User, share.hid.Device)
:System.Boolean tryGetDevice(via.hid.NativeDeviceBase, share.hid.Device)
:System.Boolean tryGetFreeDevice(share.hid.Device)
:System.Void unlinkDevice(via.hid.NativeDeviceBase)
:System.Void unlinkDevice(share.hid.Device)
:System.Void update()
-- static
:System.Int32 get_MaxDeviceNumber()
```

## `share.hid.DeviceSystem.LinkRequest`

```lua
-- methods
:System.Boolean execute()
:System.Boolean get_Completed()
:via.hid.NativeDeviceBase get_NativeDevice()
:share.hid.User get_User()
:System.Void set_Completed(System.Boolean)
:System.Void set_NativeDevice(via.hid.NativeDeviceBase)
:System.Void set_User(share.hid.User)
```

## `share.hid.DeviceSystemBehavior`

```lua
-- fields
_Prefab: via.Prefab
-- methods
:System.Void awake()
:via.Prefab get_Prefab()
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.hid.ElementDeviceKind`

```lua
-- values (System.Int32 enum)
KindGamePad
KindKeyboard
KindMouse
```

## `share.hid.ExtraCommand`

```lua
-- methods
:System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity> get_Entities()
:System.Void set_Entities(System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity>)
:System.Void setup(share.hid.ExtraCommand.Entity.Parameter[])
:System.Void setup(System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity.Parameter>)
:System.Void setup(share.hid.ExtraCommandUserData)
:System.Void update(share.hid.Command, System.Single)
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement`

```lua
-- fields
_CheckType: share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType
-- methods
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType`

```lua
-- values (System.Int32 enum)
End_L
End_R
Start_L
Start_R
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.Parameter`

```lua
-- fields
_CheckType: share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType get_CheckType()
```

## `share.hid.ExtraCommand.BoolStatus`

```lua
-- values (System.Int32 enum)
Off
On
Release
Trigger
```

## `share.hid.ExtraCommand.BoolStatusElement`

```lua
-- methods
:System.Boolean evaluate(share.hid.Command)
:share.hid.ExtraCommand.BoolStatus get_BoolStatus()
:System.Void set_BoolStatus(share.hid.ExtraCommand.BoolStatus)
```

## `share.hid.ExtraCommand.BoolStatusElement.Parameter`

```lua
-- fields
DisplayOrder_Command: System.Int32 [static]
_BoolStatus: share.hid.ExtraCommand.BoolStatus
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.BoolStatus get_BoolStatus()
:System.Boolean get_EnabledHoldTime()
```

## `share.hid.ExtraCommand.CombinationElement`

```lua
-- methods
:share.hid.ExtraCommand.CombinationType get_CombinationType()
:System.Collections.Generic.List`1<share.hid.ExtraCommand.Element> get_Elements()
:System.Int32 get_ExecuteIndex()
:System.Boolean get_IsCombinationOrder()
:System.Void reset()
:System.Void set_CombinationType(share.hid.ExtraCommand.CombinationType)
:System.Void set_Elements(System.Collections.Generic.List`1<share.hid.ExtraCommand.Element>)
:System.Void set_ExecuteIndex(System.Int32)
:System.Void update(share.hid.Command, System.Single)
:System.Void updateAny(share.hid.Command, System.Single)
:System.Void updateInclude(share.hid.Command, System.Single)
:System.Void updateOrder(share.hid.Command, System.Single)
```

## `share.hid.ExtraCommand.CombinationElement.Parameter`

```lua
-- fields
_CombinationType: share.hid.ExtraCommand.CombinationType
_ElementParams: share.hid.ExtraCommand.Element.Parameter[]
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.CombinationType get_CombinationType()
:System.String get_DisplayName()
:share.hid.ExtraCommand.Element.Parameter[] get_ElementParams()
```

## `share.hid.ExtraCommand.CombinationType`

```lua
-- values (System.Int32 enum)
Any
Include
Order
```

## `share.hid.ExtraCommand.CommandElement`

```lua
-- fields
_Name: System.String
-- methods
:System.Single get_ExtendTime()
:System.Single get_ExtendTimer()
:System.UInt32 get_Hash()
:System.Single get_HoldTime()
:System.Single get_HoldTimer()
:System.String get_Name()
:System.Void reset()
:System.Void set_ExtendTime(System.Single)
:System.Void set_ExtendTimer(System.Single)
:System.Void set_Hash(System.UInt32)
:System.Void set_HoldTime(System.Single)
:System.Void set_HoldTimer(System.Single)
:System.Void set_Name(System.String)
:System.Void update(share.hid.Command, System.Single)
```

## `share.hid.ExtraCommand.CommandElement.Parameter`

```lua
-- fields
DisplayOrder_Command: System.Int32 [static]
_ExtendTime: System.Single
_HoldTime: System.Single
_Name: System.String
-- methods
:System.String ToString()
:System.Single get_ExtendTime()
:System.Single get_HoldTime()
:System.String get_Name()
```

## `share.hid.ExtraCommand.Element`

```lua
-- methods
:System.String ToString()
:System.String get_Description()
:System.String get_DisplayName()
:System.String get_ElementName()
:share.hid.ExtraCommand.ElementStatus get_ElementStatus()
:System.Void reset()
:System.Void set_ElementName(System.String)
:System.Void set_ElementStatus(share.hid.ExtraCommand.ElementStatus)
```

## `share.hid.ExtraCommand.Element.Parameter`

```lua
-- methods
:System.String ToString()
:System.String get_DisplayName()
```

## `share.hid.ExtraCommand.ElementStatus`

```lua
-- values (System.Int32 enum)
Failure
Success
Unsettled
```

## `share.hid.ExtraCommand.Entity`

```lua
-- fields
_Name: System.String
-- methods
:System.String get_DisplayName()
:share.hid.ExtraCommand.CombinationElement get_Element()
:System.UInt32 get_Hash()
:System.String get_Name()
:System.Void set_Element(share.hid.ExtraCommand.CombinationElement)
:System.Void set_Hash(System.UInt32)
:System.Void set_Name(System.String)
:System.Boolean update(share.hid.Command, System.Single)
```

## `share.hid.ExtraCommand.Entity.Parameter`

```lua
-- fields
_ElementParam: share.hid.ExtraCommand.CombinationElement.Parameter
_Name: System.String
-- methods
:System.String get_DisplayName()
:share.hid.ExtraCommand.CombinationElement.Parameter get_ElementParam()
:System.String get_Name()
```

## `share.hid.ExtraCommand.FloatIntensityElement`

```lua
-- methods
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.FloatIntensityElement.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
```

## `share.hid.ExtraCommand.IntensityElement`

```lua
-- methods
:System.Boolean evaluateIntensity(System.Single)
:System.Single get_Intensity()
:share.hid.ExtraCommand.IntensityType get_IntensityStatus()
:System.Void set_Intensity(System.Single)
:System.Void set_IntensityStatus(share.hid.ExtraCommand.IntensityType)
```

## `share.hid.ExtraCommand.IntensityElement.Parameter`

```lua
-- fields
_Intensity: System.Single
_IntensityStatus: share.hid.ExtraCommand.IntensityType
-- methods
:System.Single get_Intensity()
:share.hid.ExtraCommand.IntensityType get_IntensityStatus()
```

## `share.hid.ExtraCommand.IntensityType`

```lua
-- values (System.Int32 enum)
Eq
Ge
Gt
Le
Lt
```

## `share.hid.ExtraCommand.RangeStatus`

```lua
-- values (System.UInt32 enum)
IncludeMax
IncludeMin
None
Outside
```

## `share.hid.ExtraCommand.Vec2AngleElement`

```lua
-- methods
:System.Boolean evaluate(share.hid.Command)
:via.Range get_Angle()
:share.hid.ExtraCommand.RangeStatus get_RangeStatus()
:System.Void set_Angle(via.Range)
:System.Void set_RangeStatus(share.hid.ExtraCommand.RangeStatus)
```

## `share.hid.ExtraCommand.Vec2AngleElement.Parameter`

```lua
-- fields
_Angle: via.Range
_RangeStatus: share.hid.ExtraCommand.RangeStatus
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:via.Range get_Angle()
:share.hid.ExtraCommand.RangeStatus get_RangeStatus()
```

## `share.hid.ExtraCommand.Vec2IntensityElement`

```lua
-- methods
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.Vec2IntensityElement.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
```

## `share.hid.ExtraCommandUserData`

```lua
-- fields
_Params: share.hid.ExtraCommand.Entity.Parameter[]
-- methods
:share.hid.ExtraCommand.Entity.Parameter[] get_Params()
```

## `share.hid.GamePadAnalog`

```lua
-- fields
_Intensity: System.Single
-- methods
:System.Single get_Intensity()
:System.Single get_PrevIntensity()
:System.Void initialize()
:System.Void set_Intensity(System.Single)
:System.Void set_PrevIntensity(System.Single)
:System.Void update(System.Single)
```

## `share.hid.GamePadStick`

```lua
-- fields
_Axis: via.vec2
_RawAxis: via.vec2
-- methods
:System.Nullable`1<System.Single> get_Angle()
:via.vec2 get_Axis()
:System.Single get_Intensity()
:System.Boolean get_On()
:System.Nullable`1<System.Single> get_PrevAngle()
:via.vec2 get_PrevAxis()
:System.Single get_PrevIntensity()
:System.Nullable`1<System.Single> get_PrevRawAngle()
:via.vec2 get_PrevRawAxis()
:System.Single get_PrevRawIntensity()
:System.Nullable`1<System.Single> get_RawAngle()
:via.vec2 get_RawAxis()
:System.Single get_RawIntensity()
:System.Boolean get_Release()
:System.Boolean get_Trigger()
:System.Void initialize()
:System.Void set_Angle(System.Nullable`1<System.Single>)
:System.Void set_Axis(via.vec2)
:System.Void set_Intensity(System.Single)
:System.Void set_On(System.Boolean)
:System.Void set_PrevAngle(System.Nullable`1<System.Single>)
:System.Void set_PrevAxis(via.vec2)
:System.Void set_PrevIntensity(System.Single)
:System.Void set_PrevRawAngle(System.Nullable`1<System.Single>)
:System.Void set_PrevRawAxis(via.vec2)
:System.Void set_PrevRawIntensity(System.Single)
:System.Void set_RawAngle(System.Nullable`1<System.Single>)
:System.Void set_RawAxis(via.vec2)
:System.Void set_RawIntensity(System.Single)
:System.Void set_Release(System.Boolean)
:System.Void set_Trigger(System.Boolean)
:System.Void update(via.vec2, via.vec2)
```

## `share.hid.InputMode`

```lua
-- values (System.Int32 enum)
GamePad
KeyboardMouse
Unknown
```

## `share.hid.KeyAssign`

```lua
-- methods
:System.Boolean getBool(System.UInt32, share.hid.Device)
:System.Boolean getBool(System.String, share.hid.Device)
:System.Single getFloat(System.UInt32, share.hid.Device)
:System.Single getFloat(System.String, share.hid.Device)
:via.Quaternion getQuaternion(System.UInt32, share.hid.Device)
:via.Quaternion getQuaternion(System.String, share.hid.Device)
:via.vec2 getVec2(System.UInt32, share.hid.Device)
:via.vec2 getVec2(System.String, share.hid.Device)
:via.vec3 getVec3(System.UInt32, share.hid.Device)
:via.vec3 getVec3(System.String, share.hid.Device)
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.BoolElement>> get_BoolElementDictionary()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.FloatElement>> get_FloatElementDictionary()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.PointElement>> get_PointElementDictionary()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.QuaternionElement>> get_QuaternionElementDictionary()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec2Element>> get_Vec2ElementDictionary()
:System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec3Element>> get_Vec3ElementDictionary()
:System.Void set_BoolElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.BoolElement>>)
:System.Void set_FloatElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.FloatElement>>)
:System.Void set_PointElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.PointElement>>)
:System.Void set_QuaternionElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.QuaternionElement>>)
:System.Void set_Vec2ElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec2Element>>)
:System.Void set_Vec3ElementDictionary(System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec3Element>>)
:System.Void setup(share.hid.KeyAssign.Parameter[])
:System.Void setup(System.Collections.Generic.List`1<share.hid.KeyAssign.Parameter>)
:System.Void setup(share.hid.KeyAssignUserData)
:System.Void update(share.hid.Device, share.hid.Command)
-- static
:System.UInt32 makeHash(System.String)
```

## `share.hid.KeyAssign.BoolElement`

```lua
-- methods
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
:System.Void set_ComparisonType(share.hid.ComparisonType)
-- static
:System.Boolean merge(System.Collections.Generic.List`1<System.Boolean>)
:System.Boolean merge(System.Collections.Generic.List`1<share.hid.KeyAssign.BoolElement>, share.hid.Device)
```

## `share.hid.KeyAssign.BoolElement.Parameter`

```lua
-- fields
_ComparisonType: share.hid.ComparisonType
-- methods
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
```

## `share.hid.KeyAssign.Element`

```lua
-- fields
MergeListCapacity: System.Int32 [static]
-- methods
:System.String get_Description()
:System.String get_DisplayName()
:System.String get_ElementName()
:System.Void set_ElementName(System.String)
```

## `share.hid.KeyAssign.Element.Parameter`

```lua
-- methods
:System.String ToString()
:System.String get_DisplayName()
```

## `share.hid.KeyAssign.FloatElement`

```lua
-- methods
:System.Collections.Generic.List`1<System.Single> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<System.Single>)
-- static
:System.Single merge(System.Collections.Generic.List`1<System.Single>)
:System.Single merge(System.Single, System.Single)
:System.Single merge(System.Collections.Generic.List`1<share.hid.KeyAssign.FloatElement>, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadButtonElement`

```lua
-- methods
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:via.hid.GamePadButton get_Scope()
:via.hid.GamePadButton get_Target()
:System.Void set_Scope(via.hid.GamePadButton)
:System.Void set_Target(via.hid.GamePadButton)
-- static
:System.String convertString(share.hid.ComparisonType, via.hid.GamePadButton, via.hid.GamePadButton)
```

## `share.hid.KeyAssign.GamePadButtonElement.Parameter`

```lua
-- fields
_Scope: via.hid.GamePadButton
_Target: via.hid.GamePadButton
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.GamePadButton get_Scope()
:via.hid.GamePadButton get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadFloat`

```lua
-- values (System.UInt32 enum)
AngularVelocityX
AngularVelocityY
AngularVelocityZ
LStickH
LStickIntensity
LStickV
LTrigBottom
None
RStickH
RStickIntensity
RStickV
RTrigBottom
```

## `share.hid.KeyAssign.GamePadFloatElement`

```lua
-- methods
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadFloat, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadFloat>)
:System.Single getValue(share.hid.KeyAssign.GamePadFloat, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadFloatElement.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadQuaternion`

```lua
-- values (System.UInt32 enum)
None
Orientation
OrientationLeft
OrientationRight
```

## `share.hid.KeyAssign.GamePadQuaternionElement`

```lua
-- fields
EnumValues: share.hid.KeyAssign.GamePadQuaternion[] [static]
-- methods
:System.String ToString()
:via.Quaternion getValue(share.hid.Device)
:share.hid.KeyAssign.GamePadQuaternion get_Target()
:System.Void set_Target(share.hid.KeyAssign.GamePadQuaternion)
-- static
:via.Quaternion getValue(share.hid.KeyAssign.GamePadQuaternion, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadQuaternionElement.Parameter`

```lua
-- fields
_Target: share.hid.KeyAssign.GamePadQuaternion
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:share.hid.KeyAssign.GamePadQuaternion get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadVec2`

```lua
-- values (System.UInt32 enum)
LStick
None
RStick
Touch_Primary
Touch_Secondary
```

## `share.hid.KeyAssign.GamePadVec2Element`

```lua
-- methods
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadVec2, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadVec2>)
:via.vec2 getValue(share.hid.KeyAssign.GamePadVec2, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadVec2Element.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadVec3`

```lua
-- values (System.UInt32 enum)
Acceleration
AccelerationLeft
AccelerationRight
AngularVelocity
AngularVelocityLeft
AngularVelocityRight
LStickDirection
None
PositionLeft
PositionRight
RStickDirection
```

## `share.hid.KeyAssign.GamePadVec3Element`

```lua
-- methods
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadVec3, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadVec3>)
:via.vec3 getValue(share.hid.KeyAssign.GamePadVec3, share.hid.Device)
-- static
:via.vec3 convertAxisToDirection(via.vec2)
```

## `share.hid.KeyAssign.GamePadVec3Element.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyBindKeyElement`

```lua
-- methods
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Scope()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Target()
:System.Void set_Scope(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
-- static
:System.String convertString(share.hid.ComparisonType, chainsaw.KeyBindCommandType[], chainsaw.KeyBindCommandType[])
:System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

## `share.hid.KeyAssign.KeyBindKeyElement.Parameter`

```lua
-- fields
_Scope: chainsaw.KeyBindCommandType[]
_Target: chainsaw.KeyBindCommandType[]
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:chainsaw.KeyBindCommandType[] get_Scope()
:chainsaw.KeyBindCommandType[] get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyBindKeyFloatElement`

```lua
-- methods
:System.String ToString()
:System.Single getValue(share.hid.Device)
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Scope()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Target()
:System.Void set_ComparisonType(share.hid.ComparisonType)
:System.Void set_Scope(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
-- static
:System.String convertString(share.hid.ComparisonType, chainsaw.KeyBindCommandType[], chainsaw.KeyBindCommandType[])
:System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

## `share.hid.KeyAssign.KeyBindKeyFloatElement.Parameter`

```lua
-- fields
_ComparisonType: share.hid.ComparisonType
_Scope: chainsaw.KeyBindCommandType[]
_Target: chainsaw.KeyBindCommandType[]
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:share.hid.ComparisonType get_ComparisonType()
:System.String get_DisplayName()
:System.Boolean get_IsMatch()
:chainsaw.KeyBindCommandType[] get_Scope()
:chainsaw.KeyBindCommandType[] get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyBindKeyVec2Element`

```lua
-- methods
:System.String ToString()
:via.vec2 getValue(share.hid.Device)
```

## `share.hid.KeyAssign.KeyBindKeyVec2Element.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyboardKeyElement`

```lua
-- methods
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> get_Scope()
:System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> get_Target()
:System.Void set_Scope(System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
-- static
:System.String convertString(share.hid.ComparisonType, via.hid.KeyboardKey[], via.hid.KeyboardKey[])
:System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>, System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
```

## `share.hid.KeyAssign.KeyboardKeyElement.Parameter`

```lua
-- fields
_Scope: via.hid.KeyboardKey[]
_Target: via.hid.KeyboardKey[]
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.KeyboardKey[] get_Scope()
:via.hid.KeyboardKey[] get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyboardKeyVec2Element`

```lua
-- methods
:System.String ToString()
:via.vec2 getValue(share.hid.Device)
```

## `share.hid.KeyAssign.KeyboardKeyVec2Element.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseButtonElement`

```lua
-- methods
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:via.hid.MouseButton get_Scope()
:via.hid.MouseButton get_Target()
:System.Void set_Scope(via.hid.MouseButton)
:System.Void set_Target(via.hid.MouseButton)
-- static
:System.String convertString(share.hid.ComparisonType, via.hid.MouseButton, via.hid.MouseButton)
```

## `share.hid.KeyAssign.MouseButtonElement.Parameter`

```lua
-- fields
_Scope: via.hid.MouseButton
_Target: via.hid.MouseButton
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.MouseButton get_Scope()
:via.hid.MouseButton get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseFloat`

```lua
-- values (System.UInt32 enum)
DeltaDistance
DeltaWheel
MovePositionH
MovePositionV
None
PositionH
PositionV
Wheel
```

## `share.hid.KeyAssign.MouseFloatElement`

```lua
-- methods
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.MouseFloat, System.Collections.Generic.List`1<share.hid.KeyAssign.MouseFloat>)
:System.Single getValue(share.hid.KeyAssign.MouseFloat, share.hid.Device)
```

## `share.hid.KeyAssign.MouseFloatElement.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MousePoint`

```lua
-- values (System.UInt32 enum)
MovePosition
None
Position
```

## `share.hid.KeyAssign.MousePointElement`

```lua
-- fields
EnumValues: share.hid.KeyAssign.MousePoint[] [static]
-- methods
:System.String ToString()
:via.Point getValue(share.hid.Device)
:share.hid.KeyAssign.MousePoint get_Target()
:System.Void set_Target(share.hid.KeyAssign.MousePoint)
-- static
:via.Point getValue(share.hid.KeyAssign.MousePoint, share.hid.Device)
```

## `share.hid.KeyAssign.MousePointElement.Parameter`

```lua
-- fields
_Target: share.hid.KeyAssign.MousePoint
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:share.hid.KeyAssign.MousePoint get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseVec2`

```lua
-- values (System.UInt32 enum)
MovePosition
None
Position
```

## `share.hid.KeyAssign.MouseVec2Element`

```lua
-- methods
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.MouseVec2, System.Collections.Generic.List`1<share.hid.KeyAssign.MouseVec2>)
:via.vec2 getValue(share.hid.KeyAssign.MouseVec2, share.hid.Device)
```

## `share.hid.KeyAssign.MouseVec2Element.Parameter`

```lua
-- methods
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.Parameter`

```lua
-- fields
_Name: System.String
_Params: share.hid.KeyAssign.Element.Parameter[]
-- methods
:System.String get_DisplayName()
:System.String get_Name()
:share.hid.KeyAssign.Element.Parameter[] get_Params()
```

## `share.hid.KeyAssign.PointElement`

```lua
-- static
:via.Point merge(System.Collections.Generic.List`1<via.Point>)
:via.Point merge(System.Collections.Generic.List`1<share.hid.KeyAssign.PointElement>, share.hid.Device)
```

## `share.hid.KeyAssign.QuaternionElement`

```lua
-- static
:via.Quaternion merge(System.Collections.Generic.List`1<via.Quaternion>)
:via.Quaternion merge(System.Collections.Generic.List`1<share.hid.KeyAssign.QuaternionElement>, share.hid.Device)
```

## `share.hid.KeyAssign.Vec2Element`

```lua
-- methods
:System.Collections.Generic.List`1<via.vec2> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<via.vec2>)
-- static
:via.vec2 merge(System.Collections.Generic.List`1<via.vec2>, System.Single, System.Boolean)
:via.vec2 merge(via.vec2, via.vec2)
:via.vec2 merge(System.Collections.Generic.List`1<share.hid.KeyAssign.Vec2Element>, share.hid.Device, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.Vec3Element`

```lua
-- methods
:System.Collections.Generic.List`1<via.vec3> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<via.vec3>)
-- static
:via.vec3 merge(System.Collections.Generic.List`1<via.vec3>, System.Single, System.Boolean)
:via.vec3 merge(via.vec3, via.vec3)
:via.vec3 merge(System.Collections.Generic.List`1<share.hid.KeyAssign.Vec3Element>, share.hid.Device, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.VecElement`

```lua
-- methods
:System.Single get_Magnification()
:System.Boolean get_Normalized()
:System.Void set_Magnification(System.Single)
:System.Void set_Normalized(System.Boolean)
-- static
:System.String convertString(System.String, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.VecElement.Parameter`

```lua
-- fields
_Magnification: System.Single
_Normalized: System.Boolean
-- methods
:System.Single get_Magnification()
:System.Boolean get_Normalized()
```

## `share.hid.KeyAssignUserData`

```lua
-- fields
_Params: share.hid.KeyAssign.Parameter[]
-- methods
:share.hid.KeyAssign.Parameter[] get_Params()
```

## `share.hid.User`

```lua
-- values (System.Int32 enum)
Invalid
User_00
User_01
User_02
User_03
User_Max
```
