// Fill out your copyright notice in the Description page of Project Settings.


#include "TorretaCpp.h"

// Sets default values
ATorretaCpp::ATorretaCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	anguloGiro = 45;
	tiempoRotacion = 3.0f;
	timerHandle;

	/*Crear al objeto en el BP*/
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
void ATorretaCpp::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(
		timerHandle,
		this,
		&ATorretaCpp::GirarTorreta,
		tiempoRotacion,
		true
	);
}

// Called every frame
void ATorretaCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATorretaCpp::GirarTorreta()
{
	FRotator incremento = FRotator(0.0f, anguloGiro, 0.0f);
	pivotArma->AddRelativeRotation(incremento);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, pivotArma->GetRelativeRotation().ToString());
	}
}