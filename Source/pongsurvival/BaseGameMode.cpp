// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"
#include "GameplayWidget.h"
#include "MessagesWidget.h"

ABaseGameMode::ABaseGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABaseGameMode::BeginPlay()
{
    Super::BeginPlay();

    AddGamePlayWidgetToViewport();
    AddMessagesWidgetToViewport();
}

void ABaseGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Continuously update the scores
    UpdateScores();

    // Check Win Condition
    WinCheck();
}

void ABaseGameMode::GameOverMessageAndAnimation(FString NewGameOverText)
{
    if (!MessagesWidget) {return;}
    MessagesWidget->GameOverText = FText::FromString(NewGameOverText);
    MessagesWidget->PlayGameOverAnimation();
}   

void ABaseGameMode::AddMessagesWidgetToViewport()
{
    MessagesWidget = CreateWidget<UMessagesWidget>(GetWorld(), MessagesWidgetClass);
    if (!MessagesWidget) {return;}
    MessagesWidget->AddToViewport();
}

void ABaseGameMode::AddGamePlayWidgetToViewport()
{
    GameplayWidget = CreateWidget<UGameplayWidget>(GetWorld(), GameplayWidgetClass);
    if (!GameplayWidget) {return;}
    GameplayWidget->AddToViewport();
}

void ABaseGameMode::UpdateScores()
{
    if (!GameplayWidget) {return;}
    GameplayWidget->PlayerScoreInt = PlayerScore;
    GameplayWidget->EnemyScoreInt = EnemyScore;
}

void ABaseGameMode::WinCheck()
{
    if (!bSomeoneWon && PlayerScore >= MaxScore)
    {
        GameOverMessageAndAnimation("Player Win");
        DelayBeforeRestart();
        bSomeoneWon = true;
        bCanSpawnBall = false;
    }
    else if (!bSomeoneWon && EnemyScore >= MaxScore)
    {
        GameOverMessageAndAnimation("Enemy Win");
        DelayBeforeRestart();
        bSomeoneWon = true;
        bCanSpawnBall = false;
    }
}

void ABaseGameMode::DelayBeforeRestart()
{
    FTimerHandle RestartTimerHandle;
    GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &ABaseGameMode::RestartGame, DelayBeforeRestartTime, false);
}

void ABaseGameMode::RestartGame()
{
    FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
    UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}

void ABaseGameMode::BallTimerHandler()
{
    FTimerHandle SpawnBallTimerHandle;
    GetWorldTimerManager().SetTimer(SpawnBallTimerHandle, this, &ABaseGameMode::SpawnBall, TimerBeforeBallSpawn, false);
}

void ABaseGameMode::CallSpawnBall()
{
    BallTimerHandler();
}

void ABaseGameMode::SpawnBall()
{
    if (!bCanSpawnBall) {return;}
    if (!BallClass) {return;}
    GetWorld()->SpawnActor<ABall>(BallClass, BallSpawnLocation, FRotator::ZeroRotator);
}

void ABaseGameMode::IncreaseScore(bool bPlayerScored,int32 ScoreAmount)
{
    if (bPlayerScored)
    {
        PlayerScore += ScoreAmount;
    }
    else
    {
        EnemyScore += ScoreAmount;
    }
} 