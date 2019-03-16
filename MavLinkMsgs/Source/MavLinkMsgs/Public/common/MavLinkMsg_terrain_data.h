 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_terrain_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_terrain_data
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 134;
    /*Latitude of SW corner of first grid [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude of SW corner of first grid [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Grid spacing [m]*/
    UPROPERTY()
    uint16 grid_spacing;

    /*bit within the terrain request mask */
    UPROPERTY()
    uint8 gridbit;

    /*Terrain data MSL [m]*/
    UPROPERTY()
    int16 data[16];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
