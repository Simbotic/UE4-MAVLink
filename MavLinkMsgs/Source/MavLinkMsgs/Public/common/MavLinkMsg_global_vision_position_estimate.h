 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_global_vision_position_estimate.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_global_vision_position_estimate
{
    GENERATED_BODY()

    static const uint32 MsgId = 101;
    /*Timestamp (UNIX time or since system boot) [us]*/
    UPROPERTY()
    uint64 usec;

    /*Global X position [m]*/
    UPROPERTY()
    float x;

    /*Global Y position [m]*/
    UPROPERTY()
    float y;

    /*Global Z position [m]*/
    UPROPERTY()
    float z;

    /*Roll angle [rad]*/
    UPROPERTY()
    float roll;

    /*Pitch angle [rad]*/
    UPROPERTY()
    float pitch;

    /*Yaw angle [rad]*/
    UPROPERTY()
    float yaw;

    /*Row-major representation of pose 6x6 cross-covariance matrix upper right triangle (states: x_global, y_global, z_global, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[21];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
