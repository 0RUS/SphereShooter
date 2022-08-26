#include "SphereShooterGameMode.h"
#include "SphereShooterHUD.h"
#include "SphereShooterCharacter.h"
#include "Blueprint/UserWidget.h"
#include "SphereShooter.h"

void ASphereShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	ASphereShooterCharacter* MyCharacter = Cast<ASphereShooterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

ASphereShooterGameMode::ASphereShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASphereShooterHUD::StaticClass();
}