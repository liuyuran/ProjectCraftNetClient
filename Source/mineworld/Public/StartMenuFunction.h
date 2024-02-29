

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StartMenuFunction.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINEWORLD_API UStartMenuFunction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStartMenuFunction();
	UFUNCTION(BlueprintCallable, Category = "开始菜单", meta = (DisplayName = "开始游戏"))
	void StartGame();
	UFUNCTION(BlueprintCallable, Category = "开始菜单", meta = (DisplayName = "技术支持"))
	static void Support();
	UFUNCTION(BlueprintCallable, Category = "开始菜单", meta = (DisplayName = "保存设置"))
	void SetSetting(FString Key, FString Value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
