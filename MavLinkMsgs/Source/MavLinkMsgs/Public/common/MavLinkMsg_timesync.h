 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_timesync.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_timesync
{
    GENERATED_BODY()

    /*Time sync timestamp 1 */
    UPROPERTY()
    int64 tc1;

    /*Time sync timestamp 2 */
    UPROPERTY()
    int64 ts1;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
