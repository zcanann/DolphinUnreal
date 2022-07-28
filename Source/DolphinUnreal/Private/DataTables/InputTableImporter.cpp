#pragma once

#include "DataTables/InputTableImporter.h"
#include "Factories/CSVImportFactory.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Misc/FileHelper.h"

#pragma optimize("", off)

bool FInputTableImporter::ImportInputTableAsAsset(const UDataTable& InDataTable)
{
	if (!InDataTable.RowStruct)
	{
		return false;
	}

	FString UniqueName = FGuid::NewGuid().ToString();
	FString OutputCsvName = TEXT("InputTables/") + UniqueName + TEXT(".csv");
	FString InputTableOutputFile = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectContentDir(), OutputCsvName));
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* FileHandle = FileManager.OpenWrite(*InputTableOutputFile);

	if (FileHandle == nullptr)
	{
		delete FileHandle;
		return false;
	}

	// Write the header (column titles)
	FString ImportKeyField;
	if (!InDataTable.ImportKeyField.IsEmpty())
	{
		// Write actual name if we have it
		ImportKeyField = InDataTable.ImportKeyField;
		AppendString(FileHandle, ImportKeyField);
	}
	else
	{
		AppendString(FileHandle, TEXT("---"));
	}

	FProperty* SkipProperty = nullptr;
	for (TFieldIterator<FProperty> It(InDataTable.RowStruct); It; ++It)
	{
		FProperty* BaseProp = *It;
		check(BaseProp);

		FString ColumnHeader = DataTableUtils::GetPropertyExportName(BaseProp, EDataTableExportFlags::None);

		if (ColumnHeader == ImportKeyField)
		{
			// Don't write header again if this is the name field, and save for skipping later
			SkipProperty = BaseProp;
			continue;
		}

		AppendString(FileHandle, TEXT(","));
		AppendString(FileHandle, ColumnHeader);
	}
	AppendString(FileHandle, TEXT("\n"));

	// Write each row
	for (auto RowIt = InDataTable.GetRowMap().CreateConstIterator(); RowIt; ++RowIt)
	{
		FName RowName = RowIt.Key();
		AppendString(FileHandle, RowName.ToString());

		uint8* RowData = RowIt.Value();
		WriteRow(FileHandle, InDataTable.RowStruct, RowData, SkipProperty);

		AppendString(FileHandle, TEXT("\n"));
	}

	/*
	bool bSuccess = UDataTableFunctionLibrary::FillDataTableFromCSVFile(&InDataTable, InputTableOutputFile);
	*/

	FileHandle->Flush(true);
	delete FileHandle;

	FString CsvContents;
	FFileHelper::LoadFileToString(CsvContents, *InputTableOutputFile, FFileHelper::EHashOptions::None);

	bool bWasCancelled = false;
	const TCHAR* Buffer = *CsvContents;
	UCSVImportFactory* ImportFactory = NewObject<UCSVImportFactory>();
	ImportFactory->FactoryCreateText(InDataTable.GetClass()
		, InDataTable.GetOuter()
		, FName(UniqueName)
		, InDataTable.GetFlags()
		, nullptr
		, TEXT("csv")
		, Buffer
		, Buffer + CsvContents.Len()
		, nullptr
		, bWasCancelled);

	return true;
}

bool FInputTableImporter::WriteRow(IFileHandle* FileHandle, const UScriptStruct* InRowStruct, const void* InRowData, const FProperty* SkipProperty)
{
	if (!InRowStruct)
	{
		return false;
	}

	for (TFieldIterator<FProperty> It(InRowStruct); It; ++It)
	{
		FProperty* BaseProp = *It;
		check(BaseProp);

		if (BaseProp == SkipProperty)
		{
			continue;
		}

		const void* Data = BaseProp->ContainerPtrToValuePtr<void>(InRowData, 0);
		WriteStructEntry(FileHandle, InRowData, BaseProp, Data);
	}

	return true;
}

bool FInputTableImporter::WriteStructEntry(IFileHandle* FileHandle, const void* InRowData, FProperty* InProperty, const void* InPropertyData)
{
	const FString PropertyValue = DataTableUtils::GetPropertyValueAsString(InProperty, (uint8*)InRowData, EDataTableExportFlags::None);

	AppendString(FileHandle, TEXT(",\""));
	AppendString(FileHandle, PropertyValue.Replace(TEXT("\""), TEXT("\"\"")));
	AppendString(FileHandle, TEXT("\""));

	return true;
}

void FInputTableImporter::AppendString(IFileHandle* FileHandle, const FString& InString)
{
	if (FileHandle == nullptr)
	{
		return;
	}

	uint8* RawBytes = (uint8*)TCHAR_TO_ANSI(*InString);
	FileHandle->Write(RawBytes, InString.Len());
}

#pragma optimize("", on)
