 
#include "MavLinkMsg_gps2_raw.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps2_raw::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps2_raw_pack(systemId, componentId, &msg,  time_usec, fix_type, lat, lon, alt, eph, epv, vel, cog, satellites_visible, dgps_numch, dgps_age);
}

void FMavlinkMsg_gps2_raw::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps2_raw::Deserialize(const mavlink_message_t& msg)
{

}

