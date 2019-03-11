 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_data_stream.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_data_stream
{
    GENERATED_BODY()

    /*The ID of the requested data stream */
    UPROPERTY()
    uint8 stream_id;

    /*The message rate [Hz]*/
    UPROPERTY()
    uint16 message_rate;

    /*1 stream is enabled, 0 stream is stopped. */
    UPROPERTY()
    uint8 on_off;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
