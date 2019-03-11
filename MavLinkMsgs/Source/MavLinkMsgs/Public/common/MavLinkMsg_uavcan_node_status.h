 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_uavcan_node_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_uavcan_node_status
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Time since the start-up of the node. [s]*/
    UPROPERTY()
    uint32 uptime_sec;

    /*Generalized node health status. */
    UPROPERTY()
    uint8 health;

    /*Generalized operating mode. */
    UPROPERTY()
    uint8 mode;

    /*Not used currently. */
    UPROPERTY()
    uint8 sub_mode;

    /*Vendor-specific status information. */
    UPROPERTY()
    uint16 vendor_specific_status_code;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
