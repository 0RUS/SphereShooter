#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelSpawner.generated.h"

UCLASS()
class SPHERESHOOTER_API ALevelSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CheckForNewWave();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Level;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> TargetClass;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	float SpawnRadius;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	float MidSpawnRadius;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	int32 SphereCount;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	int32 ThresholdDestroyedCount;

	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	float SphereCountIncrement;
	
	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	float SpawnRadiusIncrementStep;
	
	UPROPERTY(EditAnywhere, Category = Level, meta = (AllowPrivateAccess = "true"))
	float MinSphereSpacing;

public:

	void SpawnSpheres(UClass* ItemToSpawn);

	void SpawnNewWave();
};