 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_vibration.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_vibration
{
    GENERATED_BODY()

    static const uint32 MsgId = 241;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Vibration levels on X-axis */
    UPROPERTY()
    float vibration_x;

    /*Vibration levels on Y-axis */
    UPROPERTY()
    float vibration_y;

    /*Vibration levels on Z-axis */
    UPROPERTY()
    float vibration_z;

    /*first accelerometer clipping count */
    UPROPERTY()
    uint32 clipping_0;

    /*second accelerometer clipping count */
    UPROPERTY()
    uint32 clipping_1;

    /*third accelerometer clipping count */
    UPROPERTY()
    uint32 clipping_2;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
