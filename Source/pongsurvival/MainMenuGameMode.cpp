// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWIdget.h"
#include "DifficultyMenuWidget.h"

void AMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

    CastMainMenuWidget();
    SetMouseCursorVisibility(true);
}

void AMainMenuGameMode::StartGame()
{
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("Main"));
}

void AMainMenuGameMode::UnShowMainMenuWidget()
{
    if (!MainMenuWidget) {return;}
    MainMenuWidget->RemoveFromParent();
    MainMenuWidget = nullptr;
}

void AMainMenuGameMode::BackToMainMenu()
{
    CastMainMenuWidget();
    DifficultyMenuWidget->RemoveFromParent();
    DifficultyMenuWidget = nullptr;
}

void AMainMenuGameMode::CastMainMenuWidget()
{
    // Check if the widget class is valid
    if (!MainMenuWidgetClass) {return;}

    // Create the widget instance
    MainMenuWidget = CreateWidget<UMainMenuWIdget>(GetWorld(), MainMenuWidgetClass);
    if (!MainMenuWidget) {return;}

    // Add the widget to the viewport
    MainMenuWidget->AddToViewport();
}

void AMainMenuGameMode::CastToDifficultyMenuWidget()
{
    if (!DifficultyMenuWidgetClass) {return;}
    DifficultyMenuWidget = CreateWidget<UDifficultyMenuWidget>(GetWorld(), DifficultyMenuWidgetClass);
    if (!DifficultyMenuWidget) {return;}
    DifficultyMenuWidget->AddToViewport();
}

void AMainMenuGameMode::SetMouseCursorVisibility(const bool& bShowMouseCursor)
{
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PlayerController) {return;}
    PlayerController->SetShowMouseCursor(bShowMouseCursor);
}