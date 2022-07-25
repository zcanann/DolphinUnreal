#include "AssetTypes/IsoAsset.h"

#define LOCTEXT_NAMESPACE "IsoAsset"

void UIsoAsset::Serialize(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		Path.Empty();
	}

	// Save the iso path
	Ar << Path;

	Super::Serialize(Ar);
}

#undef LOCTEXT_NAMESPACE
