 
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

}

