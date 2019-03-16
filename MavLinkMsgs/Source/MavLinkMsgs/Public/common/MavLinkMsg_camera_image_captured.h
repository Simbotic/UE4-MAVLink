 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_camera_image_captured.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_camera_image_captured
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 263;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Timestamp (time since UNIX epoch) in UTC. 0 for unknown. [us]*/
    UPROPERTY()
    uint64 time_utc;

    /*Camera ID (1 for first, 2 for second, etc.) */
    UPROPERTY()
    uint8 camera_id;

    /*Latitude where image was taken [degE7]*/
    UPROPERTY()
    int32 lat;

    /*Longitude where capture was taken [degE7]*/
    UPROPERTY()
    int32 lon;

    /*Altitude (MSL) where image was taken [mm]*/
    UPROPERTY()
    int32 alt;

    /*Altitude above ground [mm]*/
    UPROPERTY()
    int32 relative_alt;

    /*Quaternion of camera orientation (w, x, y, z order, zero-rotation is 0, 0, 0, 0) */
    UPROPERTY()
    float q[4];

    /*Zero based index of this image (image count since armed -1) */
    UPROPERTY()
    int32 image_index;

    /*Boolean indicating success (1) or failure (0) while capturing this image. */
    UPROPERTY()
    int8 capture_result;

    /*URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface. */
    UPROPERTY()
    uint8 file_url[205];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
