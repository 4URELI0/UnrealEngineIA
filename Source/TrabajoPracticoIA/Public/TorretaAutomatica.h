// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorretaAutomatica.generated.h"

UCLASS()
class TRABAJOPRACTICOIA_API ATorretaAutomatica : public AActor
{
    GENERATED_BODY()

public:
    ATorretaAutomatica();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USceneComponent* CustomRootComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TorretaComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* PivotArma;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* ArmaTorreta;

    UPROPERTY(VisibleAnywhere, Category = "Torreta")
    ACharacter* PC;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    bool bPuedeApuntar = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    float VelocidadRotacion = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    float Rango = 1000.0f;

    UFUNCTION(BlueprintCallable, Category = "Torreta")
    FRotator ApuntarJugador(ACharacter* Target);
};