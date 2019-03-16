 
#include "MavLinkMsg_set_mode.h"
#include "common/mavlink.h"



void FMavlinkMsg_set_mode::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_mode_pack(systemId, componentId, &msg,  target_system, base_mode, custom_mode);
}

void FMavlinkMsg_set_mode::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_mode::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        custom_mode = mavlink_msg_set_mode_get_custom_mode(msg);
        target_system = mavlink_msg_set_mode_get_target_system(msg);
        base_mode = mavlink_msg_set_mode_get_base_mode(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SET_MODE_LEN? msg.len : MAVLINK_MSG_ID_SET_MODE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SET_MODE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

