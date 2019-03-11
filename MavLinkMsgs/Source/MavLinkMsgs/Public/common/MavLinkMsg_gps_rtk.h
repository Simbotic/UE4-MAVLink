 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_rtk.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_rtk
{
    GENERATED_BODY()

    /*Time since boot of last baseline message received. [ms]*/
    UPROPERTY()
    uint32 time_last_baseline_ms;

    /*Identification of connected RTK receiver. */
    UPROPERTY()
    uint8 rtk_receiver_id;

    /*GPS Week Number of last baseline */
    UPROPERTY()
    uint16 wn;

    /*GPS Time of Week of last baseline [ms]*/
    UPROPERTY()
    uint32 tow;

    /*GPS-specific health report for RTK data. */
    UPROPERTY()
    uint8 rtk_health;

    /*Rate of baseline messages being received by GPS [Hz]*/
    UPROPERTY()
    uint8 rtk_rate;

    /*Current number of sats used for RTK calculation. */
    UPROPERTY()
    uint8 nsats;

    /*Coordinate system of baseline */
    UPROPERTY()
    uint8 baseline_coords_type;

    /*Current baseline in ECEF x or NED north component. [mm]*/
    UPROPERTY()
    int32 baseline_a_mm;

    /*Current baseline in ECEF y or NED east component. [mm]*/
    UPROPERTY()
    int32 baseline_b_mm;

    /*Current baseline in ECEF z or NED down component. [mm]*/
    UPROPERTY()
    int32 baseline_c_mm;

    /*Current estimate of baseline accuracy. */
    UPROPERTY()
    uint32 accuracy;

    /*Current number of integer ambiguity hypotheses. */
    UPROPERTY()
    int32 iar_num_hypotheses;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
