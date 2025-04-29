// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

// Forward Declerations
class UBoxComponent;

UCLASS()
class PONGSURVIVAL_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

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

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// === Sounds ===
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* SFX_BallHit;

	// == Functions ===
	void MoveLogic(const float& DeltaTime);
	void ReverseX();
	void ReverseY();
	void RandYDirection();
	void RandXDirection();
	void PlayHitSound();

	// === Movement ===
	UPROPERTY(EditAnyWhere, Category = "Movement")
	FVector Speed;

	UPROPERTY(EditAnyWhere, Category = "Movement")
	float SpeedRatePerHit = 150.0f;

	// === Delegetes ===
	UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// === Variables ===
	FVector StartLocation;
};
