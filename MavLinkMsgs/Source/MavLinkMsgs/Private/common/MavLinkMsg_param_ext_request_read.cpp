 
#include "MavLinkMsg_param_ext_request_read.h"
#include "common/mavlink.h"

void FMavlinkMsg_param_ext_request_read::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_param_ext_request_read_pack(systemId, componentId, &msg,  target_system, target_component, (char*)param_id, param_index);
}

void FMavlinkMsg_param_ext_request_read::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_param_ext_request_read::Deserialize(const mavlink_message_t& msg)
{

}
