 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_video_stream_information.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_video_stream_information
{
    GENERATED_BODY()

    static const uint32 MsgId = 269;
    /*Video Stream ID (1 for first, 2 for second, etc.) */
    UPROPERTY()
    uint8 stream_id;

    /*Number of streams available. */
    UPROPERTY()
    uint8 count;

    /*Type of stream. */
    UPROPERTY()
    uint8 type;

    /*Bitmap of stream status flags. */
    UPROPERTY()
    uint16 flags;

    /*Frame rate. [Hz]*/
    UPROPERTY()
    float framerate;

    /*Horizontal resolution. [pix]*/
    UPROPERTY()
    uint16 resolution_h;

    /*Vertical resolution. [pix]*/
    UPROPERTY()
    uint16 resolution_v;

    /*Bit rate. [bits/s]*/
    UPROPERTY()
    uint32 bitrate;

    /*Video image rotation clockwise. [deg]*/
    UPROPERTY()
    uint16 rotation;

    /*Horizontal Field of view. [deg]*/
    UPROPERTY()
    uint16 hfov;

    /*Stream name. */
    UPROPERTY()
    uint8 name[32];

    /*Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to). */
    UPROPERTY()
    uint8 uri[160];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
