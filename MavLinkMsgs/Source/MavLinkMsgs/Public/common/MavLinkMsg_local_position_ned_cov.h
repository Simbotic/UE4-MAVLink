 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_local_position_ned_cov.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_local_position_ned_cov
{
    GENERATED_BODY()

    static const uint32 MsgId = 64;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Class id of the estimator this estimate originated from. */
    UPROPERTY()
    uint8 estimator_type;

    /*X Position [m]*/
    UPROPERTY()
    float x;

    /*Y Position [m]*/
    UPROPERTY()
    float y;

    /*Z Position [m]*/
    UPROPERTY()
    float z;

    /*X Speed [m/s]*/
    UPROPERTY()
    float vx;

    /*Y Speed [m/s]*/
    UPROPERTY()
    float vy;

    /*Z Speed [m/s]*/
    UPROPERTY()
    float vz;

    /*X Acceleration [m/s/s]*/
    UPROPERTY()
    float ax;

    /*Y Acceleration [m/s/s]*/
    UPROPERTY()
    float ay;

    /*Z Acceleration [m/s/s]*/
    UPROPERTY()
    float az;

    /*Row-major representation of position, velocity and acceleration 9x9 cross-covariance matrix upper right triangle (states: x, y, z, vx, vy, vz, ax, ay, az; first nine entries are the first ROW, next eight entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[45];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
