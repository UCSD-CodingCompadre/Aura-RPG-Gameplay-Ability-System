// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

// Define the attribute accessors from the attribute set class
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{

	GENERATED_BODY()

public:

	// Constructor
	UAuraAttributeSet();

	/*
	Set the variables that are going to be replicated
	@param TArray<FLifetimeProperty> OutLifetimeProps the lifetime properties of the replicated varaibles
	@return void
	*/
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Hold the health GamePlayAttributeData
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	// Hold the max health GamePlayAttributeData
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	// Hold the mana GamePlayAttributeData
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	// Hold the max mana GamePlayAttributeData
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	/*
	Callback function that triggers on any change to the health
	@param FGameplayeAttributeData OldHealth the old health attribute data
	@return void
	*/
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	/*
	Callback function that triggers on any change to the max health
	@param FGameplayeAttributeData OldMaxHealth the old max health attribute data
	@return void
	*/
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	/*
	Callback function that triggers on any change to the mana
	@param FGameplayeAttributeData OldMana the old mana attribute data
	@return void
	*/
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	/*
	Callback function that triggers on any change to the max mana
	@param FGameplayeAttributeData OldMaxMana the old max mana attribute data
	@return void
	*/
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
