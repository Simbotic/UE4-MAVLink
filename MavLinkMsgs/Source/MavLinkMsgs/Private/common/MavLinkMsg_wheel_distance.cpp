 
#include "MavLinkMsg_wheel_distance.h"
#include "common/mavlink.h"



void FMavlinkMsg_wheel_distance::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_wheel_distance_pack(systemId, componentId, &msg,  time_usec, count, distance);
}

void FMavlinkMsg_wheel_distance::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_wheel_distance::Deserialize(const mavlink_message_t& msg)
{

}

