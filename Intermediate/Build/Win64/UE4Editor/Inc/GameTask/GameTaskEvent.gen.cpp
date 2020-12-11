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
	static FName NAME_UGameTaskEvent_OnTrigger = FName(TEXT("OnTrigger"));
	bool UGameTaskEvent::OnTrigger()
	{
		GameTaskEvent_eventOnTrigger_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UGameTaskEvent_OnTrigger),&Parms);
		return !!Parms.ReturnValue;
	}
	void UGameTaskEvent::StaticRegisterNativesUGameTaskEvent()
	{
	}
	struct Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GameTaskEvent_eventOnTrigger_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GameTaskEvent_eventOnTrigger_Parms), &Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskEvent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskEvent, nullptr, "OnTrigger", nullptr, nullptr, sizeof(GameTaskEvent_eventOnTrigger_Parms), Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskEvent_OnTrigger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskEvent_OnTrigger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister()
	{
		return UGameTaskEvent::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskEvent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskEvent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskAuxiliaryNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameTaskEvent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameTaskEvent_OnTrigger, "OnTrigger" }, // 1941192682
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEvent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Task Event Node\n */" },
		{ "IncludePath", "GameTaskEvent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GameTaskEvent.h" },
		{ "ToolTip", "Task Event Node" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskEvent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskEvent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskEvent_Statics::ClassParams = {
		&UGameTaskEvent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
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
	IMPLEMENT_CLASS(UGameTaskEvent, 2659045735);
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
