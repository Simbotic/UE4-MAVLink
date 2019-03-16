 
#include "MavLinkMsg_attitude_quaternion_cov.h"
#include "common/mavlink.h"



void FMavlinkMsg_attitude_quaternion_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_attitude_quaternion_cov_pack(systemId, componentId, &msg,  time_usec, q, rollspeed, pitchspeed, yawspeed, covariance);
}

void FMavlinkMsg_attitude_quaternion_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_attitude_quaternion_cov::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_attitude_quaternion_cov_get_time_usec(msg);
        q = mavlink_msg_attitude_quaternion_cov_get_q(msg, attitude_quaternion_cov->q);
        rollspeed = mavlink_msg_attitude_quaternion_cov_get_rollspeed(msg);
        pitchspeed = mavlink_msg_attitude_quaternion_cov_get_pitchspeed(msg);
        yawspeed = mavlink_msg_attitude_quaternion_cov_get_yawspeed(msg);
        covariance = mavlink_msg_attitude_quaternion_cov_get_covariance(msg, attitude_quaternion_cov->covariance);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV_LEN? msg.len : MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

