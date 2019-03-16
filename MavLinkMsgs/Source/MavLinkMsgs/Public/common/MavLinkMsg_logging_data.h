 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_logging_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_logging_data
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 266;
    /*system ID of the target */
    UPROPERTY()
    uint8 target_system;

    /*component ID of the target */
    UPROPERTY()
    uint8 target_component;

    /*sequence number (can wrap) */
    UPROPERTY()
    uint16 sequence;

    /*data length [bytes]*/
    UPROPERTY()
    uint8 length;

    /*offset into data where first message starts. This can be used for recovery, when a previous message got lost (set to 255 if no start exists). [bytes]*/
    UPROPERTY()
    uint8 first_message_offset;

    /*logged data */
    UPROPERTY()
    uint8 data[249];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
