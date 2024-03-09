#include "StartMenuFunction.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UStartMenuFunction::UStartMenuFunction()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UStartMenuFunction::StartGame()
{
	UGameplayStatics::OpenLevel(this, "MainGame");
}

void UStartMenuFunction::Support()
{
	FPlatformProcess::LaunchURL(TEXT("https://halo.chaotic-quantum.site:12078"), NULL, NULL);
}

void UStartMenuFunction::SetSetting(const FString Key, const FString Value)
{
	UE_LOG(LogTemp, Display, TEXT("Set %s %s"), *FString(Key), *FString(Value));
}


// Called when the game starts
void UStartMenuFunction::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UStartMenuFunction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

