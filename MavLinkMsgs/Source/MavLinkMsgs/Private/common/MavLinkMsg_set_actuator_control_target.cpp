 
#include "MavLinkMsg_set_actuator_control_target.h"
#include "common/mavlink.h"



void FMavlinkMsg_set_actuator_control_target::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_actuator_control_target_pack(systemId, componentId, &msg,  time_usec, group_mlx, target_system, target_component, controls);
}

void FMavlinkMsg_set_actuator_control_target::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_actuator_control_target::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_set_actuator_control_target_get_time_usec(msg);
        controls = mavlink_msg_set_actuator_control_target_get_controls(msg, set_actuator_control_target->controls);
        group_mlx = mavlink_msg_set_actuator_control_target_get_group_mlx(msg);
        target_system = mavlink_msg_set_actuator_control_target_get_target_system(msg);
        target_component = mavlink_msg_set_actuator_control_target_get_target_component(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET_LEN? msg.len : MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

