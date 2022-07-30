#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Serialization/Archive.h"

#include "dolphin-ipc/IpcStructs.h"

#include "FrameInput.generated.h"

UENUM(BlueprintType)
enum class EFrameInputType : uint8
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
ENUM_RANGE_BY_FIRST_AND_LAST(EFrameInputType, EFrameInputType::A, EFrameInputType::CStickY);

USTRUCT(BlueprintType)
struct FFrameInput : public FTableRowBase
{
	GENERATED_BODY()

public:
	static FFrameInput FromDolphinControllerState(DolphinControllerState InDolphinControllerState);
	static DolphinControllerState ToDolphinControllerState(const FFrameInput& InFrameInput);
	static FString GetSimpleName(EFrameInputType FrameInputType);
	static FText GetToolTip(EFrameInputType FrameInputType, int32 InFrame);
	static bool IsFrameInputTypeButton(EFrameInputType InFrameInputType);
	static bool IsFrameInputTypeAnalog(EFrameInputType InFrameInputType);
	void ToggleButton(EFrameInputType InFrameInputType, bool bIsChecked);
	bool IsButtonToggled(EFrameInputType InFrameInputType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonA = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonB = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonX = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonY = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonDUp = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonDDown = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonDLeft = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonDRight = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonZ = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonStart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonL = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonR = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDiscChange = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bConsoleReset = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsControllerConnected = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOriginReset = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 TriggerLeft = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 TriggerRight = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 MainStickX = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 MainStickY = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 CStickX = 128;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 CStickY = 128;
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
