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
    // Sets default values for this actor's properties
    ATorretaAutomatica();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /** --- COMPONENTES --- */
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USceneComponent* CustomRootComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TorretaComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* PivotArma;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* ArmaTorreta;

    /** --- REFERENCIAS --- */
    UPROPERTY(VisibleAnywhere, Category = "Torreta")
    ACharacter* PC;

    /** --- VARIABLES --- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    bool bPuedeApuntar = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    float RotationSpeed = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torreta")
    float DetectionRange = 1000.0f;

    /** --- FUNCIONES --- */
    UFUNCTION(BlueprintCallable, Category = "Torreta")
    FRotator ApuntarJugador(ACharacter* Target);
};