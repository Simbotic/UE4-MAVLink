 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_extended_sys_state.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_extended_sys_state
{
    GENERATED_BODY()

    static const uint32 MsgId = 245;
    /*The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration. */
    UPROPERTY()
    uint8 vtol_state;

    /*The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    UPROPERTY()
    uint8 landed_state;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
