 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_vfr_hud.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_vfr_hud
{
    GENERATED_BODY()

    static const uint32 MsgId = 74;
    /*Current indicated airspeed (IAS). [m/s]*/
    UPROPERTY()
    float airspeed;

    /*Current ground speed. [m/s]*/
    UPROPERTY()
    float groundspeed;

    /*Current heading in compass units (0-360, 0=north). [deg]*/
    UPROPERTY()
    int16 heading;

    /*Current throttle setting (0 to 100). [%]*/
    UPROPERTY()
    uint16 throttle;

    /*Current altitude (MSL). [m]*/
    UPROPERTY()
    float alt;

    /*Current climb rate. [m/s]*/
    UPROPERTY()
    float climb;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
