 
#include "MavLinkMsg_set_attitude_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_set_attitude_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_attitude_target_pack(systemId, componentId, &msg,  time_boot_ms, target_system, target_component, type_mask, q, body_roll_rate, body_pitch_rate, body_yaw_rate, thrust);
}

void FMavlinkMsg_set_attitude_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_attitude_target::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_set_attitude_target_get_time_boot_ms(msg);
        q = mavlink_msg_set_attitude_target_get_q(msg, set_attitude_target->q);
        body_roll_rate = mavlink_msg_set_attitude_target_get_body_roll_rate(msg);
        body_pitch_rate = mavlink_msg_set_attitude_target_get_body_pitch_rate(msg);
        body_yaw_rate = mavlink_msg_set_attitude_target_get_body_yaw_rate(msg);
        thrust = mavlink_msg_set_attitude_target_get_thrust(msg);
        target_system = mavlink_msg_set_attitude_target_get_target_system(msg);
        target_component = mavlink_msg_set_attitude_target_get_target_component(msg);
        type_mask = mavlink_msg_set_attitude_target_get_type_mask(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN? msg.len : MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SET_ATTITUDE_TARGET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

