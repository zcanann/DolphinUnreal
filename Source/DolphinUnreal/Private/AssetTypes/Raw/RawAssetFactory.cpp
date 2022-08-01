#include "AssetTypes/Raw/RawAssetFactory.h"

#include "AssetTypes/Raw/RawAsset.h"
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "RawAssetFactory"

URawAssetFactory::URawAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("raw;")) + LOCTEXT("FormatTxt", "Gamecube/Wii memory card file").ToString());
	SupportedClass = URawAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* URawAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	URawAsset* RawAsset = nullptr;

	RawAsset = NewObject<URawAsset>(InParent, InClass, InName, Flags);

	RawAsset->Path = Filename;

	bOutOperationCanceled = false;

	return RawAsset;
}

#undef LOCTEXT_NAMESPACE
