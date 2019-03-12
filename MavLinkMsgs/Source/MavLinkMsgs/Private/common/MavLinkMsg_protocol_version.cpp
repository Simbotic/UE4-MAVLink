 
#include "MavLinkMsg_protocol_version.h"
#include "common/mavlink.h"



void FMavlinkMsg_protocol_version::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_protocol_version_pack(systemId, componentId, &msg,  version, min_version, max_version, (uint8_t*)spec_version_hash, (uint8_t*)library_version_hash);
}

void FMavlinkMsg_protocol_version::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_protocol_version::Deserialize(const mavlink_message_t& msg)
{

}

