 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_trajectory_representation_bezier.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_trajectory_representation_bezier
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 333;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Number of valid points (up-to 5 waypoints are possible) */
    UPROPERTY()
    uint8 valid_points;

    /*X-coordinate of starting bezier point, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_x[5];

    /*Y-coordinate of starting bezier point, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_y[5];

    /*Z-coordinate of starting bezier point, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_z[5];

    /*Bezier time horizon, set to NaN if velocity/acceleration should not be incorporated [s]*/
    UPROPERTY()
    float delta[5];

    /*Yaw, set to NaN for unchanged [rad]*/
    UPROPERTY()
    float pos_yaw[5];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
