// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"

#include "R_S_CustomCharacter.h"
#include "UnrealNetwork.h"

#include "R_PlayerState.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class REBOUND_4_12_API AR_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		int32 PlayerNum = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		int32 PlayerScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		FR_S_CustomCharacter CusChar;

	//constructor
	AR_PlayerState(const FObjectInitializer& ObjectInitializer);

	//event tick
	virtual void Tick(float DeltaSeconds) override;

	virtual void CopyProperties(class APlayerState * PlayerState) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutlifetimeProps) const;

};
