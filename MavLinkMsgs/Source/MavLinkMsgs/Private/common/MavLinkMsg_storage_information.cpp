 
#include "MavLinkMsg_storage_information.h"
#include "common/mavlink.h"



void FMavlinkMsg_storage_information::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_storage_information_pack(systemId, componentId, &msg,  time_boot_ms, storage_id, storage_count, status, total_capacity, used_capacity, available_capacity, read_speed, write_speed);
}

void FMavlinkMsg_storage_information::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_storage_information::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_storage_information_get_time_boot_ms(msg);
        total_capacity = mavlink_msg_storage_information_get_total_capacity(msg);
        used_capacity = mavlink_msg_storage_information_get_used_capacity(msg);
        available_capacity = mavlink_msg_storage_information_get_available_capacity(msg);
        read_speed = mavlink_msg_storage_information_get_read_speed(msg);
        write_speed = mavlink_msg_storage_information_get_write_speed(msg);
        storage_id = mavlink_msg_storage_information_get_storage_id(msg);
        storage_count = mavlink_msg_storage_information_get_storage_count(msg);
        status = mavlink_msg_storage_information_get_status(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN? msg.len : MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

