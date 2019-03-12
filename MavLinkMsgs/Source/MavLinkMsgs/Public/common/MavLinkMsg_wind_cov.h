 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_wind_cov.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_wind_cov
{
    GENERATED_BODY()

    static const uint32 MsgId = 231;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Wind in X (NED) direction [m/s]*/
    UPROPERTY()
    float wind_x;

    /*Wind in Y (NED) direction [m/s]*/
    UPROPERTY()
    float wind_y;

    /*Wind in Z (NED) direction [m/s]*/
    UPROPERTY()
    float wind_z;

    /*Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate. [m/s]*/
    UPROPERTY()
    float var_horiz;

    /*Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate. [m/s]*/
    UPROPERTY()
    float var_vert;

    /*Altitude (MSL) that this measurement was taken at [m]*/
    UPROPERTY()
    float wind_alt;

    /*Horizontal speed 1-STD accuracy [m]*/
    UPROPERTY()
    float horiz_accuracy;

    /*Vertical speed 1-STD accuracy [m]*/
    UPROPERTY()
    float vert_accuracy;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
