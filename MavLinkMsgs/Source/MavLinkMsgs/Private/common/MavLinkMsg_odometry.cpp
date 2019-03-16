 
#include "MavLinkMsg_odometry.h"
#include "common/mavlink.h"



void FMavlinkMsg_odometry::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_odometry_pack(systemId, componentId, &msg,  time_usec, frame_id, child_frame_id, x, y, z, q, vx, vy, vz, rollspeed, pitchspeed, yawspeed, pose_covariance, velocity_covariance);
}

void FMavlinkMsg_odometry::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_odometry::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_odometry_get_time_usec(msg);
        x = mavlink_msg_odometry_get_x(msg);
        y = mavlink_msg_odometry_get_y(msg);
        z = mavlink_msg_odometry_get_z(msg);
        q = mavlink_msg_odometry_get_q(msg, odometry->q);
        vx = mavlink_msg_odometry_get_vx(msg);
        vy = mavlink_msg_odometry_get_vy(msg);
        vz = mavlink_msg_odometry_get_vz(msg);
        rollspeed = mavlink_msg_odometry_get_rollspeed(msg);
        pitchspeed = mavlink_msg_odometry_get_pitchspeed(msg);
        yawspeed = mavlink_msg_odometry_get_yawspeed(msg);
        pose_covariance = mavlink_msg_odometry_get_pose_covariance(msg, odometry->pose_covariance);
        velocity_covariance = mavlink_msg_odometry_get_velocity_covariance(msg, odometry->velocity_covariance);
        frame_id = mavlink_msg_odometry_get_frame_id(msg);
        child_frame_id = mavlink_msg_odometry_get_child_frame_id(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ODOMETRY_LEN? msg.len : MAVLINK_MSG_ID_ODOMETRY_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ODOMETRY_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

