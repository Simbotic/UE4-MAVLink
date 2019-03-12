 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_protocol_version.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_protocol_version
{
    GENERATED_BODY()

    static const uint32 MsgId = 300;
    /*Currently active MAVLink version number * 100: v1.0 is 100, v2.0 is 200, etc. */
    UPROPERTY()
    uint16 version;

    /*Minimum MAVLink version supported */
    UPROPERTY()
    uint16 min_version;

    /*Maximum MAVLink version supported (set to the same value as version by default) */
    UPROPERTY()
    uint16 max_version;

    /*The first 8 bytes (not characters printed in hex!) of the git hash. */
    UPROPERTY()
    uint8 spec_version_hash[8];

    /*The first 8 bytes (not characters printed in hex!) of the git hash. */
    UPROPERTY()
    uint8 library_version_hash[8];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
