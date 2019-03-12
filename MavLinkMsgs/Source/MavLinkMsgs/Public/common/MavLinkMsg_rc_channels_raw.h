 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_rc_channels_raw.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_rc_channels_raw
{
    GENERATED_BODY()

    static const uint32 MsgId = 35;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    UPROPERTY()
    uint8 port;

    /*RC channel 1 value. [us]*/
    UPROPERTY()
    uint16 chan1_raw;

    /*RC channel 2 value. [us]*/
    UPROPERTY()
    uint16 chan2_raw;

    /*RC channel 3 value. [us]*/
    UPROPERTY()
    uint16 chan3_raw;

    /*RC channel 4 value. [us]*/
    UPROPERTY()
    uint16 chan4_raw;

    /*RC channel 5 value. [us]*/
    UPROPERTY()
    uint16 chan5_raw;

    /*RC channel 6 value. [us]*/
    UPROPERTY()
    uint16 chan6_raw;

    /*RC channel 7 value. [us]*/
    UPROPERTY()
    uint16 chan7_raw;

    /*RC channel 8 value. [us]*/
    UPROPERTY()
    uint16 chan8_raw;

    /*Receive signal strength indicator. Values: [0-100], 255: invalid/unknown. [%]*/
    UPROPERTY()
    uint8 rssi;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
