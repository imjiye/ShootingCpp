// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingActor.h"

// Sets default values
ACodingActor::ACodingActor() // ACodingActor = Actor를 상속받았다는 것
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodingActor::BeginPlay()
{
    Super::BeginPlay(); // Super = 부모 클래스

    //UE_LOG(LogTemp, Warning, TEXT("Hello World!")); // printf처럼 outputlog에 뜸

    //number 출력하기
    //UE_LOG(LogTemp, Warning, TEXT("%d"), number);

    // float 출력하기
    //UE_LOG(LogTemp, Warning, TEXT("%d"), fNumber); // 이렇게 찍으면 0이 나옴. float인데 %d로 하니까 안되는 것!
    //UE_LOG(LogTemp, Warning, TEXT("%.3f"), fNumber); // 이렇게 찍어야 제대로 숫자 나옴(%f가 원래나오는거고 f 앞에 '.숫자' 넣어주면 숫자만큼 소수점 나옴)

    // bool 출력하기
    //int size = sizeof(bool); // bool타입의 사이즈를 알아내서 int 타입 size 변수에 저장
    //UE_LOG(LogTemp, Warning, TEXT("%d"), size); // bool타입의 사이즈는 1이 나옴
    //UE_LOG(LogTemp, Warning, TEXT("bool is true : %d"), true); // true는 1
    //UE_LOG(LogTemp, Warning, TEXT("bool is false : %d"), false); // false는 0

    // 문자열
    //UE_LOG(LogTemp, Warning, TEXT("%s"), *name);

    // 조건문
     /*만약 myName이 Lisa 라면 LVMA 별장에서 쉬고 싶다.
     그렇지 않고 myName이 Jisu 라면 프랑스로 여행가고 싶다.
     이도저도 아니라면 집에서 지구마블이나 보고 싶다.*/
    /*if (myName.Equals (TEXT("Lisa")))
    {
    	UE_LOG(LogTemp, Warning, TEXT("LVMA 별장에서 쉬고 싶다."));
    }
    else if (myName.Equals(TEXT("Jisu")))
    {
    	UE_LOG(LogTemp, Warning, TEXT("프랑스로 여행가고 싶다."));
    }
    else
    {
    	UE_LOG(LogTemp, Warning, TEXT("집에서 지구마블이나 보고싶다."));
    }*/

    // 반복문
    // 0부터 10까지 다 더해서 출력하기
    /*int sum = 0;
    for (int i = 0; i <= 10; i++)
    {
        sum += i;
    }
    UE_LOG(LogTemp, Warning, TEXT("%d"), sum);*/

    // 50이상 그리고 60이하만 출력 또는 10이하거나 90이상만 출력
    /*for (int i = 0; i <= 100; i++)
    {
        if ((i >= 50 && i <= 60) || (i <= 10 || i >= 90))
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }*/
}

// Called every frame
void ACodingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

