// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskCompositeNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskCompositeNode() {}
// Cross Module References
	GAMETASK_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskCompositeChild();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskExecuteNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
// End Cross Module References
class UScriptStruct* FGameTaskCompositeChild::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAMETASK_API uint32 Get_Z_Construct_UScriptStruct_FGameTaskCompositeChild_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameTaskCompositeChild, Z_Construct_UPackage__Script_GameTask(), TEXT("GameTaskCompositeChild"), sizeof(FGameTaskCompositeChild), Get_Z_Construct_UScriptStruct_FGameTaskCompositeChild_Hash());
	}
	return Singleton;
}
template<> GAMETASK_API UScriptStruct* StaticStruct<FGameTaskCompositeChild>()
{
	return FGameTaskCompositeChild::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGameTaskCompositeChild(FGameTaskCompositeChild::StaticStruct, TEXT("/Script/GameTask"), TEXT("GameTaskCompositeChild"), false, nullptr, nullptr);
static struct FScriptStruct_GameTask_StaticRegisterNativesFGameTaskCompositeChild
{
	FScriptStruct_GameTask_StaticRegisterNativesFGameTaskCompositeChild()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GameTaskCompositeChild")),new UScriptStruct::TCppStructOps<FGameTaskCompositeChild>);
	}
} ScriptStruct_GameTask_StaticRegisterNativesFGameTaskCompositeChild;
	struct Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Events_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Events;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Events_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChildExecute_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ChildExecute;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChildComposite_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ChildComposite;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameTaskCompositeChild>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events = { "Events", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskCompositeChild, Events), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events_Inner = { "Events", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildExecute_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildExecute = { "ChildExecute", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskCompositeChild, ChildExecute), Z_Construct_UClass_UGameTaskExecuteNode_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildExecute_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildExecute_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildComposite_MetaData[] = {
		{ "Comment", "/** child node */" },
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
		{ "ToolTip", "child node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildComposite = { "ChildComposite", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskCompositeChild, ChildComposite), Z_Construct_UClass_UGameTaskCompositeNode_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildComposite_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildComposite_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_Events_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildExecute,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::NewProp_ChildComposite,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
		nullptr,
		&NewStructOps,
		"GameTaskCompositeChild",
		sizeof(FGameTaskCompositeChild),
		alignof(FGameTaskCompositeChild),
		Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameTaskCompositeChild()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGameTaskCompositeChild_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GameTask();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GameTaskCompositeChild"), sizeof(FGameTaskCompositeChild), Get_Z_Construct_UScriptStruct_FGameTaskCompositeChild_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGameTaskCompositeChild_Hash() { return 2085996089U; }
	void UGameTaskCompositeNode::StaticRegisterNativesUGameTaskCompositeNode()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskCompositeNode_NoRegister()
	{
		return UGameTaskCompositeNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskCompositeNode_Statics
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Children_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Children;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Children_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskCompositeNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskCompositeNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskCompositeNode.h" },
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events = { "Events", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskCompositeNode, Events), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events_Inner = { "Events", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children_MetaData[] = {
		{ "Comment", "/** child nodes */" },
		{ "ModuleRelativePath", "Public/GameTaskCompositeNode.h" },
		{ "ToolTip", "child nodes" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children = { "Children", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskCompositeNode, Children), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children_Inner = { "Children", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameTaskCompositeChild, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskCompositeNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Events_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskCompositeNode_Statics::NewProp_Children_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskCompositeNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskCompositeNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskCompositeNode_Statics::ClassParams = {
		&UGameTaskCompositeNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskCompositeNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskCompositeNode_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskCompositeNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskCompositeNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskCompositeNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskCompositeNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskCompositeNode, 806450076);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskCompositeNode>()
	{
		return UGameTaskCompositeNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskCompositeNode(Z_Construct_UClass_UGameTaskCompositeNode, &UGameTaskCompositeNode::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskCompositeNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskCompositeNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
