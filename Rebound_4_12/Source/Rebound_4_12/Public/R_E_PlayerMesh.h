// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "R_E_PlayerMesh.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ER_E_PlayerMesh : uint8
{	
	PM_Male	UMETA(DisplayName="Male"),
	PM_Female	UMETA(DisplayName = "Female"),
	PM_Ninja	UMETA(DisplayName = "Ninja"),
	PM_Heavy	UMETA(DisplayName = "Heavy"),
	
	
};
