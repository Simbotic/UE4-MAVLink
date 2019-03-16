 
#include "MavLinkMsg_gps_raw_int.h"
#include "common/mavlink.h"



void FMavlinkMsg_gps_raw_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_gps_raw_int_pack(systemId, componentId, &msg,  time_usec, fix_type, lat, lon, alt, eph, epv, vel, cog, satellites_visible, alt_ellipsoid, h_acc, v_acc, vel_acc, hdg_acc);
}

void FMavlinkMsg_gps_raw_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_gps_raw_int::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_gps_raw_int_get_time_usec(msg);
        lat = mavlink_msg_gps_raw_int_get_lat(msg);
        lon = mavlink_msg_gps_raw_int_get_lon(msg);
        alt = mavlink_msg_gps_raw_int_get_alt(msg);
        eph = mavlink_msg_gps_raw_int_get_eph(msg);
        epv = mavlink_msg_gps_raw_int_get_epv(msg);
        vel = mavlink_msg_gps_raw_int_get_vel(msg);
        cog = mavlink_msg_gps_raw_int_get_cog(msg);
        fix_type = mavlink_msg_gps_raw_int_get_fix_type(msg);
        satellites_visible = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
        alt_ellipsoid = mavlink_msg_gps_raw_int_get_alt_ellipsoid(msg);
        h_acc = mavlink_msg_gps_raw_int_get_h_acc(msg);
        v_acc = mavlink_msg_gps_raw_int_get_v_acc(msg);
        vel_acc = mavlink_msg_gps_raw_int_get_vel_acc(msg);
        hdg_acc = mavlink_msg_gps_raw_int_get_hdg_acc(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS_RAW_INT_LEN? msg.len : MAVLINK_MSG_ID_GPS_RAW_INT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS_RAW_INT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

