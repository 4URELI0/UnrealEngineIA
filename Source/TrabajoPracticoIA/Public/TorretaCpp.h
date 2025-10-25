// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorretaCpp.generated.h"

UCLASS()
class TRABAJOPRACTICOIA_API ATorretaCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorretaCpp();
	/*UPROPERTY(VisibleAnywhere, Category = "Components");
	USceneComponent* customRootComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components");
	UStaticMeshComponent* torretaComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components");
	UStaticMeshComponent* pivotArma;

	UPROPERTY(VisibleAnywhere, Category = "Components");
	UStaticMeshComponent* armaTorreta;


	float anguloGiro;

	float tiempoRotacion;

	float rangoVision;

	float tiempoRotacion, anguloActual = 0.0f;
	FTimerHandle timerHandle;*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GirarTorreta();
};
