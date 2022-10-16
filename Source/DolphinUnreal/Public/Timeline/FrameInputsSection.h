// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/ObjectMacros.h"
#include "MovieSceneSection.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "UObject/SoftObjectPath.h"

#include "FrameInputsSection.generated.h"

USTRUCT()
 struct FFrameInputsParams
{
	GENERATED_BODY()

	FFrameInputsParams();

	/** Gets the animation sequence length, not modified by play rate */
	 float GetSequenceLength() const;

	/** The animation this section plays */
	UPROPERTY(EditAnywhere, Category = "DataTable", DisplayName = "Data Table")
	TObjectPtr<UDataTable> DataTableAsset;

	/** The offset for the first loop of the animation clip */
	UPROPERTY(EditAnywhere, Category = "DataTable")
	FFrameNumber FirstLoopStartFrameOffset;

	/** The offset into the beginning of the animation clip */
	UPROPERTY(EditAnywhere, Category = "DataTable")
	FFrameNumber StartFrameOffset;

	/** The offset into the end of the animation clip */
	UPROPERTY(EditAnywhere, Category = "DataTable")
	FFrameNumber EndFrameOffset;

	/** The playback rate of the animation clip */
	UPROPERTY(EditAnywhere, Category = "DataTable")
	float PlayRate;

	/** Reverse the playback of the animation clip */
	UPROPERTY(EditAnywhere, Category = "Animation")
	uint32 bReverse : 1;

	UPROPERTY()
	float StartOffset_DEPRECATED;

	UPROPERTY()
	float EndOffset_DEPRECATED;

	UPROPERTY()
	FSoftObjectPath GeometryCache_DEPRECATED;
};

UCLASS()
class UFrameInputsSection : public UMovieSceneSection
{
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Animation", meta = (ShowOnlyInnerProperties))
	FFrameInputsParams Params;

	/** Get Frame Time as Animation Time*/
	virtual float MapTimeToAnimation(float ComponentDuration, FFrameTime InPosition, FFrameRate InFrameRate) const;

protected:
	//~ UMovieSceneSection interface
	virtual TOptional<TRange<FFrameNumber> > GetAutoSizeRange() const override;
	virtual void TrimSection(FQualifiedFrameTime TrimTime, bool bTrimLeft, bool bDeleteKeys) override;
	virtual UMovieSceneSection* SplitSection(FQualifiedFrameTime SplitTime, bool bDeleteKeys) override;
	virtual void GetSnapTimes(TArray<FFrameNumber>& OutSnapTimes, bool bGetSectionBorders) const override;
	virtual TOptional<FFrameTime> GetOffsetTime() const override;
	virtual void MigrateFrameTimes(FFrameRate SourceRate, FFrameRate DestinationRate) override;

	/** ~UObject interface */
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

private:

	//~ UObject interface

#if WITH_EDITOR

	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
public:
	float PreviousPlayRate;

#endif

};
