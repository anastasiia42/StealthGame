// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeZone.h"
#include "Components/BoxComponent.h"
#include "ThirdPersonStealthCharacter.h"


// Sets default values
AEscapeZone::AEscapeZone()
{
	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("EscapeZoneOverlap"));
	OverlapBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapBox->SetBoxExtent(FVector(150));
	OverlapBox->SetHiddenInGame(false);
	RootComponent = OverlapBox;

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AEscapeZone::ActivateEscape);
}


void AEscapeZone::ActivateEscape(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AThirdPersonStealthCharacter* MyCharacter = Cast<AThirdPersonStealthCharacter>(OtherActor);

	if (MyCharacter && MyCharacter->IsCarryingObjective) {
		GIsRequestingExit = 1;
	}

}



