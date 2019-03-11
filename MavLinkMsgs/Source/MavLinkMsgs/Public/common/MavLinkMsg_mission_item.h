 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_item.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_item
{
    GENERATED_BODY()

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Sequence */
    UPROPERTY()
    uint16 seq;

    /*The coordinate system of the waypoint. */
    UPROPERTY()
    uint8 frame;

    /*The scheduled action for the waypoint. */
    UPROPERTY()
    uint16 command;

    /*false:0, true:1 */
    UPROPERTY()
    uint8 current;

    /*Autocontinue to next waypoint */
    UPROPERTY()
    uint8 autocontinue;

    /*PARAM1, see MAV_CMD enum */
    UPROPERTY()
    float param1;

    /*PARAM2, see MAV_CMD enum */
    UPROPERTY()
    float param2;

    /*PARAM3, see MAV_CMD enum */
    UPROPERTY()
    float param3;

    /*PARAM4, see MAV_CMD enum */
    UPROPERTY()
    float param4;

    /*PARAM5 / local: X coordinate, global: latitude */
    UPROPERTY()
    float x;

    /*PARAM6 / local: Y coordinate, global: longitude */
    UPROPERTY()
    float y;

    /*PARAM7 / local: Z coordinate, global: altitude (relative or absolute, depending on frame). */
    UPROPERTY()
    float z;

    /*Mission type. */
    UPROPERTY()
    uint8 mission_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
