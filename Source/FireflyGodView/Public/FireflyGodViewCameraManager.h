// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "FireflyGodViewCameraManager.generated.h"


class UFireflyGodViewConfig;


// 实现了上帝视角的玩家摄像机管理器
// Player Camera Manager implements God View
UCLASS()
class FIREFLYGODVIEW_API AFireflyGodViewCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

#pragma region PlayerCameraManager

public:
	virtual void InitializeFor(APlayerController* PC) override;

protected:
	// 在蓝图端根据给定的PlayerController初始化PlayerCameraManager
	// Initialize this PlayerCameraManager for the given associated PlayerController in Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = GodView, Meta = (DisplayName = "Initialize For"))
	void ReceiveInitializeFor(APlayerController* PC);

#pragma endregion


#pragma region GodView

public:
	// 获取鼠标的移动方向
	// Get mouse 's moving direction
	UFUNCTION(BlueprintPure, Category = GodView)
	FVector GetCursorMoveDirection() const;

	// 获取屏幕视口在游戏世界中的方向， 返回结果为投影到地平线的单位向量
	// Get screen viewport 's direction in game world, which is project on world z axis plane
	UFUNCTION(BlueprintPure, Category = GodView)
	FVector GetViewportDirection() const;

protected:
	// 上帝视角的配置数据资产
	// God view 's config data asset
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GodView)
	TObjectPtr<UFireflyGodViewConfig> GodViewConfig;

	// 游戏运行时缓存的上一帧的摄像机位置
	// Cached previous camera location while game runtime
	UPROPERTY(BlueprintReadWrite, Category = GodView)
	FVector PreviousLocation = FVector::ZeroVector;

#pragma endregion
};
