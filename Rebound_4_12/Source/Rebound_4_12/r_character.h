// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "r_character.generated.h"

UCLASS()
class REBOUND_4_12_API Ar_character : public ACharacter
{
	GENERATED_BODY()

private:
	FVector camDir;

public:
	UPROPERTY(EditAnywhere)
		int playerID;
	UPROPERTY(EditAnywhere)
		bool bDisableMovment;
	UPROPERTY(EditAnywhere)
		bool bDisableAim;
	UPROPERTY(EditAnywhere)
		bool bInvincible;
	UPROPERTY(EditAnywhere)
		bool bCanDash;
	UPROPERTY(EditAnywhere)
		bool bIsDashing;
	UPROPERTY(EditAnywhere)
		bool bIsStunned;
	UPROPERTY(EditAnywhere, Category="Dash")
		float dashTimer;
	UPROPERTY(EditAnywhere, Category = "Dash")
		float dashCoolDown;	
	UPROPERTY(EditAnywhere, Category = "Dash")
		float dashSpeed;
	UPROPERTY(EditAnywhere, Category = "Dash")
		FVector dashVector;
	UPROPERTY(EditAnywhere, Category = "Dash")
		FTimerHandle dashHandle;
	UPROPERTY(EditAnyWhere, Category = "Dash")
		UParticleSystem* dashParticle;
	UPROPERTY(EditAnyWhere, Category = "Dash")
		UParticleSystem* dashCooldownParticle;
	UPROPERTY(EditAnywhere, Category = "Dash")
		UStaticMeshComponent* dashCoolDownMesh;
	UPROPERTY(EditAnywhere, Category = "Dash")
		UAudioComponent* dashCooldownAudio;
	UPROPERTY(EditAnywhere, Category = "Dash")
		UAudioComponent* dashReadyAudio;
	UPROPERTY(EditAnywhere, Category = "Dash")
		UAudioComponent* dashAudio;

	// Sets default values for this character's properties
	Ar_character();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

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
