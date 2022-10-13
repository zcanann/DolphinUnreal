// Copyright 2019 ayumax. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WindowCapture2D/CaptureMachineProperties.h"
#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#include <WinUser.h>
#else
using HBITMAP = void*;
using HDC = void*;
using HWND = void*;
#endif
#include "CaptureMachine.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCaptureMachineChangeTexture, UTexture2D*, NewTexture);

UCLASS(BlueprintType, Blueprintable)
class UCaptureMachine : public UObject
{
	GENERATED_BODY()
	
public:	
	UCaptureMachine();

	virtual void Start(FCaptureMachineProperties InProperties);
	virtual void Stop();
	virtual void Dispose();

	UFUNCTION(BlueprintPure, Category = WindowCapture2D)
	UTexture2D* CreateTexture();

protected:
	void UpdateTexture() const;
	void GetWindowSize(HWND hWnd);
	void ReCreateTexture();
	bool DoCapture();


public:
	UPROPERTY(BlueprintReadOnly, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FCaptureMachineChangeTexture ChangeTexture;

private:
	UPROPERTY()
	FCaptureMachineProperties Properties;

	char* m_BitmapBuffer = nullptr;

	HBITMAP m_hBmp = nullptr;
	HDC m_MemDC = nullptr;
	HBITMAP m_hOriginalBmp = nullptr;
	HDC m_OriginalMemDC = nullptr;
	HWND m_TargetWindow = nullptr;

	FIntVector2D m_WindowSize;
	FIntVector2D m_OriginalWindowSize;
	FIntVector2D m_WindowOffset;

	class FWCWorkerThread* CaptureWorkerThread = nullptr;
	class FRunnableThread* CaptureThread = nullptr;
};
