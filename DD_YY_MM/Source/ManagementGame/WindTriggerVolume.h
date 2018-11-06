// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "WindTriggerVolume.generated.h"


/**
 * 
 */
UCLASS()
class MANAGEMENTGAME_API AWindTriggerVolume : public ATriggerBox
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float _deltaTime) override;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(BlueprintReadWrite)
		float fForce;
private:
	void ApplyForce(AActor* actor);
	class UBoxComponent* m_myTriggerBox;
	TArray<AActor*> actors;
};
