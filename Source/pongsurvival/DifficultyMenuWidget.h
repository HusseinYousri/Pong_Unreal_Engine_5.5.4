// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongGameInstance.h"
#include "DifficultyMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API UDifficultyMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// called when the widget is constructed
	virtual void NativeConstruct() override;

private:

	// === Blueprint Functions ===
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void CallBackToMainMenu();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void DifficultyEasy();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void DifficultyMedium();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void DifficultyHard();

	// === Classes Refrences ===
	class AMainMenuGameMode* MainMenuGameMode = nullptr;
	class UPongGameInstance* GameInstance = nullptr;

	// === Functions ===
	void CastToGameMode();
	void CastToGameInstance();
	void SetDifficultyAndStart(EGameDifficulty Difficulty);
};
