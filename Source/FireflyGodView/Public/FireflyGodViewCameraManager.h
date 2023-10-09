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
	UFUNCTION(BlueprintImplementableEvent, Category = GodView, Meta = (DisplayName = "Initialize For"))
	void ReceiveInitializeFor(APlayerController* PC);

#pragma endregion


#pragma region GodView

public:
	UFUNCTION(BlueprintPure, Category = GodView)
	FVector GetCursorMoveDirection() const;

	UFUNCTION(BlueprintPure, Category = GodView)
	FVector GetViewportDirection() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GodView)
	TObjectPtr<UFireflyGodViewConfig> GodViewConfig;

	UPROPERTY(BlueprintReadWrite, Category = GodView)
	FVector PreviousLocation = FVector::ZeroVector;

#pragma endregion
};
