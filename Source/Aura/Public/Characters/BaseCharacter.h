// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class AURA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Constructor
	ABaseCharacter();

protected:
	
	/*
	Set up the skeletal mesh and components for the character
	@param none
	@return void
	*/
	virtual void BeginPlay() override;

	// Hold the pointer to the Weapoon skeletal mesh
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
