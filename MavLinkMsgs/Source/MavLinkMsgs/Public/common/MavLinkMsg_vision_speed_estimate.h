 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_vision_speed_estimate.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_vision_speed_estimate
{
    GENERATED_BODY()

    /*Timestamp (UNIX time or time since system boot) [us]*/
    UPROPERTY()
    uint64 usec;

    /*Global X speed [m/s]*/
    UPROPERTY()
    float x;

    /*Global Y speed [m/s]*/
    UPROPERTY()
    float y;

    /*Global Z speed [m/s]*/
    UPROPERTY()
    float z;

    /*Row-major representation of 3x3 linear velocity covariance matrix (states: vx, vy, vz; 1st three entries - 1st row, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[9];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
