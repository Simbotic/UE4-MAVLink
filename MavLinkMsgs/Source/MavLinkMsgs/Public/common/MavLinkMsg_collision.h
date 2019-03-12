 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_collision.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_collision
{
    GENERATED_BODY()

    static const uint32 MsgId = 247;
    /*Collision data source */
    UPROPERTY()
    uint8 src;

    /*Unique identifier, domain based on src field */
    UPROPERTY()
    uint32 id;

    /*Action that is being taken to avoid this collision */
    UPROPERTY()
    uint8 action;

    /*How concerned the aircraft is about this collision */
    UPROPERTY()
    uint8 threat_level;

    /*Estimated time until collision occurs [s]*/
    UPROPERTY()
    float time_to_minimum_delta;

    /*Closest vertical distance between vehicle and object [m]*/
    UPROPERTY()
    float altitude_minimum_delta;

    /*Closest horizontal distance between vehicle and object [m]*/
    UPROPERTY()
    float horizontal_minimum_delta;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
