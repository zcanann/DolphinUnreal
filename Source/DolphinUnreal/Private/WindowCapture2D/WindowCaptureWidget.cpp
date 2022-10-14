// Copyright 2019 ayumax. All Rights Reserved.

#include "WindowCapture2D/WindowCaptureWidget.h"

#include "Engine/Texture2D.h"

UWindowCaptureWidget::UWindowCaptureWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UWindowCaptureWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	FlushRenderingCommands();

	if (CaptureMachine)
	{
		CaptureMachine->Stop();
	}

	Super::ReleaseSlateResources(bReleaseChildren);
}


void UWindowCaptureWidget::BeginDestroy()
{
	Super::BeginDestroy();

	if (CaptureMachine)
	{
		CaptureMachine->Dispose();
		CaptureMachine = nullptr;
	}
}

void UWindowCaptureWidget::Start(FCaptureMachineProperties Properties)
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}

	CaptureMachine = NewObject<UCaptureMachine>(this);

	CaptureMachine->ChangeTexture.AddDynamic(this, &UWindowCaptureWidget::OnChangeTexture);
	CaptureMachine->Start(Properties);
}

void UWindowCaptureWidget::OnChangeTexture(UTexture2D* _NewTexture)
{
	ChangeTexture.Broadcast(_NewTexture);
}
