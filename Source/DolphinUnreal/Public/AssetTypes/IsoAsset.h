#pragma once

#include "CoreMinimal.h"

#include "IsoAsset.generated.h"

UCLASS(BlueprintType, hidecategories = (Object))
class UIsoAsset : public UObject
{
	GENERATED_BODY()

public:
	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	//~ End UObject Interface

	FString Path;
};