#pragma once

#include "CoreMinimal.h"

class IFileHandle;
class UDataTable;

class FInputTableImporter
{
public:
	static bool ImportInputTableAsAsset(const UDataTable& InDataTable);

private:
	static bool WriteRow(IFileHandle* FileHandle, const UScriptStruct* InRowStruct, const void* InRowData, const FProperty* SkipProperty = nullptr);
	static bool WriteStructEntry(IFileHandle* FileHandle, const void* InRowData, FProperty* InProperty, const void* InPropertyData);

	static void AppendString(IFileHandle* FileHandle, const FString& InString);
};