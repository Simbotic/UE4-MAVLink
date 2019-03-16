 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_count.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_count
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 44;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Number of mission items in the sequence */
    UPROPERTY()
    uint16 count;

    /*Mission type. */
    UPROPERTY()
    uint8 mission_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
