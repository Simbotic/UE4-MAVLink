 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_message_interval::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        interval_us = mavlink_msg_message_interval_get_interval_us(msg);
        message_id = mavlink_msg_message_interval_get_message_id(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN? msg.len : MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

