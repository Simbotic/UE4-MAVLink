 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_autopilot_version.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_autopilot_version
{
    GENERATED_BODY()

    static const uint32 MsgId = 148;
    /*Bitmap of capabilities */
    UPROPERTY()
    uint64 capabilities;

    /*Firmware version number */
    UPROPERTY()
    uint32 flight_sw_version;

    /*Middleware version number */
    UPROPERTY()
    uint32 middleware_sw_version;

    /*Operating system version number */
    UPROPERTY()
    uint32 os_sw_version;

    /*HW / board version (last 8 bytes should be silicon ID, if any) */
    UPROPERTY()
    uint32 board_version;

    /*Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    UPROPERTY()
    uint8 flight_custom_version[8];

    /*Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    UPROPERTY()
    uint8 middleware_custom_version[8];

    /*Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    UPROPERTY()
    uint8 os_custom_version[8];

    /*ID of the board vendor */
    UPROPERTY()
    uint16 vendor_id;

    /*ID of the product */
    UPROPERTY()
    uint16 product_id;

    /*UID if provided by hardware (see uid2) */
    UPROPERTY()
    uint64 uid;

    /*UID if provided by hardware (supersedes the uid field. If this is non-zero, use this field, otherwise use uid) */
    UPROPERTY()
    uint8 uid2[18];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
