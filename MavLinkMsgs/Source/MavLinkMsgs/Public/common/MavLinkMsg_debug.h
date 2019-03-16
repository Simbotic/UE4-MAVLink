 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_debug.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_debug
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 254;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*index of debug variable */
    UPROPERTY()
    uint8 ind;

    /*DEBUG value */
    UPROPERTY()
    float value;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
