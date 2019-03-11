 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_camera_settings.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_camera_settings
{
    GENERATED_BODY()

    /*Timestamp (time since system boot). [ms]*/
    UPROPERTY()
    uint32 time_boot_ms;

    /*Camera mode */
    UPROPERTY()
    uint8 mode_id;

    /*Current zoom level (0.0 to 100.0, NaN if not known) */
    UPROPERTY()
    float zoomLevel;

    /*Current focus level (0.0 to 100.0, NaN if not known) */
    UPROPERTY()
    float focusLevel;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
