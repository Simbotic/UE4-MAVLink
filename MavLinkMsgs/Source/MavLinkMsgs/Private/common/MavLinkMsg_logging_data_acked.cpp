 
#include "MavLinkMsg_logging_data_acked.h"
#include "common/mavlink.h"



void FMavlinkMsg_logging_data_acked::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_logging_data_acked_pack(systemId, componentId, &msg,  target_system, target_component, sequence, length, first_message_offset, (uint8_t*)data);
}

void FMavlinkMsg_logging_data_acked::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_logging_data_acked::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        sequence = mavlink_msg_logging_data_acked_get_sequence(msg);
        target_system = mavlink_msg_logging_data_acked_get_target_system(msg);
        target_component = mavlink_msg_logging_data_acked_get_target_component(msg);
        length = mavlink_msg_logging_data_acked_get_length(msg);
        first_message_offset = mavlink_msg_logging_data_acked_get_first_message_offset(msg);
        data = mavlink_msg_logging_data_acked_get_data(msg, logging_data_acked->data);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOGGING_DATA_ACKED_LEN? msg.len : MAVLINK_MSG_ID_LOGGING_DATA_ACKED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOGGING_DATA_ACKED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

