 
#include "MavLinkMsg_change_operator_control.h"
#include "common/mavlink.h"



void FMavlinkMsg_change_operator_control::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_change_operator_control_pack(systemId, componentId, &msg,  target_system, control_request, version, (char*)passkey);
}

void FMavlinkMsg_change_operator_control::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_change_operator_control::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        target_system = mavlink_msg_change_operator_control_get_target_system(msg);
        control_request = mavlink_msg_change_operator_control_get_control_request(msg);
        version = mavlink_msg_change_operator_control_get_version(msg);
        passkey = mavlink_msg_change_operator_control_get_passkey(msg, change_operator_control->passkey);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_LEN? msg.len : MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

