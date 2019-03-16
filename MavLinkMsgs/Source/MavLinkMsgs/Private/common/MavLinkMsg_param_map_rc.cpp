 
#include "MavLinkMsg_param_map_rc.h"
#include "common/mavlink.h"



void FMavlinkMsg_param_map_rc::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_param_map_rc_pack(systemId, componentId, &msg,  target_system, target_component, (char*)param_id, param_index, parameter_rc_channel_index, param_value0, scale, param_value_min, param_value_max);
}

void FMavlinkMsg_param_map_rc::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_param_map_rc::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        param_value0 = mavlink_msg_param_map_rc_get_param_value0(msg);
        scale = mavlink_msg_param_map_rc_get_scale(msg);
        param_value_min = mavlink_msg_param_map_rc_get_param_value_min(msg);
        param_value_max = mavlink_msg_param_map_rc_get_param_value_max(msg);
        param_index = mavlink_msg_param_map_rc_get_param_index(msg);
        target_system = mavlink_msg_param_map_rc_get_target_system(msg);
        target_component = mavlink_msg_param_map_rc_get_target_component(msg);
        param_id = mavlink_msg_param_map_rc_get_param_id(msg, param_map_rc->param_id);
        parameter_rc_channel_index = mavlink_msg_param_map_rc_get_parameter_rc_channel_index(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_PARAM_MAP_RC_LEN? msg.len : MAVLINK_MSG_ID_PARAM_MAP_RC_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_PARAM_MAP_RC_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

