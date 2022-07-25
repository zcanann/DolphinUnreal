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

	for (EFrameInputType FrameInputType : TEnumRange<EFrameInputType>())
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
			static const float GridCellSize = 26.0f;

			if (bAddNames)
			{
				InputsGrid->AddSlot()
				.AutoWidth()
				[
					SNew(SBox)
					.HAlign(EHorizontalAlignment::HAlign_Center)
					.WidthOverride(GridCellSize)
					[
						SNew(STextBlock)
						.Text(FText::FromString(FFrameInput::GetSimpleName(FrameInputType)))
					]
				];
			}

			if (FFrameInput::IsFrameInputTypeButton(FrameInputType))
			{
				InputsGrid->AddSlot()
				.AutoWidth()
				[
					SNew(SBox)
					.HAlign(EHorizontalAlignment::HAlign_Center)
					.WidthOverride(GridCellSize)
					[
						SNew(SCheckBox)
						.IsChecked(this, &SInputSheet::GetCheckState, FrameInputType, Index)
						.OnCheckStateChanged(this, &SInputSheet::OnCheckStateToggled, FrameInputType, Index)
						.ToolTipText(this, &SInputSheet::GetInputToolTip, FrameInputType, Index)
					]
				];
			}
			else
			{
				InputsGrid->AddSlot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(GridCellSize)
					[
						SNew(SOverlay)
						+ SOverlay::Slot()
						[
							SNew(SBorder)
							.BorderBackgroundColor(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f))
						]
						+ SOverlay::Slot()
						[
							SNew(SEditableText)
							.Justification(ETextJustify::Center)
							.ToolTipText(this, &SInputSheet::GetInputToolTip, FrameInputType, Index)
						]
					]
				];
			}

			bAddNames = false;
		}
	}
}

FText SInputSheet::GetInputToolTip(EFrameInputType InFrameInputType, int32 InIndex) const
{
	return FFrameInput::GetToolTip(InFrameInputType, InIndex);
}

ECheckBoxState SInputSheet::GetCheckState(EFrameInputType InFrameInputType, int32 InIndex) const
{
	if (FrameInputs == nullptr || !FrameInputs->IsValidIndex(InIndex))
	{
		return ECheckBoxState::Unchecked;
	}

	return (*FrameInputs)[InIndex].IsButtonToggled(InFrameInputType) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SInputSheet::OnCheckStateToggled(ECheckBoxState NewState, EFrameInputType InFrameInputType, int32 InIndex)
{
	if (FrameInputs == nullptr || !FrameInputs->IsValidIndex(InIndex))
	{
		return;
	}

	bool bIsChecked = (NewState == ECheckBoxState::Checked);

	(*FrameInputs)[InIndex].ToggleButton(InFrameInputType, bIsChecked);
}
