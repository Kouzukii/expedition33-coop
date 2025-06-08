#include "SandfallBlueprintHelpers.h"

#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"

USandfallBlueprintHelpers::USandfallBlueprintHelpers() {
}

void USandfallBlueprintHelpers::WaitTillLevelStreamingCompleted(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const TArray<UWorldPartitionStreamingSourceComponent*>& SourceComponents, bool AddPlayerControllerSource) {
}

void USandfallBlueprintHelpers::UpdateWPRuntimeHashSetRuntimeStreamingDataLoadingRange(const UObject* WorldContextObject, FName RuntimeStreamingDataName, int32 NewLoadingRange) {
}

void USandfallBlueprintHelpers::UpdateFloatingObjectsTransform(const UObject* WorldContextObject, const TArray<USceneComponent*>& Objects, const TArray<FVector> SpeedVectors, const TArray<FVector> RandomLocations, const TArray<double>& RotatorSpeeds, const TArray<double>& MovingDistances, const TArray<int32> MultiplierRemapArray) {
}

UClass* USandfallBlueprintHelpers::TryGetBlueprintClass(UObject* Object) {
    return NULL;
}

void USandfallBlueprintHelpers::TriggerMouseLMBUp(const FVector2D& CursorPosition) {
}

void USandfallBlueprintHelpers::TriggerMouseLMBDown(const FVector2D& CursorPosition) {
}

void USandfallBlueprintHelpers::TestMemTrace(const FString& ip, int32 Port) {
}

void USandfallBlueprintHelpers::StopMemTrace() {
}

void USandfallBlueprintHelpers::StartMemTrace(const FString& ip, int32 Port) {
}

FTimerHandle USandfallBlueprintHelpers::SetTimerDelegate(FTimerDynamicDelegate Delegate, float Time, bool bLooping, float InitialStartDelay, float InitialStartDelayVariance) {
    return FTimerHandle{};
}

void USandfallBlueprintHelpers::SetComponentIsEditorOnly(UActorComponent* ActorComponent, bool bIsEditorOnly) {
}

void USandfallBlueprintHelpers::SetActorIsSpatiallyLoaded(AActor* Actor, bool bIsSpatiallyLoaded) {
}

void USandfallBlueprintHelpers::SetActorIsEditorOnly(AActor* Actor, bool bIsEditorOnly) {
}

void USandfallBlueprintHelpers::ResetMaterialInstanceTextureStreamingData(UMaterialInstanceConstant* _MaterialInstance) {
}

void USandfallBlueprintHelpers::ResetAllProperties(UObject* Object, bool bIncludeComponents) {
}

void USandfallBlueprintHelpers::RequestToTrimAudioStreamingCache() {
}

bool USandfallBlueprintHelpers::RemoveMaterialInstanceStaticSwitchOverride(UMaterialInstanceConstant* _MaterialInstance, const FName& _ParameterName) {
    return false;
}

bool USandfallBlueprintHelpers::RemoveMaterialInstanceParameterOverride(UMaterialInstanceConstant* _MaterialInstance, const FName& _ParameterName) {
    return false;
}

void USandfallBlueprintHelpers::ReloadActor(AActor* Actor) {
}

void USandfallBlueprintHelpers::RegisterStringCVar(const FName _name, const FString& _defaultValue, const FText _description) {
}

void USandfallBlueprintHelpers::RegisterIntegerCVar(const FName _name, const int32 _defaultValue, const FText _description) {
}

void USandfallBlueprintHelpers::RegisterInputAction(UObject* WorldContextObject, FName InputAction, FOnInputPressed OnPressed) {
}

void USandfallBlueprintHelpers::RegisterBoolCVar(const FName _name, bool _defaultValue, const FText _description) {
}

void USandfallBlueprintHelpers::Refresh3DEditorViewport() {
}

void USandfallBlueprintHelpers::PrintStringInLog(const UObject* WorldContextObject, const FString& InString) {
}

TArray<FString> USandfallBlueprintHelpers::ParseIntoArrayLines(const FString& In, bool CullEmpty) {
    return TArray<FString>();
}

void USandfallBlueprintHelpers::OverrideBoolCVar(const FName _name, bool _value) {
}

FTransform USandfallBlueprintHelpers::OffsetTransform(const FTransform& StartTransform, float ForwardOffset, float UpOffset) {
    return FTransform{};
}

void USandfallBlueprintHelpers::MemTraceUserMark(const FString& userMark) {
}

void USandfallBlueprintHelpers::Map_ToString(const TMap<int32, int32>& TargetMap, TArray<FString>& OutStringList) {
}

void USandfallBlueprintHelpers::Map_Remap(const TMap<int32, int32>& TargetMap, const TMap<int32, int32>& RemapTable, TMap<int32, int32>& ResultMap) {
}

bool USandfallBlueprintHelpers::IsRunningOnSteamDeck() {
    return false;
}

bool USandfallBlueprintHelpers::IsRunningAutomationTest() {
    return false;
}

bool USandfallBlueprintHelpers::IsPawnInputEnabled(const APawn* _actor) {
    return false;
}

bool USandfallBlueprintHelpers::IsPackagedBuild() {
    return false;
}

bool USandfallBlueprintHelpers::IsInSimulateMode() {
    return false;
}

bool USandfallBlueprintHelpers::IsInPlayMode() {
    return false;
}

bool USandfallBlueprintHelpers::IsEventDispatcherConnected(UObject* Object, FName EventDispatcherName) {
    return false;
}

bool USandfallBlueprintHelpers::IsCurrentConsoleTypeLockheart() {
    return false;
}

bool USandfallBlueprintHelpers::isCollisionProfileValid(FName ProfileName) {
    return false;
}

bool USandfallBlueprintHelpers::IsActorSpatiallyLoaded(const AActor* Actor) {
    return false;
}

bool USandfallBlueprintHelpers::HasActorBegunPlay(const AActor* Actor) {
    return false;
}

void USandfallBlueprintHelpers::GetVendorBuildInfo(UObject* WorldContextObject, FString& OwnerInfo, FString& BuildInfo) {
}

FString USandfallBlueprintHelpers::GetUpscalerInfo() {
    return TEXT("");
}

TArray<FString> USandfallBlueprintHelpers::GetStackTrace() {
    return TArray<FString>();
}

TArray<FName> USandfallBlueprintHelpers::GetSamplingRegionNames(USkeletalMesh* SkeletalMeshAsset) {
    return TArray<FName>();
}

FGameplayTag USandfallBlueprintHelpers::GetPlatformNameAsTag() {
    return FGameplayTag::EmptyTag;
}

float USandfallBlueprintHelpers::GetMaxDistanceAttenuation(USoundBase* Sound) {
    return 0.0f;
}

float USandfallBlueprintHelpers::GetLastRenderTimeOnScreen(const UPrimitiveComponent* Primitive) {
    return 0.0f;
}

FTransform USandfallBlueprintHelpers::GetEditorViewportTransform() {
    return FTransform{};
}

FString USandfallBlueprintHelpers::GetDebugInfo() {
    return TEXT("");
}

void USandfallBlueprintHelpers::GetDataTableRowFromName(UDataTable* Table, FName RowName, FTableRowBase& OutRow) {
}

UActorComponent* USandfallBlueprintHelpers::GetComponentFromReference(const FComponentReference& ComponentReference, AActor* OwningActor) {
    return NULL;
}

UObject* USandfallBlueprintHelpers::GetClassDefaultObject(UClass* Object) {
    return NULL;
}

void USandfallBlueprintHelpers::GetBuildInfo(UObject* WorldContextObject, FString& Changelist, FString& CurrentPersistentLevel) {
}

void USandfallBlueprintHelpers::GetAllLightComponents(UWorld* World, TArray<ULightComponent*>& LightComponents) {
}

void USandfallBlueprintHelpers::GetAllComponentsByClass(UWorld* World, TSubclassOf<UActorComponent> Class, TArray<UActorComponent*>& Components) {
}

FString USandfallBlueprintHelpers::FormatTimespanWithPattern(FTimespan Timespan, const FString& FormatString) {
    return TEXT("");
}

FString USandfallBlueprintHelpers::FormatTimespan(FTimespan Timespan) {
    return TEXT("");
}

FString USandfallBlueprintHelpers::FormatDateTimeWithPattern(FDateTime DateTime, const FString& FormatString) {
    return TEXT("");
}

FString USandfallBlueprintHelpers::FormatDateTime(FDateTime DateTime) {
    return TEXT("");
}

FString USandfallBlueprintHelpers::Format(const FString& InPattern, TArray<FFormatArgumentData> InArgs) {
    return TEXT("");
}

void USandfallBlueprintHelpers::FlushInputs(APlayerController* PlayerController) {
}

AActor* USandfallBlueprintHelpers::FinishSpawningActor(AActor* Actor, const FTransform& SpawnTransform, ESpawnActorScaleMethod TransformScaleMethod) {
    return NULL;
}

void USandfallBlueprintHelpers::ExecuteDelegate(FOnInputPressed Delegate) {
}

FString USandfallBlueprintHelpers::EscapeJson(const FString& Input) {
    return TEXT("");
}

bool USandfallBlueprintHelpers::EqualsObjects(const UObject* A, const UObject* B) {
    return false;
}

void USandfallBlueprintHelpers::EditorAlert(const FText& _text) {
}

void USandfallBlueprintHelpers::Editor_TakeScreenshot(const FString& _filename, bool _showUI) {
}

void USandfallBlueprintHelpers::Editor_PushJSONToMongoDB(const FString& Json) {
}

bool USandfallBlueprintHelpers::Editor_MoveScreenshots(const FString& _sourceFile, const FString& _destination) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_GetStatValue(const FName _StatGroup, const FName _StatName, bool _isMemory, FString& _OutValue) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_GetShaderCompilationState(int32& jobCount, int32& workerCount) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_FileSaveString(const FString& Content, const FString& Filename) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_FileLoadStringReal(const FString& Filename, FString& Content) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_FileLoadString(const FString& Filename, FString& Content) {
    return false;
}

bool USandfallBlueprintHelpers::Editor_FileDelete(const FString& Filename) {
    return false;
}

void USandfallBlueprintHelpers::DrawDebugCircleArc(const UObject* WorldContextObject, FVector Center, float Radius, FVector Direction, float AngleWidth, int32 Segments, FLinearColor Color, float Lifetime, float Thickness) {
}

void USandfallBlueprintHelpers::DebugMe(UObject* _objectToDebug) {
}

UClass* USandfallBlueprintHelpers::DebugFindClassByName(const FString& _className) {
    return NULL;
}

void USandfallBlueprintHelpers::DebugCppBreakpoint() {
}

UObject* USandfallBlueprintHelpers::DebugConstructFromClass(UClass* _class, UObject* _owner) {
    return NULL;
}

void USandfallBlueprintHelpers::CopyAllProperties(UObject* FromObject, UObject* ToObject, bool bIncludeComponents) {
}

void USandfallBlueprintHelpers::ConvertSoftRefToWorldSoftRef(const TSoftObjectPtr<UObject>& _InObject, TSoftObjectPtr<UWorld>& _OutWorldSoftRef) {
}

int32 USandfallBlueprintHelpers::CompareStrings(const FString& A, const FString& B) {
    return 0;
}

bool USandfallBlueprintHelpers::CheckEntitlement(UWorld* _worldContext) {
    return false;
}

void USandfallBlueprintHelpers::CancelLatentActions(UObject* WorldContextObject, UObject* Object) {
}

void USandfallBlueprintHelpers::CallFunctionByName(UObject* _object, const FString& _functionName, bool& _IsFailed) {
}

void USandfallBlueprintHelpers::BlockTillLevelStreamingCompleted(UObject* WorldContextObject) {
}

AActor* USandfallBlueprintHelpers::BeginDeferredActorSpawnFromClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, AActor* Owner, ESpawnActorScaleMethod TransformScaleMethod) {
    return NULL;
}

void USandfallBlueprintHelpers::AssertMessage(const FString& _message, const bool _breakpoint) {
}

void USandfallBlueprintHelpers::Assert(const bool _check, const FText _message, const bool _breakpoint) {
}

void USandfallBlueprintHelpers::Array_Remap(const TArray<int32>& TargetArray, const TMap<int32, int32>& RemapTable, TArray<int32>& ResultArray) {
}


