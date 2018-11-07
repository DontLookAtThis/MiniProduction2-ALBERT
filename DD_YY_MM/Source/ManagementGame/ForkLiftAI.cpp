// Fill out your copyright notice in the Description page of Project Settings.

#include "ForkLiftAI.h"
#include "ConstructorHelpers.h"
#include "Engine.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ManagementGameCharacter.h"
#include "ManagementGameCharacter.h"
#include "ParcelGrabber.h"

// Sets default values
AForkLiftAI::AForkLiftAI()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ForkliftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Forklift Mesh"));
	ForkliftMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Other_Assets/Mesh_Forklift.Mesh_Forklift'")).Object);
	ForkliftMesh->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
	m_fMoveTimeDelay = 2.0f;
	m_fMoveTimer = m_fMoveTimeDelay + 1.0f;
	fForce = 2000.0f;
	m_bPositionSet = false;
	m_bMoving = false;
	ClosestPlayer = nullptr;
	LowestSpeed = 100.0f;
	CurrentSpeed = LowestSpeed;
}


// Called when the game starts or when spawned
void AForkLiftAI::BeginPlay()
{
	Super::BeginPlay();
	m_myTriggerBox = FindComponentByClass<UBoxComponent>();
	m_myTriggerBox->bGenerateOverlapEvents = true;
	m_myTriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AForkLiftAI::OnOverlapBegin);
	m_myTriggerBox->OnComponentEndOverlap.AddDynamic(this, &AForkLiftAI::OnOverlapEnd);
}

void AForkLiftAI::SeekPlayer()
{
	//Getting all players in the game by searching for the class
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AManagementGameCharacter::StaticClass(), ListOfPlayers);

	//Setting some variables to be used for the calculation
	float dist = 900000.0f;		//some arbitrarily high distance value
	float tempDist;				//a temporary float to store the current distance

								//Iterating through the list of players
	for (auto it : ListOfPlayers) {

		//Getting the vector between the forklift and the current iterated player
		FVector dir = it->GetActorLocation() - GetActorLocation();

		//Calculating the direction and the length of the vector. Function modifies the
		//vector [dir] and the float [tempDist] passed in
		dir.ToDirectionAndLength(dir, tempDist);

		//If tempDist is lower than the current closests dist
		if (tempDist < dist) {

			//Setting the internal closest player reference to the iterator reference
			if (Cast<AManagementGameCharacter>(it))
			{
				if (it != LastHit)
				{
					ClosestPlayer = it;
					dist = tempDist;
				}

			}
			//Sets the current distance as the new lowest


			//Setting the forklift's rotation to point towards the player
			//SetActorRotation(
				//FRotator(0.0f, dir.Rotation().Yaw, 0.0f)
			//);

		}
	}
	if (ClosestPlayer != nullptr)
	{
		if (Cast<AManagementGameCharacter>(ClosestPlayer))
		{
			OldPlayerPos = ClosestPlayer->GetActorLocation();
			m_bMoving = true;
			m_bPositionSet = true;
			//UE_LOG(LogTemp, Warning, TEXT("NOW MOVING TO: %s"), *OldPlayerPos.ToString());

			m_fMoveTimer = 0.0f;
		}
	}

}

void AForkLiftAI::DrawDebug()
{
	//FVector DirToPlayer = GetActorLocation() - FoundActors[0]->GetActorLocation();
	if (ClosestPlayer != nullptr) {
		DrawDebugLine(
			GetWorld(),
			GetActorLocation(),
			ClosestPlayer->GetActorLocation(),
			FColor(255, 0, 0),
			false, -1, 0,
			4.0
		);
	}
}
void AForkLiftAI::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("MAYBE ME"));
	if (AManagementGameCharacter* player = Cast<AManagementGameCharacter>(OtherActor))
	{
		if (player->bStunned) return;
		UE_LOG(LogTemp, Warning, TEXT("KILL ME"));
		FVector LaunchDir = player->GetActorLocation() - this->GetActorLocation();
		LaunchDir.Normalize();
		LaunchDir.Z += 0.5f;
		LaunchDir.Normalize();
		LaunchDir *= fForce;
		player->bStunned = true;
		player->fStunDuration = 2.0f;
		player->LaunchCharacter(LaunchDir, true, false);
		LastHit = player;
		Cast<UParcelGrabber>(player->grabber)->DropAction();
		CurrentSpeed = LowestSpeed;
	}
}

void AForkLiftAI::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

}



// Called every frame
void AForkLiftAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebug();
	float f;
	FVector v;
	GetActorLocation().ToDirectionAndLength(v, f);
	if (m_bMoving) {

		m_fMoveTimer += DeltaTime;
		//SetActorLocation(GetActorLocation() + GetActorForwardVector() * 1000.0f * DeltaTime);
	}
	else if (!m_bMoving) {
		//ClosestPlayer = nullptr;
		//SeekPlayer();
	}

	if (m_fMoveTimer > m_fMoveTimeDelay)
	{
		ClosestPlayer = nullptr;
		UE_LOG(LogTemp, Warning, TEXT("Resetting"));
		m_bMoving = false;
		m_bPositionSet = false;
		SeekPlayer();
	}

}

// Called to bind functionality to input
void AForkLiftAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

