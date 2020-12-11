// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Node/GameTaskGraphNode_Parallel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphNode_Parallel() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Parallel_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Parallel();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraphNode_Parallel::StaticRegisterNativesUGameTaskGraphNode_Parallel()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Parallel_NoRegister()
	{
		return UGameTaskGraphNode_Parallel::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Node/GameTaskGraphNode_Parallel.h" },
		{ "ModuleRelativePath", "Private/Node/GameTaskGraphNode_Parallel.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNode_Parallel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::ClassParams = {
		&UGameTaskGraphNode_Parallel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Parallel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphNode_Parallel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphNode_Parallel, 1582268769);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphNode_Parallel>()
	{
		return UGameTaskGraphNode_Parallel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphNode_Parallel(Z_Construct_UClass_UGameTaskGraphNode_Parallel, &UGameTaskGraphNode_Parallel::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphNode_Parallel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphNode_Parallel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
