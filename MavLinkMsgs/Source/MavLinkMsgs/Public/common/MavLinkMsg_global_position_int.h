 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_global_position_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_global_position_int
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 33;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Latitude, expressed [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude, expressed [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL. [mm]*/
    UPROPERTY()
    int32 alt;

    /*Altitude above ground [mm]*/
    UPROPERTY()
    int32 relative_alt;

    /*Ground X Speed (Latitude, positive north) [cm/s]*/
    UPROPERTY()
    int16 vx;

    /*Ground Y Speed (Longitude, positive east) [cm/s]*/
    UPROPERTY()
    int16 vy;

    /*Ground Z Speed (Altitude, positive down) [cm/s]*/
    UPROPERTY()
    int16 vz;

    /*Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg]*/
    UPROPERTY()
    uint16 hdg;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
