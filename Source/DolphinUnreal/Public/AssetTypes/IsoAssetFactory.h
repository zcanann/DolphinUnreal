#pragma once

#include "Factories/Factory.h"
#include "UObject/ObjectMacros.h"

#include "IsoAssetFactory.generated.h"

UCLASS(hidecategories = Object)
class UIsoAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
