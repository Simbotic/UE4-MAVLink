 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_attitude.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_attitude
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 30;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Roll angle (-pi..+pi) [rad]*/
    UPROPERTY()
    float roll;

    /*Pitch angle (-pi..+pi) [rad]*/
    UPROPERTY()
    float pitch;

    /*Yaw angle (-pi..+pi) [rad]*/
    UPROPERTY()
    float yaw;

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
