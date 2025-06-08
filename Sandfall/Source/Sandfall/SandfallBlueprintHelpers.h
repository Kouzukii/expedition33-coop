#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=DateTime -FallbackName=DateTime
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Timespan -FallbackName=Timespan
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESpawnActorCollisionHandlingMethod -FallbackName=ESpawnActorCollisionHandlingMethod
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESpawnActorScaleMethod -FallbackName=ESpawnActorScaleMethod
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=FormatArgumentData -FallbackName=FormatArgumentData
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=LatentActionInfo -FallbackName=LatentActionInfo
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerDynamicDelegate__DelegateSignature -FallbackName=TimerDynamicDelegateDelegate
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTags -ObjectName=GameplayTag -FallbackName=GameplayTag
#include "OnInputPressedDelegate.h"
#include "Templates/SubclassOf.h"
#include "SandfallBlueprintHelpers.generated.h"

class AActor;
class APawn;
class APlayerController;
class UActorComponent;
class UDataTable;
class ULightComponent;
class UMaterialInstanceConstant;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMesh;
class USoundBase;
class UWorld;
class UWorldPartitionStreamingSourceComponent;

UCLASS(Blueprintable)
class SANDFALL_API USandfallBlueprintHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USandfallBlueprintHelpers();

    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    static void WaitTillLevelStreamingCompleted(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const TArray<UWorldPartitionStreamingSourceComponent*>& SourceComponents, bool AddPlayerControllerSource);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UpdateWPRuntimeHashSetRuntimeStreamingDataLoadingRange(const UObject* WorldContextObject, FName RuntimeStreamingDataName, int32 NewLoadingRange);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UpdateFloatingObjectsTransform(const UObject* WorldContextObject, const TArray<USceneComponent*>& Objects, const TArray<FVector> SpeedVectors, const TArray<FVector> RandomLocations, const TArray<double>& RotatorSpeeds, const TArray<double>& MovingDistances, const TArray<int32> MultiplierRemapArray);

    UFUNCTION(BlueprintCallable)
    static UClass* TryGetBlueprintClass(UObject* Object);

    UFUNCTION(BlueprintCallable)
    static void TriggerMouseLMBUp(const FVector2D& CursorPosition);

    UFUNCTION(BlueprintCallable)
    static void TriggerMouseLMBDown(const FVector2D& CursorPosition);

    UFUNCTION(BlueprintCallable)
    static void TestMemTrace(const FString& ip, int32 Port);

    UFUNCTION(BlueprintCallable)
    static void StopMemTrace();

    UFUNCTION(BlueprintCallable)
    static void StartMemTrace(const FString& ip, int32 Port);

    UFUNCTION(BlueprintCallable)
    static FTimerHandle SetTimerDelegate(FTimerDynamicDelegate Delegate, float Time, bool bLooping, float InitialStartDelay, float InitialStartDelayVariance);

    UFUNCTION(BlueprintCallable)
    static void SetComponentIsEditorOnly(UActorComponent* ActorComponent, bool bIsEditorOnly);

    UFUNCTION(BlueprintCallable)
    static void SetActorIsSpatiallyLoaded(AActor* Actor, bool bIsSpatiallyLoaded);

    UFUNCTION(BlueprintCallable)
    static void SetActorIsEditorOnly(AActor* Actor, bool bIsEditorOnly);

    UFUNCTION(BlueprintCallable)
    static void ResetMaterialInstanceTextureStreamingData(UMaterialInstanceConstant* _MaterialInstance);

    UFUNCTION(BlueprintCallable)
    static void ResetAllProperties(UObject* Object, bool bIncludeComponents);

    UFUNCTION(BlueprintCallable)
    static void RequestToTrimAudioStreamingCache();

    UFUNCTION(BlueprintCallable)
    static bool RemoveMaterialInstanceStaticSwitchOverride(UMaterialInstanceConstant* _MaterialInstance, const FName& _ParameterName);

    UFUNCTION(BlueprintCallable)
    static bool RemoveMaterialInstanceParameterOverride(UMaterialInstanceConstant* _MaterialInstance, const FName& _ParameterName);

    UFUNCTION(BlueprintCallable)
    static void ReloadActor(AActor* Actor);

    UFUNCTION(BlueprintCallable)
    static void RegisterStringCVar(const FName _name, const FString& _defaultValue, const FText _description);

    UFUNCTION(BlueprintCallable)
    static void RegisterIntegerCVar(const FName _name, const int32 _defaultValue, const FText _description);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RegisterInputAction(UObject* WorldContextObject, FName InputAction, FOnInputPressed OnPressed);

    UFUNCTION(BlueprintCallable)
    static void RegisterBoolCVar(const FName _name, bool _defaultValue, const FText _description);

    UFUNCTION(BlueprintCallable)
    static void Refresh3DEditorViewport();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PrintStringInLog(const UObject* WorldContextObject, const FString& InString);

    UFUNCTION(BlueprintCallable)
    static TArray<FString> ParseIntoArrayLines(const FString& In, bool CullEmpty);

    UFUNCTION(BlueprintCallable)
    static void OverrideBoolCVar(const FName _name, bool _value);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform OffsetTransform(const FTransform& StartTransform, float ForwardOffset, float UpOffset);

    UFUNCTION(BlueprintCallable)
    static void MemTraceUserMark(const FString& userMark);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void Map_ToString(const TMap<int32, int32>& TargetMap, TArray<FString>& OutStringList);

    UFUNCTION(BlueprintCallable)
    static void Map_Remap(const TMap<int32, int32>& TargetMap, const TMap<int32, int32>& RemapTable, TMap<int32, int32>& ResultMap);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRunningOnSteamDeck();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRunningAutomationTest();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPawnInputEnabled(const APawn* _actor);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPackagedBuild();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInSimulateMode();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInPlayMode();

    UFUNCTION(BlueprintCallable)
    static bool IsEventDispatcherConnected(UObject* Object, FName EventDispatcherName);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCurrentConsoleTypeLockheart();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool isCollisionProfileValid(FName ProfileName);

    UFUNCTION(BlueprintCallable)
    static bool IsActorSpatiallyLoaded(const AActor* Actor);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasActorBegunPlay(const AActor* Actor);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetVendorBuildInfo(UObject* WorldContextObject, FString& OwnerInfo, FString& BuildInfo);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetUpscalerInfo();

    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetStackTrace();

    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetSamplingRegionNames(USkeletalMesh* SkeletalMeshAsset);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGameplayTag GetPlatformNameAsTag();

    UFUNCTION(BlueprintCallable)
    static float GetMaxDistanceAttenuation(USoundBase* Sound);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetLastRenderTimeOnScreen(const UPrimitiveComponent* Primitive);

    UFUNCTION(BlueprintCallable)
    static FTransform GetEditorViewportTransform();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetDebugInfo();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetDataTableRowFromName(UDataTable* Table, FName RowName, FTableRowBase& OutRow);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UActorComponent* GetComponentFromReference(const FComponentReference& ComponentReference, AActor* OwningActor);

    UFUNCTION(BlueprintCallable)
    static UObject* GetClassDefaultObject(UClass* Object);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetBuildInfo(UObject* WorldContextObject, FString& Changelist, FString& CurrentPersistentLevel);

    UFUNCTION(BlueprintCallable)
    static void GetAllLightComponents(UWorld* World, TArray<ULightComponent*>& LightComponents);

    UFUNCTION(BlueprintCallable)
    static void GetAllComponentsByClass(UWorld* World, TSubclassOf<UActorComponent> Class, TArray<UActorComponent*>& Components);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString FormatTimespanWithPattern(FTimespan Timespan, const FString& FormatString);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString FormatTimespan(FTimespan Timespan);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString FormatDateTimeWithPattern(FDateTime DateTime, const FString& FormatString);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString FormatDateTime(FDateTime DateTime);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString Format(const FString& InPattern, TArray<FFormatArgumentData> InArgs);

    UFUNCTION(BlueprintCallable)
    static void FlushInputs(APlayerController* PlayerController);

    UFUNCTION(BlueprintCallable)
    static AActor* FinishSpawningActor(AActor* Actor, const FTransform& SpawnTransform, ESpawnActorScaleMethod TransformScaleMethod);

    UFUNCTION(BlueprintCallable)
    static void ExecuteDelegate(FOnInputPressed Delegate);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString EscapeJson(const FString& Input);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EqualsObjects(const UObject* A, const UObject* B);

    UFUNCTION(BlueprintCallable)
    static void EditorAlert(const FText& _text);

    UFUNCTION(BlueprintCallable)
    static void Editor_TakeScreenshot(const FString& _filename, bool _showUI);

    UFUNCTION(BlueprintCallable)
    static void Editor_PushJSONToMongoDB(const FString& Json);

    UFUNCTION(BlueprintCallable)
    static bool Editor_MoveScreenshots(const FString& _sourceFile, const FString& _destination);

    UFUNCTION(BlueprintCallable)
    static bool Editor_GetStatValue(const FName _StatGroup, const FName _StatName, bool _isMemory, FString& _OutValue);

    UFUNCTION(BlueprintCallable)
    static bool Editor_GetShaderCompilationState(int32& jobCount, int32& workerCount);

    UFUNCTION(BlueprintCallable)
    static bool Editor_FileSaveString(const FString& Content, const FString& Filename);

    UFUNCTION(BlueprintCallable)
    static bool Editor_FileLoadStringReal(const FString& Filename, FString& Content);

    UFUNCTION(BlueprintCallable)
    static bool Editor_FileLoadString(const FString& Filename, FString& Content);

    UFUNCTION(BlueprintCallable)
    static bool Editor_FileDelete(const FString& Filename);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugCircleArc(const UObject* WorldContextObject, FVector Center, float Radius, FVector Direction, float AngleWidth, int32 Segments, FLinearColor Color, float Lifetime, float Thickness);

    UFUNCTION(BlueprintCallable)
    static void DebugMe(UObject* _objectToDebug);

    UFUNCTION(BlueprintCallable)
    static UClass* DebugFindClassByName(const FString& _className);

    UFUNCTION(BlueprintCallable)
    static void DebugCppBreakpoint();

    UFUNCTION(BlueprintCallable)
    static UObject* DebugConstructFromClass(UClass* _class, UObject* _owner);

    UFUNCTION(BlueprintCallable)
    static void CopyAllProperties(UObject* FromObject, UObject* ToObject, bool bIncludeComponents);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ConvertSoftRefToWorldSoftRef(const TSoftObjectPtr<UObject>& _InObject, TSoftObjectPtr<UWorld>& _OutWorldSoftRef);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CompareStrings(const FString& A, const FString& B);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="_worldContext"))
    static bool CheckEntitlement(UWorld* _worldContext);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CancelLatentActions(UObject* WorldContextObject, UObject* Object);

    UFUNCTION(BlueprintCallable)
    static void CallFunctionByName(UObject* _object, const FString& _functionName, bool& _IsFailed);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void BlockTillLevelStreamingCompleted(UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* BeginDeferredActorSpawnFromClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, AActor* Owner, ESpawnActorScaleMethod TransformScaleMethod);

    UFUNCTION(BlueprintCallable)
    static void AssertMessage(const FString& _message, const bool _breakpoint);

    UFUNCTION(BlueprintCallable)
    static void Assert(const bool _check, const FText _message, const bool _breakpoint);

    UFUNCTION(BlueprintCallable)
    static void Array_Remap(const TArray<int32>& TargetArray, const TMap<int32, int32>& RemapTable, TArray<int32>& ResultArray);

};

