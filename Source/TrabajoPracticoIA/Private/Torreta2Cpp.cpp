// Fill out your copyright notice in the Description page of Project Settings.


#include "Torreta2Cpp.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"

// Sets default values
ATorreta2Cpp::ATorreta2Cpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PC = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	customRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Custom Root"));
	RootComponent = customRootComponent;

	torretaComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torreta"));
	torretaComponent->SetupAttachment(customRootComponent);

	pivotArma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pivote"));
	pivotArma->SetupAttachment(torretaComponent);

	armaTorreta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmaTorreta"));
	armaTorreta->SetupAttachment(pivotArma);
}

// Called when the game starts or when spawned
void ATorreta2Cpp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATorreta2Cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FRotator ATorreta2Cpp::ApuntarJugador(ACharacter* target)
{
	FVector posTarget = target->GetActorLocation();
	FVector direccionTorreta = posTarget - pivotArma->GetComponentLocation();
	FRotator rotacionActualTorreta = direccionTorreta.Rotation();
	return rotacionActualTorreta;
}