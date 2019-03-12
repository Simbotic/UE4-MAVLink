 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_gps.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_gps
{
    GENERATED_BODY()

    static const uint32 MsgId = 113;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix. */
    UPROPERTY()
    uint8 fix_type;

    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL). Positive for up. [mm]*/
    UPROPERTY()
    int32 alt;

    /*GPS HDOP horizontal dilution of position. If unknown, set to: 65535 [cm]*/
    UPROPERTY()
    uint16 eph;

    /*GPS VDOP vertical dilution of position. If unknown, set to: 65535 [cm]*/
    UPROPERTY()
    uint16 epv;

    /*GPS ground speed. If unknown, set to: 65535 [cm/s]*/
    UPROPERTY()
    uint16 vel;

    /*GPS velocity in NORTH direction in earth-fixed NED frame [cm/s]*/
    UPROPERTY()
    int16 vn;

    /*GPS velocity in EAST direction in earth-fixed NED frame [cm/s]*/
    UPROPERTY()
    int16 ve;

    /*GPS velocity in DOWN direction in earth-fixed NED frame [cm/s]*/
    UPROPERTY()
    int16 vd;

    /*Course over ground (NOT heading, but direction of movement), 0.0..359.99 degrees. If unknown, set to: 65535 [cdeg]*/
    UPROPERTY()
    uint16 cog;

    /*Number of satellites visible. If unknown, set to 255 */
    UPROPERTY()
    uint8 satellites_visible;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
