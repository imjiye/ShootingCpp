// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

// class UBoxComponent; // ���漱�� Forward Declaration

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cube;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box; // ���漱��

	UPROPERTY(EditAnywhere)
	class UArrowComponent* Arrow; // ���漱��

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> BulletFactory; // �ش� Ŭ������ �Ļ�Ŭ������ �������༭ �������� ��������

	UPROPERTY(EditAnywhere)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 500.f;

	float H, V;
	void AxisHorizontal(float value);
	void AxisVertical(float value);

	// �ڵ� �� ��� ����� �����.
	// �Ӽ� - ������ �ִ� ����, ���� �ð�, �Ѿ��� �߻�Ǵ� �ð�(Interval)
	// ��� - ������(�Ѿ��� �����.), �ô�(�Ѿ��� ������ �ʴ´�.)
	bool bAutoFire;
	float CurrentTime;
	float MakeTime = 0.5f;

	void ActionFirePressed();
	void ActionFireReleased();

	void MakeBullet();


};
