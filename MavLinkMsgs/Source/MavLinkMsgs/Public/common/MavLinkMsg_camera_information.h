 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_camera_information.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_camera_information
{
    GENERATED_BODY()

    static const uint32 MsgId = 259;
    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Name of the camera vendor */
    UPROPERTY()
    uint8 vendor_name[32];

    /*Name of the camera model */
    UPROPERTY()
    uint8 model_name[32];

    /*Version of the camera firmware (v << 24 & 0xff = Dev, v << 16 & 0xff = Patch, v << 8 & 0xff = Minor, v & 0xff = Major) */
    UPROPERTY()
    uint32 firmware_version;

    /*Focal length [mm]*/
    UPROPERTY()
    float focal_length;

    /*Image sensor size horizontal [mm]*/
    UPROPERTY()
    float sensor_size_h;

    /*Image sensor size vertical [mm]*/
    UPROPERTY()
    float sensor_size_v;

    /*Horizontal image resolution [pix]*/
    UPROPERTY()
    uint16 resolution_h;

    /*Vertical image resolution [pix]*/
    UPROPERTY()
    uint16 resolution_v;

    /*Reserved for a lens ID */
    UPROPERTY()
    uint8 lens_id;

    /*Bitmap of camera capability flags. */
    UPROPERTY()
    uint32 flags;

    /*Camera definition version (iteration) */
    UPROPERTY()
    uint16 cam_definition_version;

    /*Camera definition URI (if any, otherwise only basic functions will be available). */
    UPROPERTY()
    uint8 cam_definition_uri[140];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
