 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_command_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_command_int
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 75;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*The coordinate system of the COMMAND. */
    UPROPERTY()
    uint8 frame;

    /*The scheduled action for the mission item. */
    UPROPERTY()
    uint16 command;

    /*false:0, true:1 */
    UPROPERTY()
    uint8 current;

    /*autocontinue to next wp */
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

    /*PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7 */
    UPROPERTY()
    int32 x;

    /*PARAM6 / local: y position in meters * 1e4, global: longitude in degrees * 10^7 */
    UPROPERTY()
    int32 y;

    /*PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame). */
    UPROPERTY()
    float z;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
