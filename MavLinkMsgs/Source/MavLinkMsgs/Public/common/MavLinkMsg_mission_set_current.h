 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_set_current.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_set_current
{
    GENERATED_BODY()

    static const uint32 MsgId = 41;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Sequence */
    UPROPERTY()
    uint16 seq;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
