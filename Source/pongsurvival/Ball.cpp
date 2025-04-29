// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>("Ball Sphere Comp");
	RootComponent = BoxComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh Comp");
	MeshComp->SetupAttachment(BoxComp);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	// Randomize initial ball direction
	RandYDirection();
	RandXDirection();

	// Initialize overlap delegate
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlapBegin);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update movement
	MoveLogic(DeltaTime);
}

void ABall::MoveLogic(const float& DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += Speed * DeltaTime;

	SetActorLocation(CurrentLocation);
}

void ABall::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor) {return;}

	// Play sound specific to the collision event.
    // Different collision types require different sounds.

	if (OtherActor->ActorHasTag("player"))
	{
		ReverseX();
		Speed.Y += -SpeedRatePerHit;
		Speed.X += SpeedRatePerHit;
		PlayHitSound();
	}

	else if (OtherActor->ActorHasTag("enemy"))
	{
		Speed.X += SpeedRatePerHit;
		Speed.Y += SpeedRatePerHit;
		ReverseX();
		PlayHitSound();
	}

	else if (OtherActor->ActorHasTag("topwall"))
	{
		ReverseY();
		PlayHitSound();
	}
}

void ABall::ReverseX()
{
	Speed.X = -Speed.X;
}

void ABall::ReverseY()
{
	Speed.Y = -Speed.Y;
}

void ABall::PlayHitSound()
{
	if (!SFX_BallHit) {return;}
	UGameplayStatics::PlaySound2D(GetWorld(), SFX_BallHit);
}

void ABall::RandYDirection()
{
	int32 RandomY = FMath::RandRange(1,6);
	switch(RandomY)
	{
		case 1:
		Speed.Y = 1200.0f;
		return;

		case 2:
		Speed.Y = -1200.0f;
		return;

		case 3:
		Speed.Y = 1300.0f;
		return;

		case 4:
		Speed.Y = -1300.0f;
		return;

		case 5:
		Speed.Y = 1400.0f;
		return;

		case 6:
		Speed.Y = -1400.0f;
		return;
	}
}

void ABall::RandXDirection()
{
	int32 RandomX = FMath::RandRange(1,6);
	switch (RandomX)
	{
		case 1:
		Speed.X = 1800.0f;
		return;

		case 2:
		Speed.X = -1800.0f;
		return;

		case 3:
		Speed.X = 1700.0f;
		return;

		case 4:
		Speed.X = -1700.0f;
		return;

		case 5:
		Speed.X = 2000.0f;
		return;

		case 6:
		Speed.X = -2000.0f;
		return;
	}
}