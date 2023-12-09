// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AEnemyCharacter::AEnemyCharacter()
{
    
    // Set the collision channel visibility to block
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}


void AEnemyCharacter::HighlightActor()
{

    // Enable skeletal mesh render custom depth
    GetMesh()->SetRenderCustomDepth(true);

    // Set the depth stencil value
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

    // Enable the weapon skeletal mesh render custom depth
	Weapon->SetRenderCustomDepth(true);

    // Set the depth stencil value
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemyCharacter::UnHighlightActor()
{

    // Disable skeletal mesh render custom depth
    GetMesh()->SetRenderCustomDepth(false);

    // Disable the weapon skeletal mesh render custom depth
	Weapon->SetRenderCustomDepth(false);
}