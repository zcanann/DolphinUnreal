#pragma once

#include "CoreMinimal.h"

#include "SavAsset.generated.h"

UCLASS(BlueprintType, hidecategories = (Object))
class USavAsset : public UObject
{
	GENERATED_BODY()

public:
	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	//~ End UObject Interface

	FString Path;
};