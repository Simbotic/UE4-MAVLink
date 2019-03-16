 
#include "MavLinkMsg_system_time.h"
#include "common/mavlink.h"



void FMavlinkMsg_system_time::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_system_time_pack(systemId, componentId, &msg,  time_unix_usec, time_boot_ms);
}

void FMavlinkMsg_system_time::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_system_time::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_unix_usec = mavlink_msg_system_time_get_time_unix_usec(msg);
        time_boot_ms = mavlink_msg_system_time_get_time_boot_ms(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SYSTEM_TIME_LEN? msg.len : MAVLINK_MSG_ID_SYSTEM_TIME_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

