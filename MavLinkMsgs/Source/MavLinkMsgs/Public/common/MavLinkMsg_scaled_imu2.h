 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_scaled_imu2.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_scaled_imu2
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 116;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*X acceleration [mG]*/
    UPROPERTY()
    int16 xacc;

    /*Y acceleration [mG]*/
    UPROPERTY()
    int16 yacc;

    /*Z acceleration [mG]*/
    UPROPERTY()
    int16 zacc;

    /*Angular speed around X axis [mrad/s]*/
    UPROPERTY()
    int16 xgyro;

    /*Angular speed around Y axis [mrad/s]*/
    UPROPERTY()
    int16 ygyro;

    /*Angular speed around Z axis [mrad/s]*/
    UPROPERTY()
    int16 zgyro;

    /*X Magnetic field [mT]*/
    UPROPERTY()
    int16 xmag;

    /*Y Magnetic field [mT]*/
    UPROPERTY()
    int16 ymag;

    /*Z Magnetic field [mT]*/
    UPROPERTY()
    int16 zmag;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
