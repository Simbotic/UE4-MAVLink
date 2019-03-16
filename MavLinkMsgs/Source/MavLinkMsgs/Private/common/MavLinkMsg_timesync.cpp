 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_timesync::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        tc1 = mavlink_msg_timesync_get_tc1(msg);
        ts1 = mavlink_msg_timesync_get_ts1(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_TIMESYNC_LEN? msg.len : MAVLINK_MSG_ID_TIMESYNC_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_TIMESYNC_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

