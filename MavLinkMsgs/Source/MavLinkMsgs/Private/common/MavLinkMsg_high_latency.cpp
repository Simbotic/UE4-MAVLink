 
#include "MavLinkMsg_high_latency.h"
#include "common/mavlink.h"



void FMavlinkMsg_high_latency::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_high_latency_pack(systemId, componentId, &msg,  base_mode, custom_mode, landed_state, roll, pitch, heading, throttle, heading_sp, latitude, longitude, altitude_amsl, altitude_sp, airspeed, airspeed_sp, groundspeed, climb_rate, gps_nsat, gps_fix_type, battery_remaining, temperature, temperature_air, failsafe, wp_num, wp_distance);
}

void FMavlinkMsg_high_latency::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_high_latency::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        custom_mode = mavlink_msg_high_latency_get_custom_mode(msg);
        latitude = mavlink_msg_high_latency_get_latitude(msg);
        longitude = mavlink_msg_high_latency_get_longitude(msg);
        roll = mavlink_msg_high_latency_get_roll(msg);
        pitch = mavlink_msg_high_latency_get_pitch(msg);
        heading = mavlink_msg_high_latency_get_heading(msg);
        heading_sp = mavlink_msg_high_latency_get_heading_sp(msg);
        altitude_amsl = mavlink_msg_high_latency_get_altitude_amsl(msg);
        altitude_sp = mavlink_msg_high_latency_get_altitude_sp(msg);
        wp_distance = mavlink_msg_high_latency_get_wp_distance(msg);
        base_mode = mavlink_msg_high_latency_get_base_mode(msg);
        landed_state = mavlink_msg_high_latency_get_landed_state(msg);
        throttle = mavlink_msg_high_latency_get_throttle(msg);
        airspeed = mavlink_msg_high_latency_get_airspeed(msg);
        airspeed_sp = mavlink_msg_high_latency_get_airspeed_sp(msg);
        groundspeed = mavlink_msg_high_latency_get_groundspeed(msg);
        climb_rate = mavlink_msg_high_latency_get_climb_rate(msg);
        gps_nsat = mavlink_msg_high_latency_get_gps_nsat(msg);
        gps_fix_type = mavlink_msg_high_latency_get_gps_fix_type(msg);
        battery_remaining = mavlink_msg_high_latency_get_battery_remaining(msg);
        temperature = mavlink_msg_high_latency_get_temperature(msg);
        temperature_air = mavlink_msg_high_latency_get_temperature_air(msg);
        failsafe = mavlink_msg_high_latency_get_failsafe(msg);
        wp_num = mavlink_msg_high_latency_get_wp_num(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIGH_LATENCY_LEN? msg.len : MAVLINK_MSG_ID_HIGH_LATENCY_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIGH_LATENCY_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

