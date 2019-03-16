 
#include "MavLinkMsg_param_value.h"
#include "common/mavlink.h"



void FMavlinkMsg_param_value::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_param_value_pack(systemId, componentId, &msg,  (char*)param_id, param_value, param_type, param_count, param_index);
}

void FMavlinkMsg_param_value::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_param_value::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        param_value = mavlink_msg_param_value_get_param_value(msg);
        param_count = mavlink_msg_param_value_get_param_count(msg);
        param_index = mavlink_msg_param_value_get_param_index(msg);
        param_id = mavlink_msg_param_value_get_param_id(msg, param_value->param_id);
        param_type = mavlink_msg_param_value_get_param_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_PARAM_VALUE_LEN? msg.len : MAVLINK_MSG_ID_PARAM_VALUE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_PARAM_VALUE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

