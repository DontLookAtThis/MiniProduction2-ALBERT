// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ManagementGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "ParcelGrabber.h"


AManagementGameCharacter::AManagementGameCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 1000.0f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = false;
	bInputEnabled = true;
	// Create a camera boom...
	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	//CameraBoom->TargetArmLength = 800.f;
	//CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	//CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	//// Create a camera...
	//TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	//TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//// Create a decal in the world to show the cursor's location
	//CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	//CursorToWorld->SetupAttachment(RootComponent);
	//static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/Due_Date/Blueprints/Player/M_Cursor_Decal.M_Cursor_Decal'"));
	//if (DecalMaterialAsset.Succeeded())
	//{
	//	CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	//}
	//CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	//CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	//StarEmitter = CreateDefaultSubobject<UParticleSystem>(TEXT("Particle Emitter"));
	StarEmitter = (ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Game/VFX/VFX_Stun.VFX_Stun'")).Object);
}


void AManagementGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	grabber = FindComponentByClass<UParcelGrabber>();
	bStunned = false;
	bSlowed = false;
	fStunDuration = 0.0f;
	fSlowDuraction = 0.0f;
}

// Called to bind functionality to input
void AManagementGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AManagementGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AManagementGameCharacter::MoveRight);

	PlayerInputComponent->BindAction("Grab&Release", IE_Pressed, this, &AManagementGameCharacter::OnSetGrabPressed);
	PlayerInputComponent->BindAction("Grab&Release", IE_Released, this, &AManagementGameCharacter::OnSetGrabRelease);
	PlayerInputComponent->BindAction("YeetAction", IE_Pressed, this, &AManagementGameCharacter::OnSetYeetPressed);
	PlayerInputComponent->BindAction("YeetAction", IE_Released, this, &AManagementGameCharacter::OnSetYeetRelease);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AManagementGameCharacter::OnSetJumpPressed);
}

void AManagementGameCharacter::MoveForward(float AxisValue)
{
	if (!bInputEnabled) return;
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	Direction *= AxisValue;
	MovementDirection += Direction;
	//UE_LOG(LogTemp, Warning, TEXT("X %s"), *Direction.ToString());
}

void AManagementGameCharacter::MoveRight(float AxisValue)
{
	if (!bInputEnabled) return;
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	Direction *= AxisValue;
	MovementDirection += Direction;
	//UE_LOG(LogTemp, Warning, TEXT("Y %s"), *Direction.ToString());
}

void AManagementGameCharacter::CardinalMovement()
{
	//UE_LOG(LogTemp, Warning, TEXT("Direction %s"), *MovementDirection.ToString());
	if (!(MovementDirection.Size() > 0.0f)) return;
	AddMovementInput(MovementDirection, fMoveSpeed);
	MovementDirection = FVector(0, 0, 0);
}

void AManagementGameCharacter::OnSetGrabPressed()
{
	if (!bInputEnabled) return;
	if(grabber)
	{
		grabber->OnSetGrabPressed();
	}
}

void AManagementGameCharacter::OnSetYeetPressed()
{
	if (!bInputEnabled) return;
	if (grabber)
	{
		grabber->OnSetYeetPressed();
	}
}

void AManagementGameCharacter::OnSetJumpPressed()
{
	if (!bInputEnabled) return;
	if (bStunned) return;
	Jump();
}

void AManagementGameCharacter::OnSetYeetRelease()
{
	if (!bInputEnabled) return;
	if (grabber)
	{
		grabber->OnSetYeetRelease();
	}
}

void AManagementGameCharacter::OnSetGrabRelease()
{
	if (!bInputEnabled) return;
	if (grabber)
	{
		grabber->OnSetGrabRelease();
	}
}

void AManagementGameCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);	
	//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StarEmitter, GetActorLocation());
	if (!bStunned && bInputEnabled)
	{
		CardinalMovement();
	}
	if (fStunDuration > 0.0f && bStunned)
	{
		fStunDuration -= DeltaSeconds;
		SetActorRotation(GetActorRotation() + FRotator(0.0f, 10.0f, 0.0f));
	}
	else if (bStunned && fStunDuration <= 0.0f)
	{
		fStunDuration = 0.0f;
		bStunned = false;
	}

	if (fSlowDuraction > 0.0f && bSlowed)
	{
		fSlowDuraction -= DeltaSeconds;
	}
	else if (bSlowed && fSlowDuraction <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Slow reset"));
		bSlowed = false;
		fSlowDuraction = 0.0f;
		fMoveSpeed = 1.0f;
	}


	//if (CursorToWorld != nullptr)
	//{
	//	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	//	{
	//		if (UWorld* World = GetWorld())
	//		{
	//			FHitResult HitResult;
	//			FCollisionQueryParams Params(NAME_None, FCollisionQueryParams::GetUnknownStatId());
	//			FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
	//			FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
	//			Params.AddIgnoredActor(this);
	//			World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
	//			FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
	//			CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
	//		
	//		}
	//	}
	//	else if (APlayerController* PC = Cast<APlayerController>(GetController()))
	//	{
	//		FHitResult TraceHitResult;
	//		PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
	//		FVector CursorFV = TraceHitResult.ImpactNormal;
	//		FRotator CursorR = CursorFV.Rotation();
	//		CursorToWorld->SetWorldLocation(TraceHitResult.Location);
	//		CursorToWorld->SetWorldRotation(CursorR);
	//	}
	//}
}
