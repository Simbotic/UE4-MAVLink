 
#include "MavLinkMsg_debug.h"
#include "common/mavlink.h"



void FMavlinkMsg_debug::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_debug_pack(systemId, componentId, &msg,  time_boot_ms, ind, value);
}

void FMavlinkMsg_debug::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_debug::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_debug_get_time_boot_ms(msg);
        value = mavlink_msg_debug_get_value(msg);
        ind = mavlink_msg_debug_get_ind(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_DEBUG_LEN? msg.len : MAVLINK_MSG_ID_DEBUG_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_DEBUG_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

