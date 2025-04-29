// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

// Forward Decleration
class UBoxComponent;
class UInputMappingContext;
class UInputAction;
class UFloatingPawnMovement;

UCLASS()
class PONGSURVIVAL_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	// === Components ===
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UBoxComponent* BaseCollision;

	UPROPERTY(EditAnywhere, Category = "Components")
	ACameraActor* CurrentCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UFloatingPawnMovement* PawmMovement;

	// === Input ===
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Move;

	// === Functions ===
	void AddMappingContext();
	void Move(const struct FInputActionValue& Value);
	void SetViewCamera();

};
