 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps2_raw.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps2_raw
{
    GENERATED_BODY()

    static const uint32 MsgId = 124;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*GPS fix type. */
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

    /*GPS HDOP horizontal dilution of position. If unknown, set to: UINT16_MAX [cm]*/
    UPROPERTY()
    uint16 eph;

    /*GPS VDOP vertical dilution of position. If unknown, set to: UINT16_MAX [cm]*/
    UPROPERTY()
    uint16 epv;

    /*GPS ground speed. If unknown, set to: UINT16_MAX [cm/s]*/
    UPROPERTY()
    uint16 vel;

    /*Course over ground (NOT heading, but direction of movement): 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg]*/
    UPROPERTY()
    uint16 cog;

    /*Number of satellites visible. If unknown, set to 255 */
    UPROPERTY()
    uint8 satellites_visible;

    /*Number of DGPS satellites */
    UPROPERTY()
    uint8 dgps_numch;

    /*Age of DGPS info [ms]*/
    UPROPERTY()
    uint32 dgps_age;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
