// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWIdget.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API UMainMenuWIdget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// called when the widget is constructed
	virtual void NativeConstruct() override;

private:

	// === Classes Refrences ===
	class AMainMenuGameMode* MainMenuGameMode = nullptr;

	// === GameMode Callable Functions ===
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void CallStartGame();

	// === Functions ===
	void CastToGameMode();
};
