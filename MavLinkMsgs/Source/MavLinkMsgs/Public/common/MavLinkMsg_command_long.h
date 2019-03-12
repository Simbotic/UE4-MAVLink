 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_command_long.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_command_long
{
    GENERATED_BODY()

    static const uint32 MsgId = 76;
    /*System which should execute the command */
    UPROPERTY()
    uint8 target_system;

    /*Component which should execute the command, 0 for all components */
    UPROPERTY()
    uint8 target_component;

    /*Command ID (of command to send). */
    UPROPERTY()
    uint16 command;

    /*0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command) */
    UPROPERTY()
    uint8 confirmation;

    /*Parameter 1 (for the specific command). */
    UPROPERTY()
    float param1;

    /*Parameter 2 (for the specific command). */
    UPROPERTY()
    float param2;

    /*Parameter 3 (for the specific command). */
    UPROPERTY()
    float param3;

    /*Parameter 4 (for the specific command). */
    UPROPERTY()
    float param4;

    /*Parameter 5 (for the specific command). */
    UPROPERTY()
    float param5;

    /*Parameter 6 (for the specific command). */
    UPROPERTY()
    float param6;

    /*Parameter 7 (for the specific command). */
    UPROPERTY()
    float param7;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
