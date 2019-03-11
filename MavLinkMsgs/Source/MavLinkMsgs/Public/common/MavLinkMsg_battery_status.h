 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_battery_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_battery_status
{
    GENERATED_BODY()

    /*Battery ID */
    UPROPERTY()
    uint8 id;

    /*Function of the battery */
    UPROPERTY()
    uint8 battery_function;

    /*Type (chemistry) of the battery */
    UPROPERTY()
    uint8 type;

    /*Temperature of the battery. INT16_MAX for unknown temperature. [cdegC]*/
    UPROPERTY()
    int16 temperature;

    /*Battery voltage of cells. Cells above the valid cell count for this battery should have the UINT16_MAX value. [mV]*/
    UPROPERTY()
    uint16 voltages[10];

    /*Battery current, -1: autopilot does not measure the current [cA]*/
    UPROPERTY()
    int16 current_battery;

    /*Consumed charge, -1: autopilot does not provide consumption estimate [mAh]*/
    UPROPERTY()
    int32 current_consumed;

    /*Consumed energy, -1: autopilot does not provide energy consumption estimate [hJ]*/
    UPROPERTY()
    int32 energy_consumed;

    /*Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery. [%]*/
    UPROPERTY()
    int8 battery_remaining;

    /*Remaining battery time, 0: autopilot does not provide remaining battery time estimate [s]*/
    UPROPERTY()
    int32 time_remaining;

    /*State for extent of discharge, provided by autopilot for warning or external reactions */
    UPROPERTY()
    uint8 charge_state;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
