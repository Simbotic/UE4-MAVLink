 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_smart_battery_info.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_smart_battery_info
{
    GENERATED_BODY()

    static const uint32 MsgId = 370;
    /*Battery ID */
    UPROPERTY()
    uint8 id;

    /*Capacity when full according to manufacturer, -1: field not provided. [mAh]*/
    UPROPERTY()
    int32 capacity_full_specification;

    /*Capacity when full (accounting for battery degradation), -1: field not provided. [mAh]*/
    UPROPERTY()
    int32 capacity_full;

    /*Charge/discharge cycle count. -1: field not provided. */
    UPROPERTY()
    uint16 cycle_count;

    /*Serial number. -1: field not provided. */
    UPROPERTY()
    int32 serial_number;

    /*Static device name. Encode as manufacturer and product names separated using an underscore. */
    UPROPERTY()
    uint8 device_name[50];

    /*Battery weight. 0: field not provided. [g]*/
    UPROPERTY()
    uint16 weight;

    /*Minimum per-cell voltage when discharging. If not supplied set to UINT16_MAX value. [mV]*/
    UPROPERTY()
    uint16 discharge_minimum_voltage;

    /*Minimum per-cell voltage when charging. If not supplied set to UINT16_MAX value. [mV]*/
    UPROPERTY()
    uint16 charging_minimum_voltage;

    /*Minimum per-cell voltage when resting. If not supplied set to UINT16_MAX value. [mV]*/
    UPROPERTY()
    uint16 resting_minimum_voltage;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
