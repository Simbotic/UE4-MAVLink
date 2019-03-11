 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_trajectory_representation_waypoints.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_trajectory_representation_waypoints
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Number of valid points (up-to 5 waypoints are possible) */
    UPROPERTY()
    uint8 valid_points;

    /*X-coordinate of waypoint, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_x[5];

    /*Y-coordinate of waypoint, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_y[5];

    /*Z-coordinate of waypoint, set to NaN if not being used [m]*/
    UPROPERTY()
    float pos_z[5];

    /*X-velocity of waypoint, set to NaN if not being used [m/s]*/
    UPROPERTY()
    float vel_x[5];

    /*Y-velocity of waypoint, set to NaN if not being used [m/s]*/
    UPROPERTY()
    float vel_y[5];

    /*Z-velocity of waypoint, set to NaN if not being used [m/s]*/
    UPROPERTY()
    float vel_z[5];

    /*X-acceleration of waypoint, set to NaN if not being used [m/s/s]*/
    UPROPERTY()
    float acc_x[5];

    /*Y-acceleration of waypoint, set to NaN if not being used [m/s/s]*/
    UPROPERTY()
    float acc_y[5];

    /*Z-acceleration of waypoint, set to NaN if not being used [m/s/s]*/
    UPROPERTY()
    float acc_z[5];

    /*Yaw angle, set to NaN if not being used [rad]*/
    UPROPERTY()
    float pos_yaw[5];

    /*Yaw rate, set to NaN if not being used [rad/s]*/
    UPROPERTY()
    float vel_yaw[5];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
