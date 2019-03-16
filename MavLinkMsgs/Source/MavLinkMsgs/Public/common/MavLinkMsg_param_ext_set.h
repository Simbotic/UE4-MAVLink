 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_param_ext_set.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_param_ext_set
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 323;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    UPROPERTY()
    uint8 param_id[16];

    /*Parameter value */
    UPROPERTY()
    uint8 param_value[128];

    /*Parameter type. */
    UPROPERTY()
    uint8 param_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
