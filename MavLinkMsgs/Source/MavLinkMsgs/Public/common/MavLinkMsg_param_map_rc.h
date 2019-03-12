 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_param_map_rc.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_param_map_rc
{
    GENERATED_BODY()

    static const uint32 MsgId = 50;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    UPROPERTY()
    uint8 param_id[16];

    /*Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index. */
    UPROPERTY()
    int16 param_index;

    /*Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC. */
    UPROPERTY()
    uint8 parameter_rc_channel_index;

    /*Initial parameter value */
    UPROPERTY()
    float param_value0;

    /*Scale, maps the RC range [-1, 1] to a parameter value */
    UPROPERTY()
    float scale;

    /*Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation) */
    UPROPERTY()
    float param_value_min;

    /*Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation) */
    UPROPERTY()
    float param_value_max;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
