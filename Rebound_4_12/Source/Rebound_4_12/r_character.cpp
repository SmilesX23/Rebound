// Fill out your copyright notice in the Description page of Project Settings.

#include "Rebound_4_12.h"
#include "r_character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
Ar_character::Ar_character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	dashCoolDownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DashCoolDownMesh"));
	dashCoolDownMesh->SetupAttachment(RootComponent);
	dashReadyAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("DashReadyAudio"));
	dashReadyAudio->SetupAttachment(RootComponent);
	dashCooldownAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("DashCooldownAudio"));
	dashCooldownAudio->SetupAttachment(RootComponent);
	dashAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("DashAudio"));
	dashCooldownAudio->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void Ar_character::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Ar_character::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	camRot = FRotator(0, UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation().Yaw, 0);
}

// Called to bind functionality to input
void Ar_character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void Ar_character::MoveVertical(float inputAxisY)
{
	if (!bDisableMovment) AddMovementInput(UKismetMathLibrary::GetForwardVector(camRot), inputAxisY);
}

void Ar_character::MoveHorizontal(float inputAxisX)
{
	if (!bDisableMovment)
	{
		AddMovementInput(UKismetMathLibrary::GetRightVector(camRot), inputAxisX);

		FVector temp = UKismetMathLibrary::GetRightVector(camRot);
		FString VeryCleanString = FString::SanitizeFloat(inputAxisX);

		UE_LOG(LogTemp, Warning, TEXT("Your message %s"), *temp.ToString());
	}
}

void Ar_character::DashToggle()
{	
	if (bCanDash && !DisableActions)
	{
		if (!bIsDashing) {
			bDisableMovment = true;
			bIsDashing = true;
			bInvincible = true;
			GetCapsuleComponent()->SetSimulatePhysics(true);
			dashVector = GetActorForwardVector();
			GetCapsuleComponent()->AddImpulse(dashVector * dashSpeed);
			GetCapsuleComponent()->SetEnableGravity(false);
			GetWorld()->GetTimerManager().SetTimer(dashHandle, this, &Ar_character::DashToggle, dashTimer, false);
		}
		else
		{
			bDisableMovment = false;
			bIsDashing = false;
			bInvincible = false;
			GetCapsuleComponent()->SetSimulatePhysics(false);
			GetCapsuleComponent()->SetEnableGravity(true);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), dashParticle, GetActorTransform(), true);
			DashCoolDownToggle();
		}
	}
}

void Ar_character::DashCoolDownToggle()
{
	if (bCanDash) 
	{
		bCanDash = false;
		GetMesh()->SetScalarParameterValueOnMaterials("SpecialEmissiveStrength", 80.0f);
		dashCoolDownMesh->ToggleVisibility();
		GetWorld()->GetTimerManager().SetTimer(dashHandle, this, &Ar_character::DashCoolDownToggle, dashCoolDownTimer, false);
	}
	else
	{
		bCanDash = true;
		GetMesh()->SetScalarParameterValueOnMaterials("SpecialEmissiveStrength", 0.0f);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), dashCooldownParticle, GetActorTransform(), true);
		dashCoolDownMesh->ToggleVisibility();
	}
}

void Ar_character::DashCancel()
{
	if (bIsDashing) {
		GetWorld()->GetTimerManager().ClearTimer(dashHandle);
		DashToggle();
	}
}

void Ar_character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(Ar_character, playerID);
	DOREPLIFETIME(Ar_character, bDisableMovment);
	DOREPLIFETIME(Ar_character, bDisableAim);
	DOREPLIFETIME(Ar_character, bInvincible);
	DOREPLIFETIME(Ar_character, bCanDash);
	DOREPLIFETIME(Ar_character, DisableActions);
	DOREPLIFETIME(Ar_character, bIsDashing);
	DOREPLIFETIME(Ar_character, bIsStunned);
	DOREPLIFETIME(Ar_character, dashTimer);
	DOREPLIFETIME(Ar_character, dashCoolDownTimer);
	DOREPLIFETIME(Ar_character, dashSpeed);
	DOREPLIFETIME(Ar_character, dashVector);
	DOREPLIFETIME(Ar_character, dashHandle);
	DOREPLIFETIME(Ar_character, RunSpeed);
	DOREPLIFETIME(Ar_character, ChargeRunSpeed);
}

