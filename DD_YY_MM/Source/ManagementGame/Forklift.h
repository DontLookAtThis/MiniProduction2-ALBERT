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
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ForkliftMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




	void SeekPlayer();
	void DrawDebug();
	float m_fMoveTimer;
	bool m_bMoving;

	TArray<AActor*> ListOfPlayers;
	AActor* ClosestPlayer;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
