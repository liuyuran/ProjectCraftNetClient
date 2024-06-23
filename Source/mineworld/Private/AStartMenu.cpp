


#include "AStartMenu.h"

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"

// Sets default values
AStartMenu::AStartMenu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStartMenu::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("开始菜单初始化操作开始..."));
	if (BaseStartMenu == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("开始菜单初始化操作失败，未设置基准菜单"));
		return;
	}
	UUserWidget* StartMenu = CreateWidget<UUserWidget>(GetWorld(), BaseStartMenu);
	StartMenu->AddToViewport();
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	UPanelWidget* ButtonPanel = reinterpret_cast<UPanelWidget*>(StartMenu->GetWidgetFromName(TEXT("menuBox")));
	if (ButtonPanel == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("开始菜单初始化操作失败，未找到容器组件"));
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		UButton* MyButton = NewObject<UButton>(this, UButton::StaticClass());
		ButtonPanel->AddChild(MyButton);
		UTextBlock* MyText = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
		MyText->SetText(FText::FromString(FString::Printf(TEXT("按钮%d"), i)));
		MyText->SetColorAndOpacity(FLinearColor::White);
		MyButton->AddChild(MyText);
		MyButton->SetBackgroundColor(FLinearColor::Gray);
	}
	UE_LOG(LogTemp, Display, TEXT("开始菜单初始化操作结束"));
}

// Called every frame
void AStartMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

