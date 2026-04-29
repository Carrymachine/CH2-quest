// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TotalDistance = 0.0f;
	MoveCount = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	PrevLocation = GetActorLocation();
	
	for (int32 i = 0; i < 10; i++)
	{
		bool CanMove = FMath::RandBool();
		if (CanMove)
		{
			TriggerEvent(i);
		}
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyActor::Move()
{
	FVector Target;

	// -50 ~ 50 randomeFloat
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;

	AddActorWorldOffset(Target);

}

void AMyActor::Turn()
{
	FRotator DeltaRotation;

	DeltaRotation.Yaw = FMath::FRandRange(-180.0, 180.0);
	DeltaRotation.Pitch = 0;
	DeltaRotation.Roll = 0;

	AddActorWorldRotation(DeltaRotation);
}

void AMyActor::TriggerEvent(int key)
{
	int32 BaseCountKey = MoveCount * 10 + key ;
	MoveCount++;
	Move();
	Turn();
	CurrentLocation = GetActorLocation();
	TotalDistance += FVector::Dist(PrevLocation,CurrentLocation);
	
	
	if (GEngine)
	{
		GEngine -> AddOnScreenDebugMessage(BaseCountKey + 1, 5, FColor::Red, FString::Printf(TEXT("Prev: %ls"),*PrevLocation.ToString()));
		GEngine -> AddOnScreenDebugMessage(BaseCountKey + 2, 5, FColor::Red, FString::Printf(TEXT("Current: %ls"),*CurrentLocation.ToString()));
		GEngine -> AddOnScreenDebugMessage(BaseCountKey + 3, 5, FColor::Red, FString::Printf(TEXT("TotalDist: %f"),TotalDistance));
		GEngine -> AddOnScreenDebugMessage(BaseCountKey + 4, 5, FColor::Red, FString::Printf(TEXT("MoveCount: %d"),MoveCount));
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Init: %s"), *PrevLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Current: %s"), *CurrentLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Acc: %f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("MoveCount: %d"), MoveCount);
	
	PrevLocation = CurrentLocation;
}
