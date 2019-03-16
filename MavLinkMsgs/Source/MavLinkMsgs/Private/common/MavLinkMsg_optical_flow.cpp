 
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
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_optical_flow::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_optical_flow_get_time_usec(msg);
        flow_comp_m_x = mavlink_msg_optical_flow_get_flow_comp_m_x(msg);
        flow_comp_m_y = mavlink_msg_optical_flow_get_flow_comp_m_y(msg);
        ground_distance = mavlink_msg_optical_flow_get_ground_distance(msg);
        flow_x = mavlink_msg_optical_flow_get_flow_x(msg);
        flow_y = mavlink_msg_optical_flow_get_flow_y(msg);
        sensor_id = mavlink_msg_optical_flow_get_sensor_id(msg);
        quality = mavlink_msg_optical_flow_get_quality(msg);
        flow_rate_x = mavlink_msg_optical_flow_get_flow_rate_x(msg);
        flow_rate_y = mavlink_msg_optical_flow_get_flow_rate_y(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_OPTICAL_FLOW_LEN? msg.len : MAVLINK_MSG_ID_OPTICAL_FLOW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_OPTICAL_FLOW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

