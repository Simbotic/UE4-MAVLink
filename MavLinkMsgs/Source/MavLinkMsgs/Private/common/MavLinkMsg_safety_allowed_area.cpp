 
#include "MavLinkMsg_safety_allowed_area.h"
#include "common/mavlink.h"



void FMavlinkMsg_safety_allowed_area::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_safety_allowed_area_pack(systemId, componentId, &msg,  frame, p1x, p1y, p1z, p2x, p2y, p2z);
}

void FMavlinkMsg_safety_allowed_area::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_safety_allowed_area::Deserialize(const mavlink_message_t& msg)
{

}

