 
#include "MavLinkMsg_debug_float_array.h"
#include "common/mavlink.h"



void FMavlinkMsg_debug_float_array::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_debug_float_array_pack(systemId, componentId, &msg,  time_usec, (char*)name, array_id, data);
}

void FMavlinkMsg_debug_float_array::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_debug_float_array::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_debug_float_array_get_time_usec(msg);
        array_id = mavlink_msg_debug_float_array_get_array_id(msg);
        name = mavlink_msg_debug_float_array_get_name(msg, debug_float_array->name);
        data = mavlink_msg_debug_float_array_get_data(msg, debug_float_array->data);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN? msg.len : MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

