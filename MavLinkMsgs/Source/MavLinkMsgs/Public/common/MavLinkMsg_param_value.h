 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_param_value.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_param_value
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 22;
    /*Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    UPROPERTY()
    uint8 param_id[16];

    /*Onboard parameter value */
    UPROPERTY()
    float param_value;

    /*Onboard parameter type. */
    UPROPERTY()
    uint8 param_type;

    /*Total number of onboard parameters */
    UPROPERTY()
    uint16 param_count;

    /*Index of this onboard parameter */
    UPROPERTY()
    uint16 param_index;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
