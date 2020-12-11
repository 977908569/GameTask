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
	GAMETASK_API UEnum* Z_Construct_UEnum_GameTask_EItemState();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_Execute_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_Execute();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskEvent_NoRegister();
// End Cross Module References
	static UEnum* EItemState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_GameTask_EItemState, Z_Construct_UPackage__Script_GameTask(), TEXT("EItemState"));
		}
		return Singleton;
	}
	template<> GAMETASK_API UEnum* StaticEnum<EItemState>()
	{
		return EItemState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemState(EItemState_StaticEnum, TEXT("/Script/GameTask"), TEXT("EItemState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_GameTask_EItemState_Hash() { return 2550929369U; }
	UEnum* Z_Construct_UEnum_GameTask_EItemState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_GameTask();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemState"), 0, Get_Z_Construct_UEnum_GameTask_EItemState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemState::Disable", (int64)EItemState::Disable },
				{ "EItemState::Progress", (int64)EItemState::Progress },
				{ "EItemState::Finish", (int64)EItemState::Finish },
				{ "EItemState::Fail", (int64)EItemState::Fail },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \xe4\xbb\xbb\xe5\x8a\xa1\xe6\x9d\xa1\xe7\x9b\xae\xe7\x8a\xb6\xe6\x80\x81\n */" },
				{ "Disable.DisplayName", "\xe6\x9c\xaa\xe6\xbf\x80\xe6\xb4\xbb" },
				{ "Disable.Name", "EItemState::Disable" },
				{ "Fail.DisplayName", "\xe5\xa4\xb1\xe8\xb4\xa5" },
				{ "Fail.Name", "EItemState::Fail" },
				{ "Finish.DisplayName", "\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90" },
				{ "Finish.Name", "EItemState::Finish" },
				{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
				{ "Progress.DisplayName", "\xe8\xbf\x9b\xe8\xa1\x8c\xe4\xb8\xad" },
				{ "Progress.Name", "EItemState::Progress" },
				{ "ToolTip", "\xe4\xbb\xbb\xe5\x8a\xa1\xe6\x9d\xa1\xe7\x9b\xae\xe7\x8a\xb6\xe6\x80\x81" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_GameTask,
				nullptr,
				"EItemState",
				"EItemState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execGetItemState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EItemState*)Z_Param__Result=P_THIS->GetItemState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execSetItemState)
	{
		P_GET_ENUM(EItemState,Z_Param_InState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetItemState(EItemState(Z_Param_InState));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execFail)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fail();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execFinish)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Finish();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execDisable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Disable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask_Execute::execActive)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Active();
		P_NATIVE_END;
	}
	static FName NAME_UGameTask_Execute_OnActive = FName(TEXT("OnActive"));
	void UGameTask_Execute::OnActive()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTask_Execute_OnActive),NULL);
	}
	static FName NAME_UGameTask_Execute_OnDisable = FName(TEXT("OnDisable"));
	void UGameTask_Execute::OnDisable()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTask_Execute_OnDisable),NULL);
	}
	static FName NAME_UGameTask_Execute_OnFail = FName(TEXT("OnFail"));
	void UGameTask_Execute::OnFail()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTask_Execute_OnFail),NULL);
	}
	static FName NAME_UGameTask_Execute_OnFinish = FName(TEXT("OnFinish"));
	void UGameTask_Execute::OnFinish()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTask_Execute_OnFinish),NULL);
	}
	void UGameTask_Execute::StaticRegisterNativesUGameTask_Execute()
	{
		UClass* Class = UGameTask_Execute::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Active", &UGameTask_Execute::execActive },
			{ "Disable", &UGameTask_Execute::execDisable },
			{ "Fail", &UGameTask_Execute::execFail },
			{ "Finish", &UGameTask_Execute::execFinish },
			{ "GetItemState", &UGameTask_Execute::execGetItemState },
			{ "SetItemState", &UGameTask_Execute::execSetItemState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameTask_Execute_Active_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_Active_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_Active_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "Active", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_Active_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_Active_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_Active()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_Active_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_Disable_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_Disable_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_Disable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "Disable", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_Disable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_Disable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_Disable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_Disable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_Fail_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_Fail_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_Fail_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "Fail", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_Fail_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_Fail_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_Fail()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_Fail_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_Finish_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_Finish_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_Finish_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "Finish", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_Finish_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_Finish_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_Finish()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_Finish_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics
	{
		struct GameTask_Execute_eventGetItemState_Parms
		{
			EItemState ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_Execute_eventGetItemState_Parms, ReturnValue), Z_Construct_UEnum_GameTask_EItemState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "GetItemState", nullptr, nullptr, sizeof(GameTask_Execute_eventGetItemState_Parms), Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_GetItemState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_GetItemState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "OnActive", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_OnActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_OnActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "OnDisable", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_OnDisable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_OnDisable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "OnFail", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_OnFail()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_OnFail_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "OnFinish", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_OnFinish()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_OnFinish_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics
	{
		struct GameTask_Execute_eventSetItemState_Parms
		{
			EItemState InState;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InState_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::NewProp_InState = { "InState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_Execute_eventSetItemState_Parms, InState), Z_Construct_UEnum_GameTask_EItemState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::NewProp_InState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::NewProp_InState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::NewProp_InState_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\xe8\xae\xbe\xe7\xbd\xae\xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\n" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask_Execute, nullptr, "SetItemState", nullptr, nullptr, sizeof(GameTask_Execute_eventSetItemState_Parms), Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Execute_SetItemState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Execute_SetItemState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameTask_Execute_NoRegister()
	{
		return UGameTask_Execute::StaticClass();
	}
	struct Z_Construct_UClass_UGameTask_Execute_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ItemState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ItemState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FinishEvents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FinishEvents;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FinishEvents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveEvents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActiveEvents;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActiveEvents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CountDown_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CountDown;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_I18Key_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_I18Key;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTask_Execute_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameTask_Execute_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameTask_Execute_Active, "Active" }, // 2770145660
		{ &Z_Construct_UFunction_UGameTask_Execute_Disable, "Disable" }, // 837796959
		{ &Z_Construct_UFunction_UGameTask_Execute_Fail, "Fail" }, // 3261077184
		{ &Z_Construct_UFunction_UGameTask_Execute_Finish, "Finish" }, // 2140233205
		{ &Z_Construct_UFunction_UGameTask_Execute_GetItemState, "GetItemState" }, // 3507487729
		{ &Z_Construct_UFunction_UGameTask_Execute_OnActive, "OnActive" }, // 2296666029
		{ &Z_Construct_UFunction_UGameTask_Execute_OnDisable, "OnDisable" }, // 934005344
		{ &Z_Construct_UFunction_UGameTask_Execute_OnFail, "OnFail" }, // 2079905628
		{ &Z_Construct_UFunction_UGameTask_Execute_OnFinish, "OnFinish" }, // 3214459657
		{ &Z_Construct_UFunction_UGameTask_Execute_SetItemState, "SetItemState" }, // 2159292456
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \xe5\x85\xb7\xe4\xbd\x93\xe6\x89\xa7\xe8\xa1\x8c\xe8\x8a\x82\xe7\x82\xb9\n */" },
		{ "IncludePath", "GameTask_Execute.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
		{ "ToolTip", "\xe5\x85\xb7\xe4\xbd\x93\xe6\x89\xa7\xe8\xa1\x8c\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState_MetaData[] = {
		{ "Comment", "//\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\n" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState = { "ItemState", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, ItemState), Z_Construct_UEnum_GameTask_EItemState, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents = { "FinishEvents", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, FinishEvents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents_Inner = { "FinishEvents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents_MetaData[] = {
		{ "Comment", "//\n" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents = { "ActiveEvents", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, ActiveEvents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents_Inner = { "ActiveEvents", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskEvent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_CountDown_MetaData[] = {
		{ "Category", "GameTask_Execute" },
		{ "DisplayName", "\xe5\x80\x92\xe8\xae\xa1\xe6\x97\xb6 \xe5\x8d\x95\xe4\xbd\x8d\xe7\xa7\x92\xef\xbc\x8c\xe4\xb8\xba-1\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8d\xe9\x99\x90\xe6\x97\xb6" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_CountDown = { "CountDown", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, CountDown), METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_CountDown_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_CountDown_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_I18Key_MetaData[] = {
		{ "Category", "GameTask_Execute" },
		{ "DisplayName", "\xe4\xbb\xbb\xe5\x8a\xa1\xe6\x8f\x8f\xe8\xbf\xb0Key" },
		{ "ModuleRelativePath", "Public/GameTask_Execute.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_I18Key = { "I18Key", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask_Execute, I18Key), METADATA_PARAMS(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_I18Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_I18Key_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTask_Execute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ItemState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_FinishEvents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_ActiveEvents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_CountDown,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Execute_Statics::NewProp_I18Key,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTask_Execute_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTask_Execute>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTask_Execute_Statics::ClassParams = {
		&UGameTask_Execute::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameTask_Execute_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(UGameTask_Execute, 1991389097);
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
