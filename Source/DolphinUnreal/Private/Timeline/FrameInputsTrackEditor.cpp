#include "Timeline/FrameInputsTrackEditor.h"

#include "Timeline/FrameInputsSection.h"
#include "Timeline/FrameInputsTrack.h"

#include "AssetRegistryModule.h"
#include "ContentBrowserModule.h"
#include "Engine/DataTable.h"
#include "ISequencerSection.h"
#include "SequencerSectionPainter.h"
#include "SequencerUtilities.h"

#define LOCTEXT_NAMESPACE "FFrameInputsTrackEditor"

class FFrameInputsSection : public ISequencerSection
{
public:
	FFrameInputsSection(UMovieSceneSection& InSection, TWeakPtr<ISequencer> InSequencer)
	{
		FrameInputsSection = Cast<UFrameInputsSection>(&InSection);
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& InPainter) const override
	{
		return InPainter.PaintSectionBackground();
	}

	virtual UMovieSceneSection* GetSectionObject() override
	{
		return FrameInputsSection;
	}

	virtual FText GetSectionTitle() const override
	{
		if (FrameInputsSection != nullptr && FrameInputsSection->DataTableAsset != nullptr)
		{
			return FText::FromString(FrameInputsSection->DataTableAsset->GetName());
		}

		return FText::FromString(FString(TEXT("Frame Inputs Section")));
	}

	virtual float GetSectionHeight() const override
	{
		return 40.0f;
	}

	class UFrameInputsSection* FrameInputsSection;
};

FFrameInputsTrackEditor::FFrameInputsTrackEditor(TSharedRef<ISequencer>InSequencer) : FMovieSceneTrackEditor(InSequencer) {}

TSharedRef<ISequencerTrackEditor> FFrameInputsTrackEditor::CreateTrackEditor(TSharedRef<ISequencer> InSequencer)
{
	return MakeShareable(new FFrameInputsTrackEditor(InSequencer));
}

TArray<FAnimatedPropertyKey, TInlineAllocator<1>> FFrameInputsTrackEditor::GetAnimatedPropertyTypes()
{
	return TArray<FAnimatedPropertyKey, TInlineAllocator<1>>({ FAnimatedPropertyKey::FromObjectType(UDataTable::StaticClass()) });
}

void FFrameInputsTrackEditor::BuildAddTrackMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddMetaDataTrack", "Add Frame Inputs Track"),
		LOCTEXT("AddMetaDataTrack", "Adds a new track to manage when frame input recordings are played"),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "ClassIcon.TextRenderComponent"),
		FUIAction(FExecuteAction::CreateLambda([=]
			{
				UMovieScene* FocusedMovieScene = GetFocusedMovieScene();
				if (IsValid(FocusedMovieScene))
				{
					// Create scoped transaction:
					const FScopedTransaction(LOCTEXT("FPMCStringsTrackEditor_Transaction", "Add Frame Inputs Track"));


					FocusedMovieScene->Modify();
					UFrameInputsTrack* NewTrack = FocusedMovieScene->AddMasterTrack<UFrameInputsTrack>();
					FFrameInputsTrackEditor::AddNewTrack(NewTrack, FocusedMovieScene);


					// Notify SequencerAboutTransactions:
					GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
				}
			})));
}

bool FFrameInputsTrackEditor::SupportsType(TSubclassOf<UMovieSceneTrack> Type) const
{
	return UFrameInputsTrack::StaticClass() == Type;
}

bool FFrameInputsTrackEditor::SupportsSequence(UMovieSceneSequence* InSequence) const
{
	if (!IsValid(InSequence))
	{
		return false;
	}

	static UClass* LevelSequencerClass = FindObject<UClass>(ANY_PACKAGE, TEXT("LevelSequence"), true);
	bool bValidClasses = true;

	bValidClasses &= (LevelSequencerClass != nullptr);
	bValidClasses &= InSequence->GetClass()->IsChildOf(LevelSequencerClass);

	return bValidClasses;
}

FReply FFrameInputsTrackEditor::AddNewTrack(UMovieSceneTrack* Track, UMovieScene* FocusedMovieScene)
{
	if (IsValid(FocusedMovieScene))
	{
		UFrameInputsTrack* FrameInputsTrack = Cast<UFrameInputsTrack>(Track);
		if (IsValid(FrameInputsTrack))
		{
			// Transactions mark on track
			Track->Modify();
			TRange<FFrameNumber> SectionRange = FocusedMovieScene->GetPlaybackRange();
			UMovieSceneSection* NewSection = Track->CreateNewSection();
			UFrameInputsSection* DataSection = Cast<UFrameInputsSection>(NewSection);

			if (IsValid(DataSection))
			{
				NewSection->SetRange(SectionRange);
				for (TObjectIterator<UWorld> Itr; Itr; ++Itr)
				{
					UWorld* World = *Itr;
					if (World->IsEditorWorld() && !World->IsTemplate())
					{
						FString LevelName = World->GetMapName();
						LevelName.RemoveFromStart(World->StreamingLevelsPrefix);
						// DataSection->FrameInputsTrackData.MapName = LevelName;
					}
				}
			}
		}
	}

	return FReply::Handled();
}

TSharedRef<ISequencerSection> FFrameInputsTrackEditor::MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding)
{
	return MakeShareable(new FFrameInputsSection(SectionObject, GetSequencer()));
}

TSharedPtr<SWidget> FFrameInputsTrackEditor::BuildOutlinerEditWidget(const FGuid& ObjectBinding, UMovieSceneTrack* Track, const FBuildEditWidgetParams& Params)
{
	// Create a container edit box
	return SNew(SHorizontalBox)

		// Add the audio combo box
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			FSequencerUtilities::MakeAddButton(LOCTEXT("FrameInputsText", "Frame Inputs"),
			FOnGetContent::CreateSP(this, &FFrameInputsTrackEditor::BuildFrameInputsSubMenu,
			FOnAssetSelected::CreateRaw(this, &FFrameInputsTrackEditor::OnFrameInputsAssetSelected, Track),
			FOnAssetEnterPressed::CreateRaw(this, &FFrameInputsTrackEditor::OnFrameInputsAssetEnterPressed, Track)), Params.NodeIsHovered, GetSequencer())
		];
}

TSharedRef<SWidget> FFrameInputsTrackEditor::BuildFrameInputsSubMenu(FOnAssetSelected OnAssetSelected, FOnAssetEnterPressed OnAssetEnterPressed)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	TArray<FName> ClassNames;
	ClassNames.Add(UDataTable::StaticClass()->GetFName());
	TSet<FName> DerivedClassNames;
	AssetRegistryModule.Get().GetDerivedClassNames(ClassNames, TSet<FName>(), DerivedClassNames);

	FMenuBuilder MenuBuilder(true, nullptr);

	FAssetPickerConfig AssetPickerConfig;
	{
		AssetPickerConfig.OnAssetSelected = OnAssetSelected;
		AssetPickerConfig.OnAssetEnterPressed = OnAssetEnterPressed;
		AssetPickerConfig.bAllowNullSelection = false;
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
		for (auto ClassName : DerivedClassNames)
		{
			AssetPickerConfig.Filter.ClassNames.Add(ClassName);
		}
		AssetPickerConfig.SaveSettingsName = TEXT("SequencerAssetPicker");
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	TSharedPtr<SBox> MenuEntry = SNew(SBox)
		.WidthOverride(300.0f)
		.HeightOverride(300.f)
		[
			ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
		];

	MenuBuilder.AddWidget(MenuEntry.ToSharedRef(), FText::GetEmpty(), true);

	return MenuBuilder.MakeWidget();
}

void FFrameInputsTrackEditor::OnFrameInputsAssetSelected(const FAssetData& AssetData, UMovieSceneTrack* Track)
{
	FSlateApplication::Get().DismissAllMenus();

	UObject* SelectedObject = AssetData.GetAsset();

	if (SelectedObject)
	{
		UDataTable* NewFrameInputs = CastChecked<UDataTable>(AssetData.GetAsset());
		if (NewFrameInputs != nullptr)
		{
			const FScopedTransaction Transaction(NSLOCTEXT("Sequencer", "AddFrameInputs_Transaction", "Add Frame Inputs"));

			auto FrameInputsTrack = Cast<UFrameInputsTrack>(Track);
			FrameInputsTrack->Modify();

			FFrameTime KeyTime = GetSequencer()->GetLocalTime().Time;
			UMovieSceneSection* NewSection = FrameInputsTrack->AddNewFrameInputs(NewFrameInputs, KeyTime.FrameNumber);

			GetSequencer()->EmptySelection();
			GetSequencer()->SelectSection(NewSection);
			GetSequencer()->ThrobSectionSelection();

			GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
		}
	}
}

void FFrameInputsTrackEditor::OnFrameInputsAssetEnterPressed(const TArray<FAssetData>& AssetData, UMovieSceneTrack* Track)
{
	if (AssetData.Num() > 0)
	{
		OnFrameInputsAssetSelected(AssetData[0].GetAsset(), Track);
	}
}

void FFrameInputsTrackEditor::OnAttachedFrameInputsAssetSelected(const FAssetData& AssetData, TArray<FGuid> ObjectBindings)
{
	FSlateApplication::Get().DismissAllMenus();

	UObject* SelectedObject = AssetData.GetAsset();

	if (SelectedObject)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("Sequencer", "AddAudio_Transaction", "Add Audio"));

		for (FGuid ObjectBinding : ObjectBindings)
		{
			HandleAssetAdded(SelectedObject, ObjectBinding);
		}
	}
}

void FFrameInputsTrackEditor::OnAttachedAudioEnterPressed(const TArray<FAssetData>& AssetData, TArray<FGuid> ObjectBindings)
{
	if (AssetData.Num() > 0)
	{
		OnAttachedFrameInputsAssetSelected(AssetData[0].GetAsset(), ObjectBindings);
	}
}

#undef LOCTEXT_NAMESPACE
