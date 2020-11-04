// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Graph/GameTaskGraphBase.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphBase() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphBase_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphBase();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraphBase::StaticRegisterNativesUGameTaskGraphBase()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphBase_NoRegister()
	{
		return UGameTaskGraphBase::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GraphVersion_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_GraphVersion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraph,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/GameTaskGraphBase.h" },
		{ "ModuleRelativePath", "Private/Graph/GameTaskGraphBase.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphBase_Statics::NewProp_GraphVersion_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/GameTaskGraphBase.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGameTaskGraphBase_Statics::NewProp_GraphVersion = { "GraphVersion", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskGraphBase, GraphVersion), METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphBase_Statics::NewProp_GraphVersion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphBase_Statics::NewProp_GraphVersion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskGraphBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphBase_Statics::NewProp_GraphVersion,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphBase_Statics::ClassParams = {
		&UGameTaskGraphBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskGraphBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphBase_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphBase, 4185753343);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphBase>()
	{
		return UGameTaskGraphBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphBase(Z_Construct_UClass_UGameTaskGraphBase, &UGameTaskGraphBase::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphBase);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UGameTaskGraphBase)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
