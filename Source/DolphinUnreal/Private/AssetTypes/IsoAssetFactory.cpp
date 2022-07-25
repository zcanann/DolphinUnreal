#include "AssetTypes/IsoAssetFactory.h"

#include "AssetTypes/IsoAsset.h"
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "IsoAssetFactory"

UIsoAssetFactory::UIsoAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("iso;gcz;rvz;wbfs;wia;")) + LOCTEXT("FormatTxt", "Gamecube/Wii ISO file").ToString());
	SupportedClass = UIsoAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UIsoAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UIsoAsset* IsoAsset = nullptr;

	IsoAsset = NewObject<UIsoAsset>(InParent, InClass, InName, Flags);

	IsoAsset->Path = Filename;

	bOutOperationCanceled = false;

	return IsoAsset;
}

#undef LOCTEXT_NAMESPACE
