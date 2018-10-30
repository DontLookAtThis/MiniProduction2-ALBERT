// Fill out your copyright notice in the Description page of Project Settings.

#include "ParcelGrabber.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "ManagementGamePlayerController.h"
#include "ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include <iostream>
#include "BoxMechanics.h"
#include <memory>

//#include "BoxMechanics.h"
// Sets default values for this component's properties
UParcelGrabber::UParcelGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	iGrabTimer = 0;
	// ...

	m_pYeetSound = ConstructorHelpers::FObjectFinder<USoundBase>(TEXT("SoundWave'/Game/Sound/RawSounds/Throw3.Throw3'")).Object;
	m_pGrabSound = ConstructorHelpers::FObjectFinder<USoundBase>(TEXT("SoundWave'/Game/Sound/RawSounds/PickUp.PickUp'")).Object;
}


// Called when the game starts
void UParcelGrabber::BeginPlay()
{
	Super::BeginPlay();
	m_PlayerCharacter = Cast<ACharacter>(GetOwner());
	m_pInputComp = GetOwner()->FindComponentByClass<UInputComponent>();	
	m_PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>(); // Find physics handle		
	if (!m_PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle ERROR : Owner = %s"), *GetOwner()->GetName());
	}	
	m_fThrowForce = m_fThrowForceDefault;
	bFirstRelease = true;
	bThrowCharging = false;
}

// Called every frame
void UParcelGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	m_fDeltaTime = DeltaTime;
	ChargeThrow();
	if (m_PhysicsHandle)
	{
		// Check if we're holding something
		if (bHolding)
		{
			// Check if we're holding something			
			if (m_PhysicsHandle->GrabbedComponent)
			{
				// Calculate the end of the raycast
				FVector PlayerForward = m_PlayerCharacter->GetActorForwardVector();
				FVector PlayerPosition = m_PlayerCharacter->GetActorLocation();
				FVector LineTraceEnd = PlayerPosition + PlayerForward * m_fHoldReach;
				UE_LOG(LogTemp, Warning, TEXT("GrabbedComponent FName: %s"), *m_PhysicsHandle->GrabbedComponent->GetReadableName());				

				// Set the targets location to the end of the raycast
				m_PhysicsHandle->SetTargetLocation(FVector(LineTraceEnd.X, LineTraceEnd.Y, LineTraceEnd.Z + 60.0f));
				m_PhysicsHandle->SetTargetRotation(m_PlayerCharacter->GetActorRotation());

				// If the compenent we're holding is being destroyed, release it so we can go pick up another
				if (m_PhysicsHandle->GrabbedComponent->IsBeingDestroyed())
				{
					m_PhysicsHandle->ReleaseComponent();
				}
			}
			else
			{
				// If holding is true but we're not holding anything, set it to false
				bHolding = false;
			}
		}
		else
		{
			// Handle grabbing processes
			if (bGrabbing)
			{
				Grab();
			}
		}		
	}
}

void UParcelGrabber::OnSetGrabPressed()
{	
	// If holding a box, do yeet stuff
	if (bHolding && bFirstRelease)
	{
		bThrowCharging = true;
	}
	// Otherwise, perform grabbing processes
	else
	{
		if (bGrabbing == false)
		{
			bGrabbing = true;
		}
	}
	
}
void UParcelGrabber::OnSetGrabRelease()
{
	if (bHolding && !bFirstRelease)
	{
		bFirstRelease = true;
	}
	else if (bHolding && bFirstRelease)
	{
		YeetAction();
		//plays the throwing sound
		UGameplayStatics::PlaySound2D(m_PlayerCharacter, m_pYeetSound, 1.0f, 2.0f, 0.6f);
	}
	bGrabbing = false;
	bThrowCharging = false;
	m_fThrowForce = m_fThrowForceDefault;
}

void UParcelGrabber::YeetAction()
{
	UPrimitiveComponent* thrownitem = m_PhysicsHandle->GrabbedComponent;
	if (thrownitem)
	{		
		if (m_PhysicsHandle->GrabbedComponent != nullptr)
		{
			// Decrement Box HP and set thrown true and held false
			thrownitem->GetOwner()->FindComponentByClass<UStaticMeshComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
			thrownitem->GetOwner()->FindComponentByClass<UBoxMechanics>()->iHealth--;			
			bHolding = false;
			bGrabbing = false;
			
			// Release the component and reset physics
			m_PhysicsHandle->ReleaseComponent();
			if (thrownitem)
			{
				thrownitem->SetSimulatePhysics(false);
				thrownitem->SetSimulatePhysics(true);
			}

			// Apply forces to the thrown item
			FVector YEET = m_PlayerCharacter->GetActorForwardVector();
			YEET.Z += 0.5f;
			thrownitem->AddImpulse(YEET * m_fThrowForce, NAME_None, true);
			thrownitem->GetOwner()->FindComponentByClass<UBoxMechanics>()->bPickedUp = false;
		}
	}
}

void UParcelGrabber::DropAction()
{
	UPrimitiveComponent* thrownitem = m_PhysicsHandle->GrabbedComponent;
	if (thrownitem)
	{
		if (m_PhysicsHandle->GrabbedComponent != nullptr)
		{
			thrownitem->GetOwner()->FindComponentByClass<UStaticMeshComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
			// Decrement Box HP and set thrown true and held false
			thrownitem->GetOwner()->FindComponentByClass<UBoxMechanics>()->iHealth--;
			bHolding = false;

			// Release the component and reset physics
			m_PhysicsHandle->ReleaseComponent();
			if (thrownitem)
			{
				thrownitem->SetSimulatePhysics(false);
				thrownitem->SetSimulatePhysics(true);
			}
			thrownitem->GetOwner()->FindComponentByClass<UBoxMechanics>()->bPickedUp = false;			
		}
	}
}

void UParcelGrabber::Grab()
{	
	if (m_PhysicsHandle)
	{
		// Reset grabbed object
		m_PhysicsHandle->ReleaseComponent();

		// Raycast to find objects to grab
		auto HitResult = GetFirstPhysicsBodyInReach();
		auto ComponentToGrab = HitResult.GetComponent();
		auto ActorHit = HitResult.GetActor();

		// If a hit was made, check that its a box and grab it
		if (ActorHit)
		{
			if (ActorHit->FindComponentByClass<UBoxMechanics>())
			{
				ActorHit->FindComponentByClass<UBoxMechanics>()->bPickedUp = true;
				ActorHit->FindComponentByClass<UStaticMeshComponent>()->SetSimulatePhysics(true);		
				ActorHit->FindComponentByClass<UStaticMeshComponent>()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Ignore);

				UE_LOG(LogTemp, Warning, TEXT("Grabbing parcel."));
				//m_PhysicsHandle->GrabComponentAtLocation(
				//	ComponentToGrab, //ComponentToGrab
				//	NAME_None, //grab what bone name, if any
				//	ComponentToGrab->GetOwner()->GetActorLocation() //grab location
				//);
				m_PhysicsHandle->GrabComponentAtLocationWithRotation(
					ComponentToGrab,
					NAME_None,
					ComponentToGrab->GetOwner()->GetActorLocation(),
					FRotator()//ComponentToGrab->GetOwner()->GetActorRotation()
				);

				bHolding = true;
				bFirstRelease = false;
				//plays the grab sound
				UGameplayStatics::PlaySound2D(m_PlayerCharacter, m_pGrabSound, 1.0f, 2.0f, 0.6f);
			}
		}
	}
}



FHitResult UParcelGrabber::GetFirstPhysicsBodyInReach()
{
	FVector PlayerForward = m_PlayerCharacter->GetActorForwardVector();
	FVector PlayerPosition = m_PlayerCharacter->GetActorLocation();	
	FVector LineTraceEnd = PlayerPosition + PlayerForward * m_fReach;	

	// Debug Box Trace
	DrawDebugBox(
		GetWorld(),
		LineTraceEnd,
		FVector(50, 50, 50),
		FColor::Purple,
		false,
		-1,
		0,
		10.0f
	);

	// Box-trace (ray-cast) out to reach distance
	FHitResult LineTraceHit;
	FCollisionShape Shape = FCollisionShape::MakeBox(FVector(50.0f, 50.0f, 50.0f));
	GetWorld()->SweepSingleByObjectType(
		LineTraceHit,
		PlayerPosition,
		LineTraceEnd,
		FQuat(),
		ECollisionChannel::ECC_PhysicsBody,
		Shape,
		FCollisionQueryParams::DefaultQueryParam			
	);	

	AActor* ActorHit = LineTraceHit.GetActor();
	if (ActorHit)
	{
		if (ActorHit->FindComponentByClass<UBoxMechanics>())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s hit."), *LineTraceHit.GetActor()->GetName());
			return LineTraceHit;
		}
		else
		{
			return FHitResult();
		}
	}	
	else
	{
		return FHitResult();
	}
}

void UParcelGrabber::ChargeThrow()
{
	if (bThrowCharging)
	{
		if (m_fThrowForce < (m_fThrowForceDefault + m_fForceIncreasePersec * 3.0f))
		{
			m_fThrowForce += (m_fDeltaTime * m_fForceIncreasePersec);
		}
	}
}

