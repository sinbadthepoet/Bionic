// Fill out your copyright notice in the Description page of Project Settings.


#include "Biped.h"

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

}

