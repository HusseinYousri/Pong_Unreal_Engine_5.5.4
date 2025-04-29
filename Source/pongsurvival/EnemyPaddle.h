// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyPaddle.generated.h"

// Forward Decleration
class UBoxComponent;

UCLASS()
class PONGSURVIVAL_API AEnemyPaddle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	float myspeed;

private:

	// === Components ===
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UBoxComponent* BaseCollision;

	// === Behavior ===
	UPROPERTY(EditAnyWhere, Category = "Behavior")
	bool bCanControlSpeed  = false;

	UPROPERTY(EditAnyWhere, Category = "Behavior")
	FVector Speed;

	UPROPERTY(EditAnyWhere, Category = "Behavior");
	float TrackSpeed = 8.0f;

	// === Functions ===
	void TrackLogic(const float& DeltaTime);
	void FindBallActor();

	// === Variables ===
	bool bCanMove = true;
	FVector StartLocation;

	// === Classes Refrences ===
	class ABall* Ball;
};
