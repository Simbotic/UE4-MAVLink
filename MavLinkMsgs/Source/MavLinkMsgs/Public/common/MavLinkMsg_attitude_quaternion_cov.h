 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_attitude_quaternion_cov.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_attitude_quaternion_cov
{
    GENERATED_BODY()

    static const uint32 MsgId = 61;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    UPROPERTY()
    float q[4];

    /*Roll angular speed [rad/s]*/
    UPROPERTY()
    float rollspeed;

    /*Pitch angular speed [rad/s]*/
    UPROPERTY()
    float pitchspeed;

    /*Yaw angular speed [rad/s]*/
    UPROPERTY()
    float yawspeed;

    /*Row-major representation of a 3x3 attitude covariance matrix (states: roll, pitch, yaw; first three entries are the first ROW, next three entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[9];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
