 
#include "MavLinkMsg_manual_setpoint.h"
#include "common/mavlink.h"



void FMavlinkMsg_manual_setpoint::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_manual_setpoint_pack(systemId, componentId, &msg,  time_boot_ms, roll, pitch, yaw, thrust, mode_switch, manual_override_switch);
}

void FMavlinkMsg_manual_setpoint::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_manual_setpoint::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_manual_setpoint_get_time_boot_ms(msg);
        roll = mavlink_msg_manual_setpoint_get_roll(msg);
        pitch = mavlink_msg_manual_setpoint_get_pitch(msg);
        yaw = mavlink_msg_manual_setpoint_get_yaw(msg);
        thrust = mavlink_msg_manual_setpoint_get_thrust(msg);
        mode_switch = mavlink_msg_manual_setpoint_get_mode_switch(msg);
        manual_override_switch = mavlink_msg_manual_setpoint_get_manual_override_switch(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MANUAL_SETPOINT_LEN? msg.len : MAVLINK_MSG_ID_MANUAL_SETPOINT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MANUAL_SETPOINT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

