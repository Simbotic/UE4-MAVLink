 
#include "MavLinkMsg_altitude.h"
#include "common/mavlink.h"



void FMavlinkMsg_altitude::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_altitude_pack(systemId, componentId, &msg,  time_usec, altitude_monotonic, altitude_amsl, altitude_local, altitude_relative, altitude_terrain, bottom_clearance);
}

void FMavlinkMsg_altitude::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_altitude::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_usec = mavlink_msg_altitude_get_time_usec(msg);
        altitude_monotonic = mavlink_msg_altitude_get_altitude_monotonic(msg);
        altitude_amsl = mavlink_msg_altitude_get_altitude_amsl(msg);
        altitude_local = mavlink_msg_altitude_get_altitude_local(msg);
        altitude_relative = mavlink_msg_altitude_get_altitude_relative(msg);
        altitude_terrain = mavlink_msg_altitude_get_altitude_terrain(msg);
        bottom_clearance = mavlink_msg_altitude_get_bottom_clearance(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_ALTITUDE_LEN? msg.len : MAVLINK_MSG_ID_ALTITUDE_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_ALTITUDE_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

