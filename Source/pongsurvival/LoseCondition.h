// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoseCondition.generated.h"

// Forward Declerations
class UBoxComponent;

UCLASS()
class PONGSURVIVAL_API ALoseCondition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoseCondition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// === Components ===
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UBoxComponent* BoxComp;

	// === Delegetes ===
	UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// === Classes Refrences ===
	class ABaseGameMode* GameMode;

	// === Sounds ===
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* SFX_Scored;

	// === Functions ===
	void PlayScoringSound();
};
