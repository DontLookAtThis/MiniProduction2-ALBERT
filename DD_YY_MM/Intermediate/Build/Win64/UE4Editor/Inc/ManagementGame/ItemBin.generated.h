// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MANAGEMENTGAME_ItemBin_generated_h
#error "ItemBin.generated.h already included, missing '#pragma once' in ItemBin.h"
#endif
#define MANAGEMENTGAME_ItemBin_generated_h

#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_RPC_WRAPPERS
#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemBin(); \
	friend MANAGEMENTGAME_API class UClass* Z_Construct_UClass_UItemBin(); \
public: \
	DECLARE_CLASS(UItemBin, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ManagementGame"), NO_API) \
	DECLARE_SERIALIZER(UItemBin) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUItemBin(); \
	friend MANAGEMENTGAME_API class UClass* Z_Construct_UClass_UItemBin(); \
public: \
	DECLARE_CLASS(UItemBin, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ManagementGame"), NO_API) \
	DECLARE_SERIALIZER(UItemBin) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UItemBin(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemBin) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemBin); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemBin); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UItemBin(UItemBin&&); \
	NO_API UItemBin(const UItemBin&); \
public:


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UItemBin(UItemBin&&); \
	NO_API UItemBin(const UItemBin&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemBin); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemBin); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UItemBin)


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PressurePlate() { return STRUCT_OFFSET(UItemBin, PressurePlate); } \
	FORCEINLINE static uint32 __PPO__ParcelBlueprint() { return STRUCT_OFFSET(UItemBin, ParcelBlueprint); } \
	FORCEINLINE static uint32 __PPO__CrateBlueprint() { return STRUCT_OFFSET(UItemBin, CrateBlueprint); } \
	FORCEINLINE static uint32 __PPO__BoxBlueprint() { return STRUCT_OFFSET(UItemBin, BoxBlueprint); } \
	FORCEINLINE static uint32 __PPO__TypeOfBin() { return STRUCT_OFFSET(UItemBin, TypeOfBin); }


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_20_PROLOG
#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_PRIVATE_PROPERTY_OFFSET \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_RPC_WRAPPERS \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_INCLASS \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DD_YY_MM_Source_ManagementGame_ItemBin_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_PRIVATE_PROPERTY_OFFSET \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_INCLASS_NO_PURE_DECLS \
	DD_YY_MM_Source_ManagementGame_ItemBin_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DD_YY_MM_Source_ManagementGame_ItemBin_h


#define FOREACH_ENUM_EBINTYPE(op) \
	op(EBinType::BT_Box) \
	op(EBinType::BT_Crate) \
	op(EBinType::BT_Parcel) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
