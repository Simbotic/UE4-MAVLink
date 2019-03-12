 
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

}

