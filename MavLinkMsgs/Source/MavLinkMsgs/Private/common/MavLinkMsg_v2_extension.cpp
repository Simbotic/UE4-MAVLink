 
#include "MavLinkMsg_v2_extension.h"
#include "common/mavlink.h"



void FMavlinkMsg_v2_extension::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_v2_extension_pack(systemId, componentId, &msg,  target_network, target_system, target_component, message_type, (uint8_t*)payload);
}

void FMavlinkMsg_v2_extension::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_v2_extension::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        message_type = mavlink_msg_v2_extension_get_message_type(msg);
        target_network = mavlink_msg_v2_extension_get_target_network(msg);
        target_system = mavlink_msg_v2_extension_get_target_system(msg);
        target_component = mavlink_msg_v2_extension_get_target_component(msg);
        payload = mavlink_msg_v2_extension_get_payload(msg, v2_extension->payload);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_V2_EXTENSION_LEN? msg.len : MAVLINK_MSG_ID_V2_EXTENSION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_V2_EXTENSION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

