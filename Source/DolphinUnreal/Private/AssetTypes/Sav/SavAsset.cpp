#include "AssetTypes/Sav/SavAsset.h"

#define LOCTEXT_NAMESPACE "SavAsset"

void USavAsset::Serialize(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		Path.Empty();
	}

	// Save the sav path
	Ar << Path;

	Super::Serialize(Ar);
}

#undef LOCTEXT_NAMESPACE
