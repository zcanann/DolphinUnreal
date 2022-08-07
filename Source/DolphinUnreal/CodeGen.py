#!/usr/bin/env python3

import io
import json
import os
import re
import shutil
import sys

from os import listdir
from os import path
from os.path import isfile, dirname, join, splitext, abspath, realpath, basename, relpath

dataTypeTable = {
    "UInt8" :
    {
        "primitive" : "uint8",
        "keywords" : "unsigned uint8 char byte ubyte",
        "bytes" : 1,
    },
    "UInt16" :
    {
        "primitive" : "uint16",
        "keywords" : "unsigned uint16 short ushort",
        "bytes" : 2,
    },
    "UInt32" :
    {
        "primitive" : "uint32",
        "keywords" : "unsigned uint32 int uint integer",
        "bytes" : 4,
    },
    "UInt64" :
    {
        "primitive" : "uint64",
        "keywords" : "unsigned uint64 long int ulong integer",
        "bytes" : 8,
    },
    "Int8" :
    {
        "primitive" : "int8",
        "keywords" : "signed int8 char byte",
        "bytes" : 1,
    },
    "Int16" :
    {
        "primitive" : "int16",
        "keywords" : "signed int16 short",
        "bytes" : 2,
    },
    "Int32" :
    {
        "primitive" : "int32",
        "keywords" : "signed int32 int int integer",
        "bytes" : 4,
    },
    "Int64" :
    {
        "primitive" : "int64",
        "keywords" : "signed int64 long int integer",
        "bytes" : 8,
    },
    "Float" :
    {
        "primitive" : "float",
        "keywords" : "float decimal single single-precision",
        "bytes" : 4,
    },
    "Double" :
    {
        "primitive" : "double",
        "keywords" : "double decimal double-precision float",
        "bytes" : 8,
    },
}

unrealDataTypes = [ "UInt8", "Int32", "Int64", "Float" ]

operatorsTable = {
    "Subtract" :
    {
        "symbol" : "-",
        "keywords" : "- Minus Subtract",
        "isBool" : False,
    },
    "Add" :
    {
        "symbol" : "+",
        "keywords" : "+ Add Addition",
        "isBool" : False,
    },
    "Multiply" :
    {
        "symbol" : "*",
        "keywords" : "* Multiply Times",
        "isBool" : False,
    },
    "Divide" :
    {
        "symbol" : "/",
        "keywords" : "/ Divide By Division",
        "isBool" : False,
    },
    "EqualTo" :
    {
        "symbol" : "==",
        "keywords" : "== Equal To Equals",
        "isBool" : True,
    },
    "NotEqualTo" :
    {
        "symbol" : "!=",
        "keywords" : "!= Not Equal To Equals",
        "isBool" : True,
    },
    "LessThan" :
    {
        "symbol" : "<",
        "keywords" : "< Less Than",
        "isBool" : True,
    },
    "LessThanOrEqualTo" :
    {
        "symbol" : "<=",
        "keywords" : "<= Less Than or Equal To Equals",
        "isBool" : True,
    },
    "GreaterThan" :
    {
        "symbol" : ">",
        "keywords" : "> Greater Than",
        "isBool" : True,
    },
    "GreaterThanOrEqualTo" :
    {
        "symbol" : ">=",
        "keywords" : ">= Greater Than or Equal To Equals",
        "isBool" : True,
    },
}

favorites = "\n"

def main():
    processTemplateFiles()
    
def processTemplateFiles():
    templateSuffix = ".Template.h"
    searchPath = dirname(realpath(__file__))
    hTemplateFiles = []

    for root, dirnames, filenames in os.walk(searchPath):
        for filename in filenames:
            if filename.endswith(templateSuffix):
                hTemplateFiles.append(join(root, filename))

    for hTemplateFile in hTemplateFiles:
        with open(hTemplateFile,'r') as hTemplateInput:
            hTemplateInputContents = hTemplateInput.read()
            hOutputFile = hTemplateFile[:-len(templateSuffix)] + ".h"

            with open(hOutputFile, 'w+', encoding="utf-8") as hWriter:
                header = """//////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN CodeGen.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////"""
                hTemplateInputContents = hTemplateInputContents.replace("#ifdef DOLPHIN_DATA_TYPES_TEMPLATE", header)
                hTemplateInputContents = hTemplateInputContents.replace("#endif // DOLPHIN_DATA_TYPES_TEMPLATE", "")
                hTemplateInputContents = hTemplateInputContents.replace("{{UE_HEADER}}", 'UCLASS(ClassGroup = "Dolphin|CPP UE4FundamentalType Wrapper", BlueprintType)')
                hTemplateInputContents = hTemplateInputContents.replace("{{MAKE}}", generateMakeForAllDataTypes())
                hTemplateInputContents = hTemplateInputContents.replace("{{CAST}}", generateCastsForAllDataTypes())
                hTemplateInputContents = hTemplateInputContents.replace("{{OPERATORS}}", generateOperatorsForAllDataTypes())
                hTemplateInputContents = hTemplateInputContents.replace("{{FAVORITES}}", generateAccumulatedFavorites())
                hWriter.write(hTemplateInputContents)

# Make

def generateMakeHeader(dataType):
    dataTypeKeywords = dataTypeTable[dataType]['keywords']
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin ' + dataType + \
        '", meta = (Keywords = "Make Create ' + dataTypeKeywords + '"))\n'
    
def generatePrimitiveMakeForDataType(dataType, unrealPrimitive):
    functionName = 'Make' + dataType
    generateFavoriteForFunctionName(functionName)
    
    castPrimitive = dataTypeTable[dataType]['primitive']
    return generateMakeHeader(dataType) + \
        '\tstatic FDolphin' + dataType + ' ' + functionName + '(' + unrealPrimitive + ' Value)\n' + \
        '\t{\n' + \
        '\t\treturn static_cast<' + castPrimitive + '>(Value);\n' + \
        '\t}\n\n'

def generateArrayMakeHeader(dataType):
    dataTypeKeywords = dataTypeTable[dataType]['keywords']
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin ' + dataType + \
        ' from Bytes", meta = (Keywords = "Make Create ' + dataTypeKeywords + ' from Array of Bytes int8 uint8 char"))\n'
        
def generateArrayMakeForDataType(dataType, unrealPrimitive):
    castPrimitive = dataTypeTable[dataType]['primitive']
    numBytes = dataTypeTable[dataType]['bytes']
    
    if numBytes <= 1:
        return ""
    
    parameters = ""
    arrayInit = ""
    arrayInitInverse = ""
    
    for index in range(numBytes):
        numByte = index + 1
        inverseNumByte = numBytes - index
        parameters += "uint8 Byte" + str(numByte) + (", " if numByte < numBytes else "")
        arrayInitInverse += "Byte" + str(numByte) + (", " if numByte < numBytes else "")
        arrayInit += "Byte" + str(inverseNumByte) + (", " if numByte < numBytes else "")
    
    functionName = 'Make' + dataType + 'FromBytes'
    generateFavoriteForFunctionName(functionName)
    
    return generateArrayMakeHeader(dataType) + \
        '\tstatic FDolphin' + dataType + ' ' + functionName + '(' + parameters + ', bool bFirstByteIsLeastSignificant = true)\n' + \
        '\t{\n' + \
        '\t\tTArray<uint8> Bytes = bFirstByteIsLeastSignificant\n' + \
        '\t\t\t? TArray<uint8>({ ' + arrayInit + ' })' + '\n' + \
        '\t\t\t: TArray<uint8>({ ' + arrayInitInverse + ' })' + ';\n' + \
        '\t\treturn *reinterpret_cast<' + castPrimitive + '*>(Bytes.GetData());\n' + \
        '\t}\n\n'

def generateHexMakeHeader(dataType):
    dataTypeKeywords = dataTypeTable[dataType]['keywords']
    primitive = dataTypeTable[dataType]['primitive']
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Make Dolphin ' + dataType + \
        ' from Hex String", meta = (ToolTip = "Creates a Dolphin-compatible ' + primitive + ' from the given hex string. Hex prefix (0x) and spaces will be ignored."' + \
        ', Keywords = "Make Create ' + dataTypeKeywords + ' from FString String Hex Hexadecimal"))\n'
        
def generateHexMakeForDataType(dataType, unrealPrimitive):
    castPrimitive = dataTypeTable[dataType]['primitive']
    numBytes = dataTypeTable[dataType]['bytes']
    
    functionName = 'Make' + dataType + 'FromHexString'
    generateFavoriteForFunctionName(functionName)
    
    return generateHexMakeHeader(dataType) + \
        '\tstatic FDolphin' + dataType + ' ' + functionName + '(FString HexString)\n' + \
        '\t{\n' + \
        '\t\tTArray<uint8> Bytes = CreateArrayFromHex(HexString, ' + str(numBytes) + ');\n' + \
        '\t\treturn *reinterpret_cast<' + castPrimitive + '*>(Bytes.GetData());\n' + \
        '\t}\n\n'

# TArray<uint8> Bytes = TArray<uint8>();
# Bytes.AddDefaulted(8);
# if (Hex.StartsWith("0x") || Hex.StartsWith("0X"))
# {
# Hex = Hex.LeftChop(2);
# }
# if (Hex.Len() <= 8)
# {
# HexToBytes(Hex, Bytes.GetData());
# }
# return *reinterpret_cast<double*>(Bytes.GetData());

def generateMakesForDataType(dataType, unrealPrimitive):
    return generatePrimitiveMakeForDataType(dataType, unrealPrimitive) + \
        generateHexMakeForDataType(dataType, unrealPrimitive) + \
        generateArrayMakeForDataType(dataType, unrealPrimitive)

def generateMakeForAllDataTypes():
    header = """//////////////////////////////////////////////////////////////////////////////////
    //                                     MAKE                                     //
    //////////////////////////////////////////////////////////////////////////////////\n\n"""
    
    return header + \
        generateMakesForDataType("UInt8", "int32") + \
        generateMakesForDataType("UInt16", "int32") + \
        generateMakesForDataType("UInt32", "int32") + \
        generateMakesForDataType("UInt64", "int64") + \
        generateMakesForDataType("Int8", "int32") + \
        generateMakesForDataType("Int16", "int32") + \
        generateMakesForDataType("Int32", "int32") + \
        generateMakesForDataType("Int64", "int64") + \
        generateMakesForDataType("Float", "float") + \
        generateMakesForDataType("Double", "float")

# Casts

def generateCastHeader(dataType, castDataType):
    dataTypeKeywords = dataTypeTable[dataType]['keywords']
    castDataTypeKeywords = dataTypeTable[castDataType]['keywords']
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast ' + dataType + " to " + castDataType + '"' + \
        ', meta = (Keywords = "Cast ' + dataType + ' ' + dataTypeKeywords + ' to ' + castDataType + ' ' + castDataTypeKeywords + '"))\n'

def generateUnrealCastHeader(dataType, unrealDataType):
    unrealPrimitive = dataTypeTable[unrealDataType]['primitive']
    dataTypeKeywords = dataTypeTable[dataType]['keywords']
    unrealDataTypeKeywords = dataTypeTable[unrealDataType]['keywords']
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Cast ' + dataType + " to Unreal " + unrealPrimitive + '"' + \
        ', meta = (Keywords = "Cast ' + dataType + ' ' + dataTypeKeywords + ' to ' + unrealDataType + ' ' + unrealDataTypeKeywords + '"))\n'

def generateCastsForDataType(dataType):
    result = ""
    primitive = dataTypeTable[dataType]['primitive']
    
    for castDataType in dataTypeTable:
        castPrimitive = dataTypeTable[castDataType]['primitive']
        if dataType == castDataType:
            continue
        result += generateCastHeader(dataType, castDataType)
        result += '\tstatic FDolphin' + castDataType + ' Cast' + dataType + 'To' + castDataType + '(const FDolphin' + dataType + '& Value)\n'
        result += '\t{\n'
        result += '\t\treturn static_cast<' + castPrimitive + '>(Value);\n'
        result += '\t}\n\n'

    for unrealDataType in unrealDataTypes:
        unrealPrimitive = dataTypeTable[unrealDataType]['primitive']
        result += generateUnrealCastHeader(dataType, unrealDataType)
        result += '\tstatic ' + unrealPrimitive + ' Cast' + dataType + 'ToUnreal' + unrealPrimitive + '(const FDolphin' + dataType + '& Value)\n'
        result += '\t{\n'
        result += '\t\treturn static_cast<' + unrealPrimitive + '>(Value);\n'
        result += '\t}\n\n'
        

    return result

def generateCastsForAllDataTypes():
    header = """//////////////////////////////////////////////////////////////////////////////////
    //                                     CAST                                     //
    //////////////////////////////////////////////////////////////////////////////////\n\n"""
    
    return header + \
        generateCastsForDataType("UInt8") + \
        generateCastsForDataType("UInt16") + \
        generateCastsForDataType("UInt32") + \
        generateCastsForDataType("UInt64") + \
        generateCastsForDataType("Int8") + \
        generateCastsForDataType("Int16") + \
        generateCastsForDataType("Int32") + \
        generateCastsForDataType("Int64") + \
        generateCastsForDataType("Float") + \
        generateCastsForDataType("Double")

# Operators
    
def generateOperatorHeader(dataType, operator):
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "' + \
        operator + " " + dataType + " " + operatorsTable[operator]['symbol'] + " " + dataType + \
        '", meta = (Keywords = "' + operatorsTable[operator]['keywords'] + '"))\n'
    
def generateOperator(dataType, operator):
    functionName = 'Dolphin_' + dataType + operator + dataType
    generateFavoriteForFunctionName(functionName)
    return generateOperatorHeader(dataType, operator) + \
        '\tstatic FDolphin' + dataType + ' ' + functionName + '(const FDolphin' + dataType + '& Value1, const FDolphin' + dataType + '& Value2)\n' + \
        '\t{\n' + \
        '\t\treturn Value1.Value ' + operatorsTable[operator]['symbol'] + ' Value2.Value;\n'  + \
        '\t}\n\n'

def generateBoolOperator(dataType, operator):
    functionName = 'Dolphin_' + dataType + operator + dataType
    generateFavoriteForFunctionName(functionName)
    return generateOperatorHeader(dataType, operator) + \
        '\tstatic bool ' + functionName + '(const FDolphin' + dataType + '& Value1, const FDolphin' + dataType + '& Value2)\n' + \
        '\t{\n' + \
        '\t\treturn Value1.Value ' + operatorsTable[operator]['symbol'] + ' Value2.Value;\n'  + \
        '\t}\n\n'

def generateOperatorsForDataType(dataType):
    result = ""
    
    for operator in operatorsTable:
        if operatorsTable[operator]['isBool']:
            result += generateBoolOperator(dataType, operator)
        else:
            result += generateOperator(dataType, operator)
    
    return result

def generateOperatorsForAllDataTypes():
    header = """//////////////////////////////////////////////////////////////////////////////////
    //                                   OPERATORS                                  //
    //////////////////////////////////////////////////////////////////////////////////\n\n"""
    return header + \
        generateOperatorsForDataType("UInt8") + \
        generateOperatorsForDataType("UInt16") + \
        generateOperatorsForDataType("UInt32") + \
        generateOperatorsForDataType("UInt64") + \
        generateOperatorsForDataType("Int8") + \
        generateOperatorsForDataType("Int16") + \
        generateOperatorsForDataType("Int32") + \
        generateOperatorsForDataType("Int64") + \
        generateOperatorsForDataType("Float") + \
        generateOperatorsForDataType("Double")

def generateFavoriteForFunctionName(functionName):
    global favorites
    favorites += '\t\tAddFunctionToFavorites(DolphinDataTypesBlueprintLibrary->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UDolphinDataTypesBlueprintLibrary, ' + functionName + ')));\n'

def generateAccumulatedFavorites():
    global favorites
    return favorites

if __name__ == '__main__':
    main()
