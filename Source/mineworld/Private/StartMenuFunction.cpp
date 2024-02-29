


#include "StartMenuFunction.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UStartMenuFunction::UStartMenuFunction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStartMenuFunction::StartGame()
{
	const UWorld* World = GetWorld();
	UGameplayStatics::OpenLevel(World, "MainGame");
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

	// ...
	
}


// Called every frame
void UStartMenuFunction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

