// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/BoxComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraActor.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseCollision = CreateDefaultSubobject<UBoxComponent>("BasePawn BaseCollision");
	RootComponent = BaseCollision;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("BasePawn MeshComp");
	MeshComp->SetupAttachment(BaseCollision);

	PawmMovement = CreateDefaultSubobject<UFloatingPawnMovement>("BasePawn PawnMovement");
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
	// As if you didn't know :/
	SetViewCamera();
	AddMappingContext();
}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput) {return;}

	// Bind Actions here
	if (IA_Move)
	{
		EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABasePawn::Move);
	}
}

void ABasePawn::Move(const struct FInputActionValue& Value)
{
	FVector2D MovementValue = Value.Get<FVector2D>();
	
	const FRotator Rotation = GetController()->GetControlRotation();
	
	const FVector MoveDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
	
	AddMovementInput(MoveDirection, MovementValue.X);
}

void ABasePawn::AddMappingContext()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) {return;}

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	if (!SubSystem) {return;}

	if (!MappingContext) {return;}
	SubSystem->AddMappingContext(MappingContext, 0);
}

void ABasePawn::SetViewCamera()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) {return;}
	if (!CurrentCamera) {return;}
	PC->SetViewTarget(CurrentCamera);
}