// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Room.h"
#include "OpenDoorComponent.h"

// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorComponent = CreateDefaultSubobject<UOpenDoorComponent>(TEXT("OpenDoorComponent"));

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Room) { return; }
	SumFromRoom = Room->GetTotalSum();

	if (SumFromRoom == SumToOpen)
	{
		DoorComponent->bIsOpen = true;
	}
	else
	{
		DoorComponent->bIsOpen = false;
	}


}