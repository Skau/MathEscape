// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTONE_API UOpenDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoorComponent();

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool GetbIsOpen() { return bIsOpen; }

	UPROPERTY(EditAnywhere, Category = "Setup")
	bool bIsOpen = false;

};