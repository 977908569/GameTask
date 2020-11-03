// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskComposite_Parallel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskComposite_Parallel() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskComposite_Parallel_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskComposite_Parallel();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskComposite_Parallel::StaticRegisterNativesUGameTaskComposite_Parallel()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskComposite_Parallel_NoRegister()
	{
		return UGameTaskComposite_Parallel::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskComposite_Parallel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskCompositeNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Composite" },
		{ "IncludePath", "GameTaskComposite_Parallel.h" },
		{ "ModuleRelativePath", "Private/GameTaskComposite_Parallel.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskComposite_Parallel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::ClassParams = {
		&UGameTaskComposite_Parallel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskComposite_Parallel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskComposite_Parallel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskComposite_Parallel, 1947584595);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskComposite_Parallel>()
	{
		return UGameTaskComposite_Parallel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskComposite_Parallel(Z_Construct_UClass_UGameTaskComposite_Parallel, &UGameTaskComposite_Parallel::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskComposite_Parallel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskComposite_Parallel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
