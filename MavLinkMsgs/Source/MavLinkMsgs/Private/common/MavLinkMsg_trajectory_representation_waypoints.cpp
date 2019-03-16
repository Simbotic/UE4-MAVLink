 
#include "MavLinkMsg_trajectory_representation_waypoints.h"
#include "common/mavlink.h"



void FMavlinkMsg_trajectory_representation_waypoints::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_trajectory_representation_waypoints_pack(systemId, componentId, &msg,  time_usec, valid_points, pos_x, pos_y, pos_z, vel_x, vel_y, vel_z, acc_x, acc_y, acc_z, pos_yaw, vel_yaw);
}

void FMavlinkMsg_trajectory_representation_waypoints::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_trajectory_representation_waypoints::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_trajectory_representation_waypoints_get_time_usec(msg);
        pos_x = mavlink_msg_trajectory_representation_waypoints_get_pos_x(msg, trajectory_representation_waypoints->pos_x);
        pos_y = mavlink_msg_trajectory_representation_waypoints_get_pos_y(msg, trajectory_representation_waypoints->pos_y);
        pos_z = mavlink_msg_trajectory_representation_waypoints_get_pos_z(msg, trajectory_representation_waypoints->pos_z);
        vel_x = mavlink_msg_trajectory_representation_waypoints_get_vel_x(msg, trajectory_representation_waypoints->vel_x);
        vel_y = mavlink_msg_trajectory_representation_waypoints_get_vel_y(msg, trajectory_representation_waypoints->vel_y);
        vel_z = mavlink_msg_trajectory_representation_waypoints_get_vel_z(msg, trajectory_representation_waypoints->vel_z);
        acc_x = mavlink_msg_trajectory_representation_waypoints_get_acc_x(msg, trajectory_representation_waypoints->acc_x);
        acc_y = mavlink_msg_trajectory_representation_waypoints_get_acc_y(msg, trajectory_representation_waypoints->acc_y);
        acc_z = mavlink_msg_trajectory_representation_waypoints_get_acc_z(msg, trajectory_representation_waypoints->acc_z);
        pos_yaw = mavlink_msg_trajectory_representation_waypoints_get_pos_yaw(msg, trajectory_representation_waypoints->pos_yaw);
        vel_yaw = mavlink_msg_trajectory_representation_waypoints_get_vel_yaw(msg, trajectory_representation_waypoints->vel_yaw);
        valid_points = mavlink_msg_trajectory_representation_waypoints_get_valid_points(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_WAYPOINTS_LEN? msg.len : MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_WAYPOINTS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_WAYPOINTS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

