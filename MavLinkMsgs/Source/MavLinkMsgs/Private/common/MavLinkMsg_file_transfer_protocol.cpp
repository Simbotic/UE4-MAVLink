 
#include "MavLinkMsg_file_transfer_protocol.h"
#include "common/mavlink.h"



void FMavlinkMsg_file_transfer_protocol::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_file_transfer_protocol_pack(systemId, componentId, &msg,  target_network, target_system, target_component, (uint8_t*)payload);
}

void FMavlinkMsg_file_transfer_protocol::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_file_transfer_protocol::Deserialize(const mavlink_message_t& msg)
{

}

