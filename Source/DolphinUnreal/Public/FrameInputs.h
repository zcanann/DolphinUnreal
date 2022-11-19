#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Serialization/Archive.h"

#include "dolphin-ipc/IpcStructs.h"

#include "FrameInputs.generated.h"

UENUM(BlueprintType)
enum class EFrameInputType : uint8
{
	Start,
	A,
	B,
	X,
	Y,
	Z,
	DLeft,
	DRight,
	DUp,
	DDown,
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

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EGameCubeEvents : uint8
{
	None = 0 UMETA(Hidden),
	OpenDiscCover = 1,
	DiscChange = 2,
	ConsoleReset = 4,
};
ENUM_CLASS_FLAGS(EGameCubeEvents);

UENUM(BlueprintType)
enum class EControllerChangeEvent : uint8
{
	None,
	ChangeControllerNoDevice,
	ChangeControllerGC,
	ChangeControllerGBA,
	ChangeControllerBongos,
	ChangeControllerSteering,
	ChangeControllerDanceMat,
	ChangeControllerKeyboard,
};
ENUM_RANGE_BY_FIRST_AND_LAST(EControllerChangeEvent, EControllerChangeEvent::None, EControllerChangeEvent::ChangeControllerKeyboard);

USTRUCT(BlueprintType)
struct FFrameInputs : public FTableRowBase
{
	GENERATED_BODY()

public:
	static FFrameInputs FromDolphinControllerState(DolphinControllerState InDolphinControllerState);
	static DolphinControllerState ToDolphinControllerState(const FFrameInputs& InFrameInputs);
	static FString GetSimpleName(EFrameInputType FrameInputsType);
	static FText GetToolTip(EFrameInputType FrameInputsType, int32 InFrame);
	static bool IsFrameInputTypeButton(EFrameInputType InFrameInputsType);
	static bool IsFrameInputTypeAnalog(EFrameInputType InFrameInputsType);
	void ToggleButton(EFrameInputType InFrameInputsType, bool bIsChecked);
	bool IsButtonToggled(EFrameInputType InFrameInputsType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonStart = false;

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
	bool bButtonL = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bButtonR = false;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOriginReset = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsControllerConnected = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EControllerChangeEvent ControllerChangeEvent = EControllerChangeEvent::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = EGameCubeEvents))
	int32 GameCubeEvents = 0;
};

FORCEINLINE FArchive& operator <<(FArchive& Ar, FFrameInputs& InFrameInputs)
{
	Ar << InFrameInputs.bButtonA;
	Ar << InFrameInputs.bButtonB;
	Ar << InFrameInputs.bButtonX;
	Ar << InFrameInputs.bButtonY;
	Ar << InFrameInputs.bButtonZ;

	Ar << InFrameInputs.bButtonDUp;
	Ar << InFrameInputs.bButtonDDown;
	Ar << InFrameInputs.bButtonDLeft;
	Ar << InFrameInputs.bButtonDRight;

	Ar << InFrameInputs.bButtonStart;

	Ar << InFrameInputs.bButtonL;
	Ar << InFrameInputs.bButtonR;
	Ar << InFrameInputs.TriggerLeft;
	Ar << InFrameInputs.TriggerRight;

	Ar << InFrameInputs.MainStickX;
	Ar << InFrameInputs.MainStickY;
	Ar << InFrameInputs.CStickX;
	Ar << InFrameInputs.CStickY;

	Ar << InFrameInputs.bOriginReset;
	Ar << InFrameInputs.bIsControllerConnected;
	Ar << InFrameInputs.ControllerChangeEvent;
	Ar << InFrameInputs.GameCubeEvents;

	return Ar;
}
