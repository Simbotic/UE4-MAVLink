 
#include "MavLinkMsg_command_long.h"
#include "common/mavlink.h"



void FMavlinkMsg_command_long::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_command_long_pack(systemId, componentId, &msg,  target_system, target_component, command, confirmation, param1, param2, param3, param4, param5, param6, param7);
}

void FMavlinkMsg_command_long::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_command_long::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        param1 = mavlink_msg_command_long_get_param1(msg);
        param2 = mavlink_msg_command_long_get_param2(msg);
        param3 = mavlink_msg_command_long_get_param3(msg);
        param4 = mavlink_msg_command_long_get_param4(msg);
        param5 = mavlink_msg_command_long_get_param5(msg);
        param6 = mavlink_msg_command_long_get_param6(msg);
        param7 = mavlink_msg_command_long_get_param7(msg);
        command = mavlink_msg_command_long_get_command(msg);
        target_system = mavlink_msg_command_long_get_target_system(msg);
        target_component = mavlink_msg_command_long_get_target_component(msg);
        confirmation = mavlink_msg_command_long_get_confirmation(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_COMMAND_LONG_LEN? msg.len : MAVLINK_MSG_ID_COMMAND_LONG_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

