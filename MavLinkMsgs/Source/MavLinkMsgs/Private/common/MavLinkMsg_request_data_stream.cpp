 
#include "MavLinkMsg_request_data_stream.h"
#include "common/mavlink.h"



void FMavlinkMsg_request_data_stream::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_request_data_stream_pack(systemId, componentId, &msg,  target_system, target_component, req_stream_id, req_message_rate, start_stop);
}

void FMavlinkMsg_request_data_stream::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_request_data_stream::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        req_message_rate = mavlink_msg_request_data_stream_get_req_message_rate(msg);
        target_system = mavlink_msg_request_data_stream_get_target_system(msg);
        target_component = mavlink_msg_request_data_stream_get_target_component(msg);
        req_stream_id = mavlink_msg_request_data_stream_get_req_stream_id(msg);
        start_stop = mavlink_msg_request_data_stream_get_start_stop(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_REQUEST_DATA_STREAM_LEN? msg.len : MAVLINK_MSG_ID_REQUEST_DATA_STREAM_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_REQUEST_DATA_STREAM_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

