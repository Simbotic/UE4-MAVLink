 
#include "MavLinkMsg_mission_clear_all.h"
#include "common/mavlink.h"



void FMavlinkMsg_mission_clear_all::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mission_clear_all_pack(systemId, componentId, &msg,  target_system, target_component, mission_type);
}

void FMavlinkMsg_mission_clear_all::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mission_clear_all::Deserialize(const mavlink_message_t& msg)
{

}

