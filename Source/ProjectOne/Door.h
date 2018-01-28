// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class ARoom;
class UOpenDoorComponent;

UCLASS()
class PROJECTONE_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int GetSumToOpen() { return SumToOpen; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ARoom* Room;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int SumToOpen = 100;

private:

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int SumFromRoom;

	UPROPERTY(VisibleAnywhere)
	UOpenDoorComponent* DoorComponent;

};