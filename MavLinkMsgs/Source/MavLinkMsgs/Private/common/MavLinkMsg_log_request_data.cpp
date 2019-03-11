 
#include "MavLinkMsg_log_request_data.h"
#include "common/mavlink.h"

void FMavlinkMsg_log_request_data::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_log_request_data_pack(systemId, componentId, &msg,  target_system, target_component, id, ofs, count);
}

void FMavlinkMsg_log_request_data::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_log_request_data::Deserialize(const mavlink_message_t& msg)
{

}
