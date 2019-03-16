 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_button_change.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_button_change
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 257;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Time of last change of button state. [ms]*/
    UPROPERTY()
    uint32 last_change_ms;

    /*Bitmap for state of buttons. */
    UPROPERTY()
    uint8 state;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
