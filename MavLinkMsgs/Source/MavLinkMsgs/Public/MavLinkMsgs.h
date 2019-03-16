// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MavLinkDispatch.h"
#include "Modules/ModuleManager.h"

class UMavlinkDispatch;

class FMavLinkMsgsModule : public IModuleInterface
{
	UMavlinkDispatch* Dispatch;
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	UMavlinkDispatch* GetMavlinkDispatch() const;
};
