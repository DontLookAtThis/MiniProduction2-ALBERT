// Fill out your copyright notice in the Description page of Project Settings.

#include "FanTriggerVolume.h"
#include "ManagementGameCharacter.h"
#include "BoxMechanics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AFanTriggerVolume::AFanTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	fForce = 1.0f;
	bActive = false;

}

void AFanTriggerVolume::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Adding Actor"));
		actors.AddUnique(OtherActor);
	}
}

void AFanTriggerVolume::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Removing Actor"));
		actors.Remove(OtherActor);
	}
}

// Called when the game starts or when spawned
void AFanTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	m_myTriggerBox = FindComponentByClass<UBoxComponent>();
	m_myTriggerBox->bGenerateOverlapEvents = true;
	m_myTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFanTriggerVolume::OnOverlapBegin);
	m_myTriggerBox->OnComponentEndOverlap.AddDynamic(this, &AFanTriggerVolume::OnOverlapEnd);
}

// Called every frame
void AFanTriggerVolume::Tick(float DeltaTime)
{
	if (bActive) {
		Super::Tick(DeltaTime);
		for (int i = 0; i < actors.Num(); i++)
			{
				ApplyForce(actors[i]);
			}
		}
	}
	

void AFanTriggerVolume::ApplyForce(AActor * actor)
{
	if (AManagementGameCharacter* player = Cast<AManagementGameCharacter>(actor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Pushing Player"));

		UCharacterMovementComponent* movement = player->GetCharacterMovement();
		player->MovementDirection += (GetActorForwardVector() * fForce * 0.5f);
		//movement->AddForce((GetActorForwardVector() * fForce * 2.0f));
	}
	else if (actor->FindComponentByClass<UBoxMechanics>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Pushing Box"));
		UStaticMeshComponent* mesh = actor->FindComponentByClass<UStaticMeshComponent>();
		mesh->AddForce((GetActorForwardVector() * fForce * 2.0f));
	}
}

