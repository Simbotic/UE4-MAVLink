 
#include "MavLinkMsg_landing_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_landing_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_landing_target_pack(systemId, componentId, &msg,  time_usec, target_num, frame, angle_x, angle_y, distance, size_x, size_y, x, y, z, q, type, position_valid);
}

void FMavlinkMsg_landing_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_landing_target::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_landing_target_get_time_usec(msg);
        angle_x = mavlink_msg_landing_target_get_angle_x(msg);
        angle_y = mavlink_msg_landing_target_get_angle_y(msg);
        distance = mavlink_msg_landing_target_get_distance(msg);
        size_x = mavlink_msg_landing_target_get_size_x(msg);
        size_y = mavlink_msg_landing_target_get_size_y(msg);
        target_num = mavlink_msg_landing_target_get_target_num(msg);
        frame = mavlink_msg_landing_target_get_frame(msg);
        x = mavlink_msg_landing_target_get_x(msg);
        y = mavlink_msg_landing_target_get_y(msg);
        z = mavlink_msg_landing_target_get_z(msg);
        q = mavlink_msg_landing_target_get_q(msg, landing_target->q);
        type = mavlink_msg_landing_target_get_type(msg);
        position_valid = mavlink_msg_landing_target_get_position_valid(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LANDING_TARGET_LEN? msg.len : MAVLINK_MSG_ID_LANDING_TARGET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LANDING_TARGET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

