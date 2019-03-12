 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_terrain_check.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_terrain_check
{
    GENERATED_BODY()

    static const uint32 MsgId = 135;
    /*Latitude [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 lon;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
