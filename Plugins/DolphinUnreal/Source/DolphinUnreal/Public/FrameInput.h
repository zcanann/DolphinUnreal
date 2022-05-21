#pragma once

#include "CoreMinimal.h"

#include "Serialization/Archive.h"

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
	static FText GetToolTip(EFrameInputButton FrameInputButton, int32 InFrame);
	void ToggleButton(EFrameInputButton InFrameInputButton, bool bIsChecked);
	bool IsButtonToggled(EFrameInputButton InFrameInputButton);

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
	uint8 MainStickX = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 MainStickY = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 CStickX = 0;

	UPROPERTY(BlueprintReadWrite)
	uint8 CStickY = 0;
};

FORCEINLINE FArchive& operator <<(FArchive& Ar, FFrameInput& InFrameInput)
{
	Ar << InFrameInput.bButtonA;
	Ar << InFrameInput.bButtonB;
	Ar << InFrameInput.bButtonX;
	Ar << InFrameInput.bButtonY;
	Ar << InFrameInput.bButtonZ;
	Ar << InFrameInput.bButtonDUp;
	Ar << InFrameInput.bButtonDDown;
	Ar << InFrameInput.bButtonDLeft;
	Ar << InFrameInput.bButtonDRight;
	Ar << InFrameInput.bButtonStart;
	Ar << InFrameInput.bButtonL;
	Ar << InFrameInput.bButtonR;
	Ar << InFrameInput.TriggerLeft;
	Ar << InFrameInput.TriggerRight;
	Ar << InFrameInput.MainStickX;
	Ar << InFrameInput.MainStickY;
	Ar << InFrameInput.CStickX;
	Ar << InFrameInput.CStickY;

	return Ar;
}
