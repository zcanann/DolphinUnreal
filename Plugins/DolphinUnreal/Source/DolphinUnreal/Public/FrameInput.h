#pragma once

#include "CoreMinimal.h"

#include "FrameInput.generated.h"

UENUM(BlueprintType)
enum class EFrameInputButton : uint8
{
	A,
	B,
	X,
	Y,
	Z,
	DLeft,
	DRight,
	DUp,
	DDown,
	Start,
	L,
	R,
	LTrigger,
	RTrigger,
	MainAnalogX,
	MainAnalogY,
	CStickX,
	CStickY,
};
ENUM_RANGE_BY_FIRST_AND_LAST(EFrameInputButton, EFrameInputButton::A, EFrameInputButton::CStickY);

USTRUCT(BlueprintType)
struct FFrameInput
{
	GENERATED_BODY()

public:
	static FString GetSimpleName(EFrameInputButton FrameInputButton);

	UPROPERTY(BlueprintReadWrite)
	bool bButtonA = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonB = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonX = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonY = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonDUp = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonDDown = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonDLeft = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonDRight = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonZ = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonStart = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonL = false;

	UPROPERTY(BlueprintReadWrite)
	bool bButtonR = false;

	UPROPERTY(BlueprintReadWrite)
	uint8 TriggerLeft = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 TriggerRight = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 MainStickLeft = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 CStickLeft = 0;
};
