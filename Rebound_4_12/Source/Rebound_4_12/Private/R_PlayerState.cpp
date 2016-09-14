// Fill out your copyright notice in the Description page of Project Settings.

#include "Rebound_4_12.h"
#include "R_PlayerState.h"
#include "UnrealNetwork.h"

void AR_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Emerald, FString::FromInt(PlayerNum));
	}
}

void AR_PlayerState::CopyProperties(class APlayerState * PlayerState)
{
	Super::CopyProperties(PlayerState);

	AR_PlayerState* newPlayerState = Cast<AR_PlayerState>(PlayerState);

	if (newPlayerState)
	{
		newPlayerState->PlayerNum = PlayerNum;
		newPlayerState->PlayerScore = PlayerScore;
		newPlayerState->CusChar = CusChar;
	}
}

AR_PlayerState::AR_PlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AR_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AR_PlayerState, PlayerNum);
	DOREPLIFETIME(AR_PlayerState, PlayerScore);
	DOREPLIFETIME(AR_PlayerState, CusChar);
}
