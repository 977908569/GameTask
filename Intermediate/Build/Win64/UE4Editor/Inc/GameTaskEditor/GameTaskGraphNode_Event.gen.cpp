// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskGraphNode_Event.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskGraphNode_Event() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Event_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode_Event();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskGraphNode_Event::StaticRegisterNativesUGameTaskGraphNode_Event()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Event_NoRegister()
	{
		return UGameTaskGraphNode_Event::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskGraphNode_Event_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskGraphNode_Event.h" },
		{ "ModuleRelativePath", "Private/GameTaskGraphNode_Event.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNode_Event>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::ClassParams = {
		&UGameTaskGraphNode_Event::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskGraphNode_Event()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskGraphNode_Event, 555456893);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskGraphNode_Event>()
	{
		return UGameTaskGraphNode_Event::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskGraphNode_Event(Z_Construct_UClass_UGameTaskGraphNode_Event, &UGameTaskGraphNode_Event::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskGraphNode_Event"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskGraphNode_Event);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
