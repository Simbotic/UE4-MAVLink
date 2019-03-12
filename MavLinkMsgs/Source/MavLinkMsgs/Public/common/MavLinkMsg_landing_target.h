 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_landing_target.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_landing_target
{
    GENERATED_BODY()

    static const uint32 MsgId = 149;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*The ID of the target if multiple targets are present */
    UPROPERTY()
    uint8 target_num;

    /*Coordinate frame used for following fields. */
    UPROPERTY()
    uint8 frame;

    /*X-axis angular offset of the target from the center of the image [rad]*/
    UPROPERTY()
    float angle_x;

    /*Y-axis angular offset of the target from the center of the image [rad]*/
    UPROPERTY()
    float angle_y;

    /*Distance to the target from the vehicle [m]*/
    UPROPERTY()
    float distance;

    /*Size of target along x-axis [rad]*/
    UPROPERTY()
    float size_x;

    /*Size of target along y-axis [rad]*/
    UPROPERTY()
    float size_y;

    /*X Position of the landing target in MAV_FRAME [m]*/
    UPROPERTY()
    float x;

    /*Y Position of the landing target in MAV_FRAME [m]*/
    UPROPERTY()
    float y;

    /*Z Position of the landing target in MAV_FRAME [m]*/
    UPROPERTY()
    float z;

    /*Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    UPROPERTY()
    float q[4];

    /*Type of landing target */
    UPROPERTY()
    uint8 type;

    /*Boolean indicating whether the position fields (x, y, z, q, type) contain valid target position information (valid: 1, invalid: 0). Default is 0 (invalid). */
    UPROPERTY()
    uint8 position_valid;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
