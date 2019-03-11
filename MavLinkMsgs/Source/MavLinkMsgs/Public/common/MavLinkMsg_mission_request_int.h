 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_request_int.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_request_int
{
    GENERATED_BODY()

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Sequence */
    UPROPERTY()
    uint16 seq;

    /*Mission type. */
    UPROPERTY()
    uint8 mission_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};