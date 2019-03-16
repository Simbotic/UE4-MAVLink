 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_raw_imu.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_raw_imu
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 27;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*X acceleration (raw) */
    UPROPERTY()
    int16 xacc;

    /*Y acceleration (raw) */
    UPROPERTY()
    int16 yacc;

    /*Z acceleration (raw) */
    UPROPERTY()
    int16 zacc;

    /*Angular speed around X axis (raw) */
    UPROPERTY()
    int16 xgyro;

    /*Angular speed around Y axis (raw) */
    UPROPERTY()
    int16 ygyro;

    /*Angular speed around Z axis (raw) */
    UPROPERTY()
    int16 zgyro;

    /*X Magnetic field (raw) */
    UPROPERTY()
    int16 xmag;

    /*Y Magnetic field (raw) */
    UPROPERTY()
    int16 ymag;

    /*Z Magnetic field (raw) */
    UPROPERTY()
    int16 zmag;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
