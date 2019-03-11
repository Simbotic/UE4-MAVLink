 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_smart_battery_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_smart_battery_status
{
    GENERATED_BODY()

    /*Battery ID */
    UPROPERTY()
    uint16 id;

    /*Remaining battery energy. Values: [0-100], -1: field not provided. [%]*/
    UPROPERTY()
    int16 capacity_remaining;

    /*Battery current (through all cells/loads). Positive if discharging, negative if charging. UINT16_MAX: field not provided. [cA]*/
    UPROPERTY()
    int16 current;

    /*Battery temperature. -1: field not provided. [cdegC]*/
    UPROPERTY()
    int16 temperature;

    /*Fault/health indications. */
    UPROPERTY()
    int32 fault_bitmask;

    /*Estimated remaining battery time. -1: field not provided. [s]*/
    UPROPERTY()
    int32 time_remaining;

    /*The cell number of the first index in the 'voltages' array field. Using this field allows you to specify cell voltages for batteries with more than 16 cells. */
    UPROPERTY()
    uint16 cell_offset;

    /*Individual cell voltages. Batteries with more 16 cells can use the cell_offset field to specify the cell offset for the array specified in the current message . Index values above the valid cell count for this battery should have the UINT16_MAX value. [mV]*/
    UPROPERTY()
    uint16 voltages[16];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
