 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_sensor.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_sensor
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 107;
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

    /*Angular speed around X axis in body frame [rad/s]*/
    UPROPERTY()
    float xgyro;

    /*Angular speed around Y axis in body frame [rad/s]*/
    UPROPERTY()
    float ygyro;

    /*Angular speed around Z axis in body frame [rad/s]*/
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

    /*Differential pressure (airspeed) [mbar]*/
    UPROPERTY()
    float diff_pressure;

    /*Altitude calculated from pressure */
    UPROPERTY()
    float pressure_alt;

    /*Temperature [degC]*/
    UPROPERTY()
    float temperature;

    /*Bitmap for fields that have updated since last message, bit 0 = xacc, bit 12: temperature, bit 31: full reset of attitude/position/velocities/etc was performed in sim. */
    UPROPERTY()
    uint32 fields_updated;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
