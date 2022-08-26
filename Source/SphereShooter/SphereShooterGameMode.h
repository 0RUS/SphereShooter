#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SphereShooterGameMode.generated.h"

UCLASS(minimalapi)
class ASphereShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	ASphereShooterGameMode();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD", Meta = (BlueprintProtected = "true"));
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;

};