// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWorld;
class UGameTaskNode;
class AGameTaskActor;
#ifdef GAMETASK_GameTask_generated_h
#error "GameTask.generated.h already included, missing '#pragma once' in GameTask.h"
#endif
#define GAMETASK_GameTask_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetWorld); \
	DECLARE_FUNCTION(execFindNode); \
	DECLARE_FUNCTION(execGetTaskActor); \
	DECLARE_FUNCTION(execStart);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetWorld); \
	DECLARE_FUNCTION(execFindNode); \
	DECLARE_FUNCTION(execGetTaskActor); \
	DECLARE_FUNCTION(execStart);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTask(); \
	friend struct Z_Construct_UClass_UGameTask_Statics; \
public: \
	DECLARE_CLASS(UGameTask, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTask)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_INCLASS \
private: \
	static void StaticRegisterNativesUGameTask(); \
	friend struct Z_Construct_UClass_UGameTask_Statics; \
public: \
	DECLARE_CLASS(UGameTask, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTask)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTask(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTask) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTask); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTask); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTask(UGameTask&&); \
	NO_API UGameTask(const UGameTask&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTask(UGameTask&&); \
	NO_API UGameTask(const UGameTask&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTask); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTask); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameTask)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_5_PROLOG
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h_8_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTask>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTask_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
