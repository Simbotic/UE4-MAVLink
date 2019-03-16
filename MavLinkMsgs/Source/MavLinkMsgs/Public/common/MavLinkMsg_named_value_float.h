 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_named_value_float.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_named_value_float
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 251;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Name of the debug variable */
    UPROPERTY()
    uint8 name[10];

    /*Floating point value */
    UPROPERTY()
    float value;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
