 
#include "MavLinkMsg_trajectory_representation_bezier.h"
#include "common/mavlink.h"



void FMavlinkMsg_trajectory_representation_bezier::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_trajectory_representation_bezier_pack(systemId, componentId, &msg,  time_usec, valid_points, pos_x, pos_y, pos_z, delta, pos_yaw);
}

void FMavlinkMsg_trajectory_representation_bezier::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_trajectory_representation_bezier::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_trajectory_representation_bezier_get_time_usec(msg);
        pos_x = mavlink_msg_trajectory_representation_bezier_get_pos_x(msg, trajectory_representation_bezier->pos_x);
        pos_y = mavlink_msg_trajectory_representation_bezier_get_pos_y(msg, trajectory_representation_bezier->pos_y);
        pos_z = mavlink_msg_trajectory_representation_bezier_get_pos_z(msg, trajectory_representation_bezier->pos_z);
        delta = mavlink_msg_trajectory_representation_bezier_get_delta(msg, trajectory_representation_bezier->delta);
        pos_yaw = mavlink_msg_trajectory_representation_bezier_get_pos_yaw(msg, trajectory_representation_bezier->pos_yaw);
        valid_points = mavlink_msg_trajectory_representation_bezier_get_valid_points(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN? msg.len : MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

