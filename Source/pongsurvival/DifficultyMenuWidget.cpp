// Fill out your copyright notice in the Description page of Project Settings.

#include "DifficultyMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuGameMode.h"

void UDifficultyMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    CastToGameMode();
    CastToGameInstance();
}

void UDifficultyMenuWidget::CastToGameInstance()
{
    GameInstance = Cast<UPongGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (!GameInstance) {return;}
}

void UDifficultyMenuWidget::CallBackToMainMenu()
{
    if (!MainMenuGameMode) {return;}
    MainMenuGameMode->BackToMainMenu();
}

void UDifficultyMenuWidget::DifficultyEasy()
{
    SetDifficultyAndStart(EGameDifficulty::Easy);
}

void UDifficultyMenuWidget::DifficultyMedium()
{
    SetDifficultyAndStart(EGameDifficulty::Medium);
}

void UDifficultyMenuWidget::DifficultyHard()
{
    SetDifficultyAndStart(EGameDifficulty::Hard);
}

void UDifficultyMenuWidget::CastToGameMode()
{
    MainMenuGameMode = Cast<AMainMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (!MainMenuGameMode) {return;}
}

void UDifficultyMenuWidget::SetDifficultyAndStart(EGameDifficulty Difficulty)
{
    if (GameInstance)
        GameInstance->SetDifficulty(Difficulty);
    if (MainMenuGameMode)
        MainMenuGameMode->StartGame();
}