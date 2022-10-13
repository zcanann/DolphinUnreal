// Copyright 2019 ayumax. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WindowCapture2D/CaptureMachineProperties.h"
#include "WindowCapture2D/CaptureMachine.h"

#include "WindowCaptureActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowCaptureActorChangeTexture, UTexture2D*, NewTexture);


UCLASS(BlueprintType, Blueprintable)
class AWindowCaptureActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AWindowCaptureActor();

protected:
	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	UTexture2D* Start(FCaptureMachineProperties Properties);

	UFUNCTION()
	void OnChangeTexture(UTexture2D* NewTexture);

public:	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginDestroy() override;

	UPROPERTY(BlueprintReadOnly, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FWindowCaptureActorChangeTexture ChangeTexture;

protected:
	UPROPERTY(Transient)
	UCaptureMachine* CaptureMachine = nullptr;
};