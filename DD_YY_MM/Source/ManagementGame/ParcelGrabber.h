// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "ParcelGrabber.generated.h"
class ManagementGamePlayerController;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MANAGEMENTGAME_API UParcelGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UParcelGrabber();
	bool bGrabbing = false;
	bool bHolding = false;
	bool bThrown = false;
	int iGrabTimer;
	void OnSetGrabPressed();
	void OnSetGrabRelease();
	void YeetAction();
	UFUNCTION(BlueprintCallable, Category = "BoxHandle")
		void DropAction();
	UPROPERTY(EditAnywhere, Category = "Throw Force")
		float m_fThrowForceDefault = 1000.0f;
	UPROPERTY(EditAnywhere, Category = "Throw Force")
		float m_fForceIncreasePersec = 500.0f;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void Grab();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FHitResult GetFirstPhysicsBodyInReach();
	
private:

	UPhysicsHandleComponent * m_PhysicsHandle = nullptr;	
	ACharacter* m_PlayerCharacter;
	APlayerController* m_pPlayerController;
	UInputComponent* m_pInputComp;
	USoundBase* m_pYeetSound;
	USoundBase* m_pGrabSound;
	float m_fReach = 150.0f; // grabber reach
	float m_fHoldReach = 100.0f; // hold reach

	float m_fDeltaTime = 0.0f;

	float m_fThrowForce;
	bool bFirstRelease;
	bool bThrowCharging;

	void ChargeThrow();
};
