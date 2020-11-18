// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTask_Execute.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTask_Execute() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_Execute_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_Execute();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
// End Cross Module References
	void UGameTask_Execute::StaticRegisterNativesUGameTask_Execute()
	{
	}
	UClass* Z_Construct_UClass_UGameTask_Execute_NoRegister()
	{
		return UGameTask_Execute::StaticClass();
	}
	struct Z_Construct_UClass_UGameTask_Execute_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Events_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Events;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Events_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTask_Execute_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTask_Execute.h" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events_MetaData[] = {
		{ "Comment", "/**\n\x09 * Active Events\n\x09 */" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
		{ "ToolTip", "Active Events" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events = { "Events", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, Events), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events_Inner = { "Events", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTask_Execute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_Events_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTask_Execute_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTask_Execute>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTask_Execute_Statics::ClassParams = {
		&UGameTask_Execute::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTask_Execute_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTask_Execute()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTask_Execute_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTask_Execute, 3112642061);
	template<> GAMETASK_API UClass* StaticClass<UGameTask_Execute>()
	{
		return UGameTask_Execute::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTask_Execute(Z_Construct_UClass_UGameTask_Execute, &UGameTask_Execute::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTask_Execute"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTask_Execute);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
