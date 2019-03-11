 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_scaled_pressure3.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_scaled_pressure3
{
    GENERATED_BODY()

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Absolute pressure [hPa]*/
    UPROPERTY()
    float press_abs;

    /*Differential pressure [hPa]*/
    UPROPERTY()
    float press_diff;

    /*Temperature measurement [cdegC]*/
    UPROPERTY()
    int16 temperature;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
