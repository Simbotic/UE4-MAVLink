 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_clear_all.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_clear_all
{
    GENERATED_BODY()

    static const uint32 MsgId = 45;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Mission type. */
    UPROPERTY()
    uint8 mission_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
