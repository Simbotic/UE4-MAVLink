 
#include "MavLinkMsg_set_home_position.h"
#include "common/mavlink.h"



void FMavlinkMsg_set_home_position::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_set_home_position_pack(systemId, componentId, &msg,  target_system, latitude, longitude, altitude, x, y, z, q, approach_x, approach_y, approach_z, time_usec);
}

void FMavlinkMsg_set_home_position::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_set_home_position::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        latitude = mavlink_msg_set_home_position_get_latitude(msg);
        longitude = mavlink_msg_set_home_position_get_longitude(msg);
        altitude = mavlink_msg_set_home_position_get_altitude(msg);
        x = mavlink_msg_set_home_position_get_x(msg);
        y = mavlink_msg_set_home_position_get_y(msg);
        z = mavlink_msg_set_home_position_get_z(msg);
        q = mavlink_msg_set_home_position_get_q(msg, set_home_position->q);
        approach_x = mavlink_msg_set_home_position_get_approach_x(msg);
        approach_y = mavlink_msg_set_home_position_get_approach_y(msg);
        approach_z = mavlink_msg_set_home_position_get_approach_z(msg);
        target_system = mavlink_msg_set_home_position_get_target_system(msg);
        time_usec = mavlink_msg_set_home_position_get_time_usec(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_SET_HOME_POSITION_LEN? msg.len : MAVLINK_MSG_ID_SET_HOME_POSITION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_SET_HOME_POSITION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

