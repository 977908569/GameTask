// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskNode() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_NoRegister();
// End Cross Module References
	void UGameTaskNode::StaticRegisterNativesUGameTaskNode()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskNode_NoRegister()
	{
		return UGameTaskNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameTaskAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameTaskAsset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NodeName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskNode.h" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData[] = {
		{ "Comment", "/** parent node */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "parent node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, ParentNode), Z_Construct_UClass_UGameTaskCompositeNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData[] = {
		{ "Comment", "/** source asset */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "source asset" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset = { "GameTaskAsset", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, GameTaskAsset), Z_Construct_UClass_UGameTask_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData[] = {
		{ "Category", "Description" },
		{ "Comment", "/** node name */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "node name" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, NodeName), METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskNode_Statics::ClassParams = {
		&UGameTaskNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskNode, 2607763942);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskNode>()
	{
		return UGameTaskNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskNode(Z_Construct_UClass_UGameTaskNode, &UGameTaskNode::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
