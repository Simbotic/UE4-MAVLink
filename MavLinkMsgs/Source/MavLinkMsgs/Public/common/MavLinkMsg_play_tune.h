 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_play_tune.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_play_tune
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 258;
    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*tune in board specific format */
    UPROPERTY()
    uint8 tune[30];

    /*tune extension (appended to tune) */
    UPROPERTY()
    uint8 tune2[200];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
