 
#include "MavLinkMsg_mission_item_reached.h"
#include "common/mavlink.h"



void FMavlinkMsg_mission_item_reached::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_mission_item_reached_pack(systemId, componentId, &msg,  seq);
}

void FMavlinkMsg_mission_item_reached::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_mission_item_reached::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        seq = mavlink_msg_mission_item_reached_get_seq(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN? msg.len : MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

