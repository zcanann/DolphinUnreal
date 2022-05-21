
#include "BlueprintNodes/K2Node_InputSheet.h"

#include "BlueprintNodes/CoreTechK2Utilities.h"
#include "BlueprintNodes/SGraphPinInputSheet.h"

// BlueprintGraph
#include "GraphEditorSettings.h"
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

const FName UK2Node_InputSheet::ButtonAPinName(TEXT("APin"));
const FName UK2Node_InputSheet::ButtonBPinName(TEXT("BPin"));
const FName UK2Node_InputSheet::ButtonXPinName(TEXT("XPin"));
const FName UK2Node_InputSheet::ButtonYPinName(TEXT("YPin"));
const FName UK2Node_InputSheet::ButtonLPinName(TEXT("LPin"));
const FName UK2Node_InputSheet::ButtonRPinName(TEXT("RPin"));
const FName UK2Node_InputSheet::ButtonZPinName(TEXT("ZPin"));
const FName UK2Node_InputSheet::ButtonDPadLeftPinName(TEXT("DLPin"));
const FName UK2Node_InputSheet::ButtonDPadRightPinName(TEXT("DRPin"));
const FName UK2Node_InputSheet::ButtonDPadUpPinName(TEXT("DUPin"));
const FName UK2Node_InputSheet::ButtonDPadDownPinName(TEXT("DDPin"));
const FName UK2Node_InputSheet::ButtonStartPinName(TEXT("StartPin"));
const FName UK2Node_InputSheet::MainStickXPinName(TEXT("MXPin"));
const FName UK2Node_InputSheet::MainStickYPinName(TEXT("MYPin"));
const FName UK2Node_InputSheet::CStickXPinName(TEXT("CXPin"));
const FName UK2Node_InputSheet::CStickYPinName(TEXT("CYPin"));

const FName UK2Node_InputSheet::CompletedPinName( TEXT( "CompletedPin" ) );

void UK2Node_InputSheet::AllocateDefaultPins( )
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

TSharedPtr<SGraphNode> UK2Node_InputSheet::CreateVisualWidget()
{
	class SInputSheet : public SGraphNode
	{
	public:
		SLATE_BEGIN_ARGS(SInputSheet){}
		SLATE_END_ARGS()

		SInputSheet()
		{}

		void Construct(const FArguments& InArgs, UK2Node_InputSheet* InNode)
		{
			bNeedsUpdate = false;
			GraphNode = InNode;
			UpdateGraphNode();
		}

		virtual void CreateStandardPinWidget(UEdGraphPin* Pin) override
		{
			if (Pin == nullptr || Pin->Direction == EEdGraphPinDirection::EGPD_Output || Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
			{
				SGraphNode::CreateStandardPinWidget(Pin);
				return;
			}

			LeftNodeBox->AddSlot()
			.AutoHeight()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(Settings->GetInputPinPadding())
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(24.0f)
					[
						SNew(STextBlock)
						.Text(Pin->PinFriendlyName)
					]
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SCheckBox)
				]
				/*
				[
					SNew(SComboButton)
					.ButtonStyle( FEditorStyle::Get(), "PropertyEditor.AssetComboStyle" )
					.ToolTipText(this, &SInputSheet::GetToolTipText)
					.ForegroundColor(this, &SInputSheet::OnGetComboForeground)
					.ButtonColorAndOpacity(this, &SInputSheet::OnGetWidgetBackground)
					.ContentPadding(FMargin(2,2,2,1))
					.MenuPlacement(MenuPlacement_BelowAnchor)
					.ButtonContent()
					[
						GetCurrentItemWidget(
							SNew(STextBlock)
							.TextStyle( FEditorStyle::Get(), "PropertyEditor.AssetClass" )
							.Font( FEditorStyle::GetFontStyle( "PropertyWindow.NormalFont" ) )
							.ColorAndOpacity(this, &SInputSheet::OnGetComboForeground)
						)
					]
					.OnGetMenuContent(this, &SInputSheet::GetPickerMenu)
				]*/
			];
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

	return SNew(SInputSheet, this);
}

void UK2Node_InputSheet::PostPasteNode( )
{
	Super::PostPasteNode( );
}

void UK2Node_InputSheet::ExpandNode( FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph )
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

bool UK2Node_InputSheet::CheckForErrors( const FKismetCompilerContext& CompilerContext )
{
	bool bError = false;

	return bError;
}

void UK2Node_InputSheet::PinConnectionListChanged( UEdGraphPin* Pin )
{
	Super::PinConnectionListChanged( Pin );
}

UEdGraphPin* UK2Node_InputSheet::GetButtonAPin( void ) const
{
	return FindPinChecked( ButtonAPinName );
}

UEdGraphPin* UK2Node_InputSheet::GetCompletedPin( void ) const
{
	return FindPinChecked( CompletedPinName );
}

FText UK2Node_InputSheet::GetNodeTitle( ENodeTitleType::Type TitleType ) const
{
	return LOCTEXT( "NodeTitle_NONE", "Input Sheet" );
}

FText UK2Node_InputSheet::GetTooltipText( ) const
{
	return LOCTEXT( "NodeToolTip", "A list of all inputs for a single frame." );
}

FText UK2Node_InputSheet::GetMenuCategory( ) const
{
	return LOCTEXT( "NodeMenu", "Core Utilities" );
}

FSlateIcon UK2Node_InputSheet::GetIconAndTint( FLinearColor& OutColor ) const
{
	return FSlateIcon( "EditorStyle", "GraphEditor.KeyEvent_16x" );
}

void UK2Node_InputSheet::GetMenuActions( FBlueprintActionDatabaseRegistrar& ActionRegistrar ) const
{
	CoreTechK2Utilities::DefaultGetMenuActions( this, ActionRegistrar );
}

#undef LOCTEXT_NAMESPACE
