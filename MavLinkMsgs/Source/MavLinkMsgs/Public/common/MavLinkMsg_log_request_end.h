 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_log_request_end.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_log_request_end
{
    GENERATED_BODY()

    static const uint32 MsgId = 122;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
