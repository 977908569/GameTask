// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskComposite_Sequence.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskComposite_Sequence() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskComposite_Sequence_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskComposite_Sequence();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
// End Cross Module References
	void UGameTaskComposite_Sequence::StaticRegisterNativesUGameTaskComposite_Sequence()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskComposite_Sequence_NoRegister()
	{
		return UGameTaskComposite_Sequence::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskComposite_Sequence_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskComposite_Sequence.h" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Sequence.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskComposite_Sequence>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::ClassParams = {
		&UGameTaskComposite_Sequence::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskComposite_Sequence()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskComposite_Sequence_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskComposite_Sequence, 1894208102);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskComposite_Sequence>()
	{
		return UGameTaskComposite_Sequence::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskComposite_Sequence(Z_Construct_UClass_UGameTaskComposite_Sequence, &UGameTaskComposite_Sequence::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskComposite_Sequence"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskComposite_Sequence);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
