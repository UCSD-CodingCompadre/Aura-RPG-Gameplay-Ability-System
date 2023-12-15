// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"


ABaseCharacter::ABaseCharacter()
{

	// Disable actor tick
	PrimaryActorTick.bCanEverTick = false;

	// Create the USkeletMeshComponent for the Weopon
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	// Attach the Weapon to the socket
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));

	// Disable collision for the Weapon
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{

	// Return the ability system component
	return AbilitySystemComponent;
}

void ABaseCharacter::BeginPlay()
{

	// Call the parent BeginPlay function
	Super::BeginPlay();
}

