// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef MANAGEMENTGAME_BoxMechanics_generated_h
#error "BoxMechanics.generated.h already included, missing '#pragma once' in BoxMechanics.h"
#endif
#define MANAGEMENTGAME_BoxMechanics_generated_h

#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBreakItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BreakItem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBreakItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BreakItem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBoxMechanics(); \
	friend MANAGEMENTGAME_API class UClass* Z_Construct_UClass_UBoxMechanics(); \
public: \
	DECLARE_CLASS(UBoxMechanics, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ManagementGame"), NO_API) \
	DECLARE_SERIALIZER(UBoxMechanics) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUBoxMechanics(); \
	friend MANAGEMENTGAME_API class UClass* Z_Construct_UClass_UBoxMechanics(); \
public: \
	DECLARE_CLASS(UBoxMechanics, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ManagementGame"), NO_API) \
	DECLARE_SERIALIZER(UBoxMechanics) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBoxMechanics(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBoxMechanics) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBoxMechanics); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBoxMechanics); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBoxMechanics(UBoxMechanics&&); \
	NO_API UBoxMechanics(const UBoxMechanics&); \
public:


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBoxMechanics(UBoxMechanics&&); \
	NO_API UBoxMechanics(const UBoxMechanics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBoxMechanics); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBoxMechanics); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBoxMechanics)


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_PRIVATE_PROPERTY_OFFSET
#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_12_PROLOG
#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_PRIVATE_PROPERTY_OFFSET \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_RPC_WRAPPERS \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_INCLASS \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_PRIVATE_PROPERTY_OFFSET \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_INCLASS_NO_PURE_DECLS \
	DD_YY_MM_Source_ManagementGame_BoxMechanics_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DD_YY_MM_Source_ManagementGame_BoxMechanics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
