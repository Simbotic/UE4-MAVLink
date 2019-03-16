 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_raw_pressure.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_raw_pressure
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 28;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Absolute pressure (raw) */
    UPROPERTY()
    int16 press_abs;

    /*Differential pressure 1 (raw, 0 if nonexistent) */
    UPROPERTY()
    int16 press_diff1;

    /*Differential pressure 2 (raw, 0 if nonexistent) */
    UPROPERTY()
    int16 press_diff2;

    /*Raw Temperature measurement (raw) */
    UPROPERTY()
    int16 temperature;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
