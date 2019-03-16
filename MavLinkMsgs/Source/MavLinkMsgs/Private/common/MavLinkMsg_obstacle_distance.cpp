 
#include "MavLinkMsg_obstacle_distance.h"
#include "common/mavlink.h"



void FMavlinkMsg_obstacle_distance::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_obstacle_distance_pack(systemId, componentId, &msg,  time_usec, sensor_type, (uint16_t*)distances, increment, min_distance, max_distance);
}

void FMavlinkMsg_obstacle_distance::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_obstacle_distance::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_obstacle_distance_get_time_usec(msg);
        distances = mavlink_msg_obstacle_distance_get_distances(msg, obstacle_distance->distances);
        min_distance = mavlink_msg_obstacle_distance_get_min_distance(msg);
        max_distance = mavlink_msg_obstacle_distance_get_max_distance(msg);
        sensor_type = mavlink_msg_obstacle_distance_get_sensor_type(msg);
        increment = mavlink_msg_obstacle_distance_get_increment(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN? msg.len : MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

