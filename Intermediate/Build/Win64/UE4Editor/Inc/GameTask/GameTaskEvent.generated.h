// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskEvent_generated_h
#error "GameTaskEvent.generated.h already included, missing '#pragma once' in GameTaskEvent.h"
#endif
#define GAMETASK_GameTaskEvent_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_RPC_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_EVENT_PARMS \
	struct GameTaskEvent_eventOnTrigger_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		GameTaskEvent_eventOnTrigger_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_CALLBACK_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTaskEvent(); \
	friend struct Z_Construct_UClass_UGameTaskEvent_Statics; \
public: \
	DECLARE_CLASS(UGameTaskEvent, UGameTaskAuxiliaryNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskEvent)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUGameTaskEvent(); \
	friend struct Z_Construct_UClass_UGameTaskEvent_Statics; \
public: \
	DECLARE_CLASS(UGameTaskEvent, UGameTaskAuxiliaryNode, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskEvent)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskEvent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskEvent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskEvent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskEvent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskEvent(UGameTaskEvent&&); \
	NO_API UGameTaskEvent(const UGameTaskEvent&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskEvent(UGameTaskEvent&&); \
	NO_API UGameTaskEvent(const UGameTaskEvent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskEvent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskEvent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameTaskEvent)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_8_PROLOG \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_EVENT_PARMS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_CALLBACK_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTaskEvent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskEvent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
