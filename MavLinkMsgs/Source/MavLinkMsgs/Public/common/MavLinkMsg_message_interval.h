 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_message_interval.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_message_interval
{
    GENERATED_BODY()

    /*The ID of the requested MAVLink message. v1.0 is limited to 254 messages. */
    UPROPERTY()
    uint16 message_id;

    /*The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent. [us]*/
    UPROPERTY()
    int32 interval_us;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
