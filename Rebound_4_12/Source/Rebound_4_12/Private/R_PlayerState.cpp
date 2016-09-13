// Fill out your copyright notice in the Description page of Project Settings.

#include "Rebound_4_12.h"
#include "R_PlayerState.h"

AR_PlayerState::AR_PlayerState()
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AR_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Emerald, FString::FromInt(PlayerNum));
}
