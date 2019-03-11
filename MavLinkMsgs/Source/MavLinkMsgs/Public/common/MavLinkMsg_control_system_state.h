 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_control_system_state.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_control_system_state
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*X acceleration in body frame [m/s/s]*/
    UPROPERTY()
    float x_acc;

    /*Y acceleration in body frame [m/s/s]*/
    UPROPERTY()
    float y_acc;

    /*Z acceleration in body frame [m/s/s]*/
    UPROPERTY()
    float z_acc;

    /*X velocity in body frame [m/s]*/
    UPROPERTY()
    float x_vel;

    /*Y velocity in body frame [m/s]*/
    UPROPERTY()
    float y_vel;

    /*Z velocity in body frame [m/s]*/
    UPROPERTY()
    float z_vel;

    /*X position in local frame [m]*/
    UPROPERTY()
    float x_pos;

    /*Y position in local frame [m]*/
    UPROPERTY()
    float y_pos;

    /*Z position in local frame [m]*/
    UPROPERTY()
    float z_pos;

    /*Airspeed, set to -1 if unknown [m/s]*/
    UPROPERTY()
    float airspeed;

    /*Variance of body velocity estimate */
    UPROPERTY()
    float vel_variance[3];

    /*Variance in local position */
    UPROPERTY()
    float pos_variance[3];

    /*The attitude, represented as Quaternion */
    UPROPERTY()
    float q[4];

    /*Angular rate in roll axis [rad/s]*/
    UPROPERTY()
    float roll_rate;

    /*Angular rate in pitch axis [rad/s]*/
    UPROPERTY()
    float pitch_rate;

    /*Angular rate in yaw axis [rad/s]*/
    UPROPERTY()
    float yaw_rate;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
