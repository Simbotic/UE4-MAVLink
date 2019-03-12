 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_safety_allowed_area.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_safety_allowed_area
{
    GENERATED_BODY()

    static const uint32 MsgId = 55;
    /*Coordinate frame. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down. */
    UPROPERTY()
    uint8 frame;

    /*x position 1 / Latitude 1 [m]*/
    UPROPERTY()
    float p1x;

    /*y position 1 / Longitude 1 [m]*/
    UPROPERTY()
    float p1y;

    /*z position 1 / Altitude 1 [m]*/
    UPROPERTY()
    float p1z;

    /*x position 2 / Latitude 2 [m]*/
    UPROPERTY()
    float p2x;

    /*y position 2 / Longitude 2 [m]*/
    UPROPERTY()
    float p2y;

    /*z position 2 / Altitude 2 [m]*/
    UPROPERTY()
    float p2z;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
