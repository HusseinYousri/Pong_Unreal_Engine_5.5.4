// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ABaseGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// === Public Functions ===
	void CallSpawnBall();	
	void IncreaseScore(bool bPlayerScored,int32 ScoreAmount);

private:
	
	// === Functions ===
	void RestartGame();
	void WinCheck();
	void DelayBeforeRestart();
	void AddGamePlayWidgetToViewport();
	void AddMessagesWidgetToViewport();
	void GameOverMessageAndAnimation(FString NewGameOverText);
	void SpawnBall();
	void BallTimerHandler();

	// === Exposed Functions ===
	UFUNCTION(BlueprintCallable, Category = "Score")
	void UpdateScores();

	// === Variables ===
	bool bSomeoneWon = false; // Might need it in the future
	bool bCanSpawnBall = true;

	// === Game Behavior ===
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Behavior", meta = (AllowPrivateAccess = "true"))
	float TimerBeforeBallSpawn = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Behavior", meta = (AllowPrivateAccess = "true"))
	int32 MaxScore = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Behavior", meta = (AllowPrivateAccess = "true"))
	FVector BallSpawnLocation = FVector(0.0f, 0.0f, 60.0f);

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Game Behavior", meta = (AllowPrivateAccess = "true"))
	float DelayBeforeRestartTime = 3.0f;

	// === Score Related ===
	UPROPERTY(BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int PlayerScore = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int EnemyScore = 0;

	// === Classes Refrences ===
	class UGameplayWidget* GameplayWidget;
	class UMessagesWidget* MessagesWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Classes Refrences")
	TSubclassOf<class UGameplayWidget> GameplayWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Classes Refrences")
	TSubclassOf<class ABall> BallClass;

	UPROPERTY(EditDefaultsOnly, Category = "Classes Refrences")
	TSubclassOf<class UMessagesWidget> MessagesWidgetClass;
};
