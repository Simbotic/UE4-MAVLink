 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_gps2_raw_get_time_usec(msg);
        lat = mavlink_msg_gps2_raw_get_lat(msg);
        lon = mavlink_msg_gps2_raw_get_lon(msg);
        alt = mavlink_msg_gps2_raw_get_alt(msg);
        dgps_age = mavlink_msg_gps2_raw_get_dgps_age(msg);
        eph = mavlink_msg_gps2_raw_get_eph(msg);
        epv = mavlink_msg_gps2_raw_get_epv(msg);
        vel = mavlink_msg_gps2_raw_get_vel(msg);
        cog = mavlink_msg_gps2_raw_get_cog(msg);
        fix_type = mavlink_msg_gps2_raw_get_fix_type(msg);
        satellites_visible = mavlink_msg_gps2_raw_get_satellites_visible(msg);
        dgps_numch = mavlink_msg_gps2_raw_get_dgps_numch(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS2_RAW_LEN? msg.len : MAVLINK_MSG_ID_GPS2_RAW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS2_RAW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

