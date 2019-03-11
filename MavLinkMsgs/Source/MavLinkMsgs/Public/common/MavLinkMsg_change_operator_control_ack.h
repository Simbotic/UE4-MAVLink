 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_change_operator_control_ack.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_change_operator_control_ack
{
    GENERATED_BODY()

    /*ID of the GCS this message  */
    UPROPERTY()
    uint8 gcs_system_id;

    /*0: request control of this MAV, 1: Release control of this MAV */
    UPROPERTY()
    uint8 control_request;

    /*0: ACK, 1: NACK: Wrong passkey, 2: NACK: Unsupported passkey encryption method, 3: NACK: Already under control */
    UPROPERTY()
    uint8 ack;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
