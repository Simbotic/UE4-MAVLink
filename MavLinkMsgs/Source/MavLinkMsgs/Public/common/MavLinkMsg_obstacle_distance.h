 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_obstacle_distance.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_obstacle_distance
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Class id of the distance sensor type. */
    UPROPERTY()
    uint8 sensor_type;

    /*Distance of obstacles around the UAV with index 0 corresponding to local North. A value of 0 means that the obstacle is right in front of the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm. [cm]*/
    UPROPERTY()
    uint16 distances[72];

    /*Angular width in degrees of each array element. [deg]*/
    UPROPERTY()
    uint8 increment;

    /*Minimum distance the sensor can measure. [cm]*/
    UPROPERTY()
    uint16 min_distance;

    /*Maximum distance the sensor can measure. [cm]*/
    UPROPERTY()
    uint16 max_distance;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
