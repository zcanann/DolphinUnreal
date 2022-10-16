#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/ObjectMacros.h"
#include "MovieSceneSection.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "UObject/SoftObjectPath.h"

#include "Misc/Guid.h"
#include "ISequencer.h"
#include "MovieSceneTrack.h"
#include "ISequencerSection.h"
#include "ISequencerTrackEditor.h"
#include "MovieSceneTrackEditor.h"

#include "FrameInputsSection.generated.h"

UCLASS()
class UFrameInputsSection : public UMovieSceneSection
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "DataTable", DisplayName = "Data Table")
	TObjectPtr<UDataTable> DataTableAsset;
};
