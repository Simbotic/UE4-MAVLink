 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_video_stream_status.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_video_stream_status
{
    GENERATED_BODY()

    /*Video Stream ID (1 for first, 2 for second, etc.) */
    UPROPERTY()
    uint8 stream_id;

    /*Bitmap of stream status flags */
    UPROPERTY()
    uint16 flags;

    /*Frame rate [Hz]*/
    UPROPERTY()
    float framerate;

    /*Horizontal resolution [pix]*/
    UPROPERTY()
    uint16 resolution_h;

    /*Vertical resolution [pix]*/
    UPROPERTY()
    uint16 resolution_v;

    /*Bit rate [bits/s]*/
    UPROPERTY()
    uint32 bitrate;

    /*Video image rotation clockwise [deg]*/
    UPROPERTY()
    uint16 rotation;

    /*Horizontal Field of view [deg]*/
    UPROPERTY()
    uint16 hfov;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
