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
    },
    "UInt16" :
    {
        "primitive" : "uint16",
        "keywords" : "unsigned uint16 short ushort",
    },
    "UInt32" :
    {
        "primitive" : "uint32",
        "keywords" : "unsigned uint32 int uint integer",
    },
    "UInt64" :
    {
        "primitive" : "uint64",
        "keywords" : "unsigned uint64 long int ulong integer",
    },
    "Int8" :
    {
        "primitive" : "int8",
        "keywords" : "signed int8 char byte",
    },
    "Int16" :
    {
        "primitive" : "int16",
        "keywords" : "signed int16 short",
    },
    "Int32" :
    {
        "primitive" : "int32",
        "keywords" : "signed int32 int int integer",
    },
    "Int64" :
    {
        "primitive" : "int64",
        "keywords" : "signed int64 long int integer",
    },
    "Float" :
    {
        "primitive" : "float",
        "keywords" : "float decimal single single-precision",
    },
    "Double" :
    {
        "primitive" : "double",
        "keywords" : "double decimal double-precision float",
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
                hTemplateInputContents = hTemplateInputContents.replace("{{CREATE}}", generateCreatorsForAllDataTypes())
                hTemplateInputContents = hTemplateInputContents.replace("{{CAST}}", generateCastsForAllDataTypes())
                hTemplateInputContents = hTemplateInputContents.replace("{{OPERATORS}}", generateOperatorsForAllDataTypes())
                hWriter.write(hTemplateInputContents)

# Creators

def generateCreateHeader(dataType):
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "Create Dolphin ' + dataType + '")\n'
    
def generateCreateForDataType(dataType, castPrimitive, primitive):
    return generateCreateHeader(dataType) + \
        '\tstatic FDolphin' + dataType + ' Create' + dataType + '(' + primitive + ' Value)\n' + \
        '\t{\n' + \
        '\t\treturn static_cast<' + castPrimitive + '>(Value);\n' + \
        '\t}\n\n'
        
def generateCreatorsForAllDataTypes():
    header = """//////////////////////////////////////////////////////////////////////////////////
    //                                    CREATE                                    //
    //////////////////////////////////////////////////////////////////////////////////\n\n"""
    
    return header + \
        generateCreateForDataType("UInt8", "uint8", "int32") + \
        generateCreateForDataType("UInt16", "uint16", "int32") + \
        generateCreateForDataType("UInt32", "uint32", "int32") + \
        generateCreateForDataType("UInt64", "uint64", "int64") + \
        generateCreateForDataType("Int8", "int8", "int32") + \
        generateCreateForDataType("Int16", "int16", "int32") + \
        generateCreateForDataType("Int32", "int32", "int32") + \
        generateCreateForDataType("Int64", "int64", "int64") + \
        generateCreateForDataType("Float", "float", "float") + \
        generateCreateForDataType("Double", "double", "float")

# Extractors

def generateExtractHeader(dataType, operationName, operation):
    return 'UFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "' + dataType + " " + operation + " " + dataType + '")\n'

def generateExtractorsForDataType(dataType):
    return ""
        
def generateExtractorsForAllDataTypes():
    header = """//////////////////////////////////////////////////////////////////////////////////
    //                                    EXTRACT                                   //
    //////////////////////////////////////////////////////////////////////////////////\n\n"""
    return header + \
        generateExtractorsForDataType("UInt8") + \
        generateExtractorsForDataType("UInt16") + \
        generateExtractorsForDataType("UInt32") + \
        generateExtractorsForDataType("UInt64") + \
        generateExtractorsForDataType("Int8") + \
        generateExtractorsForDataType("Int16") + \
        generateExtractorsForDataType("Int32") + \
        generateExtractorsForDataType("Int64") + \
        generateExtractorsForDataType("Float") + \
        generateExtractorsForDataType("Double")

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
    return '\tUFUNCTION(Category = "Dolphin|Dolphin Data Types", BlueprintPure, DisplayName = "' + dataType + " " + operatorsTable[operator]['symbol'] + " " + dataType + \
        '", meta = (Keywords = "' + operatorsTable[operator]['keywords'] + '"))\n'
    
def generateOperator(dataType, operator):
    return generateOperatorHeader(dataType, operator) + \
        "\tstatic FDolphin" + dataType + " Dolphin_" + dataType + operator + dataType + "(const FDolphin" + dataType + "& Value1, const FDolphin" + dataType + "& Value2)\n" + \
        "\t{\n" + \
        "\t\treturn Value1.Value " + operatorsTable[operator]['symbol'] + " Value2.Value;\n"  + \
        "\t}\n\n"

def generateBoolOperator(dataType, operator):
    return generateOperatorHeader(dataType, operator) + \
        "\tstatic bool Dolphin_" + dataType + operator + dataType + "(const FDolphin" + dataType + "& Value1, const FDolphin" + dataType + "& Value2)\n" + \
        "\t{\n" + \
        "\t\treturn Value1.Value " + operatorsTable[operator]['symbol'] + " Value2.Value;\n"  + \
        "\t}\n\n"

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


if __name__ == '__main__':
    main()
