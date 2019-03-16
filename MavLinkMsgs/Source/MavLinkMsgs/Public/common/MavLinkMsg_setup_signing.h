 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_setup_signing.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_setup_signing
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 256;
    /*system id of the target */
    UPROPERTY()
    uint8 target_system;

    /*component ID of the target */
    UPROPERTY()
    uint8 target_component;

    /*signing key */
    UPROPERTY()
    uint8 secret_key[32];

    /*initial timestamp */
    UPROPERTY()
    uint64 initial_timestamp;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
