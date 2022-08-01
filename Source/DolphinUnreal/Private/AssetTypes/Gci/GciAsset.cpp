#include "AssetTypes/Gci/GciAsset.h"

#define LOCTEXT_NAMESPACE "GciAsset"

void UGciAsset::Serialize(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		Path.Empty();
	}

	// Gcie the sav path
	Ar << Path;

	Super::Serialize(Ar);
}

#undef LOCTEXT_NAMESPACE
