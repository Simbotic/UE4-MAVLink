 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_command_ack.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_command_ack
{
    GENERATED_BODY()

    /*Command ID (of acknowledged command). */
    UPROPERTY()
    uint16 command;

    /*Result of command. */
    UPROPERTY()
    uint8 result;

    /*WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS. */
    UPROPERTY()
    uint8 progress;

    /*WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied. */
    UPROPERTY()
    int32 result_param2;

    /*WIP: System which requested the command to be executed */
    UPROPERTY()
    uint8 target_system;

    /*WIP: Component which requested the command to be executed */
    UPROPERTY()
    uint8 target_component;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
