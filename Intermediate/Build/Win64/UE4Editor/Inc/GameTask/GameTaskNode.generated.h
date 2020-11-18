// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskNode_generated_h
#error "GameTaskNode.generated.h already included, missing '#pragma once' in GameTaskNode.h"
#endif
#define GAMETASK_GameTaskNode_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExit); \
	DECLARE_FUNCTION(execEnter);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExit); \
	DECLARE_FUNCTION(execEnter);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_EVENT_PARMS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_CALLBACK_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTaskNode(); \
	friend struct Z_Construct_UClass_UGameTaskNode_Statics; \
public: \
	DECLARE_CLASS(UGameTaskNode, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUGameTaskNode(); \
	friend struct Z_Construct_UClass_UGameTaskNode_Statics; \
public: \
	DECLARE_CLASS(UGameTaskNode, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskNode(UGameTaskNode&&); \
	NO_API UGameTaskNode(const UGameTaskNode&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskNode(UGameTaskNode&&); \
	NO_API UGameTaskNode(const UGameTaskNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskNode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskNode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskNode)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GameTaskAsset() { return STRUCT_OFFSET(UGameTaskNode, GameTaskAsset); } \
	FORCEINLINE static uint32 __PPO__ParentNode() { return STRUCT_OFFSET(UGameTaskNode, ParentNode); }


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_13_PROLOG \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_EVENT_PARMS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h_16_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameTaskNode."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTaskNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
