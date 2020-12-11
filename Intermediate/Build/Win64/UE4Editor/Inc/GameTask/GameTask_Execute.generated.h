// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EItemState : uint8;
#ifdef GAMETASK_GameTask_Execute_generated_h
#error "GameTask_Execute.generated.h already included, missing '#pragma once' in GameTask_Execute.h"
#endif
#define GAMETASK_GameTask_Execute_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetItemState); \
	DECLARE_FUNCTION(execSetItemState); \
	DECLARE_FUNCTION(execFail); \
	DECLARE_FUNCTION(execFinish); \
	DECLARE_FUNCTION(execDisable); \
	DECLARE_FUNCTION(execActive);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetItemState); \
	DECLARE_FUNCTION(execSetItemState); \
	DECLARE_FUNCTION(execFail); \
	DECLARE_FUNCTION(execFinish); \
	DECLARE_FUNCTION(execDisable); \
	DECLARE_FUNCTION(execActive);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_EVENT_PARMS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_CALLBACK_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTask_Execute(); \
	friend struct Z_Construct_UClass_UGameTask_Execute_Statics; \
public: \
	DECLARE_CLASS(UGameTask_Execute, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTask_Execute)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUGameTask_Execute(); \
	friend struct Z_Construct_UClass_UGameTask_Execute_Statics; \
public: \
	DECLARE_CLASS(UGameTask_Execute, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTask_Execute)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTask_Execute(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTask_Execute) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTask_Execute); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTask_Execute); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTask_Execute(UGameTask_Execute&&); \
	NO_API UGameTask_Execute(const UGameTask_Execute&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTask_Execute(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTask_Execute(UGameTask_Execute&&); \
	NO_API UGameTask_Execute(const UGameTask_Execute&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTask_Execute); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTask_Execute); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTask_Execute)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ItemState() { return STRUCT_OFFSET(UGameTask_Execute, ItemState); }


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_19_PROLOG \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_EVENT_PARMS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h_22_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameTask_Execute."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTask_Execute>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_Execute_h


#define FOREACH_ENUM_EITEMSTATE(op) \
	op(EItemState::Disable) \
	op(EItemState::Progress) \
	op(EItemState::Finish) \
	op(EItemState::Fail) 

enum class EItemState : uint8;
template<> GAMETASK_API UEnum* StaticEnum<EItemState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
