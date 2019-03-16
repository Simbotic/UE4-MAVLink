 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_cellular_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_cellular_status
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 334;
    /*Status bitmap */
    UPROPERTY()
    uint16 status;

    /*Cellular network radio type: gsm, cdma, lte... */
    UPROPERTY()
    uint8 type;

    /*Cellular network RSSI/RSRP in dBm, absolute value */
    UPROPERTY()
    uint8 quality;

    /*Mobile country code. If unknown, set to: UINT16_MAX */
    UPROPERTY()
    uint16 mcc;

    /*Mobile network code. If unknown, set to: UINT16_MAX */
    UPROPERTY()
    uint16 mnc;

    /*Location area code. If unknown, set to: 0 */
    UPROPERTY()
    uint16 lac;

    /*Cell ID. If unknown, set to: UINT32_MAX */
    UPROPERTY()
    uint32 cid;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
