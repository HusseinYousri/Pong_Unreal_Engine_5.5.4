// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPaddle.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"
#include "PongGameInstance.h"

// Sets default values
AEnemyPaddle::AEnemyPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseCollision = CreateDefaultSubobject<UBoxComponent>("EnemyPaddle BaseCollision");
	RootComponent = BaseCollision;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("EnemyPaddle MeshComp");
	MeshComp->SetupAttachment(BaseCollision);

}

void AEnemyPaddle::BeginPlay()
{
	Super::BeginPlay();

	if (!bCanControlSpeed)
	{
		UPongGameInstance* GameInstance = Cast<UPongGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

    	if (GameInstance)
    	{
        	switch (GameInstance->GetDifficulty())
        	{
           	 	case EGameDifficulty::Easy:      TrackSpeed = 6.0f; break;
            	case EGameDifficulty::Medium:    TrackSpeed = 8.0f; break;
            	case EGameDifficulty::Hard:      TrackSpeed = 11.0f; break;
        	}
    	}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Remember You Have bCanControlSpeed set to true!"));
	}
	
}

// Called every frame
void AEnemyPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Continuously track the ball, since it may get destroyed
	FindBallActor();

	// Track the ball's Y position.
	TrackLogic(DeltaTime);
}

void AEnemyPaddle::TrackLogic(const float& DeltaTime)
{
	if (!Ball) {return;}
	FVector CurrentLocation = GetActorLocation();
	FVector BallLocation = Ball->GetActorLocation();
	FVector NewTarget = GetActorLocation();

	// Smoothly track ball Y-Axis
	NewTarget.Y = FMath::FInterpTo(CurrentLocation.Y, BallLocation.Y, DeltaTime, TrackSpeed);

	SetActorLocation(NewTarget);
}

void AEnemyPaddle::FindBallActor()
{
	TArray<AActor*> BallActor;
	UGameplayStatics::GetAllActorsOfClass(this, ABall::StaticClass(), BallActor);

	for (AActor* Actor : BallActor)
	{
		if (Actor)
		{
			Ball = Cast<ABall>(Actor);
		}
	}
}
