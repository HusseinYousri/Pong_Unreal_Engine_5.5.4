// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

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

	// === Public Functions ===
	void UnShowMainMenuWidget();
	void CastToDifficultyMenuWidget();
	void BackToMainMenu();

private:

	// === Classes Refrences ===
	class UMainMenuWIdget* MainMenuWidget = nullptr;
	class UDifficultyMenuWidget* DifficultyMenuWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<class UMainMenuWIdget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<class UDifficultyMenuWidget> DifficultyMenuWidgetClass;

	// === Functions ===
	void CastMainMenuWidget();
	void SetMouseCursorVisibility(const bool& bShowMouseCursor);
};
