 
#include "MavLinkMsg_memory_vect.h"
#include "common/mavlink.h"

void FMavlinkMsg_memory_vect::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_memory_vect_pack(systemId, componentId, &msg,  address, ver, type, (int8_t*)value);
}

void FMavlinkMsg_memory_vect::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_memory_vect::Deserialize(const mavlink_message_t& msg)
{

}

