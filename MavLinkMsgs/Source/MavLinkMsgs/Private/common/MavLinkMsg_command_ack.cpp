 
#include "MavLinkMsg_command_ack.h"
#include "common/mavlink.h"

void FMavlinkMsg_command_ack::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_command_ack_pack(systemId, componentId, &msg,  command, result, progress, result_param2, target_system, target_component);
}

void FMavlinkMsg_command_ack::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_command_ack::Deserialize(const mavlink_message_t& msg)
{

}

