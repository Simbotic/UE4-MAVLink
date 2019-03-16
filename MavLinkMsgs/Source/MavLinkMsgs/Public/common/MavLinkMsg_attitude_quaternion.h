 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_attitude_quaternion.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_attitude_quaternion
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 31;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Quaternion component 1, w (1 in null-rotation) */
    UPROPERTY()
    float q1;

    /*Quaternion component 2, x (0 in null-rotation) */
    UPROPERTY()
    float q2;

    /*Quaternion component 3, y (0 in null-rotation) */
    UPROPERTY()
    float q3;

    /*Quaternion component 4, z (0 in null-rotation) */
    UPROPERTY()
    float q4;

    /*Roll angular speed [rad/s]*/
    UPROPERTY()
    float rollspeed;

    /*Pitch angular speed [rad/s]*/
    UPROPERTY()
    float pitchspeed;

    /*Yaw angular speed [rad/s]*/
    UPROPERTY()
    float yawspeed;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
