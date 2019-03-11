 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_servo_output_raw.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_servo_output_raw
{
    GENERATED_BODY()

    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint32 time_usec;

    /*Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    UPROPERTY()
    uint8 port;

    /*Servo output 1 value [us]*/
    UPROPERTY()
    uint16 servo1_raw;

    /*Servo output 2 value [us]*/
    UPROPERTY()
    uint16 servo2_raw;

    /*Servo output 3 value [us]*/
    UPROPERTY()
    uint16 servo3_raw;

    /*Servo output 4 value [us]*/
    UPROPERTY()
    uint16 servo4_raw;

    /*Servo output 5 value [us]*/
    UPROPERTY()
    uint16 servo5_raw;

    /*Servo output 6 value [us]*/
    UPROPERTY()
    uint16 servo6_raw;

    /*Servo output 7 value [us]*/
    UPROPERTY()
    uint16 servo7_raw;

    /*Servo output 8 value [us]*/
    UPROPERTY()
    uint16 servo8_raw;

    /*Servo output 9 value [us]*/
    UPROPERTY()
    uint16 servo9_raw;

    /*Servo output 10 value [us]*/
    UPROPERTY()
    uint16 servo10_raw;

    /*Servo output 11 value [us]*/
    UPROPERTY()
    uint16 servo11_raw;

    /*Servo output 12 value [us]*/
    UPROPERTY()
    uint16 servo12_raw;

    /*Servo output 13 value [us]*/
    UPROPERTY()
    uint16 servo13_raw;

    /*Servo output 14 value [us]*/
    UPROPERTY()
    uint16 servo14_raw;

    /*Servo output 15 value [us]*/
    UPROPERTY()
    uint16 servo15_raw;

    /*Servo output 16 value [us]*/
    UPROPERTY()
    uint16 servo16_raw;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
