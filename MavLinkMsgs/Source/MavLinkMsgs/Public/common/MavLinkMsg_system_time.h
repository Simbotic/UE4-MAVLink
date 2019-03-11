 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_system_time.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_system_time
{
    GENERATED_BODY()

    /*Timestamp (UNIX epoch time). [us]*/
    UPROPERTY()
    uint64 time_unix_usec;

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
