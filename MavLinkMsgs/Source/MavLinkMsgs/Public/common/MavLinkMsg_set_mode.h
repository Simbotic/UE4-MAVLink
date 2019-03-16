 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_set_mode.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_set_mode
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 11;
    /*The system setting the mode */
    UPROPERTY()
    uint8 target_system;

    /*The new base mode. */
    UPROPERTY()
    uint8 base_mode;

    /*The new autopilot-specific mode. This field can be ignored by an autopilot. */
    UPROPERTY()
    uint32 custom_mode;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
