// Fill out your copyright notice in the Description page of Project Settings.

#include "Rebound_4_12.h"
#include "R_A_Mutator.h"


// Sets default values
AR_A_Mutator::AR_A_Mutator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AR_A_Mutator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AR_A_Mutator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

