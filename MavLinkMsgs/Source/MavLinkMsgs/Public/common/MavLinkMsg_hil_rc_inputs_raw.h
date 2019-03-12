 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_rc_inputs_raw.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_rc_inputs_raw
{
    GENERATED_BODY()

    static const uint32 MsgId = 92;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*RC channel 1 value [us]*/
    UPROPERTY()
    uint16 chan1_raw;

    /*RC channel 2 value [us]*/
    UPROPERTY()
    uint16 chan2_raw;

    /*RC channel 3 value [us]*/
    UPROPERTY()
    uint16 chan3_raw;

    /*RC channel 4 value [us]*/
    UPROPERTY()
    uint16 chan4_raw;

    /*RC channel 5 value [us]*/
    UPROPERTY()
    uint16 chan5_raw;

    /*RC channel 6 value [us]*/
    UPROPERTY()
    uint16 chan6_raw;

    /*RC channel 7 value [us]*/
    UPROPERTY()
    uint16 chan7_raw;

    /*RC channel 8 value [us]*/
    UPROPERTY()
    uint16 chan8_raw;

    /*RC channel 9 value [us]*/
    UPROPERTY()
    uint16 chan9_raw;

    /*RC channel 10 value [us]*/
    UPROPERTY()
    uint16 chan10_raw;

    /*RC channel 11 value [us]*/
    UPROPERTY()
    uint16 chan11_raw;

    /*RC channel 12 value [us]*/
    UPROPERTY()
    uint16 chan12_raw;

    /*Receive signal strength indicator. Values: [0-100], 255: invalid/unknown. */
    UPROPERTY()
    uint8 rssi;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
