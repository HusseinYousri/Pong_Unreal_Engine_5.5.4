// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PongGameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameDifficulty : uint8
{
    Easy,
    Medium,
    Hard
};


UCLASS()
class PONGSURVIVAL_API UPongGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "Difficulty")
    void SetDifficulty(EGameDifficulty NewDifficulty);

    UFUNCTION(BlueprintCallable, Category = "Difficulty")
    EGameDifficulty GetDifficulty() const { return CurrentDifficulty; }

private:
    EGameDifficulty CurrentDifficulty = EGameDifficulty::Easy;
};
