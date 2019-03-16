 
#include "MavLinkMsg_logging_ack.h"
#include "common/mavlink.h"



void FMavlinkMsg_logging_ack::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_logging_ack_pack(systemId, componentId, &msg,  target_system, target_component, sequence);
}

void FMavlinkMsg_logging_ack::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_logging_ack::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        sequence = mavlink_msg_logging_ack_get_sequence(msg);
        target_system = mavlink_msg_logging_ack_get_target_system(msg);
        target_component = mavlink_msg_logging_ack_get_target_component(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_LOGGING_ACK_LEN? msg.len : MAVLINK_MSG_ID_LOGGING_ACK_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_LOGGING_ACK_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

