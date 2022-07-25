
#include "BlueprintNodes/K2Node_InputSheet.h"

#include "BlueprintNodes/CoreTechK2Utilities.h"
#include "BlueprintNodes/SInputSheet.h"
#include "DolphinInstance.h"

// BlueprintGraph
#include "K2Node_AssignmentStatement.h"
#include "K2Node_CallFunction.h"
#include "K2Node_ExecutionSequence.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_TemporaryVariable.h"

// Kismet
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// KismetCompiler
#include "KismetCompiler.h"

#define LOCTEXT_NAMESPACE "K2Node_InputSheet"

const FName UK2Node_InputSheet::TargetPinName(TEXT("TargetPin"));
const FName UK2Node_InputSheet::InputsPinName(TEXT("InputsPin"));
const FName UK2Node_InputSheet::CompletedPinName(TEXT("CompletedPin"));

void UK2Node_InputSheet::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	// Execution pin
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);

	const auto TargetPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UDolphinInstance::StaticClass(), TargetPinName);
	TargetPin->PinType.bIsConst = true;
	TargetPin->PinType.bIsReference = true;
	TargetPin->PinFriendlyName = LOCTEXT("TargetPin_FriendlyName", "Target");
	CoreTechK2Utilities::SetPinToolTip(TargetPin, LOCTEXT("TargetPin_Tooltip", "The Dolphin Instance on which to perform the inputs"));

	const auto InputsPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, InputsPinName);
	InputsPin->PinType.ContainerType = EPinContainerType::Array;
	InputsPin->PinType.bIsConst = false;
	InputsPin->PinType.bIsReference = false;
	InputsPin->PinFriendlyName = LOCTEXT("InputsPin_FriendlyName", "Inputs");
	CoreTechK2Utilities::SetPinToolTip(InputsPin, LOCTEXT("InputsPin_Tooltip", "The sequence of inputs to execute frame-by-frame"));

	const auto CompletedPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, CompletedPinName);
	CompletedPin->PinFriendlyName = LOCTEXT("CompletedPin_FriendlyName", " ");
	CompletedPin->PinToolTip = LOCTEXT("CompletedPin_Tooltip", "Execution once all frames have been processed").ToString();

	AdvancedPinDisplay = ENodeAdvancedPins::NoPins;

	// Initialize 30 items
	if (FrameInputs.IsEmpty())
	{
		FrameInputs.AddZeroed(30);
	}
}

void UK2Node_InputSheet::Serialize(FArchive& Ar)
{
	if (Ar.IsLoading())
	{
		FrameInputs.Empty();
	}

	// Save/Load the frame inputs
	Ar << FrameInputs;

	Super::Serialize(Ar);
}

TSharedPtr<SGraphNode> UK2Node_InputSheet::CreateVisualWidget()
{
	return SNew(SInputSheet, this)
		.FrameInputs(&FrameInputs);
}

void UK2Node_InputSheet::PostPasteNode()
{
	Super::PostPasteNode();
}

void UK2Node_InputSheet::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	if (CheckForErrors(CompilerContext))
	{
		// remove all the links to this node as they are no longer needed
		BreakAllNodeLinks();
		return;
	}

	const auto K2Schema = GetDefault< UEdGraphSchema_K2 >();

	///////////////////////////////////////////////////////////////////////////////////
	// Cache off versions of all our important pins
	const auto ExecPin = GetExecPin();
	const auto TargetPin = GetTargetPin();
	const auto InputsPin = GetInputsPin();

	///////////////////////////////////////////////////////////////////////////////////
	//
	BreakAllNodeLinks();
}

bool UK2Node_InputSheet::CheckForErrors(const FKismetCompilerContext& CompilerContext)
{
	bool bError = false;

	return bError;
}

void UK2Node_InputSheet::PinConnectionListChanged(UEdGraphPin* Pin)
{
	Super::PinConnectionListChanged(Pin);
}

UEdGraphPin* UK2Node_InputSheet::GetTargetPin() const
{
	return FindPinChecked(TargetPinName);
}

UEdGraphPin* UK2Node_InputSheet::GetInputsPin() const
{
	return FindPinChecked(InputsPinName);
}

UEdGraphPin* UK2Node_InputSheet::GetCompletedPin() const
{
	return FindPinChecked(CompletedPinName);
}

FText UK2Node_InputSheet::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::Format(LOCTEXT("NodeTitle_NONE", "Input Sheet ({0} Frames)"), FrameInputs.Num());
}

FText UK2Node_InputSheet::GetTooltipText() const
{
	// Best left empty to make it easier to mouse over checkboxes / fields without this tooltip getting in the way
	return LOCTEXT("NodeToolTip", "");
}

FText UK2Node_InputSheet::GetMenuCategory() const
{
	return LOCTEXT("NodeMenu", "Core Utilities");
}

FSlateIcon UK2Node_InputSheet::GetIconAndTint(FLinearColor& OutColor) const
{
	return FSlateIcon("EditorStyle", "GraphEditor.KeyEvent_16x");
}

void UK2Node_InputSheet::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	CoreTechK2Utilities::DefaultGetMenuActions(this, ActionRegistrar);
}

#undef LOCTEXT_NAMESPACE
