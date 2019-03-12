 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_power_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_power_status
{
    GENERATED_BODY()

    static const uint32 MsgId = 125;
    /*5V rail voltage. [mV]*/
    UPROPERTY()
    uint16 Vcc;

    /*Servo rail voltage. [mV]*/
    UPROPERTY()
    uint16 Vservo;

    /*Bitmap of power supply status flags. */
    UPROPERTY()
    uint16 flags;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
