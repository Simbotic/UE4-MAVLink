 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_radio_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_radio_status
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 109;
    /*Local (message sender) recieved signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown. */
    UPROPERTY()
    uint8 rssi;

    /*Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown. */
    UPROPERTY()
    uint8 remrssi;

    /*Remaining free transmitter buffer space. [%]*/
    UPROPERTY()
    uint8 txbuf;

    /*Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown. */
    UPROPERTY()
    uint8 noise;

    /*Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown. */
    UPROPERTY()
    uint8 remnoise;

    /*Count of radio packet receive errors (since boot). */
    UPROPERTY()
    uint16 rxerrors;

    /*Count of error corrected radio packets (since boot). */
    UPROPERTY()
    uint16 fixed;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
