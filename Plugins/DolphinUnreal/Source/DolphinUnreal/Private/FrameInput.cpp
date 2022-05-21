#include "FrameInput.h"

#define LOCTEXT_NAMESPACE "FrameInput"

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

FText FFrameInput::GetToolTip(EFrameInputButton FrameInputButton, int32 InFrame)
{
	switch (FrameInputButton)
	{
		case EFrameInputButton::A: return FText::Format(LOCTEXT("ButtonA_ToolTip", "A Press (Frame {0})"), { InFrame });
		case EFrameInputButton::B: return FText::Format(LOCTEXT("ButtonB_ToolTip", "B Press (Frame {0})"), { InFrame });
		case EFrameInputButton::X: return FText::Format(LOCTEXT("ButtonB_ToolTip", "X Press (Frame {0})"), { InFrame });
		case EFrameInputButton::Y: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Y Press (Frame {0})"), { InFrame });
		case EFrameInputButton::Z: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Z Press (Frame {0})"), { InFrame });
		case EFrameInputButton::DLeft: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Left Press (Frame {0})"), { InFrame });
		case EFrameInputButton::DRight: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Right Press (Frame {0})"), { InFrame });
		case EFrameInputButton::DUp: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Up Press (Frame {0})"), { InFrame });
		case EFrameInputButton::DDown: return FText::Format(LOCTEXT("ButtonB_ToolTip", "D-Pad Down Press (Frame {0})"), { InFrame });
		case EFrameInputButton::Start: return FText::Format(LOCTEXT("ButtonB_ToolTip", "Start Press (Frame {0})"), { InFrame });
		case EFrameInputButton::L: return FText::Format(LOCTEXT("ButtonB_ToolTip", "L Press (Frame {0})"), { InFrame });
		case EFrameInputButton::R: return FText::Format(LOCTEXT("ButtonB_ToolTip", "R Press (Frame {0})"), { InFrame });
		case EFrameInputButton::LTrigger: return FText::Format(LOCTEXT("ButtonLTrigger_ToolTip", "Left Trigger Analog (Frame {0})"), { InFrame });
		case EFrameInputButton::RTrigger: return FText::Format(LOCTEXT("ButtonLTrigger_ToolTip", "Right Trigger Analog Press (Frame {0})"), { InFrame });
		case EFrameInputButton::MainAnalogX: return FText::Format(LOCTEXT("ButtonMx_ToolTip", "Main Analog X (Frame {0})"), { InFrame });
		case EFrameInputButton::MainAnalogY: return FText::Format(LOCTEXT("ButtonMy_ToolTip", "Main Analog Y Press (Frame {0})"), { InFrame });
		case EFrameInputButton::CStickX: return FText::Format(LOCTEXT("ButtonCx_ToolTip", "C-Stick X (Frame {0})"), { InFrame });
		case EFrameInputButton::CStickY: return FText::Format(LOCTEXT("ButtonCy_ToolTip", "C-Stick Y (Frame {0})"), { InFrame });
		default: return FText::GetEmpty();
	}
}

void FFrameInput::ToggleButton(EFrameInputButton InFrameInputButton, bool bIsChecked)
{
	switch (InFrameInputButton)
	{
		default:
		{
			case EFrameInputButton::A:
			{
				bButtonA = bIsChecked;
				break;
			}
			case EFrameInputButton::B:
			{
				bButtonB = bIsChecked;
				break;
			}
			case EFrameInputButton::X:
			{
				bButtonX = bIsChecked;
				break;
			}
			case EFrameInputButton::Y:
			{
				bButtonY = bIsChecked;
				break;
			}
			case EFrameInputButton::Z:
			{
				bButtonZ = bIsChecked;
				break;
			}
			case EFrameInputButton::DLeft:
			{
				bButtonDLeft = bIsChecked;
				break;
			}
			case EFrameInputButton::DRight:
			{
				bButtonDRight = bIsChecked;
				break;
			}
			case EFrameInputButton::DUp:
			{
				bButtonDUp = bIsChecked;
				break;
			}
			case EFrameInputButton::DDown:
			{
				bButtonDDown = bIsChecked;
				break;
			}
			case EFrameInputButton::Start:
			{
				bButtonStart = bIsChecked;
				break;
			}
			case EFrameInputButton::L:
			{
				bButtonL= bIsChecked;
				break;
			}
			case EFrameInputButton::R:
			{
				bButtonR = bIsChecked;
				break;
			}
			break;
		}
	}
}

bool FFrameInput::IsButtonToggled(EFrameInputButton InFrameInputButton)
{
	switch (InFrameInputButton)
	{
		case EFrameInputButton::A: return bButtonA;
		case EFrameInputButton::B: return bButtonB;
		case EFrameInputButton::X: return bButtonX;
		case EFrameInputButton::Y: return bButtonY;
		case EFrameInputButton::Z: return bButtonZ;
		case EFrameInputButton::DLeft: return bButtonDLeft;
		case EFrameInputButton::DRight: return bButtonDRight;
		case EFrameInputButton::DUp: return bButtonDUp;
		case EFrameInputButton::DDown: return bButtonDDown;
		case EFrameInputButton::Start: return bButtonStart;
		case EFrameInputButton::L: return bButtonL;
		case EFrameInputButton::R: return bButtonR;
		default: return false;
	}
}
