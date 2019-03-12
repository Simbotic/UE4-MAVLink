 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_memory_vect.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_memory_vect
{
    GENERATED_BODY()

    static const uint32 MsgId = 249;
    /*Starting address of the debug variables */
    UPROPERTY()
    uint16 address;

    /*Version code of the type variable. 0=unknown, type ignored and assumed int16_t. 1=as below */
    UPROPERTY()
    uint8 ver;

    /*Type code of the memory variables. for ver = 1: 0=16 x int16_t, 1=16 x uint16_t, 2=16 x Q15, 3=16 x 1Q14 */
    UPROPERTY()
    uint8 type;

    /*Memory contents at specified address */
    UPROPERTY()
    int8 value[32];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
