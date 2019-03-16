 
#include "MavLinkMsg_vision_speed_estimate.h"
#include "common/mavlink.h"



void FMavlinkMsg_vision_speed_estimate::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_vision_speed_estimate_pack(systemId, componentId, &msg,  usec, x, y, z, covariance);
}

void FMavlinkMsg_vision_speed_estimate::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_vision_speed_estimate::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        usec = mavlink_msg_vision_speed_estimate_get_usec(msg);
        x = mavlink_msg_vision_speed_estimate_get_x(msg);
        y = mavlink_msg_vision_speed_estimate_get_y(msg);
        z = mavlink_msg_vision_speed_estimate_get_z(msg);
        covariance = mavlink_msg_vision_speed_estimate_get_covariance(msg, vision_speed_estimate->covariance);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN? msg.len : MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

