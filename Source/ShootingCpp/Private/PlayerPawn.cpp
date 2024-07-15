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

	// player�� �ܰ��� �����.
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	// �ܰ��� Root�� ���δ�.(Attach)
	Cube->SetupAttachment(RootComponent);

	// Box ����� �����.
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	// Box�� Cube�� ���δ�.
	Box->SetupAttachment(Cube);

	// Arrow�� �����ؼ� ��ġ�Ѵ�.
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);
	// Location(x = 0.000000, y = 0.000000, z = 100.000000)
	Arrow->SetRelativeLocation(FVector(0, 0, 100));
	// Rotation(Pitch = 90.000000, Yaw = 0.000000, Roll = -0.000000) => y, z, x ������ �з��� �� ��!
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
	// �� �ٷ� ���� �� : FVector Dir = GetActorLocation() * V + GetActorRightVector() * H;
	Dir.Normalize();
	FVector Velocity = Dir * Speed;
	SetActorLocation(PO + Velocity * DeltaTime);
	// �� �ٷ� ���� �� : 	SetActorLocation(GetActorLocation() + Dir * Speed * DeltaTime);
#pragma endregion

#pragma region AutoFire
	// ���� bAutoFire�� true��� 
	// �ð��� �帣�ٰ�
	// ����ð��� �����ð��� �Ǹ� 
	// MakeBullet �Լ��� ȣ���Ѵ�.
	// ���� �ð��� 0���� �ʱ�ȭ�Ѵ�.
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
	// �ڵ� �ѽ�⸦ Ȱ��ȭ
	bAutoFire = true;
	// ���� �ð��� 0���� �ʱ�ȭ
	CurrentTime = 0;
	MakeBullet();
}

void APlayerPawn::ActionFireReleased()
{
	// �ڵ� �ѽ�⸦ �����.
	bAutoFire = false;
}

void APlayerPawn::MakeBullet()
{
	GetWorld()->SpawnActor<ABullet>(BulletFactory, Arrow->GetComponentTransform());
	UGameplayStatics::PlaySound2D(GetWorld(), FireSound);

}

