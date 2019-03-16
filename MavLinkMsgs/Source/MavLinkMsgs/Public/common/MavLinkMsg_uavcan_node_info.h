 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_uavcan_node_info.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_uavcan_node_info
{
    GENERATED_BODY()
    
    static const uint32 MsgId = 311;
    /*Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us]*/
    UPROPERTY()
    uint64 time_usec;

    /*Time since the start-up of the node. [s]*/
    UPROPERTY()
    uint32 uptime_sec;

    /*Node name string. For example, "sapog.px4.io". */
    UPROPERTY()
    uint8 name[80];

    /*Hardware major version number. */
    UPROPERTY()
    uint8 hw_version_major;

    /*Hardware minor version number. */
    UPROPERTY()
    uint8 hw_version_minor;

    /*Hardware unique 128-bit ID. */
    UPROPERTY()
    uint8 hw_unique_id[16];

    /*Software major version number. */
    UPROPERTY()
    uint8 sw_version_major;

    /*Software minor version number. */
    UPROPERTY()
    uint8 sw_version_minor;

    /*Version control system (VCS) revision identifier (e.g. git short commit hash). Zero if unknown. */
    UPROPERTY()
    uint32 sw_vcs_commit;

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
