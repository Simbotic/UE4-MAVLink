 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_status
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 25;
    /*Number of satellites visible */
    UPROPERTY()
    uint8 satellites_visible;

    /*Global satellite ID */
    UPROPERTY()
    uint8 satellite_prn[20];

    /*0: Satellite not used, 1: used for localization */
    UPROPERTY()
    uint8 satellite_used[20];

    /*Elevation (0: right on top of receiver, 90: on the horizon) of satellite [deg]*/
    UPROPERTY()
    uint8 satellite_elevation[20];

    /*Direction of satellite, 0: 0 deg, 255: 360 deg. [deg]*/
    UPROPERTY()
    uint8 satellite_azimuth[20];

    /*Signal to noise ratio of satellite [dB]*/
    UPROPERTY()
    uint8 satellite_snr[20];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
