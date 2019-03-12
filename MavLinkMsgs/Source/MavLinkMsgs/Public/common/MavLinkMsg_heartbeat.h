 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_heartbeat.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_heartbeat
{
    GENERATED_BODY()

    static const uint32 MsgId = 0;
    /*Type of the system (quadrotor, helicopter, etc.). Components use the same type as their associated system. */
    UPROPERTY()
    uint8 type;

    /*Autopilot type / class. */
    UPROPERTY()
    uint8 autopilot;

    /*System mode bitmap. */
    UPROPERTY()
    uint8 base_mode;

    /*A bitfield for use for autopilot-specific flags */
    UPROPERTY()
    uint32 custom_mode;

    /*System status flag. */
    UPROPERTY()
    uint8 system_status;

    /*MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version */
    UPROPERTY()
    uint8 mavlink_version;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
