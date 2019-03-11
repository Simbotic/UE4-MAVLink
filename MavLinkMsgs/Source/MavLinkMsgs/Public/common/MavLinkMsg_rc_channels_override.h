 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_rc_channels_override.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_rc_channels_override
{
    GENERATED_BODY()

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*RC channel 1 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan1_raw;

    /*RC channel 2 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan2_raw;

    /*RC channel 3 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan3_raw;

    /*RC channel 4 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan4_raw;

    /*RC channel 5 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan5_raw;

    /*RC channel 6 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan6_raw;

    /*RC channel 7 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan7_raw;

    /*RC channel 8 value. A value of UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan8_raw;

    /*RC channel 9 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan9_raw;

    /*RC channel 10 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan10_raw;

    /*RC channel 11 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan11_raw;

    /*RC channel 12 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan12_raw;

    /*RC channel 13 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan13_raw;

    /*RC channel 14 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan14_raw;

    /*RC channel 15 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan15_raw;

    /*RC channel 16 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan16_raw;

    /*RC channel 17 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan17_raw;

    /*RC channel 18 value. A value of 0 or UINT16_MAX means to ignore this field. [us]*/
    UPROPERTY()
    uint16 chan18_raw;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
