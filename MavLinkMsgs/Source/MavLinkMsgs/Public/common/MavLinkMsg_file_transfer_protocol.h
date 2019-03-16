 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_file_transfer_protocol.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_file_transfer_protocol
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 110;
    /*Network ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_network;

    /*System ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_system;

    /*Component ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_component;

    /*Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields.  The entire content of this block is opaque unless you understand any the encoding message_type.  The particular encoding used can be extension specific and might not always be documented as part of the mavlink specification. */
    UPROPERTY()
    uint8 payload[251];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
