 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_rc_channels.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_rc_channels
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 65;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available. */
    UPROPERTY()
    uint8 chancount;

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

    /*RC channel 9 value. [us]*/
    UPROPERTY()
    uint16 chan9_raw;

    /*RC channel 10 value. [us]*/
    UPROPERTY()
    uint16 chan10_raw;

    /*RC channel 11 value. [us]*/
    UPROPERTY()
    uint16 chan11_raw;

    /*RC channel 12 value. [us]*/
    UPROPERTY()
    uint16 chan12_raw;

    /*RC channel 13 value. [us]*/
    UPROPERTY()
    uint16 chan13_raw;

    /*RC channel 14 value. [us]*/
    UPROPERTY()
    uint16 chan14_raw;

    /*RC channel 15 value. [us]*/
    UPROPERTY()
    uint16 chan15_raw;

    /*RC channel 16 value. [us]*/
    UPROPERTY()
    uint16 chan16_raw;

    /*RC channel 17 value. [us]*/
    UPROPERTY()
    uint16 chan17_raw;

    /*RC channel 18 value. [us]*/
    UPROPERTY()
    uint16 chan18_raw;

    /*Receive signal strength indicator. Values: [0-100], 255: invalid/unknown. [%]*/
    UPROPERTY()
    uint8 rssi;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
