// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()


public:
	
	// Constructor
	AAuraPlayerState();

	/*
	Getter function that returns the ability system component
	@param none
	@return UAbilitySystemComponent*
	*/
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	/*
	Getter function that returns the attribute set
	@param none
	@return UAttributeSet*
	*/
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected: 

	// Hold an object pointer for the ability system component
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// Hold an object pointer for the attribute set
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
