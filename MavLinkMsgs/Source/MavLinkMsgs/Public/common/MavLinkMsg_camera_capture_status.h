 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_camera_capture_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_camera_capture_status
{
    GENERATED_BODY()

    static const uint32 MsgId = 262;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress) */
    UPROPERTY()
    uint8 image_status;

    /*Current status of video capturing (0: idle, 1: capture in progress) */
    UPROPERTY()
    uint8 video_status;

    /*Image capture interval [s]*/
    UPROPERTY()
    float image_interval;

    /*Time since recording started [ms]*/
    UPROPERTY()
    uint32 recording_time_ms;

    /*Available storage capacity. [MiB]*/
    UPROPERTY()
    float available_capacity;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
