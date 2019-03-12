 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_optical_flow.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_optical_flow
{
    GENERATED_BODY()

    static const uint32 MsgId = 100;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Sensor ID */
    UPROPERTY()
    uint8 sensor_id;

    /*Flow in x-sensor direction [dpix]*/
    UPROPERTY()
    int16 flow_x;

    /*Flow in y-sensor direction [dpix]*/
    UPROPERTY()
    int16 flow_y;

    /*Flow in x-sensor direction, angular-speed compensated [m]*/
    UPROPERTY()
    float flow_comp_m_x;

    /*Flow in y-sensor direction, angular-speed compensated [m]*/
    UPROPERTY()
    float flow_comp_m_y;

    /*Optical flow quality / confidence. 0: bad, 255: maximum quality */
    UPROPERTY()
    uint8 quality;

    /*Ground distance. Positive value: distance known. Negative value: Unknown distance [m]*/
    UPROPERTY()
    float ground_distance;

    /*Flow rate about X axis [rad/s]*/
    UPROPERTY()
    float flow_rate_x;

    /*Flow rate about Y axis [rad/s]*/
    UPROPERTY()
    float flow_rate_y;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
