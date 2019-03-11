 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_auth_key.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_auth_key
{
    GENERATED_BODY()

    /*key */
    UPROPERTY()
    uint8 key[32];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
