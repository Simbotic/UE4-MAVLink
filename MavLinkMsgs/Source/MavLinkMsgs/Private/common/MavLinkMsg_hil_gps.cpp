 
#include "MavLinkMsg_hil_gps.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_gps::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_gps_pack(systemId, componentId, &msg,  time_usec, fix_type, lat, lon, alt, eph, epv, vel, vn, ve, vd, cog, satellites_visible);
}

void FMavlinkMsg_hil_gps::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_gps::Deserialize(const mavlink_message_t& msg)
{

}

