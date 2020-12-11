// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTask/Public/GameTask.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTask() {}
// Cross Module References
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTask();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_GameTask();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskNode_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_AGameTaskActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEditedDocumentInfo();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph_NoRegister();
	GAMETASK_API UClass* Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UGameTask::execGetWorld)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UWorld**)Z_Param__Result=P_THIS->GetWorld();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask::execFindNode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UGameTaskNode**)Z_Param__Result=P_THIS->FindNode(Z_Param_InID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask::execGetTaskActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AGameTaskActor**)Z_Param__Result=P_THIS->GetTaskActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameTask::execStart)
	{
		P_GET_OBJECT(AGameTaskActor,Z_Param_InOwner);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Start(Z_Param_InOwner);
		P_NATIVE_END;
	}
	void UGameTask::StaticRegisterNativesUGameTask()
	{
		UClass* Class = UGameTask::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindNode", &UGameTask::execFindNode },
			{ "GetTaskActor", &UGameTask::execGetTaskActor },
			{ "GetWorld", &UGameTask::execGetWorld },
			{ "Start", &UGameTask::execStart },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameTask_FindNode_Statics
	{
		struct GameTask_eventFindNode_Parms
		{
			int32 InID;
			UGameTaskNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameTask_FindNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_eventFindNode_Parms, ReturnValue), Z_Construct_UClass_UGameTaskNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGameTask_FindNode_Statics::NewProp_InID = { "InID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_eventFindNode_Parms, InID), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_FindNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_FindNode_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_FindNode_Statics::NewProp_InID,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_FindNode_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\xe6\x9f\xa5\xe6\x89\xbe\xe8\x8a\x82\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_FindNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask, nullptr, "FindNode", nullptr, nullptr, sizeof(GameTask_eventFindNode_Parms), Z_Construct_UFunction_UGameTask_FindNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_FindNode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_FindNode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_FindNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_FindNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_FindNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_GetTaskActor_Statics
	{
		struct GameTask_eventGetTaskActor_Parms
		{
			AGameTaskActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_eventGetTaskActor_Parms, ReturnValue), Z_Construct_UClass_AGameTaskActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask, nullptr, "GetTaskActor", nullptr, nullptr, sizeof(GameTask_eventGetTaskActor_Parms), Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_GetTaskActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_GetTaskActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_GetWorld_Statics
	{
		struct GameTask_eventGetWorld_Parms
		{
			UWorld* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameTask_GetWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_eventGetWorld_Parms, ReturnValue), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_GetWorld_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_GetWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_GetWorld_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_GetWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask, nullptr, "GetWorld", nullptr, nullptr, sizeof(GameTask_eventGetWorld_Parms), Z_Construct_UFunction_UGameTask_GetWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_GetWorld_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_GetWorld_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_GetWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_GetWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_GetWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameTask_Start_Statics
	{
		struct GameTask_eventStart_Parms
		{
			AGameTaskActor* InOwner;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InOwner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameTask_Start_Statics::NewProp_InOwner = { "InOwner", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameTask_eventStart_Parms, InOwner), Z_Construct_UClass_AGameTaskActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameTask_Start_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameTask_Start_Statics::NewProp_InOwner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameTask_Start_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\xe4\xbb\xbb\xe5\x8a\xa1\xe5\xbc\x80\xe5\xa7\x8b\n" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
		{ "ToolTip", "\xe4\xbb\xbb\xe5\x8a\xa1\xe5\xbc\x80\xe5\xa7\x8b" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameTask_Start_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameTask, nullptr, "Start", nullptr, nullptr, sizeof(GameTask_eventStart_Parms), Z_Construct_UFunction_UGameTask_Start_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Start_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameTask_Start_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameTask_Start_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameTask_Start()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameTask_Start_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameTask_NoRegister()
	{
		return UGameTask::StaticClass();
	}
	struct Z_Construct_UClass_UGameTask_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastEditedDocuments_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LastEditedDocuments;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastEditedDocuments_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TaskGraph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TaskGraph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Comment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SubNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTask_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTask,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameTask_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameTask_FindNode, "FindNode" }, // 3028034169
		{ &Z_Construct_UFunction_UGameTask_GetTaskActor, "GetTaskActor" }, // 2072010370
		{ &Z_Construct_UFunction_UGameTask_GetWorld, "GetWorld" }, // 4131854955
		{ &Z_Construct_UFunction_UGameTask_Start, "Start" }, // 2432514181
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "GameTask.h" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments = { "LastEditedDocuments", nullptr, (EPropertyFlags)0x0010000800000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, LastEditedDocuments), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments_Inner = { "LastEditedDocuments", nullptr, (EPropertyFlags)0x0000000800000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FEditedDocumentInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_TaskGraph_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_TaskGraph = { "TaskGraph", nullptr, (EPropertyFlags)0x0010000800000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, TaskGraph), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_TaskGraph_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_TaskGraph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_Comment_MetaData[] = {
		{ "Category", "GameTask" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000800010001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, Comment), METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_Comment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_Comment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "GameTask" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000800010001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, Name), METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_Name_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes_MetaData[] = {
		{ "Category", "GameTask" },
		{ "Comment", "//Sub Nodes\n" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
		{ "ToolTip", "Sub Nodes" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes = { "SubNodes", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, SubNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes_Inner = { "SubNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTask_Statics::NewProp_RootNode_MetaData[] = {
		{ "Category", "GameTask" },
		{ "Comment", "//Main Node\n" },
		{ "ModuleRelativePath", "Public/GameTask.h" },
		{ "ToolTip", "Main Node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameTask_Statics::NewProp_RootNode = { "RootNode", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameTask, RootNode), Z_Construct_UClass_UGameTaskComposite_Flow_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::NewProp_RootNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::NewProp_RootNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameTask_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_LastEditedDocuments_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_TaskGraph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_Comment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_Name,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_SubNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameTask_Statics::NewProp_RootNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTask_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTask>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTask_Statics::ClassParams = {
		&UGameTask::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameTask_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTask_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTask_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTask()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTask_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTask, 3720243274);
	template<> GAMETASK_API UClass* StaticClass<UGameTask>()
	{
		return UGameTask::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTask(Z_Construct_UClass_UGameTask, &UGameTask::StaticClass, TEXT("/Script/GameTask"), TEXT("UGameTask"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTask);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
