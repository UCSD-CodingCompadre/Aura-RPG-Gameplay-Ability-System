// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void PlayerTick(float DeltaTime) override;

public:

	// Constructor
	AAuraPlayerController();

protected:

	/*
	Handles setting up the enchanced input subsystem and 
	input mode data
	@param none
	@return void
	*/
	virtual void BeginPlay() override;

	/*
	Sets up the input component for the controller
	@param none
	@return void
	*/
	virtual void SetupInputComponent() override;
private:

	// Hold the mapping context 
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	// Hold the input action
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	/*
	Handles the move input action
	@param FInputActionValue InputActionValue the value passed into
	the action 
	@return void
	*/
	void Move(const FInputActionValue& InputActionValue);	

	void CursorTrace();
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
