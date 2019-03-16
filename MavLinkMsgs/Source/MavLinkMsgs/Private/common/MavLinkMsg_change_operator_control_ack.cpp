 
#include "MavLinkMsg_change_operator_control_ack.h"
#include "common/mavlink.h"



void FMavlinkMsg_change_operator_control_ack::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_change_operator_control_ack_pack(systemId, componentId, &msg,  gcs_system_id, control_request, ack);
}

void FMavlinkMsg_change_operator_control_ack::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_change_operator_control_ack::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        gcs_system_id = mavlink_msg_change_operator_control_ack_get_gcs_system_id(msg);
        control_request = mavlink_msg_change_operator_control_ack_get_control_request(msg);
        ack = mavlink_msg_change_operator_control_ack_get_ack(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK_LEN? msg.len : MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

