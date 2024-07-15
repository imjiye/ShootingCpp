// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

// class UBoxComponent;

UCLASS()
class SHOOTINGCPP_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box; // 이 클래스가 시작한 후에 이걸 선언해라

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Cube;

	// 총알이 앞 방향으로 계속 이동하게 하자
	UPROPERTY(EditAnywhere)
	float Speed = 800;

};
