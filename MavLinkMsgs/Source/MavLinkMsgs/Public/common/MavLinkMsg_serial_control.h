 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_serial_control.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_serial_control
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 126;
    /*Serial control device type. */
    UPROPERTY()
    uint8 device;

    /*Bitmap of serial control flags. */
    UPROPERTY()
    uint8 flags;

    /*Timeout for reply data [ms]*/
    UPROPERTY()
    uint16 timeout;

    /*Baudrate of transfer. Zero means no change. [bits/s]*/
    UPROPERTY()
    uint32 baudrate;

    /*how many bytes in this transfer [bytes]*/
    UPROPERTY()
    uint8 count;

    /*serial data */
    UPROPERTY()
    uint8 data[70];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
