 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_local_position_ned_system_global_offset.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_local_position_ned_system_global_offset
{
    GENERATED_BODY()

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*X Position [m]*/
    UPROPERTY()
    float x;

    /*Y Position [m]*/
    UPROPERTY()
    float y;

    /*Z Position [m]*/
    UPROPERTY()
    float z;

    /*Roll [rad]*/
    UPROPERTY()
    float roll;

    /*Pitch [rad]*/
    UPROPERTY()
    float pitch;

    /*Yaw [rad]*/
    UPROPERTY()
    float yaw;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
