 
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
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_hil_optical_flow_get_time_usec(msg);
        integration_time_us = mavlink_msg_hil_optical_flow_get_integration_time_us(msg);
        integrated_x = mavlink_msg_hil_optical_flow_get_integrated_x(msg);
        integrated_y = mavlink_msg_hil_optical_flow_get_integrated_y(msg);
        integrated_xgyro = mavlink_msg_hil_optical_flow_get_integrated_xgyro(msg);
        integrated_ygyro = mavlink_msg_hil_optical_flow_get_integrated_ygyro(msg);
        integrated_zgyro = mavlink_msg_hil_optical_flow_get_integrated_zgyro(msg);
        time_delta_distance_us = mavlink_msg_hil_optical_flow_get_time_delta_distance_us(msg);
        distance = mavlink_msg_hil_optical_flow_get_distance(msg);
        temperature = mavlink_msg_hil_optical_flow_get_temperature(msg);
        sensor_id = mavlink_msg_hil_optical_flow_get_sensor_id(msg);
        quality = mavlink_msg_hil_optical_flow_get_quality(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_HIL_OPTICAL_FLOW_LEN? msg.len : MAVLINK_MSG_ID_HIL_OPTICAL_FLOW_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_HIL_OPTICAL_FLOW_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

