 
#include "MavLinkMsg_collision.h"
#include "common/mavlink.h"

void FMavlinkMsg_collision::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_collision_pack(systemId, componentId, &msg,  src, id, action, threat_level, time_to_minimum_delta, altitude_minimum_delta, horizontal_minimum_delta);
}

void FMavlinkMsg_collision::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_collision::Deserialize(const mavlink_message_t& msg)
{

}

