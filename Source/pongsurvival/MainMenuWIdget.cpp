// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWIdget.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuGameMode.h"


void UMainMenuWIdget::NativeConstruct()
{
    Super::NativeConstruct();
    
    CastToGameMode();
}

void UMainMenuWIdget::CallStartGame()
{
    if (!MainMenuGameMode) {return;}
    MainMenuGameMode->CastToDifficultyMenuWidget();
    MainMenuGameMode->UnShowMainMenuWidget();
}

void UMainMenuWIdget::CastToGameMode()
{
    MainMenuGameMode = Cast<AMainMenuGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (!MainMenuGameMode) {return;}
}