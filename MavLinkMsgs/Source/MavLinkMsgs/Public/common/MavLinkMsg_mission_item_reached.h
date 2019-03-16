 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_item_reached.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_item_reached
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 46;
    /*Sequence */
    UPROPERTY()
    uint16 seq;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
