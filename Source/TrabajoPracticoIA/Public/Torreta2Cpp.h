// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Torreta2Cpp.generated.h"

UCLASS()
class TRABAJOPRACTICOIA_API ATorreta2Cpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorreta2Cpp();
	UPROPERTY(VisibleAnywhere)
	ACharacter* PC;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* customRootComponent;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* torretaComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* pivotArma;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* armaTorreta;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Torreta")
	FRotator ApuntarJugador(ACharacter* target);
};
