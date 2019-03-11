 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_resource_request.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_resource_request
{
    GENERATED_BODY()

    /*Request ID. This ID should be re-used when sending back URI contents */
    UPROPERTY()
    uint8 request_id;

    /*The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary */
    UPROPERTY()
    uint8 uri_type;

    /*The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum) */
    UPROPERTY()
    uint8 uri[120];

    /*The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream. */
    UPROPERTY()
    uint8 transfer_type;

    /*The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP). */
    UPROPERTY()
    uint8 storage[120];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
