#pragma once

#include "CoreMinimal.h"

#include "RawAsset.generated.h"

UCLASS(BlueprintType, hidecategories = (Object))
class URawAsset : public UObject
{
	GENERATED_BODY()

public:
	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	//~ End UObject Interface

	FString Path;
};