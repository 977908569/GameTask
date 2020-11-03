// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameTaskEditor/Private/GameTaskEditorGraphSchema.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTaskEditorGraphSchema() {}
// Cross Module References
	GAMETASKEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode();
	UPackage* Z_Construct_UPackage__Script_GameTaskEditor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEdGraphSchemaAction();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister();
	GAMETASKEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode();
	GAMETASKEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorGraphSchemaBase();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorGraphSchema_NoRegister();
	GAMETASKEDITOR_API UClass* Z_Construct_UClass_UGameTaskEditorGraphSchema();
// End Cross Module References
class UScriptStruct* FGameTaskSchemaAction_NewSubNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAMETASKEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode, Z_Construct_UPackage__Script_GameTaskEditor(), TEXT("GameTaskSchemaAction_NewSubNode"), sizeof(FGameTaskSchemaAction_NewSubNode), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Hash());
	}
	return Singleton;
}
template<> GAMETASKEDITOR_API UScriptStruct* StaticStruct<FGameTaskSchemaAction_NewSubNode>()
{
	return FGameTaskSchemaAction_NewSubNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGameTaskSchemaAction_NewSubNode(FGameTaskSchemaAction_NewSubNode::StaticStruct, TEXT("/Script/GameTaskEditor"), TEXT("GameTaskSchemaAction_NewSubNode"), false, nullptr, nullptr);
static struct FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewSubNode
{
	FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewSubNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GameTaskSchemaAction_NewSubNode")),new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_NewSubNode>);
	}
} ScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewSubNode;
	struct Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NodeTemplate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Action to add a subnode to the selected node */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
		{ "ToolTip", "Action to add a subnode to the selected node" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_NewSubNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_ParentNode_MetaData[] = {
		{ "Comment", "/** parent node */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
		{ "ToolTip", "parent node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskSchemaAction_NewSubNode, ParentNode), Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_ParentNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_ParentNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_NodeTemplate_MetaData[] = {
		{ "Comment", "/** Template of node we want to create */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
		{ "ToolTip", "Template of node we want to create" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_NodeTemplate = { "NodeTemplate", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskSchemaAction_NewSubNode, NodeTemplate), Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_NodeTemplate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_NodeTemplate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_ParentNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::NewProp_NodeTemplate,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"GameTaskSchemaAction_NewSubNode",
		sizeof(FGameTaskSchemaAction_NewSubNode),
		alignof(FGameTaskSchemaAction_NewSubNode),
		Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GameTaskEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GameTaskSchemaAction_NewSubNode"), sizeof(FGameTaskSchemaAction_NewSubNode), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewSubNode_Hash() { return 197762950U; }
class UScriptStruct* FGameTaskSchemaAction_NewNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAMETASKEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode, Z_Construct_UPackage__Script_GameTaskEditor(), TEXT("GameTaskSchemaAction_NewNode"), sizeof(FGameTaskSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Hash());
	}
	return Singleton;
}
template<> GAMETASKEDITOR_API UScriptStruct* StaticStruct<FGameTaskSchemaAction_NewNode>()
{
	return FGameTaskSchemaAction_NewNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGameTaskSchemaAction_NewNode(FGameTaskSchemaAction_NewNode::StaticStruct, TEXT("/Script/GameTaskEditor"), TEXT("GameTaskSchemaAction_NewNode"), false, nullptr, nullptr);
static struct FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewNode
{
	FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GameTaskSchemaAction_NewNode")),new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_NewNode>);
	}
} ScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_NewNode;
	struct Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NodeTemplate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Action to add a node to the graph */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
		{ "ToolTip", "Action to add a node to the graph" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_NewNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewProp_NodeTemplate_MetaData[] = {
		{ "Comment", "/** Template of node we want to create */" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
		{ "ToolTip", "Template of node we want to create" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewProp_NodeTemplate = { "NodeTemplate", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameTaskSchemaAction_NewNode, NodeTemplate), Z_Construct_UClass_UGameTaskGraphNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewProp_NodeTemplate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewProp_NodeTemplate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::NewProp_NodeTemplate,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"GameTaskSchemaAction_NewNode",
		sizeof(FGameTaskSchemaAction_NewNode),
		alignof(FGameTaskSchemaAction_NewNode),
		Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GameTaskEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GameTaskSchemaAction_NewNode"), sizeof(FGameTaskSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_NewNode_Hash() { return 2422528956U; }
class UScriptStruct* FGameTaskSchemaAction_AddComment::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAMETASKEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment, Z_Construct_UPackage__Script_GameTaskEditor(), TEXT("GameTaskSchemaAction_AddComment"), sizeof(FGameTaskSchemaAction_AddComment), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Hash());
	}
	return Singleton;
}
template<> GAMETASKEDITOR_API UScriptStruct* StaticStruct<FGameTaskSchemaAction_AddComment>()
{
	return FGameTaskSchemaAction_AddComment::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGameTaskSchemaAction_AddComment(FGameTaskSchemaAction_AddComment::StaticStruct, TEXT("/Script/GameTaskEditor"), TEXT("GameTaskSchemaAction_AddComment"), false, nullptr, nullptr);
static struct FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_AddComment
{
	FScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_AddComment()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GameTaskSchemaAction_AddComment")),new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_AddComment>);
	}
} ScriptStruct_GameTaskEditor_StaticRegisterNativesFGameTaskSchemaAction_AddComment;
	struct Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameTaskSchemaAction_AddComment>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"GameTaskSchemaAction_AddComment",
		sizeof(FGameTaskSchemaAction_AddComment),
		alignof(FGameTaskSchemaAction_AddComment),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GameTaskEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GameTaskSchemaAction_AddComment"), sizeof(FGameTaskSchemaAction_AddComment), Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGameTaskSchemaAction_AddComment_Hash() { return 685875647U; }
	void UGameTaskEditorGraphSchemaBase::StaticRegisterNativesUGameTaskEditorGraphSchemaBase()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_NoRegister()
	{
		return UGameTaskEditorGraphSchemaBase::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskEditorGraphSchema.h" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskEditorGraphSchemaBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::ClassParams = {
		&UGameTaskEditorGraphSchemaBase::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskEditorGraphSchemaBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskEditorGraphSchemaBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskEditorGraphSchemaBase, 2150464936);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskEditorGraphSchemaBase>()
	{
		return UGameTaskEditorGraphSchemaBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskEditorGraphSchemaBase(Z_Construct_UClass_UGameTaskEditorGraphSchemaBase, &UGameTaskEditorGraphSchemaBase::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskEditorGraphSchemaBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskEditorGraphSchemaBase);
	void UGameTaskEditorGraphSchema::StaticRegisterNativesUGameTaskEditorGraphSchema()
	{
	}
	UClass* Z_Construct_UClass_UGameTaskEditorGraphSchema_NoRegister()
	{
		return UGameTaskEditorGraphSchema::StaticClass();
	}
	struct Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameTaskEditorGraphSchemaBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameTaskEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameTaskEditorGraphSchema.h" },
		{ "ModuleRelativePath", "Private/GameTaskEditorGraphSchema.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameTaskEditorGraphSchema>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::ClassParams = {
		&UGameTaskEditorGraphSchema::StaticClass,
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
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameTaskEditorGraphSchema()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameTaskEditorGraphSchema_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameTaskEditorGraphSchema, 457799452);
	template<> GAMETASKEDITOR_API UClass* StaticClass<UGameTaskEditorGraphSchema>()
	{
		return UGameTaskEditorGraphSchema::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameTaskEditorGraphSchema(Z_Construct_UClass_UGameTaskEditorGraphSchema, &UGameTaskEditorGraphSchema::StaticClass, TEXT("/Script/GameTaskEditor"), TEXT("UGameTaskEditorGraphSchema"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameTaskEditorGraphSchema);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
