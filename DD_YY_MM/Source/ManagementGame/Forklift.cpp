// Fill out your copyright notice in the Description page of Project Settings.

#include "Forklift.h"
#include "ConstructorHelpers.h"
#include "Engine.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ManagementGameCharacter.h"
// Sets default values
AForklift::AForklift()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ForkliftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Forklift Mesh"));
	ForkliftMesh->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Other_Assets/Mesh_Forklift.Mesh_Forklift'")).Object);
	ForkliftMesh->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
	RootComponent = ForkliftMesh;

	ClosestPlayer = nullptr;
}

// Called when the game starts or when spawned
void AForklift::BeginPlay()
{
	Super::BeginPlay();
}

void AForklift::SeekPlayer()
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
			ClosestPlayer = it;	

			//Sets the current distance as the new lowest
			dist = tempDist;

			//Setting the forklift's rotation to point towards the player
			SetActorRotation(
				FRotator(0.0f, dir.Rotation().Yaw, 0.0f)
			);
		}
	}
}

void AForklift::DrawDebug() {

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
	

// Called every frame
void AForklift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SeekPlayer();
	DrawDebug();

	SetActorLocation(GetActorLocation() + GetActorForwardVector() * 500.0f * DeltaTime);
}

