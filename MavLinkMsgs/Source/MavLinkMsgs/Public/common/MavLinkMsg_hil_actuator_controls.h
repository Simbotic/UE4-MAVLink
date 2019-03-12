 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_actuator_controls.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_actuator_controls
{
    GENERATED_BODY()

    static const uint32 MsgId = 93;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Control outputs -1 .. 1. Channel assignment depends on the simulated hardware. */
    UPROPERTY()
    float controls[16];

    /*System mode. Includes arming state. */
    UPROPERTY()
    uint8 mode;

    /*Flags as bitfield, reserved for future use. */
    UPROPERTY()
    uint64 flags;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
