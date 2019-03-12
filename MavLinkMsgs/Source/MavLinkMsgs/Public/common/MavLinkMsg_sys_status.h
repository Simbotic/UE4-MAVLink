 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_sys_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_sys_status
{
    GENERATED_BODY()

    static const uint32 MsgId = 1;
    /*Bitmap showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. */
    UPROPERTY()
    uint32 onboard_control_sensors_present;

    /*Bitmap showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. */
    UPROPERTY()
    uint32 onboard_control_sensors_enabled;

    /*Bitmap showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. */
    UPROPERTY()
    uint32 onboard_control_sensors_health;

    /*Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000 [d%]*/
    UPROPERTY()
    uint16 load;

    /*Battery voltage [mV]*/
    UPROPERTY()
    uint16 voltage_battery;

    /*Battery current, -1: autopilot does not measure the current [cA]*/
    UPROPERTY()
    int16 current_battery;

    /*Remaining battery energy, -1: autopilot estimate the remaining battery [%]*/
    UPROPERTY()
    int8 battery_remaining;

    /*Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) [c%]*/
    UPROPERTY()
    uint16 drop_rate_comm;

    /*Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) */
    UPROPERTY()
    uint16 errors_comm;

    /*Autopilot-specific errors */
    UPROPERTY()
    uint16 errors_count1;

    /*Autopilot-specific errors */
    UPROPERTY()
    uint16 errors_count2;

    /*Autopilot-specific errors */
    UPROPERTY()
    uint16 errors_count3;

    /*Autopilot-specific errors */
    UPROPERTY()
    uint16 errors_count4;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
