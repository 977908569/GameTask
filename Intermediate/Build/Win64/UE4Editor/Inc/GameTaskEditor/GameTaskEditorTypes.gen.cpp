// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskEditorTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskEditorTypes() {}
// Cross Module References
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorTypes_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorTypes();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
// End Cross Module References
	void UGameTaskEditorTypes::StaticRegisterNativesUGameTaskEditorTypes()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskEditorTypes_NoRegister()
	{
		return UGameTaskEditorTypes::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskEditorTypes_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskEditorTypes_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEditorTypes_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskEditorTypes.h" },
		{ "ModuleRelativePath", "Private/GameTaskEditorTypes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskEditorTypes_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskEditorTypes>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskEditorTypes_Statics::ClassParams = {
		&UGameTaskEditorTypes::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskEditorTypes_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEditorTypes_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskEditorTypes()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskEditorTypes_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskEditorTypes, 1511755034);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskEditorTypes>()
	{
		return UGameTaskEditorTypes::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskEditorTypes(Z_Construct_UClass_UGameTaskEditorTypes, &UGameTaskEditorTypes::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskEditorTypes"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskEditorTypes);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
