#include "BlueprintNodes/SGraphPinInputSheet.h"

#include "Widgets/Input/SComboButton.h"
#include "Widgets/Views/SListView.h"
#include "ScopedTransaction.h"

void SGraphPinInputSheet::Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InGraphPinObj);
}

TSharedRef<SWidget>	SGraphPinInputSheet::GetDefaultValueWidget()
{
	//Get list of enum indexes
	TArray< TSharedPtr<int32> > ComboItems;
	GenerateComboBoxIndexes(ComboItems);

	//Create widget
	return SAssignNew(ComboBox, SPinComboBox)
		.ComboItemList(ComboItems)
		.VisibleText(this, &SGraphPinInputSheet::OnGetText)
		.OnSelectionChanged(this, &SGraphPinInputSheet::ComboBoxSelectionChanged)
		.IsEnabled(this, &SGraphPin::GetDefaultValueIsEditable)
		.Visibility(this, &SGraphPin::GetDefaultValueVisibility)
		.OnGetDisplayName(this, &SGraphPinInputSheet::OnGetFriendlyName)
		.OnGetTooltip(this, &SGraphPinInputSheet::OnGetTooltip);
}

FText SGraphPinInputSheet::OnGetFriendlyName(int32 EnumIndex)
{
	if (GraphPinObj->IsPendingKill())
	{
		return FText();
	}

	UEnum* EnumPtr = Cast<UEnum>(GraphPinObj->PinType.PinSubCategoryObject.Get());

	check(EnumPtr);
	check(EnumIndex < EnumPtr->NumEnums());

	FText EnumValueName = EnumPtr->GetDisplayNameTextByIndex(EnumIndex);
	return EnumValueName;
}

FText SGraphPinInputSheet::OnGetTooltip(int32 EnumIndex)
{
	UEnum* EnumPtr = Cast<UEnum>(GraphPinObj->PinType.PinSubCategoryObject.Get());

	check(EnumPtr);
	check(EnumIndex < EnumPtr->NumEnums());

	FText EnumValueTooltip = EnumPtr->GetToolTipTextByIndex(EnumIndex);
	return EnumValueTooltip;
}

void SGraphPinInputSheet::ComboBoxSelectionChanged(TSharedPtr<int32> NewSelection, ESelectInfo::Type /*SelectInfo*/)
{
	UEnum* EnumPtr = Cast<UEnum>(GraphPinObj->PinType.PinSubCategoryObject.Get());
	check(EnumPtr);

	FString EnumSelectionString;
	if (NewSelection.IsValid())
	{
		check(*NewSelection < EnumPtr->NumEnums() - 1);
		EnumSelectionString = EnumPtr->GetNameStringByIndex(*NewSelection);
	}
	else
	{
		EnumSelectionString = FName(NAME_None).ToString();
	}


	if (GraphPinObj->GetDefaultAsString() != EnumSelectionString)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("GraphEditor", "ChangeEnumPinValue", "Change Enum Pin Value"));
		GraphPinObj->Modify();

		//Set new selection
		GraphPinObj->GetSchema()->TrySetDefaultValue(*GraphPinObj, EnumSelectionString);
	}
}

FString SGraphPinInputSheet::OnGetText() const
{
	FString SelectedString = GraphPinObj->GetDefaultAsString();

	UEnum* EnumPtr = Cast<UEnum>(GraphPinObj->PinType.PinSubCategoryObject.Get());
	if (EnumPtr && EnumPtr->NumEnums())
	{
		const int32 MaxIndex = EnumPtr->NumEnums() - 1;
		for (int32 EnumIdx = 0; EnumIdx < MaxIndex; ++EnumIdx)
		{
			// Ignore hidden enum values
			if (!EnumPtr->HasMetaData(TEXT("Hidden"), EnumIdx))
			{
				if (SelectedString == EnumPtr->GetNameStringByIndex(EnumIdx))
				{
					FString EnumDisplayName = EnumPtr->GetDisplayNameTextByIndex(EnumIdx).ToString();
					if (EnumDisplayName.Len() == 0)
					{
						return SelectedString;
					}
					else
					{
						return EnumDisplayName;
					}
				}
			}
		}

		if (SelectedString == EnumPtr->GetNameStringByIndex(MaxIndex))
		{
			return TEXT("(INVALID)");
		}

	}
	return SelectedString;
}

void SGraphPinInputSheet::GenerateComboBoxIndexes(TArray< TSharedPtr<int32> >& OutComboBoxIndexes)
{
	UEnum* EnumPtr = Cast<UEnum>(GraphPinObj->PinType.PinSubCategoryObject.Get());
	if (EnumPtr)
	{

		//NumEnums() - 1, because the last item in an enum is the _MAX item
		for (int32 EnumIndex = 0; EnumIndex < EnumPtr->NumEnums() - 1; ++EnumIndex)
		{
			// Ignore hidden enum values
			if (!EnumPtr->HasMetaData(TEXT("Hidden"), EnumIndex))
			{
				TSharedPtr<int32> EnumIdxPtr(new int32(EnumIndex));
				OutComboBoxIndexes.Add(EnumIdxPtr);
			}
		}
	}
}
