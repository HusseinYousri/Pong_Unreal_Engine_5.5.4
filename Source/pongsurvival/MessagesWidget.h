// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MessagesWidget.generated.h"

/**
 * 
 */
UCLASS()
class PONGSURVIVAL_API UMessagesWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// === GameOver Related ===
	UPROPERTY(BlueprintReadOnly, Category = "GameOver")
	FText GameOverText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* GameOverAnimation;
	
	// === Functions ===
	void PlayGameOverAnimation();

};
