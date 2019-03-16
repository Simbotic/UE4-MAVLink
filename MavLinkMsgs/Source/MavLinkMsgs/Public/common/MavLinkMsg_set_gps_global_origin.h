 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_set_gps_global_origin.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_set_gps_global_origin
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 48;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 latitude;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 longitude;

    /*Altitude (MSL). Positive for up. [mm]*/
    UPROPERTY()
    int32 altitude;

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
