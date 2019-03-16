 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        satellites_visible = mavlink_msg_gps_status_get_satellites_visible(msg);
        satellite_prn = mavlink_msg_gps_status_get_satellite_prn(msg, gps_status->satellite_prn);
        satellite_used = mavlink_msg_gps_status_get_satellite_used(msg, gps_status->satellite_used);
        satellite_elevation = mavlink_msg_gps_status_get_satellite_elevation(msg, gps_status->satellite_elevation);
        satellite_azimuth = mavlink_msg_gps_status_get_satellite_azimuth(msg, gps_status->satellite_azimuth);
        satellite_snr = mavlink_msg_gps_status_get_satellite_snr(msg, gps_status->satellite_snr);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS_STATUS_LEN? msg.len : MAVLINK_MSG_ID_GPS_STATUS_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS_STATUS_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

