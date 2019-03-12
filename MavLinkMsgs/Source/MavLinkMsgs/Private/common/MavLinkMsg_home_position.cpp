 
#include "MavLinkMsg_home_position.h"
#include "common/mavlink.h"



void FMavlinkMsg_home_position::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_home_position_pack(systemId, componentId, &msg,  latitude, longitude, altitude, x, y, z, q, approach_x, approach_y, approach_z, time_usec);
}

void FMavlinkMsg_home_position::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_home_position::Deserialize(const mavlink_message_t& msg)
{

}

