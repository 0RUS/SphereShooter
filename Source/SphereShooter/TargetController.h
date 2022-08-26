#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetController.generated.h"

UCLASS()
class SPHERESHOOTER_API ATargetController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere, Category = "Size", meta = (AllowPrivateAccess = "true"))
		float MinSphereRadius;

	UPROPERTY(EditAnywhere, Category = "Size", meta = (AllowPrivateAccess = "true"))
		float MaxSphereRadius;

	UPROPERTY(EditAnywhere, Category = "Size", meta = (AllowPrivateAccess = "true"))
		float RadiusDecrement;

	UFUNCTION()
		float ShangeSphereRadius(float Changer);

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
