 
#include "MavLinkMsg_position_target_global_int.h"
#include "common/mavlink.h"



void FMavlinkMsg_position_target_global_int::Serialize(uint8 systemId, uint8 componentId, __mavlink_message& msg, uint16& packSize)
{
    packSize = mavlink_msg_position_target_global_int_pack(systemId, componentId, &msg,  time_boot_ms, coordinate_frame, type_mask, lat_int, lon_int, alt, vx, vy, vz, afx, afy, afz, yaw, yaw_rate);
}

void FMavlinkMsg_position_target_global_int::Serialize(uint8 systemId, uint8 componentId, TSharedRef<TArray<uint8>, ESPMode::ThreadSafe>& buffer)
{
    uint16 size;
    __mavlink_message msg;
    Serialize(systemId, componentId,    msg, size);
    buffer->SetNum(size);
    mavlink_msg_to_send_buffer(buffer->GetData(), &msg);
}

void FMavlinkMsg_position_target_global_int::Deserialize(const mavlink_message_t& msg)
{
    #if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
        time_boot_ms = mavlink_msg_position_target_global_int_get_time_boot_ms(msg);
        lat_int = mavlink_msg_position_target_global_int_get_lat_int(msg);
        lon_int = mavlink_msg_position_target_global_int_get_lon_int(msg);
        alt = mavlink_msg_position_target_global_int_get_alt(msg);
        vx = mavlink_msg_position_target_global_int_get_vx(msg);
        vy = mavlink_msg_position_target_global_int_get_vy(msg);
        vz = mavlink_msg_position_target_global_int_get_vz(msg);
        afx = mavlink_msg_position_target_global_int_get_afx(msg);
        afy = mavlink_msg_position_target_global_int_get_afy(msg);
        afz = mavlink_msg_position_target_global_int_get_afz(msg);
        yaw = mavlink_msg_position_target_global_int_get_yaw(msg);
        yaw_rate = mavlink_msg_position_target_global_int_get_yaw_rate(msg);
        type_mask = mavlink_msg_position_target_global_int_get_type_mask(msg);
        coordinate_frame = mavlink_msg_position_target_global_int_get_coordinate_frame(msg);
    
    #else
        uint8_t len = msg.len < MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_LEN? msg.len : MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_LEN;
        FMemory::Memset(this, 0, MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT_LEN);
        FMemory::Memcpy(this, _MAV_PAYLOAD(&msg), len);
    #endif
}

