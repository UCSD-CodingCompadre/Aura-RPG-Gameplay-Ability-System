#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{

	// Set the actor tick to false
	PrimaryActorTick.bCanEverTick = false;

	// Create the UStaticMeshComponent for the mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	// Set the mesh component as the root
	SetRootComponent(Mesh);

	// Create the USphereComponent for the sphere
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	// Attach the sphere to the root component
	Sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	// Check if the actor is an ability system interface
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{

		// Hold the attribute set
		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));

		// Hold the mutated attribute set
		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);

		// Set the health of the mutable attribute set
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);

		// Destroy the actor
		Destroy();
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AAuraEffectActor::BeginPlay()
{

	// Call the parent BeginPlay function
	Super::BeginPlay();

	// Add the on overlap delegate function to the sphere component
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);

	// Add the end overlap delegate function to the sphere component
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}

