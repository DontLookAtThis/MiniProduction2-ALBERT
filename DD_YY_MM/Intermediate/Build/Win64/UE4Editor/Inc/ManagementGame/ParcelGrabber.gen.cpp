// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ParcelGrabber.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeParcelGrabber() {}
// Cross Module References
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UParcelGrabber_NoRegister();
	MANAGEMENTGAME_API UClass* Z_Construct_UClass_UParcelGrabber();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ManagementGame();
// End Cross Module References
	void UParcelGrabber::StaticRegisterNativesUParcelGrabber()
	{
	}
	UClass* Z_Construct_UClass_UParcelGrabber_NoRegister()
	{
		return UParcelGrabber::StaticClass();
	}
	UClass* Z_Construct_UClass_UParcelGrabber()
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
				{ "IncludePath", "ParcelGrabber.h" },
				{ "ModuleRelativePath", "ParcelGrabber.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UParcelGrabber>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UParcelGrabber::StaticClass,
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
	IMPLEMENT_CLASS(UParcelGrabber, 2870228228);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UParcelGrabber(Z_Construct_UClass_UParcelGrabber, &UParcelGrabber::StaticClass, TEXT("/Script/ManagementGame"), TEXT("UParcelGrabber"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UParcelGrabber);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
