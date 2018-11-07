// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ForkLiftAI.generated.h"

UCLASS()
class MANAGEMENTGAME_API AForkLiftAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AForkLiftAI();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ForkliftMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ClosestPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_bMoving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_fMoveTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_bPositionSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_fMoveTimeDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector OldPlayerPos;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(BlueprintReadWrite)
		float fForce;
	AActor * LastHit;
	class UBoxComponent* m_myTriggerBox;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float LowestSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float CurrentSpeed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SeekPlayer();
	void DrawDebug();



	TArray<AActor*> ListOfPlayers;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
