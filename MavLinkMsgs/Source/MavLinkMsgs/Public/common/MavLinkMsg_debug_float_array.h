 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_debug_float_array.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_debug_float_array
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Name, for human-friendly display in a Ground Control Station */
    UPROPERTY()
    uint8 name[10];

    /*Unique ID used to discriminate between arrays */
    UPROPERTY()
    uint16 array_id;

    /*data */
    UPROPERTY()
    float data[58];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
