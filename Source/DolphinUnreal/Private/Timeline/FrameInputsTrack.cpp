#include "Timeline/FrameInputsTrack.h"

#include "Timeline/FrameInputsSection.h"
#include "Timeline/FrameInputsTemplate.h"

#define LOCTEXT_NAMESPACE "FrameInputsTrack"

UMovieSceneSection* UFrameInputsTrack::AddNewFrameInputsOnRow(UDataTable* FrameInputs, FFrameNumber Time, int32 RowIndex)
{
	check(FrameInputs);

	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();

	float Duration = float(FrameInputs->GetRowMap().Num()); //  * FrameRate

	// add the section
	UFrameInputsSection* NewSection = NewObject<UFrameInputsSection>(this, NAME_None, RF_Transactional);
	NewSection->InitialPlacementOnRow(Sections, Time, Duration, RowIndex); // TODO: Initial time
	NewSection->DataTableAsset = FrameInputs;

	Sections.Add(NewSection);

	return NewSection;
}

FText UFrameInputsTrack::GetDisplayName() const
{
	static FText TrackName = FText::FromString(FString(TEXT("Frame Inputs")));
	return TrackName;
}

FName UFrameInputsTrack::GetTrackName() const
{
	return UFrameInputsTrack::GetDataTrackName();
}

const FName UFrameInputsTrack::GetDataTrackName()
{
	static FName TheName = FName(*FString(TEXT("FrameInputsTrack")));
	return TheName;
}

bool UFrameInputsTrack::IsEmpty() const
{
	return Sections.Num() == 0;
}

UMovieSceneSection* UFrameInputsTrack::CreateNewSection()
{
	UMovieSceneSection* Section = NewObject<UFrameInputsSection>(this, NAME_None, RF_Transactional);
	Sections.Add(Section);
	return Section;
}

void UFrameInputsTrack::AddSection(UMovieSceneSection& Section)
{
	Sections.Add(&Section);
}

void UFrameInputsTrack::RemoveSection(UMovieSceneSection& Section)
{
	Sections.Remove(&Section);
}

const TArray<UMovieSceneSection*>& UFrameInputsTrack::GetAllSections() const
{
	return Sections;
}

#undef LOCTEXT_NAMESPACE
