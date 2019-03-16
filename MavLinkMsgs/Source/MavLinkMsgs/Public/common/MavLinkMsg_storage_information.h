 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_storage_information.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_storage_information
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 261;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Storage ID (1 for first, 2 for second, etc.) */
    UPROPERTY()
    uint8 storage_id;

    /*Number of storage devices */
    UPROPERTY()
    uint8 storage_count;

    /*Status of storage (0 not available, 1 unformatted, 2 formatted) */
    UPROPERTY()
    uint8 status;

    /*Total capacity. [MiB]*/
    UPROPERTY()
    float total_capacity;

    /*Used capacity. [MiB]*/
    UPROPERTY()
    float used_capacity;

    /*Available storage capacity. [MiB]*/
    UPROPERTY()
    float available_capacity;

    /*Read speed. [MiB/s]*/
    UPROPERTY()
    float read_speed;

    /*Write speed. [MiB/s]*/
    UPROPERTY()
    float write_speed;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
