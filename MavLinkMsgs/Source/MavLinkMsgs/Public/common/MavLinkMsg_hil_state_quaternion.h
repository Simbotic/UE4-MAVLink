 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_state_quaternion.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_state_quaternion
{
    GENERATED_BODY()

    static const uint32 MsgId = 115;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation) */
    UPROPERTY()
    float attitude_quaternion[4];

    /*Body frame roll / phi angular speed [rad/s]*/
    UPROPERTY()
    float rollspeed;

    /*Body frame pitch / theta angular speed [rad/s]*/
    UPROPERTY()
    float pitchspeed;

    /*Body frame yaw / psi angular speed [rad/s]*/
    UPROPERTY()
    float yawspeed;

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude [mm]*/
    UPROPERTY()
    int32 alt;

    /*Ground X Speed (Latitude) [cm/s]*/
    UPROPERTY()
    int16 vx;

    /*Ground Y Speed (Longitude) [cm/s]*/
    UPROPERTY()
    int16 vy;

    /*Ground Z Speed (Altitude) [cm/s]*/
    UPROPERTY()
    int16 vz;

    /*Indicated airspeed [cm/s]*/
    UPROPERTY()
    uint16 ind_airspeed;

    /*True airspeed [cm/s]*/
    UPROPERTY()
    uint16 true_airspeed;

    /*X acceleration [mG]*/
    UPROPERTY()
    int16 xacc;

    /*Y acceleration [mG]*/
    UPROPERTY()
    int16 yacc;

    /*Z acceleration [mG]*/
    UPROPERTY()
    int16 zacc;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
