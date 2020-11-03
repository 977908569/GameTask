// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskCompositeNode_generated_h
#error "GameTaskCompositeNode.generated.h already included, missing '#pragma once' in GameTaskCompositeNode.h"
#endif
#define GAMETASK_GameTaskCompositeNode_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGameTaskCompositeChild_Statics; \
	GAMETASK_API static class UScriptStruct* StaticStruct();


template<> GAMETASK_API UScriptStruct* StaticStruct<struct FGameTaskCompositeChild>();

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_RPC_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_RPC_WRAPPERS_NO_PURE_DECLS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTaskCompositeNode(); \
	friend struct Z_Construct_UClass_UGameTaskCompositeNode_Statics; \
public: \
	DECLARE_CLASS(UGameTaskCompositeNode, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskCompositeNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUGameTaskCompositeNode(); \
	friend struct Z_Construct_UClass_UGameTaskCompositeNode_Statics; \
public: \
	DECLARE_CLASS(UGameTaskCompositeNode, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskCompositeNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskCompositeNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskCompositeNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskCompositeNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskCompositeNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskCompositeNode(UGameTaskCompositeNode&&); \
	NO_API UGameTaskCompositeNode(const UGameTaskCompositeNode&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskCompositeNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskCompositeNode(UGameTaskCompositeNode&&); \
	NO_API UGameTaskCompositeNode(const UGameTaskCompositeNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskCompositeNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskCompositeNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskCompositeNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_25_PROLOG
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h_28_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameTaskCompositeNode."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTaskCompositeNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskCompositeNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
