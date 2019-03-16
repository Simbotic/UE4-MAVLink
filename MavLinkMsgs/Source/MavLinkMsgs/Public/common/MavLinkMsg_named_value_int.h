 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_named_value_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_named_value_int
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 252;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Name of the debug variable */
    UPROPERTY()
    uint8 name[10];

    /*Signed integer value */
    UPROPERTY()
    int32 value;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
