 
#include "MavLinkMsg_param_ext_ack.h"
#include "common/mavlink.h"

void FMavlinkMsg_param_ext_ack::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_param_ext_ack_pack(systemId, componentId, &msg,  (char*)param_id, (char*)param_value, param_type, param_result);
}

void FMavlinkMsg_param_ext_ack::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_param_ext_ack::Deserialize(const mavlink_message_t& msg)
{

}
