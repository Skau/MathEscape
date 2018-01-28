// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

class UTextComponent;
class ADoor;

UENUM(BlueprintType)
enum class EOperators : uint8
{
	NONE,
	ADD,
	SUBTRACT,
	MULTIPLY

};

UCLASS()
class PROJECTONE_API ARoom : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	int GetTotalSum() { return TotalSum; }

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int TotalSum = 0;

	int Add(int X, int Y = 0, int Z = 0) { return X + Y + Z; }
	int Minus(int X, int Y = 0, int Z = 0) { return X - Y - Z; }
	int Multiply(int X, int Y, int Z);

	UPROPERTY(EditAnywhere)
	EOperators Operator = EOperators::NONE;

	TArray<int> GetNumbersToChooseFrom() { return NumbersToChooseFrom; }

	UPROPERTY(EditAnywhere, Category="Setup")
	TArray<int> NumbersToChooseFrom;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ARoom* RoomToGetX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ARoom* RoomToGetY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ARoom* RoomToGetZ;

	int DoMaths(EOperators Value, int X, int Y = 0, int Z = 0);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};