 
#include "MavLinkMsg_manual_control.h"
#include "common/mavlink.h"



void FMavlinkMsg_manual_control::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_manual_control_pack(systemId, componentId, &msg,  target, x, y, z, r, buttons);
}

void FMavlinkMsg_manual_control::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_manual_control::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        x = mavlink_msg_manual_control_get_x(msg);
        y = mavlink_msg_manual_control_get_y(msg);
        z = mavlink_msg_manual_control_get_z(msg);
        r = mavlink_msg_manual_control_get_r(msg);
        buttons = mavlink_msg_manual_control_get_buttons(msg);
        target = mavlink_msg_manual_control_get_target(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MANUAL_CONTROL_LEN? msg.len : MAVLINK_MSG_ID_MANUAL_CONTROL_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

