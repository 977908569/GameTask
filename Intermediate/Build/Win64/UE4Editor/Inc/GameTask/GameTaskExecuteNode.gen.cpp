// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskExecuteNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskExecuteNode() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskExecuteNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskExecuteNode();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
// End Cross Module References
	void UGameTaskExecuteNode::StaticRegisterNativesUGameTaskExecuteNode()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskExecuteNode_NoRegister()
	{
		return UGameTaskExecuteNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskExecuteNode_Statics
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
	UObject* (*const Z_Construct_UClass_UGameTaskExecuteNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskExecuteNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskExecuteNode.h" },
		{ "ModuleRelativePath", "Public/GameTaskExecuteNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTaskExecuteNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events = { "Events", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskExecuteNode, Events), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events_Inner = { "Events", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskExecuteNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskExecuteNode_Statics::NewProp_Events_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskExecuteNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskExecuteNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskExecuteNode_Statics::ClassParams = {
		&UGameTaskExecuteNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskExecuteNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskExecuteNode_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskExecuteNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskExecuteNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskExecuteNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskExecuteNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskExecuteNode, 1983256049);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskExecuteNode>()
	{
		return UGameTaskExecuteNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskExecuteNode(Z_Construct_UClass_UGameTaskExecuteNode, &UGameTaskExecuteNode::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskExecuteNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskExecuteNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
