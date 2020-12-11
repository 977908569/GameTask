// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskActor_generated_h
#error "GameTaskActor.generated.h already included, missing '#pragma once' in GameTaskActor.h"
#endif
#define GAMETASK_GameTaskActor_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDoTask);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDoTask);


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameTaskActor(); \
	friend struct Z_Construct_UClass_AGameTaskActor_Statics; \
public: \
	DECLARE_CLASS(AGameTaskActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(AGameTaskActor)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_INCLASS \
private: \
	static void StaticRegisterNativesAGameTaskActor(); \
	friend struct Z_Construct_UClass_AGameTaskActor_Statics; \
public: \
	DECLARE_CLASS(AGameTaskActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(AGameTaskActor)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameTaskActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameTaskActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameTaskActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameTaskActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameTaskActor(AGameTaskActor&&); \
	NO_API AGameTaskActor(const AGameTaskActor&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameTaskActor(AGameTaskActor&&); \
	NO_API AGameTaskActor(const AGameTaskActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameTaskActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameTaskActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameTaskActor)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_4_PROLOG
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h_7_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class AGameTaskActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
