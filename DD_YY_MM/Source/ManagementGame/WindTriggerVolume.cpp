// Fill out your copyright notice in the Description page of Project Settings.

#include "WindTriggerVolume.h"
#include "ManagementGameCharacter.h"
#include "BoxMechanics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
void AWindTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bStartWithTickEnabled = true;
	SetActorTickEnabled(true);
	fForce = 1000000000000000.0f;
	m_myTriggerBox = FindComponentByClass<UBoxComponent>();
	m_myTriggerBox->bGenerateOverlapEvents = true;
	m_myTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AWindTriggerVolume::OnOverlapBegin);
	m_myTriggerBox->OnComponentEndOverlap.AddDynamic(this, &AWindTriggerVolume::OnOverlapEnd);
}

void AWindTriggerVolume::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Ticking"));
	for (int i = 0; i < actors.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Checking force application"));
		ApplyForce(actors[i]);
	}
}

void AWindTriggerVolume::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Adding Actor"));
		actors.AddUnique(OtherActor);
	}
}

void AWindTriggerVolume::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Removing Actor"));
		actors.Remove(OtherActor);
	}
}

void AWindTriggerVolume::ApplyForce(AActor * actor)
{
	if (AManagementGameCharacter* player = Cast<AManagementGameCharacter>(actor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Pushing Player"));

		UCharacterMovementComponent* movement = player->GetCharacterMovement();
		movement->AddForce((GetActorForwardVector() * fForce));
	}
	else if (actor->FindComponentByClass<UBoxMechanics>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Pushing Box"));
		UStaticMeshComponent* mesh = player->FindComponentByClass<UStaticMeshComponent>();
		mesh->AddForce((GetActorForwardVector() * fForce));
	}
}
