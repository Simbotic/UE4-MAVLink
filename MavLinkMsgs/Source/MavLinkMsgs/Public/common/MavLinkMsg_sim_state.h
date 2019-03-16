 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_sim_state.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_sim_state
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 108;
    /*True attitude quaternion component 1, w (1 in null-rotation) */
    UPROPERTY()
    float q1;

    /*True attitude quaternion component 2, x (0 in null-rotation) */
    UPROPERTY()
    float q2;

    /*True attitude quaternion component 3, y (0 in null-rotation) */
    UPROPERTY()
    float q3;

    /*True attitude quaternion component 4, z (0 in null-rotation) */
    UPROPERTY()
    float q4;

    /*Attitude roll expressed as Euler angles, not recommended except for human-readable outputs */
    UPROPERTY()
    float roll;

    /*Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs */
    UPROPERTY()
    float pitch;

    /*Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs */
    UPROPERTY()
    float yaw;

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

    /*Latitude [deg]*/
    UPROPERTY()
    float lat;

    /*Longitude [deg]*/
    UPROPERTY()
    float lon;

    /*Altitude [m]*/
    UPROPERTY()
    float alt;

    /*Horizontal position standard deviation */
    UPROPERTY()
    float std_dev_horz;

    /*Vertical position standard deviation */
    UPROPERTY()
    float std_dev_vert;

    /*True velocity in NORTH direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float vn;

    /*True velocity in EAST direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float ve;

    /*True velocity in DOWN direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float vd;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
