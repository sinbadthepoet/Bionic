// Fill out your copyright notice in the Description page of Project Settings.


#include "Biped.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ABiped::ABiped()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABiped::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABiped::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABiped::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	auto* pc = Cast<APlayerController>(GetController());
	if (!pc) return;
	
	auto* subsystem = pc->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	subsystem->ClearAllMappings();
	subsystem->AddMappingContext(InputMappingContext, 0);
	
	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABiped::Move);
	EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABiped::Look);
	EIC->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ABiped::Jump);
	EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ABiped::StopJumping);
}

void ABiped::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(GetActorRightVector(), Input.X);
	AddMovementInput(GetActorForwardVector(), Input.Y);
}

void ABiped::Look(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddControllerYawInput(Input.X);
	AddControllerPitchInput(-Input.Y);
}
