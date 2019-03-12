 
#include "MavLinkMsg_hil_optical_flow.h"
#include "common/mavlink.h"



void FMavlinkMsg_hil_optical_flow::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_hil_optical_flow_pack(systemId, componentId, &msg,  time_usec, sensor_id, integration_time_us, integrated_x, integrated_y, integrated_xgyro, integrated_ygyro, integrated_zgyro, temperature, quality, time_delta_distance_us, distance);
}

void FMavlinkMsg_hil_optical_flow::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_hil_optical_flow::Deserialize(const mavlink_message_t& msg)
{

}

