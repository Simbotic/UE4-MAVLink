 
#include "MavLinkMsg_resource_request.h"
#include "common/mavlink.h"

void FMavlinkMsg_resource_request::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_resource_request_pack(systemId, componentId, &msg,  request_id, uri_type, (uint8_t*)uri, transfer_type, (uint8_t*)storage);
}

void FMavlinkMsg_resource_request::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_resource_request::Deserialize(const mavlink_message_t& msg)
{

}

