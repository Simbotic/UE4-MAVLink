 
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

}

