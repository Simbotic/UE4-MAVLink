 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_manual_setpoint.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_manual_setpoint
{
    GENERATED_BODY()

    static const uint32 MsgId = 81;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Desired roll rate [rad/s]*/
    UPROPERTY()
    float roll;

    /*Desired pitch rate [rad/s]*/
    UPROPERTY()
    float pitch;

    /*Desired yaw rate [rad/s]*/
    UPROPERTY()
    float yaw;

    /*Collective thrust, normalized to 0 .. 1 */
    UPROPERTY()
    float thrust;

    /*Flight mode switch position, 0.. 255 */
    UPROPERTY()
    uint8 mode_switch;

    /*Override mode switch position, 0.. 255 */
    UPROPERTY()
    uint8 manual_override_switch;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
