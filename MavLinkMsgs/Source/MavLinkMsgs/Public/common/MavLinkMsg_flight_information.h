 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_flight_information.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_flight_information
{
    GENERATED_BODY()

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Timestamp at arming (time since UNIX epoch) in UTC, 0 for unknown [us]*/
    UPROPERTY()
    uint64 arming_time_utc;

    /*Timestamp at takeoff (time since UNIX epoch) in UTC, 0 for unknown [us]*/
    UPROPERTY()
    uint64 takeoff_time_utc;

    /*Universally unique identifier (UUID) of flight, should correspond to name of log files */
    UPROPERTY()
    uint64 flight_uuid;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
