// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxMechanics.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include <string>
#include "Components/BoxComponent.h"
#include "ManagementGameCharacter.h"
#include "ForkLiftAI.h"

// Sets default values for this component's properties
UBoxMechanics::UBoxMechanics()
{
	deathTimer = 60;
	bStartup = true;
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//GetOwner()->FindComponentByClass<UStaticMeshComponent>()->OnComponentBeginOverlap.AddDynamic(this, &UBoxMechanics::OnConveyor);
	bOnConvey = false;
	bPickedUp = false;
	//if (iBoxType == 1)
	//{
	//	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Parcel_Assets/Small_Box/DestrucibleFragileBox.DestrucibleFragileBox'"));
	//	if (ItemBlueprint.Object) {
	//		DestrucitbleBox = (UClass*)ItemBlueprint.Object->GeneratedClass;
	//	}
	//}
	//else if(iBoxType == 2)
	//{
	//	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Parcel_Assets/NormalParcel/3rdBoxDestructible.3rdBoxDestructible'"));
	//	if (ItemBlueprint.Object) {
	//		DestrucitbleBox = (UClass*)ItemBlueprint.Object->GeneratedClass;
	//	}
	//}
	//else if(iBoxType == 3)
	//{
	//	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Parcel_Assets/Crate/CrateDestructible.CrateDestructible'"));
	//	if (ItemBlueprint.Object) {
	//		DestrucitbleBox = (UClass*)ItemBlueprint.Object->GeneratedClass;
	//	}
	//}
}


// Called when the game starts
void UBoxMechanics::BeginPlay()
{
	Super::BeginPlay();
	// ...
	//m_pMyBoxCollider = GetOwner()->FindComponentByClass<UBoxComponent>();
	m_pMyMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	m_pMyMesh->bGenerateOverlapEvents = true;
	m_pMyMesh->OnComponentBeginOverlap.AddDynamic(this, &UBoxMechanics::OnOverlapBegin);
	m_pMyMesh->OnComponentEndOverlap.AddDynamic(this, &UBoxMechanics::OnOverlapEnd);
	m_pMyMesh->SetSimulatePhysics(true);
}


// Called every frame
void UBoxMechanics::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);	

	if (GetOwner()->GetActorLocation().Z <= -800.0f) {
		GetOwner()->Destroy();
	}
}

void UBoxMechanics::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	float Speed;
	FVector Temp;
	GetOwner()->GetVelocity().ToDirectionAndLength(Temp, Speed);
	if (bPickedUp) return;
	if (AManagementGameCharacter* actorChar = Cast<AManagementGameCharacter>(OtherActor))
	{
		if (iBoxType == 0 && Speed > 200.0f)
		{
			actorChar->bStunned = true;
			actorChar->fStunDuration = 1.65f;
			actorChar->LaunchCharacter(FVector(0.0f, 0.0f, 800.0f), true, true);
		}
		else if (iBoxType == 1 && Speed > 200.0f)
		{
			actorChar->bSlowed = true;
			actorChar->fMoveSpeed = 0.5f;
			actorChar->fSlowDuraction = 2.0f;
		}
	}
	if (AForkLiftAI* ForkLift = Cast<AForkLiftAI>(OtherActor))
	{
		if (iBoxType == 0 && Speed > 300.0f)
		{
			ForkLift->LastHit = LastHolder;
		}
	}
	//m_pMyMesh->SetSimulatePhysics(false);
}

void UBoxMechanics::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{	
	//m_pMyMesh->SetSimulatePhysics(true);
}

void UBoxMechanics::BreakItem()
{
	//if (iHealth <= 0)
	//{
	//	deathTimer--;
	//}
	//if (deathTimer <= 0)
	//{
		FActorSpawnParameters params;
		params.Owner = GetOwner();

		FRotator rotation = GetOwner()->GetActorRotation();
		FVector location = GetOwner()->GetActorLocation();


		GetWorld()->SpawnActor<AActor>(DestrucitbleBox, location, rotation);
		GetOwner()->Destroy();
	//}
}




