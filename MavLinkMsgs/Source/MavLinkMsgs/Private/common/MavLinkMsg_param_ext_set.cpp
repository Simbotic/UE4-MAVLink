 
#include "MavLinkMsg_param_ext_set.h"
#include "common/mavlink.h"



void FMavlinkMsg_param_ext_set::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_param_ext_set_pack(systemId, componentId, &msg,  target_system, target_component, (char*)param_id, (char*)param_value, param_type);
}

void FMavlinkMsg_param_ext_set::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_param_ext_set::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        target_system = mavlink_msg_param_ext_set_get_target_system(msg);
        target_component = mavlink_msg_param_ext_set_get_target_component(msg);
        param_id = mavlink_msg_param_ext_set_get_param_id(msg, param_ext_set->param_id);
        param_value = mavlink_msg_param_ext_set_get_param_value(msg, param_ext_set->param_value);
        param_type = mavlink_msg_param_ext_set_get_param_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_PARAM_EXT_SET_LEN? msg.len : MAVLINK_MSG_ID_PARAM_EXT_SET_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_PARAM_EXT_SET_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

