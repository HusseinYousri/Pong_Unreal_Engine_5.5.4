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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// === Public Functions ===
	void SpawnBall();	
	void IncreaseScore(bool bPlayerScored,int32 ScoreAmount);

private:

	// === Functions ===
	void PauseGame();
	void ResumeGame();
	void RestartGame();
	void WinCheck();

	// === Variables ===
	UPROPERTY(BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int PlayerScore = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int EnemyScore = 0;

	// === Classes Refrences ===
	UPROPERTY(EditDefaultsOnly, Category = "Classes Refrences")
	TSubclassOf<class ABall> BallClass;
};
