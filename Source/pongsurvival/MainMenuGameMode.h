// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:

	// === Blueprint Functions ===
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void StartGame();

	// === Blueprint Variables ===

private:

	// === GameMode Variables ===
	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	TSubclassOf<class UMainMenuWIdget> MainMenuWidgetClass;
};
