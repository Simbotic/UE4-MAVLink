 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_change_operator_control.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_change_operator_control
{
    GENERATED_BODY()

    /*System the GCS requests control for */
    UPROPERTY()
    uint8 target_system;

    /*0: request control of this MAV, 1: Release control of this MAV */
    UPROPERTY()
    uint8 control_request;

    /*0: key as plaintext, 1-255: future, different hashing/encryption variants. The GCS should in general use the safest mode possible initially and then gradually move down the encryption level if it gets a NACK message indicating an encryption mismatch. [rad]*/
    UPROPERTY()
    uint8 version;

    /*Password / Key, depending on version plaintext or encrypted. 25 or less characters, NULL terminated. The characters may involve A-Z, a-z, 0-9, and "!?,.-" */
    UPROPERTY()
    uint8 passkey[25];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
