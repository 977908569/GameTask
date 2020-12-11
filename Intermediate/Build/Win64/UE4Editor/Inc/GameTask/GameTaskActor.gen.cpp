// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskActor() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_AGameTaskActor_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_AGameTaskActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GameTask();
// End Cross Module References
	DEFINE_FUNCTION(AGameTaskActor::execDoTask)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DoTask(Z_Param_InPath);
		P_NATIVE_END;
	}
	void AGameTaskActor::StaticRegisterNativesAGameTaskActor()
	{
		UClass* Class = AGameTaskActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DoTask", &AGameTaskActor::execDoTask },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGameTaskActor_DoTask_Statics
	{
		struct GameTaskActor_eventDoTask_Parms
		{
			FString InPath;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InPath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTaskActor_eventDoTask_Parms, InPath), METADATA_PARAMS(Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::NewProp_InPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::NewProp_InPath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::NewProp_InPath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameTaskActor, nullptr, "DoTask", nullptr, nullptr, sizeof(GameTaskActor_eventDoTask_Parms), Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameTaskActor_DoTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameTaskActor_DoTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGameTaskActor_NoRegister()
	{
		return AGameTaskActor::StaticClass();
	}
	struct Z_Construct_UClass_AGameTaskActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameTaskActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGameTaskActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGameTaskActor_DoTask, "DoTask" }, // 26680136
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameTaskActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "GameTaskActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GameTaskActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameTaskActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameTaskActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameTaskActor_Statics::ClassParams = {
		&AGameTaskActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGameTaskActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGameTaskActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameTaskActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameTaskActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameTaskActor, 1590722766);
	template<> GAMETASK_API UClass* StaticClass<AGameTaskActor>()
	{
		return AGameTaskActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameTaskActor(Z_Construct_UClass_AGameTaskActor, &AGameTaskActor::StaticClass, TEXT("/Script/GameTask"), TEXT("AGameTaskActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameTaskActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
