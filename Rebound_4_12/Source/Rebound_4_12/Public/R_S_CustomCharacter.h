// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedStruct.h"

#include "R_E_PlayerMesh.h"

#include "R_S_CustomCharacter.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FR_S_CustomCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colour")
		FLinearColor CharColour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		USkeletalMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		ER_E_PlayerMesh MeshEnum;

	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = "Mesh")
		UMaterialInstance* MatInst;
	
	
};
