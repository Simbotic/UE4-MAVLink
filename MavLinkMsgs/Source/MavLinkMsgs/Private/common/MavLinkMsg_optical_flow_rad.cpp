 
#include "MavLinkMsg_optical_flow_rad.h"
#include "common/mavlink.h"

void FMavlinkMsg_optical_flow_rad::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_optical_flow_rad_pack(systemId, componentId, &msg,  time_usec, sensor_id, integration_time_us, integrated_x, integrated_y, integrated_xgyro, integrated_ygyro, integrated_zgyro, temperature, quality, time_delta_distance_us, distance);
}

void FMavlinkMsg_optical_flow_rad::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_optical_flow_rad::Deserialize(const mavlink_message_t& msg)
{

}

