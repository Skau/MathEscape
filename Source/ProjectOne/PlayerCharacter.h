// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class AChangeNumberButton;

UCLASS()
class PROJECTONE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bIsCloseEnough = false;

	AChangeNumberButton* Button;

	// Handles input for moving forward and backward.
	UFUNCTION()
	void MoveX(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
	void MoveY(float Value);

	UFUNCTION()
	void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	float score = 2000;

	void TickScore(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetbHitTrigger();

	bool bHitTrigger = false;
};
