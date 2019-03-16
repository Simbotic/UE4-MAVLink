 
#include "MavLinkMsg_data_stream.h"
#include "common/mavlink.h"



void FMavlinkMsg_data_stream::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_data_stream_pack(systemId, componentId, &msg,  stream_id, message_rate, on_off);
}

void FMavlinkMsg_data_stream::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_data_stream::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        message_rate = mavlink_msg_data_stream_get_message_rate(msg);
        stream_id = mavlink_msg_data_stream_get_stream_id(msg);
        on_off = mavlink_msg_data_stream_get_on_off(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_DATA_STREAM_LEN? msg.len : MAVLINK_MSG_ID_DATA_STREAM_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_DATA_STREAM_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

