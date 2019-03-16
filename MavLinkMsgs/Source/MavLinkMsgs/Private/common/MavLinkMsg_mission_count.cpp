 
#include "MavLinkMsg_mission_count.h"
#include "common/mavlink.h"



void FMavlinkMsg_mission_count::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mission_count_pack(systemId, componentId, &msg,  target_system, target_component, count, mission_type);
}

void FMavlinkMsg_mission_count::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mission_count::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        count = mavlink_msg_mission_count_get_count(msg);
        target_system = mavlink_msg_mission_count_get_target_system(msg);
        target_component = mavlink_msg_mission_count_get_target_component(msg);
        mission_type = mavlink_msg_mission_count_get_mission_type(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MISSION_COUNT_LEN? msg.len : MAVLINK_MSG_ID_MISSION_COUNT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MISSION_COUNT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

