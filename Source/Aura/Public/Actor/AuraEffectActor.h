#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()

public:	

	// Constructor
	AAuraEffectActor();

	/*
	Callback function that triggers when something overlaps the actor
	@param UPrimitiveCompont OverlappedComponent the component that was overlapped
	OtherActor the actor that overlapped this actor
	OtherComp the component that overlapped this actor
	int32 OtherBodyIndex the index of the colliding primitive 
	bool bFromSweep indicates whether the overlap is the result of a sweep
	FHitResult SweepResult the result of the sweep
	@return void
	*/
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*
	Callback function that triggers when something ends the overlaps on the actor
	@param UPrimitiveCompont OverlappedComponent the component that was overlapped
	OtherActor the actor that overlapped this actor
	OtherComp the component that overlapped this actor
	int32 OtherBodyIndex the index of the colliding primitive 
	@return void
	*/
	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:

	virtual void BeginPlay() override;
private:
	
	// Hold an object pointer to the sphere component
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	// Hold an object pointer to the static mesh
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
