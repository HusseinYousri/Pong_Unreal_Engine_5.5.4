// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseCondition.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BaseGameMode.h"

// Sets default values
ALoseCondition::ALoseCondition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("LoseCondition BoxComp");
	RootComponent = BoxComp;
}

// Called when the game starts or when spawned
void ALoseCondition::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ABaseGameMode>(UGameplayStatics::GetGameMode(this));
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ALoseCondition::OnOverlapBegin);
}

// Called every frame
void ALoseCondition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALoseCondition::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || !GameMode) {return;}

	bool bIsPlayerNet = ActorHasTag("playernet");
	bool bIsEnemyNet = ActorHasTag("enemynet");

	// Destroy current ball and respawn another
	OtherActor->Destroy();
	GameMode->SpawnBall();

	if (bIsPlayerNet)
	{
		GameMode->IncreaseScore(false, 1);
		PlayScoringSound();
	}
	
	else if (bIsEnemyNet)
	{
		GameMode->IncreaseScore(true, 1);
		PlayScoringSound();
	}

}

void ALoseCondition::PlayScoringSound()
{
	if (!SFX_Scored) {return;}
	UGameplayStatics::PlaySound2D(GetWorld(), SFX_Scored);
}