 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_param_request_read.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_param_request_read
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 20;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    UPROPERTY()
    uint8 param_id[16];

    /*Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored) */
    UPROPERTY()
    int16 param_index;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
