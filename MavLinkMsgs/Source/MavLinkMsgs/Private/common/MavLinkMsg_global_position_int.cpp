 
#include "MavLinkMsg_global_position_int.h"
#include "common/mavlink.h"



void FMavlinkMsg_global_position_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_global_position_int_pack(systemId, componentId, &msg,  time_boot_ms, lat, lon, alt, relative_alt, vx, vy, vz, hdg);
}

void FMavlinkMsg_global_position_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_global_position_int::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_global_position_int_get_time_boot_ms(msg);
        lat = mavlink_msg_global_position_int_get_lat(msg);
        lon = mavlink_msg_global_position_int_get_lon(msg);
        alt = mavlink_msg_global_position_int_get_alt(msg);
        relative_alt = mavlink_msg_global_position_int_get_relative_alt(msg);
        vx = mavlink_msg_global_position_int_get_vx(msg);
        vy = mavlink_msg_global_position_int_get_vy(msg);
        vz = mavlink_msg_global_position_int_get_vz(msg);
        hdg = mavlink_msg_global_position_int_get_hdg(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN? msg.len : MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

