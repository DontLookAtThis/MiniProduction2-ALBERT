// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Forklift.generated.h"


UCLASS()
class MANAGEMENTGAME_API AForklift : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForklift();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* ForkliftMesh;

	void SeekPlayer();
	void DrawDebug();
	float m_fMoveTimer;

	TArray<AActor*> ListOfPlayers;
	AActor* ClosestPlayer;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
