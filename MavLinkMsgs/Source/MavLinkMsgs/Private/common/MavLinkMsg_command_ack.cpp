 
#include "MavLinkMsg_command_ack.h"
#include "common/mavlink.h"



void FMavlinkMsg_command_ack::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_command_ack_pack(systemId, componentId, &msg,  command, result, progress, result_param2, target_system, target_component);
}

void FMavlinkMsg_command_ack::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_command_ack::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        command = mavlink_msg_command_ack_get_command(msg);
        result = mavlink_msg_command_ack_get_result(msg);
        progress = mavlink_msg_command_ack_get_progress(msg);
        result_param2 = mavlink_msg_command_ack_get_result_param2(msg);
        target_system = mavlink_msg_command_ack_get_target_system(msg);
        target_component = mavlink_msg_command_ack_get_target_component(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_COMMAND_ACK_LEN? msg.len : MAVLINK_MSG_ID_COMMAND_ACK_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_COMMAND_ACK_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

