 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_log_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_log_data
{
    GENERATED_BODY()

    static const uint32 MsgId = 120;
    /*Log id (from LOG_ENTRY reply) */
    UPROPERTY()
    uint16 id;

    /*Offset into the log */
    UPROPERTY()
    uint32 ofs;

    /*Number of bytes (zero for end of log) [bytes]*/
    UPROPERTY()
    uint8 count;

    /*log data */
    UPROPERTY()
    uint8 data[90];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
