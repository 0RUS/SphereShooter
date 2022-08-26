#include "TargetController.h"
#include "Components/SphereComponent.h"
#include "SphereShooterCharacter.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "LevelSpawner.h"

// Sets default values
ATargetController::ATargetController()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionSphere->SetSphereRadius(MaxSphereRadius, false);
	CollisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = CollisionSphere;

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ATargetController::OnOverlapBegin);

	ShangeSphereRadius(RadiusDecrement);
}

// Called when the game starts or when spawned
void ATargetController::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ATargetController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ATargetController::ShangeSphereRadius(float Changer)
{
	//MaxSphereRadius = MaxSphereRadius - Changer >= MinSphereRadius ? MaxSphereRadius - Changer : MaxSphereRadius;
	float tmp = MaxSphereRadius - Changer;
	if (tmp >= MinSphereRadius)
		MaxSphereRadius = tmp;
	return MaxSphereRadius;
}

void ATargetController::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASphereShooterCharacter* test = Cast<ASphereShooterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (test->GetController() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target error"));
	}
	else
	{
		test->ChangeHitsCount(1);
		Destroy();
	}
}