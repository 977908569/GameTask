// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskTypes() {}
// Cross Module References
	GAMETASK_API UEnum* Z_Construct_UEnum_GameTask_ENodeState();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskTypes_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskTypes();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static UEnum* ENodeState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_GameTask_ENodeState, Z_Construct_UPackage__Script_GameTask(), TEXT("ENodeState"));
		}
		return Singleton;
	}
	template<> GAMETASK_API UEnum* StaticEnum<ENodeState>()
	{
		return ENodeState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ENodeState(ENodeState_StaticEnum, TEXT("/Script/GameTask"), TEXT("ENodeState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_GameTask_ENodeState_Hash() { return 4165583879U; }
	UEnum* Z_Construct_UEnum_GameTask_ENodeState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_GameTask();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ENodeState"), 0, Get_Z_Construct_UEnum_GameTask_ENodeState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ENodeState::Normal", (int64)ENodeState::Normal },
				{ "ENodeState::InProgress", (int64)ENodeState::InProgress },
				{ "ENodeState::Succeeded", (int64)ENodeState::Succeeded },
				{ "ENodeState::Failed", (int64)ENodeState::Failed },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n *Current entry status\n */" },
				{ "Failed.Comment", "//\xe6\x88\x90\xe5\x8a\x9f\n" },
				{ "Failed.Name", "ENodeState::Failed" },
				{ "Failed.ToolTip", "\xe6\x88\x90\xe5\x8a\x9f" },
				{ "InProgress.Comment", "//\xe7\xa9\xba\xe9\x97\xb2\n" },
				{ "InProgress.Name", "ENodeState::InProgress" },
				{ "InProgress.ToolTip", "\xe7\xa9\xba\xe9\x97\xb2" },
				{ "ModuleRelativePath", "Public/GameTaskTypes.h" },
				{ "Normal.Name", "ENodeState::Normal" },
				{ "Succeeded.Comment", "//\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\xad\n" },
				{ "Succeeded.Name", "ENodeState::Succeeded" },
				{ "Succeeded.ToolTip", "\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\xad" },
				{ "ToolTip", "Current entry status" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_GameTask,
				nullptr,
				"ENodeState",
				"ENodeState",
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
	void UGameTaskTypes::StaticRegisterNativesUGameTaskTypes()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskTypes_NoRegister()
	{
		return UGameTaskTypes::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskTypes_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskTypes_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskTypes_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskTypes.h" },
		{ "ModuleRelativePath", "Public/GameTaskTypes.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskTypes_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskTypes>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskTypes_Statics::ClassParams = {
		&UGameTaskTypes::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskTypes_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskTypes_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskTypes()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskTypes_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskTypes, 1497484876);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskTypes>()
	{
		return UGameTaskTypes::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskTypes(Z_Construct_UClass_UGameTaskTypes, &UGameTaskTypes::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskTypes"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskTypes);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
