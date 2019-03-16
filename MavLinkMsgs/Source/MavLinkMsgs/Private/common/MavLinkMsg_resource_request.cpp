 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_resource_request::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        request_id = mavlink_msg_resource_request_get_request_id(msg);
        uri_type = mavlink_msg_resource_request_get_uri_type(msg);
        uri = mavlink_msg_resource_request_get_uri(msg, resource_request->uri);
        transfer_type = mavlink_msg_resource_request_get_transfer_type(msg);
        storage = mavlink_msg_resource_request_get_storage(msg, resource_request->storage);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN? msg.len : MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

