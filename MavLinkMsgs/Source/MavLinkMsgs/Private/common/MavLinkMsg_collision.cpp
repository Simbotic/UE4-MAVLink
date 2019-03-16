 
#include "MavLinkMsg_collision.h"
#include "common/mavlink.h"



void FMavlinkMsg_collision::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_collision_pack(systemId, componentId, &msg,  src, id, action, threat_level, time_to_minimum_delta, altitude_minimum_delta, horizontal_minimum_delta);
}

void FMavlinkMsg_collision::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_collision::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        id = mavlink_msg_collision_get_id(msg);
        time_to_minimum_delta = mavlink_msg_collision_get_time_to_minimum_delta(msg);
        altitude_minimum_delta = mavlink_msg_collision_get_altitude_minimum_delta(msg);
        horizontal_minimum_delta = mavlink_msg_collision_get_horizontal_minimum_delta(msg);
        src = mavlink_msg_collision_get_src(msg);
        action = mavlink_msg_collision_get_action(msg);
        threat_level = mavlink_msg_collision_get_threat_level(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_COLLISION_LEN? msg.len : MAVLINK_MSG_ID_COLLISION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_COLLISION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

