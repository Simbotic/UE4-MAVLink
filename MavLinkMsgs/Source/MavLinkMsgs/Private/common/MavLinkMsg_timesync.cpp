 
#include "MavLinkMsg_timesync.h"
#include "common/mavlink.h"

void FMavlinkMsg_timesync::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_timesync_pack(systemId, componentId, &msg,  tc1, ts1);
}

void FMavlinkMsg_timesync::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_timesync::Deserialize(const mavlink_message_t& msg)
{

}

