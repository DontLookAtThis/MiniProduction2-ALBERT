// Fill out your copyright notice in the Description page of Project Settings.

#include "ConveyorBelt.h"
#include "GameFramework/CharacterMovementComponent.h" // means no red underline on get owner
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UConveyorBelt::UConveyorBelt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...

}
	

void UConveyorBelt::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	// Get overlapping actors
	UE_LOG(LogTemp, Warning, TEXT("OverlappingComponent"));
	GetOwner()->GetOverlappingActors(FoundActors);
}

void UConveyorBelt::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{	
	// Remove the actor from the list of overlapping actors
	FoundActors.Remove(OtherActor);	
}

// Called when the game starts
void UConveyorBelt::BeginPlay()
{
	Super::BeginPlay();
	
	// ...	
	m_pMyMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	m_pMyMesh->bGenerateOverlapEvents = true;
	m_pMyMesh->OnComponentBeginOverlap.AddDynamic(this, &UConveyorBelt::OnOverlapBegin);
	m_pMyMesh->OnComponentEndOverlap.AddDynamic(this, &UConveyorBelt::OnOverlapEnd);
}


// Called every frame
void UConveyorBelt::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	// Loop throug overlapping actors
	for (int i = 0; i < FoundActors.Num(); i++)
	{
		// Checking if the pointer is valid
		if (FoundActors[i]->IsValidLowLevel())
		{
			// Move the actors along the conveyer
			FVector location = FoundActors[i]->GetActorLocation();
			FVector forward = GetOwner()->GetActorForwardVector();

			location -= forward * 1.5f;
			FoundActors[i]->SetActorLocation(location);
		}		
	}
}


