 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_position_target_global_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_position_target_global_int
{
    GENERATED_BODY()

    static const uint32 MsgId = 87;
    /*Timestamp (time since system boot). The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency. [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Valid options are: MAV_FRAME_GLOBAL_INT = 5, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT = 6, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT = 11 */
    UPROPERTY()
    uint8 coordinate_frame;

    /*Bitmap to indicate which dimensions should be ignored by the vehicle. */
    UPROPERTY()
    uint16 type_mask;

    /*X Position in WGS84 frame [degE7]*/
    UPROPERTY()
    int32 lat_int;

    /*Y Position in WGS84 frame [degE7]*/
    UPROPERTY()
    int32 lon_int;

    /*Altitude (MSL, AGL or relative to home altitude, depending on frame) [m]*/
    UPROPERTY()
    float alt;

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
