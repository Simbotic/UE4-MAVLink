 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_log_entry.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_log_entry
{
    GENERATED_BODY()

    static const uint32 MsgId = 118;
    /*Log id */
    UPROPERTY()
    uint16 id;

    /*Total number of logs */
    UPROPERTY()
    uint16 num_logs;

    /*High log number */
    UPROPERTY()
    uint16 last_log_num;

    /*UTC timestamp of log since 1970, or 0 if not available [s]*/
    UPROPERTY()
    uint32 time_utc;

    /*Size of the log (may be approximate) [bytes]*/
    UPROPERTY()
    uint32 size;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
