
#include "BlueprintNodes/K2Node_InputSleeve.h"

#include "BlueprintNodes/CoreTechK2Utilities.h"
#include "BlueprintNodes/SGraphPinInputSheet.h"

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

#define LOCTEXT_NAMESPACE "K2Node_InputSleeve"

const FName UK2Node_InputSleeve::ButtonAPinName(TEXT("APin"));
const FName UK2Node_InputSleeve::ButtonBPinName(TEXT("BPin"));
const FName UK2Node_InputSleeve::ButtonXPinName(TEXT("XPin"));
const FName UK2Node_InputSleeve::ButtonYPinName(TEXT("YPin"));
const FName UK2Node_InputSleeve::ButtonLPinName(TEXT("LPin"));
const FName UK2Node_InputSleeve::ButtonRPinName(TEXT("RPin"));
const FName UK2Node_InputSleeve::ButtonZPinName(TEXT("ZPin"));
const FName UK2Node_InputSleeve::ButtonDPadLeftPinName(TEXT("DLPin"));
const FName UK2Node_InputSleeve::ButtonDPadRightPinName(TEXT("DRPin"));
const FName UK2Node_InputSleeve::ButtonDPadUpPinName(TEXT("DUPin"));
const FName UK2Node_InputSleeve::ButtonDPadDownPinName(TEXT("DDPin"));
const FName UK2Node_InputSleeve::ButtonStartPinName(TEXT("StartPin"));
const FName UK2Node_InputSleeve::MainStickXPinName(TEXT("MXPin"));
const FName UK2Node_InputSleeve::MainStickYPinName(TEXT("MYPin"));
const FName UK2Node_InputSleeve::CStickXPinName(TEXT("CXPin"));
const FName UK2Node_InputSleeve::CStickYPinName(TEXT("CYPin"));

const FName UK2Node_InputSleeve::CompletedPinName( TEXT( "CompletedPin" ) );

void UK2Node_InputSleeve::AllocateDefaultPins( )
{
	Super::AllocateDefaultPins( );

	// Execution pin
	CreatePin( EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute );

	const auto ButtonAPin = CreatePin( EGPD_Input, UEdGraphSchema_K2::PC_Boolean, ButtonAPinName);
	ButtonAPin->PinType.bIsConst = true;
	ButtonAPin->PinType.bIsReference = false;
	ButtonAPin->PinFriendlyName = LOCTEXT( "ButtonAPin_FriendlyName", "A" );

	const auto CompletedPin = CreatePin( EGPD_Output, UEdGraphSchema_K2::PC_Exec, CompletedPinName );
	CompletedPin->PinFriendlyName = LOCTEXT( "CompletedPin_FriendlyName", "Completed" );
	CompletedPin->PinToolTip = LOCTEXT( "CompletedPin_Tooltip", "Execution once all array elements have been visited" ).ToString( );

	CoreTechK2Utilities::SetPinToolTip( ButtonAPin, LOCTEXT( "ButtonAPin_Tooltip", "Whether or not to press the A button on this frame" ) );

	if (AdvancedPinDisplay == ENodeAdvancedPins::NoPins)
		AdvancedPinDisplay = ENodeAdvancedPins::Hidden;
}

TSharedPtr<SGraphNode> UK2Node_InputSleeve::CreateVisualWidget()
{
	class SInputSleeve : public SGraphNode
	{
	public:
		SLATE_BEGIN_ARGS(SInputSleeve){}
		SLATE_END_ARGS()

		SInputSleeve()
		{}

		void Construct(const FArguments& InArgs, UK2Node_InputSleeve* InNode)
		{
			bNeedsUpdate = false;
			GraphNode = InNode;
			UpdateGraphNode();
		}

		virtual void CreateStandardPinWidget(UEdGraphPin* Pin) override
		{
			SGraphNode::CreateStandardPinWidget(Pin);
		}

	private:
		FSlateColor OnGetComboForeground() const
		{
			return FSlateColor( FLinearColor( 1.f, 1.f, 1.f, IsHovered() ? 1.f : 0.6f ) );
		}

		FSlateColor OnGetWidgetForeground() const
		{
			return FSlateColor( FLinearColor( 1.f, 1.f, 1.f, IsHovered() ? 1.f : 0.15f ) );
		}

		FSlateColor OnGetWidgetBackground() const
		{
			return FSlateColor( FLinearColor( 1.f, 1.f, 1.f, IsHovered() ? 0.8f : 0.4f ) );
		}

	private:
		bool bNeedsUpdate;
	};

	return SNew(SInputSleeve, this);
}

void UK2Node_InputSleeve::PostPasteNode( )
{
	Super::PostPasteNode( );
}

void UK2Node_InputSleeve::ExpandNode( FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph )
{
	Super::ExpandNode( CompilerContext, SourceGraph );

	if (CheckForErrors( CompilerContext ))
	{
		// remove all the links to this node as they are no longer needed
		BreakAllNodeLinks( );
		return;
	}

	const auto K2Schema = GetDefault< UEdGraphSchema_K2 >( );

	///////////////////////////////////////////////////////////////////////////////////
	// Cache off versions of all our important pins
	const auto ExecPin = GetExecPin( );
	const auto ButtonAPin = GetButtonAPin( );

	///////////////////////////////////////////////////////////////////////////////////
	//
	BreakAllNodeLinks( );
}

bool UK2Node_InputSleeve::CheckForErrors( const FKismetCompilerContext& CompilerContext )
{
	bool bError = false;

	return bError;
}

void UK2Node_InputSleeve::PinConnectionListChanged( UEdGraphPin* Pin )
{
	Super::PinConnectionListChanged( Pin );
}

UEdGraphPin* UK2Node_InputSleeve::GetButtonAPin( void ) const
{
	return FindPinChecked( ButtonAPinName );
}

UEdGraphPin* UK2Node_InputSleeve::GetCompletedPin( void ) const
{
	return FindPinChecked( CompletedPinName );
}

FText UK2Node_InputSleeve::GetNodeTitle( ENodeTitleType::Type TitleType ) const
{
	return LOCTEXT( "NodeTitle_NONE", "Input Sleeve" );
}

FText UK2Node_InputSleeve::GetTooltipText( ) const
{
	return LOCTEXT( "NodeToolTip", "A list of all inputs for a single frame." );
}

FText UK2Node_InputSleeve::GetMenuCategory( ) const
{
	return LOCTEXT( "NodeMenu", "Core Utilities" );
}

FSlateIcon UK2Node_InputSleeve::GetIconAndTint( FLinearColor& OutColor ) const
{
	return FSlateIcon( "EditorStyle", "GraphEditor.Macro.ForEach_16x" );
}

void UK2Node_InputSleeve::GetMenuActions( FBlueprintActionDatabaseRegistrar& ActionRegistrar ) const
{
	CoreTechK2Utilities::DefaultGetMenuActions( this, ActionRegistrar );
}

#undef LOCTEXT_NAMESPACE
