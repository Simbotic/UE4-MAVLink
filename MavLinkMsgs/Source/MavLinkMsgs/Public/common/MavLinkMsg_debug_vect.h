 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_debug_vect.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_debug_vect
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 250;
    /*Name */
    UPROPERTY()
    uint8 name[10];

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*x */
    UPROPERTY()
    float x;

    /*y */
    UPROPERTY()
    float y;

    /*z */
    UPROPERTY()
    float z;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
