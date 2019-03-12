 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_follow_target.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_follow_target
{
    GENERATED_BODY()

    static const uint32 MsgId = 144;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint64 timestamp;

    /*bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3) */
    UPROPERTY()
    uint8 est_capabilities;

    /*Latitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude (WGS84) [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL) [m]*/
    UPROPERTY()
    float alt;

    /*target velocity (0,0,0) for unknown [m/s]*/
    UPROPERTY()
    float vel[3];

    /*linear target acceleration (0,0,0) for unknown [m/s/s]*/
    UPROPERTY()
    float acc[3];

    /*(1 0 0 0 for unknown) */
    UPROPERTY()
    float attitude_q[4];

    /*(0 0 0 for unknown) */
    UPROPERTY()
    float rates[3];

    /*eph epv */
    UPROPERTY()
    float position_cov[3];

    /*button states or switches of a tracker device */
    UPROPERTY()
    uint64 custom_state;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
