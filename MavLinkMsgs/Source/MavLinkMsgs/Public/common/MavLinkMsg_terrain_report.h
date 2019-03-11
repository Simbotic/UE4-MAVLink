 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_terrain_report.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_terrain_report
{
    GENERATED_BODY()

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 lon;

    /*grid spacing (zero if terrain at this location unavailable) */
    UPROPERTY()
    uint16 spacing;

    /*Terrain height MSL [m]*/
    UPROPERTY()
    float terrain_height;

    /*Current vehicle height above lat/lon terrain height [m]*/
    UPROPERTY()
    float current_height;

    /*Number of 4x4 terrain blocks waiting to be received or read from disk */
    UPROPERTY()
    uint16 pending;

    /*Number of 4x4 terrain blocks in memory */
    UPROPERTY()
    uint16 loaded;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
