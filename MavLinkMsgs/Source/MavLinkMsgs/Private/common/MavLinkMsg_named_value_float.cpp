 
#include "MavLinkMsg_named_value_float.h"
#include "common/mavlink.h"



void FMavlinkMsg_named_value_float::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_named_value_float_pack(systemId, componentId, &msg,  time_boot_ms, (char*)name, value);
}

void FMavlinkMsg_named_value_float::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_named_value_float::Deserialize(const mavlink_message_t& msg)
{

}

