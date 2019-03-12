 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_ping.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_ping
{
    GENERATED_BODY()

    static const uint32 MsgId = 4;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*PING sequence */
    UPROPERTY()
    uint32 seq;

    /*0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system */
    UPROPERTY()
    uint8 target_system;

    /*0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component. */
    UPROPERTY()
    uint8 target_component;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
