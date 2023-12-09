// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	
	GENERATED_BODY()

public:

	/*
	Abstact hightlight actor function to implement custom higlighting
	@param none
	@return void
	*/
	virtual void HighlightActor() = 0;

	/*
	Abstact unhightlight actor function to implement custom unhiglighting
	@param none
	@return void
	*/
	virtual void UnHighlightActor() = 0;
};
