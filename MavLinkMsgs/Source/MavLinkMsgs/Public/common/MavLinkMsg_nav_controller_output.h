 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_nav_controller_output.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_nav_controller_output
{
    GENERATED_BODY()

    static const uint32 MsgId = 62;
    /*Current desired roll [deg]*/
    UPROPERTY()
    float nav_roll;

    /*Current desired pitch [deg]*/
    UPROPERTY()
    float nav_pitch;

    /*Current desired heading [deg]*/
    UPROPERTY()
    int16 nav_bearing;

    /*Bearing to current waypoint/target [deg]*/
    UPROPERTY()
    int16 target_bearing;

    /*Distance to active waypoint [m]*/
    UPROPERTY()
    uint16 wp_dist;

    /*Current altitude error [m]*/
    UPROPERTY()
    float alt_error;

    /*Current airspeed error [m/s]*/
    UPROPERTY()
    float aspd_error;

    /*Current crosstrack error on x-y plane [m]*/
    UPROPERTY()
    float xtrack_error;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
