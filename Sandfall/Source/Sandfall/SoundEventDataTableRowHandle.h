#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "SoundEventDataTableRowHandle.generated.h"

USTRUCT(BlueprintType)
struct SANDFALL_API FSoundEventDataTableRowHandle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle m_data;
    
    FSoundEventDataTableRowHandle();
};

