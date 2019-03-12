 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_utm_global_position.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_utm_global_position
{
    GENERATED_BODY()

    static const uint32 MsgId = 340;
    /*Time of applicability of position (microseconds since UNIX epoch). [us]*/
    UPROPERTY()
    uint64 time;

    /*Unique UAS ID. */
    UPROPERTY()
    uint8 uas_id[18];

    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (WGS84) [mm]*/
    UPROPERTY()
    int32 alt;

    /*Altitude above ground [mm]*/
    UPROPERTY()
    int32 relative_alt;

    /*Ground X speed (latitude, positive north) [cm/s]*/
    UPROPERTY()
    int16 vx;

    /*Ground Y speed (longitude, positive east) [cm/s]*/
    UPROPERTY()
    int16 vy;

    /*Ground Z speed (altitude, positive down) [cm/s]*/
    UPROPERTY()
    int16 vz;

    /*Horizontal position uncertainty (standard deviation) [mm]*/
    UPROPERTY()
    uint16 h_acc;

    /*Altitude uncertainty (standard deviation) [mm]*/
    UPROPERTY()
    uint16 v_acc;

    /*Speed uncertainty (standard deviation) [cm/s]*/
    UPROPERTY()
    uint16 vel_acc;

    /*Next waypoint, latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 next_lat;

    /*Next waypoint, longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 next_lon;

    /*Next waypoint, altitude (WGS84) [mm]*/
    UPROPERTY()
    int32 next_alt;

    /*Time until next update. Set to 0 if unknown or in data driven mode. [cs]*/
    UPROPERTY()
    uint16 update_rate;

    /*Flight state */
    UPROPERTY()
    uint8 flight_state;

    /*Bitwise OR combination of the data available flags. */
    UPROPERTY()
    uint8 flags;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
