 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_highres_imu.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_highres_imu
{
    GENERATED_BODY()

    static const uint32 MsgId = 105;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*X acceleration [m/s/s]*/
    UPROPERTY()
    float xacc;

    /*Y acceleration [m/s/s]*/
    UPROPERTY()
    float yacc;

    /*Z acceleration [m/s/s]*/
    UPROPERTY()
    float zacc;

    /*Angular speed around X axis [rad/s]*/
    UPROPERTY()
    float xgyro;

    /*Angular speed around Y axis [rad/s]*/
    UPROPERTY()
    float ygyro;

    /*Angular speed around Z axis [rad/s]*/
    UPROPERTY()
    float zgyro;

    /*X Magnetic field [gauss]*/
    UPROPERTY()
    float xmag;

    /*Y Magnetic field [gauss]*/
    UPROPERTY()
    float ymag;

    /*Z Magnetic field [gauss]*/
    UPROPERTY()
    float zmag;

    /*Absolute pressure [mbar]*/
    UPROPERTY()
    float abs_pressure;

    /*Differential pressure [mbar]*/
    UPROPERTY()
    float diff_pressure;

    /*Altitude calculated from pressure */
    UPROPERTY()
    float pressure_alt;

    /*Temperature [degC]*/
    UPROPERTY()
    float temperature;

    /*Bitmap for fields that have updated since last message, bit 0 = xacc, bit 12: temperature */
    UPROPERTY()
    uint16 fields_updated;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
