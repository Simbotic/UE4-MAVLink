 
#include "MavLinkMsg_log_request_end.h"
#include "common/mavlink.h"



void FMavlinkMsg_log_request_end::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_log_request_end_pack(systemId, componentId, &msg,  target_system, target_component);
}

void FMavlinkMsg_log_request_end::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_log_request_end::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        target_system = mavlink_msg_log_request_end_get_target_system(msg);
        target_component = mavlink_msg_log_request_end_get_target_component(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOG_REQUEST_END_LEN? msg.len : MAVLINK_MSG_ID_LOG_REQUEST_END_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOG_REQUEST_END_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

