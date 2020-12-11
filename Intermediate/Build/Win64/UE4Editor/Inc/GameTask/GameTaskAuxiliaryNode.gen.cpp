// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskAuxiliaryNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskAuxiliaryNode() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskAuxiliaryNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskAuxiliaryNode();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
// End Cross Module References
	void UGameTaskAuxiliaryNode::StaticRegisterNativesUGameTaskAuxiliaryNode()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskAuxiliaryNode_NoRegister()
	{
		return UGameTaskAuxiliaryNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Auxiliary nodes are supporting nodes\n */" },
		{ "IncludePath", "GameTaskAuxiliaryNode.h" },
		{ "ModuleRelativePath", "Public/GameTaskAuxiliaryNode.h" },
		{ "ToolTip", "Auxiliary nodes are supporting nodes" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskAuxiliaryNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::ClassParams = {
		&UGameTaskAuxiliaryNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskAuxiliaryNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskAuxiliaryNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskAuxiliaryNode, 775313782);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskAuxiliaryNode>()
	{
		return UGameTaskAuxiliaryNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskAuxiliaryNode(Z_Construct_UClass_UGameTaskAuxiliaryNode, &UGameTaskAuxiliaryNode::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskAuxiliaryNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskAuxiliaryNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
