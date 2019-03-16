 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_log_request_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_log_request_data
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 119;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Log id (from LOG_ENTRY reply) */
    UPROPERTY()
    uint16 id;

    /*Offset into the log */
    UPROPERTY()
    uint32 ofs;

    /*Number of bytes [bytes]*/
    UPROPERTY()
    uint32 count;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
