#include "AssetTypes/Raw/RawAsset.h"

#define LOCTEXT_NAMESPACE "RawAsset"

void URawAsset::Serialize(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		Path.Empty();
	}

	// Rawe the sav path
	Ar << Path;

	Super::Serialize(Ar);
}

#undef LOCTEXT_NAMESPACE
