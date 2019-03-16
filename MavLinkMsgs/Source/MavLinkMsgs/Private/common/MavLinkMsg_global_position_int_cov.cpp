 
#include "MavLinkMsg_global_position_int_cov.h"
#include "common/mavlink.h"



void FMavlinkMsg_global_position_int_cov::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_global_position_int_cov_pack(systemId, componentId, &msg,  time_usec, estimator_type, lat, lon, alt, relative_alt, vx, vy, vz, covariance);
}

void FMavlinkMsg_global_position_int_cov::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_global_position_int_cov::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_global_position_int_cov_get_time_usec(msg);
        lat = mavlink_msg_global_position_int_cov_get_lat(msg);
        lon = mavlink_msg_global_position_int_cov_get_lon(msg);
        alt = mavlink_msg_global_position_int_cov_get_alt(msg);
        relative_alt = mavlink_msg_global_position_int_cov_get_relative_alt(msg);
        vx = mavlink_msg_global_position_int_cov_get_vx(msg);
        vy = mavlink_msg_global_position_int_cov_get_vy(msg);
        vz = mavlink_msg_global_position_int_cov_get_vz(msg);
        covariance = mavlink_msg_global_position_int_cov_get_covariance(msg, global_position_int_cov->covariance);
        estimator_type = mavlink_msg_global_position_int_cov_get_estimator_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV_LEN? msg.len : MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

