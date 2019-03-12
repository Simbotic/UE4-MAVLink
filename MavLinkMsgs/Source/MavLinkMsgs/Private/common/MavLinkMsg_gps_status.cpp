 
#include "MavLinkMsg_gps_status.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_status::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_status_pack(systemId, componentId, &msg,  satellites_visible, (uint8_t*)satellite_prn, (uint8_t*)satellite_used, (uint8_t*)satellite_elevation, (uint8_t*)satellite_azimuth, (uint8_t*)satellite_snr);
}

void FMavlinkMsg_gps_status::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_status::Deserialize(const mavlink_message_t& msg)
{

}

