#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "FrameInputsSection.h"
#include "FrameInputsTemplate.generated.h"

USTRUCT()
struct FFrameInputsSectionTemplateParameters : public FFrameInputsParams
{
	GENERATED_BODY()

		FFrameInputsSectionTemplateParameters() {}
	FFrameInputsSectionTemplateParameters(const FFrameInputsParams& BaseParams, FFrameNumber InSectionStartTime, FFrameNumber InSectionEndTime)
		: FFrameInputsParams(BaseParams)
		, SectionStartTime(InSectionStartTime)
		, SectionEndTime(InSectionEndTime)
	{}

	float MapTimeToAnimation(float ComponentDuration, FFrameTime InPosition, FFrameRate InFrameRate) const;

	UPROPERTY()
	FFrameNumber SectionStartTime;

	UPROPERTY()
	FFrameNumber SectionEndTime;
};

USTRUCT()
struct FFrameInputsSectionTemplate : public FMovieSceneEvalTemplate
{
	GENERATED_BODY()

	FFrameInputsSectionTemplate() {}
	FFrameInputsSectionTemplate(const UFrameInputsSection& Section);

	virtual UScriptStruct& GetScriptStructImpl() const override { return *StaticStruct(); }
	virtual void Evaluate(const FMovieSceneEvaluationOperand& Operand, const FMovieSceneContext& Context, const FPersistentEvaluationData& PersistentData, FMovieSceneExecutionTokens& ExecutionTokens) const override;

	UPROPERTY()
	FFrameInputsSectionTemplateParameters Params;
};
