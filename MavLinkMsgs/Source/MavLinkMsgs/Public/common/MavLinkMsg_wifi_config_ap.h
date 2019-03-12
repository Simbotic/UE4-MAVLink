 
#pragma once

#include "CoreMinimal.h"
#include "MavLinkMsg_wifi_config_ap.generated.h"

struct __mavlink_message;

USTRUCT(BlueprintType)
struct MAVLINKMSGS_API FMavlinkMsg_wifi_config_ap
{
    GENERATED_BODY()

    static const uint32 MsgId = 299;
    /*Name of Wi-Fi network (SSID). Leave it blank to leave it unchanged. */
    UPROPERTY()
    uint8 ssid[32];

    /*Password. Leave it blank for an open AP. */
    UPROPERTY()
    uint8 password[64];

    

    void Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize);
    void Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer);
    void Deserialize(const __mavlink_message& msg);
    
};
