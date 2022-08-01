#include "DolphinUnrealStyle.h"

#include "Interfaces/IPluginManager.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateStyleMacros.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"

FDolphinUnrealStyle::FDolphinUnrealStyle() : FSlateStyleSet("DolphinUnrealStyle")
{
	static const FVector2D Icon16x16(16.0f, 16.0f);
	static const FVector2D Icon32x32(32.0f, 32.0f);
	static const FVector2D Icon64x64(64.0f, 64.0f);
	static const FVector2D Icon128x128(128.0f, 128.0f);

	static FString PluginContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());
	SetContentRoot(PluginContentDirectory);

	// Asset styles
	{
		Set("ClassIcon.GciAsset", new IMAGE_BRUSH("Icons/AssetTypes/GCI_16", Icon16x16));
		Set("ClassThumbnail.GciAsset", new IMAGE_BRUSH("Icons/AssetTypes/GCI_128", Icon128x128));
		Set("ClassIcon.RawAsset", new IMAGE_BRUSH("Icons/AssetTypes/MemoryCard_16", Icon16x16));
		Set("ClassThumbnail.RawAsset", new IMAGE_BRUSH("Icons/AssetTypes/MemoryCard_128", Icon128x128));
		Set("ClassIcon.IsoAsset", new IMAGE_BRUSH("Icons/AssetTypes/Iso_16", Icon16x16));
		Set("ClassThumbnail.IsoAsset", new IMAGE_BRUSH("Icons/AssetTypes/Iso_128", Icon128x128));
		Set("ClassIcon.SavAsset", new IMAGE_BRUSH("Icons/AssetTypes/Sav_16", Icon16x16));
		Set("ClassThumbnail.SavAsset", new IMAGE_BRUSH("Icons/AssetTypes/Sav_128", Icon128x128));
	}
}

void FDolphinUnrealStyle::Register()
{
	FSlateStyleRegistry::RegisterSlateStyle(Get());
}


void FDolphinUnrealStyle::Unregister()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(Get());
}


FDolphinUnrealStyle& FDolphinUnrealStyle::Get()
{
	static FDolphinUnrealStyle Instance;
	return Instance;
}
