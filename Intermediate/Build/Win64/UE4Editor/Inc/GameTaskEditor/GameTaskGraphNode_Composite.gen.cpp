// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Node/GameTaskGraphNode_Composite.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphNode_Composite() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Composite_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Composite();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraphNode_Composite::StaticRegisterNativesUGameTaskGraphNode_Composite()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Composite_NoRegister()
	{
		return UGameTaskGraphNode_Composite::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Node/GameTaskGraphNode_Composite.h" },
		{ "ModuleRelativePath", "Private/Node/GameTaskGraphNode_Composite.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNode_Composite>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::ClassParams = {
		&UGameTaskGraphNode_Composite::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Composite()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphNode_Composite_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphNode_Composite, 3452042137);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphNode_Composite>()
	{
		return UGameTaskGraphNode_Composite::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphNode_Composite(Z_Construct_UClass_UGameTaskGraphNode_Composite, &UGameTaskGraphNode_Composite::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphNode_Composite"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphNode_Composite);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
