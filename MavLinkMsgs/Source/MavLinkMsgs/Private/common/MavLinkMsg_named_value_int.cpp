 
#include "MavLinkMsg_named_value_int.h"
#include "common/mavlink.h"



void FMavlinkMsg_named_value_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_named_value_int_pack(systemId, componentId, &msg,  time_boot_ms, (char*)name, value);
}

void FMavlinkMsg_named_value_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_named_value_int::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_named_value_int_get_time_boot_ms(msg);
        value = mavlink_msg_named_value_int_get_value(msg);
        name = mavlink_msg_named_value_int_get_name(msg, named_value_int->name);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_NAMED_VALUE_INT_LEN? msg.len : MAVLINK_MSG_ID_NAMED_VALUE_INT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_NAMED_VALUE_INT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

