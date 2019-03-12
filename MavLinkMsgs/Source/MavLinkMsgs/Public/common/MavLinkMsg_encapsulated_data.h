 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_encapsulated_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_encapsulated_data
{
    GENERATED_BODY()

    static const uint32 MsgId = 131;
    /*sequence number (starting with 0 on every transmission) */
    UPROPERTY()
    uint16 seqnr;

    /*image data bytes */
    UPROPERTY()
    uint8 data[253];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
