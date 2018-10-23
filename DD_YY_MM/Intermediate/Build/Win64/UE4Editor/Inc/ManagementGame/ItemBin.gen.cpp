// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ItemBin.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemBin() {}
// Cross Module References
	MANAGEMENTGAME_API UEnum* Z_Construct_UEnum_ManagementGame_EBinType();
	UPackage* Z_Construct_UPackage__Script_ManagementGame();
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UItemBin_NoRegister();
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UItemBin();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerVolume_NoRegister();
// End Cross Module References
	static UEnum* EBinType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ManagementGame_EBinType, Z_Construct_UPackage__Script_ManagementGame(), TEXT("EBinType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EBinType(EBinType_StaticEnum, TEXT("/Script/ManagementGame"), TEXT("EBinType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ManagementGame_EBinType_CRC() { return 2520054311U; }
	UEnum* Z_Construct_UEnum_ManagementGame_EBinType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ManagementGame();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EBinType"), 0, Get_Z_Construct_UEnum_ManagementGame_EBinType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EBinType::BT_Box", (int64)EBinType::BT_Box },
				{ "EBinType::BT_Crate", (int64)EBinType::BT_Crate },
				{ "EBinType::BT_Parcel", (int64)EBinType::BT_Parcel },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "BT_Box.DisplayName", "Box Bin" },
				{ "BT_Crate.DisplayName", "Crate Bin" },
				{ "BT_Parcel.DisplayName", "Parcel Bin" },
				{ "ModuleRelativePath", "ItemBin.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ManagementGame,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EBinType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EBinType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UItemBin::StaticRegisterNativesUItemBin()
	{
	}
	UClass* Z_Construct_UClass_UItemBin_NoRegister()
	{
		return UItemBin::StaticClass();
	}
	UClass* Z_Construct_UClass_UItemBin()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_ManagementGame,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "ItemBin.h" },
				{ "ModuleRelativePath", "ItemBin.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TypeOfBin_MetaData[] = {
				{ "Category", "Enum" },
				{ "ModuleRelativePath", "ItemBin.h" },
				{ "ToolTip", "enum variable to contain the type of Bin this is" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TypeOfBin = { UE4CodeGen_Private::EPropertyClass::Enum, "TypeOfBin", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(UItemBin, TypeOfBin), Z_Construct_UEnum_ManagementGame_EBinType, METADATA_PARAMS(NewProp_TypeOfBin_MetaData, ARRAY_COUNT(NewProp_TypeOfBin_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TypeOfBin_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxBlueprint_MetaData[] = {
				{ "Category", "ItemBin" },
				{ "ModuleRelativePath", "ItemBin.h" },
				{ "ToolTip", "Actor pointer to the blueprint of the box" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_BoxBlueprint = { UE4CodeGen_Private::EPropertyClass::Class, "BoxBlueprint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0044000000000001, 1, nullptr, STRUCT_OFFSET(UItemBin, BoxBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_BoxBlueprint_MetaData, ARRAY_COUNT(NewProp_BoxBlueprint_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrateBlueprint_MetaData[] = {
				{ "Category", "ItemBin" },
				{ "ModuleRelativePath", "ItemBin.h" },
				{ "ToolTip", "Actor pointer to the blueprint of the crate" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_CrateBlueprint = { UE4CodeGen_Private::EPropertyClass::Class, "CrateBlueprint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0044000000000001, 1, nullptr, STRUCT_OFFSET(UItemBin, CrateBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_CrateBlueprint_MetaData, ARRAY_COUNT(NewProp_CrateBlueprint_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParcelBlueprint_MetaData[] = {
				{ "Category", "ItemBin" },
				{ "ModuleRelativePath", "ItemBin.h" },
				{ "ToolTip", "/ Blueprint pointers\n Actor pointer to the blueprint of the parcel" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ParcelBlueprint = { UE4CodeGen_Private::EPropertyClass::Class, "ParcelBlueprint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0044000000000001, 1, nullptr, STRUCT_OFFSET(UItemBin, ParcelBlueprint), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ParcelBlueprint_MetaData, ARRAY_COUNT(NewProp_ParcelBlueprint_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PressurePlate_MetaData[] = {
				{ "Category", "ItemBin" },
				{ "ModuleRelativePath", "ItemBin.h" },
				{ "ToolTip", "Pointer to the trigger volume that will destroy the parcel upon overlap" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PressurePlate = { UE4CodeGen_Private::EPropertyClass::Object, "PressurePlate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(UItemBin, PressurePlate), Z_Construct_UClass_ATriggerVolume_NoRegister, METADATA_PARAMS(NewProp_PressurePlate_MetaData, ARRAY_COUNT(NewProp_PressurePlate_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TypeOfBin,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TypeOfBin_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BoxBlueprint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CrateBlueprint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ParcelBlueprint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PressurePlate,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UItemBin>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UItemBin::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UItemBin, 2543361291);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UItemBin(Z_Construct_UClass_UItemBin, &UItemBin::StaticClass, TEXT("/Script/ManagementGame"), TEXT("UItemBin"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UItemBin);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
