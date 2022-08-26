#include "LevelSpawner.h"
#include <SphereShooter/SphereShooterCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ALevelSpawner::ALevelSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	Level = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetComponent"));
	SetRootComponent(Level);

	SphereCount = 15;
	ThresholdDestroyedCount = 10;

	MidSpawnRadius = 1500.f;
	SpawnRadius = 2000.f;

	SphereCountIncrement = 10.f;
	SpawnRadiusIncrementStep = 200.f;
	MinSphereSpacing = 80;
}

void ALevelSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnSpheres(TargetClass);
}

void ALevelSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForNewWave();
}

void ALevelSpawner::SpawnSpheres(UClass* ItemToSpawn)
{
	FVector test = Cast<ASphereShooterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0))->GetActorLocation();

	for (int i = 0; i < SphereCount; i++)
	{
		float theta = i * 2 * 3.14 / SphereCount;
		float x = sin(theta) * SpawnRadius + test.X;
		float y = cos(theta) * SpawnRadius + test.Y;
		FVector Location(x, y, 100.f);
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, FRotator(0.0f));
		Location += FVector(x, y, 0.f);
	}

	SphereCount += SphereCountIncrement;
	SpawnRadius += SpawnRadiusIncrementStep;
}

void ALevelSpawner::CheckForNewWave()
{
	ASphereShooterCharacter* test = Cast<ASphereShooterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (test->GetHitsCount() == test->GetWaveNumber() * ThresholdDestroyedCount)
	{
		TArray<AActor*> FoundEnemies;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), TargetClass, FoundEnemies);
		for (int i = 0; i < FoundEnemies.Num(); i++)
		{
			FoundEnemies[i]->Destroy();
		}
		test->ChangeWaveValue(1);
		SpawnSpheres(TargetClass);
	}
}