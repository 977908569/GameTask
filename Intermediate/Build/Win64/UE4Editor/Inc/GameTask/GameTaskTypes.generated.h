// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMETASK_GameTaskTypes_generated_h
#error "GameTaskTypes.generated.h already included, missing '#pragma once' in GameTaskTypes.h"
#endif
#define GAMETASK_GameTaskTypes_generated_h

#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_SPARSE_DATA
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_RPC_WRAPPERS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameTaskTypes(); \
	friend struct Z_Construct_UClass_UGameTaskTypes_Statics; \
public: \
	DECLARE_CLASS(UGameTaskTypes, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskTypes)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUGameTaskTypes(); \
	friend struct Z_Construct_UClass_UGameTaskTypes_Statics; \
public: \
	DECLARE_CLASS(UGameTaskTypes, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GameTask"), NO_API) \
	DECLARE_SERIALIZER(UGameTaskTypes)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskTypes(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskTypes) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskTypes); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskTypes); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskTypes(UGameTaskTypes&&); \
	NO_API UGameTaskTypes(const UGameTaskTypes&); \
public:


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameTaskTypes(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameTaskTypes(UGameTaskTypes&&); \
	NO_API UGameTaskTypes(const UGameTaskTypes&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameTaskTypes); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameTaskTypes); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameTaskTypes)


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_PRIVATE_PROPERTY_OFFSET
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_17_PROLOG
#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_RPC_WRAPPERS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_INCLASS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_PRIVATE_PROPERTY_OFFSET \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_SPARSE_DATA \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_INCLASS_NO_PURE_DECLS \
	TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMETASK_API UClass* StaticClass<class UGameTaskTypes>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TaskProject_Plugins_GameTask_Source_GameTask_Public_GameTaskTypes_h


#define FOREACH_ENUM_GAMETASKNODESTATETYPE(op) \
	op(GameTaskNodeStateType::Disable) \
	op(GameTaskNodeStateType::Progress) \
	op(GameTaskNodeStateType::Finish) \
	op(GameTaskNodeStateType::Fail) 

enum class GameTaskNodeStateType : uint8;
template<> GAMETASK_API UEnum* StaticEnum<GameTaskNodeStateType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
