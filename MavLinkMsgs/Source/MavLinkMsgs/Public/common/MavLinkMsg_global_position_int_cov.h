 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_global_position_int_cov.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_global_position_int_cov
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Class id of the estimator this estimate originated from. */
    UPROPERTY()
    uint8 estimator_type;

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude in meters above MSL [mm]*/
    UPROPERTY()
    int32 alt;

    /*Altitude above ground [mm]*/
    UPROPERTY()
    int32 relative_alt;

    /*Ground X Speed (Latitude) [m/s]*/
    UPROPERTY()
    float vx;

    /*Ground Y Speed (Longitude) [m/s]*/
    UPROPERTY()
    float vy;

    /*Ground Z Speed (Altitude) [m/s]*/
    UPROPERTY()
    float vz;

    /*Row-major representation of a 6x6 position and velocity 6x6 cross-covariance matrix (states: lat, lon, alt, vx, vy, vz; first six entries are the first ROW, next six entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    UPROPERTY()
    float covariance[36];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
