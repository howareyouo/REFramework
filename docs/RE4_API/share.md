# `share.*`

486 types.

## `share.AccountPickerResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DeviceDisconnected` | `share.AccountPickerResult` | yes | 16 |
| `Failed` | `share.AccountPickerResult` | yes | 16 |
| `GuestUser` | `share.AccountPickerResult` | yes | 16 |
| `InvalidUser` | `share.AccountPickerResult` | yes | 16 |
| `UserChanged` | `share.AccountPickerResult` | yes | 16 |
| `UserFirstChanged` | `share.AccountPickerResult` | yes | 16 |
| `UserUnchanged` | `share.AccountPickerResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.AccountPickerResult[]`

**Methods**

```lua
:System.Void Add(share.AccountPickerResult)
:share.AccountPickerResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.AccountPickerResult)
:System.Void CopyTo(share.AccountPickerResult[], System.Int32)
:share.AccountPickerResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.AccountPickerResult> GetEnumerator()
:System.Int32 IndexOf(share.AccountPickerResult)
:System.Void Insert(System.Int32, share.AccountPickerResult)
:System.Boolean Remove(share.AccountPickerResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.AccountPickerResult)
:share.AccountPickerResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.AccountPickerResult)
```

## `share.AnalysisLogManagerAccessor`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OPTION_ID_LIST` | `chainsaw.option.OptionID[]` | yes | 16 |
| `InvalidDataStr` | `System.String` |  | 16 |
| `ChapterIDGameClear` | `System.String` |  | 24 |
| `ExtraChapterIDGameClear` | `System.String` |  | 32 |
| `<IsTemporaryForbidSend>k__BackingField` | `System.Boolean` |  | 40 |
| `<HttpClient>k__BackingField` | `via.network.HttpClient` |  | 48 |
| `_RefAnalysisLogManager` | `app.dev1lab.AnalysisLogManager` |  | 56 |
| `_DefaultUserIndex` | `via.UserIndex` |  | 64 |
| `_LastActiveSendTime` | `System.UInt64` |  | 72 |
| `_CurrFrameMainPlayTime` | `share.AnalysisLogManagerAccessor.CurrentFramePlayTime` |  | 80 |
| `_AcquiredPtas` | `System.Int64` |  | 88 |
| `_BrokenKnifeCount` | `System.Int32` |  | 96 |
| `_ValudugoResult` | `System.Int32` |  | 100 |
| `_Record_GameOverList` | `app.dev1lab.AnalysisLogEventParamMain_record.GameoverData[]` |  | 104 |
| `_Record_GameOverCount` | `System.Int32` |  | 112 |
| `_Record_MissionData` | `app.dev1lab.AnalysisLogEventParamMain_record.MissionData[]` |  | 120 |
| `_Record_MissionCount` | `System.Int32` |  | 128 |
| `_Record_FileData` | `app.dev1lab.AnalysisLogEventParamMain_record.FileData[]` |  | 136 |
| `_Record_FileCount` | `System.Int32` |  | 144 |
| `_Record_MerchantData` | `app.dev1lab.AnalysisLogEventParamMain_record.MerchantData[]` |  | 152 |
| `_Record_MerchantCount` | `System.Int32` |  | 160 |
| `_ReNetUnit_CraftData` | `chainsaw.ReNetUnit_CraftData` |  | 168 |
| `_ReNetUnit_TreasureData` | `chainsaw.ReNetUnit_TreasureData` |  | 176 |
| `_ReNetUnit_ReinforceData` | `chainsaw.ReNetUnit_ReinforceData` |  | 184 |
| `_ReNetUnit_AttackData` | `chainsaw.ReNetUnit_AttackData` |  | 192 |
| `_ReNetUnit_BattleData` | `chainsaw.ReNetUnit_BattleData` |  | 200 |
| `_ReNetUnit_BossClearData` | `chainsaw.ReNetUnit_BossClearData` |  | 208 |
| `_ReNetUnit_AnimalData` | `chainsaw.ReNetUnit_AnimalData` |  | 216 |
| `_ReNetUnit_EggData` | `chainsaw.ReNetUnit_EggData` |  | 224 |
| `_ReNetUnit_SnakeData` | `chainsaw.ReNetUnit_SnakeData` |  | 232 |
| `_ReNetUnit_ParryData` | `chainsaw.ReNetUnit_ParryData` |  | 240 |
| `_ReNetUnit_MenData` | `chainsaw.ReNetUnit_MenData` |  | 248 |
| `_ReNetUnit_WomenData` | `chainsaw.ReNetUnit_WomenData` |  | 256 |
| `_ReNetUnit_BlueCoinData` | `chainsaw.ReNetUnit_BlueCoinData` |  | 264 |
| `_ReNetUnit_ObjectDestroyData` | `chainsaw.ReNetUnit_ObjectDestroyData` |  | 272 |
| `_ReNetUnit_DollData` | `chainsaw.ReNetUnit_DollData` |  | 280 |
| `_ReNetUnit_SpentTimeData` | `chainsaw.ReNetUnit_SpentTimeData` |  | 288 |
| `_ReNetUnit_UseItemsData` | `chainsaw.ReNetUnit_UseItemsData` |  | 296 |
| `_ReNetUnit_PhotoModeData` | `chainsaw.ReNetUnit_PhotoModeData` |  | 304 |
| `_ReNetUnit_BonusMenuData` | `chainsaw.ReNetUnit_BonusMenuData` |  | 312 |
| `_ReNetUnit_DlcUse` | `chainsaw.ReNetUnit_DlcUse` |  | 320 |
| `_ReNetUnit_MercenariesInGame` | `chainsaw.ReNetUnit_MercenariesInGame` |  | 328 |
| `_ReNetUnit_MercenariesGetItemsData` | `chainsaw.ReNetUnit_GetItemsData` |  | 336 |
| `_ReNetUnit_HookShotData` | `chainsaw.ReNetUnit_HookShotData` |  | 344 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.AnalysisLogManagerAccessor.CurrentFramePlayTime`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CurrPlayTime` | `System.UInt64` |  | 16 |
| `LastPlayTime` | `System.UInt64` |  | 24 |
| `MeasuredFrame` | `System.UInt32` |  | 32 |
| `DeltaTime` | `System.UInt64` |  | 40 |

**Methods**

```lua
:System.Void updatePlayTime(System.UInt64)
```

## `share.AnalysisLogManagerAccessor.RequestFrom`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnBoot` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnChapterClear` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnGameClaer` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnIngameCleanup` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnMainMenu` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnManualSave` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `OnPeriodic` | `share.AnalysisLogManagerAccessor.RequestFrom` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.AnalysisLogManagerAccessor.RequestFrom[]`

**Methods**

```lua
:System.Void Add(share.AnalysisLogManagerAccessor.RequestFrom)
:share.AnalysisLogManagerAccessor.RequestFrom Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void CopyTo(share.AnalysisLogManagerAccessor.RequestFrom[], System.Int32)
:share.AnalysisLogManagerAccessor.RequestFrom Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.AnalysisLogManagerAccessor.RequestFrom> GetEnumerator()
:System.Int32 IndexOf(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void Insert(System.Int32, share.AnalysisLogManagerAccessor.RequestFrom)
:System.Boolean Remove(share.AnalysisLogManagerAccessor.RequestFrom)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.AnalysisLogManagerAccessor.RequestFrom)
:share.AnalysisLogManagerAccessor.RequestFrom get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.AnalysisLogManagerAccessor.RequestFrom)
```

## `share.AnalysisLogManagerAccessorBehavior`

**Methods**

```lua
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.AppBehaviorBase`

_No fields or methods._

## `share.AppGraphicsOptionControllerForPC`

**Methods**

```lua
:System.Void .ctor()
:System.Void onWindowModeChangeEvent(via.render.WindowModeChangeStatus)
:System.Void setAntiAliasingType(via.render.RenderConfig.AntiAliasingType)
:System.Void setFrameRate(app.dev1lab.GraphicsOption.FrameRateType)
:System.Void setTextureFilterQuality(via.render.SamplerQuality)
```

## `share.AppGraphicsOptionControllerForPS4`

**Methods**

```lua
:System.Void .ctor()
```

## `share.AppGraphicsOptionControllerForPS5`

**Methods**

```lua
:System.Void .ctor()
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `share.AppGraphicsOptionControllerForXB1`

**Methods**

```lua
:System.Void .ctor()
```

## `share.AppGraphicsOptionControllerForXBS`

**Methods**

```lua
:System.Void .ctor()
:System.Void registerValueItem(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
:System.Void resetToPlatformDefaultsValue(System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>, app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues)
```

## `share.AppGraphicsOptionDefaultValueUserData`

**Methods**

```lua
:System.Void .ctor()
```

## `share.AppGraphicsOptionManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_core` | `share.AppGraphicsOptionManagerCore` |  | 16 |
| `_conectableHDR` | `System.Boolean` |  | 24 |

**Methods**

```lua
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SettingAsset` | `share.AppGraphicsOptionUserData` |  | 80 |

**Methods**

```lua
:System.Void awake()
:share.AppGraphicsOptionUserData get_SettingAsset()
:System.Void onDestroy()
:System.Void set_SettingAsset(share.AppGraphicsOptionUserData)
:System.Void update()
```

## `share.AppGraphicsOptionManagerCore`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `INVALID_VALUE` | `System.Int32` | yes | 16 |
| `_PlatformInitDataCache` | `System.Collections.Generic.Dictionary`2<app.dev1lab.GraphicsOption.ID,app.dev1lab.OptionValueItem>` |  | 48 |

**Methods**

```lua
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.AppGraphicsOptionUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ps5SettingValue` | `share.AppGraphicsOptionUserData.PS5Setting` |  | 64 |
| `_XBoxSeriesSettingValue` | `share.AppGraphicsOptionUserData.XBosScarletSetting` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionUserData.PlatformSetting getPlatformSetting()
:share.AppGraphicsOptionUserData.PS5Setting get_PS5SettingValue()
:share.AppGraphicsOptionUserData.XBosScarletSetting get_XBoxSeriesSettingValue()
:System.Void set_PS5SettingValue(share.AppGraphicsOptionUserData.PS5Setting)
```

## `share.AppGraphicsOptionUserData.PS5Setting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_PS5DefaultAsset` | `share.AppGraphicsOptionDefaultValueUserData` |  | 16 |

**Methods**

```lua
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:share.AppGraphicsOptionDefaultValueUserData get_PS5DefaultAsset()
:System.Void set_PS5DefaultAsset(share.AppGraphicsOptionDefaultValueUserData)
```

## `share.AppGraphicsOptionUserData.XBosScarletSetting`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_XBoxSeriesXAsset` | `share.AppGraphicsOptionDefaultValueUserData` |  | 16 |
| `_XBoxSeriesSAsset` | `share.AppGraphicsOptionDefaultValueUserData` |  | 24 |

**Methods**

```lua
:System.Boolean CheckNecessaryAsset()
:app.dev1lab.CommonGraphicsOptionDefaultValueUserData.DefaultValues getDefaultAsset()
:share.AppGraphicsOptionDefaultValueUserData get_XBoxSeriesSAsset()
:share.AppGraphicsOptionDefaultValueUserData get_XBoxSeriesXAsset()
```

## `share.AppInterfaceBaseExtension`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "isValid", ...)  -- System.Boolean isValid(share.IAppInterfaceBase)
sdk.call_native_func(nil, type_def, "isValid", ...)  -- System.Boolean isValid(share.IValidatable)
```

## `share.AppObjectBase`

_No fields or methods._

## `share.AppPayloadBase`

_No fields or methods._

## `share.AppRegionRecognizer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Cero` | `share.CERO` |  | 28 |

**Methods**

```lua
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ArgWidget` | `System.String` | yes | 16 |
| `ArgDip` | `System.String` | yes | 24 |
| `ArgVer` | `System.String` | yes | 32 |
| `ArgGraphicsOption` | `System.String` | yes | 40 |
| `ArgRevision` | `System.String` | yes | 48 |
| `ArgRegion` | `System.String` | yes | 56 |
| `ArgCERO` | `System.String` | yes | 64 |

**Methods**

```lua
:System.Void startUp()
:System.Void updateUnitList(System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit>, app.dev1lab.CommonRuntimeArgument.Unit)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.AppSaveFileDetail`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SaveFileDetail>k__BackingField` | `via.storage.saveService.SaveFileDetail` |  | 16 |
| `<IsEmpty>k__BackingField` | `System.Boolean` |  | 24 |

**Methods**

```lua
:System.Boolean get_IsEmpty()
:via.storage.saveService.SaveFileDetail get_SaveFileDetail()
:System.Void set_IsEmpty(System.Boolean)
:System.Void set_SaveFileDetail(via.storage.saveService.SaveFileDetail)
```

## `share.AppSaveFileDetail[]`

**Methods**

```lua
:System.Void Add(share.AppSaveFileDetail)
:share.AppSaveFileDetail Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.AppSaveFileDetail)
:System.Void CopyTo(share.AppSaveFileDetail[], System.Int32)
:share.AppSaveFileDetail Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.AppSaveFileDetail> GetEnumerator()
:System.Int32 IndexOf(share.AppSaveFileDetail)
:System.Void Insert(System.Int32, share.AppSaveFileDetail)
:System.Boolean Remove(share.AppSaveFileDetail)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.AppSaveFileDetail)
:share.AppSaveFileDetail get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.AppSaveFileDetail)
```

## `share.AppSaveLoadFailedResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ExcludeGameSave` | `share.AppSaveLoadFailedResult` | yes | 16 |
| `Invalid` | `share.AppSaveLoadFailedResult` | yes | 16 |
| `None` | `share.AppSaveLoadFailedResult` | yes | 16 |
| `RegionInvalid` | `share.AppSaveLoadFailedResult` | yes | 16 |
| `UnCollectable` | `share.AppSaveLoadFailedResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.AppSaveLoadFailedResult[]`

**Methods**

```lua
:System.Void Add(share.AppSaveLoadFailedResult)
:share.AppSaveLoadFailedResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.AppSaveLoadFailedResult)
:System.Void CopyTo(share.AppSaveLoadFailedResult[], System.Int32)
:share.AppSaveLoadFailedResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.AppSaveLoadFailedResult> GetEnumerator()
:System.Int32 IndexOf(share.AppSaveLoadFailedResult)
:System.Void Insert(System.Int32, share.AppSaveLoadFailedResult)
:System.Boolean Remove(share.AppSaveLoadFailedResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.AppSaveLoadFailedResult)
:share.AppSaveLoadFailedResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.AppSaveLoadFailedResult)
```

## `share.AppSaveSlot`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Campaign1001_Auto` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1001_GameSaveEnd` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1001_GameSaveLimit` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1001_GameSaveStart` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1001_SystemSave` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1011_Auto` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1011_GameSaveEnd` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1011_GameSaveLimit` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1011_GameSaveStart` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1011_SystemSave` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1021_Auto` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1021_GameSaveEnd` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1021_GameSaveLimit` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1021_GameSaveStart` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1021_SystemSave` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1031_Auto` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1031_GameSaveEnd` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1031_GameSaveLimit` | `share.AppSaveSlot` | yes | 16 |
| `Campaign1031_GameSaveStart` | `share.AppSaveSlot` | yes | 16 |
| `Invalid` | `share.AppSaveSlot` | yes | 16 |
| `Share_SystemSave` | `share.AppSaveSlot` | yes | 16 |
| `Share_Transfer_Testing` | `share.AppSaveSlot` | yes | 16 |
| `SlotMax` | `share.AppSaveSlot` | yes | 16 |
| `SystemMaxOffset` | `share.AppSaveSlot` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.AppSaveSlotUtil`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AllSystemSaveSlotNo` | `System.Int32[]` | yes | 16 |
| `AllCampaign1001GameSaveSlotNo` | `System.Int32[]` | yes | 24 |
| `AllCampaign1011GameSaveSlotNo` | `System.Int32[]` | yes | 32 |
| `AllCampaign1021GameSaveSlotNo` | `System.Int32[]` | yes | 40 |
| `AllCampaign1031GameSaveSlotNo` | `System.Int32[]` | yes | 48 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.AppSaveSlot[]`

**Methods**

```lua
:System.Void Add(share.AppSaveSlot)
:share.AppSaveSlot Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.AppSaveSlot)
:System.Void CopyTo(share.AppSaveSlot[], System.Int32)
:share.AppSaveSlot Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.AppSaveSlot> GetEnumerator()
:System.Int32 IndexOf(share.AppSaveSlot)
:System.Void Insert(System.Int32, share.AppSaveSlot)
:System.Boolean Remove(share.AppSaveSlot)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.AppSaveSlot)
:share.AppSaveSlot get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.AppSaveSlot)
```

## `share.AppSendPacketInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `payload` | `share.AppPayloadBase` |  | 16 |
| `memberIndex` | `System.Int32` |  | 24 |
| `option` | `via.network.protocol.SendOption` |  | 28 |

## `share.AppTracksBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<LayerNo>k__BackingField` | `System.Int32` |  | 16 |

**Methods**

```lua
:System.Int32 get_LayerNo()
:System.Void initialize(System.Int32)
:System.Void set_LayerNo(System.Int32)
:System.Void setup(System.Int32)
```

## `share.AppUserdataBase`

_No fields or methods._

## `share.AppZoneBase`

_No fields or methods._

## `share.ApplicationVersion`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `InvalidAssetVersion` | `System.String` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getAssetRevision", ...)  -- System.String getAssetRevision()
sdk.call_native_func(nil, type_def, "getEngineRevision", ...)  -- System.String getEngineRevision()
sdk.call_native_func(nil, type_def, "getSaveDataVersion", ...)  -- System.UInt32 getSaveDataVersion()
sdk.call_native_func(nil, type_def, "getVersion", ...)  -- System.UInt32 getVersion()
sdk.call_native_func(nil, type_def, "getVersionString", ...)  -- System.String getVersionString()
```

## `share.AverageTimeProfiler`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultTimeLogCount` | `System.Int32` | yes | 16 |
| `<ProfiledAvarageTime>k__BackingField` | `System.Single` |  | 16 |
| `<RecentAvarageTime>k__BackingField` | `System.Single` |  | 20 |
| `<BygoneAvarageTime>k__BackingField` | `System.Single` |  | 24 |
| `<TimeLog>k__BackingField` | `System.Single[]` |  | 32 |
| `<TimeLogIndicator>k__BackingField` | `System.Int32` |  | 40 |
| `<IsNeedUpdateBygoneTimeLog>k__BackingField` | `System.Boolean` |  | 44 |
| `_RecentWeight` | `System.Single` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `End` | `share.BehaviorTreeActionTiming` | yes | 16 |
| `Start` | `share.BehaviorTreeActionTiming` | yes | 16 |
| `Update` | `share.BehaviorTreeActionTiming` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.BehaviorTreeActionTiming[]`

**Methods**

```lua
:System.Void Add(share.BehaviorTreeActionTiming)
:share.BehaviorTreeActionTiming Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.BehaviorTreeActionTiming)
:System.Void CopyTo(share.BehaviorTreeActionTiming[], System.Int32)
:share.BehaviorTreeActionTiming Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.BehaviorTreeActionTiming> GetEnumerator()
:System.Int32 IndexOf(share.BehaviorTreeActionTiming)
:System.Void Insert(System.Int32, share.BehaviorTreeActionTiming)
:System.Boolean Remove(share.BehaviorTreeActionTiming)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.BehaviorTreeActionTiming)
:share.BehaviorTreeActionTiming get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.BehaviorTreeActionTiming)
```

## `share.Bool`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `False` | `share.Bool` | yes | 16 |
| `True` | `share.Bool` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.Bool[]`

**Methods**

```lua
:System.Void Add(share.Bool)
:share.Bool Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.Bool)
:System.Void CopyTo(share.Bool[], System.Int32)
:share.Bool Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.Bool> GetEnumerator()
:System.Int32 IndexOf(share.Bool)
:System.Void Insert(System.Int32, share.Bool)
:System.Boolean Remove(share.Bool)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.Bool)
:share.Bool get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.Bool)
```

## `share.BootController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BootSettingsUserData` | `share.BootSettingsUserData` |  | 80 |

**Methods**

```lua
:share.BootSettingsUserData get_BootSettingsUserData()
:System.Void onDestroy()
:System.Void set_BootSettingsUserData(share.BootSettingsUserData)
:System.Void start()
:System.Void update()
```

## `share.BootSettingsUserData`

_No fields or methods._

## `share.BootSystem`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `APPLICATION_VERSION_LAUNCH` | `System.UInt32` | yes | 16 |
| `APPLICATION_VERSION_TU1` | `System.UInt32` | yes | 16 |
| `APPLICATION_VERSION_TU1_2` | `System.UInt32` | yes | 16 |
| `APPLICATION_VERSION_TU2` | `System.UInt32` | yes | 16 |
| `APPLICATION_VERSION_TU3` | `System.UInt32` | yes | 16 |
| `NOTIFIER_COUNT` | `System.Int32` | yes | 16 |
| `CURREENT_APPLICATION_VERSION` | `System.UInt32` |  | 16 |
| `<CurrentPhase>k__BackingField` | `share.BootSystem.Phase` |  | 20 |
| `<CurrentBootType>k__BackingField` | `share.BootType` |  | 24 |
| `RefGameCoreFolder` | `share.SceneFolderController` |  | 32 |
| `<FolderControllerList>k__BackingField` | `System.Collections.Generic.List`1<share.SceneFolderController>` |  | 40 |
| `CallbackOnCompletedActivatingAppResident` | `System.Action` |  | 48 |
| `<BootSettingsUserData>k__BackingField` | `share.BootSettingsUserData` |  | 56 |
| `<NeedToApplicationUpdate>k__BackingField` | `System.Boolean` |  | 64 |
| `CoreSystemSetupFinishNotifierList` | `System.Collections.Generic.List`1<System.Object>` |  | 72 |
| `CoreSystemShutdownFinishNotifierList` | `System.Collections.Generic.List`1<System.Object>` |  | 80 |
| `RequestedReset` | `System.Boolean` |  | 88 |
| `_RequestedGC` | `System.Boolean` |  | 89 |
| `_OriginalGlobalCollectionBaseStep` | `System.UInt32` |  | 92 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Boot` | `share.BootSystem.Phase` | yes | 16 |
| `Completed` | `share.BootSystem.Phase` | yes | 16 |
| `CoreSystemSetupRequest` | `share.BootSystem.Phase` | yes | 16 |
| `CoreSystemSetupWait` | `share.BootSystem.Phase` | yes | 16 |
| `CoreSystemShutdownWait` | `share.BootSystem.Phase` | yes | 16 |
| `Deactivated` | `share.BootSystem.Phase` | yes | 16 |
| `Invalid` | `share.BootSystem.Phase` | yes | 16 |
| `ReadyForBoot` | `share.BootSystem.Phase` | yes | 16 |
| `ReadyForDeactiveFolders` | `share.BootSystem.Phase` | yes | 16 |
| `ReadyForDeactiveGameCore` | `share.BootSystem.Phase` | yes | 16 |
| `ReadyForGameCoreActive` | `share.BootSystem.Phase` | yes | 16 |
| `Reset` | `share.BootSystem.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.BootSystem.Phase[]`

**Methods**

```lua
:System.Void Add(share.BootSystem.Phase)
:share.BootSystem.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.BootSystem.Phase)
:System.Void CopyTo(share.BootSystem.Phase[], System.Int32)
:share.BootSystem.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.BootSystem.Phase> GetEnumerator()
:System.Int32 IndexOf(share.BootSystem.Phase)
:System.Void Insert(System.Int32, share.BootSystem.Phase)
:System.Boolean Remove(share.BootSystem.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.BootSystem.Phase)
:share.BootSystem.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.BootSystem.Phase)
```

## `share.BootType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Develop` | `share.BootType` | yes | 16 |
| `Invalid` | `share.BootType` | yes | 16 |
| `Master` | `share.BootType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.BootType[]`

**Methods**

```lua
:System.Void Add(share.BootType)
:share.BootType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.BootType)
:System.Void CopyTo(share.BootType[], System.Int32)
:share.BootType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.BootType> GetEnumerator()
:System.Int32 IndexOf(share.BootType)
:System.Void Insert(System.Int32, share.BootType)
:System.Boolean Remove(share.BootType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.BootType)
:share.BootType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.BootType)
```

## `share.CERO`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `D` | `share.CERO` | yes | 16 |
| `None` | `share.CERO` | yes | 16 |
| `Z` | `share.CERO` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CERO[]`

**Methods**

```lua
:System.Void Add(share.CERO)
:share.CERO Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CERO)
:System.Void CopyTo(share.CERO[], System.Int32)
:share.CERO Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CERO> GetEnumerator()
:System.Int32 IndexOf(share.CERO)
:System.Void Insert(System.Int32, share.CERO)
:System.Boolean Remove(share.CERO)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CERO)
:share.CERO get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CERO)
```

## `share.CampaignCollector`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RegistedCampaignList` | `System.Collections.Generic.List`1<share.CampaignIdentifier>` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void onDestroy()
:System.Void start()
```

## `share.CampaignController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CampaignID>k__BackingField` | `share.CampaignIdentifier` |  | 16 |
| `<CurrentPhase>k__BackingField` | `share.CampaignController.Phase` |  | 20 |
| `FolderController` | `share.SceneFolderController` |  | 24 |
| `RequestedActivate` | `System.Boolean` |  | 32 |
| `RequestedDeactivate` | `System.Boolean` |  | 33 |
| `_RefCatalogController` | `share.CatalogCollector` |  | 40 |

**Methods**

```lua
:System.Void .ctor(share.CampaignIdentifier, via.Folder)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Active` | `share.CampaignController.Phase` | yes | 16 |
| `CloseFolderWait` | `share.CampaignController.Phase` | yes | 16 |
| `CloseWaitCatalog` | `share.CampaignController.Phase` | yes | 16 |
| `OpenFolderWait` | `share.CampaignController.Phase` | yes | 16 |
| `OpenWaitCatalog` | `share.CampaignController.Phase` | yes | 16 |
| `Sleep` | `share.CampaignController.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CampaignController.Phase[]`

**Methods**

```lua
:System.Void Add(share.CampaignController.Phase)
:share.CampaignController.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CampaignController.Phase)
:System.Void CopyTo(share.CampaignController.Phase[], System.Int32)
:share.CampaignController.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CampaignController.Phase> GetEnumerator()
:System.Int32 IndexOf(share.CampaignController.Phase)
:System.Void Insert(System.Int32, share.CampaignController.Phase)
:System.Boolean Remove(share.CampaignController.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CampaignController.Phase)
:share.CampaignController.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CampaignController.Phase)
```

## `share.CampaignController[]`

**Methods**

```lua
:System.Void Add(share.CampaignController)
:share.CampaignController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CampaignController)
:System.Void CopyTo(share.CampaignController[], System.Int32)
:share.CampaignController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CampaignController> GetEnumerator()
:System.Int32 IndexOf(share.CampaignController)
:System.Void Insert(System.Int32, share.CampaignController)
:System.Boolean Remove(share.CampaignController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CampaignController)
:share.CampaignController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CampaignController)
```

## `share.CampaignIdentifier`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Campaign1001` | `share.CampaignIdentifier` | yes | 16 |
| `Campaign1011` | `share.CampaignIdentifier` | yes | 16 |
| `Campaign1021` | `share.CampaignIdentifier` | yes | 16 |
| `Campaign2001` | `share.CampaignIdentifier` | yes | 16 |
| `Invalid` | `share.CampaignIdentifier` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CampaignIdentifier[]`

**Methods**

```lua
:System.Void Add(share.CampaignIdentifier)
:share.CampaignIdentifier Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CampaignIdentifier)
:System.Void CopyTo(share.CampaignIdentifier[], System.Int32)
:share.CampaignIdentifier Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CampaignIdentifier> GetEnumerator()
:System.Int32 IndexOf(share.CampaignIdentifier)
:System.Void Insert(System.Int32, share.CampaignIdentifier)
:System.Boolean Remove(share.CampaignIdentifier)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CampaignIdentifier)
:share.CampaignIdentifier get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CampaignIdentifier)
```

## `share.CampaignIdentifier[][]`

**Methods**

```lua
:System.Void Add(share.CampaignIdentifier[])
:share.CampaignIdentifier[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CampaignIdentifier[])
:System.Void CopyTo(share.CampaignIdentifier[][], System.Int32)
:share.CampaignIdentifier[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CampaignIdentifier[]> GetEnumerator()
:System.Int32 IndexOf(share.CampaignIdentifier[])
:System.Void Insert(System.Int32, share.CampaignIdentifier[])
:System.Boolean Remove(share.CampaignIdentifier[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CampaignIdentifier[])
:share.CampaignIdentifier[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CampaignIdentifier[])
```

## `share.CatalogCollector`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Has2ndChunkChecker` | `System.Boolean` |  | 80 |
| `_2ndChunkFolderName` | `System.String` |  | 88 |
| `_ChunkFolderInfoList` | `share.CatalogCollector.ChunkFolderInfo[]` |  | 96 |
| `_ControllerList` | `share.CatalogFolderController[]` |  | 104 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean isLoadedOrWaitingExist()
:System.Boolean isReady2ndChunk()
:System.Boolean isUnloaded()
:System.Void onDestroy()
:System.Void requestUnload()
:System.Void start()
:System.Void update()
```

## `share.CatalogCollector.ChunkFolderInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FolderName` | `System.String` |  | 16 |
| `Chunk` | `System.Int32` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
```

## `share.CatalogCollector.ChunkFolderInfo[]`

**Methods**

```lua
:System.Void Add(share.CatalogCollector.ChunkFolderInfo)
:share.CatalogCollector.ChunkFolderInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CatalogCollector.ChunkFolderInfo)
:System.Void CopyTo(share.CatalogCollector.ChunkFolderInfo[], System.Int32)
:share.CatalogCollector.ChunkFolderInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CatalogCollector.ChunkFolderInfo> GetEnumerator()
:System.Int32 IndexOf(share.CatalogCollector.ChunkFolderInfo)
:System.Void Insert(System.Int32, share.CatalogCollector.ChunkFolderInfo)
:System.Boolean Remove(share.CatalogCollector.ChunkFolderInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CatalogCollector.ChunkFolderInfo)
:share.CatalogCollector.ChunkFolderInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CatalogCollector.ChunkFolderInfo)
```

## `share.CatalogCollector[]`

**Methods**

```lua
:System.Void Add(share.CatalogCollector)
:share.CatalogCollector Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CatalogCollector)
:System.Void CopyTo(share.CatalogCollector[], System.Int32)
:share.CatalogCollector Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CatalogCollector> GetEnumerator()
:System.Int32 IndexOf(share.CatalogCollector)
:System.Void Insert(System.Int32, share.CatalogCollector)
:System.Boolean Remove(share.CatalogCollector)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CatalogCollector)
:share.CatalogCollector get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CatalogCollector)
```

## `share.CatalogFolderController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ChunkID>k__BackingField` | `System.Int32` |  | 16 |
| `<CurrentPhase>k__BackingField` | `share.CatalogFolderController.Phase` |  | 20 |
| `Controller` | `share.SceneFolderController` |  | 24 |
| `Folder` | `via.Folder` |  | 32 |
| `<TargetPhase>k__BackingField` | `share.CatalogFolderController.Phase` |  | 40 |

**Methods**

```lua
:System.Void .ctor(via.Folder, System.Int32)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Initial` | `share.CatalogFolderController.Phase` | yes | 16 |
| `KickLoad` | `share.CatalogFolderController.Phase` | yes | 16 |
| `Loaded` | `share.CatalogFolderController.Phase` | yes | 16 |
| `Unloaded` | `share.CatalogFolderController.Phase` | yes | 16 |
| `Unloading` | `share.CatalogFolderController.Phase` | yes | 16 |
| `WaitExist` | `share.CatalogFolderController.Phase` | yes | 16 |
| `WaitLoad` | `share.CatalogFolderController.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CatalogFolderController.Phase[]`

**Methods**

```lua
:System.Void Add(share.CatalogFolderController.Phase)
:share.CatalogFolderController.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CatalogFolderController.Phase)
:System.Void CopyTo(share.CatalogFolderController.Phase[], System.Int32)
:share.CatalogFolderController.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CatalogFolderController.Phase> GetEnumerator()
:System.Int32 IndexOf(share.CatalogFolderController.Phase)
:System.Void Insert(System.Int32, share.CatalogFolderController.Phase)
:System.Boolean Remove(share.CatalogFolderController.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CatalogFolderController.Phase)
:share.CatalogFolderController.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CatalogFolderController.Phase)
```

## `share.CatalogFolderController[]`

**Methods**

```lua
:System.Void Add(share.CatalogFolderController)
:share.CatalogFolderController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CatalogFolderController)
:System.Void CopyTo(share.CatalogFolderController[], System.Int32)
:share.CatalogFolderController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CatalogFolderController> GetEnumerator()
:System.Int32 IndexOf(share.CatalogFolderController)
:System.Void Insert(System.Int32, share.CatalogFolderController)
:System.Boolean Remove(share.CatalogFolderController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CatalogFolderController)
:share.CatalogFolderController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CatalogFolderController)
```

## `share.CatalogManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CatalogCollectorList` | `System.Collections.Generic.List`1<share.CatalogCollector>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
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

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
```

## `share.CatalogRegisterBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<IsRegisteredCatalog>k__BackingField` | `System.Boolean` |  | 80 |

**Methods**

```lua
:System.Boolean get_IsRegisteredCatalog()
:System.Void onUnload()
:System.Void set_IsRegisteredCatalog(System.Boolean)
:System.Void update()
```

## `share.CollectType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Any` | `share.CollectType` | yes | 16 |
| `Include` | `share.CollectType` | yes | 16 |
| `Match` | `share.CollectType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CollectType[]`

**Methods**

```lua
:System.Void Add(share.CollectType)
:share.CollectType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CollectType)
:System.Void CopyTo(share.CollectType[], System.Int32)
:share.CollectType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CollectType> GetEnumerator()
:System.Int32 IndexOf(share.CollectType)
:System.Void Insert(System.Int32, share.CollectType)
:System.Boolean Remove(share.CollectType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CollectType)
:share.CollectType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CollectType)
```

## `share.CompareType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Equal` | `share.CompareType` | yes | 16 |
| `Greater` | `share.CompareType` | yes | 16 |
| `GreaterEq` | `share.CompareType` | yes | 16 |
| `Less` | `share.CompareType` | yes | 16 |
| `LessEq` | `share.CompareType` | yes | 16 |
| `NotEqual` | `share.CompareType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.CompareType[]`

**Methods**

```lua
:System.Void Add(share.CompareType)
:share.CompareType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.CompareType)
:System.Void CopyTo(share.CompareType[], System.Int32)
:share.CompareType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.CompareType> GetEnumerator()
:System.Int32 IndexOf(share.CompareType)
:System.Void Insert(System.Int32, share.CompareType)
:System.Boolean Remove(share.CompareType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.CompareType)
:share.CompareType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.CompareType)
```

## `share.ComponentEnableController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HashBehavior` | `System.UInt32` | yes | 80 |
| `_StopLayers` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt32>` |  | 80 |
| `_OnChangeCallbacks` | `System.Collections.Generic.Dictionary`2<System.UInt32,share.ComponentEnableController.Callback>` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Void appendOnChange(via.Component, System.Action`1<System.Boolean>)
:System.Boolean applyEnabled(via.Component, System.Boolean)
:System.Void dependOnChange(via.Component, System.Action`1<System.Boolean>)
:System.Void fireEvent(System.UInt32, System.Boolean)
:System.Boolean getEnabled(via.Component)
:System.Void onDestroy()
:System.Void setEnabledInLock(via.Component, System.Boolean, System.UInt32)
:System.Void setEnabledNoLock(via.Component, System.Boolean, System.UInt32)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "readyController", ...)  -- share.ComponentEnableController readyController(via.Component)
sdk.call_native_func(nil, type_def, "setEnabled", ...)  -- System.Boolean setEnabled(via.Component, System.Boolean, System.UInt32, System.Boolean)
```

## `share.ComponentEnableController.Callback`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnChange` | `System.Action`1<System.Boolean>` |  | 16 |

**Methods**

```lua
:System.Void add_OnChange(System.Action`1<System.Boolean>)
:System.Void appendEvent(System.Action`1<System.Boolean>)
:System.Void clear()
:System.Void dependEvent(System.Action`1<System.Boolean>)
:System.Void invoke(System.Boolean)
:System.Void remove_OnChange(System.Action`1<System.Boolean>)
```

## `share.ComponentEnableController.Callback[]`

**Methods**

```lua
:System.Void Add(share.ComponentEnableController.Callback)
:share.ComponentEnableController.Callback Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ComponentEnableController.Callback)
:System.Void CopyTo(share.ComponentEnableController.Callback[], System.Int32)
:share.ComponentEnableController.Callback Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ComponentEnableController.Callback> GetEnumerator()
:System.Int32 IndexOf(share.ComponentEnableController.Callback)
:System.Void Insert(System.Int32, share.ComponentEnableController.Callback)
:System.Boolean Remove(share.ComponentEnableController.Callback)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ComponentEnableController.Callback)
:share.ComponentEnableController.Callback get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ComponentEnableController.Callback)
```

## `share.ComponentEnableMediator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<DEFAULT>k__BackingField` | `share.ComponentEnableMediator.ArgsParam` | yes | 16 |
| `<_Requested>k__BackingField` | `System.Collections.Generic.List`1<share.ComponentEnableMediator.RequestParam>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "get_DEFAULT", ...)  -- share.ComponentEnableMediator.ArgsParam get_DEFAULT()
```

## `share.ComponentEnableMediator.ArgsParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Phase>k__BackingField` | `share.ComponentEnableMediator.SetPhase` |  | 16 |
| `AppliedEvent` | `System.Action`1<System.Boolean>` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.ComponentEnableMediator.ArgsParam)
:System.Void add_AppliedEvent(System.Action`1<System.Boolean>)
:share.ComponentEnableMediator.SetPhase get_Phase()
:System.Void onApplied(System.Boolean)
:System.Void remove_AppliedEvent(System.Action`1<System.Boolean>)
:System.Void set_Phase(share.ComponentEnableMediator.SetPhase)
```

## `share.ComponentEnableMediator.ArgsParam[]`

**Methods**

```lua
:System.Void Add(share.ComponentEnableMediator.ArgsParam)
:share.ComponentEnableMediator.ArgsParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ComponentEnableMediator.ArgsParam)
:System.Void CopyTo(share.ComponentEnableMediator.ArgsParam[], System.Int32)
:share.ComponentEnableMediator.ArgsParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ComponentEnableMediator.ArgsParam> GetEnumerator()
:System.Int32 IndexOf(share.ComponentEnableMediator.ArgsParam)
:System.Void Insert(System.Int32, share.ComponentEnableMediator.ArgsParam)
:System.Boolean Remove(share.ComponentEnableMediator.ArgsParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ComponentEnableMediator.ArgsParam)
:share.ComponentEnableMediator.ArgsParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ComponentEnableMediator.ArgsParam)
```

## `share.ComponentEnableMediator.RequestParam`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.Component` |  | 16 |
| `<Enabled>k__BackingField` | `System.Boolean` |  | 24 |
| `<Layer>k__BackingField` | `System.UInt32` |  | 28 |
| `<Args>k__BackingField` | `share.ComponentEnableMediator.ArgsParam` |  | 32 |

**Methods**

```lua
:share.ComponentEnableMediator.ArgsParam get_Args()
:System.Boolean get_Enabled()
:System.UInt32 get_Layer()
:via.Component get_Target()
:System.Void set_Args(share.ComponentEnableMediator.ArgsParam)
:System.Void set_Enabled(System.Boolean)
:System.Void set_Layer(System.UInt32)
:System.Void set_Target(via.Component)
```

## `share.ComponentEnableMediator.RequestParam[]`

**Methods**

```lua
:System.Void Add(share.ComponentEnableMediator.RequestParam)
:share.ComponentEnableMediator.RequestParam Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ComponentEnableMediator.RequestParam)
:System.Void CopyTo(share.ComponentEnableMediator.RequestParam[], System.Int32)
:share.ComponentEnableMediator.RequestParam Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ComponentEnableMediator.RequestParam> GetEnumerator()
:System.Int32 IndexOf(share.ComponentEnableMediator.RequestParam)
:System.Void Insert(System.Int32, share.ComponentEnableMediator.RequestParam)
:System.Boolean Remove(share.ComponentEnableMediator.RequestParam)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ComponentEnableMediator.RequestParam)
:share.ComponentEnableMediator.RequestParam get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ComponentEnableMediator.RequestParam)
```

## `share.ComponentEnableMediator.SetPhase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FrameHead` | `share.ComponentEnableMediator.SetPhase` | yes | 16 |
| `Immediate` | `share.ComponentEnableMediator.SetPhase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ComponentEnableMediator.SetPhase[]`

**Methods**

```lua
:System.Void Add(share.ComponentEnableMediator.SetPhase)
:share.ComponentEnableMediator.SetPhase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ComponentEnableMediator.SetPhase)
:System.Void CopyTo(share.ComponentEnableMediator.SetPhase[], System.Int32)
:share.ComponentEnableMediator.SetPhase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ComponentEnableMediator.SetPhase> GetEnumerator()
:System.Int32 IndexOf(share.ComponentEnableMediator.SetPhase)
:System.Void Insert(System.Int32, share.ComponentEnableMediator.SetPhase)
:System.Boolean Remove(share.ComponentEnableMediator.SetPhase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ComponentEnableMediator.SetPhase)
:share.ComponentEnableMediator.SetPhase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ComponentEnableMediator.SetPhase)
```

## `share.ComponentEnableMediatorBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
```

## `share.ContentsHash`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DLC_0001` | `System.UInt32` | yes | 16 |
| `DLC_0002` | `System.UInt32` | yes | 16 |
| `DLC_0004` | `System.UInt32` | yes | 16 |
| `DLC_1001` | `System.UInt32` | yes | 16 |
| `DLC_1002` | `System.UInt32` | yes | 16 |
| `DLC_1003` | `System.UInt32` | yes | 16 |
| `DLC_1004` | `System.UInt32` | yes | 16 |
| `DLC_1005` | `System.UInt32` | yes | 16 |
| `DLC_1006` | `System.UInt32` | yes | 16 |
| `DLC_1101` | `System.UInt32` | yes | 16 |
| `DLC_1102` | `System.UInt32` | yes | 16 |
| `DLC_1201` | `System.UInt32` | yes | 16 |
| `DLC_1202` | `System.UInt32` | yes | 16 |
| `DLC_1301` | `System.UInt32` | yes | 16 |
| `DLC_1401` | `System.UInt32` | yes | 16 |
| `DLC_1402` | `System.UInt32` | yes | 16 |
| `DLC_2001` | `System.UInt32` | yes | 16 |
| `DLC_3001` | `System.UInt32` | yes | 16 |
| `DLC_3101` | `System.UInt32` | yes | 16 |
| `DLC_4001` | `System.UInt32` | yes | 16 |
| `DLC_4002` | `System.UInt32` | yes | 16 |
| `DLC_4003` | `System.UInt32` | yes | 16 |
| `DLC_4004` | `System.UInt32` | yes | 16 |
| `DLC_4005` | `System.UInt32` | yes | 16 |
| `DLC_4006` | `System.UInt32` | yes | 16 |
| `DLC_4007` | `System.UInt32` | yes | 16 |
| `DLC_4008` | `System.UInt32` | yes | 16 |
| `DLC_4009` | `System.UInt32` | yes | 16 |
| `DLC_4010` | `System.UInt32` | yes | 16 |
| `DLC_4011` | `System.UInt32` | yes | 16 |
| `DLC_4012` | `System.UInt32` | yes | 16 |
| `DLC_4013` | `System.UInt32` | yes | 16 |
| `DLC_4014` | `System.UInt32` | yes | 16 |
| `DLC_4015` | `System.UInt32` | yes | 16 |
| `DLC_4016` | `System.UInt32` | yes | 16 |
| `DLC_4017` | `System.UInt32` | yes | 16 |
| `DLC_4018` | `System.UInt32` | yes | 16 |
| `DLC_4019` | `System.UInt32` | yes | 16 |
| `DLC_4020` | `System.UInt32` | yes | 16 |
| `DLC_4021` | `System.UInt32` | yes | 16 |
| `DLC_4022` | `System.UInt32` | yes | 16 |
| `DLC_4023` | `System.UInt32` | yes | 16 |
| `DLC_4024` | `System.UInt32` | yes | 16 |
| `DLC_4025` | `System.UInt32` | yes | 16 |
| `DLC_4026` | `System.UInt32` | yes | 16 |
| `DLC_4027` | `System.UInt32` | yes | 16 |
| `DLC_4028` | `System.UInt32` | yes | 16 |
| `DLC_4029` | `System.UInt32` | yes | 16 |
| `DLC_4030` | `System.UInt32` | yes | 16 |
| `DLC_9001` | `System.UInt32` | yes | 16 |

## `share.ContentsManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RefMainContents` | `share.SceneFolderController` |  | 16 |
| `GameCollection` | `System.Collections.Generic.Dictionary`2<share.GameIdentifier,share.GameController>` |  | 24 |
| `CampaignCollection` | `System.Collections.Generic.Dictionary`2<share.CampaignIdentifier,share.CampaignController>` |  | 32 |
| `CurrentPhase` | `share.ContentsManager.Phase` |  | 40 |
| `_CurrentGame` | `share.GameController` |  | 48 |
| `_CurrentCampaign` | `share.CampaignController` |  | 56 |
| `_CurrentGameIdentifier` | `share.GameIdentifier` |  | 64 |
| `_CurrentCampaignIdentifer` | `share.CampaignIdentifier` |  | 68 |
| `_OnFinishActivateLaunchContents` | `System.Action` |  | 72 |
| `_OnFinishDeactivateLaunchContents` | `System.Action` |  | 80 |
| `_OnFinishActivateGame` | `System.Action` |  | 88 |
| `_OnFinishActivateCampaign` | `System.Action` |  | 96 |
| `_OnFinishDeactivateGame` | `System.Action` |  | 104 |
| `_OnFinishDeactivateCampaign` | `System.Action` |  | 112 |
| `_DoNothing` | `System.Action` |  | 120 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ActivateLaunchContents` | `share.ContentsManager.Phase` | yes | 16 |
| `Active` | `share.ContentsManager.Phase` | yes | 16 |
| `DeactivateLaunchContents` | `share.ContentsManager.Phase` | yes | 16 |
| `EndCampaignWait` | `share.ContentsManager.Phase` | yes | 16 |
| `EndGameWait` | `share.ContentsManager.Phase` | yes | 16 |
| `EndSequenceKick` | `share.ContentsManager.Phase` | yes | 16 |
| `Sleep` | `share.ContentsManager.Phase` | yes | 16 |
| `Stable` | `share.ContentsManager.Phase` | yes | 16 |
| `StartCampaignWait` | `share.ContentsManager.Phase` | yes | 16 |
| `StartComplete` | `share.ContentsManager.Phase` | yes | 16 |
| `StartGameWait` | `share.ContentsManager.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ContentsManager.Phase[]`

**Methods**

```lua
:System.Void Add(share.ContentsManager.Phase)
:share.ContentsManager.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ContentsManager.Phase)
:System.Void CopyTo(share.ContentsManager.Phase[], System.Int32)
:share.ContentsManager.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ContentsManager.Phase> GetEnumerator()
:System.Int32 IndexOf(share.ContentsManager.Phase)
:System.Void Insert(System.Int32, share.ContentsManager.Phase)
:System.Boolean Remove(share.ContentsManager.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ContentsManager.Phase)
:share.ContentsManager.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ContentsManager.Phase)
```

## `share.ContentsManagerBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.CpuQualityPerformanceBalancer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Balancer` | `share.QualityPerformanceBalancer` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SimpleCompareTypeNames` | `System.String[]` | yes | 16 |
| `CompareTypeNames` | `System.String[]` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "compare", ...)  -- System.Boolean compare(System.Single, share.CompareType, System.Single)
sdk.call_native_func(nil, type_def, "compare", ...)  -- System.Boolean compare(System.Int32, share.CompareType, System.Int32)
sdk.call_native_func(nil, type_def, "compare", ...)  -- System.Boolean compare(System.UInt64, share.CompareType, System.UInt64)
sdk.call_native_func(nil, type_def, "makeExpressionLabel", ...)  -- System.String makeExpressionLabel(System.String, share.SimpleCompareType, System.String)
sdk.call_native_func(nil, type_def, "makeExpressionLabel", ...)  -- System.String makeExpressionLabel(System.String, share.CompareType, System.String)
```

## `share.ExtraContentsController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `HolderFolders` | `System.Collections.Generic.List`1<share.ExtraContentsController.Context>` |  | 80 |
| `ActivateFolders` | `System.Collections.Generic.List`1<via.Folder>` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Boolean checkActivated()
:System.Void collectFolder()
:System.Void onDestroy()
:System.Boolean requestActivate()
:System.Boolean requestDeactivate()
:System.Void start()
:System.Void update()
```

## `share.ExtraContentsController.Context`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Holder` | `via.Folder` |  | 16 |
| `Installed` | `System.Boolean` |  | 24 |

## `share.ExtraContentsController.Context[]`

**Methods**

```lua
:System.Void Add(share.ExtraContentsController.Context)
:share.ExtraContentsController.Context Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ExtraContentsController.Context)
:System.Void CopyTo(share.ExtraContentsController.Context[], System.Int32)
:share.ExtraContentsController.Context Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ExtraContentsController.Context> GetEnumerator()
:System.Int32 IndexOf(share.ExtraContentsController.Context)
:System.Void Insert(System.Int32, share.ExtraContentsController.Context)
:System.Boolean Remove(share.ExtraContentsController.Context)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ExtraContentsController.Context)
:share.ExtraContentsController.Context get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ExtraContentsController.Context)
```

## `share.ExtraContentsManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `WaitTimerSec` | `System.Single` | yes | 16 |
| `RefExtraContentsController` | `share.ExtraContentsController` |  | 16 |
| `OnPrepareCheckEndEvent` | `System.Action` |  | 24 |
| `OnCheckEndEvent` | `System.Action` |  | 32 |
| `OnDeactivateEndEvent` | `System.Action` |  | 40 |
| `ExtraContentsProcess` | `share.ExtraContentsManager.ExtraContentsProcessType` |  | 48 |
| `ExtraContentsList` | `System.Collections.Generic.List`1<System.UInt32>` |  | 56 |
| `ExtraContentsListMutex` | `via.threading.SimpleReaderWriterLock` |  | 64 |
| `RefDLC` | `via.storage.DLC` |  | 72 |
| `<NeedInstallFinishAnnounce>k__BackingField` | `System.Boolean` |  | 80 |
| `WaitTimer` | `System.Single` |  | 84 |
| `SteamContentTable` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.UInt64>` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.ExtraContentsManager.ExtraContentsProcessType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Check` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `Deactivate` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `None` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `PrepareCheck` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `WaitDeactivate` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `WaitMounted` | `share.ExtraContentsManager.ExtraContentsProcessType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ExtraContentsManager.ExtraContentsProcessType[]`

**Methods**

```lua
:System.Void Add(share.ExtraContentsManager.ExtraContentsProcessType)
:share.ExtraContentsManager.ExtraContentsProcessType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ExtraContentsManager.ExtraContentsProcessType)
:System.Void CopyTo(share.ExtraContentsManager.ExtraContentsProcessType[], System.Int32)
:share.ExtraContentsManager.ExtraContentsProcessType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ExtraContentsManager.ExtraContentsProcessType> GetEnumerator()
:System.Int32 IndexOf(share.ExtraContentsManager.ExtraContentsProcessType)
:System.Void Insert(System.Int32, share.ExtraContentsManager.ExtraContentsProcessType)
:System.Boolean Remove(share.ExtraContentsManager.ExtraContentsProcessType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ExtraContentsManager.ExtraContentsProcessType)
:share.ExtraContentsManager.ExtraContentsProcessType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ExtraContentsManager.ExtraContentsProcessType)
```

## `share.ExtraContentsRegister`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ContentsHash` | `chainsaw.NameHash` |  | 80 |

**Methods**

```lua
:System.Void awake()
:System.Void onDestroy()
```

## `share.ExtraRegionType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `German` | `share.ExtraRegionType` | yes | 16 |
| `Unknown` | `share.ExtraRegionType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ExtraRegionType[]`

**Methods**

```lua
:System.Void Add(share.ExtraRegionType)
:share.ExtraRegionType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ExtraRegionType)
:System.Void CopyTo(share.ExtraRegionType[], System.Int32)
:share.ExtraRegionType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ExtraRegionType> GetEnumerator()
:System.Int32 IndexOf(share.ExtraRegionType)
:System.Void Insert(System.Int32, share.ExtraRegionType)
:System.Boolean Remove(share.ExtraRegionType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ExtraRegionType)
:share.ExtraRegionType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ExtraRegionType)
```

## `share.FadeController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FadeColors` | `share.FadeController.FadeColor[]` | yes | 80 |
| `_FadeType` | `share.FadeManager.FadeType` |  | 80 |
| `_SegmentOrder` | `System.UInt32` |  | 84 |
| `_DefaultTimeSecond` | `System.Single` |  | 88 |
| `_TargetInfos` | `share.FadeController.FadeTargetInfo[]` |  | 96 |
| `_Phase` | `share.FadeController.Phase` |  | 104 |
| `_FadeColor` | `share.FadeController.FadeColor` |  | 108 |
| `_OnComplete` | `System.Action` |  | 112 |
| `_RefCounter` | `share.SyncRefCounter`1<System.Int32>` |  | 120 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.FadeController.FadeColor`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Black` | `share.FadeController.FadeColor` | yes | 16 |
| `Invalid` | `share.FadeController.FadeColor` | yes | 16 |
| `White` | `share.FadeController.FadeColor` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.FadeController.FadeColor[]`

**Methods**

```lua
:System.Void Add(share.FadeController.FadeColor)
:share.FadeController.FadeColor Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FadeController.FadeColor)
:System.Void CopyTo(share.FadeController.FadeColor[], System.Int32)
:share.FadeController.FadeColor Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FadeController.FadeColor> GetEnumerator()
:System.Int32 IndexOf(share.FadeController.FadeColor)
:System.Void Insert(System.Int32, share.FadeController.FadeColor)
:System.Boolean Remove(share.FadeController.FadeColor)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FadeController.FadeColor)
:share.FadeController.FadeColor get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FadeController.FadeColor)
```

## `share.FadeController.FadeTargetInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_IsSetupped` | `System.Boolean` |  | 16 |
| `_FadeColor` | `share.FadeController.FadeColor` |  | 20 |
| `_Target` | `via.GameObjectRef` |  | 24 |
| `<ImageSlide>k__BackingField` | `via.gui.SystemImageSlide` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.FadeController.FadeColor)
:share.FadeController.FadeColor get_FadeColor()
:via.gui.SystemImageSlide get_ImageSlide()
:System.Boolean get_IsValid()
:via.GameObjectRef get_Target()
:System.Void set_ImageSlide(via.gui.SystemImageSlide)
:System.Void setup(via.GameObject, System.UInt32)
```

## `share.FadeController.FadeTargetInfo[]`

**Methods**

```lua
:System.Void Add(share.FadeController.FadeTargetInfo)
:share.FadeController.FadeTargetInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FadeController.FadeTargetInfo)
:System.Void CopyTo(share.FadeController.FadeTargetInfo[], System.Int32)
:share.FadeController.FadeTargetInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FadeController.FadeTargetInfo> GetEnumerator()
:System.Int32 IndexOf(share.FadeController.FadeTargetInfo)
:System.Void Insert(System.Int32, share.FadeController.FadeTargetInfo)
:System.Boolean Remove(share.FadeController.FadeTargetInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FadeController.FadeTargetInfo)
:share.FadeController.FadeTargetInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FadeController.FadeTargetInfo)
```

## `share.FadeController.Phase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FadeIn_Idle` | `share.FadeController.Phase` | yes | 16 |
| `FadeIn_Wait` | `share.FadeController.Phase` | yes | 16 |
| `FadeOut_Idle` | `share.FadeController.Phase` | yes | 16 |
| `FadeOut_Wait` | `share.FadeController.Phase` | yes | 16 |
| `Invalid` | `share.FadeController.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.FadeController.Phase[]`

**Methods**

```lua
:System.Void Add(share.FadeController.Phase)
:share.FadeController.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FadeController.Phase)
:System.Void CopyTo(share.FadeController.Phase[], System.Int32)
:share.FadeController.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FadeController.Phase> GetEnumerator()
:System.Int32 IndexOf(share.FadeController.Phase)
:System.Void Insert(System.Int32, share.FadeController.Phase)
:System.Boolean Remove(share.FadeController.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FadeController.Phase)
:share.FadeController.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FadeController.Phase)
```

## `share.FadeController[]`

**Methods**

```lua
:System.Void Add(share.FadeController)
:share.FadeController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FadeController)
:System.Void CopyTo(share.FadeController[], System.Int32)
:share.FadeController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FadeController> GetEnumerator()
:System.Int32 IndexOf(share.FadeController)
:System.Void Insert(System.Int32, share.FadeController)
:System.Boolean Remove(share.FadeController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FadeController)
:share.FadeController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FadeController)
```

## `share.FadeManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FadeTypes` | `share.FadeManager.FadeType[]` | yes | 16 |
| `_FadeControllers` | `share.FadeController[]` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.FadeManager.FadeType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CAMPAIGN_JUMPER` | `share.FadeManager.FadeType` | yes | 16 |
| `CAMPAIGN_MANAGER` | `share.FadeManager.FadeType` | yes | 16 |
| `EVENT` | `share.FadeManager.FadeType` | yes | 16 |
| `GAMESTATE` | `share.FadeManager.FadeType` | yes | 16 |
| `GIMMICK` | `share.FadeManager.FadeType` | yes | 16 |
| `GUI` | `share.FadeManager.FadeType` | yes | 16 |
| `INTER_GAMESTATE` | `share.FadeManager.FadeType` | yes | 16 |
| `INVALID` | `share.FadeManager.FadeType` | yes | 16 |
| `TEXT_CHANGE` | `share.FadeManager.FadeType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.FadeManager.FadeType[]`

**Methods**

```lua
:System.Void Add(share.FadeManager.FadeType)
:share.FadeManager.FadeType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FadeManager.FadeType)
:System.Void CopyTo(share.FadeManager.FadeType[], System.Int32)
:share.FadeManager.FadeType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FadeManager.FadeType> GetEnumerator()
:System.Int32 IndexOf(share.FadeManager.FadeType)
:System.Void Insert(System.Int32, share.FadeManager.FadeType)
:System.Boolean Remove(share.FadeManager.FadeType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FadeManager.FadeType)
:share.FadeManager.FadeType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FadeManager.FadeType)
```

## `share.FadeManagerBehavior`

**Methods**

```lua
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.FolderKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Body` | `share.FolderKind` | yes | 16 |
| `Head` | `share.FolderKind` | yes | 16 |
| `Nobody` | `share.FolderKind` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.FolderKind[]`

**Methods**

```lua
:System.Void Add(share.FolderKind)
:share.FolderKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.FolderKind)
:System.Void CopyTo(share.FolderKind[], System.Int32)
:share.FolderKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.FolderKind> GetEnumerator()
:System.Int32 IndexOf(share.FolderKind)
:System.Void Insert(System.Int32, share.FolderKind)
:System.Boolean Remove(share.FolderKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.FolderKind)
:share.FolderKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.FolderKind)
```

## `share.FolderService`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<InstanceFolderRoot>k__BackingField` | `via.Folder` |  | 16 |
| `<Folders>k__BackingField` | `System.Collections.Generic.Dictionary`2<share.FolderKind,via.Folder>` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:via.Folder getFolder(share.FolderKind)
:System.Collections.Generic.Dictionary`2<share.FolderKind,via.Folder> get_Folders()
:via.Folder get_InstanceFolderRoot()
:System.Void onDestroy()
:System.Void onStart(via.GameObject)
:System.Void set_Folders(System.Collections.Generic.Dictionary`2<share.FolderKind,via.Folder>)
:System.Void set_InstanceFolderRoot(via.Folder)
```

## `share.FolderServiceBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
```

## `share.FolderServiceDefinition`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_FolderKindsRaw` | `share.FolderKind[]` | yes | 16 |
| `FolderKinds` | `System.Collections.ObjectModel.ReadOnlyCollection`1<share.FolderKind>` | yes | 24 |
| `FolderKindMax` | `System.Int32` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.GameClock`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_MeasureGameElapsedTime` | `System.Boolean` |  | 16 |
| `_MeasureDemoSpendingTime` | `System.Boolean` |  | 17 |
| `_MeasureInventorySpendingTime` | `System.Boolean` |  | 18 |
| `_MeasurePauseSpendingTime` | `System.Boolean` |  | 19 |
| `_SystemSaveData` | `share.GameClock.SystemSaveData` |  | 24 |
| `_GameSaveData` | `share.GameClock.GameSaveData` |  | 32 |
| `_GameSaveData_Reset` | `share.GameClock.GameSaveData` |  | 40 |
| `<SystemSaveDataVersion>k__BackingField` | `System.UInt32` |  | 48 |
| `<SystemSaveDataHash>k__BackingField` | `System.UInt32` |  | 52 |
| `<GameSaveDataVersion>k__BackingField` | `System.UInt32` |  | 56 |
| `<GameSaveDataHash>k__BackingField` | `System.UInt32` |  | 60 |

**Methods**

```lua
:System.Void .ctor()
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "calcDateFromUlongTime", ...)  -- System.Void calcDateFromUlongTime(System.UInt64, System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "calcUlongTimeFromDate", ...)  -- System.UInt64 calcUlongTimeFromDate(System.Int32, System.Int32, System.Int32, System.Int32, System.Int32)
sdk.call_native_func(nil, type_def, "convertReadableTime", ...)  -- System.String convertReadableTime(System.UInt64)
```

## `share.GameClock.GameSaveData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_GameElapsedTime` | `System.UInt64` |  | 24 |
| `_DemoSpendingTime` | `System.UInt64` |  | 32 |
| `_InventorySpendingTime` | `System.UInt64` |  | 40 |
| `_PauseSpendingTime` | `System.UInt64` |  | 48 |

**Methods**

```lua
:System.Void .ctor(share.GameClock.GameSaveData)
:System.Void copyFrom(share.GameClock.GameSaveData)
```

## `share.GameClock.Kind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ActualPlaying` | `share.GameClock.Kind` | yes | 16 |
| `ActualRecord` | `share.GameClock.Kind` | yes | 16 |
| `DemoSpending` | `share.GameClock.Kind` | yes | 16 |
| `Game` | `share.GameClock.Kind` | yes | 16 |
| `InventorySpending` | `share.GameClock.Kind` | yes | 16 |
| `PauseSpending` | `share.GameClock.Kind` | yes | 16 |
| `System` | `share.GameClock.Kind` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameClock.Kind[]`

**Methods**

```lua
:System.Void Add(share.GameClock.Kind)
:share.GameClock.Kind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameClock.Kind)
:System.Void CopyTo(share.GameClock.Kind[], System.Int32)
:share.GameClock.Kind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameClock.Kind> GetEnumerator()
:System.Int32 IndexOf(share.GameClock.Kind)
:System.Void Insert(System.Int32, share.GameClock.Kind)
:System.Boolean Remove(share.GameClock.Kind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameClock.Kind)
:share.GameClock.Kind get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameClock.Kind)
```

## `share.GameClock.SystemSaveData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SystemElapsedTime` | `System.UInt64` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.GameClock.SystemSaveData)
:System.Void copyFrom(share.GameClock.SystemSaveData)
```

## `share.GameClockBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.GameCollector`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RegistedGameList` | `System.Collections.Generic.List`1<share.GameIdentifier>` |  | 80 |

**Methods**

```lua
:System.Void .ctor()
:System.Void onDestroy()
:System.Void start()
```

## `share.GameController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<GameID>k__BackingField` | `share.GameIdentifier` |  | 16 |
| `<CurrentPhase>k__BackingField` | `share.GameController.Phase` |  | 20 |
| `FolderController` | `share.SceneFolderController` |  | 24 |
| `GameCoreFolderController` | `share.SceneFolderController` |  | 32 |
| `SubFolderControllerList` | `System.Collections.Generic.List`1<share.SceneFolderController>` |  | 40 |
| `RequestedActivate` | `System.Boolean` |  | 48 |
| `RequestedDeactivate` | `System.Boolean` |  | 49 |
| `_RefCatalogController` | `share.CatalogCollector` |  | 56 |

**Methods**

```lua
:System.Void .ctor(share.GameIdentifier, via.Folder)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Active` | `share.GameController.Phase` | yes | 16 |
| `CloseCoreWait` | `share.GameController.Phase` | yes | 16 |
| `CloseGameWait` | `share.GameController.Phase` | yes | 16 |
| `CloseSubFoldersWait` | `share.GameController.Phase` | yes | 16 |
| `CloseWaitCatalog` | `share.GameController.Phase` | yes | 16 |
| `OpenCoreWait` | `share.GameController.Phase` | yes | 16 |
| `OpenGame` | `share.GameController.Phase` | yes | 16 |
| `OpenGameWait` | `share.GameController.Phase` | yes | 16 |
| `OpenSubFoldersWait` | `share.GameController.Phase` | yes | 16 |
| `OpenWaitCatalog` | `share.GameController.Phase` | yes | 16 |
| `Sleep` | `share.GameController.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameController.Phase[]`

**Methods**

```lua
:System.Void Add(share.GameController.Phase)
:share.GameController.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameController.Phase)
:System.Void CopyTo(share.GameController.Phase[], System.Int32)
:share.GameController.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameController.Phase> GetEnumerator()
:System.Int32 IndexOf(share.GameController.Phase)
:System.Void Insert(System.Int32, share.GameController.Phase)
:System.Boolean Remove(share.GameController.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameController.Phase)
:share.GameController.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameController.Phase)
```

## `share.GameController[]`

**Methods**

```lua
:System.Void Add(share.GameController)
:share.GameController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameController)
:System.Void CopyTo(share.GameController[], System.Int32)
:share.GameController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameController> GetEnumerator()
:System.Int32 IndexOf(share.GameController)
:System.Void Insert(System.Int32, share.GameController)
:System.Boolean Remove(share.GameController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameController)
:share.GameController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameController)
```

## `share.GameIdentifier`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Game10` | `share.GameIdentifier` | yes | 16 |
| `Game20` | `share.GameIdentifier` | yes | 16 |
| `Invalid` | `share.GameIdentifier` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameIdentifier[]`

**Methods**

```lua
:System.Void Add(share.GameIdentifier)
:share.GameIdentifier Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameIdentifier)
:System.Void CopyTo(share.GameIdentifier[], System.Int32)
:share.GameIdentifier Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameIdentifier> GetEnumerator()
:System.Int32 IndexOf(share.GameIdentifier)
:System.Void Insert(System.Int32, share.GameIdentifier)
:System.Boolean Remove(share.GameIdentifier)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameIdentifier)
:share.GameIdentifier get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameIdentifier)
```

## `share.GameIdentifier[][]`

**Methods**

```lua
:System.Void Add(share.GameIdentifier[])
:share.GameIdentifier[] Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameIdentifier[])
:System.Void CopyTo(share.GameIdentifier[][], System.Int32)
:share.GameIdentifier[] Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameIdentifier[]> GetEnumerator()
:System.Int32 IndexOf(share.GameIdentifier[])
:System.Void Insert(System.Int32, share.GameIdentifier[])
:System.Boolean Remove(share.GameIdentifier[])
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameIdentifier[])
:share.GameIdentifier[] get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameIdentifier[])
```

## `share.GameLoadCompletedEventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SlotId>k__BackingField` | `System.Int32` |  | 16 |
| `<Result>k__BackingField` | `share.SaveLoadProcessResult` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32, share.SaveLoadProcessResult)
:share.SaveLoadProcessResult get_Result()
:System.Int32 get_SlotId()
:System.Void set_Result(share.SaveLoadProcessResult)
:System.Void set_SlotId(System.Int32)
```

## `share.GameLoadRequestArgs`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.GameLoadRequestArgs)
:share.SaveLoadRequestArgs getCopy()
```

## `share.GameModeType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Invalid` | `share.GameModeType` | yes | 16 |
| `OfflineCoop` | `share.GameModeType` | yes | 16 |
| `OfflineSolo` | `share.GameModeType` | yes | 16 |
| `OnlineCoop` | `share.GameModeType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameModeType[]`

**Methods**

```lua
:System.Void Add(share.GameModeType)
:share.GameModeType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameModeType)
:System.Void CopyTo(share.GameModeType[], System.Int32)
:share.GameModeType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameModeType> GetEnumerator()
:System.Int32 IndexOf(share.GameModeType)
:System.Void Insert(System.Int32, share.GameModeType)
:System.Boolean Remove(share.GameModeType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameModeType)
:share.GameModeType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameModeType)
```

## `share.GameObjectExtension`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "addTag", ...)  -- System.Void addTag(via.GameObject, share.Tag.List)
sdk.call_native_func(nil, type_def, "convTagBits", ...)  -- System.Int32 convTagBits(System.String)
sdk.call_native_func(nil, type_def, "convTagBits", ...)  -- System.Int32 convTagBits(share.Tag.List)
sdk.call_native_func(nil, type_def, "convTagBits", ...)  -- System.Int32 convTagBits(share.Tag.List[])
sdk.call_native_func(nil, type_def, "findChild", ...)  -- via.GameObject findChild(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "getGameObjectInChildren", ...)  -- via.GameObject getGameObjectInChildren(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "getParentObject", ...)  -- via.GameObject getParentObject(via.GameObject)
sdk.call_native_func(nil, type_def, "getTagBits", ...)  -- System.Int32 getTagBits(via.GameObject)
sdk.call_native_func(nil, type_def, "readyComponent", ...)  -- via.Component readyComponent(via.GameObject, System.Type)
sdk.call_native_func(nil, type_def, "readyComponent", ...)  -- via.Component readyComponent(via.GameObject, System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "removeTag", ...)  -- System.Void removeTag(via.GameObject, share.Tag.List)
sdk.call_native_func(nil, type_def, "testAndTag", ...)  -- System.Boolean testAndTag(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "testAndTag", ...)  -- System.Boolean testAndTag(via.GameObject, share.Tag.List)
sdk.call_native_func(nil, type_def, "testAndTag", ...)  -- System.Boolean testAndTag(via.GameObject, share.Tag.List[])
sdk.call_native_func(nil, type_def, "testAnyTag", ...)  -- System.Boolean testAnyTag(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "testAnyTag", ...)  -- System.Boolean testAnyTag(via.GameObject, share.Tag.List)
sdk.call_native_func(nil, type_def, "testAnyTag", ...)  -- System.Boolean testAnyTag(via.GameObject, share.Tag.List[])
sdk.call_native_func(nil, type_def, "testMatchTag", ...)  -- System.Boolean testMatchTag(via.GameObject, System.String)
sdk.call_native_func(nil, type_def, "testMatchTag", ...)  -- System.Boolean testMatchTag(via.GameObject, share.Tag.List)
sdk.call_native_func(nil, type_def, "testMatchTag", ...)  -- System.Boolean testMatchTag(via.GameObject, share.Tag.List[])
sdk.call_native_func(nil, type_def, "testTag", ...)  -- System.Boolean testTag(via.GameObject, share.CollectType, System.String)
sdk.call_native_func(nil, type_def, "testTag", ...)  -- System.Boolean testTag(via.GameObject, share.CollectType, share.Tag.List)
sdk.call_native_func(nil, type_def, "testTag", ...)  -- System.Boolean testTag(via.GameObject, share.CollectType, share.Tag.List[])
```

## `share.GameObjectJointSetArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Phase>k__BackingField` | `share.GameObjectStateSetPhase` |  | 16 |
| `AppliedEvent` | `System.Action`1<share.GameObjectStateSetResult>` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.GameObjectJointSetArgs)
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectJointSetArgs[]`

**Methods**

```lua
:System.Void Add(share.GameObjectJointSetArgs)
:share.GameObjectJointSetArgs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectJointSetArgs)
:System.Void CopyTo(share.GameObjectJointSetArgs[], System.Int32)
:share.GameObjectJointSetArgs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectJointSetArgs> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectJointSetArgs)
:System.Void Insert(System.Int32, share.GameObjectJointSetArgs)
:System.Boolean Remove(share.GameObjectJointSetArgs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectJointSetArgs)
:share.GameObjectJointSetArgs get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectJointSetArgs)
```

## `share.GameObjectParentSetArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Phase>k__BackingField` | `share.GameObjectStateSetPhase` |  | 16 |
| `AppliedEvent` | `System.Action`1<share.GameObjectStateSetResult>` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.GameObjectParentSetArgs)
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectParentSetArgs[]`

**Methods**

```lua
:System.Void Add(share.GameObjectParentSetArgs)
:share.GameObjectParentSetArgs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectParentSetArgs)
:System.Void CopyTo(share.GameObjectParentSetArgs[], System.Int32)
:share.GameObjectParentSetArgs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectParentSetArgs> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectParentSetArgs)
:System.Void Insert(System.Int32, share.GameObjectParentSetArgs)
:System.Boolean Remove(share.GameObjectParentSetArgs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectParentSetArgs)
:share.GameObjectParentSetArgs get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectParentSetArgs)
```

## `share.GameObjectStateController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Group_StopControl` | `System.Boolean` | yes | 80 |
| `<StopUpdateLayers>k__BackingField` | `System.UInt32` |  | 80 |
| `<StopDrawLayers>k__BackingField` | `System.UInt32` |  | 84 |
| `OnSetUpdateEvent` | `System.Action`1<System.Boolean>` |  | 88 |
| `OnSetDrawEvent` | `System.Action`1<System.Boolean>` |  | 96 |
| `OnSetParentEvent` | `System.Action`1<via.GameObject>` |  | 104 |

**Methods**

```lua
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "applyParent", ...)  -- System.Boolean applyParent(via.GameObject, via.GameObject)
sdk.call_native_func(nil, type_def, "applyParentJoint", ...)  -- System.Boolean applyParentJoint(via.GameObject, System.UInt32)
sdk.call_native_func(nil, type_def, "applySameJointsConstraint", ...)  -- System.Boolean applySameJointsConstraint(via.GameObject, System.Boolean)
sdk.call_native_func(nil, type_def, "applyStateSet", ...)  -- System.Boolean applyStateSet(via.GameObject, share.ValidatedBool, share.ValidatedBool, System.UInt32)
sdk.call_native_func(nil, type_def, "readyStateController", ...)  -- share.GameObjectStateController readyStateController(via.GameObject)
```

## `share.GameObjectStateSetArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Phase>k__BackingField` | `share.GameObjectStateSetPhase` |  | 16 |
| `AppliedEvent` | `System.Action`1<share.GameObjectStateSetResult>` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.GameObjectStateSetArgs)
:System.Void add_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:share.GameObjectStateSetPhase get_Phase()
:System.Void notifyResult(share.GameObjectStateSetResult)
:System.Void remove_AppliedEvent(System.Action`1<share.GameObjectStateSetResult>)
:System.Void set_Phase(share.GameObjectStateSetPhase)
```

## `share.GameObjectStateSetArgs[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetArgs)
:share.GameObjectStateSetArgs Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetArgs)
:System.Void CopyTo(share.GameObjectStateSetArgs[], System.Int32)
:share.GameObjectStateSetArgs Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetArgs> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetArgs)
:System.Void Insert(System.Int32, share.GameObjectStateSetArgs)
:System.Boolean Remove(share.GameObjectStateSetArgs)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetArgs)
:share.GameObjectStateSetArgs get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetArgs)
```

## `share.GameObjectStateSetMediator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PSR_DEFAULT_CAPACITY` | `System.Int32` | yes | 16 |
| `SSR_DEFAULT_CAPACITY` | `System.Int32` | yes | 16 |
| `<GameObjectStateSetArgsDefault>k__BackingField` | `share.GameObjectStateSetArgs` |  | 16 |
| `<GameObjectParentSetArgsDefault>k__BackingField` | `share.GameObjectParentSetArgs` |  | 24 |
| `<GameObjectJointSetArgsDefault>k__BackingField` | `share.GameObjectJointSetArgs` |  | 32 |
| `<StateSetRequestEntry>k__BackingField` | `System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectStateSetRequest>` |  | 40 |
| `<ParentSetRequestEntry>k__BackingField` | `System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentSetRequest>` |  | 48 |
| `<ParentJointSetRequestEntry>k__BackingField` | `System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectParentJointSetRequest>` |  | 56 |
| `<SameJointsConstraintSetRequestEntry>k__BackingField` | `System.Collections.Generic.List`1<share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest>` |  | 64 |
| `<IsRejectPhase>k__BackingField` | `System.Boolean` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.GameObject` |  | 16 |
| `<JointHash>k__BackingField` | `System.UInt32` |  | 24 |
| `<Args>k__BackingField` | `share.GameObjectJointSetArgs` |  | 32 |

**Methods**

```lua
:share.GameObjectJointSetArgs get_Args()
:System.UInt32 get_JointHash()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectJointSetArgs)
:System.Void set_JointHash(System.UInt32)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectParentJointSetRequest[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:share.GameObjectStateSetMediator.GameObjectParentJointSetRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:System.Void CopyTo(share.GameObjectStateSetMediator.GameObjectParentJointSetRequest[], System.Int32)
:share.GameObjectStateSetMediator.GameObjectParentJointSetRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetMediator.GameObjectParentJointSetRequest> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:System.Void Insert(System.Int32, share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:System.Boolean Remove(share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
:share.GameObjectStateSetMediator.GameObjectParentJointSetRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetMediator.GameObjectParentJointSetRequest)
```

## `share.GameObjectStateSetMediator.GameObjectParentSetRequest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.GameObject` |  | 16 |
| `<Parent>k__BackingField` | `via.GameObject` |  | 24 |
| `<Args>k__BackingField` | `share.GameObjectParentSetArgs` |  | 32 |

**Methods**

```lua
:share.GameObjectParentSetArgs get_Args()
:via.GameObject get_Parent()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectParentSetArgs)
:System.Void set_Parent(via.GameObject)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectParentSetRequest[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:share.GameObjectStateSetMediator.GameObjectParentSetRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:System.Void CopyTo(share.GameObjectStateSetMediator.GameObjectParentSetRequest[], System.Int32)
:share.GameObjectStateSetMediator.GameObjectParentSetRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetMediator.GameObjectParentSetRequest> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:System.Void Insert(System.Int32, share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:System.Boolean Remove(share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetMediator.GameObjectParentSetRequest)
:share.GameObjectStateSetMediator.GameObjectParentSetRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetMediator.GameObjectParentSetRequest)
```

## `share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.GameObject` |  | 16 |
| `<SameJointConstreint>k__BackingField` | `System.Boolean` |  | 24 |
| `<Args>k__BackingField` | `share.GameObjectJointSetArgs` |  | 32 |

**Methods**

```lua
:share.GameObjectJointSetArgs get_Args()
:System.Boolean get_SameJointConstreint()
:via.GameObject get_Target()
:System.Void set_Args(share.GameObjectJointSetArgs)
:System.Void set_SameJointConstreint(System.Boolean)
:System.Void set_Target(via.GameObject)
```

## `share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:System.Void CopyTo(share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest[], System.Int32)
:share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:System.Void Insert(System.Int32, share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:System.Boolean Remove(share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
:share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetMediator.GameObjectSameJointsConstraintSetRequest)
```

## `share.GameObjectStateSetMediator.GameObjectStateSetRequest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.GameObject` |  | 16 |
| `<UpdateSelf>k__BackingField` | `share.ValidatedBool` |  | 24 |
| `<DrawSelf>k__BackingField` | `share.ValidatedBool` |  | 28 |
| `<Layer>k__BackingField` | `System.UInt32` |  | 32 |
| `<Args>k__BackingField` | `share.GameObjectStateSetArgs` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
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

## `share.GameObjectStateSetMediator.GameObjectStateSetRequest[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:share.GameObjectStateSetMediator.GameObjectStateSetRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:System.Void CopyTo(share.GameObjectStateSetMediator.GameObjectStateSetRequest[], System.Int32)
:share.GameObjectStateSetMediator.GameObjectStateSetRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetMediator.GameObjectStateSetRequest> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:System.Void Insert(System.Int32, share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:System.Boolean Remove(share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetMediator.GameObjectStateSetRequest)
:share.GameObjectStateSetMediator.GameObjectStateSetRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetMediator.GameObjectStateSetRequest)
```

## `share.GameObjectStateSetMediatorBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
```

## `share.GameObjectStateSetPhase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FrameHead` | `share.GameObjectStateSetPhase` | yes | 16 |
| `Immediate` | `share.GameObjectStateSetPhase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameObjectStateSetPhase[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetPhase)
:share.GameObjectStateSetPhase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetPhase)
:System.Void CopyTo(share.GameObjectStateSetPhase[], System.Int32)
:share.GameObjectStateSetPhase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetPhase> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetPhase)
:System.Void Insert(System.Int32, share.GameObjectStateSetPhase)
:System.Boolean Remove(share.GameObjectStateSetPhase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetPhase)
:share.GameObjectStateSetPhase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetPhase)
```

## `share.GameObjectStateSetResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Canceled` | `share.GameObjectStateSetResult` | yes | 16 |
| `InvalidArgs` | `share.GameObjectStateSetResult` | yes | 16 |
| `Rejected` | `share.GameObjectStateSetResult` | yes | 16 |
| `Success` | `share.GameObjectStateSetResult` | yes | 16 |
| `Unknown` | `share.GameObjectStateSetResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameObjectStateSetResult[]`

**Methods**

```lua
:System.Void Add(share.GameObjectStateSetResult)
:share.GameObjectStateSetResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameObjectStateSetResult)
:System.Void CopyTo(share.GameObjectStateSetResult[], System.Int32)
:share.GameObjectStateSetResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameObjectStateSetResult> GetEnumerator()
:System.Int32 IndexOf(share.GameObjectStateSetResult)
:System.Void Insert(System.Int32, share.GameObjectStateSetResult)
:System.Boolean Remove(share.GameObjectStateSetResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameObjectStateSetResult)
:share.GameObjectStateSetResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameObjectStateSetResult)
```

## `share.GameRemoveRequestArgs`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.GameRemoveRequestArgs)
:share.SaveLoadRequestArgs getCopy()
```

## `share.GameSaveCompletedEventArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SlotId>k__BackingField` | `System.Int32` |  | 16 |
| `<Result>k__BackingField` | `share.SaveLoadProcessResult` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(System.Int32, share.SaveLoadProcessResult)
:share.SaveLoadProcessResult get_Result()
:System.Int32 get_SlotId()
:System.Void set_Result(share.SaveLoadProcessResult)
:System.Void set_SlotId(System.Int32)
```

## `share.GameSaveRequestArgs`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.GameSaveRequestArgs)
:share.SaveLoadRequestArgs getCopy()
:System.UInt64 getSaveDataSize()
```

## `share.GameSaveTakeOverArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<NextRoundCount>k__BackingField` | `System.Int32` |  | 16 |
| `<Difficulty>k__BackingField` | `chainsaw.CampaignManager.Difficulty` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(chainsaw.CampaignManager.Difficulty, System.Int32)
:System.Void .ctor(share.GameSaveTakeOverArgs)
:share.GameSaveTakeOverArgs getCopy()
:chainsaw.CampaignManager.Difficulty get_Difficulty()
:System.Int32 get_NextRoundCount()
:System.Void set_Difficulty(chainsaw.CampaignManager.Difficulty)
:System.Void set_NextRoundCount(System.Int32)
```

## `share.GameStateArgument`

_No fields or methods._

## `share.GameStateBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CurrentPhase>k__BackingField` | `share.GameStateBase.ControlPhase` |  | 16 |
| `OnSetup` | `System.Action` |  | 24 |
| `OnEnter` | `System.Action` |  | 32 |
| `OnLeave` | `System.Action` |  | 40 |
| `OnSetupOnce` | `System.Action` |  | 48 |
| `OnEnterOnce` | `System.Action` |  | 56 |
| `OnLeaveOnce` | `System.Action` |  | 64 |
| `<StateChangeable>k__BackingField` | `System.Boolean` |  | 72 |
| `CurrentArgument` | `share.GameStateArgument` |  | 80 |
| `TargetPhase` | `share.GameStateBase.ControlPhase` |  | 88 |

**Methods**

```lua
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Finalize` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `Initialize` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `Leave` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `None` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `Setup` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `Update` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `Wait` | `share.GameStateBase.ControlPhase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.GameStateBase.ControlPhase[]`

**Methods**

```lua
:System.Void Add(share.GameStateBase.ControlPhase)
:share.GameStateBase.ControlPhase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.GameStateBase.ControlPhase)
:System.Void CopyTo(share.GameStateBase.ControlPhase[], System.Int32)
:share.GameStateBase.ControlPhase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.GameStateBase.ControlPhase> GetEnumerator()
:System.Int32 IndexOf(share.GameStateBase.ControlPhase)
:System.Void Insert(System.Int32, share.GameStateBase.ControlPhase)
:System.Boolean Remove(share.GameStateBase.ControlPhase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.GameStateBase.ControlPhase)
:share.GameStateBase.ControlPhase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.GameStateBase.ControlPhase)
```

## `share.GpuQualityPerformanceBalancer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Balancer` | `share.QualityPerformanceBalancer` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertHexToInt", ...)  -- System.Int32 convertHexToInt(System.Char)
sdk.call_native_func(nil, type_def, "toUint64", ...)  -- System.Void toUint64(System.Guid, System.UInt64, System.UInt64)
sdk.call_native_func(nil, type_def, "toUint64Lower", ...)  -- System.UInt64 toUint64Lower(System.Guid)
sdk.call_native_func(nil, type_def, "toUint64Upper", ...)  -- System.UInt64 toUint64Upper(System.Guid)
```

## `share.HIDDefine`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MouseAnyButton` | `via.hid.MouseButton` | yes | 16 |
| `S_Command_None` | `System.UInt32` | yes | 16 |
| `AllKeyList` | `via.hid.KeyboardKey[]` | yes | 24 |
| `AnyKeyList` | `System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>` | yes | 32 |
| `KeyboardKeyToHidMouseButton` | `System.Collections.Generic.Dictionary`2<via.hid.KeyboardKey,via.hid.MouseButton>` | yes | 40 |
| `BindableKeyList` | `System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>` | yes | 48 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getBindableKeyList", ...)  -- System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> getBindableKeyList()
```

## `share.IAppInterfaceBase`

_No fields or methods._

## `share.IGameSaveData`

_No fields or methods._

## `share.IGameSaveData[]`

**Methods**

```lua
:System.Void Add(share.IGameSaveData)
:share.IGameSaveData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.IGameSaveData)
:System.Void CopyTo(share.IGameSaveData[], System.Int32)
:share.IGameSaveData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.IGameSaveData> GetEnumerator()
:System.Int32 IndexOf(share.IGameSaveData)
:System.Void Insert(System.Int32, share.IGameSaveData)
:System.Boolean Remove(share.IGameSaveData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.IGameSaveData)
:share.IGameSaveData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.IGameSaveData)
```

## `share.IGameSaveSlotDetailHolder`

_No fields or methods._

## `share.ISaveLoadEventReciever`

_No fields or methods._

## `share.ISystemSaveData`

_No fields or methods._

## `share.ISystemSaveData[]`

**Methods**

```lua
:System.Void Add(share.ISystemSaveData)
:share.ISystemSaveData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ISystemSaveData)
:System.Void CopyTo(share.ISystemSaveData[], System.Int32)
:share.ISystemSaveData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ISystemSaveData> GetEnumerator()
:System.Int32 IndexOf(share.ISystemSaveData)
:System.Void Insert(System.Int32, share.ISystemSaveData)
:System.Boolean Remove(share.ISystemSaveData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ISystemSaveData)
:share.ISystemSaveData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ISystemSaveData)
```

## `share.ISystemSaveSlotDetailHolder`

_No fields or methods._

## `share.IValidatable`

_No fields or methods._

## `share.Log`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `INVALID_OBJECT_PREFIX` | `System.String` | yes | 16 |
| `LOCK` | `System.Object` | yes | 16 |
| `TRACE_PREFIX` | `System.String` | yes | 16 |
| `_Logs` | `System.String[]` | yes | 24 |
| `_LogsIndex` | `System.Int32` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getHistory", ...)  -- System.String getHistory()
sdk.call_native_func(nil, type_def, "makeFormat", ...)  -- System.String makeFormat(System.String)
```

## `share.Log.Level`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Critical` | `share.Log.Level` | yes | 16 |
| `Debug` | `share.Log.Level` | yes | 16 |
| `Error` | `share.Log.Level` | yes | 16 |
| `Info` | `share.Log.Level` | yes | 16 |
| `Notice` | `share.Log.Level` | yes | 16 |
| `Warning` | `share.Log.Level` | yes | 16 |
| `WarningOnlyLog` | `share.Log.Level` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.Log.Level[]`

**Methods**

```lua
:System.Void Add(share.Log.Level)
:share.Log.Level Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.Log.Level)
:System.Void CopyTo(share.Log.Level[], System.Int32)
:share.Log.Level Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.Log.Level> GetEnumerator()
:System.Int32 IndexOf(share.Log.Level)
:System.Void Insert(System.Int32, share.Log.Level)
:System.Boolean Remove(share.Log.Level)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.Log.Level)
:share.Log.Level get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.Log.Level)
```

## `share.LogicalOperationAndOr`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AND` | `share.LogicalOperationAndOr` | yes | 16 |
| `OR` | `share.LogicalOperationAndOr` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.LogicalOperationAndOr[]`

**Methods**

```lua
:System.Void Add(share.LogicalOperationAndOr)
:share.LogicalOperationAndOr Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.LogicalOperationAndOr)
:System.Void CopyTo(share.LogicalOperationAndOr[], System.Int32)
:share.LogicalOperationAndOr Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.LogicalOperationAndOr> GetEnumerator()
:System.Int32 IndexOf(share.LogicalOperationAndOr)
:System.Void Insert(System.Int32, share.LogicalOperationAndOr)
:System.Boolean Remove(share.LogicalOperationAndOr)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.LogicalOperationAndOr)
:share.LogicalOperationAndOr get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.LogicalOperationAndOr)
```

## `share.MainModeDefine`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "isCoop", ...)  -- System.Boolean isCoop(share.GameModeType)
```

## `share.MainModeManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CurrPhase>k__BackingField` | `share.MainModeManager.Phase` |  | 16 |
| `<CurrGameModeType>k__BackingField` | `share.GameModeType` |  | 20 |
| `GameStateCollection` | `System.Collections.Generic.Dictionary`2<System.Type,share.MainModeManager.GameStateControl>` |  | 24 |
| `StateChangeRequestQueue` | `System.Collections.Generic.Queue`1<share.MainModeManager.GameStateChangeRequest>` |  | 32 |
| `CurrentGameState` | `share.MainModeManager.GameStateControl` |  | 40 |
| `PreviousGameState` | `share.MainModeManager.GameStateControl` |  | 48 |
| `NextGameState` | `share.MainModeManager.GameStateControl` |  | 56 |
| `StartupGameState` | `System.Type` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<NextState>k__BackingField` | `System.Type` |  | 16 |
| `<Argument>k__BackingField` | `share.GameStateArgument` |  | 24 |

**Methods**

```lua
:System.Void .ctor(System.Type, share.GameStateArgument)
:share.GameStateArgument get_Argument()
:System.Type get_NextState()
:System.Void set_Argument(share.GameStateArgument)
:System.Void set_NextState(System.Type)
```

## `share.MainModeManager.GameStateChangeRequest[]`

**Methods**

```lua
:System.Void Add(share.MainModeManager.GameStateChangeRequest)
:share.MainModeManager.GameStateChangeRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.MainModeManager.GameStateChangeRequest)
:System.Void CopyTo(share.MainModeManager.GameStateChangeRequest[], System.Int32)
:share.MainModeManager.GameStateChangeRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.MainModeManager.GameStateChangeRequest> GetEnumerator()
:System.Int32 IndexOf(share.MainModeManager.GameStateChangeRequest)
:System.Void Insert(System.Int32, share.MainModeManager.GameStateChangeRequest)
:System.Boolean Remove(share.MainModeManager.GameStateChangeRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.MainModeManager.GameStateChangeRequest)
:share.MainModeManager.GameStateChangeRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.MainModeManager.GameStateChangeRequest)
```

## `share.MainModeManager.GameStateControl`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GameState` | `share.GameStateBase` |  | 16 |
| `Argument` | `share.GameStateArgument` |  | 24 |

## `share.MainModeManager.GameStateControl[]`

**Methods**

```lua
:System.Void Add(share.MainModeManager.GameStateControl)
:share.MainModeManager.GameStateControl Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.MainModeManager.GameStateControl)
:System.Void CopyTo(share.MainModeManager.GameStateControl[], System.Int32)
:share.MainModeManager.GameStateControl Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.MainModeManager.GameStateControl> GetEnumerator()
:System.Int32 IndexOf(share.MainModeManager.GameStateControl)
:System.Void Insert(System.Int32, share.MainModeManager.GameStateControl)
:System.Boolean Remove(share.MainModeManager.GameStateControl)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.MainModeManager.GameStateControl)
:share.MainModeManager.GameStateControl get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.MainModeManager.GameStateControl)
```

## `share.MainModeManager.Phase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FinalizeGameState` | `share.MainModeManager.Phase` | yes | 16 |
| `FinalizingGameState` | `share.MainModeManager.Phase` | yes | 16 |
| `GameStateLeave` | `share.MainModeManager.Phase` | yes | 16 |
| `GameStateSetup` | `share.MainModeManager.Phase` | yes | 16 |
| `GameStateUpdate` | `share.MainModeManager.Phase` | yes | 16 |
| `InitializeGameState` | `share.MainModeManager.Phase` | yes | 16 |
| `InitializingGameState` | `share.MainModeManager.Phase` | yes | 16 |
| `Invalid` | `share.MainModeManager.Phase` | yes | 16 |
| `ModeInitalize` | `share.MainModeManager.Phase` | yes | 16 |
| `ReadyForSetup` | `share.MainModeManager.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.MainModeManager.Phase[]`

**Methods**

```lua
:System.Void Add(share.MainModeManager.Phase)
:share.MainModeManager.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.MainModeManager.Phase)
:System.Void CopyTo(share.MainModeManager.Phase[], System.Int32)
:share.MainModeManager.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.MainModeManager.Phase> GetEnumerator()
:System.Int32 IndexOf(share.MainModeManager.Phase)
:System.Void Insert(System.Int32, share.MainModeManager.Phase)
:System.Boolean Remove(share.MainModeManager.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.MainModeManager.Phase)
:share.MainModeManager.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.MainModeManager.Phase)
```

## `share.MainModeManagerBehavior`

**Methods**

```lua
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.MotionFsmActionTiming`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `End` | `share.MotionFsmActionTiming` | yes | 16 |
| `Sequence` | `share.MotionFsmActionTiming` | yes | 16 |
| `Start` | `share.MotionFsmActionTiming` | yes | 16 |
| `Update` | `share.MotionFsmActionTiming` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.MotionFsmActionTiming[]`

**Methods**

```lua
:System.Void Add(share.MotionFsmActionTiming)
:share.MotionFsmActionTiming Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.MotionFsmActionTiming)
:System.Void CopyTo(share.MotionFsmActionTiming[], System.Int32)
:share.MotionFsmActionTiming Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.MotionFsmActionTiming> GetEnumerator()
:System.Int32 IndexOf(share.MotionFsmActionTiming)
:System.Void Insert(System.Int32, share.MotionFsmActionTiming)
:System.Boolean Remove(share.MotionFsmActionTiming)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.MotionFsmActionTiming)
:share.MotionFsmActionTiming get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.MotionFsmActionTiming)
```

## `share.MutexObject`

_No fields or methods._

## `share.ObjectRelationType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Child` | `share.ObjectRelationType` | yes | 16 |
| `Children` | `share.ObjectRelationType` | yes | 16 |
| `Parent` | `share.ObjectRelationType` | yes | 16 |
| `Self` | `share.ObjectRelationType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ObjectRelationType[]`

**Methods**

```lua
:System.Void Add(share.ObjectRelationType)
:share.ObjectRelationType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ObjectRelationType)
:System.Void CopyTo(share.ObjectRelationType[], System.Int32)
:share.ObjectRelationType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ObjectRelationType> GetEnumerator()
:System.Int32 IndexOf(share.ObjectRelationType)
:System.Void Insert(System.Int32, share.ObjectRelationType)
:System.Boolean Remove(share.ObjectRelationType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ObjectRelationType)
:share.ObjectRelationType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ObjectRelationType)
```

## `share.PauseManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_CacheTagValues` | `System.UInt32[]` | yes | 16 |
| `_PauseParameters` | `share.PauseManager.PauseParameter[]` |  | 16 |
| `_CustomPauseParameters` | `System.Collections.Generic.Dictionary`2<System.UInt32,share.PauseManager.PauseParameter>` |  | 24 |
| `_CachePause` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Boolean>` |  | 32 |
| `_TargetParameters` | `share.PauseManager.TargetParameter[]` |  | 40 |
| `_Pause` | `System.Collections.Generic.List`1<share.PauseManager.PauseInfo>` |  | 48 |
| `_CustomPause` | `System.Collections.Generic.List`1<share.PauseManager.CustomPauseInfo>` |  | 56 |
| `_CurrentTargetPauseUpdate` | `System.UInt32` |  | 64 |
| `_CurrentTargetPauseDraw` | `System.UInt32` |  | 68 |
| `_RequestLockObject` | `via.threading.SimpleReaderWriterLock` |  | 72 |
| `_Request` | `share.PauseManager.Requests` |  | 80 |
| `_RequestLate` | `share.PauseManager.Requests` |  | 88 |
| `_TmpExecInvoker` | `System.Collections.Generic.List`1<share.PauseManager.RequestBase>` |  | 96 |
| `_GimmickInUseInfos` | `System.Collections.Generic.List`1<share.PauseManager.GimmickInUseInfo>` |  | 104 |
| `_CntGimmickInUseHandle` | `System.UInt32` |  | 112 |
| `_EventHolders` | `share.PauseManager.EventHolder[]` |  | 120 |
| `_LockDelegate` | `share.MutexObject` |  | 128 |
| `_OnBeforeApply` | `System.Action`1<share.PauseManager.ArgBeforeApply>` |  | 136 |
| `_OnApplyed` | `System.Action`1<share.PauseManager.ArgApplyed>` |  | 144 |

**Methods**

```lua
:System.Void .ctor()
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.PauseManager.ApplyTiming`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FrameHead` | `share.PauseManager.ApplyTiming` | yes | 16 |
| `LateUpdate` | `share.PauseManager.ApplyTiming` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.ApplyTiming[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.ApplyTiming)
:share.PauseManager.ApplyTiming Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.ApplyTiming)
:System.Void CopyTo(share.PauseManager.ApplyTiming[], System.Int32)
:share.PauseManager.ApplyTiming Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.ApplyTiming> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.ApplyTiming)
:System.Void Insert(System.Int32, share.PauseManager.ApplyTiming)
:System.Boolean Remove(share.PauseManager.ApplyTiming)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.ApplyTiming)
:share.PauseManager.ApplyTiming get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.ApplyTiming)
```

## `share.PauseManager.ArgApplyed`

_No fields or methods._

## `share.PauseManager.ArgBeforeApply`

_No fields or methods._

## `share.PauseManager.CustomPauseInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pause` | `System.UInt32` |  | 16 |
| `OwnerName` | `System.String` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.PauseManager.CustomRequestInfo)
```

## `share.PauseManager.CustomPauseInfo[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.CustomPauseInfo)
:share.PauseManager.CustomPauseInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.CustomPauseInfo)
:System.Void CopyTo(share.PauseManager.CustomPauseInfo[], System.Int32)
:share.PauseManager.CustomPauseInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.CustomPauseInfo> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.CustomPauseInfo)
:System.Void Insert(System.Int32, share.PauseManager.CustomPauseInfo)
:System.Boolean Remove(share.PauseManager.CustomPauseInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.CustomPauseInfo)
:share.PauseManager.CustomPauseInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.CustomPauseInfo)
```

## `share.PauseManager.CustomRequestInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pause` | `System.UInt32` |  | 24 |
| `OwnerName` | `System.String` |  | 32 |

## `share.PauseManager.CustomRequestInfo[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.CustomRequestInfo)
:share.PauseManager.CustomRequestInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.CustomRequestInfo)
:System.Void CopyTo(share.PauseManager.CustomRequestInfo[], System.Int32)
:share.PauseManager.CustomRequestInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.CustomRequestInfo> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.CustomRequestInfo)
:System.Void Insert(System.Int32, share.PauseManager.CustomRequestInfo)
:System.Boolean Remove(share.PauseManager.CustomRequestInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.CustomRequestInfo)
:share.PauseManager.CustomRequestInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.CustomRequestInfo)
```

## `share.PauseManager.EventHolder`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnChangePauseUpdate` | `System.Action`1<System.Boolean>` |  | 16 |
| `OnChangePauseDraw` | `System.Action`1<System.Boolean>` |  | 24 |

**Methods**

```lua
:System.Void add_OnChangePauseDraw(System.Action`1<System.Boolean>)
:System.Void add_OnChangePauseUpdate(System.Action`1<System.Boolean>)
:System.Void fireOnChangePauseDraw(System.Boolean)
:System.Void fireOnChangePauseUpdate(System.Boolean)
:System.Void remove_OnChangePauseDraw(System.Action`1<System.Boolean>)
:System.Void remove_OnChangePauseUpdate(System.Action`1<System.Boolean>)
```

## `share.PauseManager.EventHolder[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.EventHolder)
:share.PauseManager.EventHolder Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.EventHolder)
:System.Void CopyTo(share.PauseManager.EventHolder[], System.Int32)
:share.PauseManager.EventHolder Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.EventHolder> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.EventHolder)
:System.Void Insert(System.Int32, share.PauseManager.EventHolder)
:System.Boolean Remove(share.PauseManager.EventHolder)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.EventHolder)
:share.PauseManager.EventHolder get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.EventHolder)
```

## `share.PauseManager.GimmickInUseInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `User` | `share.PauseManager.GimmickInUseInfo.UserType` |  | 16 |
| `Gimmick` | `via.GameObject` |  | 24 |
| `RequestUnregister` | `System.Boolean` |  | 32 |
| `HandleID` | `System.UInt32` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
```

## `share.PauseManager.GimmickInUseInfo.UserType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Enemy` | `share.PauseManager.GimmickInUseInfo.UserType` | yes | 16 |
| `Player` | `share.PauseManager.GimmickInUseInfo.UserType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.GimmickInUseInfo.UserType[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.GimmickInUseInfo.UserType)
:share.PauseManager.GimmickInUseInfo.UserType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.GimmickInUseInfo.UserType)
:System.Void CopyTo(share.PauseManager.GimmickInUseInfo.UserType[], System.Int32)
:share.PauseManager.GimmickInUseInfo.UserType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.GimmickInUseInfo.UserType> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.GimmickInUseInfo.UserType)
:System.Void Insert(System.Int32, share.PauseManager.GimmickInUseInfo.UserType)
:System.Boolean Remove(share.PauseManager.GimmickInUseInfo.UserType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.GimmickInUseInfo.UserType)
:share.PauseManager.GimmickInUseInfo.UserType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.GimmickInUseInfo.UserType)
```

## `share.PauseManager.GimmickInUseInfo[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.GimmickInUseInfo)
:share.PauseManager.GimmickInUseInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.GimmickInUseInfo)
:System.Void CopyTo(share.PauseManager.GimmickInUseInfo[], System.Int32)
:share.PauseManager.GimmickInUseInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.GimmickInUseInfo> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.GimmickInUseInfo)
:System.Void Insert(System.Int32, share.PauseManager.GimmickInUseInfo)
:System.Boolean Remove(share.PauseManager.GimmickInUseInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.GimmickInUseInfo)
:share.PauseManager.GimmickInUseInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.GimmickInUseInfo)
```

## `share.PauseManager.Option`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnExec` | `System.Action` |  | 16 |
| `Timing` | `share.PauseManager.ApplyTiming` |  | 24 |

## `share.PauseManager.PauseFlag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DebugPause` | `share.PauseManager.PauseFlag` | yes | 16 |
| `Dip` | `share.PauseManager.PauseFlag` | yes | 16 |
| `EventMovie` | `share.PauseManager.PauseFlag` | yes | 16 |
| `EventStop` | `share.PauseManager.PauseFlag` | yes | 16 |
| `EventTimeline` | `share.PauseManager.PauseFlag` | yes | 16 |
| `Loading` | `share.PauseManager.PauseFlag` | yes | 16 |
| `None` | `share.PauseManager.PauseFlag` | yes | 16 |
| `PhotoEnemy` | `share.PauseManager.PauseFlag` | yes | 16 |
| `PhotoEnvAnimal` | `share.PauseManager.PauseFlag` | yes | 16 |
| `PhotoNPC` | `share.PauseManager.PauseFlag` | yes | 16 |
| `PhotoPlayer` | `share.PauseManager.PauseFlag` | yes | 16 |
| `StopUpdate` | `share.PauseManager.PauseFlag` | yes | 16 |
| `StopUpdateWithoutCamera` | `share.PauseManager.PauseFlag` | yes | 16 |
| `Title` | `share.PauseManager.PauseFlag` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.PauseFlag[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.PauseFlag)
:share.PauseManager.PauseFlag Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.PauseFlag)
:System.Void CopyTo(share.PauseManager.PauseFlag[], System.Int32)
:share.PauseManager.PauseFlag Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.PauseFlag> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.PauseFlag)
:System.Void Insert(System.Int32, share.PauseManager.PauseFlag)
:System.Boolean Remove(share.PauseManager.PauseFlag)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.PauseFlag)
:share.PauseManager.PauseFlag get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.PauseFlag)
```

## `share.PauseManager.PauseInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pause` | `share.PauseManager.PauseType` |  | 16 |
| `OwnerName` | `System.String` |  | 24 |

**Methods**

```lua
:System.Void .ctor(share.PauseManager.PauseType, System.String)
:System.String ToString()
```

## `share.PauseManager.PauseInfo[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.PauseInfo)
:share.PauseManager.PauseInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.PauseInfo)
:System.Void CopyTo(share.PauseManager.PauseInfo[], System.Int32)
:share.PauseManager.PauseInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.PauseInfo> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.PauseInfo)
:System.Void Insert(System.Int32, share.PauseManager.PauseInfo)
:System.Boolean Remove(share.PauseManager.PauseInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.PauseInfo)
:share.PauseManager.PauseInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.PauseInfo)
```

## `share.PauseManager.PauseParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TargetUpdate` | `share.PauseManager.TargetFlag` |  | 16 |
| `TargetDraw` | `share.PauseManager.TargetFlag` |  | 20 |

**Methods**

```lua
:System.UInt32 get_TargetDrawBit()
:System.UInt32 get_TargetUpdateBit()
```

## `share.PauseManager.PauseParameter[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.PauseParameter)
:share.PauseManager.PauseParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.PauseParameter)
:System.Void CopyTo(share.PauseManager.PauseParameter[], System.Int32)
:share.PauseManager.PauseParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.PauseParameter> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.PauseParameter)
:System.Void Insert(System.Int32, share.PauseManager.PauseParameter)
:System.Boolean Remove(share.PauseManager.PauseParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.PauseParameter)
:share.PauseManager.PauseParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.PauseParameter)
```

## `share.PauseManager.PauseType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `CampaignJumpA` | `share.PauseManager.PauseType` | yes | 16 |
| `CampaignJumpB` | `share.PauseManager.PauseType` | yes | 16 |
| `CampaignJumpC` | `share.PauseManager.PauseType` | yes | 16 |
| `CampaignManagerEnvSceneLoader` | `share.PauseManager.PauseType` | yes | 16 |
| `DebugPause` | `share.PauseManager.PauseType` | yes | 16 |
| `Dip` | `share.PauseManager.PauseType` | yes | 16 |
| `EventMovie` | `share.PauseManager.PauseType` | yes | 16 |
| `EventStop` | `share.PauseManager.PauseType` | yes | 16 |
| `EventTimeline` | `share.PauseManager.PauseType` | yes | 16 |
| `Loading` | `share.PauseManager.PauseType` | yes | 16 |
| `None` | `share.PauseManager.PauseType` | yes | 16 |
| `PhotoEnemy` | `share.PauseManager.PauseType` | yes | 16 |
| `PhotoEnvAnimal` | `share.PauseManager.PauseType` | yes | 16 |
| `PhotoMode` | `share.PauseManager.PauseType` | yes | 16 |
| `PhotoNPC` | `share.PauseManager.PauseType` | yes | 16 |
| `PhotoPlayer` | `share.PauseManager.PauseType` | yes | 16 |
| `StopUpdate` | `share.PauseManager.PauseType` | yes | 16 |
| `StopUpdateWithoutCamera` | `share.PauseManager.PauseType` | yes | 16 |
| `Title` | `share.PauseManager.PauseType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.PauseType[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.PauseType)
:share.PauseManager.PauseType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.PauseType)
:System.Void CopyTo(share.PauseManager.PauseType[], System.Int32)
:share.PauseManager.PauseType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.PauseType> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.PauseType)
:System.Void Insert(System.Int32, share.PauseManager.PauseType)
:System.Boolean Remove(share.PauseManager.PauseType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.PauseType)
:share.PauseManager.PauseType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.PauseType)
```

## `share.PauseManager.RequestBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `OnExec` | `System.Action` |  | 16 |

## `share.PauseManager.RequestBase[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.RequestBase)
:share.PauseManager.RequestBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.RequestBase)
:System.Void CopyTo(share.PauseManager.RequestBase[], System.Int32)
:share.PauseManager.RequestBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.RequestBase> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.RequestBase)
:System.Void Insert(System.Int32, share.PauseManager.RequestBase)
:System.Boolean Remove(share.PauseManager.RequestBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.RequestBase)
:share.PauseManager.RequestBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.RequestBase)
```

## `share.PauseManager.RequestInfo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Pause` | `share.PauseManager.PauseType` |  | 24 |
| `OwnerName` | `System.String` |  | 32 |

## `share.PauseManager.RequestInfo[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.RequestInfo)
:share.PauseManager.RequestInfo Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.RequestInfo)
:System.Void CopyTo(share.PauseManager.RequestInfo[], System.Int32)
:share.PauseManager.RequestInfo Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.RequestInfo> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.RequestInfo)
:System.Void Insert(System.Int32, share.PauseManager.RequestInfo)
:System.Boolean Remove(share.PauseManager.RequestInfo)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.RequestInfo)
:share.PauseManager.RequestInfo get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.RequestInfo)
```

## `share.PauseManager.Requests`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Start` | `System.Collections.Generic.List`1<share.PauseManager.RequestInfo>` |  | 16 |
| `End` | `System.Collections.Generic.List`1<share.PauseManager.RequestInfo>` |  | 24 |
| `CustomStart` | `System.Collections.Generic.List`1<share.PauseManager.CustomRequestInfo>` |  | 32 |
| `CustomEnd` | `System.Collections.Generic.List`1<share.PauseManager.CustomRequestInfo>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
```

## `share.PauseManager.TargetFlag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Dynamics` | `share.PauseManager.TargetFlag` | yes | 16 |
| `None` | `share.PauseManager.TargetFlag` | yes | 16 |
| `Sound` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagCamera` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagDoll` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEffect` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEnemy` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEnvironment` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEvent` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEventStop` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagEventStopUpdate` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagGUI` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagGimmick` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagGmPause` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagItem` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagLevel` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPhotoDrawOff` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPhotoEnemy` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPhotoEnvAnimal` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPhotoNPC` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPhotoPlayer` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagPlayer` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagShell` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagWeaponMerchant` | `share.PauseManager.TargetFlag` | yes | 16 |
| `TagZone` | `share.PauseManager.TargetFlag` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.TargetFlag[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.TargetFlag)
:share.PauseManager.TargetFlag Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.TargetFlag)
:System.Void CopyTo(share.PauseManager.TargetFlag[], System.Int32)
:share.PauseManager.TargetFlag Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.TargetFlag> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.TargetFlag)
:System.Void Insert(System.Int32, share.PauseManager.TargetFlag)
:System.Boolean Remove(share.PauseManager.TargetFlag)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.TargetFlag)
:share.PauseManager.TargetFlag get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.TargetFlag)
```

## `share.PauseManager.TargetParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<IsPausedUpdate>k__BackingField` | `System.Boolean` |  | 16 |
| `<IsPausedDraw>k__BackingField` | `System.Boolean` |  | 17 |
| `_OnChangeUpdate` | `System.Action`1<System.Boolean>` |  | 24 |
| `_OnChangeDraw` | `System.Action`1<System.Boolean>` |  | 32 |

**Methods**

```lua
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PauseDynamics` | `System.Action`1<System.Boolean>` | yes | 16 |

**Methods**

```lua
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameterSound`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PauseSound` | `System.Action`1<System.Boolean>` | yes | 16 |

**Methods**

```lua
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameterTag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TagName` | `System.String` |  | 40 |
| `TagBit` | `System.Int32` |  | 48 |

**Methods**

```lua
:System.Void pauseDraw(System.Boolean)
:System.Void pauseUpdate(System.Boolean)
```

## `share.PauseManager.TargetParameter[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.TargetParameter)
:share.PauseManager.TargetParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.TargetParameter)
:System.Void CopyTo(share.PauseManager.TargetParameter[], System.Int32)
:share.PauseManager.TargetParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.TargetParameter> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.TargetParameter)
:System.Void Insert(System.Int32, share.PauseManager.TargetParameter)
:System.Boolean Remove(share.PauseManager.TargetParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.TargetParameter)
:share.PauseManager.TargetParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.TargetParameter)
```

## `share.PauseManager.TargetType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Dynamics` | `share.PauseManager.TargetType` | yes | 16 |
| `Max` | `share.PauseManager.TargetType` | yes | 16 |
| `Sound` | `share.PauseManager.TargetType` | yes | 16 |
| `TagCamera` | `share.PauseManager.TargetType` | yes | 16 |
| `TagDoll` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEffect` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEnemy` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEnvironment` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEvent` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEventStop` | `share.PauseManager.TargetType` | yes | 16 |
| `TagEventStopUpdate` | `share.PauseManager.TargetType` | yes | 16 |
| `TagGUI` | `share.PauseManager.TargetType` | yes | 16 |
| `TagGimmick` | `share.PauseManager.TargetType` | yes | 16 |
| `TagGmPause` | `share.PauseManager.TargetType` | yes | 16 |
| `TagItem` | `share.PauseManager.TargetType` | yes | 16 |
| `TagLevel` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPhotoDrawOff` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPhotoEnemy` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPhotoEnvAnimal` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPhotoNPC` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPhotoPlayer` | `share.PauseManager.TargetType` | yes | 16 |
| `TagPlayer` | `share.PauseManager.TargetType` | yes | 16 |
| `TagShell` | `share.PauseManager.TargetType` | yes | 16 |
| `TagWeaponMerchant` | `share.PauseManager.TargetType` | yes | 16 |
| `TagZone` | `share.PauseManager.TargetType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PauseManager.TargetType[]`

**Methods**

```lua
:System.Void Add(share.PauseManager.TargetType)
:share.PauseManager.TargetType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PauseManager.TargetType)
:System.Void CopyTo(share.PauseManager.TargetType[], System.Int32)
:share.PauseManager.TargetType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PauseManager.TargetType> GetEnumerator()
:System.Int32 IndexOf(share.PauseManager.TargetType)
:System.Void Insert(System.Int32, share.PauseManager.TargetType)
:System.Boolean Remove(share.PauseManager.TargetType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PauseManager.TargetType)
:share.PauseManager.TargetType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PauseManager.TargetType)
```

## `share.PauseManagerBehavior`

**Methods**

```lua
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.PrefabController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_IsConvertVec3ToPosition` | `System.Boolean` |  | 40 |
| `_LoadPriority` | `System.Int16` |  | 42 |
| `<DynamicLoadPriority>k__BackingField` | `System.Func`2<share.PrefabController,System.Int16>` |  | 48 |
| `_LastRefCount` | `System.Int32` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.Prefab)
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

## `share.PrefabController[]`

**Methods**

```lua
:System.Void Add(share.PrefabController)
:share.PrefabController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PrefabController)
:System.Void CopyTo(share.PrefabController[], System.Int32)
:share.PrefabController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PrefabController> GetEnumerator()
:System.Int32 IndexOf(share.PrefabController)
:System.Void Insert(System.Int32, share.PrefabController)
:System.Boolean Remove(share.PrefabController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PrefabController)
:share.PrefabController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PrefabController)
```

## `share.PrefabInstantiateArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DefaultImmidiate` | `share.PrefabInstantiateArgs` | yes | 16 |
| `<Phase>k__BackingField` | `share.PrefabInstantiatePhase` |  | 16 |
| `<Priority>k__BackingField` | `System.Int16` |  | 20 |
| `DynamicPriority` | `System.Func`1<System.Int16>` |  | 24 |
| `<Scale>k__BackingField` | `System.Nullable`1<via.vec3>` |  | 32 |
| `InstantiatedEvent` | `System.Action`1<share.PrefabInstantiateResults>` |  | 64 |
| `WithdrawEvent` | `System.Func`1<System.Boolean>` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.PrefabInstantiateArgs)
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

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.PrefabInstantiateDistributor`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ProcFinished>k__BackingField` | `System.Boolean` |  | 80 |
| `<ProcGroupID>k__BackingField` | `System.Int32` |  | 84 |
| `<ProcRequestSkipIndex>k__BackingField` | `System.Int32` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
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

## `share.PrefabInstantiateDistributor[]`

**Methods**

```lua
:System.Void Add(share.PrefabInstantiateDistributor)
:share.PrefabInstantiateDistributor Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PrefabInstantiateDistributor)
:System.Void CopyTo(share.PrefabInstantiateDistributor[], System.Int32)
:share.PrefabInstantiateDistributor Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PrefabInstantiateDistributor> GetEnumerator()
:System.Int32 IndexOf(share.PrefabInstantiateDistributor)
:System.Void Insert(System.Int32, share.PrefabInstantiateDistributor)
:System.Boolean Remove(share.PrefabInstantiateDistributor)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PrefabInstantiateDistributor)
:share.PrefabInstantiateDistributor get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PrefabInstantiateDistributor)
```

## `share.PrefabInstantiateMediator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `PIE_DEFAULT_CAPACITY` | `System.Int32` | yes | 16 |
| `PIR_DEFAULT_CAPACITY` | `System.Int32` | yes | 16 |
| `<PrefabInstantiateArgsDefault>k__BackingField` | `share.PrefabInstantiateArgs` |  | 16 |
| `<InstantiateTimeBudgetOnFrameHead>k__BackingField` | `System.Single` |  | 24 |
| `<InstantiateTimeBudgetOnFrameTail>k__BackingField` | `System.Single` |  | 28 |
| `<HasInstantiateRequest>k__BackingField` | `System.Boolean` |  | 32 |
| `<IsRejectPhase>k__BackingField` | `System.Boolean` |  | 33 |
| `<InstantiateFrameHeadProfile>k__BackingField` | `share.AverageTimeProfiler` |  | 40 |
| `<InstantiateFrameTailProfile>k__BackingField` | `share.AverageTimeProfiler` |  | 48 |
| `<RequestEntry>k__BackingField` | `System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>` |  | 56 |
| `<ExecuteFrameHeadEntry>k__BackingField` | `System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>` |  | 64 |
| `<ExecuteFrameTailEntry>k__BackingField` | `System.Collections.Generic.List`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest>` |  | 72 |
| `<Distributors>k__BackingField` | `System.Collections.Generic.List`1<share.PrefabInstantiateDistributor>` |  | 80 |
| `_InstantiateTimeBudgetFree` | `System.Boolean` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Prefab>k__BackingField` | `share.PrefabController` |  | 16 |
| `<Position>k__BackingField` | `via.Position` |  | 24 |
| `<Rotation>k__BackingField` | `via.Quaternion` |  | 48 |
| `<Folder>k__BackingField` | `via.Folder` |  | 64 |
| `<Requester>k__BackingField` | `System.Object` |  | 72 |
| `<Args>k__BackingField` | `share.PrefabInstantiateArgs` |  | 80 |
| `<Executed>k__BackingField` | `System.Boolean` |  | 88 |
| `<Priority>k__BackingField` | `System.Int32` |  | 92 |
| `<ProgressedFrame>k__BackingField` | `System.Single` |  | 96 |
| `<Reserved>k__BackingField` | `System.Boolean` |  | 100 |

**Methods**

```lua
:System.Void .ctor()
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

## `share.PrefabInstantiateMediator.PrefabInstantiateRequest[]`

**Methods**

```lua
:System.Void Add(share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:share.PrefabInstantiateMediator.PrefabInstantiateRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:System.Void CopyTo(share.PrefabInstantiateMediator.PrefabInstantiateRequest[], System.Int32)
:share.PrefabInstantiateMediator.PrefabInstantiateRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PrefabInstantiateMediator.PrefabInstantiateRequest> GetEnumerator()
:System.Int32 IndexOf(share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:System.Void Insert(System.Int32, share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:System.Boolean Remove(share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PrefabInstantiateMediator.PrefabInstantiateRequest)
:share.PrefabInstantiateMediator.PrefabInstantiateRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PrefabInstantiateMediator.PrefabInstantiateRequest)
```

## `share.PrefabInstantiateMediatorBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_InstantiateTimeBudgetOnFrameHead` | `System.Single` |  | 80 |
| `_InstantiateTimeBudgetOnFrameTail` | `System.Single` |  | 84 |

**Methods**

```lua
:System.Void .ctor()
:System.Void awake()
:System.Single get_InstantiateTimeBudgetOnFrameHead()
:System.Single get_InstantiateTimeBudgetOnFrameTail()
:System.Void onDestroy()
:System.Void set_InstantiateTimeBudgetOnFrameHead(System.Single)
:System.Void set_InstantiateTimeBudgetOnFrameTail(System.Single)
:System.Void start()
```

## `share.PrefabInstantiatePhase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FrameHead` | `share.PrefabInstantiatePhase` | yes | 16 |
| `FrameTail` | `share.PrefabInstantiatePhase` | yes | 16 |
| `Immediate` | `share.PrefabInstantiatePhase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PrefabInstantiatePhase[]`

**Methods**

```lua
:System.Void Add(share.PrefabInstantiatePhase)
:share.PrefabInstantiatePhase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PrefabInstantiatePhase)
:System.Void CopyTo(share.PrefabInstantiatePhase[], System.Int32)
:share.PrefabInstantiatePhase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PrefabInstantiatePhase> GetEnumerator()
:System.Int32 IndexOf(share.PrefabInstantiatePhase)
:System.Void Insert(System.Int32, share.PrefabInstantiatePhase)
:System.Boolean Remove(share.PrefabInstantiatePhase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PrefabInstantiatePhase)
:share.PrefabInstantiatePhase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PrefabInstantiatePhase)
```

## `share.PrefabInstantiateResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Canceled` | `share.PrefabInstantiateResult` | yes | 16 |
| `EmptyAsset` | `share.PrefabInstantiateResult` | yes | 16 |
| `InvalidArgs` | `share.PrefabInstantiateResult` | yes | 16 |
| `IsNotReady` | `share.PrefabInstantiateResult` | yes | 16 |
| `LostRequester` | `share.PrefabInstantiateResult` | yes | 16 |
| `Rejected` | `share.PrefabInstantiateResult` | yes | 16 |
| `Success` | `share.PrefabInstantiateResult` | yes | 16 |
| `Unknown` | `share.PrefabInstantiateResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.PrefabInstantiateResult[]`

**Methods**

```lua
:System.Void Add(share.PrefabInstantiateResult)
:share.PrefabInstantiateResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.PrefabInstantiateResult)
:System.Void CopyTo(share.PrefabInstantiateResult[], System.Int32)
:share.PrefabInstantiateResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.PrefabInstantiateResult> GetEnumerator()
:System.Int32 IndexOf(share.PrefabInstantiateResult)
:System.Void Insert(System.Int32, share.PrefabInstantiateResult)
:System.Boolean Remove(share.PrefabInstantiateResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.PrefabInstantiateResult)
:share.PrefabInstantiateResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.PrefabInstantiateResult)
```

## `share.PrefabInstantiateResults`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Result>k__BackingField` | `share.PrefabInstantiateResult` |  | 16 |
| `<GameObject>k__BackingField` | `via.GameObject` |  | 24 |
| `<InstantiateTime>k__BackingField` | `System.Single` |  | 32 |
| `<ProgressTime>k__BackingField` | `System.Single` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.PrefabInstantiateResult)
:System.Void .ctor(share.PrefabInstantiateResult, via.GameObject, System.Single, System.Single)
:System.Void .ctor(share.PrefabInstantiateResults)
:via.GameObject get_GameObject()
:System.Single get_InstantiateTime()
:System.Single get_ProgressTime()
:share.PrefabInstantiateResult get_Result()
```

## `share.QualityPerformanceBalancer`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<OnWork>k__BackingField` | `System.Boolean` |  | 16 |
| `<TimeOverComboCount>k__BackingField` | `System.Int32` |  | 20 |
| `<TimeUnderComboCount>k__BackingField` | `System.Int32` |  | 24 |
| `<CurrentPauseReason>k__BackingField` | `share.QualityPerformanceBalancer.PauseReason` |  | 28 |
| `SpeedUpBorder` | `System.Single` |  | 32 |
| `QualityUpBorder` | `System.Single` |  | 36 |
| `QualityChangeComboThreshold` | `System.Int32` |  | 40 |
| `ControlTargetList` | `System.Collections.Generic.LinkedList`1<share.QualityPerformanceBalancer.ControlTarget>` |  | 48 |
| `CurrentControlTarget` | `System.Collections.Generic.LinkedListNode`1<share.QualityPerformanceBalancer.ControlTarget>` |  | 56 |
| `NullControlTarget` | `share.QualityPerformanceBalancer.NullControl` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Target` | `share.QualityPerformanceControllable` |  | 16 |
| `Rank` | `System.Int32` |  | 24 |
| `Name` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor(share.QualityPerformanceControllable, System.Int32, System.String)
```

## `share.QualityPerformanceBalancer.ControlTarget[]`

**Methods**

```lua
:System.Void Add(share.QualityPerformanceBalancer.ControlTarget)
:share.QualityPerformanceBalancer.ControlTarget Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.QualityPerformanceBalancer.ControlTarget)
:System.Void CopyTo(share.QualityPerformanceBalancer.ControlTarget[], System.Int32)
:share.QualityPerformanceBalancer.ControlTarget Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.QualityPerformanceBalancer.ControlTarget> GetEnumerator()
:System.Int32 IndexOf(share.QualityPerformanceBalancer.ControlTarget)
:System.Void Insert(System.Int32, share.QualityPerformanceBalancer.ControlTarget)
:System.Boolean Remove(share.QualityPerformanceBalancer.ControlTarget)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.QualityPerformanceBalancer.ControlTarget)
:share.QualityPerformanceBalancer.ControlTarget get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.QualityPerformanceBalancer.ControlTarget)
```

## `share.QualityPerformanceBalancer.NullControl`

**Methods**

```lua
:System.Single getQualityUpBorder(System.Int32, System.Single)
:System.Single getSpeedUpBorder(System.Int32, System.Single)
```

## `share.QualityPerformanceBalancer.PauseReason`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Debug` | `share.QualityPerformanceBalancer.PauseReason` | yes | 16 |
| `Event` | `share.QualityPerformanceBalancer.PauseReason` | yes | 16 |
| `None` | `share.QualityPerformanceBalancer.PauseReason` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.QualityPerformanceBalancer.PauseReason[]`

**Methods**

```lua
:System.Void Add(share.QualityPerformanceBalancer.PauseReason)
:share.QualityPerformanceBalancer.PauseReason Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.QualityPerformanceBalancer.PauseReason)
:System.Void CopyTo(share.QualityPerformanceBalancer.PauseReason[], System.Int32)
:share.QualityPerformanceBalancer.PauseReason Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.QualityPerformanceBalancer.PauseReason> GetEnumerator()
:System.Int32 IndexOf(share.QualityPerformanceBalancer.PauseReason)
:System.Void Insert(System.Int32, share.QualityPerformanceBalancer.PauseReason)
:System.Boolean Remove(share.QualityPerformanceBalancer.PauseReason)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.QualityPerformanceBalancer.PauseReason)
:share.QualityPerformanceBalancer.PauseReason get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.QualityPerformanceBalancer.PauseReason)
```

## `share.QualityPerformanceBalancerBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_CpuSpeedupThreadold` | `System.Single` |  | 80 |
| `_CpuQualityupThreshold` | `System.Single` |  | 84 |
| `_CpuControlThresholdFrameCount` | `System.Int32` |  | 88 |
| `_GpuSpeedupThreadold` | `System.Single` |  | 92 |
| `_GpuQualityupThreshold` | `System.Single` |  | 96 |
| `_GpuControlThresholdFrameCount` | `System.Int32` |  | 100 |

**Methods**

```lua
:System.Void .ctor()
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

## `share.QualityPerformanceControllable`

_No fields or methods._

## `share.RegionType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Asia` | `share.RegionType` | yes | 16 |
| `Europe` | `share.RegionType` | yes | 16 |
| `Japan` | `share.RegionType` | yes | 16 |
| `USA` | `share.RegionType` | yes | 16 |
| `Unknown` | `share.RegionType` | yes | 16 |
| `WW` | `share.RegionType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.RegionType[]`

**Methods**

```lua
:System.Void Add(share.RegionType)
:share.RegionType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.RegionType)
:System.Void CopyTo(share.RegionType[], System.Int32)
:share.RegionType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.RegionType> GetEnumerator()
:System.Int32 IndexOf(share.RegionType)
:System.Void Insert(System.Int32, share.RegionType)
:System.Boolean Remove(share.RegionType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.RegionType)
:share.RegionType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.RegionType)
```

## `share.ResourceController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_InitialMaxParallelReadingCount` | `System.Int32` |  | 80 |
| `_InitialActivateInterval` | `System.Int32` |  | 84 |

**Methods**

```lua
:System.Void .ctor()
:System.Int32 get_InitialActivateInterval()
:System.Int32 get_InitialMaxParallelReadingCount()
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void set_InitialActivateInterval(System.Int32)
:System.Void set_InitialMaxParallelReadingCount(System.Int32)
:System.Void start()
```

## `share.ResourceStandbyMediator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NameAppResident` | `System.String` | yes | 16 |
| `RequestList` | `System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>` |  | 16 |
| `ReadingList` | `System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>` |  | 24 |
| `StandbyList` | `System.Collections.Generic.List`1<share.ResourceStandbyMediator.Entry>` |  | 32 |
| `RequestLockObject` | `System.Object` |  | 40 |
| `NeedToGCExecute` | `System.Boolean` |  | 48 |
| `MaxParallelReadingCount` | `System.Int32` |  | 52 |
| `_CurrentMode` | `share.ResourceStandbyMediator.Mode` |  | 56 |
| `NeedToFastTrackProcedure` | `System.Boolean` |  | 60 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RefFolder` | `via.Folder` |  | 16 |
| `RefPrefab` | `via.Prefab` |  | 24 |
| `Priority` | `System.Int16` |  | 32 |
| `AliveFrame` | `System.Int32` |  | 36 |
| `DynamicPriority` | `System.Func`1<System.Int16>` |  | 40 |
| `FinishAction` | `System.Action` |  | 48 |
| `FastTrack` | `System.Boolean` |  | 56 |

**Methods**

```lua
:System.Boolean isSameEntity(share.ResourceStandbyMediator.Entry)
:System.Void updatePriority()
```

## `share.ResourceStandbyMediator.Entry[]`

**Methods**

```lua
:System.Void Add(share.ResourceStandbyMediator.Entry)
:share.ResourceStandbyMediator.Entry Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ResourceStandbyMediator.Entry)
:System.Void CopyTo(share.ResourceStandbyMediator.Entry[], System.Int32)
:share.ResourceStandbyMediator.Entry Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ResourceStandbyMediator.Entry> GetEnumerator()
:System.Int32 IndexOf(share.ResourceStandbyMediator.Entry)
:System.Void Insert(System.Int32, share.ResourceStandbyMediator.Entry)
:System.Boolean Remove(share.ResourceStandbyMediator.Entry)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ResourceStandbyMediator.Entry)
:share.ResourceStandbyMediator.Entry get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ResourceStandbyMediator.Entry)
```

## `share.ResourceStandbyMediator.FolderEntry`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ReleaseReserved` | `System.Boolean` |  | 64 |
| `FolderPath` | `System.String` |  | 72 |
| `IncluderList` | `System.Collections.Generic.List`1<share.ResourceStandbyMediator.FolderEntry>` |  | 80 |

**Methods**

```lua
:System.Void .ctor(via.Folder)
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

## `share.ResourceStandbyMediator.FolderEntry[]`

**Methods**

```lua
:System.Void Add(share.ResourceStandbyMediator.FolderEntry)
:share.ResourceStandbyMediator.FolderEntry Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ResourceStandbyMediator.FolderEntry)
:System.Void CopyTo(share.ResourceStandbyMediator.FolderEntry[], System.Int32)
:share.ResourceStandbyMediator.FolderEntry Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ResourceStandbyMediator.FolderEntry> GetEnumerator()
:System.Int32 IndexOf(share.ResourceStandbyMediator.FolderEntry)
:System.Void Insert(System.Int32, share.ResourceStandbyMediator.FolderEntry)
:System.Boolean Remove(share.ResourceStandbyMediator.FolderEntry)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ResourceStandbyMediator.FolderEntry)
:share.ResourceStandbyMediator.FolderEntry get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ResourceStandbyMediator.FolderEntry)
```

## `share.ResourceStandbyMediator.Mode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ReadWait` | `share.ResourceStandbyMediator.Mode` | yes | 16 |
| `Standard` | `share.ResourceStandbyMediator.Mode` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ResourceStandbyMediator.Mode[]`

**Methods**

```lua
:System.Void Add(share.ResourceStandbyMediator.Mode)
:share.ResourceStandbyMediator.Mode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ResourceStandbyMediator.Mode)
:System.Void CopyTo(share.ResourceStandbyMediator.Mode[], System.Int32)
:share.ResourceStandbyMediator.Mode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ResourceStandbyMediator.Mode> GetEnumerator()
:System.Int32 IndexOf(share.ResourceStandbyMediator.Mode)
:System.Void Insert(System.Int32, share.ResourceStandbyMediator.Mode)
:System.Boolean Remove(share.ResourceStandbyMediator.Mode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ResourceStandbyMediator.Mode)
:share.ResourceStandbyMediator.Mode get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ResourceStandbyMediator.Mode)
```

## `share.ResourceStandbyMediator.PrefabEntry`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ReleaseReserved` | `System.Boolean` |  | 64 |

**Methods**

```lua
:System.Void .ctor(via.Prefab)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BOOT_GAME_CORE` | `System.Int16` | yes | 16 |
| `BOOT_RESIDENT_CONTENTS` | `System.Int16` | yes | 18 |
| `GUI_GAMESTATE_CONTROL` | `System.Int16` | yes | 20 |
| `GUI_PREFAB_INSTANTIATE` | `System.Int16` | yes | 22 |
| `BOOT_MAIN_CONTENTS` | `System.Int16` | yes | 24 |
| `BOOT_EXTRA_CONTENTS` | `System.Int16` | yes | 26 |
| `CATALOG_FOLDER_FIRST_CHANK` | `System.Int16` | yes | 28 |
| `CATALOG_FOLDER` | `System.Int16` | yes | 30 |
| `GAME_CONTENTS` | `System.Int16` | yes | 32 |
| `CAMPAIGN_CONTENTS` | `System.Int16` | yes | 34 |
| `ACCESSORY_PREFAB` | `System.Int16` | yes | 36 |
| `DROPITEM_PREFAB` | `System.Int16` | yes | 38 |
| `FAST_TRACK_BORDER` | `System.Int16` | yes | 40 |
| `CHAPTER` | `System.Int16` | yes | 42 |
| `LOCATION` | `System.Int16` | yes | 44 |
| `PREFECTURE` | `System.Int16` | yes | 46 |
| `STAGE_TIED_SCENE` | `System.Int16` | yes | 48 |
| `STAGE_ACTIVATE_HIGH` | `System.Int16` | yes | 50 |
| `STAGE_ACTIVATE_LOW` | `System.Int16` | yes | 52 |
| `STAGE_STANDBY_HIGH` | `System.Int16` | yes | 54 |
| `STAGE_STANDBY_LOW` | `System.Int16` | yes | 56 |
| `ZONE_SCENE` | `System.Int16` | yes | 58 |
| `CHARACTER_PREFAB` | `System.Int16` | yes | 60 |
| `TIMELINE_ALL_SCENE_CONTROLER` | `System.Int16` | yes | 62 |
| `TIMELINE_EVENT_CONTEXT` | `System.Int16` | yes | 64 |
| `TIMELINE_FLOW` | `System.Int16` | yes | 66 |
| `WEAPON_PREFAB` | `System.Int16` | yes | 68 |
| `TEST` | `System.Int16` | yes | 70 |
| `UNDEFINED` | `System.Int16` | yes | 72 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.RuntimeEnvironment`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<appRuntimeArguments>k__BackingField` | `share.AppRuntimeArgument` | yes | 16 |
| `<appRegionRecognizer>k__BackingField` | `share.AppRegionRecognizer` | yes | 24 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "analyzeAppRuntimeArgument", ...)  -- System.Void analyzeAppRuntimeArgument()
sdk.call_native_func(nil, type_def, "getAppRuntimeArgument", ...)  -- System.Collections.Generic.List`1<app.dev1lab.CommonRuntimeArgument.Unit> getAppRuntimeArgument(System.String)
sdk.call_native_func(nil, type_def, "get_appRegionRecognizer", ...)  -- share.AppRegionRecognizer get_appRegionRecognizer()
sdk.call_native_func(nil, type_def, "get_appRuntimeArguments", ...)  -- share.AppRuntimeArgument get_appRuntimeArguments()
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
sdk.call_native_func(nil, type_def, "recognizeRegion", ...)  -- System.Void recognizeRegion()
sdk.call_native_func(nil, type_def, "set_appRegionRecognizer", ...)  -- System.Void set_appRegionRecognizer(share.AppRegionRecognizer)
sdk.call_native_func(nil, type_def, "set_appRuntimeArguments", ...)  -- System.Void set_appRuntimeArguments(share.AppRuntimeArgument)
```

## `share.SaveDataBase`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `VersionValue` | `System.UInt32` |  | 16 |
| `HashValue` | `System.UInt32` |  | 20 |

**Methods**

```lua
:System.UInt32 get_Hash()
:System.UInt32 get_Version()
:System.Void setHashAndVersion(System.UInt32, System.UInt32)
:System.Void set_Hash(System.UInt32)
:System.Void set_Version(System.UInt32)
```

## `share.SaveDataBase[]`

**Methods**

```lua
:System.Void Add(share.SaveDataBase)
:share.SaveDataBase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataBase)
:System.Void CopyTo(share.SaveDataBase[], System.Int32)
:share.SaveDataBase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataBase> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataBase)
:System.Void Insert(System.Int32, share.SaveDataBase)
:System.Boolean Remove(share.SaveDataBase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataBase)
:share.SaveDataBase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataBase)
```

## `share.SaveDataDefinition`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SYSTEM_SAVE_DATA_SIZE` | `System.UInt64` | yes | 16 |
| `GAME_SAVE_DATA_SIZE` | `System.UInt64` | yes | 24 |
| `SYSTEM_SAVE_DATA_COUNT` | `System.Int32` | yes | 32 |
| `GAME_SAVE_DATA_COUNT` | `System.Int32` | yes | 36 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.SaveDataManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_BaseGroup000Begin` | `System.Boolean` | yes | 16 |
| `_BaseGroup000End` | `System.Boolean` | yes | 16 |
| `<CurrentGameSaveValidateDataVersion>k__BackingField` | `System.UInt32` |  | 16 |
| `<CurrentProcess>k__BackingField` | `share.SaveDataManager.Process` |  | 20 |
| `<IsShowSaveIconTransferring>k__BackingField` | `System.Boolean` |  | 24 |
| `<LoadedGamedataApplyable>k__BackingField` | `System.Boolean` |  | 25 |
| `<TempPlayLoadData>k__BackingField` | `share.SaveDataManager.CursorSaveData` |  | 32 |
| `<LastLoadSlot>k__BackingField` | `System.Int32` |  | 40 |
| `<LastLoadSuccessedGameSlot>k__BackingField` | `System.Int32` |  | 44 |
| `_SystemSaveData` | `share.SaveDataManager.SystemSaveData` |  | 48 |
| `_SystemSaveValidateData` | `share.SaveDataManager.SystemSaveValidateData` |  | 56 |
| `_GameSaveData` | `share.SaveDataManager.GameSaveData` |  | 64 |
| `_GameSaveValidateData` | `share.SaveDataManager.GameSaveValidateData` |  | 72 |
| `_SystemSaveResistrantTable` | `System.Collections.Generic.Dictionary`2<System.UInt32,share.ISystemSaveData>` |  | 80 |
| `_GameSaveResistrantTable` | `System.Collections.Generic.Dictionary`2<System.UInt32,share.IGameSaveData>` |  | 88 |
| `_SystemSaveSlotDetailHolder` | `share.ISystemSaveSlotDetailHolder` |  | 96 |
| `_GameSaveSlotDetailHolder` | `share.IGameSaveSlotDetailHolder` |  | 104 |
| `_SaveLoadEventReciever` | `share.ISaveLoadEventReciever` |  | 112 |
| `_RequestQueue` | `System.Collections.Generic.Queue`1<share.SaveDataManager.Request>` |  | 120 |
| `_CurrentRequest` | `share.SaveDataManager.Request` |  | 128 |
| `_ExcludeGameSaveCaller` | `System.Collections.Generic.List`1<System.Object>` |  | 136 |
| `_IsExcludeGameSaveInQuit` | `System.Boolean` |  | 144 |
| `_ExcludeGameSaveDelegate` | `System.Collections.Generic.List`1<share.SaveDataManager.ExcludeGameSaveDelegate>` |  | 152 |
| `_SuspendGameSaveCaller` | `System.Collections.Generic.List`1<System.Object>` |  | 160 |
| `_SaveFlowController` | `chainsaw.SaveFlowController` |  | 168 |
| `_RemoveFlowController` | `chainsaw.SaveRemoveFlowController` |  | 176 |
| `OnUpdateInIdle` | `System.Action` |  | 184 |
| `OnGameSaveCompleted` | `System.Action`1<share.GameSaveCompletedEventArgs>` |  | 192 |
| `OnGameLoadCompleted` | `System.Action`1<share.GameLoadCompletedEventArgs>` |  | 200 |
| `OnPrepareTimeout` | `System.Action` |  | 208 |
| `_IsTimeoutEventFired` | `System.Boolean` |  | 216 |
| `_TimeoutTimer` | `System.Single` |  | 220 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IsAutoSaveData` | `System.Boolean` |  | 16 |
| `IsConsentSaved` | `System.Boolean` |  | 17 |
| `IsSaved` | `System.Boolean` |  | 18 |
| `Slot` | `System.Int32` |  | 20 |

## `share.SaveDataManager.ExcludeGameSaveDelegate`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Owner` | `System.Object` |  | 16 |
| `CantGameSave` | `System.Func`1<System.Boolean>` |  | 24 |

## `share.SaveDataManager.ExcludeGameSaveDelegate[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.ExcludeGameSaveDelegate)
:share.SaveDataManager.ExcludeGameSaveDelegate Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.ExcludeGameSaveDelegate)
:System.Void CopyTo(share.SaveDataManager.ExcludeGameSaveDelegate[], System.Int32)
:share.SaveDataManager.ExcludeGameSaveDelegate Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.ExcludeGameSaveDelegate> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.ExcludeGameSaveDelegate)
:System.Void Insert(System.Int32, share.SaveDataManager.ExcludeGameSaveDelegate)
:System.Boolean Remove(share.SaveDataManager.ExcludeGameSaveDelegate)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.ExcludeGameSaveDelegate)
:share.SaveDataManager.ExcludeGameSaveDelegate get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.ExcludeGameSaveDelegate)
```

## `share.SaveDataManager.GameSaveData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GameSaveDataList` | `System.Collections.Generic.List`1<share.SaveDataBase>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
```

## `share.SaveDataManager.GameSaveData[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.GameSaveData)
:share.SaveDataManager.GameSaveData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.GameSaveData)
:System.Void CopyTo(share.SaveDataManager.GameSaveData[], System.Int32)
:share.SaveDataManager.GameSaveData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.GameSaveData> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.GameSaveData)
:System.Void Insert(System.Int32, share.SaveDataManager.GameSaveData)
:System.Boolean Remove(share.SaveDataManager.GameSaveData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.GameSaveData)
:share.SaveDataManager.GameSaveData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.GameSaveData)
```

## `share.SaveDataManager.GameSaveValidateData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Version` | `System.UInt32` |  | 16 |
| `RegionType` | `share.RegionType` |  | 20 |
| `CeroType` | `share.CERO` |  | 24 |
| `IsOverPlayGo` | `System.Boolean` |  | 28 |

## `share.SaveDataManager.GameSaveValidateData[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.GameSaveValidateData)
:share.SaveDataManager.GameSaveValidateData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.GameSaveValidateData)
:System.Void CopyTo(share.SaveDataManager.GameSaveValidateData[], System.Int32)
:share.SaveDataManager.GameSaveValidateData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.GameSaveValidateData> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.GameSaveValidateData)
:System.Void Insert(System.Int32, share.SaveDataManager.GameSaveValidateData)
:System.Boolean Remove(share.SaveDataManager.GameSaveValidateData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.GameSaveValidateData)
:share.SaveDataManager.GameSaveValidateData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.GameSaveValidateData)
```

## `share.SaveDataManager.Process`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GameLoadWait` | `share.SaveDataManager.Process` | yes | 16 |
| `Idle` | `share.SaveDataManager.Process` | yes | 16 |
| `LoadWait` | `share.SaveDataManager.Process` | yes | 16 |
| `PreIdle` | `share.SaveDataManager.Process` | yes | 16 |
| `Processing` | `share.SaveDataManager.Process` | yes | 16 |
| `RemoveWait` | `share.SaveDataManager.Process` | yes | 16 |
| `SaveWait` | `share.SaveDataManager.Process` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SaveDataManager.Process[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.Process)
:share.SaveDataManager.Process Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.Process)
:System.Void CopyTo(share.SaveDataManager.Process[], System.Int32)
:share.SaveDataManager.Process Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.Process> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.Process)
:System.Void Insert(System.Int32, share.SaveDataManager.Process)
:System.Boolean Remove(share.SaveDataManager.Process)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.Process)
:share.SaveDataManager.Process get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.Process)
```

## `share.SaveDataManager.Request`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<SystemSaveLoadKey>k__BackingField` | `share.SaveLoadKey` |  | 16 |
| `<SystemSaveLoadValidateKey>k__BackingField` | `share.SaveLoadKey` |  | 20 |
| `<GameSaveLoadKey>k__BackingField` | `share.SaveLoadKey` |  | 24 |
| `<GameSaveLoadValidateKey>k__BackingField` | `share.SaveLoadKey` |  | 28 |
| `Command` | `share.SaveDataManager.Request.CommandType` |  | 32 |
| `SlotId` | `System.Int32` |  | 36 |
| `RequestArgs` | `share.SaveLoadRequestArgs` |  | 40 |

**Methods**

```lua
:System.Void .ctor(System.Int32)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Invalid` | `share.SaveDataManager.Request.CommandType` | yes | 16 |
| `Load` | `share.SaveDataManager.Request.CommandType` | yes | 16 |
| `Remove` | `share.SaveDataManager.Request.CommandType` | yes | 16 |
| `Save` | `share.SaveDataManager.Request.CommandType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SaveDataManager.Request.CommandType[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.Request.CommandType)
:share.SaveDataManager.Request.CommandType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.Request.CommandType)
:System.Void CopyTo(share.SaveDataManager.Request.CommandType[], System.Int32)
:share.SaveDataManager.Request.CommandType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.Request.CommandType> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.Request.CommandType)
:System.Void Insert(System.Int32, share.SaveDataManager.Request.CommandType)
:System.Boolean Remove(share.SaveDataManager.Request.CommandType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.Request.CommandType)
:share.SaveDataManager.Request.CommandType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.Request.CommandType)
```

## `share.SaveDataManager.Request[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.Request)
:share.SaveDataManager.Request Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.Request)
:System.Void CopyTo(share.SaveDataManager.Request[], System.Int32)
:share.SaveDataManager.Request Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.Request> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.Request)
:System.Void Insert(System.Int32, share.SaveDataManager.Request)
:System.Boolean Remove(share.SaveDataManager.Request)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.Request)
:share.SaveDataManager.Request get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.Request)
```

## `share.SaveDataManager.SystemSaveData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `SystemSaveDataList` | `System.Collections.Generic.List`1<share.SaveDataBase>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
```

## `share.SaveDataManager.SystemSaveData[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.SystemSaveData)
:share.SaveDataManager.SystemSaveData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.SystemSaveData)
:System.Void CopyTo(share.SaveDataManager.SystemSaveData[], System.Int32)
:share.SaveDataManager.SystemSaveData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.SystemSaveData> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.SystemSaveData)
:System.Void Insert(System.Int32, share.SaveDataManager.SystemSaveData)
:System.Boolean Remove(share.SaveDataManager.SystemSaveData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.SystemSaveData)
:share.SaveDataManager.SystemSaveData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.SystemSaveData)
```

## `share.SaveDataManager.SystemSaveValidateData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Version` | `System.UInt32` |  | 16 |
| `RegionType` | `share.RegionType` |  | 20 |
| `CeroType` | `share.CERO` |  | 24 |
| `IsOverPlayGo` | `System.Boolean` |  | 28 |

## `share.SaveDataManager.SystemSaveValidateData[]`

**Methods**

```lua
:System.Void Add(share.SaveDataManager.SystemSaveValidateData)
:share.SaveDataManager.SystemSaveValidateData Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveDataManager.SystemSaveValidateData)
:System.Void CopyTo(share.SaveDataManager.SystemSaveValidateData[], System.Int32)
:share.SaveDataManager.SystemSaveValidateData Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveDataManager.SystemSaveValidateData> GetEnumerator()
:System.Int32 IndexOf(share.SaveDataManager.SystemSaveValidateData)
:System.Void Insert(System.Int32, share.SaveDataManager.SystemSaveValidateData)
:System.Boolean Remove(share.SaveDataManager.SystemSaveValidateData)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveDataManager.SystemSaveValidateData)
:share.SaveDataManager.SystemSaveValidateData get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveDataManager.SystemSaveValidateData)
```

## `share.SaveDataManagerBehavior`

**Methods**

```lua
:System.Void lateUpdate()
:System.Void onDestroy()
:System.Void start()
```

## `share.SaveDataManagerEnumExtension`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getKeyString", ...)  -- System.String getKeyString(share.SaveLoadKey)
```

## `share.SaveDataUtil`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getAutoSaveSlot", ...)  -- share.AppSaveSlot getAutoSaveSlot(share.CampaignIdentifier)
sdk.call_native_func(nil, type_def, "getCampaignIdentifier", ...)  -- share.CampaignIdentifier getCampaignIdentifier(System.Int32)
sdk.call_native_func(nil, type_def, "getCurrentAutoSaveSlot", ...)  -- share.AppSaveSlot getCurrentAutoSaveSlot()
sdk.call_native_func(nil, type_def, "getSaveIcon", ...)  -- via.storage.saveService.SaveIcon getSaveIcon(System.Int32)
sdk.call_native_func(nil, type_def, "isAutoSaveSlotIndex", ...)  -- System.Boolean isAutoSaveSlotIndex(System.Int32)
sdk.call_native_func(nil, type_def, "isCampaign1011", ...)  -- System.Boolean isCampaign1011()
sdk.call_native_func(nil, type_def, "isEnableAccessSaveFileDetailTbl", ...)  -- System.Boolean isEnableAccessSaveFileDetailTbl()
```

## `share.SaveLoadKey`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Chainsaw_GameSave_Key` | `share.SaveLoadKey` | yes | 16 |
| `Chainsaw_GameSave_Validate_Key` | `share.SaveLoadKey` | yes | 16 |
| `Chainsaw_SystemSave_Key` | `share.SaveLoadKey` | yes | 16 |
| `Chainsaw_SystemSave_Validate_Key` | `share.SaveLoadKey` | yes | 16 |
| `Highway_GameSave_Key` | `share.SaveLoadKey` | yes | 16 |
| `Highway_GameSave_Validate_Key` | `share.SaveLoadKey` | yes | 16 |
| `Highway_SystemSave_Key` | `share.SaveLoadKey` | yes | 16 |
| `Highway_SystemSave_Validate_Key` | `share.SaveLoadKey` | yes | 16 |
| `Invalid` | `share.SaveLoadKey` | yes | 16 |
| `Share_SystemSave_Key` | `share.SaveLoadKey` | yes | 16 |
| `Share_SystemSave_TransferTest_Key` | `share.SaveLoadKey` | yes | 16 |
| `Share_SystemSave_Validate_Key` | `share.SaveLoadKey` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SaveLoadKey[]`

**Methods**

```lua
:System.Void Add(share.SaveLoadKey)
:share.SaveLoadKey Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveLoadKey)
:System.Void CopyTo(share.SaveLoadKey[], System.Int32)
:share.SaveLoadKey Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveLoadKey> GetEnumerator()
:System.Int32 IndexOf(share.SaveLoadKey)
:System.Void Insert(System.Int32, share.SaveLoadKey)
:System.Boolean Remove(share.SaveLoadKey)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveLoadKey)
:share.SaveLoadKey get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveLoadKey)
```

## `share.SaveLoadProcessResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Failed` | `share.SaveLoadProcessResult` | yes | 16 |
| `Invalid` | `share.SaveLoadProcessResult` | yes | 16 |
| `Success` | `share.SaveLoadProcessResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SaveLoadProcessResult[]`

**Methods**

```lua
:System.Void Add(share.SaveLoadProcessResult)
:share.SaveLoadProcessResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveLoadProcessResult)
:System.Void CopyTo(share.SaveLoadProcessResult[], System.Int32)
:share.SaveLoadProcessResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveLoadProcessResult> GetEnumerator()
:System.Int32 IndexOf(share.SaveLoadProcessResult)
:System.Void Insert(System.Int32, share.SaveLoadProcessResult)
:System.Boolean Remove(share.SaveLoadProcessResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveLoadProcessResult)
:share.SaveLoadProcessResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveLoadProcessResult)
```

## `share.SaveLoadProcessResults`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ResultType>k__BackingField` | `share.SaveLoadProcessResult` |  | 16 |
| `<SaveResult>k__BackingField` | `via.storage.saveService.SaveResult` |  | 20 |
| `<AppSaveResult>k__BackingField` | `share.AppSaveLoadFailedResult` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:share.AppSaveLoadFailedResult get_AppSaveResult()
:share.SaveLoadProcessResult get_ResultType()
:via.storage.saveService.SaveResult get_SaveResult()
:System.Void set_AppSaveResult(share.AppSaveLoadFailedResult)
:System.Void set_ResultType(share.SaveLoadProcessResult)
:System.Void set_SaveResult(via.storage.saveService.SaveResult)
```

## `share.SaveLoadRequestArgs`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `RequestedEvent` | `System.Action`1<share.SaveLoadRequestResults>` |  | 16 |
| `ProcessedEvent` | `System.Action`1<share.SaveLoadProcessResults>` |  | 24 |
| `OnCheckCollectable` | `System.Func`1<System.Boolean>` |  | 32 |

**Methods**

```lua
:System.Void .ctor(share.SaveLoadRequestArgs)
:System.Void add_ProcessedEvent(System.Action`1<share.SaveLoadProcessResults>)
:System.Void add_RequestedEvent(System.Action`1<share.SaveLoadRequestResults>)
:System.Boolean get_IsCollectable()
:System.Void notifyProcessResult(share.SaveLoadProcessResults)
:System.Void notifyRequestResult(share.SaveLoadRequestResults)
:System.Void remove_ProcessedEvent(System.Action`1<share.SaveLoadProcessResults>)
:System.Void remove_RequestedEvent(System.Action`1<share.SaveLoadRequestResults>)
```

## `share.SaveLoadRequestResult`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Failed` | `share.SaveLoadRequestResult` | yes | 16 |
| `Invalid` | `share.SaveLoadRequestResult` | yes | 16 |
| `Success` | `share.SaveLoadRequestResult` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SaveLoadRequestResult[]`

**Methods**

```lua
:System.Void Add(share.SaveLoadRequestResult)
:share.SaveLoadRequestResult Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SaveLoadRequestResult)
:System.Void CopyTo(share.SaveLoadRequestResult[], System.Int32)
:share.SaveLoadRequestResult Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SaveLoadRequestResult> GetEnumerator()
:System.Int32 IndexOf(share.SaveLoadRequestResult)
:System.Void Insert(System.Int32, share.SaveLoadRequestResult)
:System.Boolean Remove(share.SaveLoadRequestResult)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SaveLoadRequestResult)
:share.SaveLoadRequestResult get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SaveLoadRequestResult)
```

## `share.SaveLoadRequestResults`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ResultType>k__BackingField` | `share.SaveLoadRequestResult` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:share.SaveLoadRequestResult get_ResultType()
:System.Void set_ResultType(share.SaveLoadRequestResult)
```

## `share.SceneActivateMediator`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_RequestLockObject` | `via.threading.SimpleReaderWriterLock` |  | 16 |
| `WorkingEntryList` | `System.Collections.Generic.List`1<share.SceneActivateMediator.Entry>` |  | 24 |
| `RequestEntryList` | `System.Collections.Generic.LinkedList`1<share.SceneActivateMediator.Entry>` |  | 32 |
| `EntryProcIntervalTimer` | `System.Int32` |  | 40 |
| `EntryProcInterval` | `System.Int32` |  | 44 |
| `_BurstMode` | `System.Boolean` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RefFolder>k__BackingField` | `via.Folder` |  | 16 |
| `<CurrentPhase>k__BackingField` | `share.SceneActivateMediator.Entry.Phase` |  | 24 |
| `<CurrentTarget>k__BackingField` | `share.SceneActivateMediator.Entry.Target` |  | 28 |
| `ActivateHandle` | `System.Action` |  | 32 |
| `DeactivateHandle` | `System.Action` |  | 40 |

**Methods**

```lua
:System.Void .ctor(via.Folder)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Closing` | `share.SceneActivateMediator.Entry.Phase` | yes | 16 |
| `Off` | `share.SceneActivateMediator.Entry.Phase` | yes | 16 |
| `On` | `share.SceneActivateMediator.Entry.Phase` | yes | 16 |
| `Opening` | `share.SceneActivateMediator.Entry.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SceneActivateMediator.Entry.Phase[]`

**Methods**

```lua
:System.Void Add(share.SceneActivateMediator.Entry.Phase)
:share.SceneActivateMediator.Entry.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneActivateMediator.Entry.Phase)
:System.Void CopyTo(share.SceneActivateMediator.Entry.Phase[], System.Int32)
:share.SceneActivateMediator.Entry.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneActivateMediator.Entry.Phase> GetEnumerator()
:System.Int32 IndexOf(share.SceneActivateMediator.Entry.Phase)
:System.Void Insert(System.Int32, share.SceneActivateMediator.Entry.Phase)
:System.Boolean Remove(share.SceneActivateMediator.Entry.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneActivateMediator.Entry.Phase)
:share.SceneActivateMediator.Entry.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneActivateMediator.Entry.Phase)
```

## `share.SceneActivateMediator.Entry.Target`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Off` | `share.SceneActivateMediator.Entry.Target` | yes | 16 |
| `On` | `share.SceneActivateMediator.Entry.Target` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SceneActivateMediator.Entry.Target[]`

**Methods**

```lua
:System.Void Add(share.SceneActivateMediator.Entry.Target)
:share.SceneActivateMediator.Entry.Target Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneActivateMediator.Entry.Target)
:System.Void CopyTo(share.SceneActivateMediator.Entry.Target[], System.Int32)
:share.SceneActivateMediator.Entry.Target Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneActivateMediator.Entry.Target> GetEnumerator()
:System.Int32 IndexOf(share.SceneActivateMediator.Entry.Target)
:System.Void Insert(System.Int32, share.SceneActivateMediator.Entry.Target)
:System.Boolean Remove(share.SceneActivateMediator.Entry.Target)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneActivateMediator.Entry.Target)
:share.SceneActivateMediator.Entry.Target get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneActivateMediator.Entry.Target)
```

## `share.SceneActivateMediator.Entry[]`

**Methods**

```lua
:System.Void Add(share.SceneActivateMediator.Entry)
:share.SceneActivateMediator.Entry Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneActivateMediator.Entry)
:System.Void CopyTo(share.SceneActivateMediator.Entry[], System.Int32)
:share.SceneActivateMediator.Entry Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneActivateMediator.Entry> GetEnumerator()
:System.Int32 IndexOf(share.SceneActivateMediator.Entry)
:System.Void Insert(System.Int32, share.SceneActivateMediator.Entry)
:System.Boolean Remove(share.SceneActivateMediator.Entry)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneActivateMediator.Entry)
:share.SceneActivateMediator.Entry get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneActivateMediator.Entry)
```

## `share.SceneFolderController`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CurrentPhase>k__BackingField` | `share.SceneFolderController.Phase` |  | 16 |
| `<TargetStatus>k__BackingField` | `share.SceneFolderController.Status` |  | 20 |
| `<TargetFolder>k__BackingField` | `via.Folder` |  | 24 |
| `CurrentStandbyPriority` | `System.Int16` |  | 32 |
| `LockObject` | `System.Object` |  | 40 |
| `IsFixedPriority` | `System.Boolean` |  | 48 |
| `DynamicPriorityCalcFunc` | `System.Func`1<System.Int16>` |  | 56 |
| `OnStandbyHandler` | `System.Action` |  | 64 |
| `OnReleaseHandler` | `System.Action` |  | 72 |
| `OnActiveHandler` | `System.Action` |  | 80 |
| `OnDeactiveHandler` | `System.Action` |  | 88 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(via.Folder, System.Int16)
:System.Void .ctor(via.Folder, System.Func`1<System.Int16>)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Active` | `share.SceneFolderController.Phase` | yes | 16 |
| `ActiveToStandby` | `share.SceneFolderController.Phase` | yes | 16 |
| `Inavlid` | `share.SceneFolderController.Phase` | yes | 16 |
| `None` | `share.SceneFolderController.Phase` | yes | 16 |
| `NoneToStandaby` | `share.SceneFolderController.Phase` | yes | 16 |
| `Standby` | `share.SceneFolderController.Phase` | yes | 16 |
| `StandbyToActive` | `share.SceneFolderController.Phase` | yes | 16 |
| `StandbyToNone` | `share.SceneFolderController.Phase` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SceneFolderController.Phase[]`

**Methods**

```lua
:System.Void Add(share.SceneFolderController.Phase)
:share.SceneFolderController.Phase Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneFolderController.Phase)
:System.Void CopyTo(share.SceneFolderController.Phase[], System.Int32)
:share.SceneFolderController.Phase Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneFolderController.Phase> GetEnumerator()
:System.Int32 IndexOf(share.SceneFolderController.Phase)
:System.Void Insert(System.Int32, share.SceneFolderController.Phase)
:System.Boolean Remove(share.SceneFolderController.Phase)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneFolderController.Phase)
:share.SceneFolderController.Phase get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneFolderController.Phase)
```

## `share.SceneFolderController.PrioritySetMode`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Method` | `share.SceneFolderController.PrioritySetMode` | yes | 16 |
| `Value` | `share.SceneFolderController.PrioritySetMode` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SceneFolderController.PrioritySetMode[]`

**Methods**

```lua
:System.Void Add(share.SceneFolderController.PrioritySetMode)
:share.SceneFolderController.PrioritySetMode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneFolderController.PrioritySetMode)
:System.Void CopyTo(share.SceneFolderController.PrioritySetMode[], System.Int32)
:share.SceneFolderController.PrioritySetMode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneFolderController.PrioritySetMode> GetEnumerator()
:System.Int32 IndexOf(share.SceneFolderController.PrioritySetMode)
:System.Void Insert(System.Int32, share.SceneFolderController.PrioritySetMode)
:System.Boolean Remove(share.SceneFolderController.PrioritySetMode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneFolderController.PrioritySetMode)
:share.SceneFolderController.PrioritySetMode get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneFolderController.PrioritySetMode)
```

## `share.SceneFolderController.Status`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Active` | `share.SceneFolderController.Status` | yes | 16 |
| `None` | `share.SceneFolderController.Status` | yes | 16 |
| `Standby` | `share.SceneFolderController.Status` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SceneFolderController.Status[]`

**Methods**

```lua
:System.Void Add(share.SceneFolderController.Status)
:share.SceneFolderController.Status Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneFolderController.Status)
:System.Void CopyTo(share.SceneFolderController.Status[], System.Int32)
:share.SceneFolderController.Status Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneFolderController.Status> GetEnumerator()
:System.Int32 IndexOf(share.SceneFolderController.Status)
:System.Void Insert(System.Int32, share.SceneFolderController.Status)
:System.Boolean Remove(share.SceneFolderController.Status)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneFolderController.Status)
:share.SceneFolderController.Status get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneFolderController.Status)
```

## `share.SceneFolderController[]`

**Methods**

```lua
:System.Void Add(share.SceneFolderController)
:share.SceneFolderController Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SceneFolderController)
:System.Void CopyTo(share.SceneFolderController[], System.Int32)
:share.SceneFolderController Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SceneFolderController> GetEnumerator()
:System.Int32 IndexOf(share.SceneFolderController)
:System.Void Insert(System.Int32, share.SceneFolderController)
:System.Boolean Remove(share.SceneFolderController)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SceneFolderController)
:share.SceneFolderController get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SceneFolderController)
```

## `share.ShareOptionDefine`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `INVALID_OPTION_VALUE` | `System.Int32` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
```

## `share.SimpleCompareType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Equal` | `share.SimpleCompareType` | yes | 16 |
| `NotEqual` | `share.SimpleCompareType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.SimpleCompareType[]`

**Methods**

```lua
:System.Void Add(share.SimpleCompareType)
:share.SimpleCompareType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.SimpleCompareType)
:System.Void CopyTo(share.SimpleCompareType[], System.Int32)
:share.SimpleCompareType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.SimpleCompareType> GetEnumerator()
:System.Int32 IndexOf(share.SimpleCompareType)
:System.Void Insert(System.Int32, share.SimpleCompareType)
:System.Boolean Remove(share.SimpleCompareType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.SimpleCompareType)
:share.SimpleCompareType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.SimpleCompareType)
```

## `share.Startup`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `VolatilizeEvent` | `System.Action` | yes | 16 |
| `_FrameHeadActionList` | `System.Action[]` | yes | 24 |
| `_FrameHeadActionCount` | `System.Int32` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "Main", ...)  -- System.Void Main(System.String[])
sdk.call_native_func(nil, type_def, "add_VolatilizeEvent", ...)  -- System.Void add_VolatilizeEvent(System.Action)
sdk.call_native_func(nil, type_def, "remove_VolatilizeEvent", ...)  -- System.Void remove_VolatilizeEvent(System.Action)
sdk.call_native_func(nil, type_def, "setupSocialSetting", ...)  -- System.Void setupSocialSetting()
sdk.call_native_func(nil, type_def, "updateOnFrameHead", ...)  -- System.Void updateOnFrameHead()
```

## `share.StartupGameStateBase`

_No fields or methods._

## `share.StringExtension`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `FileSeparatorChar` | `System.Char[]` | yes | 16 |
| `FileExtensionChar` | `System.Char` | yes | 24 |
| `RandomBase` | `System.String` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getFileName", ...)  -- System.String getFileName(System.String)
sdk.call_native_func(nil, type_def, "getFileNameWithoutExtension", ...)  -- System.String getFileNameWithoutExtension(System.String)
sdk.call_native_func(nil, type_def, "getFolderName", ...)  -- System.String getFolderName(System.String)
sdk.call_native_func(nil, type_def, "hash", ...)  -- System.UInt32 hash(System.String)
sdk.call_native_func(nil, type_def, "isEmpty", ...)  -- System.Boolean isEmpty(System.String)
sdk.call_native_func(nil, type_def, "random", ...)  -- System.String random(System.Int32)
```

## `share.SystemLoadRequestArgs`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.SystemLoadRequestArgs)
:share.SaveLoadRequestArgs getCopy()
```

## `share.SystemSaveRequestArgs`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.SystemSaveRequestArgs)
:share.SaveLoadRequestArgs getCopy()
:System.UInt64 getSaveDataSize()
```

## `share.Tag`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TagNameHash` | `System.Int32[]` | yes | 16 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "buildTagNameHash", ...)  -- System.Void buildTagNameHash()
```

## `share.Tag.Bit`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AIMap` | `share.Tag.Bit` | yes | 16 |
| `Camera` | `share.Tag.Bit` | yes | 16 |
| `Catalog` | `share.Tag.Bit` | yes | 16 |
| `Doll` | `share.Tag.Bit` | yes | 16 |
| `Effect` | `share.Tag.Bit` | yes | 16 |
| `Enemy` | `share.Tag.Bit` | yes | 16 |
| `Environment` | `share.Tag.Bit` | yes | 16 |
| `Event` | `share.Tag.Bit` | yes | 16 |
| `EventStop` | `share.Tag.Bit` | yes | 16 |
| `EventStopUpdate` | `share.Tag.Bit` | yes | 16 |
| `GUI` | `share.Tag.Bit` | yes | 16 |
| `Gimmick` | `share.Tag.Bit` | yes | 16 |
| `GmPause` | `share.Tag.Bit` | yes | 16 |
| `Invalid` | `share.Tag.Bit` | yes | 16 |
| `Item` | `share.Tag.Bit` | yes | 16 |
| `Level` | `share.Tag.Bit` | yes | 16 |
| `PhotoDrawOff` | `share.Tag.Bit` | yes | 16 |
| `PhotoEnemy` | `share.Tag.Bit` | yes | 16 |
| `PhotoEnvAnimal` | `share.Tag.Bit` | yes | 16 |
| `PhotoNPC` | `share.Tag.Bit` | yes | 16 |
| `PhotoPlayer` | `share.Tag.Bit` | yes | 16 |
| `Player` | `share.Tag.Bit` | yes | 16 |
| `Shell` | `share.Tag.Bit` | yes | 16 |
| `WeaponMerchant` | `share.Tag.Bit` | yes | 16 |
| `Zone` | `share.Tag.Bit` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.Tag.Bit[]`

**Methods**

```lua
:System.Void Add(share.Tag.Bit)
:share.Tag.Bit Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.Tag.Bit)
:System.Void CopyTo(share.Tag.Bit[], System.Int32)
:share.Tag.Bit Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.Tag.Bit> GetEnumerator()
:System.Int32 IndexOf(share.Tag.Bit)
:System.Void Insert(System.Int32, share.Tag.Bit)
:System.Boolean Remove(share.Tag.Bit)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.Tag.Bit)
:share.Tag.Bit get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.Tag.Bit)
```

## `share.Tag.List`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AIMap` | `share.Tag.List` | yes | 16 |
| `Camera` | `share.Tag.List` | yes | 16 |
| `Catalog` | `share.Tag.List` | yes | 16 |
| `Doll` | `share.Tag.List` | yes | 16 |
| `Effect` | `share.Tag.List` | yes | 16 |
| `Enemy` | `share.Tag.List` | yes | 16 |
| `Environment` | `share.Tag.List` | yes | 16 |
| `Event` | `share.Tag.List` | yes | 16 |
| `EventStop` | `share.Tag.List` | yes | 16 |
| `EventStopUpdate` | `share.Tag.List` | yes | 16 |
| `GUI` | `share.Tag.List` | yes | 16 |
| `Gimmick` | `share.Tag.List` | yes | 16 |
| `GmPause` | `share.Tag.List` | yes | 16 |
| `Invalid` | `share.Tag.List` | yes | 16 |
| `Item` | `share.Tag.List` | yes | 16 |
| `Level` | `share.Tag.List` | yes | 16 |
| `PhotoDrawOff` | `share.Tag.List` | yes | 16 |
| `PhotoEnemy` | `share.Tag.List` | yes | 16 |
| `PhotoEnvAnimal` | `share.Tag.List` | yes | 16 |
| `PhotoNPC` | `share.Tag.List` | yes | 16 |
| `PhotoPlayer` | `share.Tag.List` | yes | 16 |
| `Player` | `share.Tag.List` | yes | 16 |
| `Shell` | `share.Tag.List` | yes | 16 |
| `WeaponMerchant` | `share.Tag.List` | yes | 16 |
| `Zone` | `share.Tag.List` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.Tag.List[]`

**Methods**

```lua
:System.Void Add(share.Tag.List)
:share.Tag.List Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.Tag.List)
:System.Void CopyTo(share.Tag.List[], System.Int32)
:share.Tag.List Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.Tag.List> GetEnumerator()
:System.Int32 IndexOf(share.Tag.List)
:System.Void Insert(System.Int32, share.Tag.List)
:System.Boolean Remove(share.Tag.List)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.Tag.List)
:share.Tag.List get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.Tag.List)
```

## `share.TestShareBehavior`

_No fields or methods._

## `share.TitleNameType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `BIO` | `share.TitleNameType` | yes | 16 |
| `Invalid` | `share.TitleNameType` | yes | 16 |
| `RE` | `share.TitleNameType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.TitleNameType[]`

**Methods**

```lua
:System.Void Add(share.TitleNameType)
:share.TitleNameType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.TitleNameType)
:System.Void CopyTo(share.TitleNameType[], System.Int32)
:share.TitleNameType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.TitleNameType> GetEnumerator()
:System.Int32 IndexOf(share.TitleNameType)
:System.Void Insert(System.Int32, share.TitleNameType)
:System.Boolean Remove(share.TitleNameType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.TitleNameType)
:share.TitleNameType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.TitleNameType)
```

## `share.TypeExtension`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "getBaseTypes", ...)  -- System.Type[] getBaseTypes(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getBaseTypes", ...)  -- System.Type[] getBaseTypes(System.Type, System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getSubclassFullNames", ...)  -- System.String[] getSubclassFullNames(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getSubclassTypes", ...)  -- System.Type[] getSubclassTypes(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getSubclassTypes", ...)  -- System.Type[] getSubclassTypes(System.Type, System.Type, System.Boolean)
```

## `share.TypeTo`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_SetEnabled` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Func`3<via.Component,System.Boolean,System.Boolean>>` | yes | 16 |
| `_IsEnabled` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Func`2<via.Component,System.Boolean>>` | yes | 24 |
| `_HasSetuped` | `System.Boolean` | yes | 32 |

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "appendProcess", ...)  -- System.Void appendProcess(System.Type, System.Func`3<via.Component,System.Boolean,System.Boolean>, System.Func`2<via.Component,System.Boolean>)
sdk.call_native_func(nil, type_def, "findIsEnabled", ...)  -- System.Func`2<via.Component,System.Boolean> findIsEnabled(System.Type)
sdk.call_native_func(nil, type_def, "findSetEnabled", ...)  -- System.Func`3<via.Component,System.Boolean,System.Boolean> findSetEnabled(System.Type)
sdk.call_native_func(nil, type_def, "isEnabled", ...)  -- System.Boolean isEnabled(via.Component)
sdk.call_native_func(nil, type_def, "requestSetup", ...)  -- System.Void requestSetup()
sdk.call_native_func(nil, type_def, "setEnabled", ...)  -- System.Boolean setEnabled(via.Component, System.Boolean)
sdk.call_native_func(nil, type_def, "setup", ...)  -- System.Void setup()
```

## `share.TypeToHashUserdata`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `TypeNames` | `System.String[]` |  | 32 |

## `share.UpdateOrderGroup`

_No fields or methods._

## `share.User`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Invalid` | `share.User` | yes | 16 |
| `User_00` | `share.User` | yes | 16 |
| `User_01` | `share.User` | yes | 16 |
| `User_02` | `share.User` | yes | 16 |
| `User_03` | `share.User` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.UserServiceManager`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<LastActiveUserIndex>k__BackingField` | `via.UserIndex` |  | 16 |
| `_ActiveUserIndex` | `via.UserIndex` |  | 20 |
| `<ActiveUserNativeId>k__BackingField` | `System.Int32` |  | 24 |
| `OnLoginUserHandler` | `System.Action` |  | 32 |
| `OnChangedActiveUserHandler` | `System.Action` |  | 40 |
| `OnNecessaryActiveUserPairing` | `System.Action` |  | 48 |
| `<DoneFirstActiveUserPairing>k__BackingField` | `System.Boolean` |  | 56 |
| `<DoneActiveUserPairing>k__BackingField` | `System.Boolean` |  | 57 |
| `<IsWaitConnectDevice>k__BackingField` | `System.Boolean` |  | 58 |
| `<IsBackgroundExecution>k__BackingField` | `System.Boolean` |  | 59 |
| `<IsApplicationDeactivated>k__BackingField` | `System.Boolean` |  | 60 |
| `<IsApplicationSuspended>k__BackingField` | `System.Boolean` |  | 61 |
| `<IsNeedPauseRequest>k__BackingField` | `System.Boolean` |  | 62 |
| `<IsNeedPause>k__BackingField` | `System.Boolean` |  | 63 |
| `OnAccountPickerResultHandler` | `System.Action`1<share.AccountPickerResult>` |  | 64 |
| `OnBackgroundExecutionEntered` | `System.Action` |  | 72 |
| `OnBackgroundExecutionReturned` | `System.Action` |  | 80 |
| `OnApplicationDeactivated` | `System.Action` |  | 88 |
| `OnApplicationActivated` | `System.Action` |  | 96 |
| `OnApplicationSuspended` | `System.Action` |  | 104 |
| `OnApplicationResumed` | `System.Action` |  | 112 |
| `<_CurrentPhase>k__BackingField` | `share.UserServiceManager.UserServicePhaseType` |  | 120 |
| `_AccountPickerPhase` | `share.UserServiceManager.AccountPickerPhaseType` |  | 124 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ChangeUser` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `CheckAccountPicker` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `CheckReboot` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `Initialize` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `InputCheckRequest` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `InputChecking` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `Monitoring` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `Unset` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `WaitReboot` | `share.UserServiceManager.AccountPickerPhaseType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.UserServiceManager.AccountPickerPhaseType[]`

**Methods**

```lua
:System.Void Add(share.UserServiceManager.AccountPickerPhaseType)
:share.UserServiceManager.AccountPickerPhaseType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.UserServiceManager.AccountPickerPhaseType)
:System.Void CopyTo(share.UserServiceManager.AccountPickerPhaseType[], System.Int32)
:share.UserServiceManager.AccountPickerPhaseType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.UserServiceManager.AccountPickerPhaseType> GetEnumerator()
:System.Int32 IndexOf(share.UserServiceManager.AccountPickerPhaseType)
:System.Void Insert(System.Int32, share.UserServiceManager.AccountPickerPhaseType)
:System.Boolean Remove(share.UserServiceManager.AccountPickerPhaseType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.UserServiceManager.AccountPickerPhaseType)
:share.UserServiceManager.AccountPickerPhaseType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.UserServiceManager.AccountPickerPhaseType)
```

## `share.UserServiceManager.ActiveUserPadPairingResultType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `NG` | `share.UserServiceManager.ActiveUserPadPairingResultType` | yes | 16 |
| `NecessaryLastInputDevice` | `share.UserServiceManager.ActiveUserPadPairingResultType` | yes | 16 |
| `OK` | `share.UserServiceManager.ActiveUserPadPairingResultType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.UserServiceManager.ActiveUserPadPairingResultType[]`

**Methods**

```lua
:System.Void Add(share.UserServiceManager.ActiveUserPadPairingResultType)
:share.UserServiceManager.ActiveUserPadPairingResultType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.UserServiceManager.ActiveUserPadPairingResultType)
:System.Void CopyTo(share.UserServiceManager.ActiveUserPadPairingResultType[], System.Int32)
:share.UserServiceManager.ActiveUserPadPairingResultType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.UserServiceManager.ActiveUserPadPairingResultType> GetEnumerator()
:System.Int32 IndexOf(share.UserServiceManager.ActiveUserPadPairingResultType)
:System.Void Insert(System.Int32, share.UserServiceManager.ActiveUserPadPairingResultType)
:System.Boolean Remove(share.UserServiceManager.ActiveUserPadPairingResultType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.UserServiceManager.ActiveUserPadPairingResultType)
:share.UserServiceManager.ActiveUserPadPairingResultType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.UserServiceManager.ActiveUserPadPairingResultType)
```

## `share.UserServiceManager.UserServicePhaseType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Normal` | `share.UserServiceManager.UserServicePhaseType` | yes | 16 |
| `Wait` | `share.UserServiceManager.UserServicePhaseType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.UserServiceManager.UserServicePhaseType[]`

**Methods**

```lua
:System.Void Add(share.UserServiceManager.UserServicePhaseType)
:share.UserServiceManager.UserServicePhaseType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.UserServiceManager.UserServicePhaseType)
:System.Void CopyTo(share.UserServiceManager.UserServicePhaseType[], System.Int32)
:share.UserServiceManager.UserServicePhaseType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.UserServiceManager.UserServicePhaseType> GetEnumerator()
:System.Int32 IndexOf(share.UserServiceManager.UserServicePhaseType)
:System.Void Insert(System.Int32, share.UserServiceManager.UserServicePhaseType)
:System.Boolean Remove(share.UserServiceManager.UserServicePhaseType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.UserServiceManager.UserServicePhaseType)
:share.UserServiceManager.UserServicePhaseType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.UserServiceManager.UserServicePhaseType)
```

## `share.UserServiceManagerBehavior`

**Methods**

```lua
:System.Void awake()
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.User[]`

**Methods**

```lua
:System.Void Add(share.User)
:share.User Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.User)
:System.Void CopyTo(share.User[], System.Int32)
:share.User Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.User> GetEnumerator()
:System.Int32 IndexOf(share.User)
:System.Void Insert(System.Int32, share.User)
:System.Boolean Remove(share.User)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.User)
:share.User get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.User)
```

## `share.Util`

_No fields or methods._

## `share.ValidatedBool`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `False` | `share.ValidatedBool` | yes | 16 |
| `None` | `share.ValidatedBool` | yes | 16 |
| `True` | `share.ValidatedBool` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.ValidatedBool[]`

**Methods**

```lua
:System.Void Add(share.ValidatedBool)
:share.ValidatedBool Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.ValidatedBool)
:System.Void CopyTo(share.ValidatedBool[], System.Int32)
:share.ValidatedBool Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.ValidatedBool> GetEnumerator()
:System.Int32 IndexOf(share.ValidatedBool)
:System.Void Insert(System.Int32, share.ValidatedBool)
:System.Boolean Remove(share.ValidatedBool)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.ValidatedBool)
:share.ValidatedBool get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.ValidatedBool)
```

## `share.attribute.GameStateArgumentTypeAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `ArgumentType` | `System.Type` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Type)
```

## `share.attribute.PackageBuiltInAttribute`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Enabled>k__BackingField` | `System.Boolean` |  | 16 |

**Methods**

```lua
:System.Void .ctor(System.Boolean)
:System.Boolean get_Enabled()
:System.Void set_Enabled(System.Boolean)
```

## `share.hid.Command`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Enabled>k__BackingField` | `System.Boolean` |  | 16 |
| `_Triggers` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>` |  | 24 |
| `_Downs` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>` |  | 32 |
| `_Releases` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Boolean>` |  | 40 |
| `_Floats` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,System.Single>` |  | 48 |
| `_Points` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.Point>` |  | 56 |
| `_Vec2s` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.vec2>` |  | 64 |
| `_Vec3s` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.vec3>` |  | 72 |
| `_Quaternions` | `System.Collections.Concurrent.ConcurrentDictionary`2<System.UInt32,via.Quaternion>` |  | 80 |
| `_Inhibits` | `System.Collections.Generic.HashSet`1<System.UInt32>` |  | 88 |
| `_AdaptiveTriggerRange_Left` | `System.Nullable`1<via.Range>` |  | 96 |
| `_AdaptiveTriggerRange_Right` | `System.Nullable`1<via.Range>` |  | 108 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `All` | `share.hid.CommandTag` | yes | 16 |
| `Character` | `share.hid.CommandTag` | yes | 16 |
| `Develop` | `share.hid.CommandTag` | yes | 16 |
| `None` | `share.hid.CommandTag` | yes | 16 |
| `System` | `share.hid.CommandTag` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.CommandTag[]`

**Methods**

```lua
:System.Void Add(share.hid.CommandTag)
:share.hid.CommandTag Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.CommandTag)
:System.Void CopyTo(share.hid.CommandTag[], System.Int32)
:share.hid.CommandTag Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.CommandTag> GetEnumerator()
:System.Int32 IndexOf(share.hid.CommandTag)
:System.Void Insert(System.Int32, share.hid.CommandTag)
:System.Boolean Remove(share.hid.CommandTag)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.CommandTag)
:share.hid.CommandTag get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.CommandTag)
```

## `share.hid.CommandUtil`

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "compare", ...)  -- System.Boolean compare(share.hid.ComparisonType, System.UInt32, System.UInt32, System.UInt32)
sdk.call_native_func(nil, type_def, "getSubclassFullNames", ...)  -- System.String[] getSubclassFullNames(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getSubclassNames", ...)  -- System.String[] getSubclassNames(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "getSubclassTypes", ...)  -- System.Type[] getSubclassTypes(System.Type, System.Boolean)
sdk.call_native_func(nil, type_def, "isWithin", ...)  -- System.Boolean isWithin(System.Single, via.Range, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "isWithin", ...)  -- System.Boolean isWithin(System.Single, via.Range, System.Boolean, System.Boolean, System.Boolean)
sdk.call_native_func(nil, type_def, "isWithin", ...)  -- System.Boolean isWithin(System.Single, via.Range, share.hid.ExtraCommand.RangeStatus)
```

## `share.hid.CommandValueType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Bool` | `share.hid.CommandValueType` | yes | 16 |
| `Float` | `share.hid.CommandValueType` | yes | 16 |
| `Point` | `share.hid.CommandValueType` | yes | 16 |
| `Quaternion` | `share.hid.CommandValueType` | yes | 16 |
| `Vec2` | `share.hid.CommandValueType` | yes | 16 |
| `Vec3` | `share.hid.CommandValueType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.CommandValueType[]`

**Methods**

```lua
:System.Void Add(share.hid.CommandValueType)
:share.hid.CommandValueType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.CommandValueType)
:System.Void CopyTo(share.hid.CommandValueType[], System.Int32)
:share.hid.CommandValueType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.CommandValueType> GetEnumerator()
:System.Int32 IndexOf(share.hid.CommandValueType)
:System.Void Insert(System.Int32, share.hid.CommandValueType)
:System.Boolean Remove(share.hid.CommandValueType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.CommandValueType)
:share.hid.CommandValueType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.CommandValueType)
```

## `share.hid.ComparisonType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Any` | `share.hid.ComparisonType` | yes | 16 |
| `Include` | `share.hid.ComparisonType` | yes | 16 |
| `Match` | `share.hid.ComparisonType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ComparisonType[]`

**Methods**

```lua
:System.Void Add(share.hid.ComparisonType)
:share.hid.ComparisonType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ComparisonType)
:System.Void CopyTo(share.hid.ComparisonType[], System.Int32)
:share.hid.ComparisonType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ComparisonType> GetEnumerator()
:System.Int32 IndexOf(share.hid.ComparisonType)
:System.Void Insert(System.Int32, share.hid.ComparisonType)
:System.Boolean Remove(share.hid.ComparisonType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ComparisonType)
:share.hid.ComparisonType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ComparisonType)
```

## `share.hid.Device`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AxisIntensityThreshold` | `System.Single` | yes | 80 |
| `DisplayOrder_Base` | `System.Int32` | yes | 80 |
| `DisplayOrder_Debug` | `System.Int32` | yes | 80 |
| `DisplayOrder_GamePad` | `System.Int32` | yes | 80 |
| `DisplayOrder_GroupEnd` | `System.Int32` | yes | 80 |
| `DisplayOrder_Keyboard` | `System.Int32` | yes | 80 |
| `DisplayOrder_Mouse` | `System.Int32` | yes | 80 |
| `MaxAdaptiveTriggerMotor` | `System.Int32` | yes | 80 |
| `MousePositionThreshold` | `System.Single` | yes | 80 |
| `KeyboardKeyToMouseButton` | `System.Collections.Generic.Dictionary`2<via.hid.KeyboardKey,via.hid.MouseButton>` | yes | 88 |
| `<User>k__BackingField` | `share.hid.User` |  | 80 |
| `OnChangedDevice` | `System.Action`2<via.hid.NativeDeviceBase,via.hid.NativeDeviceBase>` |  | 88 |
| `<IsGamePadDevice>k__BackingField` | `System.Boolean` |  | 96 |
| `<IsPSGamePadDevice>k__BackingField` | `System.Boolean` |  | 97 |
| `<IsDualSenseDevice>k__BackingField` | `System.Boolean` |  | 98 |
| `<IsMouseDevice>k__BackingField` | `System.Boolean` |  | 99 |
| `<IsKeyboardDevice>k__BackingField` | `System.Boolean` |  | 100 |
| `<StickLeft>k__BackingField` | `share.hid.GamePadStick` |  | 104 |
| `<StickRight>k__BackingField` | `share.hid.GamePadStick` |  | 112 |
| `<AnalogLeft>k__BackingField` | `share.hid.GamePadAnalog` |  | 120 |
| `<AnalogRight>k__BackingField` | `share.hid.GamePadAnalog` |  | 128 |
| `<PositionLeft>k__BackingField` | `via.vec3` |  | 144 |
| `<PositionRight>k__BackingField` | `via.vec3` |  | 160 |
| `<Acceleration>k__BackingField` | `via.vec3` |  | 176 |
| `<AccelerationLeft>k__BackingField` | `via.vec3` |  | 192 |
| `<AccelerationRight>k__BackingField` | `via.vec3` |  | 208 |
| `<AngularVelocity>k__BackingField` | `via.vec3` |  | 224 |
| `<AngularVelocityLeft>k__BackingField` | `via.vec3` |  | 240 |
| `<AngularVelocityRight>k__BackingField` | `via.vec3` |  | 256 |
| `<Orientation>k__BackingField` | `via.Quaternion` |  | 272 |
| `<OrientationLeft>k__BackingField` | `via.Quaternion` |  | 288 |
| `<OrientationRight>k__BackingField` | `via.Quaternion` |  | 304 |
| `<GamePadButtonTrigger>k__BackingField` | `via.hid.GamePadButton` |  | 320 |
| `<GamePadButtonDown>k__BackingField` | `via.hid.GamePadButton` |  | 324 |
| `<GamePadButtonRelease>k__BackingField` | `via.hid.GamePadButton` |  | 328 |
| `<GamePadButtonRepeat>k__BackingField` | `via.hid.GamePadButton` |  | 332 |
| `<AdaptiveTriggerFeedbackParams>k__BackingField` | `System.Collections.Generic.Dictionary`2<via.hid.AdaptiveTriggerMotor,share.hid.Device.AdaptiveTriggerFeedbackParameter>` |  | 336 |
| `<ApplyAdaptiveTriggerFeedbackMotors>k__BackingField` | `System.Collections.Generic.HashSet`1<via.hid.AdaptiveTriggerMotor>` |  | 344 |
| `<GestureManager>k__BackingField` | `via.hid.GestureManager` |  | 352 |
| `PinchInOutEvent` | `void__via_hid_PinchInOutGestureInfo_` |  | 360 |
| `DragEvent` | `void__via_hid_DragGestureInfo_` |  | 368 |
| `<Position>k__BackingField` | `via.Point` |  | 376 |
| `<MovePosition>k__BackingField` | `via.Point` |  | 384 |
| `<RawMovePosition>k__BackingField` | `via.Point` |  | 392 |
| `<Wheel>k__BackingField` | `System.Single` |  | 400 |
| `<WheelDelta>k__BackingField` | `System.Single` |  | 404 |
| `<MouseButtonTrigger>k__BackingField` | `via.hid.MouseButton` |  | 408 |
| `<MouseButtonDown>k__BackingField` | `via.hid.MouseButton` |  | 412 |
| `<MouseButtonRelease>k__BackingField` | `via.hid.MouseButton` |  | 416 |
| `<MouseButtonRepeat>k__BackingField` | `via.hid.MouseButton` |  | 420 |
| `_NativeDevice` | `via.hid.NativeDeviceBase` |  | 424 |
| `_NativeDevices` | `System.Collections.Generic.HashSet`1<via.hid.NativeDeviceBase>` |  | 432 |
| `_CurrentAdaptiveTriggerFeedbackParams` | `share.hid.Device.AdaptiveTriggerFeedbackParameter[]` |  | 440 |
| `_SimpleGesture` | `share.hid.Device.SimpleGesture` |  | 448 |

**Methods**

```lua
:System.Void .ctor()
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "isAnyInput", ...)  -- System.Boolean isAnyInput(via.hid.GamePadDevice)
sdk.call_native_func(nil, type_def, "isAnyTrigger", ...)  -- System.Boolean isAnyTrigger(via.hid.GamePadDevice)
```

## `share.hid.Device.AdaptiveTriggerFeedbackParameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Power>k__BackingField` | `System.Single` |  | 16 |
| `<Frequency>k__BackingField` | `System.Single` |  | 20 |
| `<StartPos>k__BackingField` | `System.Single` |  | 24 |
| `<EndPos>k__BackingField` | `System.Single` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_EndPos()
:System.Single get_Frequency()
:System.Single get_Power()
:System.Single get_StartPos()
:System.Void set_EndPos(System.Single)
:System.Void set_Frequency(System.Single)
:System.Void set_Power(System.Single)
:System.Void set_StartPos(System.Single)
```

## `share.hid.Device.AdaptiveTriggerFeedbackParameter[]`

**Methods**

```lua
:System.Void Add(share.hid.Device.AdaptiveTriggerFeedbackParameter)
:share.hid.Device.AdaptiveTriggerFeedbackParameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.Device.AdaptiveTriggerFeedbackParameter)
:System.Void CopyTo(share.hid.Device.AdaptiveTriggerFeedbackParameter[], System.Int32)
:share.hid.Device.AdaptiveTriggerFeedbackParameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.Device.AdaptiveTriggerFeedbackParameter> GetEnumerator()
:System.Int32 IndexOf(share.hid.Device.AdaptiveTriggerFeedbackParameter)
:System.Void Insert(System.Int32, share.hid.Device.AdaptiveTriggerFeedbackParameter)
:System.Boolean Remove(share.hid.Device.AdaptiveTriggerFeedbackParameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.Device.AdaptiveTriggerFeedbackParameter)
:share.hid.Device.AdaptiveTriggerFeedbackParameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.Device.AdaptiveTriggerFeedbackParameter)
```

## `share.hid.Device.SimpleGesture`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MaxDragInfo` | `System.Int32` | yes | 16 |
| `DragInfos` | `via.hid.DragGestureInfo[]` |  | 16 |
| `PinchInOutInfo` | `via.hid.PinchInOutGestureInfo` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void clear()
:System.Void setDragInfo(via.hid.TouchInfo, System.Int32)
:System.Void update(share.hid.Device)
:System.Void updateDrag(share.hid.Device, via.hid.PSGamePadDevice)
:System.Void updatePintchInOut(share.hid.Device, via.hid.PSGamePadDevice)
```

## `share.hid.DeviceSystem`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Devices>k__BackingField` | `System.Collections.Generic.Dictionary`2<share.hid.User,System.Collections.Generic.List`1<share.hid.Device>>` |  | 16 |
| `<Prefab>k__BackingField` | `share.PrefabController` |  | 24 |
| `<LinkRequests>k__BackingField` | `System.Collections.Generic.List`1<share.hid.DeviceSystem.LinkRequest>` |  | 32 |
| `<LastInputGamePadDevices>k__BackingField` | `System.Collections.Generic.LinkedList`1<via.hid.GamePadDevice>` |  | 40 |
| `<HIDInputMode>k__BackingField` | `share.hid.InputMode` |  | 48 |
| `_ActiveCommand` | `share.hid.CommandTag` |  | 52 |
| `OnChangedActiveCommandTag` | `System.Action`1<share.hid.CommandTag>` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "get_MaxDeviceNumber", ...)  -- System.Int32 get_MaxDeviceNumber()
```

## `share.hid.DeviceSystem.LinkRequest`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<User>k__BackingField` | `share.hid.User` |  | 16 |
| `<NativeDevice>k__BackingField` | `via.hid.NativeDeviceBase` |  | 24 |
| `<Completed>k__BackingField` | `System.Boolean` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.User, via.hid.NativeDeviceBase)
:System.Boolean execute()
:System.Boolean get_Completed()
:via.hid.NativeDeviceBase get_NativeDevice()
:share.hid.User get_User()
:System.Void set_Completed(System.Boolean)
:System.Void set_NativeDevice(via.hid.NativeDeviceBase)
:System.Void set_User(share.hid.User)
```

## `share.hid.DeviceSystem.LinkRequest[]`

**Methods**

```lua
:System.Void Add(share.hid.DeviceSystem.LinkRequest)
:share.hid.DeviceSystem.LinkRequest Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.DeviceSystem.LinkRequest)
:System.Void CopyTo(share.hid.DeviceSystem.LinkRequest[], System.Int32)
:share.hid.DeviceSystem.LinkRequest Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.DeviceSystem.LinkRequest> GetEnumerator()
:System.Int32 IndexOf(share.hid.DeviceSystem.LinkRequest)
:System.Void Insert(System.Int32, share.hid.DeviceSystem.LinkRequest)
:System.Boolean Remove(share.hid.DeviceSystem.LinkRequest)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.DeviceSystem.LinkRequest)
:share.hid.DeviceSystem.LinkRequest get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.DeviceSystem.LinkRequest)
```

## `share.hid.DeviceSystemBehavior`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Prefab` | `via.Prefab` |  | 80 |

**Methods**

```lua
:System.Void awake()
:via.Prefab get_Prefab()
:System.Void onDestroy()
:System.Void start()
:System.Void update()
```

## `share.hid.Device[]`

**Methods**

```lua
:System.Void Add(share.hid.Device)
:share.hid.Device Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.Device)
:System.Void CopyTo(share.hid.Device[], System.Int32)
:share.hid.Device Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.Device> GetEnumerator()
:System.Int32 IndexOf(share.hid.Device)
:System.Void Insert(System.Int32, share.hid.Device)
:System.Boolean Remove(share.hid.Device)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.Device)
:share.hid.Device get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.Device)
```

## `share.hid.ElementDeviceKind`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `KindGamePad` | `share.hid.ElementDeviceKind` | yes | 16 |
| `KindKeyboard` | `share.hid.ElementDeviceKind` | yes | 16 |
| `KindMouse` | `share.hid.ElementDeviceKind` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ElementDeviceKind[]`

**Methods**

```lua
:System.Void Add(share.hid.ElementDeviceKind)
:share.hid.ElementDeviceKind Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ElementDeviceKind)
:System.Void CopyTo(share.hid.ElementDeviceKind[], System.Int32)
:share.hid.ElementDeviceKind Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ElementDeviceKind> GetEnumerator()
:System.Int32 IndexOf(share.hid.ElementDeviceKind)
:System.Void Insert(System.Int32, share.hid.ElementDeviceKind)
:System.Boolean Remove(share.hid.ElementDeviceKind)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ElementDeviceKind)
:share.hid.ElementDeviceKind get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ElementDeviceKind)
```

## `share.hid.ExtraCommand`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Entities>k__BackingField` | `System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity>` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity> get_Entities()
:System.Void set_Entities(System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity>)
:System.Void setup(share.hid.ExtraCommand.Entity.Parameter[])
:System.Void setup(System.Collections.Generic.List`1<share.hid.ExtraCommand.Entity.Parameter>)
:System.Void setup(share.hid.ExtraCommandUserData)
:System.Void update(share.hid.Command, System.Single)
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_CheckType` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` |  | 72 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.Parameter)
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `End_L` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` | yes | 16 |
| `End_R` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` | yes | 16 |
| `Start_L` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` | yes | 16 |
| `Start_R` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:System.Void CopyTo(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType[], System.Int32)
:share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:System.Boolean Remove(share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
:share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType)
```

## `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_CheckType` | `share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.AdaptiveFloatIntensityElement.CheckType get_CheckType()
```

## `share.hid.ExtraCommand.BoolStatus`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Off` | `share.hid.ExtraCommand.BoolStatus` | yes | 16 |
| `On` | `share.hid.ExtraCommand.BoolStatus` | yes | 16 |
| `Release` | `share.hid.ExtraCommand.BoolStatus` | yes | 16 |
| `Trigger` | `share.hid.ExtraCommand.BoolStatus` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ExtraCommand.BoolStatusElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<BoolStatus>k__BackingField` | `share.hid.ExtraCommand.BoolStatus` |  | 64 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.BoolStatusElement.Parameter)
:System.Boolean evaluate(share.hid.Command)
:share.hid.ExtraCommand.BoolStatus get_BoolStatus()
:System.Void set_BoolStatus(share.hid.ExtraCommand.BoolStatus)
```

## `share.hid.ExtraCommand.BoolStatusElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DisplayOrder_Command` | `System.Int32` | yes | 16 |
| `_BoolStatus` | `share.hid.ExtraCommand.BoolStatus` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.BoolStatus get_BoolStatus()
:System.Boolean get_EnabledHoldTime()
```

## `share.hid.ExtraCommand.BoolStatus[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.BoolStatus)
:share.hid.ExtraCommand.BoolStatus Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.BoolStatus)
:System.Void CopyTo(share.hid.ExtraCommand.BoolStatus[], System.Int32)
:share.hid.ExtraCommand.BoolStatus Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.BoolStatus> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.BoolStatus)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.BoolStatus)
:System.Boolean Remove(share.hid.ExtraCommand.BoolStatus)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.BoolStatus)
:share.hid.ExtraCommand.BoolStatus get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.BoolStatus)
```

## `share.hid.ExtraCommand.CombinationElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<CombinationType>k__BackingField` | `share.hid.ExtraCommand.CombinationType` |  | 32 |
| `<ExecuteIndex>k__BackingField` | `System.Int32` |  | 36 |
| `<Elements>k__BackingField` | `System.Collections.Generic.List`1<share.hid.ExtraCommand.Element>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.CombinationElement.Parameter)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_CombinationType` | `share.hid.ExtraCommand.CombinationType` |  | 16 |
| `_ElementParams` | `share.hid.ExtraCommand.Element.Parameter[]` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:share.hid.ExtraCommand.CombinationType get_CombinationType()
:System.String get_DisplayName()
:share.hid.ExtraCommand.Element.Parameter[] get_ElementParams()
```

## `share.hid.ExtraCommand.CombinationType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Any` | `share.hid.ExtraCommand.CombinationType` | yes | 16 |
| `Include` | `share.hid.ExtraCommand.CombinationType` | yes | 16 |
| `Order` | `share.hid.ExtraCommand.CombinationType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ExtraCommand.CombinationType[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.CombinationType)
:share.hid.ExtraCommand.CombinationType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.CombinationType)
:System.Void CopyTo(share.hid.ExtraCommand.CombinationType[], System.Int32)
:share.hid.ExtraCommand.CombinationType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.CombinationType> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.CombinationType)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.CombinationType)
:System.Boolean Remove(share.hid.ExtraCommand.CombinationType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.CombinationType)
:share.hid.ExtraCommand.CombinationType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.CombinationType)
```

## `share.hid.ExtraCommand.CommandElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Hash>k__BackingField` | `System.UInt32` |  | 32 |
| `<HoldTime>k__BackingField` | `System.Single` |  | 36 |
| `<ExtendTime>k__BackingField` | `System.Single` |  | 40 |
| `<HoldTimer>k__BackingField` | `System.Single` |  | 44 |
| `<ExtendTimer>k__BackingField` | `System.Single` |  | 48 |
| `_Name` | `System.String` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.CommandElement.Parameter)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DisplayOrder_Command` | `System.Int32` | yes | 16 |
| `_Name` | `System.String` |  | 16 |
| `_HoldTime` | `System.Single` |  | 24 |
| `_ExtendTime` | `System.Single` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:System.Single get_ExtendTime()
:System.Single get_HoldTime()
:System.String get_Name()
```

## `share.hid.ExtraCommand.Element`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ElementStatus>k__BackingField` | `share.hid.ExtraCommand.ElementStatus` |  | 16 |
| `<ElementName>k__BackingField` | `System.String` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.Element.Parameter)
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

**Methods**

```lua
:System.String ToString()
:System.String get_DisplayName()
```

## `share.hid.ExtraCommand.Element.Parameter[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.Element.Parameter)
:share.hid.ExtraCommand.Element.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.Element.Parameter)
:System.Void CopyTo(share.hid.ExtraCommand.Element.Parameter[], System.Int32)
:share.hid.ExtraCommand.Element.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.Element.Parameter> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.Element.Parameter)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.Element.Parameter)
:System.Boolean Remove(share.hid.ExtraCommand.Element.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.Element.Parameter)
:share.hid.ExtraCommand.Element.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.Element.Parameter)
```

## `share.hid.ExtraCommand.ElementStatus`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Failure` | `share.hid.ExtraCommand.ElementStatus` | yes | 16 |
| `Success` | `share.hid.ExtraCommand.ElementStatus` | yes | 16 |
| `Unsettled` | `share.hid.ExtraCommand.ElementStatus` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ExtraCommand.ElementStatus[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.ElementStatus)
:share.hid.ExtraCommand.ElementStatus Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.ElementStatus)
:System.Void CopyTo(share.hid.ExtraCommand.ElementStatus[], System.Int32)
:share.hid.ExtraCommand.ElementStatus Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.ElementStatus> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.ElementStatus)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.ElementStatus)
:System.Boolean Remove(share.hid.ExtraCommand.ElementStatus)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.ElementStatus)
:share.hid.ExtraCommand.ElementStatus get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.ElementStatus)
```

## `share.hid.ExtraCommand.Element[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.Element)
:share.hid.ExtraCommand.Element Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.Element)
:System.Void CopyTo(share.hid.ExtraCommand.Element[], System.Int32)
:share.hid.ExtraCommand.Element Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.Element> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.Element)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.Element)
:System.Boolean Remove(share.hid.ExtraCommand.Element)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.Element)
:share.hid.ExtraCommand.Element get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.Element)
```

## `share.hid.ExtraCommand.Entity`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Hash>k__BackingField` | `System.UInt32` |  | 16 |
| `<Element>k__BackingField` | `share.hid.ExtraCommand.CombinationElement` |  | 24 |
| `_Name` | `System.String` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.Entity.Parameter)
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Name` | `System.String` |  | 16 |
| `_ElementParam` | `share.hid.ExtraCommand.CombinationElement.Parameter` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_DisplayName()
:share.hid.ExtraCommand.CombinationElement.Parameter get_ElementParam()
:System.String get_Name()
```

## `share.hid.ExtraCommand.Entity.Parameter[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.Entity.Parameter)
:share.hid.ExtraCommand.Entity.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.Entity.Parameter)
:System.Void CopyTo(share.hid.ExtraCommand.Entity.Parameter[], System.Int32)
:share.hid.ExtraCommand.Entity.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.Entity.Parameter> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.Entity.Parameter)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.Entity.Parameter)
:System.Boolean Remove(share.hid.ExtraCommand.Entity.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.Entity.Parameter)
:share.hid.ExtraCommand.Entity.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.Entity.Parameter)
```

## `share.hid.ExtraCommand.Entity[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.Entity)
:share.hid.ExtraCommand.Entity Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.Entity)
:System.Void CopyTo(share.hid.ExtraCommand.Entity[], System.Int32)
:share.hid.ExtraCommand.Entity Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.Entity> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.Entity)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.Entity)
:System.Boolean Remove(share.hid.ExtraCommand.Entity)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.Entity)
:share.hid.ExtraCommand.Entity get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.Entity)
```

## `share.hid.ExtraCommand.FloatIntensityElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.FloatIntensityElement.Parameter)
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.FloatIntensityElement.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
```

## `share.hid.ExtraCommand.IntensityElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<IntensityStatus>k__BackingField` | `share.hid.ExtraCommand.IntensityType` |  | 64 |
| `<Intensity>k__BackingField` | `System.Single` |  | 68 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.IntensityElement.Parameter)
:System.Boolean evaluateIntensity(System.Single)
:System.Single get_Intensity()
:share.hid.ExtraCommand.IntensityType get_IntensityStatus()
:System.Void set_Intensity(System.Single)
:System.Void set_IntensityStatus(share.hid.ExtraCommand.IntensityType)
```

## `share.hid.ExtraCommand.IntensityElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_IntensityStatus` | `share.hid.ExtraCommand.IntensityType` |  | 32 |
| `_Intensity` | `System.Single` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_Intensity()
:share.hid.ExtraCommand.IntensityType get_IntensityStatus()
```

## `share.hid.ExtraCommand.IntensityType`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Eq` | `share.hid.ExtraCommand.IntensityType` | yes | 16 |
| `Ge` | `share.hid.ExtraCommand.IntensityType` | yes | 16 |
| `Gt` | `share.hid.ExtraCommand.IntensityType` | yes | 16 |
| `Le` | `share.hid.ExtraCommand.IntensityType` | yes | 16 |
| `Lt` | `share.hid.ExtraCommand.IntensityType` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.ExtraCommand.IntensityType[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.IntensityType)
:share.hid.ExtraCommand.IntensityType Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.IntensityType)
:System.Void CopyTo(share.hid.ExtraCommand.IntensityType[], System.Int32)
:share.hid.ExtraCommand.IntensityType Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.IntensityType> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.IntensityType)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.IntensityType)
:System.Boolean Remove(share.hid.ExtraCommand.IntensityType)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.IntensityType)
:share.hid.ExtraCommand.IntensityType get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.IntensityType)
```

## `share.hid.ExtraCommand.RangeStatus`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `IncludeMax` | `share.hid.ExtraCommand.RangeStatus` | yes | 16 |
| `IncludeMin` | `share.hid.ExtraCommand.RangeStatus` | yes | 16 |
| `None` | `share.hid.ExtraCommand.RangeStatus` | yes | 16 |
| `Outside` | `share.hid.ExtraCommand.RangeStatus` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.ExtraCommand.RangeStatus[]`

**Methods**

```lua
:System.Void Add(share.hid.ExtraCommand.RangeStatus)
:share.hid.ExtraCommand.RangeStatus Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.ExtraCommand.RangeStatus)
:System.Void CopyTo(share.hid.ExtraCommand.RangeStatus[], System.Int32)
:share.hid.ExtraCommand.RangeStatus Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.ExtraCommand.RangeStatus> GetEnumerator()
:System.Int32 IndexOf(share.hid.ExtraCommand.RangeStatus)
:System.Void Insert(System.Int32, share.hid.ExtraCommand.RangeStatus)
:System.Boolean Remove(share.hid.ExtraCommand.RangeStatus)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.ExtraCommand.RangeStatus)
:share.hid.ExtraCommand.RangeStatus get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.ExtraCommand.RangeStatus)
```

## `share.hid.ExtraCommand.Vec2AngleElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<RangeStatus>k__BackingField` | `share.hid.ExtraCommand.RangeStatus` |  | 64 |
| `<Angle>k__BackingField` | `via.Range` |  | 68 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.Vec2AngleElement.Parameter)
:System.Boolean evaluate(share.hid.Command)
:via.Range get_Angle()
:share.hid.ExtraCommand.RangeStatus get_RangeStatus()
:System.Void set_Angle(via.Range)
:System.Void set_RangeStatus(share.hid.ExtraCommand.RangeStatus)
```

## `share.hid.ExtraCommand.Vec2AngleElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_RangeStatus` | `share.hid.ExtraCommand.RangeStatus` |  | 32 |
| `_Angle` | `via.Range` |  | 36 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
:via.Range get_Angle()
:share.hid.ExtraCommand.RangeStatus get_RangeStatus()
```

## `share.hid.ExtraCommand.Vec2IntensityElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.ExtraCommand.Vec2IntensityElement.Parameter)
:System.Boolean evaluate(share.hid.Command)
```

## `share.hid.ExtraCommand.Vec2IntensityElement.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.ExtraCommand.Element createElement()
```

## `share.hid.ExtraCommandUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Params` | `share.hid.ExtraCommand.Entity.Parameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:share.hid.ExtraCommand.Entity.Parameter[] get_Params()
```

## `share.hid.GamePadAnalog`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<PrevIntensity>k__BackingField` | `System.Single` |  | 16 |
| `_Intensity` | `System.Single` |  | 20 |

**Methods**

```lua
:System.Single get_Intensity()
:System.Single get_PrevIntensity()
:System.Void initialize()
:System.Void set_Intensity(System.Single)
:System.Void set_PrevIntensity(System.Single)
:System.Void update(System.Single)
```

## `share.hid.GamePadStick`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Intensity>k__BackingField` | `System.Single` |  | 16 |
| `<RawIntensity>k__BackingField` | `System.Single` |  | 20 |
| `<Angle>k__BackingField` | `System.Nullable`1<System.Single>` |  | 24 |
| `<RawAngle>k__BackingField` | `System.Nullable`1<System.Single>` |  | 32 |
| `<Trigger>k__BackingField` | `System.Boolean` |  | 40 |
| `<On>k__BackingField` | `System.Boolean` |  | 41 |
| `<Release>k__BackingField` | `System.Boolean` |  | 42 |
| `<PrevAxis>k__BackingField` | `via.vec2` |  | 48 |
| `<PrevRawAxis>k__BackingField` | `via.vec2` |  | 64 |
| `<PrevIntensity>k__BackingField` | `System.Single` |  | 80 |
| `<PrevRawIntensity>k__BackingField` | `System.Single` |  | 84 |
| `<PrevAngle>k__BackingField` | `System.Nullable`1<System.Single>` |  | 88 |
| `<PrevRawAngle>k__BackingField` | `System.Nullable`1<System.Single>` |  | 96 |
| `_Axis` | `via.vec2` |  | 112 |
| `_RawAxis` | `via.vec2` |  | 128 |

**Methods**

```lua
:System.Void .ctor()
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

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `GamePad` | `share.hid.InputMode` | yes | 16 |
| `KeyboardMouse` | `share.hid.InputMode` | yes | 16 |
| `Unknown` | `share.hid.InputMode` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.InputMode[]`

**Methods**

```lua
:System.Void Add(share.hid.InputMode)
:share.hid.InputMode Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.InputMode)
:System.Void CopyTo(share.hid.InputMode[], System.Int32)
:share.hid.InputMode Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.InputMode> GetEnumerator()
:System.Int32 IndexOf(share.hid.InputMode)
:System.Void Insert(System.Int32, share.hid.InputMode)
:System.Boolean Remove(share.hid.InputMode)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.InputMode)
:share.hid.InputMode get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.InputMode)
```

## `share.hid.KeyAssign`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<BoolElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.BoolElement>>` |  | 16 |
| `<FloatElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.FloatElement>>` |  | 24 |
| `<PointElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.PointElement>>` |  | 32 |
| `<Vec2ElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec2Element>>` |  | 40 |
| `<Vec3ElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.Vec3Element>>` |  | 48 |
| `<QuaternionElementDictionary>k__BackingField` | `System.Collections.Generic.Dictionary`2<System.UInt32,System.Collections.Generic.List`1<share.hid.KeyAssign.QuaternionElement>>` |  | 56 |

**Methods**

```lua
:System.Void .ctor()
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
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "makeHash", ...)  -- System.UInt32 makeHash(System.String)
```

## `share.hid.KeyAssign.BoolElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ComparisonType>k__BackingField` | `share.hid.ComparisonType` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.BoolElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.BoolElement)
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
:System.Void set_ComparisonType(share.hid.ComparisonType)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- System.Boolean merge(System.Collections.Generic.List`1<System.Boolean>)
sdk.call_native_func(nil, type_def, "merge", ...)  -- System.Boolean merge(System.Collections.Generic.List`1<share.hid.KeyAssign.BoolElement>, share.hid.Device)
```

## `share.hid.KeyAssign.BoolElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ComparisonType` | `share.hid.ComparisonType` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
```

## `share.hid.KeyAssign.BoolElement[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.BoolElement)
:share.hid.KeyAssign.BoolElement Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.BoolElement)
:System.Void CopyTo(share.hid.KeyAssign.BoolElement[], System.Int32)
:share.hid.KeyAssign.BoolElement Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.BoolElement> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.BoolElement)
:System.Void Insert(System.Int32, share.hid.KeyAssign.BoolElement)
:System.Boolean Remove(share.hid.KeyAssign.BoolElement)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.BoolElement)
:share.hid.KeyAssign.BoolElement get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.BoolElement)
```

## `share.hid.KeyAssign.Element`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MergeListCapacity` | `System.Int32` | yes | 16 |
| `<ElementName>k__BackingField` | `System.String` |  | 16 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.Element)
:System.String get_Description()
:System.String get_DisplayName()
:System.String get_ElementName()
:System.Void set_ElementName(System.String)
```

## `share.hid.KeyAssign.Element.Parameter`

**Methods**

```lua
:System.String ToString()
:System.String get_DisplayName()
```

## `share.hid.KeyAssign.Element.Parameter[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.Element.Parameter)
:share.hid.KeyAssign.Element.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.Element.Parameter)
:System.Void CopyTo(share.hid.KeyAssign.Element.Parameter[], System.Int32)
:share.hid.KeyAssign.Element.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.Element.Parameter> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.Element.Parameter)
:System.Void Insert(System.Int32, share.hid.KeyAssign.Element.Parameter)
:System.Boolean Remove(share.hid.KeyAssign.Element.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.Element.Parameter)
:share.hid.KeyAssign.Element.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.Element.Parameter)
```

## `share.hid.KeyAssign.FloatElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<MergeList>k__BackingField` | `System.Collections.Generic.List`1<System.Single>` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.FloatElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.FloatElement)
:System.Collections.Generic.List`1<System.Single> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<System.Single>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- System.Single merge(System.Collections.Generic.List`1<System.Single>)
sdk.call_native_func(nil, type_def, "merge", ...)  -- System.Single merge(System.Single, System.Single)
sdk.call_native_func(nil, type_def, "merge", ...)  -- System.Single merge(System.Collections.Generic.List`1<share.hid.KeyAssign.FloatElement>, share.hid.Device)
```

## `share.hid.KeyAssign.FloatElement.Parameter`

_No fields or methods._

## `share.hid.KeyAssign.FloatElement[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.FloatElement)
:share.hid.KeyAssign.FloatElement Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.FloatElement)
:System.Void CopyTo(share.hid.KeyAssign.FloatElement[], System.Int32)
:share.hid.KeyAssign.FloatElement Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.FloatElement> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.FloatElement)
:System.Void Insert(System.Int32, share.hid.KeyAssign.FloatElement)
:System.Boolean Remove(share.hid.KeyAssign.FloatElement)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.FloatElement)
:share.hid.KeyAssign.FloatElement get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.FloatElement)
```

## `share.hid.KeyAssign.GamePadButtonElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.hid.GamePadButton` |  | 28 |
| `<Scope>k__BackingField` | `via.hid.GamePadButton` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.GamePadButtonElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.GamePadButtonElement)
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:via.hid.GamePadButton get_Scope()
:via.hid.GamePadButton get_Target()
:System.Void set_Scope(via.hid.GamePadButton)
:System.Void set_Target(via.hid.GamePadButton)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, via.hid.GamePadButton, via.hid.GamePadButton)
```

## `share.hid.KeyAssign.GamePadButtonElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `via.hid.GamePadButton` |  | 20 |
| `_Scope` | `via.hid.GamePadButton` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.GamePadButton get_Scope()
:via.hid.GamePadButton get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadFloat`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `AngularVelocityX` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `AngularVelocityY` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `AngularVelocityZ` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `LStickH` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `LStickIntensity` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `LStickV` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `LTrigBottom` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `None` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `RStickH` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `RStickIntensity` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `RStickV` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `RTrigBottom` | `share.hid.KeyAssign.GamePadFloat` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.GamePadFloatElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.GamePadFloatElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.GamePadFloatElement)
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadFloat, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadFloat>)
:System.Single getValue(share.hid.KeyAssign.GamePadFloat, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadFloatElement.Parameter`

**Methods**

```lua
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadFloat[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.GamePadFloat)
:share.hid.KeyAssign.GamePadFloat Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.GamePadFloat)
:System.Void CopyTo(share.hid.KeyAssign.GamePadFloat[], System.Int32)
:share.hid.KeyAssign.GamePadFloat Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.GamePadFloat> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.GamePadFloat)
:System.Void Insert(System.Int32, share.hid.KeyAssign.GamePadFloat)
:System.Boolean Remove(share.hid.KeyAssign.GamePadFloat)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.GamePadFloat)
:share.hid.KeyAssign.GamePadFloat get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.GamePadFloat)
```

## `share.hid.KeyAssign.GamePadQuaternion`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `None` | `share.hid.KeyAssign.GamePadQuaternion` | yes | 16 |
| `Orientation` | `share.hid.KeyAssign.GamePadQuaternion` | yes | 16 |
| `OrientationLeft` | `share.hid.KeyAssign.GamePadQuaternion` | yes | 16 |
| `OrientationRight` | `share.hid.KeyAssign.GamePadQuaternion` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.GamePadQuaternionElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EnumValues` | `share.hid.KeyAssign.GamePadQuaternion[]` | yes | 16 |
| `<Target>k__BackingField` | `share.hid.KeyAssign.GamePadQuaternion` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.GamePadQuaternionElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.GamePadQuaternionElement)
:System.String ToString()
:via.Quaternion getValue(share.hid.Device)
:share.hid.KeyAssign.GamePadQuaternion get_Target()
:System.Void set_Target(share.hid.KeyAssign.GamePadQuaternion)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getValue", ...)  -- via.Quaternion getValue(share.hid.KeyAssign.GamePadQuaternion, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadQuaternionElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `share.hid.KeyAssign.GamePadQuaternion` |  | 16 |

**Methods**

```lua
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:share.hid.KeyAssign.GamePadQuaternion get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadQuaternion[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.GamePadQuaternion)
:share.hid.KeyAssign.GamePadQuaternion Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.GamePadQuaternion)
:System.Void CopyTo(share.hid.KeyAssign.GamePadQuaternion[], System.Int32)
:share.hid.KeyAssign.GamePadQuaternion Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.GamePadQuaternion> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.GamePadQuaternion)
:System.Void Insert(System.Int32, share.hid.KeyAssign.GamePadQuaternion)
:System.Boolean Remove(share.hid.KeyAssign.GamePadQuaternion)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.GamePadQuaternion)
:share.hid.KeyAssign.GamePadQuaternion get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.GamePadQuaternion)
```

## `share.hid.KeyAssign.GamePadVec2`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `LStick` | `share.hid.KeyAssign.GamePadVec2` | yes | 16 |
| `None` | `share.hid.KeyAssign.GamePadVec2` | yes | 16 |
| `RStick` | `share.hid.KeyAssign.GamePadVec2` | yes | 16 |
| `Touch_Primary` | `share.hid.KeyAssign.GamePadVec2` | yes | 16 |
| `Touch_Secondary` | `share.hid.KeyAssign.GamePadVec2` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.GamePadVec2Element`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.GamePadVec2Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.GamePadVec2Element)
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadVec2, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadVec2>)
:via.vec2 getValue(share.hid.KeyAssign.GamePadVec2, share.hid.Device)
```

## `share.hid.KeyAssign.GamePadVec2Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadVec2[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.GamePadVec2)
:share.hid.KeyAssign.GamePadVec2 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.GamePadVec2)
:System.Void CopyTo(share.hid.KeyAssign.GamePadVec2[], System.Int32)
:share.hid.KeyAssign.GamePadVec2 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.GamePadVec2> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.GamePadVec2)
:System.Void Insert(System.Int32, share.hid.KeyAssign.GamePadVec2)
:System.Boolean Remove(share.hid.KeyAssign.GamePadVec2)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.GamePadVec2)
:share.hid.KeyAssign.GamePadVec2 get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.GamePadVec2)
```

## `share.hid.KeyAssign.GamePadVec3`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Acceleration` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `AccelerationLeft` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `AccelerationRight` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `AngularVelocity` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `AngularVelocityLeft` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `AngularVelocityRight` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `LStickDirection` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `None` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `PositionLeft` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `PositionRight` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `RStickDirection` | `share.hid.KeyAssign.GamePadVec3` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.GamePadVec3Element`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.GamePadVec3Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.GamePadVec3Element)
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.GamePadVec3, System.Collections.Generic.List`1<share.hid.KeyAssign.GamePadVec3>)
:via.vec3 getValue(share.hid.KeyAssign.GamePadVec3, share.hid.Device)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertAxisToDirection", ...)  -- via.vec3 convertAxisToDirection(via.vec2)
```

## `share.hid.KeyAssign.GamePadVec3Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.GamePadVec3[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.GamePadVec3)
:share.hid.KeyAssign.GamePadVec3 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.GamePadVec3)
:System.Void CopyTo(share.hid.KeyAssign.GamePadVec3[], System.Int32)
:share.hid.KeyAssign.GamePadVec3 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.GamePadVec3> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.GamePadVec3)
:System.Void Insert(System.Int32, share.hid.KeyAssign.GamePadVec3)
:System.Boolean Remove(share.hid.KeyAssign.GamePadVec3)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.GamePadVec3)
:share.hid.KeyAssign.GamePadVec3 get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.GamePadVec3)
```

## `share.hid.KeyAssign.KeyBindKeyElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>` |  | 32 |
| `<Scope>k__BackingField` | `System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyElement)
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Scope()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Target()
:System.Void set_Scope(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, chainsaw.KeyBindCommandType[], chainsaw.KeyBindCommandType[])
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

## `share.hid.KeyAssign.KeyBindKeyElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `chainsaw.KeyBindCommandType[]` |  | 24 |
| `_Scope` | `chainsaw.KeyBindCommandType[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:chainsaw.KeyBindCommandType[] get_Scope()
:chainsaw.KeyBindCommandType[] get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyBindKeyFloatElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<ComparisonType>k__BackingField` | `share.hid.ComparisonType` |  | 32 |
| `<Target>k__BackingField` | `System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>` |  | 40 |
| `<Scope>k__BackingField` | `System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>` |  | 48 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyFloatElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyFloatElement)
:System.String ToString()
:System.Single getValue(share.hid.Device)
:share.hid.ComparisonType get_ComparisonType()
:System.Boolean get_IsMatch()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Scope()
:System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType> get_Target()
:System.Void set_ComparisonType(share.hid.ComparisonType)
:System.Void set_Scope(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, chainsaw.KeyBindCommandType[], chainsaw.KeyBindCommandType[])
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>, System.Collections.Generic.HashSet`1<chainsaw.KeyBindCommandType>)
```

## `share.hid.KeyAssign.KeyBindKeyFloatElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_ComparisonType` | `share.hid.ComparisonType` |  | 16 |
| `_Target` | `chainsaw.KeyBindCommandType[]` |  | 24 |
| `_Scope` | `chainsaw.KeyBindCommandType[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
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

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyVec2Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.KeyBindKeyVec2Element)
:System.String ToString()
:via.vec2 getValue(share.hid.Device)
```

## `share.hid.KeyAssign.KeyBindKeyVec2Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyboardKeyElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>` |  | 32 |
| `<Scope>k__BackingField` | `System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>` |  | 40 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.KeyboardKeyElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.KeyboardKeyElement)
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> get_Scope()
:System.Collections.Generic.HashSet`1<via.hid.KeyboardKey> get_Target()
:System.Void set_Scope(System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
:System.Void set_Target(System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, via.hid.KeyboardKey[], via.hid.KeyboardKey[])
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>, System.Collections.Generic.HashSet`1<via.hid.KeyboardKey>)
```

## `share.hid.KeyAssign.KeyboardKeyElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `via.hid.KeyboardKey[]` |  | 24 |
| `_Scope` | `via.hid.KeyboardKey[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.KeyboardKey[] get_Scope()
:via.hid.KeyboardKey[] get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.KeyboardKeyVec2Element`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.KeyboardKeyVec2Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.KeyboardKeyVec2Element)
:System.String ToString()
:via.vec2 getValue(share.hid.Device)
```

## `share.hid.KeyAssign.KeyboardKeyVec2Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseButtonElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Target>k__BackingField` | `via.hid.MouseButton` |  | 28 |
| `<Scope>k__BackingField` | `via.hid.MouseButton` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.MouseButtonElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.MouseButtonElement)
:System.String ToString()
:System.Boolean getValue(share.hid.Device)
:via.hid.MouseButton get_Scope()
:via.hid.MouseButton get_Target()
:System.Void set_Scope(via.hid.MouseButton)
:System.Void set_Target(via.hid.MouseButton)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(share.hid.ComparisonType, via.hid.MouseButton, via.hid.MouseButton)
```

## `share.hid.KeyAssign.MouseButtonElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `via.hid.MouseButton` |  | 20 |
| `_Scope` | `via.hid.MouseButton` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:via.hid.MouseButton get_Scope()
:via.hid.MouseButton get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseFloat`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `DeltaDistance` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `DeltaWheel` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `MovePositionH` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `MovePositionV` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `None` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `PositionH` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `PositionV` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `Wheel` | `share.hid.KeyAssign.MouseFloat` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.MouseFloatElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.MouseFloatElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.MouseFloatElement)
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.MouseFloat, System.Collections.Generic.List`1<share.hid.KeyAssign.MouseFloat>)
:System.Single getValue(share.hid.KeyAssign.MouseFloat, share.hid.Device)
```

## `share.hid.KeyAssign.MouseFloatElement.Parameter`

**Methods**

```lua
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseFloat[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.MouseFloat)
:share.hid.KeyAssign.MouseFloat Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.MouseFloat)
:System.Void CopyTo(share.hid.KeyAssign.MouseFloat[], System.Int32)
:share.hid.KeyAssign.MouseFloat Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.MouseFloat> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.MouseFloat)
:System.Void Insert(System.Int32, share.hid.KeyAssign.MouseFloat)
:System.Boolean Remove(share.hid.KeyAssign.MouseFloat)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.MouseFloat)
:share.hid.KeyAssign.MouseFloat get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.MouseFloat)
```

## `share.hid.KeyAssign.MousePoint`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MovePosition` | `share.hid.KeyAssign.MousePoint` | yes | 16 |
| `None` | `share.hid.KeyAssign.MousePoint` | yes | 16 |
| `Position` | `share.hid.KeyAssign.MousePoint` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.MousePointElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `EnumValues` | `share.hid.KeyAssign.MousePoint[]` | yes | 16 |
| `<Target>k__BackingField` | `share.hid.KeyAssign.MousePoint` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.MousePointElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.MousePointElement)
:System.String ToString()
:via.Point getValue(share.hid.Device)
:share.hid.KeyAssign.MousePoint get_Target()
:System.Void set_Target(share.hid.KeyAssign.MousePoint)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, ".cctor", ...)  -- System.Void .cctor()
sdk.call_native_func(nil, type_def, "getValue", ...)  -- via.Point getValue(share.hid.KeyAssign.MousePoint, share.hid.Device)
```

## `share.hid.KeyAssign.MousePointElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Target` | `share.hid.KeyAssign.MousePoint` |  | 16 |

**Methods**

```lua
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:share.hid.KeyAssign.MousePoint get_Target()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MousePoint[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.MousePoint)
:share.hid.KeyAssign.MousePoint Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.MousePoint)
:System.Void CopyTo(share.hid.KeyAssign.MousePoint[], System.Int32)
:share.hid.KeyAssign.MousePoint Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.MousePoint> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.MousePoint)
:System.Void Insert(System.Int32, share.hid.KeyAssign.MousePoint)
:System.Boolean Remove(share.hid.KeyAssign.MousePoint)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.MousePoint)
:share.hid.KeyAssign.MousePoint get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.MousePoint)
```

## `share.hid.KeyAssign.MouseVec2`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `MovePosition` | `share.hid.KeyAssign.MouseVec2` | yes | 16 |
| `None` | `share.hid.KeyAssign.MouseVec2` | yes | 16 |
| `Position` | `share.hid.KeyAssign.MouseVec2` | yes | 16 |
| `value__` | `System.UInt32` |  | 16 |

## `share.hid.KeyAssign.MouseVec2Element`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.MouseVec2Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.MouseVec2Element)
:System.String ToString()
:System.Void convertTarget(share.hid.KeyAssign.MouseVec2, System.Collections.Generic.List`1<share.hid.KeyAssign.MouseVec2>)
:via.vec2 getValue(share.hid.KeyAssign.MouseVec2, share.hid.Device)
```

## `share.hid.KeyAssign.MouseVec2Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
:System.String ToString()
:share.hid.KeyAssign.Element createElement()
:System.String get_DisplayName()
:System.Boolean get_Valid()
```

## `share.hid.KeyAssign.MouseVec2[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.MouseVec2)
:share.hid.KeyAssign.MouseVec2 Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.MouseVec2)
:System.Void CopyTo(share.hid.KeyAssign.MouseVec2[], System.Int32)
:share.hid.KeyAssign.MouseVec2 Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.MouseVec2> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.MouseVec2)
:System.Void Insert(System.Int32, share.hid.KeyAssign.MouseVec2)
:System.Boolean Remove(share.hid.KeyAssign.MouseVec2)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.MouseVec2)
:share.hid.KeyAssign.MouseVec2 get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.MouseVec2)
```

## `share.hid.KeyAssign.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Name` | `System.String` |  | 16 |
| `_Params` | `share.hid.KeyAssign.Element.Parameter[]` |  | 24 |

**Methods**

```lua
:System.Void .ctor()
:System.String get_DisplayName()
:System.String get_Name()
:share.hid.KeyAssign.Element.Parameter[] get_Params()
```

## `share.hid.KeyAssign.Parameter[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.Parameter)
:share.hid.KeyAssign.Parameter Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.Parameter)
:System.Void CopyTo(share.hid.KeyAssign.Parameter[], System.Int32)
:share.hid.KeyAssign.Parameter Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.Parameter> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.Parameter)
:System.Void Insert(System.Int32, share.hid.KeyAssign.Parameter)
:System.Boolean Remove(share.hid.KeyAssign.Parameter)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.Parameter)
:share.hid.KeyAssign.Parameter get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.Parameter)
```

## `share.hid.KeyAssign.PointElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.PointElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.PointElement)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.Point merge(System.Collections.Generic.List`1<via.Point>)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.Point merge(System.Collections.Generic.List`1<share.hid.KeyAssign.PointElement>, share.hid.Device)
```

## `share.hid.KeyAssign.PointElement.Parameter`

_No fields or methods._

## `share.hid.KeyAssign.PointElement[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.PointElement)
:share.hid.KeyAssign.PointElement Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.PointElement)
:System.Void CopyTo(share.hid.KeyAssign.PointElement[], System.Int32)
:share.hid.KeyAssign.PointElement Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.PointElement> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.PointElement)
:System.Void Insert(System.Int32, share.hid.KeyAssign.PointElement)
:System.Boolean Remove(share.hid.KeyAssign.PointElement)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.PointElement)
:share.hid.KeyAssign.PointElement get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.PointElement)
```

## `share.hid.KeyAssign.QuaternionElement`

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.QuaternionElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.QuaternionElement)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.Quaternion merge(System.Collections.Generic.List`1<via.Quaternion>)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.Quaternion merge(System.Collections.Generic.List`1<share.hid.KeyAssign.QuaternionElement>, share.hid.Device)
```

## `share.hid.KeyAssign.QuaternionElement.Parameter`

_No fields or methods._

## `share.hid.KeyAssign.QuaternionElement[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.QuaternionElement)
:share.hid.KeyAssign.QuaternionElement Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.QuaternionElement)
:System.Void CopyTo(share.hid.KeyAssign.QuaternionElement[], System.Int32)
:share.hid.KeyAssign.QuaternionElement Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.QuaternionElement> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.QuaternionElement)
:System.Void Insert(System.Int32, share.hid.KeyAssign.QuaternionElement)
:System.Boolean Remove(share.hid.KeyAssign.QuaternionElement)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.QuaternionElement)
:share.hid.KeyAssign.QuaternionElement get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.QuaternionElement)
```

## `share.hid.KeyAssign.Vec2Element`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<MergeList>k__BackingField` | `System.Collections.Generic.List`1<via.vec2>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.Vec2Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.Vec2Element)
:System.Collections.Generic.List`1<via.vec2> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<via.vec2>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec2 merge(System.Collections.Generic.List`1<via.vec2>, System.Single, System.Boolean)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec2 merge(via.vec2, via.vec2)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec2 merge(System.Collections.Generic.List`1<share.hid.KeyAssign.Vec2Element>, share.hid.Device, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.Vec2Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
```

## `share.hid.KeyAssign.Vec2Element[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.Vec2Element)
:share.hid.KeyAssign.Vec2Element Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.Vec2Element)
:System.Void CopyTo(share.hid.KeyAssign.Vec2Element[], System.Int32)
:share.hid.KeyAssign.Vec2Element Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.Vec2Element> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.Vec2Element)
:System.Void Insert(System.Int32, share.hid.KeyAssign.Vec2Element)
:System.Boolean Remove(share.hid.KeyAssign.Vec2Element)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.Vec2Element)
:share.hid.KeyAssign.Vec2Element get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.Vec2Element)
```

## `share.hid.KeyAssign.Vec3Element`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<MergeList>k__BackingField` | `System.Collections.Generic.List`1<via.vec3>` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.Vec3Element.Parameter)
:System.Void .ctor(share.hid.KeyAssign.Vec3Element)
:System.Collections.Generic.List`1<via.vec3> get_MergeList()
:System.Void set_MergeList(System.Collections.Generic.List`1<via.vec3>)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec3 merge(System.Collections.Generic.List`1<via.vec3>, System.Single, System.Boolean)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec3 merge(via.vec3, via.vec3)
sdk.call_native_func(nil, type_def, "merge", ...)  -- via.vec3 merge(System.Collections.Generic.List`1<share.hid.KeyAssign.Vec3Element>, share.hid.Device, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.Vec3Element.Parameter`

**Methods**

```lua
:System.Void .ctor()
```

## `share.hid.KeyAssign.Vec3Element[]`

**Methods**

```lua
:System.Void Add(share.hid.KeyAssign.Vec3Element)
:share.hid.KeyAssign.Vec3Element Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.KeyAssign.Vec3Element)
:System.Void CopyTo(share.hid.KeyAssign.Vec3Element[], System.Int32)
:share.hid.KeyAssign.Vec3Element Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.KeyAssign.Vec3Element> GetEnumerator()
:System.Int32 IndexOf(share.hid.KeyAssign.Vec3Element)
:System.Void Insert(System.Int32, share.hid.KeyAssign.Vec3Element)
:System.Boolean Remove(share.hid.KeyAssign.Vec3Element)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.KeyAssign.Vec3Element)
:share.hid.KeyAssign.Vec3Element get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.KeyAssign.Vec3Element)
```

## `share.hid.KeyAssign.VecElement`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `<Magnification>k__BackingField` | `System.Single` |  | 24 |
| `<Normalized>k__BackingField` | `System.Boolean` |  | 28 |

**Methods**

```lua
:System.Void .ctor()
:System.Void .ctor(share.hid.KeyAssign.VecElement.Parameter)
:System.Void .ctor(share.hid.KeyAssign.VecElement)
:System.Single get_Magnification()
:System.Boolean get_Normalized()
:System.Void set_Magnification(System.Single)
:System.Void set_Normalized(System.Boolean)
```

**Static methods**

```lua
sdk.call_native_func(nil, type_def, "convertString", ...)  -- System.String convertString(System.String, System.Single, System.Boolean)
```

## `share.hid.KeyAssign.VecElement.Parameter`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Magnification` | `System.Single` |  | 16 |
| `_Normalized` | `System.Boolean` |  | 20 |

**Methods**

```lua
:System.Void .ctor()
:System.Single get_Magnification()
:System.Boolean get_Normalized()
```

## `share.hid.KeyAssignUserData`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `_Params` | `share.hid.KeyAssign.Parameter[]` |  | 32 |

**Methods**

```lua
:System.Void .ctor()
:share.hid.KeyAssign.Parameter[] get_Params()
```

## `share.hid.User`

**Fields**

| name | type | static | offset |
| --- | --- | --- | --- |
| `Invalid` | `share.hid.User` | yes | 16 |
| `User_00` | `share.hid.User` | yes | 16 |
| `User_01` | `share.hid.User` | yes | 16 |
| `User_02` | `share.hid.User` | yes | 16 |
| `User_03` | `share.hid.User` | yes | 16 |
| `User_Max` | `share.hid.User` | yes | 16 |
| `value__` | `System.Int32` |  | 16 |

## `share.hid.User[]`

**Methods**

```lua
:System.Void Add(share.hid.User)
:share.hid.User Address(System.Int32)
:System.Void Clear()
:System.Boolean Contains(share.hid.User)
:System.Void CopyTo(share.hid.User[], System.Int32)
:share.hid.User Get(System.Int32)
:System.Collections.Generic.IEnumerator`1<share.hid.User> GetEnumerator()
:System.Int32 IndexOf(share.hid.User)
:System.Void Insert(System.Int32, share.hid.User)
:System.Boolean Remove(share.hid.User)
:System.Void RemoveAt(System.Int32)
:System.Void Set(System.Int32, share.hid.User)
:share.hid.User get_Item(System.Int32)
:System.Void set_Item(System.Int32, share.hid.User)
```
