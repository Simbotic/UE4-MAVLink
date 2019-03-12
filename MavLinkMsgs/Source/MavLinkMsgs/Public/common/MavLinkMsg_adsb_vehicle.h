 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_adsb_vehicle.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_adsb_vehicle
{
    GENERATED_BODY()

    static const uint32 MsgId = 246;
    /*ICAO address */
    UPROPERTY()
    uint32 ICAO_address;

    /*Latitude [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude [degE7]*/
    UPROPERTY()
    int32 lon;

    /*ADSB altitude type. */
    UPROPERTY()
    uint8 altitude_type;

    /*Altitude(ASL) [mm]*/
    UPROPERTY()
    int32 altitude;

    /*Course over ground [cdeg]*/
    UPROPERTY()
    uint16 heading;

    /*The horizontal velocity [cm/s]*/
    UPROPERTY()
    uint16 hor_velocity;

    /*The vertical velocity. Positive is up [cm/s]*/
    UPROPERTY()
    int16 ver_velocity;

    /*The callsign, 8+null */
    UPROPERTY()
    uint8 callsign[9];

    /*ADSB emitter type. */
    UPROPERTY()
    uint8 emitter_type;

    /*Time since last communication in seconds [s]*/
    UPROPERTY()
    uint8 tslc;

    /*Bitmap to indicate various statuses including valid data fields */
    UPROPERTY()
    uint16 flags;

    /*Squawk code */
    UPROPERTY()
    uint16 squawk;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
