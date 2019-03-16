 
#include "MavLinkMsg_utm_global_position.h"
#include "common/mavlink.h"



void FMavlinkMsg_utm_global_position::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_utm_global_position_pack(systemId, componentId, &msg,  time, (uint8_t*)uas_id, lat, lon, alt, relative_alt, vx, vy, vz, h_acc, v_acc, vel_acc, next_lat, next_lon, next_alt, update_rate, flight_state, flags);
}

void FMavlinkMsg_utm_global_position::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_utm_global_position::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time = mavlink_msg_utm_global_position_get_time(msg);
        lat = mavlink_msg_utm_global_position_get_lat(msg);
        lon = mavlink_msg_utm_global_position_get_lon(msg);
        alt = mavlink_msg_utm_global_position_get_alt(msg);
        relative_alt = mavlink_msg_utm_global_position_get_relative_alt(msg);
        next_lat = mavlink_msg_utm_global_position_get_next_lat(msg);
        next_lon = mavlink_msg_utm_global_position_get_next_lon(msg);
        next_alt = mavlink_msg_utm_global_position_get_next_alt(msg);
        vx = mavlink_msg_utm_global_position_get_vx(msg);
        vy = mavlink_msg_utm_global_position_get_vy(msg);
        vz = mavlink_msg_utm_global_position_get_vz(msg);
        h_acc = mavlink_msg_utm_global_position_get_h_acc(msg);
        v_acc = mavlink_msg_utm_global_position_get_v_acc(msg);
        vel_acc = mavlink_msg_utm_global_position_get_vel_acc(msg);
        update_rate = mavlink_msg_utm_global_position_get_update_rate(msg);
        uas_id = mavlink_msg_utm_global_position_get_uas_id(msg, utm_global_position->uas_id);
        flight_state = mavlink_msg_utm_global_position_get_flight_state(msg);
        flags = mavlink_msg_utm_global_position_get_flags(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_UTM_GLOBAL_POSITION_LEN? msg.len : MAVLINK_MSG_ID_UTM_GLOBAL_POSITION_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_UTM_GLOBAL_POSITION_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

