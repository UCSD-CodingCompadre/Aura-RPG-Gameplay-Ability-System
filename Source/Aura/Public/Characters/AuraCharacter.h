// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	// Constructor
	AAuraCharacter();

	/*
	
	*/
	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;
private:

	void InitAbilityActorInfo();
};
