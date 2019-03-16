 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_orbit_execution_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_orbit_execution_status
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 360;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise. [m]*/
    UPROPERTY()
    float radius;

    /*The coordinate system of the fields: x, y, z. */
    UPROPERTY()
    uint8 frame;

    /*X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7. */
    UPROPERTY()
    int32 x;

    /*Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7. */
    UPROPERTY()
    int32 y;

    /*Altitude of center point. Coordinate system depends on frame field. [m]*/
    UPROPERTY()
    float z;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
