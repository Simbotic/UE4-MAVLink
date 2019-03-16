 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_estimator_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_estimator_status
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 230;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Bitmap indicating which EKF outputs are valid. */
    UPROPERTY()
    uint16 flags;

    /*Velocity innovation test ratio */
    UPROPERTY()
    float vel_ratio;

    /*Horizontal position innovation test ratio */
    UPROPERTY()
    float pos_horiz_ratio;

    /*Vertical position innovation test ratio */
    UPROPERTY()
    float pos_vert_ratio;

    /*Magnetometer innovation test ratio */
    UPROPERTY()
    float mag_ratio;

    /*Height above terrain innovation test ratio */
    UPROPERTY()
    float hagl_ratio;

    /*True airspeed innovation test ratio */
    UPROPERTY()
    float tas_ratio;

    /*Horizontal position 1-STD accuracy relative to the EKF local origin [m]*/
    UPROPERTY()
    float pos_horiz_accuracy;

    /*Vertical position 1-STD accuracy relative to the EKF local origin [m]*/
    UPROPERTY()
    float pos_vert_accuracy;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
