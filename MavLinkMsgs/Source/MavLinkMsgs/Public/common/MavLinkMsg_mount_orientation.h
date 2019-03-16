 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_mount_orientation.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_mount_orientation
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 265;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Roll in global frame (set to NaN for invalid). [deg]*/
    UPROPERTY()
    float roll;

    /*Pitch in global frame (set to NaN for invalid). [deg]*/
    UPROPERTY()
    float pitch;

    /*Yaw relative to vehicle(set to NaN for invalid). [deg]*/
    UPROPERTY()
    float yaw;

    /*Yaw in absolute frame, North is 0 (set to NaN for invalid). [deg]*/
    UPROPERTY()
    float yaw_absolute;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
