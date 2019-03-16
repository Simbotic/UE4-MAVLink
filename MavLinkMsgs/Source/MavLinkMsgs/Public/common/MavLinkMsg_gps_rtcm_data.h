 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_gps_rtcm_data.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_gps_rtcm_data
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 233;
    /*LSB: 1 means message is fragmented, next 2 bits are the fragment ID, the remaining 5 bits are used for the sequence ID. Messages are only to be flushed to the GPS when the entire message has been reconstructed on the autopilot. The fragment ID specifies which order the fragments should be assembled into a buffer, while the sequence ID is used to detect a mismatch between different buffers. The buffer is considered fully reconstructed when either all 4 fragments are present, or all the fragments before the first fragment with a non full payload is received. This management is used to ensure that normal GPS operation doesn't corrupt RTCM data, and to recover from a unreliable transport delivery order. */
    UPROPERTY()
    uint8 flags;

    /*data length [bytes]*/
    UPROPERTY()
    uint8 len;

    /*RTCM message (may be fragmented) */
    UPROPERTY()
    uint8 data[180];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
