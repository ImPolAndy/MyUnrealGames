// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorEventoEjemplo.h"
#include "Components/BoxComponent.h"
// Sets default values
AActorEventoEjemplo::AActorEventoEjemplo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Caja = CreateDefaultSubobject<UBoxComponent>(TEXT("Caja"));
	RootComponent = Caja;
	Caja->OnComponentBeginOverlap.AddDynamic(this, &AActorEventoEjemplo::BegingOverlap);
}

// Called when the game starts or when spawned
void AActorEventoEjemplo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorEventoEjemplo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorEventoEjemplo::BegingOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,TEXT("EventoDeEjemplo"));
}