// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
#include "EscapeZone.generated.h"

class UBoxComponent;

UCLASS()
class THIRDPERSONSTEALTH_API AEscapeZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapeZone();

protected:

	UPROPERTY(VisibleAnywhere, Category="Components")
	UBoxComponent* OverlapBox;

	UFUNCTION()
	void ActivateEscape(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:	

	
	
};
