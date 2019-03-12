 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_optical_flow.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_optical_flow
{
    GENERATED_BODY()

    static const uint32 MsgId = 114;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Sensor ID */
    UPROPERTY()
    uint8 sensor_id;

    /*Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the. [us]*/
    UPROPERTY()
    uint32 integration_time_us;

    /*Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.) [rad]*/
    UPROPERTY()
    float integrated_x;

    /*Flow in radians around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.) [rad]*/
    UPROPERTY()
    float integrated_y;

    /*RH rotation around X axis [rad]*/
    UPROPERTY()
    float integrated_xgyro;

    /*RH rotation around Y axis [rad]*/
    UPROPERTY()
    float integrated_ygyro;

    /*RH rotation around Z axis [rad]*/
    UPROPERTY()
    float integrated_zgyro;

    /*Temperature [cdegC]*/
    UPROPERTY()
    int16 temperature;

    /*Optical flow quality / confidence. 0: no valid flow, 255: maximum quality */
    UPROPERTY()
    uint8 quality;

    /*Time since the distance was sampled. [us]*/
    UPROPERTY()
    uint32 time_delta_distance_us;

    /*Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance. [m]*/
    UPROPERTY()
    float distance;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
