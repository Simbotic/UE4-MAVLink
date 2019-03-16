 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_terrain_request.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_terrain_request
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 133;
    /*Latitude of SW corner of first grid [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude of SW corner of first grid [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Grid spacing [m]*/
    UPROPERTY()
    uint16 grid_spacing;

    /*Bitmask of requested 4x4 grids (row major 8x7 array of grids, 56 bits) */
    UPROPERTY()
    uint64 mask;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
