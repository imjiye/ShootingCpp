// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// player의 외관을 만든다.
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	// 외관을 Root에 붙인다.(Attach)
	Cube->SetupAttachment(RootComponent);

	// Box 모양을 만든다.
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	// Box를 Cube에 붙인다.
	Box->SetupAttachment(Cube);

	// Arrow를 생성해서 배치한다.
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);
	// Location(x = 0.000000, y = 0.000000, z = 100.000000)
	Arrow->SetRelativeLocation(FVector(0, 0, 100));
	// Rotation(Pitch = 90.000000, Yaw = 0.000000, Roll = -0.000000) => y, z, x 순서로 밀려서 할 것!
	Arrow->SetRelativeRotation(FRotator(90, 0, 0));
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
#pragma region Move
	Super::Tick(DeltaTime);

	// P = PO + VT
	FVector PO = GetActorLocation();
	FVector Dir(0, H, V);
	// 한 줄로 쓰는 법 : FVector Dir = GetActorLocation() * V + GetActorRightVector() * H;
	Dir.Normalize();
	FVector Velocity = Dir * Speed;
	SetActorLocation(PO + Velocity * DeltaTime);
	// 한 줄로 쓰는 법 : 	SetActorLocation(GetActorLocation() + Dir * Speed * DeltaTime);
#pragma endregion

#pragma region AutoFire
	// 만약 bAutoFire가 true라면 
	// 시간이 흐르다가
	// 현재시간이 생성시간이 되면 
	// MakeBullet 함수를 호출한다.
	// 현재 시간을 0으로 초기화한다.
	if (bAutoFire ==  true)
	{
		CurrentTime += DeltaTime;
		if (CurrentTime > MakeTime)
		{
			MakeBullet();
			CurrentTime = 0;
		}
	}
#pragma endregion
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::AxisHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::AxisVertical);

	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &APlayerPawn::ActionFirePressed);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Released, this, &APlayerPawn::ActionFireReleased);
}

void APlayerPawn::AxisHorizontal(float value)
{
	H = value;
}

void APlayerPawn::AxisVertical(float value)
{
	V = value;
}

void APlayerPawn::ActionFirePressed()
{
	// 자동 총쏘기를 활성화
	bAutoFire = true;
	// 현재 시간을 0으로 초기화
	CurrentTime = 0;
	MakeBullet();
}

void APlayerPawn::ActionFireReleased()
{
	// 자동 총쏘기를 멈춘다.
	bAutoFire = false;
}

void APlayerPawn::MakeBullet()
{
	GetWorld()->SpawnActor<ABullet>(BulletFactory, Arrow->GetComponentTransform());
	UGameplayStatics::PlaySound2D(GetWorld(), FireSound);

}

