// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ManagementGamePlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeManagementGamePlayerController() {}
// Cross Module References
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_AManagementGamePlayerController_NoRegister();
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_AManagementGamePlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_ManagementGame();
// End Cross Module References
	void AManagementGamePlayerController::StaticRegisterNativesAManagementGamePlayerController()
	{
	}
	UClass* Z_Construct_UClass_AManagementGamePlayerController_NoRegister()
	{
		return AManagementGamePlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_AManagementGamePlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APlayerController,
				(UObject* (*)())Z_Construct_UPackage__Script_ManagementGame,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "ManagementGamePlayerController.h" },
				{ "ModuleRelativePath", "ManagementGamePlayerController.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AManagementGamePlayerController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AManagementGamePlayerController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800284u,
				nullptr, 0,
				nullptr, 0,
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AManagementGamePlayerController, 1225181407);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AManagementGamePlayerController(Z_Construct_UClass_AManagementGamePlayerController, &AManagementGamePlayerController::StaticClass, TEXT("/Script/ManagementGame"), TEXT("AManagementGamePlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AManagementGamePlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
