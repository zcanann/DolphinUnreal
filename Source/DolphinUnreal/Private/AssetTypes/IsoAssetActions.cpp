#include "AssetTypes/IsoAssetActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Styling/SlateStyle.h"

#include "AssetTypes/IsoAsset.h"
#include "AssetTypes/IsoAssetEditorToolkit.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FIsoAssetActions::FIsoAssetActions(const TSharedRef<ISlateStyle>& InStyle)
	: Style(InStyle)
{ }

bool FIsoAssetActions::CanFilter()
{
	return true;
}


void FIsoAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	auto IsoAssets = GetTypedWeakObjectPtrs<UIsoAsset>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("IsoAsset_ReverseText", "Reverse Text"),
		LOCTEXT("IsoAsset_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=] {
				for (auto& IsoAsset : IsoAssets)
				{
					if (IsoAsset.IsValid())
					{
						IsoAsset->PostEditChange();
						IsoAsset->MarkPackageDirty();
					}
				}
				}),
			FCanExecuteAction::CreateLambda([=] {
					for (auto& IsoAsset : IsoAssets)
					{
						if (IsoAsset.IsValid())
						{
							return true;
						}
					}
					return false;
				})
		)
	);
}


uint32 FIsoAssetActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}


FText FIsoAssetActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_IsoAsset", "Iso Asset");
}


UClass* FIsoAssetActions::GetSupportedClass() const
{
	return UIsoAsset::StaticClass();
}


FColor FIsoAssetActions::GetTypeColor() const
{
	return FColor::White;
}


bool FIsoAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}


void FIsoAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric
		: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto IsoAsset = Cast<UIsoAsset>(*ObjIt);

		if (IsoAsset != nullptr)
		{
			TSharedRef<FIsoAssetEditorToolkit> EditorToolkit = MakeShareable(new FIsoAssetEditorToolkit(Style));
			EditorToolkit->Initialize(IsoAsset, Mode, EditWithinLevelEditor);
		}
	}
}

#undef LOCTEXT_NAMESPACE
