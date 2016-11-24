// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"

#include "UnrealNetwork.h"

#include "r_character.generated.h"

UCLASS()
class REBOUND_4_12_API Ar_character : public ACharacter
{
	GENERATED_BODY()

private:
	FRotator camRot;

public:
	//TODO find variables that dont need to be replicated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		int playerID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bDisableMovment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bDisableAim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bInvincible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bCanDash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool DisableActions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bIsDashing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool bIsStunned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Dash")
		float dashTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Dash")
		float dashCoolDownTimer;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Dash")
		float dashSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Dash")
		FVector dashVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Dash")
		FTimerHandle dashHandle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Dash")
		UParticleSystem* dashParticle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Dash")
		UParticleSystem* dashCooldownParticle;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Dash")
		USceneComponent* dashCoolDownMesh;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Dash")
		USceneComponent* dashCooldownAudio;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Dash")
		USceneComponent* dashReadyAudio;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Dash")
		USceneComponent* dashAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Basic Movement")
		float RunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Basic Movement")
		float ChargeRunSpeed;

	// Sets default values for this character's properties
	Ar_character();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//sets variables as replicated
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutlifetimeProps) const;

	UFUNCTION(BlueprintCallable, Category="Movement")
		void MoveVertical(float inputAxisY);
	
	UFUNCTION(BlueprintCallable, Category="Movement")
		void MoveHorizontal(float inputAxisX);

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void DashToggle();

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void DashCoolDownToggle();

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void DashCancel();
};
