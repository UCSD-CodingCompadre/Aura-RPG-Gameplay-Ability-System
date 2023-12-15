// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{

	// Create the ability system component
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

	// Allow the component to replicate
	AbilitySystemComponent->SetIsReplicated(true);

	// Set the replication mode to mix
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Create the attribute set
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	// Set the update frequency
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{

	// Return the ability system component
	return AbilitySystemComponent;
}