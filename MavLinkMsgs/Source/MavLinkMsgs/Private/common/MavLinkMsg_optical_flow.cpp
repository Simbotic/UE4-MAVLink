 
#include "MavLinkMsg_optical_flow.h"
#include "common/mavlink.h"

void FMavlinkMsg_optical_flow::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_optical_flow_pack(systemId, componentId, &msg,  time_usec, sensor_id, flow_x, flow_y, flow_comp_m_x, flow_comp_m_y, quality, ground_distance, flow_rate_x, flow_rate_y);
}

void FMavlinkMsg_optical_flow::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId, msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_optical_flow::Deserialize(const mavlink_message_t& msg)
{

}

