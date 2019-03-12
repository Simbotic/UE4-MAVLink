 
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

}

