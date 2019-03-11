 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_request_data_stream.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_request_data_stream
{
    GENERATED_BODY()

    /*The target requested to send the message stream. */
    UPROPERTY()
    uint8 target_system;

    /*The target requested to send the message stream. */
    UPROPERTY()
    uint8 target_component;

    /*The ID of the requested data stream */
    UPROPERTY()
    uint8 req_stream_id;

    /*The requested message rate [Hz]*/
    UPROPERTY()
    uint16 req_message_rate;

    /*1 to start sending, 0 to stop sending. */
    UPROPERTY()
    uint8 start_stop;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
