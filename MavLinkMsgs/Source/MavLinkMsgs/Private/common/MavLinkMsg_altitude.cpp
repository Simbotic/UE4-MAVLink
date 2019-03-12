 
#include "MavLinkMsg_altitude.h"
#include "common/mavlink.h"



void FMavlinkMsg_altitude::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_altitude_pack(systemId, componentId, &msg,  time_usec, altitude_monotonic, altitude_amsl, altitude_local, altitude_relative, altitude_terrain, bottom_clearance);
}

void FMavlinkMsg_altitude::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_altitude::Deserialize(const mavlink_message_t& msg)
{

}

