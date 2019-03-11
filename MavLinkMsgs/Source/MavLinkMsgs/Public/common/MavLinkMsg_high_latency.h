 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_high_latency.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_high_latency
{
    GENERATED_BODY()

    /*Bitmap of enabled system modes. */
    UPROPERTY()
    uint8 base_mode;

    /*A bitfield for use for autopilot-specific flags. */
    UPROPERTY()
    uint32 custom_mode;

    /*The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    UPROPERTY()
    uint8 landed_state;

    /*roll [cdeg]*/
    UPROPERTY()
    int16 roll;

    /*pitch [cdeg]*/
    UPROPERTY()
    int16 pitch;

    /*heading [cdeg]*/
    UPROPERTY()
    uint16 heading;

    /*throttle (percentage) [%]*/
    UPROPERTY()
    int8 throttle;

    /*heading setpoint [cdeg]*/
    UPROPERTY()
    int16 heading_sp;

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 latitude;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 longitude;

    /*Altitude above mean sea level [m]*/
    UPROPERTY()
    int16 altitude_amsl;

    /*Altitude setpoint relative to the home position [m]*/
    UPROPERTY()
    int16 altitude_sp;

    /*airspeed [m/s]*/
    UPROPERTY()
    uint8 airspeed;

    /*airspeed setpoint [m/s]*/
    UPROPERTY()
    uint8 airspeed_sp;

    /*groundspeed [m/s]*/
    UPROPERTY()
    uint8 groundspeed;

    /*climb rate [m/s]*/
    UPROPERTY()
    int8 climb_rate;

    /*Number of satellites visible. If unknown, set to 255 */
    UPROPERTY()
    uint8 gps_nsat;

    /*GPS Fix type. */
    UPROPERTY()
    uint8 gps_fix_type;

    /*Remaining battery (percentage) [%]*/
    UPROPERTY()
    uint8 battery_remaining;

    /*Autopilot temperature (degrees C) [degC]*/
    UPROPERTY()
    int8 temperature;

    /*Air temperature (degrees C) from airspeed sensor [degC]*/
    UPROPERTY()
    int8 temperature_air;

    /*failsafe (each bit represents a failsafe where 0=ok, 1=failsafe active (bit0:RC, bit1:batt, bit2:GPS, bit3:GCS, bit4:fence) */
    UPROPERTY()
    uint8 failsafe;

    /*current waypoint number */
    UPROPERTY()
    uint8 wp_num;

    /*distance to target [m]*/
    UPROPERTY()
    uint16 wp_distance;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
