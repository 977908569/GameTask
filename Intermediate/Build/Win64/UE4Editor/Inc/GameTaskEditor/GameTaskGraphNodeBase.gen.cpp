// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskGraphNodeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphNodeBase() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNodeBase();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMETASKEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData();
// End Cross Module References
	void UGameTaskGraphNodeBase::StaticRegisterNativesUGameTaskGraphNodeBase()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister()
	{
		return UGameTaskGraphNodeBase::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphNodeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsSubNode_MetaData[];
#endif
		static void NewProp_bIsSubNode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSubNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsReadOnly_MetaData[];
#endif
		static void NewProp_bIsReadOnly_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsReadOnly;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CopySubNodeIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CopySubNodeIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SubNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NodeInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClassData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskGraphNodeBase.h" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "Comment", "/** error message for node */" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
		{ "ToolTip", "error message for node" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, ErrorMessage), METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode_MetaData[] = {
		{ "Comment", "/** if set, this node will be always considered as subnode */" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
		{ "ToolTip", "if set, this node will be always considered as subnode" },
	};
#endif
	void Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode_SetBit(void* Obj)
	{
		((UGameTaskGraphNodeBase*)Obj)->bIsSubNode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode = { "bIsSubNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(UGameTaskGraphNodeBase), &Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly_MetaData[] = {
		{ "Comment", "/** if set, all modifications (including delete/cut) are disabled */" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
		{ "ToolTip", "if set, all modifications (including delete/cut) are disabled" },
	};
#endif
	void Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly_SetBit(void* Obj)
	{
		((UGameTaskGraphNodeBase*)Obj)->bIsReadOnly = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly = { "bIsReadOnly", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(UGameTaskGraphNodeBase), &Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData[] = {
		{ "Comment", "/** subnode index assigned during copy operation to connect nodes again on paste */" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
		{ "ToolTip", "subnode index assigned during copy operation to connect nodes again on paste" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_CopySubNodeIndex = { "CopySubNodeIndex", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, CopySubNodeIndex), METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes_MetaData[] = {
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes = { "SubNodes", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, SubNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes_Inner = { "SubNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ParentNode_MetaData[] = {
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0010000000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, ParentNode), Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ParentNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ParentNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, NodeInstance), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_NodeInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_NodeInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ClassData_MetaData[] = {
		{ "Comment", "/** instance class */" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNodeBase.h" },
		{ "ToolTip", "instance class" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ClassData = { "ClassData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphNodeBase, ClassData), Z_Construct_UScriptStruct_FGameTaskGraphNodeClassData, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ClassData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ClassData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ErrorMessage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsSubNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_bIsReadOnly,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_CopySubNodeIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_SubNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ParentNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_NodeInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::NewProp_ClassData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNodeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::ClassParams = {
		&UGameTaskGraphNodeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphNodeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphNodeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphNodeBase, 433705703);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphNodeBase>()
	{
		return UGameTaskGraphNodeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphNodeBase(Z_Construct_UClass_UGameTaskGraphNodeBase, &UGameTaskGraphNodeBase::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphNodeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphNodeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
