 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_v2_extension.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_v2_extension
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 248;
    /*Network ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_network;

    /*System ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_system;

    /*Component ID (0 for broadcast) */
    UPROPERTY()
    uint8 target_component;

    /*A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings).  If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/extension-message-ids.xml.  Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase. */
    UPROPERTY()
    uint16 message_type;

    /*Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields.  The entire content of this block is opaque unless you understand any the encoding message_type.  The particular encoding used can be extension specific and might not always be documented as part of the mavlink specification. */
    UPROPERTY()
    uint8 payload[249];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
