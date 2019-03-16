 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_high_latency2.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_high_latency2
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 235;
    /*Timestamp (milliseconds since boot or Unix epoch) [ms]*/
    UPROPERTY()
    uint32 timestamp;

    /*Type of the MAV (quadrotor, helicopter, etc.) */
    UPROPERTY()
    uint8 type;

    /*Autopilot type / class. */
    UPROPERTY()
    uint8 autopilot;

    /*A bitfield for use for autopilot-specific flags (2 byte version). */
    UPROPERTY()
    uint16 custom_mode;

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 latitude;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 longitude;

    /*Altitude above mean sea level [m]*/
    UPROPERTY()
    int16 altitude;

    /*Altitude setpoint [m]*/
    UPROPERTY()
    int16 target_altitude;

    /*Heading [deg/2]*/
    UPROPERTY()
    uint8 heading;

    /*Heading setpoint [deg/2]*/
    UPROPERTY()
    uint8 target_heading;

    /*Distance to target waypoint or position [dam]*/
    UPROPERTY()
    uint16 target_distance;

    /*Throttle [%]*/
    UPROPERTY()
    uint8 throttle;

    /*Airspeed [m/s*5]*/
    UPROPERTY()
    uint8 airspeed;

    /*Airspeed setpoint [m/s*5]*/
    UPROPERTY()
    uint8 airspeed_sp;

    /*Groundspeed [m/s*5]*/
    UPROPERTY()
    uint8 groundspeed;

    /*Windspeed [m/s*5]*/
    UPROPERTY()
    uint8 windspeed;

    /*Wind heading [deg/2]*/
    UPROPERTY()
    uint8 wind_heading;

    /*Maximum error horizontal position since last message [dm]*/
    UPROPERTY()
    uint8 eph;

    /*Maximum error vertical position since last message [dm]*/
    UPROPERTY()
    uint8 epv;

    /*Air temperature from airspeed sensor [degC]*/
    UPROPERTY()
    int8 temperature_air;

    /*Maximum climb rate magnitude since last message [dm/s]*/
    UPROPERTY()
    int8 climb_rate;

    /*Battery (percentage, -1 for DNU) [%]*/
    UPROPERTY()
    int8 battery;

    /*Current waypoint number */
    UPROPERTY()
    uint16 wp_num;

    /*Bitmap of failure flags. */
    UPROPERTY()
    uint16 failure_flags;

    /*Field for custom payload. */
    UPROPERTY()
    int8 custom0;

    /*Field for custom payload. */
    UPROPERTY()
    int8 custom1;

    /*Field for custom payload. */
    UPROPERTY()
    int8 custom2;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
