// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "r_character.generated.h"

UCLASS()
class REBOUND_4_12_API Ar_character : public ACharacter
{
	GENERATED_BODY()

private:
	FVector camDir;

public:
	
	bool bDisableMovment;
	
	// Sets default values for this character's properties
	Ar_character();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveVertical(float inputAxisY);
	
	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveHorizontal(float inputAxisX);

};
