 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_att_pos_mocap.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_att_pos_mocap
{
    GENERATED_BODY()

    static const uint32 MsgId = 138;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    UPROPERTY()
    float q[4];

    /*X position (NED) [m]*/
    UPROPERTY()
    float x;

    /*Y position (NED) [m]*/
    UPROPERTY()
    float y;

    /*Z position (NED) [m]*/
    UPROPERTY()
    float z;

    /*Row-major representation of a pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[21];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
