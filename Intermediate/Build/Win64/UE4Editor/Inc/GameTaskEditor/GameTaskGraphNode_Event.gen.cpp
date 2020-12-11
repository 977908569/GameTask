// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/Node/GameTaskGraphNode_Event.h"
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnterEvent_MetaData[];
#endif
		static void NewProp_bEnterEvent_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnterEvent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Node/GameTaskGraphNode_Event.h" },
		{ "ModuleRelativePath", "Private/Node/GameTaskGraphNode_Event.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent_MetaData[] = {
		{ "Comment", "//\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe8\xbf\x9b\xe5\x85\xa5\xe8\xbf\x98\xe6\x98\xaf\xe9\x80\x80\xe5\x87\xba\xe4\xba\x8b\xe4\xbb\xb6\n" },
		{ "ModuleRelativePath", "Private/Node/GameTaskGraphNode_Event.h" },
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe8\xbf\x9b\xe5\x85\xa5\xe8\xbf\x98\xe6\x98\xaf\xe9\x80\x80\xe5\x87\xba\xe4\xba\x8b\xe4\xbb\xb6" },
	};
#endif
	void Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent_SetBit(void* Obj)
	{
		((UGameTaskGraphNode_Event*)Obj)->bEnterEvent = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent = { "bEnterEvent", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGameTaskGraphNode_Event), &Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::NewProp_bEnterEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskGraphNode_Event>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::ClassParams = {
		&UGameTaskGraphNode_Event::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskGraphNode_Event_Statics::PropPointers),
		0,
		0x001000A0u,
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
	IMPLEMENT_CLASS(UGameTaskGraphNode_Event, 3102532976);
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
