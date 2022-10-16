#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MovieSceneNameableTrack.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "FrameInputsTrack.generated.h"

class UDataTable;

UCLASS()
class UFrameInputsTrack : public UMovieSceneTrack
{
	GENERATED_BODY()

public:
	virtual UMovieSceneSection* AddNewFrameInputsOnRow(UDataTable* Sound, FFrameNumber Time, int32 RowIndex);
	virtual UMovieSceneSection* AddNewFrameInputs(UDataTable* Sound, FFrameNumber Time) { return AddNewFrameInputsOnRow(Sound, Time, INDEX_NONE); }

	virtual FText GetDisplayName() const override;
	virtual FName GetTrackName() const override;
	virtual bool IsEmpty() const override;
	virtual class UMovieSceneSection* CreateNewSection() override;
	virtual void AddSection(class UMovieSceneSection& Section) override;
	virtual void RemoveSection(UMovieSceneSection& Section) override;
	virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;

	static const FName GetDataTrackName();

private:
	UPROPERTY()
	TArray<UMovieSceneSection*> Sections;
};
