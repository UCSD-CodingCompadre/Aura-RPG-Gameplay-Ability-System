// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

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

