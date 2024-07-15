// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌체아 외관을 생성한다. 계층구조 : 충돌체를 Root로 만들고 외관을 Root에 붙인다.
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(Box);

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	Cube->SetupAttachment(RootComponent);

	// 외관의 크기와 충돌체의 크기를 설정한다.
	Cube->SetRelativeScale3D(FVector(1, 0.25f, 0.25f));
	Box->SetBoxExtent(FVector(50, 16, 16));
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 총알이 앞 방향으로 계속 이동하게 생성한다.
	FVector PO = GetActorLocation();
	FVector Velocity = GetActorForwardVector() * Speed;
	SetActorLocation(PO + Velocity * DeltaTime);
}

