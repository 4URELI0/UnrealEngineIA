#include "TorretaAutomatica.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

ATorretaAutomatica::ATorretaAutomatica()
{
    PrimaryActorTick.bCanEverTick = true;

    CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
    RootComponent = CustomRootComponent;

    TorretaComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torreta"));
    TorretaComponent->SetupAttachment(CustomRootComponent);

    PivotArma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PivotArma"));
    PivotArma->SetupAttachment(TorretaComponent);

    ArmaTorreta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmaTorreta"));
    ArmaTorreta->SetupAttachment(PivotArma);
}


void ATorretaAutomatica::BeginPlay()
{
    Super::BeginPlay();

  
    PC = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

void ATorretaAutomatica::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bPuedeApuntar && PC)
    {
        float Distancia = FVector::Dist(PC->GetActorLocation(), GetActorLocation());
        if (Distancia < Rango)
        {
            FVector PosJugador = PC->GetActorLocation();
            FVector PosTorreta = PivotArma->GetComponentLocation();

            FVector Direccion = PosJugador - PosTorreta;
            Direccion.Z = 0;

            FRotator TargetRot = Direccion.Rotation();

            FRotator NewRot = FMath::RInterpTo(PivotArma->GetComponentRotation(), TargetRot, DeltaTime, VelocidadRotacion);

            PivotArma->SetWorldRotation(NewRot);
        }
    }
}

FRotator ATorretaAutomatica::ApuntarJugador(ACharacter* Target)
{
    if (!Target || !PivotArma) return FRotator::ZeroRotator;

    FVector PosTarget = Target->GetActorLocation();
    FVector Direccion = PosTarget - PivotArma->GetComponentLocation();
    return Direccion.Rotation();
}