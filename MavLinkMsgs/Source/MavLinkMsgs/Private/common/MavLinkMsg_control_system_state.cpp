 
#include "MavLinkMsg_control_system_state.h"
#include "common/mavlink.h"



void FMavlinkMsg_control_system_state::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_control_system_state_pack(systemId, componentId, &msg,  time_usec, x_acc, y_acc, z_acc, x_vel, y_vel, z_vel, x_pos, y_pos, z_pos, airspeed, vel_variance, pos_variance, q, roll_rate, pitch_rate, yaw_rate);
}

void FMavlinkMsg_control_system_state::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_control_system_state::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_control_system_state_get_time_usec(msg);
        x_acc = mavlink_msg_control_system_state_get_x_acc(msg);
        y_acc = mavlink_msg_control_system_state_get_y_acc(msg);
        z_acc = mavlink_msg_control_system_state_get_z_acc(msg);
        x_vel = mavlink_msg_control_system_state_get_x_vel(msg);
        y_vel = mavlink_msg_control_system_state_get_y_vel(msg);
        z_vel = mavlink_msg_control_system_state_get_z_vel(msg);
        x_pos = mavlink_msg_control_system_state_get_x_pos(msg);
        y_pos = mavlink_msg_control_system_state_get_y_pos(msg);
        z_pos = mavlink_msg_control_system_state_get_z_pos(msg);
        airspeed = mavlink_msg_control_system_state_get_airspeed(msg);
        vel_variance = mavlink_msg_control_system_state_get_vel_variance(msg, control_system_state->vel_variance);
        pos_variance = mavlink_msg_control_system_state_get_pos_variance(msg, control_system_state->pos_variance);
        q = mavlink_msg_control_system_state_get_q(msg, control_system_state->q);
        roll_rate = mavlink_msg_control_system_state_get_roll_rate(msg);
        pitch_rate = mavlink_msg_control_system_state_get_pitch_rate(msg);
        yaw_rate = mavlink_msg_control_system_state_get_yaw_rate(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE_LEN? msg.len : MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

