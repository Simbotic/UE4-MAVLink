 
#include "MavLinkMsg_command_int.h"
#include "common/mavlink.h"



void FMavlinkMsg_command_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_command_int_pack(systemId, componentId, &msg,  target_system, target_component, frame, command, current, autocontinue, param1, param2, param3, param4, x, y, z);
}

void FMavlinkMsg_command_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_command_int::Deserialize(const mavlink_message_t& msg)
{

}

