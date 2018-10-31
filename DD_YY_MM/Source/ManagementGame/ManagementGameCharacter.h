// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ManagementGameCharacter.generated.h"

UCLASS(Blueprintable)
class AManagementGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AManagementGameCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/** Returns TopDownCameraComponent subobject **/
	//FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	///** Returns CameraBoom subobject **/
	//FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	///** Returns CursorToWorld subobject **/
	//FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }
	UPROPERTY(BlueprintReadWrite)
		bool bStunned;
	UPROPERTY(BlueprintReadWrite)
		bool bSlowed;
	UPROPERTY(BlueprintReadWrite)
		float fStunDuration;
	UPROPERTY(BlueprintReadWrite)
		float fSlowDuraction;
	UPROPERTY(BlueprintReadWrite)
		float fMoveSpeed = 1.0f;
	UPROPERTY(BlueprintReadWrite)
		FVector MovementDirection;
private:
	///** Top down camera */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UCameraComponent* TopDownCameraComponent;

	///** Camera boom positioning the camera above the character */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class USpringArmComponent* CameraBoom;

	///** A decal that projects to the cursor location. */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UDecalComponent* CursorToWorld;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void CardinalMovement();

	void OnSetGrabPressed();
	void OnSetGrabRelease();
	void OnSetYeetPressed();
	void OnSetYeetRelease();


	float m_fMoveSpeed;

	class UParcelGrabber* grabber;
};

