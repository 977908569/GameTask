// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Node/GameTaskGraphNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphNode() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNodeBase();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraphNode::StaticRegisterNativesUGameTaskGraphNode()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphNode_NoRegister()
	{
		return UGameTaskGraphNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphNodeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Node/GameTaskGraphNode.h" },
		{ "ModuleRelativePath", "Private/Node/GameTaskGraphNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNode_Statics::ClassParams = {
		&UGameTaskGraphNode::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphNode, 2192100924);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphNode>()
	{
		return UGameTaskGraphNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphNode(Z_Construct_UClass_UGameTaskGraphNode, &UGameTaskGraphNode::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
