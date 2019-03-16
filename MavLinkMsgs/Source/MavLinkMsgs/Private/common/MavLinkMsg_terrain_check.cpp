 
#include "MavLinkMsg_terrain_check.h"
#include "common/mavlink.h"



void FMavlinkMsg_terrain_check::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_terrain_check_pack(systemId, componentId, &msg,  lat, lon);
}

void FMavlinkMsg_terrain_check::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_terrain_check::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        lat = mavlink_msg_terrain_check_get_lat(msg);
        lon = mavlink_msg_terrain_check_get_lon(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_TERRAIN_CHECK_LEN? msg.len : MAVLINK_MSG_ID_TERRAIN_CHECK_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_TERRAIN_CHECK_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

