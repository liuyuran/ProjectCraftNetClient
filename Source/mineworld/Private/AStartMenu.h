

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AStartMenu.generated.h"

UCLASS()
class AStartMenu : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, Category="World")
	TSubclassOf<UUserWidget> BaseStartMenu;
	// Sets default values for this actor's properties
	AStartMenu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
