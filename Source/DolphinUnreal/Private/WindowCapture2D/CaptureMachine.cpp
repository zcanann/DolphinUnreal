﻿// Copyright 2019 ayumax. All Rights Reserved.

#include "WindowCapture2D/CaptureMachine.h"

#include "Engine/Texture2D.h"
#include "Async/Async.h"
#include "Internationalization/Regex.h"
#include "Runtime/Core/Public/HAL/RunnableThread.h"

#include "WindowCapture2D/Utils/WCWorkerThread.h"

#if PLATFORM_WINDOWS
#include <dwmapi.h>
#endif

UCaptureMachine::UCaptureMachine()
{
}

void UCaptureMachine::Start(FCaptureMachineProperties InProperties)
{
	m_TargetWindow = (HWND)InProperties.WindowIdentifier;
	Properties = InProperties;
}

void UCaptureMachine::Tick(float DeltaTime)
{
	// TODO: Respect frame rate
	DoCapture();
}

void UCaptureMachine::Stop()
{
#if PLATFORM_WINDOWS
	if (TextureTarget)
	{
		TextureTarget->ReleaseResource();
		TextureTarget = nullptr;
	}
#endif
}

void UCaptureMachine::Dispose()
{
#if PLATFORM_WINDOWS
	if (m_hBmp)
	{
		::DeleteObject(m_hBmp);
		m_BitmapBuffer = nullptr;
	}

	if (m_MemDC)
	{
		::DeleteDC(m_MemDC);
		m_MemDC = nullptr;
	}

	if (m_hOriginalBmp)
	{
		::DeleteObject(m_hOriginalBmp);
		m_hOriginalBmp = nullptr;
	}

	if (m_OriginalMemDC)
	{
		::DeleteDC(m_OriginalMemDC);
		m_OriginalMemDC = nullptr;
	}
#endif
}


bool UCaptureMachine::DoCapture()
{
#if PLATFORM_WINDOWS
	if (!m_TargetWindow)
	{
		return true;
	}

	if (!m_MemDC)
	{
		HDC foundDC = ::GetDC(m_TargetWindow);
		m_MemDC = ::CreateCompatibleDC(foundDC);

		ReleaseDC(m_TargetWindow, foundDC);
	}

	if (!TextureTarget)
	{
		CreateNewTexture();
	}

	if (Properties.CheckWindowSize)
	{
		const FIntVector2D oldWindowSize = m_WindowSize;
		GetWindowSize(m_TargetWindow);

		if (m_WindowSize != oldWindowSize)
		{
			CreateNewTexture();
		}

		if (!TextureTarget)
		{
			return true;
		}
	}

	::PrintWindow(m_TargetWindow, m_MemDC, 2);

	UpdateTexture();
#endif

	return true;
}

void UCaptureMachine::UpdateTexture()
{
#if PLATFORM_WINDOWS
	if (!TextureTarget)
	{
		return;
	}

	TextureRegion.Width = TextureTarget->GetSizeX();
	TextureRegion.Height = TextureTarget->GetSizeY();

	TextureTarget->UpdateTextureRegions(0, 1, &TextureRegion, 4 * TextureTarget->GetSizeX(), 4, reinterpret_cast<uint8*>(m_BitmapBuffer));
#endif
}

void UCaptureMachine::GetWindowSize(HWND hWnd)
{
#if PLATFORM_WINDOWS
	if (!::IsWindow(hWnd))
	{
		m_OriginalWindowSize = FIntVector2D(0, 0);
		m_WindowSize = m_OriginalWindowSize;
		m_WindowOffset = FIntVector2D(0, 0);
		return;
	}

	RECT rect;
	::GetWindowRect(hWnd, &rect);

	m_OriginalWindowSize = FIntVector2D(rect.right - rect.left, rect.bottom - rect.top);
	m_WindowSize = m_OriginalWindowSize;
	m_WindowOffset = FIntVector2D(0, 0);
#endif
}

void UCaptureMachine::CreateNewTexture()
{
#if PLATFORM_WINDOWS
	if (m_hBmp)
	{
		::DeleteObject(m_hBmp);
		m_BitmapBuffer = nullptr;
	}

	if (m_WindowSize.X == 0 || m_WindowSize.Y == 0)
	{
		TextureTarget = nullptr;
		return;
	}

	m_BitmapBuffer = new char[m_WindowSize.X * m_WindowSize.Y * 4];

	TextureTarget = UTexture2D::CreateTransient(m_WindowSize.X, m_WindowSize.Y, PF_B8G8R8A8);
	TextureTarget->UpdateResource();
	ChangeTexture.Broadcast(TextureTarget);

	BITMAPINFO bmpInfo;
	bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmpInfo.bmiHeader.biWidth = m_WindowSize.X;
	bmpInfo.bmiHeader.biHeight = m_WindowSize.Y;
	bmpInfo.bmiHeader.biPlanes = 1;
	bmpInfo.bmiHeader.biBitCount = 32;
	bmpInfo.bmiHeader.biCompression = BI_RGB;

	m_hBmp = ::CreateDIBSection(NULL, &bmpInfo, DIB_RGB_COLORS, (void**)&m_BitmapBuffer, NULL, 0);

	::SelectObject(m_MemDC, m_hBmp);
#endif
}
