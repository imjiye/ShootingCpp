// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingActor.generated.h" // gernerated.h 파일은 항상 가장 아래에 있어야함

UCLASS()
class SHOOTINGCPP_API ACodingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Edit / Visible + Anywhere / DefaultsOnly
	// Edit = Read and Write / Visible = Read Only 
	// DefaultsOnly = Blueprint Class  -> 블루프린트에서만 가능
	// InstanceOnly = Blueprint Instance -> 레벨에서만 가능
	//Anywhere = 어디서든 가능
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVariable) // 어디서든 가능하도록 해주는 것
	int number = 10;				// 4byte 정수형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVariable)
	float fNumber = 10.0f;		   	// 실수형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVariable)
	bool bReady = false;			// 논리형(결과값이 true, false)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyVariable)
	FString myName = TEXT("");  //문자열 


};

// 생성자와 소멸자
//class ACodingActor
//{
//	ACodingActor() //생성자
//	{
//	}
//
//	~ACodingActor() //소멸자
//	{
//	}
//};
