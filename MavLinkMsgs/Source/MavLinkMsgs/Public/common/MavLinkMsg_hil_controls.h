 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_hil_controls.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_hil_controls
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 91;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Control output -1 .. 1 */
    UPROPERTY()
    float roll_ailerons;

    /*Control output -1 .. 1 */
    UPROPERTY()
    float pitch_elevator;

    /*Control output -1 .. 1 */
    UPROPERTY()
    float yaw_rudder;

    /*Throttle 0 .. 1 */
    UPROPERTY()
    float throttle;

    /*Aux 1, -1 .. 1 */
    UPROPERTY()
    float aux1;

    /*Aux 2, -1 .. 1 */
    UPROPERTY()
    float aux2;

    /*Aux 3, -1 .. 1 */
    UPROPERTY()
    float aux3;

    /*Aux 4, -1 .. 1 */
    UPROPERTY()
    float aux4;

    /*System mode. */
    UPROPERTY()
    uint8 mode;

    /*Navigation mode (MAV_NAV_MODE) */
    UPROPERTY()
    uint8 nav_mode;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
