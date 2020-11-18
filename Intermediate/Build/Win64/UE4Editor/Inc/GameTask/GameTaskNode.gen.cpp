// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTaskNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskNode() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskCompositeNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UGameTaskNode::execExit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Exit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTaskNode::execEnter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Enter();
		P_NATIVE_END;
	}
	static FName NAME_UGameTaskNode_OnEnter = FName(TEXT("OnEnter"));
	void UGameTaskNode::OnEnter()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTaskNode_OnEnter),NULL);
	}
	static FName NAME_UGameTaskNode_OnExit = FName(TEXT("OnExit"));
	void UGameTaskNode::OnExit()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameTaskNode_OnExit),NULL);
	}
	void UGameTaskNode::StaticRegisterNativesUGameTaskNode()
	{
		UClass* Class = UGameTaskNode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Enter", &UGameTaskNode::execEnter },
			{ "Exit", &UGameTaskNode::execExit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameTaskNode_Enter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskNode_Enter_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * Enter the node\n\x09 */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "Enter the node" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskNode_Enter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskNode, nullptr, "Enter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskNode_Enter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskNode_Enter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskNode_Enter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskNode_Enter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskNode_Exit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskNode_Exit_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * Exit the node\n\x09 */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "Exit the node" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskNode_Exit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskNode, nullptr, "Exit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskNode_Exit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskNode_Exit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskNode_Exit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskNode_Exit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskNode, nullptr, "OnEnter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskNode_OnEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskNode_OnEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTaskNode_OnExit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTaskNode_OnExit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTaskNode_OnExit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTaskNode, nullptr, "OnExit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTaskNode_OnExit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTaskNode_OnExit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTaskNode_OnExit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTaskNode_OnExit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameTaskNode_NoRegister()
	{
		return UGameTaskNode::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameTaskAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameTaskAsset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NodeName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameTaskNode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameTaskNode_Enter, "Enter" }, // 4076880828
		{ &Z_Construct_UFunction_UGameTaskNode_Exit, "Exit" }, // 327346380
		{ &Z_Construct_UFunction_UGameTaskNode_OnEnter, "OnEnter" }, // 4158383723
		{ &Z_Construct_UFunction_UGameTaskNode_OnExit, "OnExit" }, // 2651225666
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Task Node\n */" },
		{ "IncludePath", "GameTaskNode.h" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "Task Node" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData[] = {
		{ "Comment", "/** parent node */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "parent node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, ParentNode), Z_Construct_UClass_UGameTaskCompositeNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData[] = {
		{ "Comment", "/** source asset */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "source asset" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset = { "GameTaskAsset", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, GameTaskAsset), Z_Construct_UClass_UGameTask_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData[] = {
		{ "Category", "Description" },
		{ "Comment", "/** node name */" },
		{ "ModuleRelativePath", "Public/GameTaskNode.h" },
		{ "ToolTip", "node name" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTaskNode, NodeName), METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTaskNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_ParentNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_GameTaskAsset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTaskNode_Statics::NewProp_NodeName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskNode_Statics::ClassParams = {
		&UGameTaskNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameTaskNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskNode, 4171802528);
	template<> GAMETASK_API UClass* StaticClass<UGameTaskNode>()
	{
		return UGameTaskNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskNode(Z_Construct_UClass_UGameTaskNode, &UGameTaskNode::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTaskNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
