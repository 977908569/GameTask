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
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UGameTaskComposite_Flow::execExit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Exit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTaskComposite_Flow::execEnter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Enter();
		P_NATIVE_END;
	}
	static FName NAME_UGameTaskComposite_Flow_OnEnter = FName(TEXT("OnEnter"));
	void UGameTaskComposite_Flow::OnEnter()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTaskComposite_Flow_OnEnter),NULL);
	}
	static FName NAME_UGameTaskComposite_Flow_OnExit = FName(TEXT("OnExit"));
	void UGameTaskComposite_Flow::OnExit()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTaskComposite_Flow_OnExit),NULL);
	}
	void UGameTaskComposite_Flow::StaticRegisterNativesUGameTaskComposite_Flow()
	{
		UClass* Class = UGameTaskComposite_Flow::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Enter", &UGameTaskComposite_Flow::execEnter },
			{ "Exit", &UGameTaskComposite_Flow::execExit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\xe8\xbf\x9b\xe5\x85\xa5\xe8\x8a\x82\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
		{ "ToolTip", "\xe8\xbf\x9b\xe5\x85\xa5\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskComposite_Flow, nullptr, "Enter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskComposite_Flow_Enter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskComposite_Flow_Enter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\xe9\x80\x80\xe5\x87\xba\xe8\x8a\x82\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
		{ "ToolTip", "\xe9\x80\x80\xe5\x87\xba\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskComposite_Flow, nullptr, "Exit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskComposite_Flow_Exit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskComposite_Flow_Exit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskComposite_Flow, nullptr, "OnEnter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskComposite_Flow, nullptr, "OnExit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister()
	{
		return UGameTaskComposite_Flow::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskComposite_Flow_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameTaskComposite_Flow_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameTaskComposite_Flow_Enter, "Enter" }, // 2135939658
		{ &Z_Construct_UFunction_UGameTaskComposite_Flow_Exit, "Exit" }, // 1605679217
		{ &Z_Construct_UFunction_UGameTaskComposite_Flow_OnEnter, "OnEnter" }, // 3188020171
		{ &Z_Construct_UFunction_UGameTaskComposite_Flow_OnExit, "OnExit" }, // 546256944
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "GameTaskComposite_Flow.h" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData[] = {
		{ "Category", "GameTaskComposite_Flow" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next = { "Next", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskComposite_Flow, Next), Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_Next_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData[] = {
		{ "Category", "GameTaskComposite_Flow" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents = { "ExitEvents", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskComposite_Flow, ExitEvents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_ExitEvents_Inner = { "ExitEvents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskComposite_Flow_Statics::NewProp_EnterEvents_MetaData[] = {
		{ "Category", "GameTaskComposite_Flow" },
		{ "ModuleRelativePath", "Public/GameTaskComposite_Flow.h" },
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
		FuncInfo,
		Z_Construct_UClass_UGameTaskComposite_Flow_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(UGameTaskComposite_Flow, 2085571688);
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
