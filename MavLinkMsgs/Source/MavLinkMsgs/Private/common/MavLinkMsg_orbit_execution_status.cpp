 
#include "MavLinkMsg_orbit_execution_status.h"
#include "common/mavlink.h"

void FMavlinkMsg_orbit_execution_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_orbit_execution_status_pack(systemId, componentId, &msg,  time_usec, radius, frame, x, y, z);
}

void FMavlinkMsg_orbit_execution_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_orbit_execution_status::Deserialize(const mavlink_message_t& msg)
{

}

