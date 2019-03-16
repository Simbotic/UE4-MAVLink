 
#include "MavLinkMsg_local_position_ned_cov.h"
#include "common/mavlink.h"



void FMavlinkMsg_local_position_ned_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_local_position_ned_cov_pack(systemId, componentId, &msg,  time_usec, estimator_type, x, y, z, vx, vy, vz, ax, ay, az, covariance);
}

void FMavlinkMsg_local_position_ned_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_local_position_ned_cov::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_local_position_ned_cov_get_time_usec(msg);
        x = mavlink_msg_local_position_ned_cov_get_x(msg);
        y = mavlink_msg_local_position_ned_cov_get_y(msg);
        z = mavlink_msg_local_position_ned_cov_get_z(msg);
        vx = mavlink_msg_local_position_ned_cov_get_vx(msg);
        vy = mavlink_msg_local_position_ned_cov_get_vy(msg);
        vz = mavlink_msg_local_position_ned_cov_get_vz(msg);
        ax = mavlink_msg_local_position_ned_cov_get_ax(msg);
        ay = mavlink_msg_local_position_ned_cov_get_ay(msg);
        az = mavlink_msg_local_position_ned_cov_get_az(msg);
        covariance = mavlink_msg_local_position_ned_cov_get_covariance(msg, local_position_ned_cov->covariance);
        estimator_type = mavlink_msg_local_position_ned_cov_get_estimator_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV_LEN? msg.len : MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

