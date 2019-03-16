 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_odometry.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_odometry
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 331;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Coordinate frame of reference for the pose data. */
    UPROPERTY()
    uint8 frame_id;

    /*Coordinate frame of reference for the velocity in free space (twist) data. */
    UPROPERTY()
    uint8 child_frame_id;

    /*X Position [m]*/
    UPROPERTY()
    float x;

    /*Y Position [m]*/
    UPROPERTY()
    float y;

    /*Z Position [m]*/
    UPROPERTY()
    float z;

    /*Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    UPROPERTY()
    float q[4];

    /*X linear speed [m/s]*/
    UPROPERTY()
    float vx;

    /*Y linear speed [m/s]*/
    UPROPERTY()
    float vy;

    /*Z linear speed [m/s]*/
    UPROPERTY()
    float vz;

    /*Roll angular speed [rad/s]*/
    UPROPERTY()
    float rollspeed;

    /*Pitch angular speed [rad/s]*/
    UPROPERTY()
    float pitchspeed;

    /*Yaw angular speed [rad/s]*/
    UPROPERTY()
    float yawspeed;

    /*Row-major representation of a 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float pose_covariance[21];

    /*Row-major representation of a 6x6 velocity cross-covariance matrix upper right triangle (states: vx, vy, vz, rollspeed, pitchspeed, yawspeed; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float velocity_covariance[21];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
