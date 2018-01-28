// Fill out your copyright notice in the Description page of Project Settings.

#include "ChangeNumberButton.h"
#include "Components/StaticMeshComponent.h"
#include "Room.h"

// Sets default values
AChangeNumberButton::AChangeNumberButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Mesh->bGenerateOverlapEvents = true;
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AChangeNumberButton::BeginPlay()
{
	Super::BeginPlay();
	Room->TotalSum = Room->GetNumbersToChooseFrom()[0];
	
}

// Called every frame
void AChangeNumberButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeNumberButton::CycleNumbers()
{
	TArray<int> Numbers = Room->GetNumbersToChooseFrom();
	int TotalNumbers = Numbers.Num() - 1;

	if (IndexPointer >= TotalNumbers)
	{
		IndexPointer = 0;
	}
	else
	{
		IndexPointer++;
	}
	CurrentNumberToShow = Numbers[IndexPointer];

	UE_LOG(LogTemp, Warning, TEXT("Current number: %d"), CurrentNumberToShow)
		Room->TotalSum = CurrentNumberToShow;
}