#include "AssetTypes/Gci/GciAssetFactory.h"

#include "AssetTypes/Gci/GciAsset.h"
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "GciAssetFactory"

UGciAssetFactory::UGciAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("gci;")) + LOCTEXT("FormatTxt", "Gamecube/Wii Gcie file").ToString());
	SupportedClass = UGciAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UGciAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UGciAsset* GciAsset = nullptr;

	GciAsset = NewObject<UGciAsset>(InParent, InClass, InName, Flags);

	GciAsset->Path = Filename;

	bOutOperationCanceled = false;

	return GciAsset;
}

#undef LOCTEXT_NAMESPACE
