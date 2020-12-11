// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskComposite_Flow_generated_h
#error "GameTaskComposite_Flow.generated.h already included, missing '#pragma once' in GameTaskComposite_Flow.h"
#endif
#define GAMETASK_GameTaskComposite_Flow_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExit); \
	DECLARE_FUNCTION(execEnter);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExit); \
	DECLARE_FUNCTION(execEnter);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_EVENT_PARMS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_CALLBACK_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTaskComposite_Flow(); \
	friend struct Z_Construct_UClass_UGameTaskComposite_Flow_Statics; \
public: \
	DECLARE_CLASS(UGameTaskComposite_Flow, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskComposite_Flow)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_INCLASS \
private: \
	static void StaticRegisterNativesUGameTaskComposite_Flow(); \
	friend struct Z_Construct_UClass_UGameTaskComposite_Flow_Statics; \
public: \
	DECLARE_CLASS(UGameTaskComposite_Flow, UGameTaskNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskComposite_Flow)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskComposite_Flow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskComposite_Flow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskComposite_Flow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskComposite_Flow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskComposite_Flow(UGameTaskComposite_Flow&&); \
	NO_API UGameTaskComposite_Flow(const UGameTaskComposite_Flow&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskComposite_Flow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskComposite_Flow(UGameTaskComposite_Flow&&); \
	NO_API UGameTaskComposite_Flow(const UGameTaskComposite_Flow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskComposite_Flow); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskComposite_Flow); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskComposite_Flow)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_5_PROLOG \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_EVENT_PARMS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h_8_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class GameTaskComposite_Flow."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTaskComposite_Flow>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskComposite_Flow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
