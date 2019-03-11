 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_statustext.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_statustext
{
    GENERATED_BODY()

    /*Severity of status. Relies on the definitions within RFC-5424. */
    UPROPERTY()
    uint8 severity;

    /*Status text message, without null termination character */
    UPROPERTY()
    uint8 text[50];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
