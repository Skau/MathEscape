// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "ChangeNumberButton.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
}

void APlayerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (OtherActor->IsA(AChangeNumberButton::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Is close enough"))
			bIsCloseEnough = true;
			Button = Cast<AChangeNumberButton>(OtherActor);
		}
	}
}

void APlayerCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (OtherActor->IsA(AChangeNumberButton::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Is not close enough"))
			bIsCloseEnough = false;
		}
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnOverlapBegin);
	// set up a notification for when this component overlaps something  
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::OnOverlapEnd);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickScore(DeltaTime);
}

void APlayerCharacter::TickScore(float DeltaTime)
{
	if (!bHitTrigger)
	{
		score -= (5 * DeltaTime);
	}
}

void APlayerCharacter::SetbHitTrigger()
{
	bHitTrigger = true;
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		// Moving functions
		PlayerInputComponent->BindAxis("MoveX", this, &APlayerCharacter::MoveX);
		PlayerInputComponent->BindAxis("MoveY", this, &APlayerCharacter::MoveY);

		// Looking functions
		PlayerInputComponent->BindAxis("LookPitch", this, &APlayerCharacter::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("LookYaw", this, &APlayerCharacter::AddControllerYawInput);

		PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
	}
}

void APlayerCharacter::MoveX(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::MoveY(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::Interact()
{
	if (bIsCloseEnough)
	{
		Button->CycleNumbers();
	}
}