// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextRenderActor.h"
#include "TextActor.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTONE_API ATextActor : public ATextRenderActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ARoom* Room;
};
