#include "FrameInput.h"

#define LOCTEXT_NAMESPACE "FrameInput"

FFrameInput FFrameInput::FromDolphinControllerState(DolphinControllerState InDolphinControllerState)
{
	FFrameInput Result;

	Result.bButtonA = InDolphinControllerState.A;
	Result.bButtonB = InDolphinControllerState.B;
	Result.bButtonX = InDolphinControllerState.X;
	Result.bButtonY = InDolphinControllerState.Z;
	Result.bButtonZ = InDolphinControllerState.Z;
	Result.bButtonDUp = InDolphinControllerState.DPadUp;
	Result.bButtonDDown = InDolphinControllerState.DPadDown;
	Result.bButtonDLeft = InDolphinControllerState.DPadLeft;
	Result.bButtonDRight = InDolphinControllerState.DPadRight;
	Result.bButtonL = InDolphinControllerState.L;
	Result.TriggerLeft = InDolphinControllerState.TriggerL;
	Result.bButtonR = InDolphinControllerState.R;
	Result.TriggerRight = InDolphinControllerState.TriggerR;
	Result.MainStickX = InDolphinControllerState.AnalogStickX;
	Result.MainStickY = InDolphinControllerState.AnalogStickY;
	Result.CStickX = InDolphinControllerState.CStickX;
	Result.CStickY = InDolphinControllerState.CStickY;
	Result.bDiscChange = InDolphinControllerState.Disc;
	Result.bConsoleReset = InDolphinControllerState.Reset;
	Result.bIsControllerConnected = InDolphinControllerState.IsConnected;
	Result.bOriginReset = InDolphinControllerState.GetOrigin;

	return Result;
}

DolphinControllerState FFrameInput::ToDolphinControllerState(const FFrameInput& InFrameInput)
{
	DolphinControllerState Result;

	Result.A = InFrameInput.bButtonA;
	Result.B = InFrameInput.bButtonB;
	Result.X = InFrameInput.bButtonX;
	Result.Z = InFrameInput.bButtonY;
	Result.Z = InFrameInput.bButtonZ;
	Result.DPadUp = InFrameInput.bButtonDUp;
	Result.DPadDown = InFrameInput.bButtonDDown;
	Result.DPadLeft = InFrameInput.bButtonDLeft;
	Result.DPadRight = InFrameInput.bButtonDRight;
	Result.L = InFrameInput.bButtonL;
	Result.TriggerL = InFrameInput.TriggerLeft;
	Result.R = InFrameInput.bButtonR;
	Result.TriggerR = InFrameInput.TriggerRight;
	Result.AnalogStickX = InFrameInput.MainStickX;
	Result.AnalogStickY = InFrameInput.MainStickY;
	Result.CStickX = InFrameInput.CStickX;
	Result.CStickY = InFrameInput.CStickY;
	Result.Disc = InFrameInput.bDiscChange;
	Result.Reset = InFrameInput.bConsoleReset;
	Result.IsConnected = InFrameInput.bIsControllerConnected;
	Result.GetOrigin = InFrameInput.bOriginReset;

	return Result;
}

FString FFrameInput::GetSimpleName(EFrameInputType FrameInputType)
{
	switch (FrameInputType)
	{
		case EFrameInputType::A: return TEXT("A");
		case EFrameInputType::B: return TEXT("B");
		case EFrameInputType::X: return TEXT("X");
		case EFrameInputType::Y: return TEXT("Y");
		case EFrameInputType::Z: return TEXT("Z");
		case EFrameInputType::DLeft: return TEXT("DL");
		case EFrameInputType::DRight: return TEXT("DR");
		case EFrameInputType::DUp: return TEXT("DU");
		case EFrameInputType::DDown: return TEXT("DD");
		case EFrameInputType::Start: return TEXT("S");
		case EFrameInputType::L: return TEXT("L");
		case EFrameInputType::R: return TEXT("R");
		case EFrameInputType::LTrigger: return TEXT("LT");
		case EFrameInputType::RTrigger: return TEXT("RT");
		case EFrameInputType::MainAnalogX: return TEXT("Ax");
		case EFrameInputType::MainAnalogY: return TEXT("Ay");
		case EFrameInputType::CStickX: return TEXT("Cx");
		case EFrameInputType::CStickY: return TEXT("Cy");
		default: return TEXT("?");
	}
}

FText FFrameInput::GetToolTip(EFrameInputType FrameInputType, int32 InFrame)
{
	// Convert to 1-Indexed
	InFrame++;

	switch (FrameInputType)
	{
		case EFrameInputType::A: return FText::Format(LOCTEXT("ButtonA_ToolTip", "A Press (Frame {0})"), { InFrame });
		case EFrameInputType::B: return FText::Format(LOCTEXT("ButtonB_ToolTip", "B Press (Frame {0})"), { InFrame });
		case EFrameInputType::X: return FText::Format(LOCTEXT("ButtonB_ToolTip", "X Press (Frame {0})"), { InFrame });
		case EFrameInputType::Y: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Y Press (Frame {0})"), { InFrame });
		case EFrameInputType::Z: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Z Press (Frame {0})"), { InFrame });
		case EFrameInputType::DLeft: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Left Press (Frame {0})"), { InFrame });
		case EFrameInputType::DRight: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Right Press (Frame {0})"), { InFrame });
		case EFrameInputType::DUp: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Up Press (Frame {0})"), { InFrame });
		case EFrameInputType::DDown: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Down Press (Frame {0})"), { InFrame });
		case EFrameInputType::Start: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Start Press (Frame {0})"), { InFrame });
		case EFrameInputType::L: return FText::Format(LOCTEXT("ButtonB_ToolTip", "L Press (Frame {0})"), { InFrame });
		case EFrameInputType::R: return FText::Format(LOCTEXT("ButtonB_ToolTip", "R Press (Frame {0})"), { InFrame });
		case EFrameInputType::LTrigger: return FText::Format(LOCTEXT("ButtonLTrigger_ToolTip", "Left Trigger Analog (Frame {0})"), { InFrame });
		case EFrameInputType::RTrigger: return FText::Format(LOCTEXT("ButtonLTrigger_ToolTip", "Right Trigger Analog Press (Frame {0})"), { InFrame });
		case EFrameInputType::MainAnalogX: return FText::Format(LOCTEXT("ButtonMx_ToolTip", "Main Analog X (Frame {0})"), { InFrame });
		case EFrameInputType::MainAnalogY: return FText::Format(LOCTEXT("ButtonMy_ToolTip", "Main Analog Y Press (Frame {0})"), { InFrame });
		case EFrameInputType::CStickX: return FText::Format(LOCTEXT("ButtonCx_ToolTip", "C-Stick X (Frame {0})"), { InFrame });
		case EFrameInputType::CStickY: return FText::Format(LOCTEXT("ButtonCy_ToolTip", "C-Stick Y (Frame {0})"), { InFrame });
		default: return FText::GetEmpty();
	}
}

bool FFrameInput::IsFrameInputTypeButton(EFrameInputType InFrameInputType)
{
	switch (InFrameInputType)
	{
		case EFrameInputType::A:
		case EFrameInputType::B:
		case EFrameInputType::X:
		case EFrameInputType::Y:
		case EFrameInputType::Z:
		case EFrameInputType::DLeft:
		case EFrameInputType::DRight:
		case EFrameInputType::DUp:
		case EFrameInputType::DDown:
		case EFrameInputType::Start:
		case EFrameInputType::L:
		case EFrameInputType::R:
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
}

bool FFrameInput::IsFrameInputTypeAnalog(EFrameInputType InFrameInputType)
{
	return !FFrameInput::IsFrameInputTypeButton(InFrameInputType);
}

void FFrameInput::ToggleButton(EFrameInputType InFrameInputType, bool bIsChecked)
{
	switch (InFrameInputType)
	{
		default:
		{
			case EFrameInputType::A:
			{
				bButtonA = bIsChecked;
				break;
			}
			case EFrameInputType::B:
			{
				bButtonB = bIsChecked;
				break;
			}
			case EFrameInputType::X:
			{
				bButtonX = bIsChecked;
				break;
			}
			case EFrameInputType::Y:
			{
				bButtonY = bIsChecked;
				break;
			}
			case EFrameInputType::Z:
			{
				bButtonZ = bIsChecked;
				break;
			}
			case EFrameInputType::DLeft:
			{
				bButtonDLeft = bIsChecked;
				break;
			}
			case EFrameInputType::DRight:
			{
				bButtonDRight = bIsChecked;
				break;
			}
			case EFrameInputType::DUp:
			{
				bButtonDUp = bIsChecked;
				break;
			}
			case EFrameInputType::DDown:
			{
				bButtonDDown = bIsChecked;
				break;
			}
			case EFrameInputType::Start:
			{
				bButtonStart = bIsChecked;
				break;
			}
			case EFrameInputType::L:
			{
				bButtonL= bIsChecked;
				break;
			}
			case EFrameInputType::R:
			{
				bButtonR = bIsChecked;
				break;
			}
			break;
		}
	}
}

bool FFrameInput::IsButtonToggled(EFrameInputType InFrameInputType)
{
	switch (InFrameInputType)
	{
		case EFrameInputType::A: return bButtonA;
		case EFrameInputType::B: return bButtonB;
		case EFrameInputType::X: return bButtonX;
		case EFrameInputType::Y: return bButtonY;
		case EFrameInputType::Z: return bButtonZ;
		case EFrameInputType::DLeft: return bButtonDLeft;
		case EFrameInputType::DRight: return bButtonDRight;
		case EFrameInputType::DUp: return bButtonDUp;
		case EFrameInputType::DDown: return bButtonDDown;
		case EFrameInputType::Start: return bButtonStart;
		case EFrameInputType::L: return bButtonL;
		case EFrameInputType::R: return bButtonR;
		default: return false;
	}
}
