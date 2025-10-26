#include "TorretaAutomatica.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ATorretaAutomatica::ATorretaAutomatica()
{
    PrimaryActorTick.bCanEverTick = true;

    // COMPONENTES
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

// Called every frame
void ATorretaAutomatica::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bPuedeApuntar && PC)
    {
        float Distancia = FVector::Dist(PC->GetActorLocation(), GetActorLocation());
        if (Distancia < DetectionRange)
        {
            FVector PlayerPos = PC->GetActorLocation();
            FVector MyPos = PivotArma->GetComponentLocation();

            FVector Dir = PlayerPos - MyPos;
            Dir.Z = 0; // Ignorar rotación vertical si solo apunta horizontalmente

            FRotator TargetRot = Dir.Rotation();

            // Interpolación suave hacia el jugador
            FRotator NewRot = FMath::RInterpTo(PivotArma->GetComponentRotation(), TargetRot, DeltaTime, RotationSpeed);

            PivotArma->SetWorldRotation(NewRot);
        }
    }
}

// Función auxiliar opcional (por si la querés llamar desde Blueprint)
FRotator ATorretaAutomatica::ApuntarJugador(ACharacter* Target)
{
    if (!Target || !PivotArma) return FRotator::ZeroRotator;

    FVector PosTarget = Target->GetActorLocation();
    FVector Direccion = PosTarget - PivotArma->GetComponentLocation();
    return Direccion.Rotation();
}