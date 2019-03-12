 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_distance_sensor.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_distance_sensor
{
    GENERATED_BODY()

    static const uint32 MsgId = 132;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Minimum distance the sensor can measure [cm]*/
    UPROPERTY()
    uint16 min_distance;

    /*Maximum distance the sensor can measure [cm]*/
    UPROPERTY()
    uint16 max_distance;

    /*Current distance reading [cm]*/
    UPROPERTY()
    uint16 current_distance;

    /*Type of distance sensor. */
    UPROPERTY()
    uint8 type;

    /*Onboard ID of the sensor */
    UPROPERTY()
    uint8 id;

    /*Direction the sensor faces. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270 */
    UPROPERTY()
    uint8 orientation;

    /*Measurement variance. Max standard deviation is 6cm. 256 if unknown. [cm^2]*/
    UPROPERTY()
    uint8 covariance;

    /*Horizontal Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad]*/
    UPROPERTY()
    float horizontal_fov;

    /*Vertical Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad]*/
    UPROPERTY()
    float vertical_fov;

    /*Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if the orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid." */
    UPROPERTY()
    float quaternion[4];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
