// Fill out your copyright notice in the Description page of Project Settings.

#include "Rebound_4_12.h"
#include "r_character.h"


// Sets default values
Ar_character::Ar_character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ar_character::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Ar_character::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (GEngine) camDir = FVector(0,0,GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraRotation);

}

// Called to bind functionality to input
void Ar_character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void Ar_character::MoveVertical(float inputAxisY)
{
	if (!bDisableMovment) AddMovementInput(camDir.ForwardVector, inputAxisY);
}

void Ar_character::MoveHorizontal(float inputAxisX)
{
	if (!bDisableMovment) AddMovementInput(camDir.RightVector, inputAxisX);
}


