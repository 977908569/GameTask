// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskEvent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskEvent() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskAuxiliaryNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
// End Cross Module References
	void UGameTaskEvent::StaticRegisterNativesUGameTaskEvent()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister()
	{
		return UGameTaskEvent::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskEvent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTest_MetaData[];
#endif
		static void NewProp_bTest_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTest;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskEvent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskAuxiliaryNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEvent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Task Event Node\n */" },
		{ "IncludePath", "GameTaskEvent.h" },
		{ "ModuleRelativePath", "Public/GameTaskEvent.h" },
		{ "ToolTip", "Task Event Node" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest_MetaData[] = {
		{ "Category", "GameTaskEvent" },
		{ "ModuleRelativePath", "Public/GameTaskEvent.h" },
	};
#endif
	void Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest_SetBit(void* Obj)
	{
		((UGameTaskEvent*)Obj)->bTest = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest = { "bTest", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGameTaskEvent), &Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskEvent_Statics::NewProp_bTest,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskEvent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskEvent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskEvent_Statics::ClassParams = {
		&UGameTaskEvent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskEvent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEvent_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskEvent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEvent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskEvent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskEvent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskEvent, 563275295);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskEvent>()
	{
		return UGameTaskEvent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskEvent(Z_Construct_UClass_UGameTaskEvent, &UGameTaskEvent::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskEvent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskEvent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
