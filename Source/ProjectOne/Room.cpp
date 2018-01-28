// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "TextComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Door.h"


// Sets default values
ARoom::ARoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	NumbersToChooseFrom.SetNum(3);

}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!RoomToGetX) { return; }
	if (!RoomToGetY)
	{
		TotalSum = DoMaths(Operator, RoomToGetX->GetTotalSum());
		FString SumString = FString::FromInt(TotalSum);
	}
	else if (!RoomToGetZ)
	{
		TotalSum = DoMaths(Operator, RoomToGetX->GetTotalSum(), RoomToGetY->GetTotalSum());
		FString SumString = FString::FromInt(TotalSum);
	}
	else
	{
		TotalSum = DoMaths(Operator, RoomToGetX->GetTotalSum(), RoomToGetY->GetTotalSum(), RoomToGetZ->GetTotalSum());
		FString SumString = FString::FromInt(TotalSum);
	}
}

int ARoom::DoMaths(EOperators Value, int X, int Y, int Z)
{
	int Sum = 0;
	switch (Value)
	{
	case EOperators::NONE:

		break;
	case EOperators::ADD:
		Sum = Add(X, Y, Z);
		break;
	case EOperators::SUBTRACT:
		Sum = Minus(X, Y, Z);
		break;
	case EOperators::MULTIPLY:
		Sum = Multiply(X, Y, Z);
		break;
	default:
		break;
	}
	return Sum;
}

int ARoom::Multiply(int X, int Y, int Z)
{
	if (Y == 0)
	{
		Y = 1;
	}
	if (Z == 0)
	{
		Z = 1;
	}

	return X * Y * Z;

}