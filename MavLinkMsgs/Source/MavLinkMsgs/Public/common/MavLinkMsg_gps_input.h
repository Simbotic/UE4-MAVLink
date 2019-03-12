 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_input.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_input
{
    GENERATED_BODY()

    static const uint32 MsgId = 232;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*ID of the GPS for multiple GPS inputs */
    UPROPERTY()
    uint8 gps_id;

    /*Bitmap indicating which GPS input flags fields to ignore.  All other fields must be provided. */
    UPROPERTY()
    uint16 ignore_flags;

    /*GPS time (from start of GPS week) [ms]*/
    UPROPERTY()
    uint32 time_week_ms;

    /*GPS week number */
    UPROPERTY()
    uint16 time_week;

    /*0-1: no fix, 2: 2D fix, 3: 3D fix. 4: 3D with DGPS. 5: 3D with RTK */
    UPROPERTY()
    uint8 fix_type;

    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL). Positive for up. [m]*/
    UPROPERTY()
    float alt;

    /*GPS HDOP horizontal dilution of position [m]*/
    UPROPERTY()
    float hdop;

    /*GPS VDOP vertical dilution of position [m]*/
    UPROPERTY()
    float vdop;

    /*GPS velocity in NORTH direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float vn;

    /*GPS velocity in EAST direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float ve;

    /*GPS velocity in DOWN direction in earth-fixed NED frame [m/s]*/
    UPROPERTY()
    float vd;

    /*GPS speed accuracy [m/s]*/
    UPROPERTY()
    float speed_accuracy;

    /*GPS horizontal accuracy [m]*/
    UPROPERTY()
    float horiz_accuracy;

    /*GPS vertical accuracy [m]*/
    UPROPERTY()
    float vert_accuracy;

    /*Number of satellites visible. */
    UPROPERTY()
    uint8 satellites_visible;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
