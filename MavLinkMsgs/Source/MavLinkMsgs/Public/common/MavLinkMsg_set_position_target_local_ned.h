 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_set_position_target_local_ned.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_set_position_target_local_ned
{
    GENERATED_BODY()

    static const uint32 MsgId = 84;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9 */
    UPROPERTY()
    uint8 coordinate_frame;

    /*Bitmap to indicate which dimensions should be ignored by the vehicle. */
    UPROPERTY()
    uint16 type_mask;

    /*X Position in NED frame [m]*/
    UPROPERTY()
    float x;

    /*Y Position in NED frame [m]*/
    UPROPERTY()
    float y;

    /*Z Position in NED frame (note, altitude is negative in NED) [m]*/
    UPROPERTY()
    float z;

    /*X velocity in NED frame [m/s]*/
    UPROPERTY()
    float vx;

    /*Y velocity in NED frame [m/s]*/
    UPROPERTY()
    float vy;

    /*Z velocity in NED frame [m/s]*/
    UPROPERTY()
    float vz;

    /*X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s]*/
    UPROPERTY()
    float afx;

    /*Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s]*/
    UPROPERTY()
    float afy;

    /*Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s]*/
    UPROPERTY()
    float afz;

    /*yaw setpoint [rad]*/
    UPROPERTY()
    float yaw;

    /*yaw rate setpoint [rad/s]*/
    UPROPERTY()
    float yaw_rate;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
