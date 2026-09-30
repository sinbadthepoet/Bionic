// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Biped.generated.h"

struct FInputActionValue;

UCLASS()
class BIONIC_API ABiped : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABiped();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// INPUT
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;
	
	// ACTIONS
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
