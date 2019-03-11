 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_inject_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_inject_data
{
    GENERATED_BODY()

    /*System ID */
    UPROPERTY()
    uint8 target_system;

    /*Component ID */
    UPROPERTY()
    uint8 target_component;

    /*Data length [bytes]*/
    UPROPERTY()
    uint8 len;

    /*Raw data (110 is enough for 12 satellites of RTCMv2) */
    UPROPERTY()
    uint8 data[110];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
