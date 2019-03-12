 
#include "MavLinkMsg_gps_input.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_input::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_input_pack(systemId, componentId, &msg,  time_usec, gps_id, ignore_flags, time_week_ms, time_week, fix_type, lat, lon, alt, hdop, vdop, vn, ve, vd, speed_accuracy, horiz_accuracy, vert_accuracy, satellites_visible);
}

void FMavlinkMsg_gps_input::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_input::Deserialize(const mavlink_message_t& msg)
{

}

