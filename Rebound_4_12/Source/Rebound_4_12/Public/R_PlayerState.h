// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"

#include "R_S_CustomCharacter.h"
#include "Net/UnrealNetwork.h"

#include "R_PlayerState.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class REBOUND_4_12_API AR_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)//, Replicated)
		int32 PlayerNum;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)//, Replicated)
		int32 PlayerScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)//, Replicated)
		FR_S_CustomCharacter CusChar;

	//constructor
	AR_PlayerState();

	//event tick
	virtual void Tick(float DeltaSeconds) override;


	//void AR_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutlifetimeProps) const
	//{
	//	//Super::GetLifetimeReplicatedProps(OutlifetimeProps);

	//	DOREPLIFETIME(AR_PlayerState, PlayerNum);
	//	DOREPLIFETIME(AR_PlayerState, PlayerScore);
	//	DOREPLIFETIME(AR_PlayerState, CusChar);
	//}
};
