// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FireflyGodViewConfig.generated.h"


// 上帝视角配置
// God View config
UCLASS()
class FIREFLYGODVIEW_API UFireflyGodViewConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	// 是否启用摄像机的初始位置
	// Whether to enable the initial position of the camera
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bEnableCameraInitialLocation = false;

	// 摄像机的初始位置
	// Camera 's initial location
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Meta = (EditCondition = "bEnableCameraInitialLocation", EditConditionHides))
	FVector CameraInitialLocation = FVector(0.0f, 0.0f, 1000.0f);

	// 摄像机的初始旋转
	// Camera 's initial rotation
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FRotator CameraInitialRotation = FRotator(-40.f, 0.f, 0.f);

	// 上帝视角的屏幕移动速度
	// Screen 's moving speed of god view
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Meta = (ClampMin = 0.f, UIMin = 0.f))
	float ScreenMoveSpeed = 10.f;

	// 触发上帝视角屏幕移动的鼠标在屏幕边缘的比例
	// The proportion of the mouse at the edge of the screen that triggers the movement of the screen from God's perspective
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Meta = (ClampMin = 0.f, UIMin = 0.f))
	float CursorEdgeRate = 0.01f;

	// 上帝视角的视野范围
	// Field of view of God View
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float GodViewFOV = 90.f;
};
