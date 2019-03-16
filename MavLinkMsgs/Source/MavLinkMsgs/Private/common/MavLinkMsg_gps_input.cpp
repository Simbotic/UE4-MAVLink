 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_gps_input_get_time_usec(msg);
        time_week_ms = mavlink_msg_gps_input_get_time_week_ms(msg);
        lat = mavlink_msg_gps_input_get_lat(msg);
        lon = mavlink_msg_gps_input_get_lon(msg);
        alt = mavlink_msg_gps_input_get_alt(msg);
        hdop = mavlink_msg_gps_input_get_hdop(msg);
        vdop = mavlink_msg_gps_input_get_vdop(msg);
        vn = mavlink_msg_gps_input_get_vn(msg);
        ve = mavlink_msg_gps_input_get_ve(msg);
        vd = mavlink_msg_gps_input_get_vd(msg);
        speed_accuracy = mavlink_msg_gps_input_get_speed_accuracy(msg);
        horiz_accuracy = mavlink_msg_gps_input_get_horiz_accuracy(msg);
        vert_accuracy = mavlink_msg_gps_input_get_vert_accuracy(msg);
        ignore_flags = mavlink_msg_gps_input_get_ignore_flags(msg);
        time_week = mavlink_msg_gps_input_get_time_week(msg);
        gps_id = mavlink_msg_gps_input_get_gps_id(msg);
        fix_type = mavlink_msg_gps_input_get_fix_type(msg);
        satellites_visible = mavlink_msg_gps_input_get_satellites_visible(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GPS_INPUT_LEN? msg.len : MAVLINK_MSG_ID_GPS_INPUT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GPS_INPUT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

