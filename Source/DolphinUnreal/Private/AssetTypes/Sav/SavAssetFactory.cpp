#include "AssetTypes/Sav/SavAssetFactory.h"

#include "AssetTypes/Sav/SavAsset.h"
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "SavAssetFactory"

USavAssetFactory::USavAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("sav;")) + LOCTEXT("FormatTxt", "Gamecube/Wii Save file").ToString());
	SupportedClass = USavAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* USavAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	USavAsset* SavAsset = nullptr;

	SavAsset = NewObject<USavAsset>(InParent, InClass, InName, Flags);

	SavAsset->Path = Filename;

	bOutOperationCanceled = false;

	return SavAsset;
}

#undef LOCTEXT_NAMESPACE
