// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWIdget.h"

void AMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (!MainMenuWidgetClass) {return;}
    UUserWidget* MainMenuWidget = CreateWidget<UMainMenuWIdget>(GetWorld(), MainMenuWidgetClass);
    if (!MainMenuWidget) {return;}

    MainMenuWidget->AddToViewport();
    UE_LOG(LogTemp, Warning, TEXT("Added"));
}

void AMainMenuGameMode::StartGame()
{
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("Main"));
}