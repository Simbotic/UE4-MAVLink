 
#include "MavLinkMsg_high_latency2.h"
#include "common/mavlink.h"



void FMavlinkMsg_high_latency2::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_high_latency2_pack(systemId, componentId, &msg,  timestamp, type, autopilot, custom_mode, latitude, longitude, altitude, target_altitude, heading, target_heading, target_distance, throttle, airspeed, airspeed_sp, groundspeed, windspeed, wind_heading, eph, epv, temperature_air, climb_rate, battery, wp_num, failure_flags, custom0, custom1, custom2);
}

void FMavlinkMsg_high_latency2::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_high_latency2::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        timestamp = mavlink_msg_high_latency2_get_timestamp(msg);
        latitude = mavlink_msg_high_latency2_get_latitude(msg);
        longitude = mavlink_msg_high_latency2_get_longitude(msg);
        custom_mode = mavlink_msg_high_latency2_get_custom_mode(msg);
        altitude = mavlink_msg_high_latency2_get_altitude(msg);
        target_altitude = mavlink_msg_high_latency2_get_target_altitude(msg);
        target_distance = mavlink_msg_high_latency2_get_target_distance(msg);
        wp_num = mavlink_msg_high_latency2_get_wp_num(msg);
        failure_flags = mavlink_msg_high_latency2_get_failure_flags(msg);
        type = mavlink_msg_high_latency2_get_type(msg);
        autopilot = mavlink_msg_high_latency2_get_autopilot(msg);
        heading = mavlink_msg_high_latency2_get_heading(msg);
        target_heading = mavlink_msg_high_latency2_get_target_heading(msg);
        throttle = mavlink_msg_high_latency2_get_throttle(msg);
        airspeed = mavlink_msg_high_latency2_get_airspeed(msg);
        airspeed_sp = mavlink_msg_high_latency2_get_airspeed_sp(msg);
        groundspeed = mavlink_msg_high_latency2_get_groundspeed(msg);
        windspeed = mavlink_msg_high_latency2_get_windspeed(msg);
        wind_heading = mavlink_msg_high_latency2_get_wind_heading(msg);
        eph = mavlink_msg_high_latency2_get_eph(msg);
        epv = mavlink_msg_high_latency2_get_epv(msg);
        temperature_air = mavlink_msg_high_latency2_get_temperature_air(msg);
        climb_rate = mavlink_msg_high_latency2_get_climb_rate(msg);
        battery = mavlink_msg_high_latency2_get_battery(msg);
        custom0 = mavlink_msg_high_latency2_get_custom0(msg);
        custom1 = mavlink_msg_high_latency2_get_custom1(msg);
        custom2 = mavlink_msg_high_latency2_get_custom2(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIGH_LATENCY2_LEN? msg.len : MAVLINK_MSG_ID_HIGH_LATENCY2_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIGH_LATENCY2_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

