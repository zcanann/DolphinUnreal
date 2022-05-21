#include "BlueprintNodes/SInputSheet.h"

void SInputSheet::CreateStandardPinWidget(UEdGraphPin* Pin)
{
	if (Pin == nullptr
		|| Pin->Direction == EEdGraphPinDirection::EGPD_Output
		|| Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec
		|| Pin->PinName != UK2Node_InputSheet::InputsPinName)
	{
		SGraphNode::CreateStandardPinWidget(Pin);
		return;
	}

	for (EFrameInputButton FrameInputButton : TEnumRange<EFrameInputButton>())
	{
		TSharedPtr<SHorizontalBox> InputsGrid;

		LeftNodeBox->AddSlot()
			.AutoHeight()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(Settings->GetInputPinPadding())
			[
				SAssignNew(InputsGrid, SHorizontalBox)
			];

		if (FrameInputs == nullptr)
		{
			continue;
		}

		bool bAddNames = true;

		for (int Index = 0; Index < FrameInputs->Num(); Index++)
		{
			static const float GridCellSize = 20.0f;

			if (bAddNames)
			{
				InputsGrid->AddSlot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(GridCellSize)
					[
						SNew(STextBlock)
						.Text(FText::FromString(FFrameInput::GetSimpleName(FrameInputButton)))
					]
				];
			}

			InputsGrid->AddSlot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(GridCellSize)
					[
						SNew(SCheckBox)
						.IsChecked(this, &SInputSheet::GetCheckState, FrameInputButton, Index)
						.OnCheckStateChanged(this, &SInputSheet::OnCheckStateToggled, FrameInputButton, Index)
						.ToolTipText(this, &SInputSheet::GetCheckBoxTooltip, FrameInputButton, Index)
					]
				];

			bAddNames = false;
		}
	}
}

FText SInputSheet::GetCheckBoxTooltip(EFrameInputButton InFrameInputButton, int32 InIndex) const
{
	return FFrameInput::GetToolTip(InFrameInputButton, InIndex);
}

ECheckBoxState SInputSheet::GetCheckState(EFrameInputButton InFrameInputButton, int32 InIndex) const
{
	if (FrameInputs == nullptr || !FrameInputs->IsValidIndex(InIndex))
	{
		return ECheckBoxState::Unchecked;
	}

	return (*FrameInputs)[InIndex].IsButtonToggled(InFrameInputButton) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SInputSheet::OnCheckStateToggled(ECheckBoxState NewState, EFrameInputButton InFrameInputButton, int32 InIndex)
{
	if (FrameInputs == nullptr || !FrameInputs->IsValidIndex(InIndex))
	{
		return;
	}

	bool bIsChecked = (NewState == ECheckBoxState::Checked);

	(*FrameInputs)[InIndex].ToggleButton(InFrameInputButton, bIsChecked);
}
