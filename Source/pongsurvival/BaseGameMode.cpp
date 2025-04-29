// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"

ABaseGameMode::ABaseGameMode()
{
    // Enable ticking
    PrimaryActorTick.bCanEverTick = true;
}

void ABaseGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Win check
    WinCheck();
}

void ABaseGameMode::WinCheck()
{
    if (PlayerScore == 10)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Win"));
        RestartGame();
    }
    else if (EnemyScore == 10)
    {
        UE_LOG(LogTemp, Warning, TEXT("Enemy Win"));
        RestartGame();
    }
}

void ABaseGameMode::RestartGame()
{
    FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
    UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}

void ABaseGameMode::PauseGame()
{   
    UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.01f);
	// Set a timer to reset the time dilation after 5 seconds
    FTimerHandle SlowMotionTimerHandle;
	GetWorldTimerManager().SetTimer(SlowMotionTimerHandle, this, &ABaseGameMode::ResumeGame, 0.03f, false);
}

void ABaseGameMode::ResumeGame()
{
    UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}   

void ABaseGameMode::SpawnBall()
{
    GetWorld()->SpawnActor<ABall>(BallClass, FVector(0.0f , 0.0f, 60.0f), FRotator::ZeroRotator);
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