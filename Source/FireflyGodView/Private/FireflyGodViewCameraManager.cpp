// Copyright Epic Games, Inc. All Rights Reserved.


#include "FireflyGodViewCameraManager.h"

#include "FireflyGodViewConfig.h"

#include "Kismet/KismetMathLibrary.h"


void AFireflyGodViewCameraManager::InitializeFor(APlayerController* PC)
{
	Super::InitializeFor(PC);

	ReceiveInitializeFor(PC);
}

FVector AFireflyGodViewCameraManager::GetCursorMoveDirection() const
{
	if (!IsValid(GodViewConfig))
	{
		return FVector(0.f, 0.f, 0.f);
	}

	if (!IsValid(PCOwner))
	{
		return FVector(0.f, 0.f, 0.f);
	}

	int32 ScreenSizeX = INDEX_NONE;
	int32 ScreenSizeY = INDEX_NONE;
	PCOwner->GetViewportSize(ScreenSizeX, ScreenSizeY);

	float MousePositionX = INDEX_NONE;
	float MousePositionY = INDEX_NONE;
	PCOwner->GetMousePosition(MousePositionX, MousePositionY);

	const bool CursorUp = UKismetMathLibrary::InRange_FloatFloat(UKismetMathLibrary::NormalizeToRange(
		MousePositionY, 0.f, ScreenSizeY), 0.f, GodViewConfig->CursorEdgeRate);
	const bool CursorDown = UKismetMathLibrary::InRange_FloatFloat(UKismetMathLibrary::NormalizeToRange(
		MousePositionY, 0.f, ScreenSizeY), 1.f - GodViewConfig->CursorEdgeRate, 1.f);

	const bool CursorLeft = UKismetMathLibrary::InRange_FloatFloat(UKismetMathLibrary::NormalizeToRange(
		MousePositionX, 0.f, ScreenSizeX), 0.f, GodViewConfig->CursorEdgeRate);
	const bool CursorRight = UKismetMathLibrary::InRange_FloatFloat(UKismetMathLibrary::NormalizeToRange(
		MousePositionX, 0.f, ScreenSizeX), 1.f - GodViewConfig->CursorEdgeRate, 1.f);

	const FVector ViewDirection = GetViewportDirection();

	if (CursorUp)
	{
		if (CursorLeft)
		{
			// 左上
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, -45.f, FVector::ZAxisVector);
		}
		else if (CursorRight)
		{
			// 右上
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, 45.f, FVector::ZAxisVector);
		}
		else
		{
			// 正上
			return ViewDirection;
		}
	}
	else if(CursorDown)
	{
		if (CursorLeft)
		{
			// 左下
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, -135.f, FVector::ZAxisVector);
		}
		else if (CursorRight)
		{
			// 右下
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, 135.f, FVector::ZAxisVector);
		}
		else
		{
			// 正下
			return -ViewDirection;
		}
	}
	else
	{
		if (CursorLeft)
		{
			// 正左
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, -90.f, FVector::ZAxisVector);
		}
		else if (CursorRight)
		{
			// 正右
			return UKismetMathLibrary::RotateAngleAxis(ViewDirection, 90.f, FVector::ZAxisVector);
		}
	}

	return FVector::ZeroVector;
}

FVector AFireflyGodViewCameraManager::GetViewportDirection() const
{
	if (!IsValid(PCOwner))
	{
		return FVector::ZeroVector;
	}

	FVector ViewLocation = FVector::ZeroVector;
	FRotator ViewRotation = FRotator::ZeroRotator;
	PCOwner->GetPlayerViewPoint(ViewLocation, ViewRotation);

	return UKismetMathLibrary::ProjectVectorOnToPlane(ViewRotation.Vector()
		, -FVector::ZAxisVector).GetSafeNormal();
}

FVector AFireflyGodViewCameraManager::CalcCameraLocation_Implementation()
{
	if (!IsValid(GodViewConfig))
	{
		return FVector(0.f, 0.f, 0.f);
	}

	PreviousLocation = PreviousLocation + GetCursorMoveDirection() * GodViewConfig->ScreenMoveSpeed;
	PreviousLocation.Z = GodViewConfig->CameraArmLength;

	return PreviousLocation;
}
