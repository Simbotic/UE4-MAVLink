 
#include "MavLinkMsg_message_interval.h"
#include "common/mavlink.h"

void FMavlinkMsg_message_interval::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_message_interval_pack(systemId, componentId, &msg,  message_id, interval_us);
}

void FMavlinkMsg_message_interval::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_message_interval::Deserialize(const mavlink_message_t& msg)
{

}

