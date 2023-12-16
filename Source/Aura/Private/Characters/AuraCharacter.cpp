// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AuraCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{

	// Set the character movement component to orient rotation to movement
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Set the character movement component rotation rate
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	// Set the character movement component to constrain to a plane
	GetCharacterMovement()->bConstrainToPlane = true;

	// Set the character movement component to snap to a plane
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Set the component to not use the controller pitch
	bUseControllerRotationPitch = false;

	// Set the component to not use the controller roll
	bUseControllerRotationRoll = false;
	
	// Set the component to not use the controller yaw
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{

	// Call the parent PossedBy method
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{

	// Call the parent OnRep_PlayerState
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{

	// Hold the aura player state
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	
	// Check if there is a aura player state
	check(AuraPlayerState);

	// Set the ability actor info for the ability system component
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

	// Hold the ability system component from the aura player state
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();

	// Hold the attribute set from the aura player state
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
