 
#include "MavLinkMsg_log_entry.h"
#include "common/mavlink.h"



void FMavlinkMsg_log_entry::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_log_entry_pack(systemId, componentId, &msg,  id, num_logs, last_log_num, time_utc, size);
}

void FMavlinkMsg_log_entry::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_log_entry::Deserialize(const mavlink_message_t& msg)
{

}

