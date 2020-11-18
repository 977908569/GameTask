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
	GAMETASK_API UEnum* Z_Construct_UEnum_GameTask_GameTaskNodeStateType();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskTypes_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskTypes();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static UEnum* GameTaskNodeStateType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_GameTask_GameTaskNodeStateType, Z_Construct_UPackage__Script_GameTask(), TEXT("GameTaskNodeStateType"));
		}
		return Singleton;
	}
	template<> GAMETASK_API UEnum* StaticEnum<GameTaskNodeStateType>()
	{
		return GameTaskNodeStateType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_GameTaskNodeStateType(GameTaskNodeStateType_StaticEnum, TEXT("/Script/GameTask"), TEXT("GameTaskNodeStateType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_GameTask_GameTaskNodeStateType_Hash() { return 4218431446U; }
	UEnum* Z_Construct_UEnum_GameTask_GameTaskNodeStateType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_GameTask();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("GameTaskNodeStateType"), 0, Get_Z_Construct_UEnum_GameTask_GameTaskNodeStateType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "GameTaskNodeStateType::Disable", (int64)GameTaskNodeStateType::Disable },
				{ "GameTaskNodeStateType::Progress", (int64)GameTaskNodeStateType::Progress },
				{ "GameTaskNodeStateType::Finish", (int64)GameTaskNodeStateType::Finish },
				{ "GameTaskNodeStateType::Fail", (int64)GameTaskNodeStateType::Fail },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n *Current entry status\n */" },
				{ "Disable.Name", "GameTaskNodeStateType::Disable" },
				{ "Fail.Name", "GameTaskNodeStateType::Fail" },
				{ "Finish.Name", "GameTaskNodeStateType::Finish" },
				{ "ModuleRelativePath", "Public/GameTaskTypes.h" },
				{ "Progress.Name", "GameTaskNodeStateType::Progress" },
				{ "ToolTip", "Current entry status" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_GameTask,
				nullptr,
				"GameTaskNodeStateType",
				"GameTaskNodeStateType",
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
