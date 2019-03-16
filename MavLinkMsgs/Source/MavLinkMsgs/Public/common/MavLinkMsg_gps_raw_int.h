 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_raw_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_raw_int
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 24;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*GPS fix type. */
    UPROPERTY()
    uint8 fix_type;

    /*Latitude (WGS84, EGM96 ellipsoid) [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude (WGS84, EGM96 ellipsoid) [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude. [mm]*/
    UPROPERTY()
    int32 alt;

    /*GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX */
    UPROPERTY()
    uint16 eph;

    /*GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX */
    UPROPERTY()
    uint16 epv;

    /*GPS ground speed. If unknown, set to: UINT16_MAX [cm/s]*/
    UPROPERTY()
    uint16 vel;

    /*Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg]*/
    UPROPERTY()
    uint16 cog;

    /*Number of satellites visible. If unknown, set to 255 */
    UPROPERTY()
    uint8 satellites_visible;

    /*Altitude (above WGS84, EGM96 ellipsoid). Positive for up. [mm]*/
    UPROPERTY()
    int32 alt_ellipsoid;

    /*Position uncertainty. Positive for up. [mm]*/
    UPROPERTY()
    uint32 h_acc;

    /*Altitude uncertainty. Positive for up. [mm]*/
    UPROPERTY()
    uint32 v_acc;

    /*Speed uncertainty. Positive for up. [mm]*/
    UPROPERTY()
    uint32 vel_acc;

    /*Heading / track uncertainty [degE5]*/
    UPROPERTY()
    uint32 hdg_acc;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
