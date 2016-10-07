// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedStruct.h"

#include "R_A_Mutator.h"

#include "R_S_LevelStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FR_S_LevelStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
		FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
		int32 Rounds;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
		AR_A_Mutator* Mutator;
	
};
