// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskEditorGraphTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskEditorGraphTypes() {}
// Cross Module References
	GAMETASKEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
class UScriptStruct* FGameTaskGraphNodeClassData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAMETASKEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData, Z_Construct_UPackage__Script_GameTaskEditor(), TEXT("GameTaskGraphNodeClassData"), sizeof(FGameTaskGraphNodeClassData), Get_Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Hash());
	}
	return Singleton;
}
template<> GAMETASKEDITOR_API UScriptStruct* StaticStruct<FGameTaskGraphNodeClassData>()
{
	return FGameTaskGraphNodeClassData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGameTaskGraphNodeClassData(FGameTaskGraphNodeClassData::StaticStruct, TEXT("/Script/GameTaskEditor"), TEXT("GameTaskGraphNodeClassData"), false, nullptr, nullptr);
static struct FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskGraphNodeClassData
{
	FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskGraphNodeClassData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GameTaskGraphNodeClassData")),new UScriptStruct::TCppStructOps<FGameTaskGraphNodeClassData>);
	}
} ScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskGraphNodeClassData;
	struct Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Category;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ClassName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratedClassPackage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_GeneratedClassPackage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AssetName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameTaskGraphNodeClassData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_Category_MetaData[] = {
		{ "Comment", "/** User-defined category for this class */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphTypes.h" },
		{ "ToolTip", "User-defined category for this class" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskGraphNodeClassData, Category), METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_Category_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_Category_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_ClassName_MetaData[] = {
		{ "Comment", "/** resolved name of class from asset data */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphTypes.h" },
		{ "ToolTip", "resolved name of class from asset data" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_ClassName = { "ClassName", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskGraphNodeClassData, ClassName), METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_ClassName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_ClassName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_GeneratedClassPackage_MetaData[] = {
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_GeneratedClassPackage = { "GeneratedClassPackage", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskGraphNodeClassData, GeneratedClassPackage), METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_GeneratedClassPackage_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_GeneratedClassPackage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_AssetName_MetaData[] = {
		{ "Comment", "/** path to class if it's not loaded yet */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphTypes.h" },
		{ "ToolTip", "path to class if it's not loaded yet" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskGraphNodeClassData, AssetName), METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_AssetName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_AssetName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_ClassName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_GeneratedClassPackage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::NewProp_AssetName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
		nullptr,
		&NewStructOps,
		"GameTaskGraphNodeClassData",
		sizeof(FGameTaskGraphNodeClassData),
		alignof(FGameTaskGraphNodeClassData),
		Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GameTaskEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GameTaskGraphNodeClassData"), sizeof(FGameTaskGraphNodeClassData), Get_Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData_Hash() { return 429761433U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
