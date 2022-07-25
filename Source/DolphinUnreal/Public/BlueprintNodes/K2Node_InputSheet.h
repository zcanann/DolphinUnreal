
#pragma once

#include "K2Node.h"

#include "FrameInput.h"
#include "GraphEditorSettings.h"

#include "K2Node_InputSheet.generated.h"

class UDolphinInstance;

UCLASS()
class UK2Node_InputSheet : public UK2Node
{
	GENERATED_BODY()
public:
	// Pin Accessors
	UE_NODISCARD UEdGraphPin* GetTargetPin() const;
	UE_NODISCARD UEdGraphPin* GetInputsPin() const;
	UE_NODISCARD UEdGraphPin* GetCompletedPin() const;

	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	//~ End UObject Interface
	
	//~ Begin K2Node API
	virtual UE_NODISCARD bool IsNodeSafeToIgnore() const override { return true; }
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual UE_NODISCARD FText GetMenuCategory() const override;
	//~ End K2Node API

	//~ Begin EdGraphNode API
	virtual void AllocateDefaultPins() override;
	virtual TSharedPtr<SGraphNode> CreateVisualWidget() override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual UE_NODISCARD FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual UE_NODISCARD FText GetTooltipText() const override;
	virtual UE_NODISCARD FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void PostPasteNode() override;
	//~ End EdGraphNode API

	// Pin Names
	static const FName TargetPinName;
	static const FName InputsPinName;
	static const FName CompletedPinName;
private:
	// Determine if there is any configuration options that shouldn't be allowed
	UE_NODISCARD bool CheckForErrors(const FKismetCompilerContext& CompilerContext);

	UDolphinInstance* DolphinInstance = nullptr;
	TArray<FFrameInput> FrameInputs;
};