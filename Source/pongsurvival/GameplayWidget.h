// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayWidget.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API UGameplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// === Gameplay Variables ===
	UPROPERTY(BlueprintReadOnly)
	int PlayerScoreInt = 0;

	UPROPERTY(BlueprintReadOnly)
	int EnemyScoreInt = 0;
};
