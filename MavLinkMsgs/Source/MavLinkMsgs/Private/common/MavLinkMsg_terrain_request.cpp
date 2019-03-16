 
#include "MavLinkMsg_terrain_request.h"
#include "common/mavlink.h"



void FMavlinkMsg_terrain_request::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_terrain_request_pack(systemId, componentId, &msg,  lat, lon, grid_spacing, mask);
}

void FMavlinkMsg_terrain_request::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_terrain_request::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        mask = mavlink_msg_terrain_request_get_mask(msg);
        lat = mavlink_msg_terrain_request_get_lat(msg);
        lon = mavlink_msg_terrain_request_get_lon(msg);
        grid_spacing = mavlink_msg_terrain_request_get_grid_spacing(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_TERRAIN_REQUEST_LEN? msg.len : MAVLINK_MSG_ID_TERRAIN_REQUEST_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_TERRAIN_REQUEST_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

