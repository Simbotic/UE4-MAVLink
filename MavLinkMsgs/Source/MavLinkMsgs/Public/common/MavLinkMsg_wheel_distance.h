 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_wheel_distance.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_wheel_distance
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 9000;
    /*Timestamp (synced to UNIX time or since system boot). [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Number of wheels reported. */
    UPROPERTY()
    uint8 count;

    /*Distance reported by individual wheel encoders. Forward rotations increase values, reverse rotations decrease them. Not all wheels will necessarily have wheel encoders; the mapping of encoders to wheel positions must be agreed/understood by the endpoints. [m]*/
    UPROPERTY()
    double distance[16];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
