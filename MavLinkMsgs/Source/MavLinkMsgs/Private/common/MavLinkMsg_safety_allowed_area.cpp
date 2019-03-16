 
#include "MavLinkMsg_safety_allowed_area.h"
#include "common/mavlink.h"



void FMavlinkMsg_safety_allowed_area::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_safety_allowed_area_pack(systemId, componentId, &msg,  frame, p1x, p1y, p1z, p2x, p2y, p2z);
}

void FMavlinkMsg_safety_allowed_area::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_safety_allowed_area::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        p1x = mavlink_msg_safety_allowed_area_get_p1x(msg);
        p1y = mavlink_msg_safety_allowed_area_get_p1y(msg);
        p1z = mavlink_msg_safety_allowed_area_get_p1z(msg);
        p2x = mavlink_msg_safety_allowed_area_get_p2x(msg);
        p2y = mavlink_msg_safety_allowed_area_get_p2y(msg);
        p2z = mavlink_msg_safety_allowed_area_get_p2z(msg);
        frame = mavlink_msg_safety_allowed_area_get_frame(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_LEN? msg.len : MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

