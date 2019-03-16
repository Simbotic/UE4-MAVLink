 
#include "MavLinkMsg_wifi_config_ap.h"
#include "common/mavlink.h"



void FMavlinkMsg_wifi_config_ap::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_wifi_config_ap_pack(systemId, componentId, &msg,  (char*)ssid, (char*)password);
}

void FMavlinkMsg_wifi_config_ap::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_wifi_config_ap::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        ssid = mavlink_msg_wifi_config_ap_get_ssid(msg, wifi_config_ap->ssid);
        password = mavlink_msg_wifi_config_ap_get_password(msg, wifi_config_ap->password);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN? msg.len : MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

