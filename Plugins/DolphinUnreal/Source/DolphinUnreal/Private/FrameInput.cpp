#include "FrameInput.h"

FString FFrameInput::GetSimpleName(EFrameInputButton FrameInputButton)
{
	switch (FrameInputButton)
	{
		case EFrameInputButton::A: return TEXT("A");
		case EFrameInputButton::B: return TEXT("B");
		case EFrameInputButton::X: return TEXT("X");
		case EFrameInputButton::Y: return TEXT("Y");
		case EFrameInputButton::Z: return TEXT("Z");
		case EFrameInputButton::DLeft: return TEXT("DL");
		case EFrameInputButton::DRight: return TEXT("DR");
		case EFrameInputButton::DUp: return TEXT("DU");
		case EFrameInputButton::DDown: return TEXT("DD");
		case EFrameInputButton::Start: return TEXT("S");
		case EFrameInputButton::L: return TEXT("LT");
		case EFrameInputButton::R: return TEXT("RT");
		case EFrameInputButton::LTrigger: return TEXT("LT");
		case EFrameInputButton::RTrigger: return TEXT("RT");
		case EFrameInputButton::MainAnalogX: return TEXT("Ax");
		case EFrameInputButton::MainAnalogY: return TEXT("Ay");
		case EFrameInputButton::CStickX: return TEXT("Cx");
		case EFrameInputButton::CStickY: return TEXT("Cy");
		default: return TEXT("?");
	}
}