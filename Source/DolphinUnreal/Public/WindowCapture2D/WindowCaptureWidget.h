// Copyright 2019 ayumax. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "blueprint/UserWidget.h"
#include "WindowCapture2D/CaptureMachineProperties.h"
#include "WindowCapture2D/CaptureMachine.h"

#include "WindowCaptureWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowCaptureWidgetChangeTexture, UTexture2D*, NewTexture);


UCLASS(BlueprintType, Blueprintable)
class UWindowCaptureWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UWindowCaptureWidget(const FObjectInitializer& ObjectInitializer);

protected:
	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	UTexture2D* Start(FCaptureMachineProperties Properties);

	UFUNCTION()
	void OnChangeTexture(UTexture2D* NewTexture);

public:	
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void BeginDestroy() override;

	UPROPERTY(BlueprintReadOnly, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FWindowCaptureWidgetChangeTexture ChangeTexture;

protected:
	UPROPERTY(Transient)
	UCaptureMachine* CaptureMachine = nullptr;
};
