 
#include "MavLinkMsg_local_position_ned.h"
#include "common/mavlink.h"

void FMavlinkMsg_local_position_ned::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_local_position_ned_pack(systemId, componentId, &msg,  time_boot_ms, x, y, z, vx, vy, vz);
}

void FMavlinkMsg_local_position_ned::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_local_position_ned::Deserialize(const mavlink_message_t& msg)
{

}

