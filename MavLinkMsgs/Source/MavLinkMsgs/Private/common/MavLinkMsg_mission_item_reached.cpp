 
#include "MavLinkMsg_mission_item_reached.h"
#include "common/mavlink.h"



void FMavlinkMsg_mission_item_reached::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mission_item_reached_pack(systemId, componentId, &msg,  seq);
}

void FMavlinkMsg_mission_item_reached::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mission_item_reached::Deserialize(const mavlink_message_t& msg)
{

}

