 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_data_transmission_handshake.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_data_transmission_handshake
{
    GENERATED_BODY()

    /*Type of requested/acknowledged data. */
    UPROPERTY()
    uint8 type;

    /*total data size (set on ACK only). [bytes]*/
    UPROPERTY()
    uint32 size;

    /*Width of a matrix or image. */
    UPROPERTY()
    uint16 width;

    /*Height of a matrix or image. */
    UPROPERTY()
    uint16 height;

    /*Number of packets being sent (set on ACK only). */
    UPROPERTY()
    uint16 packets;

    /*Payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only). [bytes]*/
    UPROPERTY()
    uint8 payload;

    /*JPEG quality. Values: [1-100]. [%]*/
    UPROPERTY()
    uint8 jpg_quality;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
