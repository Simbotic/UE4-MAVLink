 
#include "MavLinkMsg_data_transmission_handshake.h"
#include "common/mavlink.h"

void FMavlinkMsg_data_transmission_handshake::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_data_transmission_handshake_pack(systemId, componentId, &msg,  type, size, width, height, packets, payload, jpg_quality);
}

void FMavlinkMsg_data_transmission_handshake::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_data_transmission_handshake::Deserialize(const mavlink_message_t& msg)
{

}

