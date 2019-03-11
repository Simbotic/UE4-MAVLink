 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mission_write_partial_list.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mission_write_partial_list
{
    GENERATED_BODY()

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Start index. Must be smaller / equal to the largest index of the current onboard list. */
    UPROPERTY()
    int16 start_index;

    /*End index, equal or greater than start index. */
    UPROPERTY()
    int16 end_index;

    /*Mission type. */
    UPROPERTY()
    uint8 mission_type;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
