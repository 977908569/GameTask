// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Graph/GameTaskGraph.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraph() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraph_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraph();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphBase();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraph::StaticRegisterNativesUGameTaskGraph()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraph_NoRegister()
	{
		return UGameTaskGraph::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraph_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraph_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraph_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/GameTaskGraph.h" },
		{ "ModuleRelativePath", "Private/Graph/GameTaskGraph.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraph_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraph>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraph_Statics::ClassParams = {
		&UGameTaskGraph::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraph_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraph_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraph()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraph_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraph, 3174933371);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraph>()
	{
		return UGameTaskGraph::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraph(Z_Construct_UClass_UGameTaskGraph, &UGameTaskGraph::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraph"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraph);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
