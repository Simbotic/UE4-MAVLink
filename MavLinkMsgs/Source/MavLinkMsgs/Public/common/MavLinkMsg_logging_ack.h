 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_logging_ack.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_logging_ack
{
    GENERATED_BODY()

    static const uint32 MsgId = 268;
    /*system ID of the target */
    UPROPERTY()
    uint8 target_system;

    /*component ID of the target */
    UPROPERTY()
    uint8 target_component;

    /*sequence number (must match the one in LOGGING_DATA_ACKED) */
    UPROPERTY()
    uint16 sequence;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
