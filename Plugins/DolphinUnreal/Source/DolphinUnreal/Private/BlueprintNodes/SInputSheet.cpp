#include "BlueprintNodes/SInputSheet.h"

void SInputSheet::CreateStandardPinWidget(UEdGraphPin* Pin)
{
	if (Pin == nullptr || Pin->Direction == EEdGraphPinDirection::EGPD_Output || Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
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

		for (const FFrameInput& FrameInput : *FrameInputs)
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
					]
				];

			bAddNames = false;
		}
	}
}