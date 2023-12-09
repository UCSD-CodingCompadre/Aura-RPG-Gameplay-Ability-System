// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
	
public:

	// Constructor
	AEnemyCharacter();

	/*
	Hightlight the actor using render custom depth
	@param none
	@return void
	*/
	virtual void HighlightActor() override;

	/*
	Unhightlight the actor using render custom depth
	@param none
	@return void 
	*/
	virtual void UnHighlightActor() override;
};

