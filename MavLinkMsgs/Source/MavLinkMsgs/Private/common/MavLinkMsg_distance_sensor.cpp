 
#include "MavLinkMsg_distance_sensor.h"
#include "common/mavlink.h"



void FMavlinkMsg_distance_sensor::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_distance_sensor_pack(systemId, componentId, &msg,  time_boot_ms, min_distance, max_distance, current_distance, type, id, orientation, covariance, horizontal_fov, vertical_fov, quaternion);
}

void FMavlinkMsg_distance_sensor::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_distance_sensor::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_distance_sensor_get_time_boot_ms(msg);
        min_distance = mavlink_msg_distance_sensor_get_min_distance(msg);
        max_distance = mavlink_msg_distance_sensor_get_max_distance(msg);
        current_distance = mavlink_msg_distance_sensor_get_current_distance(msg);
        type = mavlink_msg_distance_sensor_get_type(msg);
        id = mavlink_msg_distance_sensor_get_id(msg);
        orientation = mavlink_msg_distance_sensor_get_orientation(msg);
        covariance = mavlink_msg_distance_sensor_get_covariance(msg);
        horizontal_fov = mavlink_msg_distance_sensor_get_horizontal_fov(msg);
        vertical_fov = mavlink_msg_distance_sensor_get_vertical_fov(msg);
        quaternion = mavlink_msg_distance_sensor_get_quaternion(msg, distance_sensor->quaternion);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN? msg.len : MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_DISTANCE_SENSOR_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

