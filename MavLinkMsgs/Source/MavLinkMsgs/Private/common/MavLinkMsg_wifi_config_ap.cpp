 
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

}

