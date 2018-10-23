// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ConveyorBeltMechanics.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConveyorBeltMechanics() {}
// Cross Module References
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UConveyorBeltMechanics_NoRegister();
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UConveyorBeltMechanics();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ManagementGame();
// End Cross Module References
	void UConveyorBeltMechanics::StaticRegisterNativesUConveyorBeltMechanics()
	{
	}
	UClass* Z_Construct_UClass_UConveyorBeltMechanics_NoRegister()
	{
		return UConveyorBeltMechanics::StaticClass();
	}
	UClass* Z_Construct_UClass_UConveyorBeltMechanics()
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
				{ "IncludePath", "ConveyorBeltMechanics.h" },
				{ "ModuleRelativePath", "ConveyorBeltMechanics.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UConveyorBeltMechanics>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UConveyorBeltMechanics::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConveyorBeltMechanics, 3268666225);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConveyorBeltMechanics(Z_Construct_UClass_UConveyorBeltMechanics, &UConveyorBeltMechanics::StaticClass, TEXT("/Script/ManagementGame"), TEXT("UConveyorBeltMechanics"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConveyorBeltMechanics);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
