 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_attitude_target.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_attitude_target
{
    GENERATED_BODY()

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Mappings: If any of these bits are set, the corresponding input should be ignored: bit 1: body roll rate, bit 2: body pitch rate, bit 3: body yaw rate. bit 4-bit 7: reserved, bit 8: attitude */
    UPROPERTY()
    uint8 type_mask;

    /*Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    UPROPERTY()
    float q[4];

    /*Body roll rate [rad/s]*/
    UPROPERTY()
    float body_roll_rate;

    /*Body pitch rate [rad/s]*/
    UPROPERTY()
    float body_pitch_rate;

    /*Body yaw rate [rad/s]*/
    UPROPERTY()
    float body_yaw_rate;

    /*Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust) */
    UPROPERTY()
    float thrust;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
