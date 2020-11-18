// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskComposite_Flow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskComposite_Flow() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskComposite_Flow();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
// End Cross Module References
	void UGameTaskComposite_Flow::StaticRegisterNativesUGameTaskComposite_Flow()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister()
	{
		return UGameTaskComposite_Flow::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskComposite_Flow_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Next_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Next;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExitEvents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ExitEvents;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExitEvents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnterEvents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_EnterEvents;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnterEvents_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskComposite_Flow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskCompositeNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Flow\n */" },
		{ "IncludePath", "GameTaskComposite_Flow.h" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
		{ "ToolTip", "Flow" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next = { "Next", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskComposite_Flow, Next), Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData[] = {
		{ "Category", "GameTaskComposite_Flow" },
		{ "Comment", "/**\n\x09 * Exit Node Event\n\x09 */" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
		{ "ToolTip", "Exit Node Event" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents = { "ExitEvents", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskComposite_Flow, ExitEvents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_Inner = { "ExitEvents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_MetaData[] = {
		{ "Category", "GameTaskComposite_Flow" },
		{ "Comment", "/**\n\x09\x09 * Enter Node Events\n\x09\x09 */" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
		{ "ToolTip", "Enter Node Events" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents = { "EnterEvents", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskComposite_Flow, EnterEvents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_Inner = { "EnterEvents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskComposite_Flow_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskComposite_Flow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskComposite_Flow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::ClassParams = {
		&UGameTaskComposite_Flow::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskComposite_Flow_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskComposite_Flow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskComposite_Flow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskComposite_Flow, 411838304);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskComposite_Flow>()
	{
		return UGameTaskComposite_Flow::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskComposite_Flow(Z_Construct_UClass_UGameTaskComposite_Flow, &UGameTaskComposite_Flow::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskComposite_Flow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskComposite_Flow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
