// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Templates/SubclassOf.h"
#include "Widgets/SWidget.h"
#include "ISequencerSection.h"
#include "MovieSceneTrack.h"
#include "ISequencer.h"
#include "ISequencerTrackEditor.h"
#include "MovieSceneTrackEditor.h"
#include "IContentBrowserSingleton.h"

struct FAnimatedPropertyKey;
struct FAssetData;
struct FBuildEditWidgetParams;
class FMenuBuilder;
class FSequencerSectionPainter;
class UDataTable;
class UMovieSceneTrack;
class UFrameInputsTrack;

/**
 * Tools for audio tracks
 */
class FFrameInputsTrackEditor : public FMovieSceneTrackEditor
{
public:
	FFrameInputsTrackEditor(TSharedRef<ISequencer>InSequencer);
	static TSharedRef<ISequencerTrackEditor> CreateTrackEditor(TSharedRef<ISequencer> InSequencer);

	static TArray<FAnimatedPropertyKey, TInlineAllocator<1>> GetAnimatedPropertyTypes();

	//Add our track to the add track menu
	virtual void BuildAddTrackMenu(FMenuBuilder& MenuBuilder) override;

	//Draw the track entry itself (as this is an SWidget, it can be customized and additional button or labels can be added
	virtual TSharedPtr<SWidget> BuildOutlinerEditWidget(const FGuid& ObjectBinding, UMovieSceneTrack* Track, const FBuildEditWidgetParams& Params);

	virtual TSharedRef<ISequencerSection> MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding) override;
	virtual bool SupportsType(TSubclassOf<UMovieSceneTrack> Type) const override;
	virtual bool SupportsSequence(UMovieSceneSequence* InSequence) const override;

	static FReply AddNewTrack(UMovieSceneTrack* track, UMovieScene* focusedMovieScene);

private:
	TSharedRef<SWidget> BuildFrameInputsSubMenu(FOnAssetSelected OnAssetSelected, FOnAssetEnterPressed OnAssetEnterPressed);

	void OnFrameInputsAssetSelected(const FAssetData& AssetData, UMovieSceneTrack* Track);
	void OnFrameInputsAssetEnterPressed(const TArray<FAssetData>& AssetData, UMovieSceneTrack* Track);
	void OnAttachedFrameInputsAssetSelected(const FAssetData& AssetData, TArray<FGuid> ObjectBindings);
	void OnAttachedAudioEnterPressed(const TArray<FAssetData>& AssetData, TArray<FGuid> ObjectBindings);
};
