#pragma once
#include "SGraphNode.h"

#include "CoreMinimal.h"
#include "FrameInput.h"
#include "Widgets/SWidget.h"

#include "BlueprintNodes/K2Node_InputSheet.h"

class SInputSheet : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SInputSheet)
		: _FrameInputs(nullptr)
	{}

	SLATE_ATTRIBUTE(TArray<FFrameInput>*, FrameInputs)
	SLATE_END_ARGS()

	SInputSheet() {}

	void Construct(const FArguments& InArgs, UK2Node_InputSheet* InNode)
	{
		if (InArgs._FrameInputs.IsSet())
		{
			FrameInputs = InArgs._FrameInputs.Get();
		}
		bNeedsUpdate = false;
		GraphNode = InNode;
		UpdateGraphNode();
	}

	virtual void CreateStandardPinWidget(UEdGraphPin* Pin) override;

private:
	FText GetCheckBoxTooltip(EFrameInputButton InFrameInputButton, int32 InIndex) const;
	ECheckBoxState GetCheckState(EFrameInputButton InFrameInputButton, int32 InIndex) const;
	void OnCheckStateToggled(ECheckBoxState NewState, EFrameInputButton InFrameInputButton, int32 InIndex);

	bool bNeedsUpdate = false;
	TArray<FFrameInput>* FrameInputs = nullptr;
};
