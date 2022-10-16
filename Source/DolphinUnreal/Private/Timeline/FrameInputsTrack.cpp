#include "Timeline/FrameInputsTrack.h"

#include "Timeline/FrameInputsSection.h"
#include "Timeline/FrameInputsTemplate.h"

#include "Compilation/MovieSceneCompilerRules.h"
#include "Evaluation/MovieSceneEvaluationTrack.h"
#include "Compilation/IMovieSceneTemplateGenerator.h"
#include "MovieScene.h"

#define LOCTEXT_NAMESPACE "FrameInputsTrack"

/* UFrameInputsTrack structors
 *****************************************************************************/

UFrameInputsTrack::UFrameInputsTrack(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	TrackTint = FColor(124, 15, 124, 65);
#endif

	SupportedBlendTypes.Add(EMovieSceneBlendType::Absolute);

	EvalOptions.bCanEvaluateNearestSection = true;
	EvalOptions.bEvaluateInPreroll = true;
}


/* UFrameInputsTrack interface
 *****************************************************************************/

/*
UMovieSceneSection* UFrameInputsTrack::AddNewAnimation(FFrameNumber KeyTime, UGeometryCacheComponent* GeomCacheComp)
{
	UFrameInputsSection* NewSection = Cast<UFrameInputsSection>(CreateNewSection());
	{
		FFrameTime AnimationLength = GeomCacheComp->GetDuration()* GetTypedOuter<UMovieScene>()->GetTickResolution();
		int32 IFrameNumber = AnimationLength.FrameNumber.Value + (int)(AnimationLength.GetSubFrame() + 0.5f) + 1;
		NewSection->InitialPlacementOnRow(AnimationSections, KeyTime, IFrameNumber, INDEX_NONE);
		
		NewSection->Params.DataTableAsset = (GeomCacheComp->GetGeometryCache());
	}

	AddSection(*NewSection);

	return NewSection;
}
*/

TArray<UMovieSceneSection*> UFrameInputsTrack::GetAnimSectionsAtTime(FFrameNumber Time)
{
	TArray<UMovieSceneSection*> Sections;
	for (auto Section : AnimationSections)
	{
		if (Section->IsTimeWithinSection(Time))
		{
			Sections.Add(Section);
		}
	}

	return Sections;
}

FMovieSceneEvalTemplatePtr UFrameInputsTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
	return FFrameInputsSectionTemplate(*CastChecked<UFrameInputsSection>(&InSection));
}

/* UMovieSceneTrack interface
 *****************************************************************************/


const TArray<UMovieSceneSection*>& UFrameInputsTrack::GetAllSections() const
{
	return AnimationSections;
}


bool UFrameInputsTrack::SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const
{
	return SectionClass == UFrameInputsSection::StaticClass();
}

UMovieSceneSection* UFrameInputsTrack::CreateNewSection()
{
	return NewObject<UFrameInputsSection>(this, NAME_None, RF_Transactional);
}


void UFrameInputsTrack::RemoveAllAnimationData()
{
	AnimationSections.Empty();
}


bool UFrameInputsTrack::HasSection(const UMovieSceneSection& Section) const
{
	return AnimationSections.Contains(&Section);
}


void UFrameInputsTrack::AddSection(UMovieSceneSection& Section)
{
	AnimationSections.Add(&Section);
}


void UFrameInputsTrack::RemoveSection(UMovieSceneSection& Section)
{
	AnimationSections.Remove(&Section);
}

void UFrameInputsTrack::RemoveSectionAt(int32 SectionIndex)
{
	AnimationSections.RemoveAt(SectionIndex);
}


bool UFrameInputsTrack::IsEmpty() const
{
	return AnimationSections.Num() == 0;
}

#if WITH_EDITORONLY_DATA

FText UFrameInputsTrack::GetDefaultDisplayName() const
{
	return LOCTEXT("TrackName", "Frame Inputs");
}

#endif

#undef LOCTEXT_NAMESPACE
