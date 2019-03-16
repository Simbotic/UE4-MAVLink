 
#include "MavLinkMsg_follow_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_follow_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_follow_target_pack(systemId, componentId, &msg,  timestamp, est_capabilities, lat, lon, alt, vel, acc, attitude_q, rates, position_cov, custom_state);
}

void FMavlinkMsg_follow_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_follow_target::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        timestamp = mavlink_msg_follow_target_get_timestamp(msg);
        custom_state = mavlink_msg_follow_target_get_custom_state(msg);
        lat = mavlink_msg_follow_target_get_lat(msg);
        lon = mavlink_msg_follow_target_get_lon(msg);
        alt = mavlink_msg_follow_target_get_alt(msg);
        vel = mavlink_msg_follow_target_get_vel(msg, follow_target->vel);
        acc = mavlink_msg_follow_target_get_acc(msg, follow_target->acc);
        attitude_q = mavlink_msg_follow_target_get_attitude_q(msg, follow_target->attitude_q);
        rates = mavlink_msg_follow_target_get_rates(msg, follow_target->rates);
        position_cov = mavlink_msg_follow_target_get_position_cov(msg, follow_target->position_cov);
        est_capabilities = mavlink_msg_follow_target_get_est_capabilities(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_FOLLOW_TARGET_LEN? msg.len : MAVLINK_MSG_ID_FOLLOW_TARGET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_FOLLOW_TARGET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

